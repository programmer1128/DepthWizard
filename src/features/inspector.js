// ============================================================
// DEPTHWIZARD
// REAL-TIME TERRAIN INSPECTOR
// ============================================================

import * as THREE from 'three';

import {
    camera,
    renderer
} from '../viewer/scene.js';

import { dom } from '../core/dom.js';
import { state } from '../core/state.js';

const raycaster = new THREE.Raycaster();
const pointer = new THREE.Vector2();

function updatePointer(event) {
    const rect = renderer.domElement.getBoundingClientRect();
    pointer.x = ((event.clientX - rect.left) / rect.width) * 2 - 1;
    pointer.y = -((event.clientY - rect.top) / rect.height) * 2 + 1;
}

function inspectTerrain(event) {
    if (!state.terrainModel) return;

    updatePointer(event);
    raycaster.setFromCamera(pointer, camera);

    const intersections = raycaster.intersectObject(state.terrainModel, true);
    if (!intersections.length) return;

    const point = intersections[0].point.clone();
    displayCoordinates(point);
}

function displayCoordinates(point) {
    const exaggeration = Math.max(state.verticalExaggeration || 1, 0.0001);
    const trueHeight = point.y / exaggeration;
    const unit = state.metricMode === 'metric' ? 'm' : 'rel.';

    if (dom.inspectorContent) {
        dom.inspectorContent.innerHTML = `
            <div class="inspector-row"><span>X</span><strong>${point.x.toFixed(2)}</strong></div>
            <div class="inspector-row"><span>Y</span><strong>${point.y.toFixed(2)}</strong></div>
            <div class="inspector-row"><span>Z</span><strong>${point.z.toFixed(2)}</strong></div>
        `;
    }

    if (dom.coordinates) {
        dom.coordinates.textContent =
            `X ${point.x.toFixed(2)}  •  Y ${trueHeight.toFixed(2)} ${unit}  •  Z ${point.z.toFixed(2)}`;
    }

    if (dom.inspectorMode) {
        dom.inspectorMode.textContent = state.metricMode === 'metric' ? 'METRIC' : 'RELATIVE';
        dom.inspectorMode.className = `mini-data-badge ${state.metricMode}`;
    }

    if (dom.inspectorValue) {
        dom.inspectorValue.textContent = `${trueHeight.toFixed(2)} ${unit}`;
    }

    if (dom.inspectorCoords) {
        dom.inspectorCoords.textContent = `X ${point.x.toFixed(2)}  •  Z ${point.z.toFixed(2)}`;
    }

    if (dom.inspectorNote) {
        dom.inspectorNote.textContent = state.metricMode === 'metric'
            ? `Corrected for ${exaggeration.toFixed(2)}× visual Y scaling.`
            : 'Relative surface value only • absolute metre interpretation locked.';
    }
}

export function clearInspector() {
    if (dom.inspectorContent) {
        dom.inspectorContent.innerHTML = '<div class="empty-inspector">No point selected</div>';
    }

    if (dom.coordinates) {
        dom.coordinates.textContent = 'X: —  Y: —  Z: —';
    }

    if (dom.inspectorValue) dom.inspectorValue.textContent = '—';
    if (dom.inspectorCoords) dom.inspectorCoords.textContent = 'Double-click terrain to inspect';
}

export function initInspector() {
    renderer.domElement.addEventListener('dblclick', inspectTerrain);
    clearInspector();
}
