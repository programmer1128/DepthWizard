#include "QualityControlService.h"

#include <algorithm>
#include <cmath>
#include <limits>
#include <queue>
#include <stdexcept>
#include <vector>

namespace
{
    constexpr int kNeighbourCount = 4;

    constexpr int kRowOffsets[kNeighbourCount] =
    {
        -1, 1, 0, 0
    };

    constexpr int kColOffsets[kNeighbourCount] =
    {
        0, 0, -1, 1
    };

    bool dimensionsMatch(
        const RasterGrid<float>& a,
        const RasterGrid<float>& b
    )
    {
        return a.width == b.width &&
               a.height == b.height &&
               a.isValid() &&
               b.isValid();
    }

    bool dimensionsMatch(
        const RasterGrid<uint8_t>& mask,
        const RasterGrid<float>& raster
    )
    {
        return mask.width == raster.width &&
               mask.height == raster.height &&
               mask.isValid() &&
               raster.isValid();
    }

    bool validElevation(float value)
    {
        return std::isfinite(value);
    }
}

QualityControlService::QualityControlService(Config config)
    : config_(config)
{
    if (config_.surfaceIdentityToleranceMeters <= 0.0)
    {
        throw std::invalid_argument(
            "Surface identity tolerance must be positive."
        );
    }

    if (config_.minimumBuildingHeightMeters < 0.0)
    {
        throw std::invalid_argument(
            "Minimum building height cannot be negative."
        );
    }

    if (config_.maximumBuildingHeightMeters <=
        config_.minimumBuildingHeightMeters)
    {
        throw std::invalid_argument(
            "Maximum building height must exceed minimum building height."
        );
    }

    if (config_.waterProbabilityThreshold < 0.0f ||
        config_.waterProbabilityThreshold > 1.0f)
    {
        throw std::invalid_argument(
            "Water probability threshold must be in [0,1]."
        );
    }

    if (config_.minimumWaterComponentPixels == 0)
    {
        throw std::invalid_argument(
            "Minimum water component size must be greater than zero."
        );
    }

    if (config_.waterLevelToleranceMeters <= 0.0)
    {
        throw std::invalid_argument(
            "Water level tolerance must be positive."
        );
    }
}

QualityReport QualityControlService::validateSurfaceIdentity(
    const GeoreferencedSurfaceBundle& surface
) const
{
    QualityReport report;

    report.status = QualityStatus::PASS;
    report.safeForAbsoluteOutput = true;

    if (!surface.dtm.isValid() ||
        !surface.dsm.isValid() ||
        !surface.ndsm.isValid())
    {
        report.status = QualityStatus::FAIL;
        report.safeForAbsoluteOutput = false;

        report.violations.push_back(
            "DTM, DSM, and nDSM must all be valid rasters."
        );

        return report;
    }

    if (!dimensionsMatch(surface.dtm, surface.dsm) ||
        !dimensionsMatch(surface.dtm, surface.ndsm) ||
        !dimensionsMatch(surface.validMask, surface.dtm))
    {
        report.status = QualityStatus::FAIL;
        report.safeForAbsoluteOutput = false;

        report.violations.push_back(
            "DTM, DSM, nDSM, and valid mask dimensions do not match."
        );

        return report;
    }

    double sumAbsoluteError = 0.0;
    std::size_t validPixelCount = 0;

    double maximumError = 0.0;

    for (int row = 0; row < surface.dtm.height; ++row)
    {
        for (int col = 0; col < surface.dtm.width; ++col)
        {
            const std::size_t index =
                static_cast<std::size_t>(row) *
                    static_cast<std::size_t>(surface.dtm.width)
                + static_cast<std::size_t>(col);

            if (surface.validMask.data[index] == 0)
            {
                continue;
            }

            const float dtm =
                surface.dtm.data[index];

            const float dsm =
                surface.dsm.data[index];

            const float ndsm =
                surface.ndsm.data[index];

            if (!validElevation(dtm) ||
                !validElevation(dsm) ||
                !validElevation(ndsm))
            {
                continue;
            }

            const double residual =
                (static_cast<double>(dsm) -
                 static_cast<double>(dtm)) -
                 static_cast<double>(ndsm);

            const double absoluteError =
                std::abs(residual);

            maximumError =
                std::max(maximumError, absoluteError);

            sumAbsoluteError += absoluteError;

            ++validPixelCount;
        }
    }

    if (validPixelCount == 0)
    {
        report.status = QualityStatus::FAIL;
        report.safeForAbsoluteOutput = false;

        report.violations.push_back(
            "No valid pixels were available for the DSM/DTM/nDSM identity check."
        );

        return report;
    }

    const double meanAbsoluteError =
        sumAbsoluteError /
        static_cast<double>(validPixelCount);

    /*
     * The core scientific identity required by Module 7 is:

         abs((DSM - DTM) - nDSM) < tolerance

     * We reject the surface when the worst valid pixel exceeds
     * the configured tolerance.
     */
    if (maximumError > config_.surfaceIdentityToleranceMeters)
    {
        report.status = QualityStatus::FAIL;
        report.safeForAbsoluteOutput = false;

        report.violations.push_back(
            "Surface identity check failed: "
            "abs((DSM - DTM) - nDSM) exceeds tolerance."
        );
    }

    report.userWarnings.push_back(
        "Surface identity mean absolute residual: " +
        std::to_string(meanAbsoluteError) +
        " m."
    );

    report.userWarnings.push_back(
        "Surface identity maximum absolute residual: " +
        std::to_string(maximumError) +
        " m."
    );

    return report;
}

