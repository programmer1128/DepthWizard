#pragma once

#include "../structures/CommonTypes.h"
#include "../structures/GeographicStructs.h"
#include <vector>
#include <cstdint>

class TerrainSurfaceComposer
{
public:
    static RasterGrid<uint8_t> buildAcceptedBuildingMask(
        const BuildingCollection& buildings,
        const SpatialMetadata& metadata,
        float clearanceMetres);

    // Synthesizes local ground texture over identified building footprints
    // to prevent 2D photographic "double roof" bleed beneath the 3D meshes.
    static std::vector<uint8_t> inpaintBuildingTextures(
        const std::vector<uint8_t>& originalJpegBytes,
        const RasterGrid<uint8_t>& buildingMask,
        const SpatialMetadata& metadata);
};