// ============================================================
// DEPTHWIZARD
// HYDROLOGICALLY SEEDED FLOOD SIMULATOR
// ============================================================

import * as THREE from 'three';

import { scene, camera, renderer } from '../viewer/scene.js';
import { dom } from '../core/dom.js';
import { state } from '../core/state.js';

const raycaster = new THREE.Raycaster();
const pointer = new THREE.Vector2();

let seededMode = false;
let terrainSample = null;
let initialized = false;
let samplingInProgress = false;
let samplingToken = 0;
let floodRenderFrame = 0;

function clamp(value, min, max) {
    return Math.max(min, Math.min(max, value));
}

function formatLevel(value) {
    const unit = state.metricMode === 'metric' ? ' m' : ' rel.';
    return `${Number(value).toFixed(1)}${unit}`;
}

function setFloodStatus(text, type = '') {
    if (dom.floodStatus) {
        dom.floodStatus.textContent = text;
        dom.floodStatus.dataset.state = type;
    }
}

function clearWaterMesh() {
    if (!state.floodWaterMesh) return;

    scene.remove(state.floodWaterMesh);

    state.floodWaterMesh.geometry?.dispose();
    state.floodWaterMesh.material?.dispose();
    state.floodWaterMesh = null;
}

function getTerrainIntersection(event) {
    if (!state.terrainModel) return null;

    const rect = renderer.domElement.getBoundingClientRect();
    pointer.x = ((event.clientX - rect.left) / rect.width) * 2 - 1;
    pointer.y = -((event.clientY - rect.top) / rect.height) * 2 + 1;

    raycaster.setFromCamera(pointer, camera);
    const hits = raycaster.intersectObject(state.terrainModel, true);

    return hits.length ? hits[0].point.clone() : null;
}

async function sampleTerrainGrid(resolution = 28) {
    if (!state.terrainModel) return null;

    const token = samplingToken;
    state.terrainModel.updateMatrixWorld(true);

    const box = new THREE.Box3().setFromObject(state.terrainModel);
    const minX = box.min.x;
    const maxX = box.max.x;
    const minZ = box.min.z;
    const maxZ = box.max.z;
    const size = box.getSize(new THREE.Vector3());
    const maxY = box.max.y + Math.max(10, size.y + 4);

    const width = Math.max(maxX - minX, 0.001);
    const depth = Math.max(maxZ - minZ, 0.001);
    const cellW = width / resolution;
    const cellD = depth / resolution;

    const heights = new Float32Array(resolution * resolution);
    heights.fill(NaN);

    const down = new THREE.Vector3(0, -1, 0);
    const origin = new THREE.Vector3();
    const totalCells = resolution * resolution;

    // Raycasting every cell synchronously can freeze the browser for complex GLBs.
    // Sample in small chunks and yield to the browser between chunks so the UI stays responsive.
    const chunkSize = 32;
    for (let start = 0; start < totalCells; start += chunkSize) {
        if (token !== samplingToken) return null;

        const end = Math.min(start + chunkSize, totalCells);
        for (let index = start; index < end; index++) {
            const row = Math.floor(index / resolution);
            const col = index % resolution;
            const x = minX + (col + 0.5) * cellW;
            const z = minZ + (row + 0.5) * cellD;

            origin.set(x, maxY, z);
            raycaster.set(origin, down);

            const hits = raycaster.intersectObject(state.terrainModel, true);
            if (hits.length) {
                heights[index] = hits[0].point.y;
            }
        }

        await new Promise((resolve) => requestAnimationFrame(resolve));
    }

    let minY = Infinity;
    let maxTerrainY = -Infinity;

    for (const value of heights) {
        if (!Number.isFinite(value)) continue;
        minY = Math.min(minY, value);
        maxTerrainY = Math.max(maxTerrainY, value);
    }

    if (!Number.isFinite(minY) || !Number.isFinite(maxTerrainY)) {
        return null;
    }

    return {
        resolution,
        minX,
        minZ,
        width,
        depth,
        cellW,
        cellD,
        heights,
        minY,
        maxY: maxTerrainY
    };
}

