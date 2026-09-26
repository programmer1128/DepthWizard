#include "TerrainMesher.h"
#include <cmath>
#include <algorithm>
#include <limits>
#include <stdexcept>

TerrainMesh TerrainMesher::generate(
    const GeoreferencedSurfaceBundle& surface,
    const SpatialMetadata& metadata,
    const LocalSceneFrame& frame,
    const TerrainMeshConfig& config)
{
    RasterGrid<uint8_t> noAcceptedBuildings;
    noAcceptedBuildings.width = metadata.width;
    noAcceptedBuildings.height = metadata.height;
    if (metadata.width > 0 && metadata.height > 0)
    {
        noAcceptedBuildings.data.assign(
            static_cast<std::size_t>(metadata.width) * metadata.height,
            uint8_t{0});
    }
    return generate(
        surface, noAcceptedBuildings, metadata, frame, config);
}

TerrainMesh TerrainMesher::generate(
    const GeoreferencedSurfaceBundle& surface,
    const RasterGrid<uint8_t>& acceptedBuildingMask,
    const SpatialMetadata& metadata,
    const LocalSceneFrame& frame,
    const TerrainMeshConfig& config)
{
    TerrainMesh result;
    result.terrainPrimitive.topology = PrimitiveTopology::TRIANGLES;
    result.terrainPrimitive.materialRole = MaterialRole::TERRAIN_TEXTURE;

    int width = metadata.width;
    int height = metadata.height;
    if (width < 2 || height < 2 || !config.validate() ||
        !surface.dtm.isValid() || !surface.dsm.isValid() ||
        !surface.validMask.isValid() || !acceptedBuildingMask.isValid() ||
        surface.dtm.width != width || surface.dtm.height != height ||
        surface.dsm.width != width || surface.dsm.height != height ||
        surface.validMask.width != width || surface.validMask.height != height ||
        acceptedBuildingMask.width != width ||
        acceptedBuildingMask.height != height)
        throw std::invalid_argument("TerrainMesher: invalid terrain dimensions or grid");

    //Dynamic Decimation (Stride)
    int stride = 1;
    if (width > config.maxGridSize || height > config.maxGridSize) 
    {
        stride = std::max((width - 2) / (config.maxGridSize - 1) + 1,
                          (height - 2) / (config.maxGridSize - 1) + 1);
    }

    int gridWidth = (width - 2) / stride + 2;
    int gridHeight = (height - 2) / stride + 2;
    std::vector<uint8_t> sampledValid(static_cast<size_t>(gridWidth) * gridHeight, 0);

    std::vector<float>& positions = result.terrainPrimitive.positions;
    std::vector<float> uvs;
    std::vector<uint32_t>& indices = result.terrainPrimitive.indices;

    positions.reserve(gridWidth * gridHeight * 3 + (gridWidth + gridHeight) * 6);
    uvs.reserve(gridWidth * gridHeight * 2 + (gridWidth + gridHeight) * 4);

    AxisAlignedBounds bounds;
    bounds.isInitialized = true;
    bounds.minX = bounds.minY = bounds.minZ = std::numeric_limits<double>::max();
    bounds.maxX = bounds.maxY = bounds.maxZ = std::numeric_limits<double>::lowest();

     //Generate Top Surface Vertices and UVs
     for (int y = 0; y < gridHeight; ++y) 
     {
         for (int x = 0; x < gridWidth; ++x) 
         {
             int origX = std::min(x * stride, width - 1);
             int origY = std::min(y * stride, height - 1);
             
             const std::size_t sourceIndex =
                 static_cast<std::size_t>(origY) * width + origX;

             // Rejected/missed buildings must never return as textured DSM
             // mounds. DTM already contains hills; nDSM is object height,
             // not an additional high-frequency terrain elevation.
             const bool useBareEarth =
                 config.elevationSource != TerrainElevationSource::SURFACE_PREVIEW ||
                 acceptedBuildingMask.data[sourceIndex] != 0;
             float elevation = useBareEarth
                 ? surface.dtm.data[sourceIndex]
                 : surface.dsm.data[sourceIndex];
             bool valid = surface.validMask.data[sourceIndex] != 0 &&
                          std::isfinite(elevation);
             sampledValid[static_cast<size_t>(y) * gridWidth + x] = valid;
             
             // GDAL's affine transform maps pixel EDGES; raster samples live
             // at centres. Interior terrain samples use their centres, while
             // the outermost nodes extend to the image edges using the nearest
             // valid height. This covers the same [0,width] x [0,height] domain
             // as the pixel-edge building footprints, including border roofs.
             const double pixelX = x == 0 ? 0.0 :
                 (x == gridWidth - 1 ? static_cast<double>(width) : origX + 0.5);
             const double pixelY = y == 0 ? 0.0 :
                 (y == gridHeight - 1 ? static_cast<double>(height) : origY + 0.5);
             double E = metadata.geoTransform[0] + pixelX * metadata.geoTransform[1] + pixelY * metadata.geoTransform[2];
             double N = metadata.geoTransform[3] + pixelX * metadata.geoTransform[4] + pixelY * metadata.geoTransform[5];
            
             ProjectedPoint proj{E, N};
             LocalPoint localPt = LocalFrameTransformer::toLocal(proj, frame);
             float localY = valid
                 ? LocalFrameTransformer::toLocalElevation(elevation, frame)
                 : 0.0f; // Unused placeholder: faces touching NoData are omitted.
             if (config.elevationSource == TerrainElevationSource::FLAT_PRESENTATION)
                 localY = 0.0f; // Render-only: never modify the scientific raster.

             positions.push_back(static_cast<float>(localPt.x));
             positions.push_back(localY);
             positions.push_back(static_cast<float>(localPt.z));

             // glTF (0,0) is the image's TOP LEFT, exactly like the unflipped
             // JPEG supplied by RasterIngestService. Do not apply OpenGL's
             // historical V flip: that mirrors optical roofs against geometry.
             uvs.push_back(static_cast<float>(pixelX / width));
             uvs.push_back(static_cast<float>(pixelY / height));

             if (valid) {
                 bounds.minX = std::min(bounds.minX, localPt.x);
                 bounds.minY = std::min(bounds.minY, static_cast<double>(localY));
                 bounds.minZ = std::min(bounds.minZ, localPt.z);
                 bounds.maxX = std::max(bounds.maxX, localPt.x);
                 bounds.maxY = std::max(bounds.maxY, static_cast<double>(localY));
                 bounds.maxZ = std::max(bounds.maxZ, localPt.z);
             }
         }
     }

     //Generate Top Surface Indices
     for (int y = 0; y < gridHeight - 1; y++) 
     {
         for (int x = 0; x < gridWidth - 1;x++) 
         {
             uint32_t v0 = y * gridWidth + x;
             uint32_t v1 = y * gridWidth + (x + 1);
             uint32_t v2 = (y + 1) * gridWidth + x;
             uint32_t v3 = (y + 1) * gridWidth + (x + 1);
            
             if (sampledValid[v0] && sampledValid[v2] && sampledValid[v1]) {
                 indices.push_back(v0); indices.push_back(v2); indices.push_back(v1);
             }
             if (sampledValid[v1] && sampledValid[v2] && sampledValid[v3]) {
                 indices.push_back(v1); indices.push_back(v2); indices.push_back(v3);
             }
         }
     } 

     if (indices.empty())
         throw std::runtime_error("TerrainMesher: no valid terrain triangles");

     //Skirt Generation (The Pedestal)
     float yBase = static_cast<float>(bounds.minY) - config.skirtDepth;

     float centerX = static_cast<float>((bounds.minX + bounds.maxX) / 2.0);
     float centerZ = static_cast<float>((bounds.minZ + bounds.maxZ) / 2.0);

     // A flat urban surface has no pedestal, bottom cap, or skirt vertices.
     // Depth zero alone would still create degenerate side/bottom triangles.
     if (config.generateSkirt)
     {
     bounds.minY = yBase;
     uint32_t vCenterBase = positions.size() / 3;
     positions.push_back(centerX); positions.push_back(yBase); positions.push_back(centerZ);
     uvs.push_back(0.5f); uvs.push_back(0.5f); // Neutral center UV

     auto addSkirtEdge = [&](uint32_t vTopCurr, uint32_t vTopNext) 
     {
         if (!sampledValid[vTopCurr] || !sampledValid[vTopNext])
             return;
         uint32_t vBaseCurr = positions.size() / 3;
         positions.push_back(positions[vTopCurr * 3]);     
         positions.push_back(yBase);                           
         positions.push_back(positions[vTopCurr * 3 + 2]); 
         uvs.push_back(uvs[vTopCurr * 2]);
         uvs.push_back(uvs[vTopCurr * 2 + 1]);

         uint32_t vBaseNext = positions.size() / 3;
         positions.push_back(positions[vTopNext * 3]);        
         positions.push_back(yBase);                           
         positions.push_back(positions[vTopNext * 3 + 2]);    
         uvs.push_back(uvs[vTopNext * 2]);
         uvs.push_back(uvs[vTopNext * 2 + 1]);

         indices.push_back(vTopCurr); indices.push_back(vBaseCurr); indices.push_back(vTopNext);
         indices.push_back(vTopNext); indices.push_back(vBaseCurr); indices.push_back(vBaseNext);
         indices.push_back(vBaseCurr); indices.push_back(vCenterBase); indices.push_back(vBaseNext);
     };
     
     for (int x = gridWidth - 1; x > 0; --x) 
     {
         addSkirtEdge(x, x - 1);
     }
     for (int y = 0; y < gridHeight - 1; ++y) 
     {
         addSkirtEdge(y * gridWidth, (y + 1) * gridWidth);
     }
     for (int x = 0; x < gridWidth - 1; ++x) 
     {
         addSkirtEdge((gridHeight - 1) * gridWidth + x, (gridHeight - 1) * gridWidth + x + 1);
     }
     for (int y = gridHeight - 1; y > 0; --y) 
     {
         addSkirtEdge(y * gridWidth + (gridWidth - 1), (y - 1) * gridWidth + (gridWidth - 1));
     }
     }

     //Normal Calculation
     std::vector<float> normals(positions.size(), 0.0f);
     for (size_t i = 0; i < indices.size(); i += 3) 
     {
         uint32_t i0 = indices[i], i1 = indices[i+1], i2 = indices[i+2];

         float ux = positions[i1*3] - positions[i0*3], uy = positions[i1*3+1] - positions[i0*3+1], uz = positions[i1*3+2] - positions[i0*3+2];
         float vx = positions[i2*3] - positions[i0*3], vy = positions[i2*3+1] - positions[i0*3+1], vz = positions[i2*3+2] - positions[i0*3+2];

         float nx = uy * vz - uz * vy;
         float ny = uz * vx - ux * vz;
         float nz = ux * vy - uy * vx;

         normals[i0*3] += nx; normals[i0*3+1] += ny; normals[i0*3+2] += nz;
         normals[i1*3] += nx; normals[i1*3+1] += ny; normals[i1*3+2] += nz;
         normals[i2*3] += nx; normals[i2*3+1] += ny; normals[i2*3+2] += nz;
     }

     for (size_t i = 0; i < normals.size(); i += 3) 
     {
         float length = std::sqrt(normals[i]*normals[i] + normals[i+1]*normals[i+1] + normals[i+2]*normals[i+2]);
         if (length > 0.0001f) 
         {
             normals[i] /= length; normals[i+1] /= length; normals[i+2] /= length;
         } 
         else 
         {
             normals[i] = 0.0f; normals[i+1] = 1.0f; normals[i+2] = 0.0f; 
         }
     }

     // Force hard normals for the skirts (crisp pedestal edges)
     size_t topSurfaceVertices = gridWidth * gridHeight;
     for (size_t i = topSurfaceVertices; i < positions.size() / 3; ++i) 
     {
         if (positions[i*3+1] == yBase) 
         {
             normals[i*3] = 0.0f; normals[i*3+1] = -1.0f; normals[i*3+2] = 0.0f;
         } 
         else 
         {
             float nx = positions[i*3] - centerX, nz = positions[i*3+2] - centerZ;
             float len = std::sqrt(nx*nx + nz*nz);
             if (len > 0.0001f) 
             {
                 normals[i*3] = nx / len; normals[i*3+1] = 0.0f; normals[i*3+2] = nz / len;
             }
         }
     }

     //Finalize Primitive
     result.terrainPrimitive.normals = std::move(normals);
     result.terrainPrimitive.uvs = std::move(uvs);
     result.terrainPrimitive.localBounds = bounds;

     return result;
}
