#pragma once
#include "SharedMemory.h"
#include "SharedMemoryLock.h"
#include "ConnectionManager.h"
#include "UpdateOptionsManager.h"

// Generated flatbuffer files
#include "connections_generated.h"
#include "clientData_generated.h"
#include "update_options_generated.h"

namespace GWIPC
{
constexpr uint32_t CLIENTDATA_SIZE = 1024 * 128; // Buffer size in bytes;
}
