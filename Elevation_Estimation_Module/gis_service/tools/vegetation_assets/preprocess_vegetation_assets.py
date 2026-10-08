#!/usr/bin/env python3
# Deterministic offline preprocessing of the bundled CC-BY vegetation assets
# (stage 5A). Reads only local files and never downloads anything.
#
#   small_bush.glb -> optimized/small_bush.glb
#     Sketchfab wrapper nodes flattened, base Y = 0, top Y = 1, horizontal
#     crown radius = 1 (per-axis unit normalisation, so an instance scale of
#     (crownRadius, displayHeight, crownRadius) reproduces the measured crown),
#     texture 1024 -> 512 px, alpha BLEND -> MASK, metallic 0, roughness 0.9.
#
#   forest/scene.gltf -> optimized/forest_patch.glb
#     Floor, undergrowth (Kust, Paporotnik), cameras and lights dropped; tree
#     foliage (Green_Elka, Green_sosna) and trunks (Wood_tree) kept with their
#     relative alignment; source Z-up converted to Y-up through the node
#     transforms; one primitive per material; uniform scale so the tallest
#     tree top is Y = 1 (aspect preserved), base Y = 0, horizontal centre at
#     the origin; foliage BLEND -> MASK.
#
# Usage: preprocess_vegetation_assets.py --bush <small_bush.glb> --forest <forest dir> --out <assets/vegetation>
import argparse, hashlib, io, json, shutil, struct, sys
from pathlib import Path
import numpy as np
from PIL import Image, ImageDraw

ALPHA_CUTOFF = 0.45
BUSH_TEXTURE_SIZE = 512
FOREST_KEEP = ["Green_Elka", "Green_sosna.001", "Wood_tree.001", "Wood_tree.002"]
FOLIAGE = {"bush_leaf", "Green_Elka", "Green_sosna.001"}


# --- glTF reading -----------------------------------------------------------

def load(path):
    path = Path(path)
    if path.suffix == ".glb":
        data = path.read_bytes()
        n = struct.unpack_from("<I", data, 12)[0]
        g = json.loads(data[20:20 + n])
        m = struct.unpack_from("<I", data, 20 + n)[0]
        buffers = [data[28 + n:28 + n + m]]
    else:
        g = json.loads(path.read_text())
        buffers = [(path.parent / b["uri"]).read_bytes() for b in g["buffers"]]

    def view(i):
        v = g["bufferViews"][i]
        start = v.get("byteOffset", 0)
        return buffers[v["buffer"]][start:start + v["byteLength"]], v.get("byteStride")

    def accessor(i):
        a = g["accessors"][i]
        comps = {"SCALAR": 1, "VEC2": 2, "VEC3": 3, "VEC4": 4}[a["type"]]
        dtype = np.dtype({5126: np.float32, 5125: np.uint32, 5123: np.uint16, 5121: np.uint8}[a["componentType"]])
        raw, stride = view(a["bufferView"])
        item = comps * dtype.itemsize
        stride = stride or item
        start = a.get("byteOffset", 0)
        rows = np.frombuffer(raw, np.uint8, stride * (a["count"] - 1) + item, start)
        rows = np.lib.stride_tricks.as_strided(rows, (a["count"], item), (stride, 1))
        return rows.copy().view(dtype).reshape(a["count"], comps)

    def image(i):
        im = g["images"][i]
        if "bufferView" in im:
            return view(im["bufferView"])[0], im["mimeType"]
        return (path.parent / im["uri"]).read_bytes(), "image/png" if im["uri"].endswith(".png") else "image/jpeg"

    return g, accessor, image


def node_matrix(node):
    if "matrix" in node:
        m = np.array(node["matrix"], np.float64).reshape(4, 4).T
    else:
        t = np.array(node.get("translation", [0, 0, 0]), np.float64)
        x, y, z, w = node.get("rotation", [0, 0, 0, 1])
        r = np.array([[1 - 2 * (y * y + z * z), 2 * (x * y - z * w), 2 * (x * z + y * w)],
                      [2 * (x * y + z * w), 1 - 2 * (x * x + z * z), 2 * (y * z - x * w)],
                      [2 * (x * z - y * w), 2 * (y * z + x * w), 1 - 2 * (x * x + y * y)]])
        s = np.array(node.get("scale", [1, 1, 1]), np.float64)
        m = np.eye(4); m[:3, :3] = r * s; m[:3, 3] = t
    m[np.abs(m) < 1e-12] = 0.0   # Sketchfab's 2.2e-16 axis-swap residue
    return m


