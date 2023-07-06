#pragma once
#include "SharedMemory.h"
#include "SharedMemoryLock.h"
#include "control_states_generated.h"
#include <vector>
#include <algorithm>

namespace GWIPC
{
class ControlStatesManager
{
public:
    ControlStatesManager(const std::string& connection_id)
        : connection_id_(connection_id)
        , read_buf_(std::vector<uint8_t>(64))
        , shared_memory_(std::format("{}:update_options", connection_id), 1024)
    {
    }

    const GWIPC::ControlStates* get_control_states()
    {
        auto sm_data = shared_memory_.get_data();
        if (sm_data)
        {
            {
                GWIPC::SharedMemoryLock lock(shared_memory_);
                auto data_info = shared_memory_.get_data_info();
                memcpy(read_buf_.data(), sm_data, data_info->data_size);
            }

            auto control_states = GWIPC::GetControlStates(read_buf_.data());

            return control_states;
        }

        return nullptr;
    }

    void update(float camera_yaw_angle = 0, bool strafe_left = false, bool strafe_right = false,
                bool move_forward = false, bool move_backwards = false)
    {

        // Build flatbuffer
        flatbuffers::FlatBufferBuilder builder(shared_memory_.get_sm_size());

        auto control_states_flatbuf = GWIPC::CreateControlStates(builder, camera_yaw_angle, strafe_left,
                                                                 strafe_right, move_forward, move_backwards);

        builder.Finish(control_states_flatbuf);

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
