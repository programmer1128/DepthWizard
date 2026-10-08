#include <gtest/gtest.h>
#include "CalibrationController/Sat2Lod2ModalTransport.h"
#include <drogon/HttpClient.h>
#include <drogon/utils/coroutine.h>
#include <drogon/MultiPart.h>
#include <trantor/net/EventLoopThread.h>
#include <algorithm>
#include <arpa/inet.h>
#include <filesystem>
#include <fstream>
#include <future>
#include <netinet/in.h>
#include <sstream>
#include <sys/socket.h>
#include <cstdlib>
#include <thread>
#include <vector>
#include <unistd.h>

namespace
{
// Accepts one HTTP request on a loopback port and records its raw bytes, so
// the test sees exactly what drogon puts on the wire.
struct CapturingServer
{
    int listener{-1};
    uint16_t port{0};
    std::string headers;
    std::string body;
    std::thread thread;

    CapturingServer()
    {
        listener = ::socket(AF_INET, SOCK_STREAM, 0);
        sockaddr_in address{};
        address.sin_family = AF_INET;
        address.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
        ::bind(listener, reinterpret_cast<sockaddr*>(&address), sizeof(address));
        ::listen(listener, 1);
        socklen_t length = sizeof(address);
        ::getsockname(listener, reinterpret_cast<sockaddr*>(&address), &length);
        port = ntohs(address.sin_port);
        thread = std::thread([this] { serveOnce(); });
    }

    void serveOnce()
    {
        const int connection = ::accept(listener, nullptr, nullptr);
        std::string raw;
        char buffer[65536];
        std::size_t expected = std::string::npos;
        while (true)
        {
            const auto received = ::recv(connection, buffer, sizeof(buffer), 0);
            if (received <= 0) break;
            raw.append(buffer, static_cast<std::size_t>(received));
            const auto end = raw.find("\r\n\r\n");
            if (end != std::string::npos && expected == std::string::npos)
            {
                headers = raw.substr(0, end);
                std::string lower = headers;
                std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
                const auto field = lower.find("content-length:");
                expected = end + 4 + std::stoul(lower.substr(field + 15));
            }
            if (expected != std::string::npos && raw.size() >= expected) break;
        }
        body = raw.substr(headers.size() + 4);
        const std::string reply =
            "HTTP/1.1 200 OK\r\nContent-Length: 2\r\nContent-Type: application/json\r\n\r\n{}";
        ::send(connection, reply.data(), reply.size(), 0);
        ::close(connection);
    }

    ~CapturingServer()
    {
        if (thread.joinable()) thread.join();
        ::close(listener);
    }
};
} // namespace

TEST(Sat2Lod2ModalTransportTest, SendsOneMultipartContentTypeWithThreeNamedFiles)
{
    const auto directory = std::filesystem::temp_directory_path() /
        ("sat_modal_transport_" + std::to_string(getpid()));
    std::filesystem::create_directories(directory);
    const auto write = [&](const char* name, const std::string& contents)
    {
        const auto path = directory / name;
        std::ofstream file(path, std::ios::binary);
        file.write(contents.data(), static_cast<std::streamsize>(contents.size()));
        file.close();
        return path.string();
    };
    const auto request = Sat2Lod2ModalTransport::makeRequest(
        write("ndsm.tif", std::string("height\0data", 11)),
        write("ortho.tif", "image"),
        write("label.tif", "mask"));
    ASSERT_TRUE(request);
    EXPECT_EQ(request->method(), drogon::Post);
    EXPECT_EQ(request->path(), "/api/v1/reconstruct");

    CapturingServer server;
    trantor::EventLoopThread loop;
    loop.run();
    auto client = drogon::HttpClient::newHttpClient(
        "http://127.0.0.1:" + std::to_string(server.port), loop.getLoop());
    const auto [result, response] = client->sendRequest(request, 10.0);
    server.thread.join();
    // Release the client on its own loop, before the loop stops: the server
    // closing the connection can still be delivering callbacks to it.
    std::promise<void> released;
    loop.getLoop()->runInLoop([&client, &released]
    {
        client.reset();
        released.set_value();
    });
    released.get_future().wait();
    ASSERT_EQ(result, drogon::ReqResult::Ok);

    // FastAPI reads the first content-type header. Drogon's default
    // "text/plain" must not precede the multipart header, or every job is
    // rejected with 422 and the backend silently falls back to native.
    std::string contentType;
    int contentTypeHeaders = 0;
    std::istringstream lines(server.headers);
    for (std::string line; std::getline(lines, line);)
    {
        std::string lower = line;
        std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
        if (lower.rfind("content-type:", 0) != 0) continue;
        ++contentTypeHeaders;
        contentType = line.substr(line.find(':') + 1);
        contentType.erase(0, contentType.find_first_not_of(' '));
        contentType.erase(contentType.find_last_not_of("\r ") + 1);
    }
    EXPECT_EQ(contentTypeHeaders, 1);
    EXPECT_EQ(contentType.rfind("multipart/form-data; boundary=", 0), 0U) << contentType;

    const auto received = drogon::HttpRequest::newHttpRequest();
    received->setMethod(drogon::Post);
    received->addHeader("content-type", contentType);
    received->setBody(server.body);
    drogon::MultiPartParser parser;
    ASSERT_EQ(parser.parse(received), 0);
    const auto files = parser.getFilesMap();
    ASSERT_EQ(files.size(), 3U);
    EXPECT_EQ(files.at("dsm").fileContent(), std::string("height\0data", 11));
    EXPECT_EQ(files.at("ortho").fileContent(), "image");
    EXPECT_EQ(files.at("label").fileContent(), "mask");
    std::filesystem::remove_all(directory);
}

