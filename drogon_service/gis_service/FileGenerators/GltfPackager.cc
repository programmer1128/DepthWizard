//This file is for the generation of the .glb file for the fast rendering on frontend
#include "GltfPackager.h"
#include <iostream>
#include <cstring>
#include <sstream>

// Only define these if not defined elsewhere in your project
#define TINYGLTF_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "tiny_gltf.h"

//draco compression implemented GLTF packager
std::vector<uint8_t> GltfPackager::buildToMemory(
      const DracoCompressionResult& dracoResult,
      size_t numVertices,
      size_t numIndices,
      const double bounds[6], 
      const char* imgData,
      size_t imgLength)
{
      if (!dracoResult.success) 
      {
          throw std::runtime_error("Cannot package GLTF: Draco compression failed.");
      }

      tinygltf::Model model;

      //Register Draco Extensions Globally
      model.extensionsUsed.push_back("KHR_draco_mesh_compression");
      model.extensionsRequired.push_back("KHR_draco_mesh_compression");

      //Buffer Memory Alignment (CRITICAL for Unity glTFast)
      size_t dracoBytes = dracoResult.compressedBytes.size();
      size_t padding = (4 - (dracoBytes % 4)) % 4; // Ensure 4-byte boundary
      size_t paddedDracoBytes = dracoBytes + padding;

      // Calculate terminal padding for the final chunk length
      size_t totalBytes = paddedDracoBytes + imgLength;
      size_t finalPadding = (4 - (totalBytes % 4)) % 4;

      //Allocate Single Buffer (Draco + Padding + Image + Terminal Padding)
      tinygltf::Buffer mainBuffer;
      mainBuffer.data.resize(totalBytes + finalPadding);
      
     
      // Copy Draco bitstream
      std::memcpy(mainBuffer.data.data(), dracoResult.compressedBytes.data(), dracoBytes);
     
      // Pad with zeroes (if necessary)
      if (padding > 0) 
      {
          std::memset(mainBuffer.data.data() + dracoBytes, 0, padding);
      }

      // Copy Image Data
      std::memcpy(mainBuffer.data.data() + paddedDracoBytes, imgData, imgLength);

      // Pad the very end of the BIN chunk with zeroes (if necessary)
      if (finalPadding > 0) 
      {
          std::memset(mainBuffer.data.data() + totalBytes, 0, finalPadding);
      }

      model.buffers.push_back(mainBuffer);
      //Buffer Views
      tinygltf::BufferView dracoView, imgView;
    
      dracoView.buffer = 0; 
      dracoView.byteOffset = 0; 
      dracoView.byteLength = dracoBytes; // The actual unpadded size
     
      imgView.buffer = 0; 
      imgView.byteOffset = paddedDracoBytes; 
      imgView.byteLength = imgLength;
    
      model.bufferViews.push_back(dracoView); // Index 0
      model.bufferViews.push_back(imgView);   // Index 1

      // Accessors (Orphaned from BufferViews for Draco)
      tinygltf::Accessor posAccessor, indAccessor, uvAccessor;
    
      // By setting bufferView to -1, we tell TinyGLTF to omit the JSON property,
      // which is strictly required by the KHR_draco_mesh_compression specification.
      posAccessor.bufferView = -1; 
      posAccessor.byteOffset = 0;
      posAccessor.componentType = TINYGLTF_COMPONENT_TYPE_FLOAT;
      posAccessor.count = numVertices;
      posAccessor.type = TINYGLTF_TYPE_VEC3;
      posAccessor.minValues = { bounds[0], bounds[1], bounds[2] };
      posAccessor.maxValues = { bounds[3], bounds[4], bounds[5] };

      indAccessor.bufferView = -1; 
      indAccessor.byteOffset = 0;
      indAccessor.componentType = TINYGLTF_COMPONENT_TYPE_UNSIGNED_INT;
      indAccessor.count = numIndices;
      indAccessor.type = TINYGLTF_TYPE_SCALAR;

      uvAccessor.bufferView = -1; 
      uvAccessor.byteOffset = 0;
      uvAccessor.componentType = TINYGLTF_COMPONENT_TYPE_FLOAT;
      uvAccessor.count = numVertices;
      uvAccessor.type = TINYGLTF_TYPE_VEC2;

      model.accessors.push_back(posAccessor); // Index 0
      model.accessors.push_back(indAccessor); // Index 1
      model.accessors.push_back(uvAccessor);  // Index 2

      //Image & Material Construction
      tinygltf::Image image;
      image.bufferView = 1; // Point to the image buffer view
      std::string detectedMime = "image/jpeg";
      const unsigned char* uImg = reinterpret_cast<const unsigned char*>(imgData);
      if (imgLength >= 4 && uImg[0] == 0x89 && uImg[1] == 0x50 && uImg[2] == 0x4E && uImg[3] == 0x47) 
      {
          detectedMime = "image/png";
      }

      //Image & Material Construction
      image.uri = "";       //  bypass TinyGLTF URI resolution bugs
      image.mimeType = detectedMime; 
      model.images.push_back(image); 
      tinygltf::Texture texture;
      texture.source = 0;
      model.textures.push_back(texture);

      tinygltf::Material material;
      material.pbrMetallicRoughness.baseColorTexture.index = 0;
      material.pbrMetallicRoughness.metallicFactor = 0.0;
      material.pbrMetallicRoughness.roughnessFactor = 1.0;
      model.materials.push_back(material);

      //The Mesh Primitive & Draco Extension Injection
      tinygltf::Primitive primitive;
      primitive.attributes["POSITION"] = 0; 
      primitive.attributes["TEXCOORD_0"] = 2; 
      primitive.indices = 1;
      primitive.material = 0; 
      primitive.mode = TINYGLTF_MODE_TRIANGLES;

      // Inject the KHR_draco_mesh_compression JSON metadata
      tinygltf::Value::Object dracoExt;
      dracoExt["bufferView"] = tinygltf::Value(0); // Points to the Draco BufferView
     
      tinygltf::Value::Object dracoAttrs;
      dracoAttrs["POSITION"] = tinygltf::Value(dracoResult.posAttrId);
      dracoAttrs["TEXCOORD_0"] = tinygltf::Value(dracoResult.uvAttrId);
      dracoExt["attributes"] = tinygltf::Value(dracoAttrs);

      primitive.extensions["KHR_draco_mesh_compression"] = tinygltf::Value(dracoExt);

      tinygltf::Mesh mesh;
      mesh.primitives.push_back(primitive);
      model.meshes.push_back(mesh);

      tinygltf::Node node;
      node.mesh = 0;
      model.nodes.push_back(node);

      tinygltf::Scene scene;
      scene.nodes.push_back(0);
      model.scenes.push_back(scene);
      model.defaultScene = 0;

      // Write to In-Memory Stream, then convert to Vector
      tinygltf::TinyGLTF gltfContext;
     
      // Initialize a binary string stream
      std::stringstream stream(std::ios_base::out | std::ios_base::binary);
     
      // Signature: WriteGltfSceneToStream(Model* model, std::ostream& stream, bool prettyPrint, bool writeBinary)
      bool success = gltfContext.WriteGltfSceneToStream(&model, stream, false, true);
      
      if (!success) 
      {
          throw std::runtime_error("Failed to serialize GLTF to memory.");
      }

      // Convert the stream's buffer directly to a uint8_t vector for MinIO
      std::string streamStr = stream.str();
      return std::vector<uint8_t>(streamStr.begin(), streamStr.end());
}

