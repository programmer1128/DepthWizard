#pragma once
#include <cstdint>

struct OverlapEdge 
{
     //The tiles will form a graph. Now the tiles are matrices. so
     //for every tile we need a unique id to identify them. for a max threshold of 
     //16384*16384 pixels matrix there will be more than 10^10 pixels. for every 518*518 10^6
     //we get approx 10^4 tiles, fitting comfortably in unint32_t range
     uint32_t source_tile_id; 
     uint32_t target_tile_id;
    
     // The OLS Parameters
     float local_scale;       // The s value for scale
     float local_shift;       // The t value for offset
    
     // The Topological Confidence
     float penalty_weight;    // 1.0 - Pearson Correlation
};

typedef struct MSTEdge
{
      uint32_t targetNode;
      float localScale;
      float localShift;

      MSTEdge(uint32_t tgt, double s, double t) 
        : targetNode(tgt), localScale(s), localShift(t) {}
}MSTEdge;

typedef struct GlobalTransformations
{
      float scale;
      float shift;
};