#include "MeshService.h"
#include "../UVMapping/UVMapping.h"
#include "../FileGenerators/GltfPackager.h"
#include <iostream>
#include <cstring>
#include <limits>
#include "tiny_gltf.h"

bool GlbMesher::generateGlb(
     const std::string& outputPath, 
     const std::vector<float>& dsm_matrix, 
     int width, 
     int height,
     float pixel_size,const char* imgData,
     size_t imgLength) 
{    
     std::vector<float> positions;
     std::vector<uint32_t> indices;

     //Pre-allocate memory for geometry only
     positions.resize(width * height * 3);
     indices.resize((width - 1) * (height - 1) * 6);

     float* pos_ptr = positions.data();
     uint32_t* ind_ptr = indices.data();

     size_t pos_idx = 0;
     size_t ind_idx = 0;

     double minX = std::numeric_limits<double>::max();
     double minY = std::numeric_limits<double>::max();
     double minZ = std::numeric_limits<double>::max();
     
     double maxX = std::numeric_limits<double>::lowest();
     double maxY = std::numeric_limits<double>::lowest();
     double maxZ = std::numeric_limits<double>::lowest();

     //generating vertices x,y,z
     for (int y = 0; y < height; ++y) 
     {
         for (int x = 0; x < width; ++x) 
         {
             float elevation = dsm_matrix[y * width + x];
             float px = x * pixel_size;
             float pz = y * pixel_size;

             pos_ptr[pos_idx++] = px; 
             pos_ptr[pos_idx++] = elevation;      
             pos_ptr[pos_idx++] = pz; 

             // Continuously update the bounding box
             if (px < minX) 
             {
                 minX = px;
             }
             if (elevation < minY) 
             {
                 minY = elevation;
             }
             if (pz < minZ) 
             {
                 minZ = pz;
             }
             
             if (px > maxX) 
             {
                 maxX = px;
             }
             if (elevation > maxY) 
             {
                 maxY = elevation;
             }
             if (pz > maxZ) 
             {
                 maxZ = pz;
             }
         }
     }

     //Generating triangle indices via pointers
     for (int y = 0; y < height - 1; ++y) 
     {
         for(int x = 0; x < width - 1; ++x) 
         {   
             uint32_t v0 = y * width + x;
             uint32_t v1 = y * width + (x + 1);
             uint32_t v2 = (y + 1) * width + x;
             uint32_t v3 = (y + 1) * width + (x + 1);
             
             ind_ptr[ind_idx++] = v0;
             ind_ptr[ind_idx++] = v2;
             ind_ptr[ind_idx++] = v1;
             
             ind_ptr[ind_idx++] = v1;
             ind_ptr[ind_idx++] = v2;
             ind_ptr[ind_idx++] = v3;
         }
     }

     // Generate UV Map mathematically
     std::vector<float> uvs = UVMapping::generateUV(width, height);

     // Package the bounds array for the struct
     double bounds[6] = { minX, minY, minZ, maxX, maxY, maxZ };

     // Delegate binary generation to the Packager
     return GltfPackager::buildAndSave(
         outputPath, 
         positions, 
         indices, 
         uvs, 
         bounds, 
         imgData, 
         imgLength
     );

}



/*
//discarded logic for the GLTF writer
//formatting to binary buffers of tinygltf to save as .glb
     tinygltf::Model model;
     tinygltf::Buffer mainBuffer;

     size_t posBytes = positions.size() * sizeof(float);
     size_t indBytes = indices.size() * sizeof(uint32_t);

     mainBuffer.data.resize(posBytes + indBytes);
    
     size_t offset = 0;
    
     // Copy Vertices
     std::memcpy(mainBuffer.data.data() + offset, positions.data(), posBytes);
     size_t posOffset = offset;
     offset += posBytes;

     // Copy Indices
     std::memcpy(mainBuffer.data.data() + offset, indices.data(), indBytes);
     size_t indOffset = offset;

     model.buffers.push_back(mainBuffer);

     tinygltf::BufferView posView, indView;
    
     posView.buffer = 0; posView.byteOffset = posOffset; posView.byteLength = posBytes; 
     posView.target = TINYGLTF_TARGET_ARRAY_BUFFER;
    
     indView.buffer = 0; indView.byteOffset = indOffset; indView.byteLength = indBytes; 
     indView.target = TINYGLTF_TARGET_ELEMENT_ARRAY_BUFFER;

     model.bufferViews.push_back(posView);
     model.bufferViews.push_back(indView);

    
     tinygltf::Accessor posAccessor, indAccessor;
    
     posAccessor.bufferView = 0; posAccessor.byteOffset = 0;
     posAccessor.componentType = TINYGLTF_COMPONENT_TYPE_FLOAT;
     posAccessor.count = positions.size() / 3;
     posAccessor.type = TINYGLTF_TYPE_VEC3;

     //bounding box meta data
     posAccessor.minValues = { minX, minY, minZ };
     posAccessor.maxValues = { maxX, maxY, maxZ };

     indAccessor.bufferView = 1; indAccessor.byteOffset = 0;
     indAccessor.componentType = TINYGLTF_COMPONENT_TYPE_UNSIGNED_INT;
     indAccessor.count = indices.size();
     indAccessor.type = TINYGLTF_TYPE_SCALAR;

     model.accessors.push_back(posAccessor);
     model.accessors.push_back(indAccessor);

     tinygltf::Primitive primitive;

     primitive.attributes["POSITION"] = 0; 
     primitive.indices = 1;
     primitive.mode = TINYGLTF_MODE_TRIANGLES;

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

     tinygltf::TinyGLTF gltfContext;
    
     bool success = gltfContext.WriteGltfSceneToFile(&model, outputPath, false, false, false, true);
    
     if (!success) 
     {
         std::cerr << "Failed to write geometry-only GLB file to: " << outputPath << std::endl;
     }
     return success;*/