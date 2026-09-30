import sys, numpy as np, trimesh
s = trimesh.load(sys.argv[1])
geo = s.geometry if isinstance(s, trimesh.Scene) else {"mesh": s}
assert len(geo) == 1, "sample GLB must contain ONLY the ground mesh (flood raycast contract)"
for name, m in geo.items():
    b = m.bounds
    print(f"mesh={name} verts={len(m.vertices)} tris={len(m.faces)}")
    print(f"  bounds X {b[0][0]:.1f}..{b[1][0]:.1f}  Y {b[0][1]:.1f}..{b[1][1]:.1f}  Z {b[0][2]:.1f}..{b[1][2]:.1f} m")
    assert np.isfinite(m.vertices).all(), "NaN vertices"
    assert 0.5 < (b[1][1]-b[0][1]) < 5000, "Y span not metre-scale terrain"
    uv = getattr(m.visual, "uv", None)
    tex = getattr(getattr(m.visual, "material", None), "baseColorTexture", None)
    assert uv is not None and uv.min() >= -1e-3 and uv.max() <= 1+1e-3, "UVs must be planar 0..1"
    assert tex is not None, "embedded optical texture missing (PiP/comparison shader needs it)"
    print(f"  uv ok [{uv.min():.2f},{uv.max():.2f}]  texture ok {tex.size}  doubleSided={m.visual.material.doubleSided}")
print("PASS: contract-ready for loadTerrainGLB()")