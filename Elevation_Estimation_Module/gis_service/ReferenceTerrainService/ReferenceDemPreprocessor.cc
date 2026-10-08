// implements morphological erosion/dilation, IDW gap filling and confidence evaluation

#include "ReferenceDemPreprocessor.h"
#include <cmath>
#include <algorithm>
#include <limits>
#include <iostream>
#include <stdexcept> // required for std::invalid_argument
#include <omp.h> // for multi-threading
#include <opencv2/imgproc.hpp>

float ReferenceDemPreprocessor::computeGsd(const SpatialMetadata& metadata)
{
    // Ground Sample Distance (GSD) = square root of the pixel area in meters
    double area = std::abs(metadata.geoTransform[1] * metadata.geoTransform[5] -
                           metadata.geoTransform[2] * metadata.geoTransform[4]);
    
    if (!std::isfinite(area) || area <= 0.0)
    {
        return 1.0f; // failsafe
    }

    return static_cast<float>(std::sqrt(area));
}

void ReferenceDemPreprocessor::removeSpikes(RasterGrid<float>& demGrid, float thresholdMeters)
{
    int w = demGrid.width;
    int h = demGrid.height;
    
    // make a read-only copy of the original data so we dont accidentally use altered pixels
    std::vector<float> temp = demGrid.data;

    // multi-thread the outer loop across all CPU cores
    #pragma omp parallel for schedule(dynamic)
    for (int y = 1; y < h - 1; ++y)
    {
        // thread-local array avoids slow heap memory allocation (std::vector) inside the loop
        float neighbors[8]; 

        for (int x = 1; x < w - 1; ++x)
        {
            int idx = y * w + x;
            float val = temp[idx];
            
            // skip NoData pixels
            if (std::isnan(val)) continue;

            int count = 0;
            
            // collect valid neighbors in the 3x3 surrounding box
            for (int dy = -1; dy <= 1; ++dy)
            {
                for (int dx = -1; dx <= 1; ++dx)
                {
                    if (dx == 0 && dy == 0) continue; // Skip the center pixel itself
                    
                    float n = temp[(y + dy) * w + (x + dx)];
                    if (!std::isnan(n))
                    {
                        neighbors[count++] = n;
                    }
                }
            }

            // if we have enough neighbors to make a confident guess
            if (count >= 4)
            {
                // find the median value
                std::sort(neighbors, neighbors + count);
                float median = neighbors[count / 2];

                // if our center pixel is violently different from the median, its a spike -> flatten it
                if (std::abs(val - median) > thresholdMeters)
                {
                    demGrid.data[idx] = median;
                }
            }
        }
    }
}

