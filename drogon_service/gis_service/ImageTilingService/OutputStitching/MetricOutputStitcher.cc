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

    constexpr int expectedSemanticClassCount = 6;
    const int numClasses = expectedSemanticClassCount;

     for (const auto& tile : payload.allTiles)
     {
         const int tileWidth = tile.placement.paddedWidth;
         const int tileHeight = tile.placement.paddedHeight;
 
         if (tileWidth <= 0 || tileHeight <= 0)
         {
             throw std::invalid_argument(
                 "MetricOutputStitcher: Tile dimensions must be positive.");
         }
 
         const std::size_t expectedSize =
             static_cast<std::size_t>(tileWidth) *
             static_cast<std::size_t>(tileHeight);
 
         const auto validateGrid =
             [&](const auto& grid, const char* gridName)
             {
                 if (grid.width != tileWidth ||
                     grid.height != tileHeight ||
                     grid.data.size() != expectedSize)
                 {
                     throw std::invalid_argument(
                         "MetricOutputStitcher: " +
                         std::string(gridName) +
                         " shape/data mismatch for tile " +
                         std::to_string(tile.tileId));
                 }
             };

         validateGrid(tile.metricNdsm, "metricNdsm");
         validateGrid(tile.ndsmConfidence, "ndsmConfidence");
         validateGrid(tile.validMask, "validMask");

         validateGrid(
             tile.semanticLogits.otherLogits,
             "otherLogits");

         validateGrid(
             tile.semanticLogits.groundLogits,
             "groundLogits");

         validateGrid(
             tile.semanticLogits.lowVegetationLogits,
             "lowVegetationLogits");

         validateGrid(
             tile.semanticLogits.buildingLogits,
             "buildingLogits");
 
         validateGrid(
             tile.semanticLogits.roadLogits,
             "roadLogits");
 
         validateGrid(
             tile.semanticLogits.waterLogits,
             "waterLogits");

         if (tile.semanticLogits.classCount !=
             expectedSemanticClassCount)
         {
             throw std::invalid_argument(
                 "MetricOutputStitcher: Expected exactly six "
                 "semantic classes.");
         }

         if (tile.semanticLogits.layout != TensorLayout::CHW)
         {
             throw std::invalid_argument(
                 "MetricOutputStitcher: Semantic logits must use "
                 "CHW layout.");
         }

         const auto& placement = tile.placement;

         if (placement.validStartX < 0 ||
             placement.validStartY < 0 ||
             placement.validWidth < 0 ||
             placement.validHeight < 0 ||
             placement.validStartX > tileWidth ||
             placement.validStartY > tileHeight ||
             placement.validWidth >
                 tileWidth - placement.validStartX ||
             placement.validHeight >
                 tileHeight - placement.validStartY)
         {
             throw std::invalid_argument(
                 "MetricOutputStitcher: Invalid tile valid-region "
                 "placement.");
         }
     }

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
    initGridFloat(bundle.globalNdsm);           // final blended physical height of above-ground structures in meters
    initGridFloat(bundle.globalNdsmConfidence); // normalized statistical probability of how much the model trusts its own elevation prediction for that specific pixel -> [0.0, 1.0]
    initGridUint8(bundle.globalValidMask);      // boolean flags -> to identify whether the pixel contains clear data or clouds/deep shadows

    // initialising continuous semantic logit grids
    // they contain  raw, continuous mathematical probability scores directly from the neural network -> strictly unnormalized logits, not percentages
    initGridFloat(bundle.globalSemanticLogits.otherLogits);
    initGridFloat(bundle.globalSemanticLogits.groundLogits);
    initGridFloat(bundle.globalSemanticLogits.lowVegetationLogits);
    initGridFloat(bundle.globalSemanticLogits.buildingLogits);
    initGridFloat(bundle.globalSemanticLogits.roadLogits);
    initGridFloat(bundle.globalSemanticLogits.waterLogits);

    // other values in sematic logits
    bundle.globalSemanticLogits.classCount = numClasses;
    bundle.globalSemanticLogits.layout = TensorLayout::CHW; // Channel-Height-Width

    // weight accum for denominator of blending equation (weighted avg) : sum(pred_val*wts)/sum(wts)
    std::vector<float> globalWeights(globalPixels, 0.0f); // for nDSM and Logits (w_hann*conf)
    std::vector<float> hannWeights(globalPixels, 0.0f);   // for precise confidence averaging (w_hann)

    // raw pointers for fast OpenMP array access
    float *pNdsm = bundle.globalNdsm.data.data();
    float *pConf = bundle.globalNdsmConfidence.data.data();
    uint8_t *pMask = bundle.globalValidMask.data.data();
    float *pWeight = globalWeights.data();
    float *pHannWeight = hannWeights.data();

    float *pOther = bundle.globalSemanticLogits.otherLogits.data.data();
    float *pGround = bundle.globalSemanticLogits.groundLogits.data.data();
    float *pLowVegetation = bundle.globalSemanticLogits.lowVegetationLogits.data.data();
    float *pBldg = bundle.globalSemanticLogits.buildingLogits.data.data();
    float *pRoad = bundle.globalSemanticLogits.roadLogits.data.data();
    float *pWater = bundle.globalSemanticLogits.waterLogits.data.data();

    LOG_INFO << "[MetricOutputStitcher] Initiating Hann-blending for " << payload.allTiles.size() << " tiles.";

    // accum for numerators and weights
    for (const auto &tile : payload.allTiles) // itr through input vector
    {
        // dimensions
        const int tw = tile.placement.paddedWidth;
        const int th = tile.placement.paddedHeight;
        // starting pixels coordinates (top-left corner)
        const int tx = tile.placement.sourceX;
        const int ty = tile.placement.sourceY;

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
        for (int r = 0; r < th; ++r)
        {
            float hann_y = hann_y_cache[r]; // read from cache
            int global_r = ty + r;

            if (global_r < 0 || global_r >= gh)
                continue;

            for (int c = 0; c < tw; ++c)
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

                float conf = tile.ndsmConfidence.data[localIdx];
                float active_weight = w_hann * conf;

                // structural data accumulation
                pNdsm[globalIdx] += (tile.metricNdsm.data[localIdx] * active_weight);
                pWeight[globalIdx] += active_weight;

                // FIX 4 : Confidence and Hann weights accum
                pConf[globalIdx] += (conf * w_hann);
                pHannWeight[globalIdx] += w_hann;

                // pConf[globalIdx] += conf; // to be averaged by overlap count later

                if (tile.validMask.data[localIdx] == 1)
                {
                    pMask[globalIdx] = 1;
                }

                // continuous semantic logits accumulation
                pOther[globalIdx] += (tile.semanticLogits.otherLogits.data[localIdx] * active_weight);
                pGround[globalIdx] += (tile.semanticLogits.groundLogits.data[localIdx] * active_weight);
                pLowVegetation[globalIdx] += (tile.semanticLogits.lowVegetationLogits.data[localIdx] * active_weight);
                pBldg[globalIdx] += (tile.semanticLogits.buildingLogits.data[localIdx] * active_weight);
                pRoad[globalIdx] += (tile.semanticLogits.roadLogits.data[localIdx] * active_weight);
                pWater[globalIdx] += (tile.semanticLogits.waterLogits.data[localIdx] * active_weight);
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
            pNdsm[i] /= w_sum;
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
            pNdsm[i] = 0.0f;
            pConf[i] = 0.0f;

            pOther[i] = 0.0f;
            pGround[i] = 0.0f;
            pLowVegetation[i] = 0.0f;
            pBldg[i] = 0.0f;
            pRoad[i] = 0.0f;
            pWater[i] = 0.0f;
        }

        // // in a standard stride, a pixel is covered by max 4 overlapping tiles -> strict statistical probability between 0.0 and 1.0 (0% to 100%)
        // pConf[i] = std::min(pConf[i] / 4.0f, 1.0f);
    }

    // the model metadata is hardcoded for the InferenceBundle -> since it was removed from the individual tiles to save memory
    bundle.models.nDsmModel.modelName = "DepthAnythingV2-GAMUS";
    bundle.models.nDsmModel.modelVersion = "1.0";

    bundle.models.semanticModel.modelName = "GAMUS-Semantic-Segmentation";
    bundle.models.semanticModel.modelVersion = "1.0";

    LOG_INFO << "[MetricOutputStitcher] Finalized global inference matrix natively in meters.";
    return bundle;
}
