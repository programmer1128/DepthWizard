import * as THREE from 'three';
import { OrbitControls } from 'three/examples/jsm/controls/OrbitControls.js';
import { FlyControls } from 'three/examples/jsm/controls/FlyControls.js';
import { GLTFLoader } from 'three/examples/jsm/loaders/GLTFLoader.js';
import { DRACOLoader } from 'three/examples/jsm/loaders/DRACOLoader.js';

// ============================================================
// 1. DOM REFERENCES & UI BINDINGS
// ============================================================
const container = document.getElementById('canvas-container');

// Top bar telemetry
const topModeText = document.getElementById('topModeText');
const topGridText = document.getElementById('topGridText');

// Viewer HUD
const viewerStatus = document.getElementById('viewerStatus');
const systemStatus = document.getElementById('systemStatus');
const fileStatus = document.getElementById('fileStatus');
const statusDot = document.getElementById('statusDot');
const hudStatusDot = document.getElementById('hudStatusDot');
const currentModeBadge = document.getElementById('currentModeBadge');
const routeBanner = document.getElementById('routeBanner');

// Empty State Canvas Overlay
const emptyStateOverlay = document.getElementById('emptyStateOverlay');
const emptyUploadTrigger = document.getElementById('emptyUploadTrigger');
const emptyDemoTrigger = document.getElementById('emptyDemoTrigger');

// File Upload & Preview
const imageInput = document.getElementById('imageInput');
const fileDropzone = document.getElementById('fileDropzone');
const selectedFileName = document.getElementById('selectedFileName');
const selectedFileSize = document.getElementById('selectedFileSize');
const thumbnailPreview = document.getElementById('thumbnailPreview');
const uploadBtn = document.getElementById('uploadBtn');
const demoBtn = document.getElementById('demoBtn');

// 2D vs 3D Picture-in-Picture (PiP)
const pipToggle = document.getElementById('pipToggle');
const comparisonPiP = document.getElementById('comparisonPiP');
const pipImage = document.getElementById('pipImage');
const pipPlaceholder = document.getElementById('pipPlaceholder');
const pipFilename = document.getElementById('pipFilename');
const pipDimensions = document.getElementById('pipDimensions');
const pipMinimizeBtn = document.getElementById('pipMinimizeBtn');
const pipCloseBtn = document.getElementById('pipCloseBtn');

// Navigation Controls
const orbitBtn = document.getElementById('orbitBtn');
const flyBtn = document.getElementById('flyBtn');
const resetBtn = document.getElementById('resetBtn');
const gridBtn = document.getElementById('gridBtn');

// Route Planning Controls
const drawRouteBtn = document.getElementById('drawRouteBtn');
const clearRouteBtn = document.getElementById('clearRouteBtn');
const flyRouteBtn = document.getElementById('flyRouteBtn');
const flyRouteBtnText = document.getElementById('flyRouteBtnText');
const routeWaypointsBadge = document.getElementById('routeWaypointsBadge');
const routePointsCount = document.getElementById('routePointsCount');
const routeDistance = document.getElementById('routeDistance');
const routeStatus = document.getElementById('routeStatus');

// Help & Fullscreen
const helpBtn = document.getElementById('helpBtn');
const closeHelpBtn = document.getElementById('closeHelpBtn');
const helpPanel = document.getElementById('help-panel');
const fullscreenBtn = document.getElementById('fullscreenBtn');

// ============================================================
// 2. STATUS HELPER FUNCTIONS
// ============================================================
function setViewerStatus(message, type = 'ready') {
  if (viewerStatus) viewerStatus.textContent = message;

  const dotClass = type === 'loading' ? 'loading' : type === 'error' ? 'error' : 'ready';

  if (statusDot) statusDot.className = `status-dot ${dotClass}`;
  if (hudStatusDot) hudStatusDot.className = `status-dot ${dotClass}`;

  if (systemStatus) {
    if (type === 'loading') {
      systemStatus.textContent = 'Processing / Loading';
    } else if (type === 'error') {
      systemStatus.textContent = 'System Alert';
    } else {
      systemStatus.textContent = 'Viewer Ready';
    }
  }
}

function setInteractionMode(mode) {
  if (currentModeBadge) currentModeBadge.textContent = mode;
  if (topModeText) topModeText.textContent = `${mode} VIEW`;
}

// ============================================================
// 3. THREE.JS SCENE SETUP
// ============================================================
const scene = new THREE.Scene();
scene.background = new THREE.Color(0x1a1a24);

// Lighting
const ambientLight = new THREE.AmbientLight(0xffffff, 1.6);
scene.add(ambientLight);

const directionalLight = new THREE.DirectionalLight(0xffffff, 2.2);
directionalLight.position.set(250, 500, 250);
scene.add(directionalLight);

const secondaryLight = new THREE.DirectionalLight(0x38bdf8, 0.8);
secondaryLight.position.set(-200, -200, -200);
scene.add(secondaryLight);

