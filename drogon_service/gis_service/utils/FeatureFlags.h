#pragma once
#include <json/value.h>

#include <functional>
#include <optional>
#include <string>
#include <vector>

// Feature flags for the hybrid-rendering roadmap
// (HYBRID_RENDERING_IMPLEMENTATION_PLAYBOOK.md). Every flag defaults to the
// current behaviour. No flag changes the pipeline yet: until its phase lands,
// a requested flag is reported as unimplemented and ignored.
//
// Not to be confused with DEPTHWIZARD_PRESENTATION (flat_urban | metric),
// which selects the scene's vertical frame, not its visual style.
enum class PresentationStyle
{
     Scientific,  // current height-coloured massing (default)
     Terra,       // neutral TerraPrinter-like massing
     Orthophoto   // optical roof/terrain textures
};

struct HybridFeatureFlags
{
     PresentationStyle presentationStyle{PresentationStyle::Scientific};
     bool sam2{false};          // DEPTHWIZARD_SAM2
     bool kibs{false};          // DEPTHWIZARD_KIBS
     bool hybridFusion{false};  // DEPTHWIZARD_HYBRID_FUSION
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

const char* toString(PresentationStyle style);
