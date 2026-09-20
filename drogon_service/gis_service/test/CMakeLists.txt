cmake_minimum_required(VERSION 3.10)
project(gis_service_test CXX)

# 1. Existing Drogon API Tests
add_executable(${PROJECT_NAME} test_main.cc)
target_link_libraries(${PROJECT_NAME} PRIVATE Drogon::Drogon)
ParseAndAddDrogonTests(${PROJECT_NAME})

# 2. Find Dependencies
find_package(GTest REQUIRED)
find_package(GDAL REQUIRED)
find_package(OpenMP REQUIRED)

# 3. Image Preprocessing Tests (Module 1)
add_executable(image_preprocessing_test
    ImagePreprocessing_test.cc
    ../ImagePreprocessing/ImagePreprocessingService.cc
)

# Tell the test binary where to find the headers
target_include_directories(image_preprocessing_test PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/..
    ${GDAL_INCLUDE_DIRS}
)

# Link Drogon, GTest, GDAL, and OpenMP multithreading
target_link_libraries(image_preprocessing_test PRIVATE 
    Drogon::Drogon
    GTest::gtest 
    GTest::gtest_main
    ${GDAL_LIBRARIES} 
    OpenMP::OpenMP_CXX
)