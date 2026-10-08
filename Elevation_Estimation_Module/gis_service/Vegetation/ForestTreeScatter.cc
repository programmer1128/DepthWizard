#include "ForestTreeScatter.h"
#include "DenseForestProxyGenerator.h"
#include "../MeshMapping/GeoTransformMapping.h"
#include "../MeshMapping/TerrainSurfaceSampler.h"

#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>

namespace geo = depthwizard::geo;

namespace
{
constexpr double kPi = 3.14159265358979323846;

uint64_t splitmix(uint64_t& state)
{
     uint64_t z = (state += 0x9E3779B97F4A7C15ULL);
     z = (z ^ (z >> 30)) * 0xBF58476D1CE4E5B9ULL;
     z = (z ^ (z >> 27)) * 0x94D049BB133111EBULL;
     return z ^ (z >> 31);
}

double unit(uint64_t& state) { return static_cast<double>(splitmix(state) >> 11) / 9007199254740992.0; }
} // namespace

ForestTrees ForestTreeScatter::generate(const ForestTreeScatterInput& input)
{
     ForestTrees result;
     result.chunkSizeMetres = input.chunkSizeMetres;
     const auto finish = [&](const std::string& reason) {
          result.disabledReason = reason;
          return result;
     };
     if (input.presentation != ScenePresentation::METRIC) return finish("flat_urban presentation");
     if (!input.mask || !input.classification || !input.heights || !input.surface || !input.metadata)
          return finish("vegetation inputs unavailable");
     if (input.prototypeRadii.empty() || !(input.chunkSizeMetres > 0.0)) return finish("no forest tree prototypes");
     const auto& classes = input.classification->classes;
     const auto& barrier = input.mask->barrierMask;
     const auto& height = input.heights->metricHeight;
     const int width = classes.width, rows = classes.height;
     if (!classes.isValid() || barrier.width != width || barrier.height != rows || height.width != width ||
         height.height != rows)
          return finish("vegetation rasters inconsistent");
     const double columnMetres = geo::columnSpacing(*input.metadata), rowMetres = geo::rowSpacing(*input.metadata);
     if (std::max(columnMetres, rowMetres) > input.config.individualTreeMaxGsdMetres)
          return finish("ground resolution too coarse for individual trees");
     if (!(DenseForestProxyGenerator::denseMedianHeight(*input.classification, *input.heights) >=
           DenseForestProxyGenerator::kAridMedianHeightMetres))
          return finish("arid / scrub scene (dense median height below 4 m)");
     const TerrainSurfaceSampler sampler(*input.surface, *input.metadata, input.frame, input.terrainConfig);
     if (!sampler.supported()) return finish("terrain elevation source not mirrored");

     const auto at = [width](int x, int y) { return static_cast<std::size_t>(y) * static_cast<std::size_t>(width) + static_cast<std::size_t>(x); };
     const auto dense = [&](int x, int y) {
          if (x < 0 || y < 0 || x >= width || y >= rows) return false;
          const std::size_t i = at(x, y);
          return classes.data[i] == static_cast<uint8_t>(VegetationClass::DENSE) && !barrier.data[i] && std::isfinite(height.data[i]);
     };
     // Candidate centres on a ~0.9 m grid (trees are metres apart).
     const int stride = std::max(1, static_cast<int>(std::lround(0.9 / std::min(columnMetres, rowMetres))));
     std::vector<std::size_t> order;
     for (int y = 0; y < rows; y += stride)
          for (int x = 0; x < width; x += stride)
               if (dense(x, y)) order.push_back(at(x, y));
     if (order.empty()) return finish("no dense canopy");
     result.enabled = true;
     uint64_t state = (static_cast<uint64_t>(input.config.seed) << 32) ^ 0x7EE5ULL;
     for (std::size_t i = order.size(); i > 1; --i)
          std::swap(order[i - 1], order[static_cast<std::size_t>(splitmix(state) % i)]);

     const double cell = 16.0;
     std::unordered_map<int64_t, std::vector<std::array<float, 3>>> grid;
     const auto keyOf = [cell](double x, double z) {
          return (static_cast<int64_t>(std::floor(x / cell)) << 32) ^ (static_cast<int64_t>(std::floor(z / cell)) & 0xffffffff);
     };
     const auto clear = [&](double x, double z, double r) {
          for (int dx = -1; dx <= 1; ++dx)
               for (int dz = -1; dz <= 1; ++dz)
               {
                    const auto it = grid.find(keyOf(x + dx * cell, z + dz * cell));
                    if (it == grid.end()) continue;
                    for (const auto& d : it->second)
                         if (std::hypot(x - d[0], z - d[1]) < std::max(1.5, 0.75 * (r + d[2]))) return false;
               }
          return true;
     };

     // Spacing uses the library's mean crown radius, so every prototype has
     // the same chance (narrow trees would otherwise pack in and dominate).
     float meanRadius = 0.0f;
     for (float r : input.prototypeRadii) meanRadius += r;
     meanRadius /= static_cast<float>(input.prototypeRadii.size());

     std::vector<float> local;
     const int px25 = static_cast<int>(std::ceil(2.5 / columnMetres)), py25 = static_cast<int>(std::ceil(2.5 / rowMetres));
     for (std::size_t n = 0; n < order.size() && result.trees.size() < kMaxTrees; ++n)
     {
          const int px = static_cast<int>(order[n] % static_cast<std::size_t>(width));
          const int py = static_cast<int>(order[n] / static_cast<std::size_t>(width));
          const double column = px + 0.5, row = py + 0.5;
          const LocalPoint centre = geo::pixelEdgeToLocal(*input.metadata, input.frame, column, row);
          // Cheap pre-check with the smallest possible tree (3 m): most later
          // candidates already sit inside a neighbour's spacing.
          if (!clear(centre.x, centre.z, 3.0 * meanRadius)) continue;
          // Local canopy envelope: p90 nDSM within 2.5 m.
          local.clear();
          for (int y = std::max(0, py - py25); y <= std::min(rows - 1, py + py25); ++y)
               for (int x = std::max(0, px - px25); x <= std::min(width - 1, px + px25); ++x)
                    if (std::isfinite(height.data[at(x, y)])) local.push_back(height.data[at(x, y)]);
          if (local.empty()) continue;
          const std::size_t k90 = std::min(local.size() - 1, static_cast<std::size_t>(0.9 * static_cast<double>(local.size() - 1) + 0.5));
          std::nth_element(local.begin(), local.begin() + static_cast<std::ptrdiff_t>(k90), local.end());
          uint64_t jitter = (static_cast<uint64_t>(order[n]) << 1) ^ input.config.seed ^ 0x51EDULL;
          const float treeHeight = std::clamp(local[k90] * static_cast<float>(0.8 + 0.2 * unit(jitter)), 3.0f,
                                              input.config.maxHeightMetres);
          const int prototype = static_cast<int>(unit(jitter) * static_cast<double>(input.prototypeRadii.size())) %
                                static_cast<int>(input.prototypeRadii.size());
          const float radius = treeHeight * input.prototypeRadii[static_cast<std::size_t>(prototype)];
          const float spacing = treeHeight * meanRadius;
          // Trunk zone (0.35 x crown radius, at least one pixel) must be dense and barrier-free.
          const double trunk = std::max(0.35 * radius, std::max(columnMetres, rowMetres));
          bool ok = true;
          const int tx = static_cast<int>(std::ceil(trunk / columnMetres)), ty = static_cast<int>(std::ceil(trunk / rowMetres));
          for (int y = py - ty; y <= py + ty && ok; ++y)
               for (int x = px - tx; x <= px + tx && ok; ++x)
               {
                    const double dx = (x + 0.5 - column) * columnMetres, dy = (y + 0.5 - row) * rowMetres;
                    if (dx * dx + dy * dy <= trunk * trunk) ok = dense(x, y);
               }
          if (!ok) continue;
          if (!clear(centre.x, centre.z, spacing)) continue;
          const auto ground = sampler.localHeight(column, row);
          if (!ground) continue;
          ForestTree tree;
          tree.pixelColumn = column;
          tree.pixelRow = row;
          tree.prototype = prototype;
          tree.scale = treeHeight;
          tree.crownRadiusMetres = radius;
          tree.translation = {static_cast<float>(centre.x), *ground, static_cast<float>(centre.z)};
          const float yaw = static_cast<float>(2.0 * kPi * unit(jitter));
          tree.rotation = {0.0f, std::sin(0.5f * yaw), 0.0f, std::cos(0.5f * yaw)};
          const double easting = centre.x + input.frame.projectedOriginX, northing = input.frame.projectedOriginY - centre.z;
          tree.chunkX = static_cast<int>(std::floor(easting / input.chunkSizeMetres));
          tree.chunkZ = static_cast<int>(std::floor(northing / input.chunkSizeMetres));
          grid[keyOf(centre.x, centre.z)].push_back({static_cast<float>(centre.x), static_cast<float>(centre.z), spacing});
          result.trees.push_back(tree);
     }
     std::map<std::pair<int, int>, uint32_t> chunkIndex;
     for (const ForestTree& t : result.trees) chunkIndex.emplace(std::make_pair(-t.chunkZ, t.chunkX), 0);
     uint32_t next = 0;
     for (auto& [key, index] : chunkIndex) index = next++;
     result.chunks = chunkIndex.size();
     for (ForestTree& t : result.trees) t.chunkIndex = chunkIndex.at({-t.chunkZ, t.chunkX});
     return result;
}
