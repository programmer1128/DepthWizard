#pragma once

#include "../structures/SurfaceStructs.h"
#include "../structures/GeographicStructs.h"
#include "../structures/ExportStructs.h"

#include <cstddef>

class QualityControlService
{
public:

    struct Config
    {
        double surfaceIdentityToleranceMeters = 1.0;

        double minimumBuildingHeightMeters = 0.0;
        double maximumBuildingHeightMeters = 1000.0;

        float waterProbabilityThreshold = 0.70f;

        std::size_t minimumWaterComponentPixels = 9;

        double waterLevelToleranceMeters = 2.0;
    };

    explicit QualityControlService(
        Config config = Config{}
    );

    QualityReport validate(
        const GeoreferencedSurfaceBundle& surface,
        const BuildingCollection& buildings,
        const SemanticScene& semantics
    ) const;

private:

    QualityReport validateSurfaceIdentity(
        const GeoreferencedSurfaceBundle& surface
    ) const;

    QualityReport validateBuildings(
        const BuildingCollection& buildings
    ) const;

    QualityReport validateWaterBodies(
        const GeoreferencedSurfaceBundle& surface,
        const SemanticScene& semantics
    ) const;

    float calculateOverallConfidence(
        const GeoreferencedSurfaceBundle& surface
    ) const;

    Config config_;
};