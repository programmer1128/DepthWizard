#pragma once
#include "../../structures/NdsmInferenceTypes.h"
#include "../NdsmInference/NdsmInferenceConfig.h"

class NdsmOutputStitcher
{
public:
    // Blends overlapping metric nDSM tiles -> NdsmInferenceBundle is returned
    static NdsmInferenceBundle stitch(
        const NdsmTiledPayload& payload,
        const NdsmStitchingConfig& config);
};
