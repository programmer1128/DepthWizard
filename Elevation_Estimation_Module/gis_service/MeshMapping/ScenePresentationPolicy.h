#pragma once
#include "ScenePresentationSelector.h"

#include <optional>
#include <string>

// DEPTHWIZARD_PRESENTATION: who decides the scene's vertical frame.
//
//   auto (default)  ScenePresentationSelector decides, and nothing overrides it.
//   flat_urban      operator override: every scene renders on a flat Y=0 ground.
//   metric          operator override: every scene keeps DTM terrain and skirts.
//
// The policy is render-only. Scientific rasters, exports and height queries are
// identical under every policy.
enum class ScenePresentationPolicy
{
    AUTO,
    FORCE_FLAT_URBAN,
    FORCE_METRIC
};

struct ScenePresentationPolicySetting
{
    ScenePresentationPolicy policy{ScenePresentationPolicy::AUTO};
    // Set when an unrecognised value fell back to AUTO.
    std::optional<std::string> warning;
};

// Value as written in DEPTHWIZARD_PRESENTATION: auto, flat_urban or metric.
const char* toString(ScenePresentationPolicy policy);
const char* toString(ScenePresentation presentation);

// Case-insensitive. A missing or empty value is AUTO; an unrecognised value
// is AUTO plus a warning.
ScenePresentationPolicySetting parseScenePresentationPolicy(const std::optional<std::string>& value);
ScenePresentationPolicySetting scenePresentationPolicyFromEnvironment();

// AUTO returns the selector's decision unchanged; the overrides ignore it.
ScenePresentation resolveScenePresentation(ScenePresentationPolicy policy,
                                           const ScenePresentationDecision& decision);
