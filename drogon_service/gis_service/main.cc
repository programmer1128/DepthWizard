#include <drogon/drogon.h>

#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <string>

namespace
{
std::filesystem::path executableDirectory()
{
     std::error_code ec;
     const auto exe = std::filesystem::read_symlink("/proc/self/exe", ec);
     return ec ? std::filesystem::current_path() : exe.parent_path();
}

std::string trim(const std::string& text)
{
     const auto begin = text.find_first_not_of(" \t\r\n");
     if (begin == std::string::npos) return {};
     const auto end = text.find_last_not_of(" \t\r\n");
     return text.substr(begin, end - begin + 1);
}

// KEY=VALUE lines (optional `export `, quotes, # comments). A variable that is
// already set in the environment always wins, so `export X=...` before
// ./gis_service, systemd Environment= lines or an earlier file override it.
void loadEnvironmentFile(const std::filesystem::path& path)
{
     std::ifstream file(path);
     if (!file) return;
     std::string line;
     int applied = 0;
     while (std::getline(file, line))
     {
          line = trim(line);
          if (line.empty() || line[0] == '#') continue;
          if (line.rfind("export ", 0) == 0) line = trim(line.substr(7));
          const auto equals = line.find('=');
          if (equals == std::string::npos) continue;
          const std::string key = trim(line.substr(0, equals));
          std::string value = trim(line.substr(equals + 1));
          if (value.size() >= 2 && (value.front() == '"' || value.front() == '\'') && value.back() == value.front())
               value = value.substr(1, value.size() - 2);
          if (key.empty()) continue;
          if (::setenv(key.c_str(), value.c_str(), 0) == 0) ++applied;
     }
     std::cout << "[DepthWizard] settings file " << path.string() << " (" << applied << " entries)\n";
}

std::string environment(const char* name, const std::string& fallback)
{
     const char* value = std::getenv(name);
     return value && *value ? std::string(value) : fallback;
}

trantor::Logger::LogLevel logLevel(const std::string& name)
{
     if (name == "TRACE") return trantor::Logger::kTrace;
     if (name == "DEBUG") return trantor::Logger::kDebug;
     if (name == "WARN") return trantor::Logger::kWarn;
     if (name == "ERROR") return trantor::Logger::kError;
     return trantor::Logger::kInfo;
}
} // namespace

int main()
{
     // 1. Settings. Earlier sources win: the process environment, then
     //    $DEPTHWIZARD_ENV_FILE, then deploy/secrets.env (credentials, not in
     //    git), then deploy/depthwizard.env (the tested production flags, in
     //    git). The deploy/ folder is found next to the build directory.
     const std::filesystem::path exeDir = executableDirectory();
     if (const char* file = std::getenv("DEPTHWIZARD_ENV_FILE"); file && *file) loadEnvironmentFile(file);
     for (const auto& dir : {exeDir / "deploy", exeDir.parent_path() / "deploy"})
     {
          loadEnvironmentFile(dir / "secrets.env");
          loadEnvironmentFile(dir / "depthwizard.env");
     }

     // 2. CORS. Same-origin deployments (NGINX, Vite proxy) need none; a
     //    frontend on another origin must be listed here.
     std::set<std::string> origins;
     {
          std::stringstream list(environment("DEPTHWIZARD_CORS_ORIGINS", "http://localhost:5173,http://127.0.0.1:5173"));
          for (std::string origin; std::getline(list, origin, ',');)
               if (!trim(origin).empty()) origins.insert(trim(origin));
     }
     const auto allowedOrigin = [origins](const drogon::HttpRequestPtr& req) -> std::string {
          const std::string origin = req->getHeader("Origin");
          if (origin.empty()) return {};
          if (origins.count("*")) return "*";
          return origins.count(origin) ? origin : std::string();
     };
     drogon::app().registerPreRoutingAdvice([allowedOrigin](const drogon::HttpRequestPtr& req,
                                                          drogon::FilterCallback&& defer,
                                                          drogon::FilterChainCallback&& proceed) {
          if (req->method() == drogon::Options)
          {
               auto resp = drogon::HttpResponse::newHttpResponse();
               resp->setStatusCode(drogon::k200OK);
               if (const std::string origin = allowedOrigin(req); !origin.empty())
               {
                    resp->addHeader("Access-Control-Allow-Origin", origin);
                    resp->addHeader("Vary", "Origin");
                    resp->addHeader("Access-Control-Allow-Methods", "GET, POST, OPTIONS, PUT, DELETE");
                    resp->addHeader("Access-Control-Allow-Headers", "Content-Type, Authorization, X-Requested-With");
                    resp->addHeader("Access-Control-Max-Age", "600");
               }
               defer(resp);
               return;
          }
          proceed();
     });
     drogon::app().registerPostHandlingAdvice([allowedOrigin](const drogon::HttpRequestPtr& req,
                                                             const drogon::HttpResponsePtr& resp) {
          if (const std::string origin = allowedOrigin(req); !origin.empty())
          {
               resp->addHeader("Access-Control-Allow-Origin", origin);
               resp->addHeader("Vary", "Origin");
               resp->addHeader("Access-Control-Expose-Headers", "X-Imagery-Provider, X-Imagery-Date, X-Imagery-Attribution");
          }
     });

     // 3. Listener. 127.0.0.1 behind NGINX (deploy/depthwizard.env); 0.0.0.0
     //    only when browsers reach the backend directly.
     const std::string address = environment("DEPTHWIZARD_LISTEN_ADDRESS", "0.0.0.0");
     const int port = std::atoi(environment("DEPTHWIZARD_PORT", "8081").c_str());
     drogon::app().addListener(address, static_cast<uint16_t>(port > 0 ? port : 8081));

     // 4. drogon configuration, found relative to the executable (the build
     //    directory sits next to config.json), so the daemon's working
     //    directory does not matter.
     std::filesystem::path config = exeDir.parent_path() / "config.json";
     if (!std::filesystem::exists(config)) config = "../config.json";
     drogon::app().loadConfigFile(config.string()).setClientMaxBodySize(200 * 1024 * 1024);

     drogon::app().setThreadNum(0);   // One event loop per core
     drogon::app().setLogLevel(logLevel(environment("DEPTHWIZARD_LOG_LEVEL", "TRACE")));
     std::cout << "running on " << address << ":" << port << "\n";
     drogon::app().run();
     return 0;
}
