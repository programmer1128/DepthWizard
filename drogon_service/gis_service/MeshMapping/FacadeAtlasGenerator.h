#pragma once

#include "../structures/MeshStructs.h"
#include <algorithm>
#include <cmath>
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

    // Nominal physical width of one repeating facade tile in metres.
    // A 10m wall maps accurately across [0, 1] of an atlas tile without stretching.
    static constexpr float kNominalTileWidthMetres = 10.0f;

    // Nominal story height for presentation floor count calculation per playbook Section 6.4.
    static constexpr float kStoryHeightMetres = 3.1f;

    // Generates the deterministic procedural facade atlas PNG texture asset.
    static TextureAsset generateAtlasPng(bool neutralOnly = false);

    // Stable, deterministic 32-bit integer hash for buildingId variant selection (Section 6.4).
    static inline uint32_t hashBuildingId(uint32_t id)
    {
        id ^= id >> 16;
        id *= 0x85ebca6b;
        id ^= id >> 13;
        id *= 0xc2b2ae35;
        id ^= id >> 16;
        return id;
    }

    // Derives presentation floor count from round(height / 3.1 m) with sensible clamping [1, 30].
    // Note: This is strictly a presentation property and is never exposed as measured floor count.
    static inline int computePresentationFloorCount(float buildingHeightMetres)
    {
        const float safeHeight = std::max(buildingHeightMetres, 0.0f);
        return std::clamp(static_cast<int>(std::round(safeHeight / kStoryHeightMetres)), 1, 30);
    }

    // Computes UV coordinates within the atlas for a specific wall vertex.
    // cumulativeEdgeDist: distance in metres along wall face / perimeter
    // heightFromGround: absolute vertical distance in metres from ground base (y - localBaseY)
    // totalBuildingHeight: total building height above ground in metres
    // outU, outV: computed texture coordinates in [0, 1] within the assigned atlas variant cell
    // neutralOnly: if true, forces neutral architectural concrete (Variant 3)
    static void computeWallUV(
        uint32_t buildingId,
        float cumulativeEdgeDist,
        float heightFromGround,
        float totalBuildingHeight,
        float& outU,
        float& outV,
        bool neutralOnly = false);
};

} // namespace depthwizard

