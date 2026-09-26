cmake_minimum_required(VERSION 3.20)

find_package(GTest REQUIRED)
find_package(OpenCV REQUIRED COMPONENTS core imgproc imgcodecs photo)
include(GoogleTest)

option(
    DEPTHWIZARD_ENABLE_TEST_SANITIZERS
    "Enable AddressSanitizer and UndefinedBehaviorSanitizer for unit tests"
    ON
)

if(TARGET GDAL::GDAL)
    set(DEPTHWIZARD_GDAL_TARGET GDAL::GDAL)
else()
    set(DEPTHWIZARD_GDAL_TARGET ${GDAL_LIBRARIES})
endif()

function(configure_depthwizard_test target_name)
    target_compile_features(${target_name} PRIVATE cxx_std_23)

    target_include_directories(
        ${target_name}
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/..
        ${GDAL_INCLUDE_DIRS}
    )

    target_compile_options(
        ${target_name}
        PRIVATE
        -Wall
        -Wextra
        -Wpedantic
    )

    if(
        DEPTHWIZARD_ENABLE_TEST_SANITIZERS
        AND CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang"
    )
        target_compile_options(
            ${target_name}
            PRIVATE
            -fsanitize=address,undefined
            -fno-omit-frame-pointer
        )

        target_link_options(
            ${target_name}
            PRIVATE
            -fsanitize=address,undefined
        )
    endif()
endfunction()

add_executable(
    srtm_extractor_test
    SrtmExtractor_test.cc
    ../SrtmExtractor/SrtmExtractor.cc
)

configure_depthwizard_test(srtm_extractor_test)

target_link_libraries(
    srtm_extractor_test
    PRIVATE
    GTest::gtest_main
    Drogon::Drogon
    ${DEPTHWIZARD_GDAL_TARGET}
)

gtest_discover_tests(
    srtm_extractor_test
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    DISCOVERY_MODE PRE_TEST
)

add_executable(
    metric_output_stitcher_test
    MetricOutputStitcher_test.cc
    ../ImageTilingService/OutputStitching/MetricOutputStitcher.cc
)

configure_depthwizard_test(metric_output_stitcher_test)

target_link_libraries(
    metric_output_stitcher_test
    PRIVATE
    GTest::gtest_main
    Drogon::Drogon
    OpenMP::OpenMP_CXX
)

gtest_discover_tests(
    metric_output_stitcher_test
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    DISCOVERY_MODE PRE_TEST
)

add_executable(
    reference_dem_preprocessor_test
    ReferenceDemPreprocessor_test.cc
    ../ReferenceTerrainService/ReferenceDemPreprocessor.cc
)

configure_depthwizard_test(reference_dem_preprocessor_test)
target_include_directories(reference_dem_preprocessor_test PRIVATE ${OpenCV_INCLUDE_DIRS})

target_link_libraries(
    reference_dem_preprocessor_test
    PRIVATE
    ${OpenCV_LIBS}
    GTest::gtest_main
    Drogon::Drogon
    OpenMP::OpenMP_CXX
)

gtest_discover_tests(
    reference_dem_preprocessor_test
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    DISCOVERY_MODE PRE_TEST
)



add_executable(
    metric_reference_orchestrator_test
    MetricReferenceOrchestrator_test.cc
    ../ReferenceTerrainService/MetricReferenceOrchestrator.cc
)

configure_depthwizard_test(metric_reference_orchestrator_test)

target_link_libraries(
    metric_reference_orchestrator_test
    PRIVATE
    GTest::gtest_main
    Drogon::Drogon
    ${DEPTHWIZARD_GDAL_TARGET}
)

gtest_discover_tests(
    metric_reference_orchestrator_test
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    DISCOVERY_MODE PRE_TEST
)

