#pragma once

#include "../structures/CommonTypes.h"
#include "../structures/SurfaceStructs.h"

#include <stdexcept>

class RasterDerivativeService
{
public:

    struct Config
    {
        /*
         * Hillshade sun geometry.
         *
         * Azimuth:
         *   0   = North
         *   90  = East
         *   180 = South
         *   270 = West
         *
         * These are export/display semantics and can be configured
         * later if the frontend wants different illumination.
         */
        float hillshadeSunAzimuth = 315.0f;
        float hillshadeSunElevation = 45.0f;

        /*
         * Prevent invalid or near-zero pixel dimensions from
         * entering the gradient calculation.
         */
        double minimumPixelSize = 1e-6;
    };

    explicit RasterDerivativeService(
        Config config = Config{}
    );

    /*
     * Generate the complete GIS product set from the already-fused
     * georeferenced surface.
     *
     * Important:
     * - DTM/DSM/nDSM are preserved, not recomputed.
     * - slope/aspect/hillshade are derived from DTM.
     * - canopy/confidence are carried forward from upstream data.
     */
    RasterProductSet generate(
        const GeoreferencedSurfaceBundle& surface
    ) const;

private:

    Config config_;

    double resolvePixelSizeX(
        const SpatialMetadata& metadata
    ) const;

    double resolvePixelSizeY(
        const SpatialMetadata& metadata
    ) const;

    bool validNeighborhood(
        const RasterGrid<float>& raster,
        int row,
        int col
    ) const;

    RasterGrid<float> createNoDataRaster(
        int width,
        int height
    ) const;
};