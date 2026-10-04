#pragma once
#include "VegetationClassifier.h"
#include "VegetationConfig.h"
#include "VegetationHeightSampler.h"
#include "VegetationTypes.h"
#include "../MeshMapping/MeshBuildConfig.h"
#include "../structures/GeographicStructs.h"
#include "../structures/SurfaceStructs.h"

#include <cstdint>
#include <string>
#include <vector>

enum class TreeCandidateCategory : uint8_t
{
     ISOLATED_TREE = 0,      // From vegetation the classifier reserved for trees
     DENSE_CANOPY_CROWN = 1  // A defensible crown peak inside dense canopy (detail only)
};
const char* toString(TreeCandidateCategory category);

enum class TreeProvenance : uint8_t
{
     CONFIRMED = 0,          // Crown mostly finalClassMap == VEGETATION
     RECOVERED_UNKNOWN = 1,  // Crown mostly stage-2 recovered UNKNOWN pixels
     EXPERIMENTAL = 2        // Low-confidence UNKNOWN recovery (opt-in)
};
const char* toString(TreeProvenance provenance);

enum class TreeRejection : uint8_t
{
     TOO_SHORT,
     SPIKE,
     INVALID_HEIGHT,
     OVERLAP,
     BUILDING,
     ROAD_WATER,
     BOUNDS,
     SUPPORT,
     PROPORTIONS,
     PROMINENCE,
     CONFIDENCE,
     ALREADY_REPRESENTED,
     LIMIT
};
const char* toString(TreeRejection reason);

struct TreeCandidate
{
     uint32_t id{0};
     TreeCandidateCategory category{TreeCandidateCategory::ISOLATED_TREE};
     TreeProvenance provenance{TreeProvenance::CONFIRMED};
     double pixelColumn{0.0};        // Sub-pixel pixel-edge coordinate of the crown centre
     double pixelRow{0.0};
     int peakColumn{0};              // Pixel holding the smoothed height maximum
     int peakRow{0};
     double worldX{0.0};             // Local scene frame (GeoTransformMapping)
     double worldZ{0.0};
     float baseY{0.0f};              // Rendered terrain (metric) or flat ground, local Y
     float metricHeight{0.0f};       // Robust, clamped nDSM height, metres
     float displayHeight{0.0f};      // metricHeight x displayScale
     float displayScale{1.0f};
     float topY{0.0f};               // baseY + displayHeight: the measured crown top
     float crownRadiusMetres{0.0f};
     float supportAreaSquareMetres{0.0f};
     float confidence{0.0f};
     float prominenceMetres{0.0f};
     float compactness{0.0f};
     float vegetationSupport{0.0f};
     float clearanceMetres{0.0f};    // To the nearest protected (buffered building) pixel
     uint32_t componentId{0};        // Connected vegetation region of the crown
};

struct TreeRejectedPeak
{
     int column{0};
     int row{0};
     TreeCandidateCategory category{TreeCandidateCategory::ISOLATED_TREE};
     TreeRejection reason{TreeRejection::TOO_SHORT};
};

struct VegetationTreeCandidateStats
{
     std::size_t eligibleComponents{0};
     std::size_t localMaxima{0};
     std::size_t rejected[static_cast<int>(TreeRejection::LIMIT) + 1]{};
     std::size_t isolatedCandidates{0};
     std::size_t denseCrownCandidates{0};
     std::size_t experimentalCandidates{0};
     std::size_t accepted{0};
     std::size_t count(TreeRejection reason) const { return rejected[static_cast<int>(reason)]; }
};

struct VegetationTreeCandidates
{
     bool enabled{false};
     std::string disabledReason;     // Exact reason when extraction did not run
     std::string presentationMode;
     std::string baseSource;         // "DTM" (rendered terrain surface) or "FLAT_URBAN_GROUND"
     std::string coordinateSystem;
     std::vector<TreeCandidate> candidates;   // Final order: confidence, then stable keys; ids 1..N
     std::vector<TreeRejectedPeak> rejected;
     RasterGrid<int32_t> crownLabels;         // Candidate id per crown pixel, 0 elsewhere
     VegetationTreeCandidateStats stats;
     double milliseconds{0.0};
};

