#pragma once

#include "HybridRoofGraphTypes.h"
#include "BuildingReconstructionConfig.h"
#include "../structures/GeographicStructs.h"
#include "../structures/SurfaceStructs.h"

#include <json/value.h>
#include <string>
#include <vector>

namespace depthwizard
{

// Importer and validator for the canonical hybrid geometry exchange contract
// (schema depthwizard.roofgraph.v1).
//
// Unlike Sat2Lod2Importer, HybridRoofGraphImporter:
// 1. Strictly enforces the declared coordinate convention (pixel_edge_column_row
//    as canonical, with no implicit +0.5 offset).
// 2. Enforces open rings (no implicit closing duplicate vertex).
// 3. Validates finite coordinates within raster bounds [0, W] x [0, H].
// 4. Validates confidence and metric scores in [0, 1].
// 5. Validates building and roof section ID uniqueness.
// 6. Treats KIBS corner height classes as non-authoritative advisory hints,
//    preserving GAMUS nDSM as the sole height authority.
// 7. Supports full round-trip serialization between C++ and JSON.
class HybridRoofGraphImporter
{
public:
    // Parse and validate a Json::Value root object representing a depthwizard.roofgraph.v1 document.
    static HybridRoofGraphImportResult parse(
        const Json::Value& document,
        bool strictValidation = true);

    // Parse and validate a JSON string.
    static HybridRoofGraphImportResult parseJson(
        const std::string& jsonString,
        bool strictValidation = true);

    // Parse and validate from a file on disk.
    static HybridRoofGraphImportResult parseFile(
        const std::string& path,
        bool strictValidation = true);

    // Serialize a RoofGraphDocument back to a Json::Value according to schema depthwizard.roofgraph.v1.
    static Json::Value toJson(const RoofGraphDocument& document);

    // Serialize a RoofGraphDocument to a JSON string.
    static std::string toJsonString(const RoofGraphDocument& document, bool pretty = true);

    // Project a PixelPoint to ProjectedPoint using spatial metadata with NO silent +0.5 shift
    // (exact pixel-edge convention).
    static ProjectedPoint toProjected(const PixelPoint& pixel, const SpatialMetadata& metadata);

    // Project a FootprintPolygon<PixelPoint> to FootprintPolygon<ProjectedPoint>
    // ensuring CCW outer ring and CW holes in projected space.
    static FootprintPolygon<ProjectedPoint> projectPolygon(
        const FootprintPolygon<PixelPoint>& pixelPoly,
        const SpatialMetadata& metadata);

    // Convert a validated RoofGraphDocument into native BuildingCollection instances
    // measuring metric heights exclusively from the corrected nDSM.
    static BuildingCollection toBuildingCollection(
        const RoofGraphDocument& document,
        const SemanticScene& semantics,
        const GeoreferencedSurfaceBundle& surface,
        const SpatialMetadata& metadata,
        const BuildingReconstructionConfig& config,
        const RasterGrid<float>& reconstructionNdsm,
        std::vector<std::string>& warnings);
};

} // namespace depthwizard
