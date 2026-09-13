// ============================================================
// DEPTHWIZARD
// TERRAIN INSPECTOR
// ============================================================

import * as THREE from 'three';

import {
    camera,
    renderer
} from '../viewer/scene.js';

import { dom } from '../core/dom.js';
import { state } from '../core/state.js';


// ------------------------------------------------------------
// Raycaster
// ------------------------------------------------------------

const raycaster = new THREE.Raycaster();

const pointer = new THREE.Vector2();


// ------------------------------------------------------------
// Update pointer coordinates
// ------------------------------------------------------------

function updatePointer(event) {

    const rect =
        renderer.domElement.getBoundingClientRect();

    pointer.x =
        ((event.clientX - rect.left) / rect.width) * 2 - 1;

    pointer.y =
        -((event.clientY - rect.top) / rect.height) * 2 + 1;
}


// ------------------------------------------------------------
// Inspect terrain
// ------------------------------------------------------------

function inspectTerrain(event) {

    if (!state.terrainModel) {
        return;
    }

    updatePointer(event);

    raycaster.setFromCamera(
        pointer,
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

    displayCoordinates(point);
}


// ------------------------------------------------------------
// Display coordinates
// ------------------------------------------------------------

function displayCoordinates(point) {

    const x = point.x.toFixed(2);
    const y = point.y.toFixed(2);
    const z = point.z.toFixed(2);

    if (dom.inspectorContent) {

        dom.inspectorContent.innerHTML = `
            <div class="inspector-row">
                <span>X</span>
                <strong>${x}</strong>
            </div>

            <div class="inspector-row">
                <span>Y</span>
                <strong>${y}</strong>
            </div>

            <div class="inspector-row">
                <span>Z</span>
                <strong>${z}</strong>
            </div>
        `;
    }

    if (dom.coordinates) {

        dom.coordinates.textContent =
            `X: ${x}  Y: ${y}  Z: ${z}`;
    }
}


// ------------------------------------------------------------
// Clear inspector
// ------------------------------------------------------------

export function clearInspector() {

    if (dom.inspectorContent) {

        dom.inspectorContent.innerHTML =
            '<div class="empty-inspector">Double-click terrain to inspect</div>';
    }

    if (dom.coordinates) {

        dom.coordinates.textContent =
            'X: —  Y: —  Z: —';
    }
}


// ------------------------------------------------------------
// Initialize inspector
// ------------------------------------------------------------

export function initInspector() {

    renderer.domElement.addEventListener(
        'dblclick',
        inspectTerrain
    );

    clearInspector();
}