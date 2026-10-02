#pragma once

#include "../structures/MeshStructs.h"
#include <cstdint>
#include <vector>

namespace depthwizard
{

class FacadeAtlasGenerator
{
public:
    // Atlas layout: 2x2 grid of 4 variants, 512x512 total pixels (each cell 256x256).
    // Variant 0 (top-left): Modern commercial glass / steel grid
    // Variant 1 (top-right): Architectural stone / limestone
    // Variant 2 (bottom-left): Clean brick / terracotta
    // Variant 3 (bottom-right): Neutral minimalist architectural concrete (defense/scientific)
    static constexpr int kAtlasWidth = 512;
    static constexpr int kAtlasHeight = 512;
    static constexpr int kGridCols = 2;
    static constexpr int kGridRows = 2;
    static constexpr int kVariantCount = 4;
    static constexpr int kCellWidth = kAtlasWidth / kGridCols;   // 256
    static constexpr int kCellHeight = kAtlasHeight / kGridRows; // 256

    // Generates the deterministic procedural facade atlas PNG texture asset.
    static TextureAsset generateAtlasPng(bool neutralOnly = false);

    // Computes UV coordinates within the atlas for a specific wall vertex.
    // cumulativeEdgeDist: distance in metres along footprint perimeter to this vertex
    // heightFromGround: vertical distance in metres from ground base to this vertex
    // wallHeight: total wall height at this wall section
    // buildingId: used for deterministic variant selection
    static void computeWallUV(
        uint32_t buildingId,
        float cumulativeEdgeDist,
        float heightFromGround,
        float wallHeight,
        float& outU,
        float& outV,
        bool neutralOnly = false);
};

} // namespace depthwizard
