#pragma once
#include "SharedMemory.h"
#include "SharedMemoryLock.h"
#include "update_options_generated.h"
#include <vector>
#include <algorithm>

namespace GWIPC
{
class UpdateOptionsManager
{
public:
    UpdateOptionsManager(const std::string& connection_id)
        : connection_id_(connection_id)
        , read_buf_(std::vector<uint8_t>(64))
        , shared_memory_(std::format("{}:update_options", connection_id), 1024)
    {
    }

    const GWIPC::UpdateOptions* get_update_options()
    {
        auto sm_data = shared_memory_.get_data();
        if (sm_data)
        {
            {
                GWIPC::SharedMemoryLock lock(shared_memory_);
                auto data_info = shared_memory_.get_data_info();
                memcpy(read_buf_.data(), sm_data, data_info->data_size);
            }

            auto update_options = GWIPC::GetUpdateOptions(read_buf_.data());

            return update_options;
        }

        return nullptr;
    }

    void update(bool only_send_active_quest_description, bool only_send_active_quest_objectives, bool should_update_client_data)
    {

        // Build flatbuffer
        flatbuffers::FlatBufferBuilder builder(shared_memory_.get_sm_size());

        auto options_flatbuf = GWIPC::CreateUpdateOptions(builder,
            only_send_active_quest_description,
            only_send_active_quest_objectives,
            should_update_client_data);

        builder.Finish(options_flatbuf);

        // Copy and overwrite shared memory.
        uint8_t* buf = builder.GetBufferPointer();
        int size = builder.GetSize();
        shared_memory_.write_data(buf, size);
    }


    void terminate() { shared_memory_.terminate(); }

    HANDLE get_mutex_handle() { return shared_memory_.get_mutex_handle(); }

private:
    std::string connection_id_ = "not set";

    std::vector<uint8_t> read_buf_;

    SharedMemory shared_memory_;
};
}
