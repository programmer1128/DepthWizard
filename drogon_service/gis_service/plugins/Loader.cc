/**
 *
 *  Loader.cc
 *
 */

#include "Loader.h"
#include "../SrtmExtractor/SrtmExtractor.h"
#include "../DataHandlers/MiniIOClient.h"
#include <trantor/utils/Logger.h>

using namespace drogon;

void Loader::initAndStart(const Json::Value &config)
{
    LOG_INFO << "Starting GDAL Initialization Plugin...";
    
    initGDAL();
    LOG_INFO << "GDAL configured successfully for multi-threaded AWS fetching.";

    //miniIO client settings
    MinioClient::initAPI();
    LOG_INFO << "MinIO/AWS SDK configured successfully.";
}

void Loader::shutdown() 
{
    LOG_INFO << "Shutting down GDAL Plugin...";
    
    GDALDestroyDriverManager();

    LOG_INFO<<"Shutting down MiniIO client";
    MinioClient::shutdownAPI();
}
