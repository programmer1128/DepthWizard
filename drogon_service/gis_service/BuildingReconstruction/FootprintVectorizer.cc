#include "FootprintVectorizer.h"
#include "FootprintGeometryRegularizer.h"
#include <opencv2/opencv.hpp>
#include <cmath>
#include <algorithm>
#include <utility>
#include <limits>
#include <unordered_map>
#include <cstdint>
#include <cstddef>
#include <numbers>

namespace
{
std::vector<ProjectedPoint> snapToOpticalLines(
    const std::vector<ProjectedPoint>& ring,
    const std::vector<cv::Vec4f>& opticalLines,
    const SpatialMetadata& metadata,
    double maxShiftMetres)
{
    if (ring.size() < 4 || opticalLines.empty()) return ring;
    const auto& gt = metadata.geoTransform;
    const double determinant = gt[1] * gt[5] - gt[2] * gt[4];
    if (std::abs(determinant) < 1.0e-12) return ring;
    const double metresPerPixel = std::sqrt(std::abs(determinant));
    const double maxOffsetPixels = std::min(
        3.0, maxShiftMetres / metresPerPixel);
    struct Point { double x; double y; };
    const auto toPixel = [&](const ProjectedPoint& point)
    {
        const double east = point.easting - gt[0];
        const double north = point.northing - gt[3];
        return Point{(gt[5] * east - gt[2] * north) / determinant,
                     (-gt[4] * east + gt[1] * north) / determinant};
    };
    std::vector<Point> points;
    points.reserve(ring.size());
    for (const auto& point : ring) points.push_back(toPixel(point));

    struct Line { double nx; double ny; double offset; };
    std::vector<Line> fitted;
    fitted.reserve(points.size());
    std::size_t supportedEdges = 0;
    for (std::size_t index = 0; index < points.size(); ++index)
    {
        const Point a = points[index];
        const Point b = points[(index + 1) % points.size()];
        const double dx = b.x - a.x, dy = b.y - a.y;
        const double length = std::hypot(dx, dy);
        if (length < 1.0e-6) return ring;
        const double tx = dx / length, ty = dy / length;
        const double nx = -ty, ny = tx;
        double offset = nx * a.x + ny * a.y;
        std::vector<std::pair<double, double>> evidence;
        double totalSupport = 0.0;
        if (length >= 10.0)
        {
            for (const auto& optical : opticalLines)
            {
                const double lx = optical[2] - optical[0];
                const double ly = optical[3] - optical[1];
                const double lineLength = std::hypot(lx, ly);
                if (lineLength < 8.0) continue;
                if (std::abs(tx * ly - ty * lx) / lineLength > 0.17)
                    continue;
                const double alongA =
                    (optical[0] - a.x) * tx + (optical[1] - a.y) * ty;
                const double alongB =
                    (optical[2] - a.x) * tx + (optical[3] - a.y) * ty;
                const double overlap = std::max(0.0,
                    std::min(length, std::max(alongA, alongB)) -
                    std::max(0.0, std::min(alongA, alongB)));
                if (overlap < 5.0) continue;
                const double distanceA =
                    nx * optical[0] + ny * optical[1] - offset;
                const double distanceB =
                    nx * optical[2] + ny * optical[3] - offset;
                const double distance = 0.5 * (distanceA + distanceB);
                if (std::abs(distance) > maxOffsetPixels ||
                    std::abs(distanceA - distanceB) > 2.0) continue;
                const double weight = overlap /
                    (1.0 + std::abs(distance));
                evidence.emplace_back(distance, weight);
                totalSupport += overlap;
            }
        }
        if (totalSupport >= std::max(8.0, 0.25 * length))
        {
            std::sort(evidence.begin(), evidence.end());
            double cumulative = 0.0, totalWeight = 0.0;
            for (const auto& item : evidence) totalWeight += item.second;
            for (const auto& item : evidence)
            {
                cumulative += item.second;
                if (cumulative >= 0.5 * totalWeight)
                {
                    offset += item.first;
                    ++supportedEdges;
                    break;
                }
            }
        }
        fitted.push_back({nx, ny, offset});
    }
    if (supportedEdges < 2) return ring;

    std::vector<ProjectedPoint> snapped;
    snapped.reserve(points.size());
    for (std::size_t index = 0; index < points.size(); ++index)
    {
        const auto& before = fitted[(index + fitted.size() - 1) % fitted.size()];
        const auto& after = fitted[index];
        const double det = before.nx * after.ny -
                           before.ny * after.nx;
        Point corner = points[index];
        if (std::abs(det) > 0.15)
        {
            const Point intersection{
                (before.offset * after.ny -
                 before.ny * after.offset) / det,
                (before.nx * after.offset -
                 before.offset * after.nx) / det};
            if (std::hypot(intersection.x - corner.x,
                           intersection.y - corner.y) <=
                maxShiftMetres / metresPerPixel)
                corner = intersection;
        }
        snapped.push_back({
            gt[0] + corner.x * gt[1] + corner.y * gt[2],
            gt[3] + corner.x * gt[4] + corner.y * gt[5]});
    }
    return snapped;
}
} // namespace

