#pragma once
#include "BuildingMeshConfig.h"
#include "LocalFrameTransformer.h"
#include "../structures/GeographicStructs.h"
#include "../structures/MeshStructs.h"

class BuildingMesher 
{
     public:
     static BuildingMesh generate(
         const BuildingCollection& buildings,
         const LocalSceneFrame& frame,
         const BuildingMeshConfig& config = BuildingMeshConfig());

     private:
     // Lightweight Ear-Clipping triangulator supporting holes via bridge-edges
     static std::vector<uint32_t> triangulate(
         const std::vector<LocalPoint>& outerRing, 
         const std::vector<std::vector<LocalPoint>>& holes);
        
     static bool isPointInsideTriangle(const LocalPoint& pt, const LocalPoint& v1, const LocalPoint& v2, const LocalPoint& v3);
     static float crossProduct(const LocalPoint& a, const LocalPoint& b, const LocalPoint& c);
};