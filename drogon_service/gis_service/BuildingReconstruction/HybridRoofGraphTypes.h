#pragma once

#include "../structures/CommonTypes.h"
#include "../structures/GeographicStructs.h"

#include <json/value.h>

#include <array>
#include <cstddef>
#include <optional>
#include <string>
#include <vector>

namespace depthwizard
{

// depthwizard.roofgraph.v1: proposal geometry exchanged between the backend
// and the SAM2/KIBS services. See contracts/README.md for the full rules.
//
// Coordinates are (column, row) in pixel-edge units: (0, 0) is the top-left
// corner of the raster and (W, H) the bottom-right corner. The contract has
// exactly one convention and nothing is ever shifted by half a pixel.
//
// Nothing in this document is a metric height. Heights come only from the
// corrected nDSM; heightClassHintMetres is an optional advisory prior.
inline constexpr const char* kRoofGraphSchema = "depthwizard.roofgraph.v1";
inline constexpr const char* kRoofGraphCoordinateConvention = "pixel_edge_column_row";
inline constexpr std::size_t kRoofGraphMaxRingVertices = 10000;

// Strict rejects any violation. Repair fixes what can be fixed without
// inventing data (clamping, winding, dropping an invalid element) and reports
// every change as a warning; document-level violations still fail.
enum class RoofGraphValidationMode
{
    Strict,
    Repair
};

struct RoofGraphScores
{
    double semantic{0.0};
    double ndsm{0.0};
    // Absent when the expert did not run; 0.0 means it ran and scored zero.
    std::optional<double> sam2;
    std::optional<double> kibs;
    std::optional<double> combined;
};

struct RoofGraphCornerHint
{
    PixelPoint xy;
    // KIBS discrete height class, serialized as "height_class_m". Advisory
    // only: no backend code may use it as a building or roof height.
    std::optional<double> heightClassHintMetres;
    double score{0.0};
    std::string cornerType{"unknown"};
};

struct RoofSectionProposal
{
    std::string id;
    std::vector<PixelPoint> polygon;            // Open ring, positive image-space area
    std::vector<std::vector<PixelPoint>> holes; // Open rings, negative image-space area
    std::vector<RoofGraphCornerHint> corners;
    std::string typeHint{"unknown"};
    std::vector<std::string> adjacentSections;  // IDs of sections in the same building
    double score{0.0};
};

struct RoofGraphProvenance
{
    std::string stage;
    std::string source;
    std::optional<std::string> timestamp;
    Json::Value details; // null when absent
};

struct BuildingProposal
{
    std::string id;
    // Ground footprint with its courtyard holes. Rings follow the contract's
    // image-space winding (outer positive, holes negative), which is the
    // reverse of FootprintPolygon<PixelPoint> for north-up rasters; use
    // HybridRoofGraphImporter::projectPolygon to obtain projected rings.
    FootprintPolygon<PixelPoint> footprintProposal;
    // Visible roof outline; absent when the producer did not propose one.
    std::optional<std::vector<PixelPoint>> roofprintProposal;
    RoofGraphScores scores;
    std::vector<RoofSectionProposal> roofSections;
    std::vector<RoofGraphProvenance> provenance;
};

struct RoofGraphSceneMetadata
{
    std::optional<std::string> sceneId;
    std::optional<std::string> crs;
    std::optional<std::array<double, 6>> geoTransform;
    std::optional<double> gsd;

    bool empty() const { return !sceneId && !crs && !geoTransform && !gsd; }
};

struct RoofGraphDocument
{
    int rasterWidth{0};
    int rasterHeight{0};
    RoofGraphSceneMetadata metadata;
    std::vector<BuildingProposal> buildings;
};

struct HybridRoofGraphImportResult
{
    RoofGraphDocument document;
    bool success{false};
    // Every message starts with a stable code, e.g. "out_of_bounds: ...".
    std::vector<std::string> errors;
    std::vector<std::string> warnings;
    std::size_t buildingCount{0};
    std::size_t sectionCount{0};
};

} // namespace depthwizard
