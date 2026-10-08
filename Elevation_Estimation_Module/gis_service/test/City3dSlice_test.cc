// City3D vertical slice: inputs, import, shell meshing and orchestration.
#include "BuildingReconstruction/City3dInputBuilder.h"
#include "BuildingReconstruction/City3dOrchestrator.h"
#include "BuildingReconstruction/City3dResultImporter.h"
#include "MeshMapping/BuildingMesher.h"
#include "MeshMapping/FacadeAtlasGenerator.h"
#include "MeshMapping/SceneMeshService.h"
#include "utils/FeatureFlags.h"
#include "BuildingReconstructionTestSupport.h"
#include "GlbTestSupport.h"

#include <gtest/gtest.h>
#include <json/json.h>

#include <cmath>
#include <fstream>
#include <set>
#include <sstream>
#include <unistd.h>

namespace fs = std::filesystem;
using namespace depthwizard::test;

namespace
{

constexpr float kRenderScale = 2.25f;
constexpr int kWidth = 80;
constexpr int kHeight = 60;

SpatialMetadata sceneMetadata()
{
     SpatialMetadata metadata = makeProjectedMetadata(kWidth, kHeight, 0.5, -0.5);
     metadata.projectionRef = "EPSG:32643";
     metadata.isGeoreferenced = true;
     return metadata;
}

BuildingInstance rectangleBuilding(uint32_t id, double left, double top, double right, double bottom,
                                   float metricHeight, const SpatialMetadata& metadata)
{
     BuildingInstance building;
     building.buildingId = id;
     building.pixelFootprint.outerRing = {{left, top}, {right, top}, {right, bottom}, {left, bottom}};
     for (const PixelPoint& p : building.pixelFootprint.outerRing)
          building.projectedFootprint.outerRing.push_back(City3dInputBuilder::pixelEdge(p, metadata));
     building.representativeBaseElevation = 100.0F;
     building.heightAboveGround = metricHeight * kRenderScale; // Render-scaled, as reconstruction stores it
     building.roofElevation = 100.0F + building.heightAboveGround;
     const double gsd = 0.5;
     building.footprintAreaSquareMetres = static_cast<float>((right - left) * (bottom - top) * gsd * gsd);
     return building;
}

// Gable building 7 (20 m x 15 m, eaves 6 m, ridge 9 m) touching flat building 8 (5 m).
struct Scene
{
     SpatialMetadata metadata = sceneMetadata();
     SemanticScene semantics = makeSemanticScene(kWidth, kHeight);
     GeoreferencedSurfaceBundle surface = makeSurface(kWidth, kHeight, 100.0F, 0.0F);
     RasterGrid<float> ndsm = makeConstantGrid(kWidth, kHeight, 0.0F);
     RasterGrid<int32_t> labels = makeConstantGrid<int32_t>(kWidth, kHeight, 0);
     BuildingCollection buildings;

