#pragma once

#include <vector>
#include <memory>
#include <cstdint>

// stores the zero copy AI output
// stores the details of each tile
// each tile is 518 * 518

struct TileMetadata 
{
    uint32_t tile_id; // unsigned 32 bit int, no -ve numbers, unique id to each tile

    // dimensions of the tile
    int width;
    int height;

    // displacement from top left of image
    // to know where the tile lies in the image
    int x_offset;
    int y_offset;

    // a topographical texture score
    // high: bumpy mountain ; low: flat lake
    float variance; 
    

    // std::shared_ptr guarantees we do not copy the massive float matrix in RAM
    // we just share the memory address of existing array
    std::shared_ptr<std::vector<float>> depth_matrix; 
};

// this struct represents the overlapping boundary between 2 adjacent tiles

struct OverlapEdge 
{
    // the ID of the reference tile - the one kept still
    uint32_t source_tile_id;

    // the ID of the neighboring tile - the one we are trying to align to the source tile
    uint32_t target_tile_id;

    // the s multiplier calculated by Ordinary Least Squares: OLS math 
    float local_scale;        

    // the t addition calculated by OLS math
    float local_shift;        

    // 1.0 minus the pearson correlation
    // score closer to 0.0 means the overlap is a perfect match 
    // higher score means its a bad match: ignore later
    float penalty_weight;     
};

// this struct is the payload for the graph portion of the service

struct GraphPayload 
{
    // dynamic list containing every tile processed
    std::vector<TileMetadata> all_tiles;     
    
    // dynamic list containing every OLS alignment connection: edge
    std::vector<OverlapEdge> graph_edges;    
    
    // tile id that had the highest variance 
    uint32_t root_anchor_id;                 
    
    // highest tile ID generated during extraction loop 
    uint32_t max_tile_id;                    
};