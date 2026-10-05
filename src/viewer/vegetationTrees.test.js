// node --test: instanced tree proxies (backend stage 5) load as InstancedMesh,
// keep one LOD level per batch, and never reach scientific tools.
import test from 'node:test';
import assert from 'node:assert/strict';
import * as THREE from 'three';
import { GLTFLoader } from 'three/addons/loaders/GLTFLoader.js';

import { intersectScientific, isVegetationVisualizationNode, scientificBounds } from './vegetation.js';
import {
    DEFAULT_TREE_LOD_THRESHOLDS,
    chooseTreeLevel,
    collectTreeBatches,
    createVegetationLodController,
    projectedPixels
} from './vegetationLodController.js';
import { setupVegetationTrees, treeNodes, vegetationTreeOptionsFromUrl } from './vegetationTreeRenderer.js';

// --- A GLB shaped like the backend's: base terrain node, then tree batches --

const PROVENANCE = {
    geometrySemantic: 'VEGETATION_TREE_INSTANCES',
    visualizationProxy: true,
    scientificSurface: false,
    speciesInferred: false,
    positionSource: 'SEMANTIC_VEGETATION',
    heightSource: 'NDSM',
    externalGeographicDataUsed: false
};

// Three instances: (x, baseY, z), yaw, crown radius, display height.
const INSTANCES = [
    { t: [10, 0, -5], yaw: 0.3, r: 2.5, h: 9 },
    { t: [-12, 0.5, 8], yaw: 2.1, r: 3.0, h: 12 },
    { t: [4, 1.0, 20], yaw: 4.4, r: 1.8, h: 6 }
];

function quaternionY(yaw) {
    return [0, Math.sin(yaw / 2), 0, Math.cos(yaw / 2)];
}

