#pragma once

#include "../structures/MeshStructs.h"
#include "../structures/CommonTypes.h"

// Produces a render-only optical texture. The uploaded image and all
// scientific elevation/semantic rasters remain unchanged.
class TerrainTextureComposer
{
public:
    static TextureAsset concealAcceptedRoofs(
        const TextureAsset& original,
        const RasterGrid<uint8_t>& acceptedFootprints,
        const SpatialMetadata& metadata,
        float haloMetres);
};
