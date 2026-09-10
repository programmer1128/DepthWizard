#include "FileSystemStorageService.h"
#include <trantor/utils/Logger.h>
#include <fstream>
#include <stdexcept>
#include <vector>
#include "../DataHandlers/MiniIOClient.h"

FileSystemStorageService::FileSystemStorageService(std::string location) {
    if (location.empty()) {
        throw std::runtime_error("File upload location cannot be empty.");
    }
    rootLocation_ = fs::absolute(location);
    fs::create_directories(rootLocation_);
}

void FileSystemStorageService::storeChunk(const drogon::HttpFile &chunk,
                                          int chunkIndex,
                                          int totalChunks,
                                          const std::string &fileName,
                                          const std::string &uploadId) {
    try {
        fs::path tempDir = rootLocation_ / ("temp_" + uploadId);
        fs::create_directories(tempDir);

        fs::path chunkPath = tempDir / ("chunk_" + std::to_string(chunkIndex));
        
        // Write the raw file slice directly to the exact target path
        std::ofstream chunkOut(chunkPath, std::ios::binary | std::ios::trunc);
        if (!chunkOut.is_open()) {
            throw std::runtime_error("Failed to create chunk file at: " + chunkPath.string());
        }
        chunkOut.write(chunk.fileData(), chunk.fileLength());
        chunkOut.close();

        LOG_INFO << "Saved chunk_" << chunkIndex << " in " << tempDir.string();
        assembleFileIfComplete(tempDir, fileName, totalChunks);
    } catch (const std::exception &e) {
        LOG_ERROR << "Failed to store chunk: " << e.what();
        throw;
    }
}

void FileSystemStorageService::assembleFileIfComplete(const fs::path &tempDir,
                                                      const std::string &fileName,
                                                      int totalChunks) {
    std::lock_guard<std::mutex> lock(assemblyMutex_);

    for (int i = 0; i < totalChunks; ++i) {
        if (!fs::exists(tempDir / ("chunk_" + std::to_string(i)))) {
            return;
        }
    }

    LOG_INFO << "Starting file assembly...";
    fs::path finalDestination = rootLocation_ / fileName;
    std::ofstream out(finalDestination, std::ios::binary | std::ios::trunc);

    if (!out.is_open()) {
        throw std::runtime_error("Failed to open destination file: " + finalDestination.string());
    }

    std::vector<char> buffer(64 * 1024);
    for (int i = 0; i < totalChunks; ++i) {
        fs::path chunkPath = tempDir / ("chunk_" + std::to_string(i));
        std::ifstream in(chunkPath, std::ios::binary);

        if (!in.is_open()) {
            throw std::runtime_error("Failed to read chunk: " + chunkPath.string());
        }

        while (in.read(buffer.data(), buffer.size()) || in.gcount() > 0) {
            out.write(buffer.data(), in.gcount());
        }
        in.close();

        LOG_INFO << "Copied chunk_" << i << " to " << finalDestination.string();
        fs::remove(chunkPath);
    }
    out.close();

    fs::remove_all(tempDir);
    LOG_INFO << "Copying done, temp dir deleted";

    LOG_INFO << "Starting upload to MinIO bucket: terrain-assets...";
    
    // Read the fully assembled file into a byte buffer
    std::ifstream fileToUpload(finalDestination, std::ios::binary | std::ios::ate);
    if (!fileToUpload.is_open()) {
        LOG_ERROR << "Failed to open assembled file for upload: " << finalDestination.string();
        return;
    }

    std::streamsize fileSize = fileToUpload.tellg();
    fileToUpload.seekg(0, std::ios::beg);

    std::vector<uint8_t> uploadBuffer(fileSize);
    if (fileToUpload.read(reinterpret_cast<char*>(uploadBuffer.data()), fileSize)) {
        fileToUpload.close();

        // Perform the upload
        bool success = MinioClient::uploadBuffer("terrain-assets", fileName, uploadBuffer, "application/octet-stream");
        
        if (success) {
            LOG_INFO << "Successfully uploaded " << fileName << " to terrain-assets bucket.";
        } else {
            LOG_ERROR << "Failed to upload " << fileName << " to terrain-assets bucket.";
        }
    } else {
        LOG_ERROR << "Failed to read the assembled file into memory for upload.";
        fileToUpload.close();
    }
}