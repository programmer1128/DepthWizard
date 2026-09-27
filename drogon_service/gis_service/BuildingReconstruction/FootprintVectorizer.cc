#include "FootprintVectorizer.h"
#include <opencv2/opencv.hpp>
#include <cmath>
#include <algorithm>
#include <utility>
#include <limits>
#include <unordered_map>
#include <cstdint>
#include <cstddef>

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

std::vector<ProjectedPoint> FootprintVectorizer::regularizeEdges(
    const std::vector<ProjectedPoint>& ring,
    double area,
    const BuildingReconstructionConfig& config)
{
    if (ring.size() < 3) return ring;

    std::vector<cv::Point2f> pts;
    pts.reserve(ring.size());
    for (const auto& p : ring) 
    {
        pts.push_back(cv::Point2f(static_cast<float>(p.easting), static_cast<float>(p.northing)));
    }

    // Generate minimum bounding rectangle to square off the facade
    cv::RotatedRect rect = cv::minAreaRect(pts);
    cv::Point2f rectPts[4];
    rect.points(rectPts);

    std::vector<ProjectedPoint> output;
    for (int i = 0; i < 4; ++i) 
    {
        output.push_back({rectPts[i].x, rectPts[i].y});
    }

    double changed = std::abs(calculateSignedArea(output));

    // Area deviation threshold relaxed to 10% to prevent silently reverting to raw pixels
    if (output.size() < 3 || area * changed <= 0 ||
        std::abs(changed - area) > .10 * std::abs(area) || 
        hasSelfIntersections(output)) 
    {
        return ring;
    }

    // Enforce the original orientation winding
    if ((calculateSignedArea(ring) > 0) != (calculateSignedArea(output) > 0)) 
    {
        std::reverse(output.begin(), output.end());
    }

    return output;
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
     auto simplifyAndValidateRing = [&](const std::vector<ProjectedPoint>& rawRing) -> std::vector<ProjectedPoint> 
     {
         double epsilon = config.footprintSimplificationToleranceMetres;
         std::vector<ProjectedPoint> simplifiedRing;
        
         ProjectedPoint centroid = {0.0, 0.0};
         for (const auto& p : rawRing) 
         { 
             centroid.easting += p.easting; 
             centroid.northing += p.northing; 
         }
         centroid.easting /= rawRing.size(); centroid.northing /= rawRing.size();

         for (int attempts = 0; attempts < 4; ++attempts) 
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
             if (simplifiedRing.size() >= 3 && !hasSelfIntersections(simplifiedRing)) 
             {
                 return simplifiedRing; // Success
             }
             epsilon *= 0.5; // Fallback
         }
         return {}; // Failed all validation
     };

     result.projectedFootprint.outerRing = simplifyAndValidateRing(rawOuter);
     if (result.projectedFootprint.outerRing.empty()) 
     {
         result.errorMessage = "Failed to simplify outer ring into valid topology.";
         return result;
     }

     double finalProjectedArea = std::abs(calculateSignedArea(result.projectedFootprint.outerRing)); 

     // --- REGULARIZE OUTER RING ---
     // Removed holeRings.empty() condition so courtyard buildings still regularize
     if (config.regularizeRectangularFootprints) 
     {
         result.projectedFootprint.outerRing = regularizeEdges(result.projectedFootprint.outerRing, finalProjectedArea, config);
         finalProjectedArea = std::abs(calculateSignedArea(result.projectedFootprint.outerRing));
     }

     for (const auto& rawHole : holeRings) 
     {
         std::vector<ProjectedPoint> validHole = simplifyAndValidateRing(rawHole);
         if (!validHole.empty()) 
         {
             // --- REGULARIZE COURTYARDS (HOLES) ---
             if (config.regularizeRectangularFootprints) 
             {
                 double holeArea = std::abs(calculateSignedArea(validHole));
                 validHole = regularizeEdges(validHole, holeArea, config);
             }

             // Hole Topological Constraints
             if (isPointInPolygon(validHole[0], result.projectedFootprint.outerRing) && 
                 !ringsIntersect(validHole, result.projectedFootprint.outerRing)) 
             {
                 result.projectedFootprint.holes.push_back(validHole);
                 finalProjectedArea -= std::abs(calculateSignedArea(validHole));
             }
         }
     }

     //area Deviation Enforcement
     double areaDeviation = std::abs(finalProjectedArea - stats.physicalAreaSquareMetres) / stats.physicalAreaSquareMetres;
     if (areaDeviation > config.footprintAreaDeviationTolerance) 
     {
         result.errorMessage = "Simplification resulted in excessive area deviation exceeding configured tolerance.";
         return result; // Reject heavily distorted rings
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

     result.pixelFootprint.outerRing = buildPixelRing(result.projectedFootprint.outerRing);
     for (const auto& hRing : result.projectedFootprint.holes) 
     {
         result.pixelFootprint.holes.push_back(buildPixelRing(hRing));
     }

     result.success = true;
     return result;
}