     Scene()
     {
          surface.spatialMetadata = metadata;
          for (int row = 0; row < kHeight; ++row)
               for (int column = 0; column < kWidth; ++column)
               {
                    const std::size_t i = static_cast<std::size_t>(row) * kWidth + column;
                    if (row >= 10 && row < 40 && column >= 10 && column < 50)
                    {
                         labels.data[i] = 7;
                         const double metresFromRidge = std::abs(row + 0.5 - 25.0) * 0.5;
                         ndsm.data[i] = static_cast<float>(9.0 - 3.0 * metresFromRidge / 7.5);
                    }
                    else if (row >= 10 && row < 40 && column >= 50 && column < 70)
                    {
                         labels.data[i] = 8;
                         ndsm.data[i] = 5.0F;
                    }
                    if (labels.data[i] != 0) semantics.buildingProbability.data[i] = 0.9F;
               }
          buildings.buildings.push_back(rectangleBuilding(7, 10, 10, 50, 40, 9.0F, metadata));
          buildings.buildings.push_back(rectangleBuilding(8, 50, 10, 70, 40, 5.0F, metadata));
     }
};

fs::path testRoot(const std::string& name)
{
     const fs::path root = fs::temp_directory_path() / ("city3d_slice_" + name + "_" + std::to_string(::getpid()));
     fs::remove_all(root);
     fs::create_directories(root);
     return root;
}

City3dConfig testConfig(const fs::path& root, const fs::path& binary)
{
     City3dConfig config;
     config.workRoot = root;
     config.workerBinary = binary;
     config.timeout = std::chrono::milliseconds(12000);
     config.keepWorkDirectories = true;
     return config;
}

fs::path script(const fs::path& root, const std::string& name, const std::string& body)
{
     const fs::path path = root / name;
     std::ofstream(path) << "#!/bin/sh\n" << body << "\n";
     fs::permissions(path, fs::perms::owner_all);
     return path;
}

const fs::path kRealWorker = CITY3D_WORKER_BINARY;
bool realWorkerAvailable() { return !kRealWorker.empty() && ::access(kRealWorker.c_str(), X_OK) == 0; }

// A worker result directory written by hand.
void writeResult(const fs::path& directory, const std::string& jobId, uint32_t buildingId,
                 const City3dCandidate& candidate, const std::string& obj, const std::string& status = "success")
{
     fs::create_directories(directory);
     Json::Value manifest(Json::objectValue);
     manifest["schema"] = "depthwizard.city3d-result.v1";
     manifest["job_id"] = jobId;
     manifest["building_id"] = buildingId;
     manifest["status"] = status;
     manifest["mesh"] = status == "success" ? Json::Value("building.obj") : Json::Value();
     manifest["coordinate_frame"]["origin_easting"] = candidate.originEasting;
     manifest["coordinate_frame"]["origin_northing"] = candidate.originNorthing;
     manifest["coordinate_frame"]["origin_elevation"] = candidate.originElevation;
     manifest["coordinate_frame"]["axis_convention"] = "X_EAST_Y_NORTH_Z_UP";
     std::ofstream(directory / "result.json") << manifest.toStyledString();
     std::ofstream(directory / "building.obj") << obj;
}

// A 20 m x 15 m gable box around the candidate origin, in local metres.
std::string gableObj(double ridge = 9.0, double eave = 6.0)
{
     std::ostringstream obj;
     obj << "v -10 -7.5 0\nv 10 -7.5 0\nv 10 7.5 0\nv -10 7.5 0\n"
         << "v -10 -7.5 " << eave << "\nv 10 -7.5 " << eave << "\nv 10 7.5 " << eave << "\nv -10 7.5 " << eave << "\n"
         << "v -10 0 " << ridge << "\nv 10 0 " << ridge << "\n"
         << "g roof\nf 5 6 10 9\nf 9 10 7 8\n"
         << "g wall\nf 1 2 6 5\nf 2 3 7 6\nf 3 4 8 7\nf 4 1 5 8\nf 5 9 8\nf 6 7 10\n"
         << "g ground\nf 1 4 3 2\n";
     return obj.str();
}

} // namespace

// --- Coordinates -------------------------------------------------------------

