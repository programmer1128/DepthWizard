// serializes multiple high-resolution geographic raster layers directly 
// into standard GeoTIFF format memory buffers for GIS compatibility

#pragma once
#include <string>
#include <vector>
#include <cstdint>
#include "../structures/SurfaceStructs.h"

// struct to represent a singular encoded artifact ready for upload
struct RasterArtifactBuffer 
{
    std::string productType; // eg: "dsm", "dtm", "slope"
    std::string filename;    // eg: "dsm_1234-5678.tif"
    std::string mimeType;    // "image/tiff"
    std::vector<uint8_t> bytes; 
};

class TiffExporter 
{
public:
    // core memory exporter used by individual rasters
    static std::vector<uint8_t> exportTiffToBuffer(
        const std::string& uuid,
        const std::vector<float>& dsm_matrix, 
        int width, 
        int height,
        const double* geoTransform,
        const char* projectionRef,
        float noDataValue = -9999.0f);


    // takes the full suite of derived geographic layers and systematically encodes 
    // them into 8 separate GeoTIFF buffers natively in RAM

    static std::vector<RasterArtifactBuffer> exportProducts(
        const RasterProductSet& products,
        const SpatialMetadata& metadata,
        const std::string& jobId);
};