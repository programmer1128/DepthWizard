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
    const std::string& image_path) // dsm is the complete absolute DSM matrix
{
    // load the image to RAM once
    // IMREAD_COLOR guarantees we get a standard 3-channel image (BGR)
    cv::Mat image = cv::imread(image_path, cv::IMREAD_COLOR);
    if (image.empty()) 
    {
        throw std::runtime_error("Cannot find or open the Master Image!");
    }

    int master_width = image.cols; // width of the complete image
    int master_height = image.rows; // width of the complete image

    // OpenCV loads as BGR but we need RGB 
    cv::cvtColor(image, image, cv::COLOR_BGR2RGB);

    GlbMesher mesher;
    std::string bucket = "terrain-assets"; // MinIO storage folder

    // now we iterate through every quad node in the array
    for (size_t i = 0; i < graph.nodes.size(); ++i) 
    {
        QuadNode& node = graph.nodes[i]; // actual node

        int x = node.bounds.x_offset;
        int y = node.bounds.y_offset;
        int w = node.bounds.width;
        int h = node.bounds.height;

        // no copy image cropping
        // we put a mathematical window (cv::Rect) over the image

        // clamp width and height so they never exceed the master image boundaries
        int safe_w = std::min(w, master_width - x);
        int safe_h = std::min(h, master_height - y); 

        cv::Rect roi(x, y, safe_w, safe_h);
        cv::Mat image_slice = image(roi); // extracted image

        // downscaling for zoomed out tile (levels 0, 1, 2)
        // Level of Detail (LOD) concept
        if (node.level < 3) 
        {
            cv::Mat resized_slice;

            // we shrink it to 512x512 pixels 
            // cv::INTER_AREA shrinks images without making them look jagged
            cv::resize(image_slice, resized_slice, cv::Size(512, 512), 0, 0, cv::INTER_AREA);
            image_slice = resized_slice; 
        }

        // now we turn raw pixels (cv::Mat) into a JPEG
        std::vector<uint8_t> jpeg_buffer;

        // compress the image slice at 90% quality and save it into jpeg_buffer
        stbi_write_jpg_to_func(writeJpegCallback, &jpeg_buffer, image_slice.cols, image_slice.rows, 3, image_slice.data, 90);


        // next we have to extract the local DSM from the master DSM
        // we make blank array for just this tile's elevation heights
        std::vector<float> local_dsm(safe_w * safe_h);

        for (int row = 0; row < safe_h; ++row) 
        {
            // we calculate where this specific row lives inside the master array
            int master_idx = ((y + row) * master_width) + x;
            int local_idx = row * safe_w;
            
            // copy one row of floats from the giant array into our small array
            std::memcpy(&local_dsm[local_idx], &master_dsm[master_idx], safe_w * sizeof(float));
        }

        // now we build the 3D mesh
        // we send the local dsm and JPEG image to the mesher
        // it compresses 3D mesh using Draco compression and gives us the .glb file

        std::vector<uint8_t> glb_bytes = mesher.generateGlb(local_dsm, safe_w, safe_h, 1.0f, reinterpret_cast<const char*>(jpeg_buffer.data()), jpeg_buffer.size());
        
        // upload to MinIO
        std::string key = "tile_" + std::to_string(node.id) + ".glb";
        bool uploaded = MinioClient::uploadBuffer(bucket, key, glb_bytes, "model/gltf-binary");

        if (!uploaded)
        {
             throw std::runtime_error("Failed to upload GLB to MinIO");
        }

        // now save the link to node structure
        node.glb_url = MinioClient::generatePresignedUrl(bucket, key);
    }
}