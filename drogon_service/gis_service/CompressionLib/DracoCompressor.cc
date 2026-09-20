// implements Draco compression dynamically checking for optional UVs and Normals

#include "DracoCompressor.h"
#include <draco/compression/encode.h>
#include <draco/mesh/mesh.h>
#include <draco/attributes/point_attribute.h>

DracoCompressionResult DracoCompressor::compress(const MeshPrimitive& primitive, int speed)
{
    DracoCompressionResult result;
    draco::Mesh dracoMesh;

    // basic validation
    if (!primitive.isValid() || primitive.indices.empty() || primitive.positions.empty()) 
    {
        result.success = false;
        result.errorMessage = "Invalid MeshPrimitive provided for compression";
        return result;
    }

    size_t numFaces = primitive.indices.size() / 3;
    size_t numPoints = primitive.positions.size() / 3;
    
    dracoMesh.SetNumFaces(numFaces);
    dracoMesh.set_num_points(numPoints); 

    // populate triangle connectivity (faces)
    for (size_t i = 0; i < numFaces; ++i) 
    {
        draco::Mesh::Face face;
        face[0] = draco::PointIndex(primitive.indices[i * 3 + 0]);
        face[1] = draco::PointIndex(primitive.indices[i * 3 + 1]);
        face[2] = draco::PointIndex(primitive.indices[i * 3 + 2]);
        dracoMesh.SetFace(draco::FaceIndex(i), face);
    }

    // register and fill Position Attribute (mandatory)
    draco::GeometryAttribute posAttr;
    posAttr.Init(draco::GeometryAttribute::POSITION, nullptr, 3, draco::DT_FLOAT32, false, sizeof(float) * 3, 0);
    result.posAttrId = dracoMesh.AddAttribute(posAttr, true, numPoints);

    for (size_t i = 0; i < numPoints; ++i) 
    {
        dracoMesh.attribute(result.posAttrId)->SetAttributeValue(
            draco::AttributeValueIndex(i), &primitive.positions[i * 3]);
    }

    // register and fill UV Attribute (Optional - building walls might not have them)
    if (primitive.uvs.has_value() && !primitive.uvs->empty()) 
    {
        draco::GeometryAttribute uvAttr;
        uvAttr.Init(draco::GeometryAttribute::TEX_COORD, nullptr, 2, draco::DT_FLOAT32, false, sizeof(float) * 2, 0);
        result.uvAttrId = dracoMesh.AddAttribute(uvAttr, true, numPoints);
        
        const auto& uvs = primitive.uvs.value();
        for (size_t i = 0; i < numPoints; ++i) 
        {
            dracoMesh.attribute(result.uvAttrId)->SetAttributeValue(
                draco::AttributeValueIndex(i), &uvs[i * 2]);
        }
    }

    // register and fill Normal Attribute (Optional but highly recommended)
    if (primitive.normals.has_value() && !primitive.normals->empty()) 
    {
        draco::GeometryAttribute normalAttr;
        normalAttr.Init(draco::GeometryAttribute::NORMAL, nullptr, 3, draco::DT_FLOAT32, false, sizeof(float) * 3, 0);
        result.normalAttrId = dracoMesh.AddAttribute(normalAttr, true, numPoints);

        const auto& normals = primitive.normals.value();
        for (size_t i = 0; i < numPoints; ++i) 
        {
            dracoMesh.attribute(result.normalAttrId)->SetAttributeValue(
                draco::AttributeValueIndex(i), &normals[i * 3]);
        }
    }

    // configure the Encoder
    draco::Encoder encoder;
    encoder.SetSpeedOptions(speed, speed);
    encoder.SetAttributeQuantization(draco::GeometryAttribute::POSITION, 16);
    encoder.SetAttributeQuantization(draco::GeometryAttribute::TEX_COORD, 12);
    encoder.SetAttributeQuantization(draco::GeometryAttribute::NORMAL, 10);

    draco::EncoderBuffer dracoBuffer;
    draco::Status status = encoder.EncodeMeshToBuffer(dracoMesh, &dracoBuffer);

    if (!status.ok()) 
    {
        result.success = false;
        result.errorMessage = status.error_msg_string();
        return result;
    }

    // copy out the compressed bitstream safely
    result.compressedBytes.assign(dracoBuffer.data(), dracoBuffer.data() + dracoBuffer.size());
    result.success = true;
    return result;
}

// retain the existing generic method for backward compatibility
DracoCompressionResult DracoCompressor::compressGeometry(
    const std::vector<float>& positions, const std::vector<uint32_t>& indices,
    const std::vector<float>& uvs, const std::vector<float>& normals,
    int posQuantization, int uvQuantization, int normalQuantization, int speed)
{
    MeshPrimitive prim;
    prim.positions = positions;
    prim.indices = indices;
    if (!uvs.empty()) prim.uvs = uvs;
    if (!normals.empty()) prim.normals = normals;
    return compress(prim, speed);
}