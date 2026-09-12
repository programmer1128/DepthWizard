// ============================================================
// DEPTHWIZARD
// LIGHTING + GRID SYSTEM
// ============================================================

import * as THREE from 'three';

import { scene } from './scene.js';
import { dom } from '../core/dom.js';
import { state } from '../core/state.js';
import { CONFIG } from '../core/constants.js';
import { setGridStatus } from '../ui/status.js';


// ============================================================
// LIGHTS
// ============================================================

// Main ambient illumination
export const ambientLight = new THREE.AmbientLight(
    0xffffff,
    1.6
);


// Main directional sunlight
export const directionalLight = new THREE.DirectionalLight(
    0xffffff,
    2.0
);

directionalLight.position.set(
    250,
    500,
    250
);

directionalLight.castShadow = true;

directionalLight.shadow.mapSize.width = 2048;
directionalLight.shadow.mapSize.height = 2048;

directionalLight.shadow.camera.near = 0.5;
directionalLight.shadow.camera.far = 2000;

directionalLight.shadow.camera.left = -1000;
directionalLight.shadow.camera.right = 1000;
directionalLight.shadow.camera.top = 1000;
directionalLight.shadow.camera.bottom = -1000;


// Secondary cool fill light
export const secondaryLight = new THREE.DirectionalLight(
    0x38bdf8,
    0.8
);

secondaryLight.position.set(
    -200,
    -200,
    -200
);


// Add lights to scene
scene.add(
    ambientLight,
    directionalLight,
    secondaryLight
);


// ============================================================
// GRID
// ============================================================

export const gridHelper = new THREE.GridHelper(
    CONFIG.GRID_SIZE,
    CONFIG.GRID_DIVISIONS,
    0x38bdf8,
    0x242d3d
);

gridHelper.position.y = 0;
gridHelper.visible = true;

scene.add(gridHelper);


// ============================================================
// LIGHTING STATE
// ============================================================

let lightIntensity = 2.0;


// ============================================================
// UPDATE LIGHTING BUTTON UI
// ============================================================

function updateLightingButton() {

    if (!dom.lightingBtn) {
        return;
    }

    dom.lightingBtn.classList.toggle(
        'active',
        state.lightingEnabled
    );

    dom.lightingBtn.textContent =
        state.lightingEnabled ? 'ON' : 'OFF';

}


// ============================================================
// UPDATE LIGHT VALUE DISPLAY
// ============================================================

function updateLightValue() {

    if (!dom.lightValue) {
        return;
    }

    dom.lightValue.textContent =
        lightIntensity.toFixed(1);

}


// ============================================================
// APPLY LIGHT INTENSITY
// ============================================================

export function setLightIntensity(value) {

    const intensity = Math.max(
        0,
        Math.min(3, Number(value))
    );

    if (!Number.isFinite(intensity)) {
        return;
    }

    lightIntensity = intensity;

    // IMPORTANT:
    // The original brightness slider directly controlled
    // the directional light intensity.
    directionalLight.intensity = lightIntensity;

    updateLightValue();

}


// ============================================================
// LIGHTING ON / OFF
// ============================================================

export function setLightingEnabled(enabled) {

    state.lightingEnabled = Boolean(enabled);

    ambientLight.visible =
        state.lightingEnabled;

    directionalLight.visible =
        state.lightingEnabled;

    secondaryLight.visible =
        state.lightingEnabled;

    updateLightingButton();

}


// ============================================================
// TOGGLE LIGHTING
// ============================================================

export function toggleLighting() {

    setLightingEnabled(
        !state.lightingEnabled
    );

}


// ============================================================
// GRID ON / OFF
// ============================================================

export function setGridVisible(visible) {

    state.gridVisible = Boolean(visible);

    gridHelper.visible =
        state.gridVisible;

    updateGridButton();

    setGridStatus(
        state.gridVisible
    );

}


// ============================================================
// UPDATE GRID BUTTON UI
// ============================================================

function updateGridButton() {

    if (!dom.gridBtn) {
        return;
    }

    dom.gridBtn.classList.toggle(
        'active',
        state.gridVisible
    );

    dom.gridBtn.textContent =
        state.gridVisible
            ? '▦ Grid On'
            : '▦ Grid Off';

}


// ============================================================
// TOGGLE GRID
// ============================================================

export function toggleGrid() {

    setGridVisible(
        !state.gridVisible
    );

}


// ============================================================
// INITIALIZE VISUALIZATION
// ============================================================

export function initLighting() {

    // Default state
    state.lightingEnabled = true;
    state.gridVisible = true;

    lightIntensity = 2.0;

    // Apply defaults
    setLightIntensity(lightIntensity);

    setLightingEnabled(
        state.lightingEnabled
    );

    setGridVisible(
        state.gridVisible
    );

}