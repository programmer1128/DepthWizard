#include "VegetationDiagnostics.h"

#include <json/json.h>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

#include <fstream>
#include <iomanip>
#include <sstream>

namespace
{
// Optical background at half intensity (or mid-grey without one), so the
// class colours stay legible.
cv::Mat background(const cv::Mat& opticalBgr, int width, int height)
{
     if (opticalBgr.empty() || opticalBgr.cols != width || opticalBgr.rows != height)
          return cv::Mat(height, width, CV_8UC3, cv::Scalar(96, 96, 96));
     cv::Mat dimmed;
     opticalBgr.convertTo(dimmed, CV_8UC3, 0.5);
     return dimmed;
}

void tint(cv::Vec3b& pixel, const cv::Vec3b& colour)
{
     for (int c = 0; c < 3; ++c) pixel[c] = static_cast<uint8_t>((pixel[c] + 3 * colour[c]) / 4);
}

std::string fixed(double value)
{
     std::ostringstream text;
     text << std::fixed << std::setprecision(2) << value;
     return text.str();
}
} // namespace

std::vector<std::string> VegetationDiagnostics::summaryLines(const VegetationMask& mask,
                                                             const VegetationHeights& heights, double milliseconds)
{
     const VegetationMaskStats& s = mask.stats;
     std::vector<std::string> lines;
     lines.push_back("[Vegetation] input_vegetation_pixels=" + std::to_string(s.inputVegetationPixels) +
                     ", input_unknown_pixels=" + std::to_string(s.inputUnknownPixels) +
                     ", cleaned_pixels=" + std::to_string(s.cleanedPixels()) +
                     ", components=" + std::to_string(s.components) +
                     ", pixel_m=" + fixed(mask.scale.columnSpacingMetres) + "x" + fixed(mask.scale.rowSpacingMetres) +
                     (mask.scale.georeferenced ? "" : " (fallback)"));
     lines.push_back("[Vegetation] confirmed_vegetation_pixels=" + std::to_string(s.confirmedPixels) +
                     ", recovered_unknown_pixels=" + std::to_string(s.recoveredPixels) +
                     ", gap_closed_pixels=" + std::to_string(s.gapPixels) +
                     ", removed_small_component_pixels=" + std::to_string(s.removedSmallComponentPixels));
     lines.push_back("[Vegetation] rejected_invalid_height=" + std::to_string(s.rejectedInvalidHeight) +
                     ", rejected_building_buffer=" + std::to_string(s.rejectedBuildingBuffer) +
                     ", rejected_below_min_height=" + std::to_string(s.rejectedBelowMinHeight) +
                     ", protected_pixels=" + std::to_string(s.protectedPixels));
     lines.push_back("[Vegetation] rejected_unknown_building=" + std::to_string(s.rejectedUnknownBuilding) +
                     ", rejected_unknown_road_water=" + std::to_string(s.rejectedUnknownRoadWater) +
                     ", rejected_unknown_probability=" + std::to_string(s.rejectedUnknownProbability) +
                     ", rejected_unknown_height=" + std::to_string(s.rejectedUnknownHeight) +
                     ", rejected_unknown_spatial_support=" + std::to_string(s.rejectedUnknownSpatialSupport));
     lines.push_back("[Vegetation] height_p05=" + fixed(heights.p05) + ", height_p50=" + fixed(heights.p50) +
                     ", height_p95=" + fixed(heights.p95) + ", height_ceiling=" + fixed(heights.ceilingMetres) +
                     ", clamped_pixels=" + std::to_string(heights.clampedPixels) +
                     ", processing_ms=" + fixed(milliseconds));
     return lines;
}

