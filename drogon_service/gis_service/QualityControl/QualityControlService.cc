#include "QualityControlService.h"

#include <cmath>
#include <limits>
#include <queue>
#include <stdexcept>
#include <algorithm>


QualityControlService::QualityControlService(Config config)
    : config_(config)
{
    if (!std::isfinite(config_.surfaceIdentityToleranceMeters) ||
        config_.surfaceIdentityToleranceMeters < 0.0)
    {
        throw std::invalid_argument(
            "QualityControlService: surface identity tolerance "
            "must be finite and non-negative."
        );
    }

    if (!std::isfinite(config_.maximumBuildingHeightMeters) ||
        config_.maximumBuildingHeightMeters <= 0.0)
    {
        throw std::invalid_argument(
            "QualityControlService: maximum building height "
            "must be finite and greater than zero."
        );
    }

    if (!std::isfinite(config_.minimumBuildingHeightMeters) ||
        config_.minimumBuildingHeightMeters < 0.0)
    {
        throw std::invalid_argument(
            "QualityControlService: minimum building height "
            "must be finite and non-negative."
        );
    }

    if (!std::isfinite(config_.waterProbabilityThreshold) ||
        config_.waterProbabilityThreshold < 0.0f ||
        config_.waterProbabilityThreshold > 1.0f)
    {
        throw std::invalid_argument(
            "QualityControlService: water probability threshold "
            "must lie in [0, 1]."
        );
    }

    if (config_.minimumWaterComponentPixels == 0)
    {
        throw std::invalid_argument(
            "QualityControlService: minimum water component size "
            "must be greater than zero."
        );
    }

    if (!std::isfinite(config_.waterLevelToleranceMeters) ||
        config_.waterLevelToleranceMeters < 0.0)
    {
        throw std::invalid_argument(
            "QualityControlService: water level tolerance "
            "must be finite and non-negative."
        );
    }
}


// ============================================================
// Helper: check one surface pixel
// ============================================================

bool QualityControlService::isValidPixel(
    const SurfaceBundle& surface,
    std::size_t index
) const
{
    if (surface.validMask.has_value())
    {
        const auto& mask = *surface.validMask;

        if (index >= mask.data.size())
            return false;

        if (mask.data[index] == 0)
            return false;
    }

    if (index >= surface.DTM.data.size() ||
        index >= surface.DSM.data.size() ||
        index >= surface.nDSM.data.size())
    {
        return false;
    }

    const float dtm = surface.DTM.data[index];
    const float dsm = surface.DSM.data[index];
    const float ndsm = surface.nDSM.data[index];

    return surface.DTM.isValidValue(dtm) &&
           surface.DSM.isValidValue(dsm) &&
           surface.nDSM.isValidValue(ndsm);
}


// ============================================================
// CORE CHECK
//
// Verifies:
//
//     DSM = DTM + nDSM
//
// within tolerance.
// ============================================================

