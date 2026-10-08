#include <chrono>
#include "NdsmTileDispatcher.h"
#include "InferenceProtocol/NdsmInferenceClient.h"
#include <future>
#include <trantor/utils/Logger.h>
#include <atomic>

NdsmTiledPayload NdsmTileDispatcher::dispatchBatch(
    int globalWidth, 
    int globalHeight,
    const std::vector<std::shared_ptr<TileRequest>>& tiles,
    const NdsmInferenceConfig& config)
{
    NdsmTiledPayload payload;
    payload.globalWidth = globalWidth;
    payload.globalHeight = globalHeight;
    payload.model.modelName = config.model.expectedModelName;
    payload.model.modelVersion = "1.0"; // Acquired dynamically in a fully scaled version

    std::vector<NdsmWorkerEndpoint> activeEndpoints;
    for (const auto& ep : config.endpoints) 
    {
        if (ep.enabled) activeEndpoints.push_back(ep);
    }

    if (activeEndpoints.empty() || tiles.empty()) 
    {
        LOG_ERROR << "NdsmTileDispatcher: No active endpoints or empty tile batch.";
        return payload;
    }

    std::atomic<int> successfulTiles{0};
    std::atomic<int> failedTiles{0};
    std::atomic<int> retriedTiles{0};

    struct PendingTask 
    {
        uint32_t tileId;
        std::future<NdsmTileResult> future;
    };
    
    std::vector<PendingTask> inFlight;
    std::vector<NdsmTileResult> results;
    results.reserve(tiles.size());

    int endpointIndex = 0;

    for (const auto& req : tiles) 
    {
        // Round-robin endpoint selection
        NdsmWorkerEndpoint targetEp = activeEndpoints[endpointIndex % activeEndpoints.size()];
        endpointIndex++;

        // Async dispatch with inline retry mechanism
        auto futureTask = std::async(std::launch::async, [req, targetEp, config, &successfulTiles, &failedTiles, &retriedTiles]() -> NdsmTileResult 
        {
            int attempts = 0;
            while (attempts < config.network.maxRetries) 
            {
                try 
                {
                    const auto started = std::chrono::steady_clock::now();
                    NdsmTileResult res = NdsmInferenceClient::infer(req, targetEp, config);
                    LOG_INFO << "NdsmTileDispatcher: tile " << req->tileId << " took "
                             << std::chrono::duration<double>(std::chrono::steady_clock::now() - started).count()
                             << " s (attempt " << (attempts + 1) << ")";
                    successfulTiles++;
                    return res;
                } 
                catch (const std::exception& e) 
                {
                    attempts++;
                    retriedTiles++;
                    LOG_WARN << "NdsmTileDispatcher: Tile " << req->tileId << " failed attempt " << attempts << ". Reason: " << e.what();
                    
                    if (attempts >= config.network.maxRetries) 
                    {
                        LOG_ERROR << "NdsmTileDispatcher: Tile " << req->tileId << " exhausted all retries.";
                        failedTiles++;
                        
                        // Return an explicitly broken result to trigger branch failure
                        NdsmTileResult failedRes;
                        failedRes.tileId = req->tileId;
                        failedRes.metricNdsm.width = 0; // 0 width flags failure
                        return failedRes;
                    }
                }
            }
            return NdsmTileResult{}; // Unreachable safety fallback
        });

        inFlight.push_back({req->tileId, std::move(futureTask)});

        // Strict Bounded Concurrency: Throttle if we hit the limit
        if (inFlight.size() >= static_cast<size_t>(config.network.maxConcurrentRequests)) 
        {
            NdsmTileResult res = inFlight.front().future.get();
            if (res.metricNdsm.width > 0) results.push_back(std::move(res));
            inFlight.erase(inFlight.begin());
        }
    }

    // Drain the remaining pipeline
    for (auto& task : inFlight) 
    {
        NdsmTileResult res = task.future.get();
        if (res.metricNdsm.width > 0) results.push_back(std::move(res));
    }

    payload.tiles = std::move(results);
    payload.successfulTileCount = successfulTiles.load();
    payload.failedTileCount = failedTiles.load();
    payload.retriedTileCount = retriedTiles.load();

    return payload;
}