#pragma once
#include "../structures/CommonTypes.h"

#include <cstdint>
#include <optional>
#include <vector>

struct DemAccuracyOptions
{
     int edgeBufferPixels{10};        // shaved off every border (reprojection artefacts)
     double anomalyThresholdMeters{50.0};
     double toleranceMeters{2.0};
};

struct DemErrorStatistics
{
     uint64_t pixelCount{0};
     double mae{0.0};
     double rmse{0.0};
     std::optional<double> pearson;   // empty when either surface is flat
     double medianAbsoluteError{0.0};
     double withinTolerancePercent{0.0};
};

// Generated-vs-reference DEM accuracy, following the validation script:
// valid pixels are finite in both rasters and outside the edge buffer;
// errors beyond the anomaly threshold are counted, then excluded from the
// "cleaned" statistics. Raw statistics over all valid pixels are kept so
// the exclusion is always visible.
struct DemAccuracyReport
{
     DemErrorStatistics cleaned;
     DemErrorStatistics raw;
     uint64_t anomalyPixelCount{0};
     double anomalyPercent{0.0};
     double generatedMin{0.0}, generatedMax{0.0};
     double referenceMin{0.0}, referenceMax{0.0};
     double maxAbsoluteError{0.0};
};

class DemAccuracy
{
     public:
     // Both grids share one pixel grid (reference already warped onto the
     // generated grid). Throws when no pixel is comparable.
     static DemAccuracyReport evaluate(const RasterGrid<float>& generated,
                                       const RasterGrid<float>& reference,
                                       const DemAccuracyOptions& options = {});

     // Diverging colour map of (generated - reference): blue where the model
     // is lower, white near zero, red where higher; invalid pixels are
     // transparent. Saturates at +/- rangeMeters. Returns PNG bytes.
     static std::vector<uint8_t> renderDifferencePng(const RasterGrid<float>& generated,
                                                     const RasterGrid<float>& reference,
                                                     double rangeMeters,
                                                     int maxDimension = 1024);

     // A symmetric colour range covering 95% of the cleaned errors.
     static double suggestedDifferenceRange(const RasterGrid<float>& generated,
                                            const RasterGrid<float>& reference,
                                            const DemAccuracyOptions& options = {});
};
