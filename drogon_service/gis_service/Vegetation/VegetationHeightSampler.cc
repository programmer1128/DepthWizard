#include "VegetationHeightSampler.h"

#include <algorithm>
#include <cmath>
#include <limits>
#include <vector>

namespace
{
float percentile(std::vector<float> values, double fraction)
{
     if (values.empty()) return 0.0f;
     const auto index = static_cast<std::size_t>(fraction * static_cast<double>(values.size() - 1) + 0.5);
     std::nth_element(values.begin(), values.begin() + static_cast<std::ptrdiff_t>(index), values.end());
     return values[index];
}
} // namespace

VegetationHeights VegetationHeightSampler::sample(const VegetationMask& mask, const GeoreferencedSurfaceBundle& surface,
                                                  const VegetationConfig& config)
{
     VegetationHeights heights;
     if (!mask.inputsAvailable) return heights;
     const std::size_t total = mask.tier.data.size();
     heights.metricHeight.width = mask.tier.width;
     heights.metricHeight.height = mask.tier.height;
     heights.metricHeight.data.assign(total, std::numeric_limits<float>::quiet_NaN());

     std::vector<float> sampled;
     for (std::size_t i = 0; i < total; ++i)
     {
          const auto tier = static_cast<VegetationTier>(mask.tier.data[i]);
          if (tier == VegetationTier::CONFIRMED || tier == VegetationTier::RECOVERED_UNKNOWN)
               sampled.push_back(surface.ndsm.data[i]);
     }
     heights.sampledPixels = sampled.size();
     heights.p05 = percentile(sampled, 0.05);
     heights.p50 = percentile(sampled, 0.50);
     heights.p95 = percentile(sampled, 0.95);
     heights.ceilingMetres = sampled.empty()
         ? config.maxHeightMetres
         : std::min(config.maxHeightMetres, percentile(sampled, config.heightClampPercentile));

     for (std::size_t i = 0; i < total; ++i)
     {
          if (mask.tier.data[i] == static_cast<uint8_t>(VegetationTier::NONE)) continue;
          const float raw = std::max(0.0f, surface.ndsm.data[i]);
          if (raw > heights.ceilingMetres) ++heights.clampedPixels;
          heights.metricHeight.data[i] = std::min(raw, heights.ceilingMetres);
     }
     return heights;
}

std::optional<float> VegetationHeightSampler::robustHeight(const VegetationMask& mask, const VegetationHeights& heights,
                                                           int column, int row, double radiusMetres)
{
     const int width = heights.metricHeight.width;
     const int height = heights.metricHeight.height;
     if (column < 0 || row < 0 || column >= width || row >= height) return std::nullopt;
     const double rx = std::max(0.0, radiusMetres / mask.scale.columnSpacingMetres);
     const double ry = std::max(0.0, radiusMetres / mask.scale.rowSpacingMetres);
     const int ix = static_cast<int>(std::floor(rx)), iy = static_cast<int>(std::floor(ry));
     std::vector<float> values;
     for (int dy = -iy; dy <= iy; ++dy)
          for (int dx = -ix; dx <= ix; ++dx)
          {
               const int x = column + dx, y = row + dy;
               if (x < 0 || y < 0 || x >= width || y >= height) continue;
               const double ex = rx > 0.0 ? dx / rx : 0.0, ey = ry > 0.0 ? dy / ry : 0.0;
               if (ex * ex + ey * ey > 1.0 + 1e-9) continue;
               const float value = heights.metricHeight.data[static_cast<std::size_t>(y) * width + x];
               if (std::isfinite(value)) values.push_back(value);
          }
     if (values.empty()) return std::nullopt;
     // Lower median for an even count: deterministic and never interpolated.
     const std::size_t middle = (values.size() - 1) / 2;
     std::nth_element(values.begin(), values.begin() + static_cast<std::ptrdiff_t>(middle), values.end());
     return values[middle];
}

float VegetationHeightSampler::displayHeightScale(ScenePresentation presentation, float buildingDisplayHeightScale)
{
     return presentation == ScenePresentation::FLAT_URBAN ? buildingDisplayHeightScale : 1.0f;
}

VegetationHeightRecord VegetationHeightSampler::record(float metricHeight, float baseElevation,
                                                       ScenePresentation presentation, float buildingDisplayHeightScale)
{
     VegetationHeightRecord result;
     result.metricHeight = metricHeight;
     result.displayHeightScale = displayHeightScale(presentation, buildingDisplayHeightScale);
     result.displayHeight = metricHeight * result.displayHeightScale;
     result.baseElevation = baseElevation;
     result.presentationMode = presentation == ScenePresentation::FLAT_URBAN ? "flat_urban" : "metric";
     return result;
}
