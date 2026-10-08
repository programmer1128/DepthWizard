#include "LocalFrameTransformer.h"
#include <limits>
#include <cmath>

LocalSceneFrame LocalFrameTransformer::create(
     const SpatialMetadata& metadata,
     const GeoreferencedSurfaceBundle& surface)
{
     LocalSceneFrame frame;
     frame.horizontalCrs = metadata.projectionRef;
     frame.axisConvention = "Y-UP_RIGHT-HANDED"; // Standard glTF orientation

     //Calculate Horizontal Origin (Center of the Raster)
     double centerCol = metadata.width / 2.0;
     double centerRow = metadata.height / 2.0;

     // Apply affine transform to find the exact geographic center
     frame.projectedOriginX = metadata.geoTransform[0] + centerCol * metadata.geoTransform[1] + centerRow * metadata.geoTransform[2];
     frame.projectedOriginY = metadata.geoTransform[3] + centerCol * metadata.geoTransform[4] + centerRow * metadata.geoTransform[5];

     //Calculate Vertical Origin (Lowest point of the bare-earth DTM)
     float minElev = std::numeric_limits<float>::max();
     bool foundValid = false;

     for (std::size_t i = 0; i < surface.dtm.data.size(); ++i) 
     {
         if (surface.validMask.data[i] > 0) 
         {
             float val = surface.dtm.data[i];
             if (std::isfinite(val) && val < minElev) 
             {
                 minElev = val;
                 foundValid = true;
             }
         }
     }

     // Set elevation origin (0.0 fallback if image is entirely NoData)
     frame.elevationOrigin = foundValid ? static_cast<double>(minElev) : 0.0;
    
     return frame;
}

LocalPoint LocalFrameTransformer::toLocal(const ProjectedPoint& pt, const LocalSceneFrame& frame) 
{
     LocalPoint localPt;
    
     // glTF Local X = Easting - originEasting
     localPt.x = pt.easting - frame.projectedOriginX;
    
     // glTF is a right-handed coordinate system where +Y is UP. 
     // This means +Z points OUT of the screen (South), so -Z points IN (North).
     localPt.z = -(pt.northing - frame.projectedOriginY);
    
     return localPt;
}

float LocalFrameTransformer::toLocalElevation(float elevation, const LocalSceneFrame& frame) 
{
     // glTF Local Y = Elevation - originElevation
     return elevation - static_cast<float>(frame.elevationOrigin);
}