#include "BuildingMaskProcessor.h"
#include <opencv2/opencv.hpp>
#include <cmath>
#include <algorithm>

namespace
{
BuildingMaskResult createCleanMaskImpl(
     const SemanticScene& semantics,
     const RasterGrid<float>* metricNdsm,
     const RasterGrid<uint8_t>& validMask,
     const SpatialMetadata& metadata,
     const BuildingReconstructionConfig& config)
{
     BuildingMaskResult result;

     //Configuration Validation
     if (!config.validate())
     {
         result.errorMessage = "Invalid BuildingReconstructionConfig parameters.";
         return result;
     }
     result.thresholdUsed = config.buildingProbabilityThreshold;

     int width = metadata.width;
     int height = metadata.height;

     //strict Input/Invariant Validation
     if (width <= 0 || height <= 0 ||
         semantics.buildingProbability.width != width ||
         semantics.buildingProbability.height != height ||
         semantics.groundProbability.width != width ||
         semantics.groundProbability.height != height ||
         semantics.roadProbability.width != width ||
         semantics.roadProbability.height != height ||
         semantics.vegetationProbability.width != width ||
         semantics.vegetationProbability.height != height ||
         semantics.waterProbability.width != width ||
         semantics.waterProbability.height != height ||
         semantics.semanticConfidence.width != width ||
         semantics.semanticConfidence.height != height ||
         semantics.finalClassMap.width != width ||
         semantics.finalClassMap.height != height ||
         validMask.width != width || validMask.height != height ||
         !semantics.buildingProbability.isValid() ||
         !semantics.groundProbability.isValid() ||
         !semantics.roadProbability.isValid() ||
         !semantics.vegetationProbability.isValid() ||
         !semantics.waterProbability.isValid() ||
         !semantics.semanticConfidence.isValid() ||
         !semantics.finalClassMap.isValid() ||
         !validMask.isValid() ||
         (metricNdsm != nullptr &&
          (!metricNdsm->isValid() ||
           metricNdsm->width != width || metricNdsm->height != height)))
     {

         result.errorMessage = "Grid dimension mismatch or invalid memory buffers.";
         return result;
     }

     // Ensure probability values are finite
     const auto validProbability = [](const RasterGrid<float>& grid)
     {
         return std::all_of(grid.data.begin(), grid.data.end(), [](float p) {
             return std::isfinite(p) && p >= 0.0f && p <= 1.0f;
         });
     };
     if (!validProbability(semantics.buildingProbability) ||
         !validProbability(semantics.groundProbability) ||
         !validProbability(semantics.roadProbability) ||
         !validProbability(semantics.vegetationProbability) ||
         !validProbability(semantics.waterProbability))
     {
         result.errorMessage = "Semantic probabilities contain non-finite values or exceed [0,1].";
         return result;
     }

     for (float confidence : semantics.semanticConfidence.data)
     {
         if (!std::isfinite(confidence) || confidence < 0.0f || confidence > 1.0f)
         {
             result.errorMessage =
                 "Semantic confidence contains non-finite values or exceeds [0,1].";
             return result;
         }
     }

     //Affine-Aware Metric Calculations
     //Area = |GT1 * GT5 - GT2 * GT4|
     double pixelArea = std::abs(metadata.geoTransform[1] * metadata.geoTransform[5] -
                                metadata.geoTransform[2] * metadata.geoTransform[4]);

     // Rectangular pixel resolutions
     double colRes = std::sqrt(metadata.geoTransform[1] * metadata.geoTransform[1] +
                              metadata.geoTransform[4] * metadata.geoTransform[4]);
     double rowRes = std::sqrt(metadata.geoTransform[2] * metadata.geoTransform[2] +
                              metadata.geoTransform[5] * metadata.geoTransform[5]);

     if (pixelArea <= 0.0 || colRes <= 0.0 || rowRes <= 0.0)
     {
         result.errorMessage = "Invalid or zero spatial resolution in metadata. Metric operations cannot proceed.";
         return result;
     }

     //OpenCV Matrices copied from C++ vectors
     cv::Mat validMat(height, width, CV_8UC1, const_cast<uint8_t*>(validMask.data.data()));

     // Primary candidates satisfy the strict semantic decision. Recovery
     // candidates are permitted only when the class is UNKNOWN (not another
     // positively identified class), the building probability remains
     // credible, and the metric nDSM confirms an above-ground object.
     const std::size_t totalPixels =
         static_cast<std::size_t>(width) * static_cast<std::size_t>(height);
     std::vector<uint8_t> candidateBytes(totalPixels, 0);
     std::vector<uint8_t> recoveryBytes(totalPixels, 0);
     std::vector<uint8_t> allowedBytes(totalPixels, 255);
     for (std::size_t index = 0; index < totalPixels; ++index)
     {
         const bool isBuilding =
             semantics.finalClassMap.data[index] == SemanticClass::BUILDING;
         const bool isUnknown =
             semantics.finalClassMap.data[index] == SemanticClass::UNKNOWN;
         const bool probabilityAccepted =
             semantics.buildingProbability.data[index] >=
             config.buildingProbabilityThreshold;
         const bool confidenceAccepted =
             semantics.semanticConfidence.data[index] >=
             config.minBuildingSemanticConfidence;
         const bool hasNdsmHeight =
             metricNdsm != nullptr &&
             std::isfinite(metricNdsm->data[index]) &&
             metricNdsm->data[index] >= config.minRecoveryNdsmHeightMetres;

         const bool allowVegPassage =
             metricNdsm != nullptr &&
             std::isfinite(metricNdsm->data[index]) &&
             metricNdsm->data[index] >= 3.0f &&
             semantics.buildingProbability.data[index] >= 0.02f;

         const float competitorBarrier = allowVegPassage
             ? std::max({semantics.groundProbability.data[index],
                         semantics.roadProbability.data[index],
                         semantics.waterProbability.data[index]})
             : std::max({semantics.groundProbability.data[index],
                         semantics.roadProbability.data[index],
                         semantics.vegetationProbability.data[index],
                         semantics.waterProbability.data[index]});

         const auto cls = semantics.finalClassMap.data[index];
         const bool classRecoverable =
             cls == SemanticClass::UNKNOWN ||
             (cls == SemanticClass::VEGETATION && allowVegPassage);

         const bool recoveredBuilding =
             metricNdsm != nullptr &&
             classRecoverable &&
             semantics.buildingProbability.data[index] >=
                 config.buildingRecoveryProbabilityThreshold &&
             semantics.buildingProbability.data[index] >= competitorBarrier &&
             std::isfinite(metricNdsm->data[index]) &&
             metricNdsm->data[index] >= config.minRecoveryNdsmHeightMetres;

         recoveryBytes[index] = recoveredBuilding ? 255 : 0;
         // A positive ground/road/water/vegetation decision is a barrier,
         // but elevated roofs with building evidence are allowed through.
         allowedBytes[index] = (validMask.data[index] != 0 &&
             (cls == SemanticClass::BUILDING || cls == SemanticClass::UNKNOWN ||
              (cls == SemanticClass::VEGETATION && allowVegPassage))) ? 255 : 0;
         // Primary seed is either a strict semantic building, OR an uncertain pixel with strong probability and physical height
         const bool primarySeed =
             (isBuilding && probabilityAccepted && confidenceAccepted) ||
             (isUnknown && probabilityAccepted && hasNdsmHeight);

         candidateBytes[index] = static_cast<uint8_t>(primarySeed ? 255 : 0);
     }
     cv::Mat binaryMask(height, width, CV_8UC1, candidateBytes.data());

     //Explicit Valid Mask Normalization (Guarantees 0/255)
     cv::Mat validMat255;
     cv::compare(validMat, 0, validMat255, cv::CMP_GT);
     cv::bitwise_and(binaryMask, validMat255, binaryMask);

     // Bounded, edge-connected growth from strong roofs. Unlike unconstrained
     // UNKNOWN recovery, this cannot invent distant islands from nDSM noise.
     const cv::Mat allowed(height, width, CV_8UC1, allowedBytes.data());
     const cv::Mat recovery(height, width, CV_8UC1, recoveryBytes.data());
     // COMPETITIVE ERODE-LABEL-EXPAND TO PREVENT ALLEYWAY MERGING
     // 1. Erode to break isthmuses (leaves party walls separated)
     int sepRadius = std::max(1, static_cast<int>(std::ceil(0.8 / std::min(colRes, rowRes))));
     cv::Mat sepKernel = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(sepRadius * 2 + 1, sepRadius * 2 + 1));
     cv::Mat erodedMask;
     cv::erode(binaryMask, erodedMask, sepKernel);

