#pragma once

#include <cstdint>
#include <functional>
#include <optional>
#include <string>
#include <vector>

// DEPTHWIZARD_VEGETATION=0|1|auto: the image-derived vegetation overlay.
//
//   0 (default)  bypassed entirely; the production path is untouched.
//   1            runs whenever semantic and height inputs are available.
//   auto         runs only when a usable vegetation mask with height evidence
//                exists; otherwise the original output is kept.
//
// The default follows the project's feature-flag rule: every flag defaults
// to the current behaviour (utils/FeatureFlags.h).
enum class VegetationMode
{
     OFF,
     ON,
     AUTO
};
const char* toString(VegetationMode mode);

// DEPTHWIZARD_VEGETATION_ASSET_MODE=procedural|external: which prototypes
// the tree layer uses. procedural (default) is the stage-5 output byte for
// byte; external uses the bundled CC-BY assets (small bush, forest patch).
enum class VegetationAssetMode
{
     PROCEDURAL,
     EXTERNAL
};
const char* toString(VegetationAssetMode mode);

// All vegetation settings, parsed in one place from DEPTHWIZARD_VEGETATION_*.
// Invalid values fall back to their default with a warning.
struct VegetationConfig
{
     VegetationMode mode{VegetationMode::OFF};      // DEPTHWIZARD_VEGETATION
     bool canopy{true};                             // DEPTHWIZARD_VEGETATION_CANOPY
     bool trees{true};                              // DEPTHWIZARD_VEGETATION_TREES
     float minHeightMetres{1.5f};                   // DEPTHWIZARD_VEGETATION_MIN_HEIGHT_M
     float maxHeightMetres{45.0f};                  // DEPTHWIZARD_VEGETATION_MAX_HEIGHT_M
     int maxInstances{3000};                        // DEPTHWIZARD_VEGETATION_MAX_INSTANCES
     uint32_t seed{1337};                           // DEPTHWIZARD_VEGETATION_SEED
     bool diagnostics{false};                       // DEPTHWIZARD_VEGETATION_DIAGNOSTICS
     bool recoverUnknown{true};                     // DEPTHWIZARD_VEGETATION_RECOVER_UNKNOWN
     // UNKNOWN pixels cannot exceed about 0.575 vegetation probability (the
     // class rule needs >= 0.50 and a 0.15 margin), so 0.50 is the strictest
     // threshold that can ever recover anything. Every other gate still applies.
     float unknownProbability{0.50f};               // DEPTHWIZARD_VEGETATION_UNKNOWN_PROBABILITY

     // Dense canopy versus isolated trees (stage 3). Defaults measured on the
     // NYC (0.5 m) and Test8 (10 m) fixtures; see VegetationClassifier.h.
     float denseMinAreaSquareMetres{300.0f};        // DEPTHWIZARD_VEGETATION_DENSE_MIN_AREA_M2
     float denseLocalCoverage{0.60f};               // DEPTHWIZARD_VEGETATION_DENSE_LOCAL_COVERAGE
     float individualTreeMaxGsdMetres{1.0f};        // DEPTHWIZARD_VEGETATION_INDIVIDUAL_TREE_MAX_GSD_M
     int canopyMaxTriangles{200000};                // DEPTHWIZARD_VEGETATION_CANOPY_MAX_TRIANGLES
     float canopySmoothRadiusMetres{2.0f};          // DEPTHWIZARD_VEGETATION_CANOPY_SMOOTH_RADIUS_M
     // Edge profile: near any mask edge (outline or interior clearing) the
     // displayed object height may rise at most this much per metre of
     // distance, starting from canopyLiftMetres at the edge. A bounded slope
     // cannot form walls or drapes at any display scale.
     float canopyEdgeSlope{1.0f};                   // DEPTHWIZARD_VEGETATION_CANOPY_EDGE_SLOPE

