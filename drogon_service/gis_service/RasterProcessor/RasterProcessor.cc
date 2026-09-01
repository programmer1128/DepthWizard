#include "RasterProcessor.h"

#include <gdal_utils.h>
#include <cpl_vsi.h>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <cstdlib>
#include <drogon/utils/Utilities.h>

// helper functions

std::vector<std::string> RasterProcessor::buildWarpArgs(const GDALDatasetPtr& hInputDS)
{
    // build the string configuration for warping the fetched tile

    // physical pixel dimensions of the target
    int target_W = hInputDS->GetRasterXSize(); // width
    int target_H = hInputDS->GetRasterYSize(); // height

    // geoTransform holds 6 numbers: top-left coordinates, pixel width, pixel height
    double geoTransform[6];
    hInputDS->GetGeoTransform(geoTransform);

    // next we build the list of string arguments

    std::vector<std::string> warpArgs = {
        "-ts", std::to_string(target_W), std::to_string(target_H), // to match pixel width and height exactly

        "-te", // target extent (cropping the bounding box): min x, min y, max x, max y
        std::to_string(geoTransform[0]),        // min x: left edge
        std::to_string(geoTransform[3] + (target_H * geoTransform[5])),     // min y: bottom edge
        std::to_string(geoTransform[0] + (target_W * geoTransform[1])),     // max x: right edge
        std::to_string(geoTransform[3]),        // max y: top edge

        "-t_srs", hInputDS->GetProjectionRef(),  // force the CRS of warped tile to match user's image

        "-r", "bilinear"  // smoothes out 30m blocks into a fine, smooth gradient after stretching to match high resolution of user's image
    };

    return warpArgs;
}

GDALDatasetPtr RasterProcessor::executeWarp(const GDALDatasetPtr& hDemDS, const std::vector<std::string>& warpArgs, const std::string& outPath)
{
    // to execute the warping process on fetched tile

    // to convert std::vector<std::string> into string list that GDAL needs
    char** papszWarpArgs = nullptr;
    for(const auto& arg : warpArgs)
    {
        papszWarpArgs = CSLAddString(papszWarpArgs, arg.c_str());
    }

    // load these arguments into GDAL options object
    GDALWarpAppOptions* warpOptions = GDALWarpAppOptionsNew(papszWarpArgs, nullptr);

    // GDAL's core C functions require array of raw pointers
    // we temporarily extract the raw pointer just for GDALWarp function call
    GDALDataset* rawDemPtr = hDemDS.get();

    // mathematically stretch the hDemDS and save it to outPath (/vsimem/)
    // immediately wrap the GDALDataset object and make hOutDS point to it
    GDALDatasetPtr hOutDS(static_cast<GDALDataset*>(
        GDALWarp(outPath.c_str(), nullptr, 1, (GDALDatasetH*)&rawDemPtr, warpOptions, nullptr)
    ));

    // cleanup configuration objects: as these are not unique_ptr
    GDALWarpAppOptionsFree(warpOptions);
    CSLDestroy(papszWarpArgs);

    if (!hOutDS) 
    {
        throw std::runtime_error("RasterProcessor: GDALWarp failed to stretch the DEM.");
    }

    return hOutDS; // no need for std::move as return values are automatically moved
}

std::vector<float> RasterProcessor::extractFloatMatrix(const GDALDatasetPtr& hOutDS, int width, int height)
{
    // argument is a pointer to the warped tile object
    // here we ultimately build the float vector and return it

    // we grab the first band of the image: elevation height in meters
    GDALRasterBand* demBand = hOutDS->GetRasterBand(1);

    // now we find out what number is used when satellite fails to record data
    int hasNoData;
    double noDataValue = demBand->GetNoDataValue(&hasNoData);

    // GDAL's RasterIO function copies millions of pixels in a single memory block transfer
    // we pre-size the array and let GDAL fill it with data
    std::vector<float> final_matrix(width * height);

    // now fill the data from the warped image directly to this matrix
    CPLErr err = demBand->RasterIO(GF_Read, 0, 0, width, height,            // read from x:0, y:0 to width, height
                                   final_matrix.data(), width, height,      // write into our C++ vector
                                   GDT_Float32, 0, 0);                      // specify that we want float32 numbers
    
    if (err != CE_None) {
        throw std::runtime_error("RasterProcessor: Failed to read pixel data from warped DEM.");
    }
    
    // NoData filtering 

    // if the data contains invalid "NoData" pixels (-32768)
    // convert them to NaN (Not a Number)

    if(hasNoData)
    {
        for (size_t i = 0; i < final_matrix.size(); i++) 
        {
            if (final_matrix[i] == static_cast<float>(noDataValue)) 
            {
                final_matrix[i] = std::numeric_limits<float>::quiet_NaN();
            }
        }
    }

    return final_matrix;
}

// main function

std::vector<float> RasterProcessor::processor(GDALDatasetPtr hInputDS, GDALDatasetPtr hDemDS)
{
    // we write a new RAM file location where the warped DEM will be stored using vsimem
    std::string out_warped_dem = "/vsimem/warped_dem_" + drogon::utils::getUuid() + ".tif";

    try
    {
        // build the warp arguments based on user's image
        // pass the unique_ptr directly

        std::vector<std::string> warpArgs = buildWarpArgs(hInputDS);

        // now execute the warp
        // brand new dataset gets stored in warped_dem.tif and we get a pointer to this dataset: hOutDS

        GDALDatasetPtr hOutDS = executeWarp(hDemDS, warpArgs, out_warped_dem);

        // extract the physical width and height in pixels from the user's image
        int target_W = hInputDS->GetRasterXSize();
        int target_H = hInputDS->GetRasterYSize();

        // extract the warped image pixels into a float vector

        std::vector<float> final_matrix = extractFloatMatrix(hOutDS, target_W, target_H);

        // cleanup virtual RAM files
        VSIUnlink(out_warped_dem.c_str());

        return final_matrix;

    }
    catch(const std::exception& e)
    {
        // if anything fails, still cleanup the virtual RAM files
        VSIUnlink(out_warped_dem.c_str());

        throw; // Re-throw the error to the controller
    }
}