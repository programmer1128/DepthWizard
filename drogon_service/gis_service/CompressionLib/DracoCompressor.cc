#include "DracoCompressor.h"
#include <draco/compression/encode.h>
#include <draco/mesh/mesh.h>
#include <draco/attributes/point_attribute.h>

DracoCompressionResult DracoCompressor::compressGeometry(const std::vector<float>& positions,
     const std::vector<uint32_t>& indices,
     const std::vector<float>& uvs,
     int posQuantization,
     int uvQuantization,
     int speed)
{
     DracoCompressionResult result;
     draco::Mesh dracoMesh;

     size_t numFaces = indices.size() / 3;
     size_t numPoints = positions.size() / 3;
     
     dracoMesh.SetNumFaces(numFaces);
     dracoMesh.set_num_points(numPoints); //Explicitly define point capacity

     // Populate Faces
     for (size_t i = 0; i < numFaces; ++i) 
     {
         draco::Mesh::Face face;
         //Enforce Draco strict PointIndex casting
         face[0] = draco::PointIndex(indices[i * 3 + 0]);
         face[1] = draco::PointIndex(indices[i * 3 + 1]);
         face[2] = draco::PointIndex(indices[i * 3 + 2]);
         dracoMesh.SetFace(draco::FaceIndex(i), face);
     }

     // Register Position Attribute
     draco::GeometryAttribute posAttr;
     posAttr.Init(draco::GeometryAttribute::POSITION, nullptr, 3, draco::DT_FLOAT32, false, sizeof(float) * 3, 0);
     result.posAttrId = dracoMesh.AddAttribute(posAttr, true, numPoints);

     // Register UV Attribute
     draco::GeometryAttribute uvAttr;
     uvAttr.Init(draco::GeometryAttribute::TEX_COORD, nullptr, 2, draco::DT_FLOAT32, false, sizeof(float) * 2, 0);
     result.uvAttrId = dracoMesh.AddAttribute(uvAttr, true, numPoints); // Simplified using numPoints

     // Fill Attribute Values
     for (size_t i = 0; i < numPoints; ++i) 
     {
         dracoMesh.attribute(result.posAttrId)->SetAttributeValue(draco::AttributeValueIndex(i), &positions[i * 3]);
         dracoMesh.attribute(result.uvAttrId)->SetAttributeValue(draco::AttributeValueIndex(i), &uvs[i * 2]);
     }

     // Configure & Run Encoder
     draco::Encoder encoder;
     encoder.SetSpeedOptions(speed, speed);
     encoder.SetAttributeQuantization(draco::GeometryAttribute::POSITION, posQuantization);
     encoder.SetAttributeQuantization(draco::GeometryAttribute::TEX_COORD, uvQuantization);

     draco::EncoderBuffer dracoBuffer;
     draco::Status status = encoder.EncodeMeshToBuffer(dracoMesh, &dracoBuffer);

     if (!status.ok()) 
     {
         result.success = false;
         result.errorMessage = status.error_msg_string();
         return result;
     }

     // Copy bitstream out
     result.compressedBytes.assign(dracoBuffer.data(), dracoBuffer.data() + dracoBuffer.size());
     result.success = true;
     return result;
}