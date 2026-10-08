#include "GlobalMapController.h"

#include <cpl_conv.h>
#include <cpl_http.h>
#include <cpl_vsi.h>
#include <gdal_priv.h>
#include <gdal_utils.h>
#include <ogr_spatialref.h>
#include <json/json.h>
#include <trantor/utils/ConcurrentTaskQueue.h>

#include <algorithm>
#include <chrono>
#include <cmath>
#include <ctime>
#include <memory>
#include <set>
#include <sstream>
#include <stdexcept>

namespace
{
struct GlobalMapError : std::runtime_error
{
     drogon::HttpStatusCode status;
     GlobalMapError(drogon::HttpStatusCode code, const std::string& message) : std::runtime_error(message), status(code) {}
};

std::string setting(const char* name, const std::string& fallback)
{
     const char* value = std::getenv(name);
     return value && *value ? std::string(value) : fallback;
}

struct Scene
{
     std::string id, date, href;
     double cloud{0.0};
     double bbox[4]{0, 0, 0, 0};
};

// Earth Search (STAC) query: Sentinel-2 L2A over the box, least cloudy first,
// then most recent.
std::vector<Scene> searchScenes(const double bbox[4], double maxCloud, int maxAgeDays)
{
     Json::Value body(Json::objectValue);
     body["collections"].append("sentinel-2-l2a");
     for (int k = 0; k < 4; ++k) body["bbox"].append(bbox[k]);
     body["limit"] = 30;
     body["query"]["eo:cloud_cover"]["lte"] = maxCloud;
     Json::Value byCloud, byDate;
     byCloud["field"] = "properties.eo:cloud_cover";
     byCloud["direction"] = "asc";
     byDate["field"] = "properties.datetime";
     byDate["direction"] = "desc";
     body["sortby"].append(byCloud);
     body["sortby"].append(byDate);
     if (maxAgeDays > 0)
     {
          const std::time_t since = std::time(nullptr) - static_cast<std::time_t>(maxAgeDays) * 86400;
          char start[32];
          std::strftime(start, sizeof(start), "%Y-%m-%dT00:00:00Z", std::gmtime(&since));
          body["datetime"] = std::string(start) + "/..";
     }
     Json::StreamWriterBuilder writer;
     writer["indentation"] = "";
     const std::string post = "POSTFIELDS=" + Json::writeString(writer, body);
     const char* options[] = {post.c_str(), "HEADERS=Content-Type: application/json", "TIMEOUT=45", "MAX_RETRY=2", nullptr};
     const std::string url = setting("DEPTHWIZARD_GLOBAL_MAP_STAC_URL", "https://earth-search.aws.element84.com/v1/search");
     std::unique_ptr<CPLHTTPResult, decltype(&CPLHTTPDestroyResult)> result(CPLHTTPFetch(url.c_str(), options), &CPLHTTPDestroyResult);
     if (!result || result->nStatus != 0 || !result->pabyData)
          throw GlobalMapError(drogon::k502BadGateway, "The Sentinel-2 catalogue could not be reached" +
                               std::string(result && result->pszErrBuf ? std::string(": ") + result->pszErrBuf : "."));
     Json::Value response;
     Json::CharReaderBuilder reader;
     std::string errors;
     const std::string text(reinterpret_cast<const char*>(result->pabyData), static_cast<std::size_t>(result->nDataLen));
     std::istringstream stream(text);
     if (!Json::parseFromStream(reader, stream, &response, &errors) || !response.isMember("features"))
          throw GlobalMapError(drogon::k502BadGateway, "The Sentinel-2 catalogue returned an unexpected answer.");
     std::vector<Scene> scenes;
     for (const Json::Value& feature : response["features"])
     {
          const Json::Value& visual = feature["assets"]["visual"];
          if (!visual.isMember("href")) continue;
          Scene scene;
          scene.id = feature["id"].asString();
          scene.date = feature["properties"]["datetime"].asString().substr(0, 10);
          scene.cloud = feature["properties"]["eo:cloud_cover"].asDouble();
          scene.href = visual["href"].asString();
          if (feature["bbox"].size() == 4)
               for (Json::ArrayIndex k = 0; k < 4; ++k) scene.bbox[k] = feature["bbox"][k].asDouble();
          scenes.push_back(scene);
     }
     return scenes;
}

// Least-cloudy scenes until the box is covered (by the scenes' own bounding
// boxes, sampled on a 10 x 10 grid), at most maxScenes.
std::vector<Scene> chooseScenes(const std::vector<Scene>& scenes, const double bbox[4], int maxScenes)
{
     std::vector<Scene> chosen;
     std::vector<bool> covered(100, false);
     for (const Scene& scene : scenes)
     {
          if (static_cast<int>(chosen.size()) >= maxScenes) break;
          bool adds = false;
          for (int i = 0; i < 100; ++i)
          {
               const double lon = bbox[0] + (bbox[2] - bbox[0]) * ((i % 10) + 0.5) / 10.0;
               const double lat = bbox[1] + (bbox[3] - bbox[1]) * ((i / 10) + 0.5) / 10.0;
               if (!covered[static_cast<std::size_t>(i)] && lon >= scene.bbox[0] && lon <= scene.bbox[2] &&
                   lat >= scene.bbox[1] && lat <= scene.bbox[3])
               {
                    covered[static_cast<std::size_t>(i)] = true;
                    adds = true;
               }
          }
          if (adds) chosen.push_back(scene);
          if (std::all_of(covered.begin(), covered.end(), [](bool c) { return c; })) break;
     }
     return chosen;
}

struct GeoTiff
{
     std::vector<uint8_t> bytes;
     std::string provider, dates, attribution;
};

GeoTiff buildGeoTiff(const Json::Value& request)
{
     const Json::Value& box = request["bbox"];
     if (!box.isArray() || box.size() != 4)
          throw GlobalMapError(drogon::k400BadRequest, "bbox must be [west, south, east, north] in degrees.");
     double bbox[4];
     for (Json::ArrayIndex k = 0; k < 4; ++k)
     {
          if (!box[k].isNumeric()) throw GlobalMapError(drogon::k400BadRequest, "bbox values must be numbers.");
          bbox[k] = box[k].asDouble();
          if (!std::isfinite(bbox[k])) throw GlobalMapError(drogon::k400BadRequest, "bbox values must be finite.");
     }
     if (bbox[0] < -180 || bbox[2] > 180 || bbox[1] < -84 || bbox[3] > 84 || bbox[0] >= bbox[2] || bbox[1] >= bbox[3])
          throw GlobalMapError(drogon::k400BadRequest, "bbox must satisfy -180 <= west < east <= 180 and -84 <= south < north <= 84.");
     if (bbox[2] - bbox[0] > 5.0 || bbox[3] - bbox[1] > 5.0)
          throw GlobalMapError(drogon::k400BadRequest, "The selected area is too large (at most about 500 km per side).");
     const int requestedWidth = std::clamp(request.get("width", 1024).asInt(), 256, 2048);
     const int requestedHeight = std::clamp(request.get("height", 1024).asInt(), 256, 2048);
     const double maxCloud = std::clamp(request.get("maxCloudCoverage", 20.0).asDouble(), 0.0, 100.0);
     const int maxScenes = std::clamp(std::atoi(setting("DEPTHWIZARD_GLOBAL_MAP_MAX_SCENES", "6").c_str()), 1, 20);
     const int maxAgeDays = std::max(0, std::atoi(setting("DEPTHWIZARD_GLOBAL_MAP_MAX_AGE_DAYS", "730").c_str()));

     std::vector<Scene> scenes = searchScenes(bbox, maxCloud, maxAgeDays);
     if (scenes.empty() && maxAgeDays > 0) scenes = searchScenes(bbox, maxCloud, 0);   // Any date
     if (scenes.empty())
          throw GlobalMapError(drogon::k404NotFound, "No Sentinel-2 scene with at most " + std::to_string(static_cast<int>(maxCloud)) +
                               "% cloud cover was found for this area. Try a higher cloud limit.");
     std::vector<Scene> chosen = chooseScenes(scenes, bbox, maxScenes);

     // Target grid: UTM zone of the box centre, square pixels, the longer side
     // at the requested resolution.
     const double centreLon = 0.5 * (bbox[0] + bbox[2]), centreLat = 0.5 * (bbox[1] + bbox[3]);
     const int zone = std::clamp(static_cast<int>(std::floor((centreLon + 180.0) / 6.0)) + 1, 1, 60);
     const int epsg = (centreLat >= 0 ? 32600 : 32700) + zone;
     OGRSpatialReference wgs84, utm;
     wgs84.importFromEPSG(4326);
     wgs84.SetAxisMappingStrategy(OAMS_TRADITIONAL_GIS_ORDER);
     utm.importFromEPSG(epsg);
     utm.SetAxisMappingStrategy(OAMS_TRADITIONAL_GIS_ORDER);
     std::unique_ptr<OGRCoordinateTransformation> toUtm(OGRCreateCoordinateTransformation(&wgs84, &utm));
     if (!toUtm) throw GlobalMapError(drogon::k500InternalServerError, "Cannot build the UTM transformation.");
     double minX = 1e300, minY = 1e300, maxX = -1e300, maxY = -1e300;
     for (int i = 0; i <= 8; ++i)
          for (int j = 0; j <= 8; ++j)
          {
               double x = bbox[0] + (bbox[2] - bbox[0]) * i / 8.0, y = bbox[1] + (bbox[3] - bbox[1]) * j / 8.0;
               if (!toUtm->Transform(1, &x, &y)) continue;
               minX = std::min(minX, x); maxX = std::max(maxX, x);
               minY = std::min(minY, y); maxY = std::max(maxY, y);
          }
     const double pixel = std::max(maxX - minX, maxY - minY) / std::max(requestedWidth, requestedHeight);
     const int width = std::max(1, static_cast<int>(std::lround((maxX - minX) / pixel)));
     const int height = std::max(1, static_cast<int>(std::lround((maxY - minY) / pixel)));

     // Warp the chosen true-colour COGs; the least cloudy is drawn last (on top).
     CPLSetThreadLocalConfigOption("GDAL_DISABLE_READDIR_ON_OPEN", "EMPTY_DIR");
     CPLSetThreadLocalConfigOption("CPL_VSIL_CURL_ALLOWED_EXTENSIONS", ".tif");
     CPLSetThreadLocalConfigOption("GDAL_HTTP_TIMEOUT", "60");
     CPLSetThreadLocalConfigOption("GDAL_HTTP_MAX_RETRY", "3");
     CPLSetThreadLocalConfigOption("GDAL_HTTP_RETRY_DELAY", "2");
     std::vector<GDALDatasetH> sources;
     std::set<std::string> dates;
     for (auto it = chosen.rbegin(); it != chosen.rend(); ++it)
     {
          GDALDatasetH source = GDALOpen(("/vsicurl/" + it->href).c_str(), GA_ReadOnly);
          if (source) { sources.push_back(source); dates.insert(it->date); }
     }
     if (sources.empty()) throw GlobalMapError(drogon::k502BadGateway, "The Sentinel-2 imagery could not be read.");
     const std::string output = "/vsimem/global_map_" + std::to_string(std::chrono::steady_clock::now().time_since_epoch().count()) + ".tif";
     const std::vector<std::string> args{
         "-t_srs", "EPSG:" + std::to_string(epsg), "-te", std::to_string(minX), std::to_string(minY), std::to_string(maxX),
         std::to_string(maxY), "-ts", std::to_string(width), std::to_string(height), "-r", "bilinear", "-srcnodata", "0",
         "-dstnodata", "0", "-of", "GTiff", "-co", "COMPRESS=DEFLATE", "-co", "PHOTOMETRIC=RGB"};
     std::vector<char*> argv;
     for (const std::string& a : args) argv.push_back(const_cast<char*>(a.c_str()));
     argv.push_back(nullptr);
     GDALWarpAppOptions* options = GDALWarpAppOptionsNew(argv.data(), nullptr);
     int usageError = 0;
     GDALDatasetH warped = GDALWarp(output.c_str(), nullptr, static_cast<int>(sources.size()), sources.data(), options, &usageError);
     GDALWarpAppOptionsFree(options);
     for (GDALDatasetH source : sources) GDALClose(source);
     if (!warped) throw GlobalMapError(drogon::k502BadGateway, "Building the GeoTIFF from Sentinel-2 failed.");
     GDALClose(warped);
     vsi_l_offset length = 0;
     GByte* buffer = VSIGetMemFileBuffer(output.c_str(), &length, FALSE);
     GeoTiff result;
     if (buffer) result.bytes.assign(buffer, buffer + length);
     VSIUnlink(output.c_str());
     if (result.bytes.empty()) throw GlobalMapError(drogon::k500InternalServerError, "The generated GeoTIFF is empty.");
     result.provider = "Sentinel-2 L2A (Copernicus) via Earth Search / AWS Open Data";
     for (const std::string& d : dates) result.dates += (result.dates.empty() ? "" : ",") + d;
     result.attribution = "Contains modified Copernicus Sentinel data " + (dates.empty() ? std::string() : dates.rbegin()->substr(0, 4));
     LOG_INFO << "GlobalMap: bbox [" << bbox[0] << ", " << bbox[1] << ", " << bbox[2] << ", " << bbox[3] << "] -> EPSG:" << epsg
              << " " << width << "x" << height << " px (" << pixel << " m/px) from " << sources.size() << " scene(s) "
              << result.dates << ", " << result.bytes.size() << " bytes";
     return result;
}

trantor::ConcurrentTaskQueue& workers()
{
     static trantor::ConcurrentTaskQueue queue(2, "global-map");
     return queue;
}
} // namespace

