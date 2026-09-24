// ============================================================
// DEPTHWIZARD
// TERRAIN CLICK + HEIGHT INSPECTION
// ============================================================

import * as THREE from 'three';

import {
    camera,
    renderer
} from '../viewer/scene.js';

import {
    state
} from '../core/state.js';

import {
    dom
} from '../core/dom.js';

import {
    fetchSingleHeight
} from '../services/height.js';

import {
    setViewerStatus
} from '../ui/status.js';

import {
    openCompareModal
} from '../ui/compareUI.js';

import {
    worldToRasterCoordinates
} from '../viewer/terrain.js';

import {
    isMeasurementActive
} from './measurement.js';

const raycaster = new THREE.Raycaster();
const mouse = new THREE.Vector2();

let heightCard = null;
let currentInspectedPoint = null;

function createHeightCard() {

    if (heightCard) {
        return heightCard;
    }

    heightCard = document.createElement('div');

    heightCard.id = 'terrain-height-card';

    heightCard.innerHTML = `
        <div class="height-card-header">
            <span>Terrain Height</span>
            <button
                id="height-card-close"
                type="button"
                title="Close"
            >
                ×
            </button>
        </div>

        <div class="height-card-body">

            <div class="height-card-label">
                ESTIMATED HEIGHT
            </div>

            <div
                id="terrain-height-value"
                class="height-card-value"
            >
                Loading...
            </div>

            <div
                id="terrain-height-position"
                class="height-card-position"
            >
                --
            </div>

            <div class="height-card-actions">
                <button
                    id="height-card-compare-btn"
                    class="height-card-action-btn"
                    type="button"
                >
                    Compare Elevation
                </button>
            </div>

        </div>
    `;

    document.body.appendChild(heightCard);

    const closeButton =
        document.getElementById('height-card-close');

    closeButton?.addEventListener(
        'click',
        hideHeightCard
    );

    const compareButton =
        document.getElementById('height-card-compare-btn');

    compareButton?.addEventListener('click', () => {
        hideHeightCard();
        if (currentInspectedPoint) {
            openCompareModal({
                x: currentInspectedPoint.x,
                y: currentInspectedPoint.y
            });
        } else {
            openCompareModal();
        }
    });

    return heightCard;
}

function showHeightCard(
    height,
    x,
    y,
    screenX,
    screenY,
    statusText = null
) {

    const card =
        createHeightCard();

    currentInspectedPoint = { x, y };

    const value =
        document.getElementById('terrain-height-value');

    const position =
        document.getElementById('terrain-height-position');

    const compareBtn =
        document.getElementById('height-card-compare-btn');

    if (value) {
        value.textContent = formatHeight(height);
    }

    if (position) {
        position.textContent =
            `X: ${Number(x).toFixed(2)}   Y: ${Number(y).toFixed(2)}`;
    }

    if (compareBtn) {
        const metricAvailable = state.metricMode === 'metric';
        compareBtn.textContent = metricAvailable ? 'Compare Elevation' : 'Metric Compare Locked';
        compareBtn.disabled = !metricAvailable;
    }

    // Keep card on screen bounds
    const safeLeft = Math.min(screenX + 16, window.innerWidth - 240);
    const safeTop = Math.min(screenY + 16, window.innerHeight - 200);

    card.style.left = `${Math.max(10, safeLeft)}px`;
    card.style.top = `${Math.max(10, safeTop)}px`;

    card.classList.add('visible');
}

function formatHeight(height) {

    if (
        height === null ||
        height === undefined ||
        height === ''
    ) {
        return '--';
    }

    const numeric =
        Number(height);

    if (!Number.isFinite(numeric)) {
        return String(height);
    }

    return `${numeric.toFixed(2)} m`;
}

export function hideHeightCard() {

    if (!heightCard) {
        return;
    }

    heightCard.classList.remove('visible');
}

