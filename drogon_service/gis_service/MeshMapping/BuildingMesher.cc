#include "BuildingMesher.h"
#include <cmath>
#include <algorithm>
#include <limits>
#include <cstdint>

//ear clipping triangulator
float BuildingMesher::crossProduct(const LocalPoint& a, const LocalPoint& b, const LocalPoint& c) 
{
     return static_cast<float>((b.x - a.x) * (c.z - b.z) - (b.z - a.z) * (c.x - b.x));
}

bool BuildingMesher::isPointInsideTriangle(const LocalPoint& pt, 
     const LocalPoint& v1, const LocalPoint& v2,const LocalPoint& v3) 
{
     bool b1 = crossProduct(pt, v1, v2) < 0.0f;
     bool b2 = crossProduct(pt, v2, v3) < 0.0f;
     bool b3 = crossProduct(pt, v3, v1) < 0.0f;
     return ((b1 == b2) && (b2 == b3));
}

std::vector<uint32_t> BuildingMesher::triangulate(
     const std::vector<LocalPoint>& outerRing, 
     const std::vector<std::vector<LocalPoint>>& holes) 
{
     std::vector<uint32_t> indices;
     if (outerRing.size() < 3) 
     {
         return indices;
     }

     // Merge holes into the outer ring using "bridge" edges
     std::vector<LocalPoint> poly = outerRing;
     for (const auto& hole : holes) 
     {
         if (hole.empty()) 
         {
             continue;
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
        
         // Find closest mutually visible point on the outer polygon to bridge to
         size_t polyBridgeIdx = 0;
         float minDist = std::numeric_limits<float>::max();
         for (size_t i = 0; i < poly.size(); ++i) 
         {
             if (poly[i].x > hole[holeRightMostIdx].x) 
             {
                 float dist = static_cast<float>(std::abs(poly[i].x - hole[holeRightMostIdx].x) + std::abs(poly[i].z - hole[holeRightMostIdx].z));
                 if (dist < minDist) 
                 {
                     minDist = dist;
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
             if (crossProduct(poly[iPrev], poly[iCurr], poly[iNext]) >= 0.0f) 
             {
                 bool isEar = true;
                 // Verify no other points fall inside this ear
                 for (size_t j = 0; j < remaining.size(); ++j) 
                 {
                     if (j == prev || j == i || j == next)
                     { 
                         continue;
                     } 
                     if (isPointInsideTriangle(poly[remaining[j]], poly[iPrev], poly[iCurr], poly[iNext])) {
                         isEar = false;
                         break;
                     }
                 }
                
                 if (isEar) 
                 {
                     indices.push_back(iPrev);
                     indices.push_back(iCurr);
                     indices.push_back(iNext);
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
         indices.push_back(remaining[0]);
          indices.push_back(remaining[1]);
        indices.push_back(remaining[2]);
     }
     return indices;
}



//method for mesh generation
BuildingMesh BuildingMesher::generate(
     const BuildingCollection& buildings,
     const LocalSceneFrame& frame,
     const BuildingMeshConfig& config)
{
     BuildingMesh result;
    
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
        
         std::vector<std::vector<LocalPoint>> localHoles;
         for (const auto& hole : bldg.projectedFootprint.holes) 
         {
             std::vector<LocalPoint> lHole;
             for (const auto& pt : hole) 
             {
                 lHole.push_back(LocalFrameTransformer::toLocal(pt, frame));
             }
             localHoles.push_back(lHole);
         }

         float localRoofY = LocalFrameTransformer::toLocalElevation(bldg.roofElevation, frame);
         float localBaseY = LocalFrameTransformer::toLocalElevation(bldg.representativeBaseElevation, frame);

         /*
         *Roof Generation of building
         */
         uint32_t roofIndexOffset = static_cast<uint32_t>(result.roofPrimitive.positions.size() / 3);
         
         std::vector<uint32_t> localIndices = triangulate(localOuter, localHoles);
         for (uint32_t idx : localIndices) 
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
            
             result.roofPrimitive.featureIds->push_back(bldg.buildingId);

             roofBounds.isInitialized = true;

             roofBounds.minX = std::min(roofBounds.minX, pt.x); roofBounds.maxX = std::max(roofBounds.maxX, pt.x);
             roofBounds.minY = std::min(roofBounds.minY, static_cast<double>(localRoofY)); roofBounds.maxY = std::max(roofBounds.maxY, static_cast<double>(localRoofY));
             roofBounds.minZ = std::min(roofBounds.minZ, pt.z); roofBounds.maxZ = std::max(roofBounds.maxZ, pt.z);
         };

         for (const auto& pt : localOuter) 
         {
             addRoofVertex(pt);
         }
         for (const auto& hole : localHoles) 
         {
             for (const auto& pt : hole) 
             {
                 addRoofVertex(pt);
             }
         }

       
         /*
         *Wall generation
         */
         auto extrudeRing = [&](const std::vector<LocalPoint>& ring) 
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

                 // Push 4 independent vertices per wall quad to guarantee crisp corners
                 auto pushWallVertex = [&](double vx, float vy, double vz) 
                 {
                     result.wallPrimitive.positions.push_back(static_cast<float>(vx));
                     result.wallPrimitive.positions.push_back(vy);
                     result.wallPrimitive.positions.push_back(static_cast<float>(vz));
                     
                     result.wallPrimitive.normals->push_back(nx);
                     result.wallPrimitive.normals->push_back(0.0f);
                     result.wallPrimitive.normals->push_back(nz);
                    
                     result.wallPrimitive.featureIds->push_back(bldg.buildingId);

                     wallBounds.isInitialized = true;

                     wallBounds.minX = std::min(wallBounds.minX, vx); wallBounds.maxX = std::max(wallBounds.maxX, vx);
                     wallBounds.minY = std::min(wallBounds.minY, static_cast<double>(vy)); wallBounds.maxY = std::max(wallBounds.maxY, static_cast<double>(vy));
                     wallBounds.minZ = std::min(wallBounds.minZ, vz); wallBounds.maxZ = std::max(wallBounds.maxZ, vz);
                 };

                 pushWallVertex(ptA.x, localBaseY, ptA.z); // Base A (Index 0)
                 pushWallVertex(ptA.x, localRoofY, ptA.z); // Roof A (Index 1)
                 pushWallVertex(ptB.x, localRoofY, ptB.z); // Roof B (Index 2)
                 pushWallVertex(ptB.x, localBaseY, ptB.z); // Base B (Index 3)

                 // Two triangles per wall
                 result.wallPrimitive.indices.push_back(wallIdxBase + 0);
                 result.wallPrimitive.indices.push_back(wallIdxBase + 2);
                 result.wallPrimitive.indices.push_back(wallIdxBase + 1);

                 result.wallPrimitive.indices.push_back(wallIdxBase + 0);
                 result.wallPrimitive.indices.push_back(wallIdxBase + 3);
                 result.wallPrimitive.indices.push_back(wallIdxBase + 2);
             }
         };

         extrudeRing(localOuter);
         for (const auto& hole : localHoles) 
         {
             extrudeRing(hole);
         }
     }

     result.roofPrimitive.localBounds = roofBounds;
     result.wallPrimitive.localBounds = wallBounds; 

     return result;
}
