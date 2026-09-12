import * as THREE from 'three';
import { OrbitControls } from 'three/examples/jsm/controls/OrbitControls.js';
import { FlyControls } from 'three/examples/jsm/controls/FlyControls.js';
import { GLTFLoader } from 'three/examples/jsm/loaders/GLTFLoader.js';
import { DRACOLoader } from 'three/examples/jsm/loaders/DRACOLoader.js';
import { TerrainRaycaster } from './utils/terrainRaycaster.js';
import { getActualHeight } from './services/elevationApi.js';
import {
  formatLatitude,
  formatLongitude,
  formatElevation,
  formatSlope
} from './utils/geoUtils.js';

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

// Surface Elevation & WGS84 Inspection Card DOM References
const inspectionCard = document.getElementById('inspectionCard');
const inspectBadgeId = document.getElementById('inspectBadgeId');
const inspectLat = document.getElementById('inspectLat');
const inspectLon = document.getElementById('inspectLon');
const inspectElevation = document.getElementById('inspectElevation');
const inspectSlope = document.getElementById('inspectSlope');
const inspectRefLidar = document.getElementById('inspectRefLidar');
const inspectDelta = document.getElementById('inspectDelta');
const inspectEyeAlt = document.getElementById('inspectEyeAlt');
const inspectTargetRange = document.getElementById('inspectTargetRange');
const inspectTimestamp = document.getElementById('inspectTimestamp');
const inspectExportBtn = document.getElementById('inspectExportBtn');
const inspectCopyBtn = document.getElementById('inspectCopyBtn');
const inspectCloseBtn = document.getElementById('inspectCloseBtn');
const inspectToggleBtn = document.getElementById('inspectToggleBtn');
const inspectSampleBtn = document.getElementById('inspectSampleBtn');

let currentInspectionData = {
  latitude: 45.980776,
  longitude: 7.696169,
  elevation: 1879.09,
  slopeAngle: 8.6,
  eyeAltitude: 354.2,
  targetRange: 482.7,
  referenceLidar: 1878.28,
  deltaError: -0.81
};
let terrainRaycaster = null;


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
// 3B. TOP VIEWPORT COMPASS WIDGET & VIEW SNAPPING CONTROLLER
// ============================================================
const compassWidget = document.getElementById('compassWidget');
const compassDialSvg = document.getElementById('compassDialSvg');
const compassHeadingText = document.getElementById('compassHeadingText');
const snapTopBtn = document.getElementById('snapTopBtn');
const snapPerspectiveBtn = document.getElementById('snapPerspectiveBtn');
const snapFrontBtn = document.getElementById('snapFrontBtn');
const snapEastBtn = document.getElementById('snapEastBtn');
const snapResetBtn = document.getElementById('snapResetBtn');

function updateCameraHeadingAzimuth() {
  const dir = new THREE.Vector3();
  camera.getWorldDirection(dir);
  const rad = Math.atan2(dir.x, -dir.z);
  const deg = (THREE.MathUtils.radToDeg(rad) + 360) % 360;
  const heading = Math.round(deg);

  if (compassDialSvg) {
    compassDialSvg.style.transform = `rotate(${-heading}deg)`;
  }
  if (compassHeadingText) {
    compassHeadingText.textContent = `${heading}°`;
  }
}

orbitControls.addEventListener('change', updateCameraHeadingAzimuth);
updateCameraHeadingAzimuth();

function resetCameraToTrueNorth(duration = 400) {
  const target = orbitControls.target || new THREE.Vector3(0, 0, 0);
  const offset = new THREE.Vector3().subVectors(camera.position, target);
  const horizontalRadius = Math.sqrt(offset.x * offset.x + offset.z * offset.z);
  const currentY = offset.y;
  const safeRadius = horizontalRadius > 0.001 ? horizontalRadius : 10;

  const startPos = camera.position.clone();
  const endPos = new THREE.Vector3(target.x, target.y + currentY, target.z + safeRadius);
  const startTime = performance.now();

  function step(now) {
    const elapsed = now - startTime;
    const progress = Math.min(1, elapsed / duration);
    const ease = 1 - Math.pow(1 - progress, 3);

    camera.position.lerpVectors(startPos, endPos, ease);
    orbitControls.update();
    updateCameraHeadingAzimuth();

    if (progress < 1) {
      requestAnimationFrame(step);
    } else {
      camera.position.copy(endPos);
      orbitControls.update();
      updateCameraHeadingAzimuth();
    }
  }

  requestAnimationFrame(step);
}

