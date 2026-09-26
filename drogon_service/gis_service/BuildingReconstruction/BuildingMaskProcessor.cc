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
         const bool probabilityAccepted =
             semantics.buildingProbability.data[index] >=
             config.buildingProbabilityThreshold;
         const bool confidenceAccepted =
             semantics.semanticConfidence.data[index] >=
             config.minBuildingSemanticConfidence;

         const bool recoveredBuilding =
             metricNdsm != nullptr &&
             semantics.finalClassMap.data[index] == SemanticClass::UNKNOWN &&
             semantics.buildingProbability.data[index] >=
                 config.buildingRecoveryProbabilityThreshold &&
             // The UNKNOWN decision may be a softmax margin failure at a
             // blurred roof edge. Do not grow into a pixel that instead has
             // stronger evidence for road, vegetation, water, or ground.
             semantics.buildingProbability.data[index] >= std::max({
                 semantics.groundProbability.data[index],
                 semantics.roadProbability.data[index],
                 semantics.vegetationProbability.data[index],
                 semantics.waterProbability.data[index]}) &&
             std::isfinite(metricNdsm->data[index]) &&
             metricNdsm->data[index] >= config.minRecoveryNdsmHeightMetres;

         recoveryBytes[index] = recoveredBuilding ? 255 : 0;
         const auto cls = semantics.finalClassMap.data[index];
         // A positive ground/road/water/vegetation decision is a barrier.
         // Morphology must not turn these pixels back into buildings.
         allowedBytes[index] = (validMask.data[index] != 0 &&
             (cls == SemanticClass::BUILDING || cls == SemanticClass::UNKNOWN)) ? 255 : 0;
         candidateBytes[index] = static_cast<uint8_t>(
             (isBuilding && probabilityAccepted && confidenceAccepted) ? 255 : 0);
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
     cv::Mat inverseStrong, distanceToStrong;
     cv::bitwise_not(binaryMask, inverseStrong);
     cv::distanceTransform(inverseStrong, distanceToStrong, cv::DIST_L2, 3);
     cv::Mat recoveryZone;
     cv::compare(distanceToStrong, config.recoveryDistanceMetres / std::max(colRes, rowRes),
                 recoveryZone, cv::CMP_LE);
     cv::bitwise_and(recoveryZone, recovery, recoveryZone);
     cv::bitwise_and(recoveryZone, allowed, recoveryZone);
     const int growthSteps = static_cast<int>(std::ceil(
         config.recoveryDistanceMetres / std::min(colRes, rowRes)));
     const cv::Mat cross = cv::getStructuringElement(cv::MORPH_CROSS, cv::Size(3, 3));
     for (int step = 0; step < growthSteps; ++step)
     {
         cv::Mat grown;
         cv::dilate(binaryMask, grown, cross);
         cv::bitwise_and(grown, recoveryZone, grown);
         cv::bitwise_or(binaryMask, grown, binaryMask);
     }
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
         cv::Mat openKernel = cv::getStructuringElement(cv::MORPH_ELLIPSE, 
             cv::Size(result.openingKernelWidth, result.openingKernelHeight));
         cv::morphologyEx(binaryMask, binaryMask, cv::MORPH_OPEN, openKernel);
        
         // Dilation can push building pixels into cloud/NoData regions. Re-apply mask.
         cv::bitwise_and(binaryMask, validMat255, binaryMask);
         cv::bitwise_and(binaryMask, allowed, binaryMask);
     }

     // Closing (Dilation -> Erosion)
     if (result.closingKernelWidth >= 3 || result.closingKernelHeight >= 3) 
     {
         cv::Mat closeKernel = cv::getStructuringElement(cv::MORPH_ELLIPSE, 
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
