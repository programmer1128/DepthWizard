#include "City3dResultImporter.h"

#include <json/json.h>

#include <algorithm>
#include <cmath>
#include <fstream>
#include <limits>
#include <sstream>

namespace fs = std::filesystem;

namespace
{

constexpr std::uintmax_t kMaxManifestBytes = 1u << 20;
constexpr std::uintmax_t kMaxObjBytes = 32u << 20;
constexpr std::size_t kMaxObjVertices = 200000;
constexpr double kMinTriangleArea = 1.0e-6; // square metres

using Vec3 = std::array<double, 3>;

Vec3 subtract(const Vec3& a, const Vec3& b) { return {a[0] - b[0], a[1] - b[1], a[2] - b[2]}; }
Vec3 cross(const Vec3& a, const Vec3& b)
{
     return {a[1] * b[2] - a[2] * b[1], a[2] * b[0] - a[0] * b[2], a[0] * b[1] - a[1] * b[0]};
}
double norm(const Vec3& v) { return std::sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]); }

bool readFile(const fs::path& path, std::uintmax_t limit, std::string& contents)
{
     std::error_code error;
     const fs::file_status status = fs::symlink_status(path, error);
     if (error || !fs::is_regular_file(status)) return false;
     if (fs::file_size(path, error) > limit || error) return false;
     std::ifstream file(path, std::ios::binary);
     std::ostringstream buffer;
     buffer << file.rdbuf();
     contents = buffer.str();
     return static_cast<bool>(file) || file.eof();
}

City3dImportResult rejected(City3dImportResult result, const std::string& reason)
{
     result.accepted = false;
     result.reason = reason;
     result.shell = {};
     return result;
}

} // namespace

std::vector<std::array<std::size_t, 3>> City3dResultImporter::triangulatePolygon(const std::vector<Vec3>& polygon)
{
     std::vector<std::array<std::size_t, 3>> triangles;
     const std::size_t count = polygon.size();
     if (count < 3) return triangles;

     // Newell normal; project onto the plane of its two smallest components.
     Vec3 normal{0.0, 0.0, 0.0};
     for (std::size_t i = 0; i < count; ++i)
     {
          const Vec3& a = polygon[i];
          const Vec3& b = polygon[(i + 1) % count];
          normal[0] += (a[1] - b[1]) * (a[2] + b[2]);
          normal[1] += (a[2] - b[2]) * (a[0] + b[0]);
          normal[2] += (a[0] - b[0]) * (a[1] + b[1]);
     }
     const std::size_t drop = std::abs(normal[0]) > std::abs(normal[1])
         ? (std::abs(normal[0]) > std::abs(normal[2]) ? 0 : 2)
         : (std::abs(normal[1]) > std::abs(normal[2]) ? 1 : 2);
     const std::size_t u = drop == 0 ? 1 : 0;
     const std::size_t v = drop == 2 ? 1 : 2;
     std::vector<std::array<double, 2>> flat(count);
     double twiceArea = 0.0;
     for (std::size_t i = 0; i < count; ++i) flat[i] = {polygon[i][u], polygon[i][v]};
     for (std::size_t i = 0; i < count; ++i)
          twiceArea += flat[i][0] * flat[(i + 1) % count][1] - flat[(i + 1) % count][0] * flat[i][1];
     if (std::abs(twiceArea) < 1e-12) return triangles;
     const double orientation = twiceArea > 0.0 ? 1.0 : -1.0;
     const auto turn = [&](std::size_t a, std::size_t b, std::size_t c)
     {
          return orientation * ((flat[b][0] - flat[a][0]) * (flat[c][1] - flat[a][1]) -
                                (flat[b][1] - flat[a][1]) * (flat[c][0] - flat[a][0]));
     };

     std::vector<std::size_t> remaining(count);
     for (std::size_t i = 0; i < count; ++i) remaining[i] = i;
     std::size_t guard = 0;
     while (remaining.size() > 3 && guard++ < count * count)
     {
          bool clipped = false;
          for (std::size_t i = 0; i < remaining.size(); ++i)
          {
               const std::size_t a = remaining[(i + remaining.size() - 1) % remaining.size()];
               const std::size_t b = remaining[i];
               const std::size_t c = remaining[(i + 1) % remaining.size()];
               if (turn(a, b, c) <= 1e-12) continue; // Reflex or flat corner
               bool contains = false;
               for (std::size_t p : remaining)
               {
                    if (p == a || p == b || p == c) continue;
                    // Strictly inside the ear, or on its new diagonal c-a, blocks it.
                    if (turn(a, b, p) > 1e-9 && turn(b, c, p) > 1e-9 && turn(c, a, p) >= -1e-9)
                    {
                         contains = true;
                         break;
                    }
               }
               if (contains) continue;
               triangles.push_back({a, b, c});
               remaining.erase(remaining.begin() + static_cast<std::ptrdiff_t>(i));
               clipped = true;
               break;
          }
          if (!clipped) return {};
     }
     if (remaining.size() == 3) triangles.push_back({remaining[0], remaining[1], remaining[2]});
     return triangles;
}