function buildGlb() {
    const chunks = [];
    let offset = 0;
    const bufferViews = [];
    const accessors = [];
    const view = (typed, target) => {
        const bytes = new Uint8Array(typed.buffer, typed.byteOffset, typed.byteLength);
        const padded = new Uint8Array(Math.ceil(bytes.length / 4) * 4);
        padded.set(bytes);
        chunks.push(padded);
        bufferViews.push({ buffer: 0, byteOffset: offset, byteLength: bytes.length, ...(target ? { target } : {}) });
        offset += padded.length;
        return bufferViews.length - 1;
    };
    const accessor = (typed, type, componentType, count, extra = {}, target = undefined) => {
        accessors.push({ bufferView: view(typed, target), componentType, count, type, ...extra });
        return accessors.length - 1;
    };

    // Terrain: a 100 m square at y = 0.
    const terrainPositions = new Float32Array([-50, 0, -50, 50, 0, -50, 50, 0, 50, -50, 0, 50]);
    const terrainNormals = new Float32Array([0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0]);
    const terrainIndices = new Uint32Array([0, 2, 1, 0, 3, 2]);
    const tp = accessor(terrainPositions, 'VEC3', 5126, 4, { min: [-50, 0, -50], max: [50, 0, 50] }, 34962);
    const tn = accessor(terrainNormals, 'VEC3', 5126, 4, {}, 34962);
    const ti = accessor(terrainIndices, 'SCALAR', 5125, 6, {}, 34963);

    // Prototype: trunk (thin box) and crown (box in the upper half), base y = 0, top y = 1.
    const box = (x0, y0, z0, x1, y1, z1) => {
        const p = [];
        const n = [];
        const quad = (a, b, c, d, normal) => {
            for (const v of [a, b, c, a, c, d]) {
                p.push(...v);
                n.push(...normal);
            }
        };
        quad([x0, y0, z1], [x1, y0, z1], [x1, y1, z1], [x0, y1, z1], [0, 0, 1]);
        quad([x1, y0, z0], [x0, y0, z0], [x0, y1, z0], [x1, y1, z0], [0, 0, -1]);
        quad([x1, y0, z1], [x1, y0, z0], [x1, y1, z0], [x1, y1, z1], [1, 0, 0]);
        quad([x0, y0, z0], [x0, y0, z1], [x0, y1, z1], [x0, y1, z0], [-1, 0, 0]);
        quad([x0, y1, z1], [x1, y1, z1], [x1, y1, z0], [x0, y1, z0], [0, 1, 0]);
        quad([x0, y0, z0], [x1, y0, z0], [x1, y0, z1], [x0, y0, z1], [0, -1, 0]);
        const positions = new Float32Array(p);
        const indices = new Uint32Array(positions.length / 3).map((_, k) => k);
        return { positions, normals: new Float32Array(n), indices, min: [x0, y0, z0], max: [x1, y1, z1] };
    };
    const geometry = (g) => ({
        POSITION: accessor(g.positions, 'VEC3', 5126, g.positions.length / 3, { min: g.min, max: g.max }, 34962),
        NORMAL: accessor(g.normals, 'VEC3', 5126, g.normals.length / 3, {}, 34962),
        indices: accessor(g.indices, 'SCALAR', 5125, g.indices.length, {}, 34963)
    });
    const trunk = geometry(box(-0.1, 0, -0.1, 0.1, 0.6, 0.1));
    const crown = geometry(box(-1, 0.4, -1, 1, 1, 1));

    // Instance data, stored once and shared by the three LOD nodes.
    const translations = new Float32Array(INSTANCES.flatMap((i) => i.t));
    const rotations = new Float32Array(INSTANCES.flatMap((i) => quaternionY(i.yaw)));
    const scales = new Float32Array(INSTANCES.flatMap((i) => [i.r, i.h, i.r]));
    const colours = new Float32Array(INSTANCES.flatMap(() => [0.9, 0.95, 0.85]));
    const attributes = {
        TRANSLATION: accessor(translations, 'VEC3', 5126, 3),
        ROTATION: accessor(rotations, 'VEC4', 5126, 3),
        SCALE: accessor(scales, 'VEC3', 5126, 3),
        _COLOR_0: accessor(colours, 'VEC3', 5126, 3)
    };

    const prim = (g, material) => ({ attributes: { POSITION: g.POSITION, NORMAL: g.NORMAL }, indices: g.indices, material });
    const meshes = [
        { name: 'terrain', primitives: [prim({ POSITION: tp, NORMAL: tn, indices: ti }, 0)] },
        { name: 'VEGETATION_TREE_BROADLEAF_ROUND_NEAR', primitives: [prim(trunk, 1), prim(crown, 2)] },
        { name: 'VEGETATION_TREE_BROADLEAF_ROUND_MEDIUM', primitives: [prim(trunk, 1), prim(crown, 2)] },
        { name: 'VEGETATION_TREE_BROADLEAF_ROUND_FAR', primitives: [prim(crown, 2)] }
    ];
    const bounds = { boundsMinX: -15, boundsMinY: 0, boundsMinZ: -8, boundsMaxX: 13, boundsMaxY: 12.5, boundsMaxZ: 22 };
    const treeNode = (lod, mesh) => ({
        name: `VEGETATION_TREES_${lod}_BROADLEAF_ROUND_CHUNK_000`,
        mesh,
        extensions: { EXT_mesh_gpu_instancing: { attributes } },
        extras: {
            ...PROVENANCE, ...bounds,
            vegetationLod: lod,
            vegetationBatch: 'BROADLEAF_ROUND_CHUNK_000',
            treeCategory: 'ISOLATED_TREE',
            visualVariant: 'BROADLEAF_ROUND',
            instanceCount: 3,
            typicalDisplayHeight: 9,
            typicalCrownRadius: 2.5
        }
    });
    const json = {
        asset: { version: '2.0' },
        extensionsUsed: ['EXT_mesh_gpu_instancing'],
        scene: 0,
        scenes: [{ nodes: [0, 1, 2, 3] }],
        nodes: [{ mesh: 0 }, treeNode('NEAR', 1), treeNode('MEDIUM', 2), treeNode('FAR', 3)],
        meshes,
        materials: [
            { name: 'terrain', pbrMetallicRoughness: { metallicFactor: 0, roughnessFactor: 1 } },
            { name: 'Vegetation_Tree_Trunk', pbrMetallicRoughness: { baseColorFactor: [0.3, 0.22, 0.15, 1], metallicFactor: 0, roughnessFactor: 0.95 } },
            { name: 'Vegetation_Tree_Crown_BROADLEAF_ROUND', pbrMetallicRoughness: { baseColorFactor: [0.2, 0.33, 0.12, 1], metallicFactor: 0, roughnessFactor: 0.9 } }
        ],
        accessors,
        bufferViews,
        buffers: [{ byteLength: offset }]
    };
    const binary = new Uint8Array(offset);
    let cursor = 0;
    for (const chunk of chunks) {
        binary.set(chunk, cursor);
        cursor += chunk.length;
    }
    let jsonBytes = new TextEncoder().encode(JSON.stringify(json));
    const jsonPadded = new Uint8Array(Math.ceil(jsonBytes.length / 4) * 4).fill(0x20);
    jsonPadded.set(jsonBytes);
    jsonBytes = jsonPadded;
    const total = 12 + 8 + jsonBytes.length + 8 + binary.length;
    const glb = new ArrayBuffer(total);
    const dv = new DataView(glb);
    dv.setUint32(0, 0x46546c67, true);
    dv.setUint32(4, 2, true);
    dv.setUint32(8, total, true);
    dv.setUint32(12, jsonBytes.length, true);
    dv.setUint32(16, 0x4e4f534a, true);
    new Uint8Array(glb, 20, jsonBytes.length).set(jsonBytes);
    dv.setUint32(20 + jsonBytes.length, binary.length, true);
    dv.setUint32(24 + jsonBytes.length, 0x004e4942, true);
    new Uint8Array(glb, 28 + jsonBytes.length).set(binary);
    return glb;
}

