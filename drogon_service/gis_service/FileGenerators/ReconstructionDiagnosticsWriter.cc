#include "ReconstructionDiagnosticsWriter.h"
#include <gdal_priv.h>
#include <json/json.h>
#include <fstream>
#include <memory>
#include <stdexcept>
#include <algorithm>
#include <limits>

namespace
{
template<class T>
void writeGrid(const std::filesystem::path& path, const RasterGrid<T>& grid,
               const SpatialMetadata& metadata, GDALDataType type)
{
    if (!grid.isValid() || grid.width != metadata.width || grid.height != metadata.height)
        throw std::runtime_error("Diagnostic raster has an invalid shape: " + path.string());
    auto* driver = GetGDALDriverManager()->GetDriverByName("GTiff");
    if (!driver) throw std::runtime_error("GTiff driver unavailable");
    char tiled[] = "TILED=YES", compress[] = "COMPRESS=DEFLATE";
    char* options[] = {tiled, compress, nullptr};
    std::unique_ptr<GDALDataset, decltype(&GDALClose)> ds(
        driver->Create(path.c_str(), grid.width, grid.height, 1, type, options), GDALClose);
    if (!ds) throw std::runtime_error("Cannot create diagnostic raster");
    auto affine = metadata.geoTransform;
    if (ds->SetGeoTransform(affine.data()) != CE_None ||
        ds->SetProjection(metadata.projectionRef.c_str()) != CE_None)
        throw std::runtime_error("Cannot set diagnostic spatial metadata");
    if (type == GDT_Float32) ds->GetRasterBand(1)->SetNoDataValue(std::numeric_limits<double>::quiet_NaN());
    if (ds->GetRasterBand(1)->RasterIO(GF_Write, 0, 0, grid.width, grid.height,
        const_cast<T*>(grid.data.data()), grid.width, grid.height, type, 0, 0) != CE_None)
        throw std::runtime_error("Cannot write diagnostic raster");
    if (ds->FlushCache() != CE_None) throw std::runtime_error("Cannot flush diagnostic raster");
}
}

std::filesystem::path ReconstructionDiagnosticsWriter::write(
    const std::filesystem::path& root, const std::string& uuid,
    const ReconstructionDiagnosticPayload& d, const GeoreferencedSurfaceBundle& surface)
{
    if (uuid.empty() || !std::all_of(uuid.begin(), uuid.end(), [](unsigned char c) {
        return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || c == '-';
    })) throw std::invalid_argument("Unsafe diagnostic job identifier");
    const auto folder = std::filesystem::absolute(root / uuid);
    std::filesystem::create_directories(folder);
    const auto& meta = surface.spatialMetadata;
    writeGrid(folder / "building_probability.tif", d.buildingProbability, meta, GDT_Float32);
    if (d.roadProbability.isValid()) writeGrid(folder / "road_probability.tif", d.roadProbability, meta, GDT_Float32);
    if (d.vegetationProbability.isValid()) writeGrid(folder / "vegetation_probability.tif", d.vegetationProbability, meta, GDT_Float32);
    if (d.semanticConfidence.isValid()) writeGrid(folder / "semantic_confidence.tif", d.semanticConfidence, meta, GDT_Float32);
    if (d.finalClasses.isValid()) writeGrid(folder / "final_semantic_class.tif", d.finalClasses, meta, GDT_Byte);
    writeGrid(folder / "raw_ndsm.tif", d.rawNdsm, meta, GDT_Float32);
    writeGrid(folder / "dtm.tif", surface.dtm, meta, GDT_Float32);
    writeGrid(folder / "fused_ndsm.tif", surface.ndsm, meta, GDT_Float32);
    if (d.stages.candidateMask.isValid()) writeGrid(folder / "candidate_mask.tif", d.stages.candidateMask, meta, GDT_Byte);
    if (d.stages.cleanedMask.isValid()) writeGrid(folder / "cleaned_mask.tif", d.stages.cleanedMask, meta, GDT_Byte);
    if (d.stages.instanceLabels.isValid()) writeGrid(folder / "instance_labels.tif", d.stages.instanceLabels, meta, GDT_Int32);

    Json::Value summary(Json::objectValue);
    summary["uuid"] = uuid;
    summary["presentation_mode"] = d.presentationMode;
    summary["presentation_reason"] = d.presentationReason;
    summary["strong_building_fraction"] = d.strongBuildingFraction;
    summary["vegetation_fraction"] = d.vegetationFraction;
    summary["supported_ground_relief_m"] = d.supportedGroundReliefMetres;
    summary["final_class_ids"] = "0=UNKNOWN,1=GROUND,2=BUILDING,3=ROAD,4=VEGETATION,5=WATER";
    summary["worker_logit_order"] = "OTHER,GROUND,LOW_VEGETATION,BUILDING,WATER,ROAD";
    summary["render_height_scale"] = 1.0;
    summary["scientific_rasters_flattened"] = false;
    summary["semantic_candidates"] = Json::UInt64(d.buildings.semanticCandidateCount);
    summary["accepted_buildings"] = Json::UInt64(d.buildings.buildings.size());
    summary["emitted_buildings"] = Json::UInt64(d.emittedBuildings);
    summary["component_rejected"] = Json::UInt64(d.buildings.componentRejectedCount);
    summary["vectorization_rejected"] = Json::UInt64(d.buildings.vectorizationRejectedCount);
    summary["height_rejected"] = Json::UInt64(d.buildings.physicsRejectedCount);
    summary["recovered_pixels"] = Json::UInt64(d.buildings.recoveredCandidatePixelCount);
    summary["buildings"] = Json::Value(Json::arrayValue);
    summary["rejections"] = Json::Value(Json::arrayValue);
    summary["mesh_warnings"] = Json::Value(Json::arrayValue);
    for (const auto& b : d.buildings.buildings)
    {
        Json::Value item;
        item["id"] = b.buildingId;
        item["area_m2"] = b.footprintAreaSquareMetres;
        item["height_agl_m"] = b.heightAboveGround;
        item["base_elevation_m"] = b.representativeBaseElevation;
        item["roof_elevation_m"] = b.roofElevation;
        item["building_probability"] = b.semanticConfidence;
        item["warnings"] = Json::Value(Json::arrayValue);
        for (const auto& warning : b.geometryWarnings) item["warnings"].append(warning);
        summary["buildings"].append(item);
    }
    for (const auto& reason : d.stages.rejectionReasons) summary["rejections"].append(reason);
    for (const auto& warning : d.meshWarnings) summary["mesh_warnings"].append(warning);
    // Publish the summary last; its existence signals a completed snapshot set.
    std::ofstream output(folder / "summary.json.tmp");
    Json::StreamWriterBuilder writer; writer["indentation"] = "  ";
    output << Json::writeString(writer, summary);
    output.close();
    if (!output) throw std::runtime_error("Cannot write diagnostic summary");
    std::filesystem::rename(folder / "summary.json.tmp", folder / "summary.json");
    return folder;
}
