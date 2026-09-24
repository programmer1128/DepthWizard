// ============================================================
// DEPTHWIZARD
// DE-EXAGGERATED TRUE METRIC MEASUREMENT
// ============================================================

import * as THREE from 'three';

import {
    camera,
    renderer,
    scene
} from '../viewer/scene.js';

import { state } from '../core/state.js';
import { dom } from '../core/dom.js';
import { orbitControls, flyControls } from '../controls/navigation.js';

const raycaster = new THREE.Raycaster();
const pointer = new THREE.Vector2();

let active = false;
let firstPoint = null;
let measurementLine = null;
let previousOrbitEnabled = true;

const measurementMaterial = new THREE.LineBasicMaterial({
    color: 0x7ee7ff,
    depthTest: false,
    depthWrite: false,
    transparent: true,
    opacity: 0.95
});

function updatePointer(event) {
    const rect = renderer.domElement.getBoundingClientRect();
    pointer.x = ((event.clientX - rect.left) / rect.width) * 2 - 1;
    pointer.y = -((event.clientY - rect.top) / rect.height) * 2 + 1;
}

function getTerrainPoint(event) {
    if (!state.terrainModel) return null;

    updatePointer(event);
    raycaster.setFromCamera(pointer, camera);

    const intersections = raycaster.intersectObject(state.terrainModel, true);
    if (!intersections.length) return null;

    return intersections[0].point.clone();
}

function updateMeasurementLine(pointA, pointB) {
    const positions = new Float32Array([
        pointA.x, pointA.y, pointA.z,
        pointB.x, pointB.y, pointB.z
    ]);

    if (!measurementLine) {
        const geometry = new THREE.BufferGeometry();
        geometry.setAttribute('position', new THREE.BufferAttribute(positions, 3));
        measurementLine = new THREE.Line(geometry, measurementMaterial);
        measurementLine.renderOrder = 6;
        scene.add(measurementLine);
    } else {
        measurementLine.geometry.setAttribute(
            'position',
            new THREE.BufferAttribute(positions, 3)
        );
        measurementLine.geometry.computeBoundingSphere();
    }
}

function clearMeasurementLine() {
    if (!measurementLine) return;

    scene.remove(measurementLine);
    measurementLine.geometry.dispose();
    measurementLine = null;
}

function showMeasurementReadout(data) {
    if (!dom.measurementReadout) return;

    dom.measurementReadout.innerHTML = `
        <div class="measurement-readout-head">
            <span>TRUE METRIC MEASUREMENT</span>
            <span class="metric-chip">${state.verticalExaggeration.toFixed(2)}× corrected</span>
        </div>
        <div class="measurement-readout-grid">
            <div><span>Ground distance</span><strong>${data.horizontal.toFixed(2)} m</strong></div>
            <div><span>Height delta</span><strong>${data.heightDelta.toFixed(2)} m</strong></div>
            <div><span>3D distance</span><strong>${data.distance3D.toFixed(2)} m</strong></div>
            <div><span>Physical slope</span><strong>${data.slope.toFixed(2)}°</strong></div>
        </div>
    `;
    dom.measurementReadout.classList.add('visible');
}

function hideMeasurementReadout() {
    dom.measurementReadout?.classList.remove('visible');
}

function handleMeasurementClick(event) {
    if (!active) return;

    if (state.metricMode !== 'metric') {
        if (dom.coordinates) {
            dom.coordinates.textContent = 'Metric measurement locked — upload a metric GeoTIFF.';
        }
        return;
    }

    const point = getTerrainPoint(event);
    if (!point) return;

    if (!firstPoint) {
        firstPoint = point;

        if (dom.coordinates) {
            dom.coordinates.textContent =
                `Point 1 • X ${point.x.toFixed(2)}  Y ${point.y.toFixed(2)}  Z ${point.z.toFixed(2)}`;
        }
        return;
    }

    const secondPoint = point;
    updateMeasurementLine(firstPoint, secondPoint);

    const visualVertical = secondPoint.y - firstPoint.y;
    const trueVertical = visualVertical / Math.max(state.verticalExaggeration || 1, 0.0001);

    const horizontal = Math.hypot(
        secondPoint.x - firstPoint.x,
        secondPoint.z - firstPoint.z
    );

    const distance3D = Math.hypot(horizontal, trueVertical);
    const slope = horizontal > 0
        ? Math.atan2(Math.abs(trueVertical), horizontal) * 180 / Math.PI
        : 90;

    const data = {
        horizontal,
        heightDelta: Math.abs(trueVertical),
        signedHeightDelta: trueVertical,
        distance3D,
        slope
    };

    state.lastMeasurement = {
        pointA: firstPoint.clone(),
        pointB: secondPoint.clone(),
        ...data
    };

    if (dom.coordinates) {
        dom.coordinates.textContent =
            `Ground ${horizontal.toFixed(2)} m • ΔH ${Math.abs(trueVertical).toFixed(2)} m • Slope ${slope.toFixed(2)}°`;
    }

    showMeasurementReadout(data);
    firstPoint = null;
}

export function startMeasurement() {
    if (state.metricMode !== 'metric') {
        if (dom.coordinates) {
            dom.coordinates.textContent = 'Metric measurement locked — upload a metric GeoTIFF.';
        }
        return;
    }

    active = true;
    firstPoint = null;
    previousOrbitEnabled = orbitControls.enabled;
    orbitControls.autoRotate = false;
    orbitControls.enabled = false;
    flyControls.enabled = false;

    dom.measureBtn?.classList.add('active');
    if (dom.coordinates) {
        dom.coordinates.textContent = 'Measurement active — click two points on the terrain.';
    }
}

export function stopMeasurement() {
    active = false;
    firstPoint = null;
    orbitControls.enabled = previousOrbitEnabled;
    flyControls.enabled = state.flyMode;
    orbitControls.autoRotate = state.autoRotateEnabled && !state.flyMode && !state.isFlyingRoute;
    dom.measureBtn?.classList.remove('active');
}

export function toggleMeasurement() {
    if (active) {
        stopMeasurement();
    } else {
        startMeasurement();
    }
}

export function isMeasurementActive() {
    return active;
}

export function initMeasurement() {
    renderer.domElement.addEventListener('click', handleMeasurementClick);
    hideMeasurementReadout();
}

export function clearMeasurement() {
    stopMeasurement();
    clearMeasurementLine();
    hideMeasurementReadout();
}
