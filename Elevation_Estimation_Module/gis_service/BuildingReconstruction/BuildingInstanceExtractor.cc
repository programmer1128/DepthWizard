#include "BuildingInstanceExtractor.h"
#include "BuildingInstanceSplitter.h"
#include <opencv2/opencv.hpp>
#include <algorithm>
#include <cmath>
#include <limits>
#include <tuple>
#include <cstddef>

ComponentExtractionResult BuildingInstanceExtractor::extract(
     const BuildingMaskResult& maskResult,
     const SemanticScene& semantics,
     const SpatialMetadata& metadata,
     const BuildingReconstructionConfig& config,
     const RasterGrid<float>* ndsm,
     const RasterGrid<uint8_t>* opticalGray)
{
     ComponentExtractionResult result;

     //Validate Configuration
     if (!config.validate()) 
     {
         result.errorMessage = "Invalid BuildingReconstructionConfig parameters.";
         return result;
     }

     if (!maskResult.success) 
     {
         result.errorMessage = "Failed mask provided.";
         return result;
     }

     int width = maskResult.cleanMask.width;
     int height = maskResult.cleanMask.height;

     //Strict Order of Operations Validation (Dimensions first)
     if (width <= 0 || height <= 0) 
     {
         result.errorMessage = "Mask dimensions must be positive.";
         return result;
     }

     if (metadata.width != width || metadata.height != height ||
         semantics.buildingProbability.width != width || semantics.buildingProbability.height != height ||
         semantics.semanticConfidence.width != width || semantics.semanticConfidence.height != height) 
     {
         result.errorMessage = "Dimension mismatch between metadata, mask, and semantic grids.";
         return result;
     }

     if (!maskResult.cleanMask.isValid() || !semantics.buildingProbability.isValid() || !semantics.semanticConfidence.isValid() ||
         (ndsm && (!ndsm->isValid() || ndsm->width != width || ndsm->height != height)) ||
         (opticalGray && (!opticalGray->isValid() || opticalGray->width != width ||
                          opticalGray->height != height)))
     {
         result.errorMessage = "Invalid memory buffers detected in grids.";
         return result;
     }

     //validate Probabilities AND Confidences
     for (float p : semantics.buildingProbability.data) 
     {
         if (!std::isfinite(p) || p < 0.0f || p > 1.0f) 
         {
             result.errorMessage = "Building probabilities contain invalid values.";
             return result;
         }
     }

     for (float c : semantics.semanticConfidence.data) 
     {
         if (!std::isfinite(c) || c < 0.0f || c > 1.0f) 
         {
             result.errorMessage = "Semantic confidences contain invalid values.";
             return result;
         }
     }

     //validate Projected Metric CRS
     double pixelArea = std::abs(metadata.geoTransform[1] * metadata.geoTransform[5] - 
                                 metadata.geoTransform[2] * metadata.geoTransform[4]);
                                
     // Degrees have tiny areas (e.g., 0.000001). A hard limit of 0.01 rejects geographic CRSs securely.
     if (!std::isfinite(pixelArea) || pixelArea < 0.01 || 
         (metadata.isGeoreferenced && metadata.projectionRef.find("PROJCS") == std::string::npos)) 
     {
         result.errorMessage = "Invalid affine determinant or unprojected CRS. Requires projected metric CRS.";
         return result;
     }

     // Helper to safely allocate the output label raster filled with zeros
     auto allocateZeroRaster = [&]() 
     {
         result.labelRaster.width = width;
         result.labelRaster.height = height;
         result.labelRaster.data.assign(static_cast<std::size_t>(width) * static_cast<std::size_t>(height), 0);
     };

     // Split only with supported markers, then compile statistics directly
     // from integer labels. Binary relabelling here would erase all the cuts.
     RasterGrid<int32_t> instances = BuildingInstanceSplitter::label(
         maskResult.cleanMask, semantics, ndsm, pixelArea, config,
         opticalGray);
     cv::Mat labels(height, width, CV_32S, instances.data.data());
     const int numLabels = *std::max_element(instances.data.begin(), instances.data.end()) + 1;
     cv::Mat stats = cv::Mat::zeros(numLabels, 5, CV_32S);
     cv::Mat centroids = cv::Mat::zeros(numLabels, 2, CV_64F);
     std::vector<int> right(numLabels, -1), bottom(numLabels, -1);
     for (int id = 0; id < numLabels; ++id) 
     {
         stats.at<int>(id, cv::CC_STAT_LEFT) = width;
         stats.at<int>(id, cv::CC_STAT_TOP) = height;
     }
     for (int y = 0; y < height; ++y)
         for (int x = 0; x < width; ++x) {
             const int id = labels.at<int>(y, x);
             if (!id) continue;
             ++stats.at<int>(id, cv::CC_STAT_AREA);
             stats.at<int>(id, cv::CC_STAT_LEFT) = std::min(x, stats.at<int>(id, cv::CC_STAT_LEFT));
             stats.at<int>(id, cv::CC_STAT_TOP) = std::min(y, stats.at<int>(id, cv::CC_STAT_TOP));
             right[id] = std::max(right[id], x); bottom[id] = std::max(bottom[id], y);
             centroids.at<double>(id, 0) += x; centroids.at<double>(id, 1) += y;
         }
     for (int id = 1; id < numLabels; ++id) {
         const int area = stats.at<int>(id, cv::CC_STAT_AREA);
         if (!area) continue;
         stats.at<int>(id, cv::CC_STAT_WIDTH) = right[id] - stats.at<int>(id, cv::CC_STAT_LEFT) + 1;
         stats.at<int>(id, cv::CC_STAT_HEIGHT) = bottom[id] - stats.at<int>(id, cv::CC_STAT_TOP) + 1;
         centroids.at<double>(id, 0) /= area; centroids.at<double>(id, 1) /= area;
     }
     if (config.connectivity != 4)
     {
         result.warnings.push_back(
             "Instance polygons use edge connectivity; diagonal contacts were separated.");
     }

     if (numLabels <= 1) {
         allocateZeroRaster();
         result.success = true;
         result.warnings.push_back("No building components in the cleaned mask.");
         return result;
     }

     std::vector<double> sumProb(numLabels, 0.0);
     std::vector<double> sumConf(numLabels, 0.0);
     std::vector<float> minConf(numLabels, std::numeric_limits<float>::max());
    
     const float* probPtr = semantics.buildingProbability.data.data();
     const float* confPtr = semantics.semanticConfidence.data.data();

     //std::size_t for offset math to avoid int overflow on massive grids
     for (int r = 0; r < height; ++r) 
     {
         const int32_t* labelRow = labels.ptr<int32_t>(r);
         std::size_t rowOffset = static_cast<std::size_t>(r) * width;
         for (int c = 0; c < width; ++c) 
         {
             int32_t label = labelRow[c];
             if (label > 0) 
             {
                 std::size_t flatIndex = rowOffset + c;
                 float prob = probPtr[flatIndex];
                 float conf = confPtr[flatIndex];
 
                 sumProb[label] += prob;
                 sumConf[label] += conf;
                 if (conf < minConf[label]) 
                 {
                     minConf[label] = conf;
                 }
             }
         }
    }  

     //stats Compilation & Area Filtering
     std::vector<ComponentStats> validComponents;
     validComponents.reserve(numLabels);

     for (int i = 1; i < numLabels; ++i) 
     {
         int pixelCount = stats.at<int>(i, cv::CC_STAT_AREA);
         if (pixelCount == 0) continue;
         double physicalArea = pixelCount * pixelArea;

         if (physicalArea >= config.minBuildingAreaSquareMetres) 
         {
             ComponentStats comp;
             comp._originalLabel = static_cast<int32_t>(i);
             comp.pixelCount = pixelCount;
             comp.physicalAreaSquareMetres = physicalArea;
             comp.pixelBoundingBox.x = stats.at<int>(i, cv::CC_STAT_LEFT);
             comp.pixelBoundingBox.y = stats.at<int>(i, cv::CC_STAT_TOP);
             comp.pixelBoundingBox.width = stats.at<int>(i, cv::CC_STAT_WIDTH);
             comp.pixelBoundingBox.height = stats.at<int>(i, cv::CC_STAT_HEIGHT);
             comp.centroid.column = centroids.at<double>(i, 0);
             comp.centroid.row = centroids.at<double>(i, 1);
             comp.meanBuildingProbability = static_cast<float>(sumProb[i] / pixelCount);
             comp.meanSemanticConfidence = static_cast<float>(sumConf[i] / pixelCount);
             comp.minSemanticConfidence = minConf[i];
             validComponents.push_back(comp);
         } 
         else 
         {
             result.rejectedComponentCount++;
         }
     }

     //Deterministic Strict Weak Ordering Sort
     std::sort(validComponents.begin(), validComponents.end(), 
         [](const ComponentStats& a, const ComponentStats& b) 
     {
         return  std::tie(a.pixelBoundingBox.y, a.pixelBoundingBox.x, a.pixelBoundingBox.height, 
             a.pixelBoundingBox.width, a._originalLabel) <
                 std::tie(b.pixelBoundingBox.y, b.pixelBoundingBox.x, b.pixelBoundingBox.height, 
                     b.pixelBoundingBox.width, b._originalLabel);
     });

     //Assign final int32_t IDs and build LUT
     std::vector<int32_t> remapLUT(numLabels, 0);
     int32_t nextId = 1;
    
     for (auto& comp : validComponents) 
     {
         comp.componentId = nextId;
         remapLUT[comp._originalLabel] = nextId;
         nextId++;
     }

     //Generate Final Output Raster
     allocateZeroRaster();
     for (int r = 0; r < height; ++r) 
     {
         const int32_t* oldLabelRow = labels.ptr<int32_t>(r);
         int32_t* newLabelRow = result.labelRaster.data.data() + (static_cast<std::size_t>(r) * width);
         for (int c = 0; c < width; ++c) 
         {
             newLabelRow[c] = remapLUT[oldLabelRow[c]];
         }
     }

     result.components = std::move(validComponents);
     result.acceptedComponentCount = static_cast<int>(result.components.size());
     result.success = true;

     return result;
}
