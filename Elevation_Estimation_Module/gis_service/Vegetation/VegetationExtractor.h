#pragma once
#include "VegetationConfig.h"
#include "VegetationTypes.h"
#include "../structures/GeographicStructs.h"
#include "../structures/SurfaceStructs.h"

// Builds the cleaned vegetation mask from the semantic output and the fused
// height surface. Read-only on every input.
//
// Rules, in order:
//  1. Protected = accepted building footprints dilated by buildingBufferMetres.
//     Buildings take priority over vegetation everywhere.
//  2. Confirmed tier: finalClassMap == VEGETATION with valid DTM and nDSM
//     (validMask, finite), outside the protected area, nDSM >= minimum height.
//  3. Recovered tier (recoverUnknown): finalClassMap == UNKNOWN with
//     vegetation probability >= unknownProbability, weak building/road/water
//     evidence, a valid plausible nDSM (minimum <= h <= maximum, not a
//     spike above its neighbouring object pixels), and spatial support:
//     near confirmed vegetation, or part of a compact region (>= 2 pixels)
//     of such candidates.
//  4. Specks smaller than minComponentAreaSquareMetres are removed.
//  5. Gaps up to gapClosingMetres are closed, but only with pixels that are
//     valid, unprotected, not BUILDING, ROAD or WATER, not vetoed by the
//     recovery rules and not above the maximum height.
//
// Every metre threshold is converted per raster axis from the geotransform
// (pixels need not be square); non-georeferenced rasters use
// fallbackPixelSizeMetres. The result is deterministic.
class VegetationExtractor
{
public:
     static VegetationMask extract(
         const SemanticScene& semantics,
         const GeoreferencedSurfaceBundle& surface,
         const RasterGrid<uint8_t>& buildingFootprints,
         const SpatialMetadata& metadata,
         const VegetationConfig& config);

     static VegetationPixelScale pixelScale(const SpatialMetadata& metadata, const VegetationConfig& config);
};
