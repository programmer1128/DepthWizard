// ============================================================
// DEPTHWIZARD
// TERRAIN / GLB LOADER
// ============================================================

import * as THREE from 'three';
import { GLTFLoader } from 'three/addons/loaders/GLTFLoader.js';
import { DRACOLoader } from 'three/addons/loaders/DRACOLoader.js';

import {
    scene,
    camera
} from './scene.js';

import {
    gridHelper
} from './lighting.js';

import {
    orbitControls
} from '../controls/navigation.js';

import {
    dom
} from '../core/dom.js';

import {
    state
} from '../core/state.js';

import {
    setViewerStatus,
    setFileStatus
} from '../ui/status.js';

// ============================================================
// GLTF LOADER
// ============================================================

const dracoLoader =
    new DRACOLoader();

dracoLoader.setDecoderPath(
    '/draco/'
);

const gltfLoader =
    new GLTFLoader();

gltfLoader.setDRACOLoader(
    dracoLoader
);

// ============================================================
// DISPOSE OBJECT
// ============================================================

function disposeObject(object) {

    object.traverse((child) => {

        if (!child.isMesh) {
            return;
        }

        if (child.geometry) {
            child.geometry.dispose();
        }

        if (child.material) {

            if (Array.isArray(child.material)) {

                child.material.forEach(
                    material => {

                        if (material.map) {
                            material.map.dispose();
                        }

                        material.dispose();
                    }
                );

            } else {

                if (child.material.map) {
                    child.material.map.dispose();
                }

                child.material.dispose();
            }
        }
    });
}

// ============================================================
// REMOVE CURRENT TERRAIN
// ============================================================

function removeCurrentTerrain() {

    if (!state.terrainModel) {
        return;
    }

    scene.remove(
        state.terrainModel
    );

    disposeObject(
        state.terrainModel
    );

    state.terrainModel = null;
}

// ============================================================
// LOAD TERRAIN GLB
// ============================================================

export function loadTerrainGLB(url) {

    if (!url) {

        setViewerStatus(
            'NO TERRAIN FILE',
            'error'
        );

        return;
    }

    // --------------------------------------------------------
    // Loading state
    // --------------------------------------------------------

    setViewerStatus(
        'LOADING 3D TERRAIN',
        'loading'
    );

    setFileStatus(
        'Loading terrain mesh...'
    );

    // --------------------------------------------------------
    // Remove previous terrain
    // --------------------------------------------------------

    removeCurrentTerrain();

    // --------------------------------------------------------
    // Load GLB
    // --------------------------------------------------------

    gltfLoader.load(

        url,

        (gltf) => {

            const model =
                gltf.scene;

            if (!model) {

                setViewerStatus(
                    'INVALID TERRAIN MODEL',
                    'error'
                );

                return;
            }

            // ------------------------------------------------
            // Save current terrain
            // ------------------------------------------------

            state.terrainModel =
                model;

            // ------------------------------------------------
            // Add model to scene
            // ------------------------------------------------

            scene.add(model);

            // ------------------------------------------------
            // Calculate original model bounds
            // ------------------------------------------------

            const box =
                new THREE.Box3()
                    .setFromObject(model);

            const center =
                box.getCenter(
                    new THREE.Vector3()
                );

            const size =
                box.getSize(
                    new THREE.Vector3()
                );

            // ------------------------------------------------
            // Center terrain around origin
            // ------------------------------------------------

            model.position.sub(
                center
            );

            // ------------------------------------------------
            // Recalculate bounds
            // after centering
            // ------------------------------------------------

            const centeredBox =
                new THREE.Box3()
                    .setFromObject(model);

            const centeredSize =
                centeredBox.getSize(
                    new THREE.Vector3()
                );

            // ------------------------------------------------
            // Put grid below terrain
            // ------------------------------------------------

            gridHelper.position.y =
                centeredBox.min.y - 1;

            // ------------------------------------------------
            // Calculate useful dimensions
            // ------------------------------------------------

            const maxDim =
                Math.max(
                    centeredSize.x,
                    centeredSize.y,
                    centeredSize.z
                );

            // ------------------------------------------------
            // Automatically position camera
            // ------------------------------------------------

            const cameraDistance =
                Math.max(
                    maxDim * 1.4,
                    40
                );

            camera.position.set(
                cameraDistance,
                cameraDistance * 0.75,
                cameraDistance
            );

            camera.lookAt(
                0,
                0,
                0
            );

            // ------------------------------------------------
            // Reset orbit target
            // ------------------------------------------------

            orbitControls.target.set(
                0,
                0,
                0
            );

            orbitControls.update();

            // ------------------------------------------------
            // Save reset camera state
            // ------------------------------------------------

            state.initialCameraPosition =
                camera.position.clone();

            state.initialCameraTarget =
                orbitControls.target.clone();

            // ------------------------------------------------
            // Hide empty viewer state
            // ------------------------------------------------

            if (
                dom.emptyStateOverlay
            ) {

                dom.emptyStateOverlay.style.display =
                    'none';
            }

            // ------------------------------------------------
            // Terrain dimensions
            // ------------------------------------------------

            const width =
                centeredSize.x;

            const depth =
                centeredSize.z;

            const elevation =
                centeredSize.y;

            // ------------------------------------------------
            // Update UI
            // ------------------------------------------------

            setFileStatus(
                `Mesh active: ${width.toFixed(1)} × ${depth.toFixed(1)} units ` +
                `(Elevation span: ${elevation.toFixed(1)}m)`
            );

            setViewerStatus(
                '3D VIEWER READY',
                'ready'
            );

            // ------------------------------------------------
            // Update state
            // ------------------------------------------------

            state.currentLoadedUrl =
                url;

            console.log(
                'DepthWizard terrain loaded:',
                {
                    width,
                    depth,
                    elevation
                }
            );
        },

        // ----------------------------------------------------
        // Loading progress
        // ----------------------------------------------------

        (progress) => {

            if (
                progress.total > 0
            ) {

                const percent =
                    (
                        progress.loaded /
                        progress.total
                    ) * 100;

                setFileStatus(
                    `Loading terrain mesh... ${percent.toFixed(0)}%`
                );
            }
        },

        // ----------------------------------------------------
        // Loading error
        // ----------------------------------------------------

        (error) => {

            console.error(
                'Terrain loading failed:',
                error
            );

            state.terrainModel =
                null;

            setViewerStatus(
                'TERRAIN LOAD FAILED',
                'error'
            );

            setFileStatus(
                'Unable to load 3D terrain mesh.'
            );
        }
    );
}

// ============================================================
// CLEAR TERRAIN
// ============================================================

export function clearTerrain() {

    removeCurrentTerrain();

    state.currentLoadedUrl =
        null;

    setFileStatus(
        'No terrain mesh loaded.'
    );
}