#include "DisjointSet.h"

uint32_t DisjointSet::findParent(std::vector<uint32_t>&parent,uint32_t u)
{
     if(u==parent[u])
     {
         return u;
     }
     //applying path compression
     return parent[u]=findParent(parent,parent[u]);
}

DisjointSet::DisjointSet(uint32_t maxNodeId)
{
     parent.resize(maxNodeId+1);
     size.resize(maxNodeId+1);
     for(uint32_t i=0;i<=maxNodeId;i++)
     {
         parent[i]=i;
         size[i]=1;
     }
}

bool DisjointSet::isSameComponent(uint32_t u,uint32_t v)
{
     uint32_t parentU=findParent(parent,u);
     uint32_t parentV=findParent(parent,v);

     if(parentU==parentV)
     {
         return true;
     }

     if(size[parentU]<size[parentV])
     {
         //merge the smaller component to the larger to reduce compression 
         parent[parentU]=parentV;
         size[parentV]+=size[parentU];
     }
     else
     {
         parent[parentV]=parentU;
         size[parentU]+=size[parentV];
     }
     return false;
}