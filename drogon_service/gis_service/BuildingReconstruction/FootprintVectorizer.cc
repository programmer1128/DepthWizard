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
    const std::vector<ProjectedPoint>& ring,
    double maxShift,
    double areaDeviationTolerance)
{
    if (ring.size() < 4 || maxShift <= 0.0) return ring;

    // STEP 2.1: Dominant Orientation Estimation
    // For each polygon ring, examine edges with length L_i >= 2.0 metres.
    constexpr double quarterTurn = std::numbers::pi / 2.0;
    constexpr double halfQuarterTurn = std::numbers::pi / 4.0;
    constexpr double cos80 = 0.17364817766693033; // cos(4 * 20 deg)

    struct QualifyingEdge {
        double angle;
        double length;
    };
    std::vector<QualifyingEdge> edges;
    double totalLength = 0.0;
    for (std::size_t i = 0; i < ring.size(); ++i) {
        const auto& a = ring[i];
        const auto& b = ring[(i + 1) % ring.size()];
        const double dx = b.easting - a.easting;
        const double dy = b.northing - a.northing;
        const double length = std::hypot(dx, dy);
        if (length < 2.0) continue;
        edges.push_back({std::atan2(dy, dx), length});
        totalLength += length;
    }
    if (edges.empty() || totalLength < 1e-6) return ring;

    // Find the candidate orientation angle phi* with maximum length-weighted support
    double bestSupport = 0.0;
    double bestAngle = 0.0;
    for (const auto& candidate : edges) {
        double support = 0.0;
        for (const auto& e : edges) {
            if (std::cos(4.0 * (e.angle - candidate.angle)) >= cos80) {
                support += e.length;
            }
        }
        if (support > bestSupport) {
            bestSupport = support;
            bestAngle = candidate.angle;
        }
    }

    // Only perform Manhattan orthogonalization when at least 15% of qualifying edge-length
    // support is consistent with the dominant orthogonal orientation.
    if (bestSupport < 0.15 * totalLength) return ring;

    // Refine dominant Manhattan orientation theta using four-fold formula over dominant cluster
    double S = 0.0;
    double C = 0.0;
    for (const auto& e : edges) {
        if (std::cos(4.0 * (e.angle - bestAngle)) >= cos80) {
            S += e.length * std::sin(4.0 * e.angle);
            C += e.length * std::cos(4.0 * e.angle);
        }
    }
    double theta = 0.25 * std::atan2(S, C);
    // Normalize theta to [-pi/4, pi/4]
    while (theta > halfQuarterTurn) theta -= quarterTurn;
    while (theta < -halfQuarterTurn) theta += quarterTurn;

    // Confirm support for refined theta
    double refinedSupport = 0.0;
    for (const auto& e : edges) {
        if (std::cos(4.0 * (e.angle - theta)) >= cos80) {
            refinedSupport += e.length;
        }
    }
    if (refinedSupport < 0.15 * totalLength) return ring;

    // STEP 2.2: Rotate into Manhattan frame (-theta relative to centroid)
    ProjectedPoint centroid{0.0, 0.0};
    for (const auto& pt : ring) {
        centroid.easting += pt.easting;
        centroid.northing += pt.northing;
    }
    centroid.easting /= ring.size();
    centroid.northing /= ring.size();

    const double cosTheta = std::cos(theta);
    const double sinTheta = std::sin(theta);

    struct LocalPt { double u, v; };
    std::vector<LocalPt> localPts;
    localPts.reserve(ring.size());
    for (const auto& pt : ring) {
        const double rx = pt.easting - centroid.easting;
        const double ry = pt.northing - centroid.northing;
        localPts.push_back({
            rx * cosTheta + ry * sinTheta,
            -rx * sinTheta + ry * cosTheta
        });
    }

    // STEP 2.3: Strict Orthogonal Step Insertion
    std::vector<LocalPt> stepped;
    LocalPt current = localPts[0];
    stepped.push_back(current);

    const std::size_t numLocal = localPts.size();
    for (std::size_t i = 0; i < numLocal; ++i) {
        LocalPt target = localPts[(i + 1) % numLocal];
        const double du = std::abs(target.u - current.u);
        const double dv = std::abs(target.v - current.v);
        const double edgeLen = std::hypot(target.u - current.u, target.v - current.v);

        if (du < 1e-4) {
            // Already vertical
            target.u = current.u;
            if (i < numLocal - 1) {
                stepped.push_back(target);
                current = target;
            } else {
                stepped.back().u = stepped[0].u;
            }
        } else if (dv < 1e-4) {
            // Already horizontal
            target.v = current.v;
            if (i < numLocal - 1) {
                stepped.push_back(target);
                current = target;
            } else {
                stepped.back().v = stepped[0].v;
            }
        } else if (edgeLen >= 3.0 && du > 1e-3 && dv > 1e-3 &&
                   std::min(du, dv) / std::max(du, dv) > 0.36) {
            // Genuine diagonal edge (angle between ~20 deg and 70 deg to axes, length >= 3.0m):
            // Preserve the diagonal wall rather than forcing an artificial 90-degree step.
            if (i < numLocal - 1) {
                stepped.push_back(target);
                current = target;
            }
        } else if (du >= dv) {
            // Predominantly horizontal: insert (target.u, current.v) then target
            LocalPt mid{target.u, current.v};
            stepped.push_back(mid);
            if (i < numLocal - 1) {
                stepped.push_back(target);
                current = target;
            }
        } else {
            // Predominantly vertical: insert (current.u, target.v) then target
            LocalPt mid{current.u, target.v};
            stepped.push_back(mid);
            if (i < numLocal - 1) {
                stepped.push_back(target);
                current = target;
            }
        }
    }

    // STEP 2.4: Collinear and duplicate vertex pruning helper
    auto pruneCollinearAndDuplicates = [](std::vector<LocalPt>& pts) {
        bool changed = true;
        for (int iter = 0; iter < 100 && changed && pts.size() >= 3; ++iter) {
            changed = false;

            // 1. Collinear vertices along U or V axis
            for (std::size_t i = 0; i < pts.size(); ++i) {
                if (pts.size() <= 3) break;
                const std::size_t prevIdx = (i + pts.size() - 1) % pts.size();
                const std::size_t nextIdx = (i + 1) % pts.size();
                const auto& A = pts[prevIdx];
                const auto& B = pts[i];
                const auto& C = pts[nextIdx];

                constexpr double eps = 1e-3;
                const bool collinearU = (std::abs(A.u - B.u) < eps && std::abs(B.u - C.u) < eps);
                const bool collinearV = (std::abs(A.v - B.v) < eps && std::abs(B.v - C.v) < eps);

                if (collinearU || collinearV) {
                    pts.erase(pts.begin() + i);
                    changed = true;
                    break;
                }
            }
            if (changed) continue;

            // 2. Near-duplicate vertices (< 0.2m)
            for (std::size_t i = 0; i < pts.size(); ++i) {
                if (pts.size() <= 3) break;
                const std::size_t nextIdx = (i + 1) % pts.size();
                const double dist = std::hypot(pts[nextIdx].u - pts[i].u,
                                               pts[nextIdx].v - pts[i].v);
                if (dist < 0.2) {
                    pts.erase(pts.begin() + nextIdx);
                    changed = true;
                    break;
                }
            }
        }
    };

    // Initial pruning pass
    pruneCollinearAndDuplicates(stepped);

    // STEP 2.4.1: LOD1 short-edge collapse. Fifteen bounded passes remove
    // orthogonal raster staircases shorter than five metres while the final
    // topology, area, mask-overlap and neighbouring-instance checks still
    // reject an unsupported result. A four/six-corner ring is already a
    // compact architectural primitive (rectangle or L-shape), not a raster
    // staircase; do not erase its intentional wing/recess.
    const bool hasRasterStaircase = stepped.size() > 6;
    for (int pass = 0;
         hasRasterStaircase && pass < 15 && stepped.size() > 4;
         ++pass) {
        double minLen = 2.5;
        std::size_t bestIdx = stepped.size();

        for (std::size_t i = 0; i < stepped.size(); ++i) {
            const std::size_t nextIdx = (i + 1) % stepped.size();
            const std::size_t prevIdx = (i + stepped.size() - 1) % stepped.size();
            const std::size_t afterNextIdx = (nextIdx + 1) % stepped.size();

            const bool isVert = std::abs(stepped[nextIdx].u - stepped[i].u) < 1e-3;
            const bool isHoriz = std::abs(stepped[nextIdx].v - stepped[i].v) < 1e-3;
            if (!isVert && !isHoriz) continue;

            const bool prevIsHoriz = std::abs(stepped[i].v - stepped[prevIdx].v) < 1e-3;
            const bool prevIsVert = std::abs(stepped[i].u - stepped[prevIdx].u) < 1e-3;
            const bool nextIsHoriz = std::abs(stepped[afterNextIdx].v - stepped[nextIdx].v) < 1e-3;
            const bool nextIsVert = std::abs(stepped[afterNextIdx].u - stepped[nextIdx].u) < 1e-3;

            if (isVert && (!prevIsHoriz || !nextIsHoriz)) continue;
            if (isHoriz && (!prevIsVert || !nextIsVert)) continue;

            const double edgeLen = std::hypot(stepped[nextIdx].u - stepped[i].u,
                                              stepped[nextIdx].v - stepped[i].v);
            if (edgeLen < minLen) {
                minLen = edgeLen;
                bestIdx = i;
            }
        }

        if (bestIdx >= stepped.size()) break; // No collapsible staircase edges < 2.5m remaining

        const std::size_t i = bestIdx;
        const std::size_t nextIdx = (i + 1) % stepped.size();
        const std::size_t prevIdx = (i + stepped.size() - 1) % stepped.size();
        const std::size_t afterNextIdx = (nextIdx + 1) % stepped.size();

        const bool isVertical = std::abs(stepped[nextIdx].u - stepped[i].u) < 1e-3;

        if (isVertical) {
            const double L0 = std::abs(stepped[i].u - stepped[prevIdx].u);
            const double L2 = std::abs(stepped[afterNextIdx].u - stepped[nextIdx].u);
            if (L0 >= L2) {
                stepped[afterNextIdx].v = stepped[prevIdx].v;
            } else {
                stepped[prevIdx].v = stepped[afterNextIdx].v;
            }
        } else {
            const double L0 = std::abs(stepped[i].v - stepped[prevIdx].v);
            const double L2 = std::abs(stepped[afterNextIdx].v - stepped[nextIdx].v);
            if (L0 >= L2) {
                stepped[afterNextIdx].u = stepped[prevIdx].u;
            } else {
                stepped[prevIdx].u = stepped[afterNextIdx].u;
            }
        }

        if (nextIdx > i) {
            stepped.erase(stepped.begin() + nextIdx);
            stepped.erase(stepped.begin() + i);
        } else {
            stepped.erase(stepped.begin() + i);
            stepped.erase(stepped.begin());
        }

        pruneCollinearAndDuplicates(stepped);
    }

    if (stepped.size() < 3) return ring;

    // STEP 2.5: Rotate back to world coordinates
    std::vector<ProjectedPoint> regularized;
    regularized.reserve(stepped.size());
    for (const auto& pt : stepped) {
        ProjectedPoint p;
        p.easting = centroid.easting + pt.u * cosTheta - pt.v * sinTheta;
        p.northing = centroid.northing + pt.u * sinTheta + pt.v * cosTheta;
        regularized.push_back(p);
    }

    // STEP 2.6: Polygon Validation
    if (regularized.size() < 3) return ring;

    for (std::size_t i = 0; i < regularized.size(); ++i) {
        const auto& p1 = regularized[i];
        const auto& p2 = regularized[(i + 1) % regularized.size()];
        if (std::hypot(p2.easting - p1.easting, p2.northing - p1.northing) < 1e-4) {
            return ring;
        }
    }

    const double origSignedArea = calculateSignedArea(ring);
    double newSignedArea = calculateSignedArea(regularized);

    if (!std::isfinite(origSignedArea) || !std::isfinite(newSignedArea) || std::abs(newSignedArea) < 1e-6) {
        return ring;
    }

    // Ensure winding matches original
    if (origSignedArea * newSignedArea < 0.0) {
        std::reverse(regularized.begin(), regularized.end());
        newSignedArea = calculateSignedArea(regularized);
    }

    // LOD1 collapse may move a material amount of pixel-boundary area. This
    // ring-local guard is followed by whole-footprint area and mask-IoU checks.
    const double allowedAreaTol = std::max(0.45, areaDeviationTolerance);
    if (std::abs(std::abs(newSignedArea) - std::abs(origSignedArea)) > allowedAreaTol * std::abs(origSignedArea)) {
        return ring;
    }

    if (hasSelfIntersections(regularized)) {
        return ring;
    }

    return regularized;
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
     std::unordered_map<int64_t, int64_t> edgeMap;
     auto encodeNode = [](int32_t x, int32_t y) -> int64_t { return (static_cast<int64_t>(y) << 32) | static_cast<uint32_t>(x); };
     auto decodeNode = [](int64_t val, int32_t& x, int32_t& y) { y = static_cast<int32_t>(val >> 32); x = static_cast<int32_t>(val & 0xFFFFFFFF); };

     auto addEdge = [&](int32_t x1, int32_t y1, int32_t x2, int32_t y2)
     {
         edgeMap[encodeNode(x1, y1)] = encodeNode(x2, y2);
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
             validHole = regularizeEdges(
                 validHole,
                 config.maxCornerAdjustmentMetres,
                 config.footprintAreaDeviationTolerance);
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
