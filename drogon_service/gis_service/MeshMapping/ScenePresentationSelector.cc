#include "ScenePresentationSelector.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <stdexcept>

ScenePresentationDecision ScenePresentationSelector::select(
    const SemanticScene& semantics, const GeoreferencedSurfaceBundle& surface,
    const BuildingCollection& buildings)
{
    const int width = surface.dtm.width, height = surface.dtm.height;
    const auto matches = [width, height](const auto& grid) {
        return grid.isValid() && grid.width == width && grid.height == height;
    };
    if (!matches(surface.dtm) || !matches(surface.validMask) ||
        !matches(semantics.buildingProbability) || !matches(semantics.vegetationProbability) ||
        !matches(semantics.groundProbability) || !matches(semantics.roadProbability) ||
        !matches(semantics.semanticConfidence) || !matches(semantics.finalClassMap))
        throw std::invalid_argument("ScenePresentationSelector: inconsistent input grids");

    ScenePresentationDecision decision;
    std::size_t valid = 0, strongBuildings = 0, vegetation = 0;
    std::array<std::size_t, 4> buildingByQuadrant{}, groundByQuadrant{};
    std::vector<float> groundElevations;
    for (int y = 0; y < height; ++y)
        for (int x = 0; x < width; ++x)
        {
            const auto i = static_cast<std::size_t>(y) * width + x;
            if (!surface.validMask.data[i] || !std::isfinite(surface.dtm.data[i])) continue;
            ++valid;
            const int quadrant = (x >= width / 2 ? 1 : 0) + (y >= height / 2 ? 2 : 0);
            const float building = semantics.buildingProbability.data[i];
            const float confidence = semantics.semanticConfidence.data[i];
            if (semantics.finalClassMap.data[i] == SemanticClass::BUILDING &&
                building >= .7F && confidence >= .5F)
            {
                ++strongBuildings;
                ++buildingByQuadrant[quadrant];
            }
            if (semantics.vegetationProbability.data[i] >= .6F) ++vegetation;
            const auto cls = semantics.finalClassMap.data[i];
            if ((cls == SemanticClass::GROUND || cls == SemanticClass::ROAD) &&
                confidence >= .6F && building < .1F &&
                std::max(semantics.groundProbability.data[i], semantics.roadProbability.data[i]) >= .6F)
            {
                groundElevations.push_back(surface.dtm.data[i]);
                ++groundByQuadrant[quadrant];
            }
        }

    if (valid < surface.dtm.data.size() / 2 || valid == 0)
    {
        decision.reason = "Insufficient valid scene coverage; retaining geographic terrain.";
        return decision;
    }
    decision.strongBuildingFraction = static_cast<double>(strongBuildings) / valid;
    decision.vegetationFraction = static_cast<double>(vegetation) / valid;
    int groundQuadrants = 0;
    for (int q = 0; q < 4; ++q)
    {
        // Do not let a handful of noisy pixels count as spatial coverage.
        if (buildingByQuadrant[q] >= std::max<std::size_t>(1, valid / 100)) ++decision.buildingQuadrants;
        if (groundByQuadrant[q] >= std::max<std::size_t>(1, valid / 200)) ++groundQuadrants;
    }
    if (groundElevations.size() >= 64 && groundQuadrants >= 3 &&
        groundElevations.size() >= valid / 50)
    {
        const std::size_t last = groundElevations.size() - 1;
        const auto lowIndex = static_cast<std::size_t>(.1 * last);
        const auto highIndex = static_cast<std::size_t>(.9 * last);
        std::nth_element(groundElevations.begin(), groundElevations.begin() + lowIndex, groundElevations.end());
        const float low = groundElevations[lowIndex];
        std::nth_element(groundElevations.begin(), groundElevations.begin() + highIndex, groundElevations.end());
        decision.groundReliefMetres = groundElevations[highIndex] - low;
    }

    // Broadly distributed buildings are required, not merely a building in a
    // mountain/forest scene. Supported large ground relief vetoes flattening.
    if (decision.vegetationFraction >= .55)
        decision.reason = "Vegetation-dominant scene; retaining terrain and skirts.";
    // This is a coarse surface-derived prior, not surveyed bare ground.
    // Do not let city-block contamination (as in the D.C. example) veto an
    // otherwise strong urban decision. Reserve this veto for major relief.
    else if (decision.groundReliefMetres > 80.0)
        decision.reason = "Substantial supported ground relief; retaining terrain and skirts.";
    else if (buildings.buildings.size() >= 3 && decision.strongBuildingFraction >= .10 &&
             decision.buildingQuadrants >= 3)
    {
        decision.presentation = ScenePresentation::FLAT_URBAN;
        decision.reason = "Distributed high-confidence urban structures; flat presentation without skirts.";
    }
    else
        decision.reason = "Urban evidence insufficient or localized; retaining terrain and skirts.";
    return decision;
}
