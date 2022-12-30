#pragma once
#include "SharedMemory.h"
#include "SharedMemoryLock.h"
#include "ConnectionManager.h"

// Generated flatbuffer files
#include "connections_generated.h"
#include "clientData_generated.h"

namespace GWIPC
{
constexpr uint32_t CLIENTDATA_SIZE = 4048;
}