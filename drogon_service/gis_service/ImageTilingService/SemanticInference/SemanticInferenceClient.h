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
