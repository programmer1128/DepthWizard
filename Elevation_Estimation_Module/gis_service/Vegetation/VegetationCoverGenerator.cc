#include "VegetationCoverGenerator.h"
#include "VegetationTreeInstancer.h"
#include "../MeshMapping/GeoTransformMapping.h"
#include "../MeshMapping/TerrainSurfaceSampler.h"

#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

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

float percentile(std::vector<float>& values, double share)
{
     if (values.empty()) return std::nanf("");
     const std::size_t k = std::min(values.size() - 1, static_cast<std::size_t>(share * static_cast<double>(values.size() - 1) + 0.5));
     std::nth_element(values.begin(), values.begin() + static_cast<std::ptrdiff_t>(k), values.end());
     return values[k];
}

// Image shrub detector for natural scenes: darker than the local (15 m)
// background, greener than it, green >= red, compact (survives a 2.5 m
// opening). A blob is kept when it stands (p75 nDSM >= 0.5 m) or is
// yellow-green rather than bluish (median red - blue >= 10): cast shadows are
// both flat and bluish, while small shrubs the nDSM misses are still warm.
cv::Mat detectShrubs(const cv::Mat& bgr, const RasterGrid<float>& ndsm, double pixelMetres, VegetationCoverStats& stats)
{
     cv::Mat f;
     bgr.convertTo(f, CV_32FC3);
     std::vector<cv::Mat> c;
     cv::split(f, c);   // B, G, R
     const cv::Mat sum = c[0] + c[1] + c[2] + 1e-3f;
     const cv::Mat bright = sum / 3.0f;
     const cv::Mat exg = (2.0f * c[1] - c[0] - c[2]) / sum;
     const int window = std::max(3, static_cast<int>(std::lround(15.0 / pixelMetres)) | 1);
     cv::Mat backgroundBright, backgroundExg;
     cv::blur(bright, backgroundBright, cv::Size(window, window), cv::Point(-1, -1), cv::BORDER_REPLICATE);
     cv::blur(exg, backgroundExg, cv::Size(window, window), cv::Point(-1, -1), cv::BORDER_REPLICATE);
     cv::Mat darker = (backgroundBright - bright) / cv::max(backgroundBright, 1.0f);
     cv::Mat shrub = (darker >= 0.10f) & ((exg - backgroundExg) >= 0.008f) & (c[1] >= c[2]);
     const int open = std::max(3, static_cast<int>(std::lround(2.5 / pixelMetres)) | 1);
     cv::morphologyEx(shrub, shrub, cv::MORPH_OPEN, cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(open, open)));
     cv::Mat labels;
     const int count = cv::connectedComponents(shrub, labels, 8, CV_32S);
     std::vector<std::vector<float>> heights(static_cast<std::size_t>(count)), warmth(static_cast<std::size_t>(count));
     for (int y = 0; y < labels.rows; ++y)
          for (int x = 0; x < labels.cols; ++x)
          {
               const int label = labels.at<int>(y, x);
               if (label == 0) continue;
               const float h = ndsm.data[static_cast<std::size_t>(y) * static_cast<std::size_t>(ndsm.width) + static_cast<std::size_t>(x)];
               heights[static_cast<std::size_t>(label)].push_back(std::isfinite(h) ? h : 0.0f);
               warmth[static_cast<std::size_t>(label)].push_back(c[2].at<float>(y, x) - c[0].at<float>(y, x));
          }
     std::vector<uint8_t> keep(static_cast<std::size_t>(count), 0);
     for (int label = 1; label < count; ++label)
     {
          keep[static_cast<std::size_t>(label)] = percentile(heights[static_cast<std::size_t>(label)], 0.75) >= 0.5f ||
                                                  percentile(warmth[static_cast<std::size_t>(label)], 0.5) >= 10.0f;
          if (!keep[static_cast<std::size_t>(label)]) ++stats.rejectedComponents;
     }
     for (int y = 0; y < labels.rows; ++y)
          for (int x = 0; x < labels.cols; ++x)
               if (!keep[static_cast<std::size_t>(labels.at<int>(y, x))]) shrub.at<uint8_t>(y, x) = 0;
     return shrub;
}
} // namespace

