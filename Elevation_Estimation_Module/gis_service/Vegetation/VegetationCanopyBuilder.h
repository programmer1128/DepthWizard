#pragma once
#include "VegetationClassifier.h"
#include "VegetationConfig.h"
#include "VegetationHeightSampler.h"
#include "VegetationTypes.h"
#include "../MeshMapping/MeshBuildConfig.h"
#include "../structures/MeshStructs.h"
#include "../structures/SurfaceStructs.h"

#include <string>

// Everything the canopy needs from the vegetation stage, handed to
// SceneMeshService. The pointers must outlive the call.
struct VegetationCanopyInput
{
     const VegetationMask* mask{nullptr};
     const VegetationClassification* classification{nullptr};
     const VegetationHeights* heights{nullptr};
     VegetationConfig config;
     // BuildingReconstructionConfig::heightScaleMultiplier: the canopy uses it
     // in flat_urban so trees stay proportional to the buildings.
     float buildingDisplayHeightScale{1.0f};
     // Optional: receives the built canopy and its statistics (diagnostics).
     struct VegetationCanopyMesh* output{nullptr};
     // Stage 5: tree candidates rendered as instanced proxies when
     // config.trees is set (independent of config.canopy), and an optional
     // receiver for the instances (diagnostics).
     const struct VegetationTreeCandidates* treeCandidates{nullptr};
     struct VegetationTreeInstances* treeOutput{nullptr};
     // Stage 5A (asset mode external): optional receiver for the forest-patch
     // proxies, and a note of why external assets were not used (diagnostics).
     struct DenseForestProxies* forestOutput{nullptr};
     // External mode at individual-tree resolution: semantic classes for the
     // shrub cover layer, and an optional receiver for it (diagnostics).
     const struct SemanticScene* semantics{nullptr};
     struct VegetationCover* coverOutput{nullptr};
};

struct VegetationCanopyStats
{
     int stride{0};                         // Grid step in pixels
     double cellColumnMetres{0.0};          // Grid step on the ground, per axis
     double cellRowMetres{0.0};
     std::size_t candidateCells{0};         // Cells with four dense corners
     std::size_t rejectedBarrierCells{0};   // Cell block touches a barrier pixel
     std::size_t rejectedCoverageCells{0};  // Cell block below the dense-coverage share
     std::size_t removedIslandTriangles{0};
     std::size_t vertices{0};
     std::size_t triangles{0};
     bool budgetLimited{false};             // Stride raised to meet the triangle budget
     bool terrainAligned{false};            // Stride snapped to the decimated terrain grid
     float metricHeightMin{0.0f}, metricHeightMax{0.0f};    // Smoothed, tapered nDSM at the nodes
     float displayHeightMin{0.0f}, displayHeightMax{0.0f};  // Y above the base, display units
     float displayHeightScale{1.0f};
     std::string presentationMode;
     std::string skippedReason;             // Set when no canopy is produced
     double buildMilliseconds{0.0};
};

struct VegetationCanopyMesh
{
     MeshPrimitive primitive;   // Positions, normals, UVs, indices; no feature IDs or colours
     VegetationCanopyStats stats;
     bool empty() const { return primitive.indices.empty(); }
};

// Builds the independent canopy surface over DENSE vegetation:
//
//  1. Heights: the clamped metric nDSM, smoothed with a mask-normalised box
//     filter over DENSE pixels only (sum(h * m) / sum(m)), so height never
//     bleeds onto protected, road, water, invalid or bare pixels. Near any
//     mask edge (outline or interior clearing) the displayed height rises at
//     most canopyEdgeSlope per metre from canopyLiftMetres at the edge, so no
//     vertical walls, drapes or slabs can form at any display scale. The
//     capped profile is rounded over canopyCrownRoundingMetres (again
//     mask-normalised) and capped once more, turning the cap's ridges into
//     crown-like mounds.
//  2. Grid: nodes at pixel centres every `stride` pixels. The smallest
//     stride whose triangle count fits canopyMaxTriangles is chosen (on a
//     decimated metric terrain, rounded up to a multiple of the terrain
//     stride so canopy cells coincide with terrain cells); the
//     smoothing radius grows with the stride so a single-pixel spike is never
//     sampled. A cell is meshed only when its four corners are DENSE, its
//     pixel block holds no barrier pixel and at least canopyCellMinCoverage
//     of it is DENSE. Triangle islands smaller than canopyMinIslandTriangles
//     are dropped.
//  3. Vertices: x/z and UV from GeoTransformMapping (UV = pixel / size,
//     top-left origin, no V flip); base Y on the exact rendered terrain
//     (TerrainSurfaceSampler) in metric, 0 in flat_urban;
//     Y = base + clamp(height * scale, lift, lift + edgeDistance * slope),
//     scale = 1 in metric and buildingDisplayHeightScale in flat_urban.
//  4. Winding as TerrainMesher's (v0, v2, v1) / (v1, v2, v3); area-weighted
//     vertex normals.
class VegetationCanopyBuilder
{
public:
     static VegetationCanopyMesh build(const VegetationCanopyInput& input, const GeoreferencedSurfaceBundle& surface,
                                       const SpatialMetadata& metadata, const LocalSceneFrame& frame,
                                       const TerrainMeshConfig& terrainConfig, ScenePresentation presentation);
};