// 

// #include "GltfPackager.h"
// #include <iostream>
// #include <cstring>
// #define TINYGLTF_IMPLEMENTATION
// #define STB_IMAGE_IMPLEMENTATION
// #define STB_IMAGE_WRITE_IMPLEMENTATION
// #include "tiny_gltf.h"

// bool GltfPackager::buildAndSave(const std::string& outputPath,const std::vector<float>& positions,
//      const std::vector<uint32_t>& indices,
//      const std::vector<float>& uvs,
//      const double bounds[6], 
//      const char* imgData,
//      size_t imgLength)
// {
//      tinygltf::Model model;
//      tinygltf::Buffer mainBuffer;

//      //calculate byte sizes
//      size_t posBytes = positions.size() * sizeof(float);
//      size_t indBytes = indices.size() * sizeof(uint32_t);
//      size_t uvBytes = uvs.size() * sizeof(float);
//      size_t imgBytes = imgLength;

//      //allocate memory for geometry and the image texture
//      mainBuffer.data.resize(posBytes + indBytes + uvBytes + imgBytes);
    
//      size_t offset = 0;
    
//      //copy Vertices
//      std::memcpy(mainBuffer.data.data() + offset, positions.data(), posBytes);
//      size_t posOffset = offset;
//      offset += posBytes;

//      //copy Indices
//      std::memcpy(mainBuffer.data.data() + offset, indices.data(), indBytes);
//      size_t indOffset = offset;
//      offset += indBytes;