def world_primitives(g, accessor):
    """(material index, positions, normals, uvs, indices) in world space."""
    out = []

    def visit(i, parent):
        node = g["nodes"][i]
        m = parent @ node_matrix(node)
        if "mesh" in node:
            normal_m = np.linalg.inv(m[:3, :3]).T
            for p in g["meshes"][node["mesh"]]["primitives"]:
                if p.get("mode", 4) != 4:
                    continue
                P = accessor(p["attributes"]["POSITION"]).astype(np.float64)
                N = accessor(p["attributes"]["NORMAL"]).astype(np.float64)
                UV = accessor(p["attributes"]["TEXCOORD_0"]).astype(np.float64)
                I = accessor(p["indices"]).astype(np.int64).reshape(-1)
                P = P @ m[:3, :3].T + m[:3, 3]
                N = N @ normal_m.T
                N /= np.maximum(np.linalg.norm(N, axis=1, keepdims=True), 1e-12)
                out.append((p["material"], P, N, UV, I))
        for c in node.get("children", []):
            visit(c, m)

    for root in g["scenes"][g.get("scene", 0)]["nodes"]:
        visit(root, np.eye(4))
    return out


def merge_by_material(prims, keep_names, g):
    merged = {}
    for mat, P, N, UV, I in prims:
        name = g["materials"][mat]["name"]
        if name not in keep_names:
            continue
        entry = merged.setdefault(name, {"mat": mat, "P": [], "N": [], "UV": [], "I": [], "n": 0})
        entry["P"].append(P); entry["N"].append(N); entry["UV"].append(UV); entry["I"].append(I + entry["n"])
        entry["n"] += len(P)
    return [(name, merged[name]["mat"], np.vstack(merged[name]["P"]), np.vstack(merged[name]["N"]),
             np.vstack(merged[name]["UV"]), np.concatenate(merged[name]["I"])) for name in keep_names if name in merged]


# --- Alpha-mask check -------------------------------------------------------

def mask_coverage(rgba, uvs, indices, cutoff):
    """Share of the UV-covered texels that survive the alpha cutoff (1.0 = solid cards)."""
    h, w = rgba.shape[:2]
    covered = Image.new("L", (w, h), 0)
    draw = ImageDraw.Draw(covered)
    for tri in indices.reshape(-1, 3):
        t = uvs[tri]
        t = np.clip(t - np.floor(t.min(axis=0)), 0.0, 1.0)   # Repeat-wrapped islands back into [0, 1]
        draw.polygon([(u * w, v * h) for u, v in t], fill=255)
    area = np.array(covered) > 0
    alpha = rgba[..., 3].astype(np.float64) / 255.0
    return float((alpha[area] >= cutoff).mean()) if area.any() else 0.0


# --- GLB writing ------------------------------------------------------------

class Writer:
    def __init__(self):
        self.bin = bytearray(); self.views = []; self.accessors = []

    def view(self, data, target=None):
        while len(self.bin) % 4:
            self.bin.append(0)
        v = {"buffer": 0, "byteOffset": len(self.bin), "byteLength": len(data)}
        if target:
            v["target"] = target
        self.bin += data; self.views.append(v)
        return len(self.views) - 1

    def accessor(self, array, kind, target, with_bounds=False):
        if kind == "indices":
            big = array.max() >= 65535
            data = array.astype(np.uint32 if big else np.uint16)
            acc = {"componentType": 5125 if big else 5123, "type": "SCALAR"}
        else:
            data = array.astype(np.float32)
            acc = {"componentType": 5126, "type": {2: "VEC2", 3: "VEC3"}[array.shape[1]]}
        acc.update({"bufferView": self.view(data.tobytes(), target), "count": int(len(data))})
        if with_bounds:
            acc["min"] = [float(x) for x in data.min(axis=0)]
            acc["max"] = [float(x) for x in data.max(axis=0)]
        self.accessors.append(acc)
        return len(self.accessors) - 1


