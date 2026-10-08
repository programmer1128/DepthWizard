#pragma once

#include <memory>
#include <vector>
#include <future>
#include "SemanticInferenceConfig.h"
#include "../../structures/InferenceStructs.h"
#include "../../structures/SemanticInferenceTypes.h"

class SemanticTileDispatcher
{
public:
    // Dispatches the shared tile batch across the configured semantic worker
    // pool and returns validated, unstitched semantic tiles.
    static SemanticTiledPayload dispatch(
        int globalWidth,
        int globalHeight,
        const std::vector<std::shared_ptr<TileRequest>>& tiles,
        const SemanticInferenceConfig& config);
};
