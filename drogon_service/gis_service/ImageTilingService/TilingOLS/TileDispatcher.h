#pragma once
#include <string>
#include <vector>
#include <memory>  // smart pointers (std::shared_ptr)
#include <span>    // span: a lightweight zero copy tool
#include <future>  // tools for multithreading (std::async, std::future)
#include <atomic>  // ADDED: for graceful shutdown flag
#include <drogon/drogon.h> // access to C++20 async coroutines
#include "../utils/TilingTypes.h"
#include "OlsAlignment.h"

class TileDispatcher
{
public:
    // main orchestrator function
    // this pauses - co-waits and hands over the final data package
    static drogon::Task<GraphPayload> processGeoTiff(const std::string& filepath);

    // the network bridge to Modal
    // sends bytes to clouds and waits for rDSM matrix to come back
    // UPDATED: added stop_flag for graceful cancellation
    static std::shared_ptr<std::vector<float>> streamToLightningAI(
        std::span<const uint8_t> raw_tile_binary, 
        const std::string& target_gpu_ip, 
        uint32_t tile_id,
        const std::atomic<bool>& stop_flag // ADDED
    );

    // slices the vertical overlapping region between 2 tiles
    static std::vector<float> extractVerticalOverlap(
        const std::vector<float>& matrix, int tile_w, int tile_h, int overlap_w, bool is_left_edge);

    // slices the horizontal overlapping region between 2 tiles
    static std::span<const float> extractHorizontalOverlap(
        const std::vector<float>& matrix, int tile_w, int tile_h, int overlap_h, bool is_top_edge);

    // to calculate the variance of the tiles
    static float calculateTileVariance(const std::vector<float>& matrix);
};