     // Ensure small/narrow structures that completely vanished during erosion retain a core seed
     cv::Mat seedLabels, seedStats, seedCentroids;
     int numSeedComps = cv::connectedComponentsWithStats(
         binaryMask, seedLabels, seedStats, seedCentroids, config.connectivity);
     for (int i = 1; i < numSeedComps; ++i)
     {
         cv::Mat compMask = (seedLabels == i);
         if (cv::countNonZero(erodedMask & compMask) == 0)
         {
             cv::bitwise_or(erodedMask, compMask, erodedMask);
         }
     }

     // 2. Distance Transform for nearest-neighbor (Voronoi) assignment
     cv::Mat distInput, dist, voronoiLabels;
     cv::compare(erodedMask, 0, distInput, cv::CMP_EQ); // Cores = 0, Background = 255
     cv::distanceTransform(distInput, dist, voronoiLabels, cv::DIST_L2, 3, cv::DIST_LABEL_CCOMP);

     // 3. Define target bounding mask (Primary + Allowed Recovery)
     cv::Mat targetMask;
     cv::bitwise_or(binaryMask, recovery, targetMask);
     cv::bitwise_and(targetMask, allowed, targetMask);

     // Retain only pixels in targetMask that are edge-connected to a core in erodedMask
     cv::Mat targetLabels;
     int numTargetComps = cv::connectedComponents(targetMask, targetLabels, config.connectivity, CV_32S);
     std::vector<uint8_t> compHasCore(numTargetComps, 0);
     for (int r = 0; r < height; ++r)
     {
         const uint8_t* eRow = erodedMask.ptr<uint8_t>(r);
         const int32_t* tRow = targetLabels.ptr<int32_t>(r);
         for (int c = 0; c < width; ++c)
         {
             if (eRow[c] > 0 && tRow[c] > 0)
             {
                 compHasCore[tRow[c]] = 1;
             }
         }
     }
     for (int r = 0; r < height; ++r)
     {
         uint8_t* targetRow = targetMask.ptr<uint8_t>(r);
         const int32_t* tRow = targetLabels.ptr<int32_t>(r);
         for (int c = 0; c < width; ++c)
         {
             if (tRow[c] > 0 && !compHasCore[tRow[c]])
             {
                 targetRow[c] = 0;
             }
         }
     }

