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
};
