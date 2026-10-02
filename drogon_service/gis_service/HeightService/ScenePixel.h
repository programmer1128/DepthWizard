#pragma once
#include "../structures/CommonTypes.h"

#include <algorithm>
#include <cmath>
#include <optional>

struct RasterPixel
{
     int column{0};
     int row{0};
};

// The frontend sends metres east and south of the scene's north-west corner:
// the GLB is centred on the raster, north-up, in metres, and the viewer adds
// half the model extent. The mesh reaches the outer raster edges, so one
// pixel of slack is allowed before a point counts as outside.
inline std::optional<RasterPixel> scenePixelAt(const SpatialMetadata& metadata,
                                               double eastMetres, double southMetres)
{
     const double pixelWidth = std::abs(metadata.geoTransform[1]);
     const double pixelHeight = std::abs(metadata.geoTransform[5]);
     if (!(pixelWidth > 0.0) || !(pixelHeight > 0.0) || metadata.width <= 0 ||
         metadata.height <= 0 || !std::isfinite(eastMetres) || !std::isfinite(southMetres))
         return std::nullopt;
     const double column = eastMetres / pixelWidth;
     const double row = southMetres / pixelHeight;
     if (column < -1.0 || row < -1.0 || column > metadata.width + 1.0 || row > metadata.height + 1.0)
         return std::nullopt;
     return RasterPixel{
         std::clamp(static_cast<int>(std::floor(column)), 0, metadata.width - 1),
         std::clamp(static_cast<int>(std::floor(row)), 0, metadata.height - 1)};
}
