#include "NdsmOutputStitcher.h"
#include <cmath>
#include <limits>
#include <omp.h>
#include <stdexcept>
#include <trantor/utils/Logger.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846f
#endif

NdsmInferenceBundle NdsmOutputStitcher::stitch(
    const NdsmTiledPayload& payload,
    const NdsmStitchingConfig& config)
{
    // failsafe to prevent segmentation faults from empty arrays
    if (payload.tiles.empty() || payload.globalWidth <= 0 || payload.globalHeight <= 0)
    {
        throw std::runtime_error("NdsmOutputStitcher: Invalid or empty inference payload provided.");
    }

    if (!std::isfinite(config.minimumEffectiveWeight) ||
        config.minimumEffectiveWeight <= 0.0f)
    {
        throw std::invalid_argument(
            "NdsmOutputStitcher: Minimum effective weight must be finite and positive.");
    }

    const int gw = payload.globalWidth;  // global width (no. of pixels)
    const int gh = payload.globalHeight; // global height
    const size_t globalPixels = static_cast<size_t>(gw) * gh;

    // FIX 1 : Strict Validation Pass (Checks all arrays against expected sizes)
    for (const auto &tile : payload.tiles)
    {
        const int tw = tile.placement.paddedWidth;
        const int th = tile.placement.paddedHeight;

        if (tw <= 0 || th <= 0)
            throw std::invalid_argument("NdsmOutputStitcher: Tile dimensions must be positive.");

        size_t expected_size = static_cast<size_t>(tw) * th;
        const auto hasExpectedShape =
            [tw, th, expected_size](const auto& grid)
            {
                return grid.width == tw && grid.height == th &&
                    grid.data.size() == expected_size;
            };

        if (!hasExpectedShape(tile.metricNdsm) ||
            !hasExpectedShape(tile.ndsmConfidence) ||
            !hasExpectedShape(tile.validMask))
        {
            throw std::invalid_argument("NdsmOutputStitcher: Tile grid dimensions mismatch.");
        }

        const auto &p = tile.placement;
        if (p.validStartX < 0 || p.validStartY < 0 || p.validWidth < 0 || p.validHeight < 0 ||
            p.validStartX + p.validWidth > tw || p.validStartY + p.validHeight > th)
        {
            throw std::invalid_argument("NdsmOutputStitcher: Invalid tile valid-region placement.");
        }
    }

    NdsmInferenceBundle bundle;

    // lambdas to initialize the existing RasterGrid struct safely
    auto initGridFloat = [&](RasterGrid<float> &grid)
    {
        grid.width = gw;
        grid.height = gh;
        grid.data.assign(globalPixels, 0.0f);
    };

    auto initGridUint8 = [&](RasterGrid<uint8_t> &grid)
    {
        grid.width = gw;
        grid.height = gh;
        grid.data.assign(globalPixels, 0);
    };

    // initialising core structural grids
    initGridFloat(bundle.globalMetricNdsm);     // final blended physical height of above-ground structures in meters
    initGridFloat(bundle.globalNdsmConfidence); // normalized statistical probability of how much the model trusts its own elevation prediction -> [0.0, 1.0]
    initGridUint8(bundle.globalValidMask);      // boolean flags -> to identify whether the pixel contains clear data or clouds/deep shadows

    // weight accum for denominator of blending equation (weighted avg) : sum(pred_val*wts)/sum(wts)
    std::vector<float> globalWeights(globalPixels, 0.0f); // for nDSM (w_hann*conf)
    std::vector<float> hannWeights(globalPixels, 0.0f);   // for precise confidence averaging (w_hann)

    // raw pointers for fast OpenMP array access
    float *pNdsm = bundle.globalMetricNdsm.data.data();
    float *pConf = bundle.globalNdsmConfidence.data.data();
    uint8_t *pMask = bundle.globalValidMask.data.data();
    float *pWeight = globalWeights.data();
    float *pHannWeight = hannWeights.data();

    LOG_INFO << "[NdsmOutputStitcher] Initiating Hann-blending for " << payload.tiles.size() << " structural tiles.";

    // accum for numerators and weights
    for (const auto &tile : payload.tiles)
    {
        // dimensions
        const int tw = tile.placement.paddedWidth;
        const int th = tile.placement.paddedHeight;
        // starting pixels coordinates (top-left corner)
        const int tx = tile.placement.sourceX;
        const int ty = tile.placement.sourceY;

        // Explicit valid bounds padding logic applied to structural stitcher
        const int vStartX = tile.placement.validStartX;
        const int vStartY = tile.placement.validStartY;
        const int vEndX = vStartX + tile.placement.validWidth;
        const int vEndY = vStartY + tile.placement.validHeight;

        // FIX 2 : Prevention of division-by-zero on 1x1 tiles
        float div_w = (tw > 1) ? static_cast<float>(tw - 1) : 1.0f;
        float div_h = (th > 1) ? static_cast<float>(th - 1) : 1.0f;

        // precomputing the Hann window curves to eliminate extreme no. of std::cos() calls
        std::vector<float> hann_x_cache(tw);
        for (int c = 0; c < tw; ++c)
        {
            hann_x_cache[c] = 0.5f * (1.0f - std::cos((2.0f * M_PI * c) / div_w));
        }

        std::vector<float> hann_y_cache(th);
        for (int r = 0; r < th; ++r)
        {
            hann_y_cache[r] = 0.5f * (1.0f - std::cos((2.0f * M_PI * r) / div_h));
        }

// parallel row operations within curr tile -> as we process tiles sequentially, no two threads will ever write to the same global pixel at the same time
#pragma omp parallel for schedule(dynamic)
        for (int r = vStartY; r < vEndY; ++r)
        {
            float hann_y = hann_y_cache[r]; // read from cache
            int global_r = ty + r;

            if (global_r < 0 || global_r >= gh)
                continue;

            for (int c = vStartX; c < vEndX; ++c)
            {
                int global_c = tx + c;
                if (global_c < 0 || global_c >= gw)
                    continue;

                int localIdx = r * tw + c;
                size_t globalIdx = static_cast<size_t>(global_r) * gw + global_c;

                // FIX 3 : Strict Valid Mask Gating
                uint8_t isValid = tile.validMask.data[localIdx];
                if (isValid != 0 && isValid != 1)
                    continue;
                if (isValid == 0)
                    continue;

                float hann_x = hann_x_cache[c];                  // read from cache
                const float w_hann = config.hannWindowEnabled
                    ? std::max(hann_x * hann_y, config.minimumEffectiveWeight)
                    : 1.0f;

                float conf = tile.ndsmConfidence.data[localIdx];
                const float ndsm = tile.metricNdsm.data[localIdx];
                if (!std::isfinite(ndsm) || !std::isfinite(conf) ||
                    conf < 0.0f || conf > 1.0f)
                {
                    continue;
                }
                const float active_weight = w_hann *
                    (config.confidenceWeightingEnabled ? conf : 1.0f);

                if (active_weight <= 0.0f)
                    continue;

                // structural data accumulation
                pNdsm[globalIdx] += (ndsm * active_weight);
                pWeight[globalIdx] += active_weight;

                // FIX 4 : Confidence and Hann weights accum
                pConf[globalIdx] += (conf * w_hann);
                pHannWeight[globalIdx] += w_hann;

                pMask[globalIdx] = 1;
            }
        }
    }

    // div by weights (finalisation)
#pragma omp parallel for simd schedule(static)
    for (size_t i = 0; i < globalPixels; ++i)
    {
        float w_sum = pWeight[i];
        if (w_sum > 0.0f)
        {
            pNdsm[i] /= w_sum;

            // FIX 6 : Exact weighted average for model confidence
            float h_sum = pHannWeight[i];
            if (h_sum >= 1e-7f)
            {
                pConf[i] = std::min(pConf[i] / h_sum, 1.0f);
            }
            else
            {
                pConf[i] = 0.0f;
            }
        }
        else
        {
            // failsafe for unweighted NoData regions
            pNdsm[i] = std::numeric_limits<float>::quiet_NaN();
            pConf[i] = 0.0f;
            pMask[i] = 0;
        }
    }

    // Assign mapped structural model
    bundle.model.modelName = payload.model.modelName;
    bundle.model.modelVersion = payload.model.modelVersion;

    LOG_INFO << "[NdsmOutputStitcher] Finalized global structural inference matrix natively in meters.";
    return bundle;
}
