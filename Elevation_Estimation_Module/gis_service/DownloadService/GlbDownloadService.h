#pragma once

#include <cstdint>
#include <string>
#include <vector>

class GlbDownloadService
{
public:
    static bool download(const std::string& filename, std::vector<uint8_t>& contents);
};