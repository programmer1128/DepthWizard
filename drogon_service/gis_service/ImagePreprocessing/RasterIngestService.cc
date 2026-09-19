#include "RasterIngestService.h"
#include "../DataHandlers/MiniIOClient.h"
#include "stb_image_write.h"
#include <gdal_priv.h>
#include <cpl_vsi.h>
#include <ogr_spatialref.h>
#include <trantor/utils/Logger.h>
#include <cmath>
#include <cstring>
#include <stdexcept>
#include <vector>

static void stbJpegVectorWriter(void *context, void *data, int size)
{
    auto *vec = static_cast<std::vector<uint8_t> *>(context);
    auto *bytes = static_cast<uint8_t *>(data);
    vec->insert(vec->end(), bytes, bytes + size);
}

SceneInput RasterIngestService::ingestGeoTiff(const std::string &jobId, const drogon::HttpFile &imageFile)
{
    if (imageFile.fileLength() == 0)
    {
        throw std::runtime_error("RasterIngestService: Uploaded file is empty.");
    }

    // 1. Convert HTTP upload to raw byte vector and push to MinIO
    std::string bucket = "terrain-assets";
    std::string objectKey = "raw_input_" + jobId + ".tif";

    std::vector<uint8_t> fileBuffer(
        imageFile.fileData(),
        imageFile.fileData() + imageFile.fileLength());

    LOG_INFO << "[RasterIngestService] Uploading raw GeoTIFF to MinIO: " << objectKey;
    bool uploadSuccess = MinioClient::uploadBuffer(bucket, objectKey, fileBuffer, "image/tiff");
    if (!uploadSuccess)
    {
        throw std::runtime_error("RasterIngestService: Failed to upload raw GeoTIFF to MinIO.");
    }

    // 2. Generate a secure Pre-Signed URL and mount via GDAL /vsicurl/
    // We set a 2-hour expiry to ensure it survives long-running AI inference pipelines
    std::string presignedUrl = MinioClient::generatePresignedUrl(bucket, objectKey, 7200);
    if (presignedUrl.empty())
    {
        throw std::runtime_error("RasterIngestService: Failed to generate presigned URL for raw GeoTIFF.");
    }

    // Construct the GDAL virtual network path
    std::string vsiPath = "/vsicurl/" + presignedUrl;

    // 3. Open the remote dataset via GDAL
    GDALDataset *poDS = static_cast<GDALDataset *>(GDALOpen(vsiPath.c_str(), GA_ReadOnly));
    if (!poDS)
    {
        throw std::runtime_error("RasterIngestService: Failed to parse remote image through GDAL.");
    }

    const int width = poDS->GetRasterXSize();
    const int height = poDS->GetRasterYSize();
    const int numBands = poDS->GetRasterCount();

    double adfGeoTransform[6];
    if (poDS->GetGeoTransform(adfGeoTransform) != CE_None)
    {
        GDALClose(poDS);
        throw std::runtime_error("RasterIngestService: Missing affine geotransform. GeoTIFF must be georeferenced.");
    }

    const char *rawCRS = poDS->GetProjectionRef();
    if (!rawCRS || std::strlen(rawCRS) == 0)
    {
        GDALClose(poDS);
        throw std::runtime_error("RasterIngestService: Missing CRS definition.");
    }

    // 4. Compute Affine Ground Sample Distance (GSD)
    double pixelWidth = std::abs(adfGeoTransform[1]);
    double pixelHeight = std::abs(adfGeoTransform[5]);
    double gsd = std::sqrt(pixelWidth * pixelHeight);

    SpatialMetadata spatialMeta;
    spatialMeta.width = width;
    spatialMeta.height = height;
    std::copy(std::begin(adfGeoTransform), std::end(adfGeoTransform), spatialMeta.geoTransform.begin());
    spatialMeta.projectionRef = std::string(rawCRS);
    spatialMeta.pixelSizeX = pixelWidth;
    spatialMeta.pixelSizeY = pixelHeight;
    spatialMeta.gsd = gsd;
    spatialMeta.isGeoreferenced = true;

    // 5. Extract unaltered RGB bands for the 3D GLB texture
    size_t totalPixels = static_cast<size_t>(width) * height;
    std::vector<uint8_t> interleavedRgb(totalPixels * 3, 0);
    std::vector<uint8_t> bandBuffer(totalPixels);

    for (int b = 1; b <= 3; ++b)
    {
        int srcBandIdx = (b <= numBands) ? b : 1;
        GDALRasterBand *poBand = poDS->GetRasterBand(srcBandIdx);
        poBand->RasterIO(GF_Read, 0, 0, width, height, bandBuffer.data(), width, height, GDT_Byte, 0, 0);

#pragma omp parallel for schedule(static)
        for (size_t i = 0; i < totalPixels; ++i)
        {
            interleavedRgb[i * 3 + (b - 1)] = bandBuffer[i];
        }
    }
    GDALClose(poDS);

    // 6. Encode preserved optical RGB to baseline JPEG for GLTF PBR texture mapping
    std::vector<uint8_t> compressedJpeg;
    compressedJpeg.reserve(totalPixels / 4);
    if (!stbi_write_jpg_to_func(stbJpegVectorWriter, &compressedJpeg, width, height, 3, interleavedRgb.data(), 92))
    {
        throw std::runtime_error("RasterIngestService: Failed encoding preserved JPEG texture buffer.");
    }

    // 7. Package and return the SceneInput
    SceneInput scene;
    scene.jobId = jobId;
    scene.inputPath = vsiPath; // Retain the remote /vsicurl/ path for downstream branches
    scene.inputMode = PipelineMode::GEOREFERENCED;
    scene.width = width;
    scene.height = height;
    scene.rgbTextureBytes = std::move(compressedJpeg);
    scene.textureMimeType = "image/jpeg";
    scene.spatialMetadata = spatialMeta;
    scene.sourceFormat = "GTiff";

    LOG_INFO << "[RasterIngestService] Ingested GeoTIFF " << width << "x" << height << " with GSD: " << gsd << " m/px from MinIO.";
    return scene;
}