// Ground Reference Grid (visible by default on startup)
const gridHelper = new THREE.GridHelper(1200, 48, 0x38bdf8, 0x242d3d);
gridHelper.position.y = 0;
gridHelper.visible = true;
scene.add(gridHelper);

// Camera Setup
const camera = new THREE.PerspectiveCamera(
  55,
  container.clientWidth / container.clientHeight,
  0.1,
  10000
);
camera.position.set(160, 110, 200);
camera.lookAt(0, 0, 0);

// Renderer Setup
const renderer = new THREE.WebGLRenderer({
  antialias: true,
  powerPreference: 'high-performance'
});
renderer.setSize(container.clientWidth, container.clientHeight);
renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2));
renderer.toneMapping = THREE.ACESFilmicToneMapping;
renderer.toneMappingExposure = 1.1;
container.appendChild(renderer.domElement);

// Controls Setup
const orbitControls = new OrbitControls(camera, renderer.domElement);
orbitControls.enableDamping = true;
orbitControls.dampingFactor = 0.06;
orbitControls.maxDistance = 6000;
orbitControls.minDistance = 2;
orbitControls.target.set(0, 0, 0);

const flyControls = new FlyControls(camera, renderer.domElement);
flyControls.movementSpeed = 60;
flyControls.rollSpeed = Math.PI / 10;
flyControls.dragToLook = true;
flyControls.enabled = false;

// Initial camera tracking vectors
const initialCameraPosition = new THREE.Vector3().copy(camera.position);
const initialCameraTarget = new THREE.Vector3().copy(orbitControls.target);
let initialCameraZoom = camera.zoom;

// ============================================================
// 4. APPLICATION STATE & ROUTE VARIABLES
// ============================================================
let terrainModel = null;
let currentLoadedUrl = null;
let freeFlyMode = false;
let currentPreviewUrl = null;

// Route Planning Variables (Unlimited Waypoints & Terrain Snapping)
let isDrawingRoute = false;
let isFlyingRoute = false;
let routeWaypoints = [];          // THREE.Vector3[] (User clicked points, N waypoints)
let routeMarkerMeshes = [];       // THREE.Mesh[] (Waypoint visual markers)
let routeLineMesh = null;         // THREE.Line (Surface-following route line)
let routeSurfaceCurve = null;     // THREE.CatmullRomCurve3 (Terrain-snapped surface spline)
let flyProgress = 0.0;            // 0.0 to 1.0 along routeSurfaceCurve
const FLY_SPEED = 0.05;           // Progress increment speed per second
const FLY_CAMERA_Y_OFFSET = 30.0; // Fixed vertical height clearance above terrain
let currentRouteCalculationId = 0; // Monotonic token to safely handle async overlap

// Raycaster & Interaction
const raycaster = new THREE.Raycaster();
const mouse = new THREE.Vector2();

// ============================================================
// 5. GLTF / DRACO MODEL LOADER
// ============================================================
const gltfLoader = new GLTFLoader();
const dracoLoader = new DRACOLoader();
dracoLoader.setDecoderPath('/draco/');
gltfLoader.setDRACOLoader(dracoLoader);

function loadTerrainGLB(url) {
  setViewerStatus('LOADING 3D TERRAIN', 'loading');
  if (fileStatus) fileStatus.textContent = 'Downloading and decompressing GLB mesh...';

  // Cleanup existing terrain model
  if (terrainModel) {
    scene.remove(terrainModel);
    terrainModel.traverse((child) => {
      if (child.isMesh) {
        child.geometry.dispose();
        if (child.material) {
          if (Array.isArray(child.material)) {
            child.material.forEach(m => m.dispose());
          } else {
            child.material.dispose();
          }
        }
      }
    });
    terrainModel = null;
  }

  // Clear previous route when new terrain is loaded
  clearRoute();

  gltfLoader.load(
    url,
    (gltf) => {
      console.log('GLB loaded successfully:', url);
      currentLoadedUrl = url;

      const model = gltf.scene;
      terrainModel = model;
      scene.add(model);

      // Center model around origin
      const box = new THREE.Box3().setFromObject(model);
      const center = box.getCenter(new THREE.Vector3());
      const size = box.getSize(new THREE.Vector3());

      model.position.sub(center);

      // Place reference grid right below the lowest terrain point
      const centeredBox = new THREE.Box3().setFromObject(model);
      gridHelper.position.y = centeredBox.min.y - 1;

      // Adjust camera distance to frame newly loaded mesh
      const maxDim = Math.max(size.x, size.y, size.z);
      const camDistance = Math.max(maxDim * 1.4, 40);

      camera.position.set(camDistance, camDistance * 0.75, camDistance);
      camera.lookAt(0, 0, 0);
      orbitControls.target.set(0, 0, 0);
      orbitControls.update();

      initialCameraPosition.copy(camera.position);
      initialCameraTarget.copy(orbitControls.target);
      initialCameraZoom = camera.zoom;

      // Hide empty state overlay once model is successfully loaded
      if (emptyStateOverlay) {
        emptyStateOverlay.classList.add('hidden');
      }

      setViewerStatus('3D VIEWER READY', 'ready');
      if (fileStatus) {
        fileStatus.textContent = `Mesh active: ${(size.x).toFixed(0)} × ${(size.z).toFixed(0)} units (Elevation span: ${(size.y).toFixed(1)}m)`;
      }
    },
    (progress) => {
      if (progress.total > 0) {
        const percent = ((progress.loaded / progress.total) * 100).toFixed(0);
        setViewerStatus(`LOADING ${percent}%`, 'loading');
      }
    },
    (error) => {
      console.error('GLB Load Error:', error);
      setViewerStatus('MESH LOAD ERROR', 'error');
      if (fileStatus) {
        fileStatus.textContent = 'Failed to load 3D terrain model.';
      }
    }
  );
}

