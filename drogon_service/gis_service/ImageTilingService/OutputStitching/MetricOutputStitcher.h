#pragma once
#include "../../structures/InferenceStructs.h"
#include "../../utils/TilingTypes.h"

class MetricOutputStitcher
{
public:
    // Blends overlapping metric nDSM tiles and semantic logits -> InferenceBundle ie returned : finalized, stitched global metric surface
    static InferenceBundle stitch(const TiledInferencePayload &payload);
};