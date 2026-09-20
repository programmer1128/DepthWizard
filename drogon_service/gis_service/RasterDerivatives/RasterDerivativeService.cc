#include "RasterDerivativeService.h"

#include <algorithm>
#include <cmath>
#include <limits>
#include <sstream>
#include <stdexcept>

namespace
{
    constexpr double kPi = 3.14159265358979323846;

    double degreesToRadians(double degrees)
    {
        return degrees * kPi / 180.0;
    }

    float clampFloat(float value, float minimum, float maximum)
    {
        return std::max(minimum, std::min(value, maximum));
    }

    RasterGrid<float> createNoDataRaster(int width, int height)
    {
        RasterGrid<float> raster;

        raster.width = width;
        raster.height = height;

        const float noData = std::numeric_limits<float>::quiet_NaN();

        raster.data.assign(
            static_cast<std::size_t>(width) *
            static_cast<std::size_t>(height),
            noData
        );

        raster.noData = noData;

        return raster;
    }
}

RasterDerivativeService::RasterDerivativeService(Config config)
    : config_(std::move(config))
{
    if (config_.minimumPixelSpacingMeters <= 0.0)
    {
        throw std::invalid_argument(
            "RasterDerivativeService: minimum pixel spacing must be positive."
        );
    }

    if (config_.hillshadeAltitudeDegrees < 0.0 ||
        config_.hillshadeAltitudeDegrees > 90.0)
    {
        throw std::invalid_argument(
            "RasterDerivativeService: hillshade altitude must be in [0, 90]."
        );
    }

    if (config_.hillshadeAzimuthDegrees < 0.0 ||
        config_.hillshadeAzimuthDegrees >= 360.0)
    {
        throw std::invalid_argument(
            "RasterDerivativeService: hillshade azimuth must be in [0, 360)."
        );
    }
}

float RasterDerivativeService::noDataValue() const
{
    return std::numeric_limits<float>::quiet_NaN();
}

double RasterDerivativeService::resolvePixelSpacingX(
    const RasterMetadata& metadata
) const
{
    // Prefer explicit GSD when available.
    if (metadata.gsd > config_.minimumPixelSpacingMeters)
    {
        return metadata.gsd;
    }

    // Otherwise use the GeoTransform pixel width.
    const double dx = std::abs(metadata.geoTransform[1]);

    if (dx <= config_.minimumPixelSpacingMeters)
    {
        throw std::invalid_argument(
            "RasterDerivativeService: unable to determine X pixel spacing."
        );
    }

    return dx;
}

double RasterDerivativeService::resolvePixelSpacingY(
    const RasterMetadata& metadata
) const
{
    // Prefer explicit GSD when available.
    if (metadata.gsd > config_.minimumPixelSpacingMeters)
    {
        return metadata.gsd;
    }

    // GeoTransform[5] is normally negative for north-up rasters,
    // hence abs().
    const double dy = std::abs(metadata.geoTransform[5]);

    if (dy <= config_.minimumPixelSpacingMeters)
    {
        throw std::invalid_argument(
            "RasterDerivativeService: unable to determine Y pixel spacing."
        );
    }

    return dy;
}

bool RasterDerivativeService::isValidCenterAndNeighbors(
    const RasterGrid<float>& raster,
    int row,
    int col
) const
{
    const int width = raster.width;
    const int height = raster.height;

    if (row <= 0 ||
        col <= 0 ||
        row >= height - 1 ||
        col >= width - 1)
    {
        return false;
    }

    const float nw = raster.at(row - 1, col - 1);
    const float n  = raster.at(row - 1, col);
    const float ne = raster.at(row - 1, col + 1);

    const float w  = raster.at(row, col - 1);
    const float c  = raster.at(row, col);
    const float e  = raster.at(row, col + 1);

    const float sw = raster.at(row + 1, col - 1);
    const float s  = raster.at(row + 1, col);
    const float se = raster.at(row + 1, col + 1);

    return raster.isValidValue(nw) &&
           raster.isValidValue(n) &&
           raster.isValidValue(ne) &&
           raster.isValidValue(w) &&
           raster.isValidValue(c) &&
           raster.isValidValue(e) &&
           raster.isValidValue(sw) &&
           raster.isValidValue(s) &&
           raster.isValidValue(se);
}