def write_glb(path, parts, images, asset_extras, root_extras):
    """parts: (name, P, N, UV, I, material dict with 'image' index); images: (bytes, mime, wrap)."""
    w = Writer()
    image_entries, textures, samplers, materials, primitives = [], [], [], [], []
    for data, mime, wrap in images:
        image_entries.append({"bufferView": w.view(data), "mimeType": mime})
        samplers.append({"magFilter": 9729, "minFilter": 9987, "wrapS": wrap, "wrapT": wrap})
        textures.append({"sampler": len(samplers) - 1, "source": len(image_entries) - 1})
    for name, P, N, UV, I, material in parts:
        primitives.append({"attributes": {"POSITION": w.accessor(P, "positions", 34962, True),
                                          "NORMAL": w.accessor(N, "normals", 34962),
                                          "TEXCOORD_0": w.accessor(UV, "uvs", 34962)},
                           "indices": w.accessor(I, "indices", 34963), "material": len(materials), "mode": 4})
        materials.append(material)
    while len(w.bin) % 4:
        w.bin.append(0)
    g = {"asset": {"version": "2.0", "generator": "DepthWizard preprocess_vegetation_assets.py", "extras": asset_extras},
         "scene": 0, "scenes": [{"nodes": [0]}],
         "nodes": [{"name": root_extras["assetSource"], "mesh": 0, "extras": root_extras}],
         "meshes": [{"name": root_extras["assetSource"], "primitives": primitives}],
         "materials": materials, "textures": textures, "images": image_entries, "samplers": samplers,
         "accessors": w.accessors, "bufferViews": w.views, "buffers": [{"byteLength": len(w.bin)}]}
    js = json.dumps(g, sort_keys=True, separators=(",", ":")).encode()
    js += b" " * ((4 - len(js) % 4) % 4)
    total = 12 + 8 + len(js) + 8 + len(w.bin)
    out = struct.pack("<III", 0x46546C67, 2, total) + struct.pack("<II", len(js), 0x4E4F534A) + js + \
          struct.pack("<II", len(w.bin), 0x004E4942) + bytes(w.bin)
    Path(path).write_bytes(out)
    return out


def png_bytes(image):
    buffer = io.BytesIO()
    image.save(buffer, format="PNG", optimize=True)
    return buffer.getvalue()


def material(source, name, image_index, foliage):
    pbr = source.get("pbrMetallicRoughness", {})
    m = {"name": name, "doubleSided": True,
         "pbrMetallicRoughness": {"baseColorTexture": {"index": image_index}, "metallicFactor": 0.0, "roughnessFactor": 0.9}}
    if "baseColorFactor" in pbr:
        m["pbrMetallicRoughness"]["baseColorFactor"] = pbr["baseColorFactor"]
    if foliage:
        m["alphaMode"] = "MASK"; m["alphaCutoff"] = ALPHA_CUTOFF
    return m


# --- Assets -----------------------------------------------------------------

