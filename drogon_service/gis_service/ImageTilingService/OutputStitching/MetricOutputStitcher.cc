#include "MetricOutputStitcher.h"
#include <cmath>
#include <omp.h>
#include <stdexcept>
#include <trantor/utils/Logger.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846f
#endif

InferenceBundle MetricOutputStitcher::stitch(const TiledInferencePayload &payload)
{
    // failsafe to prevent segmentation faults from empty arrays
    if (payload.allTiles.empty() || payload.globalWidth <= 0 || payload.globalHeight <= 0)
    {
        throw std::runtime_error("MetricOutputStitcher: Invalid or empty inference payload provided.");
    }

    const int gw = payload.globalWidth;  // global width (no. of pixels)
    const int gh = payload.globalHeight; // global height
    const size_t globalPixels = static_cast<size_t>(gw) * gh;

    const int numClasses = payload.allTiles[0].semanticLogits.classCount; // number of semantic categories (6 for GAMUS)

    InferenceBundle bundle; // 9 raster grids -> nDSM, confidence, valid mask, 6 semantic logit channels

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
    initGridFloat(bundle.globalNdsm);
    initGridFloat(bundle.globalNdsmConfidence);
    initGridUint8(bundle.globalValidMask);

    // initialising continuous semantic logit grids
    initGridFloat(bundle.globalSemanticLogits.groundLogits);
    initGridFloat(bundle.globalSemanticLogits.buildingLogits);
    initGridFloat(bundle.globalSemanticLogits.roadLogits);
    initGridFloat(bundle.globalSemanticLogits.vegetationLogits);
    initGridFloat(bundle.globalSemanticLogits.waterLogits);
    initGridFloat(bundle.globalSemanticLogits.unknownLogits);

    // other values in sematic logits
    bundle.globalSemanticLogits.classCount = numClasses;
    bundle.globalSemanticLogits.layout = TensorLayout::CHW; // Channel-Height-Width

    // weight accum for denominator of blending equation : sum(val*wts)/sum(wts)
    std::vector<float> globalWeights(globalPixels, 0.0f);

    // raw pointers for fast OpenMP array access
    float *pNdsm = bundle.globalNdsm.data.data();
    float *pConf = bundle.globalNdsmConfidence.data.data();
    uint8_t *pMask = bundle.globalValidMask.data.data();
    float *pWeight = globalWeights.data();

    float *pGround = bundle.globalSemanticLogits.groundLogits.data.data();
    float *pBldg = bundle.globalSemanticLogits.buildingLogits.data.data();
    float *pRoad = bundle.globalSemanticLogits.roadLogits.data.data();
    float *pVeg = bundle.globalSemanticLogits.vegetationLogits.data.data();
    float *pWater = bundle.globalSemanticLogits.waterLogits.data.data();
    float *pUnknown = bundle.globalSemanticLogits.unknownLogits.data.data();

    LOG_INFO << "[MetricOutputStitcher] Initiating Hann-blending for " << payload.allTiles.size() << " tiles.";

    // accum for numerators and weights
    for (const auto &tile : payload.allTiles)
    {
        // dimensions
        const int tw = tile.placement.paddedWidth;
        const int th = tile.placement.paddedHeight;
        // starting pixels coordinates (top-left corner)
        const int tx = tile.placement.sourceX;
        const int ty = tile.placement.sourceY;

        // precomputing the Hann window curves to eliminate extreme no. of std::cos() calls
        std::vector<float> hann_x_cache(tw);
        for (int c = 0; c < tw; ++c)
        {
            hann_x_cache[c] = 0.5f * (1.0f - std::cos((2.0f * M_PI * c) / (tw - 1.0f)));
        }

        std::vector<float> hann_y_cache(th);
        for (int r = 0; r < th; ++r)
        {
            hann_y_cache[r] = 0.5f * (1.0f - std::cos((2.0f * M_PI * r) / (th - 1.0f)));
        }

// parallel row operations within curr tile -> as we process tiles sequentially, no two threads will ever write to the same global pixel at the same time
#pragma omp parallel for schedule(dynamic)
        for (int r = 0; r < th; ++r)
        {
            float hann_y = hann_y_cache[r]; // read from cache
            int global_r = ty + r;

            if (global_r < 0 || global_r >= gh)
                continue;

            for (int c = 0; c < tw; ++c)
            {
                float hann_x = hann_x_cache[c];                  // read from cache
                float w_hann = std::max(hann_x * hann_y, 1e-6f); // 2D Hann Window

                int global_c = tx + c;
                if (global_c < 0 || global_c >= gw)
                    continue;

                int localIdx = r * tw + c;
                size_t globalIdx = static_cast<size_t>(global_r) * gw + global_c;

                float conf = tile.ndsmConfidence.data[localIdx];
                float active_weight = w_hann * conf;

                // structural data accumulation
                pNdsm[globalIdx] += (tile.metricNdsm.data[localIdx] * active_weight);
                pWeight[globalIdx] += active_weight;
                pConf[globalIdx] += conf; // to be averaged by overlap count later

                if (tile.validMask.data[localIdx] == 1)
                {
                    pMask[globalIdx] = 1;
                }

                // continuous semantic logits accumulation
                pGround[globalIdx] += (tile.semanticLogits.groundLogits.data[localIdx] * active_weight);
                pBldg[globalIdx] += (tile.semanticLogits.buildingLogits.data[localIdx] * active_weight);
                pRoad[globalIdx] += (tile.semanticLogits.roadLogits.data[localIdx] * active_weight);
                pVeg[globalIdx] += (tile.semanticLogits.vegetationLogits.data[localIdx] * active_weight);
                pWater[globalIdx] += (tile.semanticLogits.waterLogits.data[localIdx] * active_weight);
                pUnknown[globalIdx] += (tile.semanticLogits.unknownLogits.data[localIdx] * active_weight);
            }
        }
    }

    // div by weights (finalisation)
#pragma omp parallel for simd schedule(static)
    for (size_t i = 0; i < globalPixels; ++i)
    {
        float w_sum = pWeight[i];
        if (w_sum > 1e-6f)
        {
            pNdsm[i] /= w_sum;
            pGround[i] /= w_sum;
            pBldg[i] /= w_sum;
            pRoad[i] /= w_sum;
            pVeg[i] /= w_sum;
            pWater[i] /= w_sum;
            pUnknown[i] /= w_sum;
        }
        else
        {
            pNdsm[i] = 0.0f; // failsafe for unweighted NoData regions
        }

        // in a standard stride, a pixel is covered by max 4 overlapping tiles -> strict statistical probability between 0.0 and 1.0 (0% to 100%)
        pConf[i] = std::min(pConf[i] / 4.0f, 1.0f);
    }

    // the model metadata is hardcoded for the InferenceBundle -> since it was removed from the individual tiles to save memory
    bundle.models.nDsmModel.modelName = "DepthAnythingV2-GAMUS";
    bundle.models.nDsmModel.modelVersion = "1.0";

    bundle.models.semanticModel.modelName = "GAMUS-Semantic-Segmentation";
    bundle.models.semanticModel.modelVersion = "1.0";

    LOG_INFO << "[MetricOutputStitcher] Finalized global inference matrix natively in meters.";
    return bundle;
}