function loadModel() {
    return new Promise((resolve, reject) => {
        new GLTFLoader().parse(buildGlb(), '', (gltf) => resolve(gltf.scene), reject);
    });
}

function instancedMeshes(model) {
    const meshes = [];
    model.traverse((o) => { if (o.isInstancedMesh) meshes.push(o); });
    return meshes;
}

// --- Loading ----------------------------------------------------------------

test('three.js loads each tree batch as InstancedMesh with the backend transforms', async () => {
    const model = await loadModel();
    const meshes = instancedMeshes(model);
    // NEAR and MEDIUM: trunk + crown; FAR: crown only.
    assert.equal(meshes.length, 5);
    const matrix = new THREE.Matrix4();
    const expected = new THREE.Matrix4();
    for (const mesh of meshes) {
        assert.equal(mesh.count, INSTANCES.length);
        assert.ok(mesh.instanceColor, 'per-instance tint');
        INSTANCES.forEach((instance, k) => {
            mesh.getMatrixAt(k, matrix);
            expected.compose(
                new THREE.Vector3(...instance.t),
                new THREE.Quaternion(...quaternionY(instance.yaw)),
                new THREE.Vector3(instance.r, instance.h, instance.r)
            );
            matrix.elements.forEach((value, e) => assert.ok(Math.abs(value - expected.elements[e]) < 1e-5));
            // Base on the ground point, top at baseY + displayHeight.
            const base = new THREE.Vector3(0, 0, 0).applyMatrix4(matrix);
            const top = new THREE.Vector3(0, 1, 0).applyMatrix4(matrix);
            assert.ok(base.distanceTo(new THREE.Vector3(...instance.t)) < 1e-5);
            assert.ok(Math.abs(top.y - (instance.t[1] + instance.h)) < 1e-5);
        });
    }
    // No THREE.LOD per tree, and no per-tree meshes.
    let lodObjects = 0;
    model.traverse((o) => { if (o.isLOD) lodObjects += 1; });
    assert.equal(lodObjects, 0);
    assert.equal(treeNodes(model).length, 3);
});