TEST(City3dSliceTest, PointsUsePixelCentresAndFootprintsUsePixelEdges)
{
     SpatialMetadata metadata = sceneMetadata();
     metadata.geoTransform = {500000.0, 0.5, 0.1, 2000000.0, 0.05, -0.5}; // sheared
     const ProjectedPoint centre = City3dInputBuilder::pixelCentre(10, 20, metadata);
     EXPECT_DOUBLE_EQ(centre.easting, 500000.0 + 10.5 * 0.5 + 20.5 * 0.1);
     EXPECT_DOUBLE_EQ(centre.northing, 2000000.0 + 10.5 * 0.05 - 20.5 * 0.5);
     const ProjectedPoint edge = City3dInputBuilder::pixelEdge({10.0, 20.0}, metadata);
     EXPECT_DOUBLE_EQ(edge.easting, 500000.0 + 10.0 * 0.5 + 20.0 * 0.1);
     EXPECT_DOUBLE_EQ(edge.northing, 2000000.0 + 10.0 * 0.05 - 20.0 * 0.5);

     Scene scene;
     const City3dConfig config;
     const City3dCandidate candidate = City3dInputBuilder::analyse(
         scene.buildings.buildings[0], scene.labels, scene.semantics, scene.surface, scene.ndsm, scene.metadata, config);
     ASSERT_TRUE(candidate.eligible) << candidate.reason;
     // Interior pixels only (one-pixel erosion): columns 11..48, rows 11..38.
     EXPECT_EQ(candidate.points.size(), 38U * 28U);
     const ProjectedPoint first = City3dInputBuilder::pixelCentre(11, 11, scene.metadata);
     EXPECT_DOUBLE_EQ(candidate.points.front().easting, first.easting);
     EXPECT_DOUBLE_EQ(candidate.points.front().northing, first.northing);
     EXPECT_NEAR(candidate.points.front().elevation, 100.0 + 9.0 - 3.0 * 13.5 * 0.5 / 7.5, 1e-5); // DTM + metric nDSM
     EXPECT_DOUBLE_EQ(candidate.originElevation, 100.0);

     const fs::path root = testRoot("coordinates");
     std::string error;
     ASSERT_TRUE(City3dInputBuilder::writeJob(candidate, scene.buildings.buildings[0], scene.metadata, config,
                                              "job", root / "b7", error)) << error;
     std::ifstream footprint(root / "b7" / "footprint.obj");
     std::string tag;
     double x = 0, y = 0, z = 0;
     footprint.ignore(1024, '\n');
     footprint >> tag >> x >> y >> z;
     const ProjectedPoint corner = City3dInputBuilder::pixelEdge({10.0, 10.0}, scene.metadata);
     EXPECT_NEAR(x, corner.easting - candidate.originEasting, 1e-4);   // edge, not centre
     EXPECT_NEAR(y, corner.northing - candidate.originNorthing, 1e-4);
     EXPECT_EQ(z, 0.0);
     Json::Value request;
     std::ifstream(root / "b7" / "request.json") >> request;
     EXPECT_EQ(request["input_provenance"]["point_source"].asString(), "monocular_derived_dsm");
     EXPECT_FALSE(request["input_provenance"]["external_lidar_used"].asBool());
     EXPECT_EQ(request["job_id"].asString(), "job-b7");
     fs::remove_all(root);
}