QualityReport QualityControlService::validateSurfaceIdentity(
    const SurfaceBundle& surface
) const
{
    QualityReport report;

    // --------------------------------------------------------
    // 1. Raster dimension/storage consistency
    // --------------------------------------------------------

    const bool dimensionsMatch =
        surface.DTM.width == surface.DSM.width &&
        surface.DTM.width == surface.nDSM.width &&
        surface.DTM.height == surface.DSM.height &&
        surface.DTM.height == surface.nDSM.height;

    const bool storageMatches =
        surface.DTM.hasExpectedSize() &&
        surface.DSM.hasExpectedSize() &&
        surface.nDSM.hasExpectedSize();

    report.rasterDimensionsPassed =
        dimensionsMatch && storageMatches;

    if (!report.rasterDimensionsPassed)
    {
        report.errors.push_back(
            "DTM, DSM and nDSM dimensions or storage sizes do not match."
        );

        report.surfaceIdentityPassed = false;
        report.passed = false;

        return report;
    }

    // --------------------------------------------------------
    // 2. Pixel-wise validation
    // --------------------------------------------------------

    const std::size_t totalPixels =
        surface.DTM.data.size();

    double sumAbsoluteError = 0.0;
    double maxAbsoluteError = 0.0;

    std::uint64_t validCount = 0;

    for (std::size_t i = 0; i < totalPixels; ++i)
    {
        if (!isValidPixel(surface, i))
            continue;

        const double dtm =
            static_cast<double>(surface.DTM.data[i]);

        const double dsm =
            static_cast<double>(surface.DSM.data[i]);

        const double ndsm =
            static_cast<double>(surface.nDSM.data[i]);

        const double residual =
            (dsm - dtm) - ndsm;

        const double absoluteError =
            std::abs(residual);

        sumAbsoluteError += absoluteError;

        maxAbsoluteError =
            std::max(maxAbsoluteError, absoluteError);

        ++validCount;
    }

    report.validPixels = validCount;

    // --------------------------------------------------------
    // 3. No usable pixels
    // --------------------------------------------------------

    if (validCount == 0)
    {
        report.surfaceIdentityPassed = false;
        report.passed = false;

        report.errors.push_back(
            "No valid pixels were available for surface identity QC."
        );

        return report;
    }

    // --------------------------------------------------------
    // 4. Statistics
    // --------------------------------------------------------

    report.maxSurfaceIdentityError =
        maxAbsoluteError;

    report.meanSurfaceIdentityError =
        sumAbsoluteError /
        static_cast<double>(validCount);

    // --------------------------------------------------------
    // 5. Tolerance check
    // --------------------------------------------------------

    report.surfaceIdentityPassed =
        maxAbsoluteError <=
        config_.surfaceIdentityToleranceMeters;

    if (!report.surfaceIdentityPassed)
    {
        report.errors.push_back(
            "Surface identity failed: "
            "|(DSM - DTM) - nDSM| exceeds the configured tolerance."
        );
    }

    report.passed =
        report.rasterDimensionsPassed &&
        report.surfaceIdentityPassed;

    return report;
}


// ============================================================
// BUILDING CHECK
//
// Verifies:
//
//     roofElevation > baseElevation
//
// and:
//
//     plausible building height
// ============================================================

QualityReport QualityControlService::validateBuildings(
    const BuildingCollection& buildings
) const
{
    QualityReport report;

    report.buildingHeightsPassed = true;
    report.checkedBuildings =
        buildings.buildings.size();

    // No building objects is not itself a failure.
    // Module 6 may legitimately produce an empty collection
    // for rural scenes.
    if (buildings.buildings.empty())
    {
        report.warnings.push_back(
            "Building QC skipped: no buildings were supplied."
        );

        report.passed = true;
        return report;
    }

    for (const auto& building : buildings.buildings)
    {
        bool buildingValid = true;

        const double base =
            static_cast<double>(building.baseElevation);

        const double roof =
            static_cast<double>(building.roofElevation);

        const double derivedHeight =
            roof - base;

        // ----------------------------------------------------
        // 1. Numeric sanity
        // ----------------------------------------------------

        if (!std::isfinite(base) ||
            !std::isfinite(roof))
        {
            buildingValid = false;

            report.errors.push_back(
                "Building " +
                std::to_string(building.buildingId) +
                " contains non-finite base or roof elevation."
            );
        }

        // ----------------------------------------------------
        // 2. Roof must be above the base
        // ----------------------------------------------------

        if (buildingValid &&
            derivedHeight <=
            config_.minimumBuildingHeightMeters)
        {
            buildingValid = false;

            report.errors.push_back(
                "Building " +
                std::to_string(building.buildingId) +
                " has roof elevation at or below its base elevation."
            );
        }

        // ----------------------------------------------------
        // 3. Plausible height guardrail
        // ----------------------------------------------------

        if (buildingValid &&
            derivedHeight >
            config_.maximumBuildingHeightMeters)
        {
            buildingValid = false;

            report.errors.push_back(
                "Building " +
                std::to_string(building.buildingId) +
                " has an implausibly large height of " +
                std::to_string(derivedHeight) +
                " meters."
            );
        }

        // ----------------------------------------------------
        // 4. Footprint sanity
        //
        // A polygon requires at least 3 vertices.
        // ----------------------------------------------------

        if (building.footprintPolygon.size() < 3)
        {
            buildingValid = false;

            report.errors.push_back(
                "Building " +
                std::to_string(building.buildingId) +
                " has an invalid footprint polygon."
            );
        }

        if (!buildingValid)
        {
            ++report.invalidBuildings;
        }
    }

    report.buildingHeightsPassed =
        (report.invalidBuildings == 0);

    return report;
}


