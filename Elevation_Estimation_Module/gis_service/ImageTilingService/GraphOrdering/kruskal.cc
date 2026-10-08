#include "kruskal.h"
#include "DisjointSet.h"
#include<numeric>

MST_TileGraph Kruskal::findMST_Kruskal(std::vector<OverlapEdge>&edges,uint32_t maxNodeId)
{
     //array of index of the edges 
     std::vector<uint32_t> edgeIndices(edges.size());
     //fill the array with consecutive indices upto maxNodeId
     std::iota(edgeIndices.begin(),edgeIndices.end(),0);    

     //in kruskal we have to apply the sorting on the edges according to the weights
     //and then apply disjoint set. here, the edges is a struct. sorting it will involve
     //repeated copying of structs in predefined std::sort of c++ using combination of quick and heap sort
     //so instead we can sort the edge Index array based on the edge weights in the edges array
     //this improves cache locality as the entire edge index array can accumulate in CPU cache
     //upto a certain size

     auto cmp=[&](uint32_t i1,uint32_t i2)->bool
     {
         //compare based on the edge weights at these indices
         return edges[i1].penalty_weight<edges[i2].penalty_weight;
     };

     std::sort(edgeIndices.begin(),edgeIndices.end(),cmp);

     //as the edges are sorted, we can simply go through the edge indices and use DSU for kruskal
     //initialise disjoint set
     DisjointSet dsu(maxNodeId);

     //initialise tile graph
     MST_TileGraph tileGraph(maxNodeId+1,std::vector<MSTEdge>());

     uint32_t edgesAdded = 0;
     for(uint32_t edgeIndex:edgeIndices)
     {
         uint32_t u=edges[edgeIndex].source_tile_id;
         uint32_t v=edges[edgeIndex].target_tile_id;
         float wt=edges[edgeIndex].penalty_weight;
         float s=edges[edgeIndex].local_scale;
         float t=edges[edgeIndex].local_shift;
         if(!dsu.isSameComponent(u,v))
         {
             //these 2 are from different components, so we add this edge
             tileGraph[u].emplace_back(v,s,t);
             tileGraph[v].emplace_back(u, 1.0f / s, -t / s);
             edgesAdded++;
         }
         if(edgesAdded==maxNodeId)
         {
             break;
         }
     }

     return tileGraph;
}