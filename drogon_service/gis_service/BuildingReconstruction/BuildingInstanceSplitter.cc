#include "BuildingInstanceSplitter.h"
#include <opencv2/imgproc.hpp>
#include <algorithm>
#include <cmath>
#include <limits>
#include <queue>
#include <stdexcept>
#include <tuple>

RasterGrid<int32_t> BuildingInstanceSplitter::label(
    const RasterGrid<uint8_t>& mask, const SemanticScene& semantics,
    const RasterGrid<float>* ndsm, double pixelArea,
    const BuildingReconstructionConfig& config)
{
    const int w = mask.width, h = mask.height;
    if (!mask.isValid() || !config.validate() || !std::isfinite(pixelArea) || pixelArea <= 0 ||
        !semantics.buildingProbability.isValid() || semantics.buildingProbability.width != w ||
        semantics.buildingProbability.height != h ||
        (ndsm && (!ndsm->isValid() || ndsm->width != w || ndsm->height != h)))
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

    // Median filtering damps isolated nDSM errors before detecting roof steps.
    cv::Mat heights;
    if (ndsm)
        cv::medianBlur(cv::Mat(h, w, CV_32F, const_cast<float*>(ndsm->data.data())), heights, 3);

    cv::Mat cores = cv::Mat::zeros(h, w, CV_8U);
    const int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
    for (int y = 0; y < h; ++y)
        for (int x = 0; x < w; ++x)
        {
            const auto i = static_cast<std::size_t>(y) * w + x;
            if (!mask.data[i] || semantics.buildingProbability.data[i] < config.instanceSeedProbability)
                continue;
            bool roofStep = false;
            for (int k = 0; ndsm && k < 4; ++k)
            {
                const int nx = x + dx[k], ny = y + dy[k];
                if (nx < 0 || ny < 0 || nx >= w || ny >= h || !binary.at<uint8_t>(ny, nx)) continue;
                const float a = heights.at<float>(y, x), b = heights.at<float>(ny, nx);
                roofStep |= std::isfinite(a) && std::isfinite(b) &&
                    std::abs(a - b) >= config.instanceHeightStepMetres;
            }
            if (!roofStep) cores.at<uint8_t>(y, x) = 255;
        }

    cv::Mat seedLabels, seedStats, seedCentroids;
    const int seeds = cv::connectedComponentsWithStats(cores, seedLabels, seedStats, seedCentroids, 4, CV_32S);
    std::vector<int> parent(seeds, 0), supportedCount(components, 0), supportedArea(components, 0);
    std::vector<int> seedToOutput(seeds, 0);
    for (int y = 0; y < h; ++y)
        for (int x = 0; x < w; ++x)
            if (const int seed = seedLabels.at<int>(y, x); seed > 0)
                parent[seed] = original.at<int>(y, x);
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
    for (int c = 1; c < components; ++c)
        split[c] = supportedCount[c] >= 2 && supportedCount[c] <= 64 &&
            supportedArea[c] >= 0.5 * stats.at<int>(c, cv::CC_STAT_AREA);

    int nextLabel = components;
    for (int seed = 1; seed < seeds; ++seed)
        if (split[parent[seed]] && seedStats.at<int>(seed, cv::CC_STAT_AREA) * pixelArea >=
            std::max(config.minInstanceSeedAreaSquareMetres, config.minBuildingAreaSquareMetres))
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
            if (ndsm && std::isfinite(heights.ptr<float>()[i]) && std::isfinite(heights.ptr<float>()[j]))
                penalty += std::min(20.0, static_cast<double>(std::abs(heights.ptr<float>()[j] -
                    heights.ptr<float>()[i]) / config.instanceHeightStepMetres));
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
