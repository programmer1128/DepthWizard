#pragma once

#include "../structures/CommonTypes.h"
#include "../structures/GeographicStructs.h"

#include <array>
#include <cstdint>
#include <optional>
#include <string>
#include <vector>

namespace depthwizard
{

enum class RoofGraphCoordinateConvention : uint8_t
{
    PIXEL_EDGE_COLUMN_ROW,
    PIXEL_CENTRE_COLUMN_ROW
};

inline std::string toString(RoofGraphCoordinateConvention conv)
{
    switch (conv)
    {
        case RoofGraphCoordinateConvention::PIXEL_EDGE_COLUMN_ROW:
            return "pixel_edge_column_row";
        case RoofGraphCoordinateConvention::PIXEL_CENTRE_COLUMN_ROW:
            return "pixel_centre_column_row";
    }
    return "pixel_edge_column_row";
}

inline std::optional<RoofGraphCoordinateConvention> parseCoordinateConvention(const std::string& str)
{
    if (str == "pixel_edge_column_row")
        return RoofGraphCoordinateConvention::PIXEL_EDGE_COLUMN_ROW;
    if (str == "pixel_centre_column_row")
        return RoofGraphCoordinateConvention::PIXEL_CENTRE_COLUMN_ROW;
    return std::nullopt;
}

struct RoofGraphScores
{
    float semantic{0.0f};
    float ndsm{0.0f};
    float sam2{0.0f};
    float kibs{0.0f};
    std::optional<float> combined;
};

struct RoofGraphCornerHint
{
    PixelPoint xy;
    // Advisory discrete height class from KIBS prior in metres (non-authoritative;
    // GAMUS nDSM remains the sole metric height authority).
    std::optional<float> heightClassM;
    float score{0.0f};
    std::string cornerType{"unknown"};
};

struct RoofSectionProposal
{
    std::string id;
    std::vector<PixelPoint> polygon; // Open outer ring, CCW in coordinate space
    std::vector<std::vector<PixelPoint>> holes; // Open inner rings, CW
    std::vector<RoofGraphCornerHint> corners;
    std::string typeHint{"unknown"};
    std::vector<std::string> adjacentSections;
    float score{0.0f};
};

struct RoofGraphProvenance
{
    std::string stage;
    std::string source;
    std::string timestamp;
    std::string detailsJson;
};

struct BuildingProposal
{
    std::string id;
    FootprintPolygon<PixelPoint> footprintProposal; // Ground contact footprint
    FootprintPolygon<PixelPoint> roofprintProposal; // Roof boundary proposal
    RoofGraphScores scores;
    std::vector<RoofSectionProposal> roofSections;
    std::vector<RoofGraphProvenance> provenance;
};

struct RoofGraphSceneMetadata
{
    std::string sceneId;
    std::string crs;
    std::array<double, 6> geoTransform{0.0, 1.0, 0.0, 0.0, 0.0, -1.0};
    bool hasGeoTransform{false};
    double gsd{1.0};
};

struct RoofGraphDocument
{
    std::string schema{"depthwizard.roofgraph.v1"};
    int rasterWidth{0};
    int rasterHeight{0};
    RoofGraphCoordinateConvention coordinateConvention{RoofGraphCoordinateConvention::PIXEL_EDGE_COLUMN_ROW};
    RoofGraphSceneMetadata metadata;
    std::vector<BuildingProposal> buildings;
};

struct HybridRoofGraphImportResult
{
    RoofGraphDocument document;
    bool success{false};
    std::vector<std::string> errors;
    std::vector<std::string> warnings;
    std::size_t buildingCount{0};
    std::size_t sectionCount{0};
};

} // namespace depthwizard