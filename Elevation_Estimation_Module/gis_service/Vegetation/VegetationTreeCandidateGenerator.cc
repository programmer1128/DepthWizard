#include "VegetationTreeCandidateGenerator.h"
#include "VegetationMorphology.h"
#include "../MeshMapping/GeoTransformMapping.h"
#include "../MeshMapping/TerrainSurfaceSampler.h"

#include <opencv2/imgproc.hpp>

#include <algorithm>
#include <chrono>
#include <cmath>
#include <limits>
#include <map>
#include <queue>
#include <sstream>
#include <tuple>

namespace geo = depthwizard::geo;
using depthwizard::vegetation::metricEllipse;

const char* toString(TreeCandidateCategory category)
{
     return category == TreeCandidateCategory::DENSE_CANOPY_CROWN ? "DENSE_CANOPY_CROWN" : "ISOLATED_TREE";
}

const char* toString(TreeProvenance provenance)
{
     switch (provenance)
     {
     case TreeProvenance::RECOVERED_UNKNOWN: return "RECOVERED_UNKNOWN";
     case TreeProvenance::EXPERIMENTAL: return "EXPERIMENTAL";
     case TreeProvenance::CONFIRMED: break;
     }
     return "CONFIRMED";
}

const char* toString(TreeRejection reason)
{
     switch (reason)
     {
     case TreeRejection::TOO_SHORT: return "too_short";
     case TreeRejection::SPIKE: return "spike";
     case TreeRejection::INVALID_HEIGHT: return "invalid_height";
     case TreeRejection::OVERLAP: return "overlap";
     case TreeRejection::BUILDING: return "building";
     case TreeRejection::ROAD_WATER: return "road_water";
     case TreeRejection::BOUNDS: return "bounds";
     case TreeRejection::SUPPORT: return "support";
     case TreeRejection::PROPORTIONS: return "proportions";
     case TreeRejection::PROMINENCE: return "prominence";
     case TreeRejection::CONFIDENCE: return "confidence";
     case TreeRejection::ALREADY_REPRESENTED: return "already_represented";
     case TreeRejection::LIMIT: return "limit";
     }
     return "unknown";
}

namespace
{
template <typename T>
bool sized(const RasterGrid<T>& grid, int width, int height)
{
     return grid.isValid() && grid.width == width && grid.height == height;
}

// Nearest-rank percentile (the same rule as VegetationHeightSampler).
float percentile(std::vector<float> values, double fraction)
{
     const auto index = static_cast<std::size_t>(fraction * static_cast<double>(values.size() - 1) + 0.5);
     std::nth_element(values.begin(), values.begin() + static_cast<std::ptrdiff_t>(index), values.end());
     return values[index];
}

struct Peak
{
     int x{0}, y{0};
     float smoothed{0.0f};       // Smoothed height at the peak
     float robust{0.0f};         // Robust (percentile) metric height
     float vegetation{0.0f};     // Mean vegetation probability of the core
     float heightSupport{0.0f};  // Core share at or above the minimum height
     float initialRadius{0.0f};  // Distance-transform radius, clamped
     float prominence{0.0f};
     uint32_t component{0};
};

// Overlap preference: height support, vegetation support, initial radius
// (a compactness proxy), then pixel order. Never container order.
bool peakBefore(const Peak& a, const Peak& b)
{
     return std::tie(b.robust, b.vegetation, b.initialRadius, a.y, a.x) <
            std::tie(a.robust, a.vegetation, a.initialRadius, b.y, b.x);
}

struct CategoryOptions
{
     TreeCandidateCategory category{TreeCandidateCategory::ISOLATED_TREE};
     bool experimental{false};
     float separation{1.0f};
     float minSpacingMetres{0.0f};
     float minConfidence{0.0f};
     float minProminence{0.0f};
};
} // namespace

std::vector<TreeCandidate> VegetationTreeCandidateGenerator::rankAndLimit(std::vector<TreeCandidate> candidates,
                                                                          std::size_t limit,
                                                                          std::vector<TreeCandidate>* dropped)
{
     std::sort(candidates.begin(), candidates.end(), [](const TreeCandidate& a, const TreeCandidate& b)
     {
          const auto key = [](const TreeCandidate& c)
          {
               return std::make_tuple(-c.confidence, static_cast<int>(c.category), c.peakRow, c.peakColumn,
                                      static_cast<int>(c.provenance));
          };
          return key(a) < key(b);
     });
     if (candidates.size() > limit)
     {
          if (dropped != nullptr)
               dropped->assign(candidates.begin() + static_cast<std::ptrdiff_t>(limit), candidates.end());
          candidates.resize(limit);
     }
     return candidates;
}

