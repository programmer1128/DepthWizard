#include "TilingService.h"
#include "TilingOLS/TileDispatcher.h"
#include "GraphOrdering/kruskal.h"
#include "GraphOrdering/GlobalScaling.h"
#include "HannAssembler/HannAssembler.h"
#include <stdexcept>

drogon::Task<std::vector<float>> TilingService::generateStitchedDepth(
     const std::string& vsi_path, 
     int globalWidth, 
     int globalHeight) 
{
     //Dispatch tiles and wait for the AI inference payload
     std::string local_gpu_ip = "http://127.0.0.1:8000";
     LOG_INFO << "[Trace] Starting processGeoTiff...";
     GraphPayload payload = co_await TileDispatcher::processGeoTiff(vsi_path);
    
     if (payload.all_tiles.empty()) 
     {
         throw std::runtime_error("Tiling extraction failed or returned 0 tiles");
     }

     //Build the Minimum Spanning Tree (MST) using Kruskal
     LOG_INFO << "[Trace] Building MST via Kruskal with " << payload.graph_edges.size() << " edges...";
     Kruskal kruskal;
     MST_TileGraph mst = kruskal.findMST_Kruskal(payload.graph_edges, payload.max_tile_id);

     //Resolve the Global Scale (s) & Shift (t) using Breadth-First Search
     GlobalScaler scaler;
     std::vector<GlobalTransformations> transforms = scaler.findGlobalTransformation(
         mst, payload.max_tile_id, payload.root_anchor_id);

     //Initialize the Hann Assembler with the absolute bounds of the target matrix[cite: 3]
     HannAssembler assembler(globalWidth, globalHeight);
    
     // Convert TileMetadata into the TileWindow struct required by the Assembler[cite: 3]
     LOG_INFO << "[Trace] Initializing Hann Assembler...";
     std::vector<TileWindow> blueprints;
     blueprints.reserve(payload.all_tiles.size());
    
     for (const auto& tile : payload.all_tiles) 
     {
         blueprints.push_back({
             .id = static_cast<int>(tile.tile_id),
             .x_off = tile.x_offset,
             .y_off = tile.y_offset,
             .x_size = tile.width,
             .y_size = tile.height
         });
     }
     assembler.loadTileBlueprints(blueprints);

     //Execute the Halide JIT pipeline to process and accumulate each tile[cite: 3]
     LOG_INFO << "[Trace] Processing and Accumulating " << payload.all_tiles.size() << " tiles...";
     for (size_t i = 0; i < payload.all_tiles.size(); ++i) 
     {
         assembler.processAndAccumulateTile(
             blueprints[i], 
             *payload.all_tiles[i].depth_matrix, // Dereferencing the shared_ptr[cite: 3]
             transforms[payload.all_tiles[i].tile_id]
         );
     }

     //Divide accumulated depths by weights and return the final matrix[cite: 3]
     LOG_INFO << "[Trace] Finalizing Matrix...";
     co_return assembler.finalizeMatrix();
}