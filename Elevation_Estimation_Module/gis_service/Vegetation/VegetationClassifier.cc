#include "VegetationClassifier.h"
#include "VegetationMorphology.h"

#include <opencv2/imgproc.hpp>

#include <algorithm>
#include <vector>

using depthwizard::vegetation::metricEllipse;

namespace
{
std::size_t componentCount(const cv::Mat& binary)
{
     cv::Mat labels;
     return static_cast<std::size_t>(cv::connectedComponents(binary, labels, 8, CV_32S) - 1);
}
} // namespace

VegetationClassification VegetationClassifier::classify(const VegetationMask& mask, const VegetationConfig& config)
{
     VegetationClassification result;
     if (!mask.inputsAvailable) return result;
     const int width = mask.tier.width;
     const int height = mask.tier.height;
     const std::size_t total = static_cast<std::size_t>(width) * height;
     result.classes.width = width;
     result.classes.height = height;
     result.classes.data.assign(total, static_cast<uint8_t>(VegetationClass::NONE));
     VegetationClassificationStats& stats = result.stats;

     const VegetationPixelScale& scale = mask.scale;
     stats.groundResolutionMetres = std::max(scale.columnSpacingMetres, scale.rowSpacingMetres);
     stats.individualTreesResolvable = stats.groundResolutionMetres <= config.individualTreeMaxGsdMetres;

     cv::Mat vegetation(height, width, CV_8U);
     for (std::size_t i = 0; i < total; ++i)
          vegetation.data[i] = mask.tier.data[i] != static_cast<uint8_t>(VegetationTier::NONE) ? 1 : 0;
     const auto supported = [&](std::size_t i)
     {
          const auto tier = static_cast<VegetationTier>(mask.tier.data[i]);
          return tier == VegetationTier::CONFIRMED || tier == VegetationTier::RECOVERED_UNKNOWN;
     };

     cv::Mat dense;
     if (!stats.individualTreesResolvable)
     {
          // Crowns are not resolvable: all vegetation is canopy.
          dense = vegetation.clone();
     }
     else
     {
          // Local coverage over a metric window; outside the image counts as bare.
          const int rx = std::max(1, static_cast<int>(std::lround(config.denseCoverageRadiusMetres / scale.columnSpacingMetres)));
          const int ry = std::max(1, static_cast<int>(std::lround(config.denseCoverageRadiusMetres / scale.rowSpacingMetres)));
          cv::Mat coverage;
          cv::boxFilter(vegetation, coverage, CV_32F, cv::Size(2 * rx + 1, 2 * ry + 1), cv::Point(-1, -1), true,
                        cv::BORDER_CONSTANT);
          cv::Mat core = cv::Mat::zeros(height, width, CV_8U);
          for (int y = 0; y < height; ++y)
               for (int x = 0; x < width; ++x)
               {
                    const std::size_t i = static_cast<std::size_t>(y) * width + x;
                    if (vegetation.data[i] && coverage.at<float>(y, x) >= config.denseLocalCoverage - 1e-6f)
                         core.data[i] = 1;
               }

          cv::Mat distance;
          cv::distanceTransform(core, distance, cv::DIST_L2, cv::DIST_MASK_PRECISE);
          cv::Mat coreLabels, coreStats, centroids;
          const int cores = cv::connectedComponentsWithStats(core, coreLabels, coreStats, centroids, 8, CV_32S);
          std::vector<float> maxDistance(static_cast<std::size_t>(cores), 0.0f);
          std::vector<std::size_t> supportedPixels(static_cast<std::size_t>(cores), 0);
          for (int y = 0; y < height; ++y)
               for (int x = 0; x < width; ++x)
               {
                    const int label = coreLabels.at<int>(y, x);
                    if (label == 0) continue;
                    maxDistance[static_cast<std::size_t>(label)] =
                        std::max(maxDistance[static_cast<std::size_t>(label)], distance.at<float>(y, x));
                    if (supported(static_cast<std::size_t>(y) * width + x)) ++supportedPixels[static_cast<std::size_t>(label)];
               }
          const double finerSpacing = std::min(scale.columnSpacingMetres, scale.rowSpacingMetres);
          std::vector<uint8_t> seed(static_cast<std::size_t>(cores), 0);
          for (int label = 1; label < cores; ++label)
          {
               const auto area = static_cast<std::size_t>(coreStats.at<int>(label, cv::CC_STAT_AREA));
               const double areaSquareMetres = static_cast<double>(area) * scale.pixelAreaSquareMetres();
               const double widthMetres = 2.0 * maxDistance[static_cast<std::size_t>(label)] * finerSpacing;
               const bool heightSupported = 2 * supportedPixels[static_cast<std::size_t>(label)] >= area;
               if (areaSquareMetres >= config.denseMinAreaSquareMetres && widthMetres >= config.denseMinWidthMetres &&
                   heightSupported)
               {
                    seed[static_cast<std::size_t>(label)] = 1;
                    ++stats.denseSeeds;
               }
               else
                    ++stats.rejectedCores;
          }
          cv::Mat seeds = cv::Mat::zeros(height, width, CV_8U);
          for (int y = 0; y < height; ++y)
               for (int x = 0; x < width; ++x)
                    if (seed[static_cast<std::size_t>(coreLabels.at<int>(y, x))]) seeds.at<uint8_t>(y, x) = 1;

          // Dense = mask pixels of a seed's own connected region, within the
          // fringe distance of the seed.
          cv::Mat regionLabels;
          const int regions = cv::connectedComponents(vegetation, regionLabels, 8, CV_32S);
          std::vector<uint8_t> seededRegion(static_cast<std::size_t>(regions), 0);
          for (int y = 0; y < height; ++y)
               for (int x = 0; x < width; ++x)
                    if (seeds.at<uint8_t>(y, x)) seededRegion[static_cast<std::size_t>(regionLabels.at<int>(y, x))] = 1;
          cv::Mat fringe = seeds.clone();
          if (const cv::Mat kernel = metricEllipse(config.denseFringeMetres, scale); !kernel.empty())
               cv::dilate(seeds, fringe, kernel);
          dense = cv::Mat::zeros(height, width, CV_8U);
          for (int y = 0; y < height; ++y)
               for (int x = 0; x < width; ++x)
                    if (vegetation.at<uint8_t>(y, x) && fringe.at<uint8_t>(y, x) &&
                        seededRegion[static_cast<std::size_t>(regionLabels.at<int>(y, x))])
                         dense.at<uint8_t>(y, x) = 1;
     }

     cv::Mat isolated = cv::Mat::zeros(height, width, CV_8U);
     for (std::size_t i = 0; i < total; ++i)
     {
          if (!vegetation.data[i]) continue;
          const auto tier = static_cast<VegetationTier>(mask.tier.data[i]);
          const bool isDense = dense.data[i] != 0;
          result.classes.data[i] = static_cast<uint8_t>(isDense ? VegetationClass::DENSE : VegetationClass::ISOLATED);
          if (!isDense) isolated.data[i] = 1;
          std::size_t& confirmed = isDense ? stats.denseConfirmed : stats.isolatedConfirmed;
          std::size_t& recovered = isDense ? stats.denseRecovered : stats.isolatedRecovered;
          std::size_t& gap = isDense ? stats.denseGap : stats.isolatedGap;
          (tier == VegetationTier::CONFIRMED ? confirmed : tier == VegetationTier::RECOVERED_UNKNOWN ? recovered : gap)++;
          ++(isDense ? stats.densePixels : stats.isolatedPixels);
     }
     stats.denseComponents = componentCount(dense);
     stats.isolatedComponents = componentCount(isolated);
     return result;
}
