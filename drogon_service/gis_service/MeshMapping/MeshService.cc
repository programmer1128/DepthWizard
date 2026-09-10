#include "MeshService.h"
#include "../UVMapping/UVMapping.h"
#include "../FileGenerators/GltfPackager.h"
#include <iostream>
#include <cstring>
#include <limits>
#include "tiny_gltf.h"

std::vector<uint8_t> GlbMesher::generateGlb(
     const std::vector<float>& dsm_matrix, 
     int width, 
     int height,
     float pixel_size,const char* imgData,
     size_t imgLength) 
{
     // ==========================================
     // 1. DYNAMIC DECIMATION (STRIDE)
     // ==========================================
     int max_grid_size = 512;
     int stride = 1;
     
     if (width > max_grid_size || height > max_grid_size) 
    {
        // Adding (denominator - 1) forces integer division to act like std::ceil()
        int stride_x = (width + max_grid_size - 1) / max_grid_size;
        int stride_y = (height + max_grid_size - 1) / max_grid_size;
        
        stride = std::max(stride_x, stride_y);
    }

     // Calculate new downsampled geometry dimensions
     int grid_width = width / stride;
     int grid_height = height / stride;

     std::vector<float> positions;
     std::vector<uint32_t> indices;

     positions.resize(grid_width * grid_height * 3);
     indices.resize((grid_width - 1) * (grid_height - 1) * 6);

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

     float y_scale = 0.6f;

     // Generate decimated vertices
     for (int y = 0; y < grid_height; ++y) 
     {
         for (int x = 0; x < grid_width; ++x) 
         {
             // Sample the original high-resolution matrix using the stride
             int orig_x = x * stride;
             int orig_y = y * stride;
             float elevation = dsm_matrix[orig_y * width + orig_x];
             
             // Physical coordinates maintain their metric real-world scale
             float px = orig_x * pixel_size;
             float pz = orig_y * pixel_size;

             pos_ptr[pos_idx++] = px; 
             pos_ptr[pos_idx++] = elevation;      
             pos_ptr[pos_idx++] = pz; 

             if (px < minX) minX = px;
             if (elevation < minY) minY = elevation;
             if (pz < minZ) minZ = pz;
             
             if (px > maxX) maxX = px;
             if (elevation > maxY) maxY = elevation;
             if (pz > maxZ) maxZ = pz;
         }
     }

     // Generate triangle indices
     for (int y = 0; y < grid_height - 1; ++y) 
     {
         for(int x = 0; x < grid_width - 1; ++x) 
         {   
             uint32_t v0 = y * grid_width + x;
             uint32_t v1 = y * grid_width + (x + 1);
             uint32_t v2 = (y + 1) * grid_width + x;
             uint32_t v3 = (y + 1) * grid_width + (x + 1);
             
             ind_ptr[ind_idx++] = v0;
             ind_ptr[ind_idx++] = v2;
             ind_ptr[ind_idx++] = v1;
             
             ind_ptr[ind_idx++] = v1;
             ind_ptr[ind_idx++] = v2;
             ind_ptr[ind_idx++] = v3;
         }
     }

     // Find lowest elevation for the base
     float y_min = positions[1]; 
     for (size_t i = 1; i < positions.size(); i += 3) 
     {
         if (positions[i] < y_min) y_min = positions[i];
     }

     float y_base = y_min - 50.0f; 

     float min_x = positions[0];
     float min_z = positions[2];
     float max_x = positions[((grid_width * grid_height) - 1) * 3];
     float max_z = positions[((grid_width * grid_height) - 1) * 3 + 2];
     float center_x = (min_x + max_x) / 2.0f;
     float center_z = (min_z + max_z) / 2.0f; 

     // Generate UV map for the downsampled grid size
     std::vector<float> uvs = UVMapping::generateUV(grid_width, grid_height);

     uint32_t v_center_base = positions.size() / 3;
     positions.push_back(center_x);
     positions.push_back(y_base);     
     positions.push_back(center_z);
     
     uvs.push_back(0.5f); 
     uvs.push_back(0.5f);

     auto addSkirtEdge = [&](uint32_t v_top_current, uint32_t v_top_next)
     {
         uint32_t v_base_current = positions.size() / 3;
         positions.push_back(positions[v_top_current * 3]);     
         positions.push_back(y_base);                           
         positions.push_back(positions[v_top_current * 3 + 2]); 
         
         float u_curr = uvs[v_top_current * 2];
         float v_curr = uvs[v_top_current * 2 + 1];
         uvs.push_back(u_curr);
         uvs.push_back(v_curr);

         uint32_t v_base_next = positions.size() / 3;
         positions.push_back(positions[v_top_next * 3]);        
         positions.push_back(y_base);                           
         positions.push_back(positions[v_top_next * 3 + 2]);    
         
         float u_next = uvs[v_top_next * 2];
         float v_next = uvs[v_top_next * 2 + 1];
         uvs.push_back(u_next);
         uvs.push_back(v_next);

         indices.push_back(v_top_current);
         indices.push_back(v_base_current);
         indices.push_back(v_top_next);

         indices.push_back(v_top_next);
         indices.push_back(v_base_current);
         indices.push_back(v_base_next);

         indices.push_back(v_base_current);
         indices.push_back(v_center_base);
         indices.push_back(v_base_next);
     };
     
     for (int x = grid_width - 1; x > 0; --x) 
     {
         addSkirtEdge(x, x - 1);
     }
     for (int y = 0; y < grid_height - 1; ++y) 
     {
         addSkirtEdge(y * grid_width, (y + 1) * grid_width);
     }
     for (int x = 0; x < grid_width - 1; ++x) 
     {
         addSkirtEdge((grid_height - 1) * grid_width + x, (grid_height - 1) * grid_width + x + 1);
     }
     for (int y = grid_height - 1; y > 0; --y) 
     {
         addSkirtEdge(y * grid_width + (grid_width - 1), (y - 1) * grid_width + (grid_width - 1));
     }

     double bounds[6] = { minX, y_base, minZ, maxX, maxY, maxZ };

     // ==========================================
     // 2. NORMALS & HARD SHADING FOR SKIRTS
     // ==========================================
     std::vector<float> normals(positions.size(), 0.0f);

     for (size_t i = 0; i < indices.size(); i += 3) 
     {
         uint32_t i0 = indices[i];
         uint32_t i1 = indices[i+1];
         uint32_t i2 = indices[i+2];

         float v0x = positions[i0 * 3], v0y = positions[i0 * 3 + 1], v0z = positions[i0 * 3 + 2];
         float v1x = positions[i1 * 3], v1y = positions[i1 * 3 + 1], v1z = positions[i1 * 3 + 2];
         float v2x = positions[i2 * 3], v2y = positions[i2 * 3 + 1], v2z = positions[i2 * 3 + 2];

         float ux = v1x - v0x, uy = v1y - v0y, uz = v1z - v0z;
         float vx = v2x - v0x, vy = v2y - v0y, vz = v2z - v0z;

         float nx = uy * vz - uz * vy;
         float ny = uz * vx - ux * vz;
         float nz = ux * vy - uy * vx;

         normals[i0 * 3] += nx; normals[i0 * 3 + 1] += ny; normals[i0 * 3 + 2] += nz;
         normals[i1 * 3] += nx; normals[i1 * 3 + 1] += ny; normals[i1 * 3 + 2] += nz;
         normals[i2 * 3] += nx; normals[i2 * 3 + 1] += ny; normals[i2 * 3 + 2] += nz;
     }

     for (size_t i = 0; i < normals.size(); i += 3) 
     {
         float nx = normals[i], ny = normals[i+1], nz = normals[i+2];
         float length = std::sqrt(nx * nx + ny * ny + nz * nz);
         
         if (length > 0.0001f) {
             normals[i] /= length;
             normals[i+1] /= length;
             normals[i+2] /= length;
         } else {
             normals[i] = 0.0f; normals[i+1] = 1.0f; normals[i+2] = 0.0f; 
         }
     }

     // Force hard normals for the block perimeter
     size_t top_surface_vertices = grid_width * grid_height;
     for (size_t i = top_surface_vertices; i < positions.size() / 3; ++i) 
     {
         float px = positions[i * 3];
         float pz = positions[i * 3 + 2];
         float py = positions[i * 3 + 1];

         if (py == y_base) {
             normals[i * 3] = 0.0f;
             normals[i * 3 + 1] = -1.0f; // Floor points strictly down
             normals[i * 3 + 2] = 0.0f;
         } else {
             float nx = px - center_x;
             float nz = pz - center_z;
             float len = std::sqrt(nx * nx + nz * nz);
             
             if (len > 0.0001f) {
                 normals[i * 3] = nx / len;
                 normals[i * 3 + 1] = 0.0f;  // Erase upward influence for sharp corners
                 normals[i * 3 + 2] = nz / len;
             }
         }
     } 
     DracoCompressionResult dracoResult = DracoCompressor::compressGeometry(
         positions, 
         indices, 
         uvs,
         normals, // NEW: Pass the calculated normals
         16,      // posQuantization
         12,      // uvQuantization
         10,      // normalQuantization (NEW: 10-bit is standard for normals)
         7        // speed
     );

     if (!dracoResult.success) 
     {
         throw std::runtime_error("Draco Compression Failed: " + dracoResult.errorMessage);
     }

     size_t numVertices = positions.size() / 3;
     size_t numIndices = indices.size();

     std::vector<uint8_t> glbBytes = GltfPackager::buildToMemory(dracoResult, numVertices, numIndices, 
         bounds, 
         imgData, 
         imgLength
     );

     // Return the bytes upstream to PipelineService
     return glbBytes;
}