     // Individual-tree candidates (stage 4). Radii measured on NYC: the
     // isolated crowns are about 5 to 10 m across. See
     // VegetationTreeCandidateGenerator.h.
     float treeMinCrownRadiusMetres{1.0f};          // DEPTHWIZARD_VEGETATION_TREE_MIN_CROWN_RADIUS_M
     float treeMaxCrownRadiusMetres{7.0f};          // DEPTHWIZARD_VEGETATION_TREE_MAX_CROWN_RADIUS_M
     // Experimental: crown-like UNKNOWN pixels below the stage-2 threshold.
     bool treeRecoverLowConfidence{false};          // DEPTHWIZARD_VEGETATION_TREE_RECOVER_LOW_CONFIDENCE
     float treeRecoveryMinProbability{0.30f};       // DEPTHWIZARD_VEGETATION_TREE_RECOVERY_MIN_PROBABILITY
     float treeRecoveryMinConfidence{0.60f};        // DEPTHWIZARD_VEGETATION_TREE_RECOVERY_MIN_CONFIDENCE
     // Tree rendering (stage 5). Chunk size 0 = automatic: a quarter of the
     // scene extent, clamped to 100-250 m.
     float treeChunkSizeMetres{0.0f};               // DEPTHWIZARD_VEGETATION_TREE_CHUNK_SIZE_M
     bool treeLod{true};                            // DEPTHWIZARD_VEGETATION_TREE_LOD (near/medium/far batches)
     // External vegetation assets (stage 5A).
     VegetationAssetMode assetMode{VegetationAssetMode::PROCEDURAL}; // DEPTHWIZARD_VEGETATION_ASSET_MODE
     bool forestProxies{true};                      // DEPTHWIZARD_VEGETATION_FOREST_PROXIES (external mode only)

     // Conservative mask constants (metres are converted to pixels per raster
     // axis from the geotransform; not environment-configurable).
     float buildingBufferMetres{2.0f};              // Protected ring around every footprint
     float maxUnknownBuildingProbability{0.30f};    // UNKNOWN recovery: building evidence veto
     float maxUnknownRoadWaterProbability{0.30f};   // UNKNOWN recovery: road/water evidence veto
     float unknownSupportDistanceMetres{3.0f};      // UNKNOWN next to confirmed vegetation
     float unknownCompactAreaSquareMetres{25.0f};   // ...or a compact region of its own
     float unknownSpikeToleranceMetres{6.0f};       // Above the local 3x3 median height
     float minComponentAreaSquareMetres{4.0f};      // Smaller vegetation specks are noise
     float gapClosingMetres{1.0f};                  // Only gaps up to about this are closed
     float heightClampPercentile{0.995f};           // Robust scene ceiling for metric height
     // Canopy constants.
     float denseCoverageRadiusMetres{5.0f};         // Window for local vegetation coverage
     float denseMinWidthMetres{12.0f};              // 2 x largest inscribed radius of a dense core
     float denseFringeMetres{5.0f};                 // Mask pixels this close to a dense core join it
     float canopyCellMinCoverage{0.5f};             // Dense share of a grid cell's pixel block
     float canopyLiftMetres{0.3f};                  // Display clearance above the terrain (no z-fighting)
     float canopyCrownRoundingMetres{3.0f};         // Rounds the slope-capped profile into mounds
     int canopyMinIslandTriangles{8};               // Smaller triangle islands are noise
     // Tree-candidate constants.
     float treeSmoothRadiusMetres{1.0f};            // Mask-normalised nDSM smoothing before peak search
     float treeCoreRadiusMetres{1.0f};              // Window for the robust peak height
     float treeHeightPercentile{0.90f};             // Robust height: this percentile of the core
     float treeSpikeMedianFraction{0.5f};           // Core median below this share of the peak = spike
     float treeMinSupportAreaSquareMetres{3.0f};    // Smallest segmented crown
     float treeMinAspect{0.2f};                     // Height / crown diameter: below = pancake
     float treeMaxAspect{5.0f};                     // ...above = needle
     float treeIsolatedSeparation{1.0f};            // NMS distance, x the larger crown radius
     float treeIsolatedMinConfidence{0.35f};
     float denseCrownSeparation{1.5f};              // Stricter for canopy crowns
     float denseCrownMinSpacingMetres{6.0f};        // Plausible crown spacing inside canopy
     float denseCrownMinProminenceMetres{1.5f};     // Peak above its surrounding canopy
     float denseCrownMinConfidence{0.55f};
     // Non-georeferenced rasters: the conservative pixel size assumed when
     // converting the metre thresholds above.
     float fallbackPixelSizeMetres{1.0f};

     std::vector<std::string> warnings;

     using Lookup = std::function<std::optional<std::string>(const std::string&)>;
     static VegetationConfig parse(const Lookup& lookup);
     static VegetationConfig fromEnvironment();

     bool enabled() const { return mode != VegetationMode::OFF; }
     std::string summary() const;
};
