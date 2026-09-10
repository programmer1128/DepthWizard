#pragma once

#include <string>
#include <filesystem>
#include <mutex>
#include <drogon/HttpTypes.h>
#include <drogon/MultiPart.h>

namespace fs = std::filesystem;

class FileSystemStorageService {
public:
    explicit FileSystemStorageService(std::string location = "upload-dir");

    void storeChunk(const drogon::HttpFile &chunk,
                    int chunkIndex,
                    int totalChunks,
                    const std::string &fileName,
                    const std::string &uploadId);

private:
    fs::path rootLocation_;
    std::mutex assemblyMutex_;

    void assembleFileIfComplete(const fs::path &tempDir,
                                const std::string &fileName,
                                int totalChunks);
};