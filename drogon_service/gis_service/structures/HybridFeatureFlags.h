#pragma once

#include "../MeshMapping/PresentationStyle.h"
#include <cstdlib>
#include <string>
#include <string_view>

namespace depthwizard
{

struct HybridFeatureFlags
{
    PresentationStyle presentationStyle{PresentationStyle::SCIENTIFIC};
    bool enableSam2{false};
    bool enableKibs{false};
    bool enableHybridFusion{false};

    static HybridFeatureFlags loadFromEnvironment()
    {
        HybridFeatureFlags flags;

        // DEPTHWIZARD_PRESENTATION_STYLE=scientific|terra|orthophoto
        const char* styleEnv = std::getenv("DEPTHWIZARD_PRESENTATION_STYLE");
        if (styleEnv && *styleEnv)
        {
            flags.presentationStyle = parsePresentationStyle(styleEnv);
        }

        // DEPTHWIZARD_SAM2=0|1
        const char* sam2Env = std::getenv("DEPTHWIZARD_SAM2");
        if (sam2Env && *sam2Env)
        {
            const std::string_view s(sam2Env);
            flags.enableSam2 = (s == "1" || s == "true" || s == "TRUE" || s == "on" || s == "ON");
        }

        // DEPTHWIZARD_KIBS=0|1
        const char* kibsEnv = std::getenv("DEPTHWIZARD_KIBS");
        if (kibsEnv && *kibsEnv)
        {
            const std::string_view s(kibsEnv);
            flags.enableKibs = (s == "1" || s == "true" || s == "TRUE" || s == "on" || s == "ON");
        }

        // DEPTHWIZARD_HYBRID_FUSION=0|1
        const char* fusionEnv = std::getenv("DEPTHWIZARD_HYBRID_FUSION");
        if (fusionEnv && *fusionEnv)
        {
            const std::string_view s(fusionEnv);
            flags.enableHybridFusion = (s == "1" || s == "true" || s == "TRUE" || s == "on" || s == "ON");
        }

        return flags;
    }
};

} // namespace depthwizard

