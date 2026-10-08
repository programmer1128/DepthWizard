#include "ScenePresentationPolicy.h"

#include <algorithm>
#include <cctype>
#include <cstdlib>

const char* toString(ScenePresentationPolicy policy)
{
    switch (policy)
    {
    case ScenePresentationPolicy::FORCE_FLAT_URBAN: return "flat_urban";
    case ScenePresentationPolicy::FORCE_METRIC: return "metric";
    case ScenePresentationPolicy::AUTO: break;
    }
    return "auto";
}

const char* toString(ScenePresentation presentation)
{
    return presentation == ScenePresentation::FLAT_URBAN ? "flat_urban" : "metric";
}

ScenePresentationPolicySetting parseScenePresentationPolicy(const std::optional<std::string>& value)
{
    ScenePresentationPolicySetting setting;
    if (!value || value->empty()) return setting;
    std::string text = *value;
    std::transform(text.begin(), text.end(), text.begin(),
                   [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
    if (text == "auto") return setting;
    if (text == "flat_urban")
        setting.policy = ScenePresentationPolicy::FORCE_FLAT_URBAN;
    else if (text == "metric")
        setting.policy = ScenePresentationPolicy::FORCE_METRIC;
    else
        setting.warning = "DEPTHWIZARD_PRESENTATION='" + *value +
                          "' is not auto, flat_urban or metric; using auto.";
    return setting;
}

ScenePresentationPolicySetting scenePresentationPolicyFromEnvironment()
{
    const char* value = std::getenv("DEPTHWIZARD_PRESENTATION");
    return parseScenePresentationPolicy(value ? std::optional<std::string>(value) : std::nullopt);
}

ScenePresentation resolveScenePresentation(ScenePresentationPolicy policy,
                                           const ScenePresentationDecision& decision)
{
    switch (policy)
    {
    case ScenePresentationPolicy::FORCE_FLAT_URBAN: return ScenePresentation::FLAT_URBAN;
    case ScenePresentationPolicy::FORCE_METRIC: return ScenePresentation::METRIC;
    case ScenePresentationPolicy::AUTO: break;
    }
    return decision.presentation;
}
