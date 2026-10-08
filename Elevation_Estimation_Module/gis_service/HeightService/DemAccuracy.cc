#include "DemAccuracy.h"

#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

#include <algorithm>
#include <cmath>
#include <stdexcept>

namespace
{
void requireSameGrid(const RasterGrid<float>& generated, const RasterGrid<float>& reference)
{
     if (!generated.isValid() || !reference.isValid() ||
         generated.width != reference.width || generated.height != reference.height)
         throw std::invalid_argument("DemAccuracy: generated and reference grids differ");
}

// Indices of pixels that are finite in both grids and outside the border.
std::vector<std::size_t> comparablePixels(const RasterGrid<float>& generated,
                                          const RasterGrid<float>& reference,
                                          int edge)
{
     std::vector<std::size_t> pixels;
     for (int row = edge; row < generated.height - edge; ++row)
         for (int column = edge; column < generated.width - edge; ++column)
         {
             const std::size_t index = static_cast<std::size_t>(row) * generated.width + column;
             if (std::isfinite(generated.data[index]) && std::isfinite(reference.data[index]))
                 pixels.push_back(index);
         }
     return pixels;
}

DemErrorStatistics statistics(const RasterGrid<float>& generated,
                              const RasterGrid<float>& reference,
                              const std::vector<std::size_t>& pixels,
                              double tolerance)
{
     DemErrorStatistics result;
     result.pixelCount = pixels.size();
     if (pixels.empty()) return result;

     double sumAbs = 0.0, sumSquared = 0.0;
     double sumG = 0.0, sumR = 0.0, sumGG = 0.0, sumRR = 0.0, sumGR = 0.0;
     uint64_t within = 0;
     std::vector<double> absolute;
     absolute.reserve(pixels.size());
     for (const std::size_t index : pixels)
     {
         const double g = generated.data[index];
         const double r = reference.data[index];
         const double error = g - r;
         sumAbs += std::abs(error);
         sumSquared += error * error;
         within += std::abs(error) <= tolerance;
         absolute.push_back(std::abs(error));
         sumG += g; sumR += r; sumGG += g * g; sumRR += r * r; sumGR += g * r;
     }
     const double n = static_cast<double>(pixels.size());
     result.mae = sumAbs / n;
     result.rmse = std::sqrt(sumSquared / n);
     result.withinTolerancePercent = 100.0 * static_cast<double>(within) / n;

     // numpy.median: mean of the two middle values for an even count.
     const std::size_t middle = absolute.size() / 2;
     std::nth_element(absolute.begin(), absolute.begin() + middle, absolute.end());
     result.medianAbsoluteError = absolute[middle];
     if (absolute.size() % 2 == 0)
     {
         const double lower = *std::max_element(absolute.begin(), absolute.begin() + middle);
         result.medianAbsoluteError = 0.5 * (lower + absolute[middle]);
     }

     // Pearson over centred sums to limit cancellation at large elevations.
     const double covariance = sumGR - sumG * sumR / n;
     const double varianceG = sumGG - sumG * sumG / n;
     const double varianceR = sumRR - sumR * sumR / n;
     if (varianceG > 0.0 && varianceR > 0.0)
         result.pearson = covariance / std::sqrt(varianceG * varianceR);
     return result;
}
} // namespace

DemAccuracyReport DemAccuracy::evaluate(const RasterGrid<float>& generated,
                                        const RasterGrid<float>& reference,
                                        const DemAccuracyOptions& options)
{
     requireSameGrid(generated, reference);
     const std::vector<std::size_t> valid =
         comparablePixels(generated, reference, options.edgeBufferPixels);
     if (valid.empty())
         throw std::runtime_error("DemAccuracy: no overlapping valid pixels to compare");

     DemAccuracyReport report;
     report.generatedMin = report.generatedMax = generated.data[valid.front()];
     report.referenceMin = report.referenceMax = reference.data[valid.front()];
     std::vector<std::size_t> cleaned;
     cleaned.reserve(valid.size());
     for (const std::size_t index : valid)
     {
         const double g = generated.data[index];
         const double r = reference.data[index];
         report.generatedMin = std::min(report.generatedMin, g);
         report.generatedMax = std::max(report.generatedMax, g);
         report.referenceMin = std::min(report.referenceMin, r);
         report.referenceMax = std::max(report.referenceMax, r);
         const double absolute = std::abs(g - r);
         report.maxAbsoluteError = std::max(report.maxAbsoluteError, absolute);
         if (absolute > options.anomalyThresholdMeters)
             ++report.anomalyPixelCount;
         else
             cleaned.push_back(index);
     }
     report.anomalyPercent =
         100.0 * static_cast<double>(report.anomalyPixelCount) / static_cast<double>(valid.size());
     report.raw = statistics(generated, reference, valid, options.toleranceMeters);
     report.cleaned = statistics(generated, reference, cleaned, options.toleranceMeters);
     return report;
}

double DemAccuracy::suggestedDifferenceRange(const RasterGrid<float>& generated,
                                             const RasterGrid<float>& reference,
                                             const DemAccuracyOptions& options)
{
     requireSameGrid(generated, reference);
     std::vector<double> absolute;
     for (const std::size_t index : comparablePixels(generated, reference, options.edgeBufferPixels))
     {
         const double error = std::abs(static_cast<double>(generated.data[index]) - reference.data[index]);
         if (error <= options.anomalyThresholdMeters) absolute.push_back(error);
     }
     if (absolute.empty()) return 2.0;
     const std::size_t rank = static_cast<std::size_t>(0.95 * static_cast<double>(absolute.size() - 1));
     std::nth_element(absolute.begin(), absolute.begin() + rank, absolute.end());
     return std::max(2.0, std::ceil(absolute[rank]));
}

std::vector<uint8_t> DemAccuracy::renderDifferencePng(const RasterGrid<float>& generated,
                                                      const RasterGrid<float>& reference,
                                                      double rangeMeters,
                                                      int maxDimension)
{
     requireSameGrid(generated, reference);
     if (!(rangeMeters > 0.0)) rangeMeters = 1.0;

     cv::Mat image(generated.height, generated.width, CV_8UC4, cv::Scalar(0, 0, 0, 0));
     for (int row = 0; row < generated.height; ++row)
     {
         auto* pixel = image.ptr<cv::Vec4b>(row);
         for (int column = 0; column < generated.width; ++column)
         {
             const std::size_t index = static_cast<std::size_t>(row) * generated.width + column;
             const float g = generated.data[index];
             const float r = reference.data[index];
             if (!std::isfinite(g) || !std::isfinite(r)) continue;
             const double t = std::clamp((g - r) / rangeMeters, -1.0, 1.0);
             // White at zero, saturating to red (+) or blue (-). OpenCV is BGRA.
             const auto fade = static_cast<uint8_t>(std::lround(255.0 * (1.0 - std::abs(t))));
             pixel[column] = t >= 0.0 ? cv::Vec4b(fade, fade, 255, 255)
                                      : cv::Vec4b(255, fade, fade, 255);
         }
     }
     const int longest = std::max(image.cols, image.rows);
     if (maxDimension > 0 && longest > maxDimension)
     {
         const double scale = static_cast<double>(maxDimension) / longest;
         cv::resize(image, image, cv::Size(), scale, scale, cv::INTER_NEAREST);
     }
     std::vector<uint8_t> png;
     if (!cv::imencode(".png", image, png))
         throw std::runtime_error("DemAccuracy: PNG encoding failed");
     return png;
}
