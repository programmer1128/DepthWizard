#include "HeightOrchestratorService.h"
#include "HeightExtractorService.h"
#include "ReferenceDemService.h"
#include "CompareService.h" // The new service integration
#include <drogon/utils/Utilities.h>
#include <gdal_priv.h>
#include <cpl_vsi.h>
#include <stdexcept>
#include <cmath>

drogon::Task<Json::Value> HeightOrchestratorService::processSingleHeight(const std::string& uuid, float x, float y) {
    float trueElevation = HeightExtractorService::getExactElevation(uuid, x, y);
    
    Json::Value ret;
    ret["elevation_meters"] = trueElevation;
    ret["uuid"] = uuid;
    co_return ret;
}

drogon::Task<Json::Value> HeightOrchestratorService::processComparison(
    const std::string& uuid, const std::string& tag, float x, float y, const drogon::HttpFile* uploadedFile) 
{
    int window_size = 100; // 100x100 pixel grid
    GeoWindowContext context;

    // 1. Get raw bytes from Extractor and Reference services
    std::vector<uint8_t> myGeneratedDSBytes = HeightExtractorService::extractWindowTiff(uuid, x, y, window_size, context);
    std::vector<uint8_t> myReferenceDSBytes = co_await ReferenceDemService::fetchReference(tag, context, uploadedFile);

    // 2. Write bytes into GDAL's virtual memory (/vsimem/) to convert them to GDALDataset
    std::string genVsi = "/vsimem/gen_" + drogon::utils::getUuid() + ".tif";
    std::string refVsi = "/vsimem/ref_" + drogon::utils::getUuid() + ".tif";

    VSILFILE* fpGen = VSIFOpenL(genVsi.c_str(), "wb");
    VSIFWriteL(myGeneratedDSBytes.data(), 1, myGeneratedDSBytes.size(), fpGen);
    VSIFCloseL(fpGen);

    VSILFILE* fpRef = VSIFOpenL(refVsi.c_str(), "wb");
    VSIFWriteL(myReferenceDSBytes.data(), 1, myReferenceDSBytes.size(), fpRef);
    VSIFCloseL(fpRef);

    // 3. Open as GDALDatasetPtr (utilizing the predefined GDALDatasetDeleter automatically)
    GDALDatasetPtr hGenDS(static_cast<GDALDataset*>(GDALOpen(genVsi.c_str(), GA_ReadOnly)));
    
    GDALDatasetPtr hRefDS(static_cast<GDALDataset*>(GDALOpen(refVsi.c_str(), GA_ReadOnly)));

    if (!hGenDS || !hRefDS) {
        VSIUnlink(genVsi.c_str());
        VSIUnlink(refVsi.c_str());
        throw std::runtime_error("HeightOrchestratorService: Failed to parse TIFF arrays into GDAL Datasets.");
    }

    // 4. Handoff to CompareService using std::move
    CompareService compareService;
    
    // Change 2.0f to a higher tolerance (e.g., 1000.0f meters) to see accuracy scale with the offset
    ComparisonMetrics results = compareService.compare(std::move(hGenDS), std::move(hRefDS), 880.0f, true);

    // NEW: Extract the exact point heights without modifying CompareService
    float original_height = HeightExtractorService::getExactElevation(uuid, x, y);
    float diff_val = 0.0f;
    float reference_height = 0.0f;

    if (!results.diffTifVsimemPath.empty()) {
        GDALDataset* diffDS = static_cast<GDALDataset*>(GDALOpen(results.diffTifVsimemPath.c_str(), GA_ReadOnly));
        if (diffDS) {
            // The clicked point is exactly at the center of our 100x100 extracted window
            int cx = diffDS->GetRasterXSize() / 2;
            int cy = diffDS->GetRasterYSize() / 2;
            diffDS->GetRasterBand(1)->RasterIO(GF_Read, cx, cy, 1, 1, &diff_val, 1, 1, GDT_Float32, 0, 0);
            GDALClose(diffDS);
        }
    }
    
    // Calculate reference height (Diff = Gen - Ref  =>  Ref = Gen - Diff)
    // -9999.0f is the NoData value set by CompareService
    if (diff_val != -9999.0f && !std::isnan(diff_val)) {
        reference_height = original_height - diff_val;
    }

    // 5. Safe Cleanup: Remove the virtual input files from RAM
    VSIUnlink(genVsi.c_str());
    VSIUnlink(refVsi.c_str());

    // 6. Package comprehensive metrics into JSON for the frontend
    Json::Value response;
    response["status"] = "Success";
    response["rmse"] = results.rmse; 
    response["mae"] = results.mae;
    response["pearson_correlation"] = results.pearsonCorrelation;
    response["accuracy_percentage"] = results.accuracyPercentage;
    response["valid_pixels_count"] = static_cast<Json::Value::UInt64>(results.validPixelsCount);
    
    // Append the newly extracted point heights
    response["original_height_meters"] = original_height;
    response["reference_height_meters"] = reference_height;
    
    // FIX: Extract the diff map bytes to send to frontend, then delete it from RAM immediately
    if (!results.diffTifVsimemPath.empty()) {
        // Read the actual image bytes from the virtual RAM file
        vsi_l_offset dataLength = 0;
        GByte* pabyData = VSIGetMemFileBuffer(results.diffTifVsimemPath.c_str(), &dataLength, FALSE);
        
        if (pabyData && dataLength > 0) {
            // Encode the bytes to Base64 so it can be safely sent inside the JSON payload
            response["diff_map_base64"] = drogon::utils::base64Encode(pabyData, dataLength);
        }

        // CRITICAL: Unlink (delete) the file from RAM to prevent the server memory leak
        VSIUnlink(results.diffTifVsimemPath.c_str());
    }
    
    co_return response;
}