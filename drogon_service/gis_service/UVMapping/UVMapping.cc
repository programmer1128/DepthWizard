#include "UVMapping.h"


//new version of uv method with  1.0f - (static_cast<float>(r) * inv_H) removed to check
//for inversion
//pointer optimisation added here
std::vector<float> UVMapping::generateUV(int width, int height)
{
     if(width <= 1 || height <= 1)
     {
         throw std::invalid_argument("UVMapping: width and height must be greater than 1");
     }

     const float inv_W = 1.0f / static_cast<float>(width - 1);
     const float inv_H = 1.0f / static_cast<float>(height - 1);

     const size_t total_floats = static_cast<size_t>(width) * static_cast<size_t>(height) * 2;
     std::vector<float> uv_map;
     uv_map.resize(total_floats);

     //raw pointer extraction for performant access
     float* uv_ptr = uv_map.data();
     size_t index = 0;

     for (int r = 0; r < height; ++r) 
     {
         // glTF format so removing '1.0f -' inversion like commented out method below
         // Row 0 maps to V = 0.0 (Top of the image)
         const float v_coord = static_cast<float>(r) * inv_H;

         for (int c = 0; c < width; ++c) 
         {
             const float u_coord = static_cast<float>(c) * inv_W;
             
             uv_ptr[index++] = u_coord;
             uv_ptr[index++] = v_coord;
         }
     }
     return uv_map;
}


// std::vector<float> UVMapping::generateUV(int width, int height)
// {
//     // grid needs atleast 2 points to have a width or height

//     if(width<=1 || height<=1)
//     {
//         throw std::invalid_argument("UVMapping: width and height must be greater than 1");
//     }

//     // math optimization
//     // we calculate the inverse scales once outside the loop
//     // we subtract 1.0f because a grid of 100 pixels has 99 spaces between them

//     const float inv_W = 1.0f / static_cast<float>(width - 1);
//     const float inv_H = 1.0f / static_cast<float>(height - 1);

//     // we need exactly 2 floats (u and v) for each pixel 
//     // pre-allocate entire continuous RAM block instantly to avoid resizing

//     const size_t total_floats = static_cast<size_t>(width) * static_cast<size_t>(height) * 2;
//     std::vector<float> uv_map(total_floats);

//     // row major order: uv co-ordinates calculation

//     size_t index = 0;

//     for (int r = 0; r < height; ++r) // rows
//     {
//         // pre-calculate the v coordinate for this entire row
//         // invert the v-axis (1.0f - ...)

//         const float v_coord = 1.0f - (static_cast<float>(r) * inv_H);

//         for (int c = 0; c < width; ++c) // columns
//         {
//             // now calculate u coordinate
//             const float u_coord = static_cast<float>(c) * inv_W;

//             // we write u and v directly
//             uv_map[index++] = u_coord;
//             uv_map[index++] = v_coord;
//         }
//     }

//     // return the completed matrix
//     return uv_map;
// }
