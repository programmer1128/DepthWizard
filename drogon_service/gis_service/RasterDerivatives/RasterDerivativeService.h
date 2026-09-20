#pragma once

#include "../structures/Module7Types.h"

#include <stdexcept>

class RasterDerivativeService
{
public:
    struct Config
    {
        // Default sun geometry for hillshade.
        double hillshadeAltitudeDegrees = 45.0;
        double hillshadeAzimuthDegrees = 315.0;

        // Prevent division by extremely small pixel spacing.
        double minimumPixelSpacingMeters = 1e-6;
    };

    explicit RasterDerivativeService(Config config = Config{});

    // Generate the complete Module 7 raster product set.
    RasterProductSet generate(const SurfaceBundle& surface) const;

private:
    Config config_;

    double resolvePixelSpacingX(const RasterMetadata& metadata) const;
    double resolvePixelSpacingY(const RasterMetadata& metadata) const;

    bool isValidCenterAndNeighbors(
        const RasterGrid<float>& raster,
        int row,
        int col
    ) const;

    float noDataValue() const;
};