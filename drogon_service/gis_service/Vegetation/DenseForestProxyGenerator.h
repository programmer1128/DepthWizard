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

// One forest-patch visualization proxy (stage 5A). Not a reconstructed tree:
// the patch stands for dense canopy where individual crowns are not resolved.
struct ForestProxy
{
     uint32_t id{0};
     double pixelColumn{0.0}, pixelRow{0.0};   // Pixel-edge coordinates of the centre
     std::array<float, 3> translation{};       // (worldX, base Y on the terrain plane, worldZ)
     std::array<float, 4> rotation{0, 0, 0, 1};// Terrain-plane tilt x deterministic yaw (unit quaternion)
     float scale{0.0f};                        // Uniform: tallest tree height in metres (prototype top = 1)
     float envelopeMetres{0.0f};               // Local nDSM canopy envelope (p90 under the footprint)
     float footprintRadiusMetres{0.0f};        // scale x prototype horizontal radius
     float tiltDegrees{0.0f};                  // Terrain-plane slope the patch follows
     float terrainResidualMetres{0.0f};        // Largest terrain deviation from that plane
     float yawRadians{0.0f};
     int chunkX{0}, chunkZ{0};
     uint32_t chunkIndex{0};
};

struct DenseForestProxyStats
{
     std::size_t densePixels{0};
     float denseMedianHeightMetres{0.0f};
     std::size_t tested{0};
     std::size_t rejectedFootprint{0};         // Footprint leaves dense support or touches a barrier / NoData
     std::size_t rejectedLow{0};               // Envelope below the minimum patch height
     std::size_t rejectedSlope{0};             // Terrain plane steeper than the tilt limit
     std::size_t rejectedRelief{0};            // Terrain deviates too far from its plane
     std::size_t rejectedTerrain{0};           // Terrain sample missing
     std::size_t rejectedSpacing{0};           // Too close to an accepted patch
     std::size_t capped{0};                    // Not tested: cap reached
};

struct DenseForestProxies
{
     bool enabled{false};
     std::string disabledReason;
     std::vector<ForestProxy> proxies;
     DenseForestProxyStats stats;
     double chunkSizeMetres{0.0};
     std::size_t chunks{0};
     bool empty() const { return proxies.empty(); }
};

struct DenseForestProxyInput
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
     float prototypeRadius{0.0f};              // Normalised horizontal radius of the forest patch
     double chunkSizeMetres{0.0};
};

// Deterministic forest-patch placement inside stage-3 dense canopy, metric
// presentation only, never in arid scenes (dense median nDSM height < 4 m,
// the same scrub rule as the tree palette). Candidate centres are dense
// pixels in a seeded (DEPTHWIZARD_VEGETATION_SEED) shuffle; a patch is kept
// when its whole footprint disc is DENSE, barrier-free and has finite nDSM;
// its tallest tree is the local p90 nDSM envelope or lower (never canopy +
// tree); it is grounded on the rendered terrain (TerrainSurfaceSampler) and
// tilted to the local terrain plane (at most kMaxTiltDegrees, residual at
// most kMaxResidualShare of its height); and accepted discs overlap by at
// most kMaxOverlapShare. At most kMaxPatches are placed.
class DenseForestProxyGenerator
{
public:
     static constexpr std::size_t kMaxPatches = 150;
     static constexpr float kMinPatchHeightMetres = 3.0f;
     static constexpr float kAridMedianHeightMetres = 4.0f;
     static constexpr float kMaxTiltDegrees = 15.0f;
     static constexpr float kMaxResidualShare = 0.15f;
     static constexpr float kMaxOverlapShare = 0.2f;

     static DenseForestProxies generate(const DenseForestProxyInput& input);
     // Median metric height of DENSE pixels; NaN when there are none.
     static float denseMedianHeight(const VegetationClassification& classes, const VegetationHeights& heights);
};
