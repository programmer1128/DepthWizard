#pragma once

#include "../structures/QuadTreeTypes.h"
#include <vector>
#include <string>

class GlbFactory 
{
    public:
    
    // takes the graph, absolute DSM and image path
    // generates and uploads all .glb files to MinIO object storage

    static void generateAndUploadAll(
         QuadTreeGraph& graph, 
         const std::vector<float>& master_dsm, 
         const std::vector<uint8_t>& rawJpegBytes, 
         int master_width, 
         int master_height);
};