function(add_depthwizard_grid_test target_name test_source production_source)
    add_executable(
        ${target_name}
        ${test_source}
        ${production_source}
    )

    configure_depthwizard_test(${target_name})

    target_link_libraries(
        ${target_name}
        PRIVATE
        GTest::gtest_main
        OpenMP::OpenMP_CXX
    )

    gtest_discover_tests(
        ${target_name}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        DISCOVERY_MODE PRE_TEST
    )
endfunction()

add_depthwizard_grid_test(
    semantic_post_processor_test
    SemanticPostProcessor_test.cc
    ../SemanticContext/SemanticPostProcessor.cc
)

add_depthwizard_grid_test(
    ground_surface_service_test
    GroundSurfaceService_test.cc
    ../SemanticContext/GroundSurfaceService.cc
)

add_depthwizard_grid_test(
    ndsm_ground_bias_corrector_test
    NdsmGroundBiasCorrector_test.cc
    ../SurfaceFusion/NdsmGroundBiasCorrector.cc
)

add_depthwizard_grid_test(
    surface_fusion_service_test
    SurfaceFusionService_test.cc
    ../SurfaceFusion/SurfaceFusionService.cc
)

add_executable(
    dual_model_stitchers_test
    DualModelStitchers_test.cc
    ../ImageTilingService/OutputStitching/NdsmOutputStitcher.cc
    ../ImageTilingService/OutputStitching/SemanticOutputStitcher.cc
    ../ImageTilingService/Tiling/TileDispatcher.cc
    ../ImageTilingService/InferenceProtocol/InferenceClient.cc
    ../SemanticContext/SemanticPostProcessor.cc
)

configure_depthwizard_test(dual_model_stitchers_test)

target_link_libraries(
    dual_model_stitchers_test
    PRIVATE
    GTest::gtest_main
    Drogon::Drogon
    OpenMP::OpenMP_CXX
)

gtest_discover_tests(
    dual_model_stitchers_test
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    DISCOVERY_MODE PRE_TEST
)

add_depthwizard_grid_test(
    image_preprocessing_service_test
    ImagePreprocessingService_test.cc
    ../ImagePreprocessing/ImagePreprocessingService.cc
)

target_link_libraries(
    image_preprocessing_service_test
    PRIVATE
    Drogon::Drogon
    ${DEPTHWIZARD_GDAL_TARGET}
)

add_depthwizard_grid_test(
    raster_ingest_service_test
    RasterIngestService_test.cc
    ../ImagePreprocessing/RasterIngestService.cc
)

target_link_libraries(
    raster_ingest_service_test
    PRIVATE
    Drogon::Drogon
    ${DEPTHWIZARD_GDAL_TARGET}
)

function(add_building_reconstruction_test target_name test_source)
    add_executable(
        ${target_name}
        ${test_source}
        ${ARGN}
    )

    configure_depthwizard_test(${target_name})

    target_include_directories(
        ${target_name}
        PRIVATE
        ${OpenCV_INCLUDE_DIRS}
    )

    target_link_libraries(
        ${target_name}
        PRIVATE
        GTest::gtest_main
        ${OpenCV_LIBS}
    )

    gtest_discover_tests(
        ${target_name}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        DISCOVERY_MODE PRE_TEST
    )
endfunction()

add_building_reconstruction_test(
    building_mask_processor_test
    BuildingMaskProcessor_test.cc
    ../BuildingReconstruction/BuildingMaskProcessor.cc
)

add_building_reconstruction_test(
    building_instance_extractor_test
    BuildingInstanceExtractor_test.cc
    ../BuildingReconstruction/BuildingInstanceExtractor.cc
    ../BuildingReconstruction/BuildingInstanceSplitter.cc
)

add_building_reconstruction_test(
    footprint_vectorizer_test
    FootprintVectorizer_test.cc
    ../BuildingReconstruction/FootprintVectorizer.cc
)

add_building_reconstruction_test(
    building_height_estimator_test
    BuildingHeightEstimator_test.cc
    ../BuildingReconstruction/BuildingHeightEstimator.cc
)

