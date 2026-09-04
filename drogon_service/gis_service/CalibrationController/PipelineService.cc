#include "PipelineService.h"
#include "../SrtmExtractor/SrtmExtractor.h"
#include "../RasterProcessor/RasterProcessor.h"
#include "../RansacCalibrator/ransacCalibrator.h"
#include "../MeshMapping/MeshService.h"
#include "../DataHandlers/MiniIOClient.h"
#include <drogon/utils/Utilities.h>
#include <gdal_priv.h>
#include <stdexcept>
#include <cpl_vsi.h>
#include <cstring>
#include <thread>
#include <chrono>
#include <iostream>
#include "TiffExporter.h"
#include "stb_image_write.h"
#include "stb_image.h"

inline void writeJpegCallback(void* context, void* data, int size) 
{
    auto* vec = static_cast<std::vector<uint8_t>*>(context);
    auto* byteData = static_cast<uint8_t*>(data);
    vec->insert(vec->end(), byteData, byteData + size);
}


drogon::Task<std::string> PipelineService::executeCalibration(
     const drogon::HttpFile& imageFile, 
     const drogon::HttpFile& depthFile)
{
     std::string uuid = drogon::utils::getUuid();
     std::string vsi_path = mountImageToRAM(uuid, imageFile);

     try 
     {
         //auto start_total = std::chrono::steady_clock::now();

         //auto start_fetch = std::chrono::steady_clock::now();
         //parse Input
         std::vector<float> aiDepth = parseDepthMatrix(depthFile);
        
         //Extract Base Topography and Spatial Context for geotiff generation for
         //storage of data for user height req query
         SpatialMetadata meta;
         std::vector<float> srtmHeight = extractSrtmAndMetadata(vsi_path, meta);
        
         std::vector<uint8_t> textureBytes = extractJpegTexture(vsi_path, imageFile);
         // Clean RAM immediately after extraction, this prevents RAM bloat for multiple
         //user req at the same time offering better concurrency
         VSIUnlink(vsi_path.c_str()); 

         //auto end_fetch = std::chrono::steady_clock::now();
         //auto fetch_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end_fetch - start_fetch).count();
         // std::cout << "[Latency] GDAL Fetch & Extraction: " << fetch_ms << " ms\n";

         //auto start_calib = std::chrono::steady_clock::now();

         //RANSAC Calibration
         std::vector<float> absoluteDsm = calibrateHeights(aiDepth, srtmHeight);
         
         //auto end_calib = std::chrono::steady_clock::now();

         //auto calib_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end_calib - start_calib).count();
         //std::cout << "[Latency] RANSAC Calibration: " << calib_ms << " ms\n";

         //auto start_mesh = std::chrono::steady_clock::now();
         //Generate 3D Textured Mesh (.glb) and get raw bytes
         //std::vector<uint8_t> glbBytes = build3DMesh(uuid, absoluteDsm, meta, imageFile);

         std::vector<uint8_t> glbBytes = build3DMesh(uuid, absoluteDsm, meta, textureBytes);
         //auto end_mesh = std::chrono::steady_clock::now();

         //auto mesh_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end_mesh - start_mesh).count();
         //std::cout << "[Latency] Meshing & Draco Compression: " << mesh_ms << " ms\n";

         //upload the glbBytes to the MiniIO object storage
         std::string bucket = "terrain-assets";
         std::string key = "mesh_" + uuid + ".glb";
 
         //auto start_upload = std::chrono::steady_clock::now();
         //Upload to MinIO
         bool minio_success = MinioClient::uploadBuffer(bucket, key, glbBytes, "model/gltf-binary");

         if (!minio_success) 
         {
             throw std::runtime_error("Failed to upload GLB to MinIO.");
         }

         std::string minio_url = MinioClient::generatePresignedUrl(bucket, key);

         //the .tiff file generation is handed to a background async worker thread that generates
         //the .tiff n server after the .glb file is sent for better performance. UI remains smooth
         //and better performance 
         std::string tiff_output_path = "./heights_" + uuid + ".tif";

         std::thread([
             dsm = std::move(absoluteDsm),// Safely transfer memory ownership to the thread
             tiff_output_path, 
             w = meta.width, 
             h = meta.height, 
             geoTransform = meta.geoTransform,// Copy the spatial array
             proj = meta.projectionRef // Copy the projection string
             ]() mutable {
            
             TiffExporter::writeFloatTiff(
                 tiff_output_path, 
                 dsm,w,h, geoTransform.data(),proj.c_str());
 
         }).detach(); // Detach allows the thread to execute independently

         //return glb download URL of minio to frontend.
         //auto end_upload = std::chrono::steady_clock::now();
         //auto upload_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end_upload - start_upload).count();
         //std::cout << "[Latency] MinIO Network Upload: " << upload_ms << " ms\n";

         // Total Time
         //auto total_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end_upload - start_total).count();
         //std::cout << "[Latency] TOTAL PIPELINE EXECUTION: " << total_ms << " ms\n";
         co_return minio_url;
     } 
     catch (const std::exception& e) 
     {
         // Failsafe RAM cleanup
         VSIUnlink(vsi_path.c_str());
         throw; 
     }
}


