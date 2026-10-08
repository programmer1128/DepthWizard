import * as THREE from 'three';

// Chunk-level level of detail for instanced tree batches.
//
// The backend writes one EXT_mesh_gpu_instancing node per (chunk, variant,
// level): VEGETATION_TREES_<NEAR|MEDIUM|FAR>_<VARIANT>_CHUNK_<NNN>, all
// levels of one batch sharing extras.vegetationBatch. Exactly one level of a
// batch is visible at a time, chosen from the projected screen height of the
// batch's typical tree at the batch's nearest point, with hysteresis so a
// batch does not flicker at a threshold. Isolated trees always keep a
// representation (FAR has no hidden state); dense-canopy crown batches have
// no FAR level and disappear instead, since the canopy sheet already covers
// them. Forest-patch proxies (VEGETATION_FOREST_PROXY, NEAR + MEDIUM) also
// hide at far distance. A batch with only one level (LOD disabled in the
// backend, or external small-bush batches) keeps it.
// Frustum culling stays per node (three.js, InstancedMesh bounding spheres).

export const TREE_LEVELS = ['NEAR', 'MEDIUM', 'FAR', 'HIDDEN'];
export const INSTANCED_SEMANTICS = new Set(['VEGETATION_TREE_INSTANCES', 'VEGETATION_FOREST_PROXY', 'VEGETATION_COVER_PROXY']);
// Categories that disappear instead of keeping a far level: the continuous
// canopy already represents them at distance.
const HIDE_AT_FAR = new Set(['DENSE_CANOPY_CROWN', 'FOREST_PROXY']);

export const DEFAULT_TREE_LOD_THRESHOLDS = Object.freeze({
    nearPixels: 48,    // NEAR at or above this projected tree height
    mediumPixels: 14,  // MEDIUM at or above this, FAR (or hidden) below
    hysteresis: 1.2    // Switch finer at threshold x h, coarser at threshold / h
});

// Level index for a projected height in pixels, given the previous level and
// the available levels (a Set of names). Pure; exported for tests.
export function chooseTreeLevel(pixels, previous, available, thresholds = DEFAULT_TREE_LOD_THRESHOLDS) {
    const previousIndex = Math.max(0, TREE_LEVELS.indexOf(previous));
    const boundaries = [thresholds.nearPixels, thresholds.mediumPixels];
    let desired = 0;
    boundaries.forEach((threshold, boundary) => {
        // Boundary k separates level k (finer) from level k + 1 (coarser).
        const effective = previousIndex <= boundary
            ? threshold / thresholds.hysteresis
            : threshold * thresholds.hysteresis;
        if (pixels < effective) {
            desired = boundary + 1;
        }
    });
    // Nearest available level, coarser first, then finer.
    for (let index = desired; index < TREE_LEVELS.length; index += 1) {
        if (available.has(TREE_LEVELS[index])) {
            return TREE_LEVELS[index];
        }
    }
    for (let index = desired - 1; index >= 0; index -= 1) {
        if (available.has(TREE_LEVELS[index])) {
            return TREE_LEVELS[index];
        }
    }
    return previous;
}

// Projected height in pixels of an object of `worldHeight` at `distance`
// for a perspective camera and a viewport `viewportHeight` pixels tall.
export function projectedPixels(worldHeight, distance, camera, viewportHeight) {
    const fov = THREE.MathUtils.degToRad(camera.fov || 50);
    const focal = viewportHeight / (2 * Math.tan(fov / 2));
    return worldHeight * focal / Math.max(distance, 1e-3);
}

function readBounds(data) {
    const keys = ['boundsMinX', 'boundsMinY', 'boundsMinZ', 'boundsMaxX', 'boundsMaxY', 'boundsMaxZ'];
    if (!keys.every((key) => Number.isFinite(data[key]))) {
        return null;
    }
    return new THREE.Box3(
        new THREE.Vector3(data.boundsMinX, data.boundsMinY, data.boundsMinZ),
        new THREE.Vector3(data.boundsMaxX, data.boundsMaxY, data.boundsMaxZ)
    );
}

// Batch nodes of a loaded model, keyed by extras.vegetationBatch.
export function collectTreeBatches(model) {
    const batches = new Map();
    model.traverse((object) => {
        const data = object.userData || {};
        if (!INSTANCED_SEMANTICS.has(data.geometrySemantic) || typeof data.vegetationBatch !== 'string'
            || !TREE_LEVELS.includes(data.vegetationLod)) {
            return;
        }
        let batch = batches.get(data.vegetationBatch);
        if (!batch) {
            batch = {
                key: data.vegetationBatch,
                category: data.treeCategory || 'ISOLATED_TREE',
                typicalHeight: Number(data.typicalDisplayHeight) || 10,
                localBounds: readBounds(data),
                levels: new Map(),
                level: null
            };
            batches.set(batch.key, batch);
        }
        batch.levels.set(data.vegetationLod, object);
    });
    for (const batch of batches.values()) {
        batch.available = new Set(batch.levels.keys());
        if (HIDE_AT_FAR.has(batch.category) && !batch.available.has('FAR') && batch.available.size > 1) {
            batch.available.add('HIDDEN');
        }
    }
    return batches;
}

export function createVegetationLodController(model, { enabled = true, thresholds = DEFAULT_TREE_LOD_THRESHOLDS } = {}) {
    const batches = collectTreeBatches(model);
    const worldBox = new THREE.Box3();
    const scale = new THREE.Vector3();
    const cameraPosition = new THREE.Vector3();
    const scratchPosition = new THREE.Vector3();
    const scratchRotation = new THREE.Quaternion();

    function show(batch, level) {
        batch.level = level;
        for (const [name, object] of batch.levels) {
            object.visible = name === level;
        }
    }

    // Finest level first: one representation per batch from the start.
    const finest = (batch) => TREE_LEVELS.find((name) => batch.levels.has(name));
    for (const batch of batches.values()) {
        show(batch, finest(batch));
    }

    function update(camera, viewportHeight) {
        if (!enabled || !camera) {
            return;
        }
        camera.getWorldPosition(cameraPosition);
        for (const batch of batches.values()) {
            const reference = batch.levels.get(finest(batch));
            const parent = reference.parent;
            let distance;
            let height = batch.typicalHeight;
            if (parent) {
                // Vertical exaggeration scales the model, and the trees with it.
                parent.matrixWorld.decompose(scratchPosition, scratchRotation, scale);
                height *= Math.abs(scale.y);
            }
            if (batch.localBounds) {
                worldBox.copy(batch.localBounds);
                if (parent) {
                    worldBox.applyMatrix4(parent.matrixWorld);
                }
                distance = worldBox.distanceToPoint(cameraPosition);
            } else {
                distance = reference.getWorldPosition(scratchPosition).distanceTo(cameraPosition);
            }
            const pixels = projectedPixels(height, distance, camera, viewportHeight);
            const level = chooseTreeLevel(pixels, batch.level, batch.available, thresholds);
            if (level !== batch.level) {
                show(batch, level);
            }
        }
    }

    function setEnabled(value) {
        enabled = Boolean(value);
        if (!enabled) {
            for (const batch of batches.values()) {
                show(batch, finest(batch));
            }
        }
    }

    function stats() {
        const counts = { NEAR: 0, MEDIUM: 0, FAR: 0, HIDDEN: 0 };
        for (const batch of batches.values()) {
            counts[batch.level] += 1;
        }
        return { batches: batches.size, levels: counts };
    }

    return { batches, update, setEnabled, stats };
}
