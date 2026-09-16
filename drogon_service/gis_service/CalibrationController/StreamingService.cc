#include "StreamingService.h"
#include "../QuadTreeBuilder/QuadTreeBuilder.h"
#include "../StreamingGLB/GlbFactory.h"
#include "../StreamingGLB/OgcIndexer.h"
#include <iostream>
#include <stdexcept>

drogon::Task<std::string> StreamingService::generateAndStreamTileset(const StreamingContext& ctx)
{
     try 
     {
         std::cout << "[StreamingService] Starting 3D Tiles generation pipeline..." << std::endl;

         //compute Heuristics (Level of Detail variance thresholds)
         int max_level;
         float error_threshold;
         QuadTreeBuilder::computeHeuristics(
             ctx.absoluteDsm, ctx.masterWidth, ctx.masterHeight, max_level, error_threshold
         );

         //Build the Compressed Sparse Row (CSR) QuadTree
         QuadTreeGraph graph = QuadTreeBuilder::buildTree(
             ctx.absoluteDsm, ctx.masterWidth, ctx.masterHeight, max_level, error_threshold
         ) ;
         std::cout << "[StreamingService] CSR Graph built. Total Nodes: " << graph.nodes.size() << std::endl;

         //Multithreaded Meshing & Uploading
         //This fires the OpenMP BFS loop, populating node.glb_url and node.volume heights
         GlbFactory::generateAndUploadAll(
             graph, ctx.absoluteDsm, ctx.rawJpegBytes, ctx.masterWidth, ctx.masterHeight
         );
         std::cout << "[StreamingService] All .glb tiles generated and uploaded." << std::endl;

         // GDAL Projection & JSON Construction
         // Applies WGS84 coordinate math, runs DFS, and uploads tileset.json
         std::string tilesetUrl = OgcIndexer::buildAndUploadTileset(graph, ctx.meta);
         std::cout << "[StreamingService] tileset.json index successfully uploaded." << std::endl;

         // Return the final link to Drogon
         co_return tilesetUrl;
    } 
    catch (const std::exception& e) 
    {
        std::cerr << "[StreamingService] FATAL ERROR: " << e.what() << std::endl;
        throw; // Re-throw to be caught and handled by the Drogon HTTP controller
    }
}