// ============================================================
// 6. TERRAIN-FOLLOWING ROUTE PLANNING (Actions 1, 2, 3, 4)
// ============================================================

/**
 * Action 2 & 3: Terrain Snapping Algorithm & Surface Curve Rebuilding (Asynchronous with Chunking)
 * Samples the initial spline connecting N waypoints, casts rays downwards
 * from high elevation against terrainModel in small batches (12 points/chunk),
 * yielding to the main thread via requestAnimationFrame between chunks to prevent UI freeze.
 * Aborts any previous in-flight calculation if new waypoints are added concurrently.
 */
async function updateRouteLine() {
  // Overlap handling: increment token to cancel any previous in-flight calculation
  const calculationId = ++currentRouteCalculationId;

  // Need at least 2 points to generate a path
  if (routeWaypoints.length < 2) {
    if (routeLineMesh) {
      scene.remove(routeLineMesh);
      routeLineMesh.geometry.dispose();
      routeLineMesh.material.dispose();
      routeLineMesh = null;
    }
    routeSurfaceCurve = null;
    if (flyRouteBtn) flyRouteBtn.disabled = true;
    if (drawRouteBtn) drawRouteBtn.disabled = false;
    if (routeDistance) routeDistance.textContent = '0.0 m';
    if (routeStatus) routeStatus.textContent = routeWaypoints.length === 1 ? 'Add 2nd waypoint' : 'Inactive';
    setViewerStatus('3D VIEWER READY', 'ready');
    return;
  }

  // Loading States
  if (routeStatus) routeStatus.textContent = 'Calculating terrain surface...';
  if (drawRouteBtn) drawRouteBtn.disabled = true;
  if (flyRouteBtn) flyRouteBtn.disabled = true;
  setViewerStatus('CALCULATING ROUTE', 'loading');

  // Step 1: Initial guide spline connecting user's N waypoints
  const initialGuideCurve = new THREE.CatmullRomCurve3(routeWaypoints, false, 'catmullrom', 0.5);

  // Step 2: Sample initial spline at fine intervals (minimum 120 points)
  const sampleCount = Math.max(routeWaypoints.length * 35, 120);
  const initialSamples = initialGuideCurve.getPoints(sampleCount);

  // Step 3: Downward raycasting with chunking
  const downRaycaster = new THREE.Raycaster();
  const downDir = new THREE.Vector3(0, -1, 0);
  const surfaceSnappedPoints = [];
  const CHUNK_SIZE = 12; // Process 10-15 points per chunk to keep frame rate silky smooth

  for (let i = 0; i < initialSamples.length; i += CHUNK_SIZE) {
    // Check if aborted by a newer invocation
    if (calculationId !== currentRouteCalculationId) {
      return;
    }

    const chunkEnd = Math.min(i + CHUNK_SIZE, initialSamples.length);

    for (let j = i; j < chunkEnd; j++) {
      const sample = initialSamples[j];

      if (terrainModel) {
        const rayOrigin = new THREE.Vector3(sample.x, 10000, sample.z);
        downRaycaster.set(rayOrigin, downDir);
        const hits = downRaycaster.intersectObject(terrainModel, true);

        if (hits.length > 0) {
          surfaceSnappedPoints.push(new THREE.Vector3(sample.x, hits[0].point.y + 1.0, sample.z));
        } else {
          surfaceSnappedPoints.push(sample.clone());
        }
      } else {
        surfaceSnappedPoints.push(new THREE.Vector3(sample.x, gridHelper.position.y + 0.5, sample.z));
      }
    }

    // Yield to main thread via requestAnimationFrame
    await new Promise(resolve => requestAnimationFrame(resolve));
  }

  // Final check: if aborted while yielding on the last chunk, do not commit
  if (calculationId !== currentRouteCalculationId) {
    return;
  }

  // Remove existing line mesh before adding the new one
  if (routeLineMesh) {
    scene.remove(routeLineMesh);
    routeLineMesh.geometry.dispose();
    routeLineMesh.material.dispose();
    routeLineMesh = null;
  }

  // Rebuild final CatmullRomCurve3 using surface-snapped points
  routeSurfaceCurve = new THREE.CatmullRomCurve3(surfaceSnappedPoints, false, 'catmullrom', 0.25);

  // Render glowing line hugging the terrain
  const visualPoints = routeSurfaceCurve.getPoints(surfaceSnappedPoints.length);
  const lineGeometry = new THREE.BufferGeometry().setFromPoints(visualPoints);
  const lineMaterial = new THREE.LineBasicMaterial({
    color: 0x38bdf8,
    linewidth: 3,
    transparent: true,
    opacity: 0.95
  });

  routeLineMesh = new THREE.Line(lineGeometry, lineMaterial);
  scene.add(routeLineMesh);

  // Calculate actual surface contour distance
  let totalDistance = 0;
  for (let i = 0; i < visualPoints.length - 1; i++) {
    totalDistance += visualPoints[i].distanceTo(visualPoints[i + 1]);
  }

  if (routeDistance) routeDistance.textContent = `${totalDistance.toFixed(1)} m`;

  // Restore States
  if (routeStatus) routeStatus.textContent = `${routeWaypoints.length} waypoints (Ready)`;
  if (drawRouteBtn) drawRouteBtn.disabled = false;
  if (flyRouteBtn) flyRouteBtn.disabled = false;
  setViewerStatus('3D VIEWER READY', 'ready');
}

