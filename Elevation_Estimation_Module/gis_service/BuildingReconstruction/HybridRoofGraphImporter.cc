#include "HybridRoofGraphImporter.h"

#include <json/reader.h>
#include <json/writer.h>
#include <ogr_geometry.h>

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <fstream>
#include <iterator>
#include <memory>
#include <set>
#include <sstream>
#include <unordered_set>
#include <utility>

namespace depthwizard
{

namespace
{

constexpr std::uintmax_t kMaxDocumentBytes = 64ULL << 20;
// Rings with less area than this (square pixels) are degenerate.
constexpr double kMinRingArea = 1.0e-9;

enum class RingRole
{
    Outer,
    Hole
};

// ---------------------------------------------------------------------------
// Ring geometry. ml_services/common/geometry.py implements the same tests with
// the same arithmetic, so both sides accept and reject the same rings.
// ---------------------------------------------------------------------------

bool samePoint(const PixelPoint& a, const PixelPoint& b)
{
    return a.column == b.column && a.row == b.row;
}

// Shoelace area on (column, row) values. Positive for outer rings and negative
// for holes in this contract; with rows growing downwards a positive ring
// appears clockwise on screen.
double signedArea(const std::vector<PixelPoint>& ring)
{
    double twiceArea = 0.0;
    for (std::size_t index = 0; index < ring.size(); ++index)
    {
        const PixelPoint& current = ring[index];
        const PixelPoint& next = ring[(index + 1) % ring.size()];
        twiceArea += current.column * next.row - next.column * current.row;
    }
    return 0.5 * twiceArea;
}

int orientation(const PixelPoint& a, const PixelPoint& b, const PixelPoint& c)
{
    const double value = (b.column - a.column) * (c.row - a.row) -
                         (b.row - a.row) * (c.column - a.column);
    return (value > 0.0) - (value < 0.0);
}

// p is collinear with a-b; true when it lies on the closed segment.
bool onSegment(const PixelPoint& a, const PixelPoint& b, const PixelPoint& p)
{
    return std::min(a.column, b.column) <= p.column && p.column <= std::max(a.column, b.column) &&
           std::min(a.row, b.row) <= p.row && p.row <= std::max(a.row, b.row);
}

// Closed segments: touching at an endpoint or overlapping counts.
bool segmentsIntersect(const PixelPoint& p1, const PixelPoint& p2,
                       const PixelPoint& p3, const PixelPoint& p4)
{
    const int d1 = orientation(p3, p4, p1);
    const int d2 = orientation(p3, p4, p2);
    const int d3 = orientation(p1, p2, p3);
    const int d4 = orientation(p1, p2, p4);
    if (d1 * d2 < 0 && d3 * d4 < 0) return true;
    return (d1 == 0 && onSegment(p3, p4, p1)) || (d2 == 0 && onSegment(p3, p4, p2)) ||
           (d3 == 0 && onSegment(p1, p2, p3)) || (d4 == 0 && onSegment(p1, p2, p4));
}

struct Edge
{
    PixelPoint a;
    PixelPoint b;
    std::size_t index;
    int ring;
    double minColumn;
    double maxColumn;
    double minRow;
    double maxRow;
};

void appendEdges(const std::vector<PixelPoint>& ring, int ringTag, std::vector<Edge>& edges)
{
    for (std::size_t index = 0; index < ring.size(); ++index)
    {
        const PixelPoint& a = ring[index];
        const PixelPoint& b = ring[(index + 1) % ring.size()];
        edges.push_back(Edge{a, b, index, ringTag,
                             std::min(a.column, b.column), std::max(a.column, b.column),
                             std::min(a.row, b.row), std::max(a.row, b.row)});
    }
}

// Calls visit(e, f) for every pair of edges whose bounding boxes overlap,
// sweeping in column order. Stops and returns true when visit returns true.
template <typename Visit>
bool anyOverlappingPair(std::vector<Edge>& edges, Visit visit)
{
    std::sort(edges.begin(), edges.end(),
              [](const Edge& left, const Edge& right) { return left.minColumn < right.minColumn; });
    for (std::size_t i = 0; i < edges.size(); ++i)
    {
        for (std::size_t j = i + 1; j < edges.size() && edges[j].minColumn <= edges[i].maxColumn; ++j)
        {
            if (edges[i].maxRow < edges[j].minRow || edges[j].maxRow < edges[i].minRow) continue;
            if (visit(edges[i], edges[j])) return true;
        }
    }
    return false;
}

// A simple ring: non-adjacent edges never touch and adjacent edges never fold
// back onto each other. Expects no repeated consecutive vertices.
bool isSimple(const std::vector<PixelPoint>& ring)
{
    const std::size_t count = ring.size();
    std::vector<Edge> edges;
    appendEdges(ring, 0, edges);
    return !anyOverlappingPair(edges, [count](const Edge& e, const Edge& f)
    {
        const std::size_t gap = e.index > f.index ? e.index - f.index : f.index - e.index;
        if (gap == 1 || gap == count - 1)
        {
            const Edge& first = (e.index + 1) % count == f.index ? e : f;
            const Edge& second = &first == &e ? f : e;
            const double dot = (first.b.column - first.a.column) * (second.b.column - second.a.column) +
                               (first.b.row - first.a.row) * (second.b.row - second.a.row);
            return orientation(first.a, first.b, second.b) == 0 && dot < 0.0;
        }
        return segmentsIntersect(e.a, e.b, f.a, f.b);
    });
}

bool boundariesTouch(const std::vector<PixelPoint>& first, const std::vector<PixelPoint>& second)
{
    std::vector<Edge> edges;
    appendEdges(first, 0, edges);
    appendEdges(second, 1, edges);
    return anyOverlappingPair(edges, [](const Edge& e, const Edge& f)
    {
        return e.ring != f.ring && segmentsIntersect(e.a, e.b, f.a, f.b);
    });
}

// Even-odd test for a point known not to lie on the ring.
bool pointInside(const std::vector<PixelPoint>& ring, const PixelPoint& point)
{
    bool inside = false;
    for (std::size_t i = 0, j = ring.size() - 1; i < ring.size(); j = i++)
    {
        const PixelPoint& a = ring[i];
        const PixelPoint& b = ring[j];
        if ((a.row > point.row) != (b.row > point.row))
        {
            const double crossing = (b.column - a.column) * (point.row - a.row) / (b.row - a.row) + a.column;
            if (point.column < crossing) inside = !inside;
        }
    }
    return inside;
}

// Checked before simplicity so that a flat ring is reported as degenerate
// while a bow-tie, whose signed area can also be zero, is a self-intersection.
bool allCollinear(const std::vector<PixelPoint>& ring)
{
    for (std::size_t index = 2; index < ring.size(); ++index)
        if (orientation(ring[0], ring[1], ring[index]) != 0) return false;
    return true;
}

std::vector<PixelPoint> withoutConsecutiveRepeats(const std::vector<PixelPoint>& ring)
{
    std::vector<PixelPoint> unique;
    for (const PixelPoint& point : ring)
        if (unique.empty() || !samePoint(unique.back(), point)) unique.push_back(point);
    while (unique.size() > 1 && samePoint(unique.front(), unique.back())) unique.pop_back();
    return unique;
}

// Replaces a non-simple ring by the exterior of the largest valid part.
bool repairWithOgr(std::vector<PixelPoint>& ring)
{
    OGRLinearRing linearRing;
    for (const PixelPoint& point : ring) linearRing.addPoint(point.column, point.row);
    linearRing.closeRings();
    OGRPolygon polygon;
    polygon.addRing(&linearRing);

    std::unique_ptr<OGRGeometry, decltype(&OGRGeometryFactory::destroyGeometry)>
        repaired(polygon.Buffer(0.0), OGRGeometryFactory::destroyGeometry);
    if (!repaired) return false;

    const OGRPolygon* largest = nullptr;
    const auto consider = [&](const OGRGeometry* geometry)
    {
        const auto* part = dynamic_cast<const OGRPolygon*>(geometry);
        if (part != nullptr && part->getExteriorRing() != nullptr &&
            (largest == nullptr || part->get_Area() > largest->get_Area()))
            largest = part;
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
    if (largest == nullptr) return false;

    const OGRLinearRing* exterior = largest->getExteriorRing();
    ring.clear();
    for (int index = 0; index < exterior->getNumPoints(); ++index)
        ring.push_back(PixelPoint{exterior->getX(index), exterior->getY(index)});
    ring = withoutConsecutiveRepeats(ring);
    return ring.size() >= 3 && std::abs(signedArea(ring)) > kMinRingArea && isSimple(ring);
}

std::string number(double value)
{
    std::ostringstream stream;
    stream.precision(17);
    stream << value;
    return stream.str();
}

std::string pointText(double column, double row)
{
    return "(" + number(column) + ", " + number(row) + ")";
}

// ---------------------------------------------------------------------------
// Document reader
// ---------------------------------------------------------------------------

class Reader
{
public:
    Reader(RoofGraphValidationMode mode, HybridRoofGraphImportResult& result)
        : repair_(mode == RoofGraphValidationMode::Repair), result_(result)
    {
    }

    void read(const Json::Value& root)
    {
        if (!readHeader(root)) return;
        if (root.isMember("metadata")) readMetadata(root["metadata"]);

        std::unordered_set<std::string> buildingIds;
        std::unordered_set<std::string> sectionIds;
        const Json::Value& buildings = root["buildings"];
        for (Json::ArrayIndex index = 0; index < buildings.size(); ++index)
        {
            BuildingProposal building;
            if (readBuilding(buildings[index], index, buildingIds, sectionIds, building))
            {
                result_.sectionCount += building.roofSections.size();
                result_.document.buildings.push_back(std::move(building));
            }
        }
        result_.buildingCount = result_.document.buildings.size();
    }

private:
    // Document-level problems fail the import in both modes.
    void fail(const std::string& code, const std::string& message)
    {
        result_.errors.push_back(code + ": " + message + ".");
    }

    // An element breaks the contract. Strict mode records an error; repair
    // mode records what the caller does about it.
    void violation(const std::string& code, const std::string& message, const std::string& action)
    {
        if (repair_)
            result_.warnings.push_back(code + ": " + message + "; " + action + ".");
        else
            result_.errors.push_back(code + ": " + message + ".");
    }

    void note(const std::string& code, const std::string& message)
    {
        result_.warnings.push_back(code + ": " + message + ".");
    }

    bool readHeader(const Json::Value& root)
    {
        if (!root.isObject())
        {
            fail("document_type", "the document must be a JSON object");
            return false;
        }
        if (!root["schema"].isString() || root["schema"].asString() != kRoofGraphSchema)
            fail("schema", std::string("'schema' must be \"") + kRoofGraphSchema + "\"");
        for (const char* key : {"raster_width", "raster_height"})
            if (!root[key].isInt() || root[key].asInt() <= 0)
                fail("raster_size", std::string("'") + key + "' must be a positive integer");
        if (!root["coordinate_convention"].isString() ||
            root["coordinate_convention"].asString() != kRoofGraphCoordinateConvention)
        {
            fail("coordinate_convention",
                 std::string("'coordinate_convention' must be \"") + kRoofGraphCoordinateConvention +
                 "\"; producers convert other conventions to pixel edges before serializing");
        }
        if (!root["buildings"].isArray())
            fail("buildings", "'buildings' must be an array");
        if (!result_.errors.empty()) return false;

        result_.document.rasterWidth = root["raster_width"].asInt();
        result_.document.rasterHeight = root["raster_height"].asInt();
        return true;
    }

    void readMetadata(const Json::Value& value)
    {
        if (value.isNull()) return;
        if (!value.isObject())
        {
            violation("metadata", "'metadata' must be an object", "ignored it");
            return;
        }
        RoofGraphSceneMetadata& metadata = result_.document.metadata;
        metadata.sceneId = readOptionalString(value, "scene_id", "metadata");
        metadata.crs = readOptionalString(value, "crs", "metadata");

        if (value.isMember("geo_transform") && !value["geo_transform"].isNull())
        {
            const Json::Value& transform = value["geo_transform"];
            std::array<double, 6> coefficients{};
            bool valid = transform.isArray() && transform.size() == 6;
            for (Json::ArrayIndex index = 0; valid && index < 6; ++index)
            {
                valid = transform[index].isNumeric() && std::isfinite(transform[index].asDouble());
                if (valid) coefficients[index] = transform[index].asDouble();
            }
            if (valid && coefficients[1] * coefficients[5] - coefficients[2] * coefficients[4] == 0.0)
                valid = false;
            if (valid)
                metadata.geoTransform = coefficients;
            else
                violation("metadata", "metadata 'geo_transform' must be 6 finite numbers with a non-zero determinant",
                          "ignored it");
        }
        if (value.isMember("gsd") && !value["gsd"].isNull())
        {
            const Json::Value& gsd = value["gsd"];
            if (gsd.isNumeric() && std::isfinite(gsd.asDouble()) && gsd.asDouble() > 0.0)
                metadata.gsd = gsd.asDouble();
            else
                violation("metadata", "metadata 'gsd' must be a finite number greater than 0", "ignored it");
        }
    }

    std::optional<std::string> readOptionalString(const Json::Value& object, const char* key,
                                                  const std::string& context)
    {
        if (!object.isMember(key) || object[key].isNull()) return std::nullopt;
        if (object[key].isString()) return object[key].asString();
        violation("field_type", context + " '" + key + "' must be a string", "ignored it");
        return std::nullopt;
    }

    std::string readString(const Json::Value& object, const char* key, const std::string& fallback,
                           const std::string& context)
    {
        if (!object.isMember(key)) return fallback;
        if (object[key].isString()) return object[key].asString();
        violation("field_type", context + " '" + key + "' must be a string", "used '" + fallback + "'");
        return fallback;
    }

    // Absent (or null when nullable) gives nullopt.
    std::optional<double> readScore(const Json::Value& object, const char* key, bool nullable,
                                    const std::string& context)
    {
        if (!object.isMember(key) || (nullable && object[key].isNull())) return std::nullopt;
        const Json::Value& value = object[key];
        const std::string name = context + " score '" + key + "'";
        if (!value.isNumeric())
        {
            violation("field_type", name + " must be a number" + (nullable ? " or null" : ""), "ignored it");
            return std::nullopt;
        }
        double score = value.asDouble();
        if (!std::isfinite(score))
        {
            violation("non_finite", name + " is not finite", "ignored it");
            return std::nullopt;
        }
        if (score < 0.0 || score > 1.0)
        {
            violation("score_range", name + " = " + number(score) + " is outside [0, 1]", "clamped it");
            score = std::clamp(score, 0.0, 1.0);
        }
        return score;
    }

    // Reads, validates and canonicalizes one ring. On failure the caller
    // applies `consequence` (e.g. drops the building), which repair mode reports.
    bool readRing(const Json::Value& value, RingRole role, const std::string& context,
                  const std::string& consequence, std::vector<PixelPoint>& ring)
    {
        ring.clear();
        if (!value.isArray())
        {
            violation("ring_type", context + " must be an array of [column, row] points", consequence);
            return false;
        }
        if (value.size() > kRoofGraphMaxRingVertices)
        {
            violation("too_many_vertices", context + " has " + std::to_string(value.size()) +
                      " vertices; the limit is " + std::to_string(kRoofGraphMaxRingVertices), consequence);
            return false;
        }

        const double width = result_.document.rasterWidth;
        const double height = result_.document.rasterHeight;
        bool clamped = false;
        for (Json::ArrayIndex index = 0; index < value.size(); ++index)
        {
            const Json::Value& point = value[index];
            if (!point.isArray() || point.size() != 2 || !point[0].isNumeric() || !point[1].isNumeric())
            {
                violation("ring_type", context + " point " + std::to_string(index) +
                          " is not a [column, row] pair of numbers", consequence);
                return false;
            }
            double column = point[0].asDouble();
            double row = point[1].asDouble();
            if (!std::isfinite(column) || !std::isfinite(row))
            {
                violation("non_finite", context + " point " + std::to_string(index) + " is not finite",
                          consequence);
                return false;
            }
            if (column < 0.0 || column > width || row < 0.0 || row > height)
            {
                if (!repair_)
                {
                    violation("out_of_bounds", context + " point " + pointText(column, row) +
                              " is outside [0, " + number(width) + "] x [0, " + number(height) + "]", "");
                    return false;
                }
                column = std::clamp(column, 0.0, width);
                row = std::clamp(row, 0.0, height);
                clamped = true;
            }
            ring.push_back(PixelPoint{column, row});
        }
        if (clamped)
            violation("out_of_bounds", context + " has points outside the raster", "clamped them to the raster");

        if (ring.size() >= 2 && samePoint(ring.front(), ring.back()))
        {
            violation("closing_vertex", context + " repeats its first vertex at the end; rings must be open",
                      "removed the closing vertex");
            if (!repair_) return false;
            ring.pop_back();
        }
        const std::vector<PixelPoint> unique = withoutConsecutiveRepeats(ring);
        if (unique.size() != ring.size())
        {
            violation("repeated_vertex", context + " repeats consecutive vertices", "removed the repeats");
            if (!repair_) return false;
            ring = unique;
        }

        std::set<std::pair<double, double>> distinct;
        for (const PixelPoint& point : ring) distinct.emplace(point.column, point.row);
        if (distinct.size() < 3)
        {
            violation("too_few_vertices", context + " has " + std::to_string(distinct.size()) +
                      " distinct vertices; at least 3 are required", consequence);
            return false;
        }
        if (allCollinear(ring))
        {
            violation("degenerate_ring", context + " has zero area", consequence);
            return false;
        }
        if (!isSimple(ring))
        {
            violation("self_intersection", context + " is not simple (its edges cross or touch)",
                      "replaced it by its largest valid part");
            if (!repair_) return false;
            if (!repairWithOgr(ring))
            {
                note("self_intersection", context + " could not be repaired; " + consequence);
                return false;
            }
        }

        if (std::abs(signedArea(ring)) <= kMinRingArea)
        {
            violation("degenerate_ring", context + " has zero area", consequence);
            return false;
        }

        const bool positive = signedArea(ring) > 0.0;
        if (positive != (role == RingRole::Outer))
        {
            std::reverse(ring.begin(), ring.end());
            note("winding", context + " was reversed to the contract winding (" +
                 (role == RingRole::Outer ? "positive" : "negative") + " image-space area)");
        }
        return true;
    }

    // Holes must lie strictly inside the outer ring and be disjoint.
    std::vector<std::vector<PixelPoint>> readHoles(const Json::Value& object,
                                                   const std::vector<PixelPoint>& outer,
                                                   const std::string& context)
    {
        std::vector<std::vector<PixelPoint>> holes;
        if (!object.isMember("holes")) return holes;
        const Json::Value& values = object["holes"];
        if (!values.isArray())
        {
            violation("field_type", context + " 'holes' must be an array of rings", "ignored it");
            return holes;
        }
        for (Json::ArrayIndex index = 0; index < values.size(); ++index)
        {
            const std::string holeContext = context + " hole " + std::to_string(index);
            std::vector<PixelPoint> hole;
            if (!readRing(values[index], RingRole::Hole, holeContext, "dropped the hole", hole)) continue;

            bool valid = !boundariesTouch(outer, hole) && pointInside(outer, hole.front());
            for (const auto& other : holes)
            {
                valid = valid && !boundariesTouch(other, hole) &&
                        !pointInside(other, hole.front()) && !pointInside(hole, other.front());
            }
            if (!valid)
            {
                violation("invalid_hole", holeContext +
                          " must lie strictly inside its outer ring without touching it or another hole",
                          "dropped the hole");
                continue;
            }
            holes.push_back(std::move(hole));
        }
        return holes;
    }

    bool readCorner(const Json::Value& value, const std::string& context, RoofGraphCornerHint& corner)
    {
        const Json::Value& xy = value["xy"];
        if (!value.isObject() || !xy.isArray() || xy.size() != 2 || !xy[0].isNumeric() || !xy[1].isNumeric())
        {
            violation("field_type", context + " must be an object with 'xy': [column, row]", "dropped the corner");
            return false;
        }
        const double column = xy[0].asDouble();
        const double row = xy[1].asDouble();
        if (!std::isfinite(column) || !std::isfinite(row))
        {
            violation("non_finite", context + " 'xy' is not finite", "dropped the corner");
            return false;
        }
        if (column < 0.0 || column > result_.document.rasterWidth ||
            row < 0.0 || row > result_.document.rasterHeight)
        {
            violation("out_of_bounds", context + " 'xy' " + pointText(column, row) + " is outside the raster",
                      "dropped the corner");
            return false;
        }
        corner.xy = PixelPoint{column, row};

        if (value.isMember("height_class_m") && !value["height_class_m"].isNull())
        {
            const Json::Value& hint = value["height_class_m"];
            if (!hint.isNumeric())
                violation("height_hint", context + " 'height_class_m' must be a number or null", "ignored the hint");
            else if (!std::isfinite(hint.asDouble()))
                violation("non_finite", context + " 'height_class_m' is not finite", "ignored the hint");
            else if (hint.asDouble() < 0.0)
                violation("height_hint", context + " 'height_class_m' must not be negative", "ignored the hint");
            else
                corner.heightClassHintMetres = hint.asDouble();
        }
        corner.score = readScore(value, "score", false, context).value_or(0.0);
        corner.cornerType = readString(value, "corner_type", "unknown", context);
        return true;
    }

    bool readSection(const Json::Value& value, const std::string& context,
                     std::unordered_set<std::string>& sectionIds, RoofSectionProposal& section)
    {
        if (!value.isObject())
        {
            violation("field_type", context + " must be an object", "dropped the section");
            return false;
        }
        if (!value["id"].isString() || value["id"].asString().empty())
        {
            violation("missing_id", context + " needs a non-empty string 'id'", "dropped the section");
            return false;
        }
        section.id = value["id"].asString();
        const std::string sectionContext = context + " '" + section.id + "'";
        if (sectionIds.count(section.id) != 0)
        {
            violation("duplicate_id", "section id '" + section.id + "' is used more than once in the document",
                      "dropped the repeat");
            return false;
        }

        if (!value.isMember("polygon"))
        {
            violation("ring_type", sectionContext + " 'polygon' is required", "dropped the section");
            return false;
        }
        if (!readRing(value["polygon"], RingRole::Outer, sectionContext + " polygon", "dropped the section",
                      section.polygon))
            return false;
        sectionIds.insert(section.id);

        section.holes = readHoles(value, section.polygon, sectionContext);
        if (value.isMember("corners"))
        {
            const Json::Value& corners = value["corners"];
            if (!corners.isArray())
            {
                violation("field_type", sectionContext + " 'corners' must be an array", "ignored it");
            }
            else
            {
                for (Json::ArrayIndex index = 0; index < corners.size(); ++index)
                {
                    RoofGraphCornerHint corner;
                    if (readCorner(corners[index], sectionContext + " corner " + std::to_string(index), corner))
                        section.corners.push_back(std::move(corner));
                }
            }
        }
        section.typeHint = readString(value, "type_hint", "unknown", sectionContext);
        if (value.isMember("adjacent_sections"))
        {
            const Json::Value& adjacent = value["adjacent_sections"];
            if (!adjacent.isArray())
            {
                violation("field_type", sectionContext + " 'adjacent_sections' must be an array of ids", "ignored it");
            }
            else
            {
                for (const Json::Value& id : adjacent)
                {
                    if (id.isString() && !id.asString().empty())
                        section.adjacentSections.push_back(id.asString());
                    else
                        violation("field_type", sectionContext + " 'adjacent_sections' entries must be non-empty strings",
                                  "dropped the entry");
                }
            }
        }
        section.score = readScore(value, "score", false, sectionContext).value_or(0.0);
        return true;
    }

    // Adjacency may only name other sections of the same building, once each.
    void validateAdjacency(BuildingProposal& building, const std::string& context)
    {
        std::unordered_set<std::string> ids;
        for (const RoofSectionProposal& section : building.roofSections) ids.insert(section.id);
        for (RoofSectionProposal& section : building.roofSections)
        {
            std::vector<std::string> kept;
            for (const std::string& id : section.adjacentSections)
            {
                std::string problem;
                if (id == section.id)
                    problem = "lists itself as adjacent";
                else if (ids.count(id) == 0)
                    problem = "references '" + id + "', which is not a section of this building";
                else if (std::find(kept.begin(), kept.end(), id) != kept.end())
                    problem = "lists '" + id + "' more than once";
                if (problem.empty())
                    kept.push_back(id);
                else
                    violation("adjacency", context + " section '" + section.id + "' " + problem, "dropped the entry");
            }
            section.adjacentSections = std::move(kept);
        }
    }

    void readProvenance(const Json::Value& values, const std::string& context, BuildingProposal& building)
    {
        if (!values.isArray())
        {
            violation("field_type", context + " 'provenance' must be an array of objects", "ignored it");
            return;
        }
        for (Json::ArrayIndex index = 0; index < values.size(); ++index)
        {
            const Json::Value& value = values[index];
            const std::string entryContext = context + " provenance " + std::to_string(index);
            if (!value.isObject() || !value["stage"].isString() || value["stage"].asString().empty() ||
                !value["source"].isString() || value["source"].asString().empty())
            {
                violation("provenance", entryContext + " must be an object with non-empty 'stage' and 'source'",
                          "dropped the entry");
                continue;
            }
            RoofGraphProvenance entry;
            entry.stage = value["stage"].asString();
            entry.source = value["source"].asString();
            entry.timestamp = readOptionalString(value, "timestamp", entryContext);
            if (value.isMember("details")) entry.details = value["details"];
            building.provenance.push_back(std::move(entry));
        }
    }

    bool readBuilding(const Json::Value& value, Json::ArrayIndex index,
                      std::unordered_set<std::string>& buildingIds,
                      std::unordered_set<std::string>& sectionIds,
                      BuildingProposal& building)
    {
        const std::string position = "building " + std::to_string(index);
        if (!value.isObject())
        {
            violation("field_type", position + " must be an object", "dropped the building");
            return false;
        }
        if (!value["id"].isString() || value["id"].asString().empty())
        {
            violation("missing_id", position + " needs a non-empty string 'id'", "dropped the building");
            return false;
        }
        building.id = value["id"].asString();
        const std::string context = "building '" + building.id + "'";
        if (!buildingIds.insert(building.id).second)
        {
            violation("duplicate_id", "building id '" + building.id + "' is used more than once",
                      "dropped the repeat");
            return false;
        }

        if (!value.isMember("footprint_proposal"))
        {
            violation("ring_type", context + " 'footprint_proposal' is required", "dropped the building");
            return false;
        }
        if (!readRing(value["footprint_proposal"], RingRole::Outer, context + " footprint_proposal",
                      "dropped the building", building.footprintProposal.outerRing))
            return false;
        building.footprintProposal.holes = readHoles(value, building.footprintProposal.outerRing, context);

        const Json::Value& roofprint = value["roofprint_proposal"];
        if (!roofprint.isNull() && !(roofprint.isArray() && roofprint.empty()))
        {
            std::vector<PixelPoint> ring;
            if (readRing(roofprint, RingRole::Outer, context + " roofprint_proposal", "ignored the roofprint", ring))
                building.roofprintProposal = std::move(ring);
        }

        if (value.isMember("scores"))
        {
            const Json::Value& scores = value["scores"];
            if (!scores.isObject())
            {
                violation("field_type", context + " 'scores' must be an object", "used default scores");
            }
            else
            {
                building.scores.semantic = readScore(scores, "semantic", false, context).value_or(0.0);
                building.scores.ndsm = readScore(scores, "ndsm", false, context).value_or(0.0);
                building.scores.sam2 = readScore(scores, "sam2", true, context);
                building.scores.kibs = readScore(scores, "kibs", true, context);
                building.scores.combined = readScore(scores, "combined", true, context);
            }
        }

        if (value.isMember("roof_sections"))
        {
            const Json::Value& sections = value["roof_sections"];
            if (!sections.isArray())
            {
                violation("field_type", context + " 'roof_sections' must be an array", "ignored it");
            }
            else
            {
                for (Json::ArrayIndex sectionIndex = 0; sectionIndex < sections.size(); ++sectionIndex)
                {
                    RoofSectionProposal section;
                    if (readSection(sections[sectionIndex], context + " section " + std::to_string(sectionIndex),
                                    sectionIds, section))
                        building.roofSections.push_back(std::move(section));
                }
            }
        }
        validateAdjacency(building, context);

        if (value.isMember("provenance")) readProvenance(value["provenance"], context, building);
        return true;
    }

    bool repair_;
    HybridRoofGraphImportResult& result_;
};

Json::Value ringJson(const std::vector<PixelPoint>& ring)
{
    Json::Value points(Json::arrayValue);
    for (const PixelPoint& point : ring)
    {
        Json::Value pair(Json::arrayValue);
        pair.append(point.column);
        pair.append(point.row);
        points.append(pair);
    }
    return points;
}

Json::Value ringsJson(const std::vector<std::vector<PixelPoint>>& rings)
{
    Json::Value values(Json::arrayValue);
    for (const auto& ring : rings) values.append(ringJson(ring));
    return values;
}

HybridRoofGraphImportResult failure(const std::string& code, const std::string& message)
{
    HybridRoofGraphImportResult result;
    result.errors.push_back(code + ": " + message + ".");
    return result;
}

} // namespace

HybridRoofGraphImportResult HybridRoofGraphImporter::parse(
    const Json::Value& document,
    RoofGraphValidationMode mode)
{
    HybridRoofGraphImportResult result;
    try
    {
        Reader(mode, result).read(document);
    }
    catch (const std::exception& error)
    {
        result = failure("internal", std::string("unexpected parser failure: ") + error.what());
    }
    result.success = result.errors.empty();
    if (!result.success)
    {
        result.document.buildings.clear();
        result.buildingCount = 0;
        result.sectionCount = 0;
    }
    return result;
}

HybridRoofGraphImportResult HybridRoofGraphImporter::parseJson(
    const std::string& json,
    RoofGraphValidationMode mode)
{
    if (json.size() > kMaxDocumentBytes)
        return failure("document_too_large", "the document exceeds " + std::to_string(kMaxDocumentBytes) + " bytes");

    // Strict mode: no comments, NaN/Infinity tokens, duplicate keys or trailing data.
    Json::CharReaderBuilder builder;
    Json::CharReaderBuilder::strictMode(&builder.settings_);
    const std::unique_ptr<Json::CharReader> reader(builder.newCharReader());
    Json::Value root;
    std::string errors;
    if (!reader->parse(json.data(), json.data() + json.size(), &root, &errors))
        return failure("json_syntax", "invalid JSON: " + errors);
    return parse(root, mode);
}

HybridRoofGraphImportResult HybridRoofGraphImporter::parseFile(
    const std::string& path,
    RoofGraphValidationMode mode)
{
    std::ifstream file(path, std::ios::binary | std::ios::ate);
    if (!file) return failure("io", "cannot open " + path);
    const std::streamoff size = file.tellg();
    if (size < 0) return failure("io", "cannot read " + path);
    if (static_cast<std::uintmax_t>(size) > kMaxDocumentBytes)
        return failure("document_too_large", path + " exceeds " + std::to_string(kMaxDocumentBytes) + " bytes");
    file.seekg(0);
    std::string contents(static_cast<std::size_t>(size), '\0');
    if (!file.read(contents.data(), size)) return failure("io", "cannot read " + path);
    return parseJson(contents, mode);
}

Json::Value HybridRoofGraphImporter::toJson(const RoofGraphDocument& document)
{
    Json::Value root(Json::objectValue);
    root["schema"] = kRoofGraphSchema;
    root["raster_width"] = document.rasterWidth;
    root["raster_height"] = document.rasterHeight;
    root["coordinate_convention"] = kRoofGraphCoordinateConvention;

    const RoofGraphSceneMetadata& metadata = document.metadata;
    if (!metadata.empty())
    {
        Json::Value value(Json::objectValue);
        if (metadata.sceneId) value["scene_id"] = *metadata.sceneId;
        if (metadata.crs) value["crs"] = *metadata.crs;
        if (metadata.geoTransform)
        {
            Json::Value transform(Json::arrayValue);
            for (double coefficient : *metadata.geoTransform) transform.append(coefficient);
            value["geo_transform"] = transform;
        }
        if (metadata.gsd) value["gsd"] = *metadata.gsd;
        root["metadata"] = value;
    }

    Json::Value buildings(Json::arrayValue);
    for (const BuildingProposal& building : document.buildings)
    {
        Json::Value value(Json::objectValue);
        value["id"] = building.id;
        value["footprint_proposal"] = ringJson(building.footprintProposal.outerRing);
        if (building.roofprintProposal) value["roofprint_proposal"] = ringJson(*building.roofprintProposal);
        value["holes"] = ringsJson(building.footprintProposal.holes);

        Json::Value scores(Json::objectValue);
        scores["semantic"] = building.scores.semantic;
        scores["ndsm"] = building.scores.ndsm;
        if (building.scores.sam2) scores["sam2"] = *building.scores.sam2;
        if (building.scores.kibs) scores["kibs"] = *building.scores.kibs;
        if (building.scores.combined) scores["combined"] = *building.scores.combined;
        value["scores"] = scores;

        Json::Value sections(Json::arrayValue);
        for (const RoofSectionProposal& section : building.roofSections)
        {
            Json::Value sectionValue(Json::objectValue);
            sectionValue["id"] = section.id;
            sectionValue["polygon"] = ringJson(section.polygon);
            sectionValue["holes"] = ringsJson(section.holes);
            Json::Value corners(Json::arrayValue);
            for (const RoofGraphCornerHint& corner : section.corners)
            {
                Json::Value cornerValue(Json::objectValue);
                Json::Value xy(Json::arrayValue);
                xy.append(corner.xy.column);
                xy.append(corner.xy.row);
                cornerValue["xy"] = xy;
                if (corner.heightClassHintMetres) cornerValue["height_class_m"] = *corner.heightClassHintMetres;
                cornerValue["score"] = corner.score;
                cornerValue["corner_type"] = corner.cornerType;
                corners.append(cornerValue);
            }
            sectionValue["corners"] = corners;
            sectionValue["type_hint"] = section.typeHint;
            Json::Value adjacent(Json::arrayValue);
            for (const std::string& id : section.adjacentSections) adjacent.append(id);
            sectionValue["adjacent_sections"] = adjacent;
            sectionValue["score"] = section.score;
            sections.append(sectionValue);
        }
        value["roof_sections"] = sections;

        Json::Value provenance(Json::arrayValue);
        for (const RoofGraphProvenance& entry : building.provenance)
        {
            Json::Value entryValue(Json::objectValue);
            entryValue["stage"] = entry.stage;
            entryValue["source"] = entry.source;
            if (entry.timestamp) entryValue["timestamp"] = *entry.timestamp;
            if (!entry.details.isNull()) entryValue["details"] = entry.details;
            provenance.append(entryValue);
        }
        value["provenance"] = provenance;
        buildings.append(value);
    }
    root["buildings"] = buildings;
    return root;
}

std::string HybridRoofGraphImporter::toJsonString(const RoofGraphDocument& document, bool pretty)
{
    Json::StreamWriterBuilder writer;
    writer["indentation"] = pretty ? "  " : "";
    writer["emitUTF8"] = true;
    return Json::writeString(writer, toJson(document));
}

ProjectedPoint HybridRoofGraphImporter::toProjected(const PixelPoint& pixel, const SpatialMetadata& metadata)
{
    const auto& gt = metadata.geoTransform;
    return ProjectedPoint{
        gt[0] + pixel.column * gt[1] + pixel.row * gt[2],
        gt[3] + pixel.column * gt[4] + pixel.row * gt[5]};
}

FootprintPolygon<ProjectedPoint> HybridRoofGraphImporter::projectPolygon(
    const FootprintPolygon<PixelPoint>& pixelPolygon,
    const SpatialMetadata& metadata)
{
    const auto projectRing = [&](const std::vector<PixelPoint>& ring, bool counterClockwise)
    {
        std::vector<ProjectedPoint> projected;
        projected.reserve(ring.size());
        double twiceArea = 0.0;
        for (const PixelPoint& point : ring) projected.push_back(toProjected(point, metadata));
        for (std::size_t index = 0; index < projected.size(); ++index)
        {
            const ProjectedPoint& current = projected[index];
            const ProjectedPoint& next = projected[(index + 1) % projected.size()];
            twiceArea += current.easting * next.northing - next.easting * current.northing;
        }
        if ((twiceArea > 0.0) != counterClockwise) std::reverse(projected.begin(), projected.end());
        return projected;
    };

    FootprintPolygon<ProjectedPoint> projected;
    projected.outerRing = projectRing(pixelPolygon.outerRing, true);
    for (const auto& hole : pixelPolygon.holes) projected.holes.push_back(projectRing(hole, false));
    return projected;
}

} // namespace depthwizard
