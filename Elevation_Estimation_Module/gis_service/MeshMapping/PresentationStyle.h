#pragma once

#include <algorithm>
#include <cctype>
#include <optional>
#include <string>
#include <string_view>

namespace depthwizard
{

// Render-only styles (playbook section 6.5). None of them changes geometry,
// heights or exported rasters; only materials, textures and UVs differ.
enum class PresentationStyle
{
    SCIENTIFIC,          // Height-coloured massing with edge lines (default)
    TERRA_MASSING,       // Ivory roofs, neutral walls, repaired optical or muted terrain
    ORTHOPHOTO_REALISTIC // Optical roofs, repaired optical terrain, procedural facades
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

// Case-insensitive; accepts the short names and the enum names.
inline std::optional<PresentationStyle> tryParsePresentationStyle(std::string_view text)
{
    std::string value(text);
    std::transform(value.begin(), value.end(), value.begin(),
                   [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
    if (value == "scientific") return PresentationStyle::SCIENTIFIC;
    if (value == "terra" || value == "terra_massing") return PresentationStyle::TERRA_MASSING;
    if (value == "orthophoto" || value == "orthophoto_realistic") return PresentationStyle::ORTHOPHOTO_REALISTIC;
    return std::nullopt;
}

} // namespace depthwizard
