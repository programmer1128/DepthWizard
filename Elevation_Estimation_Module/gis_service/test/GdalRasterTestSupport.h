#pragma once

#include <cpl_conv.h>
#include <cpl_vsi.h>
#include <gdal_priv.h>
#include <ogr_spatialref.h>

#include <array>
#include <atomic>
#include <cstdint>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

namespace depthwizard::test
{

inline std::string uniqueVsiPath(const std::string& prefix)
{
    static std::atomic_uint64_t counter{0};
    return "/vsimem/" + prefix + "_" +
           std::to_string(counter.fetch_add(1)) + ".tif";
}

class VsiPathGuard
{
public:
    explicit VsiPathGuard(std::string path)
        : path_(std::move(path))
    {
    }

    VsiPathGuard(const VsiPathGuard&) = delete;
    VsiPathGuard& operator=(const VsiPathGuard&) = delete;

    ~VsiPathGuard()
    {
        if (!path_.empty())
        {
            VSIUnlink(path_.c_str());
        }
    }

    const std::string& path() const noexcept
    {
        return path_;
    }

private:
    std::string path_;
};

inline void createByteGeoTiff(
    const std::string& path,
    int width,
    int height,
    const std::vector<std::vector<uint8_t>>& bands,
    const std::array<double, 6>* geoTransform,
    const int* epsgCode)
{
    if (width <= 0 || height <= 0 || bands.empty())
    {
        throw std::invalid_argument("Invalid mock GeoTIFF dimensions or bands");
    }

    const std::size_t expectedPixels =
        static_cast<std::size_t>(width) * static_cast<std::size_t>(height);

    for (const auto& band : bands)
    {
        if (band.size() != expectedPixels)
        {
            throw std::invalid_argument("Mock GeoTIFF band size mismatch");
        }
    }

    GDALAllRegister();
    GDALDriver* driver = GetGDALDriverManager()->GetDriverByName("GTiff");
    if (driver == nullptr)
    {
        throw std::runtime_error("GDAL GTiff driver is unavailable");
    }

    GDALDataset* dataset = driver->Create(
        path.c_str(),
        width,
        height,
        static_cast<int>(bands.size()),
        GDT_Byte,
        nullptr);

    if (dataset == nullptr)
    {
        throw std::runtime_error("Failed to create mock GeoTIFF");
    }

    if (geoTransform != nullptr)
    {
        auto mutableTransform = *geoTransform;
        if (dataset->SetGeoTransform(mutableTransform.data()) != CE_None)
        {
            GDALClose(dataset);
            throw std::runtime_error("Failed to set mock geotransform");
        }
    }

    if (epsgCode != nullptr)
    {
        OGRSpatialReference spatialReference;
        spatialReference.SetAxisMappingStrategy(OAMS_TRADITIONAL_GIS_ORDER);

        if (spatialReference.importFromEPSG(*epsgCode) != OGRERR_NONE)
        {
            GDALClose(dataset);
            throw std::runtime_error("Failed to create mock CRS");
        }

        char* wkt = nullptr;
        spatialReference.exportToWkt(&wkt);
        const CPLErr projectionResult = dataset->SetProjection(wkt);
        CPLFree(wkt);

        if (projectionResult != CE_None)
        {
            GDALClose(dataset);
            throw std::runtime_error("Failed to set mock CRS");
        }
    }

    for (std::size_t bandIndex = 0; bandIndex < bands.size(); ++bandIndex)
    {
        GDALRasterBand* band =
            dataset->GetRasterBand(static_cast<int>(bandIndex + 1));

        const CPLErr writeResult = band->RasterIO(
            GF_Write,
            0,
            0,
            width,
            height,
            const_cast<uint8_t*>(bands[bandIndex].data()),
            width,
            height,
            GDT_Byte,
            0,
            0);

        if (writeResult != CE_None)
        {
            GDALClose(dataset);
            throw std::runtime_error("Failed to populate mock GeoTIFF band");
        }
    }

    dataset->FlushCache();
    GDALClose(dataset);
}

inline std::vector<uint8_t> copyVsiFile(const std::string& path)
{
    vsi_l_offset byteCount = 0;
    GByte* bytes = VSIGetMemFileBuffer(path.c_str(), &byteCount, FALSE);

    if (bytes == nullptr || byteCount == 0)
    {
        throw std::runtime_error("Failed to read mock /vsimem file");
    }

    return std::vector<uint8_t>(bytes, bytes + byteCount);
}

} // namespace depthwizard::test
