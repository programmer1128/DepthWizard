#pragma once

#include <vector>
#include <cstdint>
#include <string>

struct DracoCompressionResult 
{
     std::vector<uint8_t> compressedBytes;
     int posAttrId = -1;
     int uvAttrId = -1;
     //adding normal attribute to draco compression to eliminate shadows
     //and smooth vertex normals
     int normalAttrId = -1;
     bool success = false;
     std::string errorMessage;
};

class DracoCompressor 
{
     public:
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