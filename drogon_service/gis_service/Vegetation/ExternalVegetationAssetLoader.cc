#include "ExternalVegetationAssetLoader.h"

#include <tiny_gltf.h>
#include <opencv2/imgcodecs.hpp>

#include <cmath>
#include <cstring>

#ifndef DEPTHWIZARD_VEGETATION_ASSET_SOURCE_DIR
#define DEPTHWIZARD_VEGETATION_ASSET_SOURCE_DIR ""
#endif

std::size_t ExternalVegetationAsset::triangles() const
{
     std::size_t total = 0;
     for (const ExternalVegetationPart& part : parts) total += part.indices.size() / 3;
     return total;
}

namespace
{
// Copies an accessor into floats (or indices), honouring byteStride.
template <typename Out>
bool readAccessor(const tinygltf::Model& model, int index, int components, std::vector<Out>& out)
{
     if (index < 0 || index >= static_cast<int>(model.accessors.size())) return false;
     const tinygltf::Accessor& accessor = model.accessors[static_cast<std::size_t>(index)];
     if (accessor.bufferView < 0 || accessor.sparse.isSparse) return false;
     const tinygltf::BufferView& view = model.bufferViews[static_cast<std::size_t>(accessor.bufferView)];
     const tinygltf::Buffer& buffer = model.buffers[static_cast<std::size_t>(view.buffer)];
     if (tinygltf::GetNumComponentsInType(static_cast<uint32_t>(accessor.type)) != components) return false;
     const int componentBytes = tinygltf::GetComponentSizeInBytes(static_cast<uint32_t>(accessor.componentType));
     const int stride = accessor.ByteStride(view);
     if (componentBytes <= 0 || stride <= 0) return false;
     const std::size_t start = view.byteOffset + accessor.byteOffset;
     if (accessor.count > 0 &&
         start + static_cast<std::size_t>(stride) * (accessor.count - 1) + static_cast<std::size_t>(componentBytes * components) >
             buffer.data.size())
          return false;
     out.resize(accessor.count * static_cast<std::size_t>(components));
     for (std::size_t i = 0; i < accessor.count; ++i)
          for (int c = 0; c < components; ++c)
          {
               const unsigned char* p = buffer.data.data() + start + i * static_cast<std::size_t>(stride) +
                                        static_cast<std::size_t>(c * componentBytes);
               double value = 0.0;
               switch (accessor.componentType)
               {
               case TINYGLTF_COMPONENT_TYPE_FLOAT: { float f; std::memcpy(&f, p, 4); value = f; break; }
               case TINYGLTF_COMPONENT_TYPE_UNSIGNED_INT: { uint32_t u; std::memcpy(&u, p, 4); value = u; break; }
               case TINYGLTF_COMPONENT_TYPE_UNSIGNED_SHORT: { uint16_t u; std::memcpy(&u, p, 2); value = u; break; }
               case TINYGLTF_COMPONENT_TYPE_UNSIGNED_BYTE: value = *p; break;
               default: return false;
               }
               out[i * static_cast<std::size_t>(components) + static_cast<std::size_t>(c)] = static_cast<Out>(value);
          }
     return true;
}

std::optional<ExternalVegetationAsset> fail(std::string* error, const std::string& message)
{
     if (error) *error = message;
     return std::nullopt;
}
} // namespace

