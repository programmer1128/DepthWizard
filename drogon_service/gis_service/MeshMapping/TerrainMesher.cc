#include "TerrainMesher.h"
#include <cmath>
#include <algorithm>

TerrainMesh TerrainMesher::generate(
    const GeoreferencedSurfaceBundle& surface,
    const SpatialMetadata& metadata,
    const LocalSceneFrame& frame,
    const TerrainMeshConfig& config)
{
    TerrainMesh result;
    result.terrainPrimitive.topology = PrimitiveTopology::TRIANGLES;
    result.terrainPrimitive.materialRole = MaterialRole::TERRAIN_TEXTURE;

    int width = metadata.width;
    int height = metadata.height;

    //Dynamic Decimation (Stride)
    int stride = 1;
    if (width > config.maxGridSize || height > config.maxGridSize) 
    {
        stride = std::max(width / config.maxGridSize, height / config.maxGridSize);
    }

    int gridWidth = width / stride;
    int gridHeight = height / stride;

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
             
             // Sample DTM (Bare Earth) instead of DSM
             float elevation = surface.dtm.data[origY * width + origX];
             
             // Convert to Projected Metric, then to Local glTF Space
             double E = metadata.geoTransform[0] + origX * metadata.geoTransform[1] + origY * metadata.geoTransform[2];
             double N = metadata.geoTransform[3] + origX * metadata.geoTransform[4] + origY * metadata.geoTransform[5];
            
             ProjectedPoint proj{E, N};
             LocalPoint localPt = LocalFrameTransformer::toLocal(proj, frame);
             float localY = LocalFrameTransformer::toLocalElevation(elevation, frame);

             positions.push_back(static_cast<float>(localPt.x));
             positions.push_back(localY);
             positions.push_back(static_cast<float>(localPt.z));

             // UV mapping (0.0 to 1.0)
             uvs.push_back(static_cast<float>(origX) / (width - 1));
             uvs.push_back(1.0f - (static_cast<float>(origY) / (height - 1))); // glTF V axis flips

             bounds.minX = std::min(bounds.minX, localPt.x);
             bounds.minY = std::min(bounds.minY, static_cast<double>(localY));
             bounds.minZ = std::min(bounds.minZ, localPt.z);
             bounds.maxX = std::max(bounds.maxX, localPt.x);
             bounds.maxY = std::max(bounds.maxY, static_cast<double>(localY));
             bounds.maxZ = std::max(bounds.maxZ, localPt.z);
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
            
             indices.push_back(v0); indices.push_back(v2); indices.push_back(v1);
             indices.push_back(v1); indices.push_back(v2); indices.push_back(v3);
         }
     } 

     //Skirt Generation (The Pedestal)
     float yBase = static_cast<float>(bounds.minY) - config.skirtDepth;
     bounds.minY = yBase;

     float centerX = static_cast<float>((bounds.minX + bounds.maxX) / 2.0);
     float centerZ = static_cast<float>((bounds.minZ + bounds.maxZ) / 2.0);

     uint32_t vCenterBase = positions.size() / 3;
     positions.push_back(centerX); positions.push_back(yBase); positions.push_back(centerZ);
     uvs.push_back(0.5f); uvs.push_back(0.5f); // Neutral center UV

     auto addSkirtEdge = [&](uint32_t vTopCurr, uint32_t vTopNext) 
     {
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