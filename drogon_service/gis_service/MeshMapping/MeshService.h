#pragma once
#include <vector>
#include <string>
#include <cstdint>

class GlbMesher 
{
     public:
     // Generates a geometry-only 3D mesh (Vertices + Indices) and packs it into a .glb
     bool generateGlb(
         const std::string& outputPath, 
         const std::vector<float>& dsm_matrix, 
         int width, 
         int height,
         float pixel_size = 1.0f );
};