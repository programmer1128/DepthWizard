#pragma once
#include "LocalFrameTransformer.h"
#include "../structures/CommonTypes.h"

#include <cmath>
#include <utility>

// Pixel <-> world <-> UV mapping shared by new render layers (vegetation).
//
// These are the conventions TerrainMesher and BuildingMesher already use,
// written with the same floating-point operation order so the results are
// bit-identical (GeoTransformMapping_test proves it against both):
//
//  - GDAL's affine transform maps pixel EDGES: pixel (c, r) covers
//    [c, c + 1] x [r, r + 1]; its sample sits at the centre (c + 0.5, r + 0.5).
//  - Local frame: x = E - originE, z = -(N - originN) (north is -Z), Y up.
//  - glTF UV origin is the image's top-left: u = column / width,
//    v = row / height, with no OpenGL-style V flip.
//
// TerrainMesher and BuildingMesher keep their own inline copies for now.
namespace depthwizard::geo
{

// Pixel-edge coordinate -> projected (E, N). TerrainMesher.cc:107-108.
inline ProjectedPoint pixelEdgeToProjected(const SpatialMetadata& metadata, double column, double row)
{
    const auto& gt = metadata.geoTransform;
    return {gt[0] + column * gt[1] + row * gt[2], gt[3] + column * gt[4] + row * gt[5]};
}

// Raster sample (centre of pixel (column, row)) -> projected (E, N).
inline ProjectedPoint pixelCentreToProjected(const SpatialMetadata& metadata, int column, int row)
{
    return pixelEdgeToProjected(metadata, column + 0.5, row + 0.5);
}

// Pixel-edge coordinate -> local scene frame (x, z).
inline LocalPoint pixelEdgeToLocal(const SpatialMetadata& metadata, const LocalSceneFrame& frame,
                                   double column, double row)
{
    return LocalFrameTransformer::toLocal(pixelEdgeToProjected(metadata, column, row), frame);
}

// Pixel-edge coordinate -> source-image UV. TerrainMesher.cc:125-126.
inline std::pair<float, float> pixelEdgeToUv(const SpatialMetadata& metadata, double column, double row)
{
    return {static_cast<float>(column / metadata.width), static_cast<float>(row / metadata.height)};
}

// Local scene frame (x, z) -> pixel-edge coordinate through the inverse
// affine transform. BuildingMesher.cc computeRoofUV, without its border snap.
// The geotransform must be non-singular.
inline std::pair<double, double> localToPixelEdge(const SpatialMetadata& metadata, const LocalSceneFrame& frame,
                                                  double localX, double localZ)
{
    const auto& gt = metadata.geoTransform;
    const double determinant = gt[1] * gt[5] - gt[2] * gt[4];
    const double dx = localX + frame.projectedOriginX - gt[0];
    const double dy = -localZ + frame.projectedOriginY - gt[3];
    return {(dx * gt[5] - dy * gt[2]) / determinant, (dy * gt[1] - dx * gt[4]) / determinant};
}

// Local scene frame (x, z) -> source-image UV (roof UV convention).
inline std::pair<float, float> localToUv(const SpatialMetadata& metadata, const LocalSceneFrame& frame,
                                         double localX, double localZ)
{
    const auto [column, row] = localToPixelEdge(metadata, frame, localX, localZ);
    return pixelEdgeToUv(metadata, column, row);
}

// Ground spacing of one pixel step along each raster axis, in CRS units.
// Separate values: pixels need not be square, and the raster may be rotated.
inline double columnSpacing(const SpatialMetadata& metadata)
{
    const auto& gt = metadata.geoTransform;
    return std::hypot(gt[1], gt[4]);
}

inline double rowSpacing(const SpatialMetadata& metadata)
{
    const auto& gt = metadata.geoTransform;
    return std::hypot(gt[2], gt[5]);
}

} // namespace depthwizard::geo
