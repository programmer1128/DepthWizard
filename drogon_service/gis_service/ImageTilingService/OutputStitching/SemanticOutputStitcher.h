#pragma once
#include "../../structures/SemanticInferenceTypes.h"
#include "../SemanticInference/SemanticInferenceConfig.h"

class SemanticOutputStitcher
{
public:
    // Blends overlapping semantic logits -> SemanticInferenceBundle is returned : finalized, stitched global semantic layers
    static SemanticInferenceBundle stitch(
        const SemanticTiledPayload& payload,
        const SemanticInferenceConfig& config);
};