TEST(Sat2Lod2ModalTransportTest, ReadsInlineBuildingDocument)
{
    Json::Value body;
    body["status"] = "success";
    body["buildings"]["schema"] = "depthwizard.sat2lod2.v1";
    body["buildings"]["segments"] = Json::arrayValue;
    const auto response = drogon::HttpResponse::newHttpJsonResponse(body);
    const auto buildings = Sat2Lod2ModalTransport::readBuildings(response);
    EXPECT_EQ(buildings["schema"].asString(), "depthwizard.sat2lod2.v1");
    EXPECT_TRUE(buildings["segments"].isArray());

    const auto invalid = drogon::HttpResponse::newHttpJsonResponse(Json::Value{});
    EXPECT_THROW(Sat2Lod2ModalTransport::readBuildings(invalid), std::runtime_error);
}

namespace
{
// Answers one connection per scripted reply, in order, like a Modal web
// endpoint that first redirects to a result URL and then returns the result.
struct ScriptedServer
{
    int listener{-1};
    uint16_t port{0};
    std::vector<std::string> replies;
    std::vector<std::string> requestLines;
    std::thread thread;

    ScriptedServer()
    {
        listener = ::socket(AF_INET, SOCK_STREAM, 0);
        sockaddr_in address{};
        address.sin_family = AF_INET;
        address.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
        ::bind(listener, reinterpret_cast<sockaddr*>(&address), sizeof(address));
        ::listen(listener, 4);
        socklen_t length = sizeof(address);
        ::getsockname(listener, reinterpret_cast<sockaddr*>(&address), &length);
        port = ntohs(address.sin_port);
    }

    // Separate from construction so replies can name the bound port.
    void start(std::vector<std::string> scripted)
    {
        replies = std::move(scripted);
        thread = std::thread([this]
        {
            for (const std::string& reply : replies)
            {
                const int connection = ::accept(listener, nullptr, nullptr);
                if (connection < 0) break; // listener shut down: test finished early
                std::string raw;
                char buffer[65536];
                std::size_t expected = std::string::npos;
                while (true)
                {
                    const auto received = ::recv(connection, buffer, sizeof(buffer), 0);
                    if (received <= 0) break;
                    raw.append(buffer, static_cast<std::size_t>(received));
                    const auto end = raw.find("\r\n\r\n");
                    if (end != std::string::npos && expected == std::string::npos)
                    {
                        std::string lower = raw.substr(0, end);
                        std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
                        const auto field = lower.find("content-length:");
                        expected = end + 4 + (field == std::string::npos
                                                  ? 0 : std::stoul(lower.substr(field + 15)));
                    }
                    if (expected != std::string::npos && raw.size() >= expected) break;
                }
                requestLines.push_back(raw.substr(0, raw.find("\r\n")));
                ::send(connection, reply.data(), reply.size(), 0);
                ::close(connection);
            }
        });
    }

    ~ScriptedServer()
    {
        // Unblock a pending accept() so a failed test cannot hang here.
        ::shutdown(listener, SHUT_RDWR);
        if (thread.joinable()) thread.join();
        ::close(listener);
    }
};

drogon::HttpResponsePtr redirectResponse(drogon::HttpStatusCode code, const std::string& location)
{
    auto response = drogon::HttpResponse::newHttpResponse();
    response->setStatusCode(code);
    if (!location.empty()) response->addHeader("Location", location);
    return response;
}
} // namespace

