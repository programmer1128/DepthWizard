import * as THREE from 'three';
import { INSTANCED_SEMANTICS, createVegetationLodController } from './vegetationLodController.js';

// Instanced tree visualization proxies (backend stage 5). GLTFLoader turns
// each EXT_mesh_gpu_instancing node into InstancedMesh children (trunk and
// crown primitives); this module prepares them after load and drives the
// chunk-level LOD controller from the render loop.
//
// Trees are visualization proxies: the shared vegetation predicate already
// excludes them from recentering, the heatmap and scientific raycasts. They
// never alter global lighting. Shadows are optional (off by default) and
// cast by the NEAR level only.
//
// External assets (stage 5A: small bush, forest patch) arrive with authored
// base-colour textures (sRGB) and alpha MASK materials; GLTFLoader maps them
// to map + alphaTest, which this module leaves untouched.
//
// URL toggles: ?treeShadows=1 enables NEAR shadows, ?treeDiagnostic=1
// colours trees by candidate category (blue isolated, orange canopy crown,
// as in the backend diagnostics; aqua forest patches), ?treeLod=0 keeps
// every batch at its finest level.

const DIAGNOSTIC_COLOURS = {
    ISOLATED_TREE: 0x2f6bff,
    DENSE_CANOPY_CROWN: 0xff8a1f,
    EXPERIMENTAL_LOW_CONFIDENCE_TREE: 0xd02fd0,
    FOREST_PROXY: 0x1fbfbf,
    COVER_SHRUB: 0xe0c020,
    FOREST_TREE: 0x20a060
};

export function vegetationTreeOptionsFromUrl(search = '') {
    const params = new URLSearchParams(search);
    return {
        shadows: params.get('treeShadows') === '1',
        diagnostic: params.get('treeDiagnostic') === '1',
        lod: params.get('treeLod') !== '0'
    };
}

// Tree batch node objects (Group or InstancedMesh) of a model.
export function treeNodes(model) {
    const nodes = [];
    model.traverse((object) => {
        if (INSTANCED_SEMANTICS.has(object.userData?.geometrySemantic)) {
            nodes.push(object);
        }
    });
    return nodes;
}

function instancedMeshesOf(node) {
    const meshes = [];
    node.traverse((object) => {
        if (object.isInstancedMesh) {
            meshes.push(object);
        }
    });
    return meshes;
}

export function setupVegetationTrees(model, { shadows = false, diagnostic = false, lod = true } = {}) {
    const nodes = treeNodes(model);
    if (nodes.length === 0) {
        return null;
    }
    const entries = [];
    for (const node of nodes) {
        for (const mesh of instancedMeshesOf(node)) {
            // Per-node frustum culling over all instances.
            mesh.computeBoundingBox();
            mesh.computeBoundingSphere();
            mesh.frustumCulled = true;
            mesh.receiveShadow = false;
            entries.push({ mesh, node, originalMaterial: mesh.material, originalInstanceColor: mesh.instanceColor });
        }
    }
    const controller = createVegetationLodController(model, { enabled: lod });
    const diagnosticMaterials = new Map();
    const viewport = new THREE.Vector2();

    function setShadows(enabled) {
        for (const { mesh, node } of entries) {
            mesh.castShadow = Boolean(enabled) && node.userData.vegetationLod === 'NEAR';
        }
    }

    function setDiagnostic(enabled) {
        for (const entry of entries) {
            const { mesh, node } = entry;
            if (enabled) {
                const category = node.userData.treeCategory || 'ISOLATED_TREE';
                // Per (category, source material). An alpha-masked texture
                // keeps its map (alpha channel) and cutoff, so leaves stay cut
                // out; the emissive term keeps the category colour readable
                // over dark foliage.
                const key = `${category}|${entry.originalMaterial.uuid}`;
                if (!diagnosticMaterials.has(key)) {
                    const source = entry.originalMaterial;
                    const colour = DIAGNOSTIC_COLOURS[category] ?? 0xffffff;
                    const masked = source.alphaTest > 0 && source.map;
                    diagnosticMaterials.set(key, new THREE.MeshStandardMaterial({
                        color: colour, metalness: 0, roughness: 0.9,
                        map: masked ? source.map : null,
                        emissive: masked ? colour : 0x000000,
                        emissiveIntensity: masked ? 0.6 : 1,
                        alphaTest: masked ? source.alphaTest : 0,
                        side: source.side
                    }));
                }
                mesh.material = diagnosticMaterials.get(key);
                mesh.instanceColor = null;
            } else {
                mesh.material = entry.originalMaterial;
                mesh.instanceColor = entry.originalInstanceColor;
            }
        }
    }

    function update(camera, renderer) {
        renderer.getSize(viewport);
        controller.update(camera, viewport.y || 1);
    }

    function stats() {
        let instances = 0;
        let visibleMeshes = 0;
        for (const { mesh, node } of entries) {
            if (mesh.visible && node.visible) {
                visibleMeshes += 1;
            }
        }
        for (const node of nodes) {
            if (node.userData.vegetationLod === 'NEAR') {
                instances += Number(node.userData.instanceCount) || 0;
            }
        }
        return { nodes: nodes.length, instancedMeshes: entries.length, visibleMeshes, instances, ...controller.stats() };
    }

    function dispose() {
        setDiagnostic(false);
        for (const material of diagnosticMaterials.values()) {
            material.dispose();
        }
        diagnosticMaterials.clear();
    }

    setShadows(shadows);
    if (diagnostic) {
        setDiagnostic(true);
    }
    return { nodes, entries, controller, update, setShadows, setDiagnostic, stats, dispose };
}