// ============================================================
// WATER CHECK
//
// Semantic water probability -> connected components ->
// elevation range inside each component.
//
// This is a first implementation of the architecture's
// "water bodies are approximately level" check.
// ============================================================

QualityReport QualityControlService::validateWaterBodies(
    const SurfaceBundle& surface,
    const SemanticScene& semanticScene
) const
{
    QualityReport report;

    report.waterLevelPassed = true;

    // --------------------------------------------------------
    // No semantic water layer
    // --------------------------------------------------------

    if (!semanticScene.waterProbability.has_value())
    {
        report.warnings.push_back(
            "Water-level QC skipped: no water probability raster was supplied."
        );

        report.passed = true;
        return report;
    }

    const auto& water =
        *semanticScene.waterProbability;

    // --------------------------------------------------------
    // Dimension check
    // --------------------------------------------------------

    if (water.width != surface.DSM.width ||
        water.height != surface.DSM.height ||
        !water.hasExpectedSize())
    {
        report.waterLevelPassed = false;
        report.passed = false;

        report.errors.push_back(
            "Water probability raster dimensions do not match the surface raster."
        );

        return report;
    }

    const std::size_t totalPixels =
        water.data.size();

    std::vector<std::uint8_t> visited(totalPixels, 0);

    // 4-connected neighbourhood.
    const int rowOffsets[4] = {-1, 1, 0, 0};
    const int colOffsets[4] = {0, 0, -1, 1};

    // --------------------------------------------------------
    // Scan for water components
    // --------------------------------------------------------

    for (int row = 0;
         row < water.height;
         ++row)
    {
        for (int col = 0;
             col < water.width;
             ++col)
        {
            const std::size_t startIndex =
                static_cast<std::size_t>(row) *
                static_cast<std::size_t>(water.width) +
                static_cast<std::size_t>(col);

            if (visited[startIndex])
                continue;

            const float probability =
                water.data[startIndex];

            if (!water.isValidValue(probability) ||
                probability < config_.waterProbabilityThreshold)
            {
                visited[startIndex] = 1;
                continue;
            }

            // ------------------------------------------------
            // BFS connected component
            // ------------------------------------------------

            std::queue<std::pair<int, int>> pending;

            pending.push({row, col});
            visited[startIndex] = 1;

            std::size_t componentSize = 0;

            double minElevation =
                std::numeric_limits<double>::infinity();

            double maxElevation =
                -std::numeric_limits<double>::infinity();

            while (!pending.empty())
            {
                const auto [currentRow, currentCol] =
                    pending.front();

                pending.pop();

                const std::size_t index =
                    static_cast<std::size_t>(currentRow) *
                    static_cast<std::size_t>(water.width) +
                    static_cast<std::size_t>(currentCol);

                const float currentProbability =
                    water.data[index];

                if (!water.isValidValue(currentProbability) ||
                    currentProbability <
                        config_.waterProbabilityThreshold)
                {
                    continue;
                }

                ++componentSize;

                // ------------------------------------------------
                // Use DSM as the water-surface elevation.
                // This is an implementation choice for the first
                // version of the QC service.
                // ------------------------------------------------

                if (index < surface.DSM.data.size())
                {
                    const float elevation =
                        surface.DSM.data[index];

                    if (surface.DSM.isValidValue(elevation))
                    {
                        minElevation =
                            std::min(
                                minElevation,
                                static_cast<double>(elevation)
                            );

                        maxElevation =
                            std::max(
                                maxElevation,
                                static_cast<double>(elevation)
                            );
                    }
                }

                // ------------------------------------------------
                // Visit neighbouring pixels
                // ------------------------------------------------

                for (int n = 0; n < 4; ++n)
                {
                    const int nextRow =
                        currentRow + rowOffsets[n];

                    const int nextCol =
                        currentCol + colOffsets[n];

                    if (nextRow < 0 ||
                        nextRow >= water.height ||
                        nextCol < 0 ||
                        nextCol >= water.width)
                    {
                        continue;
                    }

                    const std::size_t nextIndex =
                        static_cast<std::size_t>(nextRow) *
                        static_cast<std::size_t>(water.width) +
                        static_cast<std::size_t>(nextCol);

                    if (visited[nextIndex])
                        continue;

                    visited[nextIndex] = 1;

                    const float nextProbability =
                        water.data[nextIndex];

                    if (water.isValidValue(nextProbability) &&
                        nextProbability >=
                            config_.waterProbabilityThreshold)
                    {
                        pending.push({
                            nextRow,
                            nextCol
                        });
                    }
                }
            }

            // ----------------------------------------------------
            // Ignore tiny isolated noise components.
            // ----------------------------------------------------

            if (componentSize <
                config_.minimumWaterComponentPixels)
            {
                continue;
            }

            // No valid elevations in this component.
            if (!std::isfinite(minElevation) ||
                !std::isfinite(maxElevation))
            {
                report.warnings.push_back(
                    "A water component had no valid elevation values."
                );

                continue;
            }

            const double elevationRange =
                maxElevation - minElevation;

            // ----------------------------------------------------
            // Levelness check
            // ----------------------------------------------------

            if (elevationRange >
                config_.waterLevelToleranceMeters)
            {
                report.waterLevelPassed = false;

                report.errors.push_back(
                    "A water body failed the levelness check. "
                    "Observed elevation range = " +
                    std::to_string(elevationRange) +
                    " meters."
                );
            }
        }
    }

    return report;
}


