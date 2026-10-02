#include "BaselineInspector.h"

#include <draco/compression/decode.h>
#include <drogon/utils/Utilities.h>
#include <gdal_priv.h>
#include <tiny_gltf.h>

#include <algorithm>
#include <cmath>
#include <cstring>
#include <fstream>
#include <limits>
#include <memory>
#include <set>
#include <stdexcept>

namespace
{
struct Bounds
{
    double min[3]{std::numeric_limits<double>::infinity(),
                  std::numeric_limits<double>::infinity(),
                  std::numeric_limits<double>::infinity()};
    double max[3]{-std::numeric_limits<double>::infinity(),
                  -std::numeric_limits<double>::infinity(),
                  -std::numeric_limits<double>::infinity()};

    void add(const double point[3])
    {
        for (int axis = 0; axis < 3; ++axis)
        {
            min[axis] = std::min(min[axis], point[axis]);
            max[axis] = std::max(max[axis], point[axis]);
        }
    }
    void add(const Bounds& other)
    {
        if (!other.valid()) return;
        add(other.min);
        add(other.max);
    }
    bool valid() const { return std::isfinite(min[0]); }

    Json::Value toJson() const
    {
        Json::Value value(Json::objectValue);
        if (!valid()) return Json::Value(Json::nullValue);
        Json::Value low(Json::arrayValue), high(Json::arrayValue);
        for (int axis = 0; axis < 3; ++axis)
        {
            low.append(min[axis]);
            high.append(max[axis]);
        }
        value["min"] = low;
        value["max"] = high;
        return value;
    }
};

Json::Value toJson(const tinygltf::Value& value)
{
    if (value.IsBool()) return value.Get<bool>();
    if (value.IsInt()) return value.Get<int>();
    if (value.IsNumber()) return value.GetNumberAsDouble();
    if (value.IsString()) return value.Get<std::string>();
    if (value.IsArray())
    {
        Json::Value array(Json::arrayValue);
        for (std::size_t index = 0; index < value.ArrayLen(); ++index)
            array.append(toJson(value.Get(static_cast<int>(index))));
        return array;
    }
    if (value.IsObject())
    {
        Json::Value object(Json::objectValue);
        for (const std::string& key : value.Keys()) object[key] = toJson(value.Get(key));
        return object;
    }
    return Json::Value(Json::nullValue);
}

// One element of an uncompressed accessor as doubles.
std::vector<double> readAccessorElement(const tinygltf::Model& model,
                                        const tinygltf::Accessor& accessor,
                                        std::size_t element)
{
    const int components = tinygltf::GetNumComponentsInType(accessor.type);
    const int componentSize = tinygltf::GetComponentSizeInBytes(accessor.componentType);
    const auto& view = model.bufferViews.at(accessor.bufferView);
    const auto& buffer = model.buffers.at(view.buffer);
    const std::size_t stride = view.byteStride > 0
        ? view.byteStride : static_cast<std::size_t>(components * componentSize);
    const std::size_t base = view.byteOffset + accessor.byteOffset + element * stride;
    std::vector<double> values(components);
    for (int component = 0; component < components; ++component)
    {
        const unsigned char* source = buffer.data.data() + base + component * componentSize;
        switch (accessor.componentType)
        {
            case TINYGLTF_COMPONENT_TYPE_FLOAT: { float v; std::memcpy(&v, source, 4); values[component] = v; break; }
            case TINYGLTF_COMPONENT_TYPE_UNSIGNED_INT: { uint32_t v; std::memcpy(&v, source, 4); values[component] = v; break; }
            case TINYGLTF_COMPONENT_TYPE_UNSIGNED_SHORT: { uint16_t v; std::memcpy(&v, source, 2); values[component] = v; break; }
            case TINYGLTF_COMPONENT_TYPE_UNSIGNED_BYTE: values[component] = *source; break;
            case TINYGLTF_COMPONENT_TYPE_SHORT: { int16_t v; std::memcpy(&v, source, 2); values[component] = v; break; }
            case TINYGLTF_COMPONENT_TYPE_BYTE: values[component] = static_cast<int8_t>(*source); break;
            default: throw std::runtime_error("unsupported accessor component type");
        }
    }
    return values;
}

struct DecodedPrimitive
{
    std::size_t vertexCount{0};
    std::size_t indexCount{0};
    Bounds bounds;
    std::set<long long> featureIds;
};

DecodedPrimitive decodeDraco(const tinygltf::Model& model, const tinygltf::Primitive& primitive)
{
    const auto& extension = primitive.extensions.at("KHR_draco_mesh_compression");
    const auto& view = model.bufferViews.at(extension.Get("bufferView").Get<int>());
    const auto& buffer = model.buffers.at(view.buffer);
    draco::DecoderBuffer source;
    source.Init(reinterpret_cast<const char*>(buffer.data.data() + view.byteOffset), view.byteLength);
    draco::Decoder decoder;
    auto decoded = decoder.DecodeMeshFromBuffer(&source);
    if (!decoded.ok()) throw std::runtime_error("Draco decode failed: " + decoded.status().error_msg_string());
    const std::unique_ptr<draco::Mesh> mesh = std::move(decoded).value();

    DecodedPrimitive result;
    result.vertexCount = mesh->num_points();
    result.indexCount = static_cast<std::size_t>(mesh->num_faces()) * 3;
    const tinygltf::Value& attributes = extension.Get("attributes");
    const auto attribute = [&](const char* name) -> const draco::PointAttribute*
    {
        if (!attributes.Has(name)) return nullptr;
        return mesh->GetAttributeByUniqueId(static_cast<uint32_t>(attributes.Get(name).Get<int>()));
    };
    if (const auto* positions = attribute("POSITION"))
        for (draco::PointIndex point(0); point < mesh->num_points(); ++point)
        {
            float xyz[3];
            positions->ConvertValue<float>(positions->mapped_index(point), 3, xyz);
            const double p[3]{xyz[0], xyz[1], xyz[2]};
            result.bounds.add(p);
        }
    if (const auto* ids = attribute("_FEATURE_ID_0"))
        for (draco::PointIndex point(0); point < mesh->num_points(); ++point)
        {
            float id = 0.0f;
            ids->ConvertValue<float>(ids->mapped_index(point), 1, &id);
            result.featureIds.insert(std::llround(id));
        }
    return result;
}

DecodedPrimitive decodePlain(const tinygltf::Model& model, const tinygltf::Primitive& primitive)
{
    DecodedPrimitive result;
    if (const auto found = primitive.attributes.find("POSITION"); found != primitive.attributes.end())
    {
        const auto& accessor = model.accessors.at(found->second);
        result.vertexCount = accessor.count;
        for (std::size_t element = 0; element < accessor.count; ++element)
        {
            const auto p = readAccessorElement(model, accessor, element);
            const double xyz[3]{p[0], p[1], p[2]};
            result.bounds.add(xyz);
        }
    }
    if (const auto found = primitive.attributes.find("_FEATURE_ID_0"); found != primitive.attributes.end())
    {
        const auto& accessor = model.accessors.at(found->second);
        for (std::size_t element = 0; element < accessor.count; ++element)
            result.featureIds.insert(std::llround(readAccessorElement(model, accessor, element)[0]));
    }
    result.indexCount = primitive.indices >= 0 ? model.accessors.at(primitive.indices).count
                                               : result.vertexCount;
    return result;
}

Json::Value materialJson(const tinygltf::Model& model, int index)
{
    if (index < 0) return Json::Value(Json::nullValue);
    const auto& material = model.materials.at(index);
    Json::Value value(Json::objectValue);
    value["name"] = material.name;
    Json::Value factor(Json::arrayValue);
    for (double component : material.pbrMetallicRoughness.baseColorFactor) factor.append(component);
    value["base_color_factor"] = factor;
    value["metallic"] = material.pbrMetallicRoughness.metallicFactor;
    value["roughness"] = material.pbrMetallicRoughness.roughnessFactor;
    value["double_sided"] = material.doubleSided;
    value["alpha_mode"] = material.alphaMode;
    Json::Value extensions(Json::arrayValue);
    for (const auto& [name, unused] : material.extensions) extensions.append(name);
    value["extensions"] = extensions;
    const int texture = material.pbrMetallicRoughness.baseColorTexture.index;
    if (texture >= 0)
    {
        const auto& tex = model.textures.at(texture);
        Json::Value binding(Json::objectValue);
        binding["texture"] = texture;
        binding["image"] = tex.source;
        binding["sampler"] = tex.sampler;
        if (tex.sampler >= 0)
        {
            const auto& sampler = model.samplers.at(tex.sampler);
            binding["wrap_s"] = sampler.wrapS;
            binding["wrap_t"] = sampler.wrapT;
        }
        value["base_color_texture"] = binding;
    }
    return value;
}

std::string canonicalPixelDigest(std::vector<double>& values)
{
    for (double& value : values)
    {
        if (std::isnan(value)) value = std::numeric_limits<double>::quiet_NaN();
        else if (value == 0.0) value = 0.0; // folds -0.0 into +0.0
    }
    return drogon::utils::getSha256(reinterpret_cast<const char*>(values.data()),
                                    values.size() * sizeof(double));
}
} // namespace

