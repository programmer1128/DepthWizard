#include "PipelineService.h"
#include "../SrtmExtractor/SrtmExtractor.h"
#include "../RasterProcessor/RasterProcessor.h"
#include "../RansacCalibrator/ransacCalibrator.h"
#include "../MeshMapping/MeshService.h"
#include "../DataHandlers/MiniIOClient.h"
#include "../ImageTilingService/TilingService.h"
#include <drogon/utils/Utilities.h>
#include <gdal_priv.h>
#include <stdexcept>
#include <cpl_vsi.h>
#include <cstring>
#include <thread>
#include <chrono>
#include <iostream>
#include "../FileGenerators/TiffExporter.h"
#include "stb_image_write.h"
#include "stb_image.h"
#include <fstream>
#include <algorithm>

inline void writeJpegCallback(void *context, void *data, int size)
{
    auto *vec = static_cast<std::vector<uint8_t> *>(context);
    auto *byteData = static_cast<uint8_t *>(data);
    vec->insert(vec->end(), byteData, byteData + size);
}

drogon::Task<std::string> PipelineService::executeCalibrationNormalImage(
    const drogon::HttpFile &imageFile)
{
    std::string uuid = drogon::utils::getUuid();             //
    std::string vsi_path = mountImageToRAM(uuid, imageFile); //

    try
    {
        // extract exact pixel dimensions from the JPG/PNG buffer
        int width = 0, height = 0, channels = 0;
        int ok = stbi_info_from_memory(
            reinterpret_cast<const stbi_uc *>(imageFile.fileData()),
            imageFile.fileLength(),
            &width,
            &height,
            &channels);

        if (!ok || width <= 0 || height <= 0)
        {
            throw std::runtime_error("STB Failed to parse JPG/PNG image dimensions.");
        }

        // extract textures (for JPG/PNG this is a zero-copy passthrough)
        std::vector<uint8_t> texture_map = extractTextureFromNormalImage(imageFile); //

        std::cout << "[Texture Debug] Size: " << texture_map.size() << " bytes\n";

        // generate stitched AI depth matrix with accurate dimensions
        std::vector<float> aiDepth =
            co_await TilingService::generateStitchedDepth(vsi_path, width, height);

        // free RAM disk file to prevent memory leaks
        std::remove(vsi_path.c_str()); //

        // Build Relative 3D Mesh (rDSM)
        std::vector<uint8_t> glbBytes = buildRelative3DMesh(
            uuid,
            aiDepth,
            width,
            height,
            texture_map);

        // Upload .glb to MinIO
        std::string bucket = "terrain-assets";     //
        std::string key = "mesh_" + uuid + ".glb"; //

        bool minio_success = MinioClient::uploadBuffer(bucket, key, glbBytes, "model/gltf-binary"); //
        if (!minio_success)
        {
            throw std::runtime_error("Failed to upload relative GLB to MinIO."); //
        }

        // Generate Presigned URL for frontend consumption
        std::string minio_url = MinioClient::generatePresignedUrl(bucket, key); //

        co_return minio_url;
    }
    catch (const std::exception &e)
    {
        // Failsafe RAM cleanup
        // std::remove(vsi_path.c_str());
        VSIUnlink(vsi_path.c_str());

        std::cerr << "[Relative Pipeline Error] " << e.what() << "\n";
        throw std::runtime_error(e.what());
    }
}

