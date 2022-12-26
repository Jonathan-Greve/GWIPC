#include "SharedMemory.h"
#include "SharedMemoryLock.h"
#include "connections_generated.h"
#include <vector>

class ConnectionManager {
public:
	ConnectionManager(const std::string& connection_id) : shared_memory_(SharedMemory(sm_name, sm_size)),
		connection_id_(connection_id)
	{
	}

	void connect() {
		SharedMemoryLock lock(shared_memory_); // Scoped lock
	};

	void disconnect(){
		SharedMemoryLock lock(shared_memory_);
	}
	// Returns a list of all connected email addresses.
	std::vector<std::string> get_connections() {
		uint8_t* sm_data = static_cast<uint8_t*>(shared_memory_.data());
		if (sm_data) {
			auto connections = GWIPC::GetConnections(sm_data);
			if (connections) {
				// Check 
			}
		}
	};

private:
	std::string connection_id_;

	SharedMemory shared_memory_;
	const std::string sm_name = "connections";
	const uint32_t sm_size = 1024;
};
