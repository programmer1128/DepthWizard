#pragma once
#include <string>
#include <vector>
#include <cstdint>

class GltfPackager {
public:
    static bool buildAndSave(
        const std::string& outputPath,
        const std::vector<float>& positions,
        const std::vector<uint32_t>& indices,
        const std::vector<float>& uvs,
        const double bounds[6], // [minX, minY, minZ, maxX, maxY, maxZ]
        const char* imgData,
        size_t imgLength
    );
};