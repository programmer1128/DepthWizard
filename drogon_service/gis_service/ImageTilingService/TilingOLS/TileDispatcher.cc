#include "TileDispatcher.h"

#include <sys/mman.h>     // memory mapping - mmap
#include <fcntl.h>     // file control options - O_RDONLY
#include <unistd.h>      
#include <cstring>      // memcpy
#include <numeric>        // std::accumulate
#include <sys/stat.h>    // to read exact file size dynamically

// GDAL libraries
#include <gdal_priv.h>     
#include <cpl_conv.h>


drogon::Task<GraphPayload> TileDispatcher::processGeoTiff(const std::string& filepath)
{
    GDALAllRegister();
    GDALDataset* poDataset = (GDALDataset*) GDALOpen(filepath.c_str(), GA_ReadOnly);

    if (!poDataset) {
        throw std::runtime_error("GDAL Error: Failed to open GeoTIFF file.");
    }

    int image_width = poDataset->GetRasterXSize(); 
    int image_height = poDataset->GetRasterYSize();
    int raster_bands = poDataset->GetRasterCount();

    GraphPayload final_payload;
    float absolute_max_variance = -1.0f;
    uint32_t current_tile_id = 0;

    std::vector<std::string> available_gpus = { "127.0.0.1" };
    int tile_size = 518;
    int stride = 414;   

    std::vector<std::future<OverlapEdge>> async_ols_tasks;
    int tiles_per_row = 0;

    struct PendingTile {
        uint32_t id;
        int x, y;
        std::future<std::shared_ptr<std::vector<float>>> network_task;
    };
    std::vector<PendingTile> network_pipeline;

    //Tiling Loop
    for (int y = 0; y < image_height; y += stride)
    {
        int actual_y = std::max(0, std::min(y, image_height - tile_size));
        int valid_h = std::min(tile_size, image_height - actual_y);

        for (int x = 0; x < image_width; x += stride)
        {
            int actual_x = std::max(0, std::min(x, image_width - tile_size));
            int valid_w = std::min(tile_size, image_width - actual_x);

            if (actual_y == 0) tiles_per_row++;

            size_t tile_byte_size = tile_size * tile_size * 3;
            auto contiguous_tile = std::make_shared<std::vector<uint8_t>>(tile_byte_size, 0);

            for (int b = 1; b <= 3; ++b) 
            {
                int srcB = (b <= raster_bands) ? b : 1; // Fallback for grayscale images
                GDALRasterBand* band = poDataset->GetRasterBand(srcB);
                
                // Read directly into the interleaved RGB buffer (Zero-Copy)
                band->RasterIO(GF_Read, actual_x, actual_y, valid_w, valid_h,
                               contiguous_tile->data() + (b - 1), // Offset: 0 for R, 1 for G, 2 for B
                               valid_w, valid_h,
                               GDT_Byte,
                               3,             // Pixel stride skip 3 bytes to the next R, G, or B
                               tile_size * 3, // Line stride jump to the next row of the 518 window
                               nullptr);
            }

            std::string target_gpu = available_gpus[current_tile_id % available_gpus.size()];

            std::future<std::shared_ptr<std::vector<float>>> future_matrix = 
                std::async(std::launch::async, [contiguous_tile, target_gpu, current_tile_id]() {
                    std::span<const uint8_t> tile_view(contiguous_tile->data(), contiguous_tile->size());
                    return streamToLightningAI(tile_view, target_gpu, current_tile_id);
                });
            
             network_pipeline.push_back({current_tile_id, actual_x, actual_y, std::move(future_matrix)});

             int max_in_flight = available_gpus.size() * 4;
             if (network_pipeline.size() > max_in_flight) 
             {
                 network_pipeline[network_pipeline.size() - max_in_flight - 1].network_task.wait();
             }

             current_tile_id++;
             if (actual_x >= image_width - tile_size) break;
         }
         if (actual_y >= image_height - tile_size) break;
     }
            
     //OLS Math & Assembly
     for (auto& pending : network_pipeline) 
     {
         std::shared_ptr<std::vector<float>> depth_matrix = pending.network_task.get();
         // metadata and maximum variance
            float variance = calculateTileVariance(*depth_matrix);
            TileMetadata meta{pending.id, tile_size, tile_size, pending.x, pending.y, variance, depth_matrix};

             if(variance > absolute_max_variance) 
             {
                 absolute_max_variance = variance;
                 final_payload.root_anchor_id = pending.id; // id with max variance
             }
             final_payload.all_tiles.push_back(meta);


             // async OLS math
             if (pending.x > 0)
             {
                 // find the tile just processed - to the left
                 const auto& left_tile = final_payload.all_tiles[final_payload.all_tiles.size() - 2];
 
                 // DYNAMIC OVERLAP: overlap can be larger than 104 pixels
                 // how many pixels they actually share 
                 int dynamic_overlap_w = tile_size - (pending.x - left_tile.x_offset);

                 // now slice the shared columns
                 std::vector<float> source_overlap = extractVerticalOverlap(*left_tile.depth_matrix, tile_size, tile_size, dynamic_overlap_w, false);
                 std::vector<float> target_overlap = extractVerticalOverlap(*depth_matrix, tile_size, tile_size, dynamic_overlap_w, true);
 
                 // extract primitive IDs so the lambda doesnt try to copy the structs
                 uint32_t target_id = pending.id;
                 uint32_t source_id = left_tile.tile_id;

                 // we throw the heavy SIMD maths onto a background core
                 async_ols_tasks.push_back(std::async(std::launch::async, [=]() {
                     return OlsAlignment::computeAlignment(source_id, target_id, source_overlap, target_overlap);
                 }));
             }

             if (pending.y > 0)
             {
                 // jump back by exactly one full row length to find the tile directly above us
                 int top_tile_index = pending.id - tiles_per_row;
                 const auto& top_tile = final_payload.all_tiles[top_tile_index];
 
                 // true vertical overlap distance
                 int dynamic_overlap_h = tile_size - (pending.y - top_tile.y_offset);
 
                 // slice the shared rows
                 std::span<const float> source_overlap = extractHorizontalOverlap(
                    *top_tile.depth_matrix, tile_size, tile_size, dynamic_overlap_h, false);
                 
                 std::span<const float> target_overlap = extractHorizontalOverlap(
                     *depth_matrix, tile_size, tile_size, dynamic_overlap_h, true);

                 // extract primitive IDs so the lambda doesnt try to copy the structs
                 uint32_t target_id = pending.id;
                 uint32_t source_id = top_tile.tile_id;

                 // throw SIMD math to another background core
                 async_ols_tasks.push_back(std::async(std::launch::async, [=]() {
                     return OlsAlignment::computeAlignment(source_id, target_id, source_overlap, target_overlap);
                 }));
             }
     }

     for (auto& task : async_ols_tasks)
     {
         final_payload.graph_edges.push_back(task.get());
     }

     final_payload.max_tile_id = current_tile_id - 1;

     // Close GDAL handle (Replaces munmap and close)
     GDALClose(poDataset); 

     co_return final_payload;
}


