// ============================================================
// DEPTHWIZARD
// NAVIGATION SYSTEM
// Orbit + Auto Rotate + Compass + Free Fly + Reset
// ============================================================

import * as THREE from 'three';
import { OrbitControls } from 'three/examples/jsm/controls/OrbitControls.js';
import { FlyControls } from 'three/examples/jsm/controls/FlyControls.js';

import { camera, renderer } from '../viewer/scene.js';
import { dom } from '../core/dom.js';
import { state } from '../core/state.js';
import { CONFIG } from '../core/constants.js';
import { setViewerStatus, setModeStatus } from '../ui/status.js';


// ============================================================
// CONTROLS
// ============================================================

export const orbitControls = new OrbitControls(
    camera,
    renderer.domElement
);

orbitControls.enableDamping = true;
orbitControls.dampingFactor = 0.06;

orbitControls.minDistance = CONFIG.ORBIT_MIN_DISTANCE;
orbitControls.maxDistance = CONFIG.ORBIT_MAX_DISTANCE;

orbitControls.target.set(0, 0, 0);


// IMPORTANT:
// Original viewer behavior = Orbit mode automatically rotates.
orbitControls.autoRotate = true;
orbitControls.autoRotateSpeed = 0.8;


// Free-fly controls
export const flyControls = new FlyControls(
    camera,
    renderer.domElement
);

flyControls.movementSpeed = CONFIG.FLY_MOVEMENT_SPEED;
flyControls.rollSpeed = CONFIG.FLY_ROLL_SPEED;
flyControls.dragToLook = true;
flyControls.enabled = false;


// ============================================================
// INTERNAL STATE
// ============================================================

let interactionTimeout = null;


// ============================================================
// ORBIT AUTO-ROTATION
// ============================================================

function enableAutoRotateAfterDelay(delay = 2500) {

    clearTimeout(interactionTimeout);

    interactionTimeout = setTimeout(() => {

        if (!state.flyMode && !state.isFlyingRoute) {
            orbitControls.autoRotate = true;
        }

    }, delay);
}


function pauseAutoRotate() {

    orbitControls.autoRotate = false;

    clearTimeout(interactionTimeout);
}


// ============================================================
// ORBIT USER INTERACTION
// ============================================================

orbitControls.addEventListener('start', () => {

    state.userInteracting = true;

    pauseAutoRotate();

});


orbitControls.addEventListener('end', () => {

    state.userInteracting = false;

    enableAutoRotateAfterDelay();

});


// ============================================================
// ORBIT MODE
// ============================================================

export function setOrbitMode() {

    // Stop cinematic route flight if necessary.
    if (state.isFlyingRoute) {
        return;
    }

    state.flyMode = false;

    orbitControls.enabled = true;
    flyControls.enabled = false;

    // Original behavior:
    // Orbit mode automatically rotates.
    orbitControls.autoRotate = true;

    setModeStatus('orbit');

    if (dom.orbitBtn) {
        dom.orbitBtn.classList.add('active');
    }

    if (dom.flyBtn) {
        dom.flyBtn.classList.remove('active');
    }

    setViewerStatus('Orbit Mode', 'ready');
}


// ============================================================
// FREE FLY MODE
// ============================================================

export function setFlyMode() {

    // Route flythrough must take priority.
    if (state.isFlyingRoute) {
        return;
    }

    state.flyMode = true;

    orbitControls.enabled = false;
    orbitControls.autoRotate = false;

    flyControls.enabled = true;

    setModeStatus('fly');

    if (dom.flyBtn) {
        dom.flyBtn.classList.add('active');
    }

    if (dom.orbitBtn) {
        dom.orbitBtn.classList.remove('active');
    }

    setViewerStatus('Fly Mode', 'ready');
}


// ============================================================
// TOGGLE ORBIT / FLY
// ============================================================

export function toggleNavigationMode() {

    if (state.flyMode) {
        setOrbitMode();
    } else {
        setFlyMode();
    }

}


