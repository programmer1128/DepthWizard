// implements the GeoTIFF serialization logic with strict std::async 
// multi-threading to encode 8 high-resolution maps simultaneously in RAM

#include "TiffExporter.h"
#include <gdal_priv.h>
#include <iostream>
#include <cstring>
#include <future>
#include <optional>

std::vector<uint8_t> TiffExporter::exportTiffToBuffer(
    const std::string& uuid,
    const std::vector<float>& dsm_matrix, 
    int width, 
    int height,
    const double* geoTransform,
    const char* projectionRef,
    float noDataValue)
{ 
    GDALDriver *poDriver = GetGDALDriverManager()->GetDriverByName("GTiff");
    if (!poDriver) return {};

    // use the unique UUID to guarantee thread safety inside GDAL's virtual RAM filesystem
    std::string vsi_path = "/vsimem/export_" + uuid + ".tif";

    GDALDataset *poDstDS = poDriver->Create(vsi_path.c_str(), width, height, 1, GDT_Float32, nullptr);
    if (!poDstDS) return {};

    if (geoTransform != nullptr) poDstDS->SetGeoTransform(const_cast<double*>(geoTransform));
    if (projectionRef != nullptr && std::strlen(projectionRef) > 0) poDstDS->SetProjection(projectionRef);

    GDALRasterBand *poBand = poDstDS->GetRasterBand(1);
    poBand->SetNoDataValue(static_cast<double>(noDataValue)); // apply scientific NoData marker

    CPLErr err = poBand->RasterIO(GF_Write, 0, 0, width, height, 
                                  (void*)dsm_matrix.data(), width, height, GDT_Float32, 0, 0);

    GDALClose(poDstDS);

    if (err != CE_None) 
    {
        VSIUnlink(vsi_path.c_str());
        return {};
    }

    vsi_l_offset dataLength = 0;
    GByte* pabyData = VSIGetMemFileBuffer(vsi_path.c_str(), &dataLength, FALSE);

    if (!pabyData || dataLength == 0) 
    {
        VSIUnlink(vsi_path.c_str());
        return {};
    }

    std::vector<uint8_t> tiffBytes(pabyData, pabyData + dataLength);
    VSIUnlink(vsi_path.c_str()); // strict cleanup prevents memory leaks
    return tiffBytes;
}

std::vector<RasterArtifactBuffer> TiffExporter::exportProducts(
    const RasterProductSet& products,
    const SpatialMetadata& metadata,
    const std::string& jobId)
{
    std::vector<RasterArtifactBuffer> artifacts;

    // helper lambda to safely encode and package a specific grid concurrently
    // by returning an std::optional, we gracefully handle empty grids without thread crashes
    auto packageRasterAsync = [&](const RasterGrid<float>& grid, const std::string& type) -> std::optional<RasterArtifactBuffer> 
    {
        if (grid.isValid()) 
        {
            std::string filename = type + "_" + jobId + ".tif";
            
            // the unique string (jobId + "_" + type) prevents GDAL /vsimem/ race conditions
            std::vector<uint8_t> bytes = exportTiffToBuffer(
                jobId + "_" + type, 
                grid.data, 
                metadata.width, 
                metadata.height, 
                metadata.geoTransform.data(), 
                metadata.projectionRef.c_str(),
                products.noDataValue
            );

            if (!bytes.empty()) 
            {
                return RasterArtifactBuffer{type, filename, "image/tiff", std::move(bytes)};
            }
        }
        return std::nullopt;
    };

    // launch up to 8 distinct serialization threads asynchronously
    // std::cref guarantees the massive float matrices are passed by constant reference
    std::vector<std::future<std::optional<RasterArtifactBuffer>>> futures;
    
    futures.push_back(std::async(std::launch::async, packageRasterAsync, std::cref(products.dsm), "dsm"));
    futures.push_back(std::async(std::launch::async, packageRasterAsync, std::cref(products.dtm), "dtm"));
    futures.push_back(std::async(std::launch::async, packageRasterAsync, std::cref(products.ndsm), "ndsm"));
    futures.push_back(std::async(std::launch::async, packageRasterAsync, std::cref(products.slope), "slope"));
    futures.push_back(std::async(std::launch::async, packageRasterAsync, std::cref(products.aspect), "aspect"));
    futures.push_back(std::async(std::launch::async, packageRasterAsync, std::cref(products.hillshade), "hillshade"));
    futures.push_back(std::async(std::launch::async, packageRasterAsync, std::cref(products.confidence), "confidence"));

    if (products.canopyHeight.has_value()) 
    {
        futures.push_back(std::async(std::launch::async, packageRasterAsync, std::cref(products.canopyHeight.value()), "canopy"));
    }

    // wait for all threads to finish and collect their results safely on the main thread
    for (auto& f : futures) 
    {
        std::optional<RasterArtifactBuffer> res = f.get();
        if (res.has_value()) 
        {
            artifacts.push_back(std::move(res.value()));
        }
    }

    return artifacts;
}