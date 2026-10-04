#include "VegetationTreeDiagnostics.h"

#include <json/json.h>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

#include <algorithm>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <sstream>

namespace
{
// Categorical slots of the reference palette, as BGR.
const cv::Scalar kBlue(214, 120, 42);      // #2a78d6  ISOLATED_TREE
const cv::Scalar kOrange(52, 104, 235);    // #eb6834  DENSE_CANOPY_CROWN
const cv::Scalar kAqua(122, 175, 27);      // #1baf7a
const cv::Scalar kYellow(0, 161, 237);     // #eda100
const cv::Scalar kMagenta(164, 123, 232);  // #e87ba4  EXPERIMENTAL
const cv::Scalar kGreen(0, 131, 0);        // #008300
const cv::Scalar kViolet(167, 58, 74);     // #4a3aa7
const cv::Scalar kRed(72, 73, 227);        // #e34948
const cv::Scalar kSurface(251, 252, 252);  // #fcfcfb
const cv::Scalar kTextPrimary(11, 11, 11); // #0b0b0b
const cv::Scalar kTextSecondary(78, 81, 82);  // #52514e
const cv::Scalar kGrid(225, 226, 226);

cv::Mat background(const cv::Mat& opticalBgr, int width, int height)
{
     if (opticalBgr.empty() || opticalBgr.cols != width || opticalBgr.rows != height)
          return cv::Mat(height, width, CV_8UC3, cv::Scalar(96, 96, 96));
     cv::Mat dimmed;
     opticalBgr.convertTo(dimmed, CV_8UC3, 0.6);
     return dimmed;
}

cv::Scalar categoryColour(const TreeCandidate& candidate)
{
     if (candidate.provenance == TreeProvenance::EXPERIMENTAL) return kMagenta;
     return candidate.category == TreeCandidateCategory::DENSE_CANOPY_CROWN ? kOrange : kBlue;
}

void drawCrowns(cv::Mat& image, const VegetationTreeCandidates& trees, const VegetationPixelScale& scale)
{
     for (const TreeCandidate& candidate : trees.candidates)
     {
          const cv::Point centre(static_cast<int>(std::lround(candidate.pixelColumn - 0.5)),
                                 static_cast<int>(std::lround(candidate.pixelRow - 0.5)));
          const cv::Size axes(std::max(1, static_cast<int>(std::lround(candidate.crownRadiusMetres / scale.columnSpacingMetres))),
                              std::max(1, static_cast<int>(std::lround(candidate.crownRadiusMetres / scale.rowSpacingMetres))));
          cv::ellipse(image, centre, axes, 0, 0, 360, cv::Scalar(255, 255, 255), 3, cv::LINE_AA); // Surface ring
          cv::ellipse(image, centre, axes, 0, 0, 360, categoryColour(candidate), 2, cv::LINE_AA);
          cv::circle(image, centre, 2, categoryColour(candidate), cv::FILLED, cv::LINE_AA);
     }
}

void legend(cv::Mat& image, const std::vector<std::pair<std::string, cv::Scalar>>& entries)
{
     int y = 22;
     for (const auto& [label, colour] : entries)
     {
          cv::rectangle(image, cv::Point(10, y - 11), cv::Point(10 + 14 + 9 * static_cast<int>(label.size()) + 14, y + 6),
                        kSurface, cv::FILLED);
          cv::circle(image, cv::Point(18, y - 3), 5, colour, cv::FILLED, cv::LINE_AA);
          cv::putText(image, label, cv::Point(30, y + 2), cv::FONT_HERSHEY_SIMPLEX, 0.45, kTextPrimary, 1, cv::LINE_AA);
          y += 22;
     }
}

cv::Scalar reasonColour(TreeRejection reason)
{
     switch (reason)
     {
     case TreeRejection::OVERLAP: return kBlue;
     case TreeRejection::TOO_SHORT: return kOrange;
     case TreeRejection::SPIKE: return kAqua;
     case TreeRejection::ROAD_WATER: return kYellow;
     case TreeRejection::CONFIDENCE: return kMagenta;
     case TreeRejection::SUPPORT: return kGreen;
     case TreeRejection::BUILDING: return kRed;
     default: return kViolet;
     }
}

std::string fixed(double value, int digits = 2)
{
     std::ostringstream text;
     text << std::fixed << std::setprecision(digits) << value;
     return text.str();
}
} // namespace