/**
 * Action 1 (Unlimited Waypoints):
 * Click N times to place multiple waypoints on the mesh.
 */
function addWaypoint(worldPoint) {
  const point = worldPoint.clone();
  point.y += 1.5; // Elevate waypoint sphere slightly above surface

  const sphereGeo = new THREE.SphereGeometry(2.0, 18, 18);
  const sphereMat = new THREE.MeshStandardMaterial({
    color: 0xf43f5e,
    emissive: 0xf43f5e,
    emissiveIntensity: 0.85,
    roughness: 0.2,
    metalness: 0.2
  });

  const marker = new THREE.Mesh(sphereGeo, sphereMat);
  marker.position.copy(point);
  scene.add(marker);

  // Store in array
  routeWaypoints.push(point);
  routeMarkerMeshes.push(marker);

  // Update UI stats
  if (routePointsCount) routePointsCount.textContent = routeWaypoints.length;
  if (routeWaypointsBadge) routeWaypointsBadge.textContent = `${routeWaypoints.length} Pts`;

  // Re-generate surface-snapped route line
  updateRouteLine();
}

function clearRoute() {
  // Invalidate any ongoing asynchronous calculation immediately
  currentRouteCalculationId++;

  if (isFlyingRoute) stopRouteFlythrough();

  // Remove and dispose waypoint marker meshes
  routeMarkerMeshes.forEach(marker => {
    scene.remove(marker);
    marker.geometry.dispose();
    marker.material.dispose();
  });
  routeMarkerMeshes = [];
  routeWaypoints = [];

  // Remove and dispose line mesh
  if (routeLineMesh) {
    scene.remove(routeLineMesh);
    routeLineMesh.geometry.dispose();
    routeLineMesh.material.dispose();
    routeLineMesh = null;
  }
  routeSurfaceCurve = null;

  // Reset UI counters & restore button states
  if (routePointsCount) routePointsCount.textContent = '0';
  if (routeWaypointsBadge) routeWaypointsBadge.textContent = '0 Pts';
  if (routeDistance) routeDistance.textContent = '0.0 m';
  if (routeStatus) routeStatus.textContent = 'Inactive';
  if (drawRouteBtn) drawRouteBtn.disabled = false;
  if (flyRouteBtn) flyRouteBtn.disabled = true;
  setViewerStatus('3D VIEWER READY', 'ready');
}

function toggleDrawRouteMode() {
  if (isFlyingRoute) stopRouteFlythrough();

  isDrawingRoute = !isDrawingRoute;

  if (isDrawingRoute) {
    drawRouteBtn.classList.add('active');
    if (routeBanner) routeBanner.style.display = 'flex';
    setInteractionMode('DRAW ROUTE');
  } else {
    drawRouteBtn.classList.remove('active');
    if (routeBanner) routeBanner.style.display = 'none';
    setInteractionMode(freeFlyMode ? 'FREE FLY' : 'ORBIT');
  }
}

function startRouteFlythrough() {
  if (!routeSurfaceCurve || routeWaypoints.length < 2) return;

  if (isDrawingRoute) toggleDrawRouteMode();

  isFlyingRoute = true;
  flyProgress = 0.0;

  // Disable interactive orbit/fly controls during cinematic flythrough
  orbitControls.enabled = false;
  flyControls.enabled = false;

  flyRouteBtn.classList.add('flying');
  if (flyRouteBtnText) flyRouteBtnText.textContent = 'Stop Flythrough';
  setInteractionMode('FLYING ROUTE');
  if (routeStatus) routeStatus.textContent = 'Terrain Flythrough Active...';
}

