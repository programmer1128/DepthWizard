// Iterates through an arbitrary number of primitives, handles the strict 4-byte 
// memory alignment rules required by WebGL/glTFast and serializes the JSON header

#include "GltfPackager.h"
#include <iostream>
#include <cstring>
#include <sstream>

#define TINYGLTF_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "tiny_gltf.h"

GlbBuildResult GltfPackager::buildSceneToMemory(
    const SceneMesh& scene, 
    const std::vector<DracoCompressionResult>& compressedPrimitives)
{
    GlbBuildResult buildResult;
    tinygltf::Model model;

    // Register Draco Extensions Globally
    model.extensionsUsed.push_back("KHR_draco_mesh_compression");
    model.extensionsRequired.push_back("KHR_draco_mesh_compression");

    // Gather all primitives into a clean list for iteration
    std::vector<const MeshPrimitive*> activePrimitives;
    activePrimitives.push_back(&scene.terrainPrimitive);
    activePrimitives.push_back(&scene.roofPrimitive);
    activePrimitives.push_back(&scene.wallPrimitive);
    if (scene.overlayPrimitive.has_value()) 
    {
        activePrimitives.push_back(&scene.overlayPrimitive.value());
    }

    if (activePrimitives.size() != compressedPrimitives.size()) 
    {
        buildResult.geometryWarnings.push_back("Fatal mismatch: Primitives count does not match compressed buffers count");
        return buildResult;
    }

    // Pre-calculate total memory required for the master binary chunk
    size_t totalDracoBytes = 0;
    std::vector<size_t> byteOffsets; 
    std::vector<size_t> bytePaddings;

    for (const auto& draco : compressedPrimitives) 
    {
        if (!draco.success) throw std::runtime_error("Cannot package GLTF: A Draco compression step failed.");
        
        size_t rawSize = draco.compressedBytes.size();
        size_t pad = (4 - (rawSize % 4)) % 4; // WebGL strictly requires 4-byte alignment
        
        byteOffsets.push_back(totalDracoBytes);
        bytePaddings.push_back(pad);
        
        totalDracoBytes += (rawSize + pad);
    }

    size_t imgLength = 0;
    if (scene.texture.has_value()) 
    {
        imgLength = scene.texture->bytes.size();
    }
    
    size_t finalPadding = (4 - ((totalDracoBytes + imgLength) % 4)) % 4;
    size_t masterBufferSize = totalDracoBytes + imgLength + finalPadding;

    // Allocate and fill the single Master Buffer
    tinygltf::Buffer mainBuffer;
    mainBuffer.data.resize(masterBufferSize, 0); // Fills with zeroes, implicitly handling padding
    
    for (size_t i = 0; i < compressedPrimitives.size(); ++i) 
    {
        std::memcpy(
            mainBuffer.data.data() + byteOffsets[i], 
            compressedPrimitives[i].compressedBytes.data(), 
            compressedPrimitives[i].compressedBytes.size()
        );
    }

    if (scene.texture.has_value()) 
    {
        std::memcpy(mainBuffer.data.data() + totalDracoBytes, scene.texture->bytes.data(), imgLength);
    }

    model.buffers.push_back(mainBuffer);

    // Setup Buffer Views, Accessors and Primitives dynamically
    tinygltf::Mesh gltfMesh;
    
    for (size_t i = 0; i < activePrimitives.size(); ++i) 
    {
        const MeshPrimitive* prim = activePrimitives[i];
        const DracoCompressionResult& draco = compressedPrimitives[i];

        // Create BufferView for this specific chunk of Draco data
        tinygltf::BufferView dracoView;
        dracoView.buffer = 0; 
        dracoView.byteOffset = byteOffsets[i]; 
        dracoView.byteLength = draco.compressedBytes.size();
        
        int viewIndex = model.bufferViews.size();
        model.bufferViews.push_back(dracoView);

        // Map Accessors (Set view to -1 as KHR_draco_mesh_compression requires)
        size_t numVerts = prim->positions.size() / 3;
        size_t numInds = prim->indices.size();

        buildResult.vertexCount += numVerts;
        buildResult.triangleCount += (numInds / 3);

        tinygltf::Accessor posAcc;
        posAcc.bufferView = -1; posAcc.byteOffset = 0; posAcc.count = numVerts;
        posAcc.componentType = TINYGLTF_COMPONENT_TYPE_FLOAT; posAcc.type = TINYGLTF_TYPE_VEC3;
        posAcc.minValues = { prim->localBounds.minX, prim->localBounds.minY, prim->localBounds.minZ };
        posAcc.maxValues = { prim->localBounds.maxX, prim->localBounds.maxY, prim->localBounds.maxZ };
        int posAccIdx = model.accessors.size();
        model.accessors.push_back(posAcc);

        tinygltf::Accessor indAcc;
        indAcc.bufferView = -1; indAcc.byteOffset = 0; indAcc.count = numInds;
        indAcc.componentType = TINYGLTF_COMPONENT_TYPE_UNSIGNED_INT; indAcc.type = TINYGLTF_TYPE_SCALAR;
        int indAccIdx = model.accessors.size();
        model.accessors.push_back(indAcc);

        int uvAccIdx = -1, normAccIdx = -1;

        if (draco.uvAttrId != -1) 
        {
            tinygltf::Accessor uvAcc;
            uvAcc.bufferView = -1; uvAcc.byteOffset = 0; uvAcc.count = numVerts;
            uvAcc.componentType = TINYGLTF_COMPONENT_TYPE_FLOAT; uvAcc.type = TINYGLTF_TYPE_VEC2;
            uvAccIdx = model.accessors.size();
            model.accessors.push_back(uvAcc);
        }

        if (draco.normalAttrId != -1) 
        {
            tinygltf::Accessor normAcc;
            normAcc.bufferView = -1; normAcc.byteOffset = 0; normAcc.count = numVerts;
            normAcc.componentType = TINYGLTF_COMPONENT_TYPE_FLOAT; normAcc.type = TINYGLTF_TYPE_VEC3;
            normAccIdx = model.accessors.size();
            model.accessors.push_back(normAcc);
        }

        // Construct the glTF Primitive
        tinygltf::Primitive gltfPrim;
        gltfPrim.mode = TINYGLTF_MODE_TRIANGLES;
        gltfPrim.indices = indAccIdx;
        gltfPrim.attributes["POSITION"] = posAccIdx;
        if (uvAccIdx != -1) gltfPrim.attributes["TEXCOORD_0"] = uvAccIdx;
        if (normAccIdx != -1) gltfPrim.attributes["NORMAL"] = normAccIdx;

        // Assign materials based on role (0: Terrain, 1: Roofs, 2: Walls)
        if (prim->materialRole == MaterialRole::TERRAIN_TEXTURE) gltfPrim.material = 0;
        else if (prim->materialRole == MaterialRole::BUILDING_ROOF) gltfPrim.material = 1;
        else if (prim->materialRole == MaterialRole::BUILDING_WALL) gltfPrim.material = 2;

        // Inject Draco Extension JSON
        tinygltf::Value::Object dracoExt;
        dracoExt["bufferView"] = tinygltf::Value(viewIndex);
        
        tinygltf::Value::Object dracoAttrs;
        dracoAttrs["POSITION"] = tinygltf::Value(draco.posAttrId);
        if (draco.uvAttrId != -1) dracoAttrs["TEXCOORD_0"] = tinygltf::Value(draco.uvAttrId);
        if (draco.normalAttrId != -1) dracoAttrs["NORMAL"] = tinygltf::Value(draco.normalAttrId);
        
        dracoExt["attributes"] = tinygltf::Value(dracoAttrs);
        gltfPrim.extensions["KHR_draco_mesh_compression"] = tinygltf::Value(dracoExt);

        gltfMesh.primitives.push_back(gltfPrim);
    }

    model.meshes.push_back(gltfMesh);

    // Setup Materials and Image (if applicable)
    tinygltf::Material matTerrain, matRoof, matWall;
    
    if (scene.texture.has_value()) 
    {
        tinygltf::BufferView imgView;
        imgView.buffer = 0; 
        imgView.byteOffset = totalDracoBytes; 
        imgView.byteLength = imgLength;
        int imgViewIdx = model.bufferViews.size();
        model.bufferViews.push_back(imgView);

        tinygltf::Image image;
        image.bufferView = imgViewIdx;
        image.mimeType = scene.texture->mimeType;
        model.images.push_back(image);

        tinygltf::Texture texture;
        texture.source = 0;
        model.textures.push_back(texture);

        matTerrain.pbrMetallicRoughness.baseColorTexture.index = 0;
    }
    
    matTerrain.pbrMetallicRoughness.metallicFactor = 0.0;
    matTerrain.pbrMetallicRoughness.roughnessFactor = 0.9;
    
    // Roof gets a slight neutral tint, Walls get a slightly darker tint
    matRoof.pbrMetallicRoughness.baseColorFactor = {0.8, 0.8, 0.8, 1.0};
    matWall.pbrMetallicRoughness.baseColorFactor = {0.6, 0.6, 0.6, 1.0};

    model.materials.push_back(matTerrain);
    model.materials.push_back(matRoof);
    model.materials.push_back(matWall);

    // Finalize Scene Graph
    tinygltf::Node node;
    node.mesh = 0;
    model.nodes.push_back(node);

    tinygltf::Scene gltfScene;
    gltfScene.nodes.push_back(0);
    model.scenes.push_back(gltfScene);
    model.defaultScene = 0;

    // Serialize to binary buffer
    tinygltf::TinyGLTF gltfContext;
    std::stringstream stream(std::ios_base::out | std::ios_base::binary);
    bool success = gltfContext.WriteGltfSceneToStream(&model, stream, false, true);
    
    if (!success) throw std::runtime_error("Failed to serialize GLTF to memory.");

    std::string streamStr = stream.str();
    buildResult.compressedGlbByteBuffer = std::vector<uint8_t>(streamStr.begin(), streamStr.end());
    buildResult.boundingBox = scene.sceneBounds;
    buildResult.localOrigin = scene.localFrame;

    return buildResult;
}