inline std::vector<float> PipelineService::parseDepthMatrix(const drogon::HttpFile& depthFile) const
{
     size_t floatCount = depthFile.fileLength() / sizeof(float);
     std::vector<float> aiDepth(floatCount);
     std::memcpy(aiDepth.data(), depthFile.fileData(), depthFile.fileLength());
     return aiDepth;
}

inline std::string PipelineService::mountImageToRAM(const std::string& uuid, const drogon::HttpFile& imageFile) const
{
     std::string vsi_path = "/vsimem/upload_" + uuid + ".tif";
     VSILFILE* mem_handle = VSIFileFromMemBuffer(
         vsi_path.c_str(), 
         (GByte*)imageFile.fileData(), 
         imageFile.fileLength(), 
         FALSE
     );

     if (mem_handle != nullptr) 
     {
         VSIFCloseL(mem_handle); 
     }
     return vsi_path;
}

inline std::vector<float> PipelineService::extractSrtmAndMetadata(const std::string& vsi_path, 
     SpatialMetadata& meta) const
{
     auto datasets = SrtmExtractor::fetchTile(vsi_path);
     if (!datasets.hInputDS || !datasets.hDemDS) 
     {
         throw std::runtime_error("Failed to extract datasets from AWS or input image.");
     }

     // Populate the struct with the spatial context
     meta.width = datasets.hInputDS->GetRasterXSize();
     meta.height = datasets.hInputDS->GetRasterYSize();
    
     double geoTransformRaw[6];
     if (datasets.hInputDS->GetGeoTransform(geoTransformRaw) == CE_None) 
     {
         std::copy(std::begin(geoTransformRaw), std::end(geoTransformRaw), meta.geoTransform.begin());
     }

     const char* proj = datasets.hInputDS->GetProjectionRef();
     meta.projectionRef = (proj != nullptr) ? std::string(proj) : "";

     // Process heights
     return RasterProcessor::processor(
         std::move(datasets.hInputDS),
         std::move(datasets.hDemDS)
     );
}

inline std::vector<float> PipelineService::calibrateHeights(const std::vector<float>& aiDepth, const std::vector<float>& srtmHeight) const
{
     RansacCalibrator calibrator(500, 5.0); 
     CalibrationResult best_result = calibrator.calculateScaleAndOffset(aiDepth, srtmHeight);

     if (best_result.inliers_count == 0) 
     {
         throw std::runtime_error("RANSAC failed to find a valid calibration model.");
     }

     return calibrator.applyCalibration(aiDepth, best_result.scale, best_result.offset);
}

