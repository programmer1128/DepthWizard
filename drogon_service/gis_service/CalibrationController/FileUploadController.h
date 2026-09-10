#pragma once

#include <drogon/HttpController.h>
#include "FileSystemStorageService.h"
#include <memory>

class FileUploadController : public drogon::HttpController<FileUploadController> {
public:
    METHOD_LIST_BEGIN
    ADD_METHOD_TO(FileUploadController::uploadChunk, "/chunk", drogon::Post, drogon::Options);
    METHOD_LIST_END

    FileUploadController();

    void uploadChunk(const drogon::HttpRequestPtr &req,
                     std::function<void(const drogon::HttpResponsePtr &)> &&callback);

private:
    std::unique_ptr<FileSystemStorageService> storageService_;
};