drogon::Task<Json::Value> PipelineService::executeCalibration(
    const drogon::HttpFile &imageFile)
{
    std::string uuid = drogon::utils::getUuid();
    std::string vsi_path = mountImageToRAM(uuid, imageFile);

    try
    {
        // auto start_total = std::chrono::steady_clock::now();

        auto start_fetch = std::chrono::steady_clock::now();
        // Extract Base Topography and Spatial Context for geotiff generation for
        // storage of data for user height req query
        SpatialMetadata meta;
        std::vector<float> srtmHeight = extractSrtmAndMetadata(vsi_path, meta);

        std::vector<uint8_t> textureBytes = extractJpegTexture(vsi_path, imageFile);

        auto end_fetch = std::chrono::steady_clock::now();
        auto fetch_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end_fetch - start_fetch).count();
        std::cout << "[Latency] GDAL Fetch & Extraction: " << fetch_ms << " ms\n";

        auto start_calib = std::chrono::steady_clock::now();

        // integrating the image tiling
        std::vector<float> aiDepth =
            co_await TilingService::generateStitchedDepth(vsi_path, meta.width, meta.height);

        // Clean RAM immediately after extraction, this prevents RAM bloat for multiple
        // user req at the same time offering better concurrency
        std::remove(vsi_path.c_str());

        // RANSAC Calibration
        // upto this part logic will remain same even for tiling of the .glb files
        //
        std::vector<float> absoluteDsm = calibrateHeights(aiDepth, srtmHeight);

        auto end_calib = std::chrono::steady_clock::now();

        auto calib_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end_calib - start_calib).count();
        std::cout << "[Latency] RANSAC Calibration: " << calib_ms << " ms\n";

        auto start_mesh = std::chrono::steady_clock::now();
        // Generate 3D Textured Mesh (.glb) and get raw bytes
        // std::vector<uint8_t> glbBytes = build3DMesh(uuid, absoluteDsm, meta, imageFile);

        std::vector<uint8_t> glbBytes = build3DMesh(uuid, absoluteDsm, meta, textureBytes);
        auto end_mesh = std::chrono::steady_clock::now();

        auto mesh_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end_mesh - start_mesh).count();
        std::cout << "[Latency] Meshing & Draco Compression: " << mesh_ms << " ms\n";

        // upload the glbBytes to the MiniIO object storage
        std::string bucket = "terrain-assets";
        std::string key = "mesh_" + uuid + ".glb";

        auto start_upload = std::chrono::steady_clock::now();
        // Upload to MinIO
        bool minio_success = MinioClient::uploadBuffer(bucket, key, glbBytes, "model/gltf-binary");

        if (!minio_success)
        {
            throw std::runtime_error("Failed to upload GLB to MinIO.");
        }

        std::string minio_url = MinioClient::generatePresignedUrl(bucket, key);

        // the .tiff file generation is handed to a background async worker thread that generates
        // the .tiff n server after the .glb file is sent for better performance. UI remains smooth
        // and better performance
        std::string tiff_key = "heights_" + uuid + ".tif";

        // Hand off in-memory GeoTIFF encoding and MinIO upload to the background thread
        std::thread([dsm = std::move(absoluteDsm), // Transfer ownership of elevation matrix
                     uuid,
                     tiff_key,
                     bucket,
                     w = meta.width,
                     h = meta.height,
                     geoTransform = meta.geoTransform, // Copy spatial parameters
                     proj = meta.projectionRef]() mutable
                    {
                        try
                        {
                            // generate the GeoTIFF in RAM
                            std::vector<uint8_t> tiffBytes = TiffExporter::exportTiffToBuffer(
                                uuid, dsm, w, h, geoTransform.data(), proj.c_str());

                            if (tiffBytes.empty())
                            {
                                std::cerr << "Failed to generate GeoTIFF buffer for UUID: " << uuid << "\n";
                                return;
                            }
                            // upload byte stream to MinIO
                            bool success = MinioClient::uploadBuffer(bucket, tiff_key, tiffBytes, "image/tiff");
                            if (!success)
                            {
                                std::cerr << "[MinIO Error] Background upload failed for: " << tiff_key << "\n";
                            }
                            else
                            {
                                std::cout << "[MinIO] Successfully uploaded background GeoTIFF: " << tiff_key
                                          << " (" << (tiffBytes.size() / 1024) << " KB)\n";
                            }
                        }
                        catch (const std::exception &e)
                        {
                            std::cerr << "[Worker Exception] Background TIFF task failed: " << e.what() << "\n";
                        } })
            .detach();

        // return glb download URL of minio to frontend.
        auto end_upload = std::chrono::steady_clock::now();
        auto upload_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end_upload - start_upload).count();
        std::cout << "[Latency] MinIO Network Upload: " << upload_ms << " ms\n";

        // Total Time
        // auto total_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end_upload - start_total).count();
        // std::cout << "[Latency] TOTAL PIPELINE EXECUTION: " << total_ms << " ms\n";

        // New JSON return
        Json::Value responseJson;
        responseJson["uuid"] = uuid;
        responseJson["glb_url"] = minio_url;
        co_return responseJson; // Make sure to change the method signature in .h to drogon::Task<Json::Value>
    }
    catch (const std::exception &e)
    {
        // Failsafe RAM cleanup
        // std::remove(vsi_path.c_str());
        VSIUnlink(vsi_path.c_str());

        std::cerr << "CRASH DETECTED: " << e.what() << "\n";
        // Explicitly rethrow to bypass the GCC coroutine bug
        throw std::runtime_error(e.what());
    }
}

inline std::vector<float> PipelineService::parseDepthMatrix(const drogon::HttpFile &depthFile) const
{
    size_t floatCount = depthFile.fileLength() / sizeof(float);
    std::vector<float> aiDepth(floatCount);
    std::memcpy(aiDepth.data(), depthFile.fileData(), depthFile.fileLength());
    return aiDepth;
}