// ============================================================
// Merge individual reports
// ============================================================

void QualityControlService::mergeReport(
    QualityReport& destination,
    const QualityReport& source
) const
{
    destination.rasterDimensionsPassed =
        destination.rasterDimensionsPassed &&
        source.rasterDimensionsPassed;

    destination.surfaceIdentityPassed =
        destination.surfaceIdentityPassed &&
        source.surfaceIdentityPassed;

    destination.buildingHeightsPassed =
        destination.buildingHeightsPassed &&
        source.buildingHeightsPassed;

    destination.waterLevelPassed =
        destination.waterLevelPassed &&
        source.waterLevelPassed;

    destination.checkedPixels +=
        source.checkedPixels;

    destination.validPixels +=
        source.validPixels;

    destination.maxSurfaceIdentityError =
        std::max(
            destination.maxSurfaceIdentityError,
            source.maxSurfaceIdentityError
        );

    destination.meanSurfaceIdentityError =
        std::max(
            destination.meanSurfaceIdentityError,
            source.meanSurfaceIdentityError
        );

    destination.checkedBuildings +=
        source.checkedBuildings;

    destination.invalidBuildings +=
        source.invalidBuildings;

    destination.warnings.insert(
        destination.warnings.end(),
        source.warnings.begin(),
        source.warnings.end()
    );

    destination.errors.insert(
        destination.errors.end(),
        source.errors.begin(),
        source.errors.end()
    );
}


// ============================================================
// FULL MODULE 7 QC
// ============================================================

QualityReport QualityControlService::validate(
    const SurfaceBundle& surface,
    const BuildingCollection& buildings,
    const SemanticScene* semanticScene
) const
{
    QualityReport report;

    // Start with the individual checks as "passing".
    // Individual checks will turn them false if necessary.
    report.rasterDimensionsPassed = true;
    report.surfaceIdentityPassed = true;
    report.buildingHeightsPassed = true;
    report.waterLevelPassed = true;

    // --------------------------------------------------------
    // 1. Surface identity
    // --------------------------------------------------------

    const QualityReport surfaceReport =
        validateSurfaceIdentity(surface);

    mergeReport(
        report,
        surfaceReport
    );

    // --------------------------------------------------------
    // 2. Buildings
    // --------------------------------------------------------

    const QualityReport buildingReport =
        validateBuildings(buildings);

    mergeReport(
        report,
        buildingReport
    );

    // --------------------------------------------------------
    // 3. Water
    // --------------------------------------------------------

    if (semanticScene != nullptr)
    {
        const QualityReport waterReport =
            validateWaterBodies(
                surface,
                *semanticScene
            );

        mergeReport(
            report,
            waterReport
        );
    }
    else
    {
        report.warnings.push_back(
            "Water-level QC skipped: no SemanticScene was supplied."
        );
    }

    // --------------------------------------------------------
    // 4. Final gate
    // --------------------------------------------------------

    report.passed =
        report.rasterDimensionsPassed &&
        report.surfaceIdentityPassed &&
        report.buildingHeightsPassed &&
        report.waterLevelPassed;

    return report;
}