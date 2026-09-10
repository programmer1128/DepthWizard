#pragma once

#include "../utils/QuadTreeTypes.h"
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
        const std::string& image_path
    );
};