struct VegetationTreeInput
{
     const VegetationMask* mask{nullptr};
     const VegetationClassification* classification{nullptr};
     const VegetationHeights* heights{nullptr};
     const SemanticScene* semantics{nullptr};
     const GeoreferencedSurfaceBundle* surface{nullptr};
     const SpatialMetadata* metadata{nullptr};
     LocalSceneFrame frame;
     TerrainMeshConfig terrainConfig;            // The terrain the scene renders
     ScenePresentation presentation{ScenePresentation::METRIC};
     float buildingDisplayHeightScale{1.0f};     // BuildingReconstructionConfig::heightScaleMultiplier
     VegetationConfig config;
     // Experimental recovery only: the corrected metric nDSM before semantic
     // suppression (low-probability UNKNOWN pixels are zero in surface.ndsm).
     const RasterGrid<float>* recoveryNdsm{nullptr};
};

// Deterministic individual-tree candidates (no geometry; stage 5 renders them).
//
// Gate: both pixel axes must be at most individualTreeMaxGsdMetres and the
// raster georeferenced; otherwise no candidate is produced and the reason is
// recorded (Test8 at 10 m: canopy only).
//
// Per category (ISOLATED pixels -> ISOLATED_TREE, DENSE pixels ->
// DENSE_CANOPY_CROWN), inside that class's pixels only:
//  1. Mask-normalised Gaussian smoothing of the clamped metric nDSM (never
//     across the class mask, so never across buildings, roads, water or
//     NoData).
//  2. Local maxima of the smoothed height within treeMinCrownRadiusMetres.
//  3. Robust height: the treeHeightPercentile of the core window
//     (treeCoreRadiusMetres); a peak whose core median is below
//     treeSpikeMedianFraction of it is a spike; below the minimum height is
//     too short.
//  Initial radius: the distance transform of the region (isolated trees);
//  inside dense canopy the crown's radial nDSM profile (first ring whose mean
//  smoothed height fell by max(1 m, prominence / 4)).
//  4. Radius-aware non-maximum suppression, ordered by robust height, then
//     vegetation support, then initial radius, then pixel index (stable;
//     never container order). Canopy crowns use a stricter separation and a
//     minimum spacing.
//  5. Crowns segmented by a priority flood from the accepted peaks (higher
//     smoothed height first, ties by pixel index), limited to the maximum
//     crown radius.
//  6. Crown radius = median of an extent radius (distance transform for
//     isolated trees; half the spacing to the nearest accepted crown inside
//     dense canopy), the segmented area-equivalent radius and the radial
//     decline radius (area within half the crown's prominence of its peak),
//     clamped to [min, max]; support area, compactness and height/diameter
//     checks.
//  7. Exclusions: centre on road/water evidence or a barrier; crown radius
//     shrunk to the clearance from every buffered building footprint and
//     from the image border (rejected below the minimum radius).
//  8. Confidence = 0.30 vegetation support + 0.25 min(prominence / 4 m, 1)
//     + 0.20 compactness + 0.15 height-supported core share
//     + 0.10 min(building clearance / 5 m, 1).
//  9. Base: TerrainSurfaceSampler (metric) or 0 (flat_urban);
//     displayHeight = metricHeight x displayHeightScale; topY = base + display.
// Optional experimental recovery adds crown-like UNKNOWN regions below the
// stage-2 threshold. Finally all candidates are ranked by confidence (ties:
// category, peak pixel) and cut to maxInstances; ids follow that order.
class VegetationTreeCandidateGenerator
{
public:
     static VegetationTreeCandidates generate(const VegetationTreeInput& input);

     // Ranking and limit used by generate(): independent of the input order.
     static std::vector<TreeCandidate> rankAndLimit(std::vector<TreeCandidate> candidates, std::size_t limit,
                                                    std::vector<TreeCandidate>* dropped = nullptr);
};
