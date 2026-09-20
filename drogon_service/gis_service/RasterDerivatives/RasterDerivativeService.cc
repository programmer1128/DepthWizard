#include "RasterDerivativeService.h"

#include <algorithm>
#include <cmath>
#include <limits>
#include <stdexcept>

namespace
{
    constexpr double kPi = 3.14159265358979323846;

    double degreesToRadians(double degrees)
    {
        return degrees * kPi / 180.0;
    }

    float clampValue(float value, float minimum, float maximum)
    {
        return std::max(minimum, std::min(value, maximum));
    }
}

RasterDerivativeService::RasterDerivativeService(Config config)
    : config_(config)
{
    if (config_.minimumPixelSize <= 0.0)
    {
        throw std::invalid_argument(
            "RasterDerivativeService: minimum pixel size must be positive."
        );
    }

    if (config_.hillshadeSunAzimuth < 0.0f ||
        config_.hillshadeSunAzimuth >= 360.0f)
    {
        throw std::invalid_argument(
            "RasterDerivativeService: hillshade azimuth must be in [0, 360)."
        );
    }

    if (config_.hillshadeSunElevation < 0.0f ||
        config_.hillshadeSunElevation > 90.0f)
    {
        throw std::invalid_argument(
            "RasterDerivativeService: hillshade elevation must be in [0, 90]."
        );
    }
}

double RasterDerivativeService::resolvePixelSizeX(
    const SpatialMetadata& metadata
) const
{
    if (metadata.pixelSizeX <= config_.minimumPixelSize)
    {
        throw std::invalid_argument(
            "RasterDerivativeService: invalid X pixel size."
        );
    }

    return metadata.pixelSizeX;
}

double RasterDerivativeService::resolvePixelSizeY(
    const SpatialMetadata& metadata
) const
{
    if (metadata.pixelSizeY <= config_.minimumPixelSize)
    {
        throw std::invalid_argument(
            "RasterDerivativeService: invalid Y pixel size."
        );
    }

    return metadata.pixelSizeY;
}

RasterGrid<float> RasterDerivativeService::createNoDataRaster(
    int width,
    int height
) const
{
    RasterGrid<float> raster;

    raster.width = width;
    raster.height = height;

    raster.data.assign(
        static_cast<std::size_t>(width) *
        static_cast<std::size_t>(height),
        std::numeric_limits<float>::quiet_NaN()
    );

    return raster;
}

bool RasterDerivativeService::validNeighborhood(
    const RasterGrid<float>& raster,
    int row,
    int col
) const
{
    if (!raster.isValid())
    {
        return false;
    }

    if (row <= 0 ||
        col <= 0 ||
        row >= raster.height - 1 ||
        col >= raster.width - 1)
    {
        return false;
    }

    for (int rowOffset = -1; rowOffset <= 1; ++rowOffset)
    {
        for (int colOffset = -1; colOffset <= 1; ++colOffset)
        {
            const float value =
                raster.data[
                    static_cast<std::size_t>(row + rowOffset) *
                        static_cast<std::size_t>(raster.width)
                    + static_cast<std::size_t>(col + colOffset)
                ];

            if (!std::isfinite(value))
            {
                return false;
            }
        }
    }

    return true;
}

