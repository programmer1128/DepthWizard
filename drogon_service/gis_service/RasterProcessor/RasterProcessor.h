#pragma once

#include <gdal_priv.h>
#include <vector>
#include <string>
#include <memory>

// custom deleter to delete GDALDataset object on going out of scope

struct GDALDatasetDeleter
{
    void operator()(GDALDataset* ds) const // acts as functor: function object
    {
        if(ds) // not a nullptr
        {
            GDALClose(ds);
        }
    }
};

// alias to avoid writing unique_ptr syntax every time

using GDALDatasetPtr = std::unique_ptr<GDALDataset, GDALDatasetDeleter>;

class RasterProcessor
{
    public:

    // helper functions

    // build the string configuration needed to warp the received Copernicus / SRTM tile
    // returns the string configuration for warp
    static std::vector<std::string> buildWarpArgs(const GDALDatasetPtr& hInputDS);

    // execute the warping algorithm and store the warped tile in RAM using vsimem
    // returns the GDALDatasetPtr to the warped tile (GDALDataset object)
    static GDALDatasetPtr executeWarp(const GDALDatasetPtr& hDemDS, const std::vector<std::string>& warpArgs, const std::string& outPath);

    // pulls the raw pixel data from the warped tile into a float 32 vector
    // returns the float vector - flattened matrix
    static std::vector<float> extractFloatMatrix(const GDALDatasetPtr& hOutDS, int width, int height);

    // main function 

    // takes ownership by value of the hInputDS and hDemDS from controller 
    // returns the float vector
    static std::vector<float> processor(GDALDatasetPtr hInputDS, GDALDatasetPtr hDemDS);
};