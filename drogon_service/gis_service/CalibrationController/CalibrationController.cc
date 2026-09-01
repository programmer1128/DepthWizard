#include "CalibrationController.h"
#include "../SrtmExtractor/SrtmExtractor.h"
#include "../RasterProcessor/RasterProcessor.h"

#include <drogon/utils/Utilities.h>
#include <fstream>
#include <filesystem> // For deleting the temporary file

void CalibrationController::processTerrain(const drogon::HttpRequestPtr& req,
                                           std::function<void (const drogon::HttpResponsePtr &)> &&callback)
{
    // parse the uploaded file from the HTTP request
    drogon::MultiPartParser fileUpload;
    if (fileUpload.parse(req) != 0 || fileUpload.getFiles().empty())
    {
        Json::Value error;
        error["status"] = "error";
        error["message"] = "No file uploaded. Please attach a GeoTIFF.";
        auto resp = drogon::HttpResponse::newHttpJsonResponse(error);
        resp->setStatusCode(drogon::k400BadRequest);
        callback(resp);
        return;
    }

    const auto& file = fileUpload.getFiles()[0];
    
    // save the uploaded file temporarily to the hard drive
    // we generate a UUID so multiple users dont overwrite each other's uploads
    std::string temp_file_path = "./temp_upload_" + drogon::utils::getUuid() + ".tif";
    file.saveAs(temp_file_path);

    try
    {
        // hand over to srtm extractor

        RasterDatasets datasets = SrtmExtractor::fetchTile(temp_file_path);
        
        if (!datasets.hInputDS || !datasets.hDemDS)
        {
            throw std::runtime_error("Failed to extract datasets from AWS or input image.");
        }

        // hand over to raster processor

        std::vector<float> final_matrix = RasterProcessor::processor(std::move(datasets.hInputDS), std::move(datasets.hDemDS));

        // write matrix to a text file

        std::string output_txt_path = "./final_matrix_" + drogon::utils::getUuid() + ".txt";
        std::ofstream outFile(output_txt_path);
        
        if (outFile.is_open())
        {
            outFile << "Final Extracted Float Matrix\n";
            outFile << "Total Pixels: " << final_matrix.size() << "\n\n";
            
            for (size_t i = 0; i < final_matrix.size(); ++i)
            {
                outFile << final_matrix[i] << " ";

                // added a line break every 10 numbers to make the text file readable
                if ((i + 1) % 10 == 0) outFile << "\n"; 
            }
            outFile.close();
        }

        // Delete the temporary uploaded file from the SSD
        std::filesystem::remove(temp_file_path);

        // return success message
        Json::Value success;
        success["status"] = "success";
        success["message"] = "Pipeline completed successfully.";
        success["matrix_size"] = static_cast<Json::Value::UInt64>(final_matrix.size());
        success["saved_file"] = output_txt_path;

        auto resp = drogon::HttpResponse::newHttpJsonResponse(success);
        callback(resp);
    }
    catch (const std::exception& e)
    {
        // If the pipeline crashes, we must still delete the temporary file!
        std::filesystem::remove(temp_file_path);

        Json::Value error;
        error["status"] = "error";
        error["message"] = e.what();
        
        auto resp = drogon::HttpResponse::newHttpJsonResponse(error);
        resp->setStatusCode(drogon::k500InternalServerError);
        callback(resp);
    }
}