TEST(City3dSliceTest, InputSelectionIsolatesInstancesAndRejectsUnsupportedBuildings)
{
     Scene scene;
     const City3dConfig config;
     const auto analyse = [&](const BuildingInstance& building)
     {
          return City3dInputBuilder::analyse(building, scene.labels, scene.semantics, scene.surface, scene.ndsm,
                                             scene.metadata, config);
     };
     // Points only come from label 7 even though label 8 touches it.
     const City3dCandidate gable = analyse(scene.buildings.buildings[0]);
     for (const ProjectedVertex3D& point : gable.points) EXPECT_LT(point.elevation, 109.01);
     EXPECT_EQ(analyse(scene.buildings.buildings[1]).reason, "flat_roof");

     BuildingInstance courtyard = scene.buildings.buildings[0];
     courtyard.pixelFootprint.holes = {{{20, 20}, {20, 30}, {30, 30}, {30, 20}}};
     EXPECT_EQ(analyse(courtyard).reason, "courtyard_unsupported");

     // A 6 m -> 12 m step: the two ramp columns either side of it are steeper
     // than maximumPointSlope and are left out; flat tiers stay.
     Scene stepped;
     for (std::size_t i = 0; i < stepped.labels.data.size(); ++i)
          if (stepped.labels.data[i] == 7) stepped.ndsm.data[i] = (i % kWidth) < 30 ? 6.0F : 12.0F;
     const City3dCandidate tiers = City3dInputBuilder::analyse(
         stepped.buildings.buildings[0], stepped.labels, stepped.semantics, stepped.surface, stepped.ndsm,
         stepped.metadata, config);
     ASSERT_TRUE(tiers.eligible) << tiers.reason;
     EXPECT_EQ(tiers.points.size(), (38U - 2U) * 28U);
     EXPECT_NEAR(tiers.maximumLocalHeightMetres, 12.0, 1e-5);

     City3dConfig small;
     small.maximumPoints = 100;
     EXPECT_EQ(City3dInputBuilder::analyse(scene.buildings.buildings[0], scene.labels, scene.semantics, scene.surface,
                                           scene.ndsm, scene.metadata, small).reason, "too_large_for_budget");

     Scene unreferenced;
     unreferenced.metadata.isGeoreferenced = false;
     EXPECT_EQ(City3dInputBuilder::analyse(unreferenced.buildings.buildings[0], unreferenced.labels,
                                           unreferenced.semantics, unreferenced.surface, unreferenced.ndsm,
                                           unreferenced.metadata, config).reason, "not_georeferenced");

     Scene invalid;
     for (std::size_t i = 0; i < invalid.ndsm.data.size(); ++i)
          if (invalid.labels.data[i] == 7) invalid.ndsm.data[i] = std::nanf("");
     EXPECT_EQ(City3dInputBuilder::analyse(invalid.buildings.buildings[0], invalid.labels, invalid.semantics,
                                           invalid.surface, invalid.ndsm, invalid.metadata, config).reason,
               "insufficient_points");
}

// --- OBJ import ----------------------------------------------------------------

TEST(City3dSliceTest, ImportsGroupedObjAndRestoresTheOrigin)
{
     Scene scene;
     const City3dConfig config;
     const BuildingInstance& building = scene.buildings.buildings[0];
     const City3dCandidate candidate = City3dInputBuilder::analyse(
         building, scene.labels, scene.semantics, scene.surface, scene.ndsm, scene.metadata, config);
     const fs::path root = testRoot("import");
     writeResult(root / "result", "job-b7", 7, candidate, gableObj());

     const City3dImportResult result =
         City3dResultImporter::import(root / "result", "job-b7", building, candidate, kRenderScale, config);
     ASSERT_TRUE(result.accepted) << result.reason;
     const BuildingSurfaceShell& shell = result.shell;
     EXPECT_EQ(shell.vertices.size(), 10U);
     EXPECT_DOUBLE_EQ(shell.vertices[0].easting, candidate.originEasting - 10.0);
     EXPECT_DOUBLE_EQ(shell.vertices[0].northing, candidate.originNorthing - 7.5);
     EXPECT_DOUBLE_EQ(shell.vertices[8].elevation, 100.0 + 9.0); // metric, not render-scaled
     EXPECT_EQ(shell.roofIndices.size() / 3, 4U);  // two quads
     EXPECT_EQ(shell.wallIndices.size() / 3, 10U); // four quads + two gable triangles
     EXPECT_FLOAT_EQ(shell.renderHeightScale, kRenderScale);
     EXPECT_NEAR(result.roofTopMetres, 9.0, 1e-9);

     const auto reason = [&](const std::string& obj, const std::string& jobId = "job-b7", uint32_t id = 7,
                             const std::string& status = "success")
     {
          fs::remove_all(root / "bad");
          writeResult(root / "bad", jobId, id, candidate, obj, status);
          return City3dResultImporter::import(root / "bad", "job-b7", building, candidate, kRenderScale, config).reason;
     };
     EXPECT_EQ(reason(gableObj(), "job-b9"), "job_id_mismatch");
     EXPECT_EQ(reason(gableObj(), "job-b7", 8), "building_id_mismatch");
     EXPECT_EQ(reason("", "job-b7", 7, "timeout_no_solution"), "worker_timeout_no_solution");
     EXPECT_EQ(reason("v 0 0 nan\nv 1 0 0\nv 0 1 0\ng roof\nf 1 2 3\n"), "malformed_vertex");
     EXPECT_EQ(reason("v 0 0 6\nv 1 0 6\nv 0 1 6\ng roof\nf 1 2 4\n"), "invalid_index");
     EXPECT_EQ(reason("v 0 0 6\nv 1 0 6\nv 0 1 6\ng chimney\nf 1 2 3\n"), "unknown_group");
     EXPECT_EQ(reason("v 0 0 6\nv 1 0 6\nv 0 1 6\nf 1/1 2/2 3/3\n"), "face_without_group");
     EXPECT_EQ(reason("v 0 0 6\nv 1 0 6\nv 0 1 6\ng roof\nf 1 2 3\n"), "missing_roof_or_wall");
     EXPECT_EQ(reason(gableObj(16.0)), "height_out_of_bounds");      // above official + tolerance
     EXPECT_EQ(reason(gableObj(3.0, 2.0)), "height_disagreement");    // roof top 3 m vs official 9 m
     std::string far = gableObj();
     far.replace(far.find("v -10 -7.5 0"), 12, "v -40 -7.5 0");
     EXPECT_EQ(reason(far), "footprint_overflow");

     // Concave (L-shaped) polygons triangulate into n - 2 triangles.
     const auto triangles = City3dResultImporter::triangulatePolygon(
         {{0, 0, 5}, {10, 0, 5}, {10, 4, 5}, {4, 4, 5}, {4, 10, 5}, {0, 10, 5}});
     EXPECT_EQ(triangles.size(), 4U);
     fs::remove_all(root);
}

