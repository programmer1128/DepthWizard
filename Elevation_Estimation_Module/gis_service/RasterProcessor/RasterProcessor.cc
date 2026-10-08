// implements GDAL-based warping using in-memory virtual filesystems (/vsimem/)

#include "RasterProcessor.h"
#include <gdal_utils.h>
#include <cpl_vsi.h>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <drogon/utils/Utilities.h>


// building the warp arguments
std::vector<std::string> RasterProcessor::buildWarpArgsFromMetadata(const SpatialMetadata& metadata)
{
    int target_W = metadata.width;
    int target_H = metadata.height;
    const double* gt = metadata.geoTransform.data();

    // affine transform coordinate derivation:
    // min_x = gt[0] (left border)
    // max_x = gt[0] + width * gt[1] (right border)
    // max_y = gt[3] (top border)
    // min_y = gt[3] + height * gt[5] (bottom border, since gt[5] is negative pixel height)
    double min_x = gt[0];
    double max_x = gt[0] + (target_W * gt[1]);
    double max_y = gt[3];
    double min_y = gt[3] + (target_H * gt[5]);

    // to ensure min_y is smaller than max_y
    if (min_y > max_y)
    {
        std::swap(min_y, max_y);
    }
    if (min_x > max_x)
    {
        std::swap(min_x, max_x);
    }

    std::vector<std::string> warpArgs = {
        "-ts", std::to_string(target_W), std::to_string(target_H), // exact pixel grid matching
        "-te", std::to_string(min_x), std::to_string(min_y), std::to_string(max_x), std::to_string(max_y), // bounding extent
        "-t_srs", metadata.projectionRef,   // target CRS matching optical image
        "-r", "bilinear",       // bilinear resampling for smooth topography
        "-wm", "500",         // 500 MB GDAL Warp memory allocation
        "-multi",                 // for asynchronous I/O
        "-wo", "NUM_THREADS=ALL_CPUS"          // multi-core parallel warping
    };

    return warpArgs;
}


// executing the warp
GDALDatasetPtr RasterProcessor::executeWarpInternal(
    const GDALDatasetPtr& hDemDS, 
    const std::vector<std::string>& warpArgs, 
    const std::string& outPath)
{
    if (!hDemDS)
    {
        throw std::invalid_argument("RasterProcessor: Source DEM dataset pointer is null");
    }

    // to convert C++ string list into char* array for GDAL C-API
    char** papszWarpArgs = nullptr;
    for (const auto& arg : warpArgs)
    {
        papszWarpArgs = CSLAddString(papszWarpArgs, arg.c_str());
    }

    GDALWarpAppOptions* warpOptions = GDALWarpAppOptionsNew(papszWarpArgs, nullptr);
    GDALDataset* rawDemPtr = hDemDS.get();

    // reproject directly into RAM disk path (/vsimem/)
    GDALDatasetPtr hOutDS(static_cast<GDALDataset*>(
        GDALWarp(outPath.c_str(), nullptr, 1, (GDALDatasetH*)&rawDemPtr, warpOptions, nullptr)
    ));

    GDALWarpAppOptionsFree(warpOptions);
    CSLDestroy(papszWarpArgs);

    if (!hOutDS)
    {
        throw std::runtime_error("RasterProcessor: Reprojection and resampling failed in GDALWarp.");
    }

    return hOutDS;
}

// extracting the warped DEM to RasterGrid<float>
RasterGrid<float> RasterProcessor::extractFloatGrid(const GDALDatasetPtr& hOutDS, int width, int height)
{
    GDALRasterBand* demBand = hOutDS->GetRasterBand(1);

    int hasNoData = 0;
    double noDataValue = demBand->GetNoDataValue(&hasNoData);

    RasterGrid<float> grid;
    grid.width = width;
    grid.height = height;
    grid.data.resize(static_cast<size_t>(width) * height);

    // fast block memory read directly into vector
    CPLErr err = demBand->RasterIO(
        GF_Read, 0, 0, width, height, 
        grid.data.data(), width, height, 
        GDT_Float32, 0, 0
    );

    if (err != CE_None)
    {
        throw std::runtime_error("RasterProcessor: RasterIO failed to read elevation pixels from warped DEM");
    }

    // to convert any satellite NoData into NaN
    if (hasNoData)
    {
        const float void_val = static_cast<float>(noDataValue);
        const float nan_val = std::numeric_limits<float>::quiet_NaN();
        float* ptr = grid.data.data();
        size_t total = grid.data.size();

        for (size_t i = 0; i < total; ++i)
        {
            if (ptr[i] == void_val)
            {
                ptr[i] = nan_val;
            }
        }
    }

    return grid;
}


// main orchestrator function
RasterGrid<float> RasterProcessor::warpDemToScene(
    const GDALDatasetPtr& demDataset, 
    const SpatialMetadata& metadata)
{
    std::string vsiOutPath = "/vsimem/warped_scene_" + drogon::utils::getUuid() + ".tif";

    try
    {
        std::vector<std::string> warpArgs = buildWarpArgsFromMetadata(metadata);
        GDALDatasetPtr hOutDS = executeWarpInternal(demDataset, warpArgs, vsiOutPath);

        RasterGrid<float> resultGrid = extractFloatGrid(hOutDS, metadata.width, metadata.height);

        // to delete the temporary virtual memory file
        VSIUnlink(vsiOutPath.c_str());

        return resultGrid;
    }
    catch (...)
    {
        VSIUnlink(vsiOutPath.c_str());
        throw;
    }
}

// for compare service / backward compatibility
std::vector<float> RasterProcessor::processor(GDALDatasetPtr hInputDS, GDALDatasetPtr hDemDS)
{
    SpatialMetadata meta;
    meta.width = hInputDS->GetRasterXSize();
    meta.height = hInputDS->GetRasterYSize();
    hInputDS->GetGeoTransform(meta.geoTransform.data());
    meta.projectionRef = hInputDS->GetProjectionRef();

    RasterGrid<float> warped = warpDemToScene(hDemDS, meta);
    return warped.data;
}