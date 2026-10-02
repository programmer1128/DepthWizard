#include "HybridRoofGraphImporter.h"
#include "BuildingHeightEstimator.h"
#include "FootprintGeometryRegularizer.h"

#include <json/reader.h>
#include <json/writer.h>
#include <ogr_geometry.h>

#include <algorithm>
#include <cmath>
#include <fstream>
#include <limits>
#include <memory>
#include <sstream>
#include <unordered_set>

namespace depthwizard
{

namespace
{

constexpr const char* kExpectedSchema = "depthwizard.roofgraph.v1";

double signedArea(const std::vector<PixelPoint>& ring)
{
    if (ring.size() < 3) return 0.0;
    double twiceArea = 0.0;
    const std::size_t n = ring.size();
    for (std::size_t i = 0; i < n; ++i)
    {
        const auto& curr = ring[i];
        const auto& next = ring[(i + 1) % n];
        twiceArea += curr.column * next.row - next.column * curr.row;
    }
    return 0.5 * twiceArea;
}

double projectedRingArea(const std::vector<ProjectedPoint>& ring)
{
    if (ring.size() < 3) return 0.0;
    double twiceArea = 0.0;
    const std::size_t n = ring.size();
    for (std::size_t i = 0; i < n; ++i)
    {
        const auto& curr = ring[i];
        const auto& next = ring[(i + 1) % n];
        twiceArea += curr.easting * next.northing - next.easting * curr.northing;
    }
    return 0.5 * twiceArea;
}

void removeRedundantVertices(std::vector<PixelPoint>& ring)
{
    bool changed = true;
    while (changed && ring.size() > 3)
    {
        changed = false;
        const std::size_t n = ring.size();
        for (std::size_t index = 0; index < n; ++index)
        {
            const PixelPoint& previous = ring[(index + n - 1) % n];
            const PixelPoint& current = ring[index];
            const PixelPoint& next = ring[(index + 1) % n];
            const double inX = current.column - previous.column;
            const double inY = current.row - previous.row;
            const double outX = next.column - current.column;
            const double outY = next.row - current.row;
            const double inLength = std::hypot(inX, inY);
            const double outLength = std::hypot(outX, outY);
            const bool duplicate = inLength < 1.0e-6;
            const bool collinear = inLength > 0.0 && outLength > 0.0 &&
                std::abs(inX * outY - inY * outX) / (inLength * outLength) < 0.02 &&
                inX * outX + inY * outY > 0.0;
            if (duplicate || collinear)
            {
                ring.erase(ring.begin() + static_cast<std::ptrdiff_t>(index));
                changed = true;
                break;
            }
        }
    }
}

bool repairRingWithOgr(std::vector<PixelPoint>& ring)
{
    removeRedundantVertices(ring);
    if (ring.size() < 3) return false;

    OGRLinearRing linearRing;
    for (const PixelPoint& point : ring)
        linearRing.addPoint(point.column, point.row);
    linearRing.closeRings();
    OGRPolygon polygon;
    polygon.addRing(&linearRing);
    if (polygon.IsValid()) return true;

    std::unique_ptr<OGRGeometry, decltype(&OGRGeometryFactory::destroyGeometry)>
        repaired(polygon.Buffer(0.0), OGRGeometryFactory::destroyGeometry);
    if (!repaired) return false;

    const OGRPolygon* largest = nullptr;
    double largestArea = 0.0;
    const auto consider = [&](const OGRGeometry* geometry)
    {
        const auto* part = dynamic_cast<const OGRPolygon*>(geometry);
        if (part != nullptr && part->get_Area() > largestArea)
        {
            largest = part;
            largestArea = part->get_Area();
        }
    };
    if (const auto* collection = dynamic_cast<const OGRGeometryCollection*>(repaired.get()))
    {
        for (int index = 0; index < collection->getNumGeometries(); ++index)
            consider(collection->getGeometryRef(index));
    }
    else
    {
        consider(repaired.get());
    }
    if (largest == nullptr || largest->getExteriorRing() == nullptr) return false;

    const OGRLinearRing* exterior = largest->getExteriorRing();
    ring.clear();
    for (int index = 0; index + 1 < exterior->getNumPoints(); ++index)
        ring.push_back(PixelPoint{exterior->getX(index), exterior->getY(index)});
    removeRedundantVertices(ring);
    return ring.size() >= 3;
}

bool readRing(
    const Json::Value& value,
    int rasterWidth,
    int rasterHeight,
    bool shiftFromCentre,
    bool strictValidation,
    std::vector<PixelPoint>& ring,
    std::vector<std::string>& errors,
    std::vector<std::string>& warnings,
    const std::string& context)
{
    ring.clear();
    if (!value.isArray())
    {
        errors.push_back(context + " must be a JSON array of points.");
        return false;
    }

    const double maxWidth = static_cast<double>(rasterWidth);
    const double maxHeight = static_cast<double>(rasterHeight);

    for (Json::ArrayIndex i = 0; i < value.size(); ++i)
    {
        const auto& pointVal = value[i];
        if (!pointVal.isArray() || pointVal.size() != 2 ||
            !pointVal[0].isNumeric() || !pointVal[1].isNumeric())
        {
            errors.push_back(context + " point at index " + std::to_string(i) + " is not a valid 2D numeric point [column, row].");
            return false;
        }

        double col = pointVal[0].asDouble();
        double row = pointVal[1].asDouble();

        if (!std::isfinite(col) || !std::isfinite(row))
        {
            errors.push_back(context + " point at index " + std::to_string(i) + " has non-finite coordinates.");
            return false;
        }

        if (shiftFromCentre)
        {
            col += 0.5;
            row += 0.5;
        }

        if (col < 0.0 || col > maxWidth || row < 0.0 || row > maxHeight)
        {
            if (strictValidation)
            {
                errors.push_back(context + " point (" + std::to_string(col) + ", " + std::to_string(row) +
                                 ") is outside raster bounds [0, " + std::to_string(maxWidth) + "] x [0, " +
                                 std::to_string(maxHeight) + "].");
                return false;
            }
            else
            {
                warnings.push_back(context + " point (" + std::to_string(col) + ", " + std::to_string(row) +
                                   ") was clamped to raster bounds.");
                col = std::clamp(col, 0.0, maxWidth);
                row = std::clamp(row, 0.0, maxHeight);
            }
        }

        ring.push_back(PixelPoint{col, row});
    }

    // Check for disallowed implicit closing vertex
    if (ring.size() >= 2)
    {
        const auto& first = ring.front();
        const auto& last = ring.back();
        if (std::abs(first.column - last.column) < 1.0e-6 &&
            std::abs(first.row - last.row) < 1.0e-6)
        {
            if (strictValidation)
            {
                errors.push_back(context + " has duplicate closing vertex; depthwizard.roofgraph.v1 serialized rings must be open (no closing vertex).");
                return false;
            }
            else
            {
                warnings.push_back(context + " stripped redundant closing vertex.");
                ring.pop_back();
            }
        }
    }

    if (ring.size() < 3)
    {
        errors.push_back(context + " has fewer than 3 unique vertices (got " + std::to_string(ring.size()) + ").");
        return false;
    }

    // Validate geometry via OGR
    OGRLinearRing ogrRing;
    for (const auto& pt : ring)
        ogrRing.addPoint(pt.column, pt.row);
    ogrRing.closeRings();
    OGRPolygon ogrPoly;
    ogrPoly.addRing(&ogrRing);

    if (!ogrPoly.IsValid())
    {
        if (strictValidation)
        {
            errors.push_back(context + " is self-intersecting or topologically invalid.");
            return false;
        }
        else
        {
            warnings.push_back(context + " was self-intersecting; repaired via Buffer(0.0).");
            if (!repairRingWithOgr(ring))
            {
                errors.push_back(context + " repair failed; could not produce simple polygon.");
                return false;
            }
        }
    }

    return true;
}

} // namespace

ProjectedPoint HybridRoofGraphImporter::toProjected(
    const PixelPoint& pixel, const SpatialMetadata& metadata)
{
    const auto& gt = metadata.geoTransform;
    // Canonical pixel-edge coordinate convention: no silent +0.5 is added!
    return ProjectedPoint{
        gt[0] + pixel.column * gt[1] + pixel.row * gt[2],
        gt[3] + pixel.column * gt[4] + pixel.row * gt[5]
    };
}

FootprintPolygon<ProjectedPoint> HybridRoofGraphImporter::projectPolygon(
    const FootprintPolygon<PixelPoint>& pixelPoly,
    const SpatialMetadata& metadata)
{
    FootprintPolygon<ProjectedPoint> projected;

    const auto projectRing = [&](const std::vector<PixelPoint>& pRing, bool wantCCW)
    {
        std::vector<ProjectedPoint> proj;
        proj.reserve(pRing.size());
        for (const auto& pt : pRing)
            proj.push_back(toProjected(pt, metadata));

        const double area = projectedRingArea(proj);
        const bool isCCW = (area > 0.0);
        if (isCCW != wantCCW)
            std::reverse(proj.begin(), proj.end());
        return proj;
    };

    projected.outerRing = projectRing(pixelPoly.outerRing, true);
    for (const auto& hole : pixelPoly.holes)
        projected.holes.push_back(projectRing(hole, false));

    return projected;
}

HybridRoofGraphImportResult HybridRoofGraphImporter::parse(
    const Json::Value& document,
    bool strictValidation)
{
    HybridRoofGraphImportResult result;
    if (!document.isObject())
    {
        result.errors.push_back("Root JSON document must be an object.");
        return result;
    }

    // 1. Schema check
    if (!document.isMember("schema") || !document["schema"].isString() ||
        document["schema"].asString() != kExpectedSchema)
    {
        result.errors.push_back("Missing or invalid schema identifier. Expected '" +
                                std::string(kExpectedSchema) + "'.");
        return result;
    }
    result.document.schema = document["schema"].asString();

    // 2. Raster dimensions
    if (!document.isMember("raster_width") || !document["raster_width"].isInt() ||
        document["raster_width"].asInt() <= 0)
    {
        result.errors.push_back("raster_width must be a positive integer.");
        return result;
    }
    if (!document.isMember("raster_height") || !document["raster_height"].isInt() ||
        document["raster_height"].asInt() <= 0)
    {
        result.errors.push_back("raster_height must be a positive integer.");
        return result;
    }
    result.document.rasterWidth = document["raster_width"].asInt();
    result.document.rasterHeight = document["raster_height"].asInt();

    // 3. Coordinate convention
    bool shiftFromCentre = false;
    if (document.isMember("coordinate_convention") && document["coordinate_convention"].isString())
    {
        const std::string convStr = document["coordinate_convention"].asString();
        const auto parsedConv = parseCoordinateConvention(convStr);
        if (!parsedConv.has_value())
        {
            result.errors.push_back("Unknown coordinate_convention: '" + convStr +
                                    "'. Expected 'pixel_edge_column_row' or 'pixel_centre_column_row'.");
            return result;
        }
        result.document.coordinateConvention = *parsedConv;
        if (*parsedConv == RoofGraphCoordinateConvention::PIXEL_CENTRE_COLUMN_ROW)
        {
            shiftFromCentre = true;
            result.warnings.push_back("Document declared 'pixel_centre_column_row'; converted coordinates to canonical pixel edges with +0.5 shift.");
        }
    }
    else
    {
        result.document.coordinateConvention = RoofGraphCoordinateConvention::PIXEL_EDGE_COLUMN_ROW;
    }

    // 4. Optional metadata
    if (document.isMember("metadata") && document["metadata"].isObject())
    {
        const auto& metaVal = document["metadata"];
        if (metaVal.isMember("scene_id") && metaVal["scene_id"].isString())
            result.document.metadata.sceneId = metaVal["scene_id"].asString();
        if (metaVal.isMember("crs") && metaVal["crs"].isString())
            result.document.metadata.crs = metaVal["crs"].asString();
        if (metaVal.isMember("gsd") && metaVal["gsd"].isNumeric())
            result.document.metadata.gsd = metaVal["gsd"].asDouble();
        if (metaVal.isMember("geo_transform") && metaVal["geo_transform"].isArray() &&
            metaVal["geo_transform"].size() == 6)
        {
            result.document.metadata.hasGeoTransform = true;
            for (int k = 0; k < 6; ++k)
                result.document.metadata.geoTransform[k] = metaVal["geo_transform"][k].asDouble();
        }
    }

    // 5. Buildings
    if (!document.isMember("buildings") || !document["buildings"].isArray())
    {
        result.errors.push_back("Document missing required 'buildings' array.");
        return result;
    }

    std::unordered_set<std::string> seenBuildingIds;
    const auto& buildingsVal = document["buildings"];

    for (Json::ArrayIndex bIdx = 0; bIdx < buildingsVal.size(); ++bIdx)
    {
        const auto& bVal = buildingsVal[bIdx];
        if (!bVal.isObject())
        {
            result.errors.push_back("buildings[" + std::to_string(bIdx) + "] is not an object.");
            continue;
        }

        // Building ID
        if (!bVal.isMember("id") || !bVal["id"].isString() || bVal["id"].asString().empty())
        {
            result.errors.push_back("buildings[" + std::to_string(bIdx) + "] missing or empty 'id'.");
            continue;
        }
        const std::string buildingId = bVal["id"].asString();
        if (seenBuildingIds.find(buildingId) != seenBuildingIds.end())
        {
            result.errors.push_back("Duplicate building ID detected: '" + buildingId + "'.");
            continue;
        }
        seenBuildingIds.insert(buildingId);

        BuildingProposal proposal;
        proposal.id = buildingId;

        // Footprint proposal
        const std::string fpCtx = "Building '" + buildingId + "' footprint_proposal";
        if (!bVal.isMember("footprint_proposal"))
        {
            result.errors.push_back(fpCtx + " is missing.");
            continue;
        }
        if (!readRing(bVal["footprint_proposal"], result.document.rasterWidth,
                      result.document.rasterHeight, shiftFromCentre, strictValidation,
                      proposal.footprintProposal.outerRing, result.errors, result.warnings, fpCtx))
        {
            continue;
        }
        // Normalize outer ring to CCW in (c, r) space
        if (signedArea(proposal.footprintProposal.outerRing) < 0.0)
        {
            std::reverse(proposal.footprintProposal.outerRing.begin(),
                         proposal.footprintProposal.outerRing.end());
            result.warnings.push_back(fpCtx + " normalized to Counter-Clockwise winding.");
        }

        // Holes
        if (bVal.isMember("holes") && bVal["holes"].isArray())
        {
            for (Json::ArrayIndex hIdx = 0; hIdx < bVal["holes"].size(); ++hIdx)
            {
                std::vector<PixelPoint> holeRing;
                const std::string hCtx = "Building '" + buildingId + "' hole[" + std::to_string(hIdx) + "]";
                if (readRing(bVal["holes"][hIdx], result.document.rasterWidth,
                             result.document.rasterHeight, shiftFromCentre, strictValidation,
                             holeRing, result.errors, result.warnings, hCtx))
                {
                    // Normalize hole to CW in (c, r) space
                    if (signedArea(holeRing) > 0.0)
                    {
                        std::reverse(holeRing.begin(), holeRing.end());
                        result.warnings.push_back(hCtx + " normalized to Clockwise winding.");
                    }
                    proposal.footprintProposal.holes.push_back(holeRing);
                }
            }
        }

        // Roofprint proposal
        if (bVal.isMember("roofprint_proposal") && bVal["roofprint_proposal"].isArray() &&
            bVal["roofprint_proposal"].size() >= 3)
        {
            const std::string rpCtx = "Building '" + buildingId + "' roofprint_proposal";
            readRing(bVal["roofprint_proposal"], result.document.rasterWidth,
                     result.document.rasterHeight, shiftFromCentre, strictValidation,
                     proposal.roofprintProposal.outerRing, result.errors, result.warnings, rpCtx);
            if (signedArea(proposal.roofprintProposal.outerRing) < 0.0)
                std::reverse(proposal.roofprintProposal.outerRing.begin(),
                             proposal.roofprintProposal.outerRing.end());
            proposal.roofprintProposal.holes = proposal.footprintProposal.holes;
        }
        else
        {
            // Default roofprint matches footprint
            proposal.roofprintProposal = proposal.footprintProposal;
        }

        // Confidence Scores
        if (bVal.isMember("scores") && bVal["scores"].isObject())
        {
            const auto& sVal = bVal["scores"];
            const auto readScore = [&](const char* key, float defVal) -> float
            {
                if (sVal.isMember(key) && sVal[key].isNumeric())
                {
                    float v = static_cast<float>(sVal[key].asDouble());
                    if (v < 0.0f || v > 1.0f)
                    {
                        if (strictValidation)
                            result.errors.push_back("Building '" + buildingId + "' score '" + key +
                                                    "' out of range [0, 1]: " + std::to_string(v));
                        else
                        {
                            result.warnings.push_back("Building '" + buildingId + "' score '" + key +
                                                      "' clamped to [0, 1].");
                            v = std::clamp(v, 0.0f, 1.0f);
                        }
                    }
                    return v;
                }
                return defVal;
            };

            proposal.scores.semantic = readScore("semantic", 0.0f);
            proposal.scores.ndsm = readScore("ndsm", 0.0f);
            proposal.scores.sam2 = readScore("sam2", 0.0f);
            proposal.scores.kibs = readScore("kibs", 0.0f);
            if (sVal.isMember("combined") && sVal["combined"].isNumeric())
                proposal.scores.combined = readScore("combined", 0.0f);
        }

        // Roof Sections
        std::unordered_set<std::string> seenSectionIds;
        if (bVal.isMember("roof_sections") && bVal["roof_sections"].isArray())
        {
            for (Json::ArrayIndex sIdx = 0; sIdx < bVal["roof_sections"].size(); ++sIdx)
            {
                const auto& sVal = bVal["roof_sections"][sIdx];
                if (!sVal.isObject()) continue;

                if (!sVal.isMember("id") || !sVal["id"].isString() || sVal["id"].asString().empty())
                {
                    result.errors.push_back("Building '" + buildingId + "' roof_sections[" +
                                            std::to_string(sIdx) + "] missing or empty 'id'.");
                    continue;
                }
                const std::string sectionId = sVal["id"].asString();
                if (seenSectionIds.find(sectionId) != seenSectionIds.end())
                {
                    result.errors.push_back("Duplicate roof section ID '" + sectionId +
                                            "' in building '" + buildingId + "'.");
                    continue;
                }
                seenSectionIds.insert(sectionId);

                RoofSectionProposal section;
                section.id = sectionId;

                const std::string sCtx = "Building '" + buildingId + "' section '" + sectionId + "'";
                if (!sVal.isMember("polygon") ||
                    !readRing(sVal["polygon"], result.document.rasterWidth, result.document.rasterHeight,
                              shiftFromCentre, strictValidation, section.polygon, result.errors,
                              result.warnings, sCtx + " polygon"))
                {
                    continue;
                }
                if (signedArea(section.polygon) < 0.0)
                    std::reverse(section.polygon.begin(), section.polygon.end());

                // Section Holes
                if (sVal.isMember("holes") && sVal["holes"].isArray())
                {
                    for (Json::ArrayIndex shIdx = 0; shIdx < sVal["holes"].size(); ++shIdx)
                    {
                        std::vector<PixelPoint> sHole;
                        const std::string shCtx = sCtx + " hole[" + std::to_string(shIdx) + "]";
                        if (readRing(sVal["holes"][shIdx], result.document.rasterWidth,
                                     result.document.rasterHeight, shiftFromCentre, strictValidation,
                                     sHole, result.errors, result.warnings, shCtx))
                        {
                            if (signedArea(sHole) > 0.0)
                                std::reverse(sHole.begin(), sHole.end());
                            section.holes.push_back(sHole);
                        }
                    }
                }

                if (sVal.isMember("type_hint") && sVal["type_hint"].isString())
                    section.typeHint = sVal["type_hint"].asString();

                if (sVal.isMember("score") && sVal["score"].isNumeric())
                {
                    float sc = static_cast<float>(sVal["score"].asDouble());
                    section.score = std::clamp(sc, 0.0f, 1.0f);
                }

                // Adjacent sections
                if (sVal.isMember("adjacent_sections") && sVal["adjacent_sections"].isArray())
                {
                    for (Json::ArrayIndex aIdx = 0; aIdx < sVal["adjacent_sections"].size(); ++aIdx)
                    {
                        if (sVal["adjacent_sections"][aIdx].isString())
                            section.adjacentSections.push_back(sVal["adjacent_sections"][aIdx].asString());
                    }
                }

                // Corners
                if (sVal.isMember("corners") && sVal["corners"].isArray())
                {
                    for (Json::ArrayIndex cIdx = 0; cIdx < sVal["corners"].size(); ++cIdx)
                    {
                        const auto& cVal = sVal["corners"][cIdx];
                        if (!cVal.isObject() || !cVal.isMember("xy") || !cVal["xy"].isArray() ||
                            cVal["xy"].size() != 2 || !cVal["xy"][0].isNumeric() || !cVal["xy"][1].isNumeric())
                            continue;

                        RoofGraphCornerHint corner;
                        double cx = cVal["xy"][0].asDouble();
                        double cy = cVal["xy"][1].asDouble();
                        if (shiftFromCentre)
                        {
                            cx += 0.5;
                            cy += 0.5;
                        }
                        corner.xy = PixelPoint{cx, cy};

                        if (cVal.isMember("height_class_m") && cVal["height_class_m"].isNumeric())
                            corner.heightClassM = static_cast<float>(cVal["height_class_m"].asDouble());
                        if (cVal.isMember("score") && cVal["score"].isNumeric())
                            corner.score = std::clamp(static_cast<float>(cVal["score"].asDouble()), 0.0f, 1.0f);
                        if (cVal.isMember("corner_type") && cVal["corner_type"].isString())
                            corner.cornerType = cVal["corner_type"].asString();

                        section.corners.push_back(corner);
                    }
                }

                proposal.roofSections.push_back(std::move(section));
            }
        }

        // Validate adjacent sections reference valid IDs
        for (const auto& sec : proposal.roofSections)
        {
            for (const auto& adj : sec.adjacentSections)
            {
                if (seenSectionIds.find(adj) == seenSectionIds.end())
                {
                    result.warnings.push_back("Section '" + sec.id + "' references adjacent section '" +
                                              adj + "' which is not present in building '" + buildingId + "'.");
                }
            }
        }

        // Provenance
        if (bVal.isMember("provenance") && bVal["provenance"].isArray())
        {
            for (Json::ArrayIndex pIdx = 0; pIdx < bVal["provenance"].size(); ++pIdx)
            {
                const auto& pVal = bVal["provenance"][pIdx];
                RoofGraphProvenance prov;
                if (pVal.isObject())
                {
                    if (pVal.isMember("stage") && pVal["stage"].isString())
                        prov.stage = pVal["stage"].asString();
                    if (pVal.isMember("source") && pVal["source"].isString())
                        prov.source = pVal["source"].asString();
                    if (pVal.isMember("timestamp") && pVal["timestamp"].isString())
                        prov.timestamp = pVal["timestamp"].asString();
                    if (pVal.isMember("details"))
                    {
                        Json::FastWriter writer;
                        prov.detailsJson = writer.write(pVal["details"]);
                    }
                }
                else if (pVal.isString())
                {
                    prov.stage = "note";
                    prov.source = pVal.asString();
                }
                proposal.provenance.push_back(std::move(prov));
            }
        }

        result.sectionCount += proposal.roofSections.size();
        result.document.buildings.push_back(std::move(proposal));
    }

    result.buildingCount = result.document.buildings.size();
    result.success = result.errors.empty();
    return result;
}

HybridRoofGraphImportResult HybridRoofGraphImporter::parseJson(
    const std::string& jsonString,
    bool strictValidation)
{
    Json::Value root;
    Json::CharReaderBuilder builder;
    std::string errs;
    std::istringstream stream(jsonString);

    if (!Json::parseFromStream(builder, stream, &root, &errs))
    {
        HybridRoofGraphImportResult result;
        result.errors.push_back("Failed to parse JSON string: " + errs);
        result.success = false;
        return result;
    }

    return parse(root, strictValidation);
}

HybridRoofGraphImportResult HybridRoofGraphImporter::parseFile(
    const std::string& path,
    bool strictValidation)
{
    std::ifstream file(path);
    if (!file.is_open())
    {
        HybridRoofGraphImportResult result;
        result.errors.push_back("Failed to open file: " + path);
        result.success = false;
        return result;
    }

    Json::Value root;
    Json::CharReaderBuilder builder;
    std::string errs;

    if (!Json::parseFromStream(builder, file, &root, &errs))
    {
        HybridRoofGraphImportResult result;
        result.errors.push_back("Failed to parse JSON file " + path + ": " + errs);
        result.success = false;
        return result;
    }

    return parse(root, strictValidation);
}

Json::Value HybridRoofGraphImporter::toJson(const RoofGraphDocument& document)
{
    Json::Value root(Json::objectValue);
    root["schema"] = document.schema.empty() ? kExpectedSchema : document.schema;
    root["raster_width"] = document.rasterWidth;
    root["raster_height"] = document.rasterHeight;
    root["coordinate_convention"] = toString(document.coordinateConvention);

    if (!document.metadata.sceneId.empty() || !document.metadata.crs.empty() || document.metadata.hasGeoTransform)
    {
        Json::Value meta(Json::objectValue);
        if (!document.metadata.sceneId.empty())
            meta["scene_id"] = document.metadata.sceneId;
        if (!document.metadata.crs.empty())
            meta["crs"] = document.metadata.crs;
        if (document.metadata.hasGeoTransform)
        {
            Json::Value gt(Json::arrayValue);
            for (int k = 0; k < 6; ++k)
                gt.append(document.metadata.geoTransform[k]);
            meta["geo_transform"] = gt;
        }
        meta["gsd"] = document.metadata.gsd;
        root["metadata"] = meta;
    }

    Json::Value buildings(Json::arrayValue);
    for (const auto& b : document.buildings)
    {
        Json::Value bVal(Json::objectValue);
        bVal["id"] = b.id;

        // Footprint outer ring (OPEN, no duplicate closing vertex)
        Json::Value fp(Json::arrayValue);
        for (const auto& pt : b.footprintProposal.outerRing)
        {
            Json::Value p(Json::arrayValue);
            p.append(pt.column);
            p.append(pt.row);
            fp.append(p);
        }
        bVal["footprint_proposal"] = fp;

        // Roofprint outer ring
        Json::Value rp(Json::arrayValue);
        for (const auto& pt : b.roofprintProposal.outerRing)
        {
            Json::Value p(Json::arrayValue);
            p.append(pt.column);
            p.append(pt.row);
            rp.append(p);
        }
        bVal["roofprint_proposal"] = rp;

        // Holes
        Json::Value holes(Json::arrayValue);
        for (const auto& h : b.footprintProposal.holes)
        {
            Json::Value holeRing(Json::arrayValue);
            for (const auto& pt : h)
            {
                Json::Value p(Json::arrayValue);
                p.append(pt.column);
                p.append(pt.row);
                holeRing.append(p);
            }
            holes.append(holeRing);
        }
        bVal["holes"] = holes;

        // Scores
        Json::Value scores(Json::objectValue);
        scores["semantic"] = b.scores.semantic;
        scores["ndsm"] = b.scores.ndsm;
        scores["sam2"] = b.scores.sam2;
        scores["kibs"] = b.scores.kibs;
        if (b.scores.combined.has_value())
            scores["combined"] = *b.scores.combined;
        bVal["scores"] = scores;

        // Roof sections
        Json::Value sections(Json::arrayValue);
        for (const auto& s : b.roofSections)
        {
            Json::Value sVal(Json::objectValue);
            sVal["id"] = s.id;

            Json::Value poly(Json::arrayValue);
            for (const auto& pt : s.polygon)
            {
                Json::Value p(Json::arrayValue);
                p.append(pt.column);
                p.append(pt.row);
                poly.append(p);
            }
            sVal["polygon"] = poly;

            Json::Value sHoles(Json::arrayValue);
            for (const auto& h : s.holes)
            {
                Json::Value hRing(Json::arrayValue);
                for (const auto& pt : h)
                {
                    Json::Value p(Json::arrayValue);
                    p.append(pt.column);
                    p.append(pt.row);
                    hRing.append(p);
                }
                sHoles.append(hRing);
            }
            sVal["holes"] = sHoles;

            sVal["type_hint"] = s.typeHint;
            sVal["score"] = s.score;

            Json::Value adj(Json::arrayValue);
            for (const auto& a : s.adjacentSections)
                adj.append(a);
            sVal["adjacent_sections"] = adj;

            Json::Value corners(Json::arrayValue);
            for (const auto& c : s.corners)
            {
                Json::Value cVal(Json::objectValue);
                Json::Value xy(Json::arrayValue);
                xy.append(c.xy.column);
                xy.append(c.xy.row);
                cVal["xy"] = xy;
                if (c.heightClassM.has_value())
                    cVal["height_class_m"] = *c.heightClassM;
                else
                    cVal["height_class_m"] = Json::nullValue;
                cVal["score"] = c.score;
                cVal["corner_type"] = c.cornerType;
                corners.append(cVal);
            }
            sVal["corners"] = corners;

            sections.append(sVal);
        }
        bVal["roof_sections"] = sections;

        // Provenance
        Json::Value prov(Json::arrayValue);
        for (const auto& pr : b.provenance)
        {
            Json::Value pVal(Json::objectValue);
            pVal["stage"] = pr.stage;
            pVal["source"] = pr.source;
            if (!pr.timestamp.empty())
                pVal["timestamp"] = pr.timestamp;
            if (!pr.detailsJson.empty())
            {
                Json::CharReaderBuilder rbuilder;
                std::istringstream pStream(pr.detailsJson);
                Json::Value detailsObj;
                std::string errs;
                if (Json::parseFromStream(rbuilder, pStream, &detailsObj, &errs))
                    pVal["details"] = detailsObj;
                else
                    pVal["details"] = pr.detailsJson;
            }
            prov.append(pVal);
        }
        bVal["provenance"] = prov;

        buildings.append(bVal);
    }
    root["buildings"] = buildings;

    return root;
}

std::string HybridRoofGraphImporter::toJsonString(const RoofGraphDocument& document, bool pretty)
{
    const Json::Value val = toJson(document);
    if (pretty)
    {
        Json::StreamWriterBuilder writer;
        writer["indentation"] = "  ";
        return Json::writeString(writer, val);
    }
    else
    {
        Json::FastWriter writer;
        return writer.write(val);
    }
}

BuildingCollection HybridRoofGraphImporter::toBuildingCollection(
    const RoofGraphDocument& document,
    const SemanticScene& semantics,
    const GeoreferencedSurfaceBundle& surface,
    const SpatialMetadata& metadata,
    const BuildingReconstructionConfig& config,
    const RasterGrid<float>& reconstructionNdsm,
    std::vector<std::string>& warnings)
{
    BuildingCollection collection;
    uint32_t nextId = 1;

    for (const auto& b : document.buildings)
    {
        if (b.footprintProposal.outerRing.size() < 3)
            continue;

        BuildingInstance instance;
        instance.buildingId = nextId++;
        instance.pixelFootprint = b.footprintProposal;
        instance.projectedFootprint = projectPolygon(b.footprintProposal, metadata);

        // Estimate base elevation and height strictly from DTM and GAMUS nDSM
        const BuildingHeightEstimate estimate = BuildingHeightEstimator::estimate(
            instance.pixelFootprint, surface, semantics, metadata, config, &reconstructionNdsm);

        if (estimate.success)
        {
            instance.representativeBaseElevation = estimate.representativeBaseElevation;
            instance.heightAboveGround = estimate.heightAboveGround;
            instance.roofElevation = estimate.roofElevation;
            instance.baseElevationPerVertex = estimate.baseElevationPerOuterVertex;
        }
        else
        {
            warnings.push_back("Building '" + b.id + "': " + estimate.errorMessage);
        }

        instance.footprintAreaSquareMetres = static_cast<float>(
            std::abs(projectedRingArea(instance.projectedFootprint.outerRing)));

        collection.buildings.push_back(std::move(instance));
    }

    return collection;
}

} // namespace depthwizard