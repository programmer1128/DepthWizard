#include "MiniIOClient.h"
#include <aws/core/Aws.h>
#include <aws/s3/S3Client.h>
#include <aws/s3/model/PutObjectRequest.h>
#include <aws/core/auth/AWSCredentialsProvider.h>
#include <iostream>
#include <trantor/utils/Logger.h>
#include <fstream>
#include <memory>
#include <json/json.h>
#include <stdlib.h> // Required for setenv

// Global SDK instances
static Aws::SDKOptions awsOptions;
static std::shared_ptr<Aws::S3::S3Client> s_s3Client;

void MinioClient::initAPI() 
{
    // 1. HARD BYPASS: Completely disable the 4-second IMDS black-hole timeout
    setenv("AWS_EC2_METADATA_DISABLED", "true", 1);

    Aws::InitAPI(awsOptions);

    // Default fallback values
    std::string endpoint = "127.0.0.1:9000";
    std::string accessKey = "testkey";
    std::string secretKey = "testkey";
    std::string region = "us-east-1";

    // 2. Attempt to load local git-ignored overrides
    std::ifstream localFile("config.local.json");
    if (localFile.is_open()) {
        Json::Value localConfig;
        Json::CharReaderBuilder builder;
        std::string errs;
        if (Json::parseFromStream(builder, localFile, &localConfig, &errs)) {
            if (!localConfig["minio_endpoint"].isNull()) {
                endpoint = localConfig["minio_endpoint"].asString();
                
            }
            if (!localConfig["minio_access_key"].isNull()) {
                accessKey = localConfig["minio_access_key"].asString();
            }
            if (!localConfig["minio_secret_key"].isNull()) {
                secretKey = localConfig["minio_secret_key"].asString();
            }
            if (!localConfig["minio_region"].isNull()) {
                region = localConfig["minio_region"].asString();
            }
            LOG_INFO << "minio_endpoint: " << endpoint;
            LOG_INFO << "access_key: " << accessKey;
            LOG_INFO << "secret_key: " << secretKey;
            LOG_INFO << "region: " << region;
        }
        else {
            LOG_ERROR << "Could not load config.local.json, using fallback credentials...";
        }
    }
    else {
        LOG_ERROR << "No config.local.json found, using fallback credentials...";
    }

    // 3. Configure the S3 Client using loaded settings
    Aws::Client::ClientConfiguration clientConfig;
    clientConfig.endpointOverride = endpoint;
    clientConfig.scheme = Aws::Http::Scheme::HTTP;
    clientConfig.region = region;

    Aws::Auth::AWSCredentials credentials(accessKey, secretKey);
    
    // Allocate the client to the global shared pointer
    s_s3Client = Aws::MakeShared<Aws::S3::S3Client>(
        "MinioInit",
        credentials, 
        clientConfig, 
        Aws::Client::AWSAuthV4Signer::PayloadSigningPolicy::Never, 
        false
    );

    std::cout << "[MinioClient] AWS SDK & Connection Pool Initialized." << std::endl;
}

void MinioClient::shutdownAPI() 
{
    // Destroy the client first to cleanly close the Keep-Alive connection pool
    s_s3Client.reset();
    
    Aws::ShutdownAPI(awsOptions);
    std::cout << "[MinioClient] AWS SDK Shut Down." << std::endl;
}

bool MinioClient::uploadBuffer(
    const std::string& bucketName, 
    const std::string& objectKey, 
    const std::vector<uint8_t>& buffer, 
    const std::string& contentType)
{
    if (!s_s3Client) return false;

    Aws::S3::Model::PutObjectRequest request;
    request.SetBucket(bucketName);
    request.SetKey(objectKey);
    request.SetContentType(contentType);
    
    // 3. OPTIMIZATION: Tell the SDK exactly how large the file is 
    // so it doesn't have to scan the RAM buffer to figure it out
    request.SetContentLength(buffer.size());

    auto stream = Aws::MakeShared<Aws::StringStream>("MinioUpload");
    stream->write(reinterpret_cast<const char*>(buffer.data()), buffer.size());
    request.SetBody(stream);

    // Use the global client
    auto outcome = s_s3Client->PutObject(request);

    if (!outcome.IsSuccess()) 
    {
        std::cerr << "MinIO Upload Error: " 
                  << outcome.GetError().GetExceptionName() << " - " 
                  << outcome.GetError().GetMessage() << std::endl;
        return false;
    }

    return true;
}

std::string MinioClient::generatePresignedUrl(
    const std::string& bucketName, 
    const std::string& objectKey, 
    int expirationSeconds)
{
    if (!s_s3Client) return "";

    // Use the global client
    return s_s3Client->GeneratePresignedUrl(
        bucketName, 
        objectKey, 
        Aws::Http::HttpMethod::HTTP_GET, 
        expirationSeconds
    );
}

/*
#include <aws/core/utils/memory/stl/AWSStreamFwd.h>
#include <fstream>

// ... [Keep existing initAPI, shutdownAPI, uploadBuffer methods] ...

bool MinioClient::uploadFileStream(
    const std::string& bucketName, 
    const std::string& objectKey, 
    const std::string& filePath, 
    const std::string& contentType)
{
    if (!s_s3Client) return false;

    Aws::S3::Model::PutObjectRequest request;
    request.SetBucket(bucketName);
    request.SetKey(objectKey);
    request.SetContentType(contentType);

    // Create an AWS file stream that reads directly from the disk
    auto inputData = Aws::MakeShared<Aws::FStream>("MinioUpload", filePath.c_str(), std::ios_base::in | std::ios_base::binary);
    
    if (!inputData->good()) {
        std::cerr << "MinIO Upload Error: Failed to open local file stream for " << filePath << std::endl;
        return false;
    }

    // Attach the file stream to the HTTP request body
    request.SetBody(inputData);

    auto outcome = s_s3Client->PutObject(request);

    if (!outcome.IsSuccess()) 
    {
        std::cerr << "MinIO Upload Error: " 
                  << outcome.GetError().GetExceptionName() << " - " 
                  << outcome.GetError().GetMessage() << std::endl;
        return false;
    }

    return true;
}
*/
