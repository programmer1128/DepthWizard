#include "Sat2Lod2ModalTransport.h"

#include <drogon/utils/Utilities.h>
#include <cstdint>
#include <filesystem>
#include <fstream>
#include <limits>
#include <stdexcept>

drogon::HttpRequestPtr Sat2Lod2ModalTransport::makeRequest(
    const std::string& ndsmPath,
    const std::string& orthoTiffPath,
    const std::string& labelPath)
{
    const std::string boundary = "DepthWizardSat2Lod2" + drogon::utils::getUuid();
    std::string body;
    const auto addFile = [&](const std::string& path, const char* itemName,
                             const char* fileName)
    {
        std::ifstream file(path, std::ios::binary);
        if (!file)
            throw std::runtime_error("Cannot open SAT2LoD2 upload: " + path);
        const auto fileSize = std::filesystem::file_size(path);
        if (fileSize > static_cast<std::uintmax_t>(
                           std::numeric_limits<std::streamsize>::max()))
            throw std::runtime_error("SAT2LoD2 upload is too large: " + path);
        body += "--" + boundary + "\r\n";
        body += "Content-Disposition: form-data; name=\"";
        body += itemName;
        body += "\"; filename=\"";
        body += fileName;
        body += "\"\r\nContent-Type: image/tiff\r\n\r\n";
        const auto offset = body.size();
        body.resize(offset + static_cast<std::size_t>(fileSize));
        file.read(body.data() + offset, static_cast<std::streamsize>(fileSize));
        if (!file)
            throw std::runtime_error("Cannot read SAT2LoD2 upload: " + path);
        body += "\r\n";
    };
    addFile(ndsmPath, "dsm", "ndsm.tif");
    addFile(orthoTiffPath, "ortho", "ortho.tif");
    addFile(labelPath, "label", "label.tif");
    body += "--" + boundary + "--\r\n";

    auto request = drogon::HttpRequest::newHttpRequest();
    request->setMethod(drogon::Post);
    request->setPath("/api/v1/reconstruct");
    // Must replace drogon's default content type. addHeader("content-type")
    // sends a second header after "text/plain"; FastAPI reads the first,
    // finds no file parts and rejects the job with 422.
    request->setContentTypeString("multipart/form-data; boundary=" + boundary);
    request->setBody(std::move(body));
    return request;
}

Json::Value Sat2Lod2ModalTransport::readBuildings(
    const drogon::HttpResponsePtr& response)
{
    if (!response)
        throw std::runtime_error("Modal SAT2LoD2 returned no HTTP response");
    if (response->statusCode() != drogon::k200OK)
        throw std::runtime_error(
            "Modal SAT2LoD2 HTTP " +
            std::to_string(static_cast<int>(response->statusCode())) + ": " +
            std::string(response->body().substr(0, 512)));
    const auto& document = response->getJsonObject();
    if (!document || !(*document)["buildings"].isObject() ||
        !(*document)["buildings"]["segments"].isArray())
        throw std::runtime_error("Modal SAT2LoD2 returned no building document");
    return (*document)["buildings"];
}
