cmake_minimum_required(VERSION 3.10)
project(gis_service_test CXX)

# 1. Existing Drogon API Tests
add_executable(${PROJECT_NAME} test_main.cc)
target_link_libraries(${PROJECT_NAME} PRIVATE Drogon::Drogon)
ParseAndAddDrogonTests(${PROJECT_NAME})

# 2. Find Global Test Dependencies
find_package(GTest REQUIRED)
find_package(OpenMP REQUIRED)
find_package(GDAL REQUIRED)
find_package(AWSSDK REQUIRED COMPONENTS s3)
find_package(OpenCV REQUIRED COMPONENTS core imgproc)

# ---------------------------------------------------------------------------
# 3. Image Preprocessing & Ingest Tests (Module 1)
# ---------------------------------------------------------------------------

# Automatically grab all utility files (which contains the STB implementation)
file(GLOB UTILS_SRC CONFIGURE_DEPENDS "../utils/*.cc" "../utils/*.cpp")

add_executable(image_preprocessing_test
    ImagePreprocessing_test.cc
    ../ImagePreprocessing/ImagePreprocessingService.cc
    ../ImagePreprocessing/RasterIngestService.cc
    ../DataHandlers/MiniIOClient.cc
    ../FileGenerators/GltfPackager.cc
    ${UTILS_SRC}
)

target_include_directories(image_preprocessing_test PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/..
    ${GDAL_INCLUDE_DIRS}
)
target_link_libraries(image_preprocessing_test PRIVATE 
    Drogon::Drogon
    GTest::gtest GTest::gtest_main
    ${GDAL_LIBRARIES} 
    ${AWSSDK_LINK_LIBRARIES}
    OpenMP::OpenMP_CXX
)

# ---------------------------------------------------------------------------
# 4. Metric Output Stitcher Tests (Module 2)
# ---------------------------------------------------------------------------
add_executable(metric_output_stitcher_test
    MetricOutputStitcher_test.cc
    ../ImageTilingService/OutputStitching/MetricOutputStitcher.cc
)
target_include_directories(metric_output_stitcher_test PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/..
    ${CMAKE_CURRENT_SOURCE_DIR}/../structures
    ${CMAKE_CURRENT_SOURCE_DIR}/../utils
)
target_link_libraries(metric_output_stitcher_test PRIVATE 
    Drogon::Drogon
    GTest::gtest GTest::gtest_main
    OpenMP::OpenMP_CXX
)

# ---------------------------------------------------------------------------
# 5. Building Reconstruction Tests (Module 3)
# ---------------------------------------------------------------------------
add_executable(building_reconstruction_test
    BuildingReconstruction_test.cc
    ../BuildingReconstruction/BuildingMaskProcessor.cc
    ../BuildingReconstruction/BuildingInstanceExtractor.cc
)
target_include_directories(building_reconstruction_test PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/..
    ${CMAKE_CURRENT_SOURCE_DIR}/../structures
    ${OpenCV_INCLUDE_DIRS}
)
target_link_libraries(building_reconstruction_test PRIVATE 
    Drogon::Drogon
    GTest::gtest GTest::gtest_main
    ${OpenCV_LIBS}
)