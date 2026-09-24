#pragma once

#include <drogon/drogon.h>
#include <drogon/utils/coroutine.h>
#include "../../structures/IngestionStructs.h"
#include "../../structures/SemanticInferenceTypes.h"
#include "SemanticInferenceConfig.h"

class SemanticInferenceService
{
public:
    // The single public facade for the semantic inference branch.
    // Coordinates the asynchronous dispatch of tiles and the synchronous 
    // Hann-window stitching of the returned multi-channel logits.
    static drogon::Task<SemanticInferenceBundle> generateGlobalSemantics(
        const SceneInput& scene,
        const ImageQualityResult& quality,
        const SemanticInferenceConfig& config);
};