add_building_reconstruction_test(
    building_reconstruction_service_test
    BuildingReconstructionService_test.cc
    ../BuildingReconstruction/BuildingReconstructionService.cc
    ../BuildingReconstruction/BuildingMaskProcessor.cc
    ../BuildingReconstruction/BuildingInstanceExtractor.cc
    ../BuildingReconstruction/BuildingInstanceSplitter.cc
    ../BuildingReconstruction/FootprintVectorizer.cc
    ../BuildingReconstruction/BuildingHeightEstimator.cc
)

add_executable(
    mesh_pipeline_test
    MeshPipeline_test.cc
    ../CompressionLib/DracoCompressor.cc
    ../FileGenerators/GltfPackager.cc
    ../MeshMapping/BuildingMesher.cc
    ../MeshMapping/LocalFrameTransformers.cc
    ../MeshMapping/TerrainMesher.cc
    ../MeshMapping/TerrainSurfaceComposer.cc
    ../MeshMapping/TerrainTextureComposer.cc
)

configure_depthwizard_test(mesh_pipeline_test)

target_include_directories(
    mesh_pipeline_test
    PRIVATE
    ${OpenCV_INCLUDE_DIRS}
)

target_link_libraries(
    mesh_pipeline_test
    PRIVATE
    GTest::gtest_main
    draco
    ${OpenCV_LIBS}
    opencv_imgcodecs # Encode the optical texture fixture for GLB sampler tests.
)

gtest_discover_tests(
    mesh_pipeline_test
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    DISCOVERY_MODE PRE_TEST
)

add_executable(urban_scene_integration_test
    UrbanSceneIntegration_test.cc
    ../BuildingReconstruction/BuildingMaskProcessor.cc
    ../BuildingReconstruction/BuildingInstanceExtractor.cc
    ../BuildingReconstruction/BuildingInstanceSplitter.cc
    ../BuildingReconstruction/FootprintVectorizer.cc
    ../BuildingReconstruction/BuildingHeightEstimator.cc
    ../BuildingReconstruction/BuildingReconstructionService.cc
    ../SurfaceFusion/SurfaceFusionService.cc
    ../MeshMapping/SceneMeshService.cc
    ../MeshMapping/ScenePresentationSelector.cc
    ../MeshMapping/SceneAssembler.cc
    ../MeshMapping/BuildingMesher.cc
    ../MeshMapping/LocalFrameTransformers.cc
    ../MeshMapping/TerrainMesher.cc
    ../MeshMapping/TerrainSurfaceComposer.cc
    ../MeshMapping/TerrainTextureComposer.cc
    ../CompressionLib/DracoCompressor.cc
    ../FileGenerators/GltfPackager.cc)
configure_depthwizard_test(urban_scene_integration_test)
target_include_directories(urban_scene_integration_test PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(urban_scene_integration_test PRIVATE
    GTest::gtest_main draco ${OpenCV_LIBS} OpenMP::OpenMP_CXX)
gtest_discover_tests(urban_scene_integration_test
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR} DISCOVERY_MODE PRE_TEST)

add_executable(reconstruction_diagnostics_test ReconstructionDiagnostics_test.cc
    ../FileGenerators/ReconstructionDiagnosticsWriter.cc)
configure_depthwizard_test(reconstruction_diagnostics_test)
target_link_libraries(reconstruction_diagnostics_test PRIVATE
    GTest::gtest_main Drogon::Drogon ${DEPTHWIZARD_GDAL_TARGET})
gtest_discover_tests(reconstruction_diagnostics_test
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR} DISCOVERY_MODE PRE_TEST)

add_executable(scene_presentation_selector_test ScenePresentationSelector_test.cc
    ../MeshMapping/ScenePresentationSelector.cc)
configure_depthwizard_test(scene_presentation_selector_test)
target_link_libraries(scene_presentation_selector_test PRIVATE GTest::gtest_main)
gtest_discover_tests(scene_presentation_selector_test
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR} DISCOVERY_MODE PRE_TEST)
