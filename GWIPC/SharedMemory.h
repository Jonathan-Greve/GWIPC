#pragma once
#include <Windows.h>
#include <string>
#include <format>

namespace GWIPC
{
struct DataInfo
{
    uint32_t data_size;
};

class SharedMemory
{
public:
    // Constructs a new shared memory object with the given name and size.
    // If the object already exists, it will be opened instead of created.
    // Constructs a new shared memory object with the given name and size.
    // If the object already exists, it will be opened instead of created.
    SharedMemory(std::string name, uint32_t size)
        : sm_name_(name)
        , sm_size_(size)
    {
        mutex_ = CreateMutexA(NULL, FALSE, (name + "mutex").c_str());
        if (mutex_ == NULL)
        {
            throw std::format("Could not create mutex ({})\n", GetLastError());
        }

        mapping_ = CreateFileMappingA(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, size, name.c_str());
        if (mapping_ == NULL)
        {
            throw std::format("Could not create file mapping object ({})\n", GetLastError());
        }

        data_ = MapViewOfFile(mapping_, FILE_MAP_ALL_ACCESS, 0, 0, size);
        if (data_ == NULL)
        {
            throw std::format("Could not map view of file ({})\n", GetLastError());
        }
    }

    ~SharedMemory()
    {
        UnmapViewOfFile(data_);
        CloseHandle(mapping_);
        CloseHandle(mutex_);
    }

    void terminate() { }

    void write_data(const uint8_t* new_data, uint32_t new_data_size)
    {
        DataInfo data_info(new_data_size);
        WaitForSingleObject(mutex_, INFINITE);
        std::memcpy(data_, &data_info, sizeof(DataInfo));
        std::memcpy((uint8_t*)data_ + sizeof(DataInfo), new_data, new_data_size);
        ReleaseMutex(mutex_);
    }

    // Returns a pointer to the shared memory.
    DataInfo* get_data_info() const { return static_cast<DataInfo*>(data_); }
    uint8_t* get_data() const { return static_cast<uint8_t*>(data_) + sizeof(DataInfo); }

    // Locks the shared memory for reading or writing.
    // Locks the shared memory for reading or writing.
    void lock() { WaitForSingleObject(mutex_, INFINITE); }

    // Unlocks the shared memory.
    // Unlocks the shared memory.
    void unlock() { ReleaseMutex(mutex_); }

    const std::string& get_sm_name() const { return sm_name_; }
    const uint32_t get_sm_size() const { return sm_size_; }
    HANDLE get_mutex_handle() { return mutex_; }

private:
    std::string sm_name_;
    uint32_t sm_size_;

    HANDLE mutex_;
    HANDLE mapping_;
    void* data_;
};
}
