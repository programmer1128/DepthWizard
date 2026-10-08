#pragma once

#include <chrono>
#include <filesystem>
#include <string>

struct City3dProcessResult
{
     bool started{false};
     bool timedOut{false};
     int exitCode{-1};        // Exit status, or 128 + signal
     long long elapsedMs{0};
     std::string error;
};

// Runs `binary --request REQUEST --output OUTPUT` synchronously with an
// explicit argument vector (no shell), stdout and stderr appended to
// logPath, file descriptors above 2 closed, and the child in its own process
// group. On timeout the group gets SIGTERM, then SIGKILL after a short grace.
City3dProcessResult runCity3dWorker(const std::filesystem::path& binary,
                                    const std::filesystem::path& request,
                                    const std::filesystem::path& output,
                                    const std::filesystem::path& logPath,
                                    std::chrono::milliseconds timeout);

// Last maxBytes of a log file (for diagnostics).
std::string readLogTail(const std::filesystem::path& logPath, std::size_t maxBytes = 4096);