std::vector<ProjectedPoint> FootprintVectorizer::regularizeEdges(
    const std::vector<ProjectedPoint>& ring,
    double maxShift,
    double areaDeviationTolerance)
{
    if (ring.size() < 4 || maxShift <= 0.0) return ring;

    // Fit a shared Manhattan frame from the long, supported sides. Short
    // contour details are not allowed to rotate the entire building.
    struct EdgeAngle { double angle; double length; };
    std::vector<EdgeAngle> edges;
    double totalLength = 0.0;
    for (std::size_t i = 0; i < ring.size(); ++i)
    {
        const auto& a = ring[i];
        const auto& b = ring[(i + 1) % ring.size()];
        const double dx = b.easting - a.easting;
        const double dy = b.northing - a.northing;
        const double length = std::hypot(dx, dy);
        if (length < 2.0) continue;
        edges.push_back({std::atan2(dy, dx), length});
        totalLength += length;
    }
    if (edges.empty()) return ring;

    constexpr double alignment = 0.5; // within 15 degrees of an axis
    double bestSupport = 0.0;
    double bestAngle = 0.0;
    for (const auto& candidate : edges)
    {
        double support = 0.0;
        for (const auto& edge : edges)
            if (std::cos(4.0 * (edge.angle - candidate.angle)) >= alignment)
                support += edge.length;
        if (support > bestSupport)
        {
            bestSupport = support;
            bestAngle = candidate.angle;
        }
    }
    if (bestSupport < 0.35 * totalLength) return ring;
    double sine = 0.0, cosine = 0.0;
    for (const auto& edge : edges)
        if (std::cos(4.0 * (edge.angle - bestAngle)) >= alignment)
        {
            sine += edge.length * std::sin(4.0 * edge.angle);
            cosine += edge.length * std::cos(4.0 * edge.angle);
        }
    const double theta = 0.25 * std::atan2(sine, cosine);
    const double ct = std::cos(theta), st = std::sin(theta);
    const ProjectedPoint origin = ring.front();
    struct Point { double x; double y; };
    std::vector<Point> local;
    local.reserve(ring.size());
    for (const auto& point : ring)
    {
        const double x = point.easting - origin.easting;
        const double y = point.northing - origin.northing;
        local.push_back({x * ct + y * st, -x * st + y * ct});
    }

    // A short diagonal between two perpendicular supported walls is usually
    // a raster chamfer. Join the walls at their intersection without adding
    // a two-edge staircase to the footprint.
    for (std::size_t pass = 0; pass < ring.size() && local.size() > 4; ++pass)
    {
        bool changed = false;
        for (std::size_t i = 0; i < local.size(); ++i)
        {
            const std::size_t j = (i + 1) % local.size();
            const Point prev = local[(i + local.size() - 1) % local.size()];
            const Point a = local[i], b = local[j];
            const Point next = local[(j + 1) % local.size()];
            if (std::hypot(b.x - a.x, b.y - a.y) >
                2.0 * maxShift) continue;
            const double px = a.x - prev.x, py = a.y - prev.y;
            const double nx = next.x - b.x, ny = next.y - b.y;
            const double beforeLength = std::hypot(px, py);
            const double afterLength = std::hypot(nx, ny);
            if (beforeLength < 2.0 || afterLength < 2.0) continue;
            const bool horizontalThenVertical =
                std::abs(py) < 0.15 * std::abs(px) &&
                std::abs(nx) < 0.15 * std::abs(ny);
            const bool verticalThenHorizontal =
                std::abs(px) < 0.15 * std::abs(py) &&
                std::abs(ny) < 0.15 * std::abs(nx);
            if (!horizontalThenVertical && !verticalThenHorizontal) continue;
            const Point corner = horizontalThenVertical
                ? Point{b.x, a.y} : Point{a.x, b.y};
            if (std::hypot(corner.x - a.x, corner.y - a.y) > maxShift ||
                std::hypot(corner.x - b.x, corner.y - b.y) > maxShift)
                continue;
            local[i] = corner;
            local.erase(local.begin() + j);
            changed = true;
            break;
        }
        if (!changed) break;
    }

    // Suppress tiny three-sided bays on an otherwise straight wall. The
    // raster mask can include HVAC and shadows as 1-2 m outward jogs.
    for (std::size_t pass = 0; pass < ring.size() && local.size() >= 8; ++pass)
    {
        bool changed = false;
        for (std::size_t i = 0; i < local.size(); ++i)
        {
            std::rotate(local.begin(), local.begin() + i, local.end());
            const Point a = local[0], b = local[1], c = local[2];
            const Point d = local[3], e = local[4], f = local[5];
            const double abx = b.x - a.x, aby = b.y - a.y;
            const double efx = f.x - e.x, efy = f.y - e.y;
            const double ab = std::hypot(abx, aby);
            const double ef = std::hypot(efx, efy);
            const bool sameWall = ab > 1.0 && ef > 1.0 &&
                abx * efx + aby * efy > 0.98 * ab * ef &&
                std::abs(abx * (e.y - a.y) - aby * (e.x - a.x)) /
                    ab < 0.2;
            const bool shortJog =
                std::hypot(c.x - b.x, c.y - b.y) <= maxShift &&
                std::hypot(d.x - c.x, d.y - c.y) <= maxShift &&
                std::hypot(e.x - d.x, e.y - d.y) <= maxShift;
            if (sameWall && shortJog)
            {
                local.erase(local.begin() + 1, local.begin() + 5);
                changed = true;
                break;
            }
            std::rotate(local.begin(), local.begin() + local.size() - i,
                        local.end());
        }
        if (!changed) break;
    }

    // Represent each edge as a single infinite line. A near-axis edge keeps
    // its observed midpoint and takes the common axis direction. This avoids
    // inventing a staircase vertex for every slightly diagonal raster edge.
    struct FittedLine { double nx; double ny; double offset; };
    std::vector<FittedLine> lines;
    lines.reserve(local.size());
    constexpr double axisRatio = 0.36; // about 20 degrees
    for (std::size_t i = 0; i < local.size(); ++i)
    {
        const Point a = local[i], b = local[(i + 1) % local.size()];
        const double dx = b.x - a.x, dy = b.y - a.y;
        const double length = std::hypot(dx, dy);
        if (length < 1.0e-6) return ring;
        if (std::abs(dy) <= axisRatio * std::abs(dx))
            lines.push_back({0.0, 1.0, 0.5 * (a.y + b.y)});
        else if (std::abs(dx) <= axisRatio * std::abs(dy))
            lines.push_back({1.0, 0.0, 0.5 * (a.x + b.x)});
        else
        {
            const double nx = -dy / length, ny = dx / length;
            lines.push_back({nx, ny, nx * a.x + ny * a.y});
        }
    }

    std::vector<ProjectedPoint> fitted;
    fitted.reserve(ring.size());
    for (std::size_t i = 0; i < local.size(); ++i)
    {
        const auto& before = lines[(i + lines.size() - 1) % lines.size()];
        const auto& after = lines[i];
        const double determinant = before.nx * after.ny -
                                   before.ny * after.nx;
        Point corner = local[i];
        if (std::abs(determinant) > 0.15)
        {
            const Point intersection{
                (before.offset * after.ny -
                 before.ny * after.offset) / determinant,
                (before.nx * after.offset -
                 before.offset * after.nx) / determinant};
            if (std::hypot(intersection.x - corner.x,
                           intersection.y - corner.y) <= maxShift)
                corner = intersection;
        }
        fitted.push_back({
            origin.easting + corner.x * ct - corner.y * st,
            origin.northing + corner.x * st + corner.y * ct});
    }

    // Remove repeated/collinear fitted corners. Topology and pixel agreement
    // are validated by the vectorizer before a fitted ring is accepted.
    for (int pass = 0; pass < 3 && fitted.size() > 3; ++pass)
    {
        bool changed = false;
        for (std::size_t i = 0; i < fitted.size(); ++i)
        {
            const auto& a = fitted[(i + fitted.size() - 1) % fitted.size()];
            const auto& b = fitted[i];
            const auto& c = fitted[(i + 1) % fitted.size()];
            const double abx = b.easting - a.easting;
            const double aby = b.northing - a.northing;
            const double bcx = c.easting - b.easting;
            const double bcy = c.northing - b.northing;
            const double ab = std::hypot(abx, aby);
            const double bc = std::hypot(bcx, bcy);
            const double cross = std::abs(abx * bcy - aby * bcx);
            if (ab < 0.2 || bc < 0.2 ||
                (ab > 0.0 && bc > 0.0 && cross < 0.02 * ab * bc &&
                 abx * bcx + aby * bcy > 0.0))
            {
                fitted.erase(fitted.begin() + i);
                changed = true;
                break;
            }
        }
        if (!changed) break;
    }
    if (fitted.size() < 3 || hasSelfIntersections(fitted)) return ring;
    const double originalArea = calculateSignedArea(ring);
    const double fittedArea = calculateSignedArea(fitted);
    if (!std::isfinite(fittedArea) || originalArea * fittedArea <= 0.0 ||
        std::abs(fittedArea - originalArea) >
            areaDeviationTolerance * std::abs(originalArea))
        return ring;
    return fitted;
}