function stopRouteFlythrough() {
  isFlyingRoute = false;

  flyRouteBtn.classList.remove('flying');
  if (flyRouteBtnText) flyRouteBtnText.textContent = 'Fly Route';

  // Restore previous user navigation mode
  if (freeFlyMode) {
    flyControls.enabled = true;
    orbitControls.enabled = false;
    setInteractionMode('FREE FLY');
  } else {
    orbitControls.enabled = true;
    flyControls.enabled = false;
    setInteractionMode('ORBIT');
  }

  if (routeStatus) routeStatus.textContent = `${routeWaypoints.length} waypoints (Ready)`;
}

// Raycaster Click Handler for Unlimited Waypoint Placement
renderer.domElement.addEventListener('click', (event) => {
  if (!isDrawingRoute) return;

  const rect = renderer.domElement.getBoundingClientRect();
  mouse.x = ((event.clientX - rect.left) / rect.width) * 2 - 1;
  mouse.y = -((event.clientY - rect.top) / rect.height) * 2 + 1;

  raycaster.setFromCamera(mouse, camera);

  let intersects = [];

  // Target terrain mesh (ignoring waypoint spheres and line)
  if (terrainModel) {
    intersects = raycaster.intersectObject(terrainModel, true);
  }

  // Fallback to ground grid if drawing before loading terrain
  if (intersects.length === 0 && gridHelper.visible) {
    intersects = raycaster.intersectObject(gridHelper, true);
  }

  if (intersects.length > 0) {
    const hitPoint = intersects[0].point;
    addWaypoint(hitPoint);
  }
});

// ============================================================
// 7. GEOTIFF & OPTICAL IMAGE RENDERING IN 2D PIP (Fix 1)
// ============================================================

/**
 * Parses .tif / .tiff files using GeoTIFF.fromBlob(), extracts RGB raster data,
 * renders onto an off-screen HTML5 canvas, and extracts data URL for 2D PiP display.
 * For .jpg / .png, uses standard URL.createObjectURL.
 */
