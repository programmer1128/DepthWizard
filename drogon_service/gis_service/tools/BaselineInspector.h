#pragma once
#include <json/value.h>

#include <cstdint>
#include <string>
#include <vector>

// Deterministic, machine-readable descriptions of pipeline outputs for the
// hybrid-rendering baseline harness (tools/baseline). Two runs that produce
// the same geometry or the same scientific values produce identical reports,
// so a diff of reports shows exactly what a change affected.
class BaselineInspector
{
public:
    // Decodes every primitive, Draco-compressed or not: per-primitive counts,
    // bounds, attributes, building IDs (_FEATURE_ID_0) and material/texture
    // bindings, plus scene totals and asset metadata.
    static Json::Value inspectGlb(const std::vector<uint8_t>& bytes);
    static Json::Value inspectGlbFile(const std::string& path);

    // Size, geotransform, CRS digest and, per band, a digest of the pixel
    // values (NaN payloads and -0.0 canonicalised) with summary statistics.
    static Json::Value inspectRaster(const std::string& path);
};
