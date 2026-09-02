cmake_minimum_required(VERSION 3.10)
project(gis_service CXX)

#C++20 for Coroutines and modern features
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(CheckIncludeFileCXX)

#
#FIND EXTERNAL DEPENDENCIES
find_package(Drogon CONFIG REQUIRED)
find_package(ZLIB REQUIRED)
# Crucial for Geospatial Matrix warping and AWS Tile streaming
find_package(GDAL REQUIRED) 

#SOURCE FILE DISCOVERY (Package-by-Feature Architecture)
# Explicitly grab sources from each dedicated service folder

#if new folder created then add source here in same format
file(GLOB CONTROLLER_SRC CONFIGURE_DEPENDS "CalibrationController/*.cc" "CalibrationController/*.cpp")
file(GLOB EXTRACTOR_SRC CONFIGURE_DEPENDS "SrtmExtractor/*.cc" "SrtmExtractor/*.cpp")
file(GLOB PROCESSOR_SRC CONFIGURE_DEPENDS "RasterProcessor/*.cc" "RasterProcessor/*.cpp")
file(GLOB RANSAC_SRC CONFIGURE_DEPENDS "RansacCalibrator/*.cc" "RansacCalibrator/*.cpp")
file(GLOB WRITER_SRC CONFIGURE_DEPENDS "GdalWriter/*.cc" "GdalWriter/*.cpp")
file(GLOB UTILS_SRC CONFIGURE_DEPENDS "utils/*.cc" "utils/*.cpp")
file(GLOB PLUGINS_SRC CONFIGURE_DEPENDS "plugins/*.cc" "plugins/*.cpp")
file(GLOB UVMAPPER_SRC CONFIGURE_DEPENDS "UVMapping/*.cc" "UVMapping/*.cpp")


#COMPILER OPTIMIZATIONS (Release Mode)
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    message(STATUS "Release build detected: Enabling -O3, LTO, and Native CPU optimizations.")
    
    # Maximum optimization, Link-Time Optimization (LTO), and native CPU instructions
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -march=native -flto")
    set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -s")
endif()

#EXECUTABLE TARGET & INCLUDES
add_executable(${PROJECT_NAME} main.cc)

# Generate views (if using Drogon CSP templates)
drogon_create_views(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/views
                    ${CMAKE_CURRENT_BINARY_DIR})

# Link all discovered feature sources to the executable
target_sources(${PROJECT_NAME}
               PRIVATE
               ${CONTROLLER_SRC}
               ${EXTRACTOR_SRC}
               ${PROCESSOR_SRC}
               ${RANSAC_SRC}
               ${WRITER_SRC}
               ${UTILS_SRC}
               ${PLUGINS_SRC}
               ${UVMAPPER_SRC})

# Add all specific folders to the include path so `#include "srtmExtractor.h"` works anywhere
#add folder here too for target directories to be linked during compilation and enabled globally
target_include_directories(${PROJECT_NAME}
                           PRIVATE 
                           ${CMAKE_CURRENT_SOURCE_DIR}
                           ${CMAKE_CURRENT_SOURCE_DIR}/CalibrationController
                           ${CMAKE_CURRENT_SOURCE_DIR}/SrtmExtractor
                           ${CMAKE_CURRENT_SOURCE_DIR}/RasterProcessor
                           ${CMAKE_CURRENT_SOURCE_DIR}/RansacCalibrator
                           ${CMAKE_CURRENT_SOURCE_DIR}/GdalWriter
                           ${CMAKE_CURRENT_SOURCE_DIR}/utils
                           ${CMAKE_CURRENT_SOURCE_DIR}/plugins
                           ${CMAKE_CURRENT_SOURCE_DIR}/UVMapping
                           ${GDAL_INCLUDE_DIRS}) # Bind GDAL headers


#LINK LIBRARIES TO THE TARGET
target_link_libraries(${PROJECT_NAME} PRIVATE 
    Drogon::Drogon 
    ZLIB::ZLIB
    ${GDAL_LIBRARIES} # Bind the GDAL binary
)

if (CMAKE_CXX_STANDARD LESS 20)
    message(FATAL_ERROR "C++20 is required for coroutines")
else ()
    message(STATUS "Using C++20 standard with Coroutines enabled.")
endif ()

# Optional test directory
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/test/CMakeLists.txt")
    add_subdirectory(test)
endif()