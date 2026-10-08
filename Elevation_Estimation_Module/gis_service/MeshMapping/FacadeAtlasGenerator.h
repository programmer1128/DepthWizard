#pragma once

#include "../structures/MeshStructs.h"

#include <cstdint>
#include <utility>

namespace depthwizard
{

// Deterministic procedural facade atlas (playbook section 6.4).
//
// Layout: four full-width horizontal bands, one per variant, stacked top to
// bottom. Each band holds kFloorsPerBand floors of kFloorPixels rows, the
// lowest being a darker ground floor, and kBaysPerTile identical window bays
// across its width. Because a band spans the whole width, the sampler can
// repeat horizontally (wrapS = REPEAT) along walls of any length without
// sampling another variant; vertically the texture is clamped and v stays
// inside the band.
//
// Facades are a presentation feature: the floor count is
// round(height / 3.1 m), never a measured value.
class FacadeAtlasGenerator
{
public:
    static constexpr int kVariantCount = 4;    // 0 concrete, 1 stone, 2 glass, 3 neutral concrete
    static constexpr int kNeutralVariant = 3;
    static constexpr int kBaysPerTile = 8;
    static constexpr int kBayPixels = 32;
    static constexpr int kFloorsPerBand = 32;
    static constexpr int kFloorPixels = 32;
    static constexpr int kAtlasWidth = kBaysPerTile * kBayPixels;        // 256
    static constexpr int kBandHeight = kFloorsPerBand * kFloorPixels;    // 1024
    static constexpr int kAtlasHeight = kVariantCount * kBandHeight;     // 4096
    static constexpr int kBandMarginPixels = 2; // Keeps filtering inside the band
    static constexpr double kBayWidthMetres = 3.0;
    static constexpr double kFloorHeightMetres = 3.1;
    static constexpr double kTileWidthMetres = kBaysPerTile * kBayWidthMetres; // 24 m per u

    // PNG atlas with REPEAT/CLAMP wrapping. neutral draws every band as plain
    // concrete with floor lines and no windows.
    static TextureAsset generateAtlasPng(bool neutral = false);

    // Stable variant for a building: a hash of its id, so neighbouring ids
    // do not cycle through the variants.
    static int variantFor(uint32_t buildingId, bool neutral);

    // round(wallHeight / 3.1 m), clamped to [1, kFloorsPerBand].
    static int presentationFloors(double wallHeightMetres);

    // u for a straight wall from startDistance to startDistance + length (metres
    // along the ring). The start is reduced to one tile period so values stay
    // small, and the end continues linearly so the pattern is not distorted.
    static std::pair<float, float> segmentU(double startDistanceMetres, double lengthMetres);

    // v for a point heightAboveGround metres above the building's ground on a
    // facade whose wall height maps to `floors` atlas floors.
    static float v(int variant, int floors, double wallHeightMetres, double heightAboveGroundMetres);
};

} // namespace depthwizard
