#include "MiniIOClient.h"
#include <aws/core/Aws.h>
#include <aws/s3/S3Client.h>
#include <aws/s3/model/PutObjectRequest.h>
#include <aws/core/auth/AWSCredentialsProvider.h>
#include <iostream>
#include <memory>
#include <stdlib.h> // Required for setenv and getenv
#include <fstream>  // Required for reading .env file
#include <string>   // Required for string manipulation

// Global SDK instances
static Aws::SDKOptions awsOptions;
static std::shared_ptr<Aws::S3::S3Client> s_s3Client;

// Helper function to safely trim whitespace, quotes, and \r
static std::string trim(const std::string &str)
{
    size_t first = str.find_first_not_of(" \t\r\n\"");
    if (first == std::string::npos)
        return "";
    size_t last = str.find_last_not_of(" \t\r\n\"");
    return str.substr(first, (last - first + 1));
}

// Cross-platform environment variable setter
static void setEnvVar(const std::string &key, const std::string &value)
{
#ifdef _WIN32
    _putenv_s(key.c_str(), value.c_str());
#else
    setenv(key.c_str(), value.c_str(), 1);
#endif
}

// Helper function to load .env variables
static void loadEnv(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "[Warning] Could not open " << filename << ". Relying on existing system environment variables." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::string trimmedLine = trim(line);

        // skipping empty lines and comments
        if (trimmedLine.empty() || trimmedLine[0] == '#')
            continue;

        auto delimiterPos = trimmedLine.find('=');
        if (delimiterPos != std::string::npos)
        {
            std::string key = trim(trimmedLine.substr(0, delimiterPos));
            std::string value = trim(trimmedLine.substr(delimiterPos + 1));
            setEnvVar(key, value);
        }
    }
}

void MinioClient::initAPI()
{
    // credentials loaded from .env file
    loadEnv(".env");

    // retrieving credentials using getenv
    const char *accessKeyEnv = std::getenv("MINIO_ACCESS_KEY");
    const char *secretKeyEnv = std::getenv("MINIO_SECRET_KEY");

    // fallback handling if variables are missing
    Aws::String minioAccessKey = accessKeyEnv ? accessKeyEnv : "";
    Aws::String minioSecretKey = secretKeyEnv ? secretKeyEnv : "";

    if (minioAccessKey.empty() || minioSecretKey.empty())
    {
        std::cerr << "[Error] MINIO_ACCESS_KEY or MINIO_SECRET_KEY not found in .env!" << std::endl;
        return;
    }

    // 1. cross-platform helper to completely disable the 4-second IMDS black-hole timeout
    setEnvVar("AWS_EC2_METADATA_DISABLED", "true");

    // 1. HARD BYPASS: Completely disable the 4-second IMDS black-hole timeout
    // setenv("AWS_EC2_METADATA_DISABLED", "true", 1);

    Aws::InitAPI(awsOptions);

    // 2. Initialize the S3 Client ONCE for the entire application lifecycle
    Aws::Client::ClientConfiguration clientConfig;
    clientConfig.endpointOverride = "127.0.0.1:9000";
    clientConfig.scheme = Aws::Http::Scheme::HTTP;
    clientConfig.region = "us-east-1";

    // Passing the retrieved environment variables to AWSCredentials
    Aws::Auth::AWSCredentials credentials(minioAccessKey,
                                          minioSecretKey);

    // Allocate the client to the global shared pointer
    s_s3Client = Aws::MakeShared<Aws::S3::S3Client>(
        "MinioInit",
        credentials,
        clientConfig,
        Aws::Client::AWSAuthV4Signer::PayloadSigningPolicy::Never,
        false);

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
    const std::string &bucketName,
    const std::string &objectKey,
    const std::vector<uint8_t> &buffer,
    const std::string &contentType)
{
    if (!s_s3Client)
        return false;

    Aws::S3::Model::PutObjectRequest request;
    request.SetBucket(bucketName);
    request.SetKey(objectKey);
    request.SetContentType(contentType);

    // 3. OPTIMIZATION: Tell the SDK exactly how large the file is
    // so it doesn't have to scan the RAM buffer to figure it out
    request.SetContentLength(buffer.size());

    auto stream = Aws::MakeShared<Aws::StringStream>("MinioUpload");
    stream->write(reinterpret_cast<const char *>(buffer.data()), buffer.size());
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
    const std::string &bucketName,
    const std::string &objectKey,
    int expirationSeconds)
{
    if (!s_s3Client)
        return "";

    // Use the global client
    return s_s3Client->GeneratePresignedUrl(
        bucketName,
        objectKey,
        Aws::Http::HttpMethod::HTTP_GET,
        expirationSeconds);
}