City3dImportResult City3dResultImporter::import(
     const fs::path& resultDirectory,
     const std::string& expectedJobId,
     const BuildingInstance& building,
     const City3dCandidate& candidate,
     float renderHeightScale,
     const City3dConfig& config)
{
     City3dImportResult result;
     std::string text;
     if (!readFile(resultDirectory / "result.json", kMaxManifestBytes, text))
          return rejected(result, "missing_manifest");
     Json::Value manifest;
     Json::CharReaderBuilder reader;
     std::istringstream stream(text);
     std::string parseError;
     if (!Json::parseFromStream(reader, stream, &manifest, &parseError) || !manifest.isObject())
          return rejected(result, "malformed_manifest");
     if (manifest["schema"].asString() != "depthwizard.city3d-result.v1")
          return rejected(result, "wrong_schema");
     result.workerStatus = manifest["status"].isString() ? manifest["status"].asString() : "";
     if (manifest["job_id"].asString() != expectedJobId) return rejected(result, "job_id_mismatch");
     if (!manifest["building_id"].isUInt() || manifest["building_id"].asUInt() != building.buildingId)
          return rejected(result, "building_id_mismatch");
     if (result.workerStatus != "success")
          return rejected(result, "worker_" + (result.workerStatus.empty() ? std::string("unknown") : result.workerStatus));
     if (manifest["mesh"].asString() != "building.obj") return rejected(result, "missing_mesh");

     // The origin the worker declares must be the one we sent.
     const Json::Value& frame = manifest["coordinate_frame"];
     if (!frame["origin_easting"].isNumeric() || !frame["origin_northing"].isNumeric() ||
         !frame["origin_elevation"].isNumeric() ||
         std::abs(frame["origin_easting"].asDouble() - candidate.originEasting) > 1e-6 ||
         std::abs(frame["origin_northing"].asDouble() - candidate.originNorthing) > 1e-6 ||
         std::abs(frame["origin_elevation"].asDouble() - candidate.originElevation) > 1e-6 ||
         frame["axis_convention"].asString() != "X_EAST_Y_NORTH_Z_UP")
          return rejected(result, "frame_mismatch");

     if (!readFile(resultDirectory / "building.obj", kMaxObjBytes, text)) return rejected(result, "missing_mesh");

     // Grouped OBJ: only "v x y z", "g roof|wall|ground" and "f i j k ..." (1-based).
     std::vector<Vec3> local;
     enum class Group { None, Roof, Wall, Ground };
     struct Face { Group group; std::vector<std::size_t> indices; };
     std::vector<Face> faces;
     Group group = Group::None;
     std::istringstream lines(text);
     std::string line;
     while (std::getline(lines, line))
     {
          std::istringstream fields(line);
          std::string tag;
          if (!(fields >> tag) || tag[0] == '#') continue;
          if (tag == "v")
          {
               Vec3 p{};
               if (!(fields >> p[0] >> p[1] >> p[2])) return rejected(result, "malformed_vertex");
               if (!std::isfinite(p[0]) || !std::isfinite(p[1]) || !std::isfinite(p[2]))
                    return rejected(result, "non_finite_vertex");
               if (local.size() >= kMaxObjVertices) return rejected(result, "too_many_vertices");
               local.push_back(p);
          }
          else if (tag == "g")
          {
               std::string name;
               fields >> name;
               if (name == "roof") group = Group::Roof;
               else if (name == "wall") group = Group::Wall;
               else if (name == "ground") group = Group::Ground;
               else return rejected(result, "unknown_group");
          }
          else if (tag == "f")
          {
               if (group == Group::None) return rejected(result, "face_without_group");
               Face face{group, {}};
               std::string token;
               while (fields >> token)
               {
                    if (token.find_first_not_of("0123456789") != std::string::npos || token.size() > 9)
                         return rejected(result, "malformed_face");
                    const std::size_t index = std::stoul(token);
                    if (index == 0 || index > local.size()) return rejected(result, "invalid_index");
                    face.indices.push_back(index - 1);
               }
               if (face.indices.size() < 3) return rejected(result, "malformed_face");
               faces.push_back(std::move(face));
          }
          else
               return rejected(result, "unsupported_obj_record");
     }
     if (local.empty() || faces.empty()) return rejected(result, "empty_mesh");

     // Bounds: inside the footprint box plus overflow, within plausible heights.
     double minE = 1e300, maxE = -1e300, minN = 1e300, maxN = -1e300;
     for (const ProjectedPoint& p : building.projectedFootprint.outerRing)
     {
          minE = std::min(minE, p.easting);
          maxE = std::max(maxE, p.easting);
          minN = std::min(minN, p.northing);
          maxN = std::max(maxN, p.northing);
     }
     // Heights: no vertex below the official base (minus tolerance) or above
     // the highest observed pseudo point (plus tolerance). The official height
     // is the 85th percentile of the roof, so the roof top may exceed it but
     // must not fall far below it.
     const double officialMetricHeight = building.heightAboveGround / std::max(renderHeightScale, 1e-6f);
     const double highestAllowed = candidate.maximumLocalHeightMetres + config.heightToleranceMetres;
     const double lowestRoofTop = officialMetricHeight -
         std::max(config.heightToleranceMetres, config.heightToleranceFraction * officialMetricHeight);
     BuildingSurfaceShell& shell = result.shell;
     shell.renderHeightScale = renderHeightScale;
     shell.vertices.reserve(local.size());
     for (const Vec3& p : local)
     {
          ProjectedVertex3D vertex{candidate.originEasting + p[0], candidate.originNorthing + p[1],
                                   candidate.originElevation + p[2]};
          if (vertex.easting < minE - config.footprintOverflowMetres ||
              vertex.easting > maxE + config.footprintOverflowMetres ||
              vertex.northing < minN - config.footprintOverflowMetres ||
              vertex.northing > maxN + config.footprintOverflowMetres)
               return rejected(result, "footprint_overflow");
          if (p[2] < -config.groundToleranceMetres || p[2] > highestAllowed)
               return rejected(result, "height_out_of_bounds");
          shell.vertices.push_back(vertex);
     }

     double roofTop = -1e300;
     for (const Face& face : faces)
     {
          if (face.group == Group::Ground) continue; // Validation only: the terrain closes the bottom
          std::vector<Vec3> polygon;
          for (std::size_t index : face.indices) polygon.push_back(local[index]);
          const auto triangles = triangulatePolygon(polygon);
          if (triangles.empty()) return rejected(result, "untriangulable_face");
          for (const auto& triangle : triangles)
          {
               const std::size_t a = face.indices[triangle[0]];
               const std::size_t b = face.indices[triangle[1]];
               const std::size_t c = face.indices[triangle[2]];
               if (0.5 * norm(cross(subtract(local[b], local[a]), subtract(local[c], local[a]))) < kMinTriangleArea)
               {
                    ++result.degenerateTrianglesDropped;
                    continue;
               }
               auto& target = face.group == Group::Roof ? shell.roofIndices : shell.wallIndices;
               target.insert(target.end(), {static_cast<uint32_t>(a), static_cast<uint32_t>(b),
                                            static_cast<uint32_t>(c)});
               if (face.group == Group::Roof)
                    roofTop = std::max({roofTop, local[a][2], local[b][2], local[c][2]});
          }
     }
     if (shell.roofIndices.empty() || shell.wallIndices.empty()) return rejected(result, "missing_roof_or_wall");
     if ((shell.roofIndices.size() + shell.wallIndices.size()) / 3 > config.maximumShellTriangles)
          return rejected(result, "too_many_triangles");
     result.roofTopMetres = roofTop;
     if (roofTop < lowestRoofTop) return rejected(result, "height_disagreement");

     result.accepted = true;
     return result;
}
