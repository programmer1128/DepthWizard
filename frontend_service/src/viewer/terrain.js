// ============================================================
// DEPTHWIZARD
// TERRAIN / GLB LOADER
// ============================================================

import * as THREE from 'three';
import { GLTFLoader } from 'three/addons/loaders/GLTFLoader.js';
import { DRACOLoader } from 'three/addons/loaders/DRACOLoader.js';
import { isVegetationVisualizationNode, scientificBounds } from './vegetation.js';
import { setupVegetationTrees, vegetationTreeOptionsFromUrl } from './vegetationTreeRenderer.js';

import {
    scene,
    camera,
    renderer
} from './scene.js';

import {
    gridHelper,
    configureLightingForBounds
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

const COLOR_TEXTURE_KEYS = ['map', 'emissiveMap'];
const DATA_TEXTURE_KEYS = [
    'normalMap', 'roughnessMap', 'metalnessMap', 'aoMap',
    'alphaMap', 'bumpMap', 'displacementMap', 'lightMap'
];

function eachMaterial(object, callback) {
    const materials = Array.isArray(object.material)
        ? object.material
        : [object.material];
    materials.filter(Boolean).forEach(callback);
}

function configureMaterial(material) {
    const maxAnisotropy = renderer.capabilities.getMaxAnisotropy();

    COLOR_TEXTURE_KEYS.forEach((key) => {
        const texture = material[key];
        if (!texture) return;
        texture.colorSpace = THREE.SRGBColorSpace;
        texture.anisotropy = maxAnisotropy;
        texture.needsUpdate = true;
    });

    DATA_TEXTURE_KEYS.forEach((key) => {
        const texture = material[key];
        if (!texture) return;
        texture.colorSpace = THREE.NoColorSpace;
        texture.anisotropy = maxAnisotropy;
        texture.needsUpdate = true;
    });

    material.toneMapped = true;
    if (/roof|wall|building/i.test(material.name || '')) {
        material.flatShading = true;
        material.needsUpdate = true;
    }
}

function buildStyleMaterial(material, style) {
    const clone = material.clone();
    clone.name = `${material.name || 'material'}__${style}`;

    if (style === 'terra') {
        clone.map = null;
        clone.emissiveMap = null;
        clone.vertexColors = false;
        clone.color?.set(0xb9916c);
        clone.roughness = 0.86;
        clone.metalness = 0.0;
    } else if (style === 'scientific') {
        // Preserve authored analytical vertex colours. Plain optical meshes
        // receive a restrained blue so the style remains clearly scientific.
        clone.map = null;
        clone.emissiveMap = null;
        if (!clone.vertexColors) clone.color?.set(0x4c83cf);
        clone.roughness = 0.78;
        clone.metalness = 0.0;
    }

    if (/roof|wall|building/i.test(material.name || '')) {
        clone.flatShading = true;
    }
    configureMaterial(clone);
    clone.needsUpdate = true;
    return clone;
}

export function applyPresentationStyle(style = state.presentationStyle) {
    state.presentationStyle = ['scientific', 'terra', 'orthophoto'].includes(style)
        ? style
        : 'orthophoto';

    if (!state.terrainModel) return;

    state.heatmapEnabled = false;
    dom.heatmapBtn?.classList.remove('active', 'active-green');

    state.terrainModel.traverse((child) => {
        if (child.userData.isPresentationEdge) {
            child.visible = state.presentationStyle === 'scientific';
            return;
        }
        if (!child.isMesh || !child.userData.originalMaterial) return;

        if (state.presentationStyle === 'orthophoto') {
            child.material = child.userData.originalMaterial;
        } else {
            const cacheKey = `${state.presentationStyle}Materials`;
            if (!child.userData[cacheKey]) {
                const original = Array.isArray(child.userData.originalMaterial)
                    ? child.userData.originalMaterial
                    : [child.userData.originalMaterial];
                const styled = original.map((material) =>
                    buildStyleMaterial(material, state.presentationStyle)
                );
                child.userData[cacheKey] = Array.isArray(child.userData.originalMaterial)
                    ? styled
                    : styled[0];
            }
            child.material = child.userData[cacheKey];
        }
    });
}

function fitSceneToTerrain(bounds) {
    const size = bounds.getSize(new THREE.Vector3());
    const center = bounds.getCenter(new THREE.Vector3());
    const horizontal = Math.max(size.x, size.z, 1);
    const vertical = Math.max(size.y, 1);
    const fov = THREE.MathUtils.degToRad(camera.fov);
    const fitHeightDistance = (Math.max(horizontal * 0.62, vertical) * 0.5) /
        Math.tan(fov * 0.5);
    const fitWidthDistance = fitHeightDistance / Math.max(camera.aspect, 0.5);
    const cameraDistance = Math.max(fitHeightDistance, fitWidthDistance, horizontal) * 1.15;

    camera.position.set(
        center.x + cameraDistance * 0.78,
        center.y + cameraDistance * 0.58,
        center.z + cameraDistance * 0.78
    );
    camera.near = Math.max(horizontal / 5000, 0.05);
    camera.far = Math.max(cameraDistance * 12, horizontal * 8);
    camera.updateProjectionMatrix();
    camera.lookAt(center);

    orbitControls.target.copy(center);
    orbitControls.minDistance = Math.max(horizontal * 0.015, 0.5);
    orbitControls.maxDistance = cameraDistance * 6;
    orbitControls.update();

    // Fog follows tile scale and starts beyond the model rather than obscuring
    // geometry at a fixed world-space distance.
    scene.fog = new THREE.Fog(0x101927, cameraDistance * 1.5, cameraDistance * 5.5);
    gridHelper.scale.setScalar(Math.max(horizontal * 1.65 / 1200, 0.02));
    gridHelper.position.y = bounds.min.y - Math.max(horizontal * 0.002, 0.02);

    configureLightingForBounds(bounds);
    return cameraDistance;
}

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

    state.vegetationTrees?.dispose();
    state.vegetationTrees = null;

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

                // Scientific reference bounds: vegetation proxies (canopy,
                // trees, shrubs) must not move the model centre or the
                // raster mapping used by the height APIs.
                const box =
                    scientificBounds(model);

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

                // Instanced vegetation proxies: bounds for culling, one LOD
                // level per batch before the first render (null without them).
                state.vegetationTrees = setupVegetationTrees(
                    model,
                    vegetationTreeOptionsFromUrl(window.location.search)
                );

                // Prepare the stable comparison shader before first render.
                //patchTerrainModel(model);

                // ------------------------------------------------------------
// PRESERVE ORIGINAL GLB MATERIALS
// ------------------------------------------------------------
// IMPORTANT:
// Do NOT generate heatmap colors while loading the GLB.
//
// The default state must remain exactly as authored in the GLB.
// Heatmap colors/materials are created only when the user
// explicitly activates Heatmap mode.

model.traverse((child) => {
    const isEdgeObject = child.isLine ||
        child.isLineSegments ||
        (child.material && []
            .concat(child.material)
            .some((material) => /edge|outline/i.test(material?.name || '')));

    if (isEdgeObject) {
        child.userData.isPresentationEdge = true;
        child.visible = state.presentationStyle === 'scientific';
        return;
    }

    if (!child.isMesh) return;

    child.castShadow = true;
    child.receiveShadow = true;

    // Preserve the exact original GLB material for orthophoto mode.
    child.userData.originalMaterial = child.material;
    child.userData.originalColorAttribute =
        child.geometry.getAttribute('color') || null;
    eachMaterial(child, configureMaterial);
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

            fitSceneToTerrain(centeredBox);
            applyPresentationStyle(state.presentationStyle);

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

    const centeredSize = centeredBox.getSize(new THREE.Vector3());
    gridHelper.position.y = centeredBox.min.y -
        Math.max(Math.max(centeredSize.x, centeredSize.z) * 0.002, 0.02);
    configureLightingForBounds(centeredBox);

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

    if (!state.terrainModel) {
        return;
    }

    state.terrainModel.traverse((child) => {

        if (!child.isMesh || !child.geometry) {
            return;
        }

        // Vegetation keeps its own material: the heatmap is scientific.
        if (isVegetationVisualizationNode(child)) {
            return;
        }

        // ----------------------------------------------------
        // HEATMAP ON
        // ----------------------------------------------------

        if (state.heatmapEnabled) {

            // Create heatmap material only when requested.
            if (!child.userData.heatmapMaterial) {

                const geometry =
                    child.geometry;

                geometry.computeBoundingBox();

                const minY =
                    geometry.boundingBox?.min.y ?? 0;

                const maxY =
                    geometry.boundingBox?.max.y ?? 1;

                const range =
                    Math.max(
                        maxY - minY,
                        0.0001
                    );

                const positions =
                    geometry.attributes.position;

                if (!positions) {
                    return;
                }

                const colors = [];
                const color =
                    new THREE.Color();

                for (
                    let i = 0;
                    i < positions.count;
                    i++
                ) {

                    const y =
                        positions.getY(i);

                    const normalized =
                        THREE.MathUtils.clamp(
                            (y - minY) / range,
                            0,
                            1
                        );

                    const hue =
                        (1.0 - normalized) * 0.66;

                    color.setHSL(
                        hue,
                        1.0,
                        0.5
                    );

                    colors.push(
                        color.r,
                        color.g,
                        color.b
                    );
                }

                geometry.setAttribute(
                    'color',
                    new THREE.Float32BufferAttribute(
                        colors,
                        3
                    )
                );

                child.userData.heatmapMaterial =
                    new THREE.MeshStandardMaterial({

                        vertexColors: true,

                        roughness: 0.8,

                        metalness: 0.05
                    });
            }

            child.material =
                child.userData.heatmapMaterial;

        }

        // ----------------------------------------------------
        // HEATMAP OFF
        // ----------------------------------------------------

        else {

            child.material =
                child.userData.originalMaterial;

            // Remove the generated heatmap colors.
            // This is CRITICAL because otherwise the original
            // GLB material may continue seeing the generated
            // vertex-color attribute.

            if (
                child.userData.originalColorAttribute
            ) {

                child.geometry.setAttribute(
                    'color',
                    child.userData.originalColorAttribute
                );

            } else {

                child.geometry.deleteAttribute(
                    'color'
                );
            }
        }

    });
}