TEST(Sat2Lod2ModalTransportTest, ParsesModalResultRedirects)
{
    const auto absolute = Sat2Lod2ModalTransport::redirectOf(redirectResponse(
        drogon::k303SeeOther,
        "https://user--app.modal.run/api/v1/reconstruct?__modal_function_call_id=fc-1"));
    ASSERT_TRUE(absolute);
    EXPECT_EQ(absolute->origin, "https://user--app.modal.run");
    EXPECT_EQ(absolute->pathAndQuery, "/api/v1/reconstruct?__modal_function_call_id=fc-1");

    const auto relative = Sat2Lod2ModalTransport::redirectOf(
        redirectResponse(drogon::k303SeeOther, "/result?id=2"));
    ASSERT_TRUE(relative);
    EXPECT_TRUE(relative->origin.empty());
    EXPECT_EQ(relative->pathAndQuery, "/result?id=2");

    EXPECT_FALSE(Sat2Lod2ModalTransport::redirectOf(redirectResponse(drogon::k200OK, "/x")));
    // 307 would require resending the upload body; it is not followed.
    EXPECT_FALSE(Sat2Lod2ModalTransport::redirectOf(
        redirectResponse(drogon::k307TemporaryRedirect, "/x")));
    EXPECT_FALSE(Sat2Lod2ModalTransport::redirectOf(redirectResponse(drogon::k303SeeOther, "")));
}

TEST(Sat2Lod2ModalTransportTest, ResolvesEndpointFromEnvironment)
{
    ::unsetenv("DEPTHWIZARD_SAT2LOD2");
    ::unsetenv("DEPTHWIZARD_SAT2LOD2_TRANSPORT");
    ::setenv("DEPTHWIZARD_SAT2LOD2_URL", "http://127.0.0.1:8000/", 1);
    auto endpoint = Sat2Lod2ModalTransport::endpointFromEnvironment();
    EXPECT_TRUE(endpoint.enabled);
    EXPECT_TRUE(endpoint.local);
    EXPECT_EQ(endpoint.url, "http://127.0.0.1:8000");

    ::setenv("DEPTHWIZARD_SAT2LOD2_URL", "https://user--app.modal.run", 1);
    endpoint = Sat2Lod2ModalTransport::endpointFromEnvironment();
    EXPECT_FALSE(endpoint.local);

    ::setenv("DEPTHWIZARD_SAT2LOD2", "0", 1);
    EXPECT_FALSE(Sat2Lod2ModalTransport::endpointFromEnvironment().enabled);

    ::setenv("DEPTHWIZARD_SAT2LOD2_TRANSPORT", "carrier-pigeon", 1);
    EXPECT_THROW(Sat2Lod2ModalTransport::endpointFromEnvironment(), std::runtime_error);
    ::unsetenv("DEPTHWIZARD_SAT2LOD2");
    ::unsetenv("DEPTHWIZARD_SAT2LOD2_TRANSPORT");
    ::unsetenv("DEPTHWIZARD_SAT2LOD2_URL");
}

TEST(Sat2Lod2ModalTransportTest, FollowsModalResultRedirectToTheBuildingDocument)
{
    // Modal cuts web requests at 150 s and answers 303 to a result URL.
    ScriptedServer modal;
    const std::string origin = "http://127.0.0.1:" + std::to_string(modal.port);
    const std::string resultPath = "/api/v1/reconstruct?__modal_function_call_id=fc-123";
    const std::string body =
        R"({"status":"success","buildings":{"schema":"depthwizard.sat2lod2.v1","segments":[]}})";
    modal.start({
        "HTTP/1.1 303 See Other\r\nLocation: " + origin + resultPath +
            "\r\nContent-Length: 0\r\nConnection: close\r\n\r\n",
        "HTTP/1.1 200 OK\r\nContent-Type: application/json\r\nContent-Length: " +
            std::to_string(body.size()) + "\r\nConnection: close\r\n\r\n" + body});

    auto request = drogon::HttpRequest::newHttpRequest();
    request->setMethod(drogon::Post);
    request->setPath("/api/v1/reconstruct");
    request->setBody("upload");

    trantor::EventLoopThread loop;
    loop.run();
    const auto response = drogon::sync_wait(
        Sat2Lod2ModalTransport::send(origin, request, 10.0, loop.getLoop()));
    modal.thread.join();

    ASSERT_EQ(modal.requestLines.size(), 2U);
    EXPECT_EQ(modal.requestLines[0], "POST /api/v1/reconstruct HTTP/1.1");
    // The result URL is fetched with GET, query string intact (not encoded).
    EXPECT_EQ(modal.requestLines[1], "GET " + resultPath + " HTTP/1.1");
    ASSERT_TRUE(response);
    EXPECT_EQ(response->statusCode(), drogon::k200OK);
    EXPECT_TRUE(Sat2Lod2ModalTransport::readBuildings(response)["segments"].isArray());
}
