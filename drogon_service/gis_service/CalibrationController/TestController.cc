#include "TestController.h"
#include "../TilingOLS/TileDispatcher.h" 

#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>

drogon::Task<drogon::HttpResponsePtr> TestController::runTest(drogon::HttpRequestPtr req)
{
    // Extract the file path from the URL parameters
    std::string filepath = req->getParameter("file");
    
    if (filepath.empty()) 
    {
        auto resp = drogon::HttpResponse::newHttpResponse();
        resp->setStatusCode(drogon::k400BadRequest);
        resp->setBody("Error: Please provide the '?file=' parameter with the absolute path to your GeoTIFF.");
        co_return resp;
    }

    Json::Value response_json;

    // Start timer
    auto start_time = std::chrono::high_resolution_clock::now();

    try 
    {
        // Distributed Zero-Copy Pipeline
        GraphPayload payload = co_await TileDispatcher::processGeoTiff(filepath);

        // Stop Timer & Calculate Latency
        auto end_time = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> elapsed_ms = end_time - start_time;
        double total_ms = elapsed_ms.count();

        size_t total_tiles = payload.all_tiles.size();
        size_t total_edges = payload.graph_edges.size();

        std::cout << ">> [SUCCESS] Processed " << total_tiles << " tiles & " << total_edges 
                  << " edges from " << filepath << " | Total Latency: " 
                  << std::fixed << std::setprecision(2) << total_ms << " ms | Root Anchor ID: " 
                  << payload.root_anchor_id << "\n";

        // Write Data to File
        std::string report_path = "pipeline_test_report.txt";
        std::ofstream out(report_path, std::ios::trunc);

        if (out.is_open()) 
        {
            out << "=== DISTRIBUTED PIPELINE AUDIT REPORT ===\n";
            out << "Input File     : " << filepath << "\n";
            out << "Total Latency  : " << total_ms << " ms\n";
            out << "Total Tiles    : " << total_tiles << "\n";
            out << "Root Anchor ID : " << payload.root_anchor_id << "\n";
            out << "Max Tile ID    : " << payload.max_tile_id << "\n\n";
            
            out << "--- TILE METADATA ---\n";
            for (const auto& tile : payload.all_tiles) {
                out << "ID: " << std::setw(4) << tile.tile_id 
                    << " | X: " << std::setw(5) << tile.x_offset 
                    << " | Y: " << std::setw(5) << tile.y_offset 
                    << " | Variance: " << std::fixed << std::setprecision(5) << tile.variance << "\n";
            }

            out << "\n--- OLS GRAPH EDGES ---\n";
            for (const auto& edge : payload.graph_edges) {
                out << "Src: " << std::setw(4) << edge.source_tile_id
                    << " -> Tgt: " << std::setw(4) << edge.target_tile_id 
                    << " | Scale: " << std::fixed << std::setprecision(5) << edge.local_scale 
                    << " | Shift: " << std::fixed << std::setprecision(5) << edge.local_shift 
                    << " | Penalty (1-r): " << std::fixed << std::setprecision(5) << edge.penalty_weight << "\n";
            }
            out.close();
        }

        // Return clean JSON to the client (Browser/Postman/Curl)
        response_json["status"] = "success";
        response_json["filepath"] = filepath;
        response_json["total_tiles"] = static_cast<Json::UInt64>(total_tiles);
        response_json["total_edges"] = static_cast<Json::UInt64>(total_edges);
        response_json["latency_ms"] = total_ms;
        response_json["root_anchor_id"] = payload.root_anchor_id;
        response_json["report_file"] = report_path;

        auto resp = drogon::HttpResponse::newHttpJsonResponse(response_json);
        co_return resp;
    }
    catch (const std::exception& e) 
    {
        std::cerr << ">> [CRITICAL FAILURE] " << e.what() << "\n";

        response_json["status"] = "error";
        response_json["error_message"] = e.what();

        auto resp = drogon::HttpResponse::newHttpJsonResponse(response_json);
        resp->setStatusCode(drogon::k500InternalServerError);
        co_return resp;
    }
}