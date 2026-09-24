#pragma once

#include <memory>
#include <vector>
#include <future>
#include <drogon/drogon.h>
#include <drogon/utils/coroutine.h>

#include "SemanticInferenceConfig.h"
#include "../../structures/IngestionStructs.h"
#include "../../structures/InferenceStructs.h"
#include "../../structures/SemanticInferenceTypes.h"

class SemanticTileDispatcher
{
public:
    // Slices the scene into overlapping tiles, dispatches them across the 
    // configured worker pool with bounded concurrency and retries, 
    // and returns the collected unstitched tiles.
    static drogon::Task<SemanticTiledPayload> dispatch(
        const SceneInput& scene,
        const ImageQualityResult& quality,
        const SemanticInferenceConfig& config);

    // Slices a 518x518 window out of the global CHW image tensor and mask
    static std::shared_ptr<TileRequest> extractTileMemory(
        int start_x, int start_y, int valid_w, int valid_h, int tile_size, uint32_t tile_id,
        const SceneInput& scene, const ImageQualityResult& quality);
};