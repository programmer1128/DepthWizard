#pragma once

#include <vector>
#include <string>
#include <cstdint>

// Defines the 2D window boundaries within the flattened 1D absolute DSM array
struct MatrixBounds
{
    int x_offset; // starting col (X-axis) of the curr quadrant relative to the absolute top-left corner
    int y_offset; // starting row (Y-axis) of the curr quadrant relative to the top-left corner
    int width;
    int height;
};

// Represents a single tile at a specific zoom level (Pure POD Structure)
struct QuadNode
{
    uint32_t id;
    int level;

    float error; // Topographical variance (determines subdivision) -> Level of Detail (LOD) algorithm : low variance halts subdivision to optimize flat terrain, while high variance triggers a split to capture sharp elevation changes

    MatrixBounds bounds;
    std::string glb_url; // to be populated later by MinIO upload
};

// Compressed Sparse Row (CSR) implementation for the QuadTree graph
struct QuadTreeGraph
{
    std::vector<QuadNode> nodes; // idx i corresponds to node id i

    // 1D Array of edges containing the ids of child nodes
    std::vector<uint32_t> edges;

    // Index vector marking the start/end of a parent's children in the edges array
    // Children of node 'i' are in edges[ edge_markers[i] ] to edges[ edge_markers[i+1] - 1 ]
    std::vector<uint32_t> edge_markers;
};