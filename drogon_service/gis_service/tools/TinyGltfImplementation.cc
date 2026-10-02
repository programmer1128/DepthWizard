// tinygltf's implementation for the standalone tools; the backend defines it
// in FileGenerators/GltfPackager.cc, which the tools do not link.
#define TINYGLTF_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <tiny_gltf.h>
