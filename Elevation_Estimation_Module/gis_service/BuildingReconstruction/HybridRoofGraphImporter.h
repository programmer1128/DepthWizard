#pragma once

#include "HybridRoofGraphTypes.h"
#include "../structures/GeographicStructs.h"

#include <json/value.h>
#include <string>

namespace depthwizard
{

// Parser, validator and serializer for depthwizard.roofgraph.v1. It is
// separate from Sat2Lod2Importer: SAT2LoD2 reports pixel-centre indices and
// needs +0.5, whereas this contract is pixel-edge only and is never shifted.
//
// None of these functions throw. Parsing failures are reported through
// HybridRoofGraphImportResult::errors.
class HybridRoofGraphImporter
{
public:
    static HybridRoofGraphImportResult parse(
        const Json::Value& document,
        RoofGraphValidationMode mode = RoofGraphValidationMode::Strict);

    static HybridRoofGraphImportResult parseJson(
        const std::string& json,
        RoofGraphValidationMode mode = RoofGraphValidationMode::Strict);

    static HybridRoofGraphImportResult parseFile(
        const std::string& path,
        RoofGraphValidationMode mode = RoofGraphValidationMode::Strict);

    // Canonical form: every non-optional field is written, absent optional
    // fields are omitted, rings are open and use the contract winding.
    static Json::Value toJson(const RoofGraphDocument& document);
    static std::string toJsonString(const RoofGraphDocument& document, bool pretty = true);

    // Pixel-edge (column, row) to projected coordinates, without a half-pixel shift.
    static ProjectedPoint toProjected(const PixelPoint& pixel, const SpatialMetadata& metadata);

    // Projects a footprint and orders it CCW outer / CW holes in projected
    // space, the FootprintPolygon invariant.
    static FootprintPolygon<ProjectedPoint> projectPolygon(
        const FootprintPolygon<PixelPoint>& pixelPolygon,
        const SpatialMetadata& metadata);
};

} // namespace depthwizard