// inline std::vector<uint8_t> PipelineService::build3DMesh(
//      const std::string& uuid, 
//      const std::vector<float>& absoluteDsm, 
//      const SpatialMetadata& meta, 
//      const drogon::HttpFile& imageFile) const
// {
//      std::string glb_output_path = "./mesh_" + uuid + ".glb";
//      GlbMesher mesher;
    
//      std::vector<uint8_t> glbBytes = mesher.generateGlb(
//          absoluteDsm, 
//          meta.width, 
//          meta.height, 
//          1.0f, // pixel_size modifier
//          imageFile.fileData(),   
//          imageFile.fileLength()
//      );

//      // If the vector is empty, the Draco compression or GLTF packaging failed
//      if (glbBytes.empty()) 
//      {
//          throw std::runtime_error("Failed to package the .glb 3D mesh.");
//      }

//      return glbBytes;
// }

inline std::vector<uint8_t> PipelineService::build3DMesh(
     const std::string& uuid, 
     const std::vector<float>& absoluteDsm, 
     const SpatialMetadata& meta, 
     const std::vector<uint8_t>& textureBytes) const
{
     GlbMesher mesher;
    
     std::vector<uint8_t> glbBytes = mesher.generateGlb(
         absoluteDsm, 
         meta.width, 
         meta.height, 
         1.0f, // pixel_size modifier
         reinterpret_cast<const char*>(textureBytes.data()),   
         textureBytes.size()
     );

     if (glbBytes.empty()) 
     {
         throw std::runtime_error("Failed to package the .glb 3D mesh.");
     }

     return glbBytes;
}


inline std::vector<uint8_t> PipelineService::extractJpegTexture(
    const std::string& vsi_path, 
    const drogon::HttpFile& imageFile) const
{
    //Passthrough if client explicitly uploaded a standard JPEG/PNG
    const unsigned char* raw = reinterpret_cast<const unsigned char*>(imageFile.fileData());
    size_t len = imageFile.fileLength();
    if (len >= 3 && raw[0] == 0xFF && raw[1] == 0xD8 && raw[2] == 0xFF) return std::vector<uint8_t>(raw, raw + len);
    if (len >= 4 && raw[0] == 0x89 && raw[1] == 'P' && raw[2] == 'N' && raw[3] == 'G') return std::vector<uint8_t>(raw, raw + len);

    //Open the GeoTIFF currently mounted in RAM
    GDALDataset* poDS = static_cast<GDALDataset*>(GDALOpen(vsi_path.c_str(), GA_ReadOnly));
    if (!poDS) throw std::runtime_error("Failed to open GeoTIFF for texture conversion.");

    int width = poDS->GetRasterXSize();
    int height = poDS->GetRasterYSize();
    int bands = poDS->GetRasterCount();

    //Extract pixels and 3 channels (glTF strictly requires RGB textures)
    std::vector<uint8_t> rawPixels(width * height * 3);
    std::vector<uint8_t> bandData(width * height);

    for (int b = 1; b <= 3; ++b) 
    {
        // If the TIFF is 1-band grayscale, this replicates it across RGB
        int srcB = (b <= bands) ? b : 1; 
        GDALRasterBand* band = poDS->GetRasterBand(srcB);
        
        // Read the band as 8-bit bytes
        band->RasterIO(GF_Read, 0, 0, width, height, bandData.data(), width, height, GDT_Byte, 0, 0);

        // Interleave the flat band data into RGB format (e.g., [R,G,B, R,G,B])
        for (int i = 0; i < width * height; ++i) 
        {
            rawPixels[i * 3 + (b - 1)] = bandData[i];
        }
    }
    GDALClose(poDS);

    //Encode directly to a pure, EXIF-free JPEG using STB
    std::vector<uint8_t> jpegBuffer;
    stbi_write_jpg_to_func(writeJpegCallback, &jpegBuffer, width, height, 3, rawPixels.data(), 90);

    if (jpegBuffer.empty()) 
    {
         throw std::runtime_error("STB JPEG encoding failed.");
    }

    return jpegBuffer;
}