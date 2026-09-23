#include <drogon/drogon.h>
#include <csignal>
#include <iostream>

void signal_handler(int signum) {
    std::cout << "\n>> [SYSTEM] Interrupt signal (" << signum << ") received. Shutting down...\n";
    drogon::app().quit();
}

int main() 
{
    std::signal(SIGINT, signal_handler);
    std::signal(SIGTERM, signal_handler);

    // 1. GLOBAL CORS HANDLER (Runs before everything else)
    drogon::app().registerPreRoutingAdvice([](const drogon::HttpRequestPtr &req, 
                                              drogon::FilterCallback &&defer, 
                                              drogon::FilterChainCallback &&proceed) {
        // LOG EVERY REQUEST IMMEDIATELY
        std::cout << ">> [HTTP] Received: " << req->methodString() << " " << req->path() << std::endl;

        if (req->method() == drogon::Options) {
            auto resp = drogon::HttpResponse::newHttpResponse();
            resp->setStatusCode(drogon::k200OK);
            resp->addHeader("Access-Control-Allow-Origin", "http://localhost:5173");
            resp->addHeader("Access-Control-Allow-Methods", "GET, POST, OPTIONS, PUT, DELETE");
            resp->addHeader("Access-Control-Allow-Headers", "Content-Type, Authorization, X-Requested-With");
            resp->addHeader("Access-Control-Max-Age", "3600"); // Cache preflight for 1 hour
            defer(resp);
            return;
        }
        proceed();
    });

    // 2. APPEND CORS TO RESPONSES
    drogon::app().registerPostHandlingAdvice([](const drogon::HttpRequestPtr &req, 
                                                const drogon::HttpResponsePtr &resp) {
        resp->addHeader("Access-Control-Allow-Origin", "http://localhost:5173");
    });

    drogon::app().addListener("0.0.0.0", 8080);
    
    // Increase body size limit (200MB)
    drogon::app().loadConfigFile("../config.json")
                 .setClientMaxBodySize(200 * 1024 * 1024);

    drogon::app().setThreadNum(0);
    std::cout << ">> [SYSTEM] Backend Ready on http://localhost:8080\n";
    drogon::app().setLogLevel(trantor::Logger::kTrace); // Keep trace on for now
    
    drogon::app().run();
    return 0;
}