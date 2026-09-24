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

import {
    patchTerrainModel,
    updateComparisonBounds
} from '../features/splitComparison.js';

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
    state.terrainBounds = null;
}

// ============================================================
// LOAD TERRAIN GLB
// ============================================================

export function loadTerrainGLB(url) {

    return new Promise((resolve, reject) => {

        if (!url) {

            setViewerStatus(
                'NO TERRAIN FILE',
                'error'
            );

            reject(new Error('No terrain file URL provided.'));
            return;
        }

        // ----------------------------------------------------
        // Loading state
        // ----------------------------------------------------

        setViewerStatus(
            'LOADING 3D TERRAIN',
            'loading'
        );

        setFileStatus(
            'Loading terrain mesh...'
        );

        // ----------------------------------------------------
        // Remove previous terrain
        // ----------------------------------------------------

        removeCurrentTerrain();

        // ----------------------------------------------------
        // Load GLB
        // ----------------------------------------------------

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

                    reject(new Error('Invalid terrain model in GLTF scene.'));
                    return;
                }

                // --------------------------------------------
                // Save current terrain
                // --------------------------------------------

                state.terrainModel =
                    model;

                // --------------------------------------------
                // Add model to scene
                // --------------------------------------------

                scene.add(model);

                // --------------------------------------------
                // Calculate original model bounds
                // --------------------------------------------

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

                // --------------------------------------------
                // Store original uncentered bounds in state
                // (Essential for converting world coordinates
                // back to uncentered raster coordinates for backend APIs)
                // --------------------------------------------

                state.terrainBounds = {
                    min: box.min.clone(),
                    max: box.max.clone(),
                    center: center.clone(),
                    size: size.clone()
                };

                // --------------------------------------------
                // Center terrain around origin
                // --------------------------------------------

                model.position.sub(
                    center
                );

                model.updateMatrixWorld(true);

                // Visual vertical exaggeration is always driven by one stable
                // scale factor so measurement correction can mathematically
                // divide it back out.
                model.userData.baseScaleY = model.scale.y || 1;
                model.scale.y = model.userData.baseScaleY * (state.verticalExaggeration || 1);
                model.updateMatrixWorld(true);

                // Prepare the stable comparison shader before first render.
                patchTerrainModel(model);

                // --------------------------------------------
                // GENERATE 3D ELEVATION HEAT MAP DATA
                // --------------------------------------------
                model.traverse((child) => {
                    if (child.isMesh && child.geometry) {
                        
                        // Calculate min/max height
                        child.geometry.computeBoundingBox();
                        const minY = child.geometry.boundingBox.min.y;
                        const maxY = child.geometry.boundingBox.max.y;
                        const range = maxY - minY || 1;

                        const positions = child.geometry.attributes.position;
                        const colors = [];
                        const color = new THREE.Color();

                        // Map Y height to Blue->Red Hue
                        for (let i = 0; i < positions.count; i++) {
                            const y = positions.getY(i);
                            const normalized = (y - minY) / range;
                            const hue = (1.0 - normalized) * 0.66; 
                            color.setHSL(hue, 1.0, 0.5);
                            colors.push(color.r, color.g, color.b);
                        }

                        child.geometry.setAttribute('color', new THREE.Float32BufferAttribute(colors, 3));
                        
                        // Preserve the original optical material exactly as loaded.
                        child.userData.originalMaterial = child.material;

                        // Create a dedicated heatmap material
                        child.userData.heatmapMaterial = new THREE.MeshStandardMaterial({
                            vertexColors: true,
                            roughness: 0.8,
                            metalness: 0.1
                        });

                        // Apply based on current state
                        child.material = state.heatmapEnabled ? child.userData.heatmapMaterial : child.userData.originalMaterial;
                    }
                });

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

            resolve(model);
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
            state.terrainBounds =
                null;

            setViewerStatus(
                'TERRAIN LOAD FAILED',
                'error'
            );

            setFileStatus(
                'Unable to load 3D terrain mesh.'
            );

            reject(error);
        }
    );
    });
}

// ============================================================
// ============================================================
// VERTICAL EXAGGERATION
// ============================================================

export function setVerticalExaggeration(value) {

    const next = Math.max(1, Math.min(2.5, Number(value) || 1));
    state.verticalExaggeration = next;

    if (!state.terrainModel) {
        return next;
    }

    const baseScaleY = state.terrainModel.userData.baseScaleY || 1;
    state.terrainModel.scale.y = baseScaleY * next;
    state.terrainModel.updateMatrixWorld(true);

    const centeredBox =
        new THREE.Box3().setFromObject(state.terrainModel);

    gridHelper.position.y = centeredBox.min.y - 1;

    updateComparisonBounds(state.terrainModel);

    return next;
}

// WORLD TO RASTER COORDINATES
// ============================================================

/**
 * Converts a Three.js 3D world coordinate into the original positive
 * 2D raster/image coordinates expected by the backend height and compare APIs.
 *
 * The terrain mesh is centered at origin in Three.js world space, but the
 * original GeoTIFF/raster pixel grid has non-negative coordinates [0, width]
 * and [0, depth].
 *
 * @param {THREE.Vector3} worldPoint - Raycast intersection point in world space
 * @returns {{ x: number, y: number, meshHeight: number }} - Raster coordinates (x, y) & mesh surface height
 */
export function worldToRasterCoordinates(worldPoint) {

    if (!worldPoint) {
        return { x: 0, y: 0, meshHeight: 0 };
    }

    const point = worldPoint.clone();

    if (!state.terrainModel || !state.terrainBounds) {
        return {
            x: Math.max(0, Number(point.x) || 0),
            y: Math.max(0, Number(point.z) || 0),
            meshHeight: Number(point.y) || 0
        };
    }

    state.terrainModel.updateMatrixWorld(true);

    // The model is centred around its original bounding-box centre.
    // Therefore local X/Z are centred coordinates and must be shifted by
    // half the original raster extent before sending them to backend APIs.
    const local = state.terrainModel.worldToLocal(point);
    const width = Math.max(Number(state.terrainBounds.size.x) || 0, 0);
    const depth = Math.max(Number(state.terrainBounds.size.z) || 0, 0);

    let rasterX = local.x + width * 0.5;
    let rasterY = local.z + depth * 0.5;

    rasterX = width > 0 ? Math.max(0, Math.min(rasterX, width)) : Math.max(0, rasterX);
    rasterY = depth > 0 ? Math.max(0, Math.min(rasterY, depth)) : Math.max(0, rasterY);

    // Height is returned in displayed world units here because the existing
    // height-probe feature applies the vertical-exaggeration correction once.
    return {
        x: Number(rasterX.toFixed(2)),
        y: Number(rasterY.toFixed(2)),
        meshHeight: Number(local.y.toFixed(2))
    };
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

// ============================================================
// TOGGLE HEATMAP MATERIAL
// ============================================================

export function updateTerrainHeatmap() {
    if (!state.terrainModel || state.comparisonEnabled) {
        return;
    }

    state.terrainModel.traverse((child) => {
        if (child.isMesh && child.userData.originalMaterial && child.userData.heatmapMaterial) {
            child.material = state.heatmapEnabled 
                ? child.userData.heatmapMaterial 
                : child.userData.originalMaterial;
        }
    });
}