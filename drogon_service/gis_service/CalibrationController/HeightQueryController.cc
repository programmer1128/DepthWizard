#include "HeightQueryController.h"
#include "../HeightService/HeightOrchestratorService.h"
#include <stdexcept>
#include <string>

// for single height query
drogon::Task<drogon::HttpResponsePtr> HeightQueryController::getSingleHeight(drogon::HttpRequestPtr req) 
{
     auto jsonPtr = req->getJsonObject();
     if (!jsonPtr) 
     {
         auto resp = drogon::HttpResponse::newHttpResponse();
         resp->setStatusCode(drogon::k400BadRequest);
         co_return resp;
     }   
 
     try 
     {
         Json::Value result = co_await HeightOrchestratorService::processSingleHeight(
             (*jsonPtr)["uuid"].asString(),
             (*jsonPtr)["x"].asFloat(),
             (*jsonPtr)["y"].asFloat()
         );
         co_return drogon::HttpResponse::newHttpJsonResponse(result);
     } 
     catch (const std::exception& e) 
     {
         auto resp = drogon::HttpResponse::newHttpResponse();
         resp->setStatusCode(drogon::k500InternalServerError);
         resp->setBody(e.what());
         co_return resp;
     }
}

// for compare height setup
drogon::Task<drogon::HttpResponsePtr> HeightQueryController::compareHeights(drogon::HttpRequestPtr req) 
{
     std::string uuid, tag;
     float x = 0.0f, y = 0.0f;
    
     const drogon::HttpFile* uploadedFilePtr = nullptr;
     drogon::MultiPartParser fileParser; 

     try 
     {
         if (req->contentType() == drogon::CT_MULTIPART_FORM_DATA) 
         {
             
             if (fileParser.parse(req) != 0 || fileParser.getParameters().empty()) 
             {
                 auto resp = drogon::HttpResponse::newHttpResponse();
                 resp->setStatusCode(drogon::k400BadRequest);
                 resp->setBody("Failed to parse multipart/form-data");
                 co_return resp;
             }
            
             auto params = fileParser.getParameters();
             uuid = params["uuid"];
             tag = params["tag"];
            
             //Safely parse floats and return 400 if malformed
             try 
             {
                 x = std::stof(params["x"]);
                 y = std::stof(params["y"]);
             } 
             catch (const std::invalid_argument& e) 
             {
                 auto resp = drogon::HttpResponse::newHttpResponse();
                 resp->setStatusCode(drogon::k400BadRequest);
                 resp->setBody("Invalid coordinate format. 'x' and 'y' must be valid numbers.");
                 co_return resp;
             } 
             catch (const std::out_of_range& e) 
             {
                 auto resp = drogon::HttpResponse::newHttpResponse();
                 resp->setStatusCode(drogon::k400BadRequest);
                 resp->setBody("Coordinate values out of range.");
                 co_return resp;
             }
            
            auto& files = fileParser.getFiles();
            if (!files.empty()) {
                uploadedFilePtr = &files[0];
            }
        } else {
            auto jsonPtr = req->getJsonObject();
            if (!jsonPtr) {
                auto resp = drogon::HttpResponse::newHttpResponse();
                resp->setStatusCode(drogon::k400BadRequest);
                resp->setBody("Invalid payload: Expected JSON or Multipart");
                co_return resp;
            }
            
             //Validate JSON types before accessing
             if (!(*jsonPtr)["x"].isNumeric() || !(*jsonPtr)["y"].isNumeric()) 
             {
                 auto resp = drogon::HttpResponse::newHttpResponse();
                 resp->setStatusCode(drogon::k400BadRequest);
                 resp->setBody("Invalid JSON: 'x' and 'y' must be numeric.");
                 co_return resp;
             }

             uuid = (*jsonPtr)["uuid"].asString();
             tag = (*jsonPtr)["tag"].asString();
             x = (*jsonPtr)["x"].asFloat();
             y = (*jsonPtr)["y"].asFloat();
         }

         // Handoff to Orchestrator
         Json::Value result = co_await HeightOrchestratorService::processComparison(uuid, tag, x, y, uploadedFilePtr);
         co_return drogon::HttpResponse::newHttpJsonResponse(result);

     } 
     catch (const std::exception& e) 
     {
         // This now only catches genuine internal server failures (500)
         auto resp = drogon::HttpResponse::newHttpResponse();
         resp->setStatusCode(drogon::k500InternalServerError);
         resp->setBody(e.what());
         co_return resp;
     }
}