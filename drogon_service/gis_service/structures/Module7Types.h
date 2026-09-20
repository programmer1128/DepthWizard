#pragma once

#include <cstdint>
#include <string>
#include <vector>
#include <optional>
#include <array>
#include <cmath>

// ============================================================
// Module 7: Scientific QC & Derivative Generation
// Shared data structures
// ============================================================


// ------------------------------------------------------------
// Processing mode
// ------------------------------------------------------------

enum class PipelineMode
{
    GEOREFERENCED,
    RELATIVE
};


// ------------------------------------------------------------
// RasterGrid
//
// Generic raster container used by Module 7.
//
// data is flattened row-major:
//
// index = row * width + column
//
// Example:
// 3 x 2 raster:
//
// [0, 1, 2,
//  3, 4, 5]
// ------------------------------------------------------------

template <typename T>
struct RasterGrid
{
    int width = 0;
    int height = 0;

    std::vector<T> data;

    // NoData value is optional because some rasters may use
    // NaN instead of a numeric sentinel.
    std::optional<T> noData;

    bool empty() const
    {
        return width <= 0 ||
               height <= 0 ||
               data.empty();
    }

    size_t size() const
    {
        return data.size();
    }

    bool hasExpectedSize() const
    {
        return width > 0 &&
               height > 0 &&
               data.size() ==
                   static_cast<size_t>(width) *
                   static_cast<size_t>(height);
    }

    T& at(int row, int col)
    {
        return data[
            static_cast<size_t>(row) *
            static_cast<size_t>(width) +
            static_cast<size_t>(col)
        ];
    }

    const T& at(int row, int col) const
    {
        return data[
            static_cast<size_t>(row) *
            static_cast<size_t>(width) +
            static_cast<size_t>(col)
        ];
    }

    bool isValidValue(T value) const
    {
        if constexpr (std::is_floating_point_v<T>)
        {
            if (std::isnan(value))
                return false;
        }

        if (noData.has_value() && value == *noData)
            return false;

        return true;
    }
};


// ------------------------------------------------------------
// RasterMetadata
//
// Spatial information required when these rasters eventually
// become GeoTIFF products.
// ------------------------------------------------------------

struct RasterMetadata
{
    int width = 0;
    int height = 0;

    // GDAL affine geotransform:
    //
    // Xgeo = GT[0] + column * GT[1] + row * GT[2]
    // Ygeo = GT[3] + column * GT[4] + row * GT[5]
    //
    std::array<double, 6> geoTransform{
        0.0, 0.0, 0.0,
        0.0, 0.0, 0.0
    };

    std::string projectionRef;

    // Ground sampling distance where known.
    double gsd = 0.0;

    bool hasSpatialReference() const
    {
        return !projectionRef.empty();
    }
};


// ------------------------------------------------------------
// BuildingInstance
//
// Module 6 produces individual building objects.
// Module 7 needs the heights to validate their physical
// consistency.
// ------------------------------------------------------------

struct BuildingInstance
{
    std::uint32_t buildingId = 0;

    // Polygon represented as pairs:
    // {x0,y0, x1,y1, ...}
    //
    // Coordinates are expected to be in the scene's spatial
    // coordinate system.
    std::vector<std::array<double, 2>> footprintPolygon;

    float baseElevation = 0.0f;
    float roofElevation = 0.0f;

    float heightAboveGround = 0.0f;

    float semanticConfidence = 0.0f;
    float heightConfidence = 0.0f;

    std::vector<std::string> geometryWarnings;
};


struct BuildingCollection
{
    std::vector<BuildingInstance> buildings;

    size_t size() const
    {
        return buildings.size();
    }

    bool empty() const
    {
        return buildings.empty();
    }
};


// ------------------------------------------------------------
// SemanticScene
//
// Module 6 consumes semantic information produced by the
// inference pipeline. Module 7 needs the water mask and
// related semantic information for physical QC.
// ------------------------------------------------------------

struct SemanticScene
{
    // Per-pixel class confidence/probability rasters.
    //
    // These are optional because some pipeline stages may not
    // have produced a particular semantic class.
    std::optional<RasterGrid<float>> groundProbability;
    std::optional<RasterGrid<float>> buildingProbability;
    std::optional<RasterGrid<float>> roadProbability;
    std::optional<RasterGrid<float>> vegetationProbability;
    std::optional<RasterGrid<float>> waterProbability;

    // Overall semantic confidence.
    std::optional<RasterGrid<float>> confidence;
};


// ------------------------------------------------------------
// SurfaceBundle
//
// This is the main surface input to Module 7.
//
// The architecture defines the fundamental relationship:
//
// DSM = DTM + nDSM
//
// Module 7 validates this relationship and derives the
// analytical products.
// ------------------------------------------------------------

struct SurfaceBundle
{
    RasterGrid<float> DTM;
    RasterGrid<float> DSM;
    RasterGrid<float> nDSM;

    // Optional because canopy extraction may not always
    // be available.
    std::optional<RasterGrid<float>> canopyHeight;

    // Model/pipeline confidence.
    std::optional<RasterGrid<float>> confidence;

    // Pixels that are considered usable by upstream stages.
    std::optional<RasterGrid<std::uint8_t>> validMask;

    RasterMetadata metadata;

    PipelineMode mode = PipelineMode::GEOREFERENCED;

    std::string units = "meters";
};


// ------------------------------------------------------------
// RasterProductSet
//
// These are the GIS products generated by Module 7.
//
// The architecture specifies eight analytical products:
// DTM, DSM, nDSM, slope, aspect, hillshade, canopy height,
// confidence.
// ------------------------------------------------------------

struct RasterProductSet
{
    RasterGrid<float> DSM;
    RasterGrid<float> DTM;
    RasterGrid<float> nDSM;

    RasterGrid<float> slope;
    RasterGrid<float> aspect;
    RasterGrid<float> hillshade;

    std::optional<RasterGrid<float>> canopyHeight;

    RasterGrid<float> confidence;

    RasterMetadata metadata;
};


// ------------------------------------------------------------
// QualityReport
//
// Output of QualityControlService.
//
// The report contains both a final pass/fail decision and
// diagnostics that can later be returned to the frontend.
// ------------------------------------------------------------

struct QualityReport
{
    bool passed = false;

    // Core mathematical consistency
    bool surfaceIdentityPassed = false;

    // Feature/physics checks
    bool buildingHeightsPassed = false;
    bool waterLevelPassed = false;

    // Basic raster integrity
    bool rasterDimensionsPassed = false;

    // Useful summary statistics
    std::uint64_t checkedPixels = 0;
    std::uint64_t validPixels = 0;

    double maxSurfaceIdentityError = 0.0;
    double meanSurfaceIdentityError = 0.0;

    std::size_t checkedBuildings = 0;
    std::size_t invalidBuildings = 0;

    // Human-readable diagnostics
    std::vector<std::string> warnings;
    std::vector<std::string> errors;
};