async function updateComparisonImage(file) {
  if (!file) return;

  const fileName = file.name.toLowerCase();
  const isTiff = fileName.endsWith('.tif') || fileName.endsWith('.tiff');

  // Clean up previous preview URL to prevent memory leaks
  if (currentPreviewUrl && currentPreviewUrl.startsWith('blob:')) {
    URL.revokeObjectURL(currentPreviewUrl);
    currentPreviewUrl = null;
  }

  if (isTiff) {
    // ------------------------------------------------------------
    // GeoTIFF rendering via off-screen HTML5 canvas
    // ------------------------------------------------------------
    setViewerStatus('PARSING GEOTIFF', 'loading');
    if (pipFilename) pipFilename.textContent = `Parsing ${file.name}...`;

    try {
      // Obtain GeoTIFF library from window.GeoTIFF (loaded via CDN)
      const GeoTIFFLib = window.GeoTIFF || (typeof GeoTIFF !== 'undefined' ? GeoTIFF : null);

      if (!GeoTIFFLib) {
        throw new Error('GeoTIFF parser is not available. Please verify network or CDN connection.');
      }

      console.log('Parsing GeoTIFF file with geotiff.js:', file.name);
      const tiff = await GeoTIFFLib.fromBlob(file);
      const image = await tiff.getImage();
      const width = image.getWidth();
      const height = image.getHeight();

      console.log(`GeoTIFF dimensions: ${width}×${height}px, bands: ${image.getSamplesPerPixel()}`);

      // Read RGB raster data
      let rgbData;
      try {
        rgbData = await image.readRGB({ interleave: true });
      } catch (rgbErr) {
        console.warn('image.readRGB failed, falling back to readRasters:', rgbErr);
      }

      // Create off-screen canvas to render raster data
      const offscreenCanvas = document.createElement('canvas');
      offscreenCanvas.width = width;
      offscreenCanvas.height = height;
      const ctx = offscreenCanvas.getContext('2d');
      const imgData = ctx.createImageData(width, height);

      if (rgbData && rgbData.length === width * height * 3) {
        // Interleaved RGB 8-bit array
        for (let i = 0, j = 0; i < rgbData.length; i += 3, j += 4) {
          imgData.data[j] = rgbData[i];
          imgData.data[j + 1] = rgbData[i + 1];
          imgData.data[j + 2] = rgbData[i + 2];
          imgData.data[j + 3] = 255;
        }
      } else if (rgbData && rgbData.length === width * height * 4) {
        // RGBA array
        imgData.data.set(rgbData);
      } else {
        // Fallback: read raw raster bands (handles single-band grayscale or multi-band)
        const rasters = await image.readRasters();
        const numBands = rasters.length;
        const rBand = rasters[0];
        const gBand = numBands >= 3 ? rasters[1] : rBand;
        const bBand = numBands >= 3 ? rasters[2] : rBand;

        // Determine min and max for normalization if 16-bit or float DEM
        let minVal = Infinity;
        let maxVal = -Infinity;
        for (let i = 0; i < rBand.length; i++) {
          if (rBand[i] < minVal) minVal = rBand[i];
          if (rBand[i] > maxVal) maxVal = rBand[i];
        }
        const valRange = maxVal > minVal ? maxVal - minVal : 1;
        const isByte = maxVal <= 255 && minVal >= 0;

        for (let i = 0, j = 0; i < rBand.length; i++, j += 4) {
          if (isByte) {
            imgData.data[j] = rBand[i];
            imgData.data[j + 1] = gBand[i];
            imgData.data[j + 2] = bBand[i];
          } else {
            // Normalize to 0-255 for display
            const rNorm = Math.floor(((rBand[i] - minVal) / valRange) * 255);
            const gNorm = Math.floor(((gBand[i] - minVal) / valRange) * 255);
            const bNorm = Math.floor(((bBand[i] - minVal) / valRange) * 255);
            imgData.data[j] = rNorm;
            imgData.data[j + 1] = gNorm;
            imgData.data[j + 2] = bNorm;
          }
          imgData.data[j + 3] = 255;
        }
      }

      ctx.putImageData(imgData, 0, 0);

      // Extract data URL from off-screen canvas (scale down if > 2048 for smooth UI performance)
      let finalDataUrl;
      if (width > 2048 || height > 2048) {
        const maxDimension = 2048;
        const scale = maxDimension / Math.max(width, height);
        const scaledCanvas = document.createElement('canvas');
        scaledCanvas.width = Math.round(width * scale);
        scaledCanvas.height = Math.round(height * scale);
        const sCtx = scaledCanvas.getContext('2d');
        sCtx.drawImage(offscreenCanvas, 0, 0, scaledCanvas.width, scaledCanvas.height);
        finalDataUrl = scaledCanvas.toDataURL('image/jpeg', 0.9);
      } else {
        finalDataUrl = offscreenCanvas.toDataURL('image/png');
      }

      currentPreviewUrl = finalDataUrl;

      // Update 2D PiP window
      if (pipImage) {
        pipImage.src = finalDataUrl;
        pipImage.style.display = 'block';
      }
      if (pipPlaceholder) pipPlaceholder.style.display = 'none';
      if (thumbnailPreview) {
        thumbnailPreview.src = finalDataUrl;
        thumbnailPreview.style.display = 'block';
      }
      if (pipFilename) pipFilename.textContent = file.name;
      if (pipDimensions) pipDimensions.textContent = `${width}×${height}px (GeoTIFF)`;

      if (pipToggle && pipToggle.checked && comparisonPiP) {
        comparisonPiP.classList.remove('hidden');
      }

      setViewerStatus('GEOTIFF RENDERED', 'ready');
      if (fileStatus) fileStatus.textContent = `GeoTIFF ready: ${width}×${height}px optical raster`;
    } catch (err) {
      console.error('Failed to parse GeoTIFF:', err);
      setViewerStatus('GEOTIFF PARSE ERROR', 'error');
      if (pipFilename) pipFilename.textContent = 'GeoTIFF error';
      if (pipDimensions) pipDimensions.textContent = err.message;
      if (fileStatus) fileStatus.textContent = `GeoTIFF parse failed: ${err.message}`;
    }
  } else {
    // ------------------------------------------------------------
    // Standard .jpg / .png: use standard URL.createObjectURL
    // ------------------------------------------------------------
    const objectUrl = URL.createObjectURL(file);
    currentPreviewUrl = objectUrl;

    if (pipImage) {
      pipImage.src = objectUrl;
      pipImage.style.display = 'block';
    }
    if (pipPlaceholder) pipPlaceholder.style.display = 'none';
    if (thumbnailPreview) {
      thumbnailPreview.src = objectUrl;
      thumbnailPreview.style.display = 'block';
    }
    if (pipFilename) pipFilename.textContent = file.name;

    const tempImg = new Image();
    tempImg.onload = () => {
      if (pipDimensions) pipDimensions.textContent = `${tempImg.naturalWidth}×${tempImg.naturalHeight}px`;
    };
    tempImg.src = objectUrl;

    if (pipToggle && pipToggle.checked && comparisonPiP) {
      comparisonPiP.classList.remove('hidden');
    }
  }
}

// PiP Toggle Switch
if (pipToggle) {
  pipToggle.addEventListener('change', () => {
    if (pipToggle.checked) {
      comparisonPiP.classList.remove('hidden');
    } else {
      comparisonPiP.classList.add('hidden');
    }
  });
}