if (compassWidget) {
  compassWidget.addEventListener('click', () => resetCameraToTrueNorth());
  compassWidget.addEventListener('keydown', (e) => {
    if (e.key === 'Enter' || e.key === ' ') {
      e.preventDefault();
      resetCameraToTrueNorth();
    }
  });
}

function snapCameraViewMode(viewType, duration = 400) {
  const target = orbitControls.target || new THREE.Vector3(0, 0, 0);
  const distance = Math.max(camera.position.distanceTo(target), 30);
  const startPos = camera.position.clone();
  let endPos = new THREE.Vector3();

  switch (viewType) {
    case 'top':
      endPos.set(target.x, target.y + distance, target.z + 0.001);
      break;
    case 'perspective':
      endPos.set(target.x + distance * 0.6, target.y + distance * 0.5, target.z + distance * 0.65);
      break;
    case 'front':
      endPos.set(target.x, target.y + distance * 0.25, target.z + distance * 0.95);
      break;
    case 'right':
      endPos.set(target.x + distance * 0.95, target.y + distance * 0.25, target.z);
      break;
    case 'reset':
    default:
      endPos.copy(initialCameraPosition);
      break;
  }

  const startTime = performance.now();

  function step(now) {
    const elapsed = now - startTime;
    const progress = Math.min(1, elapsed / duration);
    const ease = 1 - Math.pow(1 - progress, 3);

    camera.position.lerpVectors(startPos, endPos, ease);
    orbitControls.update();
    updateCameraHeadingAzimuth();

    if (progress < 1) {
      requestAnimationFrame(step);
    } else {
      camera.position.copy(endPos);
      orbitControls.update();
      updateCameraHeadingAzimuth();
    }
  }

  requestAnimationFrame(step);
}

if (snapTopBtn) snapTopBtn.addEventListener('click', () => snapCameraViewMode('top'));
if (snapPerspectiveBtn) snapPerspectiveBtn.addEventListener('click', () => snapCameraViewMode('perspective'));
if (snapFrontBtn) snapFrontBtn.addEventListener('click', () => snapCameraViewMode('front'));
if (snapEastBtn) snapEastBtn.addEventListener('click', () => snapCameraViewMode('right'));
if (snapResetBtn) snapResetBtn.addEventListener('click', () => snapCameraViewMode('reset'));

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
// 4B. SURFACE ELEVATION & WGS84 INSPECTION CARD CONTROLLER
// ============================================================
function updateInspectClock() {
  const now = new Date();
  const hh = String(now.getHours()).padStart(2, '0');
  const mm = String(now.getMinutes()).padStart(2, '0');
  const ss = String(now.getSeconds()).padStart(2, '0');
  if (inspectTimestamp) inspectTimestamp.textContent = `${hh}:${mm}:${ss}`;
}
setInterval(updateInspectClock, 1000);
updateInspectClock();

