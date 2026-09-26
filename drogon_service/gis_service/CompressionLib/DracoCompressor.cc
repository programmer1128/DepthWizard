#include "DracoCompressor.h"
#include <draco/compression/encode.h>
#include <draco/mesh/mesh.h>
#include <draco/attributes/point_attribute.h>
#include <iostream>
#include <limits>

CompressedPrimitive DracoCompressor::compress(
    const MeshPrimitive& primitive,
    const DracoCompressionConfig& config)
{
    CompressedPrimitive result;
    result.materialRole = primitive.materialRole;

    if (!primitive.isValid()) {
        result.errorMessage = "Invalid MeshPrimitive geometry provided to compressor.";
        return result;
    }

    draco::Mesh dracoMesh;
    size_t numFaces = primitive.indices.size() / 3;
    size_t numPoints = primitive.positions.size() / 3;

    result.vertexCount = numPoints;
    result.indexCount = primitive.indices.size();
    result.localBounds = primitive.localBounds;

    dracoMesh.SetNumFaces(numFaces);
    dracoMesh.set_num_points(numPoints);

    // 1. Populate Faces
    for (size_t i = 0; i < numFaces; ++i) {
        draco::Mesh::Face face;
        face[0] = draco::PointIndex(primitive.indices[i * 3 + 0]);
        face[1] = draco::PointIndex(primitive.indices[i * 3 + 1]);
        face[2] = draco::PointIndex(primitive.indices[i * 3 + 2]);
        dracoMesh.SetFace(draco::FaceIndex(i), face);
    }

    // 2. Register Mandatory Attribute: POSITION
    draco::GeometryAttribute posAttr;
    posAttr.Init(draco::GeometryAttribute::POSITION, nullptr, 3, draco::DT_FLOAT32, false, sizeof(float) * 3, 0);
    result.posAttrId = dracoMesh.AddAttribute(posAttr, true, numPoints);

    // 3. Register Optional Attribute: NORMAL
    if (primitive.normals.has_value()) {
        draco::GeometryAttribute normalAttr;
        normalAttr.Init(draco::GeometryAttribute::NORMAL, nullptr, 3, draco::DT_FLOAT32, false, sizeof(float) * 3, 0);
        result.normalAttrId = dracoMesh.AddAttribute(normalAttr, true, numPoints);
    }

    // 4. Register Optional Attribute: UV (TEXCOORD)
    if (primitive.uvs.has_value()) {
        draco::GeometryAttribute uvAttr;
        uvAttr.Init(draco::GeometryAttribute::TEX_COORD, nullptr, 2, draco::DT_FLOAT32, false, sizeof(float) * 2, 0);
        result.uvAttrId = dracoMesh.AddAttribute(uvAttr, true, numPoints);
    }

    // 5. Register Optional Attribute: FEATURE IDs (GENERIC)
    // Using DT_UINT16: glTF spec forbids UNSIGNED_INT for attributes.
    // UINT16 supports 65,535 unique IDs per primitive, which is sufficient
    // for any single mesh primitive. Overflow is clamped with a warning.
    bool hasFeatureIds = primitive.featureIds.has_value();
    if (hasFeatureIds) {
        draco::GeometryAttribute idAttr;
        idAttr.Init(draco::GeometryAttribute::GENERIC, nullptr, 1, draco::DT_UINT16, false, sizeof(uint16_t), 0);
        result.featureIdAttrId = dracoMesh.AddAttribute(idAttr, true, numPoints);
    }

    // 6. Fill Attribute Values with EXPLICIT Point Mapping
    for (size_t i = 0; i < numPoints; ++i) {
        draco::AttributeValueIndex avi(i);
        draco::PointIndex pi(i);

        // Position
        dracoMesh.attribute(result.posAttrId)->SetAttributeValue(avi, &primitive.positions[i * 3]);
        dracoMesh.attribute(result.posAttrId)->SetPointMapEntry(pi, avi);

        // Normal
        if (primitive.normals.has_value()) {
            dracoMesh.attribute(result.normalAttrId)->SetAttributeValue(avi, &primitive.normals.value()[i * 3]);
            dracoMesh.attribute(result.normalAttrId)->SetPointMapEntry(pi, avi);
        }

        // UV
        if (primitive.uvs.has_value()) {
            dracoMesh.attribute(result.uvAttrId)->SetAttributeValue(avi, &primitive.uvs.value()[i * 2]);
            dracoMesh.attribute(result.uvAttrId)->SetPointMapEntry(pi, avi);
        }

        // Feature ID - Lossless UINT16 with safety clamp
        if (hasFeatureIds) {
            uint32_t rawId = primitive.featureIds.value()[i];
            if (rawId > std::numeric_limits<uint16_t>::max()) {
                static bool warned = false;
                if (!warned) {
                    std::cerr << ">> [DRACO WARNING] Feature ID " << rawId 
                              << " exceeds UINT16 max (65535). Clamping to 65535.\n";
                    warned = true;
                }
                rawId = std::numeric_limits<uint16_t>::max();
            }
            uint16_t featureIdVal = static_cast<uint16_t>(rawId);
            dracoMesh.attribute(result.featureIdAttrId)->SetAttributeValue(avi, &featureIdVal);
            dracoMesh.attribute(result.featureIdAttrId)->SetPointMapEntry(pi, avi);
        }
    }

    // 7. Configure Encoder
    draco::Encoder encoder;
    encoder.SetSpeedOptions(config.speed, config.speed);
    encoder.SetAttributeQuantization(draco::GeometryAttribute::POSITION, config.posQuantization);

    if (primitive.uvs.has_value()) {
        encoder.SetAttributeQuantization(draco::GeometryAttribute::TEX_COORD, config.uvQuantization);
    }
    if (primitive.normals.has_value()) {
        encoder.SetAttributeQuantization(draco::GeometryAttribute::NORMAL, config.normalQuantization);
    }

    // CRITICAL FIX: Do NOT quantize GENERIC (Feature ID) attributes.
    // Quantization is lossy and designed for continuous spatial data.
    // Feature IDs are discrete categorical values and MUST be lossless.
    // Draco will encode UINT16 generically without quantization when this is omitted.

    draco::EncoderBuffer dracoBuffer;
    draco::Status status = encoder.EncodeMeshToBuffer(dracoMesh, &dracoBuffer);

    if (!status.ok()) {
        result.success = false;
        result.errorMessage = status.error_msg_string();
        return result;
    }

    result.compressedBytes.assign(dracoBuffer.data(), dracoBuffer.data() + dracoBuffer.size());
    result.success = true;
    return result;
}