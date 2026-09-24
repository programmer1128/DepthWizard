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
     struct TriangulationResult
     {
         std::vector<LocalPoint> vertices;
         std::vector<uint32_t> indices;
     };

     // Lightweight ear-clipping triangulator supporting holes via bridge
     // edges. Vertices are returned with indices because bridging duplicates
     // vertices and changes their order.
     static TriangulationResult triangulate(
         const std::vector<LocalPoint>& outerRing, 
         const std::vector<std::vector<LocalPoint>>& holes);

     static double signedArea(const std::vector<LocalPoint>& ring);
     static bool isPointInsideTriangle(const LocalPoint& pt, const LocalPoint& v1, const LocalPoint& v2, const LocalPoint& v3);
     static float crossProduct(const LocalPoint& a, const LocalPoint& b, const LocalPoint& c);
};
