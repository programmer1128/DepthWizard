#include "SemanticOutputStitcher.h"
#include <cmath>
#include <omp.h>
#include <stdexcept>
#include <algorithm>
#include <trantor/utils/Logger.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846f
#endif

SemanticInferenceBundle SemanticOutputStitcher::stitch(const SemanticTiledPayload &payload)
{
    // failsafe to prevent segmentation faults from empty arrays
    if (payload.tiles.empty() || payload.globalWidth <= 0 || payload.globalHeight <= 0)
    {
        throw std::runtime_error("SemanticOutputStitcher: Invalid or empty semantic payload provided.");
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

        if (tile.semanticLogits.classCount != expectedSemanticClassCount ||
            tile.semanticLogits.layout != TensorLayout::CHW)
        {
            throw std::invalid_argument("SemanticOutputStitcher: Inconsistent semantic class count or layout.");
        }

        size_t expected_size = static_cast<size_t>(tw) * th;
        if (tile.semanticLogits.groundLogits.data.size() != expected_size ||
            tile.semanticLogits.buildingLogits.data.size() != expected_size ||
            tile.semanticLogits.roadLogits.data.size() != expected_size ||
            tile.semanticLogits.vegetationLogits.data.size() != expected_size ||
            tile.semanticLogits.waterLogits.data.size() != expected_size ||
            tile.semanticLogits.unknownLogits.data.size() != expected_size ||
            tile.validMask.data.size() != expected_size)
        {
            throw std::invalid_argument("SemanticOutputStitcher: Semantic grid dimensions mismatch.");
        }

        if (tile.confidence.isValid() && tile.confidence.data.size() != expected_size)
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
    initGridFloat(bundle.globalSemanticLogits.unknownLogits);
    initGridFloat(bundle.globalSemanticLogits.groundLogits);
    initGridFloat(bundle.globalSemanticLogits.buildingLogits);
    initGridFloat(bundle.globalSemanticLogits.roadLogits);
    initGridFloat(bundle.globalSemanticLogits.vegetationLogits);
    initGridFloat(bundle.globalSemanticLogits.waterLogits);

    bundle.globalSemanticLogits.classCount = expectedSemanticClassCount;
    bundle.globalSemanticLogits.layout = TensorLayout::CHW; // Channel-Height-Width

    initGridFloat(bundle.globalConfidence);
    initGridUint8(bundle.globalValidMask);

    // weight accum for denominator of blending equation (weighted avg) : sum(pred_val*wts)/sum(wts)
    std::vector<float> globalWeights(globalPixels, 0.0f); // for Logits (w_hann*conf)
    std::vector<float> hannWeights(globalPixels, 0.0f);   // for precise confidence averaging (w_hann)

    // raw pointers for fast OpenMP array access
    float *pUnknown = bundle.globalSemanticLogits.unknownLogits.data.data();
    float *pGround = bundle.globalSemanticLogits.groundLogits.data.data();
    float *pBldg = bundle.globalSemanticLogits.buildingLogits.data.data();
    float *pRoad = bundle.globalSemanticLogits.roadLogits.data.data();
    float *pVeg = bundle.globalSemanticLogits.vegetationLogits.data.data();
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
                if (isValid == 0)
                    continue;

                float hann_x = hann_x_cache[c];                  // read from cache
                float w_hann = std::max(hann_x * hann_y, 1e-6f); // 2D Hann Window

                float conf_mult = hasSemanticConf ? tile.confidence.data[localIdx] : 1.0f;
                float active_weight = w_hann * conf_mult;

                // continuous semantic logits accumulation explicitly mapped
                pUnknown[globalIdx] += (tile.semanticLogits.unknownLogits.data[localIdx] * active_weight);
                pGround[globalIdx] += (tile.semanticLogits.groundLogits.data[localIdx] * active_weight);
                pBldg[globalIdx] += (tile.semanticLogits.buildingLogits.data[localIdx] * active_weight);
                pRoad[globalIdx] += (tile.semanticLogits.roadLogits.data[localIdx] * active_weight);
                pVeg[globalIdx] += (tile.semanticLogits.vegetationLogits.data[localIdx] * active_weight);
                pWater[globalIdx] += (tile.semanticLogits.waterLogits.data[localIdx] * active_weight);

                pWeight[globalIdx] += active_weight;
                pHannWeight[globalIdx] += w_hann;

                // FIX 4 : Confidence and Hann weights accum
                if (hasSemanticConf)
                {
                    pConf[globalIdx] += (conf_mult * w_hann);
                }

                pMask[globalIdx] = 1;
            }
        }
    }

    // div by weights (finalisation)
#pragma omp parallel for simd schedule(static)
    for (size_t i = 0; i < globalPixels; ++i)
    {
        float w_sum = pWeight[i];
        if (w_sum >= 1e-7f) // FIX 5 : Lowered tolerance to rescue extreme edge pixels
        {
            pUnknown[i] /= w_sum;
            pGround[i] /= w_sum;
            pBldg[i] /= w_sum;
            pRoad[i] /= w_sum;
            pVeg[i] /= w_sum;
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
            pUnknown[i] = 0.0f;
            pGround[i] = 0.0f;
            pBldg[i] = 0.0f;
            pRoad[i] = 0.0f;
            pVeg[i] = 0.0f;
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