// ============================================================
// RESET CAMERA
// ============================================================

export function resetCamera() {

    // Do not leave route flythrough running.
    if (state.isFlyingRoute) {
        return;
    }

    state.flyMode = false;

    flyControls.enabled = false;

    orbitControls.enabled = true;
    orbitControls.autoRotate = false;

    // Restore original saved camera position.
    if (state.initialCameraPosition) {
        camera.position.copy(state.initialCameraPosition);
    }

    // Restore zoom.
    camera.zoom = state.initialCameraZoom ?? 1;
    camera.updateProjectionMatrix();


    // Restore orbit target.
    if (state.initialCameraTarget) {

        orbitControls.target.copy(
            state.initialCameraTarget
        );

    } else {

        orbitControls.target.set(0, 0, 0);

    }


    camera.lookAt(orbitControls.target);

    orbitControls.update();

    // Original reset behavior:
    // return to Orbit mode with auto rotation.
    orbitControls.autoRotate = true;

    setModeStatus('orbit');

    if (dom.orbitBtn) {
        dom.orbitBtn.classList.add('active');
    }

    if (dom.flyBtn) {
        dom.flyBtn.classList.remove('active');
    }

    setViewerStatus('Camera reset', 'ready');

}


// ============================================================
// COMPASS
// ============================================================

export function updateCompass(force = false) {

    if (!dom.compassFace) {
        return;
    }

    // While automatic rotation is running, the compass naturally
    // follows the camera. During user interaction we explicitly
    // update it.
    if (
        orbitControls.autoRotate &&
        !state.userInteracting &&
        !force
    ) {
        return;
    }

    const direction = new THREE.Vector3();

    camera.getWorldDirection(direction);

    const angle = Math.atan2(
        direction.x,
        direction.z
    );

    dom.compassFace.style.transform =
        `rotate(${angle}rad)`;
}


// ============================================================
// COMPASS CLICK
// Reset orientation to a top-down North-facing view.
// ============================================================

function resetCompassOrientation() {

    // Compass should not interfere with Free Fly.
    if (state.flyMode || state.isFlyingRoute) {
        return;
    }

    // Pause rotation while snapping orientation.
    pauseAutoRotate();

    const distance = camera.position.distanceTo(
        orbitControls.target
    );

    camera.position.set(
        0,
        distance,
        0
    );

    camera.lookAt(
        orbitControls.target
    );

    orbitControls.update();

    updateCompass(true);

    // Resume normal Orbit auto-rotation after 2 seconds.
    setTimeout(() => {

        if (!state.flyMode && !state.isFlyingRoute) {
            orbitControls.autoRotate = true;
        }

    }, 2000);

}


// ============================================================
// NAVIGATION UPDATE
// Called every animation frame.
// ============================================================

export function updateNavigation(delta = 0.016) {

    // Cinematic route flight controls the camera itself.
    if (state.isFlyingRoute) {
        return;
    }

    if (state.flyMode) {

        flyControls.update(delta);

    } else {

        orbitControls.update();

    }

    updateCompass();

}


// ============================================================
// INITIALIZATION
// ============================================================

export function initNavigation() {

    // Initial state = Orbit.
    state.flyMode = false;

    orbitControls.enabled = true;
    orbitControls.autoRotate = true;

    flyControls.enabled = false;

    orbitControls.target.set(0, 0, 0);

    setModeStatus('orbit');


    // Compass interaction.
    if (dom.compassControl) {

        dom.compassControl.addEventListener(
            'click',
            resetCompassOrientation
        );

    }


    // Extra pointer tracking for compass / UI state.
    renderer.domElement.addEventListener(
        'pointerdown',
        () => {

            state.userInteracting = true;

        }
    );


    renderer.domElement.addEventListener(
        'pointerup',
        () => {

            state.userInteracting = false;

            if (!state.flyMode && !state.isFlyingRoute) {
                enableAutoRotateAfterDelay();
            }

        }
    );

}