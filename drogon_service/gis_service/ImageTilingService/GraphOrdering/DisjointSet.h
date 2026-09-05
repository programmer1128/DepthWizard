#pragma once
#include <cstdint>
#include<vector>

class DisjointSet
{
     private:
     uint32_t findParent(std::vector<uint32_t>&parent,uint32_t);
     std::vector<uint32_t> parent;
     std::vector<uint32_t> size;
     public:
     DisjointSet(uint32_t maxNodeId);
     
     bool isSameComponent(uint32_t u,uint32_t v);
};