Json::Value VegetationTreeDiagnostics::toJson(const VegetationTreeCandidates& trees)
{
     const auto count = [](std::size_t value) { return static_cast<Json::UInt64>(value); };
     Json::Value root(Json::objectValue);
     root["version"] = 1;
     root["coordinateSystem"] = trees.coordinateSystem;
     root["presentationMode"] = trees.presentationMode;
     root["heightSource"] = "NDSM";
     root["baseSource"] = trees.baseSource;
     root["enabled"] = trees.enabled;
     if (!trees.disabledReason.empty()) root["disabledReason"] = trees.disabledReason;
     root["speciesInferred"] = false;
     root["externalGeographicDataUsed"] = false;
     const VegetationTreeCandidateStats& s = trees.stats;
     Json::Value& stats = root["stats"];
     stats["eligibleComponents"] = count(s.eligibleComponents);
     stats["localMaxima"] = count(s.localMaxima);
     stats["isolatedCandidates"] = count(s.isolatedCandidates);
     stats["denseCanopyCrownCandidates"] = count(s.denseCrownCandidates);
     stats["experimentalCandidates"] = count(s.experimentalCandidates);
     stats["accepted"] = count(s.accepted);
     Json::Value& rejected = stats["rejected"];
     for (int reason = 0; reason <= static_cast<int>(TreeRejection::LIMIT); ++reason)
          rejected[toString(static_cast<TreeRejection>(reason))] = count(s.rejected[reason]);
     // No timing here: the candidate file is byte-identical across runs.
     Json::Value& candidates = root["candidates"];
     candidates = Json::Value(Json::arrayValue);
     for (const TreeCandidate& c : trees.candidates)
     {
          Json::Value entry(Json::objectValue);
          entry["id"] = c.id;
          entry["category"] = toString(c.category);
          entry["semanticProvenance"] = toString(c.provenance);
          entry["pixelColumn"] = c.pixelColumn;
          entry["pixelRow"] = c.pixelRow;
          entry["worldX"] = c.worldX;
          entry["worldZ"] = c.worldZ;
          entry["baseY"] = c.baseY;
          entry["metricHeight"] = c.metricHeight;
          entry["displayHeight"] = c.displayHeight;
          entry["displayScale"] = c.displayScale;
          entry["topY"] = c.topY;
          entry["crownRadius"] = c.crownRadiusMetres;
          entry["supportAreaM2"] = c.supportAreaSquareMetres;
          entry["confidence"] = c.confidence;
          entry["prominence"] = c.prominenceMetres;
          entry["compactness"] = c.compactness;
          entry["vegetationSupport"] = c.vegetationSupport;
          entry["buildingClearance"] = c.clearanceMetres;
          entry["componentId"] = c.componentId;
          candidates.append(entry);
     }
     return root;
}

