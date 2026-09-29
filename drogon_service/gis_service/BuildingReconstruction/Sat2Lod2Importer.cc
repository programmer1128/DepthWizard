#include "Sat2Lod2Importer.h"
#include "BuildingHeightEstimator.h"
#include "FootprintGeometryRegularizer.h"

#include <json/reader.h>
#include <ogr_geometry.h>
#include <opencv2/imgproc.hpp>

#include <algorithm>
#include <cmath>
#include <fstream>
#include <limits>
#include <memory>
#include <numeric>
#include <optional>

namespace
{
constexpr const char* kSchemaId = "depthwizard.sat2lod2.v1";

ProjectedPoint toProjected(const PixelPoint& pixel, const SpatialMetadata& metadata)
{
     const auto& gt = metadata.geoTransform;
     return ProjectedPoint{
         gt[0] + pixel.column * gt[1] + pixel.row * gt[2],
         gt[3] + pixel.column * gt[4] + pixel.row * gt[5]};
}

double pixelAreaSquareMetres(const SpatialMetadata& metadata)
{
     const auto& gt = metadata.geoTransform;
     return std::abs(gt[1] * gt[5] - gt[2] * gt[4]);
}

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

// SAT2LoD2 reports (column, row) indices of pixel centres. Native footprints
// use GDAL pixel-edge coordinates, where the centre of pixel i lies at i + 0.5.
bool readRing(const Json::Value& value, int width, int height,
              std::vector<PixelPoint>& ring)
{
     ring.clear();
     if (!value.isArray()) return false;
     for (const Json::Value& point : value)
     {
         if (!point.isArray() || point.size() != 2 ||
             !point[0].isNumeric() || !point[1].isNumeric())
             return false;
         const double column = point[0].asDouble() + 0.5;
         const double row = point[1].asDouble() + 0.5;
         if (!std::isfinite(column) || !std::isfinite(row)) return false;
         ring.push_back(PixelPoint{
             std::clamp(column, 0.0, static_cast<double>(width)),
             std::clamp(row, 0.0, static_cast<double>(height))});
     }
     return ring.size() >= 3;
}

// Drops repeated and collinear vertices so every wall is a real facade.
void removeRedundantVertices(std::vector<PixelPoint>& ring)
{
     bool changed = true;
     while (changed && ring.size() > 3)
     {
         changed = false;
         for (std::size_t index = 0; index < ring.size(); ++index)
         {
             const PixelPoint& previous = ring[(index + ring.size() - 1) % ring.size()];
             const PixelPoint& current = ring[index];
             const PixelPoint& next = ring[(index + 1) % ring.size()];
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

// Regularized polygons can occasionally self-touch. Repair them with a zero
// buffer and keep the largest part so triangulation cannot silently fail.
bool makeSimpleRing(std::vector<PixelPoint>& ring)
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

// Orders a pixel ring so that its projected ring is counter-clockwise, the
// FootprintPolygon invariant, and returns the matching projected ring.
std::vector<ProjectedPoint> orientAndProject(std::vector<PixelPoint>& ring,
                                             const SpatialMetadata& metadata)
{
     const auto& gt = metadata.geoTransform;
     const double determinant = gt[1] * gt[5] - gt[2] * gt[4];
     if (signedArea(ring) * determinant < 0.0)
         std::reverse(ring.begin(), ring.end());
     std::vector<ProjectedPoint> projected;
     projected.reserve(ring.size());
     for (const PixelPoint& point : ring)
         projected.push_back(toProjected(point, metadata));
     return projected;
}

PixelPoint toPixel(const ProjectedPoint& point, const SpatialMetadata& metadata)
{
     const auto& gt = metadata.geoTransform;
     const double determinant = gt[1] * gt[5] - gt[2] * gt[4];
     const double easting = point.easting - gt[0];
     const double northing = point.northing - gt[3];
     return PixelPoint{(gt[5] * easting - gt[2] * northing) / determinant,
                       (-gt[4] * easting + gt[1] * northing) / determinant};
}

// Length-weighted dominant wall direction, modulo 90 degrees.
std::optional<double> dominantOrientation(
     const std::vector<std::vector<ProjectedPoint>>& rings)
{
     double sine = 0.0;
     double cosine = 0.0;
     for (const auto& ring : rings)
         for (std::size_t index = 0; index < ring.size(); ++index)
         {
             const ProjectedPoint& a = ring[index];
             const ProjectedPoint& b = ring[(index + 1) % ring.size()];
             const double dx = b.easting - a.easting;
             const double dy = b.northing - a.northing;
             const double length = std::hypot(dx, dy);
             if (length < 2.0) continue;
             sine += length * std::sin(4.0 * std::atan2(dy, dx));
             cosine += length * std::cos(4.0 * std::atan2(dy, dx));
         }
     if (std::hypot(sine, cosine) < 1.0e-6) return std::nullopt;
     return 0.25 * std::atan2(sine, cosine);
}

double intersectionOverUnion(const std::vector<ProjectedPoint>& a,
                             const std::vector<ProjectedPoint>& b)
{
     const ProjectedPoint origin = a.front();
     const auto toPolygon = [&](const std::vector<ProjectedPoint>& ring)
     {
         OGRLinearRing linearRing;
         for (const ProjectedPoint& point : ring)
             linearRing.addPoint(point.easting - origin.easting,
                                 point.northing - origin.northing);
         linearRing.closeRings();
         OGRPolygon polygon;
         polygon.addRing(&linearRing);
         return polygon;
     };
     const OGRPolygon first = toPolygon(a);
     const OGRPolygon second = toPolygon(b);
     if (!first.IsValid() || !second.IsValid()) return 0.0;
     using GeometryPtr = std::unique_ptr<OGRGeometry, decltype(&OGRGeometryFactory::destroyGeometry)>;
     GeometryPtr intersection(first.Intersection(&second), OGRGeometryFactory::destroyGeometry);
     GeometryPtr joined(first.Union(&second), OGRGeometryFactory::destroyGeometry);
     const auto area = [](const OGRGeometry* geometry)
     {
         const auto* surface = dynamic_cast<const OGRSurface*>(geometry);
         if (surface != nullptr) return surface->get_Area();
         const auto* collection = dynamic_cast<const OGRGeometryCollection*>(geometry);
         return collection != nullptr ? collection->get_Area() : 0.0;
     };
     const double unionArea = joined ? area(joined.get()) : 0.0;
     return unionArea > 0.0 && intersection ? area(intersection.get()) / unionArea : 0.0;
}

// Snaps a footprint to a rectilinear outline aligned with theta: every wall
// becomes parallel or perpendicular to the dominant facade, collinear runs
// merge, and jogs shorter than minEdgeMetres are removed. Returns an empty
// ring when the building is not credibly rectilinear.
std::vector<ProjectedPoint> snapToManhattan(const std::vector<ProjectedPoint>& ring,
                                            double theta, double minEdgeMetres,
                                            double minIoU)
{
     if (ring.size() < 4 || minEdgeMetres <= 0.0) return {};
     const ProjectedPoint origin = ring.front();
     const double c = std::cos(theta);
     const double s = std::sin(theta);

     // Rotate so the dominant facade runs along local x. Coordinates are
     // relative to the ring, so float precision (approxPolyDP) is ample.
     std::vector<cv::Point2f> local;
     local.reserve(ring.size());
     for (const ProjectedPoint& point : ring)
     {
         const double x = point.easting - origin.easting;
         const double y = point.northing - origin.northing;
         local.emplace_back(static_cast<float>(x * c + y * s),
                            static_cast<float>(-x * s + y * c));
     }
     std::vector<cv::Point2f> simplified;
     cv::approxPolyDP(local, simplified, std::min(1.0, 0.5 * minEdgeMetres), true);
     if (simplified.size() < 4) return {};

     // Each wall is a horizontal (y = coordinate) or vertical (x = coordinate)
     // line; weight is the contour length that supports it.
     struct Wall { bool horizontal; double coordinate; double weight; };
     const auto mergeInto = [](Wall& target, const Wall& other)
     {
         target.coordinate = (target.coordinate * target.weight +
                              other.coordinate * other.weight) /
                             (target.weight + other.weight);
         target.weight += other.weight;
     };
     std::vector<Wall> walls;
     for (std::size_t index = 0; index < simplified.size(); ++index)
     {
         const cv::Point2d a = simplified[index];
         const cv::Point2d b = simplified[(index + 1) % simplified.size()];
         const double length = std::hypot(b.x - a.x, b.y - a.y);
         if (length < 1.0e-9) continue;
         const bool horizontal = std::abs(b.x - a.x) >= std::abs(b.y - a.y);
         const Wall wall{horizontal, horizontal ? 0.5 * (a.y + b.y) : 0.5 * (a.x + b.x), length};
         if (!walls.empty() && walls.back().horizontal == horizontal)
             mergeInto(walls.back(), wall);
         else
             walls.push_back(wall);
     }
     if (walls.size() > 1 && walls.front().horizontal == walls.back().horizontal)
     {
         mergeInto(walls.front(), walls.back());
         walls.pop_back();
     }
     if (walls.size() < 4 || walls.size() % 2 != 0) return {};

     // Corner i joins wall i to wall i + 1, so wall i runs from corner i - 1.
     const auto corners = [&]()
     {
         std::vector<cv::Point2d> points;
         for (std::size_t index = 0; index < walls.size(); ++index)
         {
             const Wall& wall = walls[index];
             const Wall& next = walls[(index + 1) % walls.size()];
             points.push_back(wall.horizontal ? cv::Point2d{next.coordinate, wall.coordinate}
                                              : cv::Point2d{wall.coordinate, next.coordinate});
         }
         return points;
     };

     while (walls.size() > 4)
     {
         const std::vector<cv::Point2d> points = corners();
         std::size_t shortest = 0;
         double shortestLength = std::numeric_limits<double>::infinity();
         for (std::size_t index = 0; index < walls.size(); ++index)
         {
             const cv::Point2d& start = points[(index + walls.size() - 1) % walls.size()];
             const double length = std::hypot(points[index].x - start.x, points[index].y - start.y);
             if (length < shortestLength)
             {
                 shortestLength = length;
                 shortest = index;
             }
         }
         if (shortestLength >= minEdgeMetres) break;

         // Removing a short wall joins its two neighbours, which share an axis.
         const std::size_t previous = (shortest + walls.size() - 1) % walls.size();
         const std::size_t next = (shortest + 1) % walls.size();
         Wall joined = walls[previous];
         mergeInto(joined, walls[next]);
         std::vector<Wall> remaining;
         for (std::size_t index = 0; index < walls.size(); ++index)
         {
             if (index == shortest || index == next) continue;
             remaining.push_back(index == previous ? joined : walls[index]);
         }
         walls = std::move(remaining);
     }

     std::vector<ProjectedPoint> result;
     for (const cv::Point2d& point : corners())
         result.push_back(ProjectedPoint{origin.easting + point.x * c - point.y * s,
                                         origin.northing + point.x * s + point.y * c});
     if (intersectionOverUnion(ring, result) < minIoU) return {};
     return result;
}

// The semantic mask gives SAT2LoD2 wobbly outlines. Snap them to a crisp
// rectilinear outline when the building supports it, otherwise simplify and
// let CGAL align edges to shared directions. Each step falls back to the
// previous ring if it would distort the shape.
void regularizeFootprint(std::vector<PixelPoint>& ring,
                         const SpatialMetadata& metadata,
                         const BuildingReconstructionConfig& config,
                         std::optional<double> orientation)
{
     FootprintPolygon<ProjectedPoint> projected;
     projected.outerRing = orientAndProject(ring, metadata);

     if (!orientation)
         orientation = dominantOrientation({projected.outerRing});
     if (orientation)
     {
         std::vector<PixelPoint> candidate;
         for (const ProjectedPoint& point : snapToManhattan(
                  projected.outerRing, *orientation,
                  config.sat2lod2MinFootprintEdgeMetres,
                  config.minimumFootprintMaskIoU))
             candidate.push_back(toPixel(point, metadata));
         if (candidate.size() >= 4 && makeSimpleRing(candidate))
         {
             ring = std::move(candidate);
             return;
         }
     }

     const FootprintPolygon<ProjectedPoint> simplified =
         FootprintGeometryRegularizer::simplifyPolygonWithGeos(
             projected, std::max(1.0, static_cast<double>(
                 config.footprintSimplificationToleranceMetres)));
     std::vector<ProjectedPoint> best = simplified.outerRing.size() >= 3
         ? simplified.outerRing
         : projected.outerRing;

     std::vector<ProjectedPoint> regular =
         FootprintGeometryRegularizer::regularizeContourWithCgal(
             best, config.maxCornerAdjustmentMetres,
             config.footprintAreaDeviationTolerance);
     if (regular.size() >= 3)
     {
         std::vector<PixelPoint> candidate;
         for (const ProjectedPoint& point : regular)
             candidate.push_back(toPixel(point, metadata));
         if (makeSimpleRing(candidate))
         {
             ring = std::move(candidate);
             return;
         }
     }

     std::vector<PixelPoint> candidate;
     for (const ProjectedPoint& point : best)
         candidate.push_back(toPixel(point, metadata));
     if (makeSimpleRing(candidate))
         ring = std::move(candidate);
}

std::vector<cv::Point> toCvRing(const std::vector<PixelPoint>& ring, int offsetX, int offsetY)
{
     std::vector<cv::Point> points;
     points.reserve(ring.size());
     for (const PixelPoint& point : ring)
         points.emplace_back(static_cast<int>(std::lround(point.column)) - offsetX,
                             static_cast<int>(std::lround(point.row)) - offsetY);
     return points;
}

// Fraction of a footprint's pixels the semantic model labels BUILDING.
double buildingClassFraction(const FootprintPolygon<PixelPoint>& footprint,
                             const SemanticScene& semantics,
                             const SpatialMetadata& metadata)
{
     if (!semantics.finalClassMap.isValid() || footprint.outerRing.size() < 3) return 0.0;
     cv::Mat mask(metadata.height, metadata.width, CV_8UC1, cv::Scalar(0));
     cv::fillPoly(mask, std::vector<std::vector<cv::Point>>{toCvRing(footprint.outerRing, 0, 0)},
                  cv::Scalar(1));
     for (const auto& hole : footprint.holes)
         cv::fillPoly(mask, std::vector<std::vector<cv::Point>>{toCvRing(hole, 0, 0)},
                      cv::Scalar(0));
     std::size_t inside = 0, building = 0;
     for (int row = 0; row < mask.rows; ++row)
         for (int column = 0; column < mask.cols; ++column)
             if (mask.at<uint8_t>(row, column) != 0)
             {
                 ++inside;
                 building += semantics.finalClassMap.data[
                     static_cast<std::size_t>(row) * metadata.width + column] ==
                     SemanticClass::BUILDING;
             }
     return inside == 0 ? 0.0 : static_cast<double>(building) / inside;
}

float meanBuildingProbability(const std::vector<PixelPoint>& ring,
                              const SemanticScene& semantics,
                              const SpatialMetadata& metadata)
{
     if (!semantics.buildingProbability.isValid()) return 0.0f;
     double minColumn = metadata.width, minRow = metadata.height, maxColumn = 0.0, maxRow = 0.0;
     for (const PixelPoint& point : ring)
     {
         minColumn = std::min(minColumn, point.column);
         minRow = std::min(minRow, point.row);
         maxColumn = std::max(maxColumn, point.column);
         maxRow = std::max(maxRow, point.row);
     }
     const int x0 = std::max(0, static_cast<int>(std::floor(minColumn)));
     const int y0 = std::max(0, static_cast<int>(std::floor(minRow)));
     const int x1 = std::min(metadata.width, static_cast<int>(std::ceil(maxColumn)) + 1);
     const int y1 = std::min(metadata.height, static_cast<int>(std::ceil(maxRow)) + 1);
     if (x1 <= x0 || y1 <= y0) return 0.0f;

     cv::Mat mask(y1 - y0, x1 - x0, CV_8UC1, cv::Scalar(0));
     cv::fillPoly(mask, std::vector<std::vector<cv::Point>>{toCvRing(ring, x0, y0)}, cv::Scalar(1));
     double sum = 0.0;
     std::size_t count = 0;
     for (int row = 0; row < mask.rows; ++row)
         for (int column = 0; column < mask.cols; ++column)
             if (mask.at<uint8_t>(row, column) != 0)
             {
                 sum += semantics.buildingProbability.data[
                     static_cast<std::size_t>(y0 + row) * metadata.width + x0 + column];
                 ++count;
             }
     return count == 0 ? 0.0f : static_cast<float>(sum / count);
}

struct BlockCandidate
{
     std::array<ProjectedPoint, 4> corners;
     float areaSquareMetres{0.0f};
     float height{0.0f};
     std::string satRoofType;
     float satRiseMetres{0.0f};
     bool hasRidgeLine{false};
     std::array<PixelPoint, 2> ridgeLine;
};

// One extruded building part: a clipped SAT2LoD2 rectangle or a residual
// piece of the footprint that no rectangle covered.
struct Part
{
     FootprintPolygon<ProjectedPoint> polygon;
     float areaSquareMetres{0.0f};
     BuildingHeightEstimate height;
     float fallbackHeight{0.0f};
     const BlockCandidate* rectangle{nullptr};
     bool wholeRectangle{false};
};

constexpr double kMinResidualBuildingFraction = 0.7;

using GeometryPtr = std::unique_ptr<OGRGeometry, decltype(&OGRGeometryFactory::destroyGeometry)>;

GeometryPtr own(OGRGeometry* geometry)
{
     return GeometryPtr(geometry, OGRGeometryFactory::destroyGeometry);
}

GeometryPtr toOgrPolygon(const std::vector<ProjectedPoint>& ring)
{
     auto* linearRing = new OGRLinearRing();
     for (const ProjectedPoint& point : ring)
         linearRing->addPoint(point.easting, point.northing);
     linearRing->closeRings();
     auto* polygon = new OGRPolygon();
     polygon->addRingDirectly(linearRing);
     return own(polygon);
}

// Moves every edge of a rectangle outward by delta metres (inward if negative).
std::optional<std::vector<ProjectedPoint>> offsetRectangle(
     const std::array<ProjectedPoint, 4>& corners, double delta)
{
     ProjectedPoint centre;
     for (const ProjectedPoint& corner : corners)
     {
         centre.easting += 0.25 * corner.easting;
         centre.northing += 0.25 * corner.northing;
     }
     const double ax = corners[1].easting - corners[0].easting;
     const double ay = corners[1].northing - corners[0].northing;
     const double bx = corners[2].easting - corners[1].easting;
     const double by = corners[2].northing - corners[1].northing;
     const double lengthA = std::hypot(ax, ay);
     const double lengthB = std::hypot(bx, by);
     const double halfA = 0.5 * lengthA + delta;
     const double halfB = 0.5 * lengthB + delta;
     if (lengthA <= 0.0 || lengthB <= 0.0 || halfA <= 0.0 || halfB <= 0.0) return std::nullopt;
     std::vector<ProjectedPoint> result;
     constexpr std::array<std::pair<int, int>, 4> kCornerSigns{{{-1, -1}, {1, -1}, {1, 1}, {-1, 1}}};
     for (const auto& [signA, signB] : kCornerSigns)
         result.push_back(ProjectedPoint{
             centre.easting + signA * halfA * ax / lengthA + signB * halfB * bx / lengthB,
             centre.northing + signA * halfA * ay / lengthA + signB * halfB * by / lengthB});
     return result;
}

std::vector<ProjectedPoint> exteriorPoints(const OGRLinearRing* ring)
{
     std::vector<ProjectedPoint> points;
     for (int index = 0; ring != nullptr && index + 1 < ring->getNumPoints(); ++index)
         points.push_back(ProjectedPoint{ring->getX(index), ring->getY(index)});
     return points;
}

// Polygons of a GEOS result that are at least minArea and wider than
// minWidth, so clipping slivers never become paper-thin walls.
std::vector<FootprintPolygon<ProjectedPoint>> usableParts(
     const OGRGeometry* geometry, double minArea, double minWidth)
{
     std::vector<FootprintPolygon<ProjectedPoint>> parts;
     if (geometry == nullptr) return parts;
     if (const auto* collection = dynamic_cast<const OGRGeometryCollection*>(geometry))
     {
         for (int index = 0; index < collection->getNumGeometries(); ++index)
         {
             auto nested = usableParts(collection->getGeometryRef(index), minArea, minWidth);
             parts.insert(parts.end(), nested.begin(), nested.end());
         }
         return parts;
     }
     const auto* source = dynamic_cast<const OGRPolygon*>(geometry);
     if (source == nullptr || source->get_Area() < minArea) return parts;
     GeometryPtr core = own(source->Buffer(-0.5 * minWidth, 2));
     if (!core || core->IsEmpty()) return parts;

     // Clipping leaves repeated and collinear vertices, which break roof
     // triangulation. A 1 cm tolerance removes them without moving any wall.
     GeometryPtr cleaned = own(source->SimplifyPreserveTopology(0.01));
     const auto* polygon = cleaned ? dynamic_cast<const OGRPolygon*>(cleaned.get()) : nullptr;
     if (polygon == nullptr || polygon->IsEmpty()) polygon = source;

     FootprintPolygon<ProjectedPoint> part;
     part.outerRing = exteriorPoints(polygon->getExteriorRing());
     for (int index = 0; index < polygon->getNumInteriorRings(); ++index)
     {
         std::vector<ProjectedPoint> hole = exteriorPoints(polygon->getInteriorRing(index));
         if (hole.size() >= 3) part.holes.push_back(std::move(hole));
     }
     if (part.outerRing.size() >= 3) parts.push_back(std::move(part));
     return parts;
}

double projectedSignedArea(const std::vector<ProjectedPoint>& ring)
{
     double twiceArea = 0.0;
     const ProjectedPoint origin = ring.front();
     for (std::size_t index = 0; index < ring.size(); ++index)
     {
         const ProjectedPoint& a = ring[index];
         const ProjectedPoint& b = ring[(index + 1) % ring.size()];
         twiceArea += (a.easting - origin.easting) * (b.northing - origin.northing) -
                      (b.easting - origin.easting) * (a.northing - origin.northing);
     }
     return 0.5 * twiceArea;
}

// Converts a projected part to the FootprintPolygon invariants (CCW outer,
// CW holes) and the matching pixel-edge footprint.
FootprintPolygon<PixelPoint> canonicalize(FootprintPolygon<ProjectedPoint>& polygon,
                                          const SpatialMetadata& metadata)
{
     if (projectedSignedArea(polygon.outerRing) < 0.0)
         std::reverse(polygon.outerRing.begin(), polygon.outerRing.end());
     for (auto& hole : polygon.holes)
         if (projectedSignedArea(hole) > 0.0)
             std::reverse(hole.begin(), hole.end());
     FootprintPolygon<PixelPoint> pixel;
     for (const ProjectedPoint& point : polygon.outerRing)
         pixel.outerRing.push_back(toPixel(point, metadata));
     for (const auto& hole : polygon.holes)
     {
         pixel.holes.emplace_back();
         for (const ProjectedPoint& point : hole)
             pixel.holes.back().push_back(toPixel(point, metadata));
     }
     return pixel;
}

// Snap nearly equal part heights of one segment to a shared level. The nDSM
// varies slightly across a single roof, which would otherwise show as
// hairline steps between the parts of one building.
void snapHeightTiers(std::vector<float>& heights, const std::vector<float>& areas,
                     float stepMetres)
{
     std::vector<std::size_t> order(heights.size());
     std::iota(order.begin(), order.end(), 0);
     std::sort(order.begin(), order.end(), [&](std::size_t a, std::size_t b)
               { return heights[a] > heights[b]; });

     std::size_t start = 0;
     while (start < order.size())
     {
         std::size_t end = start + 1;
         while (end < order.size() && heights[order[start]] - heights[order[end]] < stepMetres)
             ++end;
         double weightedHeight = 0.0;
         double totalArea = 0.0;
         for (std::size_t index = start; index < end; ++index)
         {
             const double area = std::max(1.0f, areas[order[index]]);
             weightedHeight += area * heights[order[index]];
             totalArea += area;
         }
         for (std::size_t index = start; index < end; ++index)
             heights[order[index]] = static_cast<float>(weightedHeight / totalArea);
         start = end;
     }
}

RoofParameters makeRoof(const BlockCandidate& candidate,
                        const std::array<ProjectedPoint, 4>& corners,
                        float height,
                        const BuildingReconstructionConfig& config,
                        const SpatialMetadata& metadata,
                        float confidence)
{
     RoofParameters roof;
     roof.type = RoofType::FLAT;
     roof.eaveHeightAboveGround = height;
     roof.ridgeHeightAboveGround = height;
     roof.confidence = confidence;

     ProjectedPoint centre;
     for (const ProjectedPoint& corner : corners)
     {
         centre.easting += 0.25 * corner.easting;
         centre.northing += 0.25 * corner.northing;
     }
     roof.ridgeStartProjected = centre;
     roof.ridgeEndProjected = centre;

     // Pitched roofs stay opt-in, sharing the native LoD2 switch and limits.
     // Large urban roofs are flat, and a smooth monocular nDSM easily fakes a
     // shallow gable; a bad pitch looks far worse than a clean flat prism.
     const bool pitched = candidate.satRoofType == "gable" ||
         candidate.satRoofType == "hip" || candidate.satRoofType == "pyramid";
     if (config.enableLod2RoofFitting && pitched &&
         candidate.satRiseMetres >= config.minRoofRiseMetres &&
         candidate.satRiseMetres <= config.maxRoofRiseMetres &&
         candidate.areaSquareMetres <= config.commercialFlatRoofAreaSquareMetres &&
         height - candidate.satRiseMetres >= config.minBuildingHeightMetres)
     {
         roof.type = candidate.satRoofType == "gable" ? RoofType::GABLE : RoofType::HIP;
         roof.eaveHeightAboveGround = height - candidate.satRiseMetres;
         if (candidate.hasRidgeLine)
         {
             roof.ridgeStartProjected = toProjected(candidate.ridgeLine[0], metadata);
             roof.ridgeEndProjected = toProjected(candidate.ridgeLine[1], metadata);
         }
     }
     for (std::size_t index = 0; index < 2; ++index)
     {
         const ProjectedPoint& point = index == 0 ? roof.ridgeStartProjected : roof.ridgeEndProjected;
         (index == 0 ? roof.ridgeStartPixel : roof.ridgeEndPixel) = toPixel(point, metadata);
     }
     return roof;
}

// Splits one segment into building parts. SAT2LoD2's rectangles carry the
// building separations that the semantic mask cannot see (row buildings
// share walls), so each rectangle becomes its own part. Taller rectangles
// are placed first and stay intact; lower ones are clipped around them, and
// neighbours keep a small gap. Large uncovered footprint areas become extra
// parts so real buildings the decomposition missed do not vanish.
std::vector<Part> partitionSegment(const std::vector<ProjectedPoint>& footprint,
                                   const std::vector<BlockCandidate>& rectangles,
                                   const BuildingReconstructionConfig& config)
{
     const double halfGap = 0.5 * config.sat2lod2PartGapMetres;
     const double minArea = config.minDecomposedBlockAreaSquareMetres;
     constexpr double kMinPartWidthMetres = 2.0;
     constexpr double kMinResidualWidthMetres = 3.0;

     // Taller first. A podium rectangle's 85th percentile can equal the
     // tower inside it, so among equal heights the smaller rectangle claims
     // its space first and the larger one is clipped around it.
     const double step = std::max(0.1, static_cast<double>(config.sat2lod2TierSnapMetres));
     const auto level = [step](const BlockCandidate* rectangle)
     { return std::lround(rectangle->height / step); };
     std::vector<const BlockCandidate*> order;
     for (const BlockCandidate& rectangle : rectangles) order.push_back(&rectangle);
     std::stable_sort(order.begin(), order.end(), [&](const auto* a, const auto* b)
     {
          if (level(a) != level(b)) return level(a) > level(b);
          return a->areaSquareMetres < b->areaSquareMetres;
     });

     std::vector<Part> parts;
     GeometryPtr occupied = own(nullptr);
     for (const BlockCandidate* rectangle : order)
     {
         const auto inner = offsetRectangle(rectangle->corners, -halfGap);
         const auto outer = offsetRectangle(rectangle->corners, halfGap);
         if (!inner || !outer) continue;
         GeometryPtr piece = toOgrPolygon(*inner);
         const double innerArea = piece->toPolygon()->get_Area();
         if (occupied)
             piece = own(piece->Difference(occupied.get()));
         GeometryPtr claimed = toOgrPolygon(*outer);
         occupied = occupied ? own(occupied->Union(claimed.get())) : std::move(claimed);
         if (!piece || !occupied) continue;

         for (auto& polygon : usableParts(piece.get(), minArea, kMinPartWidthMetres))
         {
             Part part;
             part.polygon = std::move(polygon);
             part.areaSquareMetres = static_cast<float>(
                 std::abs(projectedSignedArea(part.polygon.outerRing)));
             part.rectangle = rectangle;
             part.fallbackHeight = rectangle->height;
             part.wholeRectangle = part.polygon.holes.empty() &&
                 part.areaSquareMetres >= 0.98 * innerArea;
             parts.push_back(std::move(part));
         }
     }

     if (config.sat2lod2MinResidualAreaSquareMetres > 0.0f && occupied)
     {
         GeometryPtr outline = toOgrPolygon(footprint);
         GeometryPtr residual = own(outline->Difference(occupied.get()));
         for (auto& polygon : usableParts(residual.get(),
                                          config.sat2lod2MinResidualAreaSquareMetres,
                                          kMinResidualWidthMetres))
         {
             Part part;
             part.polygon = std::move(polygon);
             part.areaSquareMetres = static_cast<float>(
                 std::abs(projectedSignedArea(part.polygon.outerRing)));
             parts.push_back(std::move(part));
         }
     }
     return parts;
}

BuildingInstance makeBuilding(uint32_t id,
                              const FootprintPolygon<PixelPoint>& pixelFootprint,
                              const FootprintPolygon<ProjectedPoint>& projectedFootprint,
                              const BuildingHeightEstimate& estimate,
                              float heightAboveGround,
                              const SemanticScene& semantics,
                              const SpatialMetadata& metadata)
{
     BuildingInstance building;
     building.buildingId = id;
     building.pixelFootprint = pixelFootprint;
     building.projectedFootprint = projectedFootprint;
     building.footprintAreaSquareMetres = static_cast<float>(
         std::abs(projectedSignedArea(projectedFootprint.outerRing)));
     building.semanticConfidence =
         meanBuildingProbability(pixelFootprint.outerRing, semantics, metadata);
     building.heightConfidence = estimate.confidence;
     building.representativeBaseElevation = estimate.representativeBaseElevation;
     if (estimate.baseElevationPerOuterVertex.size() == projectedFootprint.outerRing.size())
     {
         building.baseElevationPerVertex = estimate.baseElevationPerOuterVertex;
         building.baseModel = BaseElevationModel::PER_VERTEX;
     }
     building.heightAboveGround = heightAboveGround;
     building.roofElevation = building.representativeBaseElevation + heightAboveGround;
     building.geometryWarnings = estimate.warnings;
     return building;
}
} // namespace

Sat2Lod2ImportResult Sat2Lod2Importer::import(
     const Json::Value& document,
     const SemanticScene& semantics,
     const GeoreferencedSurfaceBundle& surface,
     const SpatialMetadata& metadata,
     const BuildingReconstructionConfig& config,
     const RasterGrid<float>& reconstructionNdsm)
{
     Sat2Lod2ImportResult result;
     if (!document.isObject() || document["schema"].asString() != kSchemaId)
     {
         result.warnings.push_back("SAT2LoD2 output has an unsupported schema.");
         return result;
     }
     if (document["raster_width"].asInt() != metadata.width ||
         document["raster_height"].asInt() != metadata.height)
     {
         result.warnings.push_back("SAT2LoD2 output does not match the scene raster size.");
         return result;
     }
     if (!document["segments"].isArray())
     {
         result.warnings.push_back("SAT2LoD2 output has no segment list.");
         return result;
     }

     const double pixelArea = pixelAreaSquareMetres(metadata);
     uint32_t nextId = 1;

     for (const Json::Value& segment : document["segments"])
     {
         ++result.segmentCount;
         const std::string label = "SAT2LoD2 segment " + segment["id"].asString();

         FootprintPolygon<PixelPoint> footprint;
         if (!readRing(segment["footprint"], metadata.width, metadata.height,
                       footprint.outerRing) ||
             !makeSimpleRing(footprint.outerRing))
         {
             result.warnings.push_back(label + ": invalid footprint.");
             ++result.skippedSegmentCount;
             continue;
         }

         std::vector<BlockCandidate> rectangles;
         std::vector<std::vector<ProjectedPoint>> rectangleRings;
         for (const Json::Value& source : segment["blocks"])
         {
             std::vector<PixelPoint> corners;
             if (!readRing(source["corners"], metadata.width, metadata.height, corners) ||
                 corners.size() != 4)
                 continue;
             BlockCandidate candidate;
             const std::vector<ProjectedPoint> projected = orientAndProject(corners, metadata);
             rectangleRings.push_back(projected);
             std::copy(projected.begin(), projected.end(), candidate.corners.begin());
             candidate.areaSquareMetres =
                 static_cast<float>(std::abs(signedArea(corners)) * pixelArea);
             if (candidate.areaSquareMetres < config.minDecomposedBlockAreaSquareMetres)
                 continue;

             FootprintPolygon<PixelPoint> rectangleFootprint;
             rectangleFootprint.outerRing = corners;
             const BuildingHeightEstimate estimate = BuildingHeightEstimator::estimate(
                 rectangleFootprint, surface, semantics, metadata, config, &reconstructionNdsm);
             // Only orders the rectangles; every part is re-measured after clipping.
             candidate.height = estimate.success ? estimate.heightAboveGround : 0.0f;

             candidate.satRoofType = source["roof_type"].asString();
             candidate.satRiseMetres = static_cast<float>(
                 (source["ridge"].asDouble() - source["eave"].asDouble()) *
                 config.heightScaleMultiplier);
             std::vector<PixelPoint> ridge;
             const Json::Value& ridgeLine = source["ridge_line"];
             if (ridgeLine.isArray() && ridgeLine.size() == 2)
                 for (const Json::Value& point : ridgeLine)
                     if (point.isArray() && point.size() == 2)
                         ridge.push_back(PixelPoint{point[0].asDouble() + 0.5,
                                                    point[1].asDouble() + 0.5});
             if (ridge.size() == 2)
             {
                 candidate.hasRidgeLine = true;
                 candidate.ridgeLine = {ridge[0], ridge[1]};
             }
             rectangles.push_back(std::move(candidate));
         }

         // SAT2LoD2's rectangles carry its estimate of the facade direction.
         regularizeFootprint(footprint.outerRing, metadata, config,
                             dominantOrientation(rectangleRings));
         if (std::abs(signedArea(footprint.outerRing)) * pixelArea <
             config.minBuildingAreaSquareMetres)
         {
             ++result.skippedSegmentCount;
             continue;
         }
         FootprintPolygon<ProjectedPoint> projectedFootprint;
         projectedFootprint.outerRing = orientAndProject(footprint.outerRing, metadata);

         const BuildingHeightEstimate segmentHeight = BuildingHeightEstimator::estimate(
             footprint, surface, semantics, metadata, config, &reconstructionNdsm);
         if (!segmentHeight.success)
         {
             result.warnings.push_back(label + ": " + segmentHeight.errorMessage);
             ++result.skippedSegmentCount;
             continue;
         }

         if (rectangles.empty())
         {
             ++result.irregularCount;
             BuildingInstance building = makeBuilding(
                 nextId++, footprint, projectedFootprint, segmentHeight,
                 segmentHeight.heightAboveGround, semantics, metadata);
             building.geometryWarnings.push_back(
                 "SAT2LoD2 irregular footprint extruded as a flat prism.");
             result.buildings.buildings.push_back(std::move(building));
             continue;
         }

         for (auto& rectangle : rectangles)
             if (rectangle.height <= 0.0f)
                 rectangle.height = segmentHeight.heightAboveGround;
         std::vector<Part> parts =
             partitionSegment(projectedFootprint.outerRing, rectangles, config);

         std::vector<FootprintPolygon<PixelPoint>> pixelParts;
         std::vector<float> heights;
         std::vector<float> areas;
         for (Part& part : parts)
         {
             pixelParts.push_back(canonicalize(part.polygon, metadata));
             part.height = BuildingHeightEstimator::estimate(
                 pixelParts.back(), surface, semantics, metadata, config, &reconstructionNdsm);
             // A residual piece needs its own building evidence; a clipped
             // rectangle keeps SAT2LoD2's support and its measured height.
             // Courtyards are building-free in the semantic mask even though
             // SAT2LoD2's hole-filled outline covers them.
             if (part.rectangle == nullptr &&
                 (!part.height.success ||
                  buildingClassFraction(pixelParts.back(), semantics, metadata) <
                      kMinResidualBuildingFraction))
             {
                 heights.push_back(-1.0f);
                 areas.push_back(0.0f);
                 continue;
             }
             heights.push_back(part.height.success ? part.height.heightAboveGround
                                                   : part.fallbackHeight);
             areas.push_back(part.areaSquareMetres);
         }
         snapHeightTiers(heights, areas, config.sat2lod2TierSnapMetres);

         for (std::size_t index = 0; index < parts.size(); ++index)
         {
             if (heights[index] < config.minBuildingHeightMetres) continue;
             const Part& part = parts[index];
             const BuildingHeightEstimate& estimate =
                 part.height.success ? part.height : segmentHeight;
             BuildingInstance building = makeBuilding(
                 nextId++, pixelParts[index], part.polygon, estimate, heights[index],
                 semantics, metadata);

             if (part.rectangle == nullptr)
             {
                 ++result.residualPartCount;
                 building.geometryWarnings.push_back(
                     "Footprint area outside SAT2LoD2 rectangles; heights from backend nDSM.");
                 result.buildings.buildings.push_back(std::move(building));
                 continue;
             }

             ++result.buildings.lod2BlockCount;
             std::array<ProjectedPoint, 4> corners;
             if (part.wholeRectangle && part.polygon.outerRing.size() == 4)
                 std::copy(part.polygon.outerRing.begin(), part.polygon.outerRing.end(),
                           corners.begin());
             const RoofParameters roof = part.wholeRectangle && part.polygon.outerRing.size() == 4
                 ? makeRoof(*part.rectangle, corners, heights[index], config, metadata,
                            estimate.confidence)
                 : RoofParameters{};
             if (roof.type != RoofType::FLAT)
             {
                 // Pitched roofs need BuildingMesher's parametric block path.
                 DecomposedBuildingBlock block;
                 block.projectedCorners = corners;
                 for (std::size_t corner = 0; corner < 4; ++corner)
                     block.pixelCorners[corner] = toPixel(corners[corner], metadata);
                 block.roof = roof;
                 block.footprintAreaSquareMetres = part.areaSquareMetres;
                 building.blocks.push_back(block);
                 if (roof.type == RoofType::GABLE) ++result.buildings.gableRoofBlockCount;
                 else ++result.buildings.hipRoofBlockCount;
             }
             else
             {
                 ++result.buildings.flatRoofBlockCount;
             }
             building.geometryWarnings.push_back(
                 "SAT2LoD2 rectangle part; height from backend nDSM.");
             result.buildings.buildings.push_back(std::move(building));
         }
     }

     result.buildings.semanticCandidateCount = result.segmentCount;
     result.buildings.physicsRejectedCount = result.skippedSegmentCount;
     return result;
}

Sat2Lod2ImportResult Sat2Lod2Importer::importFile(
     const std::string& path,
     const SemanticScene& semantics,
     const GeoreferencedSurfaceBundle& surface,
     const SpatialMetadata& metadata,
     const BuildingReconstructionConfig& config,
     const RasterGrid<float>& reconstructionNdsm)
{
     std::ifstream stream(path);
     if (!stream)
     {
         Sat2Lod2ImportResult result;
         result.warnings.push_back("Cannot open SAT2LoD2 output " + path);
         return result;
     }
     Json::CharReaderBuilder builder;
     Json::Value document;
     std::string errors;
     if (!Json::parseFromStream(builder, stream, &document, &errors))
     {
         Sat2Lod2ImportResult result;
         result.warnings.push_back("Cannot parse SAT2LoD2 output: " + errors);
         return result;
     }
     return import(document, semantics, surface, metadata, config, reconstructionNdsm);
}

std::size_t Sat2Lod2Importer::appendUncoveredNative(
     BuildingCollection& target,
     const BuildingCollection& native,
     const SpatialMetadata& metadata,
     float maxCoveredFraction)
{
     if (metadata.width <= 0 || metadata.height <= 0) return 0;

     cv::Mat covered(metadata.height, metadata.width, CV_8UC1, cv::Scalar(0));
     uint32_t nextId = 1;
     for (const BuildingInstance& building : target.buildings)
     {
         nextId = std::max(nextId, building.buildingId + 1);
         if (building.pixelFootprint.outerRing.size() >= 3)
             cv::fillPoly(covered, std::vector<std::vector<cv::Point>>{
                 toCvRing(building.pixelFootprint.outerRing, 0, 0)}, cv::Scalar(1));
         for (const auto& block : building.blocks)
             cv::fillPoly(covered, std::vector<std::vector<cv::Point>>{toCvRing(
                 std::vector<PixelPoint>(block.pixelCorners.begin(), block.pixelCorners.end()),
                 0, 0)}, cv::Scalar(1));
     }

     std::size_t kept = 0;
     for (const BuildingInstance& building : native.buildings)
     {
         const auto& ring = building.pixelFootprint.outerRing;
         if (ring.size() < 3) continue;

         cv::Mat footprint(metadata.height, metadata.width, CV_8UC1, cv::Scalar(0));
         cv::fillPoly(footprint, std::vector<std::vector<cv::Point>>{toCvRing(ring, 0, 0)},
                      cv::Scalar(1));
         const double total = cv::countNonZero(footprint);
         if (total <= 0.0) continue;
         cv::Mat overlap;
         cv::bitwise_and(footprint, covered, overlap);
         if (cv::countNonZero(overlap) / total > maxCoveredFraction) continue;

         BuildingInstance copy = building;
         copy.buildingId = nextId++;
         copy.geometryWarnings.push_back("Native reconstruction kept: not covered by SAT2LoD2.");
         target.lod2BlockCount += copy.blocks.size();
         target.buildings.push_back(std::move(copy));
         ++kept;
     }
     return kept;
}
