#pragma once
#include "drogon_service/gis_service/structures/TileGraph.h"
#include<vector>

using MST_TileGraph=std::vector<std::vector<MSTEdge>>;

class GlobalScaler
{   
     public:
     std::vector<GlobalTransformations> findGlobalTransformation(const MST_TileGraph& mstTileGraph,
         uint32_t maxNodeId, uint32_t rootNodeId );
};