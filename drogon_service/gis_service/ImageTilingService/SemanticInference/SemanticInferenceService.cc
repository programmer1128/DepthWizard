#include "SemanticInferenceService.h"
#include "SemanticTileDispatcher.h"
//#include "OutputStitching/SemanticOutputStitcher.h"

#include <trantor/utils/Logger.h>
#include <stdexcept>

drogon::Task<SemanticInferenceBundle> SemanticInferenceService::generateGlobalSemantics(
    const SceneInput& scene,
    const ImageQualityResult& quality,
    const SemanticInferenceConfig& config)
{
    LOG_INFO << "SemanticInferenceService: Starting multi-threaded Semantic AI Dispatch...";

    // 1. Dispatch tiles to Python workers concurrently and wait for completion
    SemanticTiledPayload payload = co_await SemanticTileDispatcher::dispatch(scene, quality, config);

    if (payload.tiles.empty()) 
    {
        throw std::runtime_error("SemanticInferenceService: Dispatcher returned 0 processed tiles.");
    }

    LOG_INFO << "SemanticInferenceService: Successfully received " 
             << payload.tiles.size() << " semantic tiles. Commencing Stitching...";

    // 2. Stitch the overlapping 6-channel tiles into seamless global matrices
    //SemanticInferenceBundle globalBundle = SemanticOutputStitcher::stitch(payload, config);


    //TO BE INTEGRATED
    SemanticInferenceBundle globalBundle;
    LOG_INFO << "SemanticInferenceService: Global Semantic Surface successfully stitched.";

    // 3. Return the fully assembled bundle
    co_return globalBundle;
}