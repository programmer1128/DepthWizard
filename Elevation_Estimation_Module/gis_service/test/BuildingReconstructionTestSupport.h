#pragma once

#include "BuildingReconstruction/BuildingReconstructionConfig.h"
#include "BuildingReconstruction/BuildingReconstructionTypes.h"
#include "TestGridSupport.h"
#include "structures/GeographicStructs.h"
#include "structures/SurfaceStructs.h"

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <vector>

namespace depthwizard::test
{

inline SpatialMetadata makeProjectedMetadata(
    int width,
    int height,
    double pixelWidth = 1.0,
    double pixelHeight = 1.0)
{
    SpatialMetadata metadata;
    metadata.width = width;
    metadata.height = height;
    metadata.geoTransform = {
        500000.0,
        pixelWidth,
        0.0,
        2000000.0,
        0.0,
        pixelHeight};
    metadata.projectionRef = "PROJCS[\"Mock metric CRS\"]";
    metadata.pixelSizeX = std::abs(pixelWidth);
    metadata.pixelSizeY = std::abs(pixelHeight);
    metadata.gsd = std::sqrt(std::abs(pixelWidth * pixelHeight));
    metadata.isGeoreferenced = true;
    return metadata;
}

inline SemanticScene makeSemanticScene(
    int width,
    int height,
    SemanticClass initialClass = SemanticClass::GROUND)
{
    SemanticScene scene;
    scene.groundProbability = makeConstantGrid(width, height, 0.0F);
    scene.buildingProbability = makeConstantGrid(width, height, 0.0F);
    scene.roadProbability = makeConstantGrid(width, height, 0.0F);
    scene.vegetationProbability = makeConstantGrid(width, height, 0.0F);
    scene.waterProbability = makeConstantGrid(width, height, 0.0F);
    scene.unknownProbability = makeConstantGrid(width, height, 0.0F);
    scene.semanticConfidence = makeConstantGrid(width, height, 1.0F);
    scene.finalClassMap =
        makeConstantGrid<SemanticClass>(width, height, initialClass);
    return scene;
}

inline GeoreferencedSurfaceBundle makeSurface(
    int width,
    int height,
    float dtmValue,
    float ndsmValue)
{
    GeoreferencedSurfaceBundle surface;
    surface.spatialMetadata = makeProjectedMetadata(width, height);
    surface.dtm = makeConstantGrid(width, height, dtmValue);
    surface.ndsm = makeConstantGrid(width, height, ndsmValue);
    surface.dsm = makeConstantGrid(width, height, dtmValue + ndsmValue);
    surface.surfaceConfidence = makeConstantGrid(width, height, 1.0F);
    surface.validMask = makeConstantGrid<uint8_t>(width, height, uint8_t{1});
    surface.elevationUnit = ElevationUnit::METERS;
    return surface;
}

template<typename T>
void fillRectangle(
    RasterGrid<T>& grid,
    int left,
    int top,
    int rightExclusive,
    int bottomExclusive,
    const T& value)
{
    for (int row = top; row < bottomExclusive; ++row)
    {
        for (int column = left; column < rightExclusive; ++column)
        {
            grid.data[static_cast<std::size_t>(row) * grid.width + column] = value;
        }
    }
}

inline double projectedRingArea(const std::vector<ProjectedPoint>& ring)
{
    if (ring.size() < 3)
    {
        return 0.0;
    }

    const double originEasting = ring.front().easting;
    const double originNorthing = ring.front().northing;
    double twiceArea = 0.0;
    for (std::size_t index = 0; index < ring.size(); ++index)
    {
        const ProjectedPoint& current = ring[index];
        const ProjectedPoint& next = ring[(index + 1) % ring.size()];
        twiceArea +=
            (current.easting - originEasting) *
                (next.northing - originNorthing) -
            (next.easting - originEasting) *
                (current.northing - originNorthing);
    }
    return std::abs(twiceArea) * 0.5;
}

inline BuildingReconstructionConfig noMorphologyConfig()
{
    BuildingReconstructionConfig config;
    config.openingRadiusMetres = 0.0F;
    config.closingRadiusMetres = 0.0F;
    config.minBuildingAreaSquareMetres = 0.0F;
    config.footprintSimplificationToleranceMetres = 0.0F;
    config.footprintAreaDeviationTolerance = 0.01F;
    config.minHoleAreaSquareMetres = 1.0F;
    config.footprintDilationMetres = 0.0F;
    config.heightScaleMultiplier = 1.0F;
    config.regularizeRectangularFootprints = false;
    return config;
}

} // namespace depthwizard::test