Json::Value VegetationDiagnostics::toJson(const VegetationConfig& config, const VegetationMask& mask,
                                          const VegetationHeights& heights, double milliseconds)
{
     const VegetationMaskStats& s = mask.stats;
     Json::Value root(Json::objectValue);
     root["config"] = config.summary();
     root["inputs_available"] = mask.inputsAvailable;
     root["pixel_spacing_m"].append(mask.scale.columnSpacingMetres);
     root["pixel_spacing_m"].append(mask.scale.rowSpacingMetres);
     root["georeferenced"] = mask.scale.georeferenced;
     const auto count = [](std::size_t value) { return static_cast<Json::UInt64>(value); };
     Json::Value& stats = root["stats"];
     stats["input_vegetation_pixels"] = count(s.inputVegetationPixels);
     stats["input_unknown_pixels"] = count(s.inputUnknownPixels);
     stats["protected_pixels"] = count(s.protectedPixels);
     stats["confirmed_candidates"] = count(s.confirmedCandidates);
     stats["rejected_invalid_height"] = count(s.rejectedInvalidHeight);
     stats["rejected_building_buffer"] = count(s.rejectedBuildingBuffer);
     stats["rejected_below_min_height"] = count(s.rejectedBelowMinHeight);
     stats["recovered_unknown_candidates"] = count(s.recoveredUnknownPixels);
     stats["rejected_unknown_building"] = count(s.rejectedUnknownBuilding);
     stats["rejected_unknown_road_water"] = count(s.rejectedUnknownRoadWater);
     stats["rejected_unknown_probability"] = count(s.rejectedUnknownProbability);
     stats["rejected_unknown_height"] = count(s.rejectedUnknownHeight);
     stats["rejected_unknown_spatial_support"] = count(s.rejectedUnknownSpatialSupport);
     stats["removed_small_component_pixels"] = count(s.removedSmallComponentPixels);
     stats["closed_gap_pixels"] = count(s.closedGapPixels);
     stats["confirmed_vegetation_pixels"] = count(s.confirmedPixels);
     stats["recovered_unknown_pixels"] = count(s.recoveredPixels);
     stats["gap_closed_pixels"] = count(s.gapPixels);
     stats["cleaned_pixels"] = count(s.cleanedPixels());
     stats["components"] = count(s.components);
     Json::Value& h = root["height_metric_m"];
     h["source"] = "NDSM";
     h["p05"] = heights.p05;
     h["p50"] = heights.p50;
     h["p95"] = heights.p95;
     h["ceiling"] = heights.ceilingMetres;
     h["sampled_pixels"] = count(heights.sampledPixels);
     h["clamped_pixels"] = count(heights.clampedPixels);
     root["processing_ms"] = milliseconds;
     root["external_geographic_data_used"] = false;
     return root;
}

cv::Mat VegetationDiagnostics::semanticOverlay(const SemanticScene& semantics, const cv::Mat& opticalBgr)
{
     const auto& classes = semantics.finalClassMap;
     cv::Mat image = background(opticalBgr, classes.width, classes.height);
     for (int y = 0; y < classes.height; ++y)
          for (int x = 0; x < classes.width; ++x)
          {
               cv::Vec3b& pixel = image.at<cv::Vec3b>(y, x);
               switch (classes.data[static_cast<std::size_t>(y) * classes.width + x])
               {
               case SemanticClass::VEGETATION: tint(pixel, {40, 200, 40}); break;
               case SemanticClass::UNKNOWN: tint(pixel, {150, 150, 150}); break;
               case SemanticClass::BUILDING: tint(pixel, {40, 40, 220}); break;
               case SemanticClass::ROAD: tint(pixel, {40, 210, 230}); break;
               case SemanticClass::WATER: tint(pixel, {220, 120, 30}); break;
               case SemanticClass::GROUND: break;
               }
          }
     return image;
}

cv::Mat VegetationDiagnostics::maskOverlay(const VegetationMask& mask, const cv::Mat& opticalBgr)
{
     cv::Mat image = background(opticalBgr, mask.tier.width, mask.tier.height);
     for (int y = 0; y < mask.tier.height; ++y)
          for (int x = 0; x < mask.tier.width; ++x)
          {
               const std::size_t i = static_cast<std::size_t>(y) * mask.tier.width + x;
               cv::Vec3b& pixel = image.at<cv::Vec3b>(y, x);
               switch (static_cast<VegetationTier>(mask.tier.data[i]))
               {
               case VegetationTier::CONFIRMED: tint(pixel, {40, 220, 40}); break;
               case VegetationTier::RECOVERED_UNKNOWN: tint(pixel, {230, 40, 230}); break;
               case VegetationTier::GAP_CLOSED: tint(pixel, {230, 230, 40}); break;
               case VegetationTier::NONE:
                    if (mask.protectedMask.data[i]) tint(pixel, {40, 40, 200});
                    break;
               }
          }
     return image;
}

