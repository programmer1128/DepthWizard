#include "BuildingMaskProcessor.h"
#include <opencv2/opencv.hpp>
#include <cmath>
#include <algorithm>

BuildingMaskResult BuildingMaskProcessor::createCleanMask(
     const SemanticScene& semantics,
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
     if (width <= 0 || height <= 0 ||semantics.buildingProbability.width != width || 
         semantics.buildingProbability.height != height ||validMask.width != width || 
         validMask.height != height ||!semantics.buildingProbability.isValid() || 
         !validMask.isValid()) 
     {
        
         result.errorMessage = "Grid dimension mismatch or invalid memory buffers.";
         return result;
     }

     // Ensure probability values are finite
     for (float p : semantics.buildingProbability.data) 
     {
         if (!std::isfinite(p) || p < 0.0f || p > 1.0f) 
         {
             result.errorMessage = "Building probabilities contain non-finite values or exceed [0,1].";
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
     cv::Mat probMat(height, width, CV_32FC1, const_cast<float*>(semantics.buildingProbability.data.data()));
     cv::Mat validMat(height, width, CV_8UC1, const_cast<uint8_t*>(validMask.data.data()));

     //Probability Thresholding
     cv::Mat binaryMask = (probMat >= config.buildingProbabilityThreshold);

     //Explicit Valid Mask Normalization (Guarantees 0/255)
     cv::Mat validMat255;
     cv::compare(validMat, 0, validMat255, cv::CMP_GT);
     cv::bitwise_and(binaryMask, validMat255, binaryMask);

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
     }

     // Closing (Dilation -> Erosion)
     if (result.closingKernelWidth >= 3 || result.closingKernelHeight >= 3) 
     {
         cv::Mat closeKernel = cv::getStructuringElement(cv::MORPH_ELLIPSE, 
             cv::Size(result.closingKernelWidth, result.closingKernelHeight));
         cv::morphologyEx(binaryMask, binaryMask, cv::MORPH_CLOSE, closeKernel);
        
         // Dilation can push building pixels into cloud/NoData regions. Re-apply mask.
         cv::bitwise_and(binaryMask, validMat255, binaryMask);
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
     std::size_t totalPixels = static_cast<std::size_t>(width) * static_cast<std::size_t>(height);
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