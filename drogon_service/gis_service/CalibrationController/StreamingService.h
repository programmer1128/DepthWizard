#include <drogon/drogon.h>
#include "../structures/QuadTreeTypes.h"
#include "../CalibrationController/PipelineService.h" // For SpatialMetadata

struct StreamingContext 
{
    const std::vector<float>& absoluteDsm;
    const std::vector<uint8_t>& rawJpegBytes;
    int masterWidth;
    int masterHeight;
    const SpatialMetadata& meta;
    std::string bucketName;
};

class StreamingService
{
      public:
      // Main Entry Point: Orchestrates graph generation, multithreaded meshing, and JSON indexing.
      // Returns the Pre-Signed URL of the generated tileset.json
      static drogon::Task<std::string> generateAndStreamTileset(const StreamingContext& ctx);
};