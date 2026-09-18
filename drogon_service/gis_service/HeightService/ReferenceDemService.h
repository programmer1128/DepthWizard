#pragma once
#include <string>
#include <vector>
#include <drogon/drogon.h>
#include "HeightExtractorService.h"

class ReferenceDemService {
public:
    static drogon::Task<std::vector<uint8_t>> fetchReference(
        const std::string& tag, 
        const GeoWindowContext& context,
        const drogon::HttpFile* uploadedFile = nullptr);
};