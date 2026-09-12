// ============================================================
// DEPTHWIZARD
// ROUTE DRAWING + SURFACE FOLLOWING + FLYTHROUGH
// ============================================================

import * as THREE from 'three';

import {
    scene,
    camera,
    renderer
} from '../viewer/scene.js';

import { dom } from '../core/dom.js';
import { state } from '../core/state.js';
import { CONFIG } from '../core/constants.js';

import {
    orbitControls,
    flyControls,
    setOrbitMode
} from '../controls/navigation.js';

import {
    setViewerStatus,
    setReadyStatus
} from '../ui/status.js';


// ============================================================
// RAYCASTING
// ============================================================

const raycaster = new THREE.Raycaster();

const pointer = new THREE.Vector2();


// ============================================================
// ROUTE MATERIALS
// ============================================================

const markerMaterial = new THREE.MeshStandardMaterial({
    color: 0xff3b30,
    emissive: 0xff1a12,
    emissiveIntensity: 1.2
});

const routeMaterial = new THREE.LineBasicMaterial({
    color: 0x38bdf8,
    transparent: true,
    opacity: 0.95
});


// ============================================================
// TERRAIN INTERSECTION
// ============================================================

function getTerrainIntersection(event) {

    if (!state.terrainModel) {
        return null;
    }

    const rect =
        renderer.domElement.getBoundingClientRect();

    pointer.x =
        ((event.clientX - rect.left) / rect.width) * 2 - 1;

    pointer.y =
        -((event.clientY - rect.top) / rect.height) * 2 + 1;

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


// ============================================================
// CREATE ROUTE MARKER
// ============================================================

function createMarker(point) {

    const geometry =
        new THREE.SphereGeometry(
            CONFIG.ROUTE_MARKER_RADIUS,
            20,
            20
        );

    const marker =
        new THREE.Mesh(
            geometry,
            markerMaterial
        );

    marker.position.copy(point);

    marker.position.y +=
        CONFIG.ROUTE_WAYPOINT_HEIGHT;

    marker.castShadow = true;

    scene.add(marker);

    state.routeMarkerMeshes.push(
        marker
    );

}


// ============================================================
// UPDATE ROUTE UI
// ============================================================

function updateRouteUI() {

    const count =
        state.routeWaypoints.length;

    if (dom.routePointsCount) {
        dom.routePointsCount.textContent =
            count;
    }

    if (dom.routeWaypointsBadge) {
        dom.routeWaypointsBadge.textContent =
            count;
    }

    if (dom.flyRouteBtn) {

        dom.flyRouteBtn.disabled =
            count < 2;

    }

    if (dom.clearRouteBtn) {

        dom.clearRouteBtn.disabled =
            count === 0;

    }

}


// ============================================================
// ROUTE STATUS
// ============================================================

function setRouteStatus(message) {

    if (dom.routeStatus) {
        dom.routeStatus.textContent =
            message;
    }

}


// ============================================================
// ADD WAYPOINT
// ============================================================

export function addWaypoint(point) {

    if (!point) {
        return;
    }

    state.routeWaypoints.push(
        point.clone()
    );

    createMarker(point);

    updateRouteUI();

    setRouteStatus(
        `${state.routeWaypoints.length} waypoint${
            state.routeWaypoints.length === 1 ? '' : 's'
        }`
    );

    updateRouteLine();

}


// ============================================================
// ROUTE LINE DISPOSAL
// ============================================================

function disposeRouteLine() {

    if (!state.routeLineMesh) {
        return;
    }

    scene.remove(
        state.routeLineMesh
    );

    if (
        state.routeLineMesh.geometry
    ) {

        state.routeLineMesh.geometry.dispose();

    }

    state.routeLineMesh =
        null;

}


// ============================================================
// CREATE SIMPLE ROUTE
// ============================================================

function createFallbackRoute() {

    const points =
        state.routeWaypoints;

    if (points.length < 2) {
        return;
    }

    const curve =
        new THREE.CatmullRomCurve3(
            points,
            false,
            'centripetal',
            0.25
        );

    const samples =
        Math.max(
            CONFIG.ROUTE_MIN_SAMPLE_COUNT,
            points.length *
                CONFIG.ROUTE_SAMPLES_PER_WAYPOINT
        );

    const surfacePoints =
        curve.getPoints(samples);

    state.routeSurfaceCurve =
        new THREE.CatmullRomCurve3(
            surfacePoints,
            false,
            'centripetal',
            0.25
        );

    const geometry =
        new THREE.BufferGeometry().setFromPoints(
            surfacePoints
        );

    state.routeLineMesh =
        new THREE.Line(
            geometry,
            routeMaterial
        );

    scene.add(
        state.routeLineMesh
    );

}


// ============================================================
// UPDATE ROUTE LINE
// ============================================================

export async function updateRouteLine() {

    if (
        state.routeWaypoints.length < 2
    ) {

        disposeRouteLine();

        state.routeSurfaceCurve =
            null;

        state.routeDistance = 0;

        if (dom.routeDistance) {
            dom.routeDistance.textContent =
                '0.00 m';
        }

        return;

    }


    // Cancel previous async calculation
    const calculationId =
        ++state.currentRouteCalculationId;


    disposeRouteLine();


    setRouteStatus(
        'Calculating route...'
    );


    const controlPoints =
        state.routeWaypoints.map(
            point => point.clone()
        );


    const baseCurve =
        new THREE.CatmullRomCurve3(
            controlPoints,
            false,
            'centripetal',
            0.25
        );


    const sampleCount =
        Math.max(
            CONFIG.ROUTE_MIN_SAMPLE_COUNT,
            controlPoints.length *
                CONFIG.ROUTE_SAMPLES_PER_WAYPOINT
        );


    const basePoints =
        baseCurve.getPoints(
            sampleCount
        );


    const surfacePoints = [];

    // --------------------------------------------------------
    // Raycast each route section in chunks
    // --------------------------------------------------------

    for (
        let start = 0;
        start < basePoints.length;
        start += CONFIG.ROUTE_CHUNK_SIZE
    ) {

        if (
            calculationId !==
            state.currentRouteCalculationId
        ) {
            return;
        }


        const end =
            Math.min(
                start + CONFIG.ROUTE_CHUNK_SIZE,
                basePoints.length
            );


        for (
            let i = start;
            i < end;
            i++
        ) {

            const point =
                basePoints[i];


            if (!state.terrainModel) {

                surfacePoints.push(
                    point.clone()
                );

                continue;

            }


            // Raycast vertically downward
            const origin =
                new THREE.Vector3(
                    point.x,
                    10000,
                    point.z
                );

            const direction =
                new THREE.Vector3(
                    0,
                    -1,
                    0
                );


            raycaster.set(
                origin,
                direction
            );


            const intersections =
                raycaster.intersectObject(
                    state.terrainModel,
                    true
                );


            if (intersections.length) {

                const hit =
                    intersections[0].point.clone();

                hit.y +=
                    CONFIG.ROUTE_SURFACE_OFFSET;

                surfacePoints.push(
                    hit
                );

            } else {

                surfacePoints.push(
                    point.clone()
                );

            }

        }


        // Yield to browser so UI remains responsive
        await new Promise(
            resolve =>
                requestAnimationFrame(resolve)
        );

    }


    if (
        calculationId !==
        state.currentRouteCalculationId
    ) {
        return;
    }


    if (
        surfacePoints.length < 2
    ) {
        createFallbackRoute();
        return;
    }


    // --------------------------------------------------------
    // Final smooth curve
    // --------------------------------------------------------

    const smoothCurve =
        new THREE.CatmullRomCurve3(
            surfacePoints,
            false,
            'centripetal',
            0.25
        );


    state.routeSurfaceCurve =
        smoothCurve;


    const finalPoints =
        smoothCurve.getPoints(
            sampleCount
        );


    const geometry =
        new THREE.BufferGeometry().setFromPoints(
            finalPoints
        );


    state.routeLineMesh =
        new THREE.Line(
            geometry,
            routeMaterial
        );


    scene.add(
        state.routeLineMesh
    );


    // --------------------------------------------------------
    // Calculate distance
    // --------------------------------------------------------

    let distance = 0;

    for (
        let i = 1;
        i < finalPoints.length;
        i++
    ) {

        distance +=
            finalPoints[i - 1].distanceTo(
                finalPoints[i]
            );

    }


    state.routeDistance =
        distance;


    if (dom.routeDistance) {

        dom.routeDistance.textContent =
            `${distance.toFixed(2)} m`;

    }


    setRouteStatus(
        'Route ready'
    );

}


// ============================================================
// START DRAWING
// ============================================================

export function startRouteDrawing() {

    if (state.isFlyingRoute) {
        return;
    }


    state.isDrawingRoute =
        true;


    setRouteStatus(
        'Click terrain to add waypoints'
    );


    setViewerStatus(
        'Route drawing active',
        'ready'
    );

}


// ============================================================
// STOP DRAWING
// ============================================================

export function stopRouteDrawing() {

    state.isDrawingRoute =
        false;


    if (
        state.routeWaypoints.length
    ) {

        setRouteStatus(
            `${state.routeWaypoints.length} waypoint${
                state.routeWaypoints.length === 1 ? '' : 's'
            }`
        );

    } else {

        setRouteStatus(
            'No route'
        );

    }

}


// ============================================================
// CLEAR ROUTE
// ============================================================

export function clearRoute() {

    // Invalidate pending calculations
    state.currentRouteCalculationId++;


    state.isDrawingRoute =
        false;

    state.isFlyingRoute =
        false;


    state.routeWaypoints =
        [];


    state.routeSurfaceCurve =
        null;


    state.routeDistance =
        0;

    state.flyProgress =
        0;


    // Remove markers
    for (
        const marker of state.routeMarkerMeshes
    ) {

        scene.remove(marker);

        if (marker.geometry) {
            marker.geometry.dispose();
        }

    }

    state.routeMarkerMeshes =
        [];


    disposeRouteLine();


    // Restore controls
    orbitControls.enabled = true;
    flyControls.enabled = false;


    updateRouteUI();


    if (dom.routeDistance) {
        dom.routeDistance.textContent =
            '0.00 m';
    }


    if (dom.routeStatus) {
        dom.routeStatus.textContent =
            'No route';
    }


    if (dom.flyRouteBtnText) {
        dom.flyRouteBtnText.textContent =
            'Fly Route';
    }


    setReadyStatus(
        'Route cleared'
    );

}


// ============================================================
// ROUTE FLYTHROUGH
// ============================================================

export function startRouteFlythrough() {

    if (
        state.routeWaypoints.length < 2 ||
        !state.routeSurfaceCurve
    ) {

        setRouteStatus(
            'Add at least 2 waypoints first'
        );

        return;

    }


    // Toggle off if already flying
    if (state.isFlyingRoute) {

        stopRouteFlythrough();

        return;

    }


    state.routePreviousFlyMode =
        state.flyMode;


    state.isFlyingRoute =
        true;

    state.isDrawingRoute =
        false;

    state.flyProgress =
        0;


    orbitControls.enabled =
        false;

    flyControls.enabled =
        false;


    if (dom.flyRouteBtnText) {

        dom.flyRouteBtnText.textContent =
            'Stop Flythrough';

    }


    setViewerStatus(
        'Route flythrough active',
        'ready'
    );


    setRouteStatus(
        'Flying route...'
    );

}


// ============================================================
// STOP ROUTE FLYTHROUGH
// ============================================================

export function stopRouteFlythrough() {

    state.isFlyingRoute =
        false;


    state.flyProgress =
        0;


    orbitControls.enabled =
        true;

    flyControls.enabled =
        state.flyMode;


    if (dom.flyRouteBtnText) {

        dom.flyRouteBtnText.textContent =
            'Fly Route';

    }


    setRouteStatus(
        state.routeWaypoints.length
            ? 'Route ready'
            : 'No route'
    );

}


// ============================================================
// UPDATE ROUTE FLYTHROUGH
// ============================================================

export function updateRouteFlythrough(delta) {

    if (
        !state.isFlyingRoute ||
        !state.routeSurfaceCurve
    ) {
        return;
    }


    state.flyProgress +=
        delta *
        CONFIG.ROUTE_FLY_SPEED;


    // Loop route
    if (
        state.flyProgress >= 1
    ) {

        state.flyProgress = 0;

    }


    const point =
        state.routeSurfaceCurve.getPointAt(
            state.flyProgress
        );


    // Look ahead
    const lookAheadProgress =
        Math.min(
            1,
            state.flyProgress +
                CONFIG.ROUTE_LOOK_AHEAD_DISTANCE /
                Math.max(
                    state.routeDistance,
                    1
                )
        );


    const lookAtPoint =
        state.routeSurfaceCurve.getPointAt(
            lookAheadProgress
        );


    camera.position.set(
        point.x,
        point.y +
            CONFIG.ROUTE_CAMERA_HEIGHT,
        point.z
    );


    camera.lookAt(
        lookAtPoint.x,
        lookAtPoint.y +
            CONFIG.ROUTE_CAMERA_HEIGHT,
        lookAtPoint.z
    );

}


// ============================================================
// ROUTE CLICK HANDLER
// ============================================================

function handleRouteClick(event) {

    if (!state.isDrawingRoute) {
        return;
    }


    if (state.isFlyingRoute) {
        return;
    }


    const point =
        getTerrainIntersection(event);


    if (!point) {
        return;
    }


    addWaypoint(point);

}


// ============================================================
// INITIALIZE ROUTE
// ============================================================

export function initRoute() {

    renderer.domElement.addEventListener(
        'click',
        handleRouteClick
    );


    updateRouteUI();

    setRouteStatus(
        'No route'
    );

}