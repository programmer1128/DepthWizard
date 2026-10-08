#pragma once
#include <drogon/drogon.h>

#include <cstdint>
#include <stdexcept>
#include <string>
#include <vector>

// WGS84 bounding box sent to the reference DEM providers.
struct GeoBounds
{
     double minLon{0.0}, minLat{0.0}, maxLon{0.0}, maxLat{0.0};
};

// The reference provider failed or returned something that is not a DEM.
class ReferenceDemUnavailable : public std::runtime_error
{
     using std::runtime_error::runtime_error;
};

struct ReferenceDem
{
     std::vector<uint8_t> bytes; // GeoTIFF
     std::string dataset;        // e.g. "COP30"
};

class ReferenceDemService
{
     public:
     // tag: "opentopography" (Copernicus GLO-30), "bhuvan" (CartoDEM) or
     // "upload" (the caller's own GeoTIFF).
     static drogon::Task<ReferenceDem> fetchReference(
         const std::string& tag,
         const GeoBounds& bounds,
         const drogon::HttpFile* uploadedFile = nullptr);
};
