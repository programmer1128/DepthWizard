#include "ReferenceDemService.h"
#include <drogon/HttpClient.h>

#include <cstdlib>
#include <sstream>

namespace
{
// Copernicus GLO-30, as in the validation script: better than SRTM on steep
// terrain and a surface model like ours.
constexpr const char* kOpenTopographyDataset = "COP30";
constexpr double kRequestTimeoutSeconds = 120.0;

drogon::HttpClientPtr openTopographyClient()
{
     static auto client = drogon::HttpClient::newHttpClient("https://portal.opentopography.org");
     return client;
}

drogon::HttpClientPtr bhuvanClient()
{
     static auto client = drogon::HttpClient::newHttpClient("https://bhuvan-vec1.nrsc.gov.in");
     return client;
}

std::string openTopographyKey()
{
     const char* key = std::getenv("OPENTOPOGRAPHY_API_KEY");
     return key && *key ? key : "9edec22bf8fbc738f1e6e5189a8c188f";
}

std::string coordinate(double value)
{
     std::ostringstream text;
     text.precision(9);
     text << std::fixed << value;
     return text.str();
}

std::vector<uint8_t> bodyBytes(const drogon::HttpResponsePtr& response)
{
     const auto body = response->body();
     return std::vector<uint8_t>(body.begin(), body.end());
}
} // namespace

drogon::Task<ReferenceDem> ReferenceDemService::fetchReference(
     const std::string& tag, const GeoBounds& bounds, const drogon::HttpFile* uploadedFile)
{
     if (tag == "upload")
     {
         if (uploadedFile == nullptr)
             throw std::invalid_argument("tag 'upload' requires a reference GeoTIFF file");
         co_return ReferenceDem{
             std::vector<uint8_t>(uploadedFile->fileData(),
                                  uploadedFile->fileData() + uploadedFile->fileLength()),
             "uploaded reference"};
     }

     if (tag == "opentopography")
     {
         auto request = drogon::HttpRequest::newHttpRequest();
         request->setMethod(drogon::Get);
         request->setPath("/API/globaldem?demtype=" + std::string(kOpenTopographyDataset) +
                          "&south=" + coordinate(bounds.minLat) +
                          "&north=" + coordinate(bounds.maxLat) +
                          "&west=" + coordinate(bounds.minLon) +
                          "&east=" + coordinate(bounds.maxLon) +
                          "&outputFormat=GTiff&API_Key=" + openTopographyKey());
         const auto response = co_await openTopographyClient()->sendRequestCoro(
             request, kRequestTimeoutSeconds);
         if (!response || response->statusCode() != drogon::k200OK)
             throw ReferenceDemUnavailable(
                 "OpenTopography request failed" +
                 (response ? " (HTTP " + std::to_string(static_cast<int>(response->statusCode())) +
                                 "): " + std::string(response->body().substr(0, 300))
                           : std::string(": no response")));
         co_return ReferenceDem{bodyBytes(response), kOpenTopographyDataset};
     }

     if (tag == "bhuvan")
     {
         // OGC WCS 1.0.0 requires uppercase CRS and BBOX.
         auto request = drogon::HttpRequest::newHttpRequest();
         request->setMethod(drogon::Get);
         request->setPath("/bhuvan/wcs?service=WCS&version=1.0.0&request=GetCoverage"
                          "&coverage=bhuvan_cartodem&CRS=EPSG:4326&format=image/tiff&BBOX=" +
                          coordinate(bounds.minLon) + "," + coordinate(bounds.minLat) + "," +
                          coordinate(bounds.maxLon) + "," + coordinate(bounds.maxLat));
         const auto response = co_await bhuvanClient()->sendRequestCoro(
             request, kRequestTimeoutSeconds);
         if (!response || response->statusCode() != drogon::k200OK)
             throw ReferenceDemUnavailable(
                 "ISRO Bhuvan WCS request failed" +
                 (response ? " (HTTP " + std::to_string(static_cast<int>(response->statusCode())) + ")"
                           : std::string(": no response")));
         co_return ReferenceDem{bodyBytes(response), "CartoDEM"};
     }

     throw std::invalid_argument("Unknown reference dataset tag: " + tag);
}
