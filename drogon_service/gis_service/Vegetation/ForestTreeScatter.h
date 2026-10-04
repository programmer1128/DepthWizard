#pragma once
#include "VegetationClassifier.h"
#include "VegetationConfig.h"
#include "VegetationHeightSampler.h"
#include "VegetationTypes.h"
#include "../MeshMapping/MeshBuildConfig.h"
#include "../structures/GeographicStructs.h"
#include "../structures/SurfaceStructs.h"

#include <array>
#include <string>
#include <vector>

// One tree of the dense-forest layer (external assets, fine resolution): an
// instance of one forest-library prototype, grounded on the rendered terrain
// at its own foot (vertical, so slopes are followed tree by tree). A
// visualization proxy; individual trees are not claimed to be resolved.
struct ForestTree
{
     std::array<float, 3> translation{};        // (worldX, terrain Y, worldZ)
     std::array<float, 4> rotation{0, 0, 0, 1}; // Deterministic yaw
     float scale{0.0f};                         // Uniform: tree height in metres (prototype top = 1)
     float crownRadiusMetres{0.0f};
     int prototype{0};
     double pixelColumn{0.0}, pixelRow{0.0};
     int chunkX{0}, chunkZ{0};
     uint32_t chunkIndex{0};
};

struct ForestTrees
{
     bool enabled{false};
     std::string disabledReason;
     std::vector<ForestTree> trees;
     double chunkSizeMetres{0.0};
     std::size_t chunks{0};
     bool empty() const { return trees.empty(); }
};

struct ForestTreeScatterInput
{
     const VegetationMask* mask{nullptr};
     const VegetationClassification* classification{nullptr};
     const VegetationHeights* heights{nullptr};
     const GeoreferencedSurfaceBundle* surface{nullptr};
     const SpatialMetadata* metadata{nullptr};
     LocalSceneFrame frame;
     TerrainMeshConfig terrainConfig;
     ScenePresentation presentation{ScenePresentation::METRIC};
     VegetationConfig config;
     std::vector<float> prototypeRadii;         // Normalised crown radius of each library tree
     double chunkSizeMetres{0.0};
};

// Deterministic, seeded scatter of library trees over stage-3 DENSE canopy:
// metric presentation, individual-tree resolution, not arid (dense median
// nDSM >= 4 m). Each tree: height = local p90 nDSM (2.5 m) x [0.8, 1.0] in
// [3 m, max height]; prototype by seeded choice; crown radius = height x
// prototype radius; centre on a DENSE, barrier-free pixel (so never on the
// trail, roads, buildings or water) with a barrier-free trunk zone; crowns
// interlock (centres >= 0.75 x the summed radii apart). At most kMaxTrees.
class ForestTreeScatter
{
public:
     static constexpr std::size_t kMaxTrees = 30000;
     static ForestTrees generate(const ForestTreeScatterInput& input);
};
