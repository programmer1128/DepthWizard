// implements the Ground Bias Correction using robust median statistics
// abandons RANSAC entirely in favor of a flat scalar subtraction

#include "NdsmGroundBiasCorrector.h"
#include <algorithm>
#include <cmath>
#include <omp.h>

NdsmCorrectionResult NdsmGroundBiasCorrector::correct(
    const RasterGrid<float>& metricNdsm,
    const GroundMask& groundMask,
    const RasterGrid<float>& confidence)
{
    NdsmCorrectionResult result;
    result.confidence = confidence;

    int w = metricNdsm.width;
    int h = metricNdsm.height;
    size_t totalPixels = static_cast<size_t>(w) * h;

    // allocate the output raster grid
    result.correctedMetricNdsm.width = w;
    result.correctedMetricNdsm.height = h;
    result.correctedMetricNdsm.data.resize(totalPixels, 0.0f);

    // fast pointer access
    const float* in_ndsm = metricNdsm.data.data();
    const uint8_t* in_mask = groundMask.isValidGround.data.data();
    float* out_ndsm = result.correctedMetricNdsm.data.data();


    // gather all nDSM values that fall strictly on pure ground
    // we pre-allocate based on the valid count found in Module 4
    std::vector<float> groundSamples;
    if (groundMask.validGroundCount > 0) 
    {
        groundSamples.reserve(groundMask.validGroundCount);
    }

    // single-threaded gathering (OpenMP push_back on a dynamic vector is unsafe without heavy locks)
    for (size_t i = 0; i < totalPixels; ++i) 
    {
        if (in_mask[i] == 1 && !std::isnan(in_ndsm[i])) 
        {
            groundSamples.push_back(in_ndsm[i]);
        }
    }

    result.supportCount = groundSamples.size();
    float bias = 0.0f;



    // Safety Check: Do we have enough pure ground to trust a statistical median?
    // we require at least 500 valid ground pixels to attempt a global correction
    if (result.supportCount < 500) 
    {
        result.warning = "Insufficient pure ground pixels to calculate bias offset! Bypassing correction!";
        result.correctionApplied = false;
        
        // copy the data directly without correction using multi-threading
        #pragma omp parallel for simd schedule(static)
        for (size_t i = 0; i < totalPixels; ++i) 
        {
            out_ndsm[i] = in_ndsm[i];
        }
        
        return result;
    }



    // now we calculate robust median (More resistant to structural outliers than ordinary mean)
    // we use std::nth_element, which is significantly faster than a full sort (O(N) vs O(N log N))
    size_t medianIndex = groundSamples.size() / 2;
    std::nth_element(groundSamples.begin(), groundSamples.begin() + medianIndex, groundSamples.end());
    bias = groundSamples[medianIndex];


    // safety Guardrails on the bias
    // if the model is suddenly claiming the ground is 50 meters off, something is wrong
    // we clamp the maximum permissible scalar correction to +/- 5 meters
    bias = std::clamp(bias, -5.0f, 5.0f);
    
    result.estimatedGroundBias = bias;
    result.correctionApplied = true;



    // we apply the flat scalar subtraction across the entire grid
    // a 10m building (10.32m raw - 0.32m bias) correctly becomes exactly 10.00m
    #pragma omp parallel for simd schedule(static)
    for (size_t i = 0; i < totalPixels; ++i) 
    {
        if (!std::isnan(in_ndsm[i])) 
        {
            // ensure nDSM never drops below zero (we dont want underground buildings)
            out_ndsm[i] = std::max(0.0f, in_ndsm[i] - bias);
        } 
        else 
        {
            out_ndsm[i] = std::numeric_limits<float>::quiet_NaN();
        }
    }

    return result;
}