// main orchestrator
// implements the 2D sliding window with phase 1 / phase 2 decoupling
// drogon::Task<GraphPayload> TileDispatcher::processGeoTiff(const std::string& filepath)
// {
//     // first extract exact no. of pixels using GDAL
//     GDALAllRegister();

//     // open image in read only mode
//     GDALDataset* poDataset = (GDALDataset*) GDALOpen(filepath.c_str(), GA_ReadOnly);

//     // prevent null pointer dereference if file is missing/corrupted
//     if (!poDataset) 
//     {
//         throw std::runtime_error("GDAL Error: Failed to open GeoTIFF file.");
//     }

//     int image_width = poDataset->GetRasterXSize();  
//     int image_height = poDataset->GetRasterYSize();

//     GDALClose(poDataset);


//     // POSIX mmap ingestion
//     int fd = open(filepath.c_str(), O_RDONLY); // raw file descriptor

//     struct stat sb; // to hold the file details
//     fstat(fd, &sb); // kernel inspects fd and fills sb

//     size_t file_size = sb.st_size; // extract byte size of file dynamically


//     // now we map the file directly to RAM
//     // no copy, just pointer to the hard drive for low latency
//     uint8_t* mapped_data = (uint8_t*)mmap(nullptr, file_size, PROT_READ, MAP_SHARED, fd, 0);
//     madvise(mapped_data, file_size, MADV_WILLNEED); // optimization to start pre-loading data

//     GraphPayload final_payload;
//     float absolute_max_variance = -1.0f;
//     uint32_t current_tile_id = 0;


//     // GPU INTEGRATION LOGIC
//     // modulo operator implements round robin load balancing

//     std::vector<std::string> available_gpus = {
//         "127.0.0.1" 
//         // "tcp://lightning-ai-worker-2.cloud",
//         // "tcp://lightning-ai-worker-3.cloud",
//         // "tcp://lightning-ai-worker-4.cloud",
//         // "tcp://lightning-ai-worker-5.cloud",
//         // "tcp://lightning-ai-worker-6.cloud"
//     };