inline std::string PipelineService::mountImageToRAM(const std::string &uuid, const drogon::HttpFile &imageFile) const
{
    // Use the OS /tmp/ directory (tmpfs RAM disk) instead of GDAL's /vsimem/
    std::string real_path = "/tmp/upload_" + uuid + ".tif";

    std::ofstream out(real_path, std::ios::binary);
    if (out.is_open())
    {
        out.write(imageFile.fileData(), imageFile.fileLength());
        out.close();
    }
    else
    {
        throw std::runtime_error("Failed to write temporary image to " + real_path);
    }

    return real_path;
}

inline std::vector<float> PipelineService::extractSrtmAndMetadata(const std::string &vsi_path,
                                                                  SpatialMetadata &meta) const
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

    const char *proj = datasets.hInputDS->GetProjectionRef();
    meta.projectionRef = (proj != nullptr) ? std::string(proj) : "";

    // Process heights
    return RasterProcessor::processor(
        std::move(datasets.hInputDS),
        std::move(datasets.hDemDS));
}

inline std::vector<float> PipelineService::calibrateHeights(const std::vector<float> &aiDepth, const std::vector<float> &srtmHeight) const
{
    RansacCalibrator calibrator(500, 15.0);
    CalibrationResult result = calibrator.calculateScaleAndOffset(aiDepth, srtmHeight);

    if (result.inliers_count == 0)
    {
        throw std::runtime_error("RANSAC failed to find a valid calibration model.");
    }

    return calibrator.applyCalibration(aiDepth, result.a, result.b, result.c);
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
    const std::string &uuid,
    const std::vector<float> &absoluteDsm,
    const SpatialMetadata &meta,
    const std::vector<uint8_t> &textureBytes) const
{
    GlbMesher mesher;

    // Find the true elevation range of this specific landscape
    auto min_it = std::min_element(absoluteDsm.begin(), absoluteDsm.end());
    auto max_it = std::max_element(absoluteDsm.begin(), absoluteDsm.end());
    float min_z = (min_it != absoluteDsm.end()) ? *min_it : 0.0f;
    float max_z = (max_it != absoluteDsm.end()) ? *max_it : 1.0f;

    float z_range = max_z - min_z;
    if (z_range < 0.1f)
        z_range = 1.0f; // Failsafe against division by zero

    // Find the longest edge of the pixel grid
    float max_dimension = std::max(static_cast<float>(meta.width), static_cast<float>(meta.height));

    // Force the highest peak to be exactly 25% of the map's width.
    // This guarantees dramatic proportions without ever turning into spikes.
    float cinematic_ratio = 0.25f;
    float desired_max_height = max_dimension * cinematic_ratio;
    float dynamic_scale = desired_max_height / z_range;

    // Add a clean, proportional base thickness (2% of map width)
    float base_thickness = max_dimension * 0.02f;

    std::vector<float> exaggeratedDsm = absoluteDsm;
    for (float &z : exaggeratedDsm)
    {
        // Normalize the height to 0, stretch it to the calculated pixel scale, and add the base
        z = ((z - min_z) * dynamic_scale) + base_thickness;
    }

    std::vector<uint8_t> glbBytes = mesher.generateGlb(
        exaggeratedDsm,
        meta.width,
        meta.height,
        1.0f, // Keep X/Y plane in strict pixel units
        reinterpret_cast<const char *>(textureBytes.data()),
        textureBytes.size());

    if (glbBytes.empty())
    {
        throw std::runtime_error("Failed to package the .glb 3D mesh.");
    }

    return glbBytes;
}

// for the JPG/PNG images
inline std::vector<uint8_t> PipelineService::buildRelative3DMesh(
    const std::string &uuid,
    const std::vector<float> &relativeDsm,
    int width,
    int height,
    const std::vector<uint8_t> &textureBytes) const
{
    GlbMesher mesher;

    // 1. Find the relative range of the AI's raw output
    auto min_it = std::min_element(relativeDsm.begin(), relativeDsm.end());
    auto max_it = std::max_element(relativeDsm.begin(), relativeDsm.end());
    float min_z = (min_it != relativeDsm.end()) ? *min_it : 0.0f;
    float max_z = (max_it != relativeDsm.end()) ? *max_it : 1.0f;

    float z_range = max_z - min_z;
    if (z_range < 1e-6f)
        z_range = 1.0f; // Failsafe for flat images

    // 2. Extract dimensions directly from the JPG/PNG width and height
    float max_dimension = std::max(static_cast<float>(width), static_cast<float>(height));

    // 3. Cinematic auto-scaling
    float cinematic_ratio = 0.25f;
    float desired_max_height = max_dimension * cinematic_ratio;
    float dynamic_scale = desired_max_height / z_range;
    float base_thickness = max_dimension * 0.02f;

    // 4. Apply the scale to the relative depths
    std::vector<float> exaggeratedDsm = relativeDsm;
    for (float &z : exaggeratedDsm)
    {
        z = ((z - min_z) * dynamic_scale) + base_thickness;
    }

    // 5. Pass to your existing GlbMesher
    std::vector<uint8_t> glbBytes = mesher.generateGlb(
        exaggeratedDsm,
        width,
        height,
        1.0f, // Keep the grid strictly 1:1 with the pixel coordinates
        reinterpret_cast<const char *>(textureBytes.data()),
        textureBytes.size());

    if (glbBytes.empty())
    {
        throw std::runtime_error("Failed to package the relative .glb 3D mesh.");
    }

    return glbBytes;
}