//      //copy UVs
//      std::memcpy(mainBuffer.data.data() + offset, uvs.data(), uvBytes);
//      size_t uvOffset = offset;
//      offset += uvBytes;

//      //copy Raw Image Bytes directly into the GLB buffer
//      std::memcpy(mainBuffer.data.data() + offset, imgData, imgBytes);
//      size_t imgOffset = offset;

//      model.buffers.push_back(mainBuffer);

//      //Buffer Views
//      tinygltf::BufferView posView, indView, uvView, imgView;
    
//      posView.buffer = 0; posView.byteOffset = posOffset; posView.byteLength = posBytes; 
//      posView.target = TINYGLTF_TARGET_ARRAY_BUFFER;
    
//      indView.buffer = 0; indView.byteOffset = indOffset; indView.byteLength = indBytes; 
//      indView.target = TINYGLTF_TARGET_ELEMENT_ARRAY_BUFFER;

//      uvView.buffer = 0; uvView.byteOffset = uvOffset; uvView.byteLength = uvBytes; 
//      uvView.target = TINYGLTF_TARGET_ARRAY_BUFFER;

//      imgView.buffer = 0; imgView.byteOffset = imgOffset; imgView.byteLength = imgBytes;
    
//      model.bufferViews.push_back(posView);
//      model.bufferViews.push_back(indView);
//      model.bufferViews.push_back(uvView);
//      model.bufferViews.push_back(imgView);

//      //Accessors
//      tinygltf::Accessor posAccessor, indAccessor, uvAccessor;
    
//      posAccessor.bufferView = 0; posAccessor.byteOffset = 0;
//      posAccessor.componentType = TINYGLTF_COMPONENT_TYPE_FLOAT;
//      posAccessor.count = positions.size() / 3;
//      posAccessor.type = TINYGLTF_TYPE_VEC3;
//      posAccessor.minValues = { bounds[0], bounds[1], bounds[2] };
//      posAccessor.maxValues = { bounds[3], bounds[4], bounds[5] };

//      indAccessor.bufferView = 1; indAccessor.byteOffset = 0;
//      indAccessor.componentType = TINYGLTF_COMPONENT_TYPE_UNSIGNED_INT;
//      indAccessor.count = indices.size();
//      indAccessor.type = TINYGLTF_TYPE_SCALAR;

//      uvAccessor.bufferView = 2; uvAccessor.byteOffset = 0;
//      uvAccessor.componentType = TINYGLTF_COMPONENT_TYPE_FLOAT;
//      uvAccessor.count = uvs.size() / 2;
//      uvAccessor.type = TINYGLTF_TYPE_VEC2;

//      model.accessors.push_back(posAccessor);
//      model.accessors.push_back(indAccessor);
//      model.accessors.push_back(uvAccessor);

//      //Image, Texture, and Material Construction
//      tinygltf::Image image;
//      image.bufferView = 3; 
//      image.mimeType = "image/jpeg"; // Note: Web viewers require JPEG or PNG, not TIFF.
//      model.images.push_back(image);

//      tinygltf::Texture texture;
//      texture.source = 0; // Point to image 0
//      model.textures.push_back(texture);

//      tinygltf::Material material;
//      material.pbrMetallicRoughness.baseColorTexture.index = 0; // Bind texture to base color
//      material.pbrMetallicRoughness.metallicFactor = 0.0; // Matte look for terrain
//      material.pbrMetallicRoughness.roughnessFactor = 1.0;
//      model.materials.push_back(material);

//      //Mesh & Node Assembly
//      tinygltf::Primitive primitive;
//      primitive.attributes["POSITION"] = 0; 
//      primitive.attributes["TEXCOORD_0"] = 2; // Bind the UV Accessor
//      primitive.indices = 1;
//      primitive.material = 0; // Bind the Material
//      primitive.mode = TINYGLTF_MODE_TRIANGLES;

//      tinygltf::Mesh mesh;
//      mesh.primitives.push_back(primitive);
//      model.meshes.push_back(mesh);

//      tinygltf::Node node;
//      node.mesh = 0;
//      model.nodes.push_back(node);

//      tinygltf::Scene scene;
//      scene.nodes.push_back(0);
//      model.scenes.push_back(scene);
//      model.defaultScene = 0;

//      tinygltf::TinyGLTF gltfContext;
//      return gltfContext.WriteGltfSceneToFile(&model, outputPath, false, false, false, true);
// }