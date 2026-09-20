# Bumped to 3.10 to remove the CMake deprecation warning you saw
cmake_minimum_required(VERSION 3.10) 
project(gis_service_test CXX)

# 1. Existing Drogon API Tests
add_executable(${PROJECT_NAME} test_main.cc)
target_link_libraries(${PROJECT_NAME} PRIVATE Drogon::Drogon)
ParseAndAddDrogonTests(${PROJECT_NAME})

# 2. Metric Stitcher Google Test Binary
find_package(GTest REQUIRED)
find_package(OpenMP REQUIRED)

# Compile BOTH the test file and the actual implementation file
add_executable(metric_output_stitcher_test 
    MetricOutputStitcher_test.cc
    ../ImageTilingService/OutputStitching/MetricOutputStitcher.cc
)

# Tell the test binary where to find the headers
target_include_directories(metric_output_stitcher_test PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/..
    ${CMAKE_CURRENT_SOURCE_DIR}/../structures
    ${CMAKE_CURRENT_SOURCE_DIR}/../utils
)

# Link Drogon, GTest, and OpenMP multithreading
target_link_libraries(metric_output_stitcher_test 
    PRIVATE 
    Drogon::Drogon 
    GTest::gtest 
    GTest::gtest_main
    OpenMP::OpenMP_CXX
)

# 3. NEW: Building Reconstruction OpenCV Tests
find_package(OpenCV REQUIRED COMPONENTS core imgproc)

add_executable(building_reconstruction_test
    BuildingReconstruction_test.cc
    ../BuildingReconstruction/BuildingMaskProcessor.cc
    ../BuildingReconstruction/BuildingInstanceExtractor.cc
)

# Tell the test binary where to find the headers and OpenCV
target_include_directories(building_reconstruction_test PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/..
    ${CMAKE_CURRENT_SOURCE_DIR}/../structures
    ${OpenCV_INCLUDE_DIRS}
)

# Link Drogon, GTest, and OpenCV
target_link_libraries(building_reconstruction_test 
    PRIVATE 
    Drogon::Drogon 
    GTest::gtest 
    GTest::gtest_main 
    ${OpenCV_LIBS}
)