// --- Shell meshing ---------------------------------------------------------------

TEST(City3dSliceTest, MesherPrefersAValidShellAndKeepsIdsAndUvs)
{
     Scene scene;
     const City3dConfig config;
     BuildingInstance building = scene.buildings.buildings[0];
     const City3dCandidate candidate = City3dInputBuilder::analyse(
         building, scene.labels, scene.semantics, scene.surface, scene.ndsm, scene.metadata, config);
     const fs::path root = testRoot("meshing");
     writeResult(root / "result", "job-b7", 7, candidate, gableObj());
     City3dImportResult imported =
         City3dResultImporter::import(root / "result", "job-b7", building, candidate, kRenderScale, config);
     ASSERT_TRUE(imported.accepted) << imported.reason;
     fs::remove_all(root);

     LocalSceneFrame frame;
     frame.projectedOriginX = scene.metadata.geoTransform[0];
     frame.projectedOriginY = scene.metadata.geoTransform[3];
     frame.elevationOrigin = 100.0;
     BuildingMeshConfig meshConfig;
     meshConfig.flatPresentation = true;
     meshConfig.generateRoofUVs = true;
     meshConfig.generateWallUVs = true;

     BuildingCollection native;
     native.buildings = {building};
     const BuildingMesh nativeMesh = BuildingMesher::generate(native, frame, meshConfig, &scene.metadata);

     building.reconstructedShell = imported.shell;
     BuildingCollection shelled;
     shelled.buildings = {building};
     const BuildingMesh mesh = BuildingMesher::generate(shelled, frame, meshConfig, &scene.metadata);
     EXPECT_EQ(mesh.emittedBuildingIds, std::vector<uint32_t>{7});
     EXPECT_EQ(mesh.roofPrimitive.positions.size() / 9, 4U);  // shell roof triangles
     EXPECT_EQ(mesh.wallPrimitive.positions.size() / 9, 10U);
     EXPECT_NE(mesh.roofPrimitive.positions, nativeMesh.roofPrimitive.positions);
     for (float id : *mesh.roofPrimitive.featureIds) EXPECT_EQ(id, 7.0F);
     for (float id : *mesh.wallPrimitive.featureIds) EXPECT_EQ(id, 7.0F);

     // Ridge at 9 m metric renders at 9 x 2.25 in flat presentation, like native heights.
     float top = -1e9F;
     for (std::size_t i = 1; i < mesh.roofPrimitive.positions.size(); i += 3)
          top = std::max(top, mesh.roofPrimitive.positions[i]);
     EXPECT_NEAR(top, 9.0F * kRenderScale, 1e-3F);
     EXPECT_NEAR(top, building.heightAboveGround, 1e-3F);

     // Roof UVs are the inverse affine of each vertex (u = column / width, v = row / height).
     for (std::size_t vertex = 0; vertex < mesh.roofPrimitive.positions.size() / 3; ++vertex)
     {
          const double easting = mesh.roofPrimitive.positions[vertex * 3] + frame.projectedOriginX;
          const double northing = -mesh.roofPrimitive.positions[vertex * 3 + 2] + frame.projectedOriginY;
          const double column = (easting - scene.metadata.geoTransform[0]) / 0.5;
          const double row = (northing - scene.metadata.geoTransform[3]) / -0.5;
          EXPECT_NEAR((*mesh.roofPrimitive.uvs)[vertex * 2], column / kWidth, 1e-5);
          EXPECT_NEAR((*mesh.roofPrimitive.uvs)[vertex * 2 + 1], row / kHeight, 1e-5);
     }
     ASSERT_TRUE(mesh.wallPrimitive.uvs.has_value());
     EXPECT_EQ(mesh.wallPrimitive.uvs->size(), mesh.wallPrimitive.positions.size() / 3 * 2);
     EXPECT_FALSE(mesh.edgePrimitive.positions.empty()); // scientific creases

     // An empty shell falls back to the native path.
     building.reconstructedShell->roofIndices.clear();
     BuildingCollection fallback;
     fallback.buildings = {building};
     const BuildingMesh fallbackMesh = BuildingMesher::generate(fallback, frame, meshConfig, &scene.metadata);
     EXPECT_EQ(fallbackMesh.roofPrimitive.positions, nativeMesh.roofPrimitive.positions);
}

