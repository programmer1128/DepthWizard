#include "TileDispatcher.h"

#include <sys/socket.h>   // networking library
#include <arpa/inet.h>    // to convert IP address to network format
#include <netinet/tcp.h>    // TCP-specific socket options: TCP_NODELAY
#include <unistd.h>  
#include <sys/time.h>    

// network protocol struct
// exact 32-byte struct as in lightning AI
#pragma pack(push, 1) // no padding bytes
struct FrameHeader 
{
     uint32_t magic;         // security password to ensure valid connection
     uint32_t tile_id;       // unique ID of this tile
     uint32_t width;         // width of the payload: 518
     uint32_t height;        // height of the payload: 518
     uint32_t channels;      // no. of color channels: 3 for RGB
     uint32_t dtype;         // data type flag: 1 for uint8_t
     uint64_t payload_len;   // total bytes being sent: 518 * 518 * 3
};
#pragma pack(pop) // restore normal compiler padding rules


// network bridge
std::shared_ptr<std::vector<float>> TileDispatcher::streamToLightningAI(
     std::span<const uint8_t> raw_tile_binary, 
     const std::string& target_gpu_ip,
     uint32_t tile_id)
{
     int tile_size = 518;
     size_t expected_return_floats = tile_size * tile_size; 
     size_t expected_return_bytes = expected_return_floats * sizeof(float);

     // package the 32 byte header
     FrameHeader header;
     header.magic = 0xDEADBEEF; 
     header.tile_id = tile_id;       
     header.width = tile_size;
     header.height = tile_size;
     header.channels = 3;
     header.dtype = 1;          
     header.payload_len = raw_tile_binary.size();

     // create a TCP socket
     int sock = socket(AF_INET, SOCK_STREAM, 0);

     // TCP_NODELAY disables Nagle's algorithm & forces packets to send instantly for optimization
     int flag = 1;
     setsockopt(sock, IPPROTO_TCP, TCP_NODELAY, (char*)&flag, sizeof(int));

     // 15-Second Network Timeout Shield
     struct timeval tv;
     tv.tv_sec = 120;
     tv.tv_usec = 0;
     setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);
     setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&tv, sizeof tv);

     // setup the target cloud GPU IP Address and Port: 9092
     struct sockaddr_in serv_addr;
     serv_addr.sin_family = AF_INET;
     serv_addr.sin_port = htons(9092); 
    
     // validate IP Address formatting
     if (inet_pton(AF_INET, target_gpu_ip.c_str(), &serv_addr.sin_addr) <= 0) 
     {
         close(sock);
         throw std::runtime_error("Network Error: Invalid GPU IP Address format: " + target_gpu_ip);
     }

     // connect across the internet
     if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
     {
         int err = errno;
         close(sock);
         throw std::runtime_error("Network Error: Could not connect to Lightning AI GPU. System error: " + std::string(strerror(err)));
     }

     // sending header safely with MSG_NOSIGNAL
     if (send(sock, &header, sizeof(FrameHeader), MSG_NOSIGNAL) <= 0) 
     {
         int err = errno;
         close(sock);
         throw std::runtime_error("Network Error: Failed to send FrameHeader. System error: " + std::string(strerror(err)));
     }

     // send Payload securely in a fragmentation-proof loop
     size_t total_sent = 0;
     const char* send_ptr = reinterpret_cast<const char*>(raw_tile_binary.data());

     while (total_sent < header.payload_len) 
     {
         ssize_t sent = send(sock, send_ptr + total_sent, header.payload_len - total_sent, MSG_NOSIGNAL);
         if (sent <= 0) 
         {
             int err = errno;
             close(sock);
             throw std::runtime_error("Network Error: Connection dropped while sending image payload. System error: " + std::string(strerror(err)));
         }
         total_sent += sent;
     }

     // prepare a RAM container to hold the returning data
     auto result_matrix = std::make_shared<std::vector<float>>(expected_return_floats);

     // block and wait for the cloud GPU to send back
     // MSG_WAITALL ensures it doesnt give up if the network drops a packet temporarily
     ssize_t bytes_recvd = recv(sock, result_matrix->data(), expected_return_bytes, MSG_WAITALL);
    
     close(sock); 

     // validate that we received exactly 1MB of floats & not a partial corrupted matrix
     if (bytes_recvd != expected_return_bytes) 
     { 
         throw std::runtime_error("Network Error: Received corrupted or partial float matrix from GPU.");
     }

     return result_matrix;
}