//topological helpers
double FootprintVectorizer::calculateSignedArea(const std::vector<ProjectedPoint>& pts)
{
     size_t n = pts.size();
     if (n < 3)
     {
         return 0.0;
     }
     double area = 0.0;
     // Translate to local origin (pts[0]) to prevent floating-point cancellation on massive UTM coordinates
     double cx = pts[0].easting;
     double cy = pts[0].northing;
     for (size_t i = 0; i < n; i++)
     {
         size_t j = (i + 1) % n;
         area += ((pts[i].easting - cx) * (pts[j].northing - cy)) - ((pts[j].easting - cx) * (pts[i].northing - cy));
     }
     return area / 2.0;
}

bool FootprintVectorizer::doIntersect(const ProjectedPoint& p1, const ProjectedPoint& q1, const ProjectedPoint& p2, const ProjectedPoint& q2)
{
     auto orientation = [](const ProjectedPoint& a, const ProjectedPoint& b, const ProjectedPoint& c) -> int
     {
         double val = (b.northing - a.northing) * (c.easting - b.easting) - (b.easting - a.easting) * (c.northing - b.northing);
         if (std::abs(val) < 1e-6)
         {
             return 0; // Collinear
         }
         return (val > 0) ? 1 : 2;
     };
     auto onSegment = [](const ProjectedPoint& p, const ProjectedPoint& q, const ProjectedPoint& r) -> bool
     {
         return q.easting <= std::max(p.easting, r.easting) && q.easting >= std::min(p.easting, r.easting) &&
             q.northing <= std::max(p.northing, r.northing) && q.northing >= std::min(p.northing, r.northing);
     };

     int o1 = orientation(p1, q1, p2);
     int o2 = orientation(p1, q1, q2);
     int o3 = orientation(p2, q2, p1);
     int o4 = orientation(p2, q2, q1);

     if (o1 != o2 && o3 != o4)
     {
         return true;
     }
     if (o1 == 0 && onSegment(p1, p2, q1))
     {
         return true;
     }
     if (o2 == 0 && onSegment(p1, q2, q1))
     {
         return true;
     }
     if (o3 == 0 && onSegment(p2, p1, q2))
     {
         return true;
     }
     if (o4 == 0 && onSegment(p2, q1, q2))
     {
         return true;
     }
     return false;
}

bool FootprintVectorizer::hasSelfIntersections(const std::vector<ProjectedPoint>& ring)
{
     size_t n = ring.size();
     if (n < 4) return false;
     for (size_t i = 0; i < n; i++)
     {
         size_t next_i = (i + 1) % n;
         for (size_t j = i + 2; j < n; j++)
         {
             size_t next_j = (j + 1) % n;
             if (i == next_j || next_i == j)
             {
                 continue; // Skip adjacent edges
             }
             if (doIntersect(ring[i], ring[next_i], ring[j], ring[next_j]))
             {
                 return true;
             }
         }
     }
     return false;
}

bool FootprintVectorizer::isPointInPolygon(const ProjectedPoint& pt, const std::vector<ProjectedPoint>& polygon)
{
     bool inside = false;
     size_t n = polygon.size();
     for (size_t i = 0, j = n - 1; i < n; j = i++)
     {
         if (((polygon[i].northing > pt.northing) != (polygon[j].northing > pt.northing)) &&
             (pt.easting < (polygon[j].easting - polygon[i].easting) * (pt.northing - polygon[i].northing) /
                           (polygon[j].northing - polygon[i].northing) + polygon[i].easting))
         {
             inside = !inside;
         }
     }
     return inside;
}

bool FootprintVectorizer::ringsIntersect(const std::vector<ProjectedPoint>& ringA, const std::vector<ProjectedPoint>& ringB)
{
     for (size_t i = 0; i < ringA.size(); i++)
     {
         size_t next_i = (i + 1) % ringA.size();
         for (size_t j = 0; j < ringB.size(); j++)
         {
             size_t next_j = (j + 1) % ringB.size();
             if (doIntersect(ringA[i], ringA[next_i], ringB[j], ringB[next_j]))
             {
                 return true;
             }
         }
     }
     return false;
}

