#include "BuildingHeightEstimator.h"
#include <opencv2/opencv.hpp>
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <sstream>

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

     if (!surface.dtm.isValid() || !surface.ndsm.isValid() ||
         !surface.validMask.isValid() ||
         !semantics.finalClassMap.isValid() ||
         !semantics.buildingProbability.isValid())
     {
         result.errorMessage = "Invalid surface or semantic grids.";
         return result;
     }

     int width = metadata.width;
     int height = metadata.height;

     const auto hasExpectedShape =
         [width, height](const auto& grid)
         {
             return grid.width == width && grid.height == height && grid.isValid();
         };

     if (width <= 0 || height <= 0 ||
         !hasExpectedShape(surface.dtm) ||
         !hasExpectedShape(surface.ndsm) ||
         !hasExpectedShape(surface.validMask) ||
         !hasExpectedShape(semantics.finalClassMap) ||
         !hasExpectedShape(semantics.buildingProbability))
     {
         result.errorMessage = "Surface, semantic, and metadata dimensions do not match.";
         return result;
     }

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
     std::vector<float> footprintDtmSamples;
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

             if (footprintMask.at<uint8_t>(r, c) > 0 &&
                 std::isfinite(surface.dtm.data[idx]))
             {
                 footprintDtmSamples.push_back(surface.dtm.data[idx]);
             }

             // Sample Exterior Ground (strictly ignoring trees/water/buildings)
             if (extRow[c] > 0) 
             {
                 if ((pixelClass == SemanticClass::GROUND ||
                      pixelClass == SemanticClass::ROAD) &&
                     std::isfinite(surface.dtm.data[idx])) {
                     groundSamples.push_back(surface.dtm.data[idx]);
                 }
             }

             const bool supportsBuildingHeight =
                 pixelClass == SemanticClass::BUILDING ||
                 (pixelClass == SemanticClass::UNKNOWN &&
                  semantics.buildingProbability.data[idx] >=
                      config.buildingRecoveryProbabilityThreshold);

             // Sample Interior Roof from strict or metric-recovered building
             // evidence. Requiring only the final class here would discard
             // every candidate recovered from a softmax margin failure.
             if (intRow[c] > 0) 
             {
                 if (supportsBuildingHeight &&
                     std::isfinite(surface.ndsm.data[idx])) {
                     roofSamples.push_back(surface.ndsm.data[idx]);
                 }
             }
         }
     }

     //Compute Robust Medians & Confidence
     result.validGroundSampleCount = static_cast<int>(groundSamples.size());
     result.validRoofSampleCount = static_cast<int>(roofSamples.size());

     // Validate terrain beneath the footprint, not the exterior semantic
     // ground ring. The exterior can legitimately include a road cut or an
     // adjacent terrace, while the footprint support itself is the physical
     // surface on which the building would have to stand.
     if (static_cast<int>(footprintDtmSamples.size()) >=
         config.minRequiredSamples)
     {
         std::vector<float> orderedTerrain = footprintDtmSamples;
         std::sort(orderedTerrain.begin(), orderedTerrain.end());

         const std::size_t last = orderedTerrain.size() - 1;
         const std::size_t lowerIndex = static_cast<std::size_t>(
             std::floor(0.10 * static_cast<double>(last)));
         const std::size_t upperIndex = static_cast<std::size_t>(
             std::ceil(0.90 * static_cast<double>(last)));

         result.footprintElevationDeltaMetres =
             orderedTerrain[upperIndex] - orderedTerrain[lowerIndex];

         if (!std::isfinite(result.footprintElevationDeltaMetres) ||
             result.footprintElevationDeltaMetres >
                 config.maxFootprintElevationDeltaMetres)
         {
             std::ostringstream message;
             message << "Footprint terrain relief "
                     << result.footprintElevationDeltaMetres
                     << " m exceeds the configured "
                     << config.maxFootprintElevationDeltaMetres
                     << " m limit.";
             result.errorMessage = message.str();
             return result;
         }
     }

     if (result.validGroundSampleCount < config.minRequiredSamples) 
     {
         // The reference DTM represents bare earth beneath structures. When
         // semantic ground is unavailable around a footprint (dense urban or
         // vegetated edge), use finite DTM samples beneath the footprint. A
         // default elevation of zero is never physically valid here.
         if (static_cast<int>(footprintDtmSamples.size()) <
             config.minRequiredSamples)
         {
             result.errorMessage =
                 "Insufficient terrain samples to establish building base elevation.";
             return result;
         }

         result.representativeBaseElevation =
             calculateRobustMedian(footprintDtmSamples);
         result.validGroundSampleCount =
             static_cast<int>(footprintDtmSamples.size());
         result.warnings.push_back(
             "Exterior ground unavailable; base elevation derived from footprint DTM.");
     } 
     else 
     {
         result.representativeBaseElevation = calculateRobustMedian(groundSamples);
     }

    if (result.validRoofSampleCount < config.minRequiredSamples) 
    {
         result.warnings.push_back("Insufficient clean interior building samples. Height derived from footprint edges.");
         // Fallback: If erosion destroyed the mask, compute from the un-eroded footprint
         roofSamples.clear();
         for (int r = 0; r < roiH; ++r) 
         {
             uint8_t* footRow = footprintMask.ptr<uint8_t>(r);
             std::size_t offset = static_cast<std::size_t>(roiY + r) * width;
             for (int c = 0; c < roiW; ++c) 
             {
                 std::size_t idx = offset + (roiX + c);
                 const bool supportsBuildingHeight =
                     semantics.finalClassMap.data[idx] == SemanticClass::BUILDING ||
                     (semantics.finalClassMap.data[idx] == SemanticClass::UNKNOWN &&
                      semantics.buildingProbability.data[idx] >=
                          config.buildingRecoveryProbabilityThreshold);
                 if (footRow[c] > 0 && surface.validMask.data[idx] != 0 &&
                     supportsBuildingHeight &&
                     std::isfinite(surface.ndsm.data[idx]))
                 {
                     roofSamples.push_back(surface.ndsm.data[idx]);
                 }
             }
         }
         result.validRoofSampleCount = static_cast<int>(roofSamples.size());

         if (result.validRoofSampleCount < config.minRequiredSamples)
         {
             result.errorMessage =
                 "Insufficient valid nDSM samples to estimate building height.";
             return result;
         }

         result.heightAboveGround = calculateRobustMedian(roofSamples);
     } 
     else 
     {
         result.heightAboveGround = calculateRobustMedian(roofSamples);
     }

     // Fail closed instead of turning zero/noise into a synthetic 10 cm
     // building or allowing implausible cliffs to become structures.
     if (!std::isfinite(result.representativeBaseElevation) ||
         !std::isfinite(result.heightAboveGround) ||
         result.heightAboveGround < config.minBuildingHeightMetres ||
         result.heightAboveGround > config.maxBuildingHeightMetres)
     {
         result.errorMessage =
             "Estimated building height violates configured physical limits.";
         return result;
     }
    
     // Flat roof assumption
     result.roofElevation = result.representativeBaseElevation + result.heightAboveGround;

     // Sample a small DTM neighbourhood around every polygon vertex. Polygon
     // vertices lie on pixel edges, so a neighbourhood median is more stable
     // than selecting one side of the edge. Missing samples safely fall back
     // to the representative base.
     result.baseElevationPerOuterVertex.reserve(
         pixelFootprint.outerRing.size());
     for (const PixelPoint& vertex : pixelFootprint.outerRing)
     {
         const int centerColumn = static_cast<int>(std::lround(vertex.column));
         const int centerRow = static_cast<int>(std::lround(vertex.row));
         std::vector<float> vertexTerrainSamples;
         vertexTerrainSamples.reserve(9);

         for (int rowOffset = -1; rowOffset <= 1; ++rowOffset)
         {
             const int row = centerRow + rowOffset;
             if (row < 0 || row >= height)
                 continue;

             for (int columnOffset = -1; columnOffset <= 1; ++columnOffset)
             {
                 const int column = centerColumn + columnOffset;
                 if (column < 0 || column >= width)
                     continue;

                 const std::size_t index =
                     static_cast<std::size_t>(row) * width + column;
                 const float elevation = surface.dtm.data[index];
                 if (surface.validMask.data[index] != 0 &&
                     std::isfinite(elevation))
                 {
                     vertexTerrainSamples.push_back(elevation);
                 }
             }
         }

         result.baseElevationPerOuterVertex.push_back(
             vertexTerrainSamples.empty()
                 ? result.representativeBaseElevation
                 : calculateRobustMedian(vertexTerrainSamples));
     }

     // Confidence metric (0.0 to 1.0)
     float sampleConf = std::min(1.0f, static_cast<float>(result.validRoofSampleCount) / (config.minRequiredSamples * 4.0f));
     result.confidence = sampleConf;
    
     result.success = true;
     return result;
}
