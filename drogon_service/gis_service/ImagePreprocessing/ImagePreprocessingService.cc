#include "ImagePreprocessingService.h"
#include "../utils/GisTypes.h" // includes GDALDatasetPtr and its custom deleter
#include <gdal_priv.h>
#include <cmath>
#include <algorithm>
#include <stdexcept>
#include <omp.h>
#include <trantor/utils/Logger.h>

ImageQualityResult ImagePreprocessingService::process(const SceneInput &scene)
{
    // Opens instantly from the RAM disk mounted by RasterIngestService
    GDALDatasetPtr poDS(static_cast<GDALDataset *>(GDALOpen(scene.inputPath.c_str(), GA_ReadOnly)));
    if (!poDS)
    {
        throw std::runtime_error("ImagePreprocessingService: Failed to access RAM raster.");
    }

    const int datasetWidth = poDS->GetRasterXSize();
    const int datasetHeight = poDS->GetRasterYSize();
    const int numBands = poDS->GetRasterCount();

    if (scene.width <= 0 || scene.height <= 0)
    {
        throw std::invalid_argument(
            "ImagePreprocessingService: Scene dimensions must be positive.");
    }

    if (datasetWidth != scene.width ||
        datasetHeight != scene.height)
    {
        throw std::invalid_argument(
            "ImagePreprocessingService: Scene dimensions do not match "
            "the opened raster dimensions.");
    }

    if (numBands <= 0)
    {
        throw std::invalid_argument(
            "ImagePreprocessingService: Raster has no readable image bands.");
    }

    const int width = datasetWidth;
    const int height = datasetHeight;
    const bool isGrayscale = (numBands == 1);
    // preallocating planar memory
    const size_t totalPixels = static_cast<size_t>(width) * height;
    std::vector<uint8_t> rawR(totalPixels), rawG(totalPixels), rawB(totalPixels);

    const CPLErr redRead = poDS->GetRasterBand(1)->RasterIO(
        GF_Read, 0, 0, width, height, rawR.data(), width, height,
        GDT_Byte, 0, 0);
    const CPLErr greenRead = poDS->GetRasterBand(numBands >= 2 ? 2 : 1)->RasterIO(
        GF_Read, 0, 0, width, height, rawG.data(), width, height,
        GDT_Byte, 0, 0);
    const CPLErr blueRead = poDS->GetRasterBand(numBands >= 3 ? 3 : 1)->RasterIO(
        GF_Read, 0, 0, width, height, rawB.data(), width, height,
        GDT_Byte, 0, 0);

    if (redRead != CE_None || greenRead != CE_None || blueRead != CE_None)
    {
        throw std::runtime_error(
            "ImagePreprocessingService: Failed to read one or more RGB bands.");
    }

    // GDALClose(poDS);

    ImageQualityResult result;
    result.normalizedRgbTensor.width = width;
    result.normalizedRgbTensor.height = height;
    result.normalizedRgbTensor.channels = 3;
    result.normalizedRgbTensor.layout = TensorLayout::CHW;

    // instead of creating a nested 3D array arr[channel][row][col], a flat 1D vector is allocated that is three times the size
    result.normalizedRgbTensor.data.assign(totalPixels * 3, 0.0f);

    result.validPixelMask.width = width;
    result.validPixelMask.height = height;
    result.validPixelMask.data.assign(totalPixels, 1);

    result.cloudMask.width = width;
    result.cloudMask.height = height;
    result.cloudMask.data.assign(totalPixels, 0);

    result.shadowMask.width = width;
    result.shadowMask.height = height;
    result.shadowMask.data.assign(totalPixels, 0);

    result.saturationMask.width = width;
    result.saturationMask.height = height;
    result.saturationMask.data.assign(totalPixels, 0);

    // to format is as the req input
    float *normR = result.normalizedRgbTensor.data.data();
    float *normG = normR + totalPixels;
    float *normB = normG + totalPixels;

    uint8_t *pValid = result.validPixelMask.data.data();
    uint8_t *pCloud = result.cloudMask.data.data();
    uint8_t *pShadow = result.shadowMask.data.data();
    uint8_t *pSat = result.saturationMask.data.data();

    uint64_t validCount = 0, cloudCount = 0, shadowCount = 0, satCount = 0;

     #pragma omp parallel for reduction(+ : validCount, cloudCount, shadowCount, satCount) schedule(static)
     for (size_t i = 0; i < totalPixels; ++i)
     {
         const float r = static_cast<float>(rawR[i]);
         const float g = static_cast<float>(rawG[i]);
         const float b = static_cast<float>(rawB[i]);

         // Z-Score Normalization for Model -> preventing mathematical "gradient explosions"
         normR[i] = ((r / 255.0f) - MEAN_R) / STD_R;
         normG[i] = ((g / 255.0f) - MEAN_G) / STD_G;
         normB[i] = ((b / 255.0f) - MEAN_B) / STD_B;

         // Do not reject a valid coloured pixel merely because one channel is
         // clipped. Treat only a complete black/white triplet as unusable.
         const bool allChannelsLow = r <= 1.0f && g <= 1.0f && b <= 1.0f;
         const bool allChannelsHigh = r >= 254.0f && g >= 254.0f && b >= 254.0f;
         if (allChannelsLow || allChannelsHigh)
         {
             pSat[i] = 1;
             satCount++;
         }

         // Photometric Analysis
         const float maxCh = std::max({r, g, b});
         const float minCh = std::min({r, g, b});
         const float luminance = 0.299f * r + 0.587f * g + 0.114f * b;
         const float saturation = (maxCh > 1e-4f) ? ((maxCh - minCh) / maxCh) : 0.0f;
         const float blueRatio = b / (r + g + b + 1e-4f);

         bool isCloud = (luminance > 200.0f && saturation < 0.18f); 

         // Grayscale Immunity -> pure luminance if blue ratio is deadlocked
         bool isShadow = false;
         if (isGrayscale)
         {
             isShadow = (luminance < 40.0f);
         } 
         else
         {
             isShadow = (luminance < 40.0f && blueRatio > 0.38f);
         }

         if (isCloud)
         {
             pCloud[i] = 1;
             cloudCount++;
         }
         if (isShadow)
         {
             pShadow[i] = 1;
             shadowCount++;
         }

         bool isBorderPadding = (r == 0.0f && g == 0.0f && b == 0.0f); // detecting artificial black border padding used in GeoTIFFs

         // Shadows are real observed terrain, not missing sensor data. Keep
         // them available to both inference models so shaded slopes do not
         // become holes in the reconstructed surface. shadowMask remains a
         // diagnostic/calibration exclusion mask.
         if (isCloud || pSat[i] == 1 || isBorderPadding)
         {
             pValid[i] = 0;
         }
         else
         {
             validCount++;
         }
     }

     result.qualityScore = static_cast<float>(validCount) / static_cast<float>(totalPixels);
     LOG_INFO << "[ImagePreprocessingService] Quality Score: "
              << (result.qualityScore * 100.0f) << "%"
              << "; clouds=" << cloudCount
              << "; shadows=" << shadowCount
              << "; saturation/no-data=" << satCount;

     return result;
}
