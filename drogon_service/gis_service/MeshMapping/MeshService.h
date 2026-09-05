#pragma once
#include <vector>
#include <string>
#include <cstdint>
#include "../CompressionLib/DracoCompressor.h"

class GlbMesher 
{
     public:
     // Generates a geometry-only 3D mesh (Vertices + Indices) and packs it into a .glb
     std::vector<uint8_t> generateGlb(
         const std::vector<float>& dsm_matrix, 
         int width, 
         int height,
         float pixel_size,
         const char* imgData,
         size_t imgLength);
};