// --- Analysis exclusion -----------------------------------------------------

test('trees are visualization proxies: excluded from raycasts and bounds, still visible', async () => {
    const model = await loadModel();
    model.updateMatrixWorld(true);
    for (const mesh of instancedMeshes(model)) {
        assert.equal(isVegetationVisualizationNode(mesh), true);
    }
    // A ray straight down through the first tree reaches it raw, but
    // scientific raycasts see only the terrain below.
    const [x, , z] = INSTANCES[0].t;
    const raycaster = new THREE.Raycaster(new THREE.Vector3(x, 100, z), new THREE.Vector3(0, -1, 0));
    const raw = raycaster.intersectObject(model, true);
    assert.ok(raw.length > 0 && isVegetationVisualizationNode(raw[0].object));
    const scientific = intersectScientific(raycaster, model);
    assert.ok(scientific.length > 0);
    assert.equal(scientific[0].object.name, 'terrain');
    assert.ok(Math.abs(scientific[0].point.y) < 1e-6);
    assert.ok(scientific.every((hit) => !isVegetationVisualizationNode(hit.object)));
    // Recentering reference: terrain only (trees are taller and wider).
    const bounds = scientificBounds(model);
    assert.ok(Math.abs(bounds.max.y) < 1e-6);
    assert.ok(Math.abs(bounds.min.x + 50) < 1e-6 && Math.abs(bounds.max.x - 50) < 1e-6);
});

// --- LOD --------------------------------------------------------------------

test('LOD level follows projected size with hysteresis', () => {
    const all = new Set(['NEAR', 'MEDIUM', 'FAR']);
    const { nearPixels, mediumPixels, hysteresis } = DEFAULT_TREE_LOD_THRESHOLDS;
    assert.equal(chooseTreeLevel(200, 'NEAR', all), 'NEAR');
    assert.equal(chooseTreeLevel(30, 'NEAR', all), 'MEDIUM');
    assert.equal(chooseTreeLevel(3, 'NEAR', all), 'FAR');
    // Hysteresis: just below the NEAR threshold stays NEAR; just above it
    // does not leave MEDIUM.
    assert.equal(chooseTreeLevel(nearPixels * 0.95, 'NEAR', all), 'NEAR');
    assert.equal(chooseTreeLevel(nearPixels / hysteresis * 0.99, 'NEAR', all), 'MEDIUM');
    assert.equal(chooseTreeLevel(nearPixels * 1.05, 'MEDIUM', all), 'MEDIUM');
    assert.equal(chooseTreeLevel(nearPixels * hysteresis * 1.01, 'MEDIUM', all), 'NEAR');
    assert.equal(chooseTreeLevel(mediumPixels * 0.95, 'MEDIUM', all), 'MEDIUM');
    assert.equal(chooseTreeLevel(mediumPixels * 1.05, 'FAR', all), 'FAR');
    // Isolated trees keep a FAR representation at any distance.
    assert.equal(chooseTreeLevel(0.01, 'FAR', all), 'FAR');
    // Dense crowns (no FAR level) disappear instead.
    const crowns = new Set(['NEAR', 'MEDIUM', 'HIDDEN']);
    assert.equal(chooseTreeLevel(3, 'MEDIUM', crowns), 'HIDDEN');
    assert.equal(chooseTreeLevel(30, 'HIDDEN', crowns), 'MEDIUM');
    // LOD disabled in the backend: the only level stays.
    assert.equal(chooseTreeLevel(0.01, 'NEAR', new Set(['NEAR'])), 'NEAR');
    // Projected size: a 10 m tree 100 m away, 60 degree fov, 800 px viewport.
    const camera = new THREE.PerspectiveCamera(60, 1.6, 0.1, 1000);
    assert.ok(Math.abs(projectedPixels(10, 100, camera, 800) - 10 * 400 / Math.tan(Math.PI / 6) / 100) < 1e-9);
});

