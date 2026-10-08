#pragma once
#include "../structures/MeshStructs.h"
#include <vector>
#include <string>
#include <cstdint>

struct DracoCompressionConfig {
    int posQuantization{16};
    int uvQuantization{12};
    int normalQuantization{10};
    int colorQuantization{10};
    int featureIdQuantization{18}; // High enough to losslessly store integer IDs
    int speed{7};
};

// Represents a single compressed glTF primitive layer
struct CompressedPrimitive {
    bool success{false};
    std::string errorMessage;
    
    std::vector<uint8_t> compressedBytes;
    size_t vertexCount{0};
    size_t indexCount{0};
    AxisAlignedBounds localBounds;
    
    // Draco Attribute Mapping IDs (needed by the GLTF Packager)
    int posAttrId{-1};
    int uvAttrId{-1};
    int normalAttrId{-1};
    int colorAttrId{-1};
    int featureIdAttrId{-1};
    
    MaterialRole materialRole; // Pass through to know what to assign
};

class DracoCompressor {
public:
    static CompressedPrimitive compress(
        const MeshPrimitive& primitive,
        const DracoCompressionConfig& config = DracoCompressionConfig());
};