bool VegetationDiagnostics::write(const std::filesystem::path& folder, const VegetationConfig& config,
                                  const SemanticScene& semantics, const VegetationMask& mask,
                                  const VegetationHeights& heights, const cv::Mat& opticalBgr, double milliseconds)
{
     std::error_code error;
     std::filesystem::create_directories(folder, error);
     if (error) return false;
     bool ok = cv::imwrite((folder / "vegetation_before.png").string(), semanticOverlay(semantics, opticalBgr));
     if (mask.inputsAvailable)
          ok = cv::imwrite((folder / "vegetation_after.png").string(), maskOverlay(mask, opticalBgr)) && ok;
     Json::StreamWriterBuilder writer;
     writer["indentation"] = "  ";
     std::ofstream json(folder / "vegetation_summary.json");
     json << Json::writeString(writer, toJson(config, mask, heights, milliseconds)) << "\n";
     return ok && static_cast<bool>(json);
}

cv::Mat VegetationDiagnostics::classificationOverlay(const VegetationClassification& classification,
                                                     const VegetationMask& mask, const cv::Mat& opticalBgr)
{
     const auto& classes = classification.classes;
     cv::Mat image = background(opticalBgr, classes.width, classes.height);
     for (int y = 0; y < classes.height; ++y)
          for (int x = 0; x < classes.width; ++x)
          {
               const std::size_t i = static_cast<std::size_t>(y) * classes.width + x;
               cv::Vec3b& pixel = image.at<cv::Vec3b>(y, x);
               switch (static_cast<VegetationClass>(classes.data[i]))
               {
               case VegetationClass::DENSE: tint(pixel, {40, 200, 40}); break;
               case VegetationClass::ISOLATED: tint(pixel, {30, 140, 250}); break;
               case VegetationClass::NONE:
                    if (!mask.protectedMask.data.empty() && mask.protectedMask.data[i]) tint(pixel, {40, 40, 200});
                    break;
               }
          }
     return image;
}

cv::Mat VegetationDiagnostics::canopyWireframe(const VegetationCanopyMesh& canopy, int width, int height,
                                               const cv::Mat& opticalBgr)
{
     cv::Mat image = background(opticalBgr, width, height);
     if (canopy.empty() || !canopy.primitive.uvs) return image;
     const auto& uvs = *canopy.primitive.uvs;
     const auto& indices = canopy.primitive.indices;
     // Draw at 2x so dense grids stay legible; UV * size is the pixel-edge coordinate.
     cv::Mat large;
     cv::resize(image, large, cv::Size(), 2.0, 2.0, cv::INTER_NEAREST);
     const auto at = [&](uint32_t vertex)
     {
          return cv::Point2f(uvs[vertex * 2] * width * 2.0f, uvs[vertex * 2 + 1] * height * 2.0f);
     };
     for (std::size_t t = 0; t + 2 < indices.size(); t += 3)
     {
          const cv::Point2f a = at(indices[t]), b = at(indices[t + 1]), c = at(indices[t + 2]);
          cv::line(large, a, b, cv::Scalar(60, 255, 60), 1, cv::LINE_8);
          cv::line(large, b, c, cv::Scalar(60, 255, 60), 1, cv::LINE_8);
          cv::line(large, c, a, cv::Scalar(60, 255, 60), 1, cv::LINE_8);
     }
     return large;
}

