#pragma once

#include "../structures/CommonTypes.h"
#include "../structures/GeographicStructs.h"

// Builds render-only masks. It deliberately does not modify the scientific
// DSM/DTM products that are exported and used by downstream analysis.
class TerrainSurfaceComposer
{
public:
    static RasterGrid<uint8_t> buildAcceptedBuildingMask(
        const BuildingCollection& buildings,
        const SpatialMetadata& metadata,
        float clearanceMetres);

    // Exact footprint mask with zero clearance for texture repair: a pixel is
    // set when its centre (column + 0.5, row + 0.5) lies inside a footprint
    // (even-odd, so courtyards stay clear). Unlike buildAcceptedBuildingMask,
    // it never grows a footprint by the boundary pixels of a polygon fill.
    static RasterGrid<uint8_t> buildExactFootprintMask(
        const BuildingCollection& buildings,
        const SpatialMetadata& metadata);
};
