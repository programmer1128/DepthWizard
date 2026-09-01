#include <drogon/drogon.h>
int main() 
{
     //Set HTTP listener address and port
     drogon::app().addListener("0.0.0.0", 8080);
     //Load config file
     drogon::app().loadConfigFile("../config.json");
     //drogon::app().loadConfigFile("../config.yaml");
     //Run HTTP framework,the method will block in the internal event loop

     //set up done for maximum concurrency drogon will auto take num oif cores for laptop
     //and handle threading accordingly
     drogon::app().setThreadNum(0);
     std::cout<<"running\n";
     drogon::app().run();

     return 0;
}
