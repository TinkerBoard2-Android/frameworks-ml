/*
 * Copyright (C) 2017 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ANDROID_ML_NN_RUNTIME_MEMORY_H
#define ANDROID_ML_NN_RUNTIME_MEMORY_H

#include "NeuralNetworks.h"
#include "Utils.h"

#include <cutils/native_handle.h>
#include <sys/mman.h>
#include <unordered_map>

namespace android {
namespace nn {

class ModelBuilder;

// Represents a memory region.
class Memory {
public:
    Memory() {}
    virtual ~Memory() {}

    // Disallow copy semantics to ensure the runtime object can only be freed
    // once. Copy semantics could be enabled if some sort of reference counting
    // or deep-copy system for runtime objects is added later.
    Memory(const Memory&) = delete;
    Memory& operator=(const Memory&) = delete;

    // Creates a shared memory object of the size specified in bytes.
    int create(uint32_t size);

    hardware::hidl_memory getHidlMemory() const { return mHidlMemory; }

    // Returns a pointer to the underlying memory of this memory object.
    virtual int getPointer(uint8_t** buffer) const {
        *buffer = static_cast<uint8_t*>(static_cast<void*>(mMemory->getPointer()));
        return ANEURALNETWORKS_NO_ERROR;
    }

    virtual bool validateSize(uint32_t offset, uint32_t length) const {
        if (offset + length > mHidlMemory.size()) {
            LOG(ERROR) << "Request size larger than the memory size.";
            return false;
        } else {
            return true;
        }
    }
protected:
    // The hidl_memory handle for this shared memory.  We will pass this value when
    // communicating with the drivers.
    hardware::hidl_memory mHidlMemory;
    sp<IMemory> mMemory;
};

class MemoryFd : public Memory {
public:
    MemoryFd() {}
    ~MemoryFd() {
        // Delete the native_handle.
        if (mHandle) {
            int fd = mHandle->data[0];
            if (fd != -1) {
                close(fd);
            }
            native_handle_delete(mHandle);
        }
    }

    // Disallow copy semantics to ensure the runtime object can only be freed
    // once. Copy semantics could be enabled if some sort of reference counting
    // or deep-copy system for runtime objects is added later.
    MemoryFd(const MemoryFd&) = delete;
    MemoryFd& operator=(const MemoryFd&) = delete;

    // Create the native_handle based on input size, prot, and fd.
    // Existing native_handle will be deleted, and mHidlMemory will wrap
    // the newly created native_handle.
    int set(size_t size, int prot, int fd, size_t offset) {
        if (size == 0 || fd < 0) {
            LOG(ERROR) << "Invalid size or fd";
            return ANEURALNETWORKS_BAD_DATA;
        }
        int dupfd = dup(fd);
        if (dupfd == -1) {
            LOG(ERROR) << "Failed to dup the fd";
            return ANEURALNETWORKS_UNEXPECTED_NULL;
        }

        if (mHandle) {
            native_handle_delete(mHandle);
        }
        mHandle = native_handle_create(1, 3);
        if (mHandle == nullptr) {
            LOG(ERROR) << "Failed to create native_handle";
            return ANEURALNETWORKS_UNEXPECTED_NULL;
        }
        mHandle->data[0] = dupfd;
        mHandle->data[1] = prot;
        mHandle->data[2] = (int32_t)(uint32_t)(offset & 0xffffffff);
#if defined(__LP64__)
        mHandle->data[3] = (int32_t)(uint32_t)(offset >> 32);
#else
        mHandle->data[3] = 0;
#endif
        mHidlMemory = hidl_memory("mmap_fd", mHandle, size);
        return ANEURALNETWORKS_NO_ERROR;
    }

    int getPointer(uint8_t** buffer) const override {
        if (mHandle == nullptr) {
            LOG(ERROR) << "Memory not initialized";
            return ANEURALNETWORKS_UNEXPECTED_NULL;
        }

        int fd = mHandle->data[0];
        int prot = mHandle->data[1];
        size_t offset = getSizeFromInts(mHandle->data[2], mHandle->data[3]);
        void* data = mmap(nullptr, mHidlMemory.size(), prot, MAP_SHARED, fd, offset);
        if (data == MAP_FAILED) {
            LOG(ERROR) << "Can't mmap the file descriptor.";
            return ANEURALNETWORKS_UNMAPPABLE;
        } else {
            *buffer = static_cast<uint8_t*>(data);
            return ANEURALNETWORKS_NO_ERROR;
        }
    }

private:
    native_handle_t* mHandle = nullptr;
};

// A utility class to accumulate mulitple Memory objects and assign each
// a distinct index number, starting with 0.
//
// The user of this class is responsible for avoiding concurrent calls
// to this class from multiple threads.
class MemoryTracker {
public:
    // Adds the memory, if it does not already exists.  Returns its index.
    // The memories should survive the tracker.
    uint32_t add(const Memory* memory);
    // Returns the number of memories contained.
    uint32_t size() const { return static_cast<uint32_t>(mKnown.size()); }
    // Returns the ith memory.
    const Memory* operator[](size_t i) const { return mMemories[i]; }

private:
    // The vector of Memory pointers we are building.
    std::vector<const Memory*> mMemories;
    // A faster way to see if we already have a memory than doing find().
    std::unordered_map<const Memory*, uint32_t> mKnown;
};

}  // namespace nn
}  // namespace android

#endif  // ANDROID_ML_NN_RUNTIME_MEMORY_H