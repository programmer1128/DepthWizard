#include "MiniIOClient.h"
#include <aws/core/Aws.h>
#include <aws/s3/S3Client.h>
#include <aws/s3/model/PutObjectRequest.h>
#include <aws/core/auth/AWSCredentialsProvider.h>
#include <iostream>
#include <memory>
#include <stdlib.h> // Required for setenv

// Global SDK instances
static Aws::SDKOptions awsOptions;
static std::shared_ptr<Aws::S3::S3Client> s_s3Client;

void MinioClient::initAPI() 
{
    // 1. HARD BYPASS: Completely disable the 4-second IMDS black-hole timeout
    setenv("AWS_EC2_METADATA_DISABLED", "true", 1);

    Aws::InitAPI(awsOptions);

    // 2. Initialize the S3 Client ONCE for the entire application lifecycle
    Aws::Client::ClientConfiguration clientConfig;
    clientConfig.endpointOverride = "127.0.0.1:9000";
    clientConfig.scheme = Aws::Http::Scheme::HTTP;
    clientConfig.region = "us-east-1"; 

    Aws::Auth::AWSCredentials credentials("9490b5330aebc7f8088a", 
         "6z+Xd9fn5ndPHHlNW9jbtK8xF6y9MxfRDW9PQ6ewsrI=");
    
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