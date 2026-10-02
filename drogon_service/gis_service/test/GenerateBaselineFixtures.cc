#include "BuildingReconstructionTestSupport.h"
#include "BuildingReconstruction/BuildingReconstructionService.h"
#include "BuildingReconstruction/Sat2Lod2Importer.h"
#include "MeshMapping/SceneMeshService.h"
#include "MeshMapping/ScenePresentationSelector.h"
#include "MeshMapping/PresentationStyle.h"
#include "FileGenerators/ReconstructionDiagnosticsWriter.h"
#include "FileGenerators/TiffExporter.h"

#include <gdal_priv.h>
#include <ogr_spatialref.h>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <json/json.h>

#include <filesystem>
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>

namespace fs = std::filesystem;
using namespace depthwizard;
using namespace depthwizard::test;

namespace
{

void writeOpticalTiff(const fs::path& path, const cv::Mat& bgr, const SpatialMetadata& meta)
{
    auto* driver = GetGDALDriverManager()->GetDriverByName("GTiff");
    if (!driver) throw std::runtime_error("GTiff driver not found");
    char tiled[] = "TILED=YES";
    char comp[] = "COMPRESS=DEFLATE";
    char* options[] = {tiled, comp, nullptr};
    std::unique_ptr<GDALDataset, decltype(&GDALClose)> ds(
        driver->Create(path.c_str(), bgr.cols, bgr.rows, 3, GDT_Byte, options), GDALClose);
    if (!ds) throw std::runtime_error("Failed to create optical GeoTIFF: " + path.string());
    auto affine = meta.geoTransform;
    ds->SetGeoTransform(affine.data());
    ds->SetProjection(meta.projectionRef.c_str());

    std::vector<cv::Mat> channels;
    cv::split(bgr, channels);
    (void)ds->GetRasterBand(1)->RasterIO(GF_Write, 0, 0, bgr.cols, bgr.rows, channels[2].data, bgr.cols, bgr.rows, GDT_Byte, 0, 0);
    (void)ds->GetRasterBand(2)->RasterIO(GF_Write, 0, 0, bgr.cols, bgr.rows, channels[1].data, bgr.cols, bgr.rows, GDT_Byte, 0, 0);
    (void)ds->GetRasterBand(3)->RasterIO(GF_Write, 0, 0, bgr.cols, bgr.rows, channels[0].data, bgr.cols, bgr.rows, GDT_Byte, 0, 0);
    ds->FlushCache();
}

void writeMetadataJson(const fs::path& path, const SpatialMetadata& meta, const std::string& name, const std::string& desc)
{
    Json::Value root;
    root["name"] = name;
    root["description"] = desc;
    root["width"] = meta.width;
    root["height"] = meta.height;
    root["gsd_m"] = meta.gsd;
    root["crs"] = "EPSG:32618 (WGS 84 / UTM zone 18N)";
    root["geo_transform"] = Json::Value(Json::arrayValue);
    for (double v : meta.geoTransform) root["geo_transform"].append(v);
    
    std::ofstream out(path);
    out << root.toStyledString();
}

void writeCameraViewsJson(const fs::path& path, int width, int height, double gsd)
{
    Json::Value root;
    const double sceneExtentX = width * gsd;
    const double sceneExtentZ = height * gsd;
    const double centerX = sceneExtentX * 0.5;
    const double centerZ = sceneExtentZ * 0.5;

    // Wide camera
    Json::Value wide;
    wide["position"] = Json::Value(Json::arrayValue);
    wide["position"].append(centerX);
    wide["position"].append(sceneExtentX * 1.5);
    wide["position"].append(sceneExtentZ * 1.8);
    wide["target"] = Json::Value(Json::arrayValue);
    wide["target"].append(centerX);
    wide["target"].append(0.0);
    wide["target"].append(centerZ);
    wide["fov"] = 45.0;
    root["wide"] = wide;

    // Oblique camera
    Json::Value oblique;
    oblique["position"] = Json::Value(Json::arrayValue);
    oblique["position"].append(centerX * 1.4);
    oblique["position"].append(sceneExtentX * 0.8);
    oblique["position"].append(centerZ * 1.5);
    oblique["target"] = Json::Value(Json::arrayValue);
    oblique["target"].append(centerX);
    oblique["target"].append(15.0);
    oblique["target"].append(centerZ);
    oblique["fov"] = 45.0;
    root["oblique"] = oblique;

    // Close-up camera
    Json::Value closeup;
    closeup["position"] = Json::Value(Json::arrayValue);
    closeup["position"].append(centerX * 0.9);
    closeup["position"].append(40.0);
    closeup["position"].append(centerZ * 0.7);
    closeup["target"] = Json::Value(Json::arrayValue);
    closeup["target"].append(centerX);
    closeup["target"].append(15.0);
    closeup["target"].append(centerZ);
    closeup["fov"] = 35.0;
    root["closeup"] = closeup;

    std::ofstream out(path);
    out << root.toStyledString();
}

void renderFixedCameraViews(
    const fs::path& outputDir,
    const BuildingCollection& buildings,
    int width,
    int height,
    double gsd)
{
    const int imgW = 800;
    const int imgH = 600;
    const double sceneX = width * gsd;
    const double sceneZ = height * gsd;
    const double midX = sceneX * 0.5;
    const double midZ = sceneZ * 0.5;

    struct CameraDef
    {
        std::string name;
        cv::Point3d pos;
        cv::Point3d target;
        double fovDeg;
    };

    std::vector<CameraDef> cameras = {
        {"screenshot_wide.png", cv::Point3d(midX, sceneX * 1.5, sceneZ * 1.8), cv::Point3d(midX, 0, midZ), 45.0},
        {"screenshot_oblique.png", cv::Point3d(midX * 1.4, sceneX * 0.8, sceneZ * 1.5), cv::Point3d(midX, 15.0, midZ), 45.0},
        {"screenshot_closeup.png", cv::Point3d(midX * 0.9, 40.0, midZ * 0.7), cv::Point3d(midX, 15.0, midZ), 35.0}
    };

    for (const auto& cam : cameras)
    {
        cv::Mat canvas(imgH, imgW, CV_8UC3);
        for (int r = 0; r < imgH; ++r)
        {
            float t = static_cast<float>(r) / imgH;
            uchar b = static_cast<uchar>(40 + t * 20);
            uchar g = static_cast<uchar>(20 + t * 30);
            uchar red = static_cast<uchar>(15 + t * 30);
            canvas.row(r).setTo(cv::Scalar(b, g, red));
        }

        cv::Point3d fwd = cam.target - cam.pos;
        double lenFwd = std::sqrt(fwd.x * fwd.x + fwd.y * fwd.y + fwd.z * fwd.z);
        if (lenFwd > 1e-6) fwd *= (1.0 / lenFwd);

        cv::Point3d up(0, 1, 0);
        cv::Point3d right(
            fwd.y * up.z - fwd.z * up.y,
            fwd.z * up.x - fwd.x * up.z,
            fwd.x * up.y - fwd.y * up.x
        );
        double lenR = std::sqrt(right.x * right.x + right.y * right.y + right.z * right.z);
        if (lenR > 1e-6) right *= (1.0 / lenR);

        cv::Point3d camUp(
            right.y * fwd.z - right.z * fwd.y,
            right.z * fwd.x - right.x * fwd.z,
            right.x * fwd.y - right.y * fwd.x
        );

        auto project = [&](double x, double y, double z) -> std::pair<cv::Point2i, double> {
            cv::Point3d rel(x - cam.pos.x, y - cam.pos.y, z - cam.pos.z);
            double cx = rel.x * right.x + rel.y * right.y + rel.z * right.z;
            double cy = rel.x * camUp.x + rel.y * camUp.y + rel.z * camUp.z;
            double cz = rel.x * fwd.x + rel.y * fwd.y + rel.z * fwd.z;
            if (cz < 0.5) cz = 0.5;

            double aspect = static_cast<double>(imgW) / imgH;
            double f = 1.0 / std::tan((cam.fovDeg * M_PI / 180.0) * 0.5);
            double ndcX = (cx / cz) * (f / aspect);
            double ndcY = (cy / cz) * f;

            int sx = static_cast<int>((ndcX * 0.5 + 0.5) * imgW);
            int sy = static_cast<int>((-ndcY * 0.5 + 0.5) * imgH);
            return {cv::Point2i(sx, sy), cz};
        };

        // Draw ground grid at y=0
        int gridSteps = 8;
        for (int i = 0; i <= gridSteps; ++i)
        {
            double gx = (sceneX / gridSteps) * i;
            auto p1 = project(gx, 0.0, 0.0).first;
            auto p2 = project(gx, 0.0, sceneZ).first;
            cv::line(canvas, p1, p2, cv::Scalar(70, 70, 80), 1);

            double gz = (sceneZ / gridSteps) * i;
            auto p3 = project(0.0, 0.0, gz).first;
            auto p4 = project(sceneX, 0.0, gz).first;
            cv::line(canvas, p3, p4, cv::Scalar(70, 70, 80), 1);
        }

        struct DrawablePoly
        {
            std::vector<cv::Point2i> pts;
            double depth;
            cv::Scalar fillColor;
            cv::Scalar edgeColor;
        };
        std::vector<DrawablePoly> drawList;

        for (const auto& b : buildings.buildings)
        {
            const auto& ring = b.pixelFootprint.outerRing;
            if (ring.size() < 3) continue;

            const double baseY = 0.0;
            const double roofY = b.heightAboveGround;

            std::vector<cv::Point2i> roofPts;
            double avgDepth = 0.0;
            for (const auto& pt : ring)
            {
                double lx = pt.column * gsd;
                double lz = pt.row * gsd;
                auto [sc, d] = project(lx, roofY, lz);
                roofPts.push_back(sc);
                avgDepth += d;
            }
            avgDepth /= ring.size();

            // Wall quads
            for (std::size_t i = 0; i < ring.size(); ++i)
            {
                std::size_t next = (i + 1) % ring.size();
                double x1 = ring[i].column * gsd;
                double z1 = ring[i].row * gsd;
                double x2 = ring[next].column * gsd;
                double z2 = ring[next].row * gsd;

                auto [p1Base, d1b] = project(x1, baseY, z1);
                auto [p2Base, d2b] = project(x2, baseY, z2);
                auto [p2Roof, d2r] = project(x2, roofY, z2);
                auto [p1Roof, d1r] = project(x1, roofY, z1);

                double wallDepth = (d1b + d2b + d2r + d1r) * 0.25;
                double nx = -(z2 - z1);
                double nz = (x2 - x1);
                double nlen = std::sqrt(nx * nx + nz * nz);
                double dotLight = (nlen > 1e-6) ? (nx * 0.577 + nz * 0.577) / nlen : 0.5;
                dotLight = std::clamp(dotLight * 0.4 + 0.6, 0.3, 1.0);

                cv::Scalar wallColor(
                    static_cast<uchar>(100 * dotLight),
                    static_cast<uchar>(110 * dotLight),
                    static_cast<uchar>(130 * dotLight)
                );

                drawList.push_back({
                    {p1Base, p2Base, p2Roof, p1Roof},
                    wallDepth,
                    wallColor,
                    cv::Scalar(60, 65, 75)
                });
            }

            cv::Scalar roofColor(170, 180, 205);
            drawList.push_back({roofPts, avgDepth, roofColor, cv::Scalar(230, 240, 255)});
        }

        std::sort(drawList.begin(), drawList.end(), [](const auto& a, const auto& b) {
            return a.depth > b.depth;
        });

        for (const auto& item : drawList)
        {
            if (item.pts.size() >= 3)
            {
                cv::fillPoly(canvas, std::vector<std::vector<cv::Point>>{item.pts}, item.fillColor);
                cv::polylines(canvas, std::vector<std::vector<cv::Point>>{item.pts}, true, item.edgeColor, 1, cv::LINE_AA);
            }
        }

        cv::imwrite((outputDir / cam.name).string(), canvas);
    }
}

void generateFixture(
    const fs::path& outputDir,
    const std::string& fixtureId,
    const std::string& name,
    const std::string& desc,
    int n,
    double gsd,
    std::function<void(SemanticScene&, GeoreferencedSurfaceBundle&, cv::Mat&, Json::Value& satDoc)> sceneBuilder)
{
    std::cout << "[FIXTURE] Generating: " << fixtureId << " (" << name << ")..." << std::endl;
    fs::create_directories(outputDir);

    SpatialMetadata meta = makeProjectedMetadata(n, n, gsd, -gsd);
    OGRSpatialReference srs;
    srs.importFromEPSG(32618);
    char* wkt = nullptr;
    srs.exportToWkt(&wkt);
    meta.projectionRef = wkt;
    CPLFree(wkt);

    SemanticScene semantics = makeSemanticScene(n, n, SemanticClass::GROUND);
    GeoreferencedSurfaceBundle surface = makeSurface(n, n, 10.0F, 0.0F);
    surface.spatialMetadata = meta;

    cv::Mat optical(n, n, CV_8UC3, cv::Scalar(110, 110, 110));

    Json::Value satDoc;
    satDoc["schema"] = "depthwizard.sat2lod2.v1";
    satDoc["raster_width"] = n;
    satDoc["raster_height"] = n;
    satDoc["segments"] = Json::Value(Json::arrayValue);

    sceneBuilder(semantics, surface, optical, satDoc);

    // Save optical inputs
    writeOpticalTiff(outputDir / "source_rgb.tif", optical, meta);
    cv::imwrite((outputDir / "source_rgb.png").string(), optical);

    SceneInput sceneInput;
    sceneInput.width = n;
    sceneInput.height = n;
    sceneInput.spatialMetadata = meta;
    sceneInput.textureMimeType = "image/png";
    cv::imencode(".png", optical, sceneInput.rgbTextureBytes);

    // Reconstruct native buildings
    BuildingReconstructionDiagnostics stages;
    BuildingReconstructionConfig bldgConfig;
    BuildingCollection buildings = BuildingReconstructionService::reconstruct(
        semantics, surface, meta, bldgConfig, &stages, &surface.ndsm, &sceneInput.rgbTextureBytes);

    // Decide presentation mode
    const ScenePresentationDecision decision = ScenePresentationSelector::select(semantics, surface, buildings);
    MeshBuildConfig meshConfig;
    meshConfig.presentation = decision.presentation;
    meshConfig.presentationStyle = depthwizard::PresentationStyle::SCIENTIFIC;

    // Generate native GLB
    GlbBuildResult glb = SceneMeshService::generateGlb(sceneInput, surface, buildings, meta, meshConfig);
    if (!glb.compressedGlbByteBuffer.empty())
    {
        std::ofstream glbOut(outputDir / "native_baseline.glb", std::ios::binary);
        glbOut.write(reinterpret_cast<const char*>(glb.compressedGlbByteBuffer.data()),
                     static_cast<std::streamsize>(glb.compressedGlbByteBuffer.size()));
    }

    // Generate Sat2LoD2 GLB if available
    if (!satDoc["segments"].empty())
    {
        Sat2Lod2ImportResult satImport = Sat2Lod2Importer::import(
            satDoc, semantics, surface, meta, bldgConfig, surface.ndsm);
        if (!satImport.buildings.buildings.empty())
        {
            GlbBuildResult satGlb = SceneMeshService::generateGlb(
                sceneInput, surface, satImport.buildings, meta, meshConfig);
            if (!satGlb.compressedGlbByteBuffer.empty())
            {
                std::ofstream satOut(outputDir / "sat2lod2_baseline.glb", std::ios::binary);
                satOut.write(reinterpret_cast<const char*>(satGlb.compressedGlbByteBuffer.data()),
                             static_cast<std::streamsize>(satGlb.compressedGlbByteBuffer.size()));
            }
        }
    }
    else
    {
        fs::copy_file(outputDir / "native_baseline.glb", outputDir / "sat2lod2_baseline.glb", fs::copy_options::overwrite_existing);
    }

    // Write diagnostic rasters and summary.json
    ReconstructionDiagnosticPayload diag;
    diag.buildingProbability = semantics.buildingProbability;
    diag.roadProbability = semantics.roadProbability;
    diag.vegetationProbability = semantics.vegetationProbability;
    diag.semanticConfidence = semantics.semanticConfidence;
    diag.finalClasses.width = n;
    diag.finalClasses.height = n;
    diag.finalClasses.data.reserve(semantics.finalClassMap.data.size());
    for (auto cls : semantics.finalClassMap.data)
        diag.finalClasses.data.push_back(static_cast<uint8_t>(cls));
    diag.rawNdsm = surface.ndsm;
    diag.reconstructionNdsm = surface.ndsm;
    diag.stages = stages;
    diag.buildings = buildings;
    diag.emittedBuildings = glb.buildingCount;
    diag.presentationMode = decision.presentation == ScenePresentation::FLAT_URBAN ? "flat_urban" : "metric";
    diag.presentationReason = decision.reason;
    diag.strongBuildingFraction = decision.strongBuildingFraction;
    diag.vegetationFraction = decision.vegetationFraction;
    diag.supportedGroundReliefMetres = decision.groundReliefMetres;

    std::string hexUuid = "10000000-0000-0000-0000-000000000001";
    if (fixtureId == "residential_pitched_urban") hexUuid = "20000000-0000-0000-0000-000000000002";
    else if (fixtureId == "sparse_urban") hexUuid = "30000000-0000-0000-0000-000000000003";
    else if (fixtureId == "hilly_urban") hexUuid = "40000000-0000-0000-0000-000000000004";
    else if (fixtureId == "vegetation_heavy") hexUuid = "50000000-0000-0000-0000-000000000005";

    fs::path tempDiagRoot = fs::temp_directory_path() / "dw_phase0_diag";
    fs::create_directories(tempDiagRoot);
    const auto writtenDir = ReconstructionDiagnosticsWriter::write(tempDiagRoot, hexUuid, diag, surface);

    for (const auto& entry : fs::directory_iterator(writtenDir))
    {
        fs::copy_file(entry.path(), outputDir / entry.path().filename(), fs::copy_options::overwrite_existing);
    }
    std::error_code ec;
    fs::remove_all(writtenDir, ec);

    // Canonical dsm.tif and ndsm.tif
    TiffExporter::writeFloatTiff(
        (outputDir / "dsm.tif").string(), surface.dsm.data,
        n, n, const_cast<double*>(meta.geoTransform.data()),
        meta.projectionRef.c_str());
    TiffExporter::writeFloatTiff(
        (outputDir / "ndsm.tif").string(), surface.ndsm.data,
        n, n, const_cast<double*>(meta.geoTransform.data()),
        meta.projectionRef.c_str());

    // Save metadata and camera presets
    writeMetadataJson(outputDir / "metadata.json", meta, name, desc);
    writeCameraViewsJson(outputDir / "fixed_camera_view.json", n, n, gsd);

    // Render fixed-camera screenshots
    renderFixedCameraViews(outputDir, buildings, n, n, gsd);

    std::cout << "  -> Emitted buildings: " << glb.buildingCount
              << ", Vertices: " << glb.vertexCount
              << ", Triangles: " << glb.triangleCount
              << ", Mode: " << diag.presentationMode
              << ", Screenshots rendered: 3" << std::endl;
}

} // namespace

