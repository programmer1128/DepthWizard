#include "VegetationCanopyBuilder.h"
#include "../MeshMapping/GeoTransformMapping.h"
#include "../MeshMapping/TerrainSurfaceSampler.h"

#include <opencv2/imgproc.hpp>

#include <algorithm>
#include <chrono>
#include <cmath>
#include <limits>
#include <numeric>
#include <vector>

namespace geo = depthwizard::geo;

namespace
{
template <typename T>
bool sized(const RasterGrid<T>& grid, int width, int height)
{
     return grid.isValid() && grid.width == width && grid.height == height;
}

// Sum of an integral image over the inclusive pixel block [x0, x1] x [y0, y1].
int blockSum(const cv::Mat& integral, int x0, int y0, int x1, int y1)
{
     return integral.at<int>(y1 + 1, x1 + 1) - integral.at<int>(y0, x1 + 1) - integral.at<int>(y1 + 1, x0) +
            integral.at<int>(y0, x0);
}

struct UnionFind
{
     std::vector<uint32_t> parent;
     explicit UnionFind(std::size_t size) : parent(size) { std::iota(parent.begin(), parent.end(), 0U); }
     uint32_t find(uint32_t value)
     {
          while (parent[value] != value) value = parent[value] = parent[parent[value]];
          return value;
     }
     void unite(uint32_t a, uint32_t b)
     {
          a = find(a);
          b = find(b);
          if (a != b) parent[std::max(a, b)] = std::min(a, b); // Deterministic root
     }
};
} // namespace

