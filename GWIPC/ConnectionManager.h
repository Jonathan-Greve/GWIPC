#include "SharedMemory.h"
#include "SharedMemoryLock.h"
#include "connections_generated.h"
#include <vector>
#include <algorithm>

namespace GWIPC {
	class ConnectionManager {
	public:
		ConnectionManager(const std::string& connection_id) : shared_memory_("connections", 1024),
			connection_id_(connection_id)
		{
			// Create or open the event. This will be used to notify other processes and a client connect or disconnect.
			event_ = ::CreateEventA(nullptr, TRUE, FALSE, event_name_.c_str());
			if (event_ == nullptr) {
				throw "Could not create connections event";
			}
		}

		void connect() {
			SharedMemoryLock lock(shared_memory_); // Scoped lock

			auto curr_connection_ids = get_connections_ids();
			const auto it = std::find(curr_connection_ids.begin(), curr_connection_ids.end(), connection_id_);
			if (it == curr_connection_ids.end()) {
				curr_connection_ids.push_back(connection_id_);

				write_connections_to_sm(curr_connection_ids);
			}

			SetEvent(event_);
		}

		void disconnect() {
			SharedMemoryLock lock(shared_memory_);

			auto curr_connection_ids = get_connections_ids();
			const auto it = std::find(curr_connection_ids.begin(), curr_connection_ids.end(), connection_id_);
			if (it != curr_connection_ids.end()) {
				curr_connection_ids.erase(it);

				write_connections_to_sm(curr_connection_ids);
			}

			SetEvent(event_);
		}

		// Returns a list of all connected email addresses.
		std::vector<std::string> get_connections_ids() {
			std::vector<std::string> result;

			SharedMemoryLock lock(shared_memory_);
			uint8_t* sm_data = static_cast<uint8_t*>(shared_memory_.data());
			if (sm_data) {
				auto connections = GWIPC::GetConnections(sm_data);
				if (connections) {
					// Check
					auto ids = connections->connected_ids();
					if (ids) {
						for (const auto id : *ids) {
							result.push_back(id->str());
						}
					}
				}
			}

			return result;
		}

	private:
		std::string connection_id_ = "not set";

		SharedMemory shared_memory_;

		HANDLE event_;
		const std::string event_name_ = "connections_event";


		void write_connections_to_sm(const std::vector<std::string>& connections) {
			// Build flatbuffer
			flatbuffers::FlatBufferBuilder builder(shared_memory_.get_sm_size());
			auto new_connection_ids = builder.CreateVectorOfStrings(connections);
			auto connections_flatbuf = GWIPC::CreateConnections(builder, new_connection_ids);
			builder.Finish(connections_flatbuf);

			// Copy and overwrite shared memory.
			uint8_t* buf = builder.GetBufferPointer();
			int size = builder.GetSize();
			uint8_t* data = static_cast<uint8_t*>(shared_memory_.data());
			memcpy(data, buf, size);
		}
	};
}
