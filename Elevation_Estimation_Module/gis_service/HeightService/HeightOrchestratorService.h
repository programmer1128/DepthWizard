#pragma once
#include <drogon/drogon.h>
#include <json/json.h>

#include <cstdint>
#include <optional>
#include <string>

class HeightOrchestratorService
{
     public:
     // x, y: metres east and south of the scene's north-west corner.
     // featureId: the building ID from the clicked GLB primitive, if any.
     // A building answers with that building's height only; terrain answers
     // with the absolute elevation at the point.
     static drogon::Task<Json::Value> processSingleHeight(
         const std::string& uuid, double x, double y, std::optional<uint32_t> featureId);

     // Scene-wide accuracy of the generated DSM against a reference DEM, plus
     // both elevations at (x, y).
     static drogon::Task<Json::Value> processComparison(
         const std::string& uuid, const std::string& tag, double x, double y,
         const drogon::HttpFile* uploadedFile);
};