async function handleSurfaceInspection(data) {
  currentInspectionData = { ...currentInspectionData, ...data };

  if (inspectLat) inspectLat.textContent = formatLatitude(data.latitude);
  if (inspectLon) inspectLon.textContent = formatLongitude(data.longitude);
  if (inspectElevation) inspectElevation.textContent = formatElevation(data.elevation);
  if (inspectSlope) inspectSlope.textContent = formatSlope(data.slopeAngle);
  if (inspectEyeAlt) inspectEyeAlt.textContent = `${data.eyeAltitude.toFixed(1)} m`;
  if (inspectTargetRange) inspectTargetRange.textContent = `${data.targetRange.toFixed(1)} m`;

  if (inspectionCard) inspectionCard.classList.remove('hidden');
  if (inspectToggleBtn) {
    inspectToggleBtn.classList.add('active');
    inspectToggleBtn.textContent = '📍 Inspector On';
  }

  // Fetch benchmark LiDAR ground truth
  if (inspectRefLidar) inspectRefLidar.textContent = 'Syncing...';
  if (inspectDelta) {
    inspectDelta.textContent = '...';
    inspectDelta.className = 'benchmark-box-val';
  }

  try {
    const res = await getActualHeight(data.latitude, data.longitude, data.elevation);
    if (res) {
      currentInspectionData.referenceLidar = res.actual_height;
      currentInspectionData.deltaError = res.delta_error;

      if (inspectRefLidar) {
        inspectRefLidar.textContent = `${Number(res.actual_height).toLocaleString('en-US', {
          minimumFractionDigits: 2,
          maximumFractionDigits: 2
        })} m`;
      }

      if (inspectDelta) {
        const delta = res.delta_error;
        inspectDelta.textContent = `±${Math.abs(delta).toFixed(2)} m`;
        inspectDelta.className = `benchmark-box-val ${Math.abs(delta) <= 1.5 ? 'benchmark-delta-emerald' : 'text-amber-400'}`;
      }
    }
  } catch (err) {
    console.warn('Elevation benchmark query fallback:', err);
  }
}

terrainRaycaster = new TerrainRaycaster({
  scene,
  camera,
  domElement: renderer.domElement,
  getTerrainMesh: () => terrainModel,
  onInspect: (data) => {
    if (!isDrawingRoute) {
      handleSurfaceInspection(data);
    }
  }
});

// Inspection Card Action: Export JSON (GeoJSON format)
if (inspectExportBtn) {
  inspectExportBtn.addEventListener('click', () => {
    const feature = {
      type: 'Feature',
      properties: {
        badgeId: 'DW3D-2574',
        timestamp: new Date().toISOString(),
        datum: 'WGS84',
        verticalDatum: 'EGM96 MSL',
        latitude: currentInspectionData.latitude,
        longitude: currentInspectionData.longitude,
        surfaceElevationMsl: currentInspectionData.elevation,
        slopeAngleDeg: currentInspectionData.slopeAngle,
        referenceLidarMsl: currentInspectionData.referenceLidar,
        deltaErrorMeters: currentInspectionData.deltaError,
        eyeAltitudeMeters: currentInspectionData.eyeAltitude,
        targetRangeMeters: currentInspectionData.targetRange
      },
      geometry: {
        type: 'Point',
        coordinates: [
          currentInspectionData.longitude,
          currentInspectionData.latitude,
          currentInspectionData.elevation
        ]
      }
    };
    const blob = new Blob([JSON.stringify(feature, null, 2)], { type: 'application/json' });
    const url = URL.createObjectURL(blob);
    const a = document.createElement('a');
    a.href = url;
    a.download = `DW3D_Inspection_DW3D-2574_${Date.now()}.json`;
    document.body.appendChild(a);
    a.click();
    document.body.removeChild(a);
    URL.revokeObjectURL(url);
  });
}

// Inspection Card Action: Copy Telemetry to Clipboard
if (inspectCopyBtn) {
  inspectCopyBtn.addEventListener('click', async () => {
    const text = `[DepthWizard 3D - DW3D-2574]
Latitude: ${formatLatitude(currentInspectionData.latitude)}
Longitude: ${formatLongitude(currentInspectionData.longitude)}
Elevation: ${formatElevation(currentInspectionData.elevation)}
Slope: ${formatSlope(currentInspectionData.slopeAngle)}
LiDAR Reference: ${Number(currentInspectionData.referenceLidar).toFixed(2)} m
Delta Error: ${currentInspectionData.deltaError >= 0 ? '+' : ''}${currentInspectionData.deltaError.toFixed(2)} m
Eye Altitude: ${currentInspectionData.eyeAltitude.toFixed(1)} m
Target Range: ${currentInspectionData.targetRange.toFixed(1)} m
Datum: WGS84`;
    if (navigator.clipboard) {
      await navigator.clipboard.writeText(text);
      const originalText = inspectCopyBtn.textContent;
      inspectCopyBtn.textContent = '✓ Copied';
      inspectCopyBtn.style.color = '#34d399';
      setTimeout(() => {
        inspectCopyBtn.textContent = originalText;
        inspectCopyBtn.style.color = '';
      }, 2000);
    }
  });
}

