// triggers the TileDispatcher

#include "TilingService.h"
#include "NdsmInference/NdsmInferenceConfig.h"
#include "NdsmInference/NdsmInferenceService.h"
#include "OutputStitching/NdsmOutputStitcher.h"
#include "SemanticInference/SemanticInferenceConfig.h"
#include "SemanticInference/SemanticInferenceService.h"

#include <cmath>
#include <future>
#include <trantor/utils/Logger.h>
#include <stdexcept>

drogon::Task<DualModelInferenceBundle> TilingService::generateStitchedInference(
    const SceneInput& scene, 
    const ImageQualityResult& quality) 
{
    LOG_INFO << "TilingService: Starting dual-model inference dispatch.";

    NdsmInferenceConfig ndsmConfig = NdsmInferenceConfig::loadDefaults();
    SemanticInferenceConfig semanticConfig = SemanticInferenceConfig::loadDefaults();

    if (ndsmConfig.model.expectedTileSize <= 0 ||
        static_cast<uint32_t>(ndsmConfig.model.expectedTileSize) !=
            semanticConfig.expectedTileSize)
    {
        throw std::runtime_error(
            "TilingService: nDSM and semantic models require different tile sizes.");
    }

    const int tileSize = ndsmConfig.model.expectedTileSize;
    const int stride = std::max(
        1,
        static_cast<int>(std::lround(static_cast<double>(tileSize) * 0.8)));

    // Create one immutable tile plan and share it between both models. This is
    // the alignment contract for every downstream per-pixel operation.
    const auto tiles = TileDispatcher::buildTileRequests(
        scene,
        quality,
        tileSize,
        stride);

    auto ndsmFuture = std::async(
        std::launch::async,
        [&scene, &tiles, ndsmConfig]() {
            NdsmTiledPayload payload = NdsmInferenceService::executeInference(
                scene.width,
                scene.height,
                tiles,
                ndsmConfig);

            if (payload.failedTileCount != 0 || payload.tiles.size() != tiles.size())
            {
                throw std::runtime_error(
                    "TilingService: nDSM inference did not return every planned tile.");
            }

            return NdsmOutputStitcher::stitch(payload, ndsmConfig.stitching);
        });

    auto semanticFuture = std::async(
        std::launch::async,
        [&scene, &tiles, semanticConfig]() {
            return SemanticInferenceService::generateGlobalSemantics(
                scene.width,
                scene.height,
                tiles,
                semanticConfig);
        });

    DualModelInferenceBundle result;
    result.ndsm = ndsmFuture.get();
    result.semantics = semanticFuture.get();

    LOG_INFO << "TilingService: Both inference branches were stitched successfully.";

    co_return result;
}
