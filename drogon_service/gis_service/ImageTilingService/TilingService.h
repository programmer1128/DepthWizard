#pragma once
#include <string>
#include <vector>
#include <drogon/drogon.h>
#include <drogon/utils/coroutine.h>

class TilingService 
{
public:
    // Orchestrates the tiling, graph alignment, and Hann assembly.
    // Returns the finalized continuous 1D depth matrix.
    static drogon::Task<std::vector<float>> generateStitchedDepth(
        const std::string& vsi_path, 
        int globalWidth, 
        int globalHeight);
};