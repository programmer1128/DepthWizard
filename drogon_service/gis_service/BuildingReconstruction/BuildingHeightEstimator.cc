#include "BuildingHeightEstimator.h"
#include <opencv2/opencv.hpp>
#include <algorithm>
#include <cmath>
#include <cstdint>

float BuildingHeightEstimator::calculateRobustMedian(std::vector<float>& samples) 
{
     if (samples.empty()) 
     {
         return 0.0f;
     }
     size_t n = samples.size() / 2;
     // std::nth_element is O(N) instead of O(N log N) full sort
     std::nth_element(samples.begin(), samples.begin() + n, samples.end());
     return samples[n];
}

BuildingHeightEstimate BuildingHeightEstimator::estimate(
     const FootprintPolygon<PixelPoint>& pixelFootprint,
     const GeoreferencedSurfaceBundle& surface,
     const SemanticScene& semantics,
     const SpatialMetadata& metadata,
     const BuildingReconstructionConfig& config)
{
    BuildingHeightEstimate result;

     if (!config.validate() || pixelFootprint.outerRing.empty()) 
     {
         result.errorMessage = "Invalid configuration or empty footprint.";
         return result;
     }

     if (!surface.dtm.isValid() || !surface.ndsm.isValid() || !semantics.finalClassMap.isValid()) 
     {
         result.errorMessage = "Invalid surface or semantic grids.";
         return result;
     }

     int width = metadata.width;
     int height = metadata.height;

     //Calculate Bounding Box of the Polygon to create a localized ROI
     int minX = width, minY = height, maxX = 0, maxY = 0;
     for (const auto& pt : pixelFootprint.outerRing) 
     {
         minX = std::min(minX, static_cast<int>(pt.column));
         minY = std::min(minY, static_cast<int>(pt.row));
         maxX = std::max(maxX, static_cast<int>(pt.column));
         maxY = std::max(maxY, static_cast<int>(pt.row));
     }

     // Convert metric buffer requirements into pixel sizes
     double pixelArea = std::abs(metadata.geoTransform[1] * metadata.geoTransform[5] - metadata.geoTransform[2] * metadata.geoTransform[4]);
     double gsd = std::sqrt(pixelArea);
     int bufferPixels = std::max(1, static_cast<int>(std::ceil(config.groundBufferRadiusMetres / gsd)));
     int erodePixels  = std::max(1, static_cast<int>(std::ceil(config.footprintErosionRadiusMetres / gsd)));

     // Expand bounding box by the ground buffer radius
     int roiX = std::max(0, minX - bufferPixels - 1);
     int roiY = std::max(0, minY - bufferPixels - 1);
     int roiW = std::min(width - roiX, (maxX - minX) + (bufferPixels * 2) + 2);
     int roiH = std::min(height - roiY, (maxY - minY) + (bufferPixels * 2) + 2);

     if (roiW <= 0 || roiH <= 0) 
     {
         result.errorMessage = "Calculated ROI is invalid.";
         return result;
     }

     //Rasterize the Polygon into the ROI Mask
     cv::Mat footprintMask(roiH, roiW, CV_8UC1, cv::Scalar(0));
     std::vector<cv::Point> cvPoly;
     for (const auto& pt : pixelFootprint.outerRing) 
     {
         cvPoly.push_back(cv::Point(static_cast<int>(pt.column) - roiX, static_cast<int>(pt.row) - roiY));
     }
    
     const cv::Point* pts[1] = { cvPoly.data() };
     int npts[1] = { static_cast<int>(cvPoly.size()) };
     cv::fillPoly(footprintMask, pts, npts, 1, cv::Scalar(255));

     // Punch out holes
     for (const auto& hole : pixelFootprint.holes) 
     {
         std::vector<cv::Point> cvHole;
         for (const auto& pt : hole) {
             cvHole.push_back(cv::Point(static_cast<int>(pt.column) - roiX, static_cast<int>(pt.row) - roiY));
         }
         const cv::Point* hPts[1] = { cvHole.data() };
         int hNpts[1] = { static_cast<int>(cvHole.size()) };
         cv::fillPoly(footprintMask, hPts, hNpts, 1, cv::Scalar(0));
     }

     //Create Interior Mask (Building Heights) & Exterior Mask (Ground Bases)
     cv::Mat interiorMask, dilatedMask, exteriorMask;
    
     cv::Mat erodeKernel = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(erodePixels * 2 + 1, erodePixels * 2 + 1));
     cv::Mat dilateKernel = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(bufferPixels * 2 + 1, bufferPixels * 2 + 1));

     cv::erode(footprintMask, interiorMask, erodeKernel);
     cv::dilate(footprintMask, dilatedMask, dilateKernel);
    
     // The exterior ring is the dilated mask MINUS the original footprint
     cv::subtract(dilatedMask, footprintMask, exteriorMask);

     //Sample the Grids
     std::vector<float> groundSamples;
     std::vector<float> roofSamples;

     for (int r = 0; r < roiH;r++) 
     {
         uint8_t* intRow = interiorMask.ptr<uint8_t>(r);
         uint8_t* extRow = exteriorMask.ptr<uint8_t>(r);
         
         int globalR = roiY + r;
         std::size_t offset = static_cast<std::size_t>(globalR) * width;

         for (int c = 0; c < roiW;c++) 
         {
             int globalC = roiX + c;
             std::size_t idx = offset + globalC;
 
             // Skip pixels that are completely invalid globally (e.g., clouds/no-data)
             if (surface.validMask.data[idx] == 0) 
             {
                 continue;
             }

             SemanticClass pixelClass = semantics.finalClassMap.data[idx];

             // Sample Exterior Ground (strictly ignoring trees/water/buildings)
             if (extRow[c] > 0) 
             {
                 if (pixelClass == SemanticClass::GROUND || pixelClass == SemanticClass::ROAD) {
                     groundSamples.push_back(surface.dtm.data[idx]);
                 }
             }

             // Sample Interior Roof (strictly inside the eroded core, semantically confirmed)
             if (intRow[c] > 0) 
             {
                 if (pixelClass == SemanticClass::BUILDING) {
                     roofSamples.push_back(surface.ndsm.data[idx]);
                 }
             }
         }
     }

     //Compute Robust Medians & Confidence
     result.validGroundSampleCount = static_cast<int>(groundSamples.size());
     result.validRoofSampleCount = static_cast<int>(roofSamples.size());

     if (result.validGroundSampleCount < config.minRequiredSamples) 
     {
         result.warnings.push_back("Insufficient clean ground samples around building. Base elevation may be inaccurate.");
     } 
     else 
     {
         result.representativeBaseElevation = calculateRobustMedian(groundSamples);
     }

    if (result.validRoofSampleCount < config.minRequiredSamples) 
    {
         result.warnings.push_back("Insufficient clean interior building samples. Height derived from footprint edges.");
         // Fallback: If erosion destroyed the mask, compute from the un-eroded footprint
         for (int r = 0; r < roiH; ++r) 
         {
             uint8_t* footRow = footprintMask.ptr<uint8_t>(r);
             std::size_t offset = static_cast<std::size_t>(roiY + r) * width;
             for (int c = 0; c < roiW; ++c) 
             {
                 std::size_t idx = offset + (roiX + c);
                 if (footRow[c] > 0 && surface.validMask.data[idx] != 0 && semantics.finalClassMap.data[idx] == SemanticClass::BUILDING) 
                 {
                     roofSamples.push_back(surface.ndsm.data[idx]);
                 }
             }
         }
         result.heightAboveGround = calculateRobustMedian(roofSamples);
         result.validRoofSampleCount = static_cast<int>(roofSamples.size());
     } 
     else 
     {
         result.heightAboveGround = calculateRobustMedian(roofSamples);
     }

     //Final Physics Physics Resolution
     // A building cannot be negatively tall. Enforce physical reality.
     result.heightAboveGround = std::max(0.1f, result.heightAboveGround);
    
     // Flat roof assumption
     result.roofElevation = result.representativeBaseElevation + result.heightAboveGround;

     // Confidence metric (0.0 to 1.0)
     float sampleConf = std::min(1.0f, static_cast<float>(result.validRoofSampleCount) / (config.minRequiredSamples * 4.0f));
     result.confidence = sampleConf;
    
     result.success = true;
     return result;
}