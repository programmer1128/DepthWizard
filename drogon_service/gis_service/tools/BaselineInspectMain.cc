// baseline_inspect: deterministic JSON reports for the baseline harness.
//   baseline_inspect glb <file.glb>
//   baseline_inspect raster <file.tif>
#include "BaselineInspector.h"

#include <gdal_priv.h>
#include <json/writer.h>

#include <iostream>
#include <string>

int main(int argc, char** argv)
{
    if (argc != 3 || (std::string(argv[1]) != "glb" && std::string(argv[1]) != "raster"))
    {
        std::cerr << "usage: baseline_inspect glb|raster <file>\n";
        return 2;
    }
    try
    {
        GDALAllRegister();
        const Json::Value report = std::string(argv[1]) == "glb"
            ? BaselineInspector::inspectGlbFile(argv[2])
            : BaselineInspector::inspectRaster(argv[2]);
        Json::StreamWriterBuilder writer;
        writer["indentation"] = "  ";
        std::cout << Json::writeString(writer, report) << "\n";
        return 0;
    }
    catch (const std::exception& error)
    {
        std::cerr << "baseline_inspect: " << error.what() << "\n";
        return 1;
    }
}
