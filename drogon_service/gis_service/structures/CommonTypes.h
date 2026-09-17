#pragma once

#include <string>
#include <array>

//enum for the img format
enum class PipelineMode 
{
     GEOREFERENCED,
     RELATIVE
};

//enum for job status. drogon uses async thread system. so a job alloted
//to background thread goes with processing. job waiting for a thread goes for queued
//as drogon uses epoll queue for event processing system ready and failed denote end 
//result of a worker
enum class JobStatus 
{
     QUEUED,
     PROCESSING,
     READY,
     FAILED
};

//contiguous memory wrapper for 2D spatial data
template <typename T>
struct RasterGrid  
{
     int width{0};
     int height{0};
     std::vector<T> data;
};


//data transfer object to hold GDAL spatial context
struct SpatialMetadata 
{
     int width;
     int height;
     std::array<double, 6> geoTransform;
     std::string projectionRef;
};