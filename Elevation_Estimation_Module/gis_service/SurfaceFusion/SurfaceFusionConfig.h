#pragma once

#include <cmath>

struct SurfaceFusionConfig
{
    // Pixels classified as ground infrastructure cannot carry above-ground
    // height. This removes nDSM model noise from roads, bare ground and water.
    bool suppressGroundInfrastructureNdsm{true};

    // UNKNOWN pixels retain nDSM only when one of the two legitimate
    // above-ground object probabilities remains credible. This preserves
    // uncertain roof/canopy edges without allowing generic urban texture to
    // become a rolling surface.
    float uncertainObjectProbabilityThreshold{0.35F};

    // Metric nDSM is a height above ground and is therefore non-negative.
    bool clampNegativeNdsmToZero{true};

    bool validate() const
    {
        return std::isfinite(uncertainObjectProbabilityThreshold) &&
            uncertainObjectProbabilityThreshold >= 0.0F &&
            uncertainObjectProbabilityThreshold <= 1.0F;
    }
};