int main(int argc, char** argv)
{
    GDALAllRegister();

    fs::path baseDir = argc > 1 ? fs::path(argv[1]) : fs::path("fixtures");
    std::cout << "Generating Phase 0 baseline fixtures at: " << fs::absolute(baseDir) << std::endl;

    constexpr int N = 128;
    constexpr double GSD = 0.5;

    auto addSatSegment = [](Json::Value& satDoc, int id, double l, double t, double r, double b, double eave, double ridge, const std::string& type)
    {
        Json::Value seg;
        seg["id"] = id;
        Json::Value fp(Json::arrayValue);
        auto pt = [](double x, double y) { Json::Value p(Json::arrayValue); p.append(x); p.append(y); return p; };
        fp.append(pt(l, t)); fp.append(pt(r, t)); fp.append(pt(r, b)); fp.append(pt(l, b));
        seg["footprint"] = fp;
        seg["irregular"] = false;
        Json::Value blk;
        blk["corners"] = fp;
        blk["roof_type"] = type;
        blk["eave"] = eave;
        blk["ridge"] = ridge;
        seg["blocks"] = Json::Value(Json::arrayValue);
        seg["blocks"].append(blk);
        satDoc["segments"].append(seg);
    };

    // 1. Dense flat-roof urban tile
    generateFixture(
        baseDir / "dense_flat_urban",
        "dense_flat_urban",
        "Dense Flat-Roof Urban Tile",
        "Multi-story flat-roof office/commercial buildings with asphalt road grid and alleys.",
        N, GSD,
        [&](SemanticScene& sem, GeoreferencedSurfaceBundle& surf, cv::Mat& opt, Json::Value& satDoc)
        {
            for (int r = 0; r < N; ++r) {
                for (int c = 0; c < N; ++c) {
                    if (r < 10 || r >= 118 || (r >= 58 && r <= 68) ||
                        c < 10 || c >= 118 || (c >= 58 && c <= 68)) {
                        sem.finalClassMap.data[r * N + c] = SemanticClass::ROAD;
                        sem.roadProbability.data[r * N + c] = 0.95F;
                        opt.at<cv::Vec3b>(r, c) = cv::Vec3b(50, 50, 50);
                    }
                }
            }

            fillRectangle(sem.finalClassMap, 16, 16, 52, 52, SemanticClass::BUILDING);
            fillRectangle(sem.buildingProbability, 16, 16, 52, 52, 0.98F);
            fillRectangle(surf.ndsm, 16, 16, 52, 52, 28.0F);
            opt(cv::Rect(16, 16, 36, 36)).setTo(cv::Scalar(180, 180, 190));
            addSatSegment(satDoc, 0, 16, 16, 52, 52, 28.0, 28.0, "flat");

            fillRectangle(sem.finalClassMap, 74, 16, 112, 52, SemanticClass::BUILDING);
            fillRectangle(sem.buildingProbability, 74, 16, 112, 52, 0.99F);
            fillRectangle(surf.ndsm, 74, 16, 112, 52, 42.0F);
            opt(cv::Rect(74, 16, 38, 36)).setTo(cv::Scalar(160, 165, 175));
            addSatSegment(satDoc, 1, 74, 16, 112, 52, 42.0, 42.0, "flat");

            fillRectangle(sem.finalClassMap, 16, 74, 52, 112, SemanticClass::BUILDING);
            fillRectangle(sem.buildingProbability, 16, 74, 52, 112, 0.97F);
            fillRectangle(surf.ndsm, 16, 74, 52, 112, 18.0F);
            opt(cv::Rect(16, 74, 36, 38)).setTo(cv::Scalar(200, 195, 190));
            addSatSegment(satDoc, 2, 16, 74, 52, 112, 18.0, 18.0, "flat");

            fillRectangle(sem.finalClassMap, 74, 74, 112, 112, SemanticClass::BUILDING);
            fillRectangle(sem.buildingProbability, 74, 74, 112, 112, 0.99F);
            fillRectangle(surf.ndsm, 74, 74, 95, 112, 35.0F);
            fillRectangle(surf.ndsm, 95, 74, 112, 112, 50.0F);
            opt(cv::Rect(74, 74, 21, 38)).setTo(cv::Scalar(170, 170, 180));
            opt(cv::Rect(95, 74, 17, 38)).setTo(cv::Scalar(150, 150, 160));
            addSatSegment(satDoc, 3, 74, 74, 95, 112, 35.0, 35.0, "flat");
            addSatSegment(satDoc, 4, 95, 74, 112, 112, 50.0, 50.0, "flat");

            for (std::size_t i = 0; i < surf.dtm.data.size(); ++i) {
                surf.dsm.data[i] = surf.dtm.data[i] + surf.ndsm.data[i];
            }
        });

    // 2. Residential pitched-roof tile
    generateFixture(
        baseDir / "residential_pitched_urban",
        "residential_pitched_urban",
        "Suburban Residential Pitched-Roof Tile",
        "Detached single-family homes with pitched roof geometry, front/back yards, and trees.",
        N, GSD,
        [&](SemanticScene& sem, GeoreferencedSurfaceBundle& surf, cv::Mat& opt, Json::Value& satDoc)
        {
            for (int r = 0; r < N; ++r) {
                for (int c = 0; c < N; ++c) {
                    surf.dtm.data[r * N + c] = 15.0F + (r * 0.04F) + (c * 0.02F);
                }
            }

            for (int r = 0; r < N; ++r) {
                for (int c = 0; c < N; ++c) {
                    if ((r >= 58 && r <= 68) || (c >= 58 && c <= 68)) {
                        sem.finalClassMap.data[r * N + c] = SemanticClass::ROAD;
                        sem.roadProbability.data[r * N + c] = 0.92F;
                        opt.at<cv::Vec3b>(r, c) = cv::Vec3b(60, 60, 60);
                    }
                }
            }

            for (int r = 0; r < N; ++r) {
                for (int c = 0; c < N; ++c) {
                    if (sem.finalClassMap.data[r * N + c] == SemanticClass::GROUND &&
                        ((r % 16 < 4) || (c % 16 < 4))) {
                        sem.finalClassMap.data[r * N + c] = SemanticClass::VEGETATION;
                        sem.vegetationProbability.data[r * N + c] = 0.75F;
                        opt.at<cv::Vec3b>(r, c) = cv::Vec3b(34, 139, 34);
                    }
                }
            }

            struct House { int x, y, w, h; float height; };
            std::vector<House> houses = {
                {18, 18, 20, 24, 8.5F},
                {78, 18, 22, 22, 9.0F},
                {18, 78, 24, 20, 10.0F},
                {78, 78, 22, 26, 8.0F},
                {40, 22, 14, 18, 7.5F},
                {40, 84, 14, 20, 8.0F}
            };

            int id = 0;
            for (const auto& h : houses) {
                fillRectangle(sem.finalClassMap, h.x, h.y, h.x + h.w, h.y + h.h, SemanticClass::BUILDING);
                fillRectangle(sem.buildingProbability, h.x, h.y, h.x + h.w, h.y + h.h, 0.94F);
                fillRectangle(surf.ndsm, h.x, h.y, h.x + h.w, h.y + h.h, h.height);
                opt(cv::Rect(h.x, h.y, h.w, h.h)).setTo(cv::Scalar(40, 50, 180));
                addSatSegment(satDoc, id++, h.x, h.y, h.x + h.w, h.y + h.h, h.height * 0.7, h.height, "gable");
            }

            for (std::size_t i = 0; i < surf.dtm.data.size(); ++i) {
                surf.dsm.data[i] = surf.dtm.data[i] + surf.ndsm.data[i];
            }
        });

    // 3. Sparse urban tile
    generateFixture(
        baseDir / "sparse_urban",
        "sparse_urban",
        "Sparse Commercial / Logistics Tile",
        "Two isolated warehouse/distribution structures with large asphalt parking lots and open ground.",
        N, GSD,
        [&](SemanticScene& sem, GeoreferencedSurfaceBundle& surf, cv::Mat& opt, Json::Value& satDoc)
        {
            for (int r = 0; r < N; ++r) {
                for (int c = 0; c < N; ++c) {
                    if (r >= 20 && r <= 108 && c >= 20 && c <= 108) {
                        sem.finalClassMap.data[r * N + c] = SemanticClass::GROUND;
                        sem.groundProbability.data[r * N + c] = 0.88F;
                        opt.at<cv::Vec3b>(r, c) = cv::Vec3b(90, 95, 100);
                    }
                }
            }

            fillRectangle(sem.finalClassMap, 30, 35, 65, 85, SemanticClass::BUILDING);
            fillRectangle(sem.buildingProbability, 30, 35, 65, 85, 0.98F);
            fillRectangle(surf.ndsm, 30, 35, 65, 85, 12.0F);
            opt(cv::Rect(30, 35, 35, 50)).setTo(cv::Scalar(210, 210, 215));
            addSatSegment(satDoc, 0, 30, 35, 65, 85, 12.0, 12.0, "flat");

            fillRectangle(sem.finalClassMap, 85, 45, 105, 75, SemanticClass::BUILDING);
            fillRectangle(sem.buildingProbability, 85, 45, 105, 75, 0.96F);
            fillRectangle(surf.ndsm, 85, 45, 105, 75, 7.0F);
            opt(cv::Rect(85, 45, 20, 30)).setTo(cv::Scalar(185, 190, 195));
            addSatSegment(satDoc, 1, 85, 45, 105, 75, 7.0, 7.0, "flat");

            for (std::size_t i = 0; i < surf.dtm.data.size(); ++i) {
                surf.dsm.data[i] = surf.dtm.data[i] + surf.ndsm.data[i];
            }
        });

    // 4. Hilly urban tile
    generateFixture(
        baseDir / "hilly_urban",
        "hilly_urban",
        "Hilly Terrain Settlement",
        "Buildings built along a steep hillside slope spanning 35m to 85m elevation relief.",
        N, GSD,
        [&](SemanticScene& sem, GeoreferencedSurfaceBundle& surf, cv::Mat& opt, Json::Value& satDoc)
        {
            for (int r = 0; r < N; ++r) {
                for (int c = 0; c < N; ++c) {
                    const float elev = 35.0F + (r * 0.35F) + (c * 0.15F);
                    surf.dtm.data[r * N + c] = elev;
                    opt.at<cv::Vec3b>(r, c) = cv::Vec3b(80 + r/3, 100 + r/4, 90 + r/4);
                }
            }

            fillRectangle(sem.finalClassMap, 20, 20, 50, 50, SemanticClass::BUILDING);
            fillRectangle(sem.buildingProbability, 20, 20, 50, 50, 0.95F);
            fillRectangle(surf.ndsm, 20, 20, 50, 50, 16.0F);
            opt(cv::Rect(20, 20, 30, 30)).setTo(cv::Scalar(160, 150, 140));
            addSatSegment(satDoc, 0, 20, 20, 50, 50, 16.0, 16.0, "flat");

            fillRectangle(sem.finalClassMap, 70, 60, 105, 95, SemanticClass::BUILDING);
            fillRectangle(sem.buildingProbability, 70, 60, 105, 95, 0.96F);
            fillRectangle(surf.ndsm, 70, 60, 105, 95, 22.0F);
            opt(cv::Rect(70, 60, 35, 35)).setTo(cv::Scalar(170, 165, 160));
            addSatSegment(satDoc, 1, 70, 60, 105, 95, 22.0, 22.0, "flat");

            for (std::size_t i = 0; i < surf.dtm.data.size(); ++i) {
                surf.dsm.data[i] = surf.dtm.data[i] + surf.ndsm.data[i];
            }
        });

    // 5. Vegetation-heavy tile
    generateFixture(
        baseDir / "vegetation_heavy",
        "vegetation_heavy",
        "Vegetation-Dominated Park / Forest Zone",
        "Dense tree canopy (>60% vegetation cover) with partially occluded structures and park paths.",
        N, GSD,
        [&](SemanticScene& sem, GeoreferencedSurfaceBundle& surf, cv::Mat& opt, Json::Value& satDoc)
        {
            for (int r = 0; r < N; ++r) {
                for (int c = 0; c < N; ++c) {
                    sem.finalClassMap.data[r * N + c] = SemanticClass::VEGETATION;
                    sem.vegetationProbability.data[r * N + c] = 0.85F;
                    surf.ndsm.data[r * N + c] = 8.0F + (std::sin(r * 0.2F) * std::cos(c * 0.2F) * 4.0F);
                    opt.at<cv::Vec3b>(r, c) = cv::Vec3b(30, 120, 40);
                }
            }

            for (int r = 50; r <= 60; ++r) {
                for (int c = 0; c < N; ++c) {
                    sem.finalClassMap.data[r * N + c] = SemanticClass::ROAD;
                    sem.roadProbability.data[r * N + c] = 0.90F;
                    sem.vegetationProbability.data[r * N + c] = 0.05F;
                    surf.ndsm.data[r * N + c] = 0.0F;
                    opt.at<cv::Vec3b>(r, c) = cv::Vec3b(130, 120, 100);
                }
            }

            fillRectangle(sem.finalClassMap, 80, 20, 105, 45, SemanticClass::BUILDING);
            fillRectangle(sem.buildingProbability, 80, 20, 105, 45, 0.94F);
            fillRectangle(sem.vegetationProbability, 80, 20, 105, 45, 0.05F);
            fillRectangle(surf.ndsm, 80, 20, 105, 45, 7.0F);
            opt(cv::Rect(80, 20, 25, 25)).setTo(cv::Scalar(180, 160, 150));
            addSatSegment(satDoc, 0, 80, 20, 105, 45, 7.0, 7.0, "flat");

            for (std::size_t i = 0; i < surf.dtm.data.size(); ++i) {
                surf.dsm.data[i] = surf.dtm.data[i] + surf.ndsm.data[i];
            }
        });

    std::cout << "[SUCCESS] All 5 baseline fixtures generated successfully!" << std::endl;
    return 0;
}
