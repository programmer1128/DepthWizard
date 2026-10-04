#include "VegetationExternalPackaging.h"
#include "../MeshMapping/PresentationMaterials.h"

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <map>

namespace
{
using Extras = std::map<std::string, AppendedMeshNode::Extra>;

double centimetres(double metres) { return std::round(metres * 100.0) / 100.0; }

float median(std::vector<float> values)
{
     if (values.empty()) return 0.0f;
     std::nth_element(values.begin(), values.begin() + static_cast<std::ptrdiff_t>(values.size() / 2), values.end());
     return values[values.size() / 2];
}

std::string credit(const ExternalVegetationAsset& asset)
{
     const auto get = [&](const char* key) { const auto it = asset.credits.find(key); return it == asset.credits.end() ? std::string() : it->second; };
     return "\"" + get("title") + "\" by " + get("author") + ", " + get("license") + ", " + get("source");
}

Extras bushProvenance()
{
     return {{"geometrySemantic", std::string("VEGETATION_TREE_INSTANCES")}, {"visualizationProxy", true},
             {"scientificSurface", false}, {"speciesInferred", false},
             {"positionSource", std::string("SEMANTIC_VEGETATION")}, {"heightSource", std::string("NDSM")},
             {"externalGeographicDataUsed", false}, {"assetSource", std::string("SMALL_BUSH")}};
}

Extras forestProvenance()
{
     return {{"geometrySemantic", std::string("VEGETATION_FOREST_PROXY")}, {"visualizationProxy", true},
             {"scientificSurface", false}, {"speciesInferred", false}, {"individualTreesResolved", false},
             {"positionSource", std::string("DENSE_CANOPY_MASK")}, {"heightSource", std::string("NDSM_ENVELOPE")},
             {"externalGeographicDataUsed", false}, {"assetSource", std::string("FOREST_PATCH")}};
}

// Appends an asset's textures, materials and geometry; returns its mesh index.
int appendAsset(InstancedPackage& package, const ExternalVegetationAsset& asset, const Extras& provenance,
                const std::string& meshName)
{
     const int firstTexture = static_cast<int>(package.textures.size());
     for (const TextureAsset& image : asset.images) package.textures.push_back(image);
     InstancedMeshDef mesh;
     mesh.name = meshName;
     for (const ExternalVegetationPart& part : asset.parts)
     {
          MaterialDescriptor material = depthwizard::presentation::material(
              "Vegetation_" + std::string(toString(asset.source)) + "_" + part.materialName, MaterialRole::VEGETATION_CANOPY,
              {part.baseColorFactor[0], part.baseColorFactor[1], part.baseColorFactor[2], part.baseColorFactor[3]}, 0.0,
              std::max(0.9, part.roughness), part.doubleSided);
          material.alphaMode = part.alphaMode;
          material.alphaCutoff = part.alphaCutoff;
          material.textureIndex = firstTexture + part.image;
          Extras extras = provenance;
          extras["assetCredit"] = credit(asset);
          package.materials.emplace_back(material, extras);
          package.geometries.push_back({part.positions, part.normals, part.indices, part.uvs});
          mesh.primitives.emplace_back(static_cast<int>(package.geometries.size() - 1),
                                       static_cast<int>(package.materials.size() - 1));
     }
     package.meshes.push_back(std::move(mesh));
     return static_cast<int>(package.meshes.size() - 1);
}

void boundsExtras(Extras& extras, const std::array<double, 3>& lo, const std::array<double, 3>& hi)
{
     extras["boundsMinX"] = centimetres(lo[0]); extras["boundsMinY"] = centimetres(lo[1]); extras["boundsMinZ"] = centimetres(lo[2]);
     extras["boundsMaxX"] = centimetres(hi[0]); extras["boundsMaxY"] = centimetres(hi[1]); extras["boundsMaxZ"] = centimetres(hi[2]);
}
} // namespace