//     int tile_size = 518;
//     int stride = 414;  // 20% overlap

//     // hold background OLS math threads here so main loop doesnt block
//     std::vector<std::future<OverlapEdge>> async_ols_tasks; 

//     // we calculate dynamically
//     int tiles_per_row = 0;


//     // structure to hold parallel network jobs
//     struct PendingTile 
//     {
//         uint32_t id;
//         int x, y;
//         std::future<std::shared_ptr<std::vector<float>>> network_task;
//     };
//     std::vector<PendingTile> network_pipeline;

//     // PHASE 1 :-

//     // tiling loop - 2D sliding window
//     // window-shift boundary clamping: so tiles at extremes do not overflow and crash the prg

//     for (int y = 0; y < image_height; y += stride) // rows
//     {
//         // boundary fix: safely clamp to 0 if the entire image is smaller than the tile size
//         int actual_y = std::max(0, std::min(y, image_height - tile_size));
//         int valid_h = std::min(tile_size, image_height - actual_y);

//         for (int x = 0; x < image_width; x += stride) // columns
//         {
//             // same boundary fix, safely clamped
//             int actual_x = std::max(0, std::min(x, image_width - tile_size));
//             int valid_w = std::min(tile_size, image_width - actual_x);

//             // DYNAMIC ROW COUNT: Exactly tracks how many tiles fit in the first row
//             if (actual_y == 0) 
//             {
//                 tiles_per_row++;
//             }

//             // use std::make_shared and initialize with ', 0' to automatically pad missing pixels with black
//             size_t tile_byte_size = tile_size * tile_size * 3;
//             auto contiguous_tile = std::make_shared<std::vector<uint8_t>>(tile_byte_size, 0); 

//             // extract the 2D tile row-by-row, only copying the valid available pixels
//             for (int r = 0; r < valid_h; ++r) 
//             {
//                 size_t mmap_row_offset = ((actual_y + r) * image_width + actual_x) * 3;
//                 size_t tile_row_offset = r * tile_size * 3;

//                 // we do not copy if the offset exceeds the physical file size
//                 if (mmap_row_offset + (valid_w * 3) <= file_size) 
//                 {
//                     std::memcpy(contiguous_tile->data() + tile_row_offset, mapped_data + mmap_row_offset, valid_w * 3);
//                 }
//             }

//             // pick the next GPU in line using the Round-Robin 
//             std::string target_gpu = available_gpus[current_tile_id % available_gpus.size()];

//             // we use a lambda to capture the shared_ptr by value
//             // this guarantees the buffer stays alive until streamToLightningAI finishes
//             std::future<std::shared_ptr<std::vector<float>>> future_matrix = 
//                 std::async(std::launch::async, [contiguous_tile, target_gpu, current_tile_id]() {
//                     // create the span safely inside the background thread
//                     std::span<const uint8_t> tile_view(contiguous_tile->data(), contiguous_tile->size());
//                     return streamToLightningAI(tile_view, target_gpu, current_tile_id);
//                 });
            
//             network_pipeline.push_back({current_tile_id, actual_x, actual_y, std::move(future_matrix)});

//             // to prevent VPN DDoS by limiting concurrent flights to 4 per GPU

//             int max_in_flight = available_gpus.size() * 4; 
//             if (network_pipeline.size() > max_in_flight) {
//                 // Wait for the oldest active tile to finish before unleashing the next one
//                 network_pipeline[network_pipeline.size() - max_in_flight - 1].network_task.wait();
//             }

//             current_tile_id++;

//             // change == to >= to correctly trigger breaks on small images
//             if (actual_x >= image_width - tile_size) 
//                 break;
//         }

//         // change == to >= to correctly trigger breaks on small images
//         if (actual_y >= image_height - tile_size) 
//             break;
//     }
            
//     // PHASE 2:-
    
//     for (auto& pending : network_pipeline)
//     {
//             // this blocks only if this specific GPU hasnt returned the matrix yet
//             // while it waits, all other GPUs are actively calculating
//             std::shared_ptr<std::vector<float>> depth_matrix = pending.network_task.get();

            
//             // metadata and maximum variance
//             float variance = calculateTileVariance(*depth_matrix);
//             TileMetadata meta{pending.id, tile_size, tile_size, pending.x, pending.y, variance, depth_matrix};

