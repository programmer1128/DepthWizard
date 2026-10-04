# Vegetation asset attribution

DepthWizard's optional external vegetation prototypes
(`DEPTHWIZARD_VEGETATION_ASSET_MODE=external`) use two third-party models,
both licensed under Creative Commons Attribution 4.0 International
(CC BY 4.0, <https://creativecommons.org/licenses/by/4.0/>). They are
visualization proxies only: no species is inferred from them.

| Asset | Title | Author | Source |
|---|---|---|---|
| `optimized/small_bush.glb` | "Small bush" | yanix (<https://sketchfab.com/yanix>) | <https://sketchfab.com/3d-models/small-bush-f6ed4c70fc024ac88e8e6a19991695af> |
| `optimized/forest_patch.glb` | "Forest" | rhfqcntrkf (<https://sketchfab.com/rhfqcntrkf>) | <https://sketchfab.com/3d-models/forest-9153c2b370934758bf14c395abe36b27> |
| `optimized/forest_trees.glb` | "a forest (3) with a road at night for game" | dasy444 (<https://sketchfab.com/dasy444>) | <https://sketchfab.com/3d-models/a-forest-3-with-a-road-at-night-for-game-61f8c7817fe6457fb26e4814cfc48a3f> |

Credits, as requested by the licences:

- This work is based on "Small bush" (https://sketchfab.com/3d-models/small-bush-f6ed4c70fc024ac88e8e6a19991695af) by yanix (https://sketchfab.com/yanix) licensed under CC-BY-4.0 (http://creativecommons.org/licenses/by/4.0/).
- This work is based on "Forest" (https://sketchfab.com/3d-models/forest-9153c2b370934758bf14c395abe36b27) by rhfqcntrkf (https://sketchfab.com/rhfqcntrkf) licensed under CC-BY-4.0 (http://creativecommons.org/licenses/by/4.0/).

- This work is based on "a forest (3) with a road at night for game" (https://sketchfab.com/3d-models/a-forest-3-with-a-road-at-night-for-game-61f8c7817fe6457fb26e4814cfc48a3f) by dasy444 (https://sketchfab.com/dasy444) licensed under CC-BY-4.0 (http://creativecommons.org/licenses/by/4.0/).

## Modifications

Both optimized files are produced deterministically, offline, by
`tools/vegetation_assets/preprocess_vegetation_assets.py` from the
unmodified sources in `source/`.

**Small bush:** Sketchfab wrapper nodes flattened into one node; geometry
normalised per axis to base Y = 0, top Y = 1 and horizontal crown radius 1
(the source radius-to-height ratio, 0.611, is recorded in the node extras);
base-colour texture resized from 1024 to 512 px; alpha mode changed from
BLEND to MASK (cutoff 0.45); metallic 0, roughness 0.9;
`KHR_materials_specular` removed. Mesh, UVs and texture content are otherwise
unchanged (320 triangles).

**Forest:** the Floor ground plane and the Kust and Paporotnik undergrowth
removed; the remaining spruce (Green_Elka) and pine (Green_sosna) foliage and
the trunks (Wood_tree) kept with their relative placement; Z-up source
converted to Y-up; primitives merged per material; uniformly scaled so the
tallest tree top is Y = 1, with the base at Y = 0 and the horizontal centre at
the origin; foliage alpha changed from BLEND to MASK (cutoff 0.45); metallic
0, roughness 0.9; the two identical trunk textures stored once
(32,826 triangles).

**Forest trees (dasy444):** the ground tile (with its painted trail), the
grass and shrub sprites and the normal maps removed; five representative pine
trees kept, one per distinct atlas image (crossed-card sprite plus its bark
trunk where present), each normalised to base Y = 0, top Y = 1, centred;
foliage alpha changed from BLEND to MASK (cutoff 0.45); metallic 0, roughness
0.9. Used for dense forest at individual-tree resolution: every tree is
instanced separately and grounded on the terrain.

## Runtime

Only `optimized/` is needed at runtime; the build copies it next to the
`gis_service` executable (`assets/vegetation/optimized/`). `source/` and
`LICENSES/` are kept for provenance and licence compliance; ship
`ATTRIBUTION.md` and `LICENSES/` with any distribution that includes the
optimized assets.
