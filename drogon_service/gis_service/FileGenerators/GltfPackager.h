// packages multiple distinct 3D objects (Terrain, Roofs, Walls) into a single web-ready GLB file
// it dynamically maps materials and extensions per primitive

#pragma once
#include <string>
#include <vector>
#include "../CompressionLib/DracoCompressor.h"
#include "../structures/MeshStructs.h"
#include "../structures/ExportStructs.h"

class GltfPackager 
{
    public:
    
    // takes the orchestrated SceneMesh and the corresponding compressed Draco buffers, 
    // links them securely with the correct materials and writes the GLB entirely in RAM
    
    // scene: the master structural mesh containing multiple logical parts (terrain, buildings)
    // compressedPrimitives: the matching list of Draco bitstreams (1-to-1 mapping with scene primitives)
    
    // GlbBuildResult: contains the final byte stream and critical frontend metadata
    
    static GlbBuildResult buildSceneToMemory(
        const SceneMesh& scene, 
        const std::vector<DracoCompressionResult>& compressedPrimitives);
};