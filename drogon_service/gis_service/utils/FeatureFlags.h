#pragma once
#include "../MeshMapping/PresentationStyle.h"

#include <json/value.h>

#include <functional>
#include <optional>
#include <string>
#include <vector>

// Feature flags for the hybrid-rendering roadmap
// (HYBRID_RENDERING_IMPLEMENTATION_PLAYBOOK.md), parsed in one place. Every
// flag defaults to the current behaviour. A flag whose phase has not landed
// is reported as unimplemented and ignored.
//
// Not to be confused with DEPTHWIZARD_PRESENTATION (auto | flat_urban | metric,
// see MeshMapping/ScenePresentationPolicy.h), which selects the scene's
// vertical frame, not its visual style.
using PresentationStyle = depthwizard::PresentationStyle;

// shadow: City3D runs and is measured, but the returned GLB is native.
// selected: validated City3D shells replace native geometry per building.
enum class City3dMode
{
     Shadow,
     Selected
};
const char* toString(City3dMode mode);

struct HybridFeatureFlags
{
     // DEPTHWIZARD_PRESENTATION_STYLE=scientific|terra|orthophoto (Phase 2)
     PresentationStyle presentationStyle{PresentationStyle::SCIENTIFIC};
     // DEPTHWIZARD_NEUTRAL_FACADES=0|1 (Phase 2): plain concrete facades
     // without synthetic windows, for scientific/defence presentations.
     bool neutralFacades{false};
     bool sam2{false};          // DEPTHWIZARD_SAM2 (Phase 4)
     bool kibs{false};          // DEPTHWIZARD_KIBS (Phase 5)
     bool hybridFusion{false};  // DEPTHWIZARD_HYBRID_FUSION (Phase 6)
     bool city3d{false};                           // DEPTHWIZARD_CITY3D
     City3dMode city3dMode{City3dMode::Shadow};    // DEPTHWIZARD_CITY3D_MODE
     // Invalid values fall back to the default and are reported here.
     std::vector<std::string> warnings;

     using Lookup = std::function<std::optional<std::string>(const std::string&)>;
     static HybridFeatureFlags fromEnvironment();
     static HybridFeatureFlags parse(const Lookup& lookup);

     bool allDefault() const;
     // Flags that are set but whose phase is not implemented yet.
     std::vector<std::string> unimplementedRequests() const;
     Json::Value toJson() const;
     std::string summary() const;
};
