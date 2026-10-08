#pragma once

#include <memory>
#include <vector>
#include "../../structures/InferenceStructs.h"
#include "../../structures/SemanticInferenceTypes.h"
#include "SemanticInferenceConfig.h"

class SemanticInferenceService
{
public:
    // The single public facade for the semantic inference branch.
    // Coordinates the asynchronous dispatch of tiles and the synchronous 
    // Hann-window stitching of the returned multi-channel logits.
    static SemanticInferenceBundle generateGlobalSemantics(
        int globalWidth,
        int globalHeight,
        const std::vector<std::shared_ptr<TileRequest>>& tiles,
        const SemanticInferenceConfig& config);
};