namespace
{
bool failed(std::string* error, const std::string& message)
{
     if (error) *error = message;
     return false;
}

// Parses one normalised prototype mesh: triangle primitives with POSITION,
// NORMAL, TEXCOORD_0 and indices, base-colour textures embedded as PNG/JPEG
// (appended to `images` once per glTF image), finite bounds, base Y = 0,
// top Y = 1, horizontally centred.
bool parseMesh(const tinygltf::Model& model, int meshIndex, VegetationAssetSource expected, const std::string& label,
               ExternalVegetationAsset& asset, std::vector<TextureAsset>& images, std::map<int, int>& imageOf,
               std::string* error)
{
     asset.boundsMin = {1e30f, 1e30f, 1e30f};
     asset.boundsMax = {-1e30f, -1e30f, -1e30f};
     for (const tinygltf::Primitive& primitive : model.meshes[static_cast<std::size_t>(meshIndex)].primitives)
     {
          if (primitive.mode != TINYGLTF_MODE_TRIANGLES && primitive.mode != -1)
               return failed(error, label + "non-triangle primitive");
          ExternalVegetationPart part;
          const auto attribute = [&](const char* name) {
               const auto it = primitive.attributes.find(name);
               return it == primitive.attributes.end() ? -1 : it->second;
          };
          if (!readAccessor(model, attribute("POSITION"), 3, part.positions) ||
              !readAccessor(model, attribute("NORMAL"), 3, part.normals) ||
              !readAccessor(model, attribute("TEXCOORD_0"), 2, part.uvs) ||
              !readAccessor(model, primitive.indices, 1, part.indices))
               return failed(error, label + "a primitive lacks POSITION, NORMAL, TEXCOORD_0 or indices");
          const std::size_t vertices = part.positions.size() / 3;
          if (part.normals.size() != vertices * 3 || part.uvs.size() != vertices * 2 || part.indices.empty() ||
              part.indices.size() % 3 != 0)
               return failed(error, label + "inconsistent attribute counts");
          for (uint32_t i : part.indices)
               if (i >= vertices) return failed(error, label + "index out of range");
          for (std::size_t v = 0; v < vertices; ++v)
               for (int c = 0; c < 3; ++c)
               {
                    const float value = part.positions[v * 3 + static_cast<std::size_t>(c)];
                    if (!std::isfinite(value)) return failed(error, label + "non-finite position");
                    asset.boundsMin[static_cast<std::size_t>(c)] = std::min(asset.boundsMin[static_cast<std::size_t>(c)], value);
                    asset.boundsMax[static_cast<std::size_t>(c)] = std::max(asset.boundsMax[static_cast<std::size_t>(c)], value);
               }
          for (std::size_t v = 0; v < vertices; ++v)
               asset.horizontalRadius = std::max(asset.horizontalRadius,
                   std::hypot(part.positions[v * 3], part.positions[v * 3 + 2]));

          if (primitive.material < 0) return failed(error, label + "primitive without material");
          const tinygltf::Material& material = model.materials[static_cast<std::size_t>(primitive.material)];
          part.materialName = material.name;
          part.baseColorFactor = material.pbrMetallicRoughness.baseColorFactor;
          part.alphaMode = material.alphaMode;
          part.alphaCutoff = material.alphaCutoff;
          part.doubleSided = material.doubleSided;
          part.roughness = material.pbrMetallicRoughness.roughnessFactor;
          const int texture = material.pbrMetallicRoughness.baseColorTexture.index;
          if (texture < 0 || texture >= static_cast<int>(model.textures.size()))
               return failed(error, label + "material " + material.name + " has no base-colour texture");
          const int image = model.textures[static_cast<std::size_t>(texture)].source;
          if (image < 0 || image >= static_cast<int>(model.images.size()))
               return failed(error, label + "texture reference does not resolve");
          if (!imageOf.count(image))
          {
               const tinygltf::Image& source = model.images[static_cast<std::size_t>(image)];
               if (source.bufferView < 0 || (source.mimeType != "image/png" && source.mimeType != "image/jpeg"))
                    return failed(error, label + "texture is not an embedded PNG or JPEG");
               const tinygltf::BufferView& view = model.bufferViews[static_cast<std::size_t>(source.bufferView)];
               const auto& bytes = model.buffers[static_cast<std::size_t>(view.buffer)].data;
               TextureAsset embedded;
               embedded.bytes.assign(bytes.begin() + static_cast<std::ptrdiff_t>(view.byteOffset),
                                    bytes.begin() + static_cast<std::ptrdiff_t>(view.byteOffset + view.byteLength));
               embedded.mimeType = source.mimeType;
               if (cv::imdecode(embedded.bytes, cv::IMREAD_UNCHANGED).empty())
                    return failed(error, label + "texture does not decode");
               const int sampler = model.textures[static_cast<std::size_t>(texture)].sampler;
               if (sampler >= 0)
               {
                    const tinygltf::Sampler& s = model.samplers[static_cast<std::size_t>(sampler)];
                    embedded.wrapS = s.wrapS == TINYGLTF_TEXTURE_WRAP_REPEAT ? TextureWrap::REPEAT : TextureWrap::CLAMP_TO_EDGE;
                    embedded.wrapT = s.wrapT == TINYGLTF_TEXTURE_WRAP_REPEAT ? TextureWrap::REPEAT : TextureWrap::CLAMP_TO_EDGE;
               }
               imageOf[image] = static_cast<int>(images.size());
               images.push_back(std::move(embedded));
          }
          part.image = imageOf.at(image);
          asset.parts.push_back(std::move(part));
     }
     if (asset.parts.empty()) return failed(error, label + "no primitives");
     // Normalised frame: base Y = 0, top Y = 1, centred (bush: radius 1).
     if (std::abs(asset.boundsMin[1]) > 1e-3f || std::abs(asset.boundsMax[1] - 1.0f) > 1e-3f)
          return failed(error, label + "not normalised to base Y = 0 and top Y = 1");
     if (std::abs(asset.boundsMin[0] + asset.boundsMax[0]) > 1e-3f || std::abs(asset.boundsMin[2] + asset.boundsMax[2]) > 1e-3f)
          return failed(error, label + "not horizontally centred");
     if (!(asset.horizontalRadius > 0.0f) ||
         (expected == VegetationAssetSource::SMALL_BUSH && std::abs(asset.horizontalRadius - 1.0f) > 1e-3f))
          return failed(error, label + "invalid normalised horizontal radius");
     return true;
}
} // namespace

