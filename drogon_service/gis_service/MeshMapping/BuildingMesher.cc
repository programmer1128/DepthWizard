#include "BuildingMesher.h"
#include "FacadeAtlasGenerator.h"
#include <cmath>
#include <algorithm>
#include <limits>
#include <cstdint>
#include <stdexcept>
#include <numbers>
#include <array>
#include <memory>
#include <ogr_geometry.h>

double BuildingMesher::signedArea(const std::vector<LocalPoint>& ring)
{
     double twiceArea = 0.0;
     for (std::size_t index = 0; index < ring.size(); ++index)
     {
         const LocalPoint& current = ring[index];
         const LocalPoint& next = ring[(index + 1) % ring.size()];
         twiceArea += current.x * next.z - next.x * current.z;
     }
     return 0.5 * twiceArea;
}

// Ear clipping fallback for simple footprints.
float BuildingMesher::crossProduct(const LocalPoint& a, const LocalPoint& b, const LocalPoint& c) 
{
     return static_cast<float>((b.x - a.x) * (c.z - b.z) - (b.z - a.z) * (c.x - b.x));
}

bool BuildingMesher::isPointInsideTriangle(const LocalPoint& pt, 
     const LocalPoint& v1, const LocalPoint& v2,const LocalPoint& v3) 
{
     const float c1 = crossProduct(v1, v2, pt);
     const float c2 = crossProduct(v2, v3, pt);
     const float c3 = crossProduct(v3, v1, pt);
     const bool hasNegative = c1 < -1.0e-6f || c2 < -1.0e-6f || c3 < -1.0e-6f;
     const bool hasPositive = c1 > 1.0e-6f || c2 > 1.0e-6f || c3 > 1.0e-6f;
     return !(hasNegative && hasPositive);
}

BuildingMesher::TriangulationResult BuildingMesher::triangulate(
     const std::vector<LocalPoint>& outerRing, 
     const std::vector<std::vector<LocalPoint>>& holes) 
{
     TriangulationResult result;
     if (outerRing.size() < 3) 
     {
         return result;
     }

     // GEOS-backed constrained triangulation preserves complex concavities
     // and courtyard holes. Keep the compact ear-clipped mesh for simple
     // footprints, and as a fallback if GEOS cannot process a polygon.
     if (!holes.empty() || outerRing.size() > 8)
     {
         OGRPolygon polygon;
         const auto addRing = [&](const std::vector<LocalPoint>& points)
         {
             OGRLinearRing ring;
             for (const auto& point : points)
                 ring.addPoint(point.x, point.z);
             ring.closeRings();
             return polygon.addRing(&ring) == OGRERR_NONE;
         };
         bool ringsAdded = addRing(outerRing);
         for (const auto& hole : holes)
             if (hole.size() >= 3)
                 ringsAdded = addRing(hole) && ringsAdded;
         if (ringsAdded && polygon.IsValid())
         {
             std::unique_ptr<OGRGeometry, decltype(&OGRGeometryFactory::destroyGeometry)>
                 triangles(polygon.ConstrainedDelaunayTriangulation(),
                           OGRGeometryFactory::destroyGeometry);
             const auto* collection = triangles
                 ? dynamic_cast<const OGRGeometryCollection*>(triangles.get())
                 : nullptr;
             if (collection && collection->getNumGeometries() > 0)
             {
                 double triangleArea = 0.0;
                 bool complete = true;
                 for (int index = 0; index < collection->getNumGeometries(); ++index)
                 {
                     const auto* triangle = dynamic_cast<const OGRPolygon*>(
                         collection->getGeometryRef(index));
                     const auto* ring = triangle != nullptr
                         ? triangle->getExteriorRing() : nullptr;
                     if (ring == nullptr || ring->getNumPoints() != 4)
                     {
                         complete = false;
                         break;
                     }
                     std::array<LocalPoint, 3> vertices;
                     for (int corner = 0; corner < 3; ++corner)
                         vertices[corner] = LocalPoint{
                             ring->getX(corner), ring->getY(corner)};
                     const double signedTriangleArea = 0.5 * (
                         (vertices[1].x - vertices[0].x) *
                             (vertices[2].z - vertices[0].z) -
                         (vertices[1].z - vertices[0].z) *
                             (vertices[2].x - vertices[0].x));
                     if (std::abs(signedTriangleArea) <= 1.0e-10) continue;
                     triangleArea += std::abs(signedTriangleArea);
                     const uint32_t base = static_cast<uint32_t>(result.vertices.size());
                     result.vertices.insert(result.vertices.end(),
                                            vertices.begin(), vertices.end());
                     if (signedTriangleArea > 0.0)
                         result.indices.insert(result.indices.end(),
                                               {base, base + 2, base + 1});
                     else
                         result.indices.insert(result.indices.end(),
                                               {base, base + 1, base + 2});
                 }
                 double expectedArea = std::abs(signedArea(outerRing));
                 for (const auto& hole : holes)
                     expectedArea -= std::abs(signedArea(hole));
                 if (complete && expectedArea > 0.0 &&
                     std::abs(triangleArea - expectedArea) <=
                         std::max(0.1, 0.005 * expectedArea) &&
                     !result.indices.empty())
                     return result;
                 result = {};
             }
         }
     }

     std::vector<LocalPoint> poly = outerRing;
     // The projected-to-local transform reflects northing into -Z, so never
     // assume the projected polygon winding survived. Ear clipping operates
     // on a canonical CCW outer ring and CW holes.
     if (signedArea(poly) < 0.0)
     {
         std::reverse(poly.begin(), poly.end());
     }

     for (auto hole : holes)
     {
         if (hole.size() < 3)
         {
             continue;
         }
         if (signedArea(hole) > 0.0)
         {
             std::reverse(hole.begin(), hole.end());
         }

         // Find the rightmost point of the hole
         size_t holeRightMostIdx = 0;
         for (size_t i = 1; i < hole.size(); ++i)
         {
             if (hole[i].x > hole[holeRightMostIdx].x) 
             {
                 holeRightMostIdx = i;
             }
         }
        
         // Prefer the closest outer vertex to the right. If none exists,
         // choose the globally closest vertex instead of silently using zero.
         size_t polyBridgeIdx = 0;
         double minDistSquared = std::numeric_limits<double>::max();
         bool foundRightSideCandidate = false;
         for (size_t i = 0; i < poly.size(); ++i) 
         {
             if (poly[i].x >= hole[holeRightMostIdx].x)
             {
                 const double dx = poly[i].x - hole[holeRightMostIdx].x;
                 const double dz = poly[i].z - hole[holeRightMostIdx].z;
                 const double distanceSquared = dx * dx + dz * dz;
                 if (distanceSquared < minDistSquared)
                 {
                     minDistSquared = distanceSquared;
                     polyBridgeIdx = i;
                     foundRightSideCandidate = true;
                 }
             }
         }

         if (!foundRightSideCandidate)
         {
             for (size_t i = 0; i < poly.size(); ++i)
             {
                 const double dx = poly[i].x - hole[holeRightMostIdx].x;
                 const double dz = poly[i].z - hole[holeRightMostIdx].z;
                 const double distanceSquared = dx * dx + dz * dz;
                 if (distanceSquared < minDistSquared)
                 {
                     minDistSquared = distanceSquared;
                     polyBridgeIdx = i;
                 }
             }
         }
        
         // Insert the hole and the bridge return path
         std::vector<LocalPoint> merged;
         merged.insert(merged.end(), poly.begin(), poly.begin() + polyBridgeIdx + 1);
         merged.insert(merged.end(), hole.begin() + holeRightMostIdx, hole.end());
         merged.insert(merged.end(), hole.begin(), hole.begin() + holeRightMostIdx + 1);
         merged.push_back(poly[polyBridgeIdx]);
         merged.insert(merged.end(), poly.begin() + polyBridgeIdx + 1, poly.end());
         poly = merged;
     }

     if (signedArea(poly) < 0.0)
     {
         std::reverse(poly.begin(), poly.end());
     }

     result.vertices = poly;

     // Ear clipping O(N^2)
     std::vector<uint32_t> remaining;
     for (uint32_t i = 0; i < poly.size(); ++i) 
     {
         remaining.push_back(i);
     }

     while (remaining.size() > 3)
     {
         bool earFound = false;
         for (size_t i = 0; i < remaining.size(); ++i) 
         {
             size_t prev = (i == 0) ? remaining.size() - 1 : i - 1;
             size_t next = (i + 1) % remaining.size();
 
             uint32_t iPrev = remaining[prev];
             uint32_t iCurr = remaining[i];
             uint32_t iNext = remaining[next];

             // Convex check (cross product > 0 for CCW polygon in XZ plane)
             if (crossProduct(poly[iPrev], poly[iCurr], poly[iNext]) > 1.0e-6f)
             {
                 bool isEar = true;
                 // Verify no other points fall inside this ear
                 for (size_t j = 0; j < remaining.size(); ++j) 
                 {
                     if (j == prev || j == i || j == next)
                     { 
                         continue;
                     } 
                     const LocalPoint& candidate = poly[remaining[j]];
                     const auto samePoint = [](const LocalPoint& lhs, const LocalPoint& rhs)
                     {
                         return std::abs(lhs.x - rhs.x) <= 1.0e-8 &&
                             std::abs(lhs.z - rhs.z) <= 1.0e-8;
                     };
                     if (samePoint(candidate, poly[iPrev]) ||
                         samePoint(candidate, poly[iCurr]) ||
                         samePoint(candidate, poly[iNext]))
                     {
                         continue;
                     }
                     if (isPointInsideTriangle(candidate, poly[iPrev], poly[iCurr], poly[iNext])) {
                         isEar = false;
                         break;
                     }
                 }
                
                 if (isEar) 
                 {
                     // Ear clipping works in CCW XZ order. Reverse each
                     // triangle so its glTF face normal points toward +Y.
                     result.indices.push_back(iPrev);
                     result.indices.push_back(iNext);
                     result.indices.push_back(iCurr);
                     remaining.erase(remaining.begin() + i);
                     earFound = true;
                     break;
                 }
             }
         }
         if (!earFound) 
         {
             break; // Degenerate polygon fallback
         }
     }

     if (remaining.size() == 3) 
     {
         result.indices.push_back(remaining[0]);
         result.indices.push_back(remaining[2]);
         result.indices.push_back(remaining[1]);
     }

     const std::size_t expectedIndexCount =
         result.vertices.size() >= 3
             ? (result.vertices.size() - 2) * 3
             : 0;
     if (result.indices.size() != expectedIndexCount)
     {
         // Partial triangulation is more dangerous than no building: walls
         // would remain as detached lines and roof indices could span the
         // wrong bridge vertices.
         result.indices.clear();
     }
     return result;
}



