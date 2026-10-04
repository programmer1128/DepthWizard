#include "VegetationTreePackaging.h"
#include "../MeshMapping/PresentationMaterials.h"

#include <cmath>
#include <map>

namespace
{
// Near-white multipliers over the crown colour (also touch the trunk, but
// stay close enough to white to leave it brown).
constexpr std::array<std::array<float, 3>, 4> kTints{{
    {1.00F, 1.00F, 1.00F}, {0.86F, 0.95F, 0.82F}, {0.96F, 0.89F, 0.80F}, {0.84F, 0.91F, 0.88F}}};

// Centimetre precision keeps node extras short (doubles otherwise print with
// 17 significant digits).
double centimetres(double metres) { return std::round(metres * 100.0) / 100.0; }

std::map<std::string, AppendedMeshNode::Extra> provenanceExtras()
{
     return {
         {"geometrySemantic", std::string("VEGETATION_TREE_INSTANCES")},
         {"visualizationProxy", true},
         {"scientificSurface", false},
         {"speciesInferred", false},
         {"positionSource", std::string("SEMANTIC_VEGETATION")},
         {"heightSource", std::string("NDSM")},
         {"externalGeographicDataUsed", false},
     };
}
} // namespace

std::array<double, 3> VegetationTreePackaging::crownColour(const std::string& family, TreeVisualVariant variant)
{
     // Linear albedo. The viewer lights a sunlit top at roughly 3.2x albedo
     // (ambient 1.6 + sun 2.0, ACES), so these sit near the lit orthophoto
     // crown colour of the test scenes instead of saturating to pastel. The
     // arid family is a muted olive / brown-green at desert brightness.
     static const std::array<std::array<double, 3>, kTreeVariantCount> temperate{{
         {0.064, 0.106, 0.038},   // Broadleaf round
         {0.070, 0.109, 0.042},   // Broadleaf irregular
         {0.045, 0.086, 0.038},   // Tall / narrow
         {0.115, 0.122, 0.064},   // Dry / sparse
         {0.096, 0.115, 0.054},   // Shrub
         {0.051, 0.090, 0.032},   // Canopy crown
     }};
     static const std::array<std::array<double, 3>, kTreeVariantCount> arid{{
         {0.149, 0.162, 0.086},
         {0.140, 0.149, 0.081},
         {0.122, 0.144, 0.077},
         {0.189, 0.180, 0.113},
         {0.167, 0.171, 0.099},
         {0.126, 0.149, 0.077},
     }};
     return (family == "arid" ? arid : temperate)[static_cast<std::size_t>(variant)];
}

