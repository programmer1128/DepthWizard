#include "ReferenceDemService.h"
#include <drogon/HttpClient.h>
#include <stdexcept>

// OPTIMIZATION: Thread-safe connection pooling
static drogon::HttpClientPtr getOpenTopoClient() {
    static auto client = drogon::HttpClient::newHttpClient("https://portal.opentopography.org");
    return client;
}

static drogon::HttpClientPtr getBhuvanClient() {
    static auto client = drogon::HttpClient::newHttpClient("https://bhuvan-vec1.nrsc.gov.in");
    return client;
}

drogon::Task<std::vector<uint8_t>> ReferenceDemService::fetchReference(
    const std::string& tag, const GeoWindowContext& context, const drogon::HttpFile* uploadedFile) 
{
    if (tag == "upload" && uploadedFile != nullptr) 
    {
        co_return std::vector<uint8_t>(
            uploadedFile->fileData(), 
            uploadedFile->fileData() + uploadedFile->fileLength()
        );
    }
    
    if (tag == "opentopography") 
    {
        auto client = getOpenTopoClient(); // Uses persistent Keep-Alive connection
        
        // actual OpenTopography API Key
        std::string apiKey = "9edec22bf8fbc738f1e6e5189a8c188f"; 
        
        std::string path = "/API/globaldem?demtype=SRTMGL1&south=" + std::to_string(context.minLat) +
                           "&north=" + std::to_string(context.maxLat) +
                           "&west=" + std::to_string(context.minLon) +
                           "&east=" + std::to_string(context.maxLon) +
                           "&outputFormat=GTiff&API_Key=" + apiKey;
        
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setPath(path);
        req->setMethod(drogon::Get);
        
        auto resp = co_await client->sendRequestCoro(req);
        if (resp->statusCode() != 200) 
        {
            std::string errorBody(resp->body().data(), resp->body().length());
            throw std::runtime_error("OpenTopography API Failed with status: " + std::to_string(resp->statusCode()) + " | Reason: " + errorBody);
        }
        
        co_return std::vector<uint8_t>(
            reinterpret_cast<const uint8_t*>(resp->body().data()), 
            reinterpret_cast<const uint8_t*>(resp->body().data()) + resp->body().length()
        );
    }
    
    if (tag == "bhuvan") 
    {
        auto client = getBhuvanClient(); // Uses persistent Keep-Alive connection
        
        // FIX 2: OGC WCS 1.0.0 requires uppercase CRS and BBOX
        std::string path = "/bhuvan/wcs?service=WCS&version=1.0.0&request=GetCoverage"
                           "&coverage=bhuvan_cartodem&CRS=EPSG:4326&format=image/tiff"
                           "&BBOX=" + std::to_string(context.minLon) + "," + std::to_string(context.minLat) + "," + 
                           std::to_string(context.maxLon) + "," + std::to_string(context.maxLat);
        
        auto req = drogon::HttpRequest::newHttpRequest();
        req->setPath(path);
        req->setMethod(drogon::Get);
        
        auto resp = co_await client->sendRequestCoro(req);
        if (resp->statusCode() != 200) 
        {
            std::string errorBody(resp->body().data(), resp->body().length());
            throw std::runtime_error("ISRO Bhuvan WCS Failed with status: " + std::to_string(resp->statusCode()) + " | Reason: " + errorBody);
        }

        // ADD THIS CHECK:
        std::string responseString(resp->body().data(), resp->body().length());
        if (responseString.find("ServiceException") != std::string::npos || 
            responseString.find("<?xml") != std::string::npos) 
        {
            throw std::runtime_error("ISRO Bhuvan WCS returned an XML error instead of a TIFF: " + responseString);
        }
        
        co_return std::vector<uint8_t>(
            reinterpret_cast<const uint8_t*>(resp->body().data()), 
            reinterpret_cast<const uint8_t*>(resp->body().data()) + resp->body().length()
        );
    }

    throw std::runtime_error("Invalid Tag specified for ReferenceDemService: " + tag);
}