function nearestGridCell(point) {
    if (!terrainSample) return null;

    const col = clamp(
        Math.floor((point.x - terrainSample.minX) / terrainSample.cellW),
        0,
        terrainSample.resolution - 1
    );

    const row = clamp(
        Math.floor((point.z - terrainSample.minZ) / terrainSample.cellD),
        0,
        terrainSample.resolution - 1
    );

    const index = row * terrainSample.resolution + col;

    return {
        row,
        col,
        index
    };
}

function buildFloodMask(waterLevel) {
    if (!terrainSample || !state.floodSeedCell) return null;

    const { resolution, heights } = terrainSample;
    const visited = new Uint8Array(resolution * resolution);
    const flooded = new Uint8Array(resolution * resolution);
    const queue = [];
    let queueHead = 0;

    const seed = state.floodSeedCell.index;

    if (!Number.isFinite(heights[seed]) || heights[seed] > waterLevel) {
        return flooded;
    }

    queue.push(seed);
    visited[seed] = 1;

    while (queueHead < queue.length) {
        const current = queue[queueHead++];
        flooded[current] = 1;

        const row = Math.floor(current / resolution);
        const col = current % resolution;

        const neighbors = [
            [row - 1, col],
            [row + 1, col],
            [row, col - 1],
            [row, col + 1]
        ];

        for (const [nr, nc] of neighbors) {
            if (nr < 0 || nr >= resolution || nc < 0 || nc >= resolution) continue;

            const next = nr * resolution + nc;
            if (visited[next]) continue;
            visited[next] = 1;

            if (Number.isFinite(heights[next]) && heights[next] <= waterLevel) {
                queue.push(next);
            }
        }
    }

    return flooded;
}

function renderFlood(waterLevel) {
    clearWaterMesh();

    if (!terrainSample || !state.floodSeedCell) return;

    const flooded = buildFloodMask(waterLevel);
    if (!flooded) return;

    const positions = [];
    const indices = [];
    let vertexIndex = 0;
    let floodedCount = 0;

    for (let row = 0; row < terrainSample.resolution; row++) {
        for (let col = 0; col < terrainSample.resolution; col++) {
            const index = row * terrainSample.resolution + col;
            if (!flooded[index]) continue;

            floodedCount++;

            const x0 = terrainSample.minX + col * terrainSample.cellW;
            const x1 = x0 + terrainSample.cellW;
            const z0 = terrainSample.minZ + row * terrainSample.cellD;
            const z1 = z0 + terrainSample.cellD;
            const y = waterLevel + 0.18;

            positions.push(
                x0, y, z0,
                x1, y, z0,
                x1, y, z1,
                x0, y, z1
            );

            indices.push(
                vertexIndex, vertexIndex + 1, vertexIndex + 2,
                vertexIndex, vertexIndex + 2, vertexIndex + 3
            );

            vertexIndex += 4;
        }
    }

    if (!floodedCount) {
        setFloodStatus('Seed is above the selected water level. Raise the level to begin filling.');
        return;
    }

    const geometry = new THREE.BufferGeometry();
    geometry.setAttribute(
        'position',
        new THREE.Float32BufferAttribute(positions, 3)
    );
    geometry.setIndex(indices);
    geometry.computeVertexNormals();

    const material = new THREE.MeshStandardMaterial({
        color: 0x32b9ff,
        transparent: true,
        opacity: 0.36,
        roughness: 0.18,
        metalness: 0.02,
        depthWrite: false,
        side: THREE.DoubleSide
    });

    const mesh = new THREE.Mesh(geometry, material);
    mesh.renderOrder = 4;
    state.floodWaterMesh = mesh;
    scene.add(mesh);

    const coverage = (floodedCount / flooded.length) * 100;
    setFloodStatus(`${floodedCount.toLocaleString()} connected cells • ${coverage.toFixed(1)}% sampled area`);
}

function updateFloodSliderLabel() {
    if (!dom.floodLevelSlider || !terrainSample) return;

    const t = Number(dom.floodLevelSlider.value) / 100;
    const level = terrainSample.minY + t * (terrainSample.maxY - terrainSample.minY);

    if (dom.floodLevelValue) {
        dom.floodLevelValue.textContent = formatLevel(level);
    }

    state.floodWaterLevel = level;

    // Avoid rebuilding the flood mesh for every tiny slider event.
    if (!floodRenderFrame) {
        floodRenderFrame = requestAnimationFrame(() => {
            floodRenderFrame = 0;
            renderFlood(state.floodWaterLevel);
        });
    }
}

