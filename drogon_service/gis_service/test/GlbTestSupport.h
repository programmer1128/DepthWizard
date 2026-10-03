#pragma once

// Reads Draco-compressed attributes back out of a packaged GLB. tinygltf
// parses the glTF JSON but leaves KHR_draco_mesh_compression payloads
// encoded, so structural tests decode them here.

#include "tiny_gltf.h"

#include <draco/compression/decode.h>

#include <gtest/gtest.h>

#include <memory>
#include <string>
#include <vector>

namespace depthwizard::test
{

inline tinygltf::Model loadGlb(const std::vector<uint8_t>& glb)
{
    tinygltf::TinyGLTF loader;
    tinygltf::Model model;
    std::string error;
    std::string warning;
    EXPECT_TRUE(loader.LoadBinaryFromMemory(&model, &error, &warning, glb.data(), glb.size())) << error;
    return model;
}

// Per-vertex values of one attribute of a Draco primitive, flattened. Empty
// when the primitive has no such attribute.
inline std::vector<float> decodeDracoAttribute(const tinygltf::Model& model, const tinygltf::Primitive& primitive,
                                               const std::string& attribute)
{
    const auto extension = primitive.extensions.find("KHR_draco_mesh_compression");
    if (extension == primitive.extensions.end()) return {};
    const tinygltf::Value& draco = extension->second;
    if (!draco.Get("attributes").Has(attribute)) return {};

    const tinygltf::BufferView& view = model.bufferViews[draco.Get("bufferView").GetNumberAsInt()];
    const tinygltf::Buffer& buffer = model.buffers[view.buffer];
    draco::DecoderBuffer source;
    source.Init(reinterpret_cast<const char*>(buffer.data.data() + view.byteOffset), view.byteLength);
    draco::Decoder decoder;
    auto decoded = decoder.DecodeMeshFromBuffer(&source);
    if (!decoded.ok()) return {};
    const std::unique_ptr<draco::Mesh> mesh = std::move(decoded).value();

    const draco::PointAttribute* values =
        mesh->GetAttributeByUniqueId(draco.Get("attributes").Get(attribute).GetNumberAsInt());
    if (values == nullptr) return {};
    const int components = values->num_components();
    std::vector<float> flattened(static_cast<std::size_t>(mesh->num_points()) * components);
    for (draco::PointIndex point(0); point < mesh->num_points(); ++point)
        values->GetValue(values->mapped_index(point), flattened.data() + point.value() * components);
    return flattened;
}

inline const tinygltf::Primitive* primitiveWithMaterial(const tinygltf::Model& model, const std::string& prefix)
{
    for (const tinygltf::Primitive& primitive : model.meshes.at(0).primitives)
        if (primitive.material >= 0 && model.materials[primitive.material].name.rfind(prefix, 0) == 0)
            return &primitive;
    return nullptr;
}

} // namespace depthwizard::test
