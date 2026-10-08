#include "VegetationExtractor.h"
#include "VegetationMorphology.h"
#include "../MeshMapping/GeoTransformMapping.h"

#include <opencv2/imgproc.hpp>

#include <algorithm>
#include <array>
#include <cmath>

using depthwizard::vegetation::metricEllipse;
using depthwizard::vegetation::pixelsForArea;

namespace
{
constexpr uint8_t kNone = static_cast<uint8_t>(VegetationTier::NONE);
constexpr uint8_t kConfirmed = static_cast<uint8_t>(VegetationTier::CONFIRMED);
constexpr uint8_t kRecovered = static_cast<uint8_t>(VegetationTier::RECOVERED_UNKNOWN);
constexpr uint8_t kGap = static_cast<uint8_t>(VegetationTier::GAP_CLOSED);

template <typename T>
bool sized(const RasterGrid<T>& grid, int width, int height)
{
     return grid.isValid() && grid.width == width && grid.height == height;
}
} // namespace

VegetationPixelScale VegetationExtractor::pixelScale(const SpatialMetadata& metadata, const VegetationConfig& config)
{
     VegetationPixelScale scale;
     const double column = depthwizard::geo::columnSpacing(metadata);
     const double row = depthwizard::geo::rowSpacing(metadata);
     if (metadata.isGeoreferenced && std::isfinite(column) && std::isfinite(row) && column > 0.0 && row > 0.0)
     {
          scale.columnSpacingMetres = column;
          scale.rowSpacingMetres = row;
          scale.georeferenced = true;
     }
     else
     {
          scale.columnSpacingMetres = config.fallbackPixelSizeMetres;
          scale.rowSpacingMetres = config.fallbackPixelSizeMetres;
     }
     return scale;
}