function getHeightFromResponse(result) {
    if (!result || typeof result !== 'object') {
        return result;
    }

    const candidates = [
        result.elevation_meters,
        result.original_height_meters,
        result.height,
        result.actual_height,
        result.elevation,
        result.data?.elevation_meters,
        result.data?.original_height_meters,
        result.data?.height,
        result.data?.actual_height,
        result.data?.elevation,
        result.result?.elevation_meters,
        result.result?.original_height_meters,
        result.result?.height,
        result.result?.actual_height,
        result.value
    ];

    // Check for positive non-zero value first
    for (const val of candidates) {
        if (val !== null && val !== undefined && Number.isFinite(Number(val)) && Number(val) > 0) {
            return Number(val);
        }
    }

    // Fall back to any finite number (e.g. 0)
    for (const val of candidates) {
        if (val !== null && val !== undefined && Number.isFinite(Number(val))) {
            return Number(val);
        }
    }

    return null;
}


async function handleTerrainClick(event) {

    if (!state.terrainModel) {
        return;
    }

    // Don't interfere with route drawing
    if (state.isDrawingRoute || isMeasurementActive()) {
        return;
    }

    // Absolute metric probing is intentionally locked for dimensionless input.
    if (state.metricMode !== 'metric') {
        const rect = renderer.domElement.getBoundingClientRect();
        const messageX = Math.min(event.clientX + 14, window.innerWidth - 300);
        const messageY = Math.min(event.clientY + 14, window.innerHeight - 150);

        showHeightCard(
            'Relative only',
            0,
            0,
            messageX,
            messageY,
            'Upload a metric GeoTIFF to enable absolute height probing.'
        );
        return;
    }

    const rect =
        renderer.domElement.getBoundingClientRect();

    mouse.x =
        ((event.clientX - rect.left) /
            rect.width) * 2 - 1;

    mouse.y =
        -((event.clientY - rect.top) /
            rect.height) * 2 + 1;

    raycaster.setFromCamera(
        mouse,
        camera
    );

    const intersections =
        raycaster.intersectObject(
            state.terrainModel,
            true
        );

    if (!intersections.length) {
        return;
    }

    const point =
        intersections[0].point;

    /*
     * Terrain coordinates:
     * Convert Three.js 3D world space (where terrain is centered at origin)
     * into uncentered positive raster coordinates [0, width] and [0, depth]
     * expected by backend height and compare APIs.
     */
    const { x: apiX, y: apiY, meshHeight } =
        worldToRasterCoordinates(point);

    const correctedMeshHeight =
        Number(meshHeight) / Math.max(state.verticalExaggeration || 1, 0.0001);

    state.lastClickedPoint = {
        x: apiX,
        y: apiY,
        meshElevation: correctedMeshHeight
    };

    // If no active UUID is set yet, show prompt on card
    if (!state.currentUuid) {
        showHeightCard(
            correctedMeshHeight, // Mesh surface height as fallback
            apiX,
            apiY,
            event.clientX,
            event.clientY,
            'Upload image to query backend height'
        );
        return;
    }

    showHeightCard(
        'Loading...',
        apiX,
        apiY,
        event.clientX,
        event.clientY
    );

    try {

        setViewerStatus(
            'FETCHING ACTUAL HEIGHT',
            'loading'
        );

        const result =
            await fetchSingleHeight({
                uuid: state.currentUuid,
                x: apiX,
                y: apiY
            });

        let height =
            getHeightFromResponse(result);

        // Fallback to mesh surface height if backend returned 0 or null
        if ((height === null || height === 0) && Number.isFinite(correctedMeshHeight) && correctedMeshHeight !== 0) {
            height = correctedMeshHeight;
        }

        showHeightCard(
            height,
            apiX,
            apiY,
            event.clientX,
            event.clientY
        );

        setViewerStatus(
            '3D VIEWER READY',
            'ready'
        );

    } catch (error) {

        console.error(
            'Actual height request failed:',
            error
        );

        // Fallback to mesh surface height if available
        const fallbackHeight = (Number.isFinite(correctedMeshHeight) && correctedMeshHeight !== 0) ? correctedMeshHeight : 'Unavailable';

        showHeightCard(
            fallbackHeight,
            apiX,
            apiY,
            event.clientX,
            event.clientY,
            error.message || 'Fetch failed'
        );

        setViewerStatus(
            'HEIGHT FETCH FAILED',
            'error'
        );
    }
}

export function initHeightInspection() {

    if (!renderer?.domElement) {
        return;
    }

    renderer.domElement.addEventListener(
        'click',
        handleTerrainClick
    );
}