std::vector<std::string> VegetationTreeDiagnostics::summaryLines(const VegetationTreeCandidates& trees)
{
     if (!trees.enabled) return {"[Vegetation] trees disabled: " + trees.disabledReason};
     const VegetationTreeCandidateStats& s = trees.stats;
     return {
         "[Vegetation] tree_eligible_components=" + std::to_string(s.eligibleComponents) +
             ", local_maxima=" + std::to_string(s.localMaxima) +
             ", rejected_too_short=" + std::to_string(s.count(TreeRejection::TOO_SHORT)) +
             ", rejected_spike=" + std::to_string(s.count(TreeRejection::SPIKE)) +
             ", rejected_overlap=" + std::to_string(s.count(TreeRejection::OVERLAP)) +
             ", rejected_invalid_height=" + std::to_string(s.count(TreeRejection::INVALID_HEIGHT)),
         "[Vegetation] rejected_building=" + std::to_string(s.count(TreeRejection::BUILDING)) +
             ", rejected_road_water=" + std::to_string(s.count(TreeRejection::ROAD_WATER)) +
             ", rejected_bounds=" + std::to_string(s.count(TreeRejection::BOUNDS)) +
             ", rejected_support=" + std::to_string(s.count(TreeRejection::SUPPORT)) +
             ", rejected_proportions=" + std::to_string(s.count(TreeRejection::PROPORTIONS)) +
             ", rejected_prominence=" + std::to_string(s.count(TreeRejection::PROMINENCE)) +
             ", rejected_confidence=" + std::to_string(s.count(TreeRejection::CONFIDENCE)) +
             ", rejected_already_represented=" + std::to_string(s.count(TreeRejection::ALREADY_REPRESENTED)),
         "[Vegetation] tree_candidates: isolated=" + std::to_string(s.isolatedCandidates) +
             ", dense_canopy_crowns=" + std::to_string(s.denseCrownCandidates) +
             ", experimental=" + std::to_string(s.experimentalCandidates) + ", accepted=" + std::to_string(s.accepted) +
             ", rejected_limit=" + std::to_string(s.count(TreeRejection::LIMIT)) + ", tree_ms=" + fixed(trees.milliseconds),
     };
}

cv::Mat VegetationTreeDiagnostics::opticalOverlay(const VegetationTreeCandidates& trees,
                                                  const VegetationPixelScale& scale, const cv::Mat& opticalBgr)
{
     cv::Mat image = background(opticalBgr, trees.crownLabels.width, trees.crownLabels.height);
     drawCrowns(image, trees, scale);
     legend(image, {{"Isolated tree", kBlue}, {"Canopy crown", kOrange}, {"Experimental", kMagenta}});
     return image;
}

cv::Mat VegetationTreeDiagnostics::ndsmOverlay(const VegetationTreeCandidates& trees, const VegetationPixelScale& scale,
                                               const RasterGrid<float>& ndsm, float ceilingMetres)
{
     cv::Mat image(ndsm.height, ndsm.width, CV_8UC3);
     const float range = std::max(ceilingMetres, 1.0f);
     for (int y = 0; y < ndsm.height; ++y)
          for (int x = 0; x < ndsm.width; ++x)
          {
               const float h = ndsm.data[static_cast<std::size_t>(y) * ndsm.width + x];
               const auto level = static_cast<uint8_t>(std::isfinite(h) ? 25 + 205 * std::clamp(h / range, 0.0f, 1.0f) : 0);
               image.at<cv::Vec3b>(y, x) = cv::Vec3b(level, level, level);
          }
     drawCrowns(image, trees, scale);
     legend(image, {{"Isolated tree", kBlue}, {"Canopy crown", kOrange}, {"Experimental", kMagenta},
                    {"nDSM 0 to " + fixed(range, 1) + " m (grey)", cv::Scalar(180, 180, 180)}});
     return image;
}

cv::Mat VegetationTreeDiagnostics::crownSegmentation(const VegetationTreeCandidates& trees, const cv::Mat& opticalBgr)
{
     const auto& labels = trees.crownLabels;
     cv::Mat image = background(opticalBgr, labels.width, labels.height);
     const cv::Scalar palette[] = {kBlue, kOrange, kAqua, kYellow, kMagenta, kGreen, kViolet, kRed};
     for (int y = 0; y < labels.height; ++y)
          for (int x = 0; x < labels.width; ++x)
          {
               const int32_t id = labels.data[static_cast<std::size_t>(y) * labels.width + x];
               if (id == 0) continue;
               const cv::Scalar& colour = palette[static_cast<std::size_t>(id) % 8];
               cv::Vec3b& pixel = image.at<cv::Vec3b>(y, x);
               for (int c = 0; c < 3; ++c) pixel[c] = static_cast<uint8_t>((pixel[c] + 2 * colour[c]) / 3);
               // Crown boundaries in white.
               const bool edge = (x > 0 && labels.data[static_cast<std::size_t>(y) * labels.width + x - 1] != id) ||
                                 (y > 0 && labels.data[static_cast<std::size_t>(y - 1) * labels.width + x] != id);
               if (edge) pixel = cv::Vec3b(255, 255, 255);
          }
     return image;
}

