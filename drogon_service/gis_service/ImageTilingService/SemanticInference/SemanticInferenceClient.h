#pragma once

#include <memory>
#include <string>
#include <vector>
#include "../../structures/InferenceStructs.h" // For TileRequest
#include "../../structures/SemanticInferenceTypes.h"
#include "SemanticInferenceConfig.h"

class SemanticInferenceClient 
{
public:
    // Establishes a TCP connection to a specific Python worker, 
    // transmits the tile, and safely parses the 6-channel response.
    static SemanticTileResult inferTile(
        std::shared_ptr<TileRequest> request, 
        const SemanticWorkerEndpoint& endpoint,
        const SemanticInferenceConfig& config);
};


class SocketHandle
{
public:
    explicit SocketHandle(int descriptor) : descriptor_(descriptor) {}

    SocketHandle(const SocketHandle&) = delete;
    SocketHandle& operator=(const SocketHandle&) = delete;

    ~SocketHandle()
    {
        if (descriptor_ >= 0)
            ::close(descriptor_);
    }

    int get() const
    {
        return descriptor_;
    }

private:
    int descriptor_{-1};
};