#include "VegetationTreeInstancer.h"

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <map>
#include <tuple>

namespace
{
uint64_t mix(uint64_t key)
{
     key += 0x9e3779b97f4a7c15ULL;
     key = (key ^ (key >> 30)) * 0xbf58476d1ce4e5b9ULL;
     key = (key ^ (key >> 27)) * 0x94d049bb133111ebULL;
     return key ^ (key >> 31);
}

float median(std::vector<float> values)
{
     if (values.empty()) return 0.0f;
     const std::size_t middle = (values.size() - 1) / 2;
     std::nth_element(values.begin(), values.begin() + static_cast<std::ptrdiff_t>(middle), values.end());
     return values[middle];
}

constexpr int kTints = 4;   // Per-instance colour tints (EXT_mesh_gpu_instancing _COLOR_0)
} // namespace

double VegetationTreeInstancer::cosmeticNoise(uint32_t candidateId, uint32_t seed, uint32_t salt)
{
     const uint64_t key = mix((static_cast<uint64_t>(seed) << 32) ^ candidateId) ^ mix(salt + 0x51ed27ULL);
     return static_cast<double>(mix(key) >> 11) / static_cast<double>(1ULL << 53);
}

double VegetationTreeInstancer::chunkSize(const VegetationConfig& config, double sceneExtentMetres)
{
     if (config.treeChunkSizeMetres > 0.0f) return config.treeChunkSizeMetres;
     return std::clamp(sceneExtentMetres / 4.0, 100.0, 250.0);
}

TreeVisualVariant VegetationTreeInstancer::selectVariant(const TreeCandidate& candidate, std::string* reason)
{
     const auto pick = [&](TreeVisualVariant variant, const char* why)
     {
          if (reason != nullptr) *reason = why;
          return variant;
     };
     if (candidate.category == TreeCandidateCategory::DENSE_CANOPY_CROWN)
          return pick(TreeVisualVariant::CANOPY_CROWN, "dense-canopy crown detail");
     const double aspect = candidate.metricHeight / std::max(1e-3, 2.0 * candidate.crownRadiusMetres);
     if (candidate.metricHeight < 3.0f && aspect <= 1.0)
          return pick(TreeVisualVariant::SHRUB, "low (metric height < 3 m) and broad (height / diameter <= 1)");
     if (aspect >= 1.6) return pick(TreeVisualVariant::TALL_NARROW, "tall for its crown (height / diameter >= 1.6)");
     if (candidate.vegetationSupport < 0.7f || candidate.compactness < 0.5f)
          return pick(TreeVisualVariant::DRY_SPARSE, "weak vegetation support (< 0.7) or sparse crown (compactness < 0.5)");
     if (candidate.compactness < 0.75f)
          return pick(TreeVisualVariant::BROADLEAF_IRREGULAR, "irregular crown support (compactness < 0.75)");
     return pick(TreeVisualVariant::BROADLEAF_ROUND, "broad compact crown");
}

