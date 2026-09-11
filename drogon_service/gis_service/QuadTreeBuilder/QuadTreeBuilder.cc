#include "QuadTreeBuilder.h"
#include <cmath>
#include <stdexcept>
#include <iostream>
#include <algorithm> // Required for std::max

QuadTreeGraph QuadTreeBuilder::buildTree(const std::vector<float> &absolute_dsm, int total_width, int total_height, int max_level, float error_threshold)
{
     if (absolute_dsm.empty() || total_width <= 0 || total_height <= 0) // empty dsm or invalid dimensions
     {
         throw std::invalid_argument("QuadTreeBuilder: Invalid absolute DSM dimensions.");
     }

     QuadTreeGraph graph; // final data to be returned

     // std::vector<std::vector<uint32_t>> temp_adj; // temp 2D list to store edge mappings during DFS

     // replacing the 2D temp_adj array with a flat 1D map
     std::vector<uint32_t> first_child_map;
     // preallocation of mem to prevent costly vector resizing
     first_child_map.reserve(10000);
     graph.nodes.reserve(10000);

     QuadNode root; // root node as level 0
     root.id = 0;
     root.level = 0;
    root.error = 0.0f;
    root.bounds = {0, 0, total_width, total_height};

    // root node is pushed to the QuadNodes arr at idx 0
    graph.nodes.push_back(root);

    // temp_adj.emplace_back(); // an empty list initialised for the root node
    first_child_map.push_back(0); // root initialized with no children

    uint32_t id_counter = 1; // global id counter passed by reference down the recursion tree

    // recursive call starting at id 0
    recursiveQuadTree(graph, first_child_map, 0, absolute_dsm, total_width, max_level, error_threshold, id_counter);

    // mem preallocation for the final CSR graph arrays
    if (graph.nodes.size() > 1)
    {
        graph.edges.reserve(graph.nodes.size() - 1); // Total edges is always (Total Nodes - 1)
    }
    graph.edge_markers.resize(graph.nodes.size() + 1, 0); // (n+1) markers for n nodes

    // building the csr format
    for (size_t i = 0; i < graph.nodes.size(); ++i) // iterates through all the nodes of the graph
    {
        // the starting index in the edges array for the current node's children
        graph.edge_markers[i] = static_cast<uint32_t>(graph.edges.size());

        /*
        for (uint32_t child_id : temp_adj[i]) // itr through children of each node
        {
            graph.edges.push_back(child_id);
        }
        */

        // ids are perfectly sequential, if a node has children, we instantly know all 4 IDs
        if (first_child_map[i] != 0)
        {
            graph.edges.push_back(first_child_map[i]);
            graph.edges.push_back(first_child_map[i] + 1);
            graph.edges.push_back(first_child_map[i] + 2);
            graph.edges.push_back(first_child_map[i] + 3);
        }
    }
    // capping the marker arr so the length of the last node's edges can be calculated
    graph.edge_markers[graph.nodes.size()] = static_cast<uint32_t>(graph.edges.size()); // the last idx gives the total number of edges in the graph

    return graph;
}

void QuadTreeBuilder::computeHeuristics(const std::vector<float> &absolute_dsm, int total_width, int total_height, int &max_level, float &error_threshold)
{
    // Max Level: calculated based on the patch size limit
    int min_leaf_size = 16; // the smallest allowable tile dimension (16x16 pixels)
    int max_dim = std::max(total_width, total_height);
    // if the map is smaller than the minimum leaf -> level 0 is forced
    if (max_dim <= min_leaf_size)
    {
        max_level = 0;
    }
    else
    {
        max_level = static_cast<int>(std::log2(max_dim / min_leaf_size));
    }

    // Error Threshold: the global variance of the entire dsm
    MatrixBounds root_bounds = {0, 0, total_width, total_height};
    float global_variance = calculateVariance(absolute_dsm, root_bounds, total_width);

    // threshold set to a 5% of the global baseline -> it means, only split a tile if its local roughness is at least 5% as extreme as the entire map's roughness
    error_threshold = global_variance * 0.05f;

    // fallback floor to avoid an impossible threshold on perfectly flat maps -> acts as noise gate
    if (error_threshold < 0.1f)
    {
        error_threshold = 0.1f;
    }
}