QualityReport QualityControlService::validateBuildings(
    const BuildingCollection& buildings
) const
{
    QualityReport report;

    report.status = QualityStatus::PASS;
    report.safeForAbsoluteOutput = true;

    for (const BuildingInstance& building :
         buildings.buildings)
    {
        const float base =
            building.representativeBaseElevation;

        const float roof =
            building.roofElevation;

        const float height =
            building.heightAboveGround;

        if (!std::isfinite(base) ||
            !std::isfinite(roof) ||
            !std::isfinite(height))
        {
            report.status = QualityStatus::FAIL;
            report.safeForAbsoluteOutput = false;

            report.violations.push_back(
                "Building " +
                std::to_string(building.buildingId) +
                " contains non-finite elevation values."
            );

            continue;
        }

        if (building.projectedFootprint.outerRing.size() < 3)
        {
            report.status = QualityStatus::FAIL;
            report.safeForAbsoluteOutput = false;

            report.violations.push_back(
                "Building " +
                std::to_string(building.buildingId) +
                " has an invalid footprint."
            );
        }

        if (height <= config_.minimumBuildingHeightMeters)
        {
            report.status = QualityStatus::FAIL;
            report.safeForAbsoluteOutput = false;

            report.violations.push_back(
                "Building " +
                std::to_string(building.buildingId) +
                " does not have a strictly positive height above its base."
            );
        }

        if (height > config_.maximumBuildingHeightMeters)
        {
            report.status = QualityStatus::FAIL;
            report.safeForAbsoluteOutput = false;

            report.violations.push_back(
                "Building " +
                std::to_string(building.buildingId) +
                " exceeds the configured maximum plausible height."
            );
        }

        const double reconstructedRoof =
            static_cast<double>(base) +
            static_cast<double>(height);

        if (std::abs(
                reconstructedRoof -
                static_cast<double>(roof)
            ) > config_.surfaceIdentityToleranceMeters)
        {
            report.status = QualityStatus::FAIL;
            report.safeForAbsoluteOutput = false;

            report.violations.push_back(
                "Building " +
                std::to_string(building.buildingId) +
                " has inconsistent base + height and roof elevation."
            );
        }

        /*
         * Preserve non-fatal geometry warnings generated by Module 6.
         */
        for (const std::string& warning :
             building.geometryWarnings)
        {
            report.userWarnings.push_back(
                "Building " +
                std::to_string(building.buildingId) +
                ": " +
                warning
            );
        }
    }

    return report;
}

