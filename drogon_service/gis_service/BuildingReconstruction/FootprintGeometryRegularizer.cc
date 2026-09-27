#include "FootprintGeometryRegularizer.h"

#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Shape_regularization/regularize_contours.h>
#include <ogr_geometry.h>

#include <algorithm>
#include <cmath>
#include <iterator>
#include <limits>
#include <memory>

namespace
{
double signedArea(const std::vector<ProjectedPoint>& ring)
{
    if (ring.size() < 3) return 0.0;
    const ProjectedPoint origin = ring.front();
    double twiceArea = 0.0;
    for (std::size_t i = 0; i < ring.size(); ++i)
    {
        const auto& a = ring[i];
        const auto& b = ring[(i + 1) % ring.size()];
        twiceArea += (a.easting - origin.easting) *
                         (b.northing - origin.northing) -
                     (b.easting - origin.easting) *
                         (a.northing - origin.northing);
    }
    return 0.5 * twiceArea;
}

double distanceToRing(const ProjectedPoint& point,
                      const std::vector<ProjectedPoint>& ring)
{
    double nearest = std::numeric_limits<double>::infinity();
    for (std::size_t i = 0; i < ring.size(); ++i)
    {
        const auto& a = ring[i];
        const auto& b = ring[(i + 1) % ring.size()];
        const double dx = b.easting - a.easting;
        const double dy = b.northing - a.northing;
        const double squaredLength = dx * dx + dy * dy;
        const double fraction = squaredLength > 0.0 ? std::clamp(
            ((point.easting - a.easting) * dx +
             (point.northing - a.northing) * dy) / squaredLength,
            0.0, 1.0) : 0.0;
        nearest = std::min(nearest, std::hypot(
            point.easting - a.easting - fraction * dx,
            point.northing - a.northing - fraction * dy));
    }
    return nearest;
}

void addRing(OGRPolygon& polygon, const std::vector<ProjectedPoint>& points,
             const ProjectedPoint& origin)
{
    OGRLinearRing ring;
    for (const auto& point : points)
        ring.addPoint(point.easting - origin.easting,
                      point.northing - origin.northing);
    ring.closeRings();
    polygon.addRing(&ring);
}

std::vector<ProjectedPoint> readRing(const OGRLinearRing* ring,
                                     const ProjectedPoint& origin)
{
    if (!ring || ring->getNumPoints() < 4) return {};
    std::vector<ProjectedPoint> points;
    points.reserve(ring->getNumPoints() - 1);
    for (int i = 0; i + 1 < ring->getNumPoints(); ++i)
        points.push_back({origin.easting + ring->getX(i),
                          origin.northing + ring->getY(i)});
    return points;
}
} // namespace

std::vector<ProjectedPoint>
FootprintGeometryRegularizer::regularizeContourWithCgal(
    const std::vector<ProjectedPoint>& ring, double maxShiftMetres,
    double areaDeviationTolerance)
{
    if (ring.size() < 4 || ring.size() > 512 ||
        !std::isfinite(maxShiftMetres) || maxShiftMetres <= 0.0 ||
        !std::isfinite(areaDeviationTolerance) || areaDeviationTolerance < 0.0)
        return {};

    using Kernel = CGAL::Exact_predicates_inexact_constructions_kernel;
    using Point = Kernel::Point_2;
    using Contour = std::vector<Point>;
    using Directions =
        CGAL::Shape_regularization::Contours::Multiple_directions_2<
            Kernel, Contour>;
    const ProjectedPoint origin = ring.front();
    Contour source;
    source.reserve(ring.size());
    for (const auto& point : ring)
    {
        if (!std::isfinite(point.easting) || !std::isfinite(point.northing))
            return {};
        source.emplace_back(point.easting - origin.easting,
                            point.northing - origin.northing);
    }

    Directions directions(source, true,
        CGAL::parameters::minimum_length(2.0).maximum_angle(15.0));
    Contour regularized;
    CGAL::Shape_regularization::Contours::regularize_closed_contour(
        source, directions, std::back_inserter(regularized),
        CGAL::parameters::maximum_offset(std::min(1.0, maxShiftMetres)));
    if (regularized.size() < 3) return {};

    std::vector<ProjectedPoint> candidate;
    candidate.reserve(regularized.size());
    for (const auto& point : regularized)
        candidate.push_back({origin.easting + point.x(),
                             origin.northing + point.y()});
    if (candidate.size() > 3 &&
        std::hypot(candidate.front().easting - candidate.back().easting,
                   candidate.front().northing - candidate.back().northing) < 1e-7)
        candidate.pop_back();
    const double before = signedArea(ring);
    const double after = signedArea(candidate);
    if (candidate.size() < 3 || before * after <= 0.0 ||
        std::abs(after - before) >
            areaDeviationTolerance * std::abs(before))
        return {};
    for (const auto& point : candidate)
        if (distanceToRing(point, ring) > maxShiftMetres + 1e-6)
            return {};
    return candidate;
}

FootprintPolygon<ProjectedPoint>
FootprintGeometryRegularizer::simplifyPolygonWithGeos(
    const FootprintPolygon<ProjectedPoint>& footprint,
    double toleranceMetres)
{
    FootprintPolygon<ProjectedPoint> candidate;
    if (footprint.outerRing.size() < 3 ||
        !std::isfinite(toleranceMetres) || toleranceMetres <= 0.0)
        return candidate;

    // Projected urban coordinates are large; simplify in local metres so
    // sub-metre boundary details retain numeric precision.
    const ProjectedPoint origin = footprint.outerRing.front();
    OGRPolygon source;
    addRing(source, footprint.outerRing, origin);
    for (const auto& hole : footprint.holes)
    {
        if (hole.size() < 3) return candidate;
        addRing(source, hole, origin);
    }
    if (!source.IsValid()) return candidate;

    std::unique_ptr<OGRGeometry, decltype(&OGRGeometryFactory::destroyGeometry)>
        simplified(source.SimplifyPreserveTopology(toleranceMetres),
                   OGRGeometryFactory::destroyGeometry);
    if (!simplified || wkbFlatten(simplified->getGeometryType()) != wkbPolygon ||
        !simplified->IsValid()) return candidate;
    const auto* polygon = simplified->toPolygon();
    if (polygon->getNumInteriorRings() !=
        static_cast<int>(footprint.holes.size())) return candidate;
    candidate.outerRing = readRing(polygon->getExteriorRing(), origin);
    for (int i = 0; i < polygon->getNumInteriorRings(); ++i)
        candidate.holes.push_back(readRing(polygon->getInteriorRing(i), origin));
    if (candidate.outerRing.size() < 3 ||
        std::any_of(candidate.holes.begin(), candidate.holes.end(),
            [](const auto& hole) { return hole.size() < 3; }))
        return {};
    if (signedArea(candidate.outerRing) *
        signedArea(footprint.outerRing) <= 0.0)
        std::reverse(candidate.outerRing.begin(), candidate.outerRing.end());
    for (std::size_t i = 0; i < candidate.holes.size(); ++i)
        if (signedArea(candidate.holes[i]) *
            signedArea(footprint.holes[i]) <= 0.0)
            std::reverse(candidate.holes[i].begin(), candidate.holes[i].end());
    return candidate;
}