InstancedPackage VegetationTreePackaging::package(const VegetationTreeInstances& trees,
                                                  const TreePrototypeProvider& provider, uint32_t seed)
{
     InstancedPackage package;
     if (trees.batches.empty()) return package;

     // Materials: one trunk, then one crown material per variant as used.
     {
          auto extras = provenanceExtras();
          extras["vegetationPart"] = std::string("TRUNK");
          package.materials.emplace_back(depthwizard::presentation::material(
              "Vegetation_Tree_Trunk", MaterialRole::VEGETATION_CANOPY, {0.11, 0.08, 0.055, 1.0}, 0.0, 0.95, false), extras);
     }
     std::map<int, int> crownMaterial;                     // variant
     std::map<std::pair<int, int>, std::pair<int, int>> geometry; // (variant, lod) -> (trunk, crown)
     std::map<std::pair<int, int>, int> mesh;              // (variant, lod)
     std::map<std::string, int> batchNode;                 // batchKey -> node holding its instance data
     for (const TreeBatch& batch : trees.batches)
     {
          const int variant = static_cast<int>(batch.variant), lod = static_cast<int>(batch.lod);
          if (!crownMaterial.count(variant))
          {
               const auto colour = crownColour(trees.paletteFamily, batch.variant);
               auto extras = provenanceExtras();
               extras["vegetationPart"] = std::string("CROWN");
               extras["visualVariant"] = std::string(toString(batch.variant));
               extras["paletteFamily"] = trees.paletteFamily;
               package.materials.emplace_back(depthwizard::presentation::material(
                   std::string("Vegetation_Tree_Crown_") + toString(batch.variant),
                   MaterialRole::VEGETATION_CANOPY, {colour[0], colour[1], colour[2], 1.0}, 0.0, 0.9, false), extras);
               crownMaterial[variant] = static_cast<int>(package.materials.size() - 1);
          }
          if (!geometry.count({variant, lod}))
          {
               const TreePrototype& prototype = provider.prototype(batch.variant, batch.lod);
               int trunk = -1;
               if (prototype.trunk.triangles() > 0)
               {
                    package.geometries.push_back({prototype.trunk.positions, prototype.trunk.normals, prototype.trunk.indices});
                    trunk = static_cast<int>(package.geometries.size() - 1);
               }
               package.geometries.push_back({prototype.crown.positions, prototype.crown.normals, prototype.crown.indices});
               geometry[{variant, lod}] = {trunk, static_cast<int>(package.geometries.size() - 1)};
          }
          if (!mesh.count({variant, lod}))
          {
               const auto [trunk, crown] = geometry.at({variant, lod});
               InstancedMeshDef def;
               def.name = std::string("VEGETATION_TREE_") + toString(batch.variant) + "_" + toString(batch.lod);
               if (trunk >= 0) def.primitives.emplace_back(trunk, 0);
               def.primitives.emplace_back(crown, crownMaterial.at(variant));
               package.meshes.push_back(std::move(def));
               mesh[{variant, lod}] = static_cast<int>(package.meshes.size() - 1);
          }

          InstancedNodeDef node;
          node.name = batch.name;
          node.mesh = mesh.at({variant, lod});
          // The levels of detail of one batch share its instance accessors.
          const auto shared = batchNode.find(batch.batchKey);
          if (shared != batchNode.end()) node.instancesFrom = shared->second;
          else batchNode[batch.batchKey] = static_cast<int>(package.nodes.size());
          for (std::size_t k : node.instancesFrom >= 0 ? std::vector<std::size_t>{} : batch.instances)
          {
               const TreeInstance& instance = trees.instances[k];
               node.translations.insert(node.translations.end(), instance.translation.begin(), instance.translation.end());
               node.rotations.insert(node.rotations.end(), instance.rotation.begin(), instance.rotation.end());
               node.scales.insert(node.scales.end(), instance.scale.begin(), instance.scale.end());
               const auto& tint = kTints[static_cast<std::size_t>(instance.colourTint) % kTints.size()];
               node.colors.insert(node.colors.end(), tint.begin(), tint.end());
          }
          const TreeInstance& first = trees.instances[batch.instances.front()];
          node.extras = provenanceExtras();
          node.extras["vegetationLod"] = std::string(toString(batch.lod));
          node.extras["vegetationBatch"] = batch.batchKey;
          node.extras["treeCategory"] = std::string(toString(first.category));
          node.extras["visualVariant"] = std::string(toString(batch.variant));
          node.extras["paletteFamily"] = trees.paletteFamily;
          node.extras["chunkIndex"] = static_cast<double>(batch.chunkIndex);
          node.extras["chunkX"] = static_cast<double>(batch.chunkX);
          node.extras["chunkZ"] = static_cast<double>(batch.chunkZ);
          node.extras["chunkSizeMetres"] = centimetres(trees.chunkSizeMetres);
          node.extras["instanceCount"] = static_cast<double>(batch.instances.size());
          node.extras["typicalDisplayHeight"] = centimetres(batch.typicalHeight);
          node.extras["typicalCrownRadius"] = centimetres(batch.typicalRadius);
          node.extras["boundsMinX"] = centimetres(batch.boundsMin[0]);
          node.extras["boundsMinY"] = centimetres(batch.boundsMin[1]);
          node.extras["boundsMinZ"] = centimetres(batch.boundsMin[2]);
          node.extras["boundsMaxX"] = centimetres(batch.boundsMax[0]);
          node.extras["boundsMaxY"] = centimetres(batch.boundsMax[1]);
          node.extras["boundsMaxZ"] = centimetres(batch.boundsMax[2]);
          node.extras["prototypeTriangles"] =
              static_cast<double>(provider.prototype(batch.variant, batch.lod).triangles());
          node.extras["deterministicSeed"] = static_cast<double>(seed);
          package.nodes.push_back(std::move(node));
     }
     return package;
}
