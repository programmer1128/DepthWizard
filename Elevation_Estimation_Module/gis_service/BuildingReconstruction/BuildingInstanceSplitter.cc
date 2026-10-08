#include "BuildingInstanceSplitter.h"
#include <opencv2/imgproc.hpp>
#include <algorithm>
#include <cmath>
#include <limits>
#include <numeric>
#include <queue>
#include <stdexcept>
#include <tuple>

RasterGrid<int32_t> BuildingInstanceSplitter::label(
    const RasterGrid<uint8_t>& mask, const SemanticScene& semantics,
    const RasterGrid<float>* ndsm, double pixelArea,
    const BuildingReconstructionConfig& config,
    const RasterGrid<uint8_t>* opticalGray)
{
    const int w = mask.width, h = mask.height;
    if (!mask.isValid() || !config.validate() || !std::isfinite(pixelArea) || pixelArea <= 0 ||
        !semantics.buildingProbability.isValid() || semantics.buildingProbability.width != w ||
        semantics.buildingProbability.height != h ||
        (ndsm && (!ndsm->isValid() || ndsm->width != w || ndsm->height != h)) ||
        (opticalGray && (!opticalGray->isValid() || opticalGray->width != w ||
                         opticalGray->height != h)))
        throw std::invalid_argument("BuildingInstanceSplitter: invalid inputs");
    for (float probability : semantics.buildingProbability.data)
        if (!std::isfinite(probability) || probability < 0 || probability > 1)
            throw std::invalid_argument("BuildingInstanceSplitter: invalid probability");

    cv::Mat binary;
    cv::compare(cv::Mat(h, w, CV_8U, const_cast<uint8_t*>(mask.data.data())),
                0, binary, cv::CMP_GT);
    cv::Mat original, stats, centroids;
    const int components = cv::connectedComponentsWithStats(
        binary, original, stats, centroids, 4, CV_32S);
    RasterGrid<int32_t> result;
    result.width = w; result.height = h;
    result.data.assign(original.ptr<int32_t>(), original.ptr<int32_t>() + mask.data.size());
    if (!config.splitSupportedInstances || components <= 1) return result;

    // Edge-preserving filtering damps isolated nDSM errors while retaining
    // party-wall steps.
    cv::Mat heights;
    if (ndsm) {
        cv::Mat ndsmMat(h, w, CV_32F, const_cast<float*>(ndsm->data.data()));
        cv::Mat validMask;
        cv::compare(ndsmMat, ndsmMat, validMask, cv::CMP_EQ); // Isolate non-NaNs
        cv::Mat patched;
        ndsmMat.copyTo(patched, validMask);
        patched.setTo(0, ~validMask); // Patch NaNs for OpenCV safety
        cv::bilateralFilter(patched, heights, 5, 2.0, 2.0);
    }
    cv::Mat optical;
    if (opticalGray)
    {
        const cv::Mat source(h, w, CV_8U,
            const_cast<uint8_t*>(opticalGray->data.data()));
        cv::GaussianBlur(source, optical, cv::Size(3, 3), 0.8);
    }

    // A gradual nDSM transition can connect two roof plateaus without ever
    // producing the local step used below. Search only sizeable components
    // for two well-separated height modes with a deep histogram valley.
    // This supplies a second, building-internal seed boundary and does not
    // depend on a map or any external footprint data.
    std::vector<float> modeThreshold(components,
        std::numeric_limits<float>::quiet_NaN());
    if (ndsm)
    {
        const int lastBin = std::min(500, static_cast<int>(
            std::ceil(config.maxBuildingHeightMetres)));
        std::vector<std::vector<int>> histogram(components);
        std::vector<int> sampleCount(components, 0);
        for (int component = 1; component < components; ++component)
            if (stats.at<int>(component, cv::CC_STAT_AREA) * pixelArea >= 250.0)
                histogram[component].resize(lastBin + 1, 0);
        for (std::size_t index = 0; index < mask.data.size(); ++index)
        {
            const int component = original.ptr<int>()[index];
            if (component <= 0 || histogram[component].empty()) continue;
            const float elevation = heights.ptr<float>()[index] *
                config.heightScaleMultiplier;
            if (!std::isfinite(elevation) || elevation <= 0.0f) continue;
            const int bin = std::clamp(static_cast<int>(elevation), 0, lastBin);
            ++histogram[component][bin];
            ++sampleCount[component];
        }
        for (int component = 1; component < components; ++component)
        {
            if (sampleCount[component] < 200) continue;
            const auto& bins = histogram[component];
            std::vector<float> smooth(bins.size(), 0.0f);
            for (std::size_t bin = 1; bin + 1 < bins.size(); ++bin)
                smooth[bin] = (bins[bin - 1] + 2.0f * bins[bin] +
                               bins[bin + 1]) * 0.25f;
            std::vector<int> peaks;
            const float minPeak = std::max(20.0f,
                0.01f * sampleCount[component]);
            for (int bin = 1; bin < lastBin; ++bin)
                if (smooth[bin] >= minPeak &&
                    smooth[bin] >= smooth[bin - 1] &&
                    smooth[bin] > smooth[bin + 1])
                    peaks.push_back(bin);
            float bestRatio = 0.45f;
            for (int lower : peaks)
                for (int upper : peaks)
                {
                    if (upper - lower < std::max(8,
                            static_cast<int>(std::ceil(
                                2.0f * config.instanceHeightStepMetres))))
                        continue;
                    const int valley = static_cast<int>(
                        std::min_element(smooth.begin() + lower,
                                         smooth.begin() + upper + 1) -
                        smooth.begin());
                    const float ratio = smooth[valley] /
                        std::min(smooth[lower], smooth[upper]);
                    if (ratio >= bestRatio) continue;
                    const int lowerCount = std::accumulate(
                        bins.begin(), bins.begin() + valley, 0);
                    const float fraction = static_cast<float>(lowerCount) /
                                           sampleCount[component];
                    if (fraction < 0.15f || fraction > 0.85f) continue;
                    bestRatio = ratio;
                    modeThreshold[component] = static_cast<float>(valley);
                }
        }
    }

    cv::Mat cores = cv::Mat::zeros(h, w, CV_8U);
    const int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
    // Probe a metric neighbourhood, not only the immediately adjacent pixel.
    // Monocular nDSM transitions are often spread over several pixels; the
    // old four-neighbour test therefore left adjacent roofs connected by a
    // smooth height ramp. Cap the radius to keep large scenes bounded.
    const double gsd = std::sqrt(pixelArea);
    const int heightProbeRadius = std::clamp(
        static_cast<int>(std::ceil(1.5 / gsd)), 1, 4);
    for (int y = 0; y < h; ++y)
        for (int x = 0; x < w; ++x)
        {
            const auto i = static_cast<std::size_t>(y) * w + x;
            if (!mask.data[i] || semantics.buildingProbability.data[i] < config.instanceSeedProbability)
                continue;
            bool roofStep = false;
            if (ndsm)
            {
                float localMin = std::numeric_limits<float>::infinity();
                float localMax = -std::numeric_limits<float>::infinity();
                for (int oy = -heightProbeRadius; oy <= heightProbeRadius; ++oy)
                    for (int ox = -heightProbeRadius; ox <= heightProbeRadius; ++ox)
                    {
                        const int nx = x + ox, ny = y + oy;
                        if (nx < 0 || ny < 0 || nx >= w || ny >= h ||
                            !binary.at<uint8_t>(ny, nx)) continue;
                        const float value = heights.at<float>(ny, nx);
                        if (!std::isfinite(value)) continue;
                        localMin = std::min(localMin, value);
                        localMax = std::max(localMax, value);
                    }
                roofStep = std::isfinite(localMin) && std::isfinite(localMax) &&
                    (localMax - localMin) * config.heightScaleMultiplier >=
                        config.instanceHeightStepMetres;
            }
            if (!roofStep) cores.at<uint8_t>(y, x) = 255;
        }

    std::vector<uint8_t> heightSide(mask.data.size(), 0);
    if (ndsm)
    {
        for (std::size_t index = 0; index < mask.data.size(); ++index)
        {
            const int component = original.ptr<int>()[index];
            if (component <= 0 || !std::isfinite(modeThreshold[component]))
                continue;
            const float elevation = heights.ptr<float>()[index] *
                config.heightScaleMultiplier;
            if (!std::isfinite(elevation) ||
                std::abs(elevation - modeThreshold[component]) <= 1.0f)
            {
                cores.ptr<uint8_t>()[index] = 0;
                continue;
            }
            heightSide[index] = elevation < modeThreshold[component] ? 1 : 2;
        }
        // Even a one-pixel abrupt jump must not reconnect the two marker
        // cores. Remove both sides of their common edge from the seed mask.
        for (int y = 0; y < h; ++y)
            for (int x = 0; x < w; ++x)
            {
                const auto index = static_cast<std::size_t>(y) * w + x;
                if (!heightSide[index]) continue;
                for (int k = 0; k < 4; ++k)
                {
                    const int nx = x + dx[k], ny = y + dy[k];
                    if (nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
                    const auto neighbour = static_cast<std::size_t>(ny) * w + nx;
                    if (original.ptr<int>()[neighbour] ==
                            original.ptr<int>()[index] &&
                        heightSide[neighbour] &&
                        heightSide[neighbour] != heightSide[index])
                    {
                        cores.ptr<uint8_t>()[index] = 0;
                        cores.ptr<uint8_t>()[neighbour] = 0;
                    }
                }
            }
    }

    cv::Mat seedLabels, seedStats, seedCentroids;
    const int seeds = cv::connectedComponentsWithStats(cores, seedLabels, seedStats, seedCentroids, 4, CV_32S);
    std::vector<int> parent(seeds, 0), supportedCount(components, 0), supportedArea(components, 0);
    std::vector<uint8_t> seedSide(seeds, 0);
    std::vector<int> seedToOutput(seeds, 0);
    for (int y = 0; y < h; ++y)
        for (int x = 0; x < w; ++x)
            if (const int seed = seedLabels.at<int>(y, x); seed > 0)
            {
                parent[seed] = original.at<int>(y, x);
                seedSide[seed] = heightSide[static_cast<std::size_t>(y) * w + x];
            }
    for (int seed = 1; seed < seeds; ++seed)
    {
        const int area = seedStats.at<int>(seed, cv::CC_STAT_AREA);
        if (area * pixelArea >= std::max(config.minInstanceSeedAreaSquareMetres,
                                         config.minBuildingAreaSquareMetres))
        {
            ++supportedCount[parent[seed]];
            supportedArea[parent[seed]] += area;
        }
    }

    // Many tiny/noisy markers or poor core coverage are not evidence for a
    // subdivision. Keep the original footprint rather than erase it.
    std::vector<bool> split(components, false);
    std::vector<int> largestLow(components, 0), largestHigh(components, 0);
    for (int seed = 1; seed < seeds; ++seed)
    {
        const int component = parent[seed];
        if (component <= 0 || !std::isfinite(modeThreshold[component]))
            continue;
        int& largest = seedSide[seed] == 1
            ? largestLow[component] : largestHigh[component];
        if (seedSide[seed] &&
            (!largest || seedStats.at<int>(seed, cv::CC_STAT_AREA) >
                            seedStats.at<int>(largest, cv::CC_STAT_AREA)))
            largest = seed;
    }
    for (int c = 1; c < components; ++c)
    {
        if (std::isfinite(modeThreshold[c]))
        {
            const int minimumPixels = static_cast<int>(std::ceil(
                std::max(50.0, static_cast<double>(
                    config.minBuildingAreaSquareMetres)) /
                pixelArea));
            split[c] = largestLow[c] && largestHigh[c] &&
                seedStats.at<int>(largestLow[c], cv::CC_STAT_AREA) >=
                    minimumPixels &&
                seedStats.at<int>(largestHigh[c], cv::CC_STAT_AREA) >=
                    minimumPixels;
        }
        else
            split[c] = supportedCount[c] >= 2 &&
                supportedCount[c] <= 128 &&
                supportedArea[c] >= config.minInstanceSeedCoverageRatio *
                    stats.at<int>(c, cv::CC_STAT_AREA);
    }

    int nextLabel = components;
    for (int seed = 1; seed < seeds; ++seed)
        if (split[parent[seed]] &&
            (std::isfinite(modeThreshold[parent[seed]])
                ? (seed == largestLow[parent[seed]] ||
                   seed == largestHigh[parent[seed]])
                : seedStats.at<int>(seed, cv::CC_STAT_AREA) * pixelArea >=
                    std::max(config.minInstanceSeedAreaSquareMetres,
                             config.minBuildingAreaSquareMetres)))
            seedToOutput[seed] = nextLabel++;

    // Multi-source Dijkstra flooding, restricted to each original component.
    // Keep the integer labels directly: converting back to a binary mask
    // would merge adjacent instances all over again.
    using Entry = std::tuple<double, std::size_t, int>;
    std::priority_queue<Entry, std::vector<Entry>, std::greater<Entry>> queue;
    std::vector<double> cost(mask.data.size(), std::numeric_limits<double>::infinity());
    for (std::size_t i = 0; i < mask.data.size(); ++i)
    {
        if (!split[original.ptr<int>()[i]]) continue;
        result.data[i] = 0;
        const int out = seedToOutput[seedLabels.ptr<int>()[i]];
        if (out) { result.data[i] = out; cost[i] = 0; }
    }
    // Queue only seed-frontier pixels, not every pixel of large roof cores.
    // All core pixels have cost zero and remain owned by their original seed.
    for (std::size_t i = 0; i < mask.data.size(); ++i)
    {
        if (cost[i] != 0) continue;
        const int x = static_cast<int>(i % w), y = static_cast<int>(i / w);
        for (int k = 0; k < 4; ++k)
        {
            const int nx = x + dx[k], ny = y + dy[k];
            if (nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
            const auto j = static_cast<std::size_t>(ny) * w + nx;
            if (result.data[j] == 0 && original.ptr<int>()[j] == original.ptr<int>()[i])
            {
                queue.emplace(0, i, result.data[i]);
                break;
            }
        }
    }
    while (!queue.empty())
    {
        const auto [distance, i, label] = queue.top(); queue.pop();
        if (distance != cost[i] || label != result.data[i]) continue;
        const int x = static_cast<int>(i % w), y = static_cast<int>(i / w);
        for (int k = 0; k < 4; ++k)
        {
            const int nx = x + dx[k], ny = y + dy[k];
            if (nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
            const auto j = static_cast<std::size_t>(ny) * w + nx;
            if (original.ptr<int>()[j] != original.ptr<int>()[i]) continue;
            double penalty = 1.0 + 4.0 * (1.0 - semantics.buildingProbability.data[j]);
            if (ndsm && std::isfinite(ndsm->data[i]) &&
                std::isfinite(ndsm->data[j]) &&
                std::isfinite(heights.ptr<float>()[i]) &&
                std::isfinite(heights.ptr<float>()[j]))
            {
                const double heightDiff =
                    std::abs(heights.ptr<float>()[j] -
                             heights.ptr<float>()[i]) *
                    config.heightScaleMultiplier;
                if (heightDiff > 0.50 * config.instanceHeightStepMetres)
                {
                    penalty += 10000.0; // Absolute concrete barrier
                }
                else
                {
                    penalty += (heightDiff / config.instanceHeightStepMetres) * 25.0; // Steeper soft penalty
                }
            }
            // Crossing an optical facade edge is more expensive than
            // expanding across a homogeneous roof. The cap prevents rooftop
            // texture from overpowering semantic and height evidence.
            if (opticalGray)
                penalty += std::min(3.0, std::abs(
                    static_cast<double>(optical.ptr<uint8_t>()[j]) -
                    optical.ptr<uint8_t>()[i]) / 16.0);
            const double candidate = distance + penalty;
            if (candidate < cost[j])
            {
                cost[j] = candidate; result.data[j] = label;
                queue.emplace(candidate, j, label);
            }
        }
    }
    return result;
}
