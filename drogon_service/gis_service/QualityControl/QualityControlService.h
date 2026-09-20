#pragma once

#include "../structures/Module7Types.h"

class QualityControlService
{
public:

    struct Config
    {
        // ----------------------------------------------------
        // Surface identity:
        //
        // abs((DSM - DTM) - nDSM) <= tolerance
        // ----------------------------------------------------
        double surfaceIdentityToleranceMeters = 1.0;

        // ----------------------------------------------------
        // Building sanity guardrail.
        //
        // The architecture gives a 1,000 m hallucinated
        // skyscraper as an example. This value is therefore
        // configurable rather than a hard scientific constant.
        // ----------------------------------------------------
        double maximumBuildingHeightMeters = 1000.0;

        // Minimum accepted roof-base separation.
        // A building with roof <= base is physically invalid.
        double minimumBuildingHeightMeters = 0.0;

        // ----------------------------------------------------
        // Water-body semantic threshold.
        //
        // Water probability >= threshold is considered water.
        // ----------------------------------------------------
        float waterProbabilityThreshold = 0.70f;

        // Ignore tiny isolated water components.
        std::size_t minimumWaterComponentPixels = 9;

        // Maximum allowed elevation variation inside one
        // connected water component.
        //
        // This is an implementation guardrail and should later
        // be tuned using real data.
        double waterLevelToleranceMeters = 2.0;
    };

    explicit QualityControlService(
        Config config = Config{}
    );

    // --------------------------------------------------------
    // Full Module 7 validation.
    //
    // Runs:
    //   1. Raster/dimension validation
    //   2. DSM = DTM + nDSM
    //   3. Building geometry/height checks
    //   4. Water-level checks
    // --------------------------------------------------------
    QualityReport validate(
        const SurfaceBundle& surface,
        const BuildingCollection& buildings,
        const SemanticScene* semanticScene = nullptr
    ) const;

    // Individual checks are public so they can be unit-tested
    // independently later.
    QualityReport validateSurfaceIdentity(
        const SurfaceBundle& surface
    ) const;

    QualityReport validateBuildings(
        const BuildingCollection& buildings
    ) const;

    QualityReport validateWaterBodies(
        const SurfaceBundle& surface,
        const SemanticScene& semanticScene
    ) const;

private:

    Config config_;

    bool isValidPixel(
        const SurfaceBundle& surface,
        std::size_t index
    ) const;

    void mergeReport(
        QualityReport& destination,
        const QualityReport& source
    ) const;
};