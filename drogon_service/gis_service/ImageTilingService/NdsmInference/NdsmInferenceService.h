#pragma once
#include "../../structures/NdsmInferenceTypes.h"
#include "../../structures/InferenceStructs.h" // For TileRequest
#include "NdsmInferenceConfig.h"
#include <memory>
#include <vector>

class NdsmInferenceService 
{
public:
    // Developer A's Boundary: Validates configuration, triggers the bounded TCP dispatcher, 
    // and returns the raw validated tiles. Developer C (Stitcher) will consume this output.
    static NdsmTiledPayload executeInference(
        int globalWidth,
        int globalHeight,
        const std::vector<std::shared_ptr<TileRequest>>& tiles,
        const NdsmInferenceConfig& config);
};