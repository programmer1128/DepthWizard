#include "QuadTreeBuilder.h"
#include <cmath>
#include <stdexcept>
#include <iostream>

QuadTreeGraph QuadTreeBuilder::buildTree(const std::vector<float> &absolute_dsm, int total_width, int total_height, int max_level, float error_threshold)
{
    if (absolute_dsm.empty() || total_width <= 0 || total_height <= 0) // empty dsm or invalid dimensions
    {
        throw std::invalid_argument("QuadTreeBuilder: Invalid absolute DSM dimensions.");
    }

    QuadTreeGraph graph;                         // final data to be returned
    std::vector<std::vector<uint32_t>> temp_adj; // temp 2D list to store edge mappings during DFS

    QuadNode root; // root node as level 0
    root.id = 0;
    root.level = 0;
    root.error = 0.0f;
    root.bounds = {0, 0, total_width, total_height};

    // root node is pushed to the QuadNodes arr at idx 0
    graph.nodes.push_back(root);
    temp_adj.emplace_back(); // an empty list initialised for the root node

    uint32_t id_counter = 1; // global id counter passed by reference down the recursion tree

    // recursive call starting at id 0
    recursiveQuadTree(graph, temp_adj, 0, absolute_dsm, total_width, max_level, error_threshold, id_counter);

    // preallocation of mem
    graph.edge_markers.resize(graph.nodes.size() + 1, 0); // (n+1) markers for n nodes

    // building the csr format
    for (size_t i = 0; i < graph.nodes.size(); ++i) // iterates through all the nodes of the graph
    {
        // the starting index in the edges array for the current node's children
        graph.edge_markers[i] = static_cast<uint32_t>(graph.edges.size());
        for (uint32_t child_id : temp_adj[i]) // itr through children of each node
        {
            graph.edges.push_back(child_id);
        }
    }
    // capping the marker arr so the length of the last node's edges can be calculated
    graph.edge_markers[graph.nodes.size()] = static_cast<uint32_t>(graph.edges.size()); // the last idx gives the total number of edges in the graph

    return graph;
}

void QuadTreeBuilder::recursiveQuadTree(QuadTreeGraph &graph, std::vector<std::vector<uint32_t>> &temp_adj, uint32_t current_id, const std::vector<float> &absolute_dsm, int total_width, int max_level, float error_threshold, uint32_t &id_counter) // current_id acts as the base of the recursion
{
    // extracting bounds and level directly by value to avoid dangling references, in case graph.nodes vector reallocates memory during push_back() (if the entire block is reallocated)
    MatrixBounds bounds = graph.nodes[current_id].bounds;
    int level = graph.nodes[current_id].level;

    // Base Case 1: Max zoom level reached
    if (level >= max_level)
    {
        return;
    }
    // Base Case 2: Grid is too small to divide into 4 valid quadrants
    if (bounds.width <= 1 || bounds.height <= 1)
    {
        return;
    }

    // terrain variance within the specific node's window
    float error = calculateVariance(absolute_dsm, bounds, total_width);
    graph.nodes[current_id].error = error;

    // Base Case 3: Geometric simplicity (terrain is flat enough)
    if (error < error_threshold)
    {
        return;
    }

    // the midpoints -> calculated integer division to safely split the grid
    int half_w = bounds.width / 2;
    int half_h = bounds.height / 2;
    int rem_w = bounds.width - half_w;
    int rem_h = bounds.height - half_h;

    int x = bounds.x_offset;
    int y = bounds.y_offset;

    // the 4 child boundaries
    MatrixBounds child_bounds[4] = {
        {x, y, half_w, half_h},                // TopLeft
        {x + half_w, y, rem_w, half_h},        // TopRight
        {x, y + half_h, half_w, rem_h},        // BottomLeft
        {x + half_w, y + half_h, rem_w, rem_h} // BottomRight
    };

    uint32_t child_ids[4]; // temporary stores ids of the 4 children of current node

    // 4 children nodes generated sequentially
    for (int i = 0; i < 4; ++i)
    {
        QuadNode child;
        child.id = id_counter++;
        child.level = level + 1;
        child.bounds = child_bounds[i];
        child.error = 0.0f;

        child_ids[i] = child.id;

        graph.nodes.push_back(child); // 4 children are pushed back seq. into the nodes arr

        temp_adj.emplace_back();                      // creates a blank edge list for newly created child
        temp_adj[current_id].push_back(child_ids[i]); // add the child into the curr parent's edge list
    }

    // 4 Sequential Recursive Calls (DFS)
    recursiveQuadTree(graph, temp_adj, child_ids[0], absolute_dsm, total_width, max_level, error_threshold, id_counter);
    recursiveQuadTree(graph, temp_adj, child_ids[1], absolute_dsm, total_width, max_level, error_threshold, id_counter);
    recursiveQuadTree(graph, temp_adj, child_ids[2], absolute_dsm, total_width, max_level, error_threshold, id_counter);
    recursiveQuadTree(graph, temp_adj, child_ids[3], absolute_dsm, total_width, max_level, error_threshold, id_counter);
}

float QuadTreeBuilder::calculateVariance(const std::vector<float> &matrix, const MatrixBounds &bounds, int total_width)
{
    float sum = 0.0f;
    int valid_pixels = 0;

    // Pass 1: Mean
    // itr over the 1D array using 2D row-major logic mapping
    for (int r = bounds.y_offset; r < bounds.y_offset + bounds.height; ++r)
    {
        for (int c = bounds.x_offset; c < bounds.x_offset + bounds.width; ++c)
        {
            float val = matrix[r * total_width + c];
            if (!std::isnan(val))
            {
                sum += val;     // sum of all valid elevations
                valid_pixels++; // count of valid pixels
            }
        }
    }

    if (valid_pixels == 0) // the entire tile is void space -> return safely
        return 0.0f;

    float mean = sum / valid_pixels; // mean -> avg elevation
    float variance_sum = 0.0f;       // variance -> mathematical roughness score of the terrain

    // Pass 2: Variance
    for (int r = bounds.y_offset; r < bounds.y_offset + bounds.height; ++r)
    {
        for (int c = bounds.x_offset; c < bounds.x_offset + bounds.width; ++c)
        {
            float val = matrix[r * total_width + c];
            if (!std::isnan(val))
            {
                float diff = val - mean;       // deviation
                variance_sum += (diff * diff); // sq(deviation)
            }
        }
    }

    return variance_sum / valid_pixels; // avg
}