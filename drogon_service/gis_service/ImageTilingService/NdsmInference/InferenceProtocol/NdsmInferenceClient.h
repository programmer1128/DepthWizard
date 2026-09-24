// implements handling exactly sized byte-streams over TCP

#pragma once
#include "../../../structures/NdsmInferenceTypes.h"
#include "../../../structures/InferenceStructs.h" // For TileRequest
#include "../NdsmInferenceConfig.h"
#include <memory>
#include <string>

class NdsmInferenceClient 
{
public:
    // Establishes TCP connection, transmits exactly sized payloads, and reconstructs the tile result
    static NdsmTileResult infer(
        const std::shared_ptr<TileRequest>& request, 
        const NdsmWorkerEndpoint& endpoint,
        const NdsmInferenceConfig& config);
        
private:
    // Helper to enforce strict exact-byte transmission
    static void sendAll(int sock, const char* data, size_t length);
    
    // Helper to enforce strict exact-byte reception
    static void receiveAll(int sock, char* buffer, size_t length);
};