async function handleSeedClick(event) {
    if (!seededMode || !state.terrainModel || samplingInProgress) return;

    const point = getTerrainIntersection(event);
    if (!point) return;

    event.preventDefault();
    event.stopImmediatePropagation();

    samplingInProgress = true;
    samplingToken += 1;
    const currentToken = samplingToken;

    if (dom.floodSeedBtn) {
        dom.floodSeedBtn.disabled = true;
        dom.floodSeedBtn.textContent = 'Sampling Terrain…';
    }
    setFloodStatus('Sampling terrain for connected flood analysis…');

    try {
        if (!terrainSample) {
            terrainSample = await sampleTerrainGrid(28);
        }

        if (!terrainSample || currentToken !== samplingToken) {
            setFloodStatus('Flood sampling cancelled.', 'error');
            return;
        }

        const cell = nearestGridCell(point);
        if (!cell) return;

        state.floodSeedCell = cell;
        state.floodSeedPoint = point.clone();
        seededMode = false;

        dom.floodSeedBtn?.classList.remove('active');
        dom.floodSeedBtn?.classList.remove('armed');
        if (dom.floodSeedBtn) dom.floodSeedBtn.textContent = 'Set Seed Point';

        if (dom.floodLevelSlider) {
            const seedHeight = terrainSample.heights[cell.index];
            const t = clamp(
                (seedHeight - terrainSample.minY) / Math.max(terrainSample.maxY - terrainSample.minY, 0.001),
                0,
                1
            );
            dom.floodLevelSlider.value = String(Math.max(45, Math.round(t * 100)));
        }

        updateFloodSliderLabel();
        setFloodStatus(`Seed locked • ${cell.row + 1}:${cell.col + 1}`);
    } finally {
        samplingInProgress = false;
        if (dom.floodSeedBtn) dom.floodSeedBtn.disabled = false;
        if (dom.floodSeedBtn && !seededMode) dom.floodSeedBtn.textContent = 'Set Seed Point';
    }
}

function armSeedMode() {
    if (!state.terrainModel) {
        setFloodStatus('Load a terrain before selecting a flood seed.', 'error');
        return;
    }

    seededMode = !seededMode;
    dom.floodSeedBtn?.classList.toggle('armed', seededMode);
    dom.floodSeedBtn?.classList.toggle('active', seededMode);
    if (dom.floodSeedBtn) {
        dom.floodSeedBtn.textContent = seededMode ? 'Click Terrain to Seed' : 'Set Seed Point';
    }

    if (seededMode) {
        setFloodStatus('Seed mode armed • click a riverbank, valley, or low-lying terrain cell.');
    }
}

export function clearFlood() {
    samplingToken += 1;
    samplingInProgress = false;
    if (floodRenderFrame) {
        cancelAnimationFrame(floodRenderFrame);
        floodRenderFrame = 0;
    }
    seededMode = false;
    terrainSample = null;
    state.floodSeedCell = null;
    state.floodSeedPoint = null;
    state.floodWaterLevel = null;
    clearWaterMesh();

    dom.floodSeedBtn?.classList.remove('active', 'armed');
    if (dom.floodSeedBtn) dom.floodSeedBtn.textContent = 'Set Seed Point';
    if (dom.floodStatus) dom.floodStatus.textContent = 'Select a seed point, then raise the water level.';
}

export function initFlood() {
    if (initialized) return;
    initialized = true;

    dom.floodSeedBtn?.addEventListener('click', armSeedMode);
    dom.floodResetBtn?.addEventListener('click', clearFlood);

    dom.floodLevelSlider?.addEventListener('input', () => {
        updateFloodSliderLabel();
    });

    renderer.domElement.addEventListener(
        'click',
        handleSeedClick,
        { capture: true }
    );
}

export function updateFloodForTerrain() {
    clearFlood();
}
