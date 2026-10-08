#pragma once
#include "../structures/MeshStructs.h"
#include "../structures/ExportStructs.h"
#include "../CompressionLib/DracoCompressor.h"
#include <map>
#include <string>
#include <variant>
#include <vector>

// A separately named node appended after the base scene (vegetation
// overlays). The base node, mesh, materials, textures, accessors and buffer
// bytes are written exactly as without it.
struct AppendedMeshNode
{
     using Extra = std::variant<bool, double, std::string>;
     std::string name;
     CompressedPrimitive primitive;
     MaterialDescriptor material;           // textureIndex refers to SceneMesh::textures
     std::map<std::string, Extra> extras;   // Written to the node and to its material
};

// Instanced nodes (EXT_mesh_gpu_instancing) appended after every other node:
// shared prototype geometries, meshes that bind a geometry to materials, and
// one node per batch carrying TRANSLATION / ROTATION / SCALE accessors.
struct InstancedGeometry
{
     std::vector<float> positions;   // xyz
     std::vector<float> normals;     // xyz
     std::vector<uint32_t> indices;
     std::vector<float> uvs;         // Optional uv (TEXCOORD_0) for textured prototypes
};

struct InstancedMeshDef
{
     std::string name;
     std::vector<std::pair<int, int>> primitives;   // (geometry index, material index)
};

struct InstancedNodeDef
{
     std::string name;
     int mesh{-1};
     std::vector<float> translations;   // xyz per instance
     std::vector<float> rotations;      // xyzw unit quaternion per instance
     std::vector<float> scales;         // xyz per instance
     std::vector<float> colors;         // Optional rgb per instance (_COLOR_0 tint)
     // Index of an earlier node whose instance accessors this node reuses
     // (levels of detail of one batch); its own arrays are then left empty.
     int instancesFrom{-1};
     std::map<std::string, AppendedMeshNode::Extra> extras;
};

struct InstancedPackage
{
     std::vector<InstancedGeometry> geometries;
     // MaterialDescriptor::textureIndex here refers to InstancedPackage::textures.
     std::vector<std::pair<MaterialDescriptor, std::map<std::string, AppendedMeshNode::Extra>>> materials;
     std::vector<TextureAsset> textures;   // Written after every existing image, texture and sampler
     std::vector<InstancedMeshDef> meshes;
     std::vector<InstancedNodeDef> nodes;
     bool empty() const { return nodes.empty(); }
};

class GltfPackager 
{
     public:
     static GlbBuildResult buildSceneToMemory(
         const SceneMesh& scene,
         const std::vector<CompressedPrimitive>& compressedPrimitives,
         size_t totalBuildingCount,
         const std::vector<AppendedMeshNode>& appendedNodes = {},
         const InstancedPackage* instanced = nullptr);
};