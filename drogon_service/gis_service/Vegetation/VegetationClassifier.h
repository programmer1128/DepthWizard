#pragma once
#include "VegetationConfig.h"
#include "VegetationTypes.h"

#include <cstddef>
#include <cstdint>

// Every cleaned-mask pixel gets exactly one class, so canopy (stage 3) and
// individual trees (stage 4) never represent the same evidence twice.
enum class VegetationClass : uint8_t
{
     NONE = 0,
     DENSE = 1,      // Canopy surface
     ISOLATED = 2    // Reserved for individual trees
};

struct VegetationClassificationStats
{
     bool individualTreesResolvable{false}; // Ground resolution fine enough for crowns
     double groundResolutionMetres{0.0};    // Coarser pixel axis
     std::size_t densePixels{0};
     std::size_t isolatedPixels{0};
     std::size_t denseComponents{0};
     std::size_t isolatedComponents{0};
     std::size_t denseSeeds{0};             // Dense cores passing area, width and height support
     std::size_t rejectedCores{0};          // Cores too small, too narrow or unsupported
     // Provenance of the dense and isolated pixels.
     std::size_t denseConfirmed{0}, denseRecovered{0}, denseGap{0};
     std::size_t isolatedConfirmed{0}, isolatedRecovered{0}, isolatedGap{0};
};

struct VegetationClassification
{
     RasterGrid<uint8_t> classes;  // VegetationClass per pixel
     VegetationClassificationStats stats;
};

// Deterministic dense-versus-isolated split, from physical measurements:
//
//  - Coarse imagery (coarser pixel axis > individualTreeMaxGsdMetres, e.g.
//    Test8 at 10 m): crowns are not resolvable, so every mask pixel is DENSE
//    and no individual-tree evidence is invented.
//  - Fine imagery: local coverage = vegetation share of a
//    denseCoverageRadiusMetres window. Pixels with coverage >=
//    denseLocalCoverage form cores. A core is a dense seed when its area is
//    >= denseMinAreaSquareMetres, its width (2 x the largest inscribed
//    radius, distance transform) is >= denseMinWidthMetres, and at least
//    half its pixels carry nDSM height support (confirmed or recovered, not
//    gap-closed). DENSE = mask pixels of a seed's connected mask region that
//    lie within denseFringeMetres of the seed. Every other mask pixel is
//    ISOLATED.
//
// Distances in pixels are converted with the finer pixel axis, which
// underestimates widths on non-square pixels (fewer, not more, dense seeds).
class VegetationClassifier
{
public:
     static VegetationClassification classify(const VegetationMask& mask, const VegetationConfig& config);
};
