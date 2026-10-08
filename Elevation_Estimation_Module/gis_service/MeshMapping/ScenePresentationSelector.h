#pragma once
#include "MeshBuildConfig.h"
#include "../structures/GeographicStructs.h"
#include "../structures/SurfaceStructs.h"

struct ScenePresentationDecision
{
    ScenePresentation presentation{ScenePresentation::METRIC};
    std::string reason;
    double strongBuildingFraction{0};
    double vegetationFraction{0};
    double groundReliefMetres{0};
    int buildingQuadrants{0};
};

// Presentation classification, not a replacement for scientific land-cover
// classification. Conservative defaults retain terrain when evidence is weak.
class ScenePresentationSelector
{
public:
    static ScenePresentationDecision select(
        const SemanticScene& semantics, const GeoreferencedSurfaceBundle& surface,
        const BuildingCollection& buildings);
};
