#include <drogon/drogon.h>
int main() 
{
     drogon::app().registerPreRoutingAdvice([](const drogon::HttpRequestPtr &req, 
                                              drogon::FilterCallback &&defer, 
                                              drogon::FilterChainCallback &&proceed) {
        if (req->method() == drogon::Options) {
            auto resp = drogon::HttpResponse::newHttpResponse();
            resp->setStatusCode(drogon::k200OK);
            resp->addHeader("Access-Control-Allow-Origin", "http://localhost:5173");
            resp->addHeader("Access-Control-Allow-Methods", "GET, POST, OPTIONS, PUT, DELETE");
            resp->addHeader("Access-Control-Allow-Headers", "Content-Type, Authorization, X-Requested-With");
            defer(resp);
            return;
        }
        proceed();
    });

    // 2. Append the CORS header to all actual API responses (like your POST)
    drogon::app().registerPostHandlingAdvice([](const drogon::HttpRequestPtr &req, 
                                                const drogon::HttpResponsePtr &resp) {
        resp->addHeader("Access-Control-Allow-Origin", "http://localhost:5173");
    });
     //Set HTTP listener address and port
     drogon::app().addListener("0.0.0.0", 8081);
     //Load config file
     drogon::app().loadConfigFile("../config.json")
      // 2. Override the max body size SECOND
             .setClientMaxBodySize(200 * 1024 * 1024);
     //drogon::app().loadConfigFile("../config.yaml");
     //Run HTTP framework,the method will block in the internal event loop

     //set up done for maximum concurrency drogon will auto take num oif cores for laptop
     //and handle threading accordingly
     drogon::app().setThreadNum(0);
     std::cout<<"running\n";
     drogon::app().setLogLevel(trantor::Logger::kTrace);
     drogon::app().run();

     return 0;
}
