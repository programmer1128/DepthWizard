#include <gtest/gtest.h>
#include "CalibrationController/Sat2Lod2ModalTransport.h"
#include <drogon/HttpClient.h>
#include <drogon/MultiPart.h>
#include <trantor/net/EventLoopThread.h>
#include <algorithm>
#include <arpa/inet.h>
#include <filesystem>
#include <fstream>
#include <netinet/in.h>
#include <sstream>
#include <sys/socket.h>
#include <thread>
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
    const auto client = drogon::HttpClient::newHttpClient(
        "http://127.0.0.1:" + std::to_string(server.port), loop.getLoop());
    const auto [result, response] = client->sendRequest(request, 10.0);
    ASSERT_EQ(result, drogon::ReqResult::Ok);
    server.thread.join();

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
