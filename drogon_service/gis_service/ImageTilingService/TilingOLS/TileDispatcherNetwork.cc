#include "TileDispatcher.h"

#include <curl/curl.h>
#include <cstring>
#include <stdexcept>
#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <span>
#include <memory>
#include <mutex>

// ============================================================
// PROTOCOL (Must match Modal C++ engine)
// ============================================================
#pragma pack(push, 1)
struct FrameHeader
{
    uint32_t magic;
    uint32_t tile_id;
    uint32_t width;
    uint32_t height;
    uint32_t channels;
    uint32_t dtype;
    uint64_t payload_len;
};
#pragma pack(pop)

static constexpr uint32_t FRAME_MAGIC = 0xDEADBEEF;
static constexpr int TILE_SIZE = 518;
static constexpr size_t EXPECTED_RETURN_FLOATS = static_cast<size_t>(TILE_SIZE) * static_cast<size_t>(TILE_SIZE);
static constexpr size_t EXPECTED_RETURN_BYTES = EXPECTED_RETURN_FLOATS * sizeof(float);

// Thread-safe global init
static std::once_flag g_curl_once;
static void EnsureCurlGlobalInit() {
    std::call_once(g_curl_once, []() {
        curl_global_init(CURL_GLOBAL_DEFAULT);
        std::cout << ">> [CURL] Global Init OK (" << curl_version() << ")\n";
    });
}

// Write callback to stream response into vector
struct DownloadSink {
    std::vector<char>* buf;
    size_t hard_limit;
};

static size_t WriteCallback(char* ptr, size_t size, size_t nmemb, void* userdata) {
    auto* sink = static_cast<DownloadSink*>(userdata);
    size_t bytes = size * nmemb;
    if (sink->buf->size() + bytes > sink->hard_limit) return 0; // Abort
    sink->buf->insert(sink->buf->end(), ptr, ptr + bytes);
    return bytes;
}

// ============================================================
// NETWORK INFERENCE (libcurl + HTTP/2)
// ============================================================
std::shared_ptr<std::vector<float>>
TileDispatcher::streamToLightningAI(
    std::span<const uint8_t> raw_tile_binary,
    const std::string& target_url,
    uint32_t tile_id,
    const std::atomic<bool>& stop_flag) // ADDED PARAMETER
{
    // CHECK 1: Immediate exit if cancelled
    if (stop_flag.load()) throw std::runtime_error("Tile " + std::to_string(tile_id) + ": Cancelled.");

    EnsureCurlGlobalInit();

    if (raw_tile_binary.empty()) throw std::runtime_error("Tile " + std::to_string(tile_id) + ": empty payload.");

    // Build Header
    FrameHeader header{};
    header.magic = FRAME_MAGIC;
    header.tile_id = tile_id;
    header.width = TILE_SIZE;
    header.height = TILE_SIZE;
    header.channels = 3;
    header.dtype = 1;
    header.payload_len = raw_tile_binary.size();

    // Build Payload
    std::vector<char> http_payload(sizeof(FrameHeader) + header.payload_len);
    std::memcpy(http_payload.data(), &header, sizeof(FrameHeader));
    std::memcpy(http_payload.data() + sizeof(FrameHeader), raw_tile_binary.data(), header.payload_len);

    std::cout << ">> [CLOUD] Tile " << tile_id << " sending " << http_payload.size() << " bytes (HTTP/2)...\n";

    constexpr int max_retries = 3;
    std::vector<char> response_buf;
    response_buf.reserve(EXPECTED_RETURN_BYTES);
    bool success = false;
    CURLcode last_rc = CURLE_OK;
    long http_code = 0;

    for (int attempt = 1; attempt <= max_retries; ++attempt) {
        // CHECK 2: Exit before retry if cancelled
        if (stop_flag.load()) throw std::runtime_error("Tile " + std::to_string(tile_id) + ": Cancelled during retry.");

        response_buf.clear();
        CURL* curl = curl_easy_init();
        if (!curl) throw std::runtime_error("curl_easy_init failed");

        DownloadSink sink{&response_buf, EXPECTED_RETURN_BYTES * 2};
        struct curl_slist* headers = nullptr;
        headers = curl_slist_append(headers, "Content-Type: application/octet-stream");
        headers = curl_slist_append(headers, "User-Agent: DrogonClient/2.0");

        curl_easy_setopt(curl, CURLOPT_URL, target_url.c_str());
        curl_easy_setopt(curl, CURLOPT_POST, 1L);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, http_payload.data());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, (long)http_payload.size());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        
        // FORCE HTTP/2 (The Fix)
        curl_easy_setopt(curl, CURLOPT_HTTP_VERSION, CURL_HTTP_VERSION_2TLS);
        
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &sink);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
        curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1L); // Critical for threads
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 300L);

        last_rc = curl_easy_perform(curl);
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);

        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);

        if (last_rc == CURLE_OK && http_code == 200) {
            success = true;
            break;
        }

        std::cerr << ">> [CLOUD] Tile " << tile_id << " Fail RC=" << last_rc << " HTTP=" << http_code << "\n";
        if (attempt < max_retries) std::this_thread::sleep_for(std::chrono::seconds(2));
    }

    if (!success) throw std::runtime_error("Tile " + std::to_string(tile_id) + " failed after retries.");
    if (response_buf.size() != EXPECTED_RETURN_BYTES) throw std::runtime_error("Tile " + std::to_string(tile_id) + " size mismatch.");

    auto result = std::make_shared<std::vector<float>>(EXPECTED_RETURN_FLOATS);
    std::memcpy(result->data(), response_buf.data(), EXPECTED_RETURN_BYTES);
    
    std::cout << ">> [CLOUD] Tile " << tile_id << " SUCCESS.\n";
    return result;
}