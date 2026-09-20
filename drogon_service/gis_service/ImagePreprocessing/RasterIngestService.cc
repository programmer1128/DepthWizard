#include "RasterIngestService.h"
#include "../DataHandlers/MiniIOClient.h"
#include "../utils/GisTypes.h" // includes GDALDatasetPtr and its custom deleter
#include "stb_image_write.h"
#include <gdal_priv.h>
#include <cpl_vsi.h>
#include <ogr_spatialref.h>
#include <trantor/utils/Logger.h>
#include <cmath>
#include <cstring>
#include <stdexcept>
#include <vector>
#include <future>

// A custom C-callback required by the stb_image_write library -> instead of writing the compressed JPEG to a physical hard drive, this forces the C-library to append the compressed bytes directly into a C++ std::vector in RAM
static void stbJpegVectorWriter(void *context, void *data, int size)
{
    auto *vec = static_cast<std::vector<uint8_t> *>(context);
    auto *bytes = static_cast<uint8_t *>(data);
    vec->insert(vec->end(), bytes, bytes + size);
}

SceneInput RasterIngestService::ingestGeoTiff(const std::string &jobId, const drogon::HttpFile &imageFile)
{
    if (imageFile.fileLength() == 0) // file validation
    {
        throw std::runtime_error("RasterIngestService: Uploaded file is empty.");
    }

    // 1. Mounting the HTTP payload directly to GDAL's zero-copy RAM disk
    std::string vsiPath = "/vsimem/raw_" + jobId + ".tif";
    VSILFILE *fp = VSIFileFromMemBuffer(vsiPath.c_str(), (GByte *)imageFile.fileData(), imageFile.fileLength(), FALSE);
    VSIFCloseL(fp);

    // 2. Asynchronously uploading to MinIO so network I/O doesn't block local processing
    std::string bucket = "terrain-assets";
    std::string objectKey = "raw_input_" + jobId + ".tif";
    std::vector<uint8_t> fileBuffer(imageFile.fileData(), imageFile.fileData() + imageFile.fileLength());

    // fire and forget upload
    std::thread([bucket, objectKey, fileBuffer]()
                { MinioClient::uploadBuffer(bucket, objectKey, fileBuffer, "image/tiff"); })
        .detach();

    // 3. Opening the RAM dataset via GDAL
    GDALDatasetPtr poDS(static_cast<GDALDataset *>(GDALOpen(vsiPath.c_str(), GA_ReadOnly)));
    if (!poDS) // if file is corrupted and fails to open
    {
        VSIUnlink(vsiPath.c_str()); // erase RAM file before throwing
        throw std::runtime_error("RasterIngestService: Failed to parse raw image through GDAL.");
    }

    const int width = poDS->GetRasterXSize();
    const int height = poDS->GetRasterYSize();
    const int numBands = poDS->GetRasterCount();

    double adfGeoTransform[6];
    if (poDS->GetGeoTransform(adfGeoTransform) != CE_None) // image is just a standard photo (lacking a GeoTransform or CRS)
    {
        // GDALClose(poDS);
        VSIUnlink(vsiPath.c_str()); // erase RAM file before throwing
        throw std::runtime_error("RasterIngestService: Missing affine geotransform. GeoTIFF must be georeferenced.");
    }

    const char *rawCRS = poDS->GetProjectionRef(); // checks for a CRS (a WKT string like UTM Zone 33N or WGS84)
    if (!rawCRS || std::strlen(rawCRS) == 0)
    {
        // GDALClose(poDS);
        VSIUnlink(vsiPath.c_str()); // erase RAM file before throwing
        throw std::runtime_error("RasterIngestService: Missing CRS definition.");
    }

    // 4. Computing Affine Ground Sample Distance (GSD) with Geographic Safety Fallback
    // GSD represents the physical distance on the ground that a single pixel covers
    double pixelWidth = std::abs(adfGeoTransform[1]);
    double pixelHeight = std::abs(adfGeoTransform[5]);
    double gsd = std::sqrt(pixelWidth * pixelHeight); // geometric mean

    OGRSpatialReference oSRS;
    if (oSRS.SetFromUserInput(rawCRS) == OGRERR_NONE)
    {
        if (oSRS.IsGeographic()) // if the map uses degrees
        {
            gsd *= 111320.0; // coverting degree scaling to meters
            LOG_INFO << "[RasterIngestService] Geographic CRS detected. Applying degree-to-meter scaling.";
        }
    }

    SpatialMetadata spatialMeta;
    spatialMeta.width = width;
    spatialMeta.height = height;
    std::copy(std::begin(adfGeoTransform), std::end(adfGeoTransform), spatialMeta.geoTransform.begin());
    spatialMeta.projectionRef = std::string(rawCRS);
    spatialMeta.pixelSizeX = pixelWidth;
    spatialMeta.pixelSizeY = pixelHeight;
    spatialMeta.gsd = gsd;
    spatialMeta.isGeoreferenced = true;

    // 5. Extracting unaltered RGB bands for the 3D GLB texture
    size_t totalPixels = static_cast<size_t>(width) * height;
    std::vector<uint8_t> interleavedRgb(totalPixels * 3, 0);
    std::vector<uint8_t> bandBuffer(totalPixels);

    // GeoTIFFs usually store color data in Planar format -> all the Red pixels grouped together, then all the Greens, then all the Blues, but standard JPEGs and 3D rendering engines strictly require Interleaved format
    for (int b = 1; b <= 3; ++b)
    {
        int srcBandIdx = (b <= numBands) ? b : 1;
        GDALRasterBand *poBand = poDS->GetRasterBand(srcBandIdx);

        // (void) cast added to suppress GCC warnings
        (void)poBand->RasterIO(GF_Read, 0, 0, width, height, bandBuffer.data(), width, height, GDT_Byte, 0, 0);

#pragma omp parallel for schedule(static) // read only one band at a time to bandBuffer
        for (size_t i = 0; i < totalPixels; ++i)
        {
            interleavedRgb[i * 3 + (b - 1)] = bandBuffer[i];
        }
    }

    // GDALClose(poDS);

    // 6. Encoding preserved optical RGB to baseline JPEG for GLTF PBR texture mapping
    std::vector<uint8_t> compressedJpeg;
    compressedJpeg.reserve(totalPixels / 4);

    if (!stbi_write_jpg_to_func(stbJpegVectorWriter, &compressedJpeg, width, height, 3, interleavedRgb.data(), 92))
    {
        VSIUnlink(vsiPath.c_str()); // erase RAM file before throwing
        throw std::runtime_error("RasterIngestService: Failed encoding preserved JPEG texture buffer.");
    }

    // 7. Packaging and returning the SceneInput
    SceneInput scene;
    scene.jobId = jobId;
    scene.inputPath = vsiPath; // Local RAM path prevents double-download penalty downstream
    scene.inputMode = PipelineMode::GEOREFERENCED;
    scene.width = width;
    scene.height = height;
    scene.rgbTextureBytes = std::move(compressedJpeg);
    scene.textureMimeType = "image/jpeg";
    scene.spatialMetadata = spatialMeta;
    scene.sourceFormat = "GTiff";

    LOG_INFO << "[RasterIngestService] Ingested GeoTIFF " << width << "x" << height << " with physical GSD: " << gsd << " m/px.";

    return scene;
}