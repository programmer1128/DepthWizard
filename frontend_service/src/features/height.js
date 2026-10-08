// ============================================================
// DEPTHWIZARD
// TERRAIN CLICK + HEIGHT INSPECTION
// ============================================================

import { intersectScientific } from '../viewer/vegetation.js';
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
            <span id="height-card-title">Terrain Height</span>
            <button
                id="height-card-close"
                type="button"
                title="Close"
            >
                ×
            </button>
        </div>

        <div class="height-card-body">

            <div id="height-card-label" class="height-card-label">
                ESTIMATED HEIGHT
            </div>

            <div
                id="terrain-height-value"
                class="height-card-value"
            >
                Loading...
            </div>

            <div
                id="terrain-height-details"
                class="height-card-details"
            ></div>

            <div
                id="terrain-height-position"
                class="height-card-position"
            >
                --
            </div>

            <div
                id="terrain-height-note"
                class="height-card-note"
            ></div>

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

    document.getElementById('height-card-close')
        ?.addEventListener('click', hideHeightCard);

    document.getElementById('height-card-compare-btn')
        ?.addEventListener('click', () => {
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

/**
 * view: { title, label, value, details, note }
 * value may be a number (metres) or text.
 */
function showHeightCard(view, x, y, screenX, screenY) {

    const card = createHeightCard();

    currentInspectedPoint = { x, y };

    const setText = (id, text) => {
        const element = document.getElementById(id);
        if (element) {
            element.textContent = text ?? '';
            element.style.display = text ? '' : 'none';
        }
    };

    setText('height-card-title', view.title || 'Terrain Height');
    setText('height-card-label', view.label || 'ESTIMATED HEIGHT');
    setText('terrain-height-value', formatHeight(view.value));
    setText('terrain-height-details', view.details || '');
    setText('terrain-height-position', `X: ${Number(x).toFixed(2)} m   Y: ${Number(y).toFixed(2)} m`);
    setText('terrain-height-note', view.note || '');

    const compareBtn = document.getElementById('height-card-compare-btn');
    if (compareBtn) {
        const metricAvailable = state.metricMode === 'metric';
        compareBtn.textContent = metricAvailable ? 'Compare Elevation' : 'Metric Compare Locked';
        compareBtn.disabled = !metricAvailable;
    }

    // Keep card on screen bounds
    const safeLeft = Math.min(screenX + 16, window.innerWidth - 260);
    const safeTop = Math.min(screenY + 16, window.innerHeight - 240);

    card.style.left = `${Math.max(10, safeLeft)}px`;
    card.style.top = `${Math.max(10, safeTop)}px`;

    card.classList.add('visible');
}

function formatHeight(height) {

    if (height === null || height === undefined || height === '') {
        return '--';
    }

    const numeric = Number(height);

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

function finite(value) {
    return value !== null && value !== undefined && Number.isFinite(Number(value));
}

// Building roofs and walls carry the backend building ID per vertex in the
// GLB's _FEATURE_ID_0 attribute (Three.js lower-cases custom names).
function featureIdAt(hit) {
    const attributes = hit.object?.geometry?.attributes;
    const ids = attributes?._feature_id_0 || attributes?._FEATURE_ID_0;
    if (!ids || !hit.face) {
        return null;
    }
    const id = Math.round(ids.getX(hit.face.a));
    return id >= 1 ? id : null;
}

// Turn the backend answer into what the card shows: a building shows only
// that building's height; terrain shows the absolute elevation there.
function viewFromResponse(result) {

    if (result?.kind === 'building' && finite(result.building_height_meters)) {
        const details = [];
        if (finite(result.roof_elevation_meters)) {
            details.push(`Roof ${Number(result.roof_elevation_meters).toFixed(2)} m`);
        }
        if (finite(result.base_elevation_meters)) {
            details.push(`Ground ${Number(result.base_elevation_meters).toFixed(2)} m (absolute)`);
        }
        const scale = Number(result.render_height_scale);
        return {
            title: `Building #${result.building_id}`,
            label: 'BUILDING HEIGHT ABOVE GROUND',
            value: Number(result.building_height_meters),
            details: details.join(' · '),
            note: Number.isFinite(scale) && scale !== 1
                ? `Drawn ×${scale.toFixed(2)} taller in 3D for visibility`
                : ''
        };
    }

    const elevation = finite(result?.elevation_meters)
        ? Number(result.elevation_meters)
        : null;
    const details = finite(result?.height_above_ground_meters) &&
        Math.abs(Number(result.height_above_ground_meters)) >= 0.05
        ? `${Number(result.height_above_ground_meters).toFixed(2)} m above bare ground`
        : '';
    return {
        title: 'Terrain',
        label: 'TERRAIN ELEVATION (ABSOLUTE)',
        value: elevation,
        details,
        note: ''
    };
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
        const messageX = Math.min(event.clientX + 14, window.innerWidth - 300);
        const messageY = Math.min(event.clientY + 14, window.innerHeight - 150);

        showHeightCard({
            title: 'Terrain Height',
            value: 'Relative only',
            note: 'Upload a metric GeoTIFF to enable absolute height probing.'
        }, 0, 0, messageX, messageY);
        return;
    }

    const rect = renderer.domElement.getBoundingClientRect();

    mouse.x = ((event.clientX - rect.left) / rect.width) * 2 - 1;
    mouse.y = -((event.clientY - rect.top) / rect.height) * 2 + 1;

    raycaster.setFromCamera(mouse, camera);

    // Only solid surfaces: the white building outlines are line primitives
    // and would otherwise intercept clicks near every edge.
    const hit = intersectScientific(raycaster, state.terrainModel)
        .find((intersection) => intersection.object?.isMesh);

    if (!hit) {
        return;
    }

    /*
     * Terrain coordinates:
     * Convert Three.js 3D world space (where terrain is centered at origin)
     * into metres east/south of the terrain's north-west corner, which the
     * backend height and compare APIs expect.
     */
    const { x: apiX, y: apiY, meshHeight } = worldToRasterCoordinates(hit.point);
    const featureId = featureIdAt(hit);

    const correctedMeshHeight =
        Number(meshHeight) / Math.max(state.verticalExaggeration || 1, 0.0001);

    state.lastClickedPoint = {
        x: apiX,
        y: apiY,
        featureId,
        meshElevation: correctedMeshHeight
    };

    if (!state.currentUuid) {
        showHeightCard({
            title: featureId ? 'Building' : 'Terrain',
            value: '--',
            note: 'Upload an image to query heights from the backend.'
        }, apiX, apiY, event.clientX, event.clientY);
        return;
    }

    showHeightCard({
        title: featureId ? 'Building' : 'Terrain',
        value: 'Loading...'
    }, apiX, apiY, event.clientX, event.clientY);

    try {

        setViewerStatus('FETCHING ACTUAL HEIGHT', 'loading');

        const result = await fetchSingleHeight({
            uuid: state.currentUuid,
            x: apiX,
            y: apiY,
            featureId
        });

        showHeightCard(viewFromResponse(result), apiX, apiY, event.clientX, event.clientY);

        setViewerStatus('3D VIEWER READY', 'ready');

    } catch (error) {

        console.error('Actual height request failed:', error);

        // No mesh-height fallback: in the flat urban view the mesh Y is not
        // an elevation, so a guessed number would be wrong.
        showHeightCard({
            title: featureId ? 'Building' : 'Terrain',
            value: 'Unavailable',
            note: error.message || 'Height request failed.'
        }, apiX, apiY, event.clientX, event.clientY);

        setViewerStatus('HEIGHT FETCH FAILED', 'error');
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
