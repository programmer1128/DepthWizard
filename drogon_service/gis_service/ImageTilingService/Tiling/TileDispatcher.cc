 // handles memory slicing and multi-threaded network dispatching

#include "TileDispatcher.h"
#include "../InferenceProtocol/InferenceClient.h"
#include <algorithm>
#include <cstring>
#include <iostream>
#include <stdexcept>

drogon::Task<TiledInferencePayload> TileDispatcher::processMetricRaster(
    const SceneInput& scene, 
    const ImageQualityResult& quality)
{
    TiledInferencePayload final_payload;
    final_payload.globalWidth = scene.width;
    final_payload.globalHeight = scene.height;

    // GPU integration logic
    // we will add all GPUs here
    std::vector<std::string> available_gpus = {
        "127.0.0.1"
    };

    const int tile_size = 518;
    const int stride = 414;  // 20% overlap for Hann Window Blending
    const auto requests = buildTileRequests(scene, quality, tile_size, stride);



    // structure to hold background network threads
    struct PendingTile 
    {
        uint32_t id;
        std::future<TileInferenceResult> network_task;
    };
    std::vector<PendingTile> network_pipeline;



    // we restrict how many tiles are there over the internet to avoid crashing the VPN/Router
    const size_t max_in_flight = available_gpus.size() * 4;

    for (const auto& request : requests)
    {
        // we pick the next GPU using Round-Robin (0, 1, 2, 0, 1, 2...)
        std::string target_gpu = available_gpus[request->tileId % available_gpus.size()];

            // we launch a background CPU thread to talk to the GPU
            std::future<TileInferenceResult> future_result = std::async(
                std::launch::async, 
                [request, target_gpu]() {
                    return InferenceClient::inferMetricTile(request, target_gpu);
                }
            );
            
            // put the thread into our tracking pipeline
            network_pipeline.push_back({request->tileId, std::move(future_result)});

            // throttle control
            // if we have too many tiles over the internet, pause and wait for the oldest one to finish
            if (network_pipeline.size() > max_in_flight) 
            {
                network_pipeline[network_pipeline.size() - max_in_flight - 1].network_task.wait();
            }

    }
            
    // collection phase
    // wait for all remaining background threads to finish and collect their AI results
    for (auto& pending : network_pipeline)
    {
        // .get() pauses the main program until this specific GPU returns the data
        TileInferenceResult ai_result = pending.network_task.get();
        final_payload.allTiles.push_back(std::move(ai_result));
    }

    // return the complete list of processed tiles back to the service
    co_return final_payload;
}

std::vector<std::shared_ptr<TileRequest>> TileDispatcher::buildTileRequests(
    const SceneInput& scene,
    const ImageQualityResult& quality,
    int tileSize,
    int stride)
{
    if (scene.width <= 0 || scene.height <= 0)
        throw std::invalid_argument("TileDispatcher: Scene dimensions must be positive.");

    if (tileSize <= 0 || stride <= 0 || stride > tileSize)
        throw std::invalid_argument("TileDispatcher: Invalid tile size or stride.");

    const size_t scenePixels =
        static_cast<size_t>(scene.width) * static_cast<size_t>(scene.height);
    if (quality.normalizedRgbTensor.width != scene.width ||
        quality.normalizedRgbTensor.height != scene.height ||
        quality.normalizedRgbTensor.channels != 3 ||
        quality.normalizedRgbTensor.layout != TensorLayout::CHW ||
        quality.normalizedRgbTensor.data.size() != scenePixels * 3 ||
        quality.validPixelMask.width != scene.width ||
        quality.validPixelMask.height != scene.height ||
        quality.validPixelMask.data.size() != scenePixels)
    {
        throw std::invalid_argument(
            "TileDispatcher: Preprocessed image and mask do not match the scene.");
    }

    std::vector<std::shared_ptr<TileRequest>> requests;
    uint32_t tileId = 0;

    for (int y = 0; y < scene.height; y += stride)
    {
        const int actualY = std::max(0, std::min(y, scene.height - tileSize));
        const int validHeight = std::min(tileSize, scene.height - actualY);

        for (int x = 0; x < scene.width; x += stride)
        {
            const int actualX = std::max(0, std::min(x, scene.width - tileSize));
            const int validWidth = std::min(tileSize, scene.width - actualX);

            requests.push_back(extractTileMemory(
                actualX,
                actualY,
                validWidth,
                validHeight,
                tileSize,
                tileId++,
                scene,
                quality));

            if (actualX >= scene.width - tileSize)
                break;
        }

        if (actualY >= scene.height - tileSize)
            break;
    }

    if (requests.empty())
        throw std::runtime_error("TileDispatcher: Failed to construct any tiles.");

    return requests;
}


// optimized memory slicer that safely extracts a 518x518 window 
// out of a massive Planar CHW (Channel-Height-Width) ImageTensor
std::shared_ptr<TileRequest> TileDispatcher::extractTileMemory(
    int start_x, int start_y, int valid_w, int valid_h, int tile_size, uint32_t tile_id,
    const SceneInput& scene, const ImageQualityResult& quality)
{
    // create the package on the heap (RAM) using a smart pointer
    auto request = std::make_shared<TileRequest>();
    request->tileId = tile_id;
    request->xOffset = start_x;
    request->yOffset = start_y;
    request->width = tile_size;
    request->height = tile_size;
    request->validWidth = valid_w;
    request->validHeight = valid_h;

    // pre-fill with empty values (black pixels, invalid mask) for edge padding
    request->normalizedRgbBytes.resize(tile_size * tile_size * 3, 0.0f);
    request->validMaskBytes.resize(tile_size * tile_size, 0);

    float* dest_rgb = request->normalizedRgbBytes.data();
    uint8_t* dest_mask = request->validMaskBytes.data();
    
    // access the new ImageTensor struct
    const float* src_rgb = quality.normalizedRgbTensor.data.data();
    const uint8_t* src_mask = quality.validPixelMask.data.data();

    // cache the total pixel area for layer hopping
    size_t global_channel_area = static_cast<size_t>(scene.width) * scene.height;
    size_t tile_channel_area = static_cast<size_t>(tile_size) * tile_size;

    // CHW Tensor Copying (Process Red, then Green, then Blue separately)
    for (int c = 0; c < 3; ++c) 
    {
        for (int r = 0; r < valid_h; ++r) 
        {
            // calculate exact memory addresses jumping across the planar layers
            size_t global_index = (c * global_channel_area) + ((start_y + r) * scene.width) + start_x;
            size_t tile_index = (c * tile_channel_area) + (r * tile_size);

            // copy exactly one row of one color channel at a time
            std::memcpy(&dest_rgb[tile_index], &src_rgb[global_index], valid_w * sizeof(float));
        }
    }

    // Boolean Mask Copying (Only 1 channel, so simple row-by-row works)
    for (int r = 0; r < valid_h; ++r) 
    {
        size_t global_index = ((start_y + r) * scene.width) + start_x;
        size_t tile_index = r * tile_size;
        
        std::memcpy(&dest_mask[tile_index], &src_mask[global_index], valid_w * sizeof(uint8_t));
    }

    return request;
}