// Inspection Card Action: Close button
if (inspectCloseBtn) {
  inspectCloseBtn.addEventListener('click', () => {
    if (inspectionCard) inspectionCard.classList.add('hidden');
    if (terrainRaycaster) terrainRaycaster.hidePin();
    if (inspectToggleBtn) {
      inspectToggleBtn.classList.remove('active');
      inspectToggleBtn.textContent = '📍 Inspector Off';
    }
  });
}

// Sidebar Toggle Inspector Button
if (inspectToggleBtn) {
  inspectToggleBtn.addEventListener('click', () => {
    const isHidden = inspectionCard.classList.contains('hidden');
    if (isHidden) {
      inspectionCard.classList.remove('hidden');
      inspectToggleBtn.classList.add('active');
      inspectToggleBtn.textContent = '📍 Inspector On';
    } else {
      inspectionCard.classList.add('hidden');
      if (terrainRaycaster) terrainRaycaster.hidePin();
      inspectToggleBtn.classList.remove('active');
      inspectToggleBtn.textContent = '📍 Inspector Off';
    }
  });
}

// Sidebar Inspect Apex Summit Button
if (inspectSampleBtn) {
  inspectSampleBtn.addEventListener('click', () => {
    if (!terrainModel) {
      if (demoBtn) demoBtn.click();
      setTimeout(() => inspectApexSummit(), 1500);
    } else {
      inspectApexSummit();
    }
  });
}

function inspectApexSummit() {
  if (!terrainModel) return;
  const box = new THREE.Box3().setFromObject(terrainModel);
  const summitPos = new THREE.Vector3(
    (box.min.x + box.max.x) * 0.5,
    box.max.y,
    (box.min.z + box.max.z) * 0.5
  );

  const downRay = new THREE.Raycaster(
    new THREE.Vector3(summitPos.x, box.max.y + 100, summitPos.z),
    new THREE.Vector3(0, -1, 0)
  );
  const hits = downRay.intersectObject(terrainModel, true);
  if (hits.length > 0) {
    const hit = hits[0];
    const normal = hit.face ? hit.face.normal.clone().transformDirection(hit.object.matrixWorld) : new THREE.Vector3(0, 1, 0);
    const slope = Math.acos(Math.min(Math.max(normal.y, -1), 1)) * (180 / Math.PI);
    const u = hit.uv ? hit.uv.x : 0.52;
    const v = hit.uv ? hit.uv.y : 0.48;
    const lat = 45.95 + v * 0.07;
    const lon = 7.65 + u * 0.10;
    const elev = 1800.0 + (hit.point.y * 1.0);
    const eyeAlt = Math.max(camera.position.y, 0);
    const targetRange = camera.position.distanceTo(hit.point);

    terrainRaycaster.placePin(hit.point);
    handleSurfaceInspection({
      latitude: lat,
      longitude: lon,
      elevation: elev,
      slopeAngle: slope,
      eyeAltitude: eyeAlt,
      targetRange: targetRange,
      worldPoint: hit.point
    });
  }
}

// ============================================================
// 4C. RAYCAST MEASUREMENT (3D METRIC VECTOR & SLOPE ANALYSIS)
// ============================================================
const measureToolToggleBtn = document.getElementById('measureToolToggleBtn');
const measureToolBtnText = document.getElementById('measureToolBtnText');
const measureInstructionText = document.getElementById('measureInstructionText');
const measurePointACard = document.getElementById('measurePointACard');
const measurePointAElev = document.getElementById('measurePointAElev');
const measurePointACoord = document.getElementById('measurePointACoord');
const measurePointBCard = document.getElementById('measurePointBCard');
const measurePointBElev = document.getElementById('measurePointBElev');
const measurePointBCoord = document.getElementById('measurePointBCoord');
const measureTelemetryGrid = document.getElementById('measureTelemetryGrid');
const measureStraightDist = document.getElementById('measureStraightDist');
const measureHorizontalDist = document.getElementById('measureHorizontalDist');
const measureDeltaH = document.getElementById('measureDeltaH');
const measureSlopeGrad = document.getElementById('measureSlopeGrad');
const measureProfileContainer = document.getElementById('measureProfileContainer');
const clearMeasureBtn = document.getElementById('clearMeasureBtn');

