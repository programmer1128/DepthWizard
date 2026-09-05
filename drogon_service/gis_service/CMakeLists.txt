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

#draco compression library for compressing .glb file
find_package(draco CONFIG REQUIRED)

#MiniIO config SDK
find_package(AWSSDK REQUIRED COMPONENTS s3)

#Multithreading support added
find_package(OpenMP REQUIRED)

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
file(GLOB MESH_SRC CONFIGURE_DEPENDS "MeshMapping/*.cc" "MeshMapping/*.cpp")
file(GLOB FILE_GENERATOR_SRC CONFIGURE_DEPENDS "FileGenerators/*.cc" "FileGenerators/*.cpp")
file(GLOB UV_MAPPING CONFIGURE_DEPENDS "UVMapping/*.cc" "UVMapping/*.cpp")
file(GLOB COMPRESSOR CONFIGURE_DEPENDS "CompressionLib/*.cc" "CompressionLib/*.cpp")
file(GLOB DATA_HANDLERS CONFIGURE_DEPENDS "DataHandlers/*.cc" "DataHandlers/*.cpp")
file(GLOB IMAGE_TILER CONFIGURE_DEPENDS "ImageTilingService/*.cc" "ImageTilingService/*.cpp")


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
               ${MESH_SRC}
               ${FILE_GENERATOR_SRC}
               ${UV_MAPPING}
               ${COMPRESSOR}
               ${DATA_HANDLERS}
               ${IMAGE_TILER})

# Add all specific folders to the include path so `#include "srtmExtractor.h"` works anywhere
#add folder here too for target directories to be linked during compilation and enabled globally
target_include_directories(${PROJECT_NAME}
                           PRIVATE 
                           ${CMAKE_CURRENT_SOURCE_DIR}
                           ${CMAKE_CURRENT_SOURCE_DIR}/include
                           ${CMAKE_CURRENT_SOURCE_DIR}/CalibrationController
                           ${CMAKE_CURRENT_SOURCE_DIR}/SrtmExtractor
                           ${CMAKE_CURRENT_SOURCE_DIR}/RasterProcessor
                           ${CMAKE_CURRENT_SOURCE_DIR}/RansacCalibrator
                           ${CMAKE_CURRENT_SOURCE_DIR}/GdalWriter
                           ${CMAKE_CURRENT_SOURCE_DIR}/MeshMapping
                           ${CMAKE_CURRENT_SOURCE_DIR}/utils
                           ${CMAKE_CURRENT_SOURCE_DIR}/plugins
                           ${CMAKE_CURRENT_SOURCE_DIR}/FileGenerators
                           ${CMAKE_CURRENT_SOURCE_DIR}/UVMapping
                           ${CMAKE_CURRENT_SOURCE_DIR}/CompressionLib
                           ${CMAKE_CURRENT_SOURCE_DIR}/DataHandlers
                           ${CMAKE_CURRENT_SOURCE_DIR}/ImageTilingService
                           ${CMAKE_CURRENT_SOURCE_DIR}/structures
                           ${GDAL_INCLUDE_DIRS}) # Bind GDAL headers


#LINK LIBRARIES TO THE TARGET
target_link_libraries(${PROJECT_NAME} PRIVATE 
    Drogon::Drogon 
    ZLIB::ZLIB
    ${GDAL_LIBRARIES} # Bind the GDAL binary
    draco
    ${AWSSDK_LINK_LIBRARIES} #AWS sdk C++ lib for MiniIO client
    OpenMP::OpenMP_CXX #OpenMp Multi threading 
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