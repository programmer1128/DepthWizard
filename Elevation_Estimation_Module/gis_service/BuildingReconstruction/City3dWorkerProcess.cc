#include "City3dWorkerProcess.h"

#include <cerrno>
#include <csignal>
#include <cstring>
#include <fcntl.h>
#include <fstream>
#include <spawn.h>
#include <sys/wait.h>
#include <thread>
#include <unistd.h>
#include <vector>

extern char** environ;

namespace
{

// Waits up to `limit` for the child; true when it exited (status filled).
bool waitFor(pid_t pid, std::chrono::steady_clock::time_point limit, int& status)
{
     while (true)
     {
          const pid_t done = ::waitpid(pid, &status, WNOHANG);
          if (done == pid) return true;
          if (done < 0 && errno != EINTR) return true; // Already reaped
          if (std::chrono::steady_clock::now() >= limit) return false;
          std::this_thread::sleep_for(std::chrono::milliseconds(10));
     }
}

} // namespace

City3dProcessResult runCity3dWorker(const std::filesystem::path& binary,
                                    const std::filesystem::path& request,
                                    const std::filesystem::path& output,
                                    const std::filesystem::path& logPath,
                                    std::chrono::milliseconds timeout)
{
     City3dProcessResult result;
     std::vector<std::string> arguments{binary.string(), "--request", request.string(), "--output", output.string()};
     std::vector<char*> argv;
     for (std::string& argument : arguments) argv.push_back(argument.data());
     argv.push_back(nullptr);

     posix_spawn_file_actions_t actions;
     posix_spawnattr_t attributes;
     posix_spawn_file_actions_init(&actions);
     posix_spawnattr_init(&attributes);
     const std::string log = logPath.string();
     posix_spawn_file_actions_addopen(&actions, STDIN_FILENO, "/dev/null", O_RDONLY, 0);
     posix_spawn_file_actions_addopen(&actions, STDOUT_FILENO, log.c_str(), O_WRONLY | O_CREAT | O_APPEND, 0600);
     posix_spawn_file_actions_adddup2(&actions, STDOUT_FILENO, STDERR_FILENO);
     posix_spawn_file_actions_addclosefrom_np(&actions, 3); // No server sockets in the child
     posix_spawnattr_setpgroup(&attributes, 0);              // Own process group
     posix_spawnattr_setflags(&attributes, POSIX_SPAWN_SETPGROUP);

     const auto started = std::chrono::steady_clock::now();
     pid_t pid = 0;
     const int spawned = ::posix_spawn(&pid, binary.c_str(), &actions, &attributes, argv.data(), environ);
     posix_spawn_file_actions_destroy(&actions);
     posix_spawnattr_destroy(&attributes);
     if (spawned != 0)
     {
          result.error = std::string("cannot start the worker: ") + std::strerror(spawned);
          return result;
     }
     result.started = true;

     int status = 0;
     if (!waitFor(pid, started + timeout, status))
     {
          result.timedOut = true;
          ::kill(-pid, SIGTERM);
          if (!waitFor(pid, std::chrono::steady_clock::now() + std::chrono::milliseconds(500), status))
          {
               ::kill(-pid, SIGKILL);
               ::waitpid(pid, &status, 0);
          }
     }
     result.elapsedMs = std::chrono::duration_cast<std::chrono::milliseconds>(
         std::chrono::steady_clock::now() - started).count();
     result.exitCode = WIFEXITED(status) ? WEXITSTATUS(status)
                                         : (WIFSIGNALED(status) ? 128 + WTERMSIG(status) : -1);
     return result;
}

std::string readLogTail(const std::filesystem::path& logPath, std::size_t maxBytes)
{
     std::ifstream file(logPath, std::ios::binary | std::ios::ate);
     if (!file) return {};
     const std::streamoff size = file.tellg();
     const std::streamoff start = size > static_cast<std::streamoff>(maxBytes) ? size - static_cast<std::streamoff>(maxBytes) : 0;
     file.seekg(start);
     std::string tail(static_cast<std::size_t>(size - start), '\0');
     file.read(tail.data(), static_cast<std::streamsize>(tail.size()));
     return tail;
}
