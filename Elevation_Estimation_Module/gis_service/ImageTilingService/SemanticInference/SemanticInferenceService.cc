#include "SemanticInferenceService.h"
#include "SemanticTileDispatcher.h"
#include "../OutputStitching/SemanticOutputStitcher.h"

#include <trantor/utils/Logger.h>
#include <stdexcept>

SemanticInferenceBundle SemanticInferenceService::generateGlobalSemantics(
    int globalWidth,
    int globalHeight,
    const std::vector<std::shared_ptr<TileRequest>>& tiles,
    const SemanticInferenceConfig& config)
{
    LOG_INFO << "SemanticInferenceService: Starting multi-threaded Semantic AI Dispatch...";

    // 1. Dispatch tiles to Python workers concurrently and wait for completion
    SemanticTiledPayload payload = SemanticTileDispatcher::dispatch(
        globalWidth,
        globalHeight,
        tiles,
        config);

    if (payload.tiles.empty()) 
    {
        throw std::runtime_error("SemanticInferenceService: Dispatcher returned 0 processed tiles.");
    }

    LOG_INFO << "SemanticInferenceService: Successfully received " 
             << payload.tiles.size() << " semantic tiles. Commencing Stitching...";

    // 2. Stitch overlapping raw logits before the postprocessor applies
    // softmax. This avoids probability seams at tile boundaries.
    SemanticInferenceBundle globalBundle =
        SemanticOutputStitcher::stitch(payload, config);
    LOG_INFO << "SemanticInferenceService: Global Semantic Surface successfully stitched.";

    // 3. Return the fully assembled bundle
    return globalBundle;
}
