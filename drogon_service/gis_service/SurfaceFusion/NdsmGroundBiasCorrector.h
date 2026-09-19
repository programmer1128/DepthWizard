// analyzes the AI's metric height prediction on purely flat ground
// if the AI has a systemic offset (eg: all flat ground reads as +0.32 meters), 
// this service calculates that robust median offset and gently subtracts it globally 
// to reduce the terrain baseline exactly to 0.0 meters without distorting buildings

#pragma once

#include <vector>
#include <cstdint>
#include <string>
#include "../structures/CommonTypes.h"
#include "../SemanticContext/GroundSurfaceService.h"



// encapsulates the adjusted nDSM and metadata about the correction
struct NdsmCorrectionResult 
{
    RasterGrid<float> correctedMetricNdsm; // micro-adjusted above-ground heights
    float estimatedGroundBias{0.0f};    // the exact offset subtracted
    size_t supportCount{0};         // no. of pure ground pixels used for the median
    bool correctionApplied{false};     // true if we had enough ground to safely correct
    RasterGrid<float> confidence;    // model confidence carried forward
    std::string warning;       // populated if support was too low
};



class NdsmGroundBiasCorrector 
{
    public:
    
    // calculates the median nDSM error on strict ground pixels and subtracts it
    
    // metricNdsm: raw stitched AI nDSM
    // groundMask: strict boolean mask indicating safe ground pixels
    // confidence: raw AI confidence raster.

    // NdsmCorrectionResult: the adjusted nDSM and mathematical correction stats
    
    static NdsmCorrectionResult correct(
        const RasterGrid<float>& metricNdsm,
        const GroundMask& groundMask,
        const RasterGrid<float>& confidence);
};