def bush(src, out_dir, report):
    g, accessor, image = load(src)
    (name, mat, P, N, UV, I), = merge_by_material(world_primitives(g, accessor), ["bush_leaf"], g)
    report["small_bush"] = {"source_triangles": int(len(I) // 3), "source_vertices": int(len(P)),
                            "source_bounds": [P.min(0).round(4).tolist(), P.max(0).round(4).tolist()]}
    lo, hi = P.min(0), P.max(0)
    centre = (lo + hi) / 2
    radius = float(np.hypot(P[:, 0] - centre[0], P[:, 2] - centre[2]).max())
    height = float(hi[1] - lo[1])
    scale = np.array([1 / radius, 1 / height, 1 / radius])
    Q = (P - [centre[0], lo[1], centre[2]]) * scale
    M = N / scale
    M /= np.linalg.norm(M, axis=1, keepdims=True)
    tex_bytes, mime = image(g["textures"][g["materials"][mat]["pbrMetallicRoughness"]["baseColorTexture"]["index"]]["source"])
    rgba = Image.open(io.BytesIO(tex_bytes)).convert("RGBA").resize((BUSH_TEXTURE_SIZE,) * 2, Image.LANCZOS)
    rgba_np = np.array(rgba)
    coverage = {str(c): round(mask_coverage(rgba_np, UV, I, c), 4) for c in (0.3, ALPHA_CUTOFF, 0.6)}
    data = write_glb(out_dir / "small_bush.glb",
                     [(name, Q, M, UV, I, material(g["materials"][mat], "Vegetation_SmallBush", 0, True))],
                     [(png_bytes(rgba), "image/png", 33071)],
                     dict(g["asset"].get("extras", {}), modifications="Sketchfab wrapper nodes flattened; normalised to base Y=0, top Y=1, horizontal crown radius 1; texture resized 1024->512 px; alpha BLEND->MASK (cutoff 0.45); metallic 0, roughness 0.9; KHR_materials_specular dropped"),
                     {"assetSource": "SMALL_BUSH", "sourceRadiusOverHeight": round(radius / height, 6),
                      "normalisedRadius": 1.0, "normalisedTop": 1.0})
    report["small_bush"].update({"optimized_triangles": int(len(I) // 3), "optimized_bytes": len(data),
                                 "normalised_bounds": [Q.min(0).round(6).tolist(), Q.max(0).round(6).tolist()],
                                 "source_radius_over_height": round(radius / height, 4),
                                 "texture": f"{BUSH_TEXTURE_SIZE}x{BUSH_TEXTURE_SIZE} RGBA PNG",
                                 "alpha_mask_coverage_by_cutoff": coverage,
                                 "sha256": hashlib.sha256(data).hexdigest()})


def forest(src_dir, out_dir, report):
    g, accessor, image = load(src_dir / "scene.gltf")
    prims = world_primitives(g, accessor)
    names = [g["materials"][m]["name"] for m, *_ in prims]
    parts = merge_by_material(prims, FOREST_KEEP, g)
    allP = np.vstack([p[2] for p in parts])
    lo, hi = allP.min(0), allP.max(0)
    centre = (lo + hi) / 2
    scale = 1.0 / float(hi[1] - lo[1])
    images, image_index, out_parts, coverage = [], {}, [], {}
    for name, mat, P, N, UV, I in parts:
        src_mat = g["materials"][mat]
        tex = g["textures"][src_mat["pbrMetallicRoughness"]["baseColorTexture"]["index"]]
        data, mime = image(tex["source"])
        key = hashlib.sha256(data).hexdigest()   # Identical trunk textures are stored once
        if key not in image_index:
            image_index[key] = len(images)
            images.append((data, mime, g["samplers"][tex["sampler"]].get("wrapS", 10497)))
        Q = (P - [centre[0], lo[1], centre[2]]) * scale
        if name in FOLIAGE:
            rgba = np.array(Image.open(io.BytesIO(data)).convert("RGBA"))
            coverage[name] = {str(c): round(mask_coverage(rgba, UV, I, c), 4) for c in (0.3, ALPHA_CUTOFF, 0.6)}
        out_parts.append((name, Q, N, UV, I, material(src_mat, "Vegetation_Forest_" + name.replace(".", "_"),
                                                         image_index[key], name in FOLIAGE)))
    allQ = np.vstack([p[1] for p in out_parts])
    half = (allQ.max(0) - allQ.min(0)) / 2
    radius = float(np.hypot(allQ[:, 0], allQ[:, 2]).max())
    data = write_glb(out_dir / "forest_patch.glb", out_parts, images,
                     dict(g["asset"].get("extras", {}), modifications="Floor, Kust and Paporotnik undergrowth removed; Z-up converted to Y-up; primitives merged per material; uniformly scaled to base Y=0, tallest tree top Y=1, horizontal centre at the origin; foliage alpha BLEND->MASK (cutoff 0.45); metallic 0, roughness 0.9; identical trunk textures deduplicated"),
                     {"assetSource": "FOREST_PATCH", "normalisedTop": 1.0, "normalisedHalfExtentX": round(float(half[0]), 6),
                      "normalisedHalfExtentZ": round(float(half[2]), 6), "normalisedRadius": round(radius, 6)})
    report["forest_patch"] = {
        "source_materials": sorted(set(names)), "kept_materials": [p[0] for p in out_parts],
        "dropped_materials": sorted(set(names) - set(FOREST_KEEP)),
        "source_triangles_all": int(sum(len(p[4]) // 3 for p in prims)),
        "optimized_triangles": int(sum(len(p[4]) // 3 for p in out_parts)),
        "triangles_per_material": {p[0]: int(len(p[4]) // 3) for p in out_parts},
        "source_up_axis": "Z (mesh data); Y after the Sketchfab root transform",
        "normalised_bounds": [allQ.min(0).round(6).tolist(), allQ.max(0).round(6).tolist()],
        "normalised_radius": round(radius, 4), "images": len(images), "optimized_bytes": len(data),
        "alpha_mask_coverage_by_cutoff": coverage, "sha256": hashlib.sha256(data).hexdigest()}


FOREST_TREES_SOURCE = "a_forest_3_with_a_road_at_night_for_game.glb"
FOREST_TREE_COUNT = 6


def write_library_glb(path, prototypes, images, asset_extras):
    """prototypes: (name, parts, extras) with parts (name, P, N, UV, I, material); images shared."""
    w = Writer()
    image_entries, textures, samplers = [], [], []
    for data, mime, wrap in images:
        image_entries.append({"bufferView": w.view(data), "mimeType": mime})
        samplers.append({"magFilter": 9729, "minFilter": 9987, "wrapS": wrap, "wrapT": wrap})
        textures.append({"sampler": len(samplers) - 1, "source": len(image_entries) - 1})
    materials, material_index, meshes, nodes = [], {}, [], []
    for name, parts, extras in prototypes:
        primitives = []
        for pname, P, N, UV, I, material in parts:
            key = json.dumps(material, sort_keys=True)
            if key not in material_index:
                material_index[key] = len(materials)
                materials.append(material)
            primitives.append({"attributes": {"POSITION": w.accessor(P, "positions", 34962, True),
                                              "NORMAL": w.accessor(N, "normals", 34962),
                                              "TEXCOORD_0": w.accessor(UV, "uvs", 34962)},
                               "indices": w.accessor(I, "indices", 34963), "material": material_index[key], "mode": 4})
        meshes.append({"name": name, "primitives": primitives})
        nodes.append({"name": name, "mesh": len(meshes) - 1, "extras": extras})
    while len(w.bin) % 4:
        w.bin.append(0)
    g = {"asset": {"version": "2.0", "generator": "DepthWizard preprocess_vegetation_assets.py", "extras": asset_extras},
         "scene": 0, "scenes": [{"nodes": list(range(len(nodes)))}], "nodes": nodes, "meshes": meshes,
         "materials": materials, "textures": textures, "images": image_entries, "samplers": samplers,
         "accessors": w.accessors, "bufferViews": w.views, "buffers": [{"byteLength": len(w.bin)}]}
    js = json.dumps(g, sort_keys=True, separators=(",", ":")).encode()
    js += b" " * ((4 - len(js) % 4) % 4)
    total = 12 + 8 + len(js) + 8 + len(w.bin)
    out = struct.pack("<III", 0x46546C67, 2, total) + struct.pack("<II", len(js), 0x4E4F534A) + js + \
          struct.pack("<II", len(w.bin), 0x004E4942) + bytes(w.bin)
    Path(path).write_bytes(out)
    return out


def forest_trees(src, out_dir, report):
    """Individual pine trees from the game forest: each tall crossed-card pine
    sprite plus the bark trunk at its foot (where present). The ground tile
    (with its painted trail), grass and shrub sprites are dropped."""
    g, accessor, image = load(src)
    prims = world_primitives(g, accessor)
    name = lambda m: g["materials"][m]["name"]
    foliage = [p for p in prims if name(p[0]) == "Material"]
    trunks = [p for p in prims if name(p[0]) == "Material.004"]
    trunk_axis = [(P[P[:, 1] <= P[:, 1].min() + 0.05][:, [0, 2]].mean(0), k) for k, (_, P, _, _, _) in enumerate(trunks)]
    tall = [p for p in foliage if np.ptp(p[1][:, 1]) >= 0.8]
    # Group the tall sprites by atlas image (UV box), then take the richest
    # member (with a trunk, most triangles) of the largest groups.
    groups = {}
    for p in tall:
        UV = p[3]
        key = tuple(np.round(np.concatenate([UV.min(0), UV.max(0)]) / 0.05).astype(int))
        groups.setdefault(key, []).append(p)
    chosen = []
    for key in sorted(groups, key=lambda k: (-len(groups[k]), k))[:FOREST_TREE_COUNT]:
        def score(p):
            centre = p[1][:, [0, 2]].mean(0)
            has_trunk = any(np.hypot(*(axis - centre)) < 0.08 for axis, _ in trunk_axis)
            return (has_trunk, len(p[4]), round(float(np.ptp(p[1][:, 1])), 4))
        chosen.append(max(groups[key], key=score))
    fol_src = g["materials"][foliage[0][0]]
    bark_src = g["materials"][trunks[0][0]]
    tex_f, mime_f = image(g["textures"][fol_src["pbrMetallicRoughness"]["baseColorTexture"]["index"]]["source"])
    tex_b, mime_b = image(g["textures"][bark_src["pbrMetallicRoughness"]["baseColorTexture"]["index"]]["source"])
    images = [(tex_f, mime_f, 33071), (tex_b, mime_b, 10497)]
    m_fol = material(fol_src, "Vegetation_ForestTree_Foliage", 0, True)
    m_bark = material(bark_src, "Vegetation_ForestTree_Bark", 1, False)
    rgba = np.array(Image.open(io.BytesIO(tex_f)).convert("RGBA"))
    prototypes, stats = [], []
    for k, (_, P, N, UV, I) in enumerate(chosen):
        centre = P[:, [0, 2]].mean(0)
        trunk = next((trunks[j] for axis, j in trunk_axis if np.hypot(*(axis - centre)) < 0.08), None)
        if trunk is not None:
            centre = next(axis for axis, j in trunk_axis if trunks[j] is trunk)
        pieces = [("foliage", P, N, UV, I, m_fol)]
        if trunk is not None:
            pieces.insert(0, ("trunk", trunk[1], trunk[2], trunk[3], trunk[4], m_bark))
        allP = np.vstack([q[1] for q in pieces])
        base, top = allP[:, 1].min(), allP[:, 1].max()
        s = 1.0 / (top - base)
        parts = [(pn, (Q - [centre[0], base, centre[1]]) * s, QN, QUV, QI, mat) for pn, Q, QN, QUV, QI, mat in pieces]
        normP = np.vstack([q[1] for q in parts])
        radius = float(np.hypot(normP[:, 0], normP[:, 2]).max())
        # Re-centre horizontally on the bounding box so the loader's centring check holds.
        lo, hi = normP.min(0), normP.max(0)
        shift = np.array([(lo[0] + hi[0]) / 2, 0.0, (lo[2] + hi[2]) / 2])
        parts = [(pn, Q - shift, QN, QUV, QI, mat) for pn, Q, QN, QUV, QI, mat in parts]
        normP = np.vstack([q[1] for q in parts])
        radius = float(np.hypot(normP[:, 0], normP[:, 2]).max())
        prototypes.append((f"FOREST_TREE_{k}", parts, {"assetSource": "FOREST_TREE", "treeIndex": k,
                                                       "normalisedRadius": round(radius, 6), "hasTrunk": trunk is not None}))
        stats.append({"tree": k, "triangles": int(sum(len(q[4]) // 3 for q in parts)), "has_trunk": trunk is not None,
                      "source_height": round(float(top - base), 4), "normalised_radius": round(radius, 4),
                      "alpha_mask_coverage_045": round(mask_coverage(rgba, UV, I, ALPHA_CUTOFF), 4)})
    data = write_library_glb(out_dir / "forest_trees.glb", prototypes, images,
                             dict(g["asset"].get("extras", {}), modifications="Ground tile (with its painted trail), grass and shrub sprites removed; %d representative pine trees kept (crossed-card sprite plus bark trunk where present), each normalised to base Y=0, top Y=1, centred; foliage alpha BLEND->MASK (cutoff 0.45); normal maps dropped; metallic 0, roughness 0.9" % len(prototypes)))
    report["forest_trees"] = {"source_triangles_all": int(sum(len(p[4]) // 3 for p in prims)), "tall_sprites": len(tall),
                              "trunks": len(trunks), "trees": stats, "optimized_bytes": len(data),
                              "sha256": hashlib.sha256(data).hexdigest()}


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--bush", required=True); ap.add_argument("--forest", required=True); ap.add_argument("--out", required=True)
    ap.add_argument("--forest-trees", help="a_forest_3_with_a_road_at_night_for_game.glb (optional)")
    args = ap.parse_args()
    out = Path(args.out); forest_dir = Path(args.forest)
    for sub in ("source/small_bush", "source/forest/textures", "optimized", "LICENSES"):
        (out / sub).mkdir(parents=True, exist_ok=True)
    # Raw sources, kept for provenance (not needed at runtime).
    shutil.copyfile(args.bush, out / "source/small_bush/small_bush.glb")
    for f in ("scene.gltf", "scene.bin", "license.txt"):
        shutil.copyfile(forest_dir / f, out / "source/forest" / f)
    for f in sorted((forest_dir / "textures").iterdir()):
        shutil.copyfile(f, out / "source/forest/textures" / f.name)
    report = {}
    bush(Path(args.bush), out / "optimized", report)
    forest(forest_dir, out / "optimized", report)
    if args.forest_trees:
        (out / "source/forest_trees").mkdir(parents=True, exist_ok=True)
        shutil.copyfile(args.forest_trees, out / "source/forest_trees" / FOREST_TREES_SOURCE)
        forest_trees(Path(args.forest_trees), out / "optimized", report)
    (out / "optimized/preprocess_report.json").write_text(json.dumps(report, indent=1, sort_keys=True) + "\n")
    print(json.dumps(report, indent=1, sort_keys=True))


if __name__ == "__main__":
    sys.exit(main())
