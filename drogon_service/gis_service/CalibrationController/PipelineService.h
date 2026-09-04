#pragma once
#include <string>
#include <vector>
#include <array>
#include <drogon/MultiPart.h>
#include <drogon/drogon.h>
#include <coroutine>

//data transfer object to hold GDAL spatial context
struct SpatialMetadata 
{
     int width;
     int height;
    std::array<double, 6> geoTransform;
    std::string projectionRef;
};

class PipelineService 
{
        public:
        drogon::Task<std::string> executeCalibration(const drogon::HttpFile& imageFile, 
                 const drogon::HttpFile& depthFile);


         private:
         //service broken down to methods for better modular access control and inlining added
         //for compiler optimisation to reduce function call overhead
        
         inline std::vector<float> parseDepthMatrix(const drogon::HttpFile& depthFile) const;
        
         inline std::string mountImageToRAM(const std::string& uuid, 
                 const drogon::HttpFile& imageFile) const;
       
         inline std::vector<float> extractSrtmAndMetadata(const std::string& vsi_path, 
                 SpatialMetadata& meta) const;
       
         inline std::vector<float> calibrateHeights(const std::vector<float>& aiDepth, 
                 const std::vector<float>& srtmHeight) const;
        
        //  inline std::vector<uint8_t> build3DMesh(const std::string& uuid, const std::vector<float>& absoluteDsm, 
        //          const SpatialMetadata& meta, const drogon::HttpFile& imageFile) const;

         inline std::vector<uint8_t> build3DMesh(
                const std::string& uuid, 
                const std::vector<float>& absoluteDsm, 
                const SpatialMetadata& meta, 
                const std::vector<uint8_t>& textureBytes) const;

         inline std::vector<uint8_t> extractJpegTexture(
            const std::string& vsi_path, 
            const drogon::HttpFile& imageFile) const;
};