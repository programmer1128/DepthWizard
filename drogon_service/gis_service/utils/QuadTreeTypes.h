#pragma once

#include <vector>
#include <string>
#include <map>
#include <cstdint>

// defines the bounding box of the quad node
struct MatrixBounds 
{
    int x_offset;
    int y_offset;
    int width;
    int height;
};

// strict for a single quad node to be converted to 3D mesh
struct QuadNode 
{
    uint32_t id;         // unique id
    int level;           // zoom level (0: fully zoomed out)
    float error;         // geometric variance 
    MatrixBounds bounds; // exact pixel coordinates
    std::string glb_url; // url of MinIO where .glb is stored
};

// graph structure
struct QuadTreeGraph 
{
    std::vector<QuadNode> nodes;          // array of all quad nodes
    std::vector<uint32_t> edges;          // array of child IDs
    std::vector<size_t> edge_markers;     // index array showing where children start and stop 
};

/*  WE DO NOT NEED HASH MAPS NOW 

// structure for hash maps
struct QuadTreeRegistry 
{
    // ordered maps
    std::map<uint32_t, std::string> url_map;        // <node_id, glb_url>   
    std::map<int, std::vector<uint32_t>> level_map;   // <level id, list of node IDs of all nodes in that level>
};
*/