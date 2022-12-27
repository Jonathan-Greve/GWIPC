#pragma once
#include <Windows.h>
#include <string>
#include <format>

namespace GWIPC {
	class SharedMemory {
	public:
		// Constructs a new shared memory object with the given name and size.
		// If the object already exists, it will be opened instead of created.
		// Constructs a new shared memory object with the given name and size.
		// If the object already exists, it will be opened instead of created.
		SharedMemory(std::string name, uint32_t size) : sm_name_(name), sm_size_(size)
		{
			mutex_ = CreateMutexA(NULL, FALSE, (name + "mutex").c_str());
			if (mutex_ == NULL) {
				throw std::format("Could not create mutex ({})\n", GetLastError());
			}

			mapping_ = CreateFileMappingA(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, size, name.c_str());
			if (mapping_ == NULL) {
				throw std::format("Could not create file mapping object ({})\n", GetLastError());
			}

			data_ = MapViewOfFile(mapping_, FILE_MAP_ALL_ACCESS, 0, 0, size);
			if (data_ == NULL) {
				throw std::format("Could not map view of file ({})\n", GetLastError());
			}
		}

		// Destroys the shared memory object.
		// Destroys the shared memory object.
		~SharedMemory() {
			UnmapViewOfFile(data_);
			CloseHandle(mapping_);
			CloseHandle(mutex_);
		}

		// Returns a pointer to the shared memory.
		// Returns a pointer to the shared memory.
		void* data() const {
			return data_;
		}

		// Locks the shared memory for reading or writing.
		// Locks the shared memory for reading or writing.
		void lock() {
			WaitForSingleObject(mutex_, INFINITE);
		}

		// Unlocks the shared memory.
		// Unlocks the shared memory.
		void unlock() {
			ReleaseMutex(mutex_);
		}

		const std::string& get_sm_name() const { return sm_name_; }
		const uint32_t  get_sm_size() const { return sm_size_; }

	private:
		std::string sm_name_;
		uint32_t sm_size_;

		HANDLE mutex_;
		HANDLE mapping_;
		void* data_;
	};
}