void VegetationExternalPackaging::selectAssets(VegetationTreeInstances& trees, bool forestScene, bool gardenScene)
{
     for (TreeInstance& instance : trees.instances)
     {
          instance.assetSource = VegetationAssetSource::SMALL_BUSH;
          instance.rendered = !gardenScene && !(forestScene && instance.category == TreeCandidateCategory::DENSE_CANOPY_CROWN);
     }
     // One bush batch per (chunk, category), NEAR only.
     std::map<std::pair<uint32_t, int>, std::vector<std::size_t>> groups;
     for (std::size_t k = 0; k < trees.instances.size(); ++k)
          if (trees.instances[k].rendered)
               groups[{trees.instances[k].chunkIndex, static_cast<int>(trees.instances[k].category)}].push_back(k);
     trees.batches.clear();
     for (const auto& [key, members] : groups)
     {
          TreeBatch batch;
          batch.assetSource = VegetationAssetSource::SMALL_BUSH;
          batch.lod = TreeLod::NEAR;
          batch.chunkIndex = key.first;
          batch.category = static_cast<TreeCandidateCategory>(key.second);
          batch.variant = trees.instances[members.front()].variant;
          batch.chunkX = trees.instances[members.front()].chunkX;
          batch.chunkZ = trees.instances[members.front()].chunkZ;
          batch.instances = members;
          std::vector<float> heights, radii;
          std::array<double, 3> lo{1e300, 1e300, 1e300}, hi{-1e300, -1e300, -1e300};
          for (std::size_t k : members)
          {
               const TreeInstance& i = trees.instances[k];
               heights.push_back(i.displayHeight);
               radii.push_back(i.crownRadiusMetres);
               for (int c : {0, 2})
               {
                    lo[c] = std::min(lo[c], static_cast<double>(i.translation[c] - i.scale[c]));
                    hi[c] = std::max(hi[c], static_cast<double>(i.translation[c] + i.scale[c]));
               }
               lo[1] = std::min(lo[1], static_cast<double>(i.translation[1]));
               hi[1] = std::max(hi[1], static_cast<double>(i.translation[1] + i.scale[1]));
          }
          batch.boundsMin = lo;
          batch.boundsMax = hi;
          batch.typicalHeight = median(heights);
          batch.typicalRadius = median(radii);
          char chunkName[16];
          std::snprintf(chunkName, sizeof(chunkName), "%03u", key.first);
          const bool crown = batch.category == TreeCandidateCategory::DENSE_CANOPY_CROWN;
          batch.batchKey = std::string(crown ? "SMALL_BUSH_CROWN" : "SMALL_BUSH") + "_CHUNK_" + chunkName;
          batch.name = "VEGETATION_TREES_NEAR_" + batch.batchKey;
          trees.batches.push_back(std::move(batch));
     }
}