VegetationCover VegetationCoverGenerator::generate(const VegetationCoverInput& input)
{
     VegetationCover result;
     result.chunkSizeMetres = input.chunkSizeMetres;
     result.mode = input.presentation == ScenePresentation::FLAT_URBAN ? VegetationCoverMode::GARDEN : VegetationCoverMode::NATURAL;
     const auto finish = [&](const std::string& reason) {
          result.disabledReason = reason;
          return result;
     };
     if (!input.mask || !input.semantics || !input.surface || !input.metadata) return finish("vegetation inputs unavailable");
     const auto& barrier = input.mask->barrierMask;
     const auto& classes = input.semantics->finalClassMap;
     const auto& ndsm = input.surface->ndsm;
     const int width = barrier.width, rows = barrier.height;
     if (!barrier.isValid() || classes.width != width || classes.height != rows || ndsm.width != width || ndsm.height != rows)
          return finish("vegetation rasters inconsistent");
     const double columnMetres = geo::columnSpacing(*input.metadata), rowMetres = geo::rowSpacing(*input.metadata);
     if (std::max(columnMetres, rowMetres) > input.config.individualTreeMaxGsdMetres)
          return finish("ground resolution too coarse for shrubs");
     if (!(input.chunkSizeMetres > 0.0)) return finish("invalid chunk size");

     // Cover mask.
     const auto at = [width](int x, int y) { return static_cast<std::size_t>(y) * static_cast<std::size_t>(width) + static_cast<std::size_t>(x); };
     result.coverMask.width = width;
     result.coverMask.height = rows;
     result.coverMask.data.assign(static_cast<std::size_t>(width) * static_cast<std::size_t>(rows), 0);
     cv::Mat detected;
     if (result.mode == VegetationCoverMode::NATURAL && input.opticalBytes && !input.opticalBytes->empty())
     {
          cv::Mat bgr = cv::imdecode(*input.opticalBytes, cv::IMREAD_COLOR);
          if (!bgr.empty())
          {
               if (bgr.cols != width || bgr.rows != rows) cv::resize(bgr, bgr, cv::Size(width, rows), 0, 0, cv::INTER_AREA);
               detected = detectShrubs(bgr, ndsm, std::min(columnMetres, rowMetres), result.stats);
          }
     }
     for (int y = 0; y < rows; ++y)
          for (int x = 0; x < width; ++x)
          {
               const std::size_t i = at(x, y);
               if (barrier.data[i] || !std::isfinite(ndsm.data[i])) continue;
               if (input.forestDense && input.forestDense->classes.isValid() &&
                   input.forestDense->classes.data[i] == static_cast<uint8_t>(VegetationClass::DENSE))
                    continue;
               const SemanticClass cls = classes.data[i];
               bool cover = false;
               if (result.mode == VegetationCoverMode::GARDEN)
               {
                    cover = cls == SemanticClass::VEGETATION;
                    result.stats.semanticPixels += cover;
               }
               else
               {
                    // Measured vegetation (stage-2 mask) plus the image detector
                    // inside VEGETATION or UNKNOWN pixels.
                    const bool masked = input.mask->tier.isValid() && input.mask->tier.data[i] != 0;
                    const bool image = !detected.empty() && detected.at<uint8_t>(y, x) &&
                                       (cls == SemanticClass::VEGETATION || cls == SemanticClass::UNKNOWN);
                    cover = masked || image;
                    result.stats.semanticPixels += masked;
                    result.stats.imageDetectedPixels += image && !masked;
               }
               result.coverMask.data[i] = cover;
               result.stats.coverPixels += cover;
          }
     if (result.stats.coverPixels == 0) return finish("no vegetation cover");
     const TerrainSurfaceSampler sampler(*input.surface, *input.metadata, input.frame, input.terrainConfig);
     const bool flat = input.presentation == ScenePresentation::FLAT_URBAN;
     if (!flat && !sampler.supported()) return finish("terrain elevation source not mirrored");
     result.enabled = true;

     const float minHeight = 0.6f, maxHeight = result.mode == VegetationCoverMode::GARDEN ? 1.5f : 3.0f;
     const float minRadius = 0.6f, maxRadius = result.mode == VegetationCoverMode::GARDEN ? 1.4f : 2.2f;
     std::vector<std::size_t> order;
     for (std::size_t i = 0; i < result.coverMask.data.size(); ++i)
          if (result.coverMask.data[i]) order.push_back(i);
     uint64_t state = (static_cast<uint64_t>(input.config.seed) << 32) ^ 0xC07E2ULL;
     for (std::size_t i = order.size(); i > 1; --i)
          std::swap(order[i - 1], order[static_cast<std::size_t>(splitmix(state) % i)]);

     // Spatial hash of accepted and occupied discs (local x, z, radius).
     const double cell = 2.0 * std::max<double>(maxRadius, 7.0);
     std::unordered_map<int64_t, std::vector<std::array<float, 3>>> grid;
     const auto keyOf = [cell](double x, double z) {
          return (static_cast<int64_t>(std::floor(x / cell)) << 32) ^ (static_cast<int64_t>(std::floor(z / cell)) & 0xffffffff);
     };
     for (const auto& d : input.occupied) grid[keyOf(d[0], d[1])].push_back({d[0], d[1], -d[2]});   // Negative: candidate bush
     const auto clear = [&](double x, double z, double r) {
          for (int dx = -1; dx <= 1; ++dx)
               for (int dz = -1; dz <= 1; ++dz)
               {
                    const auto it = grid.find(keyOf(x + dx * cell, z + dz * cell));
                    if (it == grid.end()) continue;
                    for (const auto& d : it->second)
                    {
                         const double distance = std::hypot(x - d[0], z - d[1]);
                         // Candidate bushes keep their whole crown; shrubs may overlap 20 %.
                         if (d[2] < 0.0f ? distance < r - d[2] * 0.9 : distance < 0.8 * (r + d[2])) return false;
                    }
               }
          return true;
     };

     // Natural: the inscribed radius of the cover blob (metres) sizes the shrub,
     // so a shrub the image shows 3 m wide is not drawn 1 m wide.
     cv::Mat inscribed;
     if (result.mode == VegetationCoverMode::NATURAL)
     {
          cv::Mat coverMat(rows, width, CV_8U, result.coverMask.data.data());
          cv::distanceTransform(coverMat, inscribed, cv::DIST_L2, 3);
          inscribed *= static_cast<float>(std::min(columnMetres, rowMetres));
     }
     // Garden: deterministic low-frequency value noise (8 m cells) leaves lawn
     // between shrub beds instead of a uniform field.
     const auto lawn = [&](double x, double z) {
          const auto value = [&](int64_t i, int64_t j) {
               uint64_t s = (static_cast<uint64_t>(i) * 0x9E3779B1ULL) ^ (static_cast<uint64_t>(j) * 0x85EBCA77ULL) ^ input.config.seed;
               return unit(s);
          };
          const double gx = x / 8.0, gz = z / 8.0;
          const int64_t i = static_cast<int64_t>(std::floor(gx)), j = static_cast<int64_t>(std::floor(gz));
          const double fx = gx - static_cast<double>(i), fz = gz - static_cast<double>(j);
          const double a = value(i, j) * (1 - fx) + value(i + 1, j) * fx, b = value(i, j + 1) * (1 - fx) + value(i + 1, j + 1) * fx;
          return a * (1 - fz) + b * fz < 0.42;
     };

     // Natural scenes: every vegetation find is drawn as a pair (the shrub and
     // a smaller companion beside it, on the same vegetation), and drawn at
     // kNaturalProminence x its measured size so sparse scrub reads clearly.
     const bool natural = result.mode == VegetationCoverMode::NATURAL;
     const float prominence = natural ? kNaturalProminence : 1.0f;
     const auto emit = [&](double column, double row, double x, double z, float base, float radius, float metric,
                           float yaw, bool companion) {
          CoverShrub shrub;
          shrub.pixelColumn = column;
          shrub.pixelRow = row;
          shrub.metricHeight = metric;
          shrub.radiusMetres = radius;
          shrub.companion = companion;
          shrub.translation = {static_cast<float>(x), base, static_cast<float>(z)};
          shrub.rotation = {0.0f, std::sin(0.5f * yaw), 0.0f, std::cos(0.5f * yaw)};
          shrub.scale = {radius * prominence, metric * input.displayHeightScale * prominence, radius * prominence};
          const double easting = x + input.frame.projectedOriginX, northing = input.frame.projectedOriginY - z;
          shrub.chunkX = static_cast<int>(std::floor(easting / input.chunkSizeMetres));
          shrub.chunkZ = static_cast<int>(std::floor(northing / input.chunkSizeMetres));
          result.shrubs.push_back(shrub);
          result.stats.companions += companion;
     };
     // Companions: 2-3 per find (seeded), spread around the parent at 1.2 and
     // then 0.6 x its radius, each on a cover pixel free of barriers; a
     // companion with no free spot shares the parent's spot (own size and yaw),
     // so every find shows 3-4 bushes.
     const auto addCompanion = [&](double x, double z, double column, double row, float parentRadius, float parentHeight,
                                   uint64_t seed) {
          uint64_t s = seed ^ 0xA5A5ULL;
          const double start = 2.0 * kPi * unit(s);
          const int count = unit(s) < 0.5 ? 2 : 3;
          for (int n = 0; n < count; ++n)
          {
               const float share = static_cast<float>(0.6 + 0.25 * unit(s));
               const float radius = std::clamp(share * parentRadius, minRadius, maxRadius);
               const float metric = std::clamp(static_cast<float>(0.75 + 0.15 * unit(s)) * parentHeight, minHeight, maxHeight);
               const float yaw = static_cast<float>(2.0 * kPi * unit(s));
               const double direction = start + n * 2.0 * kPi / count;
               bool placed = false;
               for (double reach : {1.2, 0.6})
               {
                    for (int k = 0; k < 3 && !placed; ++k)
                    {
                         const double angle = direction + (k == 0 ? 0.0 : (k == 1 ? 0.5 : -0.5));
                         const double d = reach * parentRadius;
                         const double cx = x + d * std::cos(angle), cz = z + d * std::sin(angle);
                         const auto [c, w] = geo::localToPixelEdge(*input.metadata, input.frame, cx, cz);
                         const int ix = static_cast<int>(std::floor(c)), iy = static_cast<int>(std::floor(w));
                         if (ix < 0 || iy < 0 || ix >= width || iy >= rows) continue;
                         if (barrier.data[at(ix, iy)] || !result.coverMask.data[at(ix, iy)]) continue;
                         float base = 0.0f;
                         if (!flat)
                         {
                              const auto ground = sampler.localHeight(c, w);
                              if (!ground) continue;
                              base = *ground;
                         }
                         emit(c, w, cx, cz, base, radius, metric, yaw, true);
                         placed = true;
                    }
                    if (placed) break;
               }
               if (placed) continue;
               float base = 0.0f;
               if (!flat)
               {
                    const auto ground = sampler.localHeight(column, row);
                    if (!ground) continue;
                    base = *ground;
               }
               emit(column, row, x, z, base, radius, metric, yaw, true);
          }
     };
     // Stage-4 candidate bushes (natural): one companion each.
     if (natural)
          for (std::size_t k = 0; k < input.occupied.size(); ++k)
          {
               const auto& d = input.occupied[k];
               const auto [c, w] = geo::localToPixelEdge(*input.metadata, input.frame, d[0], d[1]);
               uint64_t s = (static_cast<uint64_t>(k) << 20) ^ input.config.seed ^ 0xC0FFEEULL;
               addCompanion(d[0], d[1], c, w, std::min(d[2], maxRadius), std::clamp(1.2f * std::min(d[2], maxRadius), minHeight, maxHeight), s);
          }

     std::vector<float> local;
     for (std::size_t n = 0; n < order.size(); ++n)
     {
          if (result.shrubs.size() >= kMaxShrubs) { result.stats.capped = order.size() - n; break; }
          ++result.stats.tested;
          const int px = static_cast<int>(order[n] % static_cast<std::size_t>(width));
          const int py = static_cast<int>(order[n] / static_cast<std::size_t>(width));
          const double column = px + 0.5, row = py + 0.5;
          // Local height: p75 of the nDSM within 1.5 m (cover pixels only).
          local.clear();
          const int hx = static_cast<int>(std::ceil(1.5 / columnMetres)), hy = static_cast<int>(std::ceil(1.5 / rowMetres));
          for (int y = std::max(0, py - hy); y <= std::min(rows - 1, py + hy); ++y)
               for (int x = std::max(0, px - hx); x <= std::min(width - 1, px + hx); ++x)
                    if (result.coverMask.data[at(x, y)]) local.push_back(ndsm.data[at(x, y)]);
          const float measured = percentile(local, 0.75);
          uint64_t jitter = (static_cast<uint64_t>(order[n]) << 1) ^ input.config.seed;
          float radius, metric;
          if (result.mode == VegetationCoverMode::NATURAL)
          {
               const float blob = inscribed.at<float>(py, px);
               radius = std::clamp(std::max(std::clamp(measured, minHeight, maxHeight) * static_cast<float>(0.9 + 0.4 * unit(jitter)),
                                            0.9f * blob), minRadius, maxRadius);
               // Shrubs the nDSM under-resolves keep a natural shrub proportion
               // (height >= 1.2 x radius; the bush asset itself is 1.64).
               metric = std::clamp(std::max(measured, 1.2f * radius), minHeight, maxHeight);
          }
          else
          {
               metric = std::clamp(measured, minHeight, maxHeight) * static_cast<float>(0.6 + 0.4 * unit(jitter));
               metric = std::max(metric, minHeight);
               radius = std::clamp(metric * static_cast<float>(0.7 + 0.7 * unit(jitter)), 0.5f, maxRadius);
          }
          // Disc: at least half cover, no barrier pixel, inside the image.
          const int rx = static_cast<int>(std::ceil(radius / columnMetres)), ry = static_cast<int>(std::ceil(radius / rowMetres));
          std::size_t inside = 0, covered = 0;
          bool blocked = false;
          for (int y = py - ry; y <= py + ry && !blocked; ++y)
               for (int x = px - rx; x <= px + rx; ++x)
               {
                    const double dx = (x + 0.5 - column) * columnMetres, dy = (y + 0.5 - row) * rowMetres;
                    if (dx * dx + dy * dy > radius * radius) continue;
                    if (x < 0 || y < 0 || x >= width || y >= rows || barrier.data[at(x, y)]) { blocked = true; break; }
                    ++inside;
                    covered += result.coverMask.data[at(x, y)];
               }
          if (blocked || inside == 0 || covered * 2 < inside) continue;
          const LocalPoint centre = geo::pixelEdgeToLocal(*input.metadata, input.frame, column, row);
          if (result.mode == VegetationCoverMode::GARDEN && lawn(centre.x, centre.z)) continue;
          if (!clear(centre.x, centre.z, radius)) continue;
          float base = 0.0f;
          if (!flat)
          {
               const auto ground = sampler.localHeight(column, row);
               if (!ground) continue;
               base = *ground;
          }
          const float yaw = static_cast<float>(2.0 * kPi * unit(jitter));
          grid[keyOf(centre.x, centre.z)].push_back({static_cast<float>(centre.x), static_cast<float>(centre.z), radius});
          emit(column, row, centre.x, centre.z, base, radius, metric, yaw, false);
          if (natural) addCompanion(centre.x, centre.z, column, row, radius, metric, jitter);
     }
     std::map<std::pair<int, int>, uint32_t> chunkIndex;
     for (const CoverShrub& s : result.shrubs) chunkIndex.emplace(std::make_pair(-s.chunkZ, s.chunkX), 0);
     uint32_t next = 0;
     for (auto& [key, index] : chunkIndex) index = next++;
     result.chunks = chunkIndex.size();
     for (CoverShrub& s : result.shrubs) s.chunkIndex = chunkIndex.at({-s.chunkZ, s.chunkX});
     return result;
}
