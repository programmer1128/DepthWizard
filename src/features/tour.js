// ============================================================
// DEPTHWIZARD
// 60-SECOND GUIDED FLIGHT TOUR
// ============================================================

import * as THREE from 'three';

import { camera } from '../viewer/scene.js';
import { orbitControls, flyControls } from '../controls/navigation.js';
import { dom } from '../core/dom.js';
import { state } from '../core/state.js';

let initialized = false;
let savedCameraPosition = null;
let savedTarget = null;
let savedOrbitEnabled = true;
let savedFlyEnabled = false;

const TOUR_DURATION = 60;

function getTourRadius() {
    const size = state.terrainBounds?.size;
    if (!size) return 200;
    return Math.max(size.x, size.z, 40) * 1.35;
}

export function startGuidedTour() {
    if (!state.terrainModel || state.isFlyingRoute) return false;

    savedCameraPosition = camera.position.clone();
    savedTarget = orbitControls.target.clone();
    savedOrbitEnabled = orbitControls.enabled;
    savedFlyEnabled = flyControls.enabled;

    state.tourActive = true;
    state.tourElapsed = 0;

    orbitControls.enabled = false;
    flyControls.enabled = false;

    if (dom.guidedTourBtn) {
        dom.guidedTourBtn.classList.add('active');
        dom.guidedTourBtn.textContent = 'Exit 360° View';
    }
    dom.judgeModeBtn?.classList.add('active');

    if (dom.tourStatus) {
        dom.tourStatus.textContent = '360° view active • 60 seconds';
    }

    return true;
}

export function stopGuidedTour(restoreCamera = true) {
    if (!state.tourActive) return;

    state.tourActive = false;

    if (restoreCamera && savedCameraPosition && savedTarget) {
        camera.position.copy(savedCameraPosition);
        orbitControls.target.copy(savedTarget);
        orbitControls.update();
    }

    orbitControls.enabled = savedOrbitEnabled;
    flyControls.enabled = savedFlyEnabled;

    if (dom.guidedTourBtn) {
        dom.guidedTourBtn.classList.remove('active');
        dom.guidedTourBtn.textContent = 'Start 360° View';
    }
    dom.judgeModeBtn?.classList.remove('active');

    if (dom.tourStatus) {
        dom.tourStatus.textContent = 'Ready • orbit camera restored';
    }
}

export function updateGuidedTour(deltaSeconds) {
    if (!state.tourActive || !state.terrainModel) return;

    state.tourElapsed += deltaSeconds;

    if (state.tourElapsed >= TOUR_DURATION) {
        stopGuidedTour(true);
        return;
    }

    const t = state.tourElapsed / TOUR_DURATION;
    const radius = getTourRadius();
    const angle = t * Math.PI * 2.0;
    const bob = Math.sin(t * Math.PI * 4.0) * radius * 0.08;
    const vertical = radius * (0.34 + 0.12 * Math.sin(t * Math.PI * 2.0));

    camera.position.set(
        Math.cos(angle) * radius,
        vertical + bob,
        Math.sin(angle) * radius
    );

    const look = new THREE.Vector3(
        0,
        (state.terrainComparisonBounds?.minY ?? 0) * 0.10,
        0
    );

    camera.lookAt(look);

    if (dom.tourStatus) {
        const remaining = Math.max(0, Math.ceil(TOUR_DURATION - state.tourElapsed));
        dom.tourStatus.textContent = `360° view active • ${remaining}s remaining`;
    }
}

export function initGuidedTour() {
    if (initialized) return;
    initialized = true;

    const toggleTour = () => {
        if (state.tourActive) {
            stopGuidedTour(true);
        } else if (!startGuidedTour()) {
            if (dom.tourStatus) dom.tourStatus.textContent = 'Load terrain before starting the tour.';
        }
    };

    dom.guidedTourBtn?.addEventListener('click', toggleTour);
    dom.judgeModeBtn?.addEventListener('click', toggleTour);
}
