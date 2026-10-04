#include "VegetationTreePrototypes.h"

#include <algorithm>
#include <cmath>
#include <limits>
#include <map>
#include <utility>

const char* toString(TreeVisualVariant variant)
{
     switch (variant)
     {
     case TreeVisualVariant::BROADLEAF_ROUND: return "BROADLEAF_ROUND";
     case TreeVisualVariant::BROADLEAF_IRREGULAR: return "BROADLEAF_IRREGULAR";
     case TreeVisualVariant::TALL_NARROW: return "TALL_NARROW";
     case TreeVisualVariant::DRY_SPARSE: return "DRY_SPARSE";
     case TreeVisualVariant::SHRUB: return "SHRUB";
     case TreeVisualVariant::CANOPY_CROWN: return "CANOPY_CROWN";
     }
     return "UNKNOWN";
}

const char* toString(TreeLod lod)
{
     switch (lod)
     {
     case TreeLod::NEAR: return "NEAR";
     case TreeLod::MEDIUM: return "MEDIUM";
     case TreeLod::FAR: return "FAR";
     }
     return "UNKNOWN";
}

std::string TreePrototype::name() const
{
     return std::string(toString(variant)) + "_" + toString(lod);
}

namespace
{
struct Vec3
{
     double x{0}, y{0}, z{0};
};

// Deterministic value in [-1, 1] (splitmix64).
double noise(uint64_t key)
{
     key += 0x9e3779b97f4a7c15ULL;
     key = (key ^ (key >> 30)) * 0xbf58476d1ce4e5b9ULL;
     key = (key ^ (key >> 27)) * 0x94d049bb133111ebULL;
     key ^= key >> 31;
     return static_cast<double>(key >> 11) / static_cast<double>(1ULL << 53) * 2.0 - 1.0;
}

// Unit icosahedron, optionally subdivided once (20 or 80 faces).
void icosphere(int subdivisions, std::vector<Vec3>& vertices, std::vector<std::array<uint32_t, 3>>& faces)
{
     const double t = (1.0 + std::sqrt(5.0)) / 2.0;
     vertices = {{-1, t, 0}, {1, t, 0}, {-1, -t, 0}, {1, -t, 0}, {0, -1, t}, {0, 1, t},
                 {0, -1, -t}, {0, 1, -t}, {t, 0, -1}, {t, 0, 1}, {-t, 0, -1}, {-t, 0, 1}};
     faces = {{0, 11, 5}, {0, 5, 1}, {0, 1, 7}, {0, 7, 10}, {0, 10, 11}, {1, 5, 9}, {5, 11, 4},
              {11, 10, 2}, {10, 7, 6}, {7, 1, 8}, {3, 9, 4}, {3, 4, 2}, {3, 2, 6}, {3, 6, 8},
              {3, 8, 9}, {4, 9, 5}, {2, 4, 11}, {6, 2, 10}, {8, 6, 7}, {9, 8, 1}};
     for (Vec3& v : vertices)
     {
          const double l = std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
          v = {v.x / l, v.y / l, v.z / l};
     }
     for (int s = 0; s < subdivisions; ++s)
     {
          std::map<std::pair<uint32_t, uint32_t>, uint32_t> midpoints;
          const auto midpoint = [&](uint32_t a, uint32_t b)
          {
               const auto key = std::minmax(a, b);
               const auto found = midpoints.find(key);
               if (found != midpoints.end()) return found->second;
               Vec3 m{(vertices[a].x + vertices[b].x) / 2, (vertices[a].y + vertices[b].y) / 2,
                      (vertices[a].z + vertices[b].z) / 2};
               const double l = std::sqrt(m.x * m.x + m.y * m.y + m.z * m.z);
               vertices.push_back({m.x / l, m.y / l, m.z / l});
               const auto index = static_cast<uint32_t>(vertices.size() - 1);
               midpoints.emplace(key, index);
               return index;
          };
          std::vector<std::array<uint32_t, 3>> refined;
          for (const auto& f : faces)
          {
               const uint32_t a = midpoint(f[0], f[1]), b = midpoint(f[1], f[2]), c = midpoint(f[2], f[0]);
               refined.push_back({f[0], a, c});
               refined.push_back({f[1], b, a});
               refined.push_back({f[2], c, b});
               refined.push_back({a, b, c});
          }
          faces = std::move(refined);
     }
}

// Flat-shaded triangle with an outward normal (counter-clockwise seen from outside).
void addTriangle(TreePrototypePart& part, const Vec3& a, const Vec3& b, const Vec3& c)
{
     const Vec3 u{b.x - a.x, b.y - a.y, b.z - a.z}, v{c.x - a.x, c.y - a.y, c.z - a.z};
     Vec3 n{u.y * v.z - u.z * v.y, u.z * v.x - u.x * v.z, u.x * v.y - u.y * v.x};
     const double l = std::sqrt(n.x * n.x + n.y * n.y + n.z * n.z);
     if (l < 1e-12) return; // Never emit a degenerate triangle
     n = {n.x / l, n.y / l, n.z / l};
     for (const Vec3* p : {&a, &b, &c})
     {
          part.indices.push_back(static_cast<uint32_t>(part.positions.size() / 3));
          part.positions.insert(part.positions.end(), {static_cast<float>(p->x), static_cast<float>(p->y),
                                                       static_cast<float>(p->z)});
          part.normals.insert(part.normals.end(), {static_cast<float>(n.x), static_cast<float>(n.y),
                                                   static_cast<float>(n.z)});
     }
}

// A jittered ellipsoid lobe. Jitter is per unique vertex, so the lobe stays closed.
void addLobe(TreePrototypePart& part, Vec3 centre, Vec3 radii, int subdivisions, uint64_t seed, double jitter)
{
     std::vector<Vec3> unit;
     std::vector<std::array<uint32_t, 3>> faces;
     icosphere(subdivisions, unit, faces);
     std::vector<Vec3> points(unit.size());
     for (std::size_t i = 0; i < unit.size(); ++i)
     {
          const double k = 1.0 + jitter * noise(seed * 1000003ULL + i);
          points[i] = {centre.x + unit[i].x * radii.x * k, centre.y + unit[i].y * radii.y * k,
                       centre.z + unit[i].z * radii.z * k};
     }
     for (const auto& f : faces)
     {
          // Keep outward orientation after jitter: compare with the unit normal.
          const Vec3& a = points[f[0]];
          const Vec3& b = points[f[1]];
          const Vec3& c = points[f[2]];
          const Vec3 u{b.x - a.x, b.y - a.y, b.z - a.z}, v{c.x - a.x, c.y - a.y, c.z - a.z};
          const Vec3 n{u.y * v.z - u.z * v.y, u.z * v.x - u.x * v.z, u.x * v.y - u.y * v.x};
          const Vec3 outward{unit[f[0]].x + unit[f[1]].x + unit[f[2]].x, unit[f[0]].y + unit[f[1]].y + unit[f[2]].y,
                             unit[f[0]].z + unit[f[1]].z + unit[f[2]].z};
          if (n.x * outward.x + n.y * outward.y + n.z * outward.z >= 0) addTriangle(part, a, b, c);
          else addTriangle(part, a, c, b);
     }
}

// Tapered trunk side walls (no caps: the base sits on the ground and the top
// is inside the crown).
void addTrunk(TreePrototypePart& part, double baseRadius, double topRadius, double top, int segments)
{
     for (int s = 0; s < segments; ++s)
     {
          const double a0 = 2 * M_PI * s / segments, a1 = 2 * M_PI * (s + 1) / segments;
          const Vec3 b0{baseRadius * std::cos(a0), 0, baseRadius * std::sin(a0)};
          const Vec3 b1{baseRadius * std::cos(a1), 0, baseRadius * std::sin(a1)};
          const Vec3 t0{topRadius * std::cos(a0), top, topRadius * std::sin(a0)};
          const Vec3 t1{topRadius * std::cos(a1), top, topRadius * std::sin(a1)};
          addTriangle(part, b0, t0, b1);
          addTriangle(part, b1, t0, t1);
     }
}

struct Lobe
{
     Vec3 centre;
     Vec3 radii;
};

struct Design
{
     double trunkBase, trunkTop, trunkHeight; // Radii and height before normalization
     std::vector<Lobe> lobes;
     double jitter;
};

Design design(TreeVisualVariant variant)
{
     switch (variant)
     {
     case TreeVisualVariant::BROADLEAF_ROUND:
          return {0.07, 0.045, 0.50,
                  {{{0.00, 0.66, 0.00}, {0.86, 0.34, 0.86}},
                   {{0.30, 0.76, 0.14}, {0.55, 0.26, 0.55}},
                   {{-0.26, 0.73, -0.20}, {0.50, 0.25, 0.50}}},
                  0.10};
     case TreeVisualVariant::BROADLEAF_IRREGULAR:
          return {0.07, 0.04, 0.48,
                  {{{0.12, 0.62, 0.05}, {0.70, 0.30, 0.62}},
                   {{-0.38, 0.70, 0.22}, {0.48, 0.28, 0.46}},
                   {{0.22, 0.80, -0.32}, {0.45, 0.22, 0.42}}},
                  0.18};
     case TreeVisualVariant::TALL_NARROW:
          return {0.06, 0.035, 0.32,
                  {{{0.00, 0.56, 0.00}, {0.55, 0.36, 0.55}},
                   {{0.05, 0.84, -0.03}, {0.36, 0.20, 0.36}}},
                  0.10};
     case TreeVisualVariant::DRY_SPARSE:
          return {0.06, 0.03, 0.62,
                  {{{0.24, 0.74, 0.04}, {0.46, 0.17, 0.44}},
                   {{-0.28, 0.68, 0.12}, {0.38, 0.15, 0.36}},
                   {{0.02, 0.88, -0.22}, {0.30, 0.12, 0.30}}},
                  0.22};
     case TreeVisualVariant::SHRUB:
          return {0.0, 0.0, 0.0,
                  {{{0.00, 0.45, 0.00}, {0.90, 0.45, 0.85}},
                   {{0.32, 0.50, -0.22}, {0.55, 0.38, 0.55}}},
                  0.16};
     case TreeVisualVariant::CANOPY_CROWN:
          // Grounded like every instance, but the crown fills only the upper
          // part; the thin trunk stays inside the canopy envelope.
          return {0.04, 0.03, 0.62,
                  {{{0.00, 0.78, 0.00}, {0.88, 0.22, 0.88}},
                   {{0.24, 0.84, -0.16}, {0.52, 0.17, 0.50}},
                   {{-0.28, 0.80, 0.20}, {0.46, 0.16, 0.44}}},
                  0.12};
     }
     return {};
}

TreePrototype build(TreeVisualVariant variant, TreeLod lod)
{
     const Design d = design(variant);
     TreePrototype prototype;
     prototype.variant = variant;
     prototype.lod = lod;
     const uint64_t seed = static_cast<uint64_t>(variant) * 7919ULL + 17ULL;
     if (lod == TreeLod::FAR)
     {
          // Silhouette: one 20-triangle lobe spanning the crown envelope.
          double top = 0.0, bottom = std::numeric_limits<double>::max(), reach = 0.0;
          for (const Lobe& l : d.lobes)
          {
               top = std::max(top, l.centre.y + l.radii.y);
               bottom = std::min(bottom, l.centre.y - l.radii.y);
               reach = std::max(reach, std::hypot(l.centre.x, l.centre.z) + std::max(l.radii.x, l.radii.z));
          }
          addLobe(prototype.crown, {0.0, (top + bottom) / 2, 0.0}, {reach, (top - bottom) / 2, reach}, 0, seed, 0.0);
          if (d.trunkHeight > 0.0) addTrunk(prototype.trunk, d.trunkBase, d.trunkTop, std::max(bottom, 0.05), 3);
     }
     else
     {
          const int subdivisions = lod == TreeLod::NEAR ? 1 : 0;
          for (std::size_t i = 0; i < d.lobes.size(); ++i)
               addLobe(prototype.crown, d.lobes[i].centre, d.lobes[i].radii, subdivisions, seed + i, d.jitter);
          if (d.trunkHeight > 0.0)
               addTrunk(prototype.trunk, d.trunkBase, d.trunkTop, d.trunkHeight, lod == TreeLod::NEAR ? 6 : 4);
     }

     // Normalize: base at Y = 0, top at Y = 1, crown radius 1.
     double minY = std::numeric_limits<double>::max(), maxY = std::numeric_limits<double>::lowest(), radius = 0.0;
     for (const TreePrototypePart* part : {&prototype.trunk, &prototype.crown})
          for (std::size_t i = 0; i < part->positions.size(); i += 3)
          {
               minY = std::min(minY, static_cast<double>(part->positions[i + 1]));
               maxY = std::max(maxY, static_cast<double>(part->positions[i + 1]));
          }
     for (std::size_t i = 0; i < prototype.crown.positions.size(); i += 3)
          radius = std::max(radius, std::hypot(static_cast<double>(prototype.crown.positions[i]),
                                               static_cast<double>(prototype.crown.positions[i + 2])));
     const double base = minY; // The trunk foot, or the shrub crown's lowest point
     for (TreePrototypePart* part : {&prototype.trunk, &prototype.crown})
     {
          for (std::size_t i = 0; i < part->positions.size(); i += 3)
          {
               part->positions[i] = static_cast<float>(part->positions[i] / radius);
               part->positions[i + 1] = static_cast<float>((part->positions[i + 1] - base) / (maxY - base));
               part->positions[i + 2] = static_cast<float>(part->positions[i + 2] / radius);
          }
          // Re-derive flat normals after the anisotropic scale.
          for (std::size_t t = 0; t + 2 < part->indices.size(); t += 3)
          {
               const float* a = &part->positions[part->indices[t] * 3];
               const float* b = &part->positions[part->indices[t + 1] * 3];
               const float* c = &part->positions[part->indices[t + 2] * 3];
               const double ux = b[0] - a[0], uy = b[1] - a[1], uz = b[2] - a[2];
               const double vx = c[0] - a[0], vy = c[1] - a[1], vz = c[2] - a[2];
               double nx = uy * vz - uz * vy, ny = uz * vx - ux * vz, nz = ux * vy - uy * vx;
               const double l = std::sqrt(nx * nx + ny * ny + nz * nz);
               nx /= l; ny /= l; nz /= l;
               for (int k = 0; k < 3; ++k)
               {
                    float* n = &part->normals[part->indices[t + k] * 3];
                    n[0] = static_cast<float>(nx); n[1] = static_cast<float>(ny); n[2] = static_cast<float>(nz);
               }
          }
     }
     // Exact extremes after float rounding.
     for (TreePrototypePart* part : {&prototype.trunk, &prototype.crown})
          for (std::size_t i = 1; i < part->positions.size(); i += 3)
               part->positions[i] = std::clamp(part->positions[i], 0.0f, 1.0f);
     return prototype;
}
} // namespace

ProceduralTreePrototypeProvider::ProceduralTreePrototypeProvider()
{
     for (int v = 0; v < kTreeVariantCount; ++v)
          for (int l = 0; l < 3; ++l)
               prototypes_[static_cast<std::size_t>(v)][static_cast<std::size_t>(l)] =
                   build(static_cast<TreeVisualVariant>(v), static_cast<TreeLod>(l));
}

const TreePrototype& ProceduralTreePrototypeProvider::prototype(TreeVisualVariant variant, TreeLod lod) const
{
     return prototypes_[static_cast<std::size_t>(variant)][static_cast<std::size_t>(lod)];
}

const ProceduralTreePrototypeProvider& ProceduralTreePrototypeProvider::instance()
{
     static const ProceduralTreePrototypeProvider provider;
     return provider;
}
