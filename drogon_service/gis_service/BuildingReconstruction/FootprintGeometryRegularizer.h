#pragma once

#include "BuildingReconstructionTypes.h"
#include <vector>

// Candidate generators only. The vectorizer applies its area, courtyard,
// neighbour-exclusion, and mask-overlap checks before accepting either shape.
class FootprintGeometryRegularizer
{
public:
    static std::vector<ProjectedPoint> regularizeContourWithCgal(
        const std::vector<ProjectedPoint>& ring, double maxShiftMetres,
        double areaDeviationTolerance);

    static FootprintPolygon<ProjectedPoint> simplifyPolygonWithGeos(
        const FootprintPolygon<ProjectedPoint>& footprint,
        double toleranceMetres);
};