let isCaliperMeasureMode = false;
let caliperPoints = [];
let caliperMarkerMeshes = [];
let caliperLineMesh = null;

function clearCaliperMeasurementVisuals() {
  if (caliperLineMesh) {
    scene.remove(caliperLineMesh);
    if (caliperLineMesh.geometry) caliperLineMesh.geometry.dispose();
    if (caliperLineMesh.material) caliperLineMesh.material.dispose();
    caliperLineMesh = null;
  }
  caliperMarkerMeshes.forEach((m) => {
    scene.remove(m);
    if (m.geometry) m.geometry.dispose();
    if (m.material) m.material.dispose();
  });
  caliperMarkerMeshes = [];
  caliperPoints = [];

  if (measurePointAElev) measurePointAElev.textContent = 'Elev: -- m';
  if (measurePointACoord) measurePointACoord.textContent = 'Click on 3D terrain';
  if (measurePointBElev) measurePointBElev.textContent = 'Elev: -- m';
  if (measurePointBCoord) measurePointBCoord.textContent = 'Click target on 3D terrain';
  if (measureTelemetryGrid) measureTelemetryGrid.style.display = 'none';
  if (measureProfileContainer) measureProfileContainer.innerHTML = '';
  if (measureInstructionText) {
    measureInstructionText.textContent = isCaliperMeasureMode
      ? 'Click Point A on the 3D block to measure.'
      : 'Click Point A then Point B on the 3D block to measure.';
  }
}

function toggleCaliperMeasureMode(forceState) {
  isCaliperMeasureMode = typeof forceState === 'boolean' ? forceState : !isCaliperMeasureMode;

  if (isCaliperMeasureMode) {
    if (isDrawingRoute) toggleDrawRouteMode();
    if (measureToolToggleBtn) {
      measureToolToggleBtn.classList.add('active');
    }
    if (measureToolBtnText) {
      measureToolBtnText.textContent = '⊙ Measurement Tool Active (Click Terrain)';
    }
    if (measureInstructionText) {
      measureInstructionText.textContent = 'Click Point A then Point B on the 3D block to measure.';
    }
    setInteractionMode('CALIPER MEASURE');
  } else {
    clearCaliperMeasurementVisuals();
    if (measureToolToggleBtn) {
      measureToolToggleBtn.classList.remove('active');
    }
    if (measureToolBtnText) {
      measureToolBtnText.textContent = 'Enable Raycast Measurement';
    }
    setInteractionMode('ORBIT');
  }
}

if (measureToolToggleBtn) {
  measureToolToggleBtn.addEventListener('click', () => toggleCaliperMeasureMode());
}

if (clearMeasureBtn) {
  clearMeasureBtn.addEventListener('click', clearCaliperMeasurementVisuals);
}

