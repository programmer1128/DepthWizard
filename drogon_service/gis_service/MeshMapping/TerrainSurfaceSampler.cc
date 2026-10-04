#include "TerrainSurfaceSampler.h"
#include "LocalFrameTransformer.h"

#include <algorithm>
#include <cmath>

TerrainSurfaceSampler::TerrainSurfaceSampler(const GeoreferencedSurfaceBundle& surface, const SpatialMetadata& metadata,
                                             const LocalSceneFrame& frame, const TerrainMeshConfig& config)
{
     const int width = metadata.width;
     const int height = metadata.height;
     if (config.elevationSource == TerrainElevationSource::SURFACE_PREVIEW || width < 2 || height < 2 ||
         surface.dtm.width != width || surface.dtm.height != height || surface.validMask.width != width ||
         surface.validMask.height != height || config.maxGridSize < 2)
     {
          supported_ = false;
          return;
     }
     const bool flat = config.elevationSource == TerrainElevationSource::FLAT_PRESENTATION;

     // TerrainMesher.cc: dynamic decimation and grid size.
     if (width > config.maxGridSize || height > config.maxGridSize)
          stride_ = std::max((width - 2) / (config.maxGridSize - 1) + 1, (height - 2) / (config.maxGridSize - 1) + 1);
     gridWidth_ = (width - 2) / stride_ + 2;
     gridHeight_ = (height - 2) / stride_ + 2;

     nodeColumns_.resize(static_cast<std::size_t>(gridWidth_));
     nodeRows_.resize(static_cast<std::size_t>(gridHeight_));
     for (int x = 0; x < gridWidth_; ++x)
     {
          const int origX = std::min(x * stride_, width - 1);
          nodeColumns_[static_cast<std::size_t>(x)] =
              x == 0 ? 0.0 : (x == gridWidth_ - 1 ? static_cast<double>(width) : origX + 0.5);
     }
     for (int y = 0; y < gridHeight_; ++y)
     {
          const int origY = std::min(y * stride_, height - 1);
          nodeRows_[static_cast<std::size_t>(y)] =
              y == 0 ? 0.0 : (y == gridHeight_ - 1 ? static_cast<double>(height) : origY + 0.5);
     }
     nodeHeights_.assign(static_cast<std::size_t>(gridWidth_) * gridHeight_, 0.0f);
     nodeValid_.assign(nodeHeights_.size(), 0);
     for (int y = 0; y < gridHeight_; ++y)
          for (int x = 0; x < gridWidth_; ++x)
          {
               const int origX = std::min(x * stride_, width - 1);
               const int origY = std::min(y * stride_, height - 1);
               const std::size_t source = static_cast<std::size_t>(origY) * width + origX;
               const float elevation = surface.dtm.data[source];
               const bool valid = surface.validMask.data[source] != 0 && std::isfinite(elevation);
               const std::size_t node = static_cast<std::size_t>(y) * gridWidth_ + x;
               nodeValid_[node] = valid ? 1 : 0;
               nodeHeights_[node] =
                   flat ? 0.0f : (valid ? LocalFrameTransformer::toLocalElevation(elevation, frame) : 0.0f);
          }
}

std::optional<float> TerrainSurfaceSampler::localHeight(double column, double row) const
{
     if (!supported_ || !(column >= nodeColumns_.front() && column <= nodeColumns_.back() &&
                          row >= nodeRows_.front() && row <= nodeRows_.back()))
          return std::nullopt;
     // Cell containing the point (the last cell owns the far edge).
     const auto cellOf = [](const std::vector<double>& nodes, double value)
     {
          const auto upper = std::upper_bound(nodes.begin(), nodes.end(), value);
          const auto index = static_cast<int>(std::distance(nodes.begin(), upper)) - 1;
          return std::clamp(index, 0, static_cast<int>(nodes.size()) - 2);
     };
     const int x = cellOf(nodeColumns_, column);
     const int y = cellOf(nodeRows_, row);
     const double a = (column - nodeColumns_[static_cast<std::size_t>(x)]) /
                      (nodeColumns_[static_cast<std::size_t>(x) + 1] - nodeColumns_[static_cast<std::size_t>(x)]);
     const double b = (row - nodeRows_[static_cast<std::size_t>(y)]) /
                      (nodeRows_[static_cast<std::size_t>(y) + 1] - nodeRows_[static_cast<std::size_t>(y)]);
     const std::size_t v0 = static_cast<std::size_t>(y) * gridWidth_ + x;
     const std::size_t v1 = v0 + 1;
     const std::size_t v2 = v0 + static_cast<std::size_t>(gridWidth_);
     const std::size_t v3 = v2 + 1;
     // TerrainMesher emits (v0, v2, v1) and (v1, v2, v3): the diagonal runs v1-v2.
     if (a + b <= 1.0)
     {
          if (!nodeValid_[v0] || !nodeValid_[v1] || !nodeValid_[v2]) return std::nullopt;
          return static_cast<float>(nodeHeights_[v0] + a * (nodeHeights_[v1] - nodeHeights_[v0]) +
                                    b * (nodeHeights_[v2] - nodeHeights_[v0]));
     }
     if (!nodeValid_[v1] || !nodeValid_[v2] || !nodeValid_[v3]) return std::nullopt;
     return static_cast<float>(nodeHeights_[v3] + (1.0 - a) * (nodeHeights_[v2] - nodeHeights_[v3]) +
                               (1.0 - b) * (nodeHeights_[v1] - nodeHeights_[v3]));
}
