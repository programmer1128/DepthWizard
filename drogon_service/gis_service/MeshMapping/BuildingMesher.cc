#include "BuildingMesher.h"
#include <cmath>
#include <algorithm>
#include <limits>
#include <cstdint>
#include <stdexcept>

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

//ear clipping triangulator
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
     const BuildingMeshConfig& config)
{
     BuildingMesh result;

     if (!config.validate())
     {
         throw std::invalid_argument("BuildingMesher: invalid mesh configuration");
     }
    
     // Initialize Roof Primitive
     result.roofPrimitive.topology = PrimitiveTopology::TRIANGLES;
     result.roofPrimitive.materialRole = MaterialRole::BUILDING_ROOF;
     result.roofPrimitive.featureIds.emplace(); // Activate feature tracking
     result.roofPrimitive.normals.emplace();
     
     // Initialize Wall Primitive
     result.wallPrimitive.topology = PrimitiveTopology::TRIANGLES;
     result.wallPrimitive.materialRole = MaterialRole::BUILDING_WALL;
     result.wallPrimitive.featureIds.emplace();
     result.wallPrimitive.normals.emplace();
    
     if (config.generateRoofUVs) result.roofPrimitive.uvs.emplace();
     if (config.generateWallUVs) result.wallPrimitive.uvs.emplace();

     AxisAlignedBounds roofBounds; roofBounds.isInitialized = false;
     roofBounds.minX = roofBounds.minY = roofBounds.minZ = std::numeric_limits<double>::max();
     roofBounds.maxX = roofBounds.maxY = roofBounds.maxZ = std::numeric_limits<double>::lowest();

     AxisAlignedBounds wallBounds = roofBounds;

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
                 auto pushWallVertex = [&](double vx, float vy, double vz) 
                 {
                     result.wallPrimitive.positions.push_back(static_cast<float>(vx));
                     result.wallPrimitive.positions.push_back(vy);
                     result.wallPrimitive.positions.push_back(static_cast<float>(vz));
                     
                     result.wallPrimitive.normals->push_back(nx);
                     result.wallPrimitive.normals->push_back(0.0f);
                     result.wallPrimitive.normals->push_back(nz);
                    
                     result.wallPrimitive.featureIds->push_back(
                         static_cast<float>(bldg.buildingId));

                     wallBounds.isInitialized = true;

                     wallBounds.minX = std::min(wallBounds.minX, vx); wallBounds.maxX = std::max(wallBounds.maxX, vx);
                     wallBounds.minY = std::min(wallBounds.minY, static_cast<double>(vy)); wallBounds.maxY = std::max(wallBounds.maxY, static_cast<double>(vy));
                     wallBounds.minZ = std::min(wallBounds.minZ, vz); wallBounds.maxZ = std::max(wallBounds.maxZ, vz);
                 };

                 pushWallVertex(ptA.x, baseA, ptA.z); // Base A (Index 0)
                 pushWallVertex(ptA.x, localRoofY, ptA.z); // Roof A (Index 1)
                 pushWallVertex(ptB.x, localRoofY, ptB.z); // Roof B (Index 2)
                 pushWallVertex(ptB.x, baseB, ptB.z); // Base B (Index 3)

                 // Two triangles per wall
                 result.wallPrimitive.indices.push_back(wallIdxBase + 0);
                 result.wallPrimitive.indices.push_back(wallIdxBase + 1);
                 result.wallPrimitive.indices.push_back(wallIdxBase + 2);

                 result.wallPrimitive.indices.push_back(wallIdxBase + 0);
                 result.wallPrimitive.indices.push_back(wallIdxBase + 2);
                 result.wallPrimitive.indices.push_back(wallIdxBase + 3);
             }
         };

         extrudeRing(
             localOuter,
             localOuterBaseY.empty() ? nullptr : &localOuterBaseY);
         for (const auto& hole : localHoles) 
         {
             extrudeRing(hole, nullptr);
         }
     }

     result.roofPrimitive.localBounds = roofBounds;
     result.wallPrimitive.localBounds = wallBounds; 

     return result;
}
