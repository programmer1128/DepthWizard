#pragma once

#include <vector>
#include <cstdint>
#include "../utils/QuadTreeTypes.h"

class QuadTreeBuilder
{
public:
    // entry point returning the fully flattened QuadTreeGraph directly
    static QuadTreeGraph buildTree(
        const std::vector<float> &absolute_dsm,
        int total_width,
        int total_height,
        int max_level,
        float error_threshold);

    // isolated helper function to calculate LOD parameters
    static void computeHeuristics(
        const std::vector<float> &absolute_dsm,
        int total_width,
        int total_height,
        int &max_level,
        float &error_threshold);

private:
    // calculates topographical variance for a specific matrix window
    static float calculateVariance(
        const std::vector<float> &matrix,
        const MatrixBounds &bounds,
        int total_width);

    // recursive engine utilizing the 4 recursive call structure
    static void recursiveQuadTree(
        QuadTreeGraph &graph,
        std::vector<std::vector<uint32_t>> &temp_adj,
        uint32_t current_id,
        const std::vector<float> &absolute_dsm,
        int total_width,
        int max_level,
        float error_threshold,
        uint32_t &id_counter);
};