// std::vector<uint8_t> GlbMesher::generateGlb(
//      const std::vector<float>& dsm_matrix, 
//      int width, 
//      int height,
//      float pixel_size,const char* imgData,
//      size_t imgLength) 
// {    
//      std::vector<float> positions;
//      std::vector<uint32_t> indices;

//      //Pre-allocate memory for geometry only
//      positions.resize(width * height * 3);
//      indices.resize((width - 1) * (height - 1) * 6);

//      float* pos_ptr = positions.data();
//      uint32_t* ind_ptr = indices.data();

//      size_t pos_idx = 0;
//      size_t ind_idx = 0;

//      double minX = std::numeric_limits<double>::max();
//      double minY = std::numeric_limits<double>::max();
//      double minZ = std::numeric_limits<double>::max();
     
//      double maxX = std::numeric_limits<double>::lowest();
//      double maxY = std::numeric_limits<double>::lowest();
//      double maxZ = std::numeric_limits<double>::lowest();

//      //generating vertices x,y,z
//      for (int y = 0; y < height; ++y) 
//      {
//          for (int x = 0; x < width; ++x) 
//          {
//              float elevation = dsm_matrix[y * width + x];
//              float px = x * pixel_size;
//              float pz = y * pixel_size;

//              pos_ptr[pos_idx++] = px; 
//              pos_ptr[pos_idx++] = elevation;      
//              pos_ptr[pos_idx++] = pz; 

