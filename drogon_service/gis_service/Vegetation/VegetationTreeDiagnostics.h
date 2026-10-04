#pragma once
#include "VegetationTreeCandidateGenerator.h"
#include "VegetationTreeInstancer.h"
#include "DenseForestProxyGenerator.h"
#include "VegetationCoverGenerator.h"

#include <json/value.h>
#include <opencv2/core.hpp>

#include <filesystem>
#include <string>
#include <vector>

// Diagnostics for stage-4 tree candidates. The JSON is a diagnostic format
// (schema version 1), not a public API contract.
class VegetationTreeDiagnostics
{
public:
     static Json::Value toJson(const VegetationTreeCandidates& trees);
     static std::vector<std::string> summaryLines(const VegetationTreeCandidates& trees);

     // Crown circles (blue isolated, orange canopy crown, magenta experimental)
     // over the optical image, and over the metric nDSM (grey, 0 to ceiling).
     static cv::Mat opticalOverlay(const VegetationTreeCandidates& trees, const VegetationPixelScale& scale,
                                   const cv::Mat& opticalBgr);
     static cv::Mat ndsmOverlay(const VegetationTreeCandidates& trees, const VegetationPixelScale& scale,
                                const RasterGrid<float>& ndsm, float ceilingMetres);
     static cv::Mat crownSegmentation(const VegetationTreeCandidates& trees, const cv::Mat& opticalBgr);
     static cv::Mat rejectedPeaks(const VegetationTreeCandidates& trees, const cv::Mat& opticalBgr);
     // Single-series histogram (bars in one hue on the chart surface).
     static cv::Mat histogram(const std::vector<float>& values, const std::string& title, const std::string& unit,
                              double low, double high, int bins);

     // Stage 5 instances: per-instance variant, reason, rotation, heights and
     // batch, plus per-variant / per-batch totals.
     static Json::Value instancesJson(const VegetationTreeInstances& trees);
     static std::vector<std::string> instanceLines(const VegetationTreeInstances& trees);
     static bool writeInstances(const std::filesystem::path& folder, const VegetationTreeInstances& trees);

     // Stage 5A forest-patch proxies (vegetation_forest_proxies.json). Proxy
     // counts are visualization patches, never reconstructed trees.
     static Json::Value forestJson(const DenseForestProxies& forest);
     static std::vector<std::string> forestLines(const DenseForestProxies& forest);
     static bool writeForest(const std::filesystem::path& folder, const DenseForestProxies& forest);

     // Stage 5A shrub cover: one log line; vegetation_cover.json (stats and
     // shrubs) and vegetation_cover.png (cover mask magenta, shrub discs green,
     // over the optical image).
     static std::string coverLine(const VegetationCover& cover);
     static bool writeCover(const std::filesystem::path& folder, const VegetationCover& cover, const cv::Mat& opticalBgr);

     // Writes vegetation_tree_candidates.json, the overlays, the segmentation,
     // the rejected-peak image and the three histograms into `folder`.
     static bool write(const std::filesystem::path& folder, const VegetationTreeCandidates& trees,
                       const VegetationPixelScale& scale, const RasterGrid<float>& ndsm, float ceilingMetres,
                       const cv::Mat& opticalBgr);
};
