#pragma once
#include "CommonTypes.h"
#include <optional>
#include <vector>
#include <cstdint>

enum class PrimitiveTopology 
{ 
     TRIANGLES, 
     LINES, 
     POINTS 
}; // Topology Enum

enum class MaterialRole 
{ 
     TERRAIN_TEXTURE, 
     BUILDING_ROOF, 
     BUILDING_WALL, 
     BUILDING_EDGE,
     ANALYSIS_OVERLAY,
     VEGETATION_CANOPY   // Appended overlay node (vegetation stage 3)
};// Typed materials

enum class TextureSemantic
{
    NONE,
    OPTICAL_ORIGINAL,
    OPTICAL_GROUND_REPAIRED,
    FACADE_ATLAS,
    AO_ATLAS
};

enum class TextureWrap
{
    CLAMP_TO_EDGE, // Geographic images: finite, never tiled
    REPEAT         // Facade atlas along a wall (horizontal bands only)
};

// One glTF material per role. Every primitive role in the scene must have
// exactly one descriptor; the packager rejects unbound or invalid bindings.
struct MaterialDescriptor
{
    std::string name;
    MaterialRole role{MaterialRole::TERRAIN_TEXTURE};
    TextureSemantic textureSemantic{TextureSemantic::NONE};
    int textureIndex{-1}; // Index into SceneMesh::textures, -1 if untextured
    std::vector<double> baseColorFactor{1.0, 1.0, 1.0, 1.0};
    double metallicFactor{0.0};
    double roughnessFactor{0.9};
    bool doubleSided{false};
    bool unlit{false};
    std::string alphaMode{"OPAQUE"};
    double alphaCutoff{0.5};   // MASK only; written for instanced vegetation materials
};

struct TextureAsset 
{
    std::vector<uint8_t> bytes;
    std::string mimeType; // Preserves image/jpeg or image/png
    TextureSemantic semantic{TextureSemantic::NONE};
    TextureWrap wrapS{TextureWrap::CLAMP_TO_EDGE};
    TextureWrap wrapT{TextureWrap::CLAMP_TO_EDGE};
};

struct MeshPrimitive 
{
    PrimitiveTopology topology{PrimitiveTopology::TRIANGLES}; // Strongly typed
    std::vector<float> positions;
    std::optional<std::vector<float>> normals; // Optional
    std::optional<std::vector<float>> uvs;     // Optional for untextured walls
    std::vector<uint32_t> indices;
    // glTF 2.0 forbids UNSIGNED_INT for vertex attributes. Float retains
    // exact integer identity for IDs up to 16,777,216 and is WebGL-safe.
    std::optional<std::vector<float>> featureIds; // Bound per-vertex
    std::optional<std::vector<float>> colors;     // RGBA per vertex (stride of 4 floats: [R, G, B, A])
    MaterialRole materialRole{MaterialRole::TERRAIN_TEXTURE};
    AxisAlignedBounds localBounds; // Strongly typed bounds
    
     // Safety validation rules
     bool isValid() const 
     {
         if (positions.size() % 3 != 0) 
         {
             return false;
         }
         if (normals.has_value() && normals->size() != positions.size()) 
         {
             return false;
         }
         if (uvs.has_value() && uvs->size() != (positions.size() / 3) * 2) 
         {
             return false;
         }
         if (featureIds.has_value() && featureIds->size() != positions.size() / 3) 
         {
             return false;
         }
         if (colors.has_value() && colors->size() != (positions.size() / 3) * 4)
         {
             return false;
         }
         if (topology == PrimitiveTopology::TRIANGLES && indices.size() % 3 != 0) 
         {
             return false;
         }
         if (topology == PrimitiveTopology::LINES && indices.size() % 2 != 0)
         {
             return false;
         }
         return true;
    }
};

struct TerrainMesh 
{
    MeshPrimitive terrainPrimitive;
};

struct BuildingMesh 
{
    MeshPrimitive roofPrimitive;
    MeshPrimitive wallPrimitive;
    MeshPrimitive edgePrimitive; // Mode: LINES
    std::vector<uint32_t> emittedBuildingIds;
    std::vector<uint32_t> rejectedBuildingIds;
    // Roof vertices whose inverse-affine image position lies outside the
    // raster by more than rounding error. Their UVs are left unclamped.
    std::size_t roofUvOutOfBoundsVertexCount{0};
};

struct SceneMesh 
{
    std::string presentationMode{"metric"};
    LocalSceneFrame localFrame;
    MeshPrimitive terrainPrimitive;
    MeshPrimitive roofPrimitive;
    MeshPrimitive wallPrimitive;
    MeshPrimitive edgePrimitive; // Wireframe edge lines (Mode: LINES)
    std::optional<MeshPrimitive> overlayPrimitive;
    std::vector<MaterialRole> materials;
    std::optional<TextureAsset> texture; // Legacy single texture, used when textures is empty
    std::vector<TextureAsset> textures;  // Multi-texture table
    std::vector<MaterialDescriptor> materialDescriptors; // PBR material table
    std::string presentationStyle{"scientific"}; // depthwizard::toString(PresentationStyle)
    bool syntheticFacades{false}; // Walls carry the procedural facade atlas
    AxisAlignedBounds sceneBounds;
};