cv::Mat VegetationTreeDiagnostics::rejectedPeaks(const VegetationTreeCandidates& trees, const cv::Mat& opticalBgr)
{
     cv::Mat image = background(opticalBgr, trees.crownLabels.width, trees.crownLabels.height);
     for (const TreeRejectedPeak& peak : trees.rejected)
          cv::drawMarker(image, cv::Point(peak.column, peak.row), reasonColour(peak.reason), cv::MARKER_TILTED_CROSS, 7, 2);
     std::vector<std::pair<std::string, cv::Scalar>> entries;
     for (TreeRejection reason : {TreeRejection::OVERLAP, TreeRejection::TOO_SHORT, TreeRejection::SPIKE,
                                  TreeRejection::ROAD_WATER, TreeRejection::CONFIDENCE, TreeRejection::SUPPORT,
                                  TreeRejection::BUILDING})
          entries.emplace_back(std::string(toString(reason)) + " (" + std::to_string(trees.stats.count(reason)) + ")",
                               reasonColour(reason));
     entries.emplace_back("other", kViolet);
     legend(image, entries);
     return image;
}

cv::Mat VegetationTreeDiagnostics::histogram(const std::vector<float>& values, const std::string& title,
                                             const std::string& unit, double low, double high, int bins)
{
     const int width = 640, height = 400, left = 56, right = 20, top = 52, bottom = 56;
     cv::Mat image(height, width, CV_8UC3, kSurface);
     std::vector<int> counts(static_cast<std::size_t>(bins), 0);
     for (float value : values)
     {
          if (!std::isfinite(value)) continue;
          const int bin = std::clamp(static_cast<int>((value - low) / (high - low) * bins), 0, bins - 1);
          ++counts[static_cast<std::size_t>(bin)];
     }
     const int maxCount = std::max(1, *std::max_element(counts.begin(), counts.end()));
     const int plotWidth = width - left - right, plotHeight = height - top - bottom;
     cv::putText(image, title + " (n = " + std::to_string(values.size()) + ")", cv::Point(left, 30),
                 cv::FONT_HERSHEY_SIMPLEX, 0.6, kTextPrimary, 1, cv::LINE_AA);
     // Recessive grid and count labels.
     for (int k = 0; k <= 4; ++k)
     {
          const int y = top + plotHeight - plotHeight * k / 4;
          cv::line(image, cv::Point(left, y), cv::Point(width - right, y), kGrid, 1);
          cv::putText(image, std::to_string(maxCount * k / 4), cv::Point(8, y + 4), cv::FONT_HERSHEY_SIMPLEX, 0.4,
                      kTextSecondary, 1, cv::LINE_AA);
     }
     const double barWidth = static_cast<double>(plotWidth) / bins;
     for (int b = 0; b < bins; ++b)
     {
          const int barHeight = plotHeight * counts[static_cast<std::size_t>(b)] / maxCount;
          if (barHeight == 0) continue;
          const int x0 = left + static_cast<int>(std::lround(b * barWidth)) + 1;  // 2 px surface gap between bars
          const int x1 = left + static_cast<int>(std::lround((b + 1) * barWidth)) - 1;
          cv::rectangle(image, cv::Point(x0, top + plotHeight - barHeight), cv::Point(std::max(x0, x1), top + plotHeight),
                        kBlue, cv::FILLED);
     }
     cv::line(image, cv::Point(left, top + plotHeight), cv::Point(width - right, top + plotHeight), kTextSecondary, 1);
     for (int k = 0; k <= 4; ++k)
     {
          const double value = low + (high - low) * k / 4.0;
          const int x = left + plotWidth * k / 4;
          cv::putText(image, fixed(value, 1), cv::Point(x - 12, top + plotHeight + 20), cv::FONT_HERSHEY_SIMPLEX, 0.4,
                      kTextSecondary, 1, cv::LINE_AA);
     }
     cv::putText(image, unit, cv::Point(left + plotWidth / 2 - 20, height - 12), cv::FONT_HERSHEY_SIMPLEX, 0.45,
                 kTextSecondary, 1, cv::LINE_AA);
     return image;
}

