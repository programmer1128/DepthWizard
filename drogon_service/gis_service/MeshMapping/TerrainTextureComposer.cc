#include "TerrainTextureComposer.h"

#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/photo.hpp>

#include <cmath>
#include <cstddef>
#include <stdexcept>
#include <vector>

TextureAsset TerrainTextureComposer::concealAcceptedRoofs(
    const TextureAsset& original,
    const RasterGrid<uint8_t>& acceptedFootprints,
    const SpatialMetadata& metadata,
    float haloMetres)
{
    if (!acceptedFootprints.isValid() || metadata.width <= 0 ||
        metadata.height <= 0 || acceptedFootprints.width != metadata.width ||
        acceptedFootprints.height != metadata.height ||
        !std::isfinite(haloMetres) || haloMetres < 0.0f ||
        haloMetres > 3.0f)
        throw std::invalid_argument("TerrainTextureComposer: invalid mask or halo");

    if (original.bytes.empty()) return original;
    if (original.mimeType != "image/jpeg" && original.mimeType != "image/png")
        throw std::invalid_argument("TerrainTextureComposer: unsupported optical texture");

    cv::Mat mask(metadata.height, metadata.width, CV_8UC1,
                 const_cast<uint8_t*>(acceptedFootprints.data.data()));
    cv::Mat repairMask;
    cv::compare(mask, 0, repairMask, cv::CMP_GT);
    const int buildingPixels = cv::countNonZero(repairMask);
    const std::size_t totalPixels =
        static_cast<std::size_t>(metadata.width) * metadata.height;
    if (buildingPixels == 0 || static_cast<std::size_t>(buildingPixels) == totalPixels)
        return original;

    const double columnResolution = std::hypot(
        metadata.geoTransform[1], metadata.geoTransform[4]);
    const double rowResolution = std::hypot(
        metadata.geoTransform[2], metadata.geoTransform[5]);
    if (!std::isfinite(columnResolution) || columnResolution <= 0.0 ||
        !std::isfinite(rowResolution) || rowResolution <= 0.0)
        throw std::invalid_argument("TerrainTextureComposer: invalid pixel resolution");

    if (haloMetres > 0.0f)
    {
        const int radiusX = static_cast<int>(std::ceil(haloMetres / columnResolution));
        const int radiusY = static_cast<int>(std::ceil(haloMetres / rowResolution));
        const cv::Mat kernel = cv::getStructuringElement(
            cv::MORPH_ELLIPSE, cv::Size(radiusX * 2 + 1, radiusY * 2 + 1));
        cv::dilate(repairMask, repairMask, kernel);
    }

    // A border-touching building can cover the whole tiny fixture after
    // dilation. In a real image this is also an unobservable ground texture.
    if (static_cast<std::size_t>(cv::countNonZero(repairMask)) == totalPixels)
        return original;

    const cv::Mat decoded = cv::imdecode(original.bytes, cv::IMREAD_COLOR);
    if (decoded.empty() || decoded.cols != metadata.width ||
        decoded.rows != metadata.height)
        throw std::runtime_error("TerrainTextureComposer: optical texture shape mismatch");

    cv::Mat repaired;
    cv::inpaint(decoded, repairMask, repaired, 3.0, cv::INPAINT_TELEA);

    // Lossless encoding keeps roads and other unmasked optical pixels intact.
    // Only the GLB texture is changed; the source GeoTIFF is never rewritten.
    TextureAsset output;
    output.mimeType = "image/png";
    if (!cv::imencode(".png", repaired, output.bytes,
                      {cv::IMWRITE_PNG_COMPRESSION, 3}))
        throw std::runtime_error("TerrainTextureComposer: texture encoding failed");
    return output;
}
