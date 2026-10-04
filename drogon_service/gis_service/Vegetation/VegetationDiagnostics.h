#pragma once
#include "VegetationCanopyBuilder.h"
#include "VegetationClassifier.h"
#include "VegetationConfig.h"
#include "VegetationHeightSampler.h"
#include "VegetationTypes.h"
#include "../structures/GeographicStructs.h"

#include <json/value.h>
#include <opencv2/core.hpp>

#include <filesystem>
#include <string>
#include <vector>

class VegetationDiagnostics
{
public:
     // Concise "[Vegetation] ..." log lines.
     static std::vector<std::string> summaryLines(const VegetationMask& mask, const VegetationHeights& heights,
                                                  double milliseconds);
     static Json::Value toJson(const VegetationConfig& config, const VegetationMask& mask,
                               const VegetationHeights& heights, double milliseconds);

     // "Before": the semantic classes over the optical image (vegetation
     // green, UNKNOWN grey, building red, road yellow, water blue).
     static cv::Mat semanticOverlay(const SemanticScene& semantics, const cv::Mat& opticalBgr);
     // "After": the cleaned mask over the optical image (confirmed green,
     // recovered UNKNOWN magenta, closed gaps cyan, protected buffer red).
     static cv::Mat maskOverlay(const VegetationMask& mask, const cv::Mat& opticalBgr);

     // Canopy stage: classes over the optical image (dense green, isolated
     // orange, protected red), and the canopy triangle edges drawn at their UVs.
     static cv::Mat classificationOverlay(const VegetationClassification& classification, const VegetationMask& mask,
                                          const cv::Mat& opticalBgr);
     static cv::Mat canopyWireframe(const VegetationCanopyMesh& canopy, int width, int height,
                                    const cv::Mat& opticalBgr);
     static Json::Value canopyJson(const VegetationClassification& classification, const VegetationCanopyMesh& canopy);
     // Concise "[Vegetation] ..." canopy log lines.
     static std::vector<std::string> canopyLines(const VegetationClassification& classification,
                                                 const VegetationCanopyMesh& canopy);
     // Writes vegetation_classes.png, vegetation_canopy_wireframe.png and
     // vegetation_canopy.json into `folder`.
     static bool writeCanopy(const std::filesystem::path& folder, const VegetationClassification& classification,
                             const VegetationMask& mask, const VegetationCanopyMesh& canopy,
                             const cv::Mat& opticalBgr);

     // Writes vegetation_before.png, vegetation_after.png and
     // vegetation_summary.json into `folder`. Returns false on failure.
     static bool write(const std::filesystem::path& folder, const VegetationConfig& config,
                       const SemanticScene& semantics, const VegetationMask& mask, const VegetationHeights& heights,
                       const cv::Mat& opticalBgr, double milliseconds);
};