QualityReport QualityControlService::validateWaterBodies(
    const GeoreferencedSurfaceBundle& surface,
    const SemanticScene& semantics
) const
{
    QualityReport report;

    report.status = QualityStatus::PASS;
    report.safeForAbsoluteOutput = true;

    if (!surface.dsm.isValid() ||
        !surface.validMask.isValid() ||
        !semantics.waterProbability.isValid())
    {
        report.status = QualityStatus::FAIL;
        report.safeForAbsoluteOutput = false;

        report.violations.push_back(
            "Water QC cannot run because required rasters are invalid."
        );

        return report;
    }

    if (!dimensionsMatch(
            semantics.waterProbability,
            surface.dsm
        ))
    {
        report.status = QualityStatus::FAIL;
        report.safeForAbsoluteOutput = false;

        report.violations.push_back(
            "Water probability raster does not match the surface grid."
        );

        return report;
    }

    const int width = surface.dsm.width;
    const int height = surface.dsm.height;

    std::vector<uint8_t> visited(
        static_cast<std::size_t>(width) *
        static_cast<std::size_t>(height),
        0
    );

    for (int row = 0; row < height; ++row)
    {
        for (int col = 0; col < width; ++col)
        {
            const std::size_t startIndex =
                static_cast<std::size_t>(row) *
                    static_cast<std::size_t>(width)
                + static_cast<std::size_t>(col);

            if (visited[startIndex] != 0)
            {
                continue;
            }

            if (surface.validMask.data[startIndex] == 0)
            {
                visited[startIndex] = 1;
                continue;
            }

            if (semantics.waterProbability.data[startIndex] <
                config_.waterProbabilityThreshold)
            {
                visited[startIndex] = 1;
                continue;
            }

            /*
             * BFS for one connected water component.
             */
            std::queue<std::pair<int, int>> queue;

            queue.push({row, col});
            visited[startIndex] = 1;

            std::vector<float> elevations;

            while (!queue.empty())
            {
                const auto [currentRow, currentCol] =
                    queue.front();

                queue.pop();

                const std::size_t index =
                    static_cast<std::size_t>(currentRow) *
                        static_cast<std::size_t>(width)
                    + static_cast<std::size_t>(currentCol);

                const float elevation =
                    surface.dsm.data[index];

                if (validElevation(elevation))
                {
                    elevations.push_back(elevation);
                }

                for (int neighbour = 0;
                     neighbour < kNeighbourCount;
                     ++neighbour)
                {
                    const int nextRow =
                        currentRow +
                        kRowOffsets[neighbour];

                    const int nextCol =
                        currentCol +
                        kColOffsets[neighbour];

                    if (nextRow < 0 ||
                        nextRow >= height ||
                        nextCol < 0 ||
                        nextCol >= width)
                    {
                        continue;
                    }

                    const std::size_t nextIndex =
                        static_cast<std::size_t>(nextRow) *
                            static_cast<std::size_t>(width)
                        + static_cast<std::size_t>(nextCol);

                    if (visited[nextIndex] != 0)
                    {
                        continue;
                    }

                    if (surface.validMask.data[nextIndex] == 0)
                    {
                        visited[nextIndex] = 1;
                        continue;
                    }

                    if (semantics.waterProbability.data[nextIndex] <
                        config_.waterProbabilityThreshold)
                    {
                        visited[nextIndex] = 1;
                        continue;
                    }

                    visited[nextIndex] = 1;
                    queue.push({nextRow, nextCol});
                }
            }

            /*
             * Ignore tiny components because they are more likely
             * to represent isolated classification noise than a
             * meaningful water body.
             */
            if (elevations.size() <
                config_.minimumWaterComponentPixels)
            {
                continue;
            }

            const auto [minimumIt, maximumIt] =
                std::minmax_element(
                    elevations.begin(),
                    elevations.end()
                );

            const double elevationRange =
                static_cast<double>(*maximumIt) -
                static_cast<double>(*minimumIt);

            if (elevationRange >
                config_.waterLevelToleranceMeters)
            {
                report.status = QualityStatus::FAIL;
                report.safeForAbsoluteOutput = false;

                report.violations.push_back(
                    "A water-body component has an elevation "
                    "range greater than the configured level tolerance."
                );
            }
        }
    }

    return report;
}

float QualityControlService::calculateOverallConfidence(
    const GeoreferencedSurfaceBundle& surface
) const
{
    if (!surface.surfaceConfidence.isValid() ||
        !surface.validMask.isValid())
    {
        return 0.0f;
    }

    double sum = 0.0;
    std::size_t count = 0;

    for (std::size_t i = 0;
         i < surface.surfaceConfidence.data.size();
         ++i)
    {
        if (surface.validMask.data[i] == 0)
        {
            continue;
        }

        const float confidence =
            surface.surfaceConfidence.data[i];

        if (!std::isfinite(confidence))
        {
            continue;
        }

        sum += static_cast<double>(
            std::clamp(confidence, 0.0f, 1.0f)
        );

        ++count;
    }

    if (count == 0)
    {
        return 0.0f;
    }

    return static_cast<float>(
        sum / static_cast<double>(count)
    );
}

QualityReport QualityControlService::validate(
    const GeoreferencedSurfaceBundle& surface,
    const BuildingCollection& buildings,
    const SemanticScene& semantics
) const
{
    QualityReport finalReport;

    finalReport.status = QualityStatus::PASS;
    finalReport.safeForAbsoluteOutput = true;

    const QualityReport surfaceReport =
        validateSurfaceIdentity(surface);

    const QualityReport buildingReport =
        validateBuildings(buildings);

    const QualityReport waterReport =
        validateWaterBodies(surface, semantics);

    const auto merge =
        [&finalReport](const QualityReport& report)
        {
            if (report.status == QualityStatus::FAIL)
            {
                finalReport.status = QualityStatus::FAIL;
                finalReport.safeForAbsoluteOutput = false;
            }
            else if (report.status == QualityStatus::WARN &&
                     finalReport.status == QualityStatus::PASS)
            {
                finalReport.status = QualityStatus::WARN;
            }

            finalReport.violations.insert(
                finalReport.violations.end(),
                report.violations.begin(),
                report.violations.end()
            );

            finalReport.userWarnings.insert(
                finalReport.userWarnings.end(),
                report.userWarnings.begin(),
                report.userWarnings.end()
            );
        };

    merge(surfaceReport);
    merge(buildingReport);
    merge(waterReport);

    finalReport.overallConfidence =
        calculateOverallConfidence(surface);

    /*
     * Even with a technically passing QC result, a low model
     * confidence should remain visible to downstream consumers.
     */
    if (finalReport.overallConfidence < 0.50f &&
        finalReport.status == QualityStatus::PASS)
    {
        finalReport.status = QualityStatus::WARN;

        finalReport.userWarnings.push_back(
            "Overall surface confidence is below 0.50."
        );
    }

    return finalReport;
}