#pragma once
#include "VegetationTreeInstancer.h"
#include "VegetationTreePrototypes.h"
#include "../FileGenerators/GltfPackager.h"

#include <array>

// Turns tree instances into the packager's instanced vegetation: one shared
// trunk and crown geometry per (variant, level of detail), one trunk material
// and one crown material per variant, one mesh per (variant, level) and one
// EXT_mesh_gpu_instancing node per batch with a per-instance colour tint
// (_COLOR_0), tagged as a visualization proxy. Colours are visual only and
// never encode a vegetation class.
class VegetationTreePackaging
{
public:
     static InstancedPackage package(const VegetationTreeInstances& trees, const TreePrototypeProvider& provider,
                                     uint32_t seed);

     // Crown albedo (linear RGB) of a variant in a palette family.
     static std::array<double, 3> crownColour(const std::string& family, TreeVisualVariant variant);
};
