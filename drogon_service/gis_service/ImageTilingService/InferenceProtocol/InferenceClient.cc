// the actual network code
// packs the bytes, opens a TCP socket, streams the data
// mathematically reverses the GAMUS scale to give us true meters

#include "InferenceClient.h"
#include <sys/socket.h>   
#include <arpa/inet.h>    
#include <netinet/tcp.h>  
#include <unistd.h>  
#include <sys/time.h>    
#include <stdexcept>
#include <cstring>

// the 32-byte security password and information block the model expects first
#pragma pack(push, 1) // force compiler not to add empty padding bytes
struct FrameHeader 
{
     uint32_t magic;         // security password 
     uint32_t tile_id;       // ID of the tile
     uint32_t width;         // 518
     uint32_t height;        // 518
     uint32_t channels;      // 3 (RGB)
     uint32_t dtype;         // 4 (Float32 format)
     uint64_t payload_len;   // total size of the colors we are sending
};
#pragma pack(pop)

TileInferenceResult InferenceClient::inferMetricTile(std::shared_ptr<TileRequest> request, const std::string& target_gpu_ip)
{
     // build the header (envelope)
     FrameHeader header;
     header.magic = 0xDEADBEEF; 
     header.tile_id = request->tileId;       
     header.width = request->width;
     header.height = request->height;
     header.channels = 3;
     header.dtype = 4; // assuming 4 means float32 
     header.payload_len = request->normalizedRgbBytes.size() * sizeof(float);

     // open the TCP Socket Connection
     int sock = socket(AF_INET, SOCK_STREAM, 0);

     // disable Nagle's algorithm so the internet sends our packets instantly
     int flag = 1;
     setsockopt(sock, IPPROTO_TCP, TCP_NODELAY, (char*)&flag, sizeof(int));

     // 120-sec network timeout shield (prevents C++ server from freezing if the model crashes)
     struct timeval tv;
     tv.tv_sec = 120;
     tv.tv_usec = 0;
     setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);
     setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&tv, sizeof tv);

     // set up the target GPU address
     struct sockaddr_in serv_addr;
     serv_addr.sin_family = AF_INET;
     serv_addr.sin_port = htons(9092); 
    
     if (inet_pton(AF_INET, target_gpu_ip.c_str(), &serv_addr.sin_addr) <= 0) 
     {
         close(sock);
         throw std::runtime_error("Network Error: Invalid GPU IP Address: " + target_gpu_ip);
     }

     if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
     {
         close(sock);
         throw std::runtime_error("Network Error: Could not connect to GPU at " + target_gpu_ip);
     }

     // send the header
     send(sock, &header, sizeof(FrameHeader), MSG_NOSIGNAL);

     // send the raw RGB image data securely in a loop to prevent fragmentation loss
     size_t total_sent = 0;
     const char* send_ptr = reinterpret_cast<const char*>(request->normalizedRgbBytes.data());

     while (total_sent < header.payload_len) 
     {
         ssize_t sent = send(sock, send_ptr + total_sent, header.payload_len - total_sent, MSG_NOSIGNAL);
         if (sent <= 0) 
         {
             close(sock);
             throw std::runtime_error("Network Error: Connection dropped while sending image payload");
         }
         total_sent += sent;
     }

     // prepare containers to hold 4 distinct results coming back
     size_t pixel_count = request->width * request->height;
     
     TileInferenceResult result;
     result.tileId = request->tileId;

     // map to the new TilePlacement struct
     result.placement.sourceX = request->xOffset;
     result.placement.sourceY = request->yOffset;
     result.placement.paddedWidth = request->width;
     result.placement.paddedHeight = request->height;
     result.placement.validStartX = 0;
     result.placement.validStartY = 0;
     
     result.placement.validWidth = request->validWidth;
     result.placement.validHeight = request->validHeight;

     // initialize the new RasterGrid formats
     result.metricNdsm.width = request->width;
     result.metricNdsm.height = request->height;
     result.metricNdsm.data.resize(pixel_count);

     result.ndsmConfidence.width = request->width;
     result.ndsmConfidence.height = request->height;
     result.ndsmConfidence.data.resize(pixel_count);

     result.validMask.width = request->width;
     result.validMask.height = request->height;
     result.validMask.data.resize(pixel_count);

     // temporary flat buffer for the 6-channel semantic logits
     std::vector<float> flatLogits(pixel_count * 6);

     // receive the 4 layers one by one. MSG_WAITALL ensures we dont proceed until the whole layer arrives
     recv(sock, result.metricNdsm.data.data(), pixel_count * sizeof(float), MSG_WAITALL);
     recv(sock, flatLogits.data(), pixel_count * 6 * sizeof(float), MSG_WAITALL);
     recv(sock, result.ndsmConfidence.data.data(), pixel_count * sizeof(float), MSG_WAITALL);
     recv(sock, result.validMask.data.data(), pixel_count * sizeof(uint8_t), MSG_WAITALL);

     close(sock);
     
     
     // distribute flat logits into the 6 separate RasterGrids 
     result.semanticLogits.classCount = 6;
     result.semanticLogits.layout = TensorLayout::CHW;
     
     auto initGrid = [&](RasterGrid<float>& grid) {
         grid.width = request->width;
         grid.height = request->height;
         grid.data.resize(pixel_count);
     };

     initGrid(result.semanticLogits.unknownLogits);
     initGrid(result.semanticLogits.groundLogits);
     initGrid(result.semanticLogits.buildingLogits);
     initGrid(result.semanticLogits.roadLogits);
     initGrid(result.semanticLogits.vegetationLogits);
     initGrid(result.semanticLogits.waterLogits);

     // copy Channel by Channel (CHW format)
     std::memcpy(result.semanticLogits.unknownLogits.data.data(), &flatLogits[0 * pixel_count], pixel_count * sizeof(float));
     std::memcpy(result.semanticLogits.groundLogits.data.data(), &flatLogits[1 * pixel_count], pixel_count * sizeof(float));
     std::memcpy(result.semanticLogits.buildingLogits.data.data(), &flatLogits[2 * pixel_count], pixel_count * sizeof(float));
     std::memcpy(result.semanticLogits.roadLogits.data.data(), &flatLogits[3 * pixel_count], pixel_count * sizeof(float));
     std::memcpy(result.semanticLogits.vegetationLogits.data.data(), &flatLogits[4 * pixel_count], pixel_count * sizeof(float));
     std::memcpy(result.semanticLogits.waterLogits.data.data(), &flatLogits[5 * pixel_count], pixel_count * sizeof(float));


     // Reverse GAMUS Normalization to absolute meters
     // if model was trained to output numbers divided by 20, we must multiply by 20 here 
     // to ensure the rest of the C++ engine gets true heights in meters
     const float GAMUS_SCALE_FACTOR = 20.0f; // to match exact model training scale
     
     float* ndsm_ptr = result.metricNdsm.data.data();
     for (size_t i = 0; i < pixel_count; ++i) 
     {
         ndsm_ptr[i] *= GAMUS_SCALE_FACTOR;
     }

     return result; // return the TileInferenceResult
}