// a bounded thread queue to prevent network flooding and handle retries

#pragma once
#include "../../structures/NdsmInferenceTypes.h"
#include "../../structures/InferenceStructs.h"
#include "NdsmInferenceConfig.h"
#include <vector>
#include <memory>

class NdsmTileDispatcher 
{
public:
    // Processes a batch of tiles using a strictly bounded thread pool with inline retries
    static NdsmTiledPayload dispatchBatch(
        int globalWidth, 
        int globalHeight,
        const std::vector<std::shared_ptr<TileRequest>>& tiles,
        const NdsmInferenceConfig& config);
};