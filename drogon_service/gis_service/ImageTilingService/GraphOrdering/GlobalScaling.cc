#include "GlobalScaling.h"
#include <queue>

std::vector<GlobalTransformations> GlobalScaler::findGlobalTransformation(
     const MST_TileGraph& mstTileGraph, uint32_t maxNodeId,uint32_t rootNodeId)
    
{
     //visited array 
     std::vector<bool>visited(maxNodeId+1,false);
     std::queue<uint32_t> queue;    
     //this vector serves as the global map for every tile required while doing the stitching
     //process. index of this vector is the nodeId, that needs no hashing, reducing overload
     std::vector<GlobalTransformations> globalTransformations(maxNodeId+1);

     //root node will be the node with the maximum variance for best terrain features
     queue.push(rootNodeId);
     visited[rootNodeId]=true;
     //alloting default values for the root node
     globalTransformations[rootNodeId].scale=1;
     globalTransformations[rootNodeId].shift=0;

     //applying global scale BFS on the MST
     while(!queue.empty())
     {
         //spread BFS by levels
         uint32_t currNode=queue.front();
         float parent_GlobalScale=globalTransformations[currNode].scale;
         float parent_GlobalShift=globalTransformations[currNode].shift;
         queue.pop();
         for(const auto &edge:mstTileGraph[currNode])
         {
             uint32_t neighId=edge.targetNode;
             if(!visited[neighId])
             {
                 //mark current node as visited
                 visited[neighId]=true;
                 //applying global scale and shift transformations

                 float neigh_curr_Scale=edge.localScale;
                 float neigh_curr_Shift=edge.localShift;
                
                 //applying s(k)_global=s(k)_local*s(parent(k))_global
                 //t(k)_global=t(k)_local*s(parent(k))_global+t(parent(k))_global
                 float neigh_GlobalScale=neigh_curr_Scale*parent_GlobalScale;
                 float neigh_GlobalShift=neigh_curr_Shift*parent_GlobalScale+parent_GlobalShift;

                 //clamping for AI noise
                 neigh_GlobalScale=std::max(std::min(neigh_GlobalScale,float(2.0)),float(0.5));

                 //pushing values to global transformations map
                 globalTransformations[neighId]={neigh_GlobalScale,neigh_GlobalShift};

                 //push neigh to queue
                 queue.push(neighId);
             }
         }
     }

     return globalTransformations;
}