#include "SemanticOutputStitcher.h"
#include <cmath>
#include <omp.h>
#include <stdexcept>
#include <algorithm>
#include <trantor/utils/Logger.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846f
#endif

SemanticInferenceBundle SemanticOutputStitcher::stitch(
    const SemanticTiledPayload& payload,
    const SemanticInferenceConfig& config)
{
    // failsafe to prevent segmentation faults from empty arrays
    if (payload.tiles.empty() || payload.globalWidth <= 0 || payload.globalHeight <= 0)
    {
        throw std::runtime_error("SemanticOutputStitcher: Invalid or empty semantic payload provided.");
    }

    if (!std::isfinite(config.minEffectiveWeight) ||
        config.minEffectiveWeight <= 0.0f)
    {
        throw std::invalid_argument(
            "SemanticOutputStitcher: Minimum effective weight must be finite and positive.");
    }

    const int gw = payload.globalWidth;  // global width (no. of pixels)
    const int gh = payload.globalHeight; // global height
    const size_t globalPixels = static_cast<size_t>(gw) * gh;

    const int expectedSemanticClassCount = 6; // number of semantic categories (6 for GAMUS)

    // FIX 1 : Strict Validation Pass (Checks all logic buffers)
    for (const auto &tile : payload.tiles)
    {
        const int tw = tile.placement.paddedWidth;
        const int th = tile.placement.paddedHeight;

        if (tw <= 0 || th <= 0)
            throw std::invalid_argument("SemanticOutputStitcher: Tile dimensions must be positive.");

        if (tile.semanticSchemaId != DEPTHWIZARD_SEMANTIC_SCHEMA_ID ||
            tile.semanticLogits.classCount != expectedSemanticClassCount ||
            tile.semanticLogits.layout != TensorLayout::CHW)
        {
            throw std::invalid_argument("SemanticOutputStitcher: Inconsistent semantic class count or layout.");
        }

        size_t expected_size = static_cast<size_t>(tw) * th;
        const auto hasExpectedShape =
            [tw, th, expected_size](const auto& grid)
            {
                return grid.width == tw && grid.height == th &&
                    grid.data.size() == expected_size;
            };

        if (!hasExpectedShape(tile.semanticLogits.otherLogits) ||
            !hasExpectedShape(tile.semanticLogits.groundLogits) ||
            !hasExpectedShape(tile.semanticLogits.lowVegetationLogits) ||
            !hasExpectedShape(tile.semanticLogits.buildingLogits) ||
            !hasExpectedShape(tile.semanticLogits.roadLogits) ||
            !hasExpectedShape(tile.semanticLogits.waterLogits) ||
            !hasExpectedShape(tile.validMask))
        {
            throw std::invalid_argument("SemanticOutputStitcher: Semantic grid dimensions mismatch.");
        }

        if (tile.confidence.isValid() && !hasExpectedShape(tile.confidence))
        {
            throw std::invalid_argument("SemanticOutputStitcher: Confidence grid dimensions mismatch.");
        }

        const auto &p = tile.placement;
        // Explicitly honor valid bounds padding logic so we don't accidentally stitch bad edge pixels
        if (p.validStartX < 0 || p.validStartY < 0 || p.validWidth < 0 || p.validHeight < 0 ||
            p.validStartX + p.validWidth > tw || p.validStartY + p.validHeight > th)
        {
            throw std::invalid_argument("SemanticOutputStitcher: Invalid tile valid-region placement.");
        }
    }

    SemanticInferenceBundle bundle;
    bundle.semanticSchemaId = DEPTHWIZARD_SEMANTIC_SCHEMA_ID; // Explicit schema tag

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

    // initialising continuous semantic logit grids securely
    initGridFloat(bundle.globalSemanticLogits.otherLogits);
    initGridFloat(bundle.globalSemanticLogits.groundLogits);
    initGridFloat(bundle.globalSemanticLogits.lowVegetationLogits);
    initGridFloat(bundle.globalSemanticLogits.buildingLogits);
    initGridFloat(bundle.globalSemanticLogits.roadLogits);
    initGridFloat(bundle.globalSemanticLogits.waterLogits);

    bundle.globalSemanticLogits.classCount = expectedSemanticClassCount;
    bundle.globalSemanticLogits.layout = TensorLayout::CHW; // Channel-Height-Width

    initGridFloat(bundle.globalConfidence);
    initGridUint8(bundle.globalValidMask);

    // weight accum for denominator of blending equation (weighted avg) : sum(pred_val*wts)/sum(wts)
    std::vector<float> globalWeights(globalPixels, 0.0f); // for Logits (w_hann*conf)
    std::vector<float> hannWeights(globalPixels, 0.0f);   // for precise confidence averaging (w_hann)

    // raw pointers for fast OpenMP array access
    float *pOther = bundle.globalSemanticLogits.otherLogits.data.data();
    float *pGround = bundle.globalSemanticLogits.groundLogits.data.data();
    float *pLowVegetation = bundle.globalSemanticLogits.lowVegetationLogits.data.data();
    float *pBldg = bundle.globalSemanticLogits.buildingLogits.data.data();
    float *pRoad = bundle.globalSemanticLogits.roadLogits.data.data();
    float *pWater = bundle.globalSemanticLogits.waterLogits.data.data();

    float *pConf = bundle.globalConfidence.data.data();
    uint8_t *pMask = bundle.globalValidMask.data.data();
    float *pWeight = globalWeights.data();
    float *pHannWeight = hannWeights.data();

    LOG_INFO << "[SemanticOutputStitcher] Initiating Hann-blending for " << payload.tiles.size() << " semantic tiles.";

    // accum for numerators and weights
    for (const auto &tile : payload.tiles) // itr through input vector
    {
        // dimensions
        const int tw = tile.placement.paddedWidth;
        const int th = tile.placement.paddedHeight;
        // starting pixels coordinates (top-left corner)
        const int tx = tile.placement.sourceX;
        const int ty = tile.placement.sourceY;

        // Honor explicit valid bounds over basic tile bounds
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
            hann_x_cache[c] = 0.5f * (1.0f - std::cos((2.0f * M_PI * c) / div_w));

        std::vector<float> hann_y_cache(th);
        for (int r = 0; r < th; ++r)
            hann_y_cache[r] = 0.5f * (1.0f - std::cos((2.0f * M_PI * r) / div_h));

        bool hasSemanticConf = tile.confidence.isValid();

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
                    ? std::max(hann_x * hann_y, config.minEffectiveWeight)
                    : 1.0f;

                float conf_mult = hasSemanticConf ? tile.confidence.data[localIdx] : 1.0f;
                if (!std::isfinite(conf_mult) || conf_mult < 0.0f || conf_mult > 1.0f)
                    continue;

                const float other = tile.semanticLogits.otherLogits.data[localIdx];
                const float ground = tile.semanticLogits.groundLogits.data[localIdx];
                const float lowVegetation = tile.semanticLogits.lowVegetationLogits.data[localIdx];
                const float building = tile.semanticLogits.buildingLogits.data[localIdx];
                const float road = tile.semanticLogits.roadLogits.data[localIdx];
                const float water = tile.semanticLogits.waterLogits.data[localIdx];
                if (!std::isfinite(other) || !std::isfinite(ground) ||
                    !std::isfinite(lowVegetation) ||
                    !std::isfinite(building) || !std::isfinite(road) ||
                    !std::isfinite(water))
                {
                    continue;
                }

                float active_weight = w_hann * conf_mult;

                if (active_weight <= 0.0f)
                    continue;

                // continuous semantic logits accumulation explicitly mapped
                pOther[globalIdx] += other * active_weight;
                pGround[globalIdx] += ground * active_weight;
                pLowVegetation[globalIdx] += lowVegetation * active_weight;
                pBldg[globalIdx] += building * active_weight;
                pRoad[globalIdx] += road * active_weight;
                pWater[globalIdx] += water * active_weight;

                pWeight[globalIdx] += active_weight;
                pHannWeight[globalIdx] += w_hann;

                // FIX 4 : Confidence and Hann weights accum
                pConf[globalIdx] += (conf_mult * w_hann);

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
            pOther[i] /= w_sum;
            pGround[i] /= w_sum;
            pLowVegetation[i] /= w_sum;
            pBldg[i] /= w_sum;
            pRoad[i] /= w_sum;
            pWater[i] /= w_sum;

            // FIX 6 : Exact weighted average for model confidence
            // only compute confidence if the pixel as a whole contains valid predictions
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
            pOther[i] = 0.0f;
            pGround[i] = 0.0f;
            pLowVegetation[i] = 0.0f;
            pBldg[i] = 0.0f;
            pRoad[i] = 0.0f;
            pWater[i] = 0.0f;
            pConf[i] = 0.0f;
            pMask[i] = 0;
        }
    }

    bundle.model.modelName = payload.model.modelName;
    bundle.model.modelVersion = payload.model.modelVersion;

    LOG_INFO << "[SemanticOutputStitcher] Finalized global semantic logit inference.";
    return bundle;
}
