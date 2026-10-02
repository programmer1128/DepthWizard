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
     if (!value || value->empty() || *value == "0") return false;
     if (*value == "1") return true;
     warnings.push_back(name + "='" + *value + "' is not 0 or 1; using 0.");
     return false;
}
} // namespace

const char* toString(PresentationStyle style)
{
     switch (style)
     {
         case PresentationStyle::Terra: return "terra";
         case PresentationStyle::Orthophoto: return "orthophoto";
         case PresentationStyle::Scientific: break;
     }
     return "scientific";
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
         const std::string value = lower(*style);
         if (value == "terra") flags.presentationStyle = PresentationStyle::Terra;
         else if (value == "orthophoto") flags.presentationStyle = PresentationStyle::Orthophoto;
         else if (value != "scientific")
             flags.warnings.push_back("DEPTHWIZARD_PRESENTATION_STYLE='" + *style +
                                      "' is not scientific, terra or orthophoto; using scientific.");
     }
     flags.sam2 = parseSwitch(lookup, "DEPTHWIZARD_SAM2", flags.warnings);
     flags.kibs = parseSwitch(lookup, "DEPTHWIZARD_KIBS", flags.warnings);
     flags.hybridFusion = parseSwitch(lookup, "DEPTHWIZARD_HYBRID_FUSION", flags.warnings);
     return flags;
}

bool HybridFeatureFlags::allDefault() const
{
     return presentationStyle == PresentationStyle::Scientific && !sam2 && !kibs && !hybridFusion;
}

std::vector<std::string> HybridFeatureFlags::unimplementedRequests() const
{
     // Phase 0 defines the flags only; each phase removes its entry here.
     std::vector<std::string> requested;
     if (presentationStyle != PresentationStyle::Scientific)
         requested.push_back(std::string("DEPTHWIZARD_PRESENTATION_STYLE=") + toString(presentationStyle));
     if (sam2) requested.push_back("DEPTHWIZARD_SAM2=1");
     if (kibs) requested.push_back("DEPTHWIZARD_KIBS=1");
     if (hybridFusion) requested.push_back("DEPTHWIZARD_HYBRID_FUSION=1");
     return requested;
}

Json::Value HybridFeatureFlags::toJson() const
{
     Json::Value value(Json::objectValue);
     value["presentation_style"] = toString(presentationStyle);
     value["sam2"] = sam2;
     value["kibs"] = kibs;
     value["hybrid_fusion"] = hybridFusion;
     return value;
}

std::string HybridFeatureFlags::summary() const
{
     std::ostringstream text;
     text << "presentation_style=" << toString(presentationStyle)
          << " sam2=" << sam2 << " kibs=" << kibs << " hybrid_fusion=" << hybridFusion;
     return text.str();
}
