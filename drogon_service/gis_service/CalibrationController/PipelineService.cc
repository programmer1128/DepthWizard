#include "PipelineService.h"
#include "../SrtmExtractor/SrtmExtractor.h"
#include "../RasterProcessor/RasterProcessor.h"
#include "../RansacCalibrator/ransacCalibrator.h"
#include "../MeshMapping/MeshService.h"
#include <drogon/utils/Utilities.h>
#include <gdal_priv.h>
#include <stdexcept>
#include <cpl_vsi.h>
#include <cstring>
#include <thread>
#include "TiffExporter.h"

std::string PipelineService::executeCalibration(
    const drogon::HttpFile& imageFile, 
    const drogon::HttpFile& depthFile)
{
     std::string uuid = drogon::utils::getUuid();
     std::string vsi_path = mountImageToRAM(uuid, imageFile);

     try 
     {
         //parse Input
         std::vector<float> aiDepth = parseDepthMatrix(depthFile);
        
         //Extract Base Topography and Spatial Context for geotiff generation for
         //storage of data for user height req query
         SpatialMetadata meta;
         std::vector<float> srtmHeight = extractSrtmAndMetadata(vsi_path, meta);
        
         // Clean RAM immediately after extraction, this prevents RAM bloat for multiple
         //user req at the same time offering better concurrency
         VSIUnlink(vsi_path.c_str()); 

         //RANSAC Calibration
         std::vector<float> absoluteDsm = calibrateHeights(aiDepth, srtmHeight);

         //Generate 3D Textured Mesh (.glb)
         std::string glb_output_path = build3DMesh(uuid, absoluteDsm, meta, imageFile);

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

         //return glb to frontend
         return glb_output_path;
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

inline std::string PipelineService::build3DMesh(
     const std::string& uuid, 
     const std::vector<float>& absoluteDsm, 
     const SpatialMetadata& meta, 
     const drogon::HttpFile& imageFile) const
{
     std::string glb_output_path = "./mesh_" + uuid + ".glb";
     GlbMesher mesher;
    
     bool mesh_success = mesher.generateGlb(
         glb_output_path, 
         absoluteDsm, 
         meta.width, 
         meta.height, 
         1.0f, // pixel_size modifier
         imageFile.fileData(),   
         imageFile.fileLength()
     );

     if (!mesh_success) 
     {
         throw std::runtime_error("Failed to package the .glb 3D mesh.");
     }

     return glb_output_path;
}