// window manager 
// cuts the large image into smaller 518x518 squares 
// assigns them to GPUs and collects the results concurrently

#pragma once

#include <string>  
#include <vector>  
#include <memory>  
#include <future>  
#include <drogon/drogon.h> 
#include "../../structures/IngestionStructs.h" 
#include "../../structures/InferenceStructs.h" 
#include "../InferenceProtocol/InferenceClient.h"
#include "../../utils/TilingTypes.h"


class TileDispatcher 
{
    public:

    // main orchestrator that manages the sliding window and multi-threading
    // inputs: SceneInput and ImageQualityResult -> complete image
    // outputs: task that returns the fully populated TiledInferencePayload

    static drogon::Task<TiledInferencePayload> processMetricRaster(
        const SceneInput& scene, 
        const ImageQualityResult& quality);

    // helper function that copies a 518x518 square of pixels out of the main image
     
    static std::shared_ptr<TileRequest> extractTileMemory(
        int start_x, int start_y, int valid_w, int valid_h, int tile_size, uint32_t tile_id,
        const SceneInput& scene, const ImageQualityResult& quality);
};