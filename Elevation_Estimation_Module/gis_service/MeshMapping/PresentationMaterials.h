#pragma once

#include "../structures/MeshStructs.h"

#include <optional>
#include <string>
#include <vector>

// Material tables for the three presentation styles (playbook section 6.5)
// and the binding rules every GLB must satisfy (section 6.1). Header-only so
// the packager and SceneMeshService share one definition.
namespace depthwizard::presentation
{

// Stable name written to a textured material's extras.textureSemantic, so a
// GLB states which image each material samples.
inline const char* textureSemanticName(TextureSemantic semantic)
{
    switch (semantic)
    {
    case TextureSemantic::OPTICAL_ORIGINAL: return "OPTICAL_ORIGINAL";
    case TextureSemantic::OPTICAL_GROUND_REPAIRED: return "OPTICAL_GROUND_REPAIRED";
    case TextureSemantic::FACADE_ATLAS: return "FACADE_ATLAS";
    case TextureSemantic::AO_ATLAS: return "AO_ATLAS";
    case TextureSemantic::NONE: break;
    }
    return "NONE";
}

inline MaterialDescriptor material(std::string name, MaterialRole role,
                                   std::vector<double> baseColor, double metallic, double roughness,
                                   bool doubleSided, bool unlit = false)
{
    MaterialDescriptor descriptor;
    descriptor.name = std::move(name);
    descriptor.role = role;
    descriptor.baseColorFactor = std::move(baseColor);
    descriptor.metallicFactor = metallic;
    descriptor.roughnessFactor = roughness;
    descriptor.doubleSided = doubleSided;
    descriptor.unlit = unlit;
    return descriptor;
}

inline MaterialDescriptor textured(MaterialDescriptor descriptor, int textureIndex, TextureSemantic semantic)
{
    descriptor.textureIndex = textureIndex;
    descriptor.textureSemantic = semantic;
    return descriptor;
}

// SCIENTIFIC: exactly the materials the packager has always written. Colour
// comes from the height-tier COLOR_0 vertex colours.
inline std::vector<MaterialDescriptor> scientificMaterials()
{
    return {
        material("Terrain_Grey", MaterialRole::TERRAIN_TEXTURE, {0.26, 0.26, 0.26, 1.0}, 0.0, 0.9, false, true),
        material("Building_Roof", MaterialRole::BUILDING_ROOF, {1.0, 1.0, 1.0, 1.0}, 0.10, 0.40, true),
        material("Building_Wall", MaterialRole::BUILDING_WALL, {1.0, 1.0, 1.0, 1.0}, 0.10, 0.40, true),
        // 0.1f, not 0.1: the legacy value, kept so scientific GLBs stay byte-identical.
        material("Building_Edge_Highlight", MaterialRole::BUILDING_EDGE, {1.0, 1.0, 1.0, 1.0}, 0.0,
                 static_cast<double>(0.1f), false),
    };
}

// TERRA_MASSING: ivory roofs, slightly darker neutral walls, no vertex colours
// and no synthetic facade. Terrain shows the repaired optical image when one
// is available, otherwise a muted grey.
inline std::vector<MaterialDescriptor> terraMaterials(std::optional<int> repairedGroundTexture)
{
    MaterialDescriptor terrain = repairedGroundTexture
        ? textured(material("Terrain_Repaired_Optical", MaterialRole::TERRAIN_TEXTURE, {1.0, 1.0, 1.0, 1.0},
                            0.0, 0.9, false),
                   *repairedGroundTexture, TextureSemantic::OPTICAL_GROUND_REPAIRED)
        : material("Terrain_Muted", MaterialRole::TERRAIN_TEXTURE, {0.40, 0.40, 0.40, 1.0}, 0.0, 1.0, false);
    return {
        terrain,
        material("Building_Roof_Terra", MaterialRole::BUILDING_ROOF, {0.95, 0.94, 0.90, 1.0}, 0.0, 0.80, true),
        material("Building_Wall_Terra", MaterialRole::BUILDING_WALL, {0.70, 0.69, 0.67, 1.0}, 0.0, 0.85, true),
    };
}

// ORTHOPHOTO_REALISTIC: original optical image on roofs, repaired image on
// terrain, procedural facade atlas on walls.
inline std::vector<MaterialDescriptor> orthophotoMaterials(int repairedGroundTexture, int opticalTexture,
                                                           int facadeTexture)
{
    return {
        textured(material("Terrain_Repaired_Optical", MaterialRole::TERRAIN_TEXTURE, {1.0, 1.0, 1.0, 1.0},
                          0.0, 0.9, false),
                 repairedGroundTexture, TextureSemantic::OPTICAL_GROUND_REPAIRED),
        textured(material("Building_Roof_Optical", MaterialRole::BUILDING_ROOF, {1.0, 1.0, 1.0, 1.0},
                          0.0, 0.80, true),
                 opticalTexture, TextureSemantic::OPTICAL_ORIGINAL),
        textured(material("Building_Wall_Facade", MaterialRole::BUILDING_WALL, {1.0, 1.0, 1.0, 1.0},
                          0.0, 0.85, true),
                 facadeTexture, TextureSemantic::FACADE_ATLAS),
    };
}

// Empty when the scene's materials, textures and primitives are consistent;
// otherwise the first violation.
inline std::string bindingProblem(const SceneMesh& scene)
{
    struct Use
    {
        MaterialRole role;
        const MeshPrimitive* primitive;
        const char* name;
    };
    std::vector<Use> uses{{MaterialRole::TERRAIN_TEXTURE, &scene.terrainPrimitive, "terrain"}};
    if (!scene.roofPrimitive.indices.empty()) uses.push_back({MaterialRole::BUILDING_ROOF, &scene.roofPrimitive, "roof"});
    if (!scene.wallPrimitive.indices.empty()) uses.push_back({MaterialRole::BUILDING_WALL, &scene.wallPrimitive, "wall"});

    for (const Use& use : uses)
    {
        const MaterialDescriptor* bound = nullptr;
        for (const MaterialDescriptor& descriptor : scene.materialDescriptors)
        {
            if (descriptor.role != use.role) continue;
            if (bound != nullptr) return std::string("more than one ") + use.name + " material";
            bound = &descriptor;
        }
        if (bound == nullptr) return std::string("no ") + use.name + " material";
        if (bound->textureIndex < 0)
        {
            if (bound->textureSemantic != TextureSemantic::NONE)
                return std::string(use.name) + " material names a texture semantic but no texture";
            continue;
        }
        if (bound->textureIndex >= static_cast<int>(scene.textures.size()))
            return std::string(use.name) + " material references a missing texture";
        const TextureSemantic semantic = scene.textures[bound->textureIndex].semantic;
        if (semantic != bound->textureSemantic)
            return std::string(use.name) + " material texture semantic does not match its texture";
        if (!use.primitive->uvs.has_value())
            return std::string(use.name) + " material is textured but the primitive has no TEXCOORD_0";
        if (use.role == MaterialRole::TERRAIN_TEXTURE && semantic == TextureSemantic::OPTICAL_ORIGINAL)
            return "terrain must not use the original roof-containing optical image";
        if (use.role == MaterialRole::BUILDING_ROOF && semantic == TextureSemantic::OPTICAL_GROUND_REPAIRED)
            return "roofs must not use the repaired ground image";
        if (use.role == MaterialRole::BUILDING_WALL && semantic != TextureSemantic::FACADE_ATLAS)
            return "walls may only use the facade atlas";
    }
    return {};
}

} // namespace depthwizard::presentation