VegetationTreeCandidates VegetationTreeCandidateGenerator::generate(const VegetationTreeInput& input)
{
     const auto started = std::chrono::steady_clock::now();
     VegetationTreeCandidates result;
     const bool flat = input.presentation == ScenePresentation::FLAT_URBAN;
     result.presentationMode = flat ? "flat_urban" : "metric";
     result.baseSource = flat ? "FLAT_URBAN_GROUND" : "DTM";
     result.coordinateSystem = "local scene frame: x = E - " + std::to_string(input.frame.projectedOriginX) +
                               ", z = -(N - " + std::to_string(input.frame.projectedOriginY) +
                               "), Y up = elevation - " + std::to_string(input.frame.elevationOrigin) +
                               " (metric) or flat ground; horizontal CRS of the source raster";
     const auto finish = [&](const std::string& reason)
     {
          result.disabledReason = reason;
          result.milliseconds =
              std::chrono::duration<double, std::milli>(std::chrono::steady_clock::now() - started).count();
          return result;
     };

     if (input.mask == nullptr || input.classification == nullptr || input.heights == nullptr ||
         input.semantics == nullptr || input.surface == nullptr || input.metadata == nullptr ||
         !input.mask->inputsAvailable)
          return finish("vegetation inputs unavailable");
     const SpatialMetadata& metadata = *input.metadata;
     const int width = metadata.width;
     const int height = metadata.height;
     const VegetationMask& mask = *input.mask;
     const VegetationConfig& config = input.config;
     if (!sized(input.classification->classes, width, height) || !sized(input.heights->metricHeight, width, height) ||
         !sized(mask.barrierMask, width, height) || !sized(mask.protectedMask, width, height))
          return finish("vegetation inputs unavailable");

     // Resolution gate: both pixel axes, georeferenced only.
     const VegetationPixelScale& scale = mask.scale;
     if (!scale.georeferenced)
          return finish("raster is not georeferenced: no metric crown reconstruction");
     if (std::max(scale.columnSpacingMetres, scale.rowSpacingMetres) > config.individualTreeMaxGsdMetres)
     {
          std::ostringstream reason;
          reason << "ground resolution " << scale.columnSpacingMetres << " x " << scale.rowSpacingMetres
                 << " m exceeds DEPTHWIZARD_VEGETATION_INDIVIDUAL_TREE_MAX_GSD_M=" << config.individualTreeMaxGsdMetres
                 << " m: individual crowns are not resolvable (canopy only)";
          return finish(reason.str());
     }
     const TerrainSurfaceSampler sampler(*input.surface, metadata, input.frame, input.terrainConfig);
     if (!flat && !sampler.supported()) return finish("terrain elevation source not mirrored");
     result.enabled = true;

     const std::size_t total = static_cast<std::size_t>(width) * height;
     const double finer = std::min(scale.columnSpacingMetres, scale.rowSpacingMetres);
     const double pixelArea = scale.pixelAreaSquareMetres();
     const float displayScale =
         VegetationHeightSampler::displayHeightScale(input.presentation, input.buildingDisplayHeightScale);
     const SemanticScene& semantics = *input.semantics;
     const auto metricDistance = [&](double x0, double y0, double x1, double y1)
     { return std::hypot((x1 - x0) * scale.columnSpacingMetres, (y1 - y0) * scale.rowSpacingMetres); };
     const auto radiusPixels = [&](double metres)
     {
          return std::make_pair(std::max(1, static_cast<int>(std::lround(metres / scale.columnSpacingMetres))),
                                std::max(1, static_cast<int>(std::lround(metres / scale.rowSpacingMetres))));
     };

     // Clearance to the nearest buffered building pixel.
     cv::Mat free(height, width, CV_8U), clearance;
     for (std::size_t i = 0; i < total; ++i) free.data[i] = mask.protectedMask.data[i] ? 0 : 1;
     cv::distanceTransform(free, clearance, cv::DIST_L2, cv::DIST_MASK_PRECISE);

     result.crownLabels.width = width;
     result.crownLabels.height = height;
     result.crownLabels.data.assign(total, 0);
     std::vector<TreeCandidate> all;   // Provisional ids = index + 1
     VegetationTreeCandidateStats& stats = result.stats;
     const auto reject = [&](int x, int y, TreeCandidateCategory category, TreeRejection reason)
     {
          ++stats.rejected[static_cast<int>(reason)];
          result.rejected.push_back({x, y, category, reason});
     };

     const auto runCategory = [&](const cv::Mat& region, const std::vector<float>& heights,
                                  const CategoryOptions& options)
     {
          if (cv::countNonZero(region) == 0) return;
          cv::Mat components;
          const int componentCount = cv::connectedComponents(region, components, 8, CV_32S);
          stats.eligibleComponents += static_cast<std::size_t>(componentCount - 1);

          // 1. Mask-normalised smoothing inside the region only.
          cv::Mat weighted(height, width, CV_32F), weights(height, width, CV_32F), smoothed;
          for (int y = 0; y < height; ++y)
               for (int x = 0; x < width; ++x)
               {
                    const std::size_t i = static_cast<std::size_t>(y) * width + x;
                    const bool inside = region.data[i] != 0;
                    weighted.at<float>(y, x) = inside ? heights[i] : 0.0f;
                    weights.at<float>(y, x) = inside ? 1.0f : 0.0f;
               }
          {
               // Gaussian (sigma = radius / 2 per axis), so a crown has one
               // true maximum instead of a box-filter plateau.
               const double sigmaX = std::max(0.5, 0.5 * config.treeSmoothRadiusMetres / scale.columnSpacingMetres);
               const double sigmaY = std::max(0.5, 0.5 * config.treeSmoothRadiusMetres / scale.rowSpacingMetres);
               const cv::Size kernel(2 * static_cast<int>(std::ceil(3 * sigmaX)) + 1,
                                     2 * static_cast<int>(std::ceil(3 * sigmaY)) + 1);
               cv::Mat sum, count;
               cv::GaussianBlur(weighted, sum, kernel, sigmaX, sigmaY, cv::BORDER_CONSTANT);
               cv::GaussianBlur(weights, count, kernel, sigmaX, sigmaY, cv::BORDER_CONSTANT);
               smoothed = cv::Mat(height, width, CV_32F, cv::Scalar(-1.0f));
               for (int y = 0; y < height; ++y)
                    for (int x = 0; x < width; ++x)
                         if (region.at<uint8_t>(y, x))
                              smoothed.at<float>(y, x) = sum.at<float>(y, x) / count.at<float>(y, x);
          }
          cv::Mat regionDistance;
          cv::distanceTransform(region, regionDistance, cv::DIST_L2, cv::DIST_MASK_PRECISE);

          // 2. Local maxima within the minimum crown radius.
          cv::Mat dilated;
          cv::dilate(smoothed, dilated, metricEllipse(config.treeMinCrownRadiusMetres, scale, true));
          const auto [coreX, coreY] = radiusPixels(config.treeCoreRadiusMetres);
          std::vector<Peak> peaks;
          for (int y = 0; y < height; ++y)
               for (int x = 0; x < width; ++x)
               {
                    if (!region.at<uint8_t>(y, x)) continue;
                    const float value = smoothed.at<float>(y, x);
                    if (value <= 0.0f || value < dilated.at<float>(y, x)) continue;
                    ++stats.localMaxima;
                    // 3. Robust height over the core window.
                    std::vector<float> core;
                    double vegetationSum = 0.0;
                    for (int dy = -coreY; dy <= coreY; ++dy)
                         for (int dx = -coreX; dx <= coreX; ++dx)
                         {
                              const int nx = x + dx, ny = y + dy;
                              if (nx < 0 || ny < 0 || nx >= width || ny >= height) continue;
                              const double ex = static_cast<double>(dx) / coreX, ey = static_cast<double>(dy) / coreY;
                              if (ex * ex + ey * ey > 1.0 + 1e-9 || !region.at<uint8_t>(ny, nx)) continue;
                              const std::size_t j = static_cast<std::size_t>(ny) * width + nx;
                              if (!std::isfinite(heights[j])) continue;
                              core.push_back(heights[j]);
                              vegetationSum += semantics.vegetationProbability.data[j];
                         }
                    const std::size_t i = static_cast<std::size_t>(y) * width + x;
                    if (core.empty() || !std::isfinite(heights[i]))
                    {
                         reject(x, y, options.category, TreeRejection::INVALID_HEIGHT);
                         continue;
                    }
                    Peak peak;
                    peak.x = x;
                    peak.y = y;
                    peak.smoothed = value;
                    peak.robust = std::min(percentile(core, config.treeHeightPercentile), input.heights->ceilingMetres);
                    const float median = percentile(core, 0.5);
                    if (peak.robust < config.minHeightMetres)
                    {
                         reject(x, y, options.category, TreeRejection::TOO_SHORT);
                         continue;
                    }
                    if (median < config.treeSpikeMedianFraction * std::max(heights[i], peak.robust))
                    {
                         reject(x, y, options.category, TreeRejection::SPIKE);
                         continue;
                    }
                    peak.vegetation = static_cast<float>(vegetationSum / static_cast<double>(core.size()));
                    peak.heightSupport = static_cast<float>(
                        std::count_if(core.begin(), core.end(), [&](float h) { return h >= config.minHeightMetres; })) /
                        static_cast<float>(core.size());
                    peak.initialRadius = static_cast<float>(std::clamp(
                        regionDistance.at<float>(y, x) * finer, static_cast<double>(config.treeMinCrownRadiusMetres),
                        static_cast<double>(config.treeMaxCrownRadiusMetres)));
                    peak.component = static_cast<uint32_t>(components.at<int>(y, x));
                    peaks.push_back(peak);
               }

          // Prominence: above the lowest smoothed height in a 2 m ring beyond
          // the initial radius (canopy crowns), or the height itself.
          for (Peak& peak : peaks)
          {
               peak.prominence = peak.robust;
               if (options.category != TreeCandidateCategory::DENSE_CANOPY_CROWN) continue;
               const double outer = peak.initialRadius + 2.0;
               const auto [ox, oy] = radiusPixels(outer);
               float lowest = std::numeric_limits<float>::max();
               for (int dy = -oy; dy <= oy; ++dy)
                    for (int dx = -ox; dx <= ox; ++dx)
                    {
                         const int nx = peak.x + dx, ny = peak.y + dy;
                         if (nx < 0 || ny < 0 || nx >= width || ny >= height || !region.at<uint8_t>(ny, nx)) continue;
                         const double d = metricDistance(peak.x, peak.y, nx, ny);
                         if (d < peak.initialRadius || d > outer) continue;
                         lowest = std::min(lowest, smoothed.at<float>(ny, nx));
                    }
               if (lowest != std::numeric_limits<float>::max()) peak.prominence = peak.smoothed - lowest;

               // Inside canopy the region edge is far away, so the crown's own
               // radial nDSM profile gives the initial radius: the first ring
               // whose mean smoothed height has fallen by max(1 m, prominence / 4).
               const double drop = std::max(1.0, 0.25 * static_cast<double>(peak.prominence));
               const auto [mx, my] = radiusPixels(config.treeMaxCrownRadiusMetres);
               const int rings = static_cast<int>(std::ceil(config.treeMaxCrownRadiusMetres / finer));
               std::vector<double> ringSum(static_cast<std::size_t>(rings + 1), 0.0);
               std::vector<int> ringCount(static_cast<std::size_t>(rings + 1), 0);
               for (int dy = -my; dy <= my; ++dy)
                    for (int dx = -mx; dx <= mx; ++dx)
                    {
                         const int nx = peak.x + dx, ny = peak.y + dy;
                         if (nx < 0 || ny < 0 || nx >= width || ny >= height || !region.at<uint8_t>(ny, nx)) continue;
                         const int ring = static_cast<int>(std::lround(metricDistance(peak.x, peak.y, nx, ny) / finer));
                         if (ring > rings) continue;
                         ringSum[static_cast<std::size_t>(ring)] += smoothed.at<float>(ny, nx);
                         ++ringCount[static_cast<std::size_t>(ring)];
                    }
               double profileRadius = config.treeMaxCrownRadiusMetres;
               for (int ring = 1; ring <= rings; ++ring)
               {
                    if (ringCount[static_cast<std::size_t>(ring)] == 0) continue;
                    if (ringSum[static_cast<std::size_t>(ring)] / ringCount[static_cast<std::size_t>(ring)] <=
                        peak.smoothed - drop)
                    {
                         profileRadius = ring * finer;
                         break;
                    }
               }
               peak.initialRadius = static_cast<float>(std::clamp(profileRadius,
                                                                  static_cast<double>(config.treeMinCrownRadiusMetres),
                                                                  static_cast<double>(config.treeMaxCrownRadiusMetres)));
          }

          // 4. Radius-aware non-maximum suppression in a stable order.
          std::sort(peaks.begin(), peaks.end(), peakBefore);
          std::vector<Peak> seeds;
          for (const Peak& peak : peaks)
          {
               bool overlaps = false;
               for (const Peak& seed : seeds)
               {
                    const double separation = std::max<double>(
                        options.separation * std::max(peak.initialRadius, seed.initialRadius), options.minSpacingMetres);
                    if (metricDistance(peak.x, peak.y, seed.x, seed.y) < separation)
                    {
                         overlaps = true;
                         break;
                    }
               }
               if (overlaps) reject(peak.x, peak.y, options.category, TreeRejection::OVERLAP);
               else seeds.push_back(peak);
          }
          if (seeds.empty()) return;

          // 5. Crown segmentation: priority flood from the seeds (higher
          //    smoothed height first, then pixel index), within the maximum
          //    crown radius of the seed.
          std::vector<int32_t> owner(total, 0);
          using Entry = std::tuple<float, int64_t, int32_t>; // height, -index, seed (1-based)
          std::priority_queue<Entry> queue;
          for (std::size_t s = 0; s < seeds.size(); ++s)
          {
               const std::size_t i = static_cast<std::size_t>(seeds[s].y) * width + seeds[s].x;
               owner[i] = static_cast<int32_t>(s + 1);
               queue.emplace(seeds[s].smoothed, -static_cast<int64_t>(i), static_cast<int32_t>(s + 1));
          }
          while (!queue.empty())
          {
               const auto [value, negativeIndex, seed] = queue.top();
               queue.pop();
               (void)value;
               const int64_t index = -negativeIndex;
               const int x = static_cast<int>(index % width), y = static_cast<int>(index / width);
               for (int dy = -1; dy <= 1; ++dy)
                    for (int dx = -1; dx <= 1; ++dx)
                    {
                         const int nx = x + dx, ny = y + dy;
                         if ((dx == 0 && dy == 0) || nx < 0 || ny < 0 || nx >= width || ny >= height) continue;
                         const std::size_t j = static_cast<std::size_t>(ny) * width + nx;
                         if (owner[j] != 0 || !region.data[j]) continue;
                         const Peak& source = seeds[static_cast<std::size_t>(seed - 1)];
                         if (metricDistance(source.x, source.y, nx, ny) > config.treeMaxCrownRadiusMetres) continue;
                         owner[j] = seed;
                         queue.emplace(smoothed.at<float>(ny, nx), -static_cast<int64_t>(j), seed);
                    }
          }

          // 6. Crown measurements.
          const std::size_t seedCount = seeds.size();
          std::vector<std::size_t> area(seedCount + 1, 0), halfArea(seedCount + 1, 0), confirmed(seedCount + 1, 0),
              recovered(seedCount + 1, 0);
          std::vector<double> extent(seedCount + 1, 0.0), centroidX(seedCount + 1, 0.0), centroidY(seedCount + 1, 0.0),
              centroidWeight(seedCount + 1, 0.0);
          for (int y = 0; y < height; ++y)
               for (int x = 0; x < width; ++x)
               {
                    const std::size_t i = static_cast<std::size_t>(y) * width + x;
                    const int32_t s = owner[i];
                    if (s == 0) continue;
                    const Peak& seed = seeds[static_cast<std::size_t>(s - 1)];
                    ++area[s];
                    const float value = smoothed.at<float>(y, x);
                    // Radial decline: still within half the crown's relief of
                    // its peak (half height for an isolated tree).
                    if (value >= seed.smoothed - 0.5f * seed.prominence) ++halfArea[s];
                    const double d = metricDistance(seed.x, seed.y, x, y);
                    extent[s] = std::max(extent[s], d);
                    if (d <= config.treeCoreRadiusMetres && value >= 0.9f * seed.smoothed)
                    {
                         centroidX[s] += value * (x + 0.5);
                         centroidY[s] += value * (y + 0.5);
                         centroidWeight[s] += value;
                    }
                    const auto tier = static_cast<VegetationTier>(mask.tier.data[i]);
                    if (tier == VegetationTier::CONFIRMED) ++confirmed[s];
                    else if (tier == VegetationTier::RECOVERED_UNKNOWN) ++recovered[s];
               }

          std::vector<int32_t> seedToId(seedCount + 1, 0);
          for (std::size_t s = 1; s <= seedCount; ++s)
          {
               const Peak& seed = seeds[s - 1];
               const double supportArea = static_cast<double>(area[s]) * pixelArea;
               if (supportArea < config.treeMinSupportAreaSquareMetres)
               {
                    reject(seed.x, seed.y, options.category, TreeRejection::SUPPORT);
                    continue;
               }
               const double areaRadius = std::sqrt(supportArea / M_PI);
               const double declineRadius = std::sqrt(static_cast<double>(halfArea[s]) * pixelArea / M_PI);
               // Inside continuous canopy the region's distance transform only
               // measures the distance to the canopy edge; the spacing to the
               // nearest neighbouring crown is the informative extent there.
               double extentRadius = seed.initialRadius;
               if (options.category == TreeCandidateCategory::DENSE_CANOPY_CROWN)
               {
                    double nearest = config.treeMaxCrownRadiusMetres * 2.0;
                    for (const Peak& other : seeds)
                         if (&other != &seed) nearest = std::min(nearest, metricDistance(seed.x, seed.y, other.x, other.y));
                    extentRadius = 0.5 * nearest;
               }
               double radii[3] = {extentRadius, areaRadius, declineRadius};
               std::sort(radii, radii + 3);
               double radius = std::clamp(radii[1], static_cast<double>(config.treeMinCrownRadiusMetres),
                                          static_cast<double>(config.treeMaxCrownRadiusMetres));
               const double reach = extent[s] + 0.5 * finer;
               const double compactness = std::min(1.0, supportArea / (M_PI * reach * reach));
               const double aspect = seed.robust / (2.0 * radius);
               if (aspect < config.treeMinAspect || aspect > config.treeMaxAspect)
               {
                    reject(seed.x, seed.y, options.category, TreeRejection::PROPORTIONS);
                    continue;
               }
               const double column = centroidWeight[s] > 0.0 ? centroidX[s] / centroidWeight[s] : seed.x + 0.5;
               const double row = centroidWeight[s] > 0.0 ? centroidY[s] / centroidWeight[s] : seed.y + 0.5;
               const int cx = std::clamp(static_cast<int>(column), 0, width - 1);
               const int cy = std::clamp(static_cast<int>(row), 0, height - 1);
               const std::size_t ci = static_cast<std::size_t>(cy) * width + cx;

               // 7. Exclusions.
               const auto cls = semantics.finalClassMap.data[ci];
               if (mask.protectedMask.data[ci])
               {
                    reject(seed.x, seed.y, options.category, TreeRejection::BUILDING);
                    continue;
               }
               if (cls == SemanticClass::ROAD || cls == SemanticClass::WATER ||
                   std::max(semantics.roadProbability.data[ci], semantics.waterProbability.data[ci]) >=
                       config.maxUnknownRoadWaterProbability)
               {
                    reject(seed.x, seed.y, options.category, TreeRejection::ROAD_WATER);
                    continue;
               }
               if (mask.barrierMask.data[ci])
               {
                    reject(seed.x, seed.y, options.category, TreeRejection::INVALID_HEIGHT);
                    continue;
               }
               // Capped at the scene diagonal (no building at all: the distance
               // transform's sentinel is not a distance).
               const double diagonal = std::hypot(width * scale.columnSpacingMetres, height * scale.rowSpacingMetres);
               const double buildingClearance =
                   // One full pixel of margin absorbs footprint-rasterisation differences.
                   std::min(diagonal, std::max(0.0, clearance.at<float>(cy, cx) * finer - finer));
               if (buildingClearance < config.treeMinCrownRadiusMetres)
               {
                    reject(seed.x, seed.y, options.category, TreeRejection::BUILDING);
                    continue;
               }
               radius = std::min(radius, buildingClearance);
               const double border = std::min({column * scale.columnSpacingMetres, row * scale.rowSpacingMetres,
                                               (width - column) * scale.columnSpacingMetres,
                                               (height - row) * scale.rowSpacingMetres});
               if (border < config.treeMinCrownRadiusMetres)
               {
                    reject(seed.x, seed.y, options.category, TreeRejection::BOUNDS);
                    continue;
               }
               radius = std::min(radius, border);

               // 8. Confidence.
               const double confidence = 0.30 * seed.vegetation + 0.25 * std::min(seed.prominence / 4.0, 1.0) +
                                         0.20 * compactness + 0.15 * seed.heightSupport +
                                         0.10 * std::min(buildingClearance / 5.0, 1.0);
               if (seed.prominence < options.minProminence)
               {
                    reject(seed.x, seed.y, options.category, TreeRejection::PROMINENCE);
                    continue;
               }
               if (confidence < options.minConfidence)
               {
                    reject(seed.x, seed.y, options.category, TreeRejection::CONFIDENCE);
                    continue;
               }
               if (options.experimental)
               {
                    // Not if a confirmed/recovered candidate already covers it.
                    bool represented = false;
                    for (const TreeCandidate& other : all)
                         represented = represented ||
                             metricDistance(other.pixelColumn, other.pixelRow, column, row) <
                                 std::max<double>(radius, other.crownRadiusMetres);
                    if (represented)
                    {
                         reject(seed.x, seed.y, options.category, TreeRejection::ALREADY_REPRESENTED);
                         continue;
                    }
               }

               // 9. Base, world position and heights.
               float base = 0.0f;
               if (!flat)
               {
                    const auto ground = sampler.localHeight(column, row);
                    if (!ground)
                    {
                         reject(seed.x, seed.y, options.category, TreeRejection::INVALID_HEIGHT);
                         continue;
                    }
                    base = *ground;
               }
               TreeCandidate candidate;
               candidate.id = static_cast<uint32_t>(all.size() + 1);
               candidate.category = options.category;
               candidate.provenance = options.experimental ? TreeProvenance::EXPERIMENTAL
                   : (recovered[s] > confirmed[s] ? TreeProvenance::RECOVERED_UNKNOWN : TreeProvenance::CONFIRMED);
               candidate.pixelColumn = column;
               candidate.pixelRow = row;
               candidate.peakColumn = seed.x;
               candidate.peakRow = seed.y;
               const LocalPoint local = geo::pixelEdgeToLocal(metadata, input.frame, column, row);
               candidate.worldX = local.x;
               candidate.worldZ = local.z;
               candidate.baseY = base;
               candidate.metricHeight = seed.robust;
               candidate.displayScale = displayScale;
               candidate.displayHeight = seed.robust * displayScale;
               candidate.topY = base + candidate.displayHeight;
               candidate.crownRadiusMetres = static_cast<float>(radius);
               candidate.supportAreaSquareMetres = static_cast<float>(supportArea);
               candidate.confidence = static_cast<float>(confidence);
               candidate.prominenceMetres = seed.prominence;
               candidate.compactness = static_cast<float>(compactness);
               candidate.vegetationSupport = seed.vegetation;
               candidate.clearanceMetres = static_cast<float>(buildingClearance);
               candidate.componentId = seed.component;
               all.push_back(candidate);
               seedToId[s] = static_cast<int32_t>(candidate.id);
          }
          // Provisional crown labels (rewritten with final ids below).
          for (std::size_t i = 0; i < total; ++i)
               if (owner[i] != 0 && seedToId[static_cast<std::size_t>(owner[i])] != 0)
                    result.crownLabels.data[i] = seedToId[static_cast<std::size_t>(owner[i])];
     };

     const auto& classes = input.classification->classes.data;
     const auto classRegion = [&](VegetationClass cls)
     {
          cv::Mat region(height, width, CV_8U);
          for (std::size_t i = 0; i < total; ++i)
               region.data[i] = classes[i] == static_cast<uint8_t>(cls) &&
                                        std::isfinite(input.heights->metricHeight.data[i])
                   ? 1 : 0;
          return region;
     };
     runCategory(classRegion(VegetationClass::ISOLATED), input.heights->metricHeight.data,
                 {TreeCandidateCategory::ISOLATED_TREE, false, config.treeIsolatedSeparation, 0.0f,
                  config.treeIsolatedMinConfidence, 0.0f});
     runCategory(classRegion(VegetationClass::DENSE), input.heights->metricHeight.data,
                 {TreeCandidateCategory::DENSE_CANOPY_CROWN, false, config.denseCrownSeparation,
                  config.denseCrownMinSpacingMetres, config.denseCrownMinConfidence,
                  config.denseCrownMinProminenceMetres});

     // Experimental low-confidence recovery: crown-like UNKNOWN regions the
     // stage-2 mask left out, with every building/road/water gate.
     if (config.treeRecoverLowConfidence)
     {
          const RasterGrid<float>& source =
              input.recoveryNdsm != nullptr && sized(*input.recoveryNdsm, width, height) ? *input.recoveryNdsm
                                                                                         : input.surface->ndsm;
          std::vector<float> recoveryHeights(total, std::numeric_limits<float>::quiet_NaN());
          cv::Mat candidates = cv::Mat::zeros(height, width, CV_8U);
          for (std::size_t i = 0; i < total; ++i)
          {
               const float h = source.data[i];
               if (semantics.finalClassMap.data[i] != SemanticClass::UNKNOWN ||
                   mask.tier.data[i] != static_cast<uint8_t>(VegetationTier::NONE) || mask.barrierMask.data[i] ||
                   semantics.vegetationProbability.data[i] < config.treeRecoveryMinProbability ||
                   semantics.buildingProbability.data[i] >= config.maxUnknownBuildingProbability ||
                   std::max(semantics.roadProbability.data[i], semantics.waterProbability.data[i]) >=
                       config.maxUnknownRoadWaterProbability ||
                   !std::isfinite(h) || h < config.minHeightMetres || h > config.maxHeightMetres)
                    continue;
               candidates.data[i] = 1;
               recoveryHeights[i] = std::min(h, input.heights->ceilingMetres);
          }
          // Keep only crown-sized, compact regions.
          cv::Mat labels, componentStats, centroids;
          const int count = cv::connectedComponentsWithStats(candidates, labels, componentStats, centroids, 8, CV_32S);
          const double minArea = M_PI * config.treeMinCrownRadiusMetres * config.treeMinCrownRadiusMetres;
          const double maxArea = M_PI * config.treeMaxCrownRadiusMetres * config.treeMaxCrownRadiusMetres;
          std::vector<uint8_t> keep(static_cast<std::size_t>(count), 0);
          for (int label = 1; label < count; ++label)
          {
               const double areaMetres = componentStats.at<int>(label, cv::CC_STAT_AREA) * pixelArea;
               const double boxMetres = componentStats.at<int>(label, cv::CC_STAT_WIDTH) * scale.columnSpacingMetres *
                                        componentStats.at<int>(label, cv::CC_STAT_HEIGHT) * scale.rowSpacingMetres;
               keep[static_cast<std::size_t>(label)] =
                   areaMetres >= minArea && areaMetres <= maxArea && areaMetres >= 0.4 * boxMetres ? 1 : 0;
          }
          for (std::size_t i = 0; i < total; ++i)
               if (!keep[static_cast<std::size_t>(reinterpret_cast<const int*>(labels.data)[i])]) candidates.data[i] = 0;
          runCategory(candidates, recoveryHeights,
                      {TreeCandidateCategory::ISOLATED_TREE, true, config.treeIsolatedSeparation, 0.0f,
                       config.treeRecoveryMinConfidence, 0.0f});
     }

     // Rank by confidence and cut to the instance limit; ids follow the rank.
     std::vector<TreeCandidate> dropped;
     result.candidates =
         rankAndLimit(all, static_cast<std::size_t>(std::max(0, config.maxInstances)), &dropped);
     for (const TreeCandidate& candidate : dropped)
          reject(candidate.peakColumn, candidate.peakRow, candidate.category, TreeRejection::LIMIT);
     std::vector<int32_t> finalId(all.size() + 1, 0);
     for (std::size_t rank = 0; rank < result.candidates.size(); ++rank)
     {
          finalId[result.candidates[rank].id] = static_cast<int32_t>(rank + 1);
          result.candidates[rank].id = static_cast<uint32_t>(rank + 1);
     }
     for (int32_t& label : result.crownLabels.data) label = finalId[static_cast<std::size_t>(label)];
     for (const TreeCandidate& candidate : result.candidates)
     {
          if (candidate.provenance == TreeProvenance::EXPERIMENTAL) ++stats.experimentalCandidates;
          else if (candidate.category == TreeCandidateCategory::DENSE_CANOPY_CROWN) ++stats.denseCrownCandidates;
          else ++stats.isolatedCandidates;
     }
     stats.accepted = result.candidates.size();
     // Rejections in a stable order for the diagnostics.
     std::sort(result.rejected.begin(), result.rejected.end(), [](const TreeRejectedPeak& a, const TreeRejectedPeak& b)
     {
          return std::make_tuple(static_cast<int>(a.category), a.row, a.column, static_cast<int>(a.reason)) <
                 std::make_tuple(static_cast<int>(b.category), b.row, b.column, static_cast<int>(b.reason));
     });
     return finish("");
}
