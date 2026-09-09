#pragma once 

#include <span> // imports span
#include "../structures/TileGraph.h"

// this class has mathematical formulas needed to figure out how to blend 2 overlapping tiles together
class OlsAlignment 
{
    public:

    // calculates the perfect scale (s multiplier), shift (t addition) and Pearson correlation
    // returns an OverlapEdge object

    static OverlapEdge computeAlignment(
        uint32_t source_id, 
        uint32_t target_id, 
        std::span<const float> source_overlap, 
        std::span<const float> target_overlap,
        float no_data_value = -9999.0f // req for pitfall 5
    );

    // source_id: reference tile - A - B
    // target_id: neighbour tile
    // source_overlap: pointer to the overlapping pixels of A
    // target_overlap: pointer to the overlapping pixels of B
    // no_data_value: if a pixel has this value, ignore it
};