// --- Flags -------------------------------------------------------------------------

TEST(City3dSliceTest, FeatureIsOffByDefault)
{
     const auto parse = [](std::map<std::string, std::string> values)
     {
          return HybridFeatureFlags::parse([values](const std::string& name) -> std::optional<std::string>
          {
               const auto found = values.find(name);
               return found == values.end() ? std::nullopt : std::optional<std::string>(found->second);
          });
     };
     const HybridFeatureFlags defaults = parse({});
     EXPECT_FALSE(defaults.city3d);
     EXPECT_EQ(defaults.city3dMode, City3dMode::Shadow);
     EXPECT_TRUE(defaults.allDefault());
     const HybridFeatureFlags selected = parse({{"DEPTHWIZARD_CITY3D", "1"}, {"DEPTHWIZARD_CITY3D_MODE", "selected"}});
     EXPECT_TRUE(selected.city3d);
     EXPECT_EQ(selected.city3dMode, City3dMode::Selected);
     EXPECT_EQ(parse({{"DEPTHWIZARD_CITY3D_MODE", "all"}}).warnings.size(), 1U);
}

// --- Orchestration -------------------------------------------------------------------

TEST(City3dSliceTest, ShadowAndSelectedModesWithTheRealWorker)
{
     if (!realWorkerAvailable()) GTEST_SKIP() << "city3d_worker not built";
     Scene scene;
     const fs::path root = testRoot("orchestrator");
     const City3dConfig config = testConfig(root, kRealWorker);
     const BuildingCollection before = scene.buildings;
     const City3dRunSummary summary = City3dOrchestrator::run(
         scene.buildings, scene.labels, scene.semantics, scene.surface, scene.ndsm, scene.metadata,
         kRenderScale, config, "job");
     ASSERT_EQ(summary.outcomes.size(), 2U);
     std::map<uint32_t, City3dBuildingOutcome> outcomes;
     for (const auto& outcome : summary.outcomes) outcomes[outcome.buildingId] = outcome;
     EXPECT_EQ(outcomes[8].route, "not_eligible");
     EXPECT_EQ(outcomes[8].reason, "flat_roof");
     ASSERT_EQ(outcomes[7].route, "attempted");
     ASSERT_TRUE(outcomes[7].accepted) << outcomes[7].reason << "\n" << outcomes[7].logTail;
     EXPECT_EQ(outcomes[7].workerStatus, "success");
     EXPECT_LT(outcomes[7].elapsedMs, 12000);
     EXPECT_TRUE(fs::exists(root / "job" / "b7" / "worker.log"));

     // Shadow: the collection is untouched.
     EXPECT_FALSE(scene.buildings.buildings[0].reconstructedShell.has_value());
     // Selected: the shell is attached; official heights and footprints stay.
     BuildingCollection selected = scene.buildings;
     EXPECT_EQ(City3dOrchestrator::attachAcceptedShells(selected, summary), 1U);
     ASSERT_TRUE(selected.buildings[0].reconstructedShell.has_value());
     EXPECT_FALSE(selected.buildings[1].reconstructedShell.has_value());
     EXPECT_EQ(selected.buildings[0].heightAboveGround, before.buildings[0].heightAboveGround);
     EXPECT_EQ(selected.buildings[0].roofElevation, before.buildings[0].roofElevation);
     EXPECT_EQ(selected.buildings[0].projectedFootprint.outerRing.size(),
               before.buildings[0].projectedFootprint.outerRing.size());

     // The selected collection packs into a GLB with both buildings' feature IDs.
     MeshBuildConfig meshConfig;
     meshConfig.presentation = ScenePresentation::FLAT_URBAN;
     SceneInput input;
     input.width = kWidth;
     input.height = kHeight;
     input.spatialMetadata = scene.metadata;
     const GlbBuildResult glb = SceneMeshService::generateGlb(input, scene.surface, selected, scene.metadata, meshConfig);
     ASSERT_FALSE(glb.compressedGlbByteBuffer.empty());
     EXPECT_EQ(glb.buildingCount, 2U);
     const tinygltf::Model model = loadGlb(glb.compressedGlbByteBuffer);
     std::set<float> ids;
     for (float id : decodeDracoAttribute(model, model.meshes[0].primitives[1], "_FEATURE_ID_0")) ids.insert(id);
     EXPECT_EQ(ids, (std::set<float>{7.0F, 8.0F}));
     fs::remove_all(root);
}

