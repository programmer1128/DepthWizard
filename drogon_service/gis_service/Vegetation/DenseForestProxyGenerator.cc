#include "DenseForestProxyGenerator.h"
#include "VegetationTreeInstancer.h"
#include "../MeshMapping/GeoTransformMapping.h"
#include "../MeshMapping/TerrainSurfaceSampler.h"

#include <algorithm>
#include <cmath>
#include <map>

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

float percentile(std::vector<float> values, double share)
{
     if (values.empty()) return std::nanf("");
     const std::size_t k = std::min(values.size() - 1, static_cast<std::size_t>(share * static_cast<double>(values.size() - 1) + 0.5));
     std::nth_element(values.begin(), values.begin() + static_cast<std::ptrdiff_t>(k), values.end());
     return values[k];
}

std::array<float, 4> multiply(const std::array<float, 4>& a, const std::array<float, 4>& b)
{
     return {a[3] * b[0] + a[0] * b[3] + a[1] * b[2] - a[2] * b[1],
             a[3] * b[1] - a[0] * b[2] + a[1] * b[3] + a[2] * b[0],
             a[3] * b[2] + a[0] * b[1] - a[1] * b[0] + a[2] * b[3],
             a[3] * b[3] - a[0] * b[0] - a[1] * b[1] - a[2] * b[2]};
}
} // namespace

float DenseForestProxyGenerator::denseMedianHeight(const VegetationClassification& classes, const VegetationHeights& heights)
{
     std::vector<float> values;
     for (std::size_t i = 0; i < classes.classes.data.size() && i < heights.metricHeight.data.size(); ++i)
          if (classes.classes.data[i] == static_cast<uint8_t>(VegetationClass::DENSE) &&
              std::isfinite(heights.metricHeight.data[i]))
               values.push_back(heights.metricHeight.data[i]);
     return percentile(std::move(values), 0.5);
}

