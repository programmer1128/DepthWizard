#include "GlbDownloadService.h"

#include "../DataHandlers/MiniIOClient.h"

bool GlbDownloadService::download(
    const std::string& filename,
    std::vector<uint8_t>& contents)
{
    return MinioClient::downloadBuffer("terrain-assets", filename, contents);
}