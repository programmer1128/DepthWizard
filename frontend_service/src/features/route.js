// ============================================================
// DEPTHWIZARD
// ROUTE DRAWING + SURFACE FOLLOWING + FLYTHROUGH
// ============================================================

import { intersectScientific } from '../viewer/vegetation.js';
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
        intersectScientific(
            raycaster,
            state.terrainModel
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
    if (dom.undoRouteBtn) {
        dom.undoRouteBtn.disabled =
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

// Add this at the top of the file (or right above the function) to cache the points
let routeProfilePoints = [];

// ============================================================
// DRAW ELEVATION PROFILE CHART (WITH LIVE TRACKING)
// ============================================================
function drawElevationProfile(points, currentProgress = null) {
    const container = document.getElementById('elevationChartContainer');
    const canvas = document.getElementById('elevationChart');
    
    if (!container || !canvas || points.length < 2) {
        if (container) container.style.display = 'none';
        return;
    }
    
    routeProfilePoints = points;
    container.style.display = 'block';
    
    const ctx = canvas.getContext('2d');
    const width = canvas.width;
    const height = canvas.height;
    ctx.clearRect(0, 0, width, height);
    
    // 1. Calculate physical distances for accurate X-axis spacing
    const distances = [0];
    let totalDist = 0;
    for (let i = 1; i < points.length; i++) {
        totalDist += points[i].distanceTo(points[i - 1]);
        distances.push(totalDist);
    }
    
    // Find absolute Min and Max heights
    let minY = Infinity, maxY = -Infinity;
    points.forEach(p => {
        if (p.y < minY) minY = p.y;
        if (p.y > maxY) maxY = p.y;
    });
    
    const rangeY = (maxY - minY) || 1;
    const padding = 5; 
    const drawHeight = height - (padding * 2);
    
    // Helper to get exact canvas coordinates for any waypoint
    const getCanvasCoords = (index) => {
        const x = totalDist === 0 ? 0 : (distances[index] / totalDist) * width;
        const normalizedY = (points[index].y - minY) / rangeY;
        const y = height - padding - (normalizedY * drawHeight);
        return { x, y };
    };

    // 2. Draw Filled Gradient Polygon
    ctx.beginPath();
    ctx.moveTo(0, height);
    points.forEach((_, i) => {
        const { x, y } = getCanvasCoords(i);
        ctx.lineTo(x, y);
    });
    ctx.lineTo(width, height);
    ctx.closePath();
    
    const grad = ctx.createLinearGradient(0, 0, 0, height);
    grad.addColorStop(0, 'rgba(56, 189, 248, 0.4)');
    grad.addColorStop(1, 'rgba(56, 189, 248, 0.0)');
    ctx.fillStyle = grad;
    ctx.fill();
    
    // 3. Draw Top Crisp Line
    ctx.beginPath();
    points.forEach((_, i) => {
        const { x, y } = getCanvasCoords(i);
        if (i === 0) ctx.moveTo(x, y);
        else ctx.lineTo(x, y);
    });
    ctx.strokeStyle = '#38bdf8';
    ctx.lineWidth = 1.5;
    ctx.stroke();

    // 4. DRAW LIVE TRACKING DOT (Mathematically locked to the line)
    if (currentProgress !== null) {
        // Prevent floating point overshoot
        const targetDist = Math.min(Math.max(currentProgress * totalDist, 0), totalDist);
        let segIdx = 0;

        // Find which line segment the dot is currently on
        for (let i = 0; i < distances.length - 1; i++) {
            if (targetDist >= distances[i] && targetDist <= distances[i + 1]) {
                segIdx = i;
                break;
            }
        }

        const d1 = distances[segIdx];
        const d2 = distances[segIdx + 1];
        const segmentProgress = (d2 === d1) ? 0 : (targetDist - d1) / (d2 - d1);

        const p1 = getCanvasCoords(segIdx);
        const p2 = getCanvasCoords(segIdx + 1);

        // Interpolate exact 2D canvas coordinates
        const dotX = p1.x + (p2.x - p1.x) * segmentProgress;
        const dotY = p1.y + (p2.y - p1.y) * segmentProgress;

        // Draw outer red glow
        ctx.beginPath();
        ctx.arc(dotX, dotY, 6, 0, Math.PI * 2);
        ctx.fillStyle = 'rgba(239, 68, 68, 0.4)';
        ctx.fill();

        // Draw solid red core
        ctx.beginPath();
        ctx.arc(dotX, dotY, 2.5, 0, Math.PI * 2);
        ctx.fillStyle = '#ef4444';
        ctx.fill();
        
        // Draw vertical tracking line
        ctx.beginPath();
        ctx.moveTo(dotX, dotY + 4);
        ctx.lineTo(dotX, height);
        ctx.strokeStyle = 'rgba(239, 68, 68, 0.5)';
        ctx.lineWidth = 1;
        ctx.setLineDash([2, 2]); // Dotted line
        ctx.stroke();
        ctx.setLineDash([]); // Reset
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
                intersectScientific(
                    raycaster,
                    state.terrainModel
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


    // Call the chart drawer
    drawElevationProfile(finalPoints);

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

    // Add this block to reset the draw button visually
    if (dom.drawRouteBtn) {
        dom.drawRouteBtn.classList.remove('active');
    }

    if (dom.routeDistance) {
        dom.routeDistance.textContent = '0.00 m';
    }

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


    drawElevationProfile([]); // Clears and hides the chart

    setReadyStatus(
        'Route cleared'
    );

}

// ============================================================
// REMOVE LAST WAYPOINT
// ============================================================

export function removeLastWaypoint() {

    if (!state.routeWaypoints.length) {
        return;
    }

    // Invalidate any route calculation currently in progress.
    state.currentRouteCalculationId++;

    // Remove the last waypoint.
    state.routeWaypoints.pop();

    // Remove the corresponding marker.
    const marker =
        state.routeMarkerMeshes.pop();

    if (marker) {

        scene.remove(marker);

        if (marker.geometry) {
            marker.geometry.dispose();
        }

    }

    // Rebuild route from the remaining points.
    updateRouteUI();

    if (!state.routeWaypoints.length) {

        disposeRouteLine();

        state.routeSurfaceCurve = null;
        state.routeDistance = 0;

        if (dom.routeDistance) {
            dom.routeDistance.textContent = '0.00 m';
        }

        setRouteStatus('No route');

        drawElevationProfile([]);

        return;
    }

    setRouteStatus(
        `${state.routeWaypoints.length} waypoint${
            state.routeWaypoints.length === 1 ? '' : 's'
        }`
    );

    updateRouteLine();
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

    // Redraw the chart without the progress parameter to remove the dot
    drawElevationProfile(routeProfilePoints);
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

    // Update chart with live progress indicator
    drawElevationProfile(routeProfilePoints, state.flyProgress);
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

    if (dom.undoRouteBtn) {

        dom.undoRouteBtn.addEventListener(
            'click',
            removeLastWaypoint
        );

    }


    updateRouteUI();

    setRouteStatus(
        'No route'
    );

}