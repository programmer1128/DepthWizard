#pragma once
#include "../structures/MeshStructs.h"

#include <array>
#include <filesystem>
#include <map>
#include <optional>
#include <string>
#include <vector>

// Which prototype draws a vegetation proxy (stage 5A). PROCEDURAL is the
// stage-5 low-poly set; SMALL_BUSH and FOREST_PATCH are the bundled CC-BY
// assets (assets/vegetation/ATTRIBUTION.md). No species is inferred.
enum class VegetationAssetSource
{
     PROCEDURAL,
     SMALL_BUSH,
     FOREST_PATCH,
     FOREST_TREE     // Individual trees from the forest library (fine-resolution dense forest)
};
inline const char* toString(VegetationAssetSource source)
{
     switch (source)
     {
     case VegetationAssetSource::SMALL_BUSH: return "SMALL_BUSH";
     case VegetationAssetSource::FOREST_PATCH: return "FOREST_PATCH";
     case VegetationAssetSource::FOREST_TREE: return "FOREST_TREE";
     case VegetationAssetSource::PROCEDURAL: break;
     }
     return "PROCEDURAL";
}

// One textured primitive of an imported prototype, in the normalised
// prototype frame (Y-up, base Y = 0).
struct ExternalVegetationPart
{
     std::string materialName;
     std::vector<float> positions;   // xyz
     std::vector<float> normals;     // xyz
     std::vector<float> uvs;         // uv (TEXCOORD_0)
     std::vector<uint32_t> indices;
     std::vector<double> baseColorFactor{1.0, 1.0, 1.0, 1.0};
     std::string alphaMode{"OPAQUE"};
     double alphaCutoff{0.5};
     bool doubleSided{true};
     double roughness{0.9};
     int image{-1};                  // Index into ExternalVegetationAsset::images
};

struct ExternalVegetationAsset
{
     VegetationAssetSource source{VegetationAssetSource::SMALL_BUSH};
     std::filesystem::path path;
     std::vector<ExternalVegetationPart> parts;
     std::vector<TextureAsset> images;     // Raw PNG/JPEG bytes (base colour, sRGB)
     std::array<float, 3> boundsMin{}, boundsMax{};
     float horizontalRadius{0.0f};         // Largest distance from the vertical axis
     std::map<std::string, std::string> credits;   // title, author, source, license
     std::size_t triangles() const;
};

// Several prototypes sharing one texture set (forest_trees.glb: one node
// per tree). Each prototype's parts index into `images`.
struct ExternalVegetationLibrary
{
     std::filesystem::path path;
     std::vector<TextureAsset> images;
     std::vector<ExternalVegetationAsset> prototypes;
     std::map<std::string, std::string> credits;
};

// Loads and validates one optimized asset (preprocess_vegetation_assets.py
// output): glTF 2.0, triangle primitives with POSITION, NORMAL, TEXCOORD_0
// and indices, base-colour textures that resolve to embedded PNG/JPEG,
// finite bounds, base Y = 0 and top Y = 1 (and, for SMALL_BUSH, horizontal
// radius 1). nullopt with a reason on any failure.
class ExternalVegetationAssetLoader
{
public:
     static std::optional<ExternalVegetationAsset> load(const std::filesystem::path& path,
                                                        VegetationAssetSource expected, std::string* error);
     static std::optional<ExternalVegetationLibrary> loadLibrary(const std::filesystem::path& path,
                                                                 VegetationAssetSource expected, std::string* error);
};

// The bundled assets, loaded once per process. Directory:
// <executable dir>/assets/vegetation/optimized when present (the build copies
// it there), otherwise the source tree's assets/vegetation/optimized.
class VegetationAssetPrototypeProvider
{
public:
     explicit VegetationAssetPrototypeProvider(const std::filesystem::path& directory);
     static const VegetationAssetPrototypeProvider& instance();
     static std::filesystem::path defaultDirectory();

     const ExternalVegetationAsset* bush() const { return bush_ ? &*bush_ : nullptr; }
     const ExternalVegetationAsset* forest() const { return forest_ ? &*forest_ : nullptr; }
     const ExternalVegetationLibrary* forestTrees() const { return forestTrees_ ? &*forestTrees_ : nullptr; }
     // Empty when both assets loaded; otherwise one line per failure.
     const std::string& error() const { return error_; }
     const std::filesystem::path& directory() const { return directory_; }

private:
     std::filesystem::path directory_;
     std::optional<ExternalVegetationAsset> bush_, forest_;
     std::optional<ExternalVegetationLibrary> forestTrees_;
     std::string error_;
};