     // 4. Expand labels, strictly preserving a 1-pixel gap at conflict boundaries
     cv::Mat competitiveMask = cv::Mat::zeros(height, width, CV_8UC1);
     float maxDistPx = config.recoveryDistanceMetres / std::min(colRes, rowRes);

     for (int r = 0; r < height; ++r)
     {
         const uint8_t* targetRow = targetMask.ptr<uint8_t>(r);
         const uint8_t* targetUp = (r > 0) ? targetMask.ptr<uint8_t>(r - 1) : nullptr;
         const uint8_t* targetDown = (r + 1 < height) ? targetMask.ptr<uint8_t>(r + 1) : nullptr;
         const int32_t* voronoiRow = voronoiLabels.ptr<int32_t>(r);
         const int32_t* voronoiUp = (r > 0) ? voronoiLabels.ptr<int32_t>(r - 1) : nullptr;
         const int32_t* voronoiDown = (r + 1 < height) ? voronoiLabels.ptr<int32_t>(r + 1) : nullptr;
         const float* distRow = dist.ptr<float>(r);
         uint8_t* outRow = competitiveMask.ptr<uint8_t>(r);

         for (int c = 0; c < width; ++c)
         {
             if (targetRow[c] > 0 && distRow[c] <= maxDistPx)
             {
                 int32_t myLabel = voronoiRow[c];
                 if (myLabel != 0)
                 {
                     // If any 4-neighbor belongs to a DIFFERENT core, this is a party-wall boundary. Leave it 0.
                     bool conflict = false;
                     if (c > 0 && targetRow[c - 1] > 0 && voronoiRow[c - 1] != 0 && voronoiRow[c - 1] != myLabel) conflict = true;
                     if (c + 1 < width && targetRow[c + 1] > 0 && voronoiRow[c + 1] != 0 && voronoiRow[c + 1] != myLabel) conflict = true;
                     if (targetUp && targetUp[c] > 0 && voronoiUp[c] != 0 && voronoiUp[c] != myLabel) conflict = true;
                     if (targetDown && targetDown[c] > 0 && voronoiDown[c] != 0 && voronoiDown[c] != myLabel) conflict = true;

                     if (!conflict) outRow[c] = 255;
                 }
             }
         }
     }
     binaryMask = competitiveMask;
     