// PiP Close & Minimize Buttons
if (pipCloseBtn) {
  pipCloseBtn.addEventListener('click', () => {
    comparisonPiP.classList.add('hidden');
    if (pipToggle) pipToggle.checked = false;
  });
}

if (pipMinimizeBtn) {
  pipMinimizeBtn.addEventListener('click', () => {
    comparisonPiP.classList.toggle('minimized');
    pipMinimizeBtn.textContent = comparisonPiP.classList.contains('minimized') ? '+' : '_';
  });
}

// ============================================================
// 8. FILE INPUT & BACKEND PIPELINE
// ============================================================
imageInput.addEventListener('change', () => {
  const file = imageInput.files[0];
  if (!file) {
    if (selectedFileName) selectedFileName.textContent = 'No file chosen';
    if (selectedFileSize) selectedFileSize.textContent = 'Ready for upload';
    if (thumbnailPreview) thumbnailPreview.style.display = 'none';
    return;
  }

  const sizeMB = (file.size / (1024 * 1024)).toFixed(2);
  if (selectedFileName) selectedFileName.textContent = file.name;
  if (selectedFileSize) selectedFileSize.textContent = `${file.type || 'Satellite Image'} • ${sizeMB} MB`;
  if (fileStatus) fileStatus.textContent = `Imagery selected: ${file.name}`;

  // Update 2D PiP comparison (handles GeoTIFF canvas or URL.createObjectURL)
  updateComparisonImage(file);
});

// Drag and drop events for file dropzone
['dragenter', 'dragover'].forEach(eventName => {
  fileDropzone.addEventListener(eventName, (e) => {
    e.preventDefault();
    fileDropzone.classList.add('dragover');
  }, false);
});

['dragleave', 'drop'].forEach(eventName => {
  fileDropzone.addEventListener(eventName, (e) => {
    e.preventDefault();
    fileDropzone.classList.remove('dragover');
  }, false);
});

fileDropzone.addEventListener('drop', (e) => {
  const dt = e.dataTransfer;
  const files = dt.files;
  if (files.length > 0) {
    imageInput.files = files;
    imageInput.dispatchEvent(new Event('change'));
  }
});

// Backend Upload Processor
uploadBtn.addEventListener('click', async () => {
  const file = imageInput.files[0];
  if (!file) {
    alert('Please select satellite imagery (.png, .jpg, or .tif) first.');
    return;
  }

  const formData = new FormData();
  formData.append('image', file);

  try {
    setViewerStatus('PROCESSING UPLOAD', 'loading');
    if (fileStatus) fileStatus.textContent = 'Transmitting image to height estimation backend...';
    uploadBtn.disabled = true;

    const response = await fetch('http://localhost:8080/api/v1/processor', {
      method: 'POST',
      body: formData
    });

    if (!response.ok) {
      throw new Error(`Server returned HTTP ${response.status}`);
    }

    const result = await response.json();
    console.log('Backend pipeline response:', result);

    if (result.status === 'success' && result.saved_file) {
      if (fileStatus) fileStatus.textContent = 'Pipeline complete. Loading generated 3D mesh...';
      loadTerrainGLB(result.saved_file);
    } else {
      throw new Error(result.message || 'Height estimation pipeline did not return a GLB mesh.');
    }
  } catch (error) {
    console.error('Backend upload failed:', error);
    setViewerStatus('UPLOAD FAILED', 'error');
    if (fileStatus) {
      fileStatus.textContent = `Backend error: ${error.message}. Is localhost:8080 running?`;
    }
  } finally {
    uploadBtn.disabled = false;
  }
});

// Demo Loader Buttons
function loadDemoTerrain() {
  console.log('Loading demo terrain (/test_8_output.glb)...');
  loadTerrainGLB('/test_8_output.glb');

  if (thumbnailPreview) {
    thumbnailPreview.src = '/icons.svg';
    thumbnailPreview.style.display = 'block';
  }
  if (selectedFileName) selectedFileName.textContent = 'test_8_output.glb (Demo)';
  if (selectedFileSize) selectedFileSize.textContent = 'ISRO Satellite Sample';
  if (pipFilename) pipFilename.textContent = 'Demo Terrain Mesh';
}

demoBtn.addEventListener('click', loadDemoTerrain);
emptyDemoTrigger.addEventListener('click', loadDemoTerrain);
emptyUploadTrigger.addEventListener('click', () => imageInput.click());

// ============================================================
// 9. NAVIGATION & VIEW CONTROLS
// ============================================================
// Orbit Mode Button
orbitBtn.addEventListener('click', () => {
  if (isFlyingRoute) stopRouteFlythrough();

  freeFlyMode = false;
  orbitControls.enabled = true;
  flyControls.enabled = false;

  orbitBtn.classList.add('active');
  flyBtn.classList.remove('active');
  setInteractionMode('ORBIT');
});