RasterGrid<float> ReferenceDemPreprocessor::applyAdaptiveGroundFilter(
    const RasterGrid<float>& inputGrid,
    float gsdMeters)
{
    if (!inputGrid.isValid() || !std::isfinite(gsdMeters) || gsdMeters <= 0.0F)
    {
        throw std::invalid_argument("ReferenceDemPreprocessor: invalid grid or GSD.");
    }

    // Respect the physical 25 m radius even after warping a 30 m DEM to a
    // 0.5 m optical grid. The former 15-pixel cap reduced it to just 7.5 m.
    // OpenCV uses separable min/max filters for a rectangular kernel, avoiding
    // a full radius-squared neighbourhood scan for every optical pixel.
    const int maxDimension = std::max(inputGrid.width, inputGrid.height);
    const int radius = static_cast<int>(std::min(
        std::ceil(25.0 / gsdMeters), static_cast<double>(maxDimension - 1)));
    const int radiusX = std::min(radius, inputGrid.width - 1);
    const int radiusY = std::min(radius, inputGrid.height - 1);
    const cv::Mat kernel = cv::getStructuringElement(
        cv::MORPH_RECT, cv::Size(radiusX * 2 + 1, radiusY * 2 + 1));

    cv::Mat values(inputGrid.height, inputGrid.width, CV_32FC1);
    const float high = std::numeric_limits<float>::max();
    const float low = std::numeric_limits<float>::lowest();
    for (std::size_t i = 0; i < inputGrid.data.size(); ++i)
    {
        values.ptr<float>()[i] = std::isfinite(inputGrid.data[i])
            ? inputGrid.data[i] : high;
    }

    cv::Mat eroded;
    cv::erode(values, eroded, kernel, cv::Point(-1, -1), 1,
              cv::BORDER_CONSTANT, cv::Scalar(high));
    // An all-invalid erosion window must not dominate the dilation.
    for (std::size_t i = 0; i < inputGrid.data.size(); ++i)
    {
        if (eroded.ptr<float>()[i] == high)
            eroded.ptr<float>()[i] = low;
    }

    cv::Mat opened;
    cv::dilate(eroded, opened, kernel, cv::Point(-1, -1), 1,
               cv::BORDER_CONSTANT, cv::Scalar(low));

    RasterGrid<float> result = inputGrid;
    for (std::size_t i = 0; i < result.data.size(); ++i)
    {
        // Preserve original voids for the explicit IDW/validity stage.
        const float value = opened.ptr<float>()[i];
        result.data[i] = std::isfinite(inputGrid.data[i]) && value != low
            ? value : std::numeric_limits<float>::quiet_NaN();
    }
    return result;
}

void ReferenceDemPreprocessor::inpaintVoidsIDW(
    RasterGrid<float>& demGrid, 
    RasterGrid<uint8_t>& validMask, 
    int searchRadius)
{
    int w = demGrid.width;
    int h = demGrid.height;
    std::vector<float> original = demGrid.data;

    // optimization: pre-calculate spatial weights for Inverse Distance Weighting (IDW)
    struct WeightNode { int dx, dy; double weight; };
    std::vector<WeightNode> weightKernel;
    
    for (int dy = -searchRadius; dy <= searchRadius; ++dy) {
        for (int dx = -searchRadius; dx <= searchRadius; ++dx) {
            if (dx == 0 && dy == 0) continue; // skip center
            double dist_sq = dx * dx + dy * dy;
            weightKernel.push_back({dx, dy, 1.0 / dist_sq}); // the closer the pixel, the stronger the weight
        }
    }

    // multi-thread the void filling process
    #pragma omp parallel for schedule(dynamic)
    for (int y = 0; y < h; ++y)
    {
        for (int x = 0; x < w; ++x)
        {
            int idx = y * w + x;
            
            // if the pixel is already good, we mark it valid and skip
            if (!std::isnan(original[idx]))
            {
                validMask.data[idx] = 1;
                continue;
            }

            double weighted_sum = 0.0;
            double weight_total = 0.0;

            // search surrounding area using pre-computed weights
            for (const auto& node : weightKernel)
            {
                int nx = x + node.dx;
                int ny = y + node.dy;

                if (nx >= 0 && nx < w && ny >= 0 && ny < h)
                {
                    float val = original[ny * w + nx];
                    if (!std::isnan(val))
                    {
                        weighted_sum += val * node.weight;
                        weight_total += node.weight;
                    }
                }
            }

            // if we found valid ground nearby, interpolate
            // else it remains a void
            if (weight_total > 0.0)
            {
                demGrid.data[idx] = static_cast<float>(weighted_sum / weight_total);
                validMask.data[idx] = 1; // mark as safely recovered
            }
            else
            {
                demGrid.data[idx] = std::numeric_limits<float>::quiet_NaN();
                validMask.data[idx] = 0; // unrecoverable void
            }
        }
    }
}