VegetationMask VegetationExtractor::extract(
    const SemanticScene& semantics,
    const GeoreferencedSurfaceBundle& surface,
    const RasterGrid<uint8_t>& buildingFootprints,
    const SpatialMetadata& metadata,
    const VegetationConfig& config)
{
     VegetationMask mask;
     const int width = metadata.width;
     const int height = metadata.height;
     mask.scale = pixelScale(metadata, config);
     if (width <= 0 || height <= 0 || !sized(semantics.finalClassMap, width, height) ||
         !sized(semantics.vegetationProbability, width, height) ||
         !sized(semantics.buildingProbability, width, height) ||
         !sized(semantics.roadProbability, width, height) || !sized(semantics.waterProbability, width, height) ||
         !sized(surface.dtm, width, height) || !sized(surface.ndsm, width, height) ||
         !sized(surface.validMask, width, height) || !sized(buildingFootprints, width, height))
          return mask;
     mask.inputsAvailable = true;

     const std::size_t total = static_cast<std::size_t>(width) * height;
     mask.tier.width = mask.protectedMask.width = width;
     mask.tier.height = mask.protectedMask.height = height;
     mask.tier.data.assign(total, kNone);
     VegetationMaskStats& stats = mask.stats;

     // 1. Buildings take priority: footprints plus a metric safety buffer.
     cv::Mat protectedArea(height, width, CV_8U);
     for (std::size_t i = 0; i < total; ++i) protectedArea.data[i] = buildingFootprints.data[i] != 0 ? 1 : 0;
     if (const cv::Mat kernel = metricEllipse(config.buildingBufferMetres, mask.scale); !kernel.empty())
          cv::dilate(protectedArea, protectedArea, kernel);
     mask.protectedMask.data.assign(protectedArea.data, protectedArea.data + total);
     stats.protectedPixels = static_cast<std::size_t>(cv::countNonZero(protectedArea));

     const auto& cls = semantics.finalClassMap.data;
     const auto& ndsm = surface.ndsm.data;
     const auto validHeight = [&](std::size_t i)
     { return surface.validMask.data[i] != 0 && std::isfinite(surface.dtm.data[i]) && std::isfinite(ndsm[i]); };
     const auto isProtected = [&](std::size_t i) { return protectedArea.data[i] != 0; };

     // 2. Confirmed tier.
     cv::Mat confirmed = cv::Mat::zeros(height, width, CV_8U);
     for (std::size_t i = 0; i < total; ++i)
     {
          if (cls[i] == SemanticClass::UNKNOWN) ++stats.inputUnknownPixels;
          if (cls[i] != SemanticClass::VEGETATION) continue;
          ++stats.inputVegetationPixels;
          if (!validHeight(i)) ++stats.rejectedInvalidHeight;
          else if (isProtected(i)) ++stats.rejectedBuildingBuffer;
          else if (ndsm[i] < config.minHeightMetres) ++stats.rejectedBelowMinHeight;
          else
          {
               confirmed.data[i] = 1;
               ++stats.confirmedCandidates;
          }
     }

     // 3. Conservative UNKNOWN recovery. `vetoed` remembers pixels rejected on
     //    building, road/water or height evidence: gap closing may not
     //    re-admit them.
     cv::Mat recovered = cv::Mat::zeros(height, width, CV_8U);
     cv::Mat vetoed = cv::Mat::zeros(height, width, CV_8U);
     if (config.recoverUnknown)
     {
          // A spike stands far above the median of its neighbouring object
          // pixels (valid, at least the minimum height; ground is ignored so
          // a region's edge is not mistaken for a spike). With fewer than
          // three such neighbours the spatial-support rule decides instead.
          const auto isSpike = [&](int x, int y)
          {
               std::array<float, 8> values{};
               int count = 0;
               for (int dy = -1; dy <= 1; ++dy)
                    for (int dx = -1; dx <= 1; ++dx)
                    {
                         const int nx = x + dx, ny = y + dy;
                         if ((dx == 0 && dy == 0) || nx < 0 || ny < 0 || nx >= width || ny >= height) continue;
                         const std::size_t j = static_cast<std::size_t>(ny) * width + nx;
                         if (validHeight(j) && ndsm[j] >= config.minHeightMetres) values[count++] = ndsm[j];
                    }
               if (count < 3) return false;
               std::nth_element(values.begin(), values.begin() + count / 2, values.begin() + count);
               return ndsm[static_cast<std::size_t>(y) * width + x] - values[count / 2] >
                      config.unknownSpikeToleranceMetres;
          };

          cv::Mat candidates = cv::Mat::zeros(height, width, CV_8U);
          for (int y = 0; y < height; ++y)
               for (int x = 0; x < width; ++x)
               {
                    const std::size_t i = static_cast<std::size_t>(y) * width + x;
                    if (cls[i] != SemanticClass::UNKNOWN) continue;
                    if (isProtected(i) || semantics.buildingProbability.data[i] >= config.maxUnknownBuildingProbability)
                    {
                         ++stats.rejectedUnknownBuilding;
                         vetoed.data[i] = 1;
                    }
                    else if (std::max(semantics.roadProbability.data[i], semantics.waterProbability.data[i]) >=
                             config.maxUnknownRoadWaterProbability)
                    {
                         ++stats.rejectedUnknownRoadWater;
                         vetoed.data[i] = 1;
                    }
                    else if (!(semantics.vegetationProbability.data[i] >= config.unknownProbability))
                         ++stats.rejectedUnknownProbability;
                    else if (!validHeight(i) || ndsm[i] < config.minHeightMetres ||
                             ndsm[i] > config.maxHeightMetres || isSpike(x, y))
                    {
                         ++stats.rejectedUnknownHeight;
                         vetoed.data[i] = ndsm[i] >= config.minHeightMetres ? 1 : 0; // Low pixels may fill gaps
                    }
                    else
                         candidates.data[i] = 1;
               }

          // Spatial support: next to confirmed vegetation, or a compact
          // region of candidates (never a lone pixel).
          cv::Mat nearConfirmed;
          cv::dilate(confirmed, nearConfirmed, metricEllipse(config.unknownSupportDistanceMetres, mask.scale, true));
          cv::Mat labels, componentStats, centroids;
          cv::connectedComponentsWithStats(candidates, labels, componentStats, centroids, 8, CV_32S);
          const int compactPixels = pixelsForArea(config.unknownCompactAreaSquareMetres, mask.scale, 2);
          for (std::size_t i = 0; i < total; ++i)
          {
               if (!candidates.data[i]) continue;
               const int label = reinterpret_cast<const int*>(labels.data)[i];
               if (nearConfirmed.data[i] || componentStats.at<int>(label, cv::CC_STAT_AREA) >= compactPixels)
               {
                    recovered.data[i] = 1;
                    ++stats.recoveredUnknownPixels;
               }
               else
                    ++stats.rejectedUnknownSpatialSupport;
          }
     }

     for (std::size_t i = 0; i < total; ++i)
          mask.tier.data[i] = confirmed.data[i] ? kConfirmed : (recovered.data[i] ? kRecovered : kNone);

     // 4. Remove specks smaller than the minimum component area.
     {
          cv::Mat binary(height, width, CV_8U);
          for (std::size_t i = 0; i < total; ++i) binary.data[i] = mask.tier.data[i] != kNone ? 1 : 0;
          cv::Mat labels, componentStats, centroids;
          const int count = cv::connectedComponentsWithStats(binary, labels, componentStats, centroids, 8, CV_32S);
          const int minimumPixels = pixelsForArea(config.minComponentAreaSquareMetres, mask.scale, 1);
          std::vector<uint8_t> small(static_cast<std::size_t>(count), 0);
          for (int label = 1; label < count; ++label)
               small[static_cast<std::size_t>(label)] =
                   componentStats.at<int>(label, cv::CC_STAT_AREA) < minimumPixels ? 1 : 0;
          for (std::size_t i = 0; i < total; ++i)
          {
               const int label = reinterpret_cast<const int*>(labels.data)[i];
               if (label > 0 && small[static_cast<std::size_t>(label)])
               {
                    mask.tier.data[i] = kNone;
                    ++stats.removedSmallComponentPixels;
               }
          }
     }

     // 5. Close small gaps, never into protected, invalid, vetoed, building,
     //    road or water pixels, nor above the physical maximum height.
     //    Closing cannot grow the outer boundary of a region.
     if (const cv::Mat kernel = metricEllipse(config.gapClosingMetres, mask.scale); !kernel.empty())
     {
          cv::Mat binary(height, width, CV_8U), closed;
          for (std::size_t i = 0; i < total; ++i) binary.data[i] = mask.tier.data[i] != kNone ? 1 : 0;
          cv::morphologyEx(binary, closed, cv::MORPH_CLOSE, kernel);
          for (std::size_t i = 0; i < total; ++i)
          {
               if (!closed.data[i] || binary.data[i]) continue;
               if (!validHeight(i) || isProtected(i) || vetoed.data[i] || ndsm[i] > config.maxHeightMetres ||
                   cls[i] == SemanticClass::BUILDING || cls[i] == SemanticClass::ROAD ||
                   cls[i] == SemanticClass::WATER)
                    continue;
               mask.tier.data[i] = kGap;
               ++stats.closedGapPixels;
          }
     }

     // Barriers for later geometry stages.
     mask.barrierMask.width = width;
     mask.barrierMask.height = height;
     mask.barrierMask.data.assign(total, 0);
     for (std::size_t i = 0; i < total; ++i)
          mask.barrierMask.data[i] = (!validHeight(i) || isProtected(i) || cls[i] == SemanticClass::BUILDING ||
                                      cls[i] == SemanticClass::ROAD || cls[i] == SemanticClass::WATER)
              ? 1 : 0;

     // Final statistics.
     cv::Mat binary(height, width, CV_8U);
     for (std::size_t i = 0; i < total; ++i)
     {
          const uint8_t tier = mask.tier.data[i];
          binary.data[i] = tier != kNone ? 1 : 0;
          if (tier == kConfirmed) ++stats.confirmedPixels;
          else if (tier == kRecovered) ++stats.recoveredPixels;
          else if (tier == kGap) ++stats.gapPixels;
     }
     cv::Mat labels;
     stats.components = static_cast<std::size_t>(cv::connectedComponents(binary, labels, 8, CV_32S) - 1);
     return mask;
}