RasterProductSet RasterDerivativeService::generate(
    const GeoreferencedSurfaceBundle& surface
) const
{
    /*
     * ------------------------------------------------------------
     * 1. Validate input surfaces
     * ------------------------------------------------------------
     */
    if (!surface.dtm.isValid() ||
        !surface.dsm.isValid() ||
        !surface.ndsm.isValid() ||
        !surface.surfaceConfidence.isValid() ||
        !surface.validMask.isValid())
    {
        throw std::invalid_argument(
            "RasterDerivativeService: one or more surface rasters are invalid."
        );
    }

    const int width = surface.dtm.width;
    const int height = surface.dtm.height;

    if (surface.dsm.width != width ||
        surface.dsm.height != height ||
        surface.ndsm.width != width ||
        surface.ndsm.height != height ||
        surface.surfaceConfidence.width != width ||
        surface.surfaceConfidence.height != height ||
        surface.validMask.width != width ||
        surface.validMask.height != height)
    {
        throw std::invalid_argument(
            "RasterDerivativeService: surface raster dimensions do not match."
        );
    }

    /*
     * The derivative formulas require physical pixel spacing.
     *
     * These values are supplied by the authoritative SpatialMetadata.
     */
    const double pixelSizeX =
        resolvePixelSizeX(surface.spatialMetadata);

    const double pixelSizeY =
        resolvePixelSizeY(surface.spatialMetadata);

    /*
     * ------------------------------------------------------------
     * 2. Allocate output object
     * ------------------------------------------------------------
     */
    RasterProductSet products;

    /*
     * Preserve the authoritative spatial metadata.
     */
    products.spatialMetadata =
        surface.spatialMetadata;

    products.elevationUnit =
        surface.elevationUnit;

    /*
     * ------------------------------------------------------------
     * 3. Preserve the fused surfaces
     * ------------------------------------------------------------
     *
     * Module 7 does NOT recompute them.
     */
    products.dtm = surface.dtm;
    products.dsm = surface.dsm;
    products.ndsm = surface.ndsm;

    /*
     * Preserve the validity mask and explicit NoData convention.
     */
    products.validMask =
        surface.validMask;

    /*
     * ------------------------------------------------------------
     * 4. Allocate derivative layers
     * ------------------------------------------------------------
     */
    products.slope =
        createNoDataRaster(width, height);

    products.aspect =
        createNoDataRaster(width, height);

    products.hillshade =
        createNoDataRaster(width, height);

    /*
     * ------------------------------------------------------------
     * 5. Slope / aspect / hillshade
     * ------------------------------------------------------------
     *
     * IMPORTANT:
     *
     * These are calculated from DTM only.
     *
     * We intentionally do NOT use DSM here because buildings and
     * other elevated structures would introduce artificial terrain
     * slopes.
     */
    const double sunAzimuthRad =
        degreesToRadians(
            static_cast<double>(
                config_.hillshadeSunAzimuth
            )
        );

    const double sunElevationRad =
        degreesToRadians(
            static_cast<double>(
                config_.hillshadeSunElevation
            )
        );

    const double sinSunElevation =
        std::sin(sunElevationRad);

    const double cosSunElevation =
        std::cos(sunElevationRad);

    for (int row = 1; row < height - 1; ++row)
    {
        for (int col = 1; col < width - 1; ++col)
        {
            /*
             * If the 3x3 DTM neighborhood contains NoData,
             * we cannot safely calculate a local derivative.
             */
            if (!validNeighborhood(
                    surface.dtm,
                    row,
                    col))
            {
                continue;
            }

            const std::size_t nwIndex =
                static_cast<std::size_t>(row - 1) *
                    static_cast<std::size_t>(width)
                + static_cast<std::size_t>(col - 1);

            const std::size_t nIndex =
                static_cast<std::size_t>(row - 1) *
                    static_cast<std::size_t>(width)
                + static_cast<std::size_t>(col);

            const std::size_t neIndex =
                static_cast<std::size_t>(row - 1) *
                    static_cast<std::size_t>(width)
                + static_cast<std::size_t>(col + 1);

            const std::size_t wIndex =
                static_cast<std::size_t>(row) *
                    static_cast<std::size_t>(width)
                + static_cast<std::size_t>(col - 1);

            const std::size_t eIndex =
                static_cast<std::size_t>(row) *
                    static_cast<std::size_t>(width)
                + static_cast<std::size_t>(col + 1);

            const std::size_t swIndex =
                static_cast<std::size_t>(row + 1) *
                    static_cast<std::size_t>(width)
                + static_cast<std::size_t>(col - 1);

            const std::size_t sIndex =
                static_cast<std::size_t>(row + 1) *
                    static_cast<std::size_t>(width)
                + static_cast<std::size_t>(col);

            const std::size_t seIndex =
                static_cast<std::size_t>(row + 1) *
                    static_cast<std::size_t>(width)
                + static_cast<std::size_t>(col + 1);

            const double zNW =
                surface.dtm.data[nwIndex];

            const double zN =
                surface.dtm.data[nIndex];

            const double zNE =
                surface.dtm.data[neIndex];

            const double zW =
                surface.dtm.data[wIndex];

            const double zE =
                surface.dtm.data[eIndex];

            const double zSW =
                surface.dtm.data[swIndex];

            const double zS =
                surface.dtm.data[sIndex];

            const double zSE =
                surface.dtm.data[seIndex];

            /*
             * Horn-style 3x3 finite difference.
             *
             * dzdx:
             *   east-west terrain gradient
             *
             * dzdyNorth:
             *   north-south terrain gradient
             */
            const double dzdx =
                (
                    (zNE + 2.0 * zE + zSE) -
                    (zNW + 2.0 * zW + zSW)
                ) / (8.0 * pixelSizeX);

            const double dzdyNorth =
                (
                    (zNW + 2.0 * zN + zNE) -
                    (zSW + 2.0 * zS + zSE)
                ) / (8.0 * pixelSizeY);

            /*
             * ----------------------------------------------------
             * SLOPE
             * ----------------------------------------------------
             */
            const double gradientMagnitude =
                std::sqrt(
                    dzdx * dzdx +
                    dzdyNorth * dzdyNorth
                );

            const double slopeRadians =
                std::atan(gradientMagnitude);

            const double slopeDegrees =
                slopeRadians * 180.0 / kPi;

            products.slope.data[
                static_cast<std::size_t>(row) *
                    static_cast<std::size_t>(width)
                + static_cast<std::size_t>(col)
            ] =
                static_cast<float>(slopeDegrees);

            /*
             * ----------------------------------------------------
             * ASPECT
             * ----------------------------------------------------
             *
             * Compass convention:
             *
             *   0°   North
             *   90°  East
             *   180° South
             *   270° West
             *
             * Aspect is the downslope direction, so we use the
             * negative gradient.
             */
            if (gradientMagnitude > 1e-12)
            {
                double aspectDegrees =
                    std::atan2(
                        -dzdx,
                        -dzdyNorth
                    ) * 180.0 / kPi;

                if (aspectDegrees < 0.0)
                {
                    aspectDegrees += 360.0;
                }

                products.aspect.data[
                    static_cast<std::size_t>(row) *
                        static_cast<std::size_t>(width)
                    + static_cast<std::size_t>(col)
                ] =
                    static_cast<float>(aspectDegrees);

                /*
                 * ------------------------------------------------
                 * HILLSHADE
                 * ------------------------------------------------
                 */
                const double aspectRadians =
                    degreesToRadians(
                        aspectDegrees
                    );

                const double hillshade =
                    255.0 *
                    (
                        cosSunElevation *
                            std::cos(slopeRadians)
                        +
                        sinSunElevation *
                            std::sin(slopeRadians) *
                            std::cos(
                                sunAzimuthRad -
                                aspectRadians
                            )
                    );

                products.hillshade.data[
                    static_cast<std::size_t>(row) *
                        static_cast<std::size_t>(width)
                    + static_cast<std::size_t>(col)
                ] =
                    clampValue(
                        static_cast<float>(hillshade),
                        0.0f,
                        255.0f
                    );
            }
            else
            {
                /*
                 * Flat terrain has no meaningful aspect.
                 *
                 * We leave aspect as NoData, but the flat-surface
                 * hillshade remains valid.
                 */
                const double hillshade =
                    255.0 * cosSunElevation;

                products.hillshade.data[
                    static_cast<std::size_t>(row) *
                        static_cast<std::size_t>(width)
                    + static_cast<std::size_t>(col)
                ] =
                    clampValue(
                        static_cast<float>(hillshade),
                        0.0f,
                        255.0f
                    );
            }
        }
    }

    /*
     * ------------------------------------------------------------
     * 6. Product semantics
     * ------------------------------------------------------------
     */
    products.slopeUnits =
        "DEGREES";

    products.aspectConvention =
        "CLOCKWISE_FROM_NORTH";

    products.hillshade =
        products.hillshade;

    products.sunAzimuth =
        config_.hillshadeSunAzimuth;

    products.sunElevation =
        config_.hillshadeSunElevation;

    /*
     * ------------------------------------------------------------
     * 7. Canopy height
     * ------------------------------------------------------------
     *
     * Canopy isolation belongs to the upstream canopy-processing
     * stage. Module 7 should not reinterpret arbitrary nDSM pixels
     * as vegetation.
     */
    products.canopyHeight =
        std::nullopt;

    /*
     * There is currently no canopy raster inside
     * GeoreferencedSurfaceBundle.
     *
     * Therefore the optional product stays empty until the
     * upstream contract is extended to provide it.
     */

    /*
     * ------------------------------------------------------------
     * 8. Confidence
     * ------------------------------------------------------------
     *
     * Preserve the upstream surface confidence directly.
     */
    products.confidence =
        surface.surfaceConfidence;

    /*
     * Explicit serialization NoData value.
     *
     * Actual internal invalid pixels remain represented by NaN
     * inside the RasterGrid. TiffExporter later converts them to
     * the canonical numeric NoData value.
     */
    products.noDataValue =
        -9999.0f;

    return products;
}