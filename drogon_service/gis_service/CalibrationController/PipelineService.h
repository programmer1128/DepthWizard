#pragma once
#include <string>
#include <vector>
#include <array>
#include <drogon/MultiPart.h>
#include <drogon/drogon.h>
#include <coroutine>
#include "../structures/CommonTypes.h"
#include "../structures/ExportStructs.h"
#include "../structures/IngestionStructs.h"


class PipelineService 
{
         public:
         drogon::Task<Json::Value> executeCalibration(const drogon::HttpFile& imageFile);

         drogon::Task<std::string> executeCalibrationNormalImage(const drogon::HttpFile& imageFile);

         // constructs the final comprehensive struct matching frontend expectations
        static PipelineResult buildResult(
                const SceneInput& scene,
                const ArtifactManifest& artifacts,
                const QualityReport& quality,
                const ModelMetadata& model);

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

         inline std::vector<uint8_t> buildRelative3DMesh(
                 const std::string& uuid, 
                 const std::vector<float>& relativeDsm,int width,int height,
                 const std::vector<uint8_t>& textureBytes) const;
         
         inline std::vector<uint8_t> extractJpegTexture(
            const std::string& vsi_path, 
            const drogon::HttpFile& imageFile) const;

         inline std::vector<uint8_t> extractTextureFromNormalImage(const drogon::HttpFile& imageFile);
};