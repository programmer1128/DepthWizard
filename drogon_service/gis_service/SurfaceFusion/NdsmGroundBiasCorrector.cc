#include "NdsmGroundBiasCorrector.h"
#include <algorithm>
#include <cmath>
#include <omp.h>
#include <stdexcept>
#include <limits>

NdsmCorrectionResult NdsmGroundBiasCorrector::correct(
    const RasterGrid<float>& metricNdsm,
    const GroundMask& groundMask,
    const RasterGrid<float>& confidence)
{
    // Validate inputs
    if (!metricNdsm.isValid())
    {
        throw std::invalid_argument(
            "NdsmGroundBiasCorrector: Invalid metric nDSM grid.");
    }

    const int w = metricNdsm.width;
    const int h = metricNdsm.height;

    const auto matchesNdsmShape =
        [w, h](const auto& grid)
        {
            return grid.isValid() &&
                grid.width == w &&
                grid.height == h;
        };

    if (!matchesNdsmShape(groundMask.isValidGround) ||
        !matchesNdsmShape(groundMask.weights) ||
        !matchesNdsmShape(confidence))
    {
        throw std::invalid_argument(
            "NdsmGroundBiasCorrector: Input raster dimensions are inconsistent.");
    }

    const size_t totalPixels =
        static_cast<size_t>(w) * static_cast<size_t>(h);

    if (groundMask.validGroundCount > totalPixels)
    {
        throw std::invalid_argument(
            "NdsmGroundBiasCorrector: Ground support count exceeds raster size.");
    }
    
    NdsmCorrectionResult result;
    result.confidence = confidence;

    // Allocate the output raster grid
    result.correctedMetricNdsm.width = w;
    result.correctedMetricNdsm.height = h;
    result.correctedMetricNdsm.data.resize(totalPixels, 0.0f);

    // Fast memory pointers
    const float* in_ndsm = metricNdsm.data.data();
    const uint8_t* in_mask = groundMask.isValidGround.data.data();
    float* out_ndsm = result.correctedMetricNdsm.data.data();

    // Gather all nDSM values that fall strictly on pure ground
    std::vector<float> groundSamples;
    if (groundMask.validGroundCount > 0) 
    {
        groundSamples.reserve(groundMask.validGroundCount);
    }

    // Extract valid ground samples sequentially
    for (size_t i = 0; i < totalPixels; ++i) 
    {
        if (in_mask[i] == 1 && !std::isnan(in_ndsm[i])) 
        {
            groundSamples.push_back(in_ndsm[i]);
        }
    }

    result.supportCount = groundSamples.size();
    float bias = 0.0f;

    // We require at least 500 valid ground pixels to attempt a global statistical correction
    if (result.supportCount < 500) 
    {
        result.warning = "Insufficient pure ground pixels to calculate bias offset! Bypassing correction!";
        result.correctionApplied = false;
        
        // Even if bypassed, apply physical guardrails: max(0) traps trenches, min(850) traps extreme network explosion spikes
        #pragma omp parallel for simd schedule(static)
        for (size_t i = 0; i < totalPixels; ++i) 
        {
            if (!std::isnan(in_ndsm[i])) {
                out_ndsm[i] = std::min(850.0f, std::max(0.0f, in_ndsm[i]));
            } else {
                out_ndsm[i] = std::numeric_limits<float>::quiet_NaN();
            }
        }
        
        return result;
    }

    // Calculate robust median (Resistant to structural outliers)
    size_t medianIndex = groundSamples.size() / 2;
    std::nth_element(groundSamples.begin(), groundSamples.begin() + medianIndex, groundSamples.end());
    bias = groundSamples[medianIndex];

    // Clamp the maximum permissible scalar correction to +/- 5 meters
    bias = std::clamp(bias, -5.0f, 5.0f);
    
    result.estimatedGroundBias = bias;
    result.correctionApplied = true;

    // Apply the flat scalar subtraction across the entire grid and enforce physical ceilings/floors
    #pragma omp parallel for simd schedule(static)
    for (size_t i = 0; i < totalPixels; ++i) 
    {
        if (!std::isnan(in_ndsm[i])) 
        {
            out_ndsm[i] = std::min(850.0f, std::max(0.0f, in_ndsm[i] - bias));
        } 
        else 
        {
            out_ndsm[i] = std::numeric_limits<float>::quiet_NaN();
        }
    }

    return result;
}