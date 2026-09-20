#include "GltfPackager.h"
#include <iostream>
#include <cstring>
#include <sstream>
#include <unordered_map>

// Only define these in exactly ONE .cc file in your project
#define TINYGLTF_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "tiny_gltf.h"

GlbBuildResult GltfPackager::buildSceneToMemory(
    const SceneMesh& scene,
    const std::vector<CompressedPrimitive>& compressedPrimitives,
    size_t totalBuildingCount)
{
    GlbBuildResult result;
    tinygltf::Model model;

    // 1. Register Global Extensions
    model.extensionsUsed.push_back("KHR_draco_mesh_compression");
    model.extensionsRequired.push_back("KHR_draco_mesh_compression");

    // 2. Metadata Injection (Asset Extras)
    tinygltf::Value::Object extras;
    extras["horizontalCrs"] = tinygltf::Value(scene.localFrame.horizontalCrs);
    extras["projectedOriginX"] = tinygltf::Value(scene.localFrame.projectedOriginX);
    extras["projectedOriginY"] = tinygltf::Value(scene.localFrame.projectedOriginY);
    extras["elevationOrigin"] = tinygltf::Value(scene.localFrame.elevationOrigin);
    extras["axisConvention"] = tinygltf::Value(scene.localFrame.axisConvention);
    extras["buildingCount"] = tinygltf::Value(static_cast<int>(totalBuildingCount));
    model.asset.extras = tinygltf::Value(extras);
    model.asset.generator = "DepthWizard 3D Pipeline";
    model.asset.version = "2.0";

    // 3. Main Binary Buffer Assembly
    tinygltf::Buffer mainBuffer;
    size_t currentOffset = 0;
    
    // First Pass: Calculate total required memory to avoid reallocations
    size_t totalMemoryRequired = 0;
    for (const auto& prim : compressedPrimitives) {
        size_t bytes = prim.compressedBytes.size();
        totalMemoryRequired += bytes + ((4 - (bytes % 4)) % 4);
    }
    if (scene.texture.has_value()) {
        size_t bytes = scene.texture->bytes.size();
        totalMemoryRequired += bytes + ((4 - (bytes % 4)) % 4);
    }
    
    mainBuffer.data.resize(totalMemoryRequired);
    
    // 4. Construct Buffer Views & Append Bytes
    std::vector<int> dracoBufferViewIndices;
    
    for (const auto& prim : compressedPrimitives) {
        size_t dracoLen = prim.compressedBytes.size();
        size_t pad = (4 - (dracoLen % 4)) % 4;

        std::memcpy(mainBuffer.data.data() + currentOffset, prim.compressedBytes.data(), dracoLen);
        if (pad > 0) std::memset(mainBuffer.data.data() + currentOffset + dracoLen, 0, pad);

        tinygltf::BufferView bView;
        bView.buffer = 0;
        bView.byteOffset = currentOffset;
        bView.byteLength = dracoLen;
        model.bufferViews.push_back(bView);
        dracoBufferViewIndices.push_back(model.bufferViews.size() - 1);

        currentOffset += dracoLen + pad;
    }

    // 5. Embed Image Texture
    int textureImageIndex = -1;
    if (scene.texture.has_value()) {
        size_t imgLen = scene.texture->bytes.size();
        size_t pad = (4 - (imgLen % 4)) % 4;

        std::memcpy(mainBuffer.data.data() + currentOffset, scene.texture->bytes.data(), imgLen);
        if (pad > 0) std::memset(mainBuffer.data.data() + currentOffset + imgLen, 0, pad);

        tinygltf::BufferView imgView;
        imgView.buffer = 0;
        imgView.byteOffset = currentOffset;
        imgView.byteLength = imgLen;
        model.bufferViews.push_back(imgView);
        int imgViewIndex = static_cast<int>(model.bufferViews.size() - 1);
        currentOffset += imgLen + pad;

        tinygltf::Image image;
        image.bufferView = imgViewIndex;
        image.mimeType = scene.texture->mimeType;
        model.images.push_back(image);

        tinygltf::Texture tex;
        tex.source = 0; // Point to image 0
        model.textures.push_back(tex);
        textureImageIndex = 0;
    }
    
    model.buffers.push_back(mainBuffer);

    // 6. Define Materials (The Hologram Styling)
    std::unordered_map<MaterialRole, int> materialMap;
    
    auto createMaterial = [&](MaterialRole role) -> int {
        tinygltf::Material mat;
        mat.pbrMetallicRoughness.metallicFactor = 0.0; // Matte finish
        mat.pbrMetallicRoughness.roughnessFactor = 0.9;
        mat.doubleSided = false;

        if (role == MaterialRole::TERRAIN_TEXTURE && textureImageIndex >= 0) {
            mat.pbrMetallicRoughness.baseColorTexture.index = textureImageIndex;
            mat.name = "Terrain_Optical";
        } else if (role == MaterialRole::BUILDING_WALL) {
            // Teal/Cyan solid hologram block[cite: 10]
            mat.pbrMetallicRoughness.baseColorFactor = {0.2, 0.8, 0.7, 1.0}; 
            mat.name = "Hologram_Wall";
        } else if (role == MaterialRole::BUILDING_ROOF) {
            // Lighter Salmon/Gray solid block for roofs to distinguish from walls[cite: 10]
            mat.pbrMetallicRoughness.baseColorFactor = {0.9, 0.6, 0.5, 1.0};
            mat.name = "Hologram_Roof";
        }
        
        model.materials.push_back(mat);
        return static_cast<int>(model.materials.size() - 1);
    };

    for (MaterialRole role : scene.materials) {
        materialMap[role] = createMaterial(role);
    }

    // 7. Assemble Mesh and Primitives
    tinygltf::Mesh mesh;
    
    // We assume the accessors array will grow sequentially as we push them
    for (size_t i = 0; i < compressedPrimitives.size(); ++i) {
        const auto& prim = compressedPrimitives[i];
        if (!prim.success) continue;

        tinygltf::Primitive gltfPrim;
        gltfPrim.mode = TINYGLTF_MODE_TRIANGLES;
        gltfPrim.material = materialMap[prim.materialRole];

        tinygltf::Value::Object dracoExt;
        dracoExt["bufferView"] = tinygltf::Value(dracoBufferViewIndices[i]);
        tinygltf::Value::Object dracoAttrs;

        // Position Accessor (Required)
        tinygltf::Accessor posAcc;
        posAcc.bufferView = -1; // Must be -1 for Draco
        posAcc.componentType = TINYGLTF_COMPONENT_TYPE_FLOAT;
        posAcc.type = TINYGLTF_TYPE_VEC3;
        posAcc.count = prim.vertexCount;
        if (prim.localBounds.isInitialized) {
            posAcc.minValues = { prim.localBounds.minX, prim.localBounds.minY, prim.localBounds.minZ };
            posAcc.maxValues = { prim.localBounds.maxX, prim.localBounds.maxY, prim.localBounds.maxZ };
        }
        model.accessors.push_back(posAcc);
        int posAccIdx = static_cast<int>(model.accessors.size() - 1);
        gltfPrim.attributes["POSITION"] = posAccIdx;
        dracoAttrs["POSITION"] = tinygltf::Value(prim.posAttrId);

        // Optional Normal Accessor
        if (prim.normalAttrId >= 0) {
            tinygltf::Accessor normAcc;
            normAcc.bufferView = -1;
            normAcc.componentType = TINYGLTF_COMPONENT_TYPE_FLOAT;
            normAcc.type = TINYGLTF_TYPE_VEC3;
            normAcc.count = prim.vertexCount;
            model.accessors.push_back(normAcc);
            int normAccIdx = static_cast<int>(model.accessors.size() - 1);
            gltfPrim.attributes["NORMAL"] = normAccIdx;
            dracoAttrs["NORMAL"] = tinygltf::Value(prim.normalAttrId);
        }

        // Optional UV Accessor (TEXCOORD_0)
        if (prim.uvAttrId >= 0) {
            tinygltf::Accessor uvAcc;
            uvAcc.bufferView = -1;
            uvAcc.componentType = TINYGLTF_COMPONENT_TYPE_FLOAT;
            uvAcc.type = TINYGLTF_TYPE_VEC2;
            uvAcc.count = prim.vertexCount;
            model.accessors.push_back(uvAcc);
            int uvAccIdx = static_cast<int>(model.accessors.size() - 1);
            gltfPrim.attributes["TEXCOORD_0"] = uvAccIdx;
            dracoAttrs["TEXCOORD_0"] = tinygltf::Value(prim.uvAttrId);
        }

        // Optional Feature ID Accessor (For WebGL clicking)
        if (prim.featureIdAttrId >= 0) {
            tinygltf::Accessor featAcc;
            featAcc.bufferView = -1;
            featAcc.componentType = TINYGLTF_COMPONENT_TYPE_UNSIGNED_INT;
            featAcc.type = TINYGLTF_TYPE_SCALAR;
            featAcc.count = prim.vertexCount;
            model.accessors.push_back(featAcc);
            int featAccIdx = static_cast<int>(model.accessors.size() - 1);
            // Standard naming convention for custom per-vertex IDs in glTF
            gltfPrim.attributes["_FEATURE_ID_0"] = featAccIdx; 
            dracoAttrs["_FEATURE_ID_0"] = tinygltf::Value(prim.featureIdAttrId);
        }

        // Apply Draco Extension to this Primitive
        dracoExt["attributes"] = tinygltf::Value(dracoAttrs);
        gltfPrim.extensions["KHR_draco_mesh_compression"] = tinygltf::Value(dracoExt);

        tinygltf::Accessor indexAcc;
        indexAcc.bufferView = -1;
        indexAcc.componentType = TINYGLTF_COMPONENT_TYPE_UNSIGNED_INT;
        indexAcc.type = TINYGLTF_TYPE_SCALAR;
        indexAcc.count = prim.indexCount;
        model.accessors.push_back(indexAcc);
        gltfPrim.indices = static_cast<int>(model.accessors.size() - 1);

        mesh.primitives.push_back(gltfPrim);
    }
    
    model.meshes.push_back(mesh);

    // 8. Connect Nodes & Scenes
    tinygltf::Node node;
    node.mesh = 0;
    model.nodes.push_back(node);

    tinygltf::Scene gltfScene;
    gltfScene.nodes.push_back(0);
    model.scenes.push_back(gltfScene);
    model.defaultScene = 0;

    // 9. Serialize to Binary (.glb)
    tinygltf::TinyGLTF gltfContext;
    std::stringstream stream(std::ios_base::out | std::ios_base::binary);
    
    bool success = gltfContext.WriteGltfSceneToStream(&model, stream, false, true);
    if (!success) {
        result.geometryWarnings.push_back("Failed to serialize GLTF scene to memory stream.");
        return result; // Empty glb byte vector
    }

    std::string streamStr = stream.str();
    result.compressedGlbByteBuffer = std::vector<uint8_t>(streamStr.begin(), streamStr.end());
    
    // Fill final result payload
    result.buildingCount = totalBuildingCount;
    result.boundingBox = scene.sceneBounds;
    result.localOrigin = scene.localFrame;

    return result;
}
