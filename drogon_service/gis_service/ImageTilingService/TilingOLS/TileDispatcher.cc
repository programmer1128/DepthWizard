#include "TileDispatcher.h"
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>
#include <numeric>
#include <sys/stat.h>
#include <gdal_priv.h>
#include <cpl_conv.h>
#include <iostream>

drogon::Task<GraphPayload> TileDispatcher::processGeoTiff(const std::string& filepath)
{
    // --- GRACEFUL SHUTDOWN TOKEN ---
    auto stop_flag = std::make_shared<std::atomic<bool>>(false);

    std::cout << ">> [DEBUG] processGeoTiff ENTERED with file: " << filepath << std::endl; // ADD
    
    // Note: In a real app, you'd hook this to a signal handler or API endpoint.
    // For now, if the coroutine is destroyed (e.g. client disconnects/server stop),
    // we rely on the try-catch below to handle the fallout.

    GDALAllRegister();
    GDALDataset* poDataset = (GDALDataset*) GDALOpen(filepath.c_str(), GA_ReadOnly);
    if (!poDataset) throw std::runtime_error("GDAL Error: Failed to open GeoTIFF.");

    int image_width = poDataset->GetRasterXSize();
    int image_height = poDataset->GetRasterYSize();
    int raster_bands = poDataset->GetRasterCount();

    GraphPayload final_payload;
    float absolute_max_variance = -1.0f;
    uint32_t current_tile_id = 0;

    std::vector<std::string> available_gpus = { 
        "https://satadru-ghosh-cse28--depth-wizard-inference-depthinferen-f5d179.modal.run"
    };

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

    // --- PHASE 1: TILING & DISPATCH ---
    try {
        for (int y = 0; y < image_height; y += stride)
        {
            // Check for shutdown between rows
            if (stop_flag->load()) break;

            int actual_y = std::max(0, std::min(y, image_height - tile_size));
            int valid_h = std::min(tile_size, image_height - actual_y);

            for (int x = 0; x < image_width; x += stride)
            {
                if (stop_flag->load()) break;

                int actual_x = std::max(0, std::min(x, image_width - tile_size));
                int valid_w = std::min(tile_size, image_width - actual_x);
                if (actual_y == 0) tiles_per_row++;

                size_t tile_byte_size = tile_size * tile_size * 3;
                auto contiguous_tile = std::make_shared<std::vector<uint8_t>>(tile_byte_size, 0);

                for (int b = 1; b <= 3; ++b) {
                    int srcB = (b <= raster_bands) ? b : 1;
                    GDALRasterBand* band = poDataset->GetRasterBand(srcB);
                    band->RasterIO(GF_Read, actual_x, actual_y, valid_w, valid_h,
                                   contiguous_tile->data() + (b - 1), valid_w, valid_h,
                                   GDT_Byte, 3, tile_size * 3, nullptr);
                }

                std::string target_gpu = available_gpus[current_tile_id % available_gpus.size()];

                // Capture stop_flag by value (shared_ptr copy)
                std::future<std::shared_ptr<std::vector<float>>> future_matrix = 
                    std::async(std::launch::async, [contiguous_tile, target_gpu, current_tile_id, stop_flag]() {
                        std::span<const uint8_t> tile_view(contiguous_tile->data(), contiguous_tile->size());
                        return streamToLightningAI(tile_view, target_gpu, current_tile_id, *stop_flag);
                    });
                
                network_pipeline.push_back({current_tile_id, actual_x, actual_y, std::move(future_matrix)});

                // Stagger logic (kept from your version)
                if (current_tile_id == 0) {
                    std::cout << ">> [STAGGER] Tile 0 dispatched. Pausing 2.5s...\n";
                    std::this_thread::sleep_for(std::chrono::milliseconds(2500));
                } else {
                    std::this_thread::sleep_for(std::chrono::milliseconds(200));
                }

                int max_in_flight = available_gpus.size() * 4;
                if (network_pipeline.size() > max_in_flight) {
                    // Wait for oldest, but check stop flag first
                    if(!stop_flag->load()) {
                        network_pipeline[network_pipeline.size() - max_in_flight - 1].network_task.wait();
                    }
                }
                current_tile_id++;
                if (actual_x >= image_width - tile_size) break;
            }
            if (actual_y >= image_height - tile_size) break;
        }
    } catch (...) {
        std::cerr << ">> [CRITICAL] Exception during tiling dispatch.\n";
        stop_flag->store(true); // Signal all threads to stop
    }

    // --- PHASE 2: ASSEMBLY (Wrapped in Try-Catch for Safety) ---
    try {
        for (auto& pending : network_pipeline) 
        {
            // .get() will throw if the async task threw (e.g. cancelled)
            std::shared_ptr<std::vector<float>> depth_matrix = pending.network_task.get();
            
            float variance = calculateTileVariance(*depth_matrix);
            TileMetadata meta{pending.id, tile_size, tile_size, pending.x, pending.y, variance, depth_matrix};

            if(variance > absolute_max_variance) {
                absolute_max_variance = variance;
                final_payload.root_anchor_id = pending.id;
            }
            final_payload.all_tiles.push_back(meta);

            if (pending.x > 0) {
                const auto& left_tile = final_payload.all_tiles[final_payload.all_tiles.size() - 2];
                int dynamic_overlap_w = tile_size - (pending.x - left_tile.x_offset);
                std::vector<float> source_overlap = extractVerticalOverlap(*left_tile.depth_matrix, tile_size, tile_size, dynamic_overlap_w, false);
                std::vector<float> target_overlap = extractVerticalOverlap(*depth_matrix, tile_size, tile_size, dynamic_overlap_w, true);
                uint32_t target_id = pending.id;
                uint32_t source_id = left_tile.tile_id;
                async_ols_tasks.push_back(std::async(std::launch::async, [=]() {
                    return OlsAlignment::computeAlignment(source_id, target_id, source_overlap, target_overlap);
                }));
            }

            if (pending.y > 0) {
                int top_tile_index = pending.id - tiles_per_row;
                const auto& top_tile = final_payload.all_tiles[top_tile_index];
                int dynamic_overlap_h = tile_size - (pending.y - top_tile.y_offset);
                std::span<const float> source_overlap = extractHorizontalOverlap(*top_tile.depth_matrix, tile_size, tile_size, dynamic_overlap_h, false);
                std::span<const float> target_overlap = extractHorizontalOverlap(*depth_matrix, tile_size, tile_size, dynamic_overlap_h, true);
                uint32_t target_id = pending.id;
                uint32_t source_id = top_tile.tile_id;
                async_ols_tasks.push_back(std::async(std::launch::async, [=]() {
                    return OlsAlignment::computeAlignment(source_id, target_id, source_overlap, target_overlap);
                }));
            }
        }

        for (auto& task : async_ols_tasks) {
            final_payload.graph_edges.push_back(task.get());
        }
        final_payload.max_tile_id = current_tile_id - 1;

    } catch (const std::exception& e) {
        std::cerr << ">> [PIPELINE ABORTED] " << e.what() << "\n";
        std::cerr << ">> [CLEANUP] Cancelling remaining tasks and closing GDAL.\n";
        stop_flag->store(true); // Ensure any lingering threads know to stop
        
        // We don't re-throw here because we want to ensure GDALClose runs.
        // Depending on your API design, you might want to return an empty payload 
        // or throw a specific "Cancelled" error to the frontend.
    }

    // Always close GDAL
    GDALClose(poDataset); 
    
    // If we aborted, final_payload might be partial. 
    // Ideally, check a flag here and throw if incomplete.
    if (stop_flag->load()) {
        throw std::runtime_error("Processing cancelled by user.");
    }

    co_return final_payload;
}