RasterGrid<float> ReferenceDemPreprocessor::computeTerrainConfidence(
    const RasterGrid<float>& dtmGrid, 
    const RasterGrid<uint8_t>& validMask)
{
    int w = dtmGrid.width;
    int h = dtmGrid.height;
    
    RasterGrid<float> confidence;
    confidence.width = w;
    confidence.height = h;
    confidence.data.resize(w * h, 0.0f);

    // multi-threaded slope gradient calculation
    #pragma omp parallel for schedule(static)
    for (int y = 1; y < h - 1; ++y)
    {
        for (int x = 1; x < w - 1; ++x)
        {
            int idx = y * w + x;
            if (validMask.data[idx] == 0 || std::isnan(dtmGrid.data[idx]))
            {
                confidence.data[idx] = 0.0f;
                continue;
            }

            // fix: Retrieve neighbors for Central Difference gradient
            float right = dtmGrid.data[y * w + (x + 1)];
            float left  = dtmGrid.data[y * w + (x - 1)];
            float down  = dtmGrid.data[(y + 1) * w + x];
            float up    = dtmGrid.data[(y - 1) * w + x];

            // fix: If the surrounding stencil contains NaN voids, the gradient calculation will collapse to NaN
            // we explicitly catch this and yield zero confidence
            if (std::isnan(right) || std::isnan(left) || std::isnan(down) || std::isnan(up)) 
            {
                confidence.data[idx] = 0.0f;
                continue;
            }

            // estimate local slope via central differences (calculating the steepness)
            float dz_dx = (right - left) * 0.5f;
            float dz_dy = (down - up) * 0.5f;
            float gradient = std::sqrt(dz_dx * dz_dx + dz_dy * dz_dy);

            // confidence Model: 
            // 30-meter satellite data is very reliable on flat ground but gets highly inaccurate 
            // on extremely steep cliff faces
            // steeper the slope, lower our confidence
            float conf = 1.0f / (1.0f + 0.05f * gradient);
            
            // clamp between 20% and 100% confidence
            confidence.data[idx] = std::clamp(conf, 0.2f, 1.0f);
        }
    }

    return confidence;
}

ReferenceTerrainBundle ReferenceDemPreprocessor::process(
    const RasterGrid<float>& warpedDem, 
    const SceneInput& scene,
    const std::string& demSource)
{
    // fix: Strict boundary validations to prevent segmentation faults and logic breaks
    if (warpedDem.width <= 0 || warpedDem.height <= 0 || warpedDem.data.empty()) 
    {
        throw std::invalid_argument("ReferenceDemPreprocessor: Warped DEM raster is empty.");
    }
    
    if (warpedDem.width != scene.width || warpedDem.height != scene.height) 
    {
        throw std::invalid_argument("ReferenceDemPreprocessor: Severe dimension mismatch between Optical Scene and Warped DEM.");
    }
    
    if (!scene.spatialMetadata.has_value()) 
    {
        throw std::invalid_argument("ReferenceDemPreprocessor: Cannot process terrain. SceneInput is missing SpatialMetadata.");
    }

    ReferenceTerrainBundle bundle;
    bundle.rawWarpedDem = warpedDem;
    bundle.demSource = demSource;
    bundle.sourceResolutionMeters = 30.0f;

    int w = scene.width;
    int h = scene.height;

    // initialize the valid mask with zeros
    bundle.validMask.width = w;
    bundle.validMask.height = h;
    bundle.validMask.data.resize(w * h, 0);

    // calculate physical Ground Sample Distance
    float gsd = computeGsd(*scene.spatialMetadata);

    // remove isolated spike anomalies
    RasterGrid<float> filteredDem = warpedDem;
    removeSpikes(filteredDem, 35.0f);

    // apply morphological opening to digitally bulldoze forests and buildings
    RasterGrid<float> bareEarthDTM = applyAdaptiveGroundFilter(filteredDem, gsd);

    // fill localized voids using Inverse Distance Weighting
    inpaintVoidsIDW(bareEarthDTM, bundle.validMask, 5);

    // generate per-pixel terrain confidence based on the slope
    bundle.confidence = computeTerrainConfidence(bareEarthDTM, bundle.validMask);
    bundle.correctedTerrainPrior = bareEarthDTM;

    return bundle;
}