//             if(variance > absolute_max_variance) 
//             {
//                 absolute_max_variance = variance;
//                 final_payload.root_anchor_id = pending.id; // id with max variance
//             }
//             final_payload.all_tiles.push_back(meta);


//             // async OLS math
//             if (pending.x > 0)
//             {
//                 // find the tile just processed - to the left
//                 const auto& left_tile = final_payload.all_tiles[final_payload.all_tiles.size() - 2];

//                 // DYNAMIC OVERLAP: overlap can be larger than 104 pixels
//                 // how many pixels they actually share 
//                 int dynamic_overlap_w = tile_size - (pending.x - left_tile.x_offset);

//                 // now slice the shared columns
//                 std::vector<float> source_overlap = extractVerticalOverlap(*left_tile.depth_matrix, tile_size, tile_size, dynamic_overlap_w, false);
//                 std::vector<float> target_overlap = extractVerticalOverlap(*depth_matrix, tile_size, tile_size, dynamic_overlap_w, true);

//                 // extract primitive IDs so the lambda doesnt try to copy the structs
//                 uint32_t target_id = pending.id;
//                 uint32_t source_id = left_tile.tile_id;

//                 // we throw the heavy SIMD maths onto a background core
//                 async_ols_tasks.push_back(std::async(std::launch::async, [=]() {
//                     return OlsAlignment::computeAlignment(source_id, target_id, source_overlap, target_overlap);
//                 }));
//             }

//             if (pending.y > 0)
//             {
//                 // jump back by exactly one full row length to find the tile directly above us
//                 int top_tile_index = pending.id - tiles_per_row;
//                 const auto& top_tile = final_payload.all_tiles[top_tile_index];

//                 // true vertical overlap distance
//                 int dynamic_overlap_h = tile_size - (pending.y - top_tile.y_offset);

//                 // slice the shared rows
//                 std::span<const float> source_overlap = extractHorizontalOverlap(
//                     *top_tile.depth_matrix, tile_size, tile_size, dynamic_overlap_h, false);
                
//                 std::span<const float> target_overlap = extractHorizontalOverlap(
//                     *depth_matrix, tile_size, tile_size, dynamic_overlap_h, true);

//                 // extract primitive IDs so the lambda doesnt try to copy the structs
//                 uint32_t target_id = pending.id;
//                 uint32_t source_id = top_tile.tile_id;

//                 // throw SIMD math to another background core
//                 async_ols_tasks.push_back(std::async(std::launch::async, [=]() {
//                     return OlsAlignment::computeAlignment(source_id, target_id, source_overlap, target_overlap);
//                 }));
//             }
//     }


//     // synchronization now
//     // wait for all the background CPU cores to finish their math & collect graph edges
//     for (auto& task : async_ols_tasks) 
//     {
//         final_payload.graph_edges.push_back(task.get());
//     }

//     final_payload.max_tile_id = current_tile_id - 1; // max id calculation

//     // clean up the memory map and close the file
//     munmap(mapped_data, file_size);
//     close(fd);

//     co_return final_payload;
// }

// extracts the left/right overlapping columns
std::vector<float> TileDispatcher::extractVerticalOverlap(
    const std::vector<float>& matrix, int tile_w, int tile_h, int overlap_w, bool is_left_edge) 
{
    std::vector<float> overlap(overlap_w * tile_h);
    int start_col = is_left_edge ? 0 : (tile_w - overlap_w);

    for (int r = 0; r < tile_h; ++r) 
    {
        // std::memcpy used as it is fastest here
        std::memcpy(&overlap[r * overlap_w], &matrix[r * tile_w + start_col], overlap_w * sizeof(float));
    }
    return overlap;
}

// extracts the overlapping top/bottom rows 
std::span<const float> TileDispatcher::extractHorizontalOverlap(
    const std::vector<float>& matrix, int tile_w, int tile_h, int overlap_h, bool is_top_edge)
{
    int start_row = is_top_edge ? 0 : (tile_h - overlap_h);
    
    // returns a lightweight window - std::span - pointing directly at the existing memory
    return std::span<const float>(matrix.data() + (start_row * tile_w), overlap_h * tile_w);
}

// calculate the variance for the tile
float TileDispatcher::calculateTileVariance(const std::vector<float>& matrix) 
{
    // std::accumulate sums up all values in the matrix
    float sum = std::accumulate(matrix.begin(), matrix.end(), 0.0f);
    float mean = sum / matrix.size();
    
    float variance = 0.0f;

    // calculate variance of each pixel from the mean
    for (float val : matrix) 
        variance += (val - mean) * (val - mean);
    
    return variance / matrix.size();
}