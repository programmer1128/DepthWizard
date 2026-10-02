#pragma once

#include <string>
#include <string_view>

namespace depthwizard
{

enum class PresentationStyle
{
    SCIENTIFIC,          // Current height-colored baseline with optional edge lines
    TERRA_MASSING,       // Clean ivory/white roofs, neutral walls, muted/optical terrain
    ORTHOPHOTO_REALISTIC // Photographic roof texture, repaired optical terrain, facade atlas
};

inline const char* toString(PresentationStyle style) noexcept
{
    switch (style)
    {
        case PresentationStyle::SCIENTIFIC:
            return "scientific";
        case PresentationStyle::TERRA_MASSING:
            return "terra";
        case PresentationStyle::ORTHOPHOTO_REALISTIC:
            return "orthophoto";
    }
    return "scientific";
}

inline PresentationStyle parsePresentationStyle(std::string_view str) noexcept
{
    if (str == "terra" || str == "TERRA" ||
        str == "terra_massing" || str == "TERRA_MASSING")
    {
        return PresentationStyle::TERRA_MASSING;
    }
    if (str == "orthophoto" || str == "ORTHOPHOTO" ||
        str == "orthophoto_realistic" || str == "ORTHOPHOTO_REALISTIC")
    {
        return PresentationStyle::ORTHOPHOTO_REALISTIC;
    }
    return PresentationStyle::SCIENTIFIC;
}

} // namespace depthwizard