RasterProductSet RasterDerivativeService::generate(
    const SurfaceBundle& surface
) const
{
    const int width = surface.DTM.width;
    const int height = surface.DTM.height;

    if (width <= 0 || height <= 0)
    {
        throw std::invalid_argument(
            "RasterDerivativeService: DTM has invalid dimensions."
        );
    }

    const std::size_t expectedSize =
        static_cast<std::size_t>(width) *
        static_cast<std::size_t>(height);

    if (surface.DTM.data.size() != expectedSize ||
        surface.DSM.data.size() != expectedSize ||
        surface.nDSM.data.size() != expectedSize)
    {
        throw std::invalid_argument(
            "RasterDerivativeService: DTM, DSM and nDSM dimensions/storage "
            "do not match."
        );
    }

    const double dx = resolvePixelSpacingX(surface.metadata);
    const double dy = resolvePixelSpacingY(surface.metadata);

    RasterProductSet products;

    /*
     * ------------------------------------------------------------
     * 1. Preserve authoritative base surfaces
     * ------------------------------------------------------------
     *
     * Module 7 is not responsible for rebuilding these surfaces.
     */
    products.DTM = surface.DTM;
    products.DSM = surface.DSM;
    products.nDSM = surface.nDSM;

    products.metadata = surface.metadata;

    /*
     * ------------------------------------------------------------
     * 2. Allocate derivative rasters
     * ------------------------------------------------------------
     */
    products.slope = createNoDataRaster(width, height);
    products.aspect = createNoDataRaster(width, height);
    products.hillshade = createNoDataRaster(width, height);

    /*
     * ------------------------------------------------------------
     * 3. Generate slope, aspect and hillshade from DTM
     * ------------------------------------------------------------
     *
     * We use a 3x3 Horn-style neighborhood.
     *
     * IMPORTANT:
     * DTM is used here intentionally.
     * DSM is NOT used for terrain derivatives.
     */
    const double sunAltitudeRad =
        degreesToRadians(config_.hillshadeAltitudeDegrees);

    const double sunAzimuthRad =
        degreesToRadians(config_.hillshadeAzimuthDegrees);

    const double sinSunAltitude = std::sin(sunAltitudeRad);
    const double cosSunAltitude = std::cos(sunAltitudeRad);

    const float nodata = noDataValue();

    for (int row = 1; row < height - 1; ++row)
    {
        for (int col = 1; col < width - 1; ++col)
        {
            if (!isValidCenterAndNeighbors(surface.DTM, row, col))
            {
                products.slope.at(row, col) = nodata;
                products.aspect.at(row, col) = nodata;
                products.hillshade.at(row, col) = nodata;
                continue;
            }

            const double zNW = surface.DTM.at(row - 1, col - 1);
            const double zN  = surface.DTM.at(row - 1, col);
            const double zNE = surface.DTM.at(row - 1, col + 1);

            const double zW  = surface.DTM.at(row, col - 1);
            const double zE  = surface.DTM.at(row, col + 1);

            const double zSW = surface.DTM.at(row + 1, col - 1);
            const double zS  = surface.DTM.at(row + 1, col);
            const double zSE = surface.DTM.at(row + 1, col + 1);

            /*
             * East-west gradient.
             *
             * Positive dzdx means elevation increases toward east.
             */
            const double dzdx =
                (
                    (zNE + 2.0 * zE + zSE) -
                    (zNW + 2.0 * zW + zSW)
                ) / (8.0 * dx);

            /*
             * North-south gradient.
             *
             * Positive dzdyNorth means elevation increases toward north.
             */
            const double dzdyNorth =
                (
                    (zNW + 2.0 * zN + zNE) -
                    (zSW + 2.0 * zS + zSE)
                ) / (8.0 * dy);

            /*
             * ----------------------------------------------------
             * SLOPE
             * ----------------------------------------------------
             *
             * slope = atan(horizontal gradient magnitude)
             */
            const double gradientMagnitude =
                std::sqrt(
                    dzdx * dzdx +
                    dzdyNorth * dzdyNorth
                );

            const double slopeRad =
                std::atan(gradientMagnitude);

            const double slopeDeg =
                slopeRad * 180.0 / kPi;

            products.slope.at(row, col) =
                static_cast<float>(slopeDeg);

            /*
             * ----------------------------------------------------
             * ASPECT
             * ----------------------------------------------------
             *
             * Aspect is the downslope direction:
             *
             *   0   = North
             *   90  = East
             *   180 = South
             *   270 = West
             */
            double aspectDeg;

            if (gradientMagnitude <= 1e-12)
            {
                // Flat terrain has no defined aspect.
                products.aspect.at(row, col) = nodata;

                /*
                 * Hillshade of a flat surface is independent
                 * of direction.
                 */
                const double hillshade =
                    255.0 * cosSunAltitude;

                products.hillshade.at(row, col) =
                    clampFloat(
                        static_cast<float>(hillshade),
                        0.0f,
                        255.0f
                    );

                continue;
            }

            aspectDeg =
                std::atan2(
                    -dzdx,
                    -dzdyNorth
                ) * 180.0 / kPi;

            if (aspectDeg < 0.0)
            {
                aspectDeg += 360.0;
            }

            products.aspect.at(row, col) =
                static_cast<float>(aspectDeg);

            /*
             * ----------------------------------------------------
             * HILLSHADE
             * ----------------------------------------------------
             *
             * Illumination based on:
             * - sun altitude
             * - sun azimuth
             * - terrain slope
             * - terrain aspect
             */
            const double aspectRad =
                degreesToRadians(aspectDeg);

            const double hillshade =
                255.0 *
                (
                    cosSunAltitude * std::cos(slopeRad) +
                    sinSunAltitude *
                    std::sin(slopeRad) *
                    std::cos(
                        sunAzimuthRad - aspectRad
                    )
                );

            products.hillshade.at(row, col) =
                clampFloat(
                    static_cast<float>(hillshade),
                    0.0f,
                    255.0f
                );
        }
    }

    /*
     * ------------------------------------------------------------
     * 4. Canopy height
     * ------------------------------------------------------------
     *
     * Do NOT invent a canopy model here.
     *
     * If upstream Module 6 already supplied canopy height,
     * preserve it.
     */
    if (surface.canopyHeight.has_value())
    {
        products.canopyHeight = surface.canopyHeight;
    }
    else
    {
        products.canopyHeight = std::nullopt;
    }

    /*
     * ------------------------------------------------------------
     * 5. Confidence
     * ------------------------------------------------------------
     *
     * Preserve upstream confidence.
     *
     * For the current interim Module7Types contract,
     * RasterProductSet::confidence is required, so a missing
     * upstream confidence raster becomes an all-NoData raster.
     *
     * We deliberately do NOT fabricate a numerical confidence
     * value.
     */
    if (surface.confidence.has_value())
    {
        products.confidence = *surface.confidence;
    }
    else
    {
        products.confidence = createNoDataRaster(width, height);
    }

    return products;
}