#pragma once
#include "../structures/CommonTypes.h"

#include <cstddef>
#include <cstdint>

// Provenance of every pixel in the cleaned vegetation mask.
enum class VegetationTier : uint8_t
{
     NONE = 0,
     CONFIRMED = 1,          // finalClassMap == VEGETATION
     RECOVERED_UNKNOWN = 2,  // UNKNOWN pixel recovered by the conservative rule
     GAP_CLOSED = 3          // Small gap inside a vegetation region (morphological close)
};

struct VegetationMaskStats
{
     // Inputs.
     std::size_t inputVegetationPixels{0};   // finalClassMap == VEGETATION
     std::size_t inputUnknownPixels{0};      // finalClassMap == UNKNOWN
     std::size_t protectedPixels{0};         // Buffered building footprints

     // Confirmed tier (class 4).
     std::size_t confirmedCandidates{0};     // Passed every confirmed-tier rule
     std::size_t rejectedInvalidHeight{0};   // NaN/Inf/NoData nDSM or DTM, or invalid mask
     std::size_t rejectedBuildingBuffer{0};  // Inside a buffered footprint
     std::size_t rejectedBelowMinHeight{0};  // nDSM below the minimum object height

     // UNKNOWN recovery tier.
     std::size_t recoveredUnknownPixels{0};
     std::size_t rejectedUnknownBuilding{0};       // Buffered footprint or building evidence
     std::size_t rejectedUnknownRoadWater{0};      // Road or water evidence
     std::size_t rejectedUnknownProbability{0};    // Vegetation probability below the threshold
     std::size_t rejectedUnknownHeight{0};         // Invalid, too low, too high or a local spike
     std::size_t rejectedUnknownSpatialSupport{0}; // Neither near confirmed vegetation nor compact

     // Cleanup.
     std::size_t removedSmallComponentPixels{0};
     std::size_t closedGapPixels{0};

     // Final cleaned mask.
     std::size_t confirmedPixels{0};
     std::size_t recoveredPixels{0};
     std::size_t gapPixels{0};
     std::size_t components{0};              // 8-connected regions

     std::size_t cleanedPixels() const { return confirmedPixels + recoveredPixels + gapPixels; }
};

// Pixel-size conversion used for every metre threshold.
struct VegetationPixelScale
{
     double columnSpacingMetres{1.0};
     double rowSpacingMetres{1.0};
     bool georeferenced{false};
     double pixelAreaSquareMetres() const { return columnSpacingMetres * rowSpacingMetres; }
};

struct VegetationMask
{
     RasterGrid<uint8_t> tier;            // VegetationTier per pixel
     RasterGrid<uint8_t> protectedMask;   // Buffered building footprints (1 = protected)
     // Pixels no vegetation geometry may touch: protected, BUILDING, ROAD,
     // WATER, or without a valid DTM/nDSM (1 = barrier).
     RasterGrid<uint8_t> barrierMask;
     VegetationPixelScale scale;
     VegetationMaskStats stats;
     bool inputsAvailable{false};         // Semantic and height grids present and consistent
};
