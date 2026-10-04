#pragma once
#include "DenseForestProxyGenerator.h"
#include "ExternalVegetationAssetLoader.h"
#include "VegetationCoverGenerator.h"
#include "ForestTreeScatter.h"
#include "VegetationTreeInstancer.h"
#include "../FileGenerators/GltfPackager.h"

// Stage 5A: the external-asset form of the tree layer.
//
// Selection (deterministic, from the presentation and measured geometry only):
//   - every rendered stage-4 candidate uses SMALL_BUSH, with its stage-5
//     transform unchanged (base, top, crown radius, yaw);
//   - in a forest scene (metric, not arid, forest patches placed) the
//     DENSE_CANOPY_CROWN candidates are represented by the FOREST_PATCH
//     proxies instead and are not drawn as bushes (never both);
//   - FOREST_PATCH proxies come from DenseForestProxyGenerator only, so they
//     never appear in flat_urban or arid scenes;
//   - garden scenes (flat_urban): no candidate bushes at all; the vegetation
//     is the shrub cover (VegetationCoverGenerator) at garden scale, so no
//     tree-sized bushes stand in parks;
//   - cover shrubs (VEGETATION_COVER_PROXY) share the bush prototype, one
//     node per chunk, NEAR only (always visible).
// Bushes: one EXT_mesh_gpu_instancing node per (chunk, category), NEAR only.
// Forest patches: one batch per chunk at NEAR and MEDIUM (shared instance
// data, no FAR: the continuous canopy remains at distance). One shared
// geometry and texture set per asset; authored textures, no tints.
class VegetationExternalPackaging
{
public:
     // Marks each instance's asset source and replaces trees.batches with
     // the bush batches.
     static void selectAssets(VegetationTreeInstances& trees, bool forestScene, bool gardenScene = false);
     static InstancedPackage package(const VegetationTreeInstances& trees, const DenseForestProxies& forest,
                                     const ExternalVegetationAsset& bush, const ExternalVegetationAsset* forestAsset,
                                     uint32_t seed, const VegetationCover* cover = nullptr,
                                     float bushProminence = 1.0f, const ForestTrees* forestTrees = nullptr,
                                     const ExternalVegetationLibrary* treeLibrary = nullptr);
};
