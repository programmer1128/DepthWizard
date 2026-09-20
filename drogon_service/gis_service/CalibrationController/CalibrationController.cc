#include "CalibrationController.h"
#include "../SrtmExtractor/SrtmExtractor.h"
#include "../RasterProcessor/RasterProcessor.h"
#include "CalibrationController.h"
#include "PipelineService.h"
#include <drogon/utils/Utilities.h>
#include <fstream>
#include <filesystem> // For deleting the temporary file
#include <cstring>

/*

drogon::Task<drogon::HttpResponsePtr> CalibrationController::processTerrain(drogon::HttpRequestPtr req)
{
     drogon::MultiPartParser fileUpload;
    
     if (fileUpload.parse(req) != 0) 
     {
         Json::Value error;
         error["status"] = "error";
         error["message"] = "Failed to parse multipart request.";
         auto resp = drogon::HttpResponse::newHttpJsonResponse(error);
         resp->setStatusCode(drogon::k400BadRequest);
         co_return resp; 
     }

     auto files = fileUpload.getFilesMap();

     //Ensure both the image and the test depth matrix were uploaded
     if (files.find("image") == files.end()) 
     {
         Json::Value error;
         error["status"] = "error";
         error["message"] = "Missing files. Please provide image file";
         auto resp = drogon::HttpResponse::newHttpJsonResponse(error);
         resp->setStatusCode(drogon::k400BadRequest);
         co_return resp; 
     }

     //Read-only access
     const auto& imageFile = files.at("image");
     //const auto& depthFile = files.at("depth");

     try 
     {
        //  //convert the uploaded depth binary directly into a std::vector<float>
        //  // We calculate how many floats are in the file by dividing byte length by 4 (sizeof float)
        //  size_t floatCount = depthFile.fileLength() / sizeof(float);
        //  std::vector<float> aiDepth(floatCount);
        
        //  // Copy the raw bytes directly into the vector's memory
        //  std::memcpy(aiDepth.data(), depthFile.fileData(), depthFile.fileLength());
         //Execute the strictly isolated C++ GIS Pipeline
         //Execute the strictly isolated C++ GIS Pipeline
         Json::Value pipelineResult = co_await PipelineService().executeCalibration(
                 imageFile
             );

         //Return Success
         Json::Value success;
         success["status"] = "success";
         success["message"] = "Pipeline completed successfully.";
         
         // Extract the values from the pipeline result and send them to the frontend
         success["uuid"] = pipelineResult["uuid"].asString();
         success["glb_url"] = pipelineResult["glb_url"].asString();

         co_return drogon::HttpResponse::newHttpJsonResponse(success);

     } 
     catch (const std::exception& e) 
     {
         Json::Value error;
         error["status"] = "error";
         error["message"] = e.what();
         auto resp = drogon::HttpResponse::newHttpJsonResponse(error);
         resp->setStatusCode(drogon::k500InternalServerError);
         co_return resp;
     }
}


drogon::Task<drogon::HttpResponsePtr> CalibrationController::processNormalImageForTerrain
     (drogon::HttpRequestPtr req)
{
     drogon::MultiPartParser fileUpload;
    
     if (fileUpload.parse(req) != 0) 
     {
         Json::Value error;
         error["status"] = "error";
         error["message"] = "Failed to parse multipart request.";
         auto resp = drogon::HttpResponse::newHttpJsonResponse(error);
         resp->setStatusCode(drogon::k400BadRequest);
         co_return resp; 
     }

     auto files = fileUpload.getFilesMap();

     //Ensure both the image and the test depth matrix were uploaded
     if (files.find("image") == files.end()) 
     {
         Json::Value error;
         error["status"] = "error";
         error["message"] = "Missing files. Please provide image file";
         auto resp = drogon::HttpResponse::newHttpJsonResponse(error);
         resp->setStatusCode(drogon::k400BadRequest);
         co_return resp; 
     }

     //Read-only access
     const auto& imageFile = files.at("image");
     //const auto& depthFile = files.at("depth");

     try 
     {
        //  //convert the uploaded depth binary directly into a std::vector<float>
        //  // We calculate how many floats are in the file by dividing byte length by 4 (sizeof float)
        //  size_t floatCount = depthFile.fileLength() / sizeof(float);
        //  std::vector<float> aiDepth(floatCount);
        
        //  // Copy the raw bytes directly into the vector's memory
        //  std::memcpy(aiDepth.data(), depthFile.fileData(), depthFile.fileLength());
         //Execute the strictly isolated C++ GIS Pipeline
         std::string saved_file = co_await PipelineService().executeCalibrationNormalImage(imageFile);

         //Return Success
         Json::Value success;
         success["status"] = "success";
         success["message"] = "Pipeline completed successfully.";
         success["saved_file"] = saved_file;

         co_return drogon::HttpResponse::newHttpJsonResponse(success);

     } 
     catch (const std::exception& e) 
     {
         Json::Value error;
         error["status"] = "error";
         error["message"] = e.what();
         auto resp = drogon::HttpResponse::newHttpJsonResponse(error);
         resp->setStatusCode(drogon::k500InternalServerError);
         co_return resp;
     }
}

*/