// Free Fly Mode Button
flyBtn.addEventListener('click', () => {
  if (isFlyingRoute) stopRouteFlythrough();
  if (isDrawingRoute) toggleDrawRouteMode();

  freeFlyMode = true;
  orbitControls.enabled = false;
  flyControls.enabled = true;

  flyBtn.classList.add('active');
  orbitBtn.classList.remove('active');
  setInteractionMode('FREE FLY');
});

// Reset Camera View Button
resetBtn.addEventListener('click', () => {
  if (isFlyingRoute) stopRouteFlythrough();

  freeFlyMode = false;
  orbitControls.enabled = true;
  flyControls.enabled = false;

  camera.position.copy(initialCameraPosition);
  camera.zoom = initialCameraZoom;
  camera.updateProjectionMatrix();

  orbitControls.target.copy(initialCameraTarget);
  camera.lookAt(initialCameraTarget);
  orbitControls.update();

  orbitBtn.classList.add('active');
  flyBtn.classList.remove('active');
  setInteractionMode('ORBIT');
});

// Ground Grid Toggle
gridBtn.addEventListener('click', () => {
  gridHelper.visible = !gridHelper.visible;
  gridBtn.classList.toggle('active', gridHelper.visible);
  gridBtn.textContent = gridHelper.visible ? '▦ Grid On' : '▦ Grid Off';
  if (topGridText) topGridText.textContent = gridHelper.visible ? 'ACTIVE' : 'OFF';
});

// Route Planning Button Listeners
drawRouteBtn.addEventListener('click', toggleDrawRouteMode);
clearRouteBtn.addEventListener('click', clearRoute);
flyRouteBtn.addEventListener('click', () => {
  if (isFlyingRoute) {
    stopRouteFlythrough();
  } else {
    startRouteFlythrough();
  }
});

// Help Modal Controls
helpBtn.addEventListener('click', () => helpPanel.classList.toggle('show'));
closeHelpBtn.addEventListener('click', () => helpPanel.classList.remove('show'));

// Fullscreen Toggle
fullscreenBtn.addEventListener('click', async () => {
  if (!document.fullscreenElement) {
    await document.documentElement.requestFullscreen();
    fullscreenBtn.textContent = '🗗';
  } else {
    await document.exitFullscreen();
    fullscreenBtn.textContent = '⛶';
  }
});

// Global Keyboard Shortcuts
window.addEventListener('keydown', (event) => {
  if (event.key.toLowerCase() === 'f' && !event.target.matches('input, textarea')) {
    if (freeFlyMode) {
      orbitBtn.click();
    } else {
      flyBtn.click();
    }
  }

  if (event.key === 'Escape') {
    if (isDrawingRoute) toggleDrawRouteMode();
    if (isFlyingRoute) stopRouteFlythrough();
    if (helpPanel.classList.contains('show')) helpPanel.classList.remove('show');
  }
});

// Window Resize Handler
window.addEventListener('resize', () => {
  camera.aspect = container.clientWidth / container.clientHeight;
  camera.updateProjectionMatrix();
  renderer.setSize(container.clientWidth, container.clientHeight);
});

// ============================================================
// 10. MAIN ANIMATION & TERRAIN-FOLLOWING FLYTHROUGH LOOP (Action 4)
// ============================================================
const clock = new THREE.Clock();

function animate() {
  requestAnimationFrame(animate);

  const delta = clock.getDelta();

  if (isFlyingRoute && routeSurfaceCurve) {
    // Increment fly progress along the surface curve
    flyProgress += delta * FLY_SPEED;

    if (flyProgress >= 1.0) {
      // Completed route flythrough
      stopRouteFlythrough();
      if (routeStatus) routeStatus.textContent = 'Flythrough Complete';
    } else {
      // Action 4: Position camera at curve position + fixed vertical offset (Y + 30)
      // to glide smoothly above the terrain rather than scraping the ground
      const groundPos = routeSurfaceCurve.getPointAt(flyProgress);
      camera.position.set(
        groundPos.x,
        groundPos.y + FLY_CAMERA_Y_OFFSET,
        groundPos.z
      );

      // Action 4: Look ahead along path using curve.getTangentAt(t)
      const tangent = routeSurfaceCurve.getTangentAt(flyProgress).normalize();
      const lookAheadDistance = 45.0;
      const lookTarget = camera.position.clone().add(tangent.clone().multiplyScalar(lookAheadDistance));
      // Point slightly downward toward the terrain ahead
      lookTarget.y = groundPos.y + (FLY_CAMERA_Y_OFFSET * 0.6);

      camera.lookAt(lookTarget);
    }
  } else if (freeFlyMode) {
    flyControls.update(delta);
  } else {
    orbitControls.update();
  }

  renderer.render(scene, camera);
}

// Start animation loop
animate();
setViewerStatus('VIEWER READY', 'ready');
console.log('DepthWizard 3D ready. GeoTIFF parser loaded. Terrain-snapping route engine initialized.');