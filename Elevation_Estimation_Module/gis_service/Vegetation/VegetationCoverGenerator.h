#pragma once
#include "VegetationClassifier.h"
#include "VegetationConfig.h"
#include "VegetationTypes.h"
#include "../MeshMapping/MeshBuildConfig.h"
#include "../structures/GeographicStructs.h"
#include "../structures/SurfaceStructs.h"

#include <array>
#include <string>
#include <vector>

// One shrub of the vegetation cover layer (stage 5A, external assets): a
// visualization proxy filling the vegetation the image shows, not a
// reconstructed plant. Height is the local nDSM clamped to a shrub range.
struct CoverShrub
{
     std::array<float, 3> translation{};        // (worldX, base Y, worldZ)
     std::array<float, 4> rotation{0, 0, 0, 1}; // Deterministic yaw
     std::array<float, 3> scale{};              // Drawn (radius, height, radius): display scale x prominence
     bool companion{false};                     // Second bush of a pair (natural scenes)
     float metricHeight{0.0f};
     float radiusMetres{0.0f};
     double pixelColumn{0.0}, pixelRow{0.0};
     int chunkX{0}, chunkZ{0};
     uint32_t chunkIndex{0};
};

enum class VegetationCoverMode
{
     GARDEN,    // flat_urban: semantic VEGETATION pixels, garden-scale shrubs
     NATURAL    // metric: image shrub detector (dark, greener than its
                // surroundings, compact, with nDSM support) plus the vegetation mask
};

struct VegetationCoverStats
{
     std::size_t coverPixels{0};
     std::size_t semanticPixels{0};       // From the semantic VEGETATION class
     std::size_t imageDetectedPixels{0};  // From the optical shrub detector (NATURAL)
     std::size_t rejectedComponents{0};   // Detector blobs without nDSM support or too thin
     std::size_t tested{0};
     std::size_t capped{0};
     std::size_t companions{0};
};

struct VegetationCover
{
     bool enabled{false};
     std::string disabledReason;
     VegetationCoverMode mode{VegetationCoverMode::NATURAL};
     RasterGrid<uint8_t> coverMask;        // 1 = shrubs may be placed (diagnostics)
     std::vector<CoverShrub> shrubs;
     VegetationCoverStats stats;
     double chunkSizeMetres{0.0};
     std::size_t chunks{0};
     bool empty() const { return shrubs.empty(); }
};

struct VegetationCoverInput
{
     const VegetationMask* mask{nullptr};
     const SemanticScene* semantics{nullptr};
     const GeoreferencedSurfaceBundle* surface{nullptr};
     const SpatialMetadata* metadata{nullptr};
     const std::vector<uint8_t>* opticalBytes{nullptr};   // Encoded orthophoto (PNG/JPEG)
     LocalSceneFrame frame;
     TerrainMeshConfig terrainConfig;
     ScenePresentation presentation{ScenePresentation::METRIC};
     float displayHeightScale{1.0f};
     VegetationConfig config;
     double chunkSizeMetres{0.0};
     // Optional: DENSE pixels of this classification are drawn as forest trees
     // and get no shrubs.
     const VegetationClassification* forestDense{nullptr};
     // Discs already drawn by stage-4 candidate bushes (local x, z, radius m).
     std::vector<std::array<float, 3>> occupied;
};

// Deterministic, seeded (DEPTHWIZARD_VEGETATION_SEED) shrub fill of the cover
// mask. Natural: radius = max(clamped p75 nDSM within 1.5 m x [0.9, 1.3],
// 0.9 x the cover blob's inscribed radius) in [0.6, 2.2] m, height = max(p75
// nDSM, 1.2 x radius) in [0.6, 3.0] m. Garden: heights in [0.6, 1.5] m with
// varied radii, and deterministic lawn gaps (8 m value noise) between beds;
// its disc at least half cover, free of barrier pixels (buildings and their
// buffer, roads, water, NoData) and of candidate bushes; neighbouring discs
// overlap by at most 20 %. Natural scenes add 2-3 companions around each
// shrub and each candidate bush, and draw both at kNaturalProminence x. Only at
// individual-tree resolution
// (DEPTHWIZARD_VEGETATION_INDIVIDUAL_TREE_MAX_GSD_M); at most kMaxShrubs.
class VegetationCoverGenerator
{
public:
     static constexpr std::size_t kMaxShrubs = 80000;
     // Natural scenes draw every find as 3-4 bushes at 2.75 x the measured
     // size (visual prominence only; measured heights stay in metricHeight).
     static constexpr float kNaturalProminence = 2.75f;
     static VegetationCover generate(const VegetationCoverInput& input);
};