     cv::Mat recovered;
     cv::bitwise_and(binaryMask, recovery, recovered);
     result.recoveredCandidatePixelCount = cv::countNonZero(recovered);
     result.candidateMask.width = width;
     result.candidateMask.height = height;
     result.candidateMask.data = candidateBytes;

     //Affine-Aware Morphology
     //std::ceil to prevent truncation, generating independent width/height for rectangular pixels
     auto calcKernelDim = [](float radius, double res) -> int
     {
         if (radius <= 0.0f) return 1;
         int pixels = static_cast<int>(std::ceil(radius / res));
         return std::max(1, (pixels * 2) + 1);
     };

     result.openingKernelWidth  = calcKernelDim(config.openingRadiusMetres, colRes);
     result.openingKernelHeight = calcKernelDim(config.openingRadiusMetres, rowRes);
     result.closingKernelWidth  = calcKernelDim(config.closingRadiusMetres, colRes);
     result.closingKernelHeight = calcKernelDim(config.closingRadiusMetres, rowRes);

     // Opening (Erosion -> Dilation)
     if (result.openingKernelWidth >= 3 || result.openingKernelHeight >= 3)
     {
         cv::Mat openKernel = cv::getStructuringElement(cv::MORPH_RECT,
             cv::Size(result.openingKernelWidth, result.openingKernelHeight));
         cv::morphologyEx(binaryMask, binaryMask, cv::MORPH_OPEN, openKernel);

         // Dilation can push building pixels into cloud/NoData regions. Re-apply mask.
         cv::bitwise_and(binaryMask, validMat255, binaryMask);
         cv::bitwise_and(binaryMask, allowed, binaryMask);
     }

     // Closing (Dilation -> Erosion)
     if (result.closingKernelWidth >= 3 || result.closingKernelHeight >= 3)
     {
         cv::Mat closeKernel = cv::getStructuringElement(cv::MORPH_RECT,
             cv::Size(result.closingKernelWidth, result.closingKernelHeight));
         cv::morphologyEx(binaryMask, binaryMask, cv::MORPH_CLOSE, closeKernel);

         // Dilation can push building pixels into cloud/NoData regions. Re-apply mask.
         cv::bitwise_and(binaryMask, validMat255, binaryMask);
         cv::bitwise_and(binaryMask, allowed, binaryMask);
     }

     //Connected Components (Small Region Rejection)
     cv::Mat labels, stats, centroids;
     int numLabels = cv::connectedComponentsWithStats(binaryMask, labels, stats, centroids, config.connectivity, CV_32S);

     std::vector<uint8_t> labelToKeep(numLabels, 0);

     // Evaluate physics (start at 1 to skip background)
     for (int i = 1; i < numLabels; ++i)
     {
         int pixelCount = stats.at<int>(i, cv::CC_STAT_AREA);
         double areaSquareMetres = pixelCount * pixelArea;

         if (areaSquareMetres >= config.minBuildingAreaSquareMetres) {
             labelToKeep[i] = 1;
         }
         else
         {
             result.smallComponentRejectedPixelCount += pixelCount;
         }
     }

     //Safe Output Matrix Generation
     result.cleanMask.width = width;
     result.cleanMask.height = height;

     // Cast to size_t to prevent overflow on massive grids
     result.cleanMask.data.resize(totalPixels, 0);

     // Iterate using row pointers to guarantee safety even if memory is not perfectly continuous
     for (int r = 0; r < height; ++r)
     {
         const int* labelRow = labels.ptr<int>(r);
         uint8_t* outRow = result.cleanMask.data.data() + (r * width);
         for (int c = 0; c < width; ++c)
         {
             outRow[c] = labelToKeep[labelRow[c]];
         }
     }

     result.success = true;
     return result;
}
} // namespace

BuildingMaskResult BuildingMaskProcessor::createCleanMask(
     const SemanticScene& semantics,
     const RasterGrid<uint8_t>& validMask,
     const SpatialMetadata& metadata,
     const BuildingReconstructionConfig& config)
{
     return createCleanMaskImpl(
         semantics, nullptr, validMask, metadata, config);
}

BuildingMaskResult BuildingMaskProcessor::createCleanMask(
     const SemanticScene& semantics,
     const RasterGrid<float>& metricNdsm,
     const RasterGrid<uint8_t>& validMask,
     const SpatialMetadata& metadata,
     const BuildingReconstructionConfig& config)
{
     return createCleanMaskImpl(
         semantics, &metricNdsm, validMask, metadata, config);
}
