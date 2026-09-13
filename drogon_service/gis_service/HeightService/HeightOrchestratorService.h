#pragma once
#include <string>
#include <drogon/drogon.h>
#include <json/json.h>

class HeightOrchestratorService {
public:
    // Orchestrates the single height extraction
    static drogon::Task<Json::Value> processSingleHeight(const std::string& uuid, float x, float y);

    // Orchestrates the dual-TIF extraction and passes to ComparatorService
    static drogon::Task<Json::Value> processComparison(
        const std::string& uuid, 
        const std::string& tag, 
        float x, 
        float y, 
        const drogon::HttpFile* uploadedFile);
};