test('exactly one LOD level per batch is visible as the camera moves', async () => {
    const model = await loadModel();
    model.updateMatrixWorld(true);
    const controller = createVegetationLodController(model);
    const batch = [...controller.batches.values()][0];
    const visibleLevels = () => [...batch.levels].filter(([, object]) => object.visible).map(([name]) => name);
    assert.deepEqual(visibleLevels(), ['NEAR']);   // Before the first render
    const camera = new THREE.PerspectiveCamera(60, 1.6, 0.1, 100000);
    const seen = [];
    for (const distance of [20, 200, 600, 3000, 20000, 3000, 600, 200, 20]) {
        camera.position.set(0, distance, distance);
        camera.updateMatrixWorld(true);
        controller.update(camera, 800);
        const visible = visibleLevels();
        assert.equal(visible.length, 1, `one level at ${distance} m`);
        seen.push(visible[0]);
    }
    assert.deepEqual(seen, ['NEAR', 'MEDIUM', 'FAR', 'FAR', 'FAR', 'FAR', 'FAR', 'MEDIUM', 'NEAR']);
    // Disabling LOD returns to the finest level.
    controller.setEnabled(false);
    assert.deepEqual(visibleLevels(), ['NEAR']);
});

test('dense-crown batches hide when small; batches are grouped by vegetationBatch', () => {
    const model = new THREE.Group();
    const make = (lod, category, batchKey) => {
        const node = new THREE.Group();
        node.userData = { ...PROVENANCE, vegetationLod: lod, vegetationBatch: batchKey, treeCategory: category,
                          typicalDisplayHeight: 10, boundsMinX: 0, boundsMinY: 0, boundsMinZ: 0,
                          boundsMaxX: 10, boundsMaxY: 10, boundsMaxZ: 10 };
        model.add(node);
        return node;
    };
    make('NEAR', 'DENSE_CANOPY_CROWN', 'CANOPY_CROWN_CHUNK_000');
    make('MEDIUM', 'DENSE_CANOPY_CROWN', 'CANOPY_CROWN_CHUNK_000');
    const lone = make('NEAR', 'ISOLATED_TREE', 'SHRUB_CHUNK_001');   // LOD off: one level
    model.updateMatrixWorld(true);
    const batches = collectTreeBatches(model);
    assert.equal(batches.size, 2);
    assert.ok(batches.get('CANOPY_CROWN_CHUNK_000').available.has('HIDDEN'));
    assert.ok(!batches.get('SHRUB_CHUNK_001').available.has('HIDDEN'));
    const controller = createVegetationLodController(model);
    const camera = new THREE.PerspectiveCamera(60, 1.6, 0.1, 1e6);
    camera.position.set(0, 50000, 0);
    camera.updateMatrixWorld(true);
    controller.update(camera, 800);
    const crown = controller.batches.get('CANOPY_CROWN_CHUNK_000');
    assert.equal(crown.level, 'HIDDEN');
    assert.ok([...crown.levels.values()].every((object) => !object.visible));
    assert.equal(lone.visible, true);
    assert.deepEqual(controller.stats().levels, { NEAR: 1, MEDIUM: 0, FAR: 0, HIDDEN: 1 });
});

// --- Renderer setup ---------------------------------------------------------

