#include <gtest/gtest.h>

#include "ImagePreprocessing/RasterIngestService.h"
#include "DataHandlers/MiniIOClient.h"
#include "GdalRasterTestSupport.h"
#include "TestGridSupport.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_image_write.h>

#include <cpl_vsi.h>
#include <drogon/MultiPart.h>

#include <array>
#include <chrono>
#include <condition_variable>
#include <cstdint>
#include <mutex>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

namespace minio_test_double
{
std::mutex mutex;
std::condition_variable condition;
std::size_t callCount{0};
std::string bucket;
std::string objectKey;
std::string contentType;
std::size_t uploadedBytes{0};

void reset()
{
    std::scoped_lock lock(mutex);
    callCount = 0;
    bucket.clear();
    objectKey.clear();
    contentType.clear();
    uploadedBytes = 0;
}

bool waitForCall()
{
    std::unique_lock lock(mutex);
    return condition.wait_for(
        lock,
        std::chrono::seconds(2),
        [] { return callCount > 0; });
}
} // namespace minio_test_double

bool MinioClient::uploadBuffer(
    const std::string& bucketName,
    const std::string& key,
    const std::vector<uint8_t>& buffer,
    const std::string& type)
{
    {
        std::scoped_lock lock(minio_test_double::mutex);
        ++minio_test_double::callCount;
        minio_test_double::bucket = bucketName;
        minio_test_double::objectKey = key;
        minio_test_double::contentType = type;
        minio_test_double::uploadedBytes = buffer.size();
    }
    minio_test_double::condition.notify_all();
    return true;
}

namespace
{
using namespace depthwizard::test;

class MultipartUpload
{
public:
    MultipartUpload(const std::vector<uint8_t>& bytes, const std::string& fileName)
    {
        const std::string boundary = "DepthWizardUnitTestBoundary";
        std::string body;
        body.reserve(bytes.size() + 256);
        body += "--" + boundary + "\r\n";
        body += "Content-Disposition: form-data; name=\"file\"; filename=\"" + fileName + "\"\r\n";
        body += "Content-Type: image/tiff\r\n\r\n";
        if (!bytes.empty())
        {
            body.append(
                reinterpret_cast<const char*>(bytes.data()),
                bytes.size());
        }
        body += "\r\n--" + boundary + "--\r\n";

        request_ = drogon::HttpRequest::newHttpRequest();
        request_->setMethod(drogon::Post);

        request_->addHeader(
            "content-type",
            "multipart/form-data; boundary=" + boundary);

        request_->addHeader(
            "content-length",
            std::to_string(body.size()));

        request_->setBody(std::move(body));

        const int parseResult = parser_.parse(request_);

        if (parseResult != 0)
        {
            throw std::runtime_error(
                "Failed to parse test multipart request. Parser result: " +
                std::to_string(parseResult));
        }

        if (parser_.getFiles().size() != 1)
        {
            throw std::runtime_error(
                "Expected exactly one multipart file, received: " +
                std::to_string(parser_.getFiles().size()));
        }
    }

