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
    fetchActualHeight
} from '../services/height.js';

import {
    setViewerStatus
} from '../ui/status.js';

const raycaster = new THREE.Raycaster();
const mouse = new THREE.Vector2();

let heightCard = null;

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
            >
                ×
            </button>
        </div>

        <div class="height-card-body">

            <div class="height-card-label">
                HEIGHT
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

        </div>
    `;

    document.body.appendChild(heightCard);

    const closeButton =
        document.getElementById(
            'height-card-close'
        );

    closeButton?.addEventListener(
        'click',
        hideHeightCard
    );

    return heightCard;
}

function showHeightCard(
    height,
    x,
    y,
    screenX,
    screenY
) {

    const card =
        createHeightCard();

    const value =
        document.getElementById(
            'terrain-height-value'
        );

    const position =
        document.getElementById(
            'terrain-height-position'
        );

    value.textContent =
        formatHeight(height);

    position.textContent =
        `X: ${Number(x).toFixed(2)}   Y: ${Number(y).toFixed(2)}`;

    card.style.left =
        `${screenX + 16}px`;

    card.style.top =
        `${screenY + 16}px`;

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

    heightCard.classList.remove(
        'visible'
    );
}

function getHeightFromResponse(result) {

    return (
        result.height ??
        result.actual_height ??
        result.data?.height ??
        result.data?.actual_height ??
        result.result?.height ??
        result.result?.actual_height
    );
}

async function handleTerrainClick(event) {

    if (!state.terrainModel) {
        return;
    }

    if (state.isDrawingRoute) {
        return;
    }

    // Don't interfere with route drawing.
    if (state.isDrawingRoute) {
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
     *
     * Three.js:
     *   X = horizontal
     *   Y = elevation
     *   Z = depth
     *
     * The backend API expects X and Y.
     * For now we map:
     *
     * API X = Three.js X
     * API Y = Three.js Z
     *
     * If the backend uses another coordinate
     * system, ONLY this mapping needs changing.
     */

    const apiX =
        point.x;

    const apiY =
        point.z;

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
            await fetchActualHeight(
                apiX,
                apiY
            );

        const height =
            getHeightFromResponse(
                result
            );

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

        showHeightCard(
            'Unavailable',
            apiX,
            apiY,
            event.clientX,
            event.clientY
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