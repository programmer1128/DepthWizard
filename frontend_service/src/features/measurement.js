// ============================================================
// DEPTHWIZARD
// TERRAIN MEASUREMENT
// ============================================================

import * as THREE from 'three';

import {
    camera,
    renderer
} from '../viewer/scene.js';

import { state } from '../core/state.js';
import { dom } from '../core/dom.js';


// ------------------------------------------------------------
// Raycaster
// ------------------------------------------------------------

const raycaster = new THREE.Raycaster();

const pointer = new THREE.Vector2();


// ------------------------------------------------------------
// Measurement state
// ------------------------------------------------------------

let active = false;
let firstPoint = null;
let measurementLine = null;


// ------------------------------------------------------------
// Measurement material
// ------------------------------------------------------------

const measurementMaterial =
    new THREE.LineBasicMaterial({
        color: 0xffff00
    });


// ------------------------------------------------------------
// Convert mouse position to normalized coordinates
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
// Find terrain point
// ------------------------------------------------------------

function getTerrainPoint(event) {

    if (!state.terrainModel) {
        return null;
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
        return null;
    }

    return intersections[0].point.clone();
}


// ------------------------------------------------------------
// Create / update measurement line
// ------------------------------------------------------------

function updateMeasurementLine(
    pointA,
    pointB
) {

    const positions =
        new Float32Array([
            pointA.x,
            pointA.y,
            pointA.z,

            pointB.x,
            pointB.y,
            pointB.z
        ]);

    if (!measurementLine) {

        const geometry =
            new THREE.BufferGeometry();

        geometry.setAttribute(
            'position',
            new THREE.BufferAttribute(
                positions,
                3
            )
        );

        measurementLine =
            new THREE.Line(
                geometry,
                measurementMaterial
            );

        sceneAddMeasurement(
            measurementLine
        );

    } else {

        measurementLine.geometry
            .setAttribute(
                'position',
                new THREE.BufferAttribute(
                    positions,
                    3
                )
            );

        measurementLine.geometry
            .computeBoundingSphere();
    }
}


// ------------------------------------------------------------
// Add line to scene
// ------------------------------------------------------------

function sceneAddMeasurement(line) {

    // Importing scene at module level keeps the measurement
    // module independent from main.js.
    import('../viewer/scene.js')
        .then(({ scene }) => {

            scene.add(line);
        });
}


// ------------------------------------------------------------
// Remove measurement line
// ------------------------------------------------------------

function clearMeasurementLine() {

    if (!measurementLine) {
        return;
    }

    import('../viewer/scene.js')
        .then(({ scene }) => {

            scene.remove(
                measurementLine
            );

            measurementLine.geometry.dispose();
        });

    measurementLine = null;
}


// ------------------------------------------------------------
// Handle terrain click
// ------------------------------------------------------------

function handleMeasurementClick(event) {

    if (!active) {
        return;
    }

    const point =
        getTerrainPoint(event);

    if (!point) {
        return;
    }


    // --------------------------------------------------------
    // First point
    // --------------------------------------------------------

    if (!firstPoint) {

        firstPoint =
            point;

        if (dom.coordinates) {

            dom.coordinates.textContent =
                `Point 1: X ${point.x.toFixed(2)}  Y ${point.y.toFixed(2)}  Z ${point.z.toFixed(2)}`;
        }

        return;
    }


    // --------------------------------------------------------
    // Second point
    // --------------------------------------------------------

    const secondPoint =
        point;

    updateMeasurementLine(
        firstPoint,
        secondPoint
    );

    const distance =
        firstPoint.distanceTo(
            secondPoint
        );


    if (dom.coordinates) {

        dom.coordinates.textContent =
            `Distance: ${distance.toFixed(2)} m`;
    }


    // --------------------------------------------------------
    // Prepare for next measurement
    // --------------------------------------------------------

    firstPoint = null;
}


// ------------------------------------------------------------
// Start measurement
// ------------------------------------------------------------

export function startMeasurement() {

    active = true;
    firstPoint = null;

    if (dom.measureBtn) {

        dom.measureBtn.classList.add(
            'active'
        );
    }

    if (dom.coordinates) {

        dom.coordinates.textContent =
            'Measurement active — select two points';
    }
}


// ------------------------------------------------------------
// Stop measurement
// ------------------------------------------------------------

export function stopMeasurement() {

    active = false;
    firstPoint = null;

    if (dom.measureBtn) {

        dom.measureBtn.classList.remove(
            'active'
        );
    }
}


// ------------------------------------------------------------
// Toggle measurement
// ------------------------------------------------------------

export function toggleMeasurement() {

    if (active) {

        stopMeasurement();

    } else {

        startMeasurement();
    }
}


// ------------------------------------------------------------
// Check state
// ------------------------------------------------------------

export function isMeasurementActive() {

    return active;
}


// ------------------------------------------------------------
// Initialize measurement
// ------------------------------------------------------------

export function initMeasurement() {

    renderer.domElement.addEventListener(
        'click',
        handleMeasurementClick
    );
}