VegetationCanopyMesh VegetationCanopyBuilder::build(const VegetationCanopyInput& input,
                                                    const GeoreferencedSurfaceBundle& surface,
                                                    const SpatialMetadata& metadata, const LocalSceneFrame& frame,
                                                    const TerrainMeshConfig& terrainConfig,
                                                    ScenePresentation presentation)
{
     const auto started = std::chrono::steady_clock::now();
     VegetationCanopyMesh mesh;
     VegetationCanopyStats& stats = mesh.stats;
     const bool flat = presentation == ScenePresentation::FLAT_URBAN;
     stats.presentationMode = flat ? "flat_urban" : "metric";
     stats.displayHeightScale =
         VegetationHeightSampler::displayHeightScale(presentation, input.buildingDisplayHeightScale);
     const auto finish = [&](const char* reason)
     {
          if (reason != nullptr) stats.skippedReason = reason;
          stats.buildMilliseconds =
              std::chrono::duration<double, std::milli>(std::chrono::steady_clock::now() - started).count();
          return mesh;
     };

     const int width = metadata.width;
     const int height = metadata.height;
     if (input.mask == nullptr || input.classification == nullptr || input.heights == nullptr ||
         !input.mask->inputsAvailable || !sized(input.mask->barrierMask, width, height) ||
         !sized(input.classification->classes, width, height) ||
         !sized(input.heights->metricHeight, width, height))
          return finish("vegetation inputs unavailable");
     const TerrainSurfaceSampler sampler(surface, metadata, frame, terrainConfig);
     if (!flat && !sampler.supported()) return finish("terrain elevation source not mirrored");

     const std::size_t total = static_cast<std::size_t>(width) * height;
     cv::Mat dense(height, width, CV_8U), barrier(height, width, CV_8U);
     std::size_t densePixels = 0;
     for (std::size_t i = 0; i < total; ++i)
     {
          dense.data[i] = input.classification->classes.data[i] == static_cast<uint8_t>(VegetationClass::DENSE) &&
                                  std::isfinite(input.heights->metricHeight.data[i])
              ? 1 : 0;
          barrier.data[i] = input.mask->barrierMask.data[i] ? 1 : 0;
          densePixels += dense.data[i];
     }
     if (densePixels == 0) return finish("no dense vegetation");

     cv::Mat denseIntegral, barrierIntegral;
     cv::integral(dense, denseIntegral, CV_32S);
     cv::integral(barrier, barrierIntegral, CV_32S);

     const VegetationConfig& config = input.config;
     const VegetationPixelScale& scale = input.mask->scale;
     const double finerSpacing = std::min(scale.columnSpacingMetres, scale.rowSpacingMetres);

     // Base Y per node pixel (cached): the rendered terrain surface, or the
     // flat ground plane.
     std::vector<float> baseCache(total, std::numeric_limits<float>::quiet_NaN());
     std::vector<uint8_t> baseKnown(total, 0);
     const auto baseAt = [&](int column, int row) -> float
     {
          const std::size_t i = static_cast<std::size_t>(row) * width + column;
          if (!baseKnown[i])
          {
               baseKnown[i] = 1;
               if (flat) baseCache[i] = 0.0f;
               else if (const auto value = sampler.localHeight(column + 0.5, row + 0.5)) baseCache[i] = *value;
          }
          return baseCache[i];
     };

     // A cell (i, j) spans node pixels (i*s, j*s) to ((i+1)*s, (j+1)*s).
     const auto cellValid = [&](int s, int i, int j, bool count)
     {
          const int x0 = i * s, y0 = j * s, x1 = x0 + s, y1 = y0 + s;
          if (!dense.at<uint8_t>(y0, x0) || !dense.at<uint8_t>(y0, x1) || !dense.at<uint8_t>(y1, x0) ||
              !dense.at<uint8_t>(y1, x1))
               return false;
          if (count) ++stats.candidateCells;
          if (blockSum(barrierIntegral, x0, y0, x1, y1) != 0)
          {
               if (count) ++stats.rejectedBarrierCells;
               return false;
          }
          const int blockArea = (s + 1) * (s + 1);
          if (blockSum(denseIntegral, x0, y0, x1, y1) < config.canopyCellMinCoverage * blockArea)
          {
               if (count) ++stats.rejectedCoverageCells;
               return false;
          }
          return std::isfinite(baseAt(x0, y0)) && std::isfinite(baseAt(x1, y0)) && std::isfinite(baseAt(x0, y1)) &&
                 std::isfinite(baseAt(x1, y1));
     };

     // Smallest stride whose triangle count fits the budget.
     int stride = 1;
     const int maxStride = std::max(1, std::min(width, height) - 1);
     for (;; ++stride)
     {
          std::size_t cells = 0;
          const int columns = (width - 1) / stride, rows = (height - 1) / stride;
          for (int j = 0; j < rows; ++j)
               for (int i = 0; i < columns; ++i) cells += cellValid(stride, i, j, false) ? 1 : 0;
          if (2 * cells <= static_cast<std::size_t>(config.canopyMaxTriangles) || stride >= maxStride) break;
     }
     stats.budgetLimited = stride > 1;
     // On a decimated metric terrain, snap the stride to a multiple of the
     // terrain's: with equal strides every canopy cell is a terrain cell with
     // the same diagonal, so the clearance between the two linear surfaces is
     // interpolated from the (positive) vertex clearances and the canopy can
     // never dip under a terrain crease.
     if (!flat && sampler.stride() > 1)
     {
          const int terrainStride = sampler.stride();
          stride = std::min(((stride + terrainStride - 1) / terrainStride) * terrainStride,
                            std::max(terrainStride, maxStride));
          stats.terrainAligned = true;
     }
     stats.stride = stride;
     stats.cellColumnMetres = stride * scale.columnSpacingMetres;
     stats.cellRowMetres = stride * scale.rowSpacingMetres;

     // Mask-normalised smoothing over DENSE pixels; the radius covers at
     // least half a cell so a single-pixel spike is never sampled alone.
     cv::Mat heightsTimesMask(height, width, CV_32F), maskFloat(height, width, CV_32F);
     for (int y = 0; y < height; ++y)
          for (int x = 0; x < width; ++x)
          {
               const std::size_t i = static_cast<std::size_t>(y) * width + x;
               const bool inside = dense.data[i] != 0;
               heightsTimesMask.at<float>(y, x) = inside ? input.heights->metricHeight.data[i] : 0.0f;
               maskFloat.at<float>(y, x) = inside ? 1.0f : 0.0f;
          }
     const double radius = std::max<double>(config.canopySmoothRadiusMetres,
                                            0.5 * stride * std::max(scale.columnSpacingMetres, scale.rowSpacingMetres));
     const int rx = static_cast<int>(std::lround(radius / scale.columnSpacingMetres));
     const int ry = static_cast<int>(std::lround(radius / scale.rowSpacingMetres));
     // Separate buffers: OpenCV filters in place when dst aliases src, and
     // maskFloat must stay a 0/1 mask for the rounding pass below.
     cv::Mat numerator = heightsTimesMask.clone(), denominator = maskFloat.clone();
     if (rx > 0 || ry > 0)
     {
          const cv::Size kernel(2 * rx + 1, 2 * ry + 1);
          cv::boxFilter(heightsTimesMask, numerator, CV_32F, kernel, cv::Point(-1, -1), false, cv::BORDER_CONSTANT);
          cv::boxFilter(maskFloat, denominator, CV_32F, kernel, cv::Point(-1, -1), false, cv::BORDER_CONSTANT);
     }
     cv::Mat edgeDistance;
     cv::distanceTransform(dense, edgeDistance, cv::DIST_L2, cv::DIST_MASK_PRECISE);

     // Display profile per DENSE pixel: the smoothed height, capped near any
     // mask edge by the slope limit; then rounded (mask-normalised) so the
     // cap's distance-field ridges become crown-like mounds, and capped again
     // so rounding can never steepen an edge.
     cv::Mat edgeLimit(height, width, CV_32F), profile(height, width, CV_32F);
     for (int y = 0; y < height; ++y)
          for (int x = 0; x < width; ++x)
          {
               const float limit = static_cast<float>(config.canopyLiftMetres +
                                                      edgeDistance.at<float>(y, x) * finerSpacing * config.canopyEdgeSlope);
               edgeLimit.at<float>(y, x) = limit;
               const float full = std::max(0.0f, numerator.at<float>(y, x) / std::max(denominator.at<float>(y, x), 1e-12f)) *
                                  stats.displayHeightScale;
               profile.at<float>(y, x) = dense.at<uint8_t>(y, x)
                   ? std::max(config.canopyLiftMetres, std::min(full, limit))
                   : 0.0f;
          }
     {
          const int roundX = static_cast<int>(std::lround(config.canopyCrownRoundingMetres / scale.columnSpacingMetres));
          const int roundY = static_cast<int>(std::lround(config.canopyCrownRoundingMetres / scale.rowSpacingMetres));
          if (roundX > 0 || roundY > 0)
          {
               const cv::Size kernel(2 * roundX + 1, 2 * roundY + 1);
               cv::Mat profileSum, weight;
               cv::boxFilter(profile, profileSum, CV_32F, kernel, cv::Point(-1, -1), false, cv::BORDER_CONSTANT);
               cv::boxFilter(maskFloat, weight, CV_32F, kernel, cv::Point(-1, -1), false, cv::BORDER_CONSTANT);
               for (int y = 0; y < height; ++y)
                    for (int x = 0; x < width; ++x)
                         if (dense.at<uint8_t>(y, x))
                              profile.at<float>(y, x) = std::max(
                                  config.canopyLiftMetres,
                                  std::min(profileSum.at<float>(y, x) / weight.at<float>(y, x), edgeLimit.at<float>(y, x)));
          }
     }

     // Cells, then islands.
     const int columns = (width - 1) / stride, rows = (height - 1) / stride;
     const int nodeColumns = columns + 1;
     std::vector<std::pair<int, int>> cells;
     for (int j = 0; j < rows; ++j)
          for (int i = 0; i < columns; ++i)
               if (cellValid(stride, i, j, true)) cells.emplace_back(i, j);
     const auto nodeId = [&](int i, int j) { return static_cast<uint32_t>(j * nodeColumns + i); };
     UnionFind islands(static_cast<std::size_t>(nodeColumns) * (rows + 1));
     for (const auto& [i, j] : cells)
     {
          islands.unite(nodeId(i, j), nodeId(i + 1, j));
          islands.unite(nodeId(i, j), nodeId(i, j + 1));
          islands.unite(nodeId(i, j), nodeId(i + 1, j + 1));
     }
     std::vector<std::size_t> islandTriangles(islands.parent.size(), 0);
     for (const auto& [i, j] : cells) islandTriangles[islands.find(nodeId(i, j))] += 2;

     // Vertices for nodes of kept cells, in node order (deterministic).
     MeshPrimitive& primitive = mesh.primitive;
     primitive.topology = PrimitiveTopology::TRIANGLES;
     primitive.materialRole = MaterialRole::VEGETATION_CANOPY;
     primitive.normals.emplace();
     primitive.uvs.emplace();
     std::vector<uint32_t> vertexOf(islands.parent.size(), std::numeric_limits<uint32_t>::max());
     std::vector<uint8_t> nodeUsed(islands.parent.size(), 0);
     for (const auto& [i, j] : cells)
     {
          if (islandTriangles[islands.find(nodeId(i, j))] < static_cast<std::size_t>(config.canopyMinIslandTriangles))
          {
               stats.removedIslandTriangles += 2;
               continue;
          }
          for (const auto& [ni, nj] : {std::pair{i, j}, std::pair{i + 1, j}, std::pair{i, j + 1}, std::pair{i + 1, j + 1}})
               nodeUsed[nodeId(ni, nj)] = 1;
     }
     stats.metricHeightMin = stats.displayHeightMin = std::numeric_limits<float>::max();
     stats.metricHeightMax = stats.displayHeightMax = std::numeric_limits<float>::lowest();
     AxisAlignedBounds& bounds = primitive.localBounds;
     bounds.isInitialized = true;
     bounds.minX = bounds.minY = bounds.minZ = std::numeric_limits<double>::max();
     bounds.maxX = bounds.maxY = bounds.maxZ = std::numeric_limits<double>::lowest();
     for (int nj = 0; nj <= rows; ++nj)
          for (int ni = 0; ni < nodeColumns; ++ni)
          {
               const uint32_t node = nodeId(ni, nj);
               if (!nodeUsed[node]) continue;
               const int column = ni * stride, row = nj * stride;
               const double pixelColumn = column + 0.5, pixelRow = row + 0.5;
               const float display = profile.at<float>(row, column);
               const float metric = display / stats.displayHeightScale;
               const float base = baseAt(column, row);
               const LocalPoint local = geo::pixelEdgeToLocal(metadata, frame, pixelColumn, pixelRow);
               const auto [u, v] = geo::pixelEdgeToUv(metadata, pixelColumn, pixelRow);
               const float x = static_cast<float>(local.x), y = base + display, z = static_cast<float>(local.z);
               vertexOf[node] = static_cast<uint32_t>(primitive.positions.size() / 3);
               primitive.positions.insert(primitive.positions.end(), {x, y, z});
               primitive.uvs->insert(primitive.uvs->end(), {u, v});
               bounds.expand(x, y, z);
               stats.metricHeightMin = std::min(stats.metricHeightMin, metric);
               stats.metricHeightMax = std::max(stats.metricHeightMax, metric);
               stats.displayHeightMin = std::min(stats.displayHeightMin, display);
               stats.displayHeightMax = std::max(stats.displayHeightMax, display);
          }
     for (const auto& [i, j] : cells)
     {
          if (islandTriangles[islands.find(nodeId(i, j))] < static_cast<std::size_t>(config.canopyMinIslandTriangles))
               continue;
          const uint32_t v0 = vertexOf[nodeId(i, j)], v1 = vertexOf[nodeId(i + 1, j)];
          const uint32_t v2 = vertexOf[nodeId(i, j + 1)], v3 = vertexOf[nodeId(i + 1, j + 1)];
          primitive.indices.insert(primitive.indices.end(), {v0, v2, v1, v1, v2, v3});
     }

     // Area-weighted vertex normals with TerrainMesher's cross-product order.
     std::vector<float>& normals = *primitive.normals;
     normals.assign(primitive.positions.size(), 0.0f);
     const auto& p = primitive.positions;
     for (std::size_t t = 0; t + 2 < primitive.indices.size(); t += 3)
     {
          const uint32_t i0 = primitive.indices[t], i1 = primitive.indices[t + 1], i2 = primitive.indices[t + 2];
          const float ux = p[i1 * 3] - p[i0 * 3], uy = p[i1 * 3 + 1] - p[i0 * 3 + 1], uz = p[i1 * 3 + 2] - p[i0 * 3 + 2];
          const float vx = p[i2 * 3] - p[i0 * 3], vy = p[i2 * 3 + 1] - p[i0 * 3 + 1], vz = p[i2 * 3 + 2] - p[i0 * 3 + 2];
          const float nx = uy * vz - uz * vy, ny = uz * vx - ux * vz, nz = ux * vy - uy * vx;
          for (const uint32_t vertex : {i0, i1, i2})
          {
               normals[vertex * 3] += nx;
               normals[vertex * 3 + 1] += ny;
               normals[vertex * 3 + 2] += nz;
          }
     }
     for (std::size_t i = 0; i < normals.size(); i += 3)
     {
          const float length = std::sqrt(normals[i] * normals[i] + normals[i + 1] * normals[i + 1] +
                                         normals[i + 2] * normals[i + 2]);
          if (length > 1e-8f)
          {
               normals[i] /= length;
               normals[i + 1] /= length;
               normals[i + 2] /= length;
          }
          else
          {
               normals[i] = 0.0f;
               normals[i + 1] = 1.0f;
               normals[i + 2] = 0.0f;
          }
     }
     stats.vertices = primitive.positions.size() / 3;
     stats.triangles = primitive.indices.size() / 3;
     if (stats.triangles == 0)
     {
          primitive = MeshPrimitive{};
          stats.metricHeightMin = stats.metricHeightMax = stats.displayHeightMin = stats.displayHeightMax = 0.0f;
          return finish("no dense cell survived the barrier, coverage and island rules");
     }
     return finish(nullptr);
}
