#include "DracoCompressor.h"
#include <draco/compression/encode.h>
#include <draco/mesh/mesh.h>
#include <draco/attributes/point_attribute.h>

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
    if (primitive.featureIds.has_value()) {
        draco::GeometryAttribute idAttr;
        // Map as a generic custom attribute. The GLTF packager will map this to _FEATURE_ID_0
        idAttr.Init(draco::GeometryAttribute::GENERIC, nullptr, 1,
                    draco::DT_FLOAT32, false, sizeof(float), 0);
        result.featureIdAttrId = dracoMesh.AddAttribute(idAttr, true, numPoints);
    }

    // 6. Register Optional Attribute: COLOR (COLOR_0)
    if (primitive.colors.has_value()) {
        draco::GeometryAttribute colorAttr;
        colorAttr.Init(draco::GeometryAttribute::COLOR, nullptr, 4,
                       draco::DT_FLOAT32, false, sizeof(float) * 4, 0);
        result.colorAttrId = dracoMesh.AddAttribute(colorAttr, true, numPoints);
    }

    // 7. Fill Attribute Values Safely
    for (size_t i = 0; i < numPoints; ++i) {
        dracoMesh.attribute(result.posAttrId)->SetAttributeValue(
            draco::AttributeValueIndex(i), &primitive.positions[i * 3]);
         
        if (primitive.normals.has_value()) {
            dracoMesh.attribute(result.normalAttrId)->SetAttributeValue(
                draco::AttributeValueIndex(i), &primitive.normals.value()[i * 3]);
        }

        if (primitive.uvs.has_value()) {
            dracoMesh.attribute(result.uvAttrId)->SetAttributeValue(
                draco::AttributeValueIndex(i), &primitive.uvs.value()[i * 2]);
        }

        if (primitive.featureIds.has_value()) {
            dracoMesh.attribute(result.featureIdAttrId)->SetAttributeValue(
                draco::AttributeValueIndex(i), &primitive.featureIds.value()[i]);
        }

        if (primitive.colors.has_value()) {
            dracoMesh.attribute(result.colorAttrId)->SetAttributeValue(
                draco::AttributeValueIndex(i), &primitive.colors.value()[i * 4]);
        }
    }

    // 8. Configure & Run Encoder
    draco::Encoder encoder;
    encoder.SetSpeedOptions(config.speed, config.speed);
    encoder.SetAttributeQuantization(draco::GeometryAttribute::POSITION, config.posQuantization);
    
    if (primitive.uvs.has_value()) {
        encoder.SetAttributeQuantization(draco::GeometryAttribute::TEX_COORD, config.uvQuantization);
    }
    if (primitive.normals.has_value()) {
        encoder.SetAttributeQuantization(draco::GeometryAttribute::NORMAL, config.normalQuantization);
    }
    if (primitive.colors.has_value()) {
        encoder.SetAttributeQuantization(draco::GeometryAttribute::COLOR, config.colorQuantization);
    }
    // Feature IDs are floats only because glTF restricts vertex component
    // types. Do not quantize them: picking requires exact integral values.

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