DenseForestProxies DenseForestProxyGenerator::generate(const DenseForestProxyInput& input)
{
     DenseForestProxies result;
     result.chunkSizeMetres = input.chunkSizeMetres;
     const auto finish = [&](const std::string& reason) {
          result.disabledReason = reason;
          return result;
     };
     if (input.presentation != ScenePresentation::METRIC) return finish("flat_urban presentation (forest patches are metric only)");
     if (!input.mask || !input.classification || !input.heights || !input.surface || !input.metadata)
          return finish("vegetation inputs unavailable");
     const auto& classes = input.classification->classes;
     const auto& barrier = input.mask->barrierMask;
     const auto& height = input.heights->metricHeight;
     const int width = classes.width, rows = classes.height;
     if (!classes.isValid() || barrier.width != width || barrier.height != rows || height.width != width ||
         height.height != rows)
          return finish("vegetation rasters inconsistent");
     if (!(input.prototypeRadius > 0.0f) || !(input.chunkSizeMetres > 0.0)) return finish("invalid forest prototype");

     const auto at = [width](int x, int y) { return static_cast<std::size_t>(y) * static_cast<std::size_t>(width) + static_cast<std::size_t>(x); };
     std::vector<std::size_t> dense;
     for (int y = 0; y < rows; ++y)
          for (int x = 0; x < width; ++x)
               if (classes.data[at(x, y)] == static_cast<uint8_t>(VegetationClass::DENSE) && !barrier.data[at(x, y)] &&
                   std::isfinite(height.data[at(x, y)]))
                    dense.push_back(at(x, y));
     result.stats.densePixels = dense.size();
     if (dense.empty()) return finish("no dense canopy");
     result.stats.denseMedianHeightMetres = denseMedianHeight(*input.classification, *input.heights);
     if (!(result.stats.denseMedianHeightMetres >= kAridMedianHeightMetres))
          return finish("arid / scrub scene (dense median height below 4 m)");
     const TerrainSurfaceSampler sampler(*input.surface, *input.metadata, input.frame, input.terrainConfig);
     if (!sampler.supported()) return finish("terrain elevation source not mirrored");
     result.enabled = true;

     const double columnMetres = geo::columnSpacing(*input.metadata), rowMetres = geo::rowSpacing(*input.metadata);
     // Footprint disc test: every pixel DENSE, barrier-free and with a finite
     // nDSM; returns the heights under the disc (empty when the test fails).
     const auto disc = [&](double column, double row, double radiusMetres, std::vector<float>& heights) {
          heights.clear();
          const int rx = static_cast<int>(std::ceil(radiusMetres / columnMetres));
          const int ry = static_cast<int>(std::ceil(radiusMetres / rowMetres));
          const int cx = static_cast<int>(std::floor(column)), cy = static_cast<int>(std::floor(row));
          for (int y = cy - ry; y <= cy + ry; ++y)
               for (int x = cx - rx; x <= cx + rx; ++x)
               {
                    const double dx = (x + 0.5 - column) * columnMetres, dy = (y + 0.5 - row) * rowMetres;
                    if (dx * dx + dy * dy > radiusMetres * radiusMetres) continue;
                    if (x < 0 || y < 0 || x >= width || y >= rows) return false;   // Image exterior
                    const std::size_t i = at(x, y);
                    if (classes.data[i] != static_cast<uint8_t>(VegetationClass::DENSE) || barrier.data[i] ||
                        !std::isfinite(height.data[i]))
                         return false;
                    heights.push_back(height.data[i]);
               }
          return !heights.empty();
     };

     // Seeded Fisher-Yates over the dense pixels: no grid pattern, reproducible.
     uint64_t state = (static_cast<uint64_t>(input.config.seed) << 32) ^ 0xF07E57ULL;
     for (std::size_t i = dense.size(); i > 1; --i)
          std::swap(dense[i - 1], dense[static_cast<std::size_t>(splitmix(state) % i)]);

     const double probeMetres = std::max({15.0, 2.0 * columnMetres, 2.0 * rowMetres});
     const std::size_t maxTests = 40 * kMaxPatches;
     std::vector<float> heights;
     for (std::size_t order = 0; order < dense.size(); ++order)
     {
          if (result.proxies.size() >= kMaxPatches || result.stats.tested >= maxTests)
          {
               result.stats.capped = dense.size() - order;
               break;
          }
          ++result.stats.tested;
          const std::size_t pixel = dense[order];
          const double column = static_cast<double>(pixel % static_cast<std::size_t>(width)) + 0.5;
          const double row = static_cast<double>(pixel / static_cast<std::size_t>(width)) + 0.5;

          // Height: local p90 envelope, then the footprint it implies.
          if (!disc(column, row, probeMetres, heights)) { ++result.stats.rejectedFootprint; continue; }
          float patchHeight = std::min(percentile(heights, 0.9), input.config.maxHeightMetres);
          double radius = patchHeight * input.prototypeRadius;
          if (radius > probeMetres && !disc(column, row, radius, heights))
          {
               // Narrow canopy: shrink the patch to the verified probe disc.
               patchHeight = static_cast<float>(probeMetres / input.prototypeRadius);
               radius = probeMetres;
               disc(column, row, radius, heights);
          }
          else if (radius <= probeMetres)
               disc(column, row, radius, heights);
          if (heights.empty()) { ++result.stats.rejectedFootprint; continue; }
          const float envelope = percentile(heights, 0.9);
          patchHeight = std::min(patchHeight, envelope);   // Tallest tree never above the envelope
          if (patchHeight < kMinPatchHeightMetres) { ++result.stats.rejectedLow; continue; }
          radius = patchHeight * input.prototypeRadius;

          const LocalPoint centre = geo::pixelEdgeToLocal(*input.metadata, input.frame, column, row);
          bool spaced = true;
          for (const ForestProxy& other : result.proxies)
          {
               const double d = std::hypot(centre.x - other.translation[0], centre.z - other.translation[2]);
               spaced = spaced && d >= (1.0 - kMaxOverlapShare) * (radius + other.footprintRadiusMetres);
          }
          if (!spaced) { ++result.stats.rejectedSpacing; continue; }

          // Terrain plane through 17 samples of the rendered terrain.
          std::vector<std::array<double, 3>> samples;   // (dx, dz, y)
          bool terrainOk = true;
          for (int ring = 0; ring <= 2 && terrainOk; ++ring)
               for (int k = 0; k < (ring == 0 ? 1 : 8) && terrainOk; ++k)
               {
                    const double angle = k * kPi / 4.0, r = radius * ring / 2.0;
                    const double dx = r * std::cos(angle), dz = r * std::sin(angle);
                    const auto [c, w] = geo::localToPixelEdge(*input.metadata, input.frame, centre.x + dx, centre.z + dz);
                    const auto y = sampler.localHeight(c, w);
                    if (!y) terrainOk = false;
                    else samples.push_back({dx, dz, static_cast<double>(*y)});
               }
          if (!terrainOk) { ++result.stats.rejectedTerrain; continue; }
          // Least squares y = a dx + b dz + c (dx, dz are centred by symmetry).
          double sxx = 0, szz = 0, sxz = 0, sxy = 0, szy = 0, sy = 0;
          for (const auto& s : samples)
          {
               sxx += s[0] * s[0]; szz += s[1] * s[1]; sxz += s[0] * s[1];
               sxy += s[0] * s[2]; szy += s[1] * s[2]; sy += s[2];
          }
          const double det = sxx * szz - sxz * sxz;
          const double a = det > 1e-12 ? (sxy * szz - szy * sxz) / det : 0.0;
          const double b = det > 1e-12 ? (szy * sxx - sxy * sxz) / det : 0.0;
          const double c = sy / static_cast<double>(samples.size());
          const double tilt = std::atan(std::hypot(a, b)) * 180.0 / kPi;
          if (tilt > kMaxTiltDegrees) { ++result.stats.rejectedSlope; continue; }
          double residual = 0.0;
          for (const auto& s : samples) residual = std::max(residual, std::abs(s[2] - (a * s[0] + b * s[1] + c)));
          if (residual > kMaxResidualShare * patchHeight) { ++result.stats.rejectedRelief; continue; }

          ForestProxy proxy;
          proxy.id = static_cast<uint32_t>(result.proxies.size() + 1);
          proxy.pixelColumn = column;
          proxy.pixelRow = row;
          proxy.translation = {static_cast<float>(centre.x), static_cast<float>(c), static_cast<float>(centre.z)};
          proxy.scale = patchHeight;
          proxy.envelopeMetres = envelope;
          proxy.footprintRadiusMetres = static_cast<float>(radius);
          proxy.tiltDegrees = static_cast<float>(tilt);
          proxy.terrainResidualMetres = static_cast<float>(residual);
          proxy.yawRadians = static_cast<float>(2.0 * kPi * VegetationTreeInstancer::cosmeticNoise(proxy.id, input.config.seed, 11));
          const std::array<float, 4> yaw{0.0f, std::sin(0.5f * proxy.yawRadians), 0.0f, std::cos(0.5f * proxy.yawRadians)};
          // Tilt: rotate +Y onto the terrain normal (-a, 1, -b).
          const double nx = -a, ny = 1.0, nz = -b, nl = std::sqrt(nx * nx + ny * ny + nz * nz);
          const double ax = nz / nl, az = -nx / nl, al = std::hypot(ax, az);
          std::array<float, 4> tiltQ{0.0f, 0.0f, 0.0f, 1.0f};
          if (al > 1e-9)
          {
               const double half = 0.5 * std::acos(std::clamp(ny / nl, -1.0, 1.0));
               tiltQ = {static_cast<float>(ax / al * std::sin(half)), 0.0f, static_cast<float>(az / al * std::sin(half)),
                        static_cast<float>(std::cos(half))};
          }
          proxy.rotation = multiply(tiltQ, yaw);
          const float norm = std::sqrt(proxy.rotation[0] * proxy.rotation[0] + proxy.rotation[1] * proxy.rotation[1] +
                                       proxy.rotation[2] * proxy.rotation[2] + proxy.rotation[3] * proxy.rotation[3]);
          for (float& q : proxy.rotation) q /= norm;
          const double easting = centre.x + input.frame.projectedOriginX, northing = input.frame.projectedOriginY - centre.z;
          proxy.chunkX = static_cast<int>(std::floor(easting / input.chunkSizeMetres));
          proxy.chunkZ = static_cast<int>(std::floor(northing / input.chunkSizeMetres));
          result.proxies.push_back(proxy);
     }
     std::map<std::pair<int, int>, uint32_t> chunkIndex;
     for (const ForestProxy& p : result.proxies) chunkIndex.emplace(std::make_pair(-p.chunkZ, p.chunkX), 0);
     uint32_t next = 0;
     for (auto& [key, index] : chunkIndex) index = next++;
     result.chunks = chunkIndex.size();
     for (ForestProxy& p : result.proxies) p.chunkIndex = chunkIndex.at({-p.chunkZ, p.chunkX});
     return result;
}