//              // Continuously update the bounding box
//              if (px < minX) 
//              {
//                  minX = px;
//              }
//              if (elevation < minY) 
//              {
//                  minY = elevation;
//              }
//              if (pz < minZ) 
//              {
//                  minZ = pz;
//              }
             
//              if (px > maxX) 
//              {
//                  maxX = px;
//              }
//              if (elevation > maxY) 
//              {
//                  maxY = elevation;
//              }
//              if (pz > maxZ) 
//              {
//                  maxZ = pz;
//              }
//          }
//      }

//      //Generating triangle indices via pointers
//      for (int y = 0; y < height - 1; ++y) 
//      {
//          for(int x = 0; x < width - 1; ++x) 
//          {   
//              uint32_t v0 = y * width + x;
//              uint32_t v1 = y * width + (x + 1);
//              uint32_t v2 = (y + 1) * width + x;
//              uint32_t v3 = (y + 1) * width + (x + 1);
             
//              ind_ptr[ind_idx++] = v0;
//              ind_ptr[ind_idx++] = v2;
//              ind_ptr[ind_idx++] = v1;
             
//              ind_ptr[ind_idx++] = v1;
//              ind_ptr[ind_idx++] = v2;
//              ind_ptr[ind_idx++] = v3;
//          }
//      }

//      // 1. Find the lowest elevation (y_min) in your current mesh
//      // CRITICAL FIX: Y (index 1) is Elevation in glTF, not Z!
//      float y_min = positions[1]; 
//      for (size_t i = 1; i < positions.size(); i += 3) 
//      {
//          if (positions[i] < y_min) 
//          {
//              y_min = positions[i];
//          }
//      }

//      // 2. Define the bottom floor and its geometric center
//      float y_base = y_min - 50.0f; // Drop the floor 50 units down along the Y axis

