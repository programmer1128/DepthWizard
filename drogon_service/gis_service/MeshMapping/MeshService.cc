#include "MeshService.h"
#include <iostream>
#include <cstring>

#define TINYGLTF_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "tiny_gltf.h"

bool GlbMesher::generateGlb(
     const std::string& outputPath, 
     const std::vector<float>& dsm_matrix, 
     int width, 
     int height,
     float pixel_size) 
{    
     std::vector<float> positions;
     std::vector<uint32_t> indices;

     // Pre-allocate memory for geometry only
     positions.reserve(width * height * 3);
     indices.reserve((width - 1) * (height - 1) * 6);

     //generating vertices x,y,z
     for (int y=0;y<height;y++) 
     {
         for (int x=0;x<width;x++) 
         {
             //the entire matrix is in 1d flat form. so we need 1d index acc to x and y
             float elevation = dsm_matrix[y * width + x];
             positions.push_back(x * pixel_size); // X
             positions.push_back(elevation); // Y (Up)
             positions.push_back(y * pixel_size); // Z
         }
     }

     //generating triangle indices
     for (int y=0;y<height-1;y++) 
     {
         for(int x=0;x<width-1;x++) 
         {   
             uint32_t v0=y*width+x;
             uint32_t v1=y*width+(x + 1);
             uint32_t v2=(y+1)*width + x;
             uint32_t v3=(y+1)*width+(x + 1);
             // Triangle 1
             indices.push_back(v0);
             indices.push_back(v2);
             indices.push_back(v1);
             // Triangle 2
             indices.push_back(v1);
             indices.push_back(v2);
             indices.push_back(v3);
         }
     }

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
     return success;
}