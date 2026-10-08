#pragma once

#include <gdal_priv.h>
#include <memory>

// custom deleter to automatically close GDAL datasets
struct GDALDatasetDeleter
{
    void operator()(GDALDataset *ds) const
    {
        if (ds)
            GDALClose(ds);
    }
};

// wrapper that holds a GDALDataset* - for simplicity of usage

using GDALDatasetPtr = std::unique_ptr<GDALDataset, GDALDatasetDeleter>;