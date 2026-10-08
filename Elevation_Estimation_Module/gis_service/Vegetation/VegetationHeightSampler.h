#pragma once
#include "VegetationConfig.h"
#include "VegetationTypes.h"
#include "../MeshMapping/MeshBuildConfig.h"
#include "../structures/SurfaceStructs.h"

#include <optional>
#include <string>

// Vegetation heights. Object height comes only from the fused metric nDSM
// (surface.ndsm, i.e. DSM - DTM as validated by SurfaceFusionService); the
// base comes from the DTM that TerrainMesher samples. Raw DSM elevation is
// never an object height.
struct VegetationHeights
{
     // Metric object height per pixel, clamped to [0, ceiling]; NaN outside
     // the cleaned mask.
     RasterGrid<float> metricHeight;
     float ceilingMetres{0.0f};   // min(maximum, robust scene percentile)
     float p05{0.0f}, p50{0.0f}, p95{0.0f};
     std::size_t sampledPixels{0};   // Confirmed + recovered pixels used for the percentiles
     std::size_t clampedPixels{0};   // Pixels lowered to the ceiling
};

// One vegetation feature's heights, kept apart so the metric measurement is
// never confused with the display value.
struct VegetationHeightRecord
{
     float metricHeight{0.0f};        // Clamped nDSM, metres
     float displayHeight{0.0f};       // metricHeight * displayHeightScale
     float displayHeightScale{1.0f};
     float baseElevation{0.0f};       // Absolute DTM elevation, metres
     std::string presentationMode;    // "metric" or "flat_urban"
};

class VegetationHeightSampler
{
public:
     // Percentiles use the confirmed and recovered tiers (gap pixels may be
     // low by construction). The ceiling is min(maxHeightMetres, the
     // heightClampPercentile of those heights).
     static VegetationHeights sample(const VegetationMask& mask, const GeoreferencedSurfaceBundle& surface,
                                     const VegetationConfig& config);

     // Median metric height of mask pixels inside an ellipse of radiusMetres
     // around pixel (column, row): robust against a single noisy pixel.
     static std::optional<float> robustHeight(const VegetationMask& mask, const VegetationHeights& heights,
                                              int column, int row, double radiusMetres);

     // Presentation-aware object-height scale: 1.0 for metric terrain; the
     // building display scale (BuildingReconstructionConfig::heightScaleMultiplier)
     // in flat_urban, so trees stay proportional to the buildings beside them.
     static float displayHeightScale(ScenePresentation presentation, float buildingDisplayHeightScale);

     static VegetationHeightRecord record(float metricHeight, float baseElevation, ScenePresentation presentation,
                                          float buildingDisplayHeightScale);
};
