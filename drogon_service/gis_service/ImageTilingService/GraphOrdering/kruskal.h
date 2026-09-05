#include<vector>
#include<algorithm>
#include "drogon_service/gis_service/structures/TileGraph.h"

using MST_TileGraph=std::vector<std::vector<MSTEdge>>;

class Kruskal
{
     public:
     //get the min spanning tree graph from kruskal
     MST_TileGraph findMST_Kruskal(std::vector<OverlapEdge>&edges,uint32_t maxNodeId);
};