// ============================================================
// DEPTHWIZARD
// THREE.JS SCENE, CAMERA & RENDERER
// ============================================================

import * as THREE from 'three';

import { dom } from '../core/dom.js';
import { CONFIG } from '../core/constants.js';


// ------------------------------------------------------------
// Scene
// ------------------------------------------------------------

export const scene = new THREE.Scene();

scene.background = null;


// ------------------------------------------------------------
// Camera
// ------------------------------------------------------------

export const camera =
    new THREE.PerspectiveCamera(
        CONFIG.CAMERA_FOV,
        dom.container.clientWidth /
            dom.container.clientHeight,
        CONFIG.CAMERA_NEAR,
        CONFIG.CAMERA_FAR
    );

camera.position.set(
    CONFIG.INITIAL_CAMERA_X,
    CONFIG.INITIAL_CAMERA_Y,
    CONFIG.INITIAL_CAMERA_Z
);

camera.lookAt(0, 0, 0);


// ------------------------------------------------------------
// Renderer
// ------------------------------------------------------------

export const renderer =
    new THREE.WebGLRenderer({
        antialias: true,
        alpha: true,
        powerPreference: 'high-performance'
    });

renderer.setClearColor(
    0x000000,
    0
);

renderer.toneMapping =
    THREE.ACESFilmicToneMapping;

renderer.toneMappingExposure =
    CONFIG.TONE_MAPPING_EXPOSURE;

renderer.shadowMap.enabled = true;

renderer.shadowMap.type =
    THREE.PCFShadowMap;

renderer.setSize(
    dom.container.clientWidth,
    dom.container.clientHeight
);

renderer.setPixelRatio(
    Math.min(
        window.devicePixelRatio,
        CONFIG.MAX_PIXEL_RATIO
    )
);

dom.container.appendChild(
    renderer.domElement
);


// ------------------------------------------------------------
// Handle window/container resize
// ------------------------------------------------------------

export function resizeRenderer() {

    const width =
        dom.container.clientWidth;

    const height =
        dom.container.clientHeight;

    if (width <= 0 || height <= 0) {
        return;
    }

    camera.aspect =
        width / height;

    camera.updateProjectionMatrix();

    renderer.setSize(
        width,
        height
    );

    renderer.setPixelRatio(
        Math.min(
            window.devicePixelRatio,
            CONFIG.MAX_PIXEL_RATIO
        )
    );
}