Json::Value BaselineInspector::inspectGlb(const std::vector<uint8_t>& bytes)
{
    tinygltf::TinyGLTF loader;
    tinygltf::Model model;
    std::string error, warning;
    if (!loader.LoadBinaryFromMemory(&model, &error, &warning, bytes.data(),
                                     static_cast<unsigned int>(bytes.size())))
        throw std::runtime_error("not a loadable GLB: " + error);

    Json::Value report(Json::objectValue);
    report["schema"] = "depthwizard.baseline.glb.v1";
    report["byte_size"] = static_cast<Json::UInt64>(bytes.size());
    report["generator"] = model.asset.generator;
    report["extras"] = toJson(model.asset.extras);
    Json::Value used(Json::arrayValue), required(Json::arrayValue);
    for (const auto& name : model.extensionsUsed) used.append(name);
    for (const auto& name : model.extensionsRequired) required.append(name);
    report["extensions_used"] = used;
    report["extensions_required"] = required;

    Json::Value counts(Json::objectValue);
    counts["meshes"] = static_cast<Json::UInt64>(model.meshes.size());
    counts["nodes"] = static_cast<Json::UInt64>(model.nodes.size());
    counts["materials"] = static_cast<Json::UInt64>(model.materials.size());
    counts["textures"] = static_cast<Json::UInt64>(model.textures.size());
    counts["images"] = static_cast<Json::UInt64>(model.images.size());
    counts["samplers"] = static_cast<Json::UInt64>(model.samplers.size());
    report["counts"] = counts;

    Json::Value images(Json::arrayValue);
    for (const auto& image : model.images)
    {
        Json::Value entry(Json::objectValue);
        entry["mime_type"] = image.mimeType;
        entry["width"] = image.width;
        entry["height"] = image.height;
        images.append(entry);
    }
    report["images"] = images;

    Json::Value primitives(Json::arrayValue);
    Bounds sceneBounds;
    std::set<long long> buildingIds;
    std::size_t vertices = 0, triangles = 0, lines = 0;
    for (std::size_t meshIndex = 0; meshIndex < model.meshes.size(); ++meshIndex)
        for (std::size_t primitiveIndex = 0; primitiveIndex < model.meshes[meshIndex].primitives.size();
             ++primitiveIndex)
        {
            const auto& primitive = model.meshes[meshIndex].primitives[primitiveIndex];
            const bool compressed = primitive.extensions.count("KHR_draco_mesh_compression") > 0;
            const DecodedPrimitive decoded = compressed ? decodeDraco(model, primitive)
                                                        : decodePlain(model, primitive);
            Json::Value entry(Json::objectValue);
            entry["mesh"] = static_cast<Json::UInt64>(meshIndex);
            entry["primitive"] = static_cast<Json::UInt64>(primitiveIndex);
            entry["mode"] = primitive.mode;
            entry["draco"] = compressed;
            Json::Value attributes(Json::arrayValue);
            for (const auto& [name, unused] : primitive.attributes) attributes.append(name);
            entry["attributes"] = attributes;
            entry["vertex_count"] = static_cast<Json::UInt64>(decoded.vertexCount);
            entry["index_count"] = static_cast<Json::UInt64>(decoded.indexCount);
            const std::size_t primitiveTriangles = primitive.mode == TINYGLTF_MODE_TRIANGLES
                ? decoded.indexCount / 3 : 0;
            const std::size_t primitiveLines = primitive.mode == TINYGLTF_MODE_LINE
                ? decoded.indexCount / 2 : 0;
            entry["triangle_count"] = static_cast<Json::UInt64>(primitiveTriangles);
            entry["line_count"] = static_cast<Json::UInt64>(primitiveLines);
            entry["bounds"] = decoded.bounds.toJson();
            Json::Value ids(Json::arrayValue);
            for (long long id : decoded.featureIds) ids.append(static_cast<Json::Int64>(id));
            entry["feature_ids"] = ids;
            entry["material"] = materialJson(model, primitive.material);
            primitives.append(entry);

            sceneBounds.add(decoded.bounds);
            for (long long id : decoded.featureIds) if (id > 0) buildingIds.insert(id);
            vertices += decoded.vertexCount;
            triangles += primitiveTriangles;
            lines += primitiveLines;
        }
    report["primitives"] = primitives;

    Json::Value totals(Json::objectValue);
    totals["vertices"] = static_cast<Json::UInt64>(vertices);
    totals["triangles"] = static_cast<Json::UInt64>(triangles);
    totals["lines"] = static_cast<Json::UInt64>(lines);
    totals["bounds"] = sceneBounds.toJson();
    report["totals"] = totals;
    Json::Value ids(Json::arrayValue);
    for (long long id : buildingIds) ids.append(static_cast<Json::Int64>(id));
    report["building_ids"] = ids;
    report["building_id_count"] = static_cast<Json::UInt64>(buildingIds.size());
    return report;
}