Json::Value VegetationDiagnostics::canopyJson(const VegetationClassification& classification,
                                              const VegetationCanopyMesh& canopy)
{
     const auto count = [](std::size_t value) { return static_cast<Json::UInt64>(value); };
     const VegetationClassificationStats& c = classification.stats;
     const VegetationCanopyStats& s = canopy.stats;
     Json::Value root(Json::objectValue);
     Json::Value& cls = root["classification"];
     cls["individual_trees_resolvable"] = c.individualTreesResolvable;
     cls["ground_resolution_m"] = c.groundResolutionMetres;
     cls["dense_pixels"] = count(c.densePixels);
     cls["isolated_pixels"] = count(c.isolatedPixels);
     cls["dense_components"] = count(c.denseComponents);
     cls["isolated_components"] = count(c.isolatedComponents);
     cls["dense_seeds"] = count(c.denseSeeds);
     cls["rejected_cores"] = count(c.rejectedCores);
     cls["dense_confirmed"] = count(c.denseConfirmed);
     cls["dense_recovered_unknown"] = count(c.denseRecovered);
     cls["dense_gap_closed"] = count(c.denseGap);
     cls["isolated_confirmed"] = count(c.isolatedConfirmed);
     cls["isolated_recovered_unknown"] = count(c.isolatedRecovered);
     cls["isolated_gap_closed"] = count(c.isolatedGap);
     Json::Value& mesh = root["canopy"];
     mesh["appended"] = !canopy.empty() && s.skippedReason.empty();
     if (!s.skippedReason.empty()) mesh["skipped_reason"] = s.skippedReason;
     mesh["vertices"] = count(s.vertices);
     mesh["triangles"] = count(s.triangles);
     mesh["stride_pixels"] = s.stride;
     mesh["cell_m"].append(s.cellColumnMetres);
     mesh["cell_m"].append(s.cellRowMetres);
     mesh["budget_limited"] = s.budgetLimited;
     mesh["terrain_aligned"] = s.terrainAligned;
     mesh["candidate_cells"] = count(s.candidateCells);
     mesh["rejected_barrier_cells"] = count(s.rejectedBarrierCells);
     mesh["rejected_coverage_cells"] = count(s.rejectedCoverageCells);
     mesh["removed_island_triangles"] = count(s.removedIslandTriangles);
     mesh["presentation_mode"] = s.presentationMode;
     mesh["display_height_scale"] = s.displayHeightScale;
     mesh["metric_height_m"].append(s.metricHeightMin);
     mesh["metric_height_m"].append(s.metricHeightMax);
     mesh["display_height"].append(s.displayHeightMin);
     mesh["display_height"].append(s.displayHeightMax);
     mesh["build_ms"] = s.buildMilliseconds;
     return root;
}

std::vector<std::string> VegetationDiagnostics::canopyLines(const VegetationClassification& classification,
                                                            const VegetationCanopyMesh& canopy)
{
     const VegetationClassificationStats& c = classification.stats;
     const VegetationCanopyStats& s = canopy.stats;
     return {
         "[Vegetation] dense_components=" + std::to_string(c.denseComponents) +
             ", isolated_components=" + std::to_string(c.isolatedComponents) +
             ", dense_pixels=" + std::to_string(c.densePixels) + ", isolated_pixels=" + std::to_string(c.isolatedPixels) +
             ", individual_trees_resolvable=" + std::to_string(c.individualTreesResolvable) +
             ", ground_resolution_m=" + fixed(c.groundResolutionMetres),
         "[Vegetation] canopy_vertices=" + std::to_string(s.vertices) + ", canopy_triangles=" +
             std::to_string(s.triangles) + ", stride=" + std::to_string(s.stride) + " (" + fixed(s.cellColumnMetres) +
             "x" + fixed(s.cellRowMetres) + " m" + (s.terrainAligned ? ", terrain-aligned" : "") + "), rejected_barrier_cells=" + std::to_string(s.rejectedBarrierCells) +
             ", display_height=" + fixed(s.displayHeightMin) + ".." + fixed(s.displayHeightMax) +
             " (scale " + fixed(s.displayHeightScale) + ", " + s.presentationMode + "), build_ms=" +
             fixed(s.buildMilliseconds) + (s.skippedReason.empty() ? "" : ", skipped: " + s.skippedReason),
     };
}

bool VegetationDiagnostics::writeCanopy(const std::filesystem::path& folder,
                                        const VegetationClassification& classification, const VegetationMask& mask,
                                        const VegetationCanopyMesh& canopy, const cv::Mat& opticalBgr)
{
     std::error_code error;
     std::filesystem::create_directories(folder, error);
     if (error) return false;
     bool ok = cv::imwrite((folder / "vegetation_classes.png").string(),
                           classificationOverlay(classification, mask, opticalBgr));
     ok = cv::imwrite((folder / "vegetation_canopy_wireframe.png").string(),
                      canopyWireframe(canopy, classification.classes.width, classification.classes.height,
                                      opticalBgr)) && ok;
     Json::StreamWriterBuilder writer;
     writer["indentation"] = "  ";
     std::ofstream json(folder / "vegetation_canopy.json");
     json << Json::writeString(writer, canopyJson(classification, canopy)) << "\n";
     return ok && static_cast<bool>(json);
}