bool VegetationTreeDiagnostics::write(const std::filesystem::path& folder, const VegetationTreeCandidates& trees,
                                      const VegetationPixelScale& scale, const RasterGrid<float>& ndsm,
                                      float ceilingMetres, const cv::Mat& opticalBgr)
{
     std::error_code error;
     std::filesystem::create_directories(folder, error);
     if (error) return false;
     Json::StreamWriterBuilder writer;
     writer["indentation"] = "  ";
     std::ofstream json(folder / "vegetation_tree_candidates.json");
     json << Json::writeString(writer, toJson(trees)) << "\n";
     bool ok = static_cast<bool>(json);
     if (!trees.enabled) return ok;
     std::vector<float> confidence, radius, heights;
     for (const TreeCandidate& c : trees.candidates)
     {
          confidence.push_back(c.confidence);
          radius.push_back(c.crownRadiusMetres);
          heights.push_back(c.metricHeight);
     }
     const float maxHeight = heights.empty() ? 1.0f : *std::max_element(heights.begin(), heights.end());
     const float maxRadius = radius.empty() ? 1.0f : *std::max_element(radius.begin(), radius.end());
     ok = cv::imwrite((folder / "vegetation_trees_optical.png").string(), opticalOverlay(trees, scale, opticalBgr)) && ok;
     ok = cv::imwrite((folder / "vegetation_trees_ndsm.png").string(), ndsmOverlay(trees, scale, ndsm, ceilingMetres)) && ok;
     ok = cv::imwrite((folder / "vegetation_crowns.png").string(), crownSegmentation(trees, opticalBgr)) && ok;
     ok = cv::imwrite((folder / "vegetation_trees_rejected.png").string(), rejectedPeaks(trees, opticalBgr)) && ok;
     ok = cv::imwrite((folder / "vegetation_tree_confidence_histogram.png").string(),
                      histogram(confidence, "Tree candidate confidence", "confidence", 0.0, 1.0, 20)) && ok;
     ok = cv::imwrite((folder / "vegetation_tree_radius_histogram.png").string(),
                      histogram(radius, "Crown radius", "metres", 0.0, std::ceil(maxRadius + 0.5), 20)) && ok;
     ok = cv::imwrite((folder / "vegetation_tree_height_histogram.png").string(),
                      histogram(heights, "Metric tree height (nDSM)", "metres", 0.0, std::ceil(maxHeight + 0.5), 20)) && ok;
     return ok;
}