test('setup bounds instances for culling, shadows only at NEAR, diagnostic colours restore', async () => {
    const model = await loadModel();
    model.updateMatrixWorld(true);
    assert.equal(setupVegetationTrees(new THREE.Group()), null);
    const trees = setupVegetationTrees(model, { shadows: false });
    for (const { mesh } of trees.entries) {
        assert.equal(mesh.castShadow, false);
        // The bounding sphere covers every instance, not just the prototype.
        for (const instance of INSTANCES) {
            const top = new THREE.Vector3(instance.t[0], instance.t[1] + instance.h * 0.99, instance.t[2]);
            if (mesh.geometry.boundingBox.max.y > 0.9) {
                assert.ok(mesh.boundingSphere.distanceToPoint(top) <= 1e-3);
            }
        }
    }
    trees.setShadows(true);
    for (const { mesh, node } of trees.entries) {
        assert.equal(mesh.castShadow, node.userData.vegetationLod === 'NEAR');
    }
    const originals = trees.entries.map((entry) => entry.mesh.material);
    trees.setDiagnostic(true);
    for (const { mesh } of trees.entries) {
        assert.equal(mesh.material.color.getHex(), 0x2f6bff);
        assert.equal(mesh.instanceColor, null);
    }
    trees.setDiagnostic(false);
    trees.entries.forEach((entry, k) => {
        assert.equal(entry.mesh.material, originals[k]);
        assert.ok(entry.mesh.instanceColor);
    });
    assert.equal(trees.stats().instances, 3);
    assert.deepEqual(vegetationTreeOptionsFromUrl('?treeShadows=1&treeDiagnostic=1'),
                     { shadows: true, diagnostic: true, lod: true });
    assert.deepEqual(vegetationTreeOptionsFromUrl('?treeLod=0'), { shadows: false, diagnostic: false, lod: false });
    trees.dispose();
});

// --- Stage 5A: forest proxies and alpha-masked assets ------------------------

test('forest-patch batches hide at far distance; alpha-masked diagnostics keep their cut-outs', () => {
    const model = new THREE.Group();
    const texture = new THREE.Texture();
    const forestMaterial = new THREE.MeshStandardMaterial({ map: texture, alphaTest: 0.45, side: THREE.DoubleSide });
    const make = (lod) => {
        const mesh = new THREE.InstancedMesh(new THREE.BoxGeometry(1, 1, 1), forestMaterial, 2);
        const node = new THREE.Group();
        node.add(mesh);
        node.userData = { geometrySemantic: 'VEGETATION_FOREST_PROXY', visualizationProxy: true, scientificSurface: false,
                          vegetationLod: lod, vegetationBatch: 'FOREST_PATCH_CHUNK_000', treeCategory: 'FOREST_PROXY',
                          typicalDisplayHeight: 12, instanceCount: 2, boundsMinX: 0, boundsMinY: 0, boundsMinZ: 0,
                          boundsMaxX: 50, boundsMaxY: 12, boundsMaxZ: 50 };
        model.add(node);
        return node;
    };
    make('NEAR');
    make('MEDIUM');
    model.updateMatrixWorld(true);
    assert.equal(isVegetationVisualizationNode(model.children[0].children[0]), true);
    const trees = setupVegetationTrees(model);
    const batch = trees.controller.batches.get('FOREST_PATCH_CHUNK_000');
    assert.ok(batch.available.has('HIDDEN'));
    const camera = new THREE.PerspectiveCamera(60, 1.6, 0.1, 1e6);
    camera.position.set(0, 60000, 0);
    camera.updateMatrixWorld(true);
    trees.controller.update(camera, 800);
    assert.equal(batch.level, 'HIDDEN');
    camera.position.set(25, 40, 60);
    camera.updateMatrixWorld(true);
    trees.controller.update(camera, 800);
    assert.equal(batch.level, 'NEAR');
    trees.setDiagnostic(true);
    const diag = trees.entries[0].mesh.material;
    assert.equal(diag.map, texture);
    assert.equal(diag.alphaTest, 0.45);
    assert.equal(diag.color.getHex(), 0x1fbfbf);
    trees.setDiagnostic(false);
    assert.equal(trees.entries[0].mesh.material, forestMaterial);
});