Json::Value BaselineInspector::inspectGlbFile(const std::string& path)
{
    std::ifstream file(path, std::ios::binary);
    if (!file) throw std::runtime_error("cannot open " + path);
    const std::vector<uint8_t> bytes((std::istreambuf_iterator<char>(file)),
                                     std::istreambuf_iterator<char>());
    return inspectGlb(bytes);
}

Json::Value BaselineInspector::inspectRaster(const std::string& path)
{
    std::unique_ptr<GDALDataset, void (*)(GDALDataset*)> dataset(
        static_cast<GDALDataset*>(GDALOpen(path.c_str(), GA_ReadOnly)),
        [](GDALDataset* d) { if (d) GDALClose(d); });
    if (!dataset) throw std::runtime_error("cannot open raster " + path);

    Json::Value report(Json::objectValue);
    report["schema"] = "depthwizard.baseline.raster.v1";
    const int width = dataset->GetRasterXSize();
    const int height = dataset->GetRasterYSize();
    report["width"] = width;
    report["height"] = height;
    double geoTransform[6];
    Json::Value transform(Json::arrayValue);
    if (dataset->GetGeoTransform(geoTransform) == CE_None)
        for (double value : geoTransform) transform.append(value);
    report["geotransform"] = transform;
    const std::string wkt = dataset->GetProjectionRef() ? dataset->GetProjectionRef() : "";
    report["crs_sha256"] = wkt.empty() ? std::string() : drogon::utils::getSha256(wkt.data(), wkt.size());

    Json::Value bands(Json::arrayValue);
    for (int bandIndex = 1; bandIndex <= dataset->GetRasterCount(); ++bandIndex)
    {
        GDALRasterBand* band = dataset->GetRasterBand(bandIndex);
        std::vector<double> values(static_cast<std::size_t>(width) * height);
        if (band->RasterIO(GF_Read, 0, 0, width, height, values.data(), width, height,
                           GDT_Float64, 0, 0) != CE_None)
            throw std::runtime_error("cannot read band " + std::to_string(bandIndex) + " of " + path);
        int hasNoData = 0;
        const double noData = band->GetNoDataValue(&hasNoData);

        std::size_t valid = 0, invalid = 0;
        double minimum = std::numeric_limits<double>::infinity();
        double maximum = -std::numeric_limits<double>::infinity();
        double sum = 0.0;
        for (double value : values)
        {
            const bool isNoData = std::isnan(value) ||
                (hasNoData && !std::isnan(noData) && value == noData);
            if (isNoData) { ++invalid; continue; }
            ++valid;
            minimum = std::min(minimum, value);
            maximum = std::max(maximum, value);
            sum += value;
        }
        Json::Value entry(Json::objectValue);
        entry["data_type"] = GDALGetDataTypeName(band->GetRasterDataType());
        entry["nodata"] = hasNoData ? (std::isnan(noData) ? Json::Value("nan") : Json::Value(noData))
                                    : Json::Value(Json::nullValue);
        entry["valid_pixels"] = static_cast<Json::UInt64>(valid);
        entry["invalid_pixels"] = static_cast<Json::UInt64>(invalid);
        entry["min"] = valid ? Json::Value(minimum) : Json::Value(Json::nullValue);
        entry["max"] = valid ? Json::Value(maximum) : Json::Value(Json::nullValue);
        entry["mean"] = valid ? Json::Value(sum / static_cast<double>(valid)) : Json::Value(Json::nullValue);
        entry["pixel_sha256"] = canonicalPixelDigest(values);
        bands.append(entry);
    }
    report["bands"] = bands;
    return report;
}
