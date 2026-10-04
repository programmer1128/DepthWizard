#pragma once

#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

// Visual variants of the tree visualization proxies. They are chosen from
// measured geometry only and are not species classifications.
enum class TreeVisualVariant : uint8_t
{
     BROADLEAF_ROUND = 0,
     BROADLEAF_IRREGULAR = 1,
     TALL_NARROW = 2,
     DRY_SPARSE = 3,
     SHRUB = 4,
     CANOPY_CROWN = 5   // Crown detail for dense canopy: crown in the upper part, thin hidden trunk
};
const char* toString(TreeVisualVariant variant);
constexpr int kTreeVariantCount = 6;

enum class TreeLod : uint8_t
{
     NEAR = 0,
     MEDIUM = 1,
     FAR = 2
};
const char* toString(TreeLod lod);

// One part of a prototype (trunk or crown), flat-shaded, in prototype space.
struct TreePrototypePart
{
     std::vector<float> positions;   // xyz
     std::vector<float> normals;     // xyz, unit length
     std::vector<uint32_t> indices;
     std::size_t triangles() const { return indices.size() / 3; }
};

// Prototype space: base at Y = 0, top at Y = 1, crown radius 1 (horizontal
// extent of the crown from the Y axis), Y up. An instance scale of
// (crownRadius, displayHeight, crownRadius) therefore puts the base on the
// ground point and the top exactly displayHeight above it.
struct TreePrototype
{
     TreeVisualVariant variant{TreeVisualVariant::BROADLEAF_ROUND};
     TreeLod lod{TreeLod::NEAR};
     TreePrototypePart trunk;   // May be empty (shrub, far level)
     TreePrototypePart crown;
     std::string name() const;
     std::size_t triangles() const { return trunk.triangles() + crown.triangles(); }
};

// Replaceable source of prototypes (procedural now; verified CC0 assets
// could be substituted without touching candidate extraction).
class TreePrototypeProvider
{
public:
     virtual ~TreePrototypeProvider() = default;
     virtual const TreePrototype& prototype(TreeVisualVariant variant, TreeLod lod) const = 0;
     virtual std::string description() const = 0;
};

// Compact procedural prototypes: jittered low-poly ellipsoid crown lobes on a
// tapered trunk. Near 150-320 triangles, medium 30-80, far a 20-triangle
// crown silhouette. No network or external asset dependency.
class ProceduralTreePrototypeProvider final : public TreePrototypeProvider
{
public:
     ProceduralTreePrototypeProvider();
     const TreePrototype& prototype(TreeVisualVariant variant, TreeLod lod) const override;
     std::string description() const override { return "procedural low-poly prototypes (DepthWizard)"; }

     static const ProceduralTreePrototypeProvider& instance();

private:
     std::array<std::array<TreePrototype, 3>, kTreeVariantCount> prototypes_;
};