//      // Extract corner coordinates to find the spatial center of the map
//      float min_x = positions[0];
//      float min_z = positions[2];
//      float max_x = positions[((width * height) - 1) * 3];
//      float max_z = positions[((width * height) - 1) * 3 + 2];
//      float center_x = (min_x + max_x) / 2.0f;
//      float center_z = (min_z + max_z) / 2.0f; 

//      // ==========================================
//      // CRITICAL FIX: GENERATE UVS NOW, NOT LATER
//      // ==========================================
//      std::vector<float> uvs = UVMapping::generateUV(width, height);

//      // Push the single central base vertex (the "hub" of the floor)
//      uint32_t v_center_base = positions.size() / 3;
//      positions.push_back(center_x);
//      positions.push_back(y_base);     
//      positions.push_back(center_z);
     
//      // Give the center floor a neutral UV coordinate
//      uvs.push_back(0.5f); 
//      uvs.push_back(0.5f);

//      // 3. Helper lambda to add a skirt edge AND stitch the floor triangle
//      auto addSkirtEdge = [&](uint32_t v_top_current, uint32_t v_top_next)
//      {
//          // 3A: Build the Base Current Vertex
//          uint32_t v_base_current = positions.size() / 3;
//          positions.push_back(positions[v_top_current * 3]);     // Keep X
//          positions.push_back(y_base);                           // Drop Y
//          positions.push_back(positions[v_top_current * 3 + 2]); // Keep Z
         
//          // Fix the UV tearing: Copy the UV from the top vertex to stretch the border down
//          float u_curr = uvs[v_top_current * 2];
//          float v_curr = uvs[v_top_current * 2 + 1];
//          uvs.push_back(u_curr);
//          uvs.push_back(v_curr);

//          // 3B: Build the Base Next Vertex
//          uint32_t v_base_next = positions.size() / 3;
//          positions.push_back(positions[v_top_next * 3]);        // Keep X
//          positions.push_back(y_base);                           // Drop Y
//          positions.push_back(positions[v_top_next * 3 + 2]);    // Keep Z
         
//          // Fix the UV tearing: Copy the UV from the next top vertex
//          float u_next = uvs[v_top_next * 2];
//          float v_next = uvs[v_top_next * 2 + 1];
//          uvs.push_back(u_next);
//          uvs.push_back(v_next);

//          // 3C: Stitch the side wall quad 
//          indices.push_back(v_top_current);
//          indices.push_back(v_base_current);
//          indices.push_back(v_top_next);

//          indices.push_back(v_top_next);
//          indices.push_back(v_base_current);
//          indices.push_back(v_base_next);

//          // 3D: Stitch the floor triangle to seal the bottom
//          indices.push_back(v_base_current);
//          indices.push_back(v_center_base);
//          indices.push_back(v_base_next);
//      };

//      // 4. Traverse the perimeter in a continuous counter-clockwise ring
     
//      // Top edge: Traverse Right to Left
//      for (int x = width - 1; x > 0; --x) addSkirtEdge(x, x - 1);
     
//      // Left edge: Traverse Top to Bottom
//      for (int y = 0; y < height - 1; ++y) addSkirtEdge(y * width, (y + 1) * width);
     
//      // Bottom edge: Traverse Left to Right
//      for (int x = 0; x < width - 1; ++x) addSkirtEdge((height - 1) * width + x, (height - 1) * width + x + 1);
     
//      // Right edge: Traverse Bottom to Top
//      for (int y = height - 1; y > 0; --y) addSkirtEdge(y * width + (width - 1), (y - 1) * width + (width - 1));

//      // Update Bounding Box
//      double bounds[6] = { minX, y_base, minZ, maxX, maxY, maxZ };
//      // Your UVMapping::generateUV only generates UVs for the top surface (width * height).
//      // We added a bunch of vertices for the skirts and floor. We must pad the UV array so 
//      // its size matches the new positions array size.
//      //std::vector<float> uvs = UVMapping::generateUV(width, height);
     
//      // The center base vertex needs a UV coordinate (we'll just use 0.5, 0.5)
//     //  uvs.push_back(0.5f);
//     //  uvs.push_back(0.5f);
     