function renderCaliperProfileSvg(pA, pB, deltaH, minElev, maxElev) {
  if (!measureProfileContainer) return;

  const elevRange = Math.max(maxElev - minElev, 10.0);
  const yA = 55 - ((pA.elevation - minElev) / elevRange) * 40;
  const yB = 55 - ((pB.elevation - minElev) / elevRange) * 40;
  const midY = (yA + yB) / 2 + (pA.elevation > pB.elevation ? 5 : -5);
  const deltaSign = deltaH >= 0 ? '+' : '';

  measureProfileContainer.innerHTML = `
    <div style="border-radius: 6px; background: rgba(0,0,0,0.5); border: 1px solid rgba(255,255,255,0.1); padding: 8px;">
      <div style="display: flex; justify-content: space-between; font-size: 10px; font-family: var(--font-mono); margin-bottom: 4px;">
        <span style="color: #22d3ee; font-weight: bold;">Point A: ${pA.elevation.toFixed(1)}m</span>
        <span style="color: #f59e0b; font-weight: bold;">Point B: ${pB.elevation.toFixed(1)}m</span>
      </div>
      <svg viewBox="0 0 280 70" style="width: 100%; height: 60px; overflow: visible;">
        <defs>
          <linearGradient id="caliperSvgGrad" x1="0%" y1="0%" x2="0%" y2="100%">
            <stop offset="0%" stop-color="#f59e0b" stop-opacity="0.35" />
            <stop offset="100%" stop-color="#0b1329" stop-opacity="0.0" />
          </linearGradient>
          <linearGradient id="caliperLineGrad" x1="0%" y1="0%" x2="100%" y2="0%">
            <stop offset="0%" stop-color="#22d3ee" />
            <stop offset="100%" stop-color="#f59e0b" />
          </linearGradient>
        </defs>
        <line x1="15" y1="65" x2="265" y2="65" stroke="rgba(255,255,255,0.15)" stroke-width="1" />
        <path d="M 15 ${yA} Q 140 ${midY} 265 ${yB} L 265 65 L 15 65 Z" fill="url(#caliperSvgGrad)" />
        <path d="M 15 ${yA} Q 140 ${midY} 265 ${yB}" fill="none" stroke="url(#caliperLineGrad)" stroke-width="2.5" stroke-linecap="round" />
        <circle cx="15" cy="${yA}" r="3.5" fill="#22d3ee" stroke="#ffffff" stroke-width="1.5" />
        <circle cx="265" cy="${yB}" r="3.5" fill="#f59e0b" stroke="#ffffff" stroke-width="1.5" />
        <rect x="110" y="2" width="60" height="14" rx="3" fill="#0f172a" stroke="#64748b" />
        <text x="140" y="12" fill="#38bdf8" font-size="8" font-family="monospace" font-weight="bold" text-anchor="middle">
          ΔH ${deltaSign}${deltaH.toFixed(1)}m
        </text>
      </svg>
      <div style="display: flex; justify-content: space-between; font-size: 9px; color: #94a3b8; font-family: var(--font-mono); margin-top: 2px;">
        <span>Min: ${minElev.toFixed(1)}m</span>
        <span style="color: ${deltaH >= 0 ? '#34d399' : '#f87171'}; font-weight: bold;">Slope: ${deltaSign}${deltaH.toFixed(1)}m</span>
        <span>Max: ${maxElev.toFixed(1)}m</span>
      </div>
    </div>
  `;
}