InstancedPackage VegetationExternalPackaging::package(const VegetationTreeInstances& trees, const DenseForestProxies& forest,
                                                      const ExternalVegetationAsset& bush,
                                                      const ExternalVegetationAsset* forestAsset, uint32_t seed,
                                                      const VegetationCover* cover, float bushProminence,
                                                      const ForestTrees* forestTrees,
                                                      const ExternalVegetationLibrary* treeLibrary)
{
     InstancedPackage package;
     int bushMesh = -1;
     if (!trees.batches.empty() || (cover != nullptr && !cover->empty()))
          bushMesh = appendAsset(package, bush, bushProvenance(), "VEGETATION_SMALL_BUSH");
     if (!trees.batches.empty())
     {
          const int mesh = bushMesh;
          for (const TreeBatch& batch : trees.batches)
          {
               InstancedNodeDef node;
               node.name = batch.name;
               node.mesh = mesh;
               for (std::size_t k : batch.instances)
               {
                    const TreeInstance& i = trees.instances[k];
                    node.translations.insert(node.translations.end(), i.translation.begin(), i.translation.end());
                    node.rotations.insert(node.rotations.end(), i.rotation.begin(), i.rotation.end());
                    // Natural cover scenes draw candidates at the same visual
                    // prominence as the cover (base unchanged; diagnostics keep
                    // the measured transform).
                    for (float v : i.scale) node.scales.push_back(v * bushProminence);
               }
               node.extras = bushProvenance();
               node.extras["visualProminenceScale"] = static_cast<double>(bushProminence);
               node.extras["vegetationLod"] = std::string("NEAR");
               node.extras["vegetationBatch"] = batch.batchKey;
               node.extras["treeCategory"] = std::string(toString(batch.category));
               node.extras["chunkIndex"] = static_cast<double>(batch.chunkIndex);
               node.extras["chunkX"] = static_cast<double>(batch.chunkX);
               node.extras["chunkZ"] = static_cast<double>(batch.chunkZ);
               node.extras["chunkSizeMetres"] = centimetres(trees.chunkSizeMetres);
               node.extras["instanceCount"] = static_cast<double>(batch.instances.size());
               node.extras["typicalDisplayHeight"] = centimetres(batch.typicalHeight);
               node.extras["typicalCrownRadius"] = centimetres(batch.typicalRadius);
               std::array<double, 3> lo = batch.boundsMin, hi = batch.boundsMax;
               if (bushProminence != 1.0f)
               {
                    const double cx = 0.5 * (lo[0] + hi[0]), cz = 0.5 * (lo[2] + hi[2]);
                    for (int c : {0, 2})
                    {
                         const double centre = c == 0 ? cx : cz;
                         lo[c] = centre + (lo[c] - centre) * bushProminence;
                         hi[c] = centre + (hi[c] - centre) * bushProminence;
                    }
                    hi[1] = lo[1] + (hi[1] - lo[1]) * bushProminence;
               }
               boundsExtras(node.extras, lo, hi);
               node.extras["prototypeTriangles"] = static_cast<double>(bush.triangles());
               node.extras["deterministicSeed"] = static_cast<double>(seed);
               package.nodes.push_back(std::move(node));
          }
     }
     if (cover != nullptr && !cover->empty())
     {
          const bool garden = cover->mode == VegetationCoverMode::GARDEN;
          std::map<uint32_t, std::vector<std::size_t>> groups;
          for (std::size_t k = 0; k < cover->shrubs.size(); ++k) groups[cover->shrubs[k].chunkIndex].push_back(k);
          for (const auto& [chunk, members] : groups)
          {
               InstancedNodeDef node;
               char chunkName[16];
               std::snprintf(chunkName, sizeof(chunkName), "%03u", chunk);
               const std::string batchKey = std::string("COVER_SMALL_BUSH_CHUNK_") + chunkName;
               node.name = "VEGETATION_COVER_NEAR_SMALL_BUSH_CHUNK_" + std::string(chunkName);
               node.mesh = bushMesh;
               std::vector<float> heights, radii;
               std::array<double, 3> lo{1e300, 1e300, 1e300}, hi{-1e300, -1e300, -1e300};
               for (std::size_t k : members)
               {
                    const CoverShrub& s = cover->shrubs[k];
                    node.translations.insert(node.translations.end(), s.translation.begin(), s.translation.end());
                    node.rotations.insert(node.rotations.end(), s.rotation.begin(), s.rotation.end());
                    node.scales.insert(node.scales.end(), s.scale.begin(), s.scale.end());
                    heights.push_back(s.scale[1]);
                    radii.push_back(s.scale[0]);
                    for (int c : {0, 2})
                    {
                         lo[c] = std::min(lo[c], static_cast<double>(s.translation[c] - s.scale[0]));
                         hi[c] = std::max(hi[c], static_cast<double>(s.translation[c] + s.scale[0]));
                    }
                    lo[1] = std::min(lo[1], static_cast<double>(s.translation[1]));
                    hi[1] = std::max(hi[1], static_cast<double>(s.translation[1] + s.scale[1]));
               }
               node.extras = {{"geometrySemantic", std::string("VEGETATION_COVER_PROXY")}, {"visualizationProxy", true},
                              {"scientificSurface", false}, {"speciesInferred", false}, {"individualTreesResolved", false},
                              {"positionSource", std::string(garden ? "SEMANTIC_VEGETATION" : "IMAGE_VEGETATION_COVER")},
                              {"heightSource", std::string(garden ? "NDSM_CLAMPED_SHRUB" : "NDSM_OR_CROWN_PROPORTION")},
                              {"externalGeographicDataUsed", false},
                              {"assetSource", std::string("SMALL_BUSH")}, {"coverMode", std::string(garden ? "GARDEN" : "NATURAL")}};
               node.extras["vegetationLod"] = std::string("NEAR");
               node.extras["vegetationBatch"] = batchKey;
               node.extras["treeCategory"] = std::string("COVER_SHRUB");
               node.extras["visualProminenceScale"] = static_cast<double>(garden ? 1.0f : VegetationCoverGenerator::kNaturalProminence);
               node.extras["chunkIndex"] = static_cast<double>(chunk);
               node.extras["chunkSizeMetres"] = centimetres(cover->chunkSizeMetres);
               node.extras["instanceCount"] = static_cast<double>(members.size());
               node.extras["typicalDisplayHeight"] = centimetres(median(heights));
               node.extras["typicalCrownRadius"] = centimetres(median(radii));
               boundsExtras(node.extras, lo, hi);
               node.extras["prototypeTriangles"] = static_cast<double>(bush.triangles());
               node.extras["deterministicSeed"] = static_cast<double>(seed);
               package.nodes.push_back(std::move(node));
          }
     }
     // Dense forest (fine resolution): library trees, one shared texture set,
     // one mesh per tree, one node per (chunk, tree).
     if (forestTrees != nullptr && treeLibrary != nullptr && !forestTrees->empty())
     {
          const int firstTexture = static_cast<int>(package.textures.size());
          for (const TextureAsset& image : treeLibrary->images) package.textures.push_back(image);
          const Extras provenance{{"geometrySemantic", std::string("VEGETATION_FOREST_PROXY")}, {"visualizationProxy", true},
                                  {"scientificSurface", false}, {"speciesInferred", false}, {"individualTreesResolved", false},
                                  {"positionSource", std::string("DENSE_CANOPY_MASK")}, {"heightSource", std::string("NDSM_ENVELOPE")},
                                  {"externalGeographicDataUsed", false}, {"assetSource", std::string("FOREST_TREE")}};
          std::map<std::string, int> materialOf;
          std::vector<int> meshOf;
          for (std::size_t k = 0; k < treeLibrary->prototypes.size(); ++k)
          {
               const ExternalVegetationAsset& tree = treeLibrary->prototypes[k];
               InstancedMeshDef mesh;
               mesh.name = "VEGETATION_FOREST_TREE_" + std::to_string(k);
               for (const ExternalVegetationPart& part : tree.parts)
               {
                    if (!materialOf.count(part.materialName))
                    {
                         MaterialDescriptor material = depthwizard::presentation::material(
                             "Vegetation_FOREST_TREE_" + part.materialName, MaterialRole::VEGETATION_CANOPY,
                             {part.baseColorFactor[0], part.baseColorFactor[1], part.baseColorFactor[2], part.baseColorFactor[3]},
                             0.0, std::max(0.9, part.roughness), part.doubleSided);
                         material.alphaMode = part.alphaMode;
                         material.alphaCutoff = part.alphaCutoff;
                         material.textureIndex = firstTexture + part.image;
                         Extras extras = provenance;
                         const auto get = [&](const char* key) { const auto it = treeLibrary->credits.find(key); return it == treeLibrary->credits.end() ? std::string() : it->second; };
                         extras["assetCredit"] = "\"" + get("title") + "\" by " + get("author") + ", " + get("license") + ", " + get("source");
                         package.materials.emplace_back(material, extras);
                         materialOf[part.materialName] = static_cast<int>(package.materials.size() - 1);
                    }
                    package.geometries.push_back({part.positions, part.normals, part.indices, part.uvs});
                    mesh.primitives.emplace_back(static_cast<int>(package.geometries.size() - 1), materialOf.at(part.materialName));
               }
               package.meshes.push_back(std::move(mesh));
               meshOf.push_back(static_cast<int>(package.meshes.size() - 1));
          }
          std::map<std::pair<uint32_t, int>, std::vector<std::size_t>> groups;
          for (std::size_t i = 0; i < forestTrees->trees.size(); ++i)
               groups[{forestTrees->trees[i].chunkIndex, forestTrees->trees[i].prototype}].push_back(i);
          for (const auto& [key, members] : groups)
          {
               char chunkName[16];
               std::snprintf(chunkName, sizeof(chunkName), "%03u", key.first);
               const std::string batchKey = "FOREST_TREE_" + std::to_string(key.second) + "_CHUNK_" + chunkName;
               InstancedNodeDef node;
               node.name = "VEGETATION_FOREST_NEAR_" + batchKey;
               node.mesh = meshOf[static_cast<std::size_t>(key.second)];
               std::vector<float> heights, radii;
               std::array<double, 3> lo{1e300, 1e300, 1e300}, hi{-1e300, -1e300, -1e300};
               for (std::size_t i : members)
               {
                    const ForestTree& t = forestTrees->trees[i];
                    node.translations.insert(node.translations.end(), t.translation.begin(), t.translation.end());
                    node.rotations.insert(node.rotations.end(), t.rotation.begin(), t.rotation.end());
                    node.scales.insert(node.scales.end(), {t.scale, t.scale, t.scale});
                    heights.push_back(t.scale);
                    radii.push_back(t.crownRadiusMetres);
                    for (int c : {0, 2})
                    {
                         lo[c] = std::min(lo[c], static_cast<double>(t.translation[c] - t.crownRadiusMetres));
                         hi[c] = std::max(hi[c], static_cast<double>(t.translation[c] + t.crownRadiusMetres));
                    }
                    lo[1] = std::min(lo[1], static_cast<double>(t.translation[1]));
                    hi[1] = std::max(hi[1], static_cast<double>(t.translation[1] + t.scale));
               }
               node.extras = provenance;
               node.extras["vegetationLod"] = std::string("NEAR");
               node.extras["vegetationBatch"] = batchKey;
               node.extras["treeCategory"] = std::string("FOREST_TREE");
               node.extras["chunkIndex"] = static_cast<double>(key.first);
               node.extras["chunkSizeMetres"] = centimetres(forestTrees->chunkSizeMetres);
               node.extras["instanceCount"] = static_cast<double>(members.size());
               node.extras["typicalDisplayHeight"] = centimetres(median(heights));
               node.extras["typicalCrownRadius"] = centimetres(median(radii));
               boundsExtras(node.extras, lo, hi);
               node.extras["prototypeTriangles"] = static_cast<double>(treeLibrary->prototypes[static_cast<std::size_t>(key.second)].triangles());
               node.extras["deterministicSeed"] = static_cast<double>(seed);
               package.nodes.push_back(std::move(node));
          }
     }
     if (forestAsset != nullptr && !forest.empty())
     {
          const int mesh = appendAsset(package, *forestAsset, forestProvenance(), "VEGETATION_FOREST_PATCH");
          std::map<uint32_t, std::vector<std::size_t>> groups;
          for (std::size_t k = 0; k < forest.proxies.size(); ++k) groups[forest.proxies[k].chunkIndex].push_back(k);
          for (const auto& [chunk, members] : groups)
          {
               std::vector<float> heights, radii;
               std::array<double, 3> lo{1e300, 1e300, 1e300}, hi{-1e300, -1e300, -1e300};
               for (std::size_t k : members)
               {
                    const ForestProxy& p = forest.proxies[k];
                    heights.push_back(p.scale);
                    radii.push_back(p.footprintRadiusMetres);
                    const double lean = p.footprintRadiusMetres * std::sin(p.tiltDegrees * 3.14159265358979 / 180.0);
                    for (int c : {0, 2})
                    {
                         lo[c] = std::min(lo[c], static_cast<double>(p.translation[c] - p.footprintRadiusMetres));
                         hi[c] = std::max(hi[c], static_cast<double>(p.translation[c] + p.footprintRadiusMetres));
                    }
                    lo[1] = std::min(lo[1], p.translation[1] - lean);
                    hi[1] = std::max(hi[1], p.translation[1] + p.scale + lean);
               }
               char chunkName[16];
               std::snprintf(chunkName, sizeof(chunkName), "%03u", chunk);
               const std::string batchKey = std::string("FOREST_PATCH_CHUNK_") + chunkName;
               int first = -1;
               for (const char* lod : {"NEAR", "MEDIUM"})
               {
                    InstancedNodeDef node;
                    node.name = std::string("VEGETATION_FOREST_") + lod + "_" + batchKey;
                    node.mesh = mesh;
                    if (first >= 0) node.instancesFrom = first;
                    else
                         for (std::size_t k : members)
                         {
                              const ForestProxy& p = forest.proxies[k];
                              node.translations.insert(node.translations.end(), p.translation.begin(), p.translation.end());
                              node.rotations.insert(node.rotations.end(), p.rotation.begin(), p.rotation.end());
                              node.scales.insert(node.scales.end(), {p.scale, p.scale, p.scale});
                         }
                    node.extras = forestProvenance();
                    node.extras["vegetationLod"] = std::string(lod);
                    node.extras["vegetationBatch"] = batchKey;
                    node.extras["treeCategory"] = std::string("FOREST_PROXY");
                    node.extras["chunkIndex"] = static_cast<double>(chunk);
                    node.extras["chunkX"] = static_cast<double>(forest.proxies[members.front()].chunkX);
                    node.extras["chunkZ"] = static_cast<double>(forest.proxies[members.front()].chunkZ);
                    node.extras["chunkSizeMetres"] = centimetres(forest.chunkSizeMetres);
                    node.extras["instanceCount"] = static_cast<double>(members.size());
                    node.extras["typicalDisplayHeight"] = centimetres(median(heights));
                    node.extras["typicalFootprintRadius"] = centimetres(median(radii));
                    boundsExtras(node.extras, lo, hi);
                    node.extras["prototypeTriangles"] = static_cast<double>(forestAsset->triangles());
                    node.extras["deterministicSeed"] = static_cast<double>(seed);
                    if (first < 0) first = static_cast<int>(package.nodes.size());
                    package.nodes.push_back(std::move(node));
               }
          }
     }
     return package;
}
