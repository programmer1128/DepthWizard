#include "GltfPackager.h"
#include "../MeshMapping/PresentationMaterials.h"
#include <algorithm>
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

    // Material table: the scene's descriptors, or the scientific materials for
    // the roles of a scene assembled without descriptors.
    std::vector<MaterialDescriptor> descriptors = scene.materialDescriptors;
    if (descriptors.empty()) {
        for (const MaterialDescriptor& descriptor : depthwizard::presentation::scientificMaterials()) {
            if (std::find(scene.materials.begin(), scene.materials.end(), descriptor.role) != scene.materials.end())
                descriptors.push_back(descriptor);
        }
    }
    const bool anyUnlit = std::any_of(descriptors.begin(), descriptors.end(),
                                      [](const MaterialDescriptor& d) { return d.unlit; });

    // 1. Register Global Extensions
    model.extensionsUsed.push_back("KHR_draco_mesh_compression");
    model.extensionsRequired.push_back("KHR_draco_mesh_compression");
    if (anyUnlit) model.extensionsUsed.push_back("KHR_materials_unlit");

    // 2. Metadata Injection (Asset Extras)
    tinygltf::Value::Object extras;
    extras["horizontalCrs"] = tinygltf::Value(scene.localFrame.horizontalCrs);
    extras["projectedOriginX"] = tinygltf::Value(scene.localFrame.projectedOriginX);
    extras["projectedOriginY"] = tinygltf::Value(scene.localFrame.projectedOriginY);
    extras["elevationOrigin"] = tinygltf::Value(scene.localFrame.elevationOrigin);
    extras["axisConvention"] = tinygltf::Value(scene.localFrame.axisConvention);
    extras["buildingCount"] = tinygltf::Value(static_cast<int>(totalBuildingCount));
    extras["presentationMode"] = tinygltf::Value(scene.presentationMode);
    extras["renderYIsAbsoluteElevationOffset"] = tinygltf::Value(scene.presentationMode == "metric");
    extras["heightScale"] = tinygltf::Value(1.0);
    extras["presentationStyle"] = tinygltf::Value(scene.presentationStyle);
    // Procedural facades are a presentation feature, never source-derived.
    if (scene.syntheticFacades) extras["syntheticFacades"] = tinygltf::Value(true);
    model.asset.extras = tinygltf::Value(extras);
    model.asset.generator = "DepthWizard 3D Pipeline";
    model.asset.version = "2.0";

    // 3. Main Binary Buffer Assembly
    tinygltf::Buffer mainBuffer;
    size_t currentOffset = 0;
    
    const bool hasEdgeLines = scene.edgePrimitive.positions.size() >= 6 && !scene.edgePrimitive.indices.empty();

    // First Pass: Calculate total required memory to avoid reallocations
    size_t totalMemoryRequired = 0;
    for (const auto& prim : compressedPrimitives) {
        size_t bytes = prim.compressedBytes.size();
        totalMemoryRequired += bytes + ((4 - (bytes % 4)) % 4);
    }
    std::vector<TextureAsset> allTextures;
    if (!scene.textures.empty()) {
        allTextures = scene.textures;
    } else if (scene.texture.has_value()) {
        allTextures.push_back(*scene.texture);
    }
    for (const auto& tex : allTextures) {
        size_t bytes = tex.bytes.size();
        totalMemoryRequired += bytes + ((4 - (bytes % 4)) % 4);
    }
    if (hasEdgeLines) {
        size_t posBytes = scene.edgePrimitive.positions.size() * sizeof(float);
        totalMemoryRequired += posBytes + ((4 - (posBytes % 4)) % 4);

        if (scene.edgePrimitive.colors.has_value() && !scene.edgePrimitive.colors->empty()) {
            size_t colBytes = scene.edgePrimitive.colors->size() * sizeof(float);
            totalMemoryRequired += colBytes + ((4 - (colBytes % 4)) % 4);
        }

        size_t idxBytes = scene.edgePrimitive.indices.size() * sizeof(uint32_t);
        totalMemoryRequired += idxBytes + ((4 - (idxBytes % 4)) % 4);
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

    // 5. Embed Image Textures
    for (size_t texIdx = 0; texIdx < allTextures.size(); ++texIdx) {
        const auto& texAsset = allTextures[texIdx];
        size_t imgLen = texAsset.bytes.size();
        size_t pad = (4 - (imgLen % 4)) % 4;

        std::memcpy(mainBuffer.data.data() + currentOffset, texAsset.bytes.data(), imgLen);
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
        image.mimeType = texAsset.mimeType;
        model.images.push_back(image);

        tinygltf::Texture tex;
        tex.source = static_cast<int>(model.images.size() - 1);
        // Geographic images are clamped (finite, and no opposite-edge bleeding
        // at skirts); the facade atlas repeats horizontally within its bands.
        const auto wrap = [](TextureWrap mode) {
            return mode == TextureWrap::REPEAT ? TINYGLTF_TEXTURE_WRAP_REPEAT
                                               : TINYGLTF_TEXTURE_WRAP_CLAMP_TO_EDGE;
        };
        tinygltf::Sampler sampler;
        sampler.wrapS = wrap(texAsset.wrapS);
        sampler.wrapT = wrap(texAsset.wrapT);
        sampler.magFilter = TINYGLTF_TEXTURE_FILTER_LINEAR;
        sampler.minFilter = TINYGLTF_TEXTURE_FILTER_LINEAR_MIPMAP_LINEAR;
        model.samplers.push_back(sampler);
        tex.sampler = static_cast<int>(model.samplers.size() - 1);
        model.textures.push_back(tex);
    }

    // 5b. Embed Uncompressed Line Edge Primitive (Mode: LINES)
    int edgePosAccIdx = -1;
    int edgeColorAccIdx = -1;
    int edgeIdxAccIdx = -1;

    if (hasEdgeLines) {
        // Edge Positions BufferView & Accessor
        size_t posBytes = scene.edgePrimitive.positions.size() * sizeof(float);
        size_t posPad = (4 - (posBytes % 4)) % 4;
        std::memcpy(mainBuffer.data.data() + currentOffset, scene.edgePrimitive.positions.data(), posBytes);
        if (posPad > 0) std::memset(mainBuffer.data.data() + currentOffset + posBytes, 0, posPad);

        tinygltf::BufferView posView;
        posView.buffer = 0;
        posView.byteOffset = currentOffset;
        posView.byteLength = posBytes;
        posView.target = TINYGLTF_TARGET_ARRAY_BUFFER;
        model.bufferViews.push_back(posView);
        int posViewIdx = static_cast<int>(model.bufferViews.size() - 1);
        currentOffset += posBytes + posPad;

        tinygltf::Accessor posAcc;
        posAcc.bufferView = posViewIdx;
        posAcc.byteOffset = 0;
        posAcc.componentType = TINYGLTF_COMPONENT_TYPE_FLOAT;
        posAcc.type = TINYGLTF_TYPE_VEC3;
        posAcc.count = scene.edgePrimitive.positions.size() / 3;
        if (scene.edgePrimitive.localBounds.isInitialized) {
            posAcc.minValues = { scene.edgePrimitive.localBounds.minX, scene.edgePrimitive.localBounds.minY, scene.edgePrimitive.localBounds.minZ };
            posAcc.maxValues = { scene.edgePrimitive.localBounds.maxX, scene.edgePrimitive.localBounds.maxY, scene.edgePrimitive.localBounds.maxZ };
        }
        model.accessors.push_back(posAcc);
        edgePosAccIdx = static_cast<int>(model.accessors.size() - 1);

        // Edge Colors BufferView & Accessor
        if (scene.edgePrimitive.colors.has_value() && !scene.edgePrimitive.colors->empty()) {
            size_t colBytes = scene.edgePrimitive.colors->size() * sizeof(float);
            size_t colPad = (4 - (colBytes % 4)) % 4;
            std::memcpy(mainBuffer.data.data() + currentOffset, scene.edgePrimitive.colors->data(), colBytes);
            if (colPad > 0) std::memset(mainBuffer.data.data() + currentOffset + colBytes, 0, colPad);

            tinygltf::BufferView colView;
            colView.buffer = 0;
            colView.byteOffset = currentOffset;
            colView.byteLength = colBytes;
            colView.target = TINYGLTF_TARGET_ARRAY_BUFFER;
            model.bufferViews.push_back(colView);
            int colViewIdx = static_cast<int>(model.bufferViews.size() - 1);
            currentOffset += colBytes + colPad;

            tinygltf::Accessor colAcc;
            colAcc.bufferView = colViewIdx;
            colAcc.byteOffset = 0;
            colAcc.componentType = TINYGLTF_COMPONENT_TYPE_FLOAT;
            colAcc.type = TINYGLTF_TYPE_VEC4;
            colAcc.count = scene.edgePrimitive.colors->size() / 4;
            model.accessors.push_back(colAcc);
            edgeColorAccIdx = static_cast<int>(model.accessors.size() - 1);
        }

        // Edge Indices BufferView & Accessor
        size_t idxBytes = scene.edgePrimitive.indices.size() * sizeof(uint32_t);
        size_t idxPad = (4 - (idxBytes % 4)) % 4;
        std::memcpy(mainBuffer.data.data() + currentOffset, scene.edgePrimitive.indices.data(), idxBytes);
        if (idxPad > 0) std::memset(mainBuffer.data.data() + currentOffset + idxBytes, 0, idxPad);

        tinygltf::BufferView idxView;
        idxView.buffer = 0;
        idxView.byteOffset = currentOffset;
        idxView.byteLength = idxBytes;
        idxView.target = TINYGLTF_TARGET_ELEMENT_ARRAY_BUFFER;
        model.bufferViews.push_back(idxView);
        int idxViewIdx = static_cast<int>(model.bufferViews.size() - 1);
        currentOffset += idxBytes + idxPad;

        tinygltf::Accessor idxAcc;
        idxAcc.bufferView = idxViewIdx;
        idxAcc.byteOffset = 0;
        idxAcc.componentType = TINYGLTF_COMPONENT_TYPE_UNSIGNED_INT;
        idxAcc.type = TINYGLTF_TYPE_SCALAR;
        idxAcc.count = scene.edgePrimitive.indices.size();
        model.accessors.push_back(idxAcc);
        edgeIdxAccIdx = static_cast<int>(model.accessors.size() - 1);
    }
    
    model.buffers.push_back(mainBuffer);

    // 6. Define Materials
    std::unordered_map<MaterialRole, int> materialMap;
    for (const auto& desc : descriptors) {
        tinygltf::Material mat;
        mat.name = desc.name;
        if (desc.baseColorFactor.size() == 4) {
            mat.pbrMetallicRoughness.baseColorFactor = desc.baseColorFactor;
        }
        mat.pbrMetallicRoughness.metallicFactor = desc.metallicFactor;
        mat.pbrMetallicRoughness.roughnessFactor = desc.roughnessFactor;
        mat.doubleSided = desc.doubleSided;
        mat.alphaMode = desc.alphaMode;

        if (desc.textureIndex >= 0) {
            if (desc.textureIndex >= static_cast<int>(model.textures.size())) {
                result.geometryWarnings.push_back("Material " + desc.name + " references a missing texture.");
                return result;
            }
            mat.pbrMetallicRoughness.baseColorTexture.index = desc.textureIndex;
            mat.pbrMetallicRoughness.baseColorTexture.texCoord = 0;
            // Untextured (scientific) materials stay byte-identical.
            mat.extras = tinygltf::Value(tinygltf::Value::Object{
                {"textureSemantic",
                 tinygltf::Value(std::string(depthwizard::presentation::textureSemanticName(desc.textureSemantic)))}});
        }

        if (desc.unlit) {
            mat.extensions["KHR_materials_unlit"] = tinygltf::Value(tinygltf::Value::Object{});
        }

        model.materials.push_back(mat);
        materialMap[desc.role] = static_cast<int>(model.materials.size() - 1);
    }

    // 7. Assemble Mesh and Primitives
    tinygltf::Mesh mesh;
    
    // We assume the accessors array will grow sequentially as we push them
    for (size_t i = 0; i < compressedPrimitives.size(); ++i) {
        const auto& prim = compressedPrimitives[i];
        if (!prim.success) continue;

        tinygltf::Primitive gltfPrim;
        gltfPrim.mode = TINYGLTF_MODE_TRIANGLES;
        // Never fall back to material 0: that would put the terrain material on a roof.
        const auto bound = materialMap.find(prim.materialRole);
        if (bound == materialMap.end()) {
            result.geometryWarnings.push_back("A primitive's material role has no material.");
            return result;
        }
        gltfPrim.material = bound->second;

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

        // Optional Color Accessor (COLOR_0)
        if (prim.colorAttrId >= 0) {
            tinygltf::Accessor colorAcc;
            colorAcc.bufferView = -1; // Must be -1 for Draco compression
            colorAcc.componentType = TINYGLTF_COMPONENT_TYPE_FLOAT;
            colorAcc.type = TINYGLTF_TYPE_VEC4;
            colorAcc.count = prim.vertexCount;
            model.accessors.push_back(colorAcc);
            int colorAccIdx = static_cast<int>(model.accessors.size() - 1);
            gltfPrim.attributes["COLOR_0"] = colorAccIdx;
            dracoAttrs["COLOR_0"] = tinygltf::Value(prim.colorAttrId);
        }

        // Optional Feature ID Accessor (For WebGL clicking)
        if (prim.featureIdAttrId >= 0) {
            tinygltf::Accessor featAcc;
            featAcc.bufferView = -1;
            featAcc.componentType = TINYGLTF_COMPONENT_TYPE_FLOAT;
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

    // Append Edge Highlight Line Primitive (Uncompressed LINES mode 1)
    if (hasEdgeLines && edgePosAccIdx >= 0 && edgeIdxAccIdx >= 0) {
        tinygltf::Primitive linePrim;
        linePrim.mode = TINYGLTF_MODE_LINE;
        if (materialMap.find(MaterialRole::BUILDING_EDGE) != materialMap.end()) {
            linePrim.material = materialMap[MaterialRole::BUILDING_EDGE];
        } else {
            tinygltf::Material edgeMat;
            edgeMat.pbrMetallicRoughness.baseColorFactor = {1.0f, 1.0f, 1.0f, 1.0f};
            edgeMat.pbrMetallicRoughness.metallicFactor = 0.0f;
            edgeMat.pbrMetallicRoughness.roughnessFactor = 0.1f;
            edgeMat.name = "Building_Edge_Highlight";
            model.materials.push_back(edgeMat);
            linePrim.material = static_cast<int>(model.materials.size() - 1);
        }
        linePrim.attributes["POSITION"] = edgePosAccIdx;
        if (edgeColorAccIdx >= 0) {
            linePrim.attributes["COLOR_0"] = edgeColorAccIdx;
        }
        linePrim.indices = edgeIdxAccIdx;
        mesh.primitives.push_back(linePrim);
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
