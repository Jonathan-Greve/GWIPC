#include "SharedMemory.h"
#include "SharedMemoryLock.h"
#include "connections_generated.h"
#include <vector>
#include <algorithm>

namespace GWIPC
{
class ConnectionManager
{
public:
    // Used by readers
    ConnectionManager()
        : shared_memory_("connections", 1024)
    {
        create_event();
    }

    // Used by writers
    ConnectionManager(const std::string& connection_id)
        : shared_memory_("connections", 1024)
        , connection_id_(connection_id)
    {
        create_event();
    }

    void connect()
    {
        SharedMemoryLock lock(shared_memory_); // Scoped lock

        auto curr_connection_ids = get_connections_ids();
        const auto it = std::find(curr_connection_ids.begin(), curr_connection_ids.end(), connection_id_);
        if (it == curr_connection_ids.end())
        {
            curr_connection_ids.push_back(connection_id_);

            write_connections_to_sm(curr_connection_ids);
        }

        SetEvent(event_);
    }

    void disconnect()
    {
        SharedMemoryLock lock(shared_memory_);

        auto curr_connection_ids = get_connections_ids();
        const auto it = std::find(curr_connection_ids.begin(), curr_connection_ids.end(), connection_id_);
        if (it != curr_connection_ids.end())
        {
            curr_connection_ids.erase(it);

            write_connections_to_sm(curr_connection_ids);
        }

        SetEvent(event_);
    }

    // Returns a list of all connected email addresses.
    std::vector<std::string> get_connections_ids()
    {
        std::vector<std::string> result;

        auto sm_data = shared_memory_.get_data();
        if (sm_data)
        {
            auto connections = GWIPC::GetConnections(sm_data);
            if (connections)
            {
                // Check
                auto ids = connections->connected_ids();
                if (ids)
                {
                    for (const auto id : *ids)
                    {
                        result.push_back(id->str());
                    }
                }
            }
        }

        return result;
    }

    void terminate()
    {
        shared_memory_.terminate();
        CloseHandle(event_);
    }

    // Used by the Replayer.h
    void clear_all_connections()
    {
        std::vector<std::string> empty;
        write_connections_to_sm(empty);

        SetEvent(event_);
    }

    // Used by the Replayer.h
    void connect_multiple(const std::vector<std::string>& connection_ids)
    {
        auto curr_connection_ids = get_connections_ids();
        for (const auto& connection_id : connection_ids)
        {
            const auto it = std::find(curr_connection_ids.begin(), curr_connection_ids.end(), connection_id);
            if (it == curr_connection_ids.end())
            {
                curr_connection_ids.push_back(connection_id);
            }
        }

        write_connections_to_sm(curr_connection_ids);

        SetEvent(event_);
    }

    HANDLE get_event_handle() { return event_; }
    HANDLE get_mutex_handle() { return shared_memory_.get_mutex_handle(); }

private:
    std::string connection_id_ = "not set";

    SharedMemory shared_memory_;

    HANDLE event_;
    const std::string event_name_ = "connections_event";

    void write_connections_to_sm(const std::vector<std::string>& connections)
    {
        // Build flatbuffer
        flatbuffers::FlatBufferBuilder builder(shared_memory_.get_sm_size());
        auto new_connection_ids = builder.CreateVectorOfStrings(connections);
        auto connections_flatbuf = GWIPC::CreateConnections(builder, new_connection_ids);
        builder.Finish(connections_flatbuf);

        // Copy and overwrite shared memory.
        uint8_t* buf = builder.GetBufferPointer();
        int size = builder.GetSize();
        shared_memory_.write_data(buf, size);
    }

    void create_event()
    {
        // Create or open the event. This will be used to notify other processes and a client connect or disconnect.
        event_ = ::CreateEventA(nullptr, TRUE, FALSE, event_name_.c_str());
        if (event_ == nullptr)
        {
            throw "Could not create connections event";
        }
    }
};
}