VegetationTreeInstances VegetationTreeInstancer::build(const VegetationTreeCandidates& candidates,
                                                       const LocalSceneFrame& frame, const VegetationConfig& config,
                                                       double sceneExtentMetres)
{
     VegetationTreeInstances result;
     result.chunkSizeMetres = chunkSize(config, sceneExtentMetres);
     result.lodEnabled = config.treeLod;
     // Scrubland: the median measured height of all candidates (isolated
     // trees and canopy crowns) is below 4 m. Isolated trees alone are not
     // enough: urban parks have short isolated shrubs beside tall canopy.
     std::vector<float> heights;
     for (const TreeCandidate& c : candidates.candidates) heights.push_back(c.metricHeight);
     result.paletteFamily = !heights.empty() && median(heights) < 4.0f ? "arid" : "temperate";
     if (!candidates.enabled || candidates.candidates.empty()) return result;

     for (const TreeCandidate& c : candidates.candidates)
     {
          TreeInstance instance;
          instance.candidateId = c.id;
          instance.category = c.category;
          instance.variant = selectVariant(c, &instance.variantReason);
          instance.colourTint = static_cast<int>(cosmeticNoise(c.id, config.seed, 3) * kTints);
          instance.rotationRadians = static_cast<float>(cosmeticNoise(c.id, config.seed, 1) * 2.0 * M_PI);
          instance.widthFactor = static_cast<float>(0.9 + 0.1 * cosmeticNoise(c.id, config.seed, 2));
          instance.translation = {static_cast<float>(c.worldX), c.baseY, static_cast<float>(c.worldZ)};
          const float half = 0.5f * instance.rotationRadians;
          instance.rotation = {0.0f, std::sin(half), 0.0f, std::cos(half)};
          const float horizontal = c.crownRadiusMetres * instance.widthFactor;
          instance.scale = {horizontal, c.displayHeight, horizontal};
          instance.metricHeight = c.metricHeight;
          instance.displayHeight = c.displayHeight;
          instance.crownRadiusMetres = c.crownRadiusMetres;
          // Stable grid in projected coordinates (independent of the local origin).
          const double easting = c.worldX + frame.projectedOriginX;
          const double northing = frame.projectedOriginY - c.worldZ;
          instance.chunkX = static_cast<int>(std::floor(easting / result.chunkSizeMetres));
          instance.chunkZ = static_cast<int>(std::floor(northing / result.chunkSizeMetres));
          ++result.perVariant[static_cast<std::size_t>(instance.variant)];
          ++(c.category == TreeCandidateCategory::DENSE_CANOPY_CROWN ? result.canopyCrowns : result.isolated);
          result.instances.push_back(std::move(instance));
     }

     // Chunk indices in grid order (north to south, west to east).
     std::map<std::pair<int, int>, uint32_t> chunkIndex;
     for (const TreeInstance& i : result.instances) chunkIndex.emplace(std::make_pair(-i.chunkZ, i.chunkX), 0);
     uint32_t next = 0;
     for (auto& [key, index] : chunkIndex) index = next++;
     result.chunks = chunkIndex.size();
     for (TreeInstance& i : result.instances) i.chunkIndex = chunkIndex.at({-i.chunkZ, i.chunkX});

     // Batches per (chunk, variant) and level of detail; colour variety is a
     // per-instance tint, not a separate batch.
     std::map<std::tuple<uint32_t, int>, std::vector<std::size_t>> groups;
     for (std::size_t k = 0; k < result.instances.size(); ++k)
     {
          const TreeInstance& i = result.instances[k];
          groups[{i.chunkIndex, static_cast<int>(i.variant)}].push_back(k);
     }
     for (const auto& [key, members] : groups)
     {
          const auto [chunk, variantValue] = key;
          const auto variant = static_cast<TreeVisualVariant>(variantValue);
          std::vector<TreeLod> levels{TreeLod::NEAR};
          if (config.treeLod)
          {
               levels.push_back(TreeLod::MEDIUM);
               // Canopy crowns need no far level: the continuous canopy remains.
               if (variant != TreeVisualVariant::CANOPY_CROWN) levels.push_back(TreeLod::FAR);
          }
          std::vector<float> heights, radii;
          std::array<double, 3> lo{1e300, 1e300, 1e300}, hi{-1e300, -1e300, -1e300};
          for (std::size_t k : members)
          {
               const TreeInstance& i = result.instances[k];
               heights.push_back(i.displayHeight);
               radii.push_back(i.crownRadiusMetres);
               lo = {std::min(lo[0], static_cast<double>(i.translation[0] - i.scale[0])),
                     std::min(lo[1], static_cast<double>(i.translation[1])),
                     std::min(lo[2], static_cast<double>(i.translation[2] - i.scale[2]))};
               hi = {std::max(hi[0], static_cast<double>(i.translation[0] + i.scale[0])),
                     std::max(hi[1], static_cast<double>(i.translation[1] + i.scale[1])),
                     std::max(hi[2], static_cast<double>(i.translation[2] + i.scale[2]))};
          }
          char chunkName[16];
          std::snprintf(chunkName, sizeof(chunkName), "%03u", chunk);
          for (TreeLod lod : levels)
          {
               TreeBatch batch;
               batch.variant = variant;
               batch.lod = lod;
               batch.chunkIndex = chunk;
               batch.chunkX = result.instances[members.front()].chunkX;
               batch.chunkZ = result.instances[members.front()].chunkZ;
               batch.instances = members;
               batch.boundsMin = lo;
               batch.boundsMax = hi;
               batch.typicalHeight = median(heights);
               batch.typicalRadius = median(radii);
               batch.batchKey = std::string(toString(variant)) + "_CHUNK_" + chunkName;
               batch.name = std::string("VEGETATION_TREES_") + toString(lod) + "_" + batch.batchKey;
               result.batches.push_back(std::move(batch));
          }
     }
     return result;
}
