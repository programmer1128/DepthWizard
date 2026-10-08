#pragma once
#include "TerrainMeshConfig.h"
#include "../structures/CommonTypes.h"
#include "../structures/SurfaceStructs.h"

#include <optional>
#include <vector>

// Height of the exact terrain surface TerrainMesher renders, at any pixel-edge
// coordinate, so overlays (vegetation canopy) can sit on it rather than on a
// raw DTM sample that a decimated terrain mesh may cut through.
//
// It mirrors TerrainMesher's grid: the same decimation stride, outer nodes on
// the pixel edges 0 and width/height, interior nodes at pixel centres, node
// elevation from the DTM (Y = 0 for FLAT_PRESENTATION), and the same diagonal
// split of every cell into (v0, v2, v1) and (v1, v2, v3). Grid cells are
// axis-aligned in pixel space and the geotransform is affine, so barycentric
// interpolation in pixel space equals interpolation on the rendered triangle.
// TerrainSurfaceSampler_test checks it against TerrainMesher.
class TerrainSurfaceSampler
{
public:
     TerrainSurfaceSampler(const GeoreferencedSurfaceBundle& surface, const SpatialMetadata& metadata,
                           const LocalSceneFrame& frame, const TerrainMeshConfig& config);

     // False for elevation sources the sampler does not mirror (SURFACE_PREVIEW).
     bool supported() const { return supported_; }
     int stride() const { return stride_; }

     // Local Y (elevation - elevationOrigin) of the rendered terrain at a
     // pixel-edge coordinate; nullopt outside the raster or where the terrain
     // triangle is missing (NoData corner).
     std::optional<float> localHeight(double column, double row) const;

private:
     bool supported_{true};
     int stride_{1};
     int gridWidth_{0};
     int gridHeight_{0};
     std::vector<double> nodeColumns_;
     std::vector<double> nodeRows_;
     std::vector<float> nodeHeights_;
     std::vector<uint8_t> nodeValid_;
};