//vectorisation
FootprintVectorizationResult FootprintVectorizer::vectorize(
     const ComponentStats& stats,
     const RasterGrid<int32_t>& labelRaster,
     const SpatialMetadata& metadata,
     const BuildingReconstructionConfig& config,
     const std::vector<cv::Vec4f>* opticalLines)
{
     FootprintVectorizationResult result;

     if (!config.validate() || stats.componentId <= 0 || stats.physicalAreaSquareMetres <= 0.0)
     {
         result.errorMessage = "Invalid configuration, negative area, or component ID.";
         return result;
     }

     if (!labelRaster.isValid() || labelRaster.width != metadata.width || labelRaster.height != metadata.height)
     {
         result.errorMessage = "Label raster mismatch.";
         return result;
     }

     // Strict Metric CRS Validation
     double det = metadata.geoTransform[1] * metadata.geoTransform[5] - metadata.geoTransform[2] * metadata.geoTransform[4];
     if (!metadata.isGeoreferenced || metadata.projectionRef.empty() || metadata.projectionRef.find("PROJCS") == std::string::npos || std::abs(det) < 1e-8)
     {
         result.errorMessage = "Unprojected or geographic CRS detected. Footprint vectorization requires a projected metric working CRS.";
         return result;
     }

     // Bounding Box Validation using int64_t to prevent overflow
     int64_t bx = stats.pixelBoundingBox.x;
     int64_t by = stats.pixelBoundingBox.y;
     int64_t bw = stats.pixelBoundingBox.width;
     int64_t bh = stats.pixelBoundingBox.height;

     if (bw <= 0 || bh <= 0 || bx < 0 || by < 0 || bx + bw > labelRaster.width || by + bh > labelRaster.height)
     {
         result.errorMessage = "Component bounding box exceeds raster limits.";
         return result;
     }

     const double gsd = std::max(1e-4, metadata.gsd);
     const int dilationRadius = (config.footprintDilationMetres > 0.0f && gsd > 1e-6)
         ? static_cast<int>(std::ceil(config.footprintDilationMetres / gsd))
         : 0;

     const int roiX = std::max<int>(0, static_cast<int>(bx - dilationRadius));
     const int roiY = std::max<int>(0, static_cast<int>(by - dilationRadius));
     const int roiMaxX = std::min<int>(labelRaster.width, static_cast<int>(bx + bw + dilationRadius));
     const int roiMaxY = std::min<int>(labelRaster.height, static_cast<int>(by + bh + dilationRadius));
     const int roiW = roiMaxX - roiX;
     const int roiH = roiMaxY - roiY;

     cv::Mat roiMask = cv::Mat::zeros(roiH, roiW, CV_8UC1);
     for (int r = 0; r < roiH; ++r)
     {
         const int globalR = roiY + r;
         const std::size_t offset = static_cast<std::size_t>(globalR) * labelRaster.width;
         for (int c = 0; c < roiW; ++c)
         {
             const int globalC = roiX + c;
             if (labelRaster.data[offset + globalC] == stats.componentId)
             {
                 roiMask.at<uint8_t>(r, c) = 1;
             }
         }
     }

     if (dilationRadius > 0)
     {
         // Dilation is intended to compensate for semantic edge blur at the
         // exterior facade.  It must not pave over a real enclosed courtyard.
         // Record background components that are enclosed by the observed
         // instance before widening its outer boundary, then restore them.
         cv::Mat observedInverse;
         cv::compare(roiMask, 0, observedInverse, cv::CMP_EQ);
         cv::Mat backgroundLabels;
         const int backgroundCount = cv::connectedComponents(
             observedInverse, backgroundLabels, 4, CV_32S);
         std::vector<uint8_t> enclosedBackground(
             static_cast<std::size_t>(backgroundCount), 1);
         if (!enclosedBackground.empty()) enclosedBackground[0] = 0;
         for (int c = 0; c < roiW; ++c)
         {
             enclosedBackground[backgroundLabels.at<int>(0, c)] = 0;
             enclosedBackground[backgroundLabels.at<int>(roiH - 1, c)] = 0;
         }
         for (int r = 0; r < roiH; ++r)
         {
             enclosedBackground[backgroundLabels.at<int>(r, 0)] = 0;
             enclosedBackground[backgroundLabels.at<int>(r, roiW - 1)] = 0;
         }

         cv::Mat kernel = cv::getStructuringElement(
             cv::MORPH_RECT, cv::Size(2 * dilationRadius + 1, 2 * dilationRadius + 1));
         cv::dilate(roiMask, roiMask, kernel);
         // Do not dilate into other building components
         for (int r = 0; r < roiH; ++r)
         {
             const int globalR = roiY + r;
             const std::size_t offset = static_cast<std::size_t>(globalR) * labelRaster.width;
             for (int c = 0; c < roiW; ++c)
             {
                 const int globalC = roiX + c;
                 const auto label = labelRaster.data[offset + globalC];
                 if (label > 0 && label != stats.componentId)
                 {
                     roiMask.at<uint8_t>(r, c) = 0;
                 }
             }
         }

         for (int r = 0; r < roiH; ++r)
         {
             for (int c = 0; c < roiW; ++c)
             {
                 const int backgroundId = backgroundLabels.at<int>(r, c);
                 if (backgroundId > 0 &&
                     enclosedBackground[static_cast<std::size_t>(backgroundId)] != 0)
                 {
                     roiMask.at<uint8_t>(r, c) = 0;
                 }
             }
         }
     }

     //Exact Raster-Cell Edge Polygonization (Replaces OpenCV findContours)
     struct BoundaryEdge
     {
         int64_t start;
         int64_t end;
         bool used{false};
     };
     std::vector<BoundaryEdge> edges;
     std::unordered_map<int64_t, std::vector<std::size_t>> outgoing;
     auto encodeNode = [](int32_t x, int32_t y) -> int64_t { return (static_cast<int64_t>(y) << 32) | static_cast<uint32_t>(x); };
     auto decodeNode = [](int64_t val, int32_t& x, int32_t& y) { y = static_cast<int32_t>(val >> 32); x = static_cast<int32_t>(val & 0xFFFFFFFF); };

     auto addEdge = [&](int32_t x1, int32_t y1, int32_t x2, int32_t y2)
     {
         const int64_t start = encodeNode(x1, y1);
         outgoing[start].push_back(edges.size());
         edges.push_back({start, encodeNode(x2, y2)});
     };

     auto isMasked = [&](int32_t c, int32_t r) -> bool {
         if (c < roiX || r < roiY || c >= roiMaxX || r >= roiMaxY) return false;
         return roiMask.at<uint8_t>(r - roiY, c - roiX) != 0;
     };

     // Scan ROI to extract unshared exterior cell edges
     for (int32_t r = roiY; r < roiMaxY; ++r)
     {
         for (int32_t c = roiX; c < roiMaxX; ++c)
         {
             if (isMasked(c, r))
             {
                 if (!isMasked(c, r - 1))
                 {
                     addEdge(c, r, c + 1, r);         // Top edge
                 }
                 if (!isMasked(c + 1, r))
                 {
                     addEdge(c + 1, r, c + 1, r + 1); // Right edge
                 }
                 if (!isMasked(c, r + 1))
                 {
                     addEdge(c + 1, r + 1, c, r + 1); // Bottom edge
                 }
                 if (!isMasked(c - 1, r))
                 {
                     addEdge(c, r + 1, c, r);         // Left edge
                 }
             }
         }
     }

     // A corner can have two outgoing edges when separate background regions
     // touch diagonally. Keep both; a single-entry map silently drops one.
     auto direction = [&](int64_t start, int64_t end)
     {
         int32_t x0, y0, x1, y1;
         decodeNode(start, x0, y0);
         decodeNode(end, x1, y1);
         if (x1 > x0) return 0; // east
         if (y1 > y0) return 1; // south
         if (x1 < x0) return 2; // west
         return 3;             // north
     };
     auto turnPriority = [](int turn)
     {
         switch (turn)
         {
             case 1: return 0; // right
             case 0: return 1; // straight
             case 3: return 2; // left
             default: return 3;
         }
     };

     std::vector<std::vector<ProjectedPoint>> rawRings;
     for (std::size_t first = 0; first < edges.size(); ++first)
     {
         if (edges[first].used) continue;
         const int64_t startNode = edges[first].start;
         std::size_t current = first;

         std::vector<int64_t> ringNodes;
         bool closed = false;
         for (std::size_t count = 0; count < edges.size(); ++count)
         {
             ringNodes.push_back(edges[current].start);

             edges[current].used = true;
             const int64_t nextNode = edges[current].end;
             if (nextNode == startNode)
             {
                 closed = true;
                 break;
             }
             const auto candidates = outgoing.find(nextNode);
             if (candidates == outgoing.end()) break;
             const int incoming = direction(edges[current].start, nextNode);
             std::size_t next = edges.size();
             int bestPriority = 4;
             for (std::size_t candidate : candidates->second)
             {
                 if (edges[candidate].used) continue;
                 const int turn = (direction(nextNode, edges[candidate].end) -
                                   incoming + 4) % 4;
                 const int priority = turnPriority(turn);
                 if (priority < bestPriority)
                 {
                     bestPriority = priority;
                     next = candidate;
                 }
             }
             if (next == edges.size()) break;
             current = next;
         }
         if (!closed)
         {
             result.errorMessage = "Building boundary contains an open cell-edge ring.";
             return result;
         }
         // A ring can touch itself at a single cell corner. Separate its two
         // cycles so a small touching courtyard does not make the entire
         // building appear multipart or self-intersecting.
         std::vector<std::vector<int64_t>> pending;
         pending.push_back(std::move(ringNodes));
         while (!pending.empty())
         {
             auto nodes = std::move(pending.back());
             pending.pop_back();
             std::unordered_map<int64_t, std::size_t> seen;
             bool divided = false;
             for (std::size_t index = 0; index < nodes.size(); ++index)
             {
                 const auto [it, inserted] = seen.emplace(nodes[index], index);
                 if (inserted) continue;
                 const std::size_t firstIndex = it->second;
                 std::vector<int64_t> cycleA(
                     nodes.begin() + firstIndex, nodes.begin() + index);
                 std::vector<int64_t> cycleB(
                     nodes.begin() + index, nodes.end());
                 cycleB.insert(cycleB.end(), nodes.begin(),
                               nodes.begin() + firstIndex);
                 if (cycleA.size() < 3 || cycleB.size() < 3)
                 {
                     result.errorMessage = "Building boundary contains a degenerate touching ring.";
                     return result;
                 }
                 pending.push_back(std::move(cycleA));
                 pending.push_back(std::move(cycleB));
                 divided = true;
                 break;
             }
             if (divided) continue;
             if (nodes.size() < 3) continue;
             std::vector<ProjectedPoint> ring;
             ring.reserve(nodes.size());
             for (int64_t node : nodes)
             {
                 int32_t px, py;
                 decodeNode(node, px, py);
                 ring.push_back({
                     metadata.geoTransform[0] +
                         px * metadata.geoTransform[1] +
                         py * metadata.geoTransform[2],
                     metadata.geoTransform[3] +
                         px * metadata.geoTransform[4] +
                         py * metadata.geoTransform[5]});
             }
             rawRings.push_back(std::move(ring));
         }
     }

     if (rawRings.empty())
     {
         result.errorMessage = "Failed to construct valid cell boundaries.";
         return result;
     }

     //classify Rings & Reject Multipart Components
     std::vector<std::vector<ProjectedPoint>> outerRings;
     std::vector<std::vector<ProjectedPoint>> holeRings;

     // A negative affine determinant reverses polygon winding when converting
     // from pixel coordinates to projected coordinates.
     const double affineOrientation = (det >= 0.0) ? 1.0 : -1.0;

     for (auto ring : rawRings)
     {
         const double projectedSignedArea = calculateSignedArea(ring);

         // Restore the winding produced by the boundary tracer before the
         // affine transform changed its orientation.
         const double topologySignedArea =
             projectedSignedArea * affineOrientation;

         if (topologySignedArea > 0.0)
         {
             // Canonical projected-coordinate output: outer ring is CCW.
             if (projectedSignedArea < 0.0)
             {
                 std::reverse(ring.begin(), ring.end());
             }

             outerRings.push_back(std::move(ring));
         }
         else if (
             topologySignedArea < 0.0 &&
             std::abs(projectedSignedArea) >=
                 config.minHoleAreaSquareMetres)
         {
             // Small segmentation voids around rooftop equipment are often
             // triangular or ragged. Retain compact, rectilinear light wells
             // while removing these unsupported punctures from flat roofs.
             const double holeArea = std::abs(projectedSignedArea);
             if (holeArea < 20.0 && ring.size() >= 3)
             {
                 const auto origin = ring.front();
                 std::vector<cv::Point2f> local;
                 local.reserve(ring.size());
                 for (const auto& point : ring)
                     local.emplace_back(
                         static_cast<float>(point.easting - origin.easting),
                         static_cast<float>(point.northing - origin.northing));
                 const cv::RotatedRect box = cv::minAreaRect(local);
                 const double boxArea = static_cast<double>(box.size.width) *
                                        box.size.height;
                 if (boxArea <= 0.0 || holeArea / boxArea < 0.72 ||
                     std::min(box.size.width, box.size.height) < 1.0f)
                     continue;
             }
             // Canonical projected-coordinate output: holes are CW.
             if (projectedSignedArea > 0.0)
             {
                 std::reverse(ring.begin(), ring.end());
             }

             holeRings.push_back(std::move(ring));
         }
     }

     if (outerRings.size() != 1)
     {
         result.errorMessage = "Component has multiple disconnected outer rings (multipart). Rejecting to prevent topological corruption.";
         return result;
     }

     std::vector<ProjectedPoint> rawOuter = outerRings[0];

    double rawOuterArea = std::abs(calculateSignedArea(rawOuter));
    for (const auto& hole : holeRings)
        rawOuterArea -= std::abs(calculateSignedArea(hole));
    const double referenceArea = (dilationRadius > 0) ? rawOuterArea : stats.physicalAreaSquareMetres;
    const std::size_t dilatedPixelCount = (dilationRadius > 0)
        ? static_cast<std::size_t>(cv::countNonZero(roiMask))
        : static_cast<std::size_t>(stats.pixelCount);

     //Metric RDP Simplification with Validation
     auto simplifyAndValidateRing = [&](const std::vector<ProjectedPoint>& rawRing,
                                        double initialEpsilon) -> std::vector<ProjectedPoint>
     {
         if (rawRing.empty()) return {};
         double minE = rawRing.front().easting, maxE = rawRing.front().easting;
         double minN = rawRing.front().northing, maxN = rawRing.front().northing;
         for (const auto& p : rawRing)
         {
             minE = std::min(minE, p.easting);
             maxE = std::max(maxE, p.easting);
             minN = std::min(minN, p.northing);
             maxN = std::max(maxN, p.northing);
         }
         const double minDim = std::max(1.0, std::min(maxE - minE, maxN - minN));
         double epsilon = std::min(initialEpsilon, std::max(0.5, minDim * 0.12));
         std::vector<ProjectedPoint> simplifiedRing;

         ProjectedPoint centroid = {0.0, 0.0};
         for (const auto& p : rawRing)
         {
             centroid.easting += p.easting;
             centroid.northing += p.northing;
         }
         centroid.easting /= rawRing.size(); centroid.northing /= rawRing.size();

         const double rawSignedArea = calculateSignedArea(rawRing);
         const double areaBudget =
             static_cast<double>(config.footprintAreaDeviationTolerance);

         for (int attempts = 0; attempts < 8; ++attempts)
         {
             std::vector<cv::Point2f> localPoints;
             for (const auto& pt : rawRing)
             {
                 localPoints.push_back(cv::Point2f(static_cast<float>(pt.easting - centroid.easting), static_cast<float>(pt.northing - centroid.northing)));
             }

             std::vector<cv::Point2f> simplifiedLocal;
             cv::approxPolyDP(localPoints, simplifiedLocal, epsilon, true);

             simplifiedRing.clear();
             for (const auto& lpt : simplifiedLocal)
             {
                 simplifiedRing.push_back({lpt.x + centroid.easting, lpt.y + centroid.northing});
             }

             // Remove duplicated closing vertex ONLY if exact match
             if (simplifiedRing.size() > 0 &&
                 simplifiedRing.front().easting == simplifiedRing.back().easting &&
                 simplifiedRing.front().northing == simplifiedRing.back().northing)
             {
                 simplifiedRing.pop_back();
             }

             // Validation
             const double simplifiedArea = calculateSignedArea(simplifiedRing);
             if (simplifiedRing.size() >= 3 &&
                 rawSignedArea * simplifiedArea > 0.0 &&
                 std::abs(simplifiedArea - rawSignedArea) <=
                     areaBudget * std::abs(rawSignedArea) + 1e-8 &&
                 !hasSelfIntersections(simplifiedRing))
             {
                 return simplifiedRing; // Success
             }
             epsilon *= 0.5; // Fallback
         }
         // Aggressive epsilon must not make a previously valid building vanish.
         if (rawRing.size() >= 3 && std::abs(rawSignedArea) > 1e-8 &&
             !hasSelfIntersections(rawRing)) return rawRing;
         return {};
     };

     result.projectedFootprint.outerRing = simplifyAndValidateRing(
         rawOuter, config.footprintSimplificationToleranceMetres);
     if (result.projectedFootprint.outerRing.empty())
     {
         result.errorMessage = "Failed to simplify outer ring into valid topology.";
         return result;
     }

     // A near-rectangular image-derived footprint may be regularized to its
     // dominant axes. Work in local metres to avoid float loss at UTM
     // eastings/northings. Preserve genuine concavity and all courtyards.
     if (config.regularizeRectangularFootprints)
     {
         const ProjectedPoint origin = rawOuter.front();
         std::vector<cv::Point2f> local;
         for (const auto& point : rawOuter)
             local.emplace_back(point.easting - origin.easting,
                                point.northing - origin.northing);
         const cv::RotatedRect box = cv::minAreaRect(local);
         const double boxArea = static_cast<double>(box.size.width) * box.size.height;
         const double rawArea = std::abs(calculateSignedArea(rawOuter));
         std::vector<cv::Point2f> hull;
         cv::convexHull(local, hull);
         const double hullArea = std::abs(cv::contourArea(hull));
         // Rectangle candidacy is governed by box fill, corner support, area,
         // final mask IoU and neighbour exclusion. Concavity alone is not a
         // veto because tree occlusion can create artificial recesses.
         cv::Point2f corners[4];
         box.points(corners);
         bool cornersSupported = true;
         const double halfPixelDiagonal = 0.5 * std::hypot(
             std::hypot(metadata.geoTransform[1], metadata.geoTransform[4]),
             std::hypot(metadata.geoTransform[2], metadata.geoTransform[5]));
         const double cornerSupportDistance =
             config.maxCornerAdjustmentMetres +
             config.footprintDilationMetres + halfPixelDiagonal;
         for (const auto& corner : corners)
         {
             if (std::abs(cv::pointPolygonTest(local, corner, true)) >
                 config.maxCornerAdjustmentMetres + 1e-6)
                 cornersSupported = false;

             // Check support against the observed instance, not only the
             // already-dilated outline.  This retains the requested removal
             // of the global convex-hull-solidity veto while preventing a
             // deep L/U-shaped recess from being paved into a rectangle.
             const double cornerE = origin.easting + corner.x;
             const double cornerN = origin.northing + corner.y;
             double nearestObserved = std::numeric_limits<double>::infinity();
             for (int row = static_cast<int>(by);
                  row < static_cast<int>(by + bh); ++row)
             {
                 for (int column = static_cast<int>(bx);
                      column < static_cast<int>(bx + bw); ++column)
                 {
                     if (labelRaster.data[
                             static_cast<std::size_t>(row) * labelRaster.width +
                             column] != stats.componentId)
                         continue;
                     const double centreE = metadata.geoTransform[0] +
                         (column + 0.5) * metadata.geoTransform[1] +
                         (row + 0.5) * metadata.geoTransform[2];
                     const double centreN = metadata.geoTransform[3] +
                         (column + 0.5) * metadata.geoTransform[4] +
                         (row + 0.5) * metadata.geoTransform[5];
                     nearestObserved = std::min(nearestObserved,
                         std::hypot(centreE - cornerE, centreN - cornerN));
                 }
             }
             if (nearestObserved > cornerSupportDistance + 1e-6)
                 cornersSupported = false;
         }

         double totalHolesArea = 0.0;
         for (const auto& hole : holeRings)
         {
             totalHolesArea += std::abs(calculateSignedArea(hole));
         }
         const double expectedOuterArea = referenceArea + totalHolesArea;

         // A building must be extremely close to its own convex hull to be treated as a basic rectangle.
         // This prevents E-shaped or U-shaped complexes from being paved over by a single 4-point bounding box.
         if (boxArea > 0.0 && rawArea / boxArea >= config.minimumRectangleFillRatio &&
             hullArea > 0.0 && rawArea / hullArea >= 0.96 && cornersSupported &&
             std::abs(boxArea - expectedOuterArea) <= config.footprintAreaDeviationTolerance * expectedOuterArea)
         {
             auto& ring = result.projectedFootprint.outerRing;
             ring.clear();
             for (const auto& corner : corners)
                 ring.push_back({origin.easting + corner.x, origin.northing + corner.y});
             if (calculateSignedArea(ring) < 0.0)
                 std::reverse(ring.begin(), ring.end());
             result.warnings.push_back("Near-rectangular footprint regularized to supported axes.");
         }
     }

     double finalProjectedArea = std::abs(calculateSignedArea(result.projectedFootprint.outerRing));

     if (config.regularizeSupportedEdges)
     {
         result.projectedFootprint.outerRing = regularizeEdges(
             result.projectedFootprint.outerRing,
             config.maxCornerAdjustmentMetres,
             config.footprintAreaDeviationTolerance);
         // CGAL can align several facade directions in one closed contour.
         // Keep the established fit when the candidate moves too far, changes
         // winding/area, or introduces a crossing.
         auto cgalRing =
             FootprintGeometryRegularizer::regularizeContourWithCgal(
                 result.projectedFootprint.outerRing,
                 config.maxCornerAdjustmentMetres,
                 config.footprintAreaDeviationTolerance);
         if (!cgalRing.empty() &&
             cgalRing.size() <= result.projectedFootprint.outerRing.size() &&
             !hasSelfIntersections(cgalRing))
             result.projectedFootprint.outerRing = std::move(cgalRing);
         finalProjectedArea = std::abs(calculateSignedArea(result.projectedFootprint.outerRing));
     }

     for (const auto& rawHole : holeRings)
     {
         std::vector<ProjectedPoint> validHole = simplifyAndValidateRing(
             rawHole, config.footprintSimplificationToleranceMetres);
         // Never silently pave a courtyard because simplification failed.
         // Retry the exact pixel-edge geometry before rejecting topology.
         if (validHole.empty()) validHole = rawHole;
         if (config.regularizeSupportedEdges)
         {
             validHole = regularizeEdges(
                 validHole,
                 config.maxCornerAdjustmentMetres,
                 config.footprintAreaDeviationTolerance);
             auto cgalHole =
                 FootprintGeometryRegularizer::regularizeContourWithCgal(
                     validHole, config.maxCornerAdjustmentMetres,
                     config.footprintAreaDeviationTolerance);
             if (!cgalHole.empty() && cgalHole.size() <= validHole.size() &&
                 !hasSelfIntersections(cgalHole))
                 validHole = std::move(cgalHole);
         }
         if (!isPointInPolygon(validHole[0], result.projectedFootprint.outerRing) ||
             ringsIntersect(validHole, result.projectedFootprint.outerRing))
         {
             result.projectedFootprint.outerRing = rawOuter;
             validHole = rawHole;
         }
         if (!isPointInPolygon(validHole[0], result.projectedFootprint.outerRing) ||
             ringsIntersect(validHole, result.projectedFootprint.outerRing))
         {
             result.errorMessage = "Courtyard topology cannot be preserved; refusing to fill the hole.";
             return result;
         }
         result.projectedFootprint.holes.push_back(std::move(validHole));
     }

     // Independently adjusted rings can collide. Validate the polygon as one
     // object, then retry all original rings together instead of losing an
     // otherwise valid building because its presentation fit was too strong.
     auto validCourtyards = [&]()
     {
         for (std::size_t i = 0; i < result.projectedFootprint.holes.size(); ++i)
         {
             const auto& hole = result.projectedFootprint.holes[i];
             if (!isPointInPolygon(hole[0], result.projectedFootprint.outerRing) ||
                 ringsIntersect(hole, result.projectedFootprint.outerRing)) return false;
             for (std::size_t j = 0; j < i; ++j)
             {
                 const auto& other = result.projectedFootprint.holes[j];
                 if (ringsIntersect(hole, other) || isPointInPolygon(hole[0], other) ||
                     isPointInPolygon(other[0], hole)) return false;
             }
         }
         return true;
     };
     if (!validCourtyards())
     {
         result.projectedFootprint.outerRing = rawOuter;
         result.projectedFootprint.holes = holeRings;
         result.warnings.push_back("Architectural fit conflicted with courtyards; retained observed boundaries.");
         if (!validCourtyards())
         {
             result.errorMessage = "Invalid courtyard topology in observed footprint.";
             return result;
         }
     }
     finalProjectedArea = std::abs(calculateSignedArea(result.projectedFootprint.outerRing));
     for (const auto& hole : result.projectedFootprint.holes)
         finalProjectedArea -= std::abs(calculateSignedArea(hole));

     //area Deviation Enforcement
     double areaDeviation = std::abs(finalProjectedArea - referenceArea) / referenceArea;
     if (areaDeviation > config.footprintAreaDeviationTolerance)
     {
         result.projectedFootprint.outerRing = rawOuter;
         result.projectedFootprint.holes = holeRings;
         finalProjectedArea = rawOuterArea;
         areaDeviation = std::abs(finalProjectedArea - referenceArea) / referenceArea;
         if (areaDeviation > config.footprintAreaDeviationTolerance)
         {
             result.errorMessage = "Observed footprint exceeds configured area tolerance.";
             return result;
         }
         std::erase(result.warnings,
             std::string("Near-rectangular footprint regularized to supported axes."));
         result.warnings.push_back("Architectural fit exceeded area tolerance; retained observed boundary.");
     }

     if (opticalLines != nullptr && !opticalLines->empty())
     {
         const auto previous = result.projectedFootprint.outerRing;
         auto snapped = snapToOpticalLines(
             previous, *opticalLines, metadata,
             config.maxCornerAdjustmentMetres);
         const double previousArea = calculateSignedArea(previous);
         const double snappedArea = calculateSignedArea(snapped);
         double snappedNetArea = std::abs(snappedArea);
         for (const auto& hole : result.projectedFootprint.holes)
             snappedNetArea -= std::abs(calculateSignedArea(hole));
         if (snapped.size() == previous.size() &&
             previousArea * snappedArea > 0.0 &&
             !hasSelfIntersections(snapped) &&
             std::abs(snappedArea - previousArea) <=
                 0.05 * std::abs(previousArea) &&
             std::abs(snappedNetArea - referenceArea) <=
                 config.footprintAreaDeviationTolerance * referenceArea)
         {
             result.projectedFootprint.outerRing = std::move(snapped);
             if (!validCourtyards())
                 result.projectedFootprint.outerRing = previous;
         }
     }

     //Generate Corresponding Pixel Polygon (Preserves exact Projected Vertex Correspondence)
     auto buildPixelRing = [&](const std::vector<ProjectedPoint>& projRing) -> std::vector<PixelPoint>
     {
         std::vector<PixelPoint> pixRing;
         double invDet = metadata.geoTransform[1] * metadata.geoTransform[5] - metadata.geoTransform[2] * metadata.geoTransform[4];
         double invGT1 = metadata.geoTransform[5] / invDet;
         double invGT2 = -metadata.geoTransform[2] / invDet;
         double invGT4 = -metadata.geoTransform[4] / invDet;
         double invGT5 = metadata.geoTransform[1] / invDet;

         for (const auto& pt : projRing)
         {
             double dE = pt.easting - metadata.geoTransform[0];
             double dN = pt.northing - metadata.geoTransform[3];
             pixRing.push_back({ (invGT1 * dE + invGT2 * dN), (invGT4 * dE + invGT5 * dN) });
         }
         return pixRing;
     };

     // Check the final footprint against the original instance pixels. Area
     // alone misses a shifted polygon of the same size, and a sharp facade is
     // not useful if it steals another labelled roof. Pixel centres match the
     // source raster's cell-edge polygon convention.
     bool initialNeighbourOverlap = false;
     auto fitsInstance = [&](const FootprintPolygon<ProjectedPoint>& polygon,
                             bool& coversNeighbour) -> bool
     {
         std::vector<cv::Point2f> pixelOuter;
         for (const auto& p : buildPixelRing(polygon.outerRing))
             pixelOuter.emplace_back(p.column, p.row);
         if (pixelOuter.size() < 3) return false;

         std::vector<std::vector<cv::Point2f>> pixelHoles;
         for (const auto& ring : polygon.holes)
         {
             auto& hole = pixelHoles.emplace_back();
             for (const auto& p : buildPixelRing(ring))
                 hole.emplace_back(p.column, p.row);
         }

         const cv::Rect bounds = cv::boundingRect(pixelOuter) &
             cv::Rect(0, 0, labelRaster.width, labelRaster.height);
         std::size_t candidatePixels = 0, matchingPixels = 0, neighbourPixels = 0;
         coversNeighbour = false;
         for (int row = bounds.y; row < bounds.y + bounds.height; ++row)
         {
             for (int col = bounds.x; col < bounds.x + bounds.width; ++col)
             {
                 const cv::Point2f centre(col + 0.5f, row + 0.5f);
                 if (cv::pointPolygonTest(pixelOuter, centre, false) <= 0) continue;
                 bool inHole = false;
                 for (const auto& hole : pixelHoles)
                     if (cv::pointPolygonTest(hole, centre, false) >= 0)
                     { inHole = true; break; }
                 if (inHole) continue;
                 ++candidatePixels;
                 const auto label = labelRaster.data[
                     static_cast<std::size_t>(row) * labelRaster.width + col];
                 if (isMasked(col, row)) ++matchingPixels;
                 if (label > 0 && label != stats.componentId) ++neighbourPixels;
             }
         }
         const double neighbourRatio = stats.pixelCount > 0 ?
             static_cast<double>(neighbourPixels) / stats.pixelCount : 0.0;
         const bool isBoundingBox = std::any_of(result.warnings.begin(), result.warnings.end(),
             [](const std::string& w) { return w.find("Near-rectangular") != std::string::npos; });
         const double maxNeighbourRatio = (isBoundingBox || initialNeighbourOverlap) ? 0.0 : 0.20;
         coversNeighbour = (neighbourRatio > maxNeighbourRatio);
         const std::size_t unionPixels =
             dilatedPixelCount + candidatePixels - matchingPixels;
         const double pixelIoU = unionPixels > 0
             ? static_cast<double>(matchingPixels) / unionPixels : 0.0;
         const double requiredIoU =
             static_cast<double>(config.minimumFootprintMaskIoU);
         return !coversNeighbour && pixelIoU >= requiredIoU;
     };

     bool coversNeighbour = false;
     // GEOS simplifies the complete polygon, including its courtyards, as a
     // single topology. Admit its candidate only when the same pixel and
     // neighbour checks used for the architectural fit still pass.
     const auto beforeGeos = result.projectedFootprint;
     auto geosCandidate =
         FootprintGeometryRegularizer::simplifyPolygonWithGeos(
             beforeGeos,
             std::min(1.0, 0.25 *
                 static_cast<double>(config.footprintSimplificationToleranceMetres)));
     const auto vertexCount = [](const auto& polygon)
     {
         std::size_t count = polygon.outerRing.size();
         for (const auto& hole : polygon.holes) count += hole.size();
         return count;
     };
     if (!geosCandidate.outerRing.empty() &&
         vertexCount(geosCandidate) < vertexCount(beforeGeos))
     {
         const auto netArea = [&](const auto& polygon)
         {
             double area = std::abs(calculateSignedArea(polygon.outerRing));
             for (const auto& hole : polygon.holes)
                 area -= std::abs(calculateSignedArea(hole));
             return area;
         };
         const double oldArea = netArea(beforeGeos);
         const double newArea = netArea(geosCandidate);
         if (oldArea > 0.0 &&
             std::abs(newArea - oldArea) <= 0.05 * oldArea &&
             std::abs(newArea - referenceArea) <=
                 config.footprintAreaDeviationTolerance * referenceArea)
         {
             result.projectedFootprint = std::move(geosCandidate);
             bool geosCoversNeighbour = false;
             if (!validCourtyards() ||
                 !fitsInstance(result.projectedFootprint,
                               geosCoversNeighbour))
                 result.projectedFootprint = beforeGeos;
         }
     }
     if (!fitsInstance(result.projectedFootprint, coversNeighbour))
     {
         initialNeighbourOverlap = coversNeighbour;
         std::erase(result.warnings,
             std::string("Near-rectangular footprint regularized to supported axes."));
         bool foundSupportedFit = false;

         // Do not discard every straight facade because one corner crossed a
         // neighbouring label. Retry RDP at progressively smaller metric
         // tolerances, preserving all courtyards and the same pixel-level
         // alignment check. The exact observed cell boundary is the last resort.
         for (double scale : {1.0, 0.75, 0.5, 0.25, 0.125})
         {
             FootprintPolygon<ProjectedPoint> trial;
             const double epsilon =
                 scale * config.footprintSimplificationToleranceMetres;
             trial.outerRing = simplifyAndValidateRing(rawOuter, epsilon);
             for (const auto& rawHole : holeRings)
                 trial.holes.push_back(simplifyAndValidateRing(rawHole, epsilon));
             if (trial.outerRing.size() < 3 ||
                 std::any_of(trial.holes.begin(), trial.holes.end(),
                     [](const auto& hole) { return hole.size() < 3; })) continue;

             result.projectedFootprint = std::move(trial);
             double trialArea = std::abs(calculateSignedArea(result.projectedFootprint.outerRing));
             for (const auto& hole : result.projectedFootprint.holes)
                 trialArea -= std::abs(calculateSignedArea(hole));
             if (!validCourtyards() ||
                 std::abs(trialArea - referenceArea) >
                     config.footprintAreaDeviationTolerance * referenceArea) continue;
             if (!fitsInstance(result.projectedFootprint, coversNeighbour)) continue;
             foundSupportedFit = true;
             break;
         }

         if (foundSupportedFit)
             result.warnings.push_back(
                 "Architectural fit refined to preserve neighbouring roofs and observed pixels.");
         else
         {
             result.projectedFootprint.outerRing = rawOuter;
             result.projectedFootprint.holes = holeRings;
             result.warnings.push_back(initialNeighbourOverlap
                 ? "Architectural fit overlapped a neighbouring instance; retained observed boundary."
                 : "Architectural fit moved off instance pixels; retained observed boundary.");
         }
     }

     result.pixelFootprint.outerRing = buildPixelRing(result.projectedFootprint.outerRing);
     for (const auto& hRing : result.projectedFootprint.holes)
         result.pixelFootprint.holes.push_back(buildPixelRing(hRing));

     result.success = true;
     return result;
}