Json::Value VegetationTreeDiagnostics::instancesJson(const VegetationTreeInstances& trees)
{
     Json::Value root(Json::objectValue);
     root["version"] = 1;
     root["geometrySemantic"] = "VEGETATION_TREE_INSTANCES";
     root["speciesInferred"] = false;
     root["paletteFamily"] = trees.paletteFamily;
     root["chunkSizeMetres"] = trees.chunkSizeMetres;
     root["chunks"] = static_cast<Json::UInt64>(trees.chunks);
     root["lodEnabled"] = trees.lodEnabled;
     root["isolated"] = static_cast<Json::UInt64>(trees.isolated);
     root["canopyCrowns"] = static_cast<Json::UInt64>(trees.canopyCrowns);
     Json::Value& perVariant = root["instancesPerVariant"];
     perVariant = Json::Value(Json::objectValue);
     for (int v = 0; v < kTreeVariantCount; ++v)
          perVariant[toString(static_cast<TreeVisualVariant>(v))] = static_cast<Json::UInt64>(trees.perVariant[static_cast<std::size_t>(v)]);
     Json::Value& prototypes = root["prototypeTriangles"];
     prototypes = Json::Value(Json::objectValue);
     for (int v = 0; v < kTreeVariantCount; ++v)
          for (int l = 0; l < 3; ++l)
          {
               const TreePrototype& p = ProceduralTreePrototypeProvider::instance().prototype(
                   static_cast<TreeVisualVariant>(v), static_cast<TreeLod>(l));
               prototypes[p.name()] = static_cast<Json::UInt64>(p.triangles());
          }
     Json::Value& batches = root["batches"];
     batches = Json::Value(Json::arrayValue);
     for (const TreeBatch& b : trees.batches)
     {
          Json::Value entry(Json::objectValue);
          entry["node"] = b.name;
          entry["lod"] = toString(b.lod);
          entry["batch"] = b.batchKey;
          entry["instances"] = static_cast<Json::UInt64>(b.instances.size());
          entry["chunkIndex"] = b.chunkIndex;
          for (int c = 0; c < 3; ++c)
          {
               entry["boundsMin"].append(b.boundsMin[static_cast<std::size_t>(c)]);
               entry["boundsMax"].append(b.boundsMax[static_cast<std::size_t>(c)]);
          }
          batches.append(entry);
     }
     Json::Value& instances = root["instances"];
     instances = Json::Value(Json::arrayValue);
     for (const TreeInstance& i : trees.instances)
     {
          Json::Value entry(Json::objectValue);
          entry["candidateId"] = i.candidateId;
          entry["category"] = toString(i.category);
          entry["visualVariant"] = toString(i.variant);
          entry["variantReason"] = i.variantReason;
          entry["colourTint"] = i.colourTint;
          entry["deterministicRotation"] = i.rotationRadians;
          entry["widthFactor"] = i.widthFactor;
          entry["metricHeight"] = i.metricHeight;
          entry["displayHeight"] = i.displayHeight;
          entry["crownRadius"] = i.crownRadiusMetres;
          for (float v : i.translation) entry["translation"].append(v);
          for (float v : i.rotation) entry["rotation"].append(v);
          for (float v : i.scale) entry["scale"].append(v);
          entry["chunkIndex"] = i.chunkIndex;
          entry["assetSource"] = toString(i.assetSource);
          entry["rendered"] = i.rendered;
          instances.append(entry);
     }
     return root;
}

std::vector<std::string> VegetationTreeDiagnostics::instanceLines(const VegetationTreeInstances& trees)
{
     std::string variants;
     for (int v = 0; v < kTreeVariantCount; ++v)
     {
          if (trees.perVariant[static_cast<std::size_t>(v)] == 0) continue;
          if (!variants.empty()) variants += ", ";
          variants += std::string(toString(static_cast<TreeVisualVariant>(v))) + "=" +
                      std::to_string(trees.perVariant[static_cast<std::size_t>(v)]);
     }
     return {"[Vegetation] tree_instances=" + std::to_string(trees.instances.size()) + " (isolated=" +
                 std::to_string(trees.isolated) + ", canopy_crowns=" + std::to_string(trees.canopyCrowns) +
                 "), variants: " + variants,
             "[Vegetation] tree_chunks=" + std::to_string(trees.chunks) + " (" + fixed(trees.chunkSizeMetres, 0) +
                 " m), instanced_nodes=" + std::to_string(trees.batches.size()) + ", lod=" +
                 std::to_string(trees.lodEnabled) + ", palette_family=" + trees.paletteFamily};
}

bool VegetationTreeDiagnostics::writeInstances(const std::filesystem::path& folder, const VegetationTreeInstances& trees)
{
     std::error_code error;
     std::filesystem::create_directories(folder, error);
     if (error) return false;
     Json::StreamWriterBuilder writer;
     writer["indentation"] = "  ";
     std::ofstream json(folder / "vegetation_tree_instances.json");
     json << Json::writeString(writer, instancesJson(trees)) << "\n";
     return static_cast<bool>(json);
}

