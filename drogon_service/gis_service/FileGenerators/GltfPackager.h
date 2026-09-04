#pragma once
#include <string>
#include <vector>
#include <cstdint>
#include "../CompressionLib/DracoCompressor.h"

class GltfPackager 
{
     public:
     static std::vector<uint8_t> buildToMemory(
         const DracoCompressionResult& dracoResult,
         size_t numVertices,
         size_t numIndices,
         const double bounds[6], 
         const char* imgData,
         size_t imgLength);
};