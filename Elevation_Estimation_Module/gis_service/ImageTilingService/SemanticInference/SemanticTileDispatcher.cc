#include <chrono>
#include "SemanticTileDispatcher.h"
#include "SemanticInferenceClient.h"
#include <algorithm>
#include <stdexcept>
#include <trantor/utils/Logger.h>

static bool isTransientError(const std::string& msg)
{
    // Permanent errors must fail immediately without retries
    if (msg.find("Protocol version mismatch") != std::string::npos ||
        msg.find("Class count mismatch") != std::string::npos ||
        msg.find("Shape mismatch") != std::string::npos ||
        msg.find("non-binary values") != std::string::npos ||
        msg.find("Magic number") != std::string::npos)
    {
        return false;
    }
    return true;
}

static SemanticTileResult inferWithRetry(
    std::shared_ptr<TileRequest> request,
    const std::vector<SemanticWorkerEndpoint>& enabledEndpoints,
    const SemanticInferenceConfig& config)
{
    std::string lastError;

    for (int attempt = 0; attempt <= config.maxRetries; ++attempt)
    {
        // Round-robin shift on retry across healthy worker endpoints
        const auto& endpoint = enabledEndpoints[(request->tileId + attempt) % enabledEndpoints.size()];

        try
        {
            const auto started = std::chrono::steady_clock::now();
            SemanticTileResult result = SemanticInferenceClient::inferTile(request, endpoint, config);
            LOG_INFO << "SemanticTileDispatcher: tile " << request->tileId << " took "
                     << std::chrono::duration<double>(std::chrono::steady_clock::now() - started).count()
                     << " s (attempt " << (attempt + 1) << ")";
            return result;
        }
        catch (const std::invalid_argument&)
        {
            throw; // Non-transient input error
        }
        catch (const std::runtime_error& err)
        {
            lastError = err.what();
            LOG_WARN << "SemanticTileDispatcher: Tile " << request->tileId
                     << " attempt " << (attempt + 1) << " failed: " << lastError;

            if (!isTransientError(lastError))
            {
                throw;
            }
        }
    }

    throw std::runtime_error("SemanticTileDispatcher: Tile " + std::to_string(request->tileId) +
                             " failed after " + std::to_string(config.maxRetries + 1) +
                             " attempts. Last error: " + lastError);
}

SemanticTiledPayload SemanticTileDispatcher::dispatch(
    int globalWidth,
    int globalHeight,
    const std::vector<std::shared_ptr<TileRequest>>& tiles,
    const SemanticInferenceConfig& config)
{
    config.validate();

    if (globalWidth <= 0 || globalHeight <= 0)
    {
        throw std::invalid_argument(
            "SemanticTileDispatcher: Global dimensions must be positive.");
    }

    if (tiles.empty())
    {
        throw std::invalid_argument(
            "SemanticTileDispatcher: Shared tile batch is empty.");
    }

    std::vector<SemanticWorkerEndpoint> enabledEndpoints;
    for (const auto& ep : config.endpoints)
    {
        if (ep.enabled)
        {
            enabledEndpoints.push_back(ep);
        }
    }

    if (enabledEndpoints.empty())
    {
        throw std::runtime_error("SemanticTileDispatcher: No enabled endpoints available.");
    }

    SemanticTiledPayload payload;
    payload.globalWidth = static_cast<uint32_t>(globalWidth);
    payload.globalHeight = static_cast<uint32_t>(globalHeight);
    payload.model.modelName = config.expectedModelName;
    payload.model.modelVersion = config.acceptedVersions.empty() ? "1.0" : config.acceptedVersions.front();

    struct PendingTask
    {
        uint32_t tileId;
        std::future<SemanticTileResult> futureResult;
    };

    std::vector<PendingTask> inFlight;
    const size_t maxInFlight = static_cast<size_t>(config.maxConcurrentRequests);

    for (const auto& request : tiles)
    {
        if (!request)
        {
            throw std::invalid_argument(
                "SemanticTileDispatcher: Shared tile batch contains a null tile.");
        }

        std::future<SemanticTileResult> futureResult = std::async(
            std::launch::async,
            [request, enabledEndpoints, &config]() {
                return inferWithRetry(request, enabledEndpoints, config);
            });

        inFlight.push_back({request->tileId, std::move(futureResult)});

        // Bounded concurrency: collect the oldest request before submitting
        // more work than the configured worker pool can sustain.
        if (inFlight.size() >= maxInFlight)
        {
            payload.tiles.push_back(inFlight.front().futureResult.get());
            inFlight.erase(inFlight.begin());
        }
    }

    // Drain remaining in-flight tasks
    for (auto& pending : inFlight)
    {
        payload.tiles.push_back(pending.futureResult.get());
    }

    payload.successfulTileCount = static_cast<uint32_t>(payload.tiles.size());

    // Sort tiles deterministically by tileId so output does not depend on completion timing
    std::sort(payload.tiles.begin(), payload.tiles.end(),
              [](const SemanticTileResult& a, const SemanticTileResult& b) {
                  return a.tileId < b.tileId;
              });

    LOG_INFO << "SemanticTileDispatcher: Finished dispatching "
             << payload.successfulTileCount << " semantic tiles.";

    return payload;
}