drogon::HttpResponsePtr CalibrationController::toHttpResponse(const PipelineResult& result)
{
    Json::Value json;
    
    if (result.status == PipelineStatus::FATAL_ERROR) {
        json["status"] = "error";
    } else {
        json["status"] = "success";
    }

    json["uuid"] = result.jobId;
    json["mode"] = (result.processingMode == PipelineMode::GEOREFERENCED) ? "absolute" : "relative";
    
    if (result.manifest.glb.url.has_value()) {
        json["glb_url"] = result.manifest.glb.url.value();
    }

    // Map the raster processing statuses
    auto mapArtifact = [](const ArtifactStatus& artifact) -> Json::Value {
        Json::Value node;
        switch(artifact.status) {
            case JobStatus::QUEUED: node["status"] = "queued"; break;
            case JobStatus::PROCESSING: node["status"] = "processing"; break;
            case JobStatus::READY: 
                node["status"] = "ready"; 
                if (artifact.url.has_value()) node["url"] = artifact.url.value();
                break;
            case JobStatus::FAILED: node["status"] = "failed"; break;
        }
        return node;
    };

    json["artifacts"]["dsm"] = mapArtifact(result.manifest.dsm);
    json["artifacts"]["dtm"] = mapArtifact(result.manifest.dtm);
    json["artifacts"]["ndsm"] = mapArtifact(result.manifest.ndsm);
    json["artifacts"]["slope"] = mapArtifact(result.manifest.slope);
    json["artifacts"]["hillshade"] = mapArtifact(result.manifest.hillshade);
    json["artifacts"]["confidence"] = mapArtifact(result.manifest.confidence);
    
    if (result.manifest.canopyHeight.has_value()) {
        json["artifacts"]["canopy"] = mapArtifact(result.manifest.canopyHeight.value());
    }

    // Map Quality Report
    json["quality"]["status"] = (result.qualityReport.status == QualityStatus::PASS) ? "pass" : 
                                (result.qualityReport.status == QualityStatus::WARN) ? "warn" : "fail";
    json["quality"]["confidence"] = result.qualityReport.overallConfidence;
    
    Json::Value warningsArray(Json::arrayValue);
    for (const auto& w : result.qualityReport.userWarnings) warningsArray.append(w);
    json["quality"]["warnings"] = warningsArray;

    auto resp = drogon::HttpResponse::newHttpJsonResponse(json);
    if (result.status == PipelineStatus::FATAL_ERROR) resp->setStatusCode(drogon::k500InternalServerError);
    else resp->setStatusCode(drogon::k200OK);
    
    return resp;
}