// loops through the array of quad nodes
// crops the image and DSM
// calls mesh service and draco compression
// uploads the .glb files to MinIO

#include "GlbFactory.h"
#include "../MeshMapping/MeshService.h"
#include "../DataHandlers/MiniIOClient.h"
#include <opencv2/opencv.hpp>
#include "stb_image_write.h"
#include <iostream>
#include <queue>
#include <omp.h>
#include <cstring> // for std::memcpy

// inline for STB to write JPEG bytes directly into RAM - faster
inline void writeJpegCallback(void* context, void* data, int size) 
{
    auto* vec = static_cast<std::vector<uint8_t>*>(context);
    auto* byteData = static_cast<uint8_t*>(data);
    vec->insert(vec->end(), byteData, byteData + size);
}

void GlbFactory::generateAndUploadAll(
     QuadTreeGraph& graph, 
     const std::vector<float>& master_dsm, 
     const std::vector<uint8_t>& rawJpegBytes, 
     int master_width, 
     int master_height) 
{
     cv::Mat image = cv::imdecode(rawJpegBytes, cv::IMREAD_COLOR);
     if (image.empty()) 
     {
         throw std::runtime_error("Cannot decode the Master Image in memory!");
     }
     
     cv::cvtColor(image, image, cv::COLOR_BGR2RGB);

     // --- NEW: GLOBAL Z-EXAGGERATION MATH ---
     // We MUST calculate the scale globally so all tiles connect seamlessly at their seams.
     float global_min_z = 1e9f, global_max_z = -1e9f;
     for (float val : master_dsm) {
         if (!std::isnan(val)) {
             if (val < global_min_z) global_min_z = val;
             if (val > global_max_z) global_max_z = val;
         }
     }
     
     float z_range = global_max_z - global_min_z;
     if (z_range < 0.1f) z_range = 1.0f; // Failsafe
     
     float max_dimension = std::max(static_cast<float>(master_width), static_cast<float>(master_height));
     float cinematic_ratio = 0.25f; // Max peak is 25% of total map width
     float global_dynamic_scale = (max_dimension * cinematic_ratio) / z_range;
     float global_base_thickness = max_dimension * 0.02f; // 2% base

     // Build the BFS Queue for Upload Prioritization
     std::vector<uint32_t> bfs_queue;
     bfs_queue.reserve(graph.nodes.size());
     std::queue<uint32_t> q;
    
     q.push(0); // Root node ID
     while (!q.empty()) 
     {
         uint32_t current_id = q.front();
         q.pop();
         bfs_queue.push_back(current_id);

         size_t start_idx = graph.edge_markers[current_id];
         size_t end_idx = graph.edge_markers[current_id + 1];
         for (size_t idx = start_idx; idx < end_idx; ++idx) 
         {
             q.push(graph.edges[idx]);
         }
     }

     std::string bucket = "terrain-assets"; 

     // Multithreaded Processing & Uploading
     #pragma omp parallel for schedule(dynamic, 8) 
     for (size_t i = 0; i < bfs_queue.size(); ++i) 
     {
         uint32_t node_id = bfs_queue[i];
         QuadNode& node = graph.nodes[node_id];
 
         int x = node.bounds.x_offset;
         int y = node.bounds.y_offset;
         int w = node.bounds.width;
         int h = node.bounds.height;

        // OVERLAP FIX: Add +1 to grab the neighbor's border pixel so they stitch together seamlessly!
         int safe_w = std::min(w + 1, master_width - x);
         int safe_h = std::min(h + 1, master_height - y);

         // --- A. Image Slicing and Compression ---
         cv::Rect roi(x, y, safe_w, safe_h);
         
         // CRITICAL BUG FIX: .clone() forces OpenCV to create contiguous memory!
         cv::Mat image_slice = image(roi).clone(); 

         // Downscale for zoomed-out tiles (LOD concept)
         if (node.level < 3) 
         {
             cv::Mat resized_slice;
             cv::resize(image_slice, resized_slice, cv::Size(512, 512), 0, 0, cv::INTER_AREA);
             image_slice = resized_slice;
         }

         std::vector<uint8_t> jpeg_buffer;
         stbi_write_jpg_to_func(writeJpegCallback, &jpeg_buffer, image_slice.cols, image_slice.rows, 3, image_slice.data, 90);


         // --- B. DSM Slicing & Dynamic Height Calculation ---
         std::vector<float> local_dsm(safe_w * safe_h);
         float local_min = std::numeric_limits<float>::max();
         float local_max = std::numeric_limits<float>::lowest();

         for (int row = 0; row < safe_h; ++row) 
         {
             int master_idx = ((y + row) * master_width) + x;
             int local_idx = row * safe_w;
            
             // Replaced memcpy with a per-pixel loop to safely apply cinematic scaling
             for (int col = 0; col < safe_w; ++col) 
             {
                 float val = master_dsm[master_idx + col];
                 if (!std::isnan(val)) 
                 {
                     // Apply the global cinematic stretch to this local pixel
                     val = ((val - global_min_z) * global_dynamic_scale) + global_base_thickness;
                     
                     // Track true min/max for OGC bounding boxes
                     if (val < local_min) local_min = val;
                     if (val > local_max) local_max = val;
                 }
                 else 
                 {
                     val = 0.0f; // Replace NaNs to prevent 3D rendering crashes
                 }
                 local_dsm[local_idx + col] = val;
             }
         }

         // Handle edge case of entirely NaN tiles (ocean/void)
         if (local_min > local_max) { local_min = 0.0f; local_max = 0.0f; }
        
         // Store the true CALCULATED heights into the node for OgcIndexer to use
         // If we don't store the scaled heights, the renderer will cull the tiles incorrectly!
         node.volume.min_height = local_min;
         node.volume.max_height = local_max;


         // --- C. Mesh Generation & MinIO Upload ---
         GlbMesher mesher; 
         std::vector<uint8_t> glb_bytes = mesher.generateGlb(local_dsm, safe_w, safe_h, 1.0f, reinterpret_cast<const char*>(jpeg_buffer.data()), jpeg_buffer.size());
         
         std::string key = "tile_" + std::to_string(node.id) + ".glb";
         bool uploaded = MinioClient::uploadBuffer(bucket, key, glb_bytes, "model/gltf-binary");
 
         if (!uploaded)
         {
             std::cerr << "Failed to upload GLB for node " << node.id << " to MinIO" << std::endl;
         }
 
         node.glb_url = MinioClient::generatePresignedUrl(bucket, key);
     }
}