    const drogon::HttpFile& file() const
    {
        return parser_.getFiles().front();
    }

private:
    drogon::HttpRequestPtr request_;
    drogon::MultiPartParser parser_;
};

std::vector<uint8_t> makeGeoTiffBytes(
    bool includeTransform,
    bool includeCrs,
    int bandCount = 3)
{
    const std::string path = uniqueVsiPath("ingest_source");
    VsiPathGuard guard(path);

    const std::vector<uint8_t> red(16, 80);
    const std::vector<uint8_t> green(16, 120);
    const std::vector<uint8_t> blue(16, 160);
    std::vector<std::vector<uint8_t>> bands;
    bands.push_back(red);
    if (bandCount >= 2) bands.push_back(green);
    if (bandCount >= 3) bands.push_back(blue);

    const std::array<double, 6> transform{500000.0, 2.0, 0.0, 2000000.0, 0.0, -8.0};
    const int epsg = 32645;
    createByteGeoTiff(
        path,
        4,
        4,
        bands,
        includeTransform ? &transform : nullptr,
        includeCrs ? &epsg : nullptr);
    return copyVsiFile(path);
}

class RasterIngestServiceTest : public testing::Test
{
protected:
    void SetUp() override
    {
        minio_test_double::reset();
    }
};

TEST_F(RasterIngestServiceTest, IngestsMock4x4ProjectedGeoTiffAndBuildsScene)
{
    const std::vector<uint8_t> bytes = makeGeoTiffBytes(true, true);
    MultipartUpload upload(bytes, "scene.tif");

    const SceneInput scene = timedCall(
        "RasterIngestService::ingestGeoTiff valid-4x4",
        [&] { return RasterIngestService::ingestGeoTiff("valid_4x4", upload.file()); });
    VsiPathGuard outputGuard(scene.inputPath);

    EXPECT_EQ(scene.jobId, "valid_4x4");
    EXPECT_EQ(scene.inputMode, PipelineMode::GEOREFERENCED);
    EXPECT_EQ(scene.width, 4);
    EXPECT_EQ(scene.height, 4);
    EXPECT_EQ(scene.textureMimeType, "image/jpeg");
    EXPECT_EQ(scene.sourceFormat, "GTiff");
    ASSERT_TRUE(scene.spatialMetadata.has_value());
    EXPECT_TRUE(scene.spatialMetadata->isGeoreferenced);
    EXPECT_DOUBLE_EQ(scene.spatialMetadata->pixelSizeX, 2.0);
    EXPECT_DOUBLE_EQ(scene.spatialMetadata->pixelSizeY, 8.0);
    EXPECT_DOUBLE_EQ(scene.spatialMetadata->gsd, 4.0);

    ASSERT_GE(scene.rgbTextureBytes.size(), 2U);
    EXPECT_EQ(scene.rgbTextureBytes[0], 0xFF);
    EXPECT_EQ(scene.rgbTextureBytes[1], 0xD8);

    EXPECT_TRUE(minio_test_double::waitForCall());
    std::scoped_lock lock(minio_test_double::mutex);
    EXPECT_EQ(minio_test_double::bucket, "terrain-assets");
    EXPECT_EQ(minio_test_double::objectKey, "raw_input_valid_4x4.tif");
    EXPECT_EQ(minio_test_double::contentType, "image/tiff");
    EXPECT_EQ(minio_test_double::uploadedBytes, bytes.size());
}

TEST_F(RasterIngestServiceTest, RejectsEmptyUpload)
{
    MultipartUpload upload({0}, "empty.tif");

    drogon::HttpFile emptyFile = upload.file();
    emptyFile.setFile("", 0);

    ASSERT_EQ(emptyFile.fileLength(), 0U);

    EXPECT_THROW(
        static_cast<void>(timedCall(
            "RasterIngestService::ingestGeoTiff empty",
            [&]
            {
                return RasterIngestService::ingestGeoTiff(
                    "empty",
                    emptyFile);
            })),
        std::runtime_error);
}

TEST_F(RasterIngestServiceTest, RejectsCorruptedRasterBytes)
{
    MultipartUpload upload({1, 2, 3, 4, 5}, "corrupt.tif");
    EXPECT_THROW(
        static_cast<void>(timedCall(
            "RasterIngestService::ingestGeoTiff corrupt",
            [&] { return RasterIngestService::ingestGeoTiff("corrupt", upload.file()); })),
        std::runtime_error);
    VSIStatBufL statBuffer{};
    EXPECT_NE(VSIStatL("/vsimem/raw_corrupt.tif", &statBuffer), 0);
    EXPECT_TRUE(minio_test_double::waitForCall());
}

TEST_F(RasterIngestServiceTest, RejectsGeoTiffWithoutAffineTransform)
{
    const std::vector<uint8_t> bytes = makeGeoTiffBytes(false, true);
    MultipartUpload upload(bytes, "missing_transform.tif");
    EXPECT_THROW(
        static_cast<void>(timedCall(
            "RasterIngestService::ingestGeoTiff missing-transform",
            [&]
            {
                return RasterIngestService::ingestGeoTiff(
                    "missing_transform", upload.file());
            })),
        std::runtime_error);
    VSIStatBufL statBuffer{};
    EXPECT_NE(
        VSIStatL("/vsimem/raw_missing_transform.tif", &statBuffer),
        0);
    EXPECT_TRUE(minio_test_double::waitForCall());
}

TEST_F(RasterIngestServiceTest, RejectsGeoTiffWithoutCrs)
{
    const std::vector<uint8_t> bytes = makeGeoTiffBytes(true, false);
    MultipartUpload upload(bytes, "missing_crs.tif");
    EXPECT_THROW(
        static_cast<void>(timedCall(
            "RasterIngestService::ingestGeoTiff missing-crs",
            [&]
            {
                return RasterIngestService::ingestGeoTiff(
                    "missing_crs", upload.file());
            })),
        std::runtime_error);
    VSIStatBufL statBuffer{};
    EXPECT_NE(VSIStatL("/vsimem/raw_missing_crs.tif", &statBuffer), 0);
    EXPECT_TRUE(minio_test_double::waitForCall());
}

} // namespace
