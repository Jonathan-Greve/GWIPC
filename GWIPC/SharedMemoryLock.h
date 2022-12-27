#pragma once
#include "SharedMemory.h"


namespace GWIPC {
    class SharedMemoryLock {
    public:
        // Locks the shared memory object.
        SharedMemoryLock(SharedMemory& shm) : shm_(shm) {
            shm_.lock();
        }

        // Unlocks the shared memory object.
        ~SharedMemoryLock() {
            shm_.unlock();
        }

    private:
        SharedMemory& shm_;
    };
}