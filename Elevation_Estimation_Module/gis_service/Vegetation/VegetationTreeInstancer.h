#pragma once
#include "VegetationConfig.h"
#include "VegetationTreeCandidateGenerator.h"
#include "VegetationTreePrototypes.h"
#include "ExternalVegetationAssetLoader.h"
#include "../structures/CommonTypes.h"

#include <array>
#include <cstdint>
#include <string>
#include <vector>

// One instance of a tree visualization proxy, derived from one stage-4
// candidate. Position and total height are the candidate's; only rotation,
// a <= 10% crown-width reduction and the colour tint are cosmetic (deterministic
// from candidate id and DEPTHWIZARD_VEGETATION_SEED).
struct TreeInstance
{
     uint32_t candidateId{0};
     TreeCandidateCategory category{TreeCandidateCategory::ISOLATED_TREE};
     TreeVisualVariant variant{TreeVisualVariant::BROADLEAF_ROUND};
     std::string variantReason;
     int colourTint{0};                    // Per-instance tint index (0-3), cosmetic
     float rotationRadians{0.0f};          // Yaw about +Y
     float widthFactor{1.0f};              // In [0.9, 1.0]: never wider than the measured crown
     std::array<float, 3> translation{};   // (worldX, baseY, worldZ)
     std::array<float, 4> rotation{0, 0, 0, 1}; // Unit quaternion (x, y, z, w)
     std::array<float, 3> scale{};         // (crownRadius x width, displayHeight, crownRadius x width)
     float metricHeight{0.0f};
     float displayHeight{0.0f};
     float crownRadiusMetres{0.0f};
     int chunkX{0}, chunkZ{0};             // Projected-coordinate grid cell
     uint32_t chunkIndex{0};
     // Stage 5A: the prototype that draws it; false when a forest patch
     // represents this dense-canopy crown instead (never both).
     VegetationAssetSource assetSource{VegetationAssetSource::PROCEDURAL};
     bool rendered{true};
};

// Instances sharing one prototype mesh, level of detail and chunk: one
// EXT_mesh_gpu_instancing node (colour variety is a per-instance tint).
struct TreeBatch
{
     TreeVisualVariant variant{TreeVisualVariant::BROADLEAF_ROUND};
     TreeLod lod{TreeLod::NEAR};
     uint32_t chunkIndex{0};
     int chunkX{0}, chunkZ{0};
     std::vector<std::size_t> instances;   // Indices into VegetationTreeInstances::instances
     std::array<double, 3> boundsMin{}, boundsMax{};   // Local frame, all instances' extents
     std::string name;                     // VEGETATION_TREES_<LOD>_<VARIANT>_CHUNK_<NNN>
     std::string batchKey;                 // Shared by the LOD levels of one batch
     float typicalHeight{0.0f};            // Median display height (frontend LOD)
     float typicalRadius{0.0f};            // Median crown radius
     VegetationAssetSource assetSource{VegetationAssetSource::PROCEDURAL};
     TreeCandidateCategory category{TreeCandidateCategory::ISOLATED_TREE};   // External batches: one category
};

struct VegetationTreeInstances
{
     std::vector<TreeInstance> instances;  // In candidate order
     std::vector<TreeBatch> batches;       // Deterministic order
     double chunkSizeMetres{0.0};
     std::size_t chunks{0};
     bool lodEnabled{true};
     std::string paletteFamily;            // "temperate" or "arid"
     std::array<std::size_t, kTreeVariantCount> perVariant{};
     std::size_t isolated{0}, canopyCrowns{0};
     bool empty() const { return instances.empty(); }
};

// Visual variant from measured geometry (metric height, crown radius,
// vegetation support, compactness); dense-canopy crowns always use the
// CANOPY_CROWN profile. Palette family: "arid" when the median measured
// height of all candidates is below 4 m (scrub: muted olive/brown-green),
// otherwise "temperate".
class VegetationTreeInstancer
{
public:
     static VegetationTreeInstances build(const VegetationTreeCandidates& candidates, const LocalSceneFrame& frame,
                                          const VegetationConfig& config, double sceneExtentMetres);

     static TreeVisualVariant selectVariant(const TreeCandidate& candidate, std::string* reason = nullptr);
     // Deterministic value in [0, 1) from candidate id, seed and a salt.
     static double cosmeticNoise(uint32_t candidateId, uint32_t seed, uint32_t salt);
     static double chunkSize(const VegetationConfig& config, double sceneExtentMetres);
};