void GlobalMapController::geotiff(const drogon::HttpRequestPtr& request,
                                  std::function<void(const drogon::HttpResponsePtr&)>&& callback)
{
     const auto json = request->getJsonObject();
     if (!json)
     {
          Json::Value error;
          error["message"] = "Expected a JSON body with bbox, width, height and maxCloudCoverage.";
          auto response = drogon::HttpResponse::newHttpJsonResponse(error);
          response->setStatusCode(drogon::k400BadRequest);
          callback(response);
          return;
     }
     // Network reads and warping take seconds: off the event loop.
     workers().runTaskInQueue([body = *json, callback = std::move(callback)]() {
          try
          {
               GeoTiff tiff = buildGeoTiff(body);
               auto response = drogon::HttpResponse::newHttpResponse();
               response->setStatusCode(drogon::k200OK);
               response->setContentTypeString("image/tiff");
               response->addHeader("Content-Disposition", "attachment; filename=\"global-map.tif\"");
               response->addHeader("X-Imagery-Provider", tiff.provider);
               response->addHeader("X-Imagery-Date", tiff.dates);
               response->addHeader("X-Imagery-Attribution", tiff.attribution);
               response->setBody(std::string(tiff.bytes.begin(), tiff.bytes.end()));
               callback(response);
          }
          catch (const GlobalMapError& error)
          {
               Json::Value body;
               body["message"] = error.what();
               auto response = drogon::HttpResponse::newHttpJsonResponse(body);
               response->setStatusCode(error.status);
               callback(response);
          }
          catch (const std::exception& error)
          {
               Json::Value body;
               body["message"] = std::string("Global map imagery failed: ") + error.what();
               auto response = drogon::HttpResponse::newHttpJsonResponse(body);
               response->setStatusCode(drogon::k500InternalServerError);
               callback(response);
          }
     });
}