//     //  // Every skirt edge adds two vertices to the positions array.
//     //  // Total skirt vertices = positions.size() / 3 - top_surface_count - 1 (for the center)
//     //  // To keep things simple and give the side walls an "earthy" stretch from the edge of the image:
//     //  // We will assign UV coordinate (0,0) or (1,1) depending on the edge, or just clamp them.
//     //  // For this basic fix, we'll assign (0,0) to all skirt vertices so they pull color from the corner pixel.
//     //  size_t current_uv_count = uvs.size() / 2;
//     //  size_t target_vertex_count = positions.size() / 3;
     
//     //  while (current_uv_count < target_vertex_count) 
//     //  {
//     //      uvs.push_back(0.0f); // U
//     //      uvs.push_back(0.0f); // V
//     //      current_uv_count++;
//     //  }

//      // ==========================================
//      // STEP C: CALCULATE SMOOTH VERTEX NORMALS
//      // ==========================================
//      std::vector<float> normals(positions.size(), 0.0f);

//      // 1. Calculate Face Normals and Accumulate them into the Vertex Normals
//      for (size_t i = 0; i < indices.size(); i += 3) 
//      {
//          uint32_t i0 = indices[i];
//          uint32_t i1 = indices[i+1];
//          uint32_t i2 = indices[i+2];

//          // Extract vertices
//          float v0x = positions[i0 * 3], v0y = positions[i0 * 3 + 1], v0z = positions[i0 * 3 + 2];
//          float v1x = positions[i1 * 3], v1y = positions[i1 * 3 + 1], v1z = positions[i1 * 3 + 2];
//          float v2x = positions[i2 * 3], v2y = positions[i2 * 3 + 1], v2z = positions[i2 * 3 + 2];

//          // Calculate edges: U = v1 - v0, V = v2 - v0
//          float ux = v1x - v0x, uy = v1y - v0y, uz = v1z - v0z;
//          float vx = v2x - v0x, vy = v2y - v0y, vz = v2z - v0z;

//          // Cross Product: N = U x V
//          float nx = uy * vz - uz * vy;
//          float ny = uz * vx - ux * vz;
//          float nz = ux * vy - uy * vx;

//          // Accumulate normals for the three vertices
//          normals[i0 * 3] += nx; normals[i0 * 3 + 1] += ny; normals[i0 * 3 + 2] += nz;
//          normals[i1 * 3] += nx; normals[i1 * 3 + 1] += ny; normals[i1 * 3 + 2] += nz;
//          normals[i2 * 3] += nx; normals[i2 * 3 + 1] += ny; normals[i2 * 3 + 2] += nz;
//      }

//      // 2. Normalize all accumulated vertex normals
//      for (size_t i = 0; i < normals.size(); i += 3) 
//      {
//          float nx = normals[i], ny = normals[i+1], nz = normals[i+2];
//          float length = std::sqrt(nx * nx + ny * ny + nz * nz);
         
//          // Prevent division by zero
//          if (length > 0.0001f) {
//              normals[i] /= length;
//              normals[i+1] /= length;
//              normals[i+2] /= length;
//          } else {
//              normals[i] = 0.0f; normals[i+1] = 1.0f; normals[i+2] = 0.0f; // Default straight up
//          }
//      }




//     //  // Delegate binary generation to the Packager
//     //  return GltfPackager::buildAndSave(
//     //      outputPath, 
//     //      positions, 
//     //      indices, 
//     //      uvs, 
//     //      bounds, 
//     //      imgData, 
//     //      imgLength
//     //  );
//      //Compress the raw arrays into a Draco bitstream this ensures smaller .glb file generation
//      //and faster download for Unity
//      DracoCompressionResult dracoResult = DracoCompressor::compressGeometry(
//          positions, 
//          indices, 
//          uvs,
//          normals, // NEW: Pass the calculated normals
//          16,      // posQuantization
//          12,      // uvQuantization
//          10,      // normalQuantization (NEW: 10-bit is standard for normals)
//          7        // speed
//      );

//      if (!dracoResult.success) 
//      {
//          throw std::runtime_error("Draco Compression Failed: " + dracoResult.errorMessage);
//      }

//      size_t numVertices = positions.size() / 3;
//      size_t numIndices = indices.size();

//      std::vector<uint8_t> glbBytes = GltfPackager::buildToMemory(dracoResult, numVertices, numIndices, 
//          bounds, 
//          imgData, 
//          imgLength
//      );

//      // Return the bytes upstream to PipelineService
//      return glbBytes;
// }



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