Json::Value VegetationTreeDiagnostics::forestJson(const DenseForestProxies& forest)
{
     Json::Value root(Json::objectValue);
     root["version"] = 1;
     root["geometrySemantic"] = "VEGETATION_FOREST_PROXY";
     root["assetSource"] = "FOREST_PATCH";
     root["positionSource"] = "DENSE_CANOPY_MASK";
     root["heightSource"] = "NDSM_ENVELOPE";
     root["individualTreesResolved"] = false;
     root["speciesInferred"] = false;
     root["externalGeographicDataUsed"] = false;
     root["enabled"] = forest.enabled;
     root["disabledReason"] = forest.disabledReason;
     root["forestProxyCount"] = static_cast<Json::UInt64>(forest.proxies.size());
     root["chunks"] = static_cast<Json::UInt64>(forest.chunks);
     root["chunkSizeMetres"] = forest.chunkSizeMetres;
     Json::Value& stats = root["stats"];
     stats["densePixels"] = static_cast<Json::UInt64>(forest.stats.densePixels);
     stats["denseMedianHeightMetres"] = forest.stats.denseMedianHeightMetres;
     stats["tested"] = static_cast<Json::UInt64>(forest.stats.tested);
     stats["rejectedFootprint"] = static_cast<Json::UInt64>(forest.stats.rejectedFootprint);
     stats["rejectedLow"] = static_cast<Json::UInt64>(forest.stats.rejectedLow);
     stats["rejectedSlope"] = static_cast<Json::UInt64>(forest.stats.rejectedSlope);
     stats["rejectedRelief"] = static_cast<Json::UInt64>(forest.stats.rejectedRelief);
     stats["rejectedTerrain"] = static_cast<Json::UInt64>(forest.stats.rejectedTerrain);
     stats["rejectedSpacing"] = static_cast<Json::UInt64>(forest.stats.rejectedSpacing);
     stats["notTestedAfterCap"] = static_cast<Json::UInt64>(forest.stats.capped);
     Json::Value& proxies = root["proxies"];
     proxies = Json::Value(Json::arrayValue);
     for (const ForestProxy& p : forest.proxies)
     {
          Json::Value entry(Json::objectValue);
          entry["id"] = p.id;
          entry["pixelColumn"] = p.pixelColumn;
          entry["pixelRow"] = p.pixelRow;
          for (float v : p.translation) entry["translation"].append(v);
          for (float v : p.rotation) entry["rotation"].append(v);
          entry["scale"] = p.scale;
          entry["envelopeMetres"] = p.envelopeMetres;
          entry["footprintRadiusMetres"] = p.footprintRadiusMetres;
          entry["tiltDegrees"] = p.tiltDegrees;
          entry["terrainResidualMetres"] = p.terrainResidualMetres;
          entry["yawRadians"] = p.yawRadians;
          entry["chunkIndex"] = p.chunkIndex;
          proxies.append(entry);
     }
     return root;
}

std::vector<std::string> VegetationTreeDiagnostics::forestLines(const DenseForestProxies& forest)
{
     const auto& s = forest.stats;
     return {"[Vegetation] forest_proxies=" + std::to_string(forest.proxies.size()) + " (visualization patches, not trees)" +
                 (forest.enabled ? std::string() : ", disabled: " + forest.disabledReason) + ", chunks=" +
                 std::to_string(forest.chunks) + ", dense_median_height=" + fixed(s.denseMedianHeightMetres, 2),
             "[Vegetation] forest_rejections: tested=" + std::to_string(s.tested) + ", footprint=" +
                 std::to_string(s.rejectedFootprint) + ", low=" + std::to_string(s.rejectedLow) + ", slope=" +
                 std::to_string(s.rejectedSlope) + ", relief=" + std::to_string(s.rejectedRelief) + ", terrain=" +
                 std::to_string(s.rejectedTerrain) + ", spacing=" + std::to_string(s.rejectedSpacing)};
}

bool VegetationTreeDiagnostics::writeForest(const std::filesystem::path& folder, const DenseForestProxies& forest)
{
     std::error_code error;
     std::filesystem::create_directories(folder, error);
     if (error) return false;
     Json::StreamWriterBuilder writer;
     writer["indentation"] = "  ";
     std::ofstream json(folder / "vegetation_forest_proxies.json");
     json << Json::writeString(writer, forestJson(forest)) << "\n";
     return static_cast<bool>(json);
}

std::string VegetationTreeDiagnostics::coverLine(const VegetationCover& cover)
{
     const auto& s = cover.stats;
     return "[Vegetation] cover_shrubs=" + std::to_string(cover.shrubs.size()) + " (visualization, " +
            (cover.mode == VegetationCoverMode::GARDEN ? "garden" : "natural") + ")" +
            (cover.enabled ? std::string() : ", disabled: " + cover.disabledReason) + ", cover_pixels=" +
            std::to_string(s.coverPixels) + " (semantic " + std::to_string(s.semanticPixels) + ", image " +
            std::to_string(s.imageDetectedPixels) + "), companions=" + std::to_string(s.companions) +
            ", rejected_flat_blobs=" + std::to_string(s.rejectedComponents) +
            ", chunks=" + std::to_string(cover.chunks);
}

