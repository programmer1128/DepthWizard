#include "VegetationConfig.h"

#include <algorithm>
#include <cctype>
#include <charconv>
#include <cmath>
#include <cstdlib>
#include <sstream>
#include <type_traits>

namespace
{
std::string lower(std::string text)
{
     std::transform(text.begin(), text.end(), text.begin(),
                    [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
     return text;
}

void parseSwitch(const VegetationConfig::Lookup& lookup, const std::string& name, bool& target,
                 std::vector<std::string>& warnings)
{
     const std::optional<std::string> value = lookup(name);
     if (!value || value->empty()) return;
     const std::string text = lower(*value);
     if (text == "1" || text == "true" || text == "on") target = true;
     else if (text == "0" || text == "false" || text == "off") target = false;
     else
          warnings.push_back(name + "='" + *value + "' is not 0 or 1; using " + (target ? "1." : "0."));
}

// A finite number inside [low, high]; anything else keeps the default.
template <typename T>
void parseNumber(const VegetationConfig::Lookup& lookup, const std::string& name, T& target, double low,
                 double high, std::vector<std::string>& warnings)
{
     const std::optional<std::string> value = lookup(name);
     if (!value || value->empty()) return;
     double parsed = 0.0;
     const char* begin = value->data();
     const char* end = begin + value->size();
     const auto [stop, error] = std::from_chars(begin, end, parsed);
     const bool integral = std::is_integral_v<T>;
     if (error != std::errc() || stop != end || !std::isfinite(parsed) || parsed < low || parsed > high ||
         (integral && parsed != std::floor(parsed)))
     {
          std::ostringstream message;
          message << name << "='" << *value << "' is not a " << (integral ? "whole number" : "number")
                  << " in [" << low << ", " << high << "]; using " << target << ".";
          warnings.push_back(message.str());
          return;
     }
     target = static_cast<T>(parsed);
}
} // namespace

const char* toString(VegetationAssetMode mode)
{
     return mode == VegetationAssetMode::EXTERNAL ? "external" : "procedural";
}

const char* toString(VegetationMode mode)
{
     switch (mode)
     {
     case VegetationMode::ON: return "1";
     case VegetationMode::AUTO: return "auto";
     case VegetationMode::OFF: break;
     }
     return "0";
}

VegetationConfig VegetationConfig::fromEnvironment()
{
     return parse([](const std::string& name) -> std::optional<std::string>
     {
          const char* value = std::getenv(name.c_str());
          if (value == nullptr) return std::nullopt;
          return std::string(value);
     });
}

VegetationConfig VegetationConfig::parse(const Lookup& lookup)
{
     VegetationConfig config;
     if (const auto mode = lookup("DEPTHWIZARD_VEGETATION"); mode && !mode->empty())
     {
          const std::string text = lower(*mode);
          if (text == "1" || text == "true" || text == "on") config.mode = VegetationMode::ON;
          else if (text == "auto") config.mode = VegetationMode::AUTO;
          else if (text != "0" && text != "false" && text != "off")
               config.warnings.push_back("DEPTHWIZARD_VEGETATION='" + *mode + "' is not 0, 1 or auto; using 0.");
     }
     parseSwitch(lookup, "DEPTHWIZARD_VEGETATION_CANOPY", config.canopy, config.warnings);
     parseSwitch(lookup, "DEPTHWIZARD_VEGETATION_TREES", config.trees, config.warnings);
     parseSwitch(lookup, "DEPTHWIZARD_VEGETATION_DIAGNOSTICS", config.diagnostics, config.warnings);
     parseSwitch(lookup, "DEPTHWIZARD_VEGETATION_RECOVER_UNKNOWN", config.recoverUnknown, config.warnings);
     parseNumber(lookup, "DEPTHWIZARD_VEGETATION_MIN_HEIGHT_M", config.minHeightMetres, 0.0, 20.0, config.warnings);
     parseNumber(lookup, "DEPTHWIZARD_VEGETATION_MAX_HEIGHT_M", config.maxHeightMetres, 1.0, 150.0, config.warnings);
     parseNumber(lookup, "DEPTHWIZARD_VEGETATION_MAX_INSTANCES", config.maxInstances, 0.0, 100000.0, config.warnings);
     parseNumber(lookup, "DEPTHWIZARD_VEGETATION_SEED", config.seed, 0.0, 4294967295.0, config.warnings);
     // Recovery must stay conservative: below 0.5 UNKNOWN pixels are not
     // even majority vegetation.
     parseNumber(lookup, "DEPTHWIZARD_VEGETATION_UNKNOWN_PROBABILITY", config.unknownProbability, 0.5, 1.0,
                 config.warnings);
     parseNumber(lookup, "DEPTHWIZARD_VEGETATION_DENSE_MIN_AREA_M2", config.denseMinAreaSquareMetres, 10.0, 1.0e6,
                 config.warnings);
     parseNumber(lookup, "DEPTHWIZARD_VEGETATION_DENSE_LOCAL_COVERAGE", config.denseLocalCoverage, 0.1, 1.0,
                 config.warnings);
     parseNumber(lookup, "DEPTHWIZARD_VEGETATION_INDIVIDUAL_TREE_MAX_GSD_M", config.individualTreeMaxGsdMetres, 0.05,
                 10.0, config.warnings);
     parseNumber(lookup, "DEPTHWIZARD_VEGETATION_CANOPY_MAX_TRIANGLES", config.canopyMaxTriangles, 100.0, 5.0e6,
                 config.warnings);
     parseNumber(lookup, "DEPTHWIZARD_VEGETATION_CANOPY_SMOOTH_RADIUS_M", config.canopySmoothRadiusMetres, 0.0, 20.0,
                 config.warnings);
     parseNumber(lookup, "DEPTHWIZARD_VEGETATION_CANOPY_EDGE_SLOPE", config.canopyEdgeSlope, 0.2, 10.0,
                 config.warnings);
     parseNumber(lookup, "DEPTHWIZARD_VEGETATION_TREE_MIN_CROWN_RADIUS_M", config.treeMinCrownRadiusMetres, 0.25, 10.0,
                 config.warnings);
     parseNumber(lookup, "DEPTHWIZARD_VEGETATION_TREE_MAX_CROWN_RADIUS_M", config.treeMaxCrownRadiusMetres, 0.5, 30.0,
                 config.warnings);
     parseSwitch(lookup, "DEPTHWIZARD_VEGETATION_TREE_RECOVER_LOW_CONFIDENCE", config.treeRecoverLowConfidence,
                 config.warnings);
     parseNumber(lookup, "DEPTHWIZARD_VEGETATION_TREE_RECOVERY_MIN_PROBABILITY", config.treeRecoveryMinProbability,
                 0.05, 0.95, config.warnings);
     parseNumber(lookup, "DEPTHWIZARD_VEGETATION_TREE_RECOVERY_MIN_CONFIDENCE", config.treeRecoveryMinConfidence,
                 0.0, 1.0, config.warnings);
     parseNumber(lookup, "DEPTHWIZARD_VEGETATION_TREE_CHUNK_SIZE_M", config.treeChunkSizeMetres, 0.0, 5000.0,
                 config.warnings);
     parseSwitch(lookup, "DEPTHWIZARD_VEGETATION_TREE_LOD", config.treeLod, config.warnings);
     if (const auto assets = lookup("DEPTHWIZARD_VEGETATION_ASSET_MODE"); assets && !assets->empty())
     {
          const std::string text = lower(*assets);
          if (text == "external") config.assetMode = VegetationAssetMode::EXTERNAL;
          else if (text != "procedural")
               config.warnings.push_back("DEPTHWIZARD_VEGETATION_ASSET_MODE='" + *assets +
                                         "' is not procedural or external; using procedural.");
     }
     parseSwitch(lookup, "DEPTHWIZARD_VEGETATION_FOREST_PROXIES", config.forestProxies, config.warnings);
     if (config.treeMaxCrownRadiusMetres <= config.treeMinCrownRadiusMetres)
     {
          config.warnings.push_back("DEPTHWIZARD_VEGETATION_TREE_MAX_CROWN_RADIUS_M must exceed the minimum; using defaults 1 and 7.");
          config.treeMinCrownRadiusMetres = VegetationConfig{}.treeMinCrownRadiusMetres;
          config.treeMaxCrownRadiusMetres = VegetationConfig{}.treeMaxCrownRadiusMetres;
     }
     if (config.maxHeightMetres <= config.minHeightMetres)
     {
          config.warnings.push_back("DEPTHWIZARD_VEGETATION_MAX_HEIGHT_M must exceed the minimum; using defaults 1.5 and 45.");
          config.minHeightMetres = VegetationConfig{}.minHeightMetres;
          config.maxHeightMetres = VegetationConfig{}.maxHeightMetres;
     }
     return config;
}

std::string VegetationConfig::summary() const
{
     std::ostringstream text;
     text << "vegetation=" << toString(mode) << " canopy=" << canopy << " trees=" << trees
          << " min_height_m=" << minHeightMetres << " max_height_m=" << maxHeightMetres
          << " max_instances=" << maxInstances << " seed=" << seed
          << " recover_unknown=" << recoverUnknown << " unknown_probability=" << unknownProbability
          << " dense_min_area_m2=" << denseMinAreaSquareMetres << " dense_local_coverage=" << denseLocalCoverage
          << " individual_tree_max_gsd_m=" << individualTreeMaxGsdMetres
          << " canopy_max_triangles=" << canopyMaxTriangles << " canopy_smooth_radius_m=" << canopySmoothRadiusMetres
          << " canopy_edge_slope=" << canopyEdgeSlope
          << " tree_crown_radius_m=" << treeMinCrownRadiusMetres << ".." << treeMaxCrownRadiusMetres
          << " tree_recover_low_confidence=" << treeRecoverLowConfidence
          << " tree_chunk_size_m=" << treeChunkSizeMetres << " tree_lod=" << treeLod
          << " asset_mode=" << toString(assetMode) << " forest_proxies=" << forestProxies
          << " diagnostics=" << diagnostics;
     return text.str();
}
