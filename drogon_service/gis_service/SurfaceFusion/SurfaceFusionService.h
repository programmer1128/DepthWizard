// absolute elevation pipeline
// it strictly superimposes the corrected AI heights (nDSM) onto the pure terrain base (DTM) 
// to construct the final, absolute Digital Surface Model (DSM)

#pragma once

#include "../structures/SurfaceStructs.h"
#include "../structures/GeographicStructs.h"
#include "../ReferenceTerrainService/ReferenceDemPreprocessor.h"
#include "SurfaceFusionConfig.h"

class SurfaceFusionService 
{
    public:
    
    // Computes DSM = DTM + semantically valid nDSM and calculates unified
    // confidence. Ground, roads and water receive zero above-ground height.
    
    // correctedNdsm: the above-ground heights after Ground Bias correction
    // reference: the prepared bare-earth DTM (Raster grids and metadata)
    // semantics: the semantic probability maps (used to weigh confidence)
    // aiConfidence: the raw neural network confidence map
    // metadata: the overarching spatial configuration of the entire scene.

    // GeoreferencedSurfaceBundle: finalized suite of elevation and validity maps ready for Meshing and GIS Export

    static GeoreferencedSurfaceBundle composeMetricSurface(
        const RasterGrid<float>& correctedNdsm,
        const ReferenceTerrainBundle& reference,
        const SemanticScene& semantics,
        const RasterGrid<float>& aiConfidence,
        const SpatialMetadata& metadata,
        const SurfaceFusionConfig& config = SurfaceFusionConfig{});
};
