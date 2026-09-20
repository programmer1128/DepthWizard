#include "BuildingInstanceExtractor.h"
#include <opencv2/opencv.hpp>
#include <algorithm>
#include <cmath>
#include <limits>
#include <tuple>
#include <cstddef>

ComponentExtractionResult BuildingInstanceExtractor::extract(
    const BuildingMaskResult &maskResult,
    const SemanticScene &semantics,
    const SpatialMetadata &metadata,
    const BuildingReconstructionConfig &config)
{
    ComponentExtractionResult result;

    // Validate Configuration
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

    // Strict Order of Operations Validation (Dimensions first)
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

    if (!maskResult.cleanMask.isValid() || !semantics.buildingProbability.isValid() || !semantics.semanticConfidence.isValid())
    {
        result.errorMessage = "Invalid memory buffers detected in grids.";
        return result;
    }

    // Validate Probabilities AND Confidences to prevent silent NaN/Infinity poisoning in OpenCV
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

    // Validate Projected Metric CRS
    double pixelArea = std::abs(metadata.geoTransform[1] * metadata.geoTransform[5] -
                                metadata.geoTransform[2] * metadata.geoTransform[4]);

    // ARCHITECTURAL GATE: A hard limit of 1e-10 allows ultra-high-res millimeter drone imagery
    // while safely rejecting unprojected Geographic CRSs (degrees)
    if (!std::isfinite(pixelArea) || pixelArea < 1e-10 ||
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

    // Converting 0/1 boolean mask to 0/255 for OpenCV mathematical operations
    cv::Mat rawMask(height, width, CV_8UC1, const_cast<uint8_t *>(maskResult.cleanMask.data.data()));
    cv::Mat binaryMask = rawMask * 255;

    // TOPOLOGICAL BASELINE: Count the true physical building clusters before any splitting occurs.
    cv::Mat initialLabels;
    int numClusters = cv::connectedComponents(binaryMask, initialLabels, config.connectivity, CV_32S);

    // PROTECTION 1: Pad the binary mask by 1 pixel of black. This guarantees distanceTransform
    // doesn't fail/underflow on buildings touching the absolute edge of the map.
    cv::Mat paddedMask;
    cv::copyMakeBorder(binaryMask, paddedMask, 1, 1, 1, 1, cv::BORDER_CONSTANT, cv::Scalar(0));

    // WATERSHED PREP
    cv::Mat distTransform;
    cv::distanceTransform(paddedMask, distTransform, cv::DIST_L2, 5);

    double gsd = std::sqrt(pixelArea);
    double distThreshPixels = std::max(1.0, 1.2 / gsd);

    cv::Mat sureFg;
    cv::threshold(distTransform, sureFg, distThreshPixels, 255, cv::THRESH_BINARY);
    sureFg.convertTo(sureFg, CV_8U);

    cv::Mat markers;
    // PROTECTION 2: Force 8-connectivity for foreground peaks to prevent diagonal ridges fragmenting
    int numPeaks = cv::connectedComponents(sureFg, markers, 8, CV_32S);

    cv::Mat splitMask = binaryMask.clone();

    // OPTIMIZATION & PROTECTION 3: The Topological Bypass
    // If the number of peaks equals the number of clusters, no buildings are touching.
    // By bypassing Watershed, we mathematically preserve 100% of the building's outer perimeter.
    if (numPeaks > numClusters)
    {
        cv::Mat sureBg;
        cv::dilate(paddedMask, sureBg, cv::Mat(), cv::Point(-1, -1), 2);

        cv::Mat unknown = sureBg - sureFg;
        markers = markers + 1;            // Background = 1
        markers.setTo(0, unknown == 255); // Unknown boundaries = 0

        // Explicitly pin the padded 1-pixel border as Background (Label 1).
        cv::rectangle(markers, cv::Point(0, 0), cv::Point(markers.cols - 1, markers.rows - 1), cv::Scalar(1), 1);

        cv::Mat dummyRgb;
        cv::cvtColor(paddedMask, dummyRgb, cv::COLOR_GRAY2BGR);
        cv::watershed(dummyRgb, markers);

        cv::Mat croppedMarkers = markers(cv::Rect(1, 1, width, height));

        // Erase ONLY the collision boundaries (-1) drawn by Watershed to sever the bridge.
        splitMask.setTo(0, croppedMarkers == -1);
    }

    // Apply OpenCV connected components on the finalized, severed mask
    cv::Mat labels, stats, centroids;
    int numLabels = cv::connectedComponentsWithStats(splitMask, labels, stats, centroids, config.connectivity, CV_32S);

    if (numLabels <= 1)
    {
        allocateZeroRaster();
        result.success = true;
        result.warnings.push_back("No valid building components remained after watershed splitting.");
        return result;
    }

    std::vector<double> sumProb(numLabels, 0.0);
    std::vector<double> sumConf(numLabels, 0.0);
    std::vector<float> minConf(numLabels, std::numeric_limits<float>::max());

    const float *probPtr = semantics.buildingProbability.data.data();
    const float *confPtr = semantics.semanticConfidence.data.data();

    // std::size_t for offset math to avoid int overflow on massive grids
    for (int r = 0; r < height; ++r)
    {
        const int32_t *labelRow = labels.ptr<int32_t>(r);
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

    // Stats Compilation & Area Filtering
    std::vector<ComponentStats> validComponents;
    validComponents.reserve(numLabels);

    for (int i = 1; i < numLabels; ++i)
    {
        int pixelCount = stats.at<int>(i, cv::CC_STAT_AREA);
        double physicalArea = pixelCount * pixelArea;

        //
        if (physicalArea > config.minBuildingAreaSquareMetres)
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

    // Deterministic Strict Weak Ordering Sort
    std::sort(validComponents.begin(), validComponents.end(),
              [](const ComponentStats &a, const ComponentStats &b)
              {
                  return std::tie(a.pixelBoundingBox.y, a.pixelBoundingBox.x, a.pixelBoundingBox.height,
                                  a.pixelBoundingBox.width, a._originalLabel) <
                         std::tie(b.pixelBoundingBox.y, b.pixelBoundingBox.x, b.pixelBoundingBox.height,
                                  b.pixelBoundingBox.width, b._originalLabel);
              });

    // Assign final int32_t IDs and build LUT
    std::vector<int32_t> remapLUT(numLabels, 0);
    int32_t nextId = 1;

    for (auto &comp : validComponents)
    {
        comp.componentId = nextId;
        remapLUT[comp._originalLabel] = nextId;
        nextId++;
    }

    // Generate Final Output Raster safely
    allocateZeroRaster();
    for (int r = 0; r < height; ++r)
    {
        const int32_t *oldLabelRow = labels.ptr<int32_t>(r);
        int32_t *newLabelRow = result.labelRaster.data.data() + (static_cast<std::size_t>(r) * width);
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