bool VegetationTreeDiagnostics::writeCover(const std::filesystem::path& folder, const VegetationCover& cover,
                                           const cv::Mat& opticalBgr)
{
     std::error_code error;
     std::filesystem::create_directories(folder, error);
     if (error) return false;
     Json::Value root(Json::objectValue);
     root["version"] = 1;
     root["geometrySemantic"] = "VEGETATION_COVER_PROXY";
     root["mode"] = cover.mode == VegetationCoverMode::GARDEN ? "GARDEN" : "NATURAL";
     root["enabled"] = cover.enabled;
     root["disabledReason"] = cover.disabledReason;
     root["coverShrubCount"] = static_cast<Json::UInt64>(cover.shrubs.size());
     root["individualTreesResolved"] = false;
     root["speciesInferred"] = false;
     root["chunks"] = static_cast<Json::UInt64>(cover.chunks);
     Json::Value& stats = root["stats"];
     stats["coverPixels"] = static_cast<Json::UInt64>(cover.stats.coverPixels);
     stats["semanticPixels"] = static_cast<Json::UInt64>(cover.stats.semanticPixels);
     stats["imageDetectedPixels"] = static_cast<Json::UInt64>(cover.stats.imageDetectedPixels);
     stats["rejectedFlatComponents"] = static_cast<Json::UInt64>(cover.stats.rejectedComponents);
     stats["tested"] = static_cast<Json::UInt64>(cover.stats.tested);
     stats["notTestedAfterCap"] = static_cast<Json::UInt64>(cover.stats.capped);
     stats["companions"] = static_cast<Json::UInt64>(cover.stats.companions);
     root["visualProminenceScale"] = cover.mode == VegetationCoverMode::NATURAL ? VegetationCoverGenerator::kNaturalProminence : 1.0f;
     Json::Value& shrubs = root["shrubs"];
     shrubs = Json::Value(Json::arrayValue);
     for (const CoverShrub& s : cover.shrubs)
     {
          Json::Value entry(Json::objectValue);
          entry["pixelColumn"] = s.pixelColumn;
          entry["pixelRow"] = s.pixelRow;
          for (float v : s.translation) entry["translation"].append(v);
          for (float v : s.scale) entry["scale"].append(v);
          entry["metricHeight"] = s.metricHeight;
          entry["radiusMetres"] = s.radiusMetres;
          entry["chunkIndex"] = s.chunkIndex;
          entry["companion"] = s.companion;
          shrubs.append(entry);
     }
     Json::StreamWriterBuilder writer;
     writer["indentation"] = "  ";
     std::ofstream json(folder / "vegetation_cover.json");
     json << Json::writeString(writer, root) << "\n";
     bool ok = static_cast<bool>(json);
     if (!opticalBgr.empty() && cover.coverMask.isValid())
     {
          cv::Mat image;
          cv::resize(opticalBgr, image, cv::Size(cover.coverMask.width, cover.coverMask.height));
          cv::Mat overlay = image.clone();
          for (int y = 0; y < image.rows; ++y)
               for (int x = 0; x < image.cols; ++x)
                    if (cover.coverMask.data[static_cast<std::size_t>(y) * static_cast<std::size_t>(image.cols) + static_cast<std::size_t>(x)])
                         overlay.at<cv::Vec3b>(y, x) = cv::Vec3b(255, 0, 255);
          cv::addWeighted(image, 0.5, overlay, 0.5, 0.0, image);
          for (const CoverShrub& s : cover.shrubs)
               cv::circle(image, cv::Point(static_cast<int>(s.pixelColumn), static_cast<int>(s.pixelRow)), 1,
                          cv::Scalar(40, 220, 40), cv::FILLED);
          ok = cv::imwrite((folder / "vegetation_cover.png").string(), image) && ok;
     }
     return ok;
}