//method for mesh generation
BuildingMesh BuildingMesher::generate(
     const BuildingCollection& buildings,
     const LocalSceneFrame& frame,
     const BuildingMeshConfig& config,
     const SpatialMetadata* metadata)
{
     BuildingMesh result;

     const auto computeRoofUV = [&](double localX, double localZ) -> std::pair<float, float>
     {
         if (metadata == nullptr || !config.generateRoofUVs)
         {
             return {0.5f, 0.5f};
         }
         const double easting = localX + frame.projectedOriginX;
         const double northing = -localZ + frame.projectedOriginY;
         const double* gt = metadata->geoTransform.data();
         const double det = gt[1] * gt[5] - gt[2] * gt[4];
         if (std::abs(det) <= 1e-12)
         {
             return {0.5f, 0.5f};
         }
         const double dx = easting - gt[0];
         const double dy = northing - gt[3];
         const double col = (dx * gt[5] - dy * gt[2]) / det;
         const double row = (dy * gt[1] - dx * gt[4]) / det;
         float u = static_cast<float>(col / metadata->width);
         float v = static_cast<float>(row / metadata->height);
         u = std::clamp(u, 0.0f, 1.0f);
         v = std::clamp(v, 0.0f, 1.0f);
         return {u, v};
     };

     if (!config.validate())
     {
         throw std::invalid_argument("BuildingMesher: invalid mesh configuration");
     }
    
     // Initialize Roof Primitive
     result.roofPrimitive.topology = PrimitiveTopology::TRIANGLES;
     result.roofPrimitive.materialRole = MaterialRole::BUILDING_ROOF;
     result.roofPrimitive.featureIds.emplace(); // Activate feature tracking
     result.roofPrimitive.normals.emplace();
     result.roofPrimitive.colors.emplace();
     
     // Initialize Wall Primitive
     result.wallPrimitive.topology = PrimitiveTopology::TRIANGLES;
     result.wallPrimitive.materialRole = MaterialRole::BUILDING_WALL;
     result.wallPrimitive.featureIds.emplace();
     result.wallPrimitive.normals.emplace();
     result.wallPrimitive.colors.emplace();

     // Initialize Edge Primitive (Mode: LINES)
     result.edgePrimitive.topology = PrimitiveTopology::LINES;
     result.edgePrimitive.materialRole = MaterialRole::BUILDING_EDGE;
     result.edgePrimitive.colors.emplace();
    
     if (config.generateRoofUVs) result.roofPrimitive.uvs.emplace();
     if (config.generateWallUVs) result.wallPrimitive.uvs.emplace();

     AxisAlignedBounds roofBounds; roofBounds.isInitialized = false;
     roofBounds.minX = roofBounds.minY = roofBounds.minZ = std::numeric_limits<double>::max();
     roofBounds.maxX = roofBounds.maxY = roofBounds.maxZ = std::numeric_limits<double>::lowest();

     AxisAlignedBounds wallBounds = roofBounds;
     AxisAlignedBounds edgeBounds = roofBounds;

     for (const auto& bldg : buildings.buildings) 
     {
         //Transform Footprint to Local Coordinates
         std::vector<LocalPoint> localOuter;
         for (const auto& pt : bldg.projectedFootprint.outerRing) 
         {
             localOuter.push_back(LocalFrameTransformer::toLocal(pt, frame));
         }

         std::vector<float> localOuterBaseY;
         if (bldg.baseElevationPerVertex.size() == localOuter.size())
         {
             localOuterBaseY.reserve(localOuter.size());
             for (float elevation : bldg.baseElevationPerVertex)
             {
                 localOuterBaseY.push_back(
                     LocalFrameTransformer::toLocalElevation(
                         elevation - config.wallTerrainEmbedDepthMetres,
                         frame));
             }
         }

         // Restore canonical XZ winding after the projected-to-local axis
         // reflection. Keep per-vertex wall bases aligned with their vertices.
         if (signedArea(localOuter) < 0.0)
         {
             std::reverse(localOuter.begin(), localOuter.end());
             if (!localOuterBaseY.empty())
             {
                 std::reverse(localOuterBaseY.begin(), localOuterBaseY.end());
             }
         }
        
         std::vector<std::vector<LocalPoint>> localHoles;
         for (const auto& hole : bldg.projectedFootprint.holes) 
         {
             std::vector<LocalPoint> lHole;
             for (const auto& pt : hole) 
             {
                 lHole.push_back(LocalFrameTransformer::toLocal(pt, frame));
             }
             if (signedArea(lHole) > 0.0)
             {
                 std::reverse(lHole.begin(), lHole.end());
             }
             localHoles.push_back(lHole);
         }

         float localRoofY = LocalFrameTransformer::toLocalElevation(bldg.roofElevation, frame);
         float localBaseY = LocalFrameTransformer::toLocalElevation(
             bldg.representativeBaseElevation -
                 config.wallTerrainEmbedDepthMetres,
             frame);

         if (config.flatPresentation)
         {
             // Ground is Y=0 in this view. Preserve nDSM metres at 1:1 scale;
             // absolute terrain/base elevations remain in diagnostics/GeoTIFFs.
             localRoofY = bldg.heightAboveGround;
             localBaseY = -config.wallTerrainEmbedDepthMetres;
             std::fill(localOuterBaseY.begin(), localOuterBaseY.end(), localBaseY);
         }

         // Tiered MapFlow color gradient based strictly on absolute heightAboveGround.
         // Do not calculate a scene maximum; use absolute meters to keep city tiles consistent.
         // - Low-rise (< 15 meters): Cyan (0.0f, 0.80f, 0.95f)
         // - Mid-rise (15m to 45m): Deep Blue (0.10f, 0.25f, 0.90f)
         // - High-rise (> 45 meters): Hologram Red (1.0f, 0.15f, 0.30f)
         float tierR{0.0f}, tierG{0.80f}, tierB{0.95f}, tierA{1.0f};
         float wallR{0.0f}, wallG{0.52f}, wallB{0.6175f}, wallA{1.0f};
         float roofR{0.0f}, roofG{0.80f}, roofB{0.95f}, roofA{1.0f};

         const auto selectHeightColors = [&](float h)
         {
             if (config.presentationStyle == depthwizard::PresentationStyle::ORTHOPHOTO_REALISTIC)
             {
                 tierR = 1.0f; tierG = 1.0f; tierB = 1.0f; tierA = 1.0f;
                 roofR = 1.0f; roofG = 1.0f; roofB = 1.0f; roofA = 1.0f;
                 wallR = 1.0f; wallG = 1.0f; wallB = 1.0f; wallA = 1.0f;
                 return;
             }
             if (config.presentationStyle == depthwizard::PresentationStyle::TERRA_MASSING)
             {
                 tierR = 0.95f; tierG = 0.94f; tierB = 0.90f; tierA = 1.0f;
                 roofR = 0.95f; roofG = 0.94f; roofB = 0.90f; roofA = 1.0f;
                 wallR = 0.70f; wallG = 0.69f; wallB = 0.67f; wallA = 1.0f;
                 return;
             }
             if (h > 45.0f)
             {
                 tierR = 1.0f; tierG = 0.15f; tierB = 0.30f;
             }
             else if (h >= 15.0f)
             {
                 tierR = 0.10f; tierG = 0.25f; tierB = 0.90f;
             }
             else
             {
                 tierR = 0.00f; tierG = 0.80f; tierB = 0.95f;
             }
             tierA = 1.0f;
             roofR = tierR; roofG = tierG; roofB = tierB; roofA = tierA;
             // Contrast Shadowing: wall faces (|Ny| < 0.5f) are 35% darker than roofs
             wallR = 0.65f * tierR;
             wallG = 0.65f * tierG;
             wallB = 0.65f * tierB;
             wallA = tierA;
         };
         selectHeightColors(bldg.heightAboveGround);

         // Parametric LoD2 block path. The validated source footprint remains
         // the terrain cutout, while supported non-overlapping rectangles
         // provide crisp walls and conservative flat/gable/hip roofs.
         if (!bldg.blocks.empty())
         {
             struct Vertex3
             {
                 double x;
                 float y;
                 double z;
             };
             struct LocalBlock
             {
                 std::array<LocalPoint, 4> corners;
                 RoofParameters roof;
                 float eaveY{0.0f};
                 float ridgeY{0.0f};
             };

             auto expandBounds = [](AxisAlignedBounds& bounds,
                                    const Vertex3& vertex)
             {
                 bounds.isInitialized = true;
                 bounds.minX = std::min(bounds.minX, vertex.x);
                 bounds.maxX = std::max(bounds.maxX, vertex.x);
                 bounds.minY = std::min(
                     bounds.minY, static_cast<double>(vertex.y));
                 bounds.maxY = std::max(
                     bounds.maxY, static_cast<double>(vertex.y));
                 bounds.minZ = std::min(bounds.minZ, vertex.z);
                 bounds.maxZ = std::max(bounds.maxZ, vertex.z);
             };

             auto emitTriangle = [&](MeshPrimitive& primitive,
                                     AxisAlignedBounds& bounds,
                                     Vertex3 a, Vertex3 b, Vertex3 c,
                                     float colorR, float colorG,
                                     float colorB, float colorA,
                                     const std::array<double, 3>& preferred,
                                     const std::array<std::pair<float, float>, 3>* customUVs = nullptr)
             {
                 const auto normal = [](const Vertex3& p0,
                                        const Vertex3& p1,
                                        const Vertex3& p2)
                 {
                     const double abx = p1.x - p0.x;
                     const double aby = p1.y - p0.y;
                     const double abz = p1.z - p0.z;
                     const double acx = p2.x - p0.x;
                     const double acy = p2.y - p0.y;
                     const double acz = p2.z - p0.z;
                     return std::array<double, 3>{
                         aby * acz - abz * acy,
                         abz * acx - abx * acz,
                         abx * acy - aby * acx};
                 };
                 std::array<std::pair<float, float>, 3> localUVs;
                 bool hasCustomUVs = false;
                 if (customUVs != nullptr)
                 {
                     localUVs = *customUVs;
                     hasCustomUVs = true;
                 }
                 auto n = normal(a, b, c);
                 if (n[0] * preferred[0] + n[1] * preferred[1] +
                         n[2] * preferred[2] < 0.0)
                 {
                     std::swap(b, c);
                     if (hasCustomUVs) std::swap(localUVs[1], localUVs[2]);
                     n = normal(a, b, c);
                 }
                 const double length = std::sqrt(
                     n[0] * n[0] + n[1] * n[1] + n[2] * n[2]);
                 if (length <= 1.0e-8) return;
                 const std::array<float, 3> unit{
                     static_cast<float>(n[0] / length),
                     static_cast<float>(n[1] / length),
                     static_cast<float>(n[2] / length)};
                 const uint32_t base = static_cast<uint32_t>(
                     primitive.positions.size() / 3);

                 float finalR = colorR;
                 float finalG = colorG;
                 float finalB = colorB;
                 // Contrast Shadowing: multiply chosen RGB tier by 0.65f if face normal is vertical (|Ny| < 0.5f)
                 if (&primitive == &result.wallPrimitive && std::abs(unit[1]) < 0.5f &&
                     config.presentationStyle == depthwizard::PresentationStyle::SCIENTIFIC)
                 {
                     finalR = tierR * 0.65f;
                     finalG = tierG * 0.65f;
                     finalB = tierB * 0.65f;
                 }

                 const std::array<Vertex3, 3> triVertices{a, b, c};
                 for (std::size_t vIdx = 0; vIdx < 3; ++vIdx)
                 {
                     const Vertex3& vertex = triVertices[vIdx];
                     primitive.positions.push_back(
                         static_cast<float>(vertex.x));
                     primitive.positions.push_back(vertex.y);
                     primitive.positions.push_back(
                         static_cast<float>(vertex.z));
                     primitive.normals->insert(
                         primitive.normals->end(), unit.begin(), unit.end());
                     primitive.featureIds->push_back(
                         static_cast<float>(bldg.buildingId));
                     primitive.colors->insert(
                         primitive.colors->end(),
                         {finalR, finalG, finalB, colorA});
                     if (primitive.uvs.has_value())
                     {
                         if (hasCustomUVs)
                         {
                             primitive.uvs->push_back(localUVs[vIdx].first);
                             primitive.uvs->push_back(localUVs[vIdx].second);
                         }
                         else if (&primitive == &result.roofPrimitive)
                         {
                             auto [u, v] = computeRoofUV(vertex.x, vertex.z);
                             primitive.uvs->push_back(u);
                             primitive.uvs->push_back(v);
                         }
                         else
                         {
                             primitive.uvs->push_back(0.5f);
                             primitive.uvs->push_back(0.5f);
                         }
                     }
                     expandBounds(bounds, vertex);
                 }
                 primitive.indices.insert(
                     primitive.indices.end(), {base, base + 1, base + 2});
             };

             auto pushEdge = [&](const Vertex3& a, const Vertex3& b)
             {
                 if (config.presentationStyle != depthwizard::PresentationStyle::SCIENTIFIC) return;
                 const uint32_t base = static_cast<uint32_t>(
                     result.edgePrimitive.positions.size() / 3);
                 result.edgePrimitive.positions.insert(
                     result.edgePrimitive.positions.end(),
                     {static_cast<float>(a.x), a.y, static_cast<float>(a.z),
                      static_cast<float>(b.x), b.y, static_cast<float>(b.z)});
                 result.edgePrimitive.colors->insert(
                     result.edgePrimitive.colors->end(),
                     {1.0f, 1.0f, 1.0f, 0.90f,
                      1.0f, 1.0f, 1.0f, 0.90f});
                 result.edgePrimitive.indices.insert(
                     result.edgePrimitive.indices.end(), {base, base + 1});
                 expandBounds(edgeBounds, a);
                 expandBounds(edgeBounds, b);
             };

             std::vector<LocalBlock> blocks;
             blocks.reserve(bldg.blocks.size());
             for (const auto& source : bldg.blocks)
             {
                 LocalBlock block;
                 block.roof = source.roof;
                 for (std::size_t index = 0; index < 4; ++index)
                     block.corners[index] = LocalFrameTransformer::toLocal(
                         source.projectedCorners[index], frame);
                 std::vector<LocalPoint> winding(
                     block.corners.begin(), block.corners.end());
                 if (signedArea(winding) < 0.0)
                     std::reverse(block.corners.begin(), block.corners.end());
                 block.eaveY = config.flatPresentation
                     ? source.roof.eaveHeightAboveGround
                     : LocalFrameTransformer::toLocalElevation(
                         bldg.representativeBaseElevation +
                             source.roof.eaveHeightAboveGround,
                         frame);
                 block.ridgeY = config.flatPresentation
                     ? source.roof.ridgeHeightAboveGround
                     : LocalFrameTransformer::toLocalElevation(
                         bldg.representativeBaseElevation +
                             source.roof.ridgeHeightAboveGround,
                         frame);
                 blocks.push_back(block);
             }

             auto pointInConvexBlock = [](const LocalPoint& point,
                                          const LocalBlock& block)
             {
                 bool hasPositive = false;
                 bool hasNegative = false;
                 for (std::size_t index = 0; index < 4; ++index)
                 {
                     const auto& a = block.corners[index];
                     const auto& b = block.corners[(index + 1) % 4];
                     const double cross = (b.x - a.x) * (point.z - a.z) -
                         (b.z - a.z) * (point.x - a.x);
                     hasPositive = hasPositive || cross > 1.0e-5;
                     hasNegative = hasNegative || cross < -1.0e-5;
                     if (hasPositive && hasNegative) return false;
                 }
                 return true;
             };

             auto adjacentHeight = [&](std::size_t blockIndex,
                                       const LocalPoint& a,
                                       const LocalPoint& b)
             {
                 const LocalPoint midpoint{
                     0.5 * (a.x + b.x), 0.5 * (a.z + b.z)};
                 float height = -std::numeric_limits<float>::infinity();
                 for (std::size_t other = 0; other < blocks.size(); ++other)
                 {
                     if (other == blockIndex) continue;
                     if (pointInConvexBlock(midpoint, blocks[other]))
                         height = std::max(height, blocks[other].eaveY);
                 }
                 return height;
             };

             float maxRidgeY = localBaseY;
             for (const auto& blk : blocks)
             {
                 maxRidgeY = std::max(maxRidgeY, blk.ridgeY);
             }
             const float totalBldgHeight = std::max(maxRidgeY - localBaseY, 0.1f);

             for (std::size_t blockIndex = 0;
                  blockIndex < blocks.size(); ++blockIndex)
             {
                 const auto& block = blocks[blockIndex];
                 selectHeightColors(block.roof.ridgeHeightAboveGround);
                 LocalPoint centre;
                 for (const auto& corner : block.corners)
                 {
                     centre.x += corner.x;
                     centre.z += corner.z;
                 }
                 centre.x /= 4.0;
                 centre.z /= 4.0;

                 const double edge0 = std::hypot(
                     block.corners[1].x - block.corners[0].x,
                     block.corners[1].z - block.corners[0].z);
                 const double edge1 = std::hypot(
                     block.corners[2].x - block.corners[1].x,
                     block.corners[2].z - block.corners[1].z);
                 bool ridgeRunsAlongEdge0 = edge0 >= edge1;
                 if (block.roof.type != RoofType::FLAT)
                 {
                     const LocalPoint fittedStart =
                         LocalFrameTransformer::toLocal(
                             block.roof.ridgeStartProjected, frame);
                     const LocalPoint fittedEnd =
                         LocalFrameTransformer::toLocal(
                             block.roof.ridgeEndProjected, frame);
                     const double fittedX = fittedEnd.x - fittedStart.x;
                     const double fittedZ = fittedEnd.z - fittedStart.z;
                     const double fittedLength = std::hypot(fittedX, fittedZ);
                     if (fittedLength > 1.0e-6 && edge0 > 1.0e-6 &&
                         edge1 > 1.0e-6)
                     {
                         const double edge0Alignment = std::abs(
                             fittedX * (block.corners[1].x - block.corners[0].x) +
                             fittedZ * (block.corners[1].z - block.corners[0].z)) /
                             (fittedLength * edge0);
                         const double edge1Alignment = std::abs(
                             fittedX * (block.corners[2].x - block.corners[1].x) +
                             fittedZ * (block.corners[2].z - block.corners[1].z)) /
                             (fittedLength * edge1);
                         ridgeRunsAlongEdge0 =
                             edge0Alignment >= edge1Alignment;
                     }
                 }
                 const std::array<int, 2> startEnd = ridgeRunsAlongEdge0
                     ? std::array<int, 2>{3, 0}
                     : std::array<int, 2>{0, 1};
                 const std::array<int, 2> finishEnd = ridgeRunsAlongEdge0
                     ? std::array<int, 2>{1, 2}
                     : std::array<int, 2>{2, 3};
                 const std::array<int, 2> sideA = ridgeRunsAlongEdge0
                     ? std::array<int, 2>{0, 1}
                     : std::array<int, 2>{1, 2};
                 const std::array<int, 2> sideB = ridgeRunsAlongEdge0
                     ? std::array<int, 2>{3, 2}
                     : std::array<int, 2>{0, 3};

                 std::array<float, 4> edgeLengths{};
                 std::array<float, 4> edgeStartDist{};
                 float perimeterDist = 0.0f;
                 for (std::size_t edge = 0; edge < 4; ++edge)
                 {
                     edgeStartDist[edge] = perimeterDist;
                     const auto& ca = block.corners[edge];
                     const auto& cb = block.corners[(edge + 1) % 4];
                     edgeLengths[edge] = static_cast<float>(std::hypot(cb.x - ca.x, cb.z - ca.z));
                     perimeterDist += edgeLengths[edge];
                 }

                 auto midpoint = [&](const std::array<int, 2>& end)
                 {
                     return LocalPoint{
                         0.5 * (block.corners[end[0]].x +
                                block.corners[end[1]].x),
                         0.5 * (block.corners[end[0]].z +
                                block.corners[end[1]].z)};
                 };
                 LocalPoint ridgeStart = midpoint(startEnd);
                 LocalPoint ridgeFinish = midpoint(finishEnd);
                 if (block.roof.type == RoofType::HIP)
                 {
                     const double ridgeLength = std::hypot(
                         ridgeFinish.x - ridgeStart.x,
                         ridgeFinish.z - ridgeStart.z);
                     const double shortWidth = std::min(edge0, edge1);
                     const double inset = std::min(
                         0.45 * ridgeLength, 0.5 * shortWidth);
                     if (ridgeLength > 1.0e-6)
                     {
                         const double dirX =
                             (ridgeFinish.x - ridgeStart.x) / ridgeLength;
                         const double dirZ =
                             (ridgeFinish.z - ridgeStart.z) / ridgeLength;
                         ridgeStart.x += inset * dirX;
                         ridgeStart.z += inset * dirZ;
                         ridgeFinish.x -= inset * dirX;
                         ridgeFinish.z -= inset * dirZ;
                     }
                 }

                 const auto eaveVertex = [&](int index)
                 {
                     return Vertex3{block.corners[index].x, block.eaveY,
                                    block.corners[index].z};
                 };
                 const Vertex3 ridgeA{
                     ridgeStart.x, block.ridgeY, ridgeStart.z};
                 const Vertex3 ridgeB{
                     ridgeFinish.x, block.ridgeY, ridgeFinish.z};

                 if (block.roof.type == RoofType::FLAT)
                 {
                     emitTriangle(result.roofPrimitive, roofBounds,
                         eaveVertex(0), eaveVertex(1), eaveVertex(2),
                         roofR, roofG, roofB, roofA, {0.0, 1.0, 0.0});
                     emitTriangle(result.roofPrimitive, roofBounds,
                         eaveVertex(0), eaveVertex(2), eaveVertex(3),
                         roofR, roofG, roofB, roofA, {0.0, 1.0, 0.0});
                 }
                 else
                 {
                     emitTriangle(result.roofPrimitive, roofBounds,
                         eaveVertex(sideA[0]), eaveVertex(sideA[1]), ridgeB,
                         roofR, roofG, roofB, roofA, {0.0, 1.0, 0.0});
                     emitTriangle(result.roofPrimitive, roofBounds,
                         eaveVertex(sideA[0]), ridgeB, ridgeA,
                         roofR, roofG, roofB, roofA, {0.0, 1.0, 0.0});
                     emitTriangle(result.roofPrimitive, roofBounds,
                         eaveVertex(sideB[0]), ridgeA, ridgeB,
                         roofR, roofG, roofB, roofA, {0.0, 1.0, 0.0});
                     emitTriangle(result.roofPrimitive, roofBounds,
                         eaveVertex(sideB[0]), ridgeB,
                         eaveVertex(sideB[1]),
                         roofR, roofG, roofB, roofA, {0.0, 1.0, 0.0});

                     if (block.roof.type == RoofType::HIP)
                     {
                         emitTriangle(result.roofPrimitive, roofBounds,
                             eaveVertex(startEnd[0]),
                             eaveVertex(startEnd[1]), ridgeA,
                             roofR, roofG, roofB, roofA,
                             {0.0, 1.0, 0.0});
                         emitTriangle(result.roofPrimitive, roofBounds,
                             eaveVertex(finishEnd[0]), ridgeB,
                             eaveVertex(finishEnd[1]),
                             roofR, roofG, roofB, roofA,
                             {0.0, 1.0, 0.0});
                     }
                     else
                     {
                         const auto emitGableEnd = [&](const auto& end,
                                                       const Vertex3& ridge)
                         {
                             const LocalPoint endMid = midpoint(end);
                             const std::array<double, 3> outward{
                                 endMid.x - centre.x, 0.0,
                                 endMid.z - centre.z};
                              const Vertex3 v0 = eaveVertex(end[0]);
                              const Vertex3 v1 = eaveVertex(end[1]);
                              const float gableSpan = static_cast<float>(
                                  std::hypot(v1.x - v0.x, v1.z - v0.z));
                              const float eaveH = block.eaveY - localBaseY;
                              const float ridgeH = block.ridgeY - localBaseY;
                              const std::size_t gableEdgeIdx = end[0];
                              const float gStartDist = (gableEdgeIdx < 4) ? edgeStartDist[gableEdgeIdx] : 0.0f;
                              const float gTileBase = std::floor(gStartDist / depthwizard::FacadeAtlasGenerator::kNominalTileWidthMetres) * depthwizard::FacadeAtlasGenerator::kNominalTileWidthMetres;
                              const float gStartInTile = gStartDist - gTileBase;
                              float u0 = 0.5f, v0_uv = 0.5f, u1 = 0.5f, v1_uv = 0.5f, uRidge = 0.5f, vRidge = 0.5f;
                              depthwizard::FacadeAtlasGenerator::computeWallUV(
                                  bldg.buildingId, gStartInTile, eaveH, totalBldgHeight, u0, v0_uv);
                              depthwizard::FacadeAtlasGenerator::computeWallUV(
                                  bldg.buildingId, gStartInTile + gableSpan, eaveH, totalBldgHeight, u1, v1_uv);
                              depthwizard::FacadeAtlasGenerator::computeWallUV(
                                  bldg.buildingId, gStartInTile + 0.5f * gableSpan, ridgeH, totalBldgHeight, uRidge, vRidge);
                              std::array<std::pair<float, float>, 3> gableUVs{
                                  {{u0, v0_uv}, {u1, v1_uv}, {uRidge, vRidge}}};
                              emitTriangle(result.wallPrimitive, wallBounds,
                                  v0, v1, ridge,
                                  wallR, wallG, wallB, wallA, outward, &gableUVs);
                          };
                         emitGableEnd(startEnd, ridgeA);
                         emitGableEnd(finishEnd, ridgeB);
                     }
                 }

                 for (std::size_t edge = 0; edge < 4; ++edge)
                 {
                     const auto& a = block.corners[edge];
                     const auto& b = block.corners[(edge + 1) % 4];
                     const double dx = b.x - a.x;
                     const double dz = b.z - a.z;
                     const double lengthSquared = dx * dx + dz * dz;
                     if (lengthSquared <= 1.0e-12) continue;
                     std::vector<double> cuts{0.0, 1.0};
                     // A neighbour can cover only part of a long edge. Split
                     // at its corners before deciding which wall spans are
                     // exterior and which are shared or setback steps.
                     for (std::size_t other = 0; other < blocks.size(); ++other)
                     {
                         if (other == blockIndex) continue;
                         for (const auto& corner : blocks[other].corners)
                         {
                             const double offsetX = corner.x - a.x;
                             const double offsetZ = corner.z - a.z;
                             const double t = (offsetX * dx + offsetZ * dz) /
                                 lengthSquared;
                             const double distance = std::abs(
                                 offsetX * dz - offsetZ * dx) /
                                 std::sqrt(lengthSquared);
                             if (t > 1.0e-6 && t < 1.0 - 1.0e-6 &&
                                 distance < 1.0e-4)
                                 cuts.push_back(t);
                         }
                     }
                     std::sort(cuts.begin(), cuts.end());
                     cuts.erase(std::unique(cuts.begin(), cuts.end(),
                         [](double left, double right)
                         { return std::abs(left - right) < 1.0e-6; }),
                         cuts.end());
                     for (std::size_t segment = 0; segment + 1 < cuts.size();
                          ++segment)
                     {
                         const LocalPoint start{
                             a.x + cuts[segment] * dx,
                             a.z + cuts[segment] * dz};
                         const LocalPoint finish{
                             a.x + cuts[segment + 1] * dx,
                             a.z + cuts[segment + 1] * dz};
                         const float neighbourY = adjacentHeight(
                             blockIndex, start, finish);
                         if (!std::isfinite(neighbourY) ||
                             block.eaveY > neighbourY + 0.1f)
                         {
                             const LocalPoint edgeMid{
                                 0.5 * (start.x + finish.x),
                                 0.5 * (start.z + finish.z)};
                             const std::array<double, 3> outward{
                                 edgeMid.x - centre.x, 0.0,
                                 edgeMid.z - centre.z};
                             const float wallBaseY = std::isfinite(neighbourY)
                                 ? neighbourY : localBaseY;
                             const Vertex3 baseA{start.x, wallBaseY, start.z};
                             const Vertex3 topA{start.x, block.eaveY, start.z};
                             const Vertex3 topB{finish.x, block.eaveY, finish.z};
                             const Vertex3 baseB{finish.x, wallBaseY, finish.z};
                             const float segStartDist = edgeStartDist[edge] +
                                 static_cast<float>(cuts[segment]) * edgeLengths[edge];
                             const float segFinishDist = edgeStartDist[edge] +
                                 static_cast<float>(cuts[segment + 1]) * edgeLengths[edge];
                             const float absBaseH = wallBaseY - localBaseY;
                             const float absTopH = block.eaveY - localBaseY;
                             const float tileBase = std::floor(segStartDist / depthwizard::FacadeAtlasGenerator::kNominalTileWidthMetres) * depthwizard::FacadeAtlasGenerator::kNominalTileWidthMetres;
                             const float segStartInTile = segStartDist - tileBase;
                             const float segFinishInTile = segFinishDist - tileBase;
                             float uBaseA = 0.5f, vBaseA = 0.5f, uTopA = 0.5f, vTopA = 0.5f;
                             float uTopB = 0.5f, vTopB = 0.5f, uBaseB = 0.5f, vBaseB = 0.5f;
                             depthwizard::FacadeAtlasGenerator::computeWallUV(
                                 bldg.buildingId, segStartInTile, absBaseH, totalBldgHeight, uBaseA, vBaseA);
                             depthwizard::FacadeAtlasGenerator::computeWallUV(
                                 bldg.buildingId, segStartInTile, absTopH, totalBldgHeight, uTopA, vTopA);
                             depthwizard::FacadeAtlasGenerator::computeWallUV(
                                 bldg.buildingId, segFinishInTile, absTopH, totalBldgHeight, uTopB, vTopB);
                             depthwizard::FacadeAtlasGenerator::computeWallUV(
                                 bldg.buildingId, segFinishInTile, absBaseH, totalBldgHeight, uBaseB, vBaseB);
                             std::array<std::pair<float, float>, 3> uvQuad1{
                                 {{uBaseA, vBaseA}, {uTopA, vTopA}, {uTopB, vTopB}}};
                             std::array<std::pair<float, float>, 3> uvQuad2{
                                 {{uBaseA, vBaseA}, {uTopB, vTopB}, {uBaseB, vBaseB}}};
                             emitTriangle(result.wallPrimitive, wallBounds,
                                 baseA, topA, topB,
                                 wallR, wallG, wallB, wallA, outward, &uvQuad1);
                             emitTriangle(result.wallPrimitive, wallBounds,
                                 baseA, topB, baseB,
                                 wallR, wallG, wallB, wallA, outward, &uvQuad2);
                             pushEdge(baseA, topA);
                         }
                         if (!std::isfinite(neighbourY) ||
                             std::abs(block.eaveY - neighbourY) > 0.1f)
                             pushEdge(
                                 Vertex3{start.x, block.eaveY, start.z},
                                 Vertex3{finish.x, block.eaveY, finish.z});
                     }
                 }
                 if (block.roof.type != RoofType::FLAT)
                 {
                     pushEdge(ridgeA, ridgeB);
                     pushEdge(eaveVertex(startEnd[0]), ridgeA);
                     pushEdge(eaveVertex(startEnd[1]), ridgeA);
                     pushEdge(eaveVertex(finishEnd[0]), ridgeB);
                     pushEdge(eaveVertex(finishEnd[1]), ridgeB);
                 }
             }

             result.emittedBuildingIds.push_back(bldg.buildingId);
             continue;
         }

         /*
         *Roof Generation of building
         */
         const TriangulationResult triangulation =
             triangulate(localOuter, localHoles);
         if (triangulation.indices.empty())
         {
             // Never emit walls without a valid roof. That failure mode is
             // exactly the thin cyan contour seen when roof triangulation
             // silently failed after the local-axis winding reflection.
             result.rejectedBuildingIds.push_back(bldg.buildingId);
             continue;
         }

         uint32_t roofIndexOffset = static_cast<uint32_t>(result.roofPrimitive.positions.size() / 3);
         for (uint32_t idx : triangulation.indices)
         {
             result.roofPrimitive.indices.push_back(roofIndexOffset + idx);
         }

         auto addRoofVertex = [&](const LocalPoint& pt) 
         {
             result.roofPrimitive.positions.push_back(static_cast<float>(pt.x));
             result.roofPrimitive.positions.push_back(localRoofY);
             result.roofPrimitive.positions.push_back(static_cast<float>(pt.z));
             
             result.roofPrimitive.normals->push_back(0.0f);
             result.roofPrimitive.normals->push_back(1.0f); // Hard normal straight up
             result.roofPrimitive.normals->push_back(0.0f);
            
             result.roofPrimitive.featureIds->push_back(
                 static_cast<float>(bldg.buildingId));

             if (result.roofPrimitive.colors.has_value())
             {
                 result.roofPrimitive.colors->push_back(roofR);
                 result.roofPrimitive.colors->push_back(roofG);
                 result.roofPrimitive.colors->push_back(roofB);
                 result.roofPrimitive.colors->push_back(roofA);
             }
             if (result.roofPrimitive.uvs.has_value())
             {
                 auto [u, v] = computeRoofUV(pt.x, pt.z);
                 result.roofPrimitive.uvs->push_back(u);
                 result.roofPrimitive.uvs->push_back(v);
             }

             roofBounds.isInitialized = true;

             roofBounds.minX = std::min(roofBounds.minX, pt.x); roofBounds.maxX = std::max(roofBounds.maxX, pt.x);
             roofBounds.minY = std::min(roofBounds.minY, static_cast<double>(localRoofY)); roofBounds.maxY = std::max(roofBounds.maxY, static_cast<double>(localRoofY));
             roofBounds.minZ = std::min(roofBounds.minZ, pt.z); roofBounds.maxZ = std::max(roofBounds.maxZ, pt.z);
         };

         for (const auto& pt : triangulation.vertices)
         {
             addRoofVertex(pt);
         }

       
         /*
         *Wall generation
         */
         auto extrudeRing = [&](const std::vector<LocalPoint>& ring,
                                const std::vector<float>* vertexBaseY)
         {
             float ringDist = 0.0f;
             for (size_t i = 0; i < ring.size(); ++i) 
             {
                 size_t nextIdx = (i + 1) % ring.size();
                 LocalPoint ptA = ring[i];
                 LocalPoint ptB = ring[nextIdx];

                 // Calculate Hard Face Normal
                 float dx = static_cast<float>(ptB.x - ptA.x);
                 float dz = static_cast<float>(ptB.z - ptA.z);
                 float nx = dz;
                 float nz = -dx;
                 float len = std::sqrt(nx * nx + nz * nz);
                 if (len > 0.0001f) 
                 { 
                     nx /= len; nz /= len; 
                 }

                 uint32_t wallIdxBase = static_cast<uint32_t>(result.wallPrimitive.positions.size() / 3);
                 const float baseA = vertexBaseY != nullptr
                     ? (*vertexBaseY)[i]
                     : localBaseY;
                 const float baseB = vertexBaseY != nullptr
                     ? (*vertexBaseY)[nextIdx]
                     : localBaseY;

                 // Push 4 independent vertices per wall quad to guarantee crisp corners
                 const float absBaseHA = baseA - localBaseY;
                 const float absBaseHB = baseB - localBaseY;
                 const float absRoofH = localRoofY - localBaseY;
                 const float totalBldgH = std::max(absRoofH, 0.1f);
                 float uBaseA = 0.5f, vBaseA = 0.5f, uRoofA = 0.5f, vRoofA = 0.5f;
                 float uRoofB = 0.5f, vRoofB = 0.5f, uBaseB = 0.5f, vBaseB = 0.5f;
                 if (result.wallPrimitive.uvs.has_value())
                 {
                     const float tileBase = std::floor(ringDist / depthwizard::FacadeAtlasGenerator::kNominalTileWidthMetres) * depthwizard::FacadeAtlasGenerator::kNominalTileWidthMetres;
                     const float startInTile = ringDist - tileBase;
                     const float finishInTile = ringDist + len - tileBase;
                     depthwizard::FacadeAtlasGenerator::computeWallUV(
                         bldg.buildingId, startInTile, absBaseHA, totalBldgH, uBaseA, vBaseA);
                     depthwizard::FacadeAtlasGenerator::computeWallUV(
                         bldg.buildingId, startInTile, absRoofH, totalBldgH, uRoofA, vRoofA);
                     depthwizard::FacadeAtlasGenerator::computeWallUV(
                         bldg.buildingId, finishInTile, absRoofH, totalBldgH, uRoofB, vRoofB);
                     depthwizard::FacadeAtlasGenerator::computeWallUV(
                         bldg.buildingId, finishInTile, absBaseHB, totalBldgH, uBaseB, vBaseB);
                 }
                 auto pushWallVertex = [&](double vx, float vy, double vz, float u, float v)
                 {
                     result.wallPrimitive.positions.push_back(static_cast<float>(vx));
                     result.wallPrimitive.positions.push_back(vy);
                     result.wallPrimitive.positions.push_back(static_cast<float>(vz));
                     
                     result.wallPrimitive.normals->push_back(nx);
                     result.wallPrimitive.normals->push_back(0.0f);
                     result.wallPrimitive.normals->push_back(nz);
                    
                     result.wallPrimitive.featureIds->push_back(
                         static_cast<float>(bldg.buildingId));

                     if (result.wallPrimitive.colors.has_value())
                     {
                         result.wallPrimitive.colors->push_back(wallR);
                         result.wallPrimitive.colors->push_back(wallG);
                         result.wallPrimitive.colors->push_back(wallB);
                         result.wallPrimitive.colors->push_back(wallA);
                     }
                     if (result.wallPrimitive.uvs.has_value())
                     {
                         result.wallPrimitive.uvs->push_back(u);
                         result.wallPrimitive.uvs->push_back(v);
                     }

                     wallBounds.isInitialized = true;

                     wallBounds.minX = std::min(wallBounds.minX, vx); wallBounds.maxX = std::max(wallBounds.maxX, vx);
                     wallBounds.minY = std::min(wallBounds.minY, static_cast<double>(vy)); wallBounds.maxY = std::max(wallBounds.maxY, static_cast<double>(vy));
                     wallBounds.minZ = std::min(wallBounds.minZ, vz); wallBounds.maxZ = std::max(wallBounds.maxZ, vz);
                 };

                 pushWallVertex(ptA.x, baseA, ptA.z, uBaseA, vBaseA); // Base A (Index 0)
                 pushWallVertex(ptA.x, localRoofY, ptA.z, uRoofA, vRoofA); // Roof A (Index 1)
                 pushWallVertex(ptB.x, localRoofY, ptB.z, uRoofB, vRoofB); // Roof B (Index 2)
                 pushWallVertex(ptB.x, baseB, ptB.z, uBaseB, vBaseB); // Base B (Index 3)

                 // For the canonical CCW XZ outer ring, up x edge is
                 // (dz, 0, -dx): exactly the outward normal above. Reversing
                 // these indices would cull the exterior. CW courtyard rings
                 // intentionally point inward into the courtyard void.
                 result.wallPrimitive.indices.push_back(wallIdxBase + 0);
                 result.wallPrimitive.indices.push_back(wallIdxBase + 1);
                 result.wallPrimitive.indices.push_back(wallIdxBase + 2);

                 result.wallPrimitive.indices.push_back(wallIdxBase + 0);
                 result.wallPrimitive.indices.push_back(wallIdxBase + 2);
                 result.wallPrimitive.indices.push_back(wallIdxBase + 3);
                 ringDist += len;
             }
         };

         extrudeRing(
             localOuter,
             localOuterBaseY.empty() ? nullptr : &localOuterBaseY);
         for (const auto& hole : localHoles) 
         {
             extrudeRing(hole, nullptr);
         }

         /*
          * Wireframe Edge Highlight Generation (Mode: LINES)
          */
         auto pushEdgeSegment = [&](double x1, float y1, double z1,
                                    double x2, float y2, double z2)
         {
             if (config.presentationStyle != depthwizard::PresentationStyle::SCIENTIFIC) return;
             uint32_t baseIdx = static_cast<uint32_t>(result.edgePrimitive.positions.size() / 3);
             result.edgePrimitive.positions.push_back(static_cast<float>(x1));
             result.edgePrimitive.positions.push_back(y1);
             result.edgePrimitive.positions.push_back(static_cast<float>(z1));

             result.edgePrimitive.positions.push_back(static_cast<float>(x2));
             result.edgePrimitive.positions.push_back(y2);
             result.edgePrimitive.positions.push_back(static_cast<float>(z2));

             if (result.edgePrimitive.colors.has_value())
             {
                 result.edgePrimitive.colors->push_back(1.0f);
                 result.edgePrimitive.colors->push_back(1.0f);
                 result.edgePrimitive.colors->push_back(1.0f);
                 result.edgePrimitive.colors->push_back(0.90f);

                 result.edgePrimitive.colors->push_back(1.0f);
                 result.edgePrimitive.colors->push_back(1.0f);
                 result.edgePrimitive.colors->push_back(1.0f);
                 result.edgePrimitive.colors->push_back(0.90f);
             }

             result.edgePrimitive.indices.push_back(baseIdx);
             result.edgePrimitive.indices.push_back(baseIdx + 1);

             edgeBounds.isInitialized = true;
             edgeBounds.minX = std::min({edgeBounds.minX, x1, x2});
             edgeBounds.maxX = std::max({edgeBounds.maxX, x1, x2});
             edgeBounds.minY = std::min({edgeBounds.minY, static_cast<double>(y1), static_cast<double>(y2)});
             edgeBounds.maxY = std::max({edgeBounds.maxY, static_cast<double>(y1), static_cast<double>(y2)});
             edgeBounds.minZ = std::min({edgeBounds.minZ, z1, z2});
             edgeBounds.maxZ = std::max({edgeBounds.maxZ, z1, z2});
         };

         // Outer roof perimeter and vertical corner seams
         const size_t outerCount = localOuter.size();
         for (size_t i = 0; i < outerCount; ++i)
         {
             size_t prevIdx = (i + outerCount - 1) % outerCount;
             size_t nextIdx = (i + 1) % outerCount;
             const auto& ptPrev = localOuter[prevIdx];
             const auto& ptCurr = localOuter[i];
             const auto& ptNext = localOuter[nextIdx];

             pushEdgeSegment(ptCurr.x, localRoofY, ptCurr.z, ptNext.x, localRoofY, ptNext.z);

             // Vertical corner seam at ptCurr only if it represents a genuine architectural corner
             const double inX = ptCurr.x - ptPrev.x;
             const double inZ = ptCurr.z - ptPrev.z;
             const double inLen = std::hypot(inX, inZ);

             const double outX = ptNext.x - ptCurr.x;
             const double outZ = ptNext.z - ptCurr.z;
             const double outLen = std::hypot(outX, outZ);

             if (inLen > 1e-4 && outLen > 1e-4)
             {
                 const double cross = (inX * outZ - inZ * outX) / (inLen * outLen);
                 const double dot = (inX * outX + inZ * outZ) / (inLen * outLen);
                 const double turnAngleDeg = std::acos(std::clamp(dot, -1.0, 1.0)) * 180.0 / std::numbers::pi;
                 if (turnAngleDeg >= 65.0 && turnAngleDeg <= 115.0 && std::abs(cross) > 0.5)
                 {
                     const float baseA = !localOuterBaseY.empty() ? localOuterBaseY[i] : localBaseY;
                     pushEdgeSegment(ptCurr.x, baseA, ptCurr.z, ptCurr.x, localRoofY, ptCurr.z);
                 }
             }
         }

         // Hole roof perimeters and vertical seams
         for (const auto& hole : localHoles)
         {
             const size_t holeCount = hole.size();
             for (size_t i = 0; i < holeCount; ++i)
             {
                 size_t prevIdx = (i + holeCount - 1) % holeCount;
                 size_t nextIdx = (i + 1) % holeCount;
                 const auto& ptPrev = hole[prevIdx];
                 const auto& ptCurr = hole[i];
                 const auto& ptNext = hole[nextIdx];

                 pushEdgeSegment(ptCurr.x, localRoofY, ptCurr.z, ptNext.x, localRoofY, ptNext.z);

                 const double inX = ptCurr.x - ptPrev.x;
                 const double inZ = ptCurr.z - ptPrev.z;
                 const double inLen = std::hypot(inX, inZ);

                 const double outX = ptNext.x - ptCurr.x;
                 const double outZ = ptNext.z - ptCurr.z;
                 const double outLen = std::hypot(outX, outZ);

                 if (inLen > 1e-4 && outLen > 1e-4)
                 {
                     const double cross = (inX * outZ - inZ * outX) / (inLen * outLen);
                     const double dot = (inX * outX + inZ * outZ) / (inLen * outLen);
                     const double turnAngleDeg = std::acos(std::clamp(dot, -1.0, 1.0)) * 180.0 / std::numbers::pi;
                     if (turnAngleDeg >= 65.0 && turnAngleDeg <= 115.0 && std::abs(cross) > 0.5)
                     {
                         pushEdgeSegment(ptCurr.x, localBaseY, ptCurr.z, ptCurr.x, localRoofY, ptCurr.z);
                     }
                 }
             }
         }

         result.emittedBuildingIds.push_back(bldg.buildingId);
     }

     result.roofPrimitive.localBounds = roofBounds;
     result.wallPrimitive.localBounds = wallBounds; 
     result.edgePrimitive.localBounds = edgeBounds;

     return result;
}
