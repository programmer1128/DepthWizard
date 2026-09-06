#pragma once

#include <string>  
#include <vector>  
#include <memory>  // smart pointers (std::shared_ptr) 
#include <span>    // span: a lightweight zero copy tool 
#include <future>  // tools for multithreading (std::async, std::future) 
#include <drogon/drogon.h> // access to C++20 async coroutines

#include "../utils/TilingTypes.h" 
#include "OlsAlignment.h"  

class TileDispatcher 
{
    public:

    // main orchestrator function
    // this pauses - co-waits and hands over the final data package
    static drogon::Task<GraphPayload> processGeoTiff(const std::string& filepath);


    // the network bridge to Lightning AI
    // sends bytes to clouds and waits for rDSM matrix to come back
    static std::shared_ptr<std::vector<float>> streamToLightningAI(
        std::span<const uint8_t> raw_tile_binary, 
        const std::string& target_gpu_ip, uint32_t tile_id
    );
    // raw_tile_binary: zero-copy window pointing to the 518*518 pixel bytes inside mmap file
    // target_gpu_ip: Tailscale IP address of GPU we are sending this tile to 


    // slices the vertical overlapping region between 2 tiles
    // we have to copy memory as columns are non contagious
    static std::vector<float> extractVerticalOverlap(
        const std::vector<float>& matrix, int tile_w, int tile_h, int overlap_w, bool is_left_edge);
    // matrix: full matrix returned by AI
    // overlap_w: width of the overlapping strip


    // slices the horizontal overlapping region between 2 tiles
    // use span as rows are contiguous so save time
    static std::span<const float> extractHorizontalOverlap(
        const std::vector<float>& matrix, int tile_w, int tile_h, int overlap_h, bool is_top_edge);
    // matrix: full matrix returned by AI
    // overlap_h: height of the overlapping strip


    // to calculate the variance of the tiles
    static float calculateTileVariance(const std::vector<float>& matrix);
    // matrix: 518*518 matrix to scan for variance
};