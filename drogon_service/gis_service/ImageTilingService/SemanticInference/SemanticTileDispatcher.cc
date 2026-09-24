#include "SemanticTileDispatcher.h"
#include "SemanticInferenceClient.h"
#include <cmath>
#include <algorithm>
#include <cstring>
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
            return SemanticInferenceClient::inferTile(request, endpoint, config);
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

drogon::Task<SemanticTiledPayload> SemanticTileDispatcher::dispatch(
    const SceneInput& scene,
    const ImageQualityResult& quality,
    const SemanticInferenceConfig& config)
{
    config.validate();

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
    payload.globalWidth = scene.width;
    payload.globalHeight = scene.height;
    payload.model.modelName = config.expectedModelName;
    payload.model.modelVersion = config.acceptedVersions.empty() ? "1.0" : config.acceptedVersions.front();

    const int tileSize = static_cast<int>(config.expectedTileSize);
    // 20% overlap stride for smooth Hann-window blending
    const int stride = std::max(1, static_cast<int>(std::round(tileSize * 0.8f)));

    struct PendingTask
    {
        uint32_t tileId;
        std::future<SemanticTileResult> futureResult;
    };

    std::vector<PendingTask> inFlight;
    uint32_t currentTileId = 0;
    const size_t maxInFlight = static_cast<size_t>(config.maxConcurrentRequests);

    for (int y = 0; y < scene.height; y += stride)
    {
        int actualY = std::max(0, std::min(y, scene.height - tileSize));
        int validH = std::min(tileSize, scene.height - actualY);

        for (int x = 0; x < scene.width; x += stride)
        {
            int actualX = std::max(0, std::min(x, scene.width - tileSize));
            int validW = std::min(tileSize, scene.width - actualX);

            std::shared_ptr<TileRequest> request = extractTileMemory(
                actualX, actualY, validW, validH, tileSize, currentTileId, scene, quality);

            // Dispatch asynchronous inference
            std::future<SemanticTileResult> fut = std::async(
                std::launch::async,
                [request, enabledEndpoints, &config]() {
                    return inferWithRetry(request, enabledEndpoints, config);
                });

            inFlight.push_back({currentTileId, std::move(fut)});

            // Bounded concurrency throttling: wait for oldest task when queue is saturated
            if (inFlight.size() >= maxInFlight)
            {
                payload.tiles.push_back(inFlight.front().futureResult.get());
                inFlight.erase(inFlight.begin());
            }

            currentTileId++;

            if (actualX >= scene.width - tileSize)
                break;
        }

        if (actualY >= scene.height - tileSize)
            break;
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

    co_return payload;
}

std::shared_ptr<TileRequest> SemanticTileDispatcher::extractTileMemory(
    int start_x, int start_y, int valid_w, int valid_h, int tile_size, uint32_t tile_id,
    const SceneInput& scene, const ImageQualityResult& quality)
{
    auto request = std::make_shared<TileRequest>();
    request->tileId = tile_id;
    request->xOffset = start_x;
    request->yOffset = start_y;
    request->width = tile_size;
    request->height = tile_size;
    request->validWidth = valid_w;
    request->validHeight = valid_h;

    const size_t totalTilePixels = static_cast<size_t>(tile_size) * tile_size;
    request->normalizedRgbBytes.assign(totalTilePixels * 3, 0.0f);
    request->validMaskBytes.assign(totalTilePixels, 0);

    float* destRgb = request->normalizedRgbBytes.data();
    uint8_t* destMask = request->validMaskBytes.data();

    const float* srcRgb = quality.normalizedRgbTensor.data.data();
    const uint8_t* srcMask = quality.validPixelMask.data.data();

    const size_t globalChannelArea = static_cast<size_t>(scene.width) * scene.height;
    const size_t tileChannelArea = totalTilePixels;

    // Planar CHW tensor extraction: Channel-by-Channel
    for (int c = 0; c < 3; ++c)
    {
        for (int r = 0; r < valid_h; ++r)
        {
            size_t globalIdx = (c * globalChannelArea) + ((start_y + r) * scene.width) + start_x;
            size_t tileIdx = (c * tileChannelArea) + (r * tile_size);

            std::memcpy(&destRgb[tileIdx], &srcRgb[globalIdx], valid_w * sizeof(float));
        }
    }

    // Single-channel mask extraction
    for (int r = 0; r < valid_h; ++r)
    {
        size_t globalIdx = ((start_y + r) * scene.width) + start_x;
        size_t tileIdx = r * tile_size;

        std::memcpy(&destMask[tileIdx], &srcMask[globalIdx], valid_w * sizeof(uint8_t));
    }

    return request;
}