function handleCaliperClick(hitPoint, normal, uv) {
  const bounds = { minLat: 45.965, maxLat: 45.995, minLon: 7.685, maxLon: 7.725 };
  const u = uv ? uv.x : 0.5;
  const v = uv ? uv.y : 0.5;
  const lat = bounds.minLat + (1 - v) * (bounds.maxLat - bounds.minLat);
  const lon = bounds.minLon + u * (bounds.maxLon - bounds.minLon);
  const elevation = hitPoint.y + 1850.0;

  if (caliperPoints.length >= 2) {
    clearCaliperMeasurementVisuals();
  }

  const pointData = {
    point3D: hitPoint.clone(),
    elevation,
    lat,
    lon
  };
  caliperPoints.push(pointData);

  // Drop 3D node sphere
  const sphereGeo = new THREE.SphereGeometry(1.8, 16, 16);
  const sphereMat = new THREE.MeshBasicMaterial({
    color: caliperPoints.length === 1 ? 0x06b6d4 : 0xf59e0b
  });
  const marker = new THREE.Mesh(sphereGeo, sphereMat);
  marker.position.copy(hitPoint);
  marker.position.y += 0.8;
  scene.add(marker);
  caliperMarkerMeshes.push(marker);

  // Synchronize with API and right InspectionCard
  const xVal = lon.toFixed(6);
  const yVal = lat.toFixed(6);
  const zVal = elevation.toFixed(2);
  const endpointUrl = `/api/v1/get-actual-height/x=${xVal},y=${yVal},z=${zVal}`;

  const slope = normal ? Math.acos(Math.min(Math.max(normal.y, -1), 1)) * (180 / Math.PI) : 0;
  handleSurfaceInspection({
    latitude: lat,
    longitude: lon,
    elevation: elevation,
    slopeAngle: slope,
    eyeAltitude: Math.max(camera.position.y, 0) + 1850.0,
    targetRange: camera.position.distanceTo(hitPoint),
    endpointUrl
  });

  if (caliperPoints.length === 1) {
    if (measurePointAElev) measurePointAElev.textContent = `Elev: ${elevation.toFixed(1)} m MSL`;
    if (measurePointACoord) measurePointACoord.textContent = `${lat.toFixed(4)}°N, ${lon.toFixed(4)}°E`;
    if (measureInstructionText) {
      measureInstructionText.textContent = 'Click Point B on 3D terrain to complete vector.';
    }
  } else if (caliperPoints.length === 2) {
    const pA = caliperPoints[0];
    const pB = caliperPoints[1];

    if (measurePointBElev) measurePointBElev.textContent = `Elev: ${elevation.toFixed(1)} m MSL`;
    if (measurePointBCoord) measurePointBCoord.textContent = `${lat.toFixed(4)}°N, ${lon.toFixed(4)}°E`;

    // 3D Dashed connector line
    const lineGeo = new THREE.BufferGeometry().setFromPoints([pA.point3D, pB.point3D]);
    const lineMat = new THREE.LineDashedMaterial({
      color: 0xf59e0b,
      dashSize: 4,
      gapSize: 2
    });
    caliperLineMesh = new THREE.Line(lineGeo, lineMat);
    caliperLineMesh.computeLineDistances();
    scene.add(caliperLineMesh);

    // Compute metrics
    const deltaH = pB.elevation - pA.elevation;
    const horizontalDistance = Math.hypot(pB.point3D.x - pA.point3D.x, pB.point3D.z - pA.point3D.z);
    const straightDistance = pA.point3D.distanceTo(pB.point3D);
    const slopeAngle = Math.atan2(Math.abs(deltaH), horizontalDistance || 1) * (180 / Math.PI);
    const slopePercent = (Math.abs(deltaH) / (horizontalDistance || 1)) * 100;

    if (measureStraightDist) measureStraightDist.textContent = `${straightDistance.toFixed(1)} m`;
    if (measureHorizontalDist) measureHorizontalDist.textContent = `${horizontalDistance.toFixed(1)} m`;
    if (measureDeltaH) {
      const sign = deltaH >= 0 ? '+' : '';
      measureDeltaH.textContent = `${sign}${deltaH.toFixed(1)} m`;
      measureDeltaH.style.color = deltaH >= 0 ? '#34d399' : '#f87171';
    }
    if (measureSlopeGrad) {
      measureSlopeGrad.textContent = `${slopeAngle.toFixed(1)}° (${slopePercent.toFixed(0)}%)`;
    }

    if (measureTelemetryGrid) measureTelemetryGrid.style.display = 'block';

    renderCaliperProfileSvg(pA, pB, deltaH, Math.min(pA.elevation, pB.elevation), Math.max(pA.elevation, pB.elevation));

    if (measureInstructionText) {
      measureInstructionText.textContent = 'Measurement complete. Click again to measure a new vector.';
    }
  }
}



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

// Raycaster Click Handler for Waypoint Placement & Caliper Measurement
renderer.domElement.addEventListener('click', (event) => {
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
    const hit = intersects[0];
    const hitPoint = hit.point;

    if (isDrawingRoute) {
      addWaypoint(hitPoint);
    } else if (isCaliperMeasureMode) {
      const normal = hit.face ? hit.face.normal.clone().transformDirection(hit.object.matrixWorld) : new THREE.Vector3(0, 1, 0);
      handleCaliperClick(hitPoint, normal, hit.uv);
    }
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

  // Update pulsing cyan 3D pin animations
  if (terrainRaycaster) {
    terrainRaycaster.update(delta);
  }

  renderer.render(scene, camera);
}

// Start animation loop
animate();
setViewerStatus('VIEWER READY', 'ready');
console.log('DepthWizard 3D ready. GeoTIFF parser loaded. Terrain-snapping route engine initialized.');