#pragma once
#include <vector>
#include <string>
#include <cstdint>

class MinioClient 
{
public:
    static void initAPI();
    static void shutdownAPI();

    // Uploads a raw byte array directly to a MinIO bucket
    static bool uploadBuffer(
        const std::string& bucketName, 
        const std::string& objectKey, 
        const std::vector<uint8_t>& buffer, 
        const std::string& contentType
    );

    // Generates a Pre-Signed URL for Unity to download the file directly
    static std::string generatePresignedUrl(
        const std::string& bucketName, 
        const std::string& objectKey, 
        int expirationSeconds = 3600
    );
};