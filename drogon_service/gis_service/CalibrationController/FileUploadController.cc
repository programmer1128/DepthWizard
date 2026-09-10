#include "FileUploadController.h"
#include <drogon/MultiPart.h>

FileUploadController::FileUploadController() {
    storageService_ = std::make_unique<FileSystemStorageService>("upload-dir");
}

void FileUploadController::uploadChunk(
    const drogon::HttpRequestPtr &req,
    std::function<void(const drogon::HttpResponsePtr &)> &&callback) {

    if (req->method() == drogon::Options) {
        auto resp = drogon::HttpResponse::newHttpResponse();
        resp->addHeader("Access-Control-Allow-Origin", "*");
        resp->addHeader("Access-Control-Allow-Methods", "POST, OPTIONS");
        resp->addHeader("Access-Control-Allow-Headers", "*");
        callback(resp);
        return;
    }

    drogon::MultiPartParser fileUpload;
    if (fileUpload.parse(req) != 0) {
        Json::Value json;
        json["message"] = "Invalid multipart/form-data request.";
        auto resp = drogon::HttpResponse::newHttpJsonResponse(json);
        resp->setStatusCode(drogon::k400BadRequest);
        resp->addHeader("Access-Control-Allow-Origin", "*");
        callback(resp);
        return;
    }

    const auto &files = fileUpload.getFiles();
    const auto &params = fileUpload.getParameters();

    if (files.empty() || 
        params.find("chunkIndex") == params.end() ||
        params.find("totalChunks") == params.end() ||
        params.find("fileName") == params.end() ||
        params.find("uploadId") == params.end()) {

        Json::Value json;
        json["message"] = "Missing required form fields or chunk payload.";
        auto resp = drogon::HttpResponse::newHttpJsonResponse(json);
        resp->setStatusCode(drogon::k400BadRequest);
        resp->addHeader("Access-Control-Allow-Origin", "*");
        callback(resp);
        return;
    }

    try {
        const drogon::HttpFile &chunk = files[0];
        int chunkIndex = std::stoi(params.at("chunkIndex"));
        int totalChunks = std::stoi(params.at("totalChunks"));
        std::string fileName = params.at("fileName");
        std::string uploadId = params.at("uploadId");

        storageService_->storeChunk(chunk, chunkIndex, totalChunks, fileName, uploadId);

        Json::Value json;
        json["message"] = "Chunk " + std::to_string(chunkIndex) + " received.";
        auto resp = drogon::HttpResponse::newHttpJsonResponse(json);
        resp->addHeader("Access-Control-Allow-Origin", "*");
        callback(resp);
    } catch (const std::exception &e) {
        Json::Value json;
        json["message"] = std::string("Failed to upload chunk: ") + e.what();
        auto resp = drogon::HttpResponse::newHttpJsonResponse(json);
        resp->setStatusCode(drogon::k500InternalServerError);
        resp->addHeader("Access-Control-Allow-Origin", "*");
        callback(resp);
    }
}