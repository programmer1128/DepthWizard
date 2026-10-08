#!/usr/bin/env python3
"""Synthetic urban sample terrain for DepthWizard.
This replaces the previous remote-tiles terrain with a simple building-style mesh
so the app loads a textured, elevated urban landscape without needing external
network access.

Output:
  - test_8_output.glb
  - demo_optical.jpg
"""
import argparse
import math
import random

import numpy as np
import trimesh
from PIL import Image


def make_road_grid(extent, cell_count):
    """Return a 2D mask with 1 = building footprint, 0 = road/empty space."""
    grid = np.ones((cell_count, cell_count), dtype=np.uint8)
    for r in range(cell_count):
        for c in range(cell_count):
            if r % 2 == 0 or c % 2 == 0:
                grid[r, c] = 0
    return grid


def make_ground_mesh(extent, grid_size):
    xs = np.linspace(-extent / 2, extent / 2, grid_size)
    X, Z = np.meshgrid(xs, xs)
    Y = np.zeros_like(X, dtype=np.float64)
    vertices = np.stack([X.ravel(), Y.ravel(), Z.ravel()], axis=1)
    faces = []
    for r in range(grid_size - 1):
        for c in range(grid_size - 1):
            a = r * grid_size + c
            b = a + 1
            d = (r + 1) * grid_size + c
            e = d + 1
            faces.append([a, b, e])
            faces.append([a, e, d])
    mesh = trimesh.Trimesh(vertices=vertices, faces=np.array(faces), process=False)
    return mesh


def add_buildings(scene, extent, building_count=36):
    rng = random.Random(7)
    half = extent / 2
    cell = extent / 8
    centers = []

    for _ in range(building_count):
        cx = rng.uniform(-half + 12, half - 12)
        cz = rng.uniform(-half + 12, half - 12)
        width = rng.uniform(6, 16)
        depth = rng.uniform(6, 16)
        height = rng.uniform(8, 38)

        # Keep the buildings inside the terrain footprint.
        if abs(cx) > half - 10 or abs(cz) > half - 10:
            continue

        centers.append((cx, cz, width, depth, height))

    for i, (cx, cz, width, depth, height) in enumerate(centers):
        block = trimesh.creation.box(extents=[width, height, depth])
        block.apply_translation([cx, height / 2, cz])
        color = np.array([
            0.22 + (i % 5) * 0.08,
            0.34 + (i % 3) * 0.12,
            0.48 + (i % 4) * 0.1,
            1.0
        ])
        block.visual.face_colors = np.tile(color * 255, (len(block.faces), 1)).astype(np.uint8)
        scene.add_geometry(block, node_name=f"building_{i}", geom_name=f"building_{i}")

    # Add a few central towers for more interesting elevation variation.
    for i in range(6):
        base = [-18 + i * 7, 18 - i * 5]
        tower = trimesh.creation.box(extents=[4.5, 45 + i * 10, 4.5])
        tower.apply_translation([base[0], (45 + i * 10) / 2, base[1]])
        tower.visual.face_colors = np.tile(np.array([0.6, 0.7, 0.86, 1.0]) * 255, (len(tower.faces), 1)).astype(np.uint8)
        scene.add_geometry(tower, node_name=f"tower_{i}", geom_name=f"tower_{i}")


def make_demo_texture(extent, size=1024):
    """Create a simple grayscale/brownish city texture that looks like a map."""
    img = np.zeros((size, size, 3), dtype=np.uint8)
    y, x = np.indices((size, size))
    base = 210 + (x % 23) * 2 + (y % 17) * 2
    img[:, :, 0] = base
    img[:, :, 1] = base - 10
    img[:, :, 2] = base - 30

    # Add darker roads and blocks.
    xs = np.linspace(-1, 1, size)
    ys = np.linspace(-1, 1, size)
    xx, yy = np.meshgrid(xs, ys)
    road_mask = (np.abs(xx) < 0.12) | (np.abs(yy) < 0.12)
    img[road_mask] = np.array([120, 120, 120], dtype=np.uint8)

    return Image.fromarray(img, mode="RGB")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--extent", type=float, default=220.0)
    ap.add_argument("--grid", type=int, default=128)
    ap.add_argument("--out", default="test_8_output.glb")
    ap.add_argument("--optical-out", default="demo_optical.jpg")
    args = ap.parse_args()

    scene = trimesh.Scene()
    ground = make_ground_mesh(args.extent, args.grid)
    ground.visual.face_colors = np.tile(np.array([0.56, 0.58, 0.62, 1.0]) * 255, (len(ground.faces), 1)).astype(np.uint8)
    scene.add_geometry(ground, node_name="ground", geom_name="ground")

    add_buildings(scene, args.extent)

    texture = make_demo_texture(args.extent)
    texture.save(args.optical_out, quality=88)

    scene.export(args.out)
    print(f"[ok] {args.out}: synthetic urban terrain generated")
    print(f"[ok] {args.optical_out}: demo texture saved")
    print("NEXT: refresh the page and click 'Load Sample Terrain'.")


if __name__ == "__main__":
    main()