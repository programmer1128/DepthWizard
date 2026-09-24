#pragma once
#include "../../structures/NdsmInferenceTypes.h"

class NdsmOutputStitcher
{
public:
    // Blends overlapping metric nDSM tiles -> NdsmInferenceBundle is returned
    static NdsmInferenceBundle stitch(const NdsmTiledPayload &payload);
};