// ... (Helper functions extractVerticalOverlap, extractHorizontalOverlap, calculateTileVariance remain exactly as they were in your file) ...

std::vector<float> TileDispatcher::extractVerticalOverlap(
    const std::vector<float>& matrix, int tile_w, int tile_h, int overlap_w, bool is_left_edge) 
{
    std::vector<float> overlap(overlap_w * tile_h);
    int start_col = is_left_edge ? 0 : (tile_w - overlap_w);
    for (int r = 0; r < tile_h; ++r) {
        std::memcpy(&overlap[r * overlap_w], &matrix[r * tile_w + start_col], overlap_w * sizeof(float));
    }
    return overlap;
}

std::span<const float> TileDispatcher::extractHorizontalOverlap(
    const std::vector<float>& matrix, int tile_w, int tile_h, int overlap_h, bool is_top_edge)
{
    int start_row = is_top_edge ? 0 : (tile_h - overlap_h);
    return std::span<const float>(matrix.data() + (start_row * tile_w), overlap_h * tile_w);
}

float TileDispatcher::calculateTileVariance(const std::vector<float>& matrix) 
{
    float sum = std::accumulate(matrix.begin(), matrix.end(), 0.0f);
    float mean = sum / matrix.size();
    float variance = 0.0f;
    for (float val : matrix) 
        variance += (val - mean) * (val - mean);
    return variance / matrix.size();
}