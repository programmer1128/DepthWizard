#pragma once

#include "../structures/MeshStructs.h"
#include "../structures/CommonTypes.h"

// Produces a render-only optical texture and solid terrain vertex colors. The uploaded image and all
// scientific elevation/semantic rasters remain unchanged.
class TerrainTextureComposer
{
public:
    static TextureAsset concealAcceptedRoofs(
        const TextureAsset& original,
        const RasterGrid<uint8_t>& acceptedFootprints,
        const SpatialMetadata& metadata,
        float haloMetres);

    // MapFlow AI presentation aesthetic:
    // Bypasses standard RGB orthophoto sampling and forces terrain vertex colors
    // to emit a solid, unlit dark grey (RGB 0.26f, 0.26f, 0.26f, 1.0f).
    static std::vector<float> composeSolidTerrainColors(
        std::size_t vertexCount,
        float r = 0.26f,
        float g = 0.26f,
        float b = 0.26f,
        float a = 1.0f);

    static void applySolidGreyTerrainColors(
        MeshPrimitive& terrainPrimitive,
        float r = 0.26f,
        float g = 0.26f,
        float b = 0.26f,
        float a = 1.0f);

    static std::vector<float> sampleTerrainVertexColors(
        const TextureAsset& original,
        const std::vector<float>& uvs,
        float r = 0.26f,
        float g = 0.26f,
        float b = 0.26f,
        float a = 1.0f);
};
