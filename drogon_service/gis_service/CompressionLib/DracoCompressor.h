// upgraded to accept the formal MeshPrimitive struct 
// it dynamically handles geometry that may or may not have textures (UVs) or normals, 
// which is critical since building walls often lack optical textures

#pragma once

#include <vector>
#include <cstdint>
#include <string>
#include "../structures/MeshStructs.h"

struct DracoCompressionResult 
{
    std::vector<uint8_t> compressedBytes;
    int posAttrId = -1;
    int uvAttrId = -1;
    int normalAttrId = -1;
    bool success = false;
    std::string errorMessage;
};

class DracoCompressor 
{
public:
    // core function to compress a fully populated primitive (terrain, roof or wall)
    static DracoCompressionResult compress(const MeshPrimitive& primitive, int speed = 5);

    // retained for backward compatibility with older generic calls
    static DracoCompressionResult compressGeometry(
        const std::vector<float>& positions,
        const std::vector<uint32_t>& indices,
        const std::vector<float>& uvs,
        const std::vector<float>& normals,
        int posQuantization = 14,
        int uvQuantization = 12,
        int normalQuantization = 10,
        int speed = 5);
};