TEST(City3dSliceTest, EveryWorkerFailureKeepsNativeGeometry)
{
     Scene scene;
     const fs::path root = testRoot("failures");
     const auto runWith = [&](const fs::path& binary, std::chrono::milliseconds timeout = std::chrono::milliseconds(12000))
     {
          City3dConfig config = testConfig(root / ("work_" + binary.filename().string()), binary);
          config.timeout = timeout;
          return City3dOrchestrator::run(scene.buildings, scene.labels, scene.semantics, scene.surface, scene.ndsm,
                                         scene.metadata, kRenderScale, config, "job");
     };
     const auto reasonFor7 = [](const City3dRunSummary& summary)
     {
          for (const auto& outcome : summary.outcomes)
               if (outcome.buildingId == 7) return outcome.reason;
          return std::string("missing");
     };

     const City3dRunSummary missing = runWith(root / "absent_worker");
     EXPECT_EQ(reasonFor7(missing), "worker_unavailable");
     const City3dRunSummary crash = runWith(script(root, "crash.sh", "echo boom >&2; exit 4"));
     EXPECT_EQ(reasonFor7(crash), "worker_exit_4");
     const auto started = std::chrono::steady_clock::now();
     const City3dRunSummary hang = runWith(script(root, "hang.sh", "sleep 30"), std::chrono::milliseconds(1000));
     EXPECT_EQ(reasonFor7(hang), "worker_timeout");
     EXPECT_LT(std::chrono::steady_clock::now() - started, std::chrono::seconds(5)); // killed, not waited for
     const City3dRunSummary garbage = runWith(script(root, "garbage.sh",
         "mkdir -p \"$4\" && echo 'not json' > \"$4/result.json\""));
     EXPECT_EQ(reasonFor7(garbage), "malformed_manifest");
     const City3dRunSummary wrongId = runWith(script(root, "wrong_id.sh",
         "mkdir -p \"$4\" && printf '{\"schema\":\"depthwizard.city3d-result.v1\",\"job_id\":\"job-b7\","
         "\"building_id\":99,\"status\":\"success\",\"mesh\":\"building.obj\"}' > \"$4/result.json\""));
     EXPECT_EQ(reasonFor7(wrongId), "building_id_mismatch");
     for (const auto* summary : {&missing, &crash, &hang, &garbage, &wrongId})
          EXPECT_TRUE(summary->acceptedShells.empty());

     // One building failing never affects another: a second gable keeps its result.
     if (realWorkerAvailable())
     {
          Scene two;
          for (std::size_t i = 0; i < two.labels.data.size(); ++i)
               if (two.labels.data[i] == 8) two.ndsm.data[i] = two.ndsm.data[i - 40]; // copy the gable
          two.buildings.buildings[1].heightAboveGround = 9.0F * kRenderScale;
          const fs::path mixed = script(root, "mixed.sh",
              "case \"$2\" in *b7/*) exit 3;; esac\nexec '" + kRealWorker.string() + "' \"$@\"");
          City3dConfig config = testConfig(root / "mixed", mixed);
          const City3dRunSummary summary = City3dOrchestrator::run(
              two.buildings, two.labels, two.semantics, two.surface, two.ndsm, two.metadata, kRenderScale, config, "job");
          std::map<uint32_t, City3dBuildingOutcome> outcomes;
          for (const auto& outcome : summary.outcomes) outcomes[outcome.buildingId] = outcome;
          EXPECT_EQ(outcomes[7].reason, "worker_exit_3");
          EXPECT_TRUE(outcomes[8].accepted) << outcomes[8].reason << "\n" << outcomes[8].logTail;
          EXPECT_EQ(summary.acceptedShells.count(7), 0U);
          EXPECT_EQ(summary.acceptedShells.count(8), 1U);
     }
     fs::remove_all(root);
}

TEST(City3dSliceTest, BuildingBudgetLimitsAttempts)
{
     Scene scene;
     // Six more gable buildings stacked below, each its own label.
     const fs::path root = testRoot("budget");
     City3dConfig config = testConfig(root, root / "absent_worker");
     config.maxBuildings = 1;
     BuildingCollection twin = scene.buildings;
     twin.buildings[1] = scene.buildings.buildings[0];
     twin.buildings[1].buildingId = 9; // No pixels carry label 9
     const City3dRunSummary summary = City3dOrchestrator::run(
         twin, scene.labels, scene.semantics, scene.surface, scene.ndsm, scene.metadata, kRenderScale, config, "job");
     std::map<uint32_t, std::string> routes;
     for (const auto& outcome : summary.outcomes) routes[outcome.buildingId] = outcome.route + "/" + outcome.reason;
     EXPECT_EQ(routes[7], "attempted/worker_unavailable");
     EXPECT_EQ(routes[9], "not_eligible/insufficient_points");
     fs::remove_all(root);
}
