#include "FeatureFlags.h"

#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <sstream>

namespace
{
std::string lower(std::string text)
{
     std::transform(text.begin(), text.end(), text.begin(),
                    [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
     return text;
}

bool parseSwitch(const HybridFeatureFlags::Lookup& lookup, const std::string& name,
                 std::vector<std::string>& warnings)
{
     const std::optional<std::string> value = lookup(name);
     if (!value || value->empty()) return false;
     const std::string text = lower(*value);
     if (text == "1" || text == "true" || text == "on") return true;
     if (text == "0" || text == "false" || text == "off") return false;
     warnings.push_back(name + "='" + *value + "' is not 0 or 1; using 0.");
     return false;
}
} // namespace

const char* toString(City3dMode mode)
{
     return mode == City3dMode::Selected ? "selected" : "shadow";
}

HybridFeatureFlags HybridFeatureFlags::fromEnvironment()
{
     return parse([](const std::string& name) -> std::optional<std::string>
     {
         const char* value = std::getenv(name.c_str());
         if (value == nullptr) return std::nullopt;
         return std::string(value);
     });
}

HybridFeatureFlags HybridFeatureFlags::parse(const Lookup& lookup)
{
     HybridFeatureFlags flags;
     if (const auto style = lookup("DEPTHWIZARD_PRESENTATION_STYLE"); style && !style->empty())
     {
         if (const auto parsed = depthwizard::tryParsePresentationStyle(*style))
             flags.presentationStyle = *parsed;
         else
             flags.warnings.push_back("DEPTHWIZARD_PRESENTATION_STYLE='" + *style +
                                      "' is not scientific, terra or orthophoto; using scientific.");
     }
     flags.neutralFacades = parseSwitch(lookup, "DEPTHWIZARD_NEUTRAL_FACADES", flags.warnings);
     flags.sam2 = parseSwitch(lookup, "DEPTHWIZARD_SAM2", flags.warnings);
     flags.kibs = parseSwitch(lookup, "DEPTHWIZARD_KIBS", flags.warnings);
     flags.hybridFusion = parseSwitch(lookup, "DEPTHWIZARD_HYBRID_FUSION", flags.warnings);
     flags.city3d = parseSwitch(lookup, "DEPTHWIZARD_CITY3D", flags.warnings);
     if (const auto mode = lookup("DEPTHWIZARD_CITY3D_MODE"); mode && !mode->empty())
     {
         const std::string value = lower(*mode);
         if (value == "selected") flags.city3dMode = City3dMode::Selected;
         else if (value != "shadow")
             flags.warnings.push_back("DEPTHWIZARD_CITY3D_MODE='" + *mode + "' is not shadow or selected; using shadow.");
     }
     return flags;
}

bool HybridFeatureFlags::allDefault() const
{
     return presentationStyle == PresentationStyle::SCIENTIFIC && !neutralFacades &&
            !sam2 && !kibs && !hybridFusion && !city3d;
}

std::vector<std::string> HybridFeatureFlags::unimplementedRequests() const
{
     // Each phase removes its entry here; presentation styles landed in Phase 2.
     std::vector<std::string> requested;
     if (sam2) requested.push_back("DEPTHWIZARD_SAM2=1");
     if (kibs) requested.push_back("DEPTHWIZARD_KIBS=1");
     if (hybridFusion) requested.push_back("DEPTHWIZARD_HYBRID_FUSION=1");
     return requested;
}

Json::Value HybridFeatureFlags::toJson() const
{
     Json::Value value(Json::objectValue);
     value["presentation_style"] = depthwizard::toString(presentationStyle);
     value["neutral_facades"] = neutralFacades;
     value["sam2"] = sam2;
     value["kibs"] = kibs;
     value["hybrid_fusion"] = hybridFusion;
     value["city3d"] = city3d;
     value["city3d_mode"] = toString(city3dMode);
     return value;
}

std::string HybridFeatureFlags::summary() const
{
     std::ostringstream text;
     text << "presentation_style=" << depthwizard::toString(presentationStyle)
          << " neutral_facades=" << neutralFacades
          << " sam2=" << sam2 << " kibs=" << kibs << " hybrid_fusion=" << hybridFusion
          << " city3d=" << city3d << " city3d_mode=" << toString(city3dMode);
     return text.str();
}