std::optional<ExternalVegetationAsset> ExternalVegetationAssetLoader::load(const std::filesystem::path& path,
                                                                           VegetationAssetSource expected,
                                                                           std::string* error)
{
     const std::string label = std::string(toString(expected)) + " asset " + path.string() + ": ";
     std::error_code ec;
     if (!std::filesystem::is_regular_file(path, ec)) return fail(error, label + "file not found");
     tinygltf::TinyGLTF loader;
     tinygltf::Model model;
     std::string err, warn;
     // Images are decoded by the loader, which also proves they are valid.
     if (!loader.LoadBinaryFromFile(&model, &err, &warn, path.string()))
          return fail(error, label + "not a readable GLB (" + err + ")");
     if (model.asset.version != "2.0") return fail(error, label + "glTF version " + model.asset.version + " is not 2.0");
     if (model.meshes.size() != 1 || model.nodes.size() != 1 || model.nodes[0].mesh != 0)
          return fail(error, label + "expected one node with one mesh");
     const tinygltf::Node& node = model.nodes[0];
     if (!node.matrix.empty() || !node.translation.empty() || !node.rotation.empty() || !node.scale.empty())
          return fail(error, label + "the prototype node must carry no transform");

     ExternalVegetationAsset asset;
     asset.source = expected;
     asset.path = path;
     if (model.asset.extras.IsObject())
          for (const char* key : {"title", "author", "source", "license"})
               if (model.asset.extras.Has(key) && model.asset.extras.Get(key).IsString())
                    asset.credits[key] = model.asset.extras.Get(key).Get<std::string>();
     std::map<int, int> imageOf;   // glTF image -> asset image
     if (!parseMesh(model, 0, expected, label, asset, asset.images, imageOf, error)) return std::nullopt;
     return asset;
}

std::optional<ExternalVegetationLibrary> ExternalVegetationAssetLoader::loadLibrary(const std::filesystem::path& path,
                                                                                   VegetationAssetSource expected,
                                                                                   std::string* error)
{
     const std::string label = std::string(toString(expected)) + " library " + path.string() + ": ";
     std::error_code ec;
     if (!std::filesystem::is_regular_file(path, ec))
     {
          if (error) *error = label + "file not found";
          return std::nullopt;
     }
     tinygltf::TinyGLTF loader;
     tinygltf::Model model;
     std::string err, warn;
     if (!loader.LoadBinaryFromFile(&model, &err, &warn, path.string()))
     {
          if (error) *error = label + "not a readable GLB (" + err + ")";
          return std::nullopt;
     }
     if (model.asset.version != "2.0" || model.nodes.empty())
     {
          if (error) *error = label + "not a glTF 2.0 prototype library";
          return std::nullopt;
     }
     ExternalVegetationLibrary library;
     library.path = path;
     if (model.asset.extras.IsObject())
          for (const char* key : {"title", "author", "source", "license"})
               if (model.asset.extras.Has(key) && model.asset.extras.Get(key).IsString())
                    library.credits[key] = model.asset.extras.Get(key).Get<std::string>();
     std::map<int, int> imageOf;
     for (const tinygltf::Node& node : model.nodes)
     {
          if (node.mesh < 0 || !node.matrix.empty() || !node.translation.empty() || !node.rotation.empty() ||
              !node.scale.empty())
          {
               if (error) *error = label + "every prototype node needs one mesh and no transform";
               return std::nullopt;
          }
          ExternalVegetationAsset prototype;
          prototype.source = expected;
          prototype.path = path;
          prototype.credits = library.credits;
          if (!parseMesh(model, node.mesh, expected, label + node.name + ": ", prototype, library.images, imageOf, error))
               return std::nullopt;
          library.prototypes.push_back(std::move(prototype));
     }
     return library;
}

VegetationAssetPrototypeProvider::VegetationAssetPrototypeProvider(const std::filesystem::path& directory)
     : directory_(directory)
{
     std::string bushError, forestError;
     bush_ = ExternalVegetationAssetLoader::load(directory / "small_bush.glb", VegetationAssetSource::SMALL_BUSH, &bushError);
     forest_ = ExternalVegetationAssetLoader::load(directory / "forest_patch.glb", VegetationAssetSource::FOREST_PATCH,
                                                    &forestError);
     std::string treesError;
     forestTrees_ = ExternalVegetationAssetLoader::loadLibrary(directory / "forest_trees.glb",
                                                               VegetationAssetSource::FOREST_TREE, &treesError);
     error_ = bushError;
     if (!forestError.empty()) error_ += (error_.empty() ? "" : "; ") + forestError;
     if (!treesError.empty()) error_ += (error_.empty() ? "" : "; ") + treesError;
}

std::filesystem::path VegetationAssetPrototypeProvider::defaultDirectory()
{
     std::error_code ec;
     const std::filesystem::path executable = std::filesystem::read_symlink("/proc/self/exe", ec);
     if (!ec)
     {
          const std::filesystem::path bundled = executable.parent_path() / "assets" / "vegetation" / "optimized";
          if (std::filesystem::is_directory(bundled, ec)) return bundled;
     }
     return std::filesystem::path(DEPTHWIZARD_VEGETATION_ASSET_SOURCE_DIR);
}

const VegetationAssetPrototypeProvider& VegetationAssetPrototypeProvider::instance()
{
     static const VegetationAssetPrototypeProvider provider(defaultDirectory());
     return provider;
}
