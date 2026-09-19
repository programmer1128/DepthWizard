// triggers the TileDispatcher

#include "TilingService.h"
#include <trantor/utils/Logger.h>
#include <stdexcept>

drogon::Task<InferenceBundle> TilingService::generateStitchedMetricInference(
    const SceneInput& scene, 
    const ImageQualityResult& quality) 
{
    LOG_INFO << "TilingService: Starting Multi-Threaded AI Dispatch...";

    // dispatch the 518x518 windows and wait for them to process
    TiledInferencePayload payload = co_await TileDispatcher::processMetricRaster(scene, quality);

    if (payload.allTiles.empty()) 
    {
        throw std::runtime_error("TilingService: AI Dispatcher returned 0 processed tiles");
    }

    LOG_INFO << "TilingService: Successfully received " << payload.allTiles.size() << " tiles. Commencing Stitching...";

    // hand the tiles over to the MetricOutputStitcher for Hann blending
    InferenceBundle globalBundle = MetricOutputStitcher::stitch(payload);

    LOG_INFO << "TilingService: Global Metric Surface successfully stitched.";

    // return the fully assembled map to the PipelineService
    co_return globalBundle;
}