inline std::vector<uint8_t> PipelineService::extractJpegTexture(
    const std::string &vsi_path,
    const drogon::HttpFile &imageFile) const
{
    // Passthrough if client explicitly uploaded a standard JPEG/PNG
    const unsigned char *raw = reinterpret_cast<const unsigned char *>(imageFile.fileData());
    size_t len = imageFile.fileLength();
    if (len >= 3 && raw[0] == 0xFF && raw[1] == 0xD8 && raw[2] == 0xFF)
        return std::vector<uint8_t>(raw, raw + len);
    if (len >= 4 && raw[0] == 0x89 && raw[1] == 'P' && raw[2] == 'N' && raw[3] == 'G')
        return std::vector<uint8_t>(raw, raw + len);

    // Open the GeoTIFF currently mounted in RAM
    GDALDataset *poDS = static_cast<GDALDataset *>(GDALOpen(vsi_path.c_str(), GA_ReadOnly));
    if (!poDS)
        throw std::runtime_error("Failed to open GeoTIFF for texture conversion.");

    int width = poDS->GetRasterXSize();
    int height = poDS->GetRasterYSize();
    int bands = poDS->GetRasterCount();

    // Extract pixels and 3 channels (glTF strictly requires RGB textures)
    std::vector<uint8_t> rawPixels(width * height * 3);
    std::vector<uint8_t> bandData(width * height);

    for (int b = 1; b <= 3; ++b)
    {
        // If the TIFF is 1-band grayscale, this replicates it across RGB
        int srcB = (b <= bands) ? b : 1;
        GDALRasterBand *band = poDS->GetRasterBand(srcB);

        // Read the band as 8-bit bytes
        band->RasterIO(GF_Read, 0, 0, width, height, bandData.data(), width, height, GDT_Byte, 0, 0);

        // Interleave the flat band data into RGB format (e.g., [R,G,B, R,G,B])
        for (int i = 0; i < width * height; ++i)
        {
            rawPixels[i * 3 + (b - 1)] = bandData[i];
        }
    }
    GDALClose(poDS);

    // Encode directly to a pure, EXIF-free JPEG using STB
    std::vector<uint8_t> jpegBuffer;
    stbi_write_jpg_to_func(writeJpegCallback, &jpegBuffer, width, height, 3, rawPixels.data(), 90);

    if (jpegBuffer.empty())
    {
        throw std::runtime_error("STB JPEG encoding failed.");
    }

    return jpegBuffer;
}

inline std::vector<uint8_t> PipelineService::extractTextureFromNormalImage(const drogon::HttpFile &imageFile)
{
    const uint8_t *rawData = reinterpret_cast<const uint8_t *>(imageFile.fileData());
    size_t length = imageFile.fileLength();

    if (!rawData || length < 4)
    {
        return {};
    }

    // 1. Passthrough if the input is already a JPEG
    if (rawData[0] == 0xFF && rawData[1] == 0xD8)
    {
        return std::vector<uint8_t>(rawData, rawData + length);
    }

    // 2. Decode PNG / other formats to raw RGB
    int w = 0, h = 0, channels = 0;
    stbi_uc *decodedPixels = stbi_load_from_memory(
        rawData, static_cast<int>(length), &w, &h, &channels, 3 // Force 3 channels (RGB)
    );

    if (!decodedPixels)
    {
        std::cerr << "[Texture Error] stbi_load_from_memory failed: " << stbi_failure_reason() << "\n";
        return {};
    }

    // 3. Re-encode to JPEG in memory for glTF compatibility
    std::vector<uint8_t> jpegBuffer;
    auto writeFunc = [](void *context, void *data, int size)
    {
        auto *buf = reinterpret_cast<std::vector<uint8_t> *>(context);
        const auto *bytes = reinterpret_cast<const uint8_t *>(data);
        buf->insert(buf->end(), bytes, bytes + size);
    };

    stbi_write_jpg_to_func(writeFunc, &jpegBuffer, w, h, 3, decodedPixels, 90);
    stbi_image_free(decodedPixels);

    return jpegBuffer;
}