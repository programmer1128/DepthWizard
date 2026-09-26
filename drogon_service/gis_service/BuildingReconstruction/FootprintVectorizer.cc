#include "FootprintVectorizer.h"
#include <opencv2/opencv.hpp>
#include <cmath>
#include <algorithm>
#include <utility>
#include <limits>
#include <unordered_map>
#include <cstdint>
#include <cstddef>
#include <numbers>

std::vector<ProjectedPoint> FootprintVectorizer::regularizeEdges(
    const std::vector<ProjectedPoint>& ring, double maxShift)
{
    if (ring.size() < 4 || maxShift <= 0) return ring;

    // Only long observed edges vote for an architectural orientation. A roof
    // can be rotated relative to the image; the fourfold angle treats both
    // orthogonal wall directions as one axis without assuming north-up walls.
    constexpr double quarterTurn = std::numbers::pi / 2;
    struct EdgeVote { double angle, length; };
    std::vector<EdgeVote> votes;
    double totalLength = 0.0;
    for (std::size_t i = 0; i < ring.size(); ++i) {
        const auto& a = ring[i]; const auto& b = ring[(i + 1) % ring.size()];
        const double dx = b.easting - a.easting, dy = b.northing - a.northing;
        const double length = std::hypot(dx, dy);
        if (length < std::max(2.0, 2.0 * maxShift)) continue;
        votes.push_back({std::atan2(dy, dx), length});
        totalLength += length;
    }
    if (votes.size() < 2) return ring;

    // A large complex roof may have several genuine orientations. A global
    // vector average cancels them and disables every right-angle fit. Find
    // the best-supported local pair of perpendicular facade directions;
    // leave unsupported wings and diagonal edges unchanged.
    double bestSupport = 0.0, bestAngle = 0.0;
    for (const auto& candidate : votes) {
        double support = 0.0;
        for (const auto& edge : votes)
            if (std::cos(4 * (edge.angle - candidate.angle)) >= 0.5)
                support += edge.length;
        if (support > bestSupport) {
            bestSupport = support;
            bestAngle = candidate.angle;
        }
    }
    if (bestSupport < .40 * totalLength) return ring;
    double sx = 0.0, sy = 0.0;
    for (const auto& edge : votes)
        if (std::cos(4 * (edge.angle - bestAngle)) >= 0.5) {
            sx += edge.length * std::cos(4 * edge.angle);
            sy += edge.length * std::sin(4 * edge.angle);
        }
    const double orientation = std::atan2(sy, sx) / 4;
    struct Line { double x, y, dx, dy; };
    std::vector<Line> lines(ring.size());
    std::vector<bool> supported(ring.size(), false);
    const auto origin = ring.front();
    for (std::size_t i = 0; i < ring.size(); ++i) {
        const auto& a = ring[i]; const auto& b = ring[(i + 1) % ring.size()];
        const double dx = b.easting - a.easting, dy = b.northing - a.northing;
        const double length = std::hypot(dx, dy);
        if (length < 1e-8) return ring;
        const double angle = std::atan2(dy, dx);
        const double fitted = orientation + std::round((angle - orientation) / quarterTurn) * quarterTurn;
        // Long segments near the consensus axis may be straightened. Genuine
        // diagonals and short facade details keep their original direction.
        supported[i] = length >= std::max(2.0, 2.0 * maxShift) &&
            std::abs(fitted - angle) <= std::numbers::pi / 9;
        lines[i] = {(a.easting + b.easting) / 2 - origin.easting,
                    (a.northing + b.northing) / 2 - origin.northing,
                    std::cos(fitted), std::sin(fitted)};
    }

    std::vector<ProjectedPoint> candidate = ring;
    std::vector<bool> removed(ring.size(), false);
    bool changedAny = false;
    for (std::size_t i = 0; i < ring.size(); ++i) {
        if (!supported[i] || removed[(i + 1) % ring.size()]) continue;
        std::size_t j = (i + 1) % ring.size();
        double gapLength = 0.0;
        std::size_t gapEdges = 0;
        while (!supported[j] && gapEdges < 6) {
            const auto& start = ring[j];
            const auto& end = ring[(j + 1) % ring.size()];
            const double dx = end.easting - start.easting;
            const double dy = end.northing - start.northing;
            gapLength += std::hypot(dx, dy);
            const double angle = std::atan2(dy, dx);
            const double nearestAxis = orientation +
                std::round((angle - orientation) / quarterTurn) * quarterTurn;
            // A short edge parallel to the facade may form a real narrow
            // wing or courtyard step. Only bridge unsupported chamfers.
            if (std::abs(nearestAxis - angle) <= std::numbers::pi / 12 ||
                gapLength > 2.0 * maxShift) break;
            j = (j + 1) % ring.size();
            ++gapEdges;
        }
        if (!supported[j] || j == i || removed[j]) continue;

        const auto& a = lines[i];
        const auto& b = lines[j];
        const double det = a.dx * b.dy - a.dy * b.dx;
        // Only perpendicular supporting walls define a reliable square corner.
        if (std::abs(det) < .8) continue;
        const double t = ((b.x - a.x) * b.dy - (b.y - a.y) * b.dx) / det;
        ProjectedPoint p{origin.easting + a.x + t * a.dx, origin.northing + a.y + t * a.dy};
        if (!std::isfinite(p.easting) || !std::isfinite(p.northing)) continue;
        bool supportedCorner = true;
        for (std::size_t k = (i + 1) % ring.size(); ; k = (k + 1) % ring.size()) {
            if (std::hypot(p.easting - ring[k].easting,
                           p.northing - ring[k].northing) > maxShift) {
                supportedCorner = false;
                break;
            }
            if (k == j) break;
        }
        if (!supportedCorner) continue;

        candidate[(i + 1) % ring.size()] = p;
        for (std::size_t k = (i + 2) % ring.size(); k != (j + 1) % ring.size();
             k = (k + 1) % ring.size())
            removed[k] = true;
        changedAny = true;
    }
    if (!changedAny) return ring;
    std::vector<ProjectedPoint> output;
    output.reserve(ring.size());
    for (std::size_t i = 0; i < ring.size(); ++i)
        if (!removed[i]) output.push_back(candidate[i]);
    const double area = calculateSignedArea(ring), changed = calculateSignedArea(output);
    if (output.size() < 3 || area * changed <= 0 ||
        std::abs(changed - area) > .05 * std::abs(area) ||
        hasSelfIntersections(output)) return ring;
    return output;
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
     const BuildingReconstructionConfig& config)
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

     //Exact Raster-Cell Edge Polygonization (Replaces OpenCV findContours)
     std::unordered_map<int64_t, int64_t> edgeMap;
     auto encodeNode = [](int32_t x, int32_t y) -> int64_t { return (static_cast<int64_t>(y) << 32) | static_cast<uint32_t>(x); };
     auto decodeNode = [](int64_t val, int32_t& x, int32_t& y) { y = static_cast<int32_t>(val >> 32); x = static_cast<int32_t>(val & 0xFFFFFFFF); };
    
     auto addEdge = [&](int32_t x1, int32_t y1, int32_t x2, int32_t y2) 
     {
         edgeMap[encodeNode(x1, y1)] = encodeNode(x2, y2);
     };

     auto isMasked = [&](int32_t c, int32_t r) -> bool {
         if (c < bx || r < by || c >= bx + bw || r >= by + bh) return false;
         std::size_t offset = static_cast<std::size_t>(r) * labelRaster.width + c;
         return labelRaster.data[offset] == stats.componentId;
     };

     // Scan ROI to extract unshared exterior cell edges
     for (int32_t r = by; r < by + bh; ++r) 
     {
         for (int32_t c = bx; c < bx + bw; ++c) 
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

     //Assemble Rings from Edge Map
     std::vector<std::vector<ProjectedPoint>> rawRings;
     while (!edgeMap.empty()) 
     {
         auto it = edgeMap.begin();
         int64_t startNode = it->first;
         int64_t currNode = startNode;
        
         std::vector<ProjectedPoint> ring;
         do 
         {
             int32_t px, py;
             decodeNode(currNode, px, py);
            
             // Generate Project Corner Coordinate exactly
             double E = metadata.geoTransform[0] + px * metadata.geoTransform[1] + py * metadata.geoTransform[2];
             double N = metadata.geoTransform[3] + px * metadata.geoTransform[4] + py * metadata.geoTransform[5];
             ring.push_back({E, N});
            
             int64_t nextNode = edgeMap[currNode];
             edgeMap.erase(currNode);
             currNode = nextNode;
         } 
         while (currNode != startNode && edgeMap.count(currNode));
        
         if (ring.size() >= 3) 
         {
             rawRings.push_back(ring);
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

     //Metric RDP Simplification with Validation
     auto simplifyAndValidateRing = [&](const std::vector<ProjectedPoint>& rawRing,
                                        double initialEpsilon) -> std::vector<ProjectedPoint>
     {
         double epsilon = initialEpsilon;
         std::vector<ProjectedPoint> simplifiedRing;
        
         ProjectedPoint centroid = {0.0, 0.0};
         for (const auto& p : rawRing) 
         { 
             centroid.easting += p.easting; 
             centroid.northing += p.northing; 
         }
         centroid.easting /= rawRing.size(); centroid.northing /= rawRing.size();

         const double rawSignedArea = calculateSignedArea(rawRing);
         const double areaBudget = std::min(0.05,
             static_cast<double>(config.footprintAreaDeviationTolerance));

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
     if (config.regularizeRectangularFootprints && holeRings.empty())
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

         // A high box fill alone also accepts L/U/E-shaped buildings. Require
         // near-convex evidence so those architectural recesses stay intact.
         // Rounded convex rectangles can still qualify at the looser fill ratio.
         cv::Point2f corners[4];
         box.points(corners);
         bool cornersSupported = true;
         for (const auto& corner : corners)
         {
             if (std::abs(cv::pointPolygonTest(local, corner, true)) >
                 config.maxCornerAdjustmentMetres + 1e-6)
                 cornersSupported = false;
         }
         if (boxArea > 0.0 && rawArea / boxArea >= config.minimumRectangleFillRatio &&
             hullArea > 0.0 && rawArea / hullArea >= 0.96 && cornersSupported &&
             std::abs(boxArea - stats.physicalAreaSquareMetres) <=
                 config.footprintAreaDeviationTolerance * stats.physicalAreaSquareMetres)
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
             result.projectedFootprint.outerRing, config.maxCornerAdjustmentMetres);
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
             validHole = regularizeEdges(validHole, config.maxCornerAdjustmentMetres);
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
     double areaDeviation = std::abs(finalProjectedArea - stats.physicalAreaSquareMetres) / stats.physicalAreaSquareMetres;
     if (areaDeviation > config.footprintAreaDeviationTolerance) 
     {
         result.projectedFootprint.outerRing = rawOuter;
         result.projectedFootprint.holes = holeRings;
         finalProjectedArea = std::abs(calculateSignedArea(rawOuter));
         for (const auto& hole : holeRings)
             finalProjectedArea -= std::abs(calculateSignedArea(hole));
         areaDeviation = std::abs(finalProjectedArea - stats.physicalAreaSquareMetres) /
             stats.physicalAreaSquareMetres;
         if (areaDeviation > config.footprintAreaDeviationTolerance)
         {
             result.errorMessage = "Observed footprint exceeds configured area tolerance.";
             return result;
         }
         std::erase(result.warnings,
             std::string("Near-rectangular footprint regularized to supported axes."));
         result.warnings.push_back("Architectural fit exceeded area tolerance; retained observed boundary.");
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
         std::size_t candidatePixels = 0, matchingPixels = 0;
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
                 if (label == stats.componentId) ++matchingPixels;
                 else if (label > 0) coversNeighbour = true;
             }
         }
         const std::size_t unionPixels =
             static_cast<std::size_t>(stats.pixelCount) + candidatePixels - matchingPixels;
         const double pixelIoU = unionPixels > 0
             ? static_cast<double>(matchingPixels) / unionPixels : 0.0;
         return !coversNeighbour && pixelIoU >= config.minimumFootprintMaskIoU;
     };

     bool coversNeighbour = false;
     if (!fitsInstance(result.projectedFootprint, coversNeighbour))
     {
         const bool initialNeighbourOverlap = coversNeighbour;
         bool foundSupportedFit = false;

         // Do not discard every straight facade because one corner crossed a
         // neighbouring label. Retry RDP at progressively smaller metric
         // tolerances, preserving all courtyards and the same pixel-level
         // alignment check. The exact observed cell boundary is the last resort.
         for (double scale : {0.75, 0.5, 0.25, 0.125})
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
                 std::abs(trialArea - stats.physicalAreaSquareMetres) >
                     config.footprintAreaDeviationTolerance *
                         stats.physicalAreaSquareMetres) continue;
             if (!fitsInstance(result.projectedFootprint, coversNeighbour)) continue;
             foundSupportedFit = true;
             break;
         }

         std::erase(result.warnings,
             std::string("Near-rectangular footprint regularized to supported axes."));
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
