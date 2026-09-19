// high-speed geospatial raster warping and resampling routines
// transforms low resolution Copernicus/SRTM DEMs to align pixel-for-pixel with 
// the high resolution optical image's CRS and bounding box

#pragma once

#include <gdal_priv.h>
#include <vector>
#include <string>
#include <memory>
#include "../utils/GisTypes.h"
#include "../structures/CommonTypes.h"

class RasterProcessor
{
    public:
    
    // warps and resamples an input reference DEM directly onto the spatial grid 
    // defined by the optical image's SpatialMetadata
    // demDataset: managed GDAL pointer to the raw reference DEM (Copernicus or SRTM)
    // metadata: spatial dimensions, affine GeoTransform and CRS projection of the optical scene
    
    // RasterGrid<float>: 1D continuous float buffer representing the resampled DEM, 
    // guaranteed to match the target scene width and height exactly
    static RasterGrid<float> warpDemToScene(
        const GDALDatasetPtr& demDataset, 
        const SpatialMetadata& metadata);


    // kept for backward compatibility with the HeightQueryController / CompareService
    static std::vector<float> processor(GDALDatasetPtr hInputDS, GDALDatasetPtr hDemDS);


    // constructs the command-line style arguments required by GDALWarpAppOptions
    // configures target resolution, bounding box bounds (-te), target SRS, 
    // bilinear interpolation, memory cache and CPU thread parallelism
    static std::vector<std::string> buildWarpArgsFromMetadata(const SpatialMetadata& metadata);

    
    // invokes GDALWarp to reproject and resample the source raster into virtual RAM (/vsimem/)
    static GDALDatasetPtr executeWarpInternal(
        const GDALDatasetPtr& hDemDS, 
        const std::vector<std::string>& warpArgs, 
        const std::string& outPath);


    // reads band 1 from the warped dataset into a RasterGrid<float> and converts 
    // satellite NoData flags into quiet NaN
    static RasterGrid<float> extractFloatGrid(
        const GDALDatasetPtr& hOutDS, 
        int width, 
        int height);
};