void QuadTreeBuilder::recursiveQuadTree(QuadTreeGraph &graph, std::vector<uint32_t> &first_child_map, uint32_t current_id, const std::vector<float> &absolute_dsm, int total_width, int max_level, float error_threshold, uint32_t &id_counter) // current_id acts as the base of the recursion
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

    uint32_t first_child_id = id_counter; // the starting id for this block of 4 children
    // uint32_t child_ids[4]; // temporary stores ids of the 4 children of current node

    // 4 children nodes generated sequentially
    for (int i = 0; i < 4; ++i)
    {
        QuadNode child;
        child.id = id_counter++;
        child.level = level + 1;
        child.bounds = child_bounds[i];
        child.error = 0.0f;

        // child_ids[i] = child.id;

        graph.nodes.push_back(child); // 4 children are pushed back seq. into the nodes arr
        first_child_map.push_back(0); // initialisation of newly created child as a leaf in the map

        // temp_adj.emplace_back();                      // creates a blank edge list for newly created child
        // temp_adj[current_id].push_back(child_ids[i]); // add the child into the curr parent's edge list
    }

    first_child_map[current_id] = first_child_id; // the curr parent is linked to its first child

    // 4 Sequential Recursive Calls (DFS) using sequential math
    recursiveQuadTree(graph, first_child_map, first_child_id, absolute_dsm, total_width, max_level, error_threshold, id_counter);
    recursiveQuadTree(graph, first_child_map, first_child_id + 1, absolute_dsm, total_width, max_level, error_threshold, id_counter);
    recursiveQuadTree(graph, first_child_map, first_child_id + 2, absolute_dsm, total_width, max_level, error_threshold, id_counter);
    recursiveQuadTree(graph, first_child_map, first_child_id + 3, absolute_dsm, total_width, max_level, error_threshold, id_counter);

    /*
    // 4 Sequential Recursive Calls (DFS)
    recursiveQuadTree(graph, temp_adj, child_ids[0], absolute_dsm, total_width, max_level, error_threshold, id_counter);
    recursiveQuadTree(graph, temp_adj, child_ids[1], absolute_dsm, total_width, max_level, error_threshold, id_counter);
    recursiveQuadTree(graph, temp_adj, child_ids[2], absolute_dsm, total_width, max_level, error_threshold, id_counter);
    recursiveQuadTree(graph, temp_adj, child_ids[3], absolute_dsm, total_width, max_level, error_threshold, id_counter);
    */
}

float QuadTreeBuilder::calculateVariance(const std::vector<float> &matrix, const MatrixBounds &bounds, int total_width)
{
    double sum = 0.0;
    double sq_sum = 0.0;
    int valid_pixels = 0;

    // Variance Calculation
    for (int r = bounds.y_offset; r < bounds.y_offset + bounds.height; ++r)
    {
        int row_start_idx = r * total_width;
        for (int c = bounds.x_offset; c < bounds.x_offset + bounds.width; ++c)
        {
            float val = matrix[row_start_idx + c];
            if (!std::isnan(val))
            {
                double d_val = static_cast<double>(val);
                sum += d_val;              // sum of all valid elevations
                sq_sum += (d_val * d_val); // accum sqrs simultaneously
                valid_pixels++;            // count of valid pixels
            }
        }
    }

    if (valid_pixels == 0) // the entire tile is void space -> return safely
        return 0.0f;

    // mathematical formula for single-pass variance: Variance = E[X^2] - (E[X])^2
    double mean = sum / valid_pixels;
    double mean_of_squares = sq_sum / valid_pixels;

    float variance = static_cast<float>(mean_of_squares - (mean * mean));

    // clamping to 0 to handle floating point inaccuracies resulting in negative numbers
    return variance > 0.0f ? variance : 0.0f;
}