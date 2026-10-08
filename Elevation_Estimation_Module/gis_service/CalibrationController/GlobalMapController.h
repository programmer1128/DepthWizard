#pragma once
#include <drogon/HttpController.h>

// POST /api/v1/global-map/geotiff
//   {"bbox": [west, south, east, north] (WGS84 degrees), "width": 256..2048,
//    "height": 256..2048, "maxCloudCoverage": 0..100}
// -> image/tiff: an RGB GeoTIFF of the box (WGS 84 / UTM zone of its centre),
//    built from the least-cloudy recent Sentinel-2 L2A true-colour scenes.
//    The frontend then submits it to /api/v1/processor like any upload.
//
// Imagery: Copernicus Sentinel-2 (open licence) from the public Element84
// Earth Search catalogue and the AWS open-data bucket. No credentials.
// Settings: DEPTHWIZARD_GLOBAL_MAP_STAC_URL, DEPTHWIZARD_GLOBAL_MAP_MAX_SCENES,
// DEPTHWIZARD_GLOBAL_MAP_MAX_AGE_DAYS.
class GlobalMapController : public drogon::HttpController<GlobalMapController>
{
public:
     METHOD_LIST_BEGIN
     ADD_METHOD_TO(GlobalMapController::geotiff, "/api/v1/global-map/geotiff", drogon::Post);
     METHOD_LIST_END

     void geotiff(const drogon::HttpRequestPtr& request,
                  std::function<void(const drogon::HttpResponsePtr&)>&& callback);
};
