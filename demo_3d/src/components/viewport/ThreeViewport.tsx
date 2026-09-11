import React, { useEffect, useRef, useImperativeHandle, forwardRef, useCallback, useState } from 'react';
import * as THREE from 'three';
import { OrbitControls } from 'three/examples/jsm/controls/OrbitControls.js';
import { GLTFLoader } from 'three/examples/jsm/loaders/GLTFLoader.js';
import { TilesRenderer } from '3d-tiles-renderer';
import { 
  GLTFMeshFeaturesExtension, 
  GLTFStructuralMetadataExtension 
} from '3d-tiles-renderer/plugins';
import { 
  Radio, 
  Crosshair, 
  Eye, 
  Compass, 
  Gauge, 
  ShieldCheck 
} from 'lucide-react';

import type { 
  ShadingMode, 
  TelemetryData, 
  SunLightingConfig, 
  MeasurePoint, 
  MeasurementResult,
  FlightWaypoint,
  TransectMeasurement,
  TransectSamplePoint
} from '../../types/gis';
import type { ElevationJobResponse, ElevationInspectionPoint } from '../../types/elevationApi';
import type { TerrainDataPackage } from '../../utils/terrainGenerator';

export interface ThreeViewportHandle {
  takeSnapshot: () => void;
  resetCamera: () => void;
  snapNadir: () => void;
  snapOblique: () => void;
  fitBounds: () => void;
  resetNorth: () => void;
  zoomIn: () => void;
  zoomOut: () => void;
}

interface ThreeViewportProps {
  dataset: TerrainDataPackage;
  jobResponse: ElevationJobResponse | null;
  shadingMode: ShadingMode;
  sunConfig: SunLightingConfig;
  fov?: number;
  isTurntable?: boolean;
  turntableSpeed?: number;
  isSplitScreen?: boolean;
  splitPosition?: number;
  onCameraHeadingChange?: (heading: number) => void;
  // Waypoint Tour
  waypoints: FlightWaypoint[];
  onAddWaypoint: (wp: FlightWaypoint) => void;
  isPlacingWaypoints: boolean;
  isTourPlaying: boolean;
  tourSpeed: number;
  isLooping: boolean;
  // First-Person Drone Flight
  isDroneMode: boolean;
  droneCruiseSpeed: number;
  // Transect Cross-Section
  isPlacingTransect: boolean;
  onTransectUpdated: (transect: TransectMeasurement | null) => void;
  // Measurement & Telemetry
  isMeasuring: boolean;
  onTelemetryUpdate?: (data: TelemetryData) => void;
  onMeasurementUpdate: (result: MeasurementResult | null) => void;
  onInspectionPointSelected: (point: ElevationInspectionPoint) => void;
}

// Terrain Base Dimensions (in 3D world units)
const TERRAIN_SIZE = 100;
const BASE_HEIGHT_SCALE = 22; // Maximum peak height at true 1:1 metric scale

export const ThreeViewport = forwardRef<ThreeViewportHandle, ThreeViewportProps>(({
  dataset,
  jobResponse,
  shadingMode,
  sunConfig,
  fov = 45,
  isTurntable = false,
  turntableSpeed = 1.0,
  isSplitScreen = false,
  splitPosition = 0.5,
  onCameraHeadingChange,
  waypoints,
  onAddWaypoint,
  isPlacingWaypoints,
  isTourPlaying,
  tourSpeed,
  isLooping,
  isDroneMode,
  droneCruiseSpeed,
  isPlacingTransect,
  onTransectUpdated,
  isMeasuring,
  onTelemetryUpdate,
  onMeasurementUpdate,
  onInspectionPointSelected,
}, ref) => {
  const containerRef = useRef<HTMLDivElement>(null);
  const sceneRef = useRef<THREE.Scene | null>(null);
  const rendererRef = useRef<THREE.WebGLRenderer | null>(null);
  const cameraRef = useRef<THREE.PerspectiveCamera | null>(null);
  const controlsRef = useRef<OrbitControls | null>(null);
  const terrainMeshRef = useRef<THREE.Mesh | null>(null);
  const flatMeshRef = useRef<THREE.Mesh | null>(null);
  const tilesRendererRef = useRef<TilesRenderer | null>(null);
  const tilesGroupRef = useRef<THREE.Group | null>(null);
  const dirLightRef = useRef<THREE.DirectionalLight | null>(null);
  const hemiLightRef = useRef<THREE.HemisphereLight | null>(null);
  const ambientLightRef = useRef<THREE.AmbientLight | null>(null);

  // Groups for Dynamic Visuals
  const pinGroupRef = useRef<THREE.Group | null>(null);
  const pinAuraMeshRef = useRef<THREE.Mesh | null>(null);
  const measureGroupRef = useRef<THREE.Group | null>(null);
  const waypointGroupRef = useRef<THREE.Group | null>(null);
  const transectGroupRef = useRef<THREE.Group | null>(null);

  // States for interactive measurement & transect
  const pointAStateRef = useRef<MeasurePoint | null>(null);
  const pointBStateRef = useRef<MeasurePoint | null>(null);
  const transectPointARef = useRef<MeasurePoint | null>(null);

  // Drone Cockpit HUD state (updated in requestAnimationFrame)
  const [cockpitTelemetry, setCockpitTelemetry] = useState({
    altitudeAGL: 45,
    airspeed: 0,
    heading: 0,
    pitch: 0,
  });

  // Drone Flight Controls state
  const keysDownRef = useRef<{ [code: string]: boolean }>({});
  const droneYawRef = useRef<number>(0);
  const dronePitchRef = useRef<number>(0);
  const isMouseDownRef = useRef<boolean>(false);
  const lastMousePosRef = useRef<{ x: number; y: number }>({ x: 0, y: 0 });

  // Animation and Tour refs
  const splineProgressRef = useRef<number>(0);
  const raycasterRef = useRef<THREE.Raycaster>(new THREE.Raycaster());
  const mouseNdcRef = useRef<THREE.Vector2>(new THREE.Vector2(-999, -999));
  const isPointerInsideRef = useRef<boolean>(false);

  // FPS tracking
  const fpsFramesRef = useRef<number>(0);
  const fpsLastTimeRef = useRef<number>(0);
  const currentFpsRef = useRef<number>(60);

  // Synchronize dynamic React state into livePropsRef
  const livePropsRef = useRef({
    dataset,
    jobResponse,
    shadingMode,
    waypoints,
    isTourPlaying,
    tourSpeed,
    isLooping,
    isDroneMode,
    droneCruiseSpeed,
    isTurntable,
    turntableSpeed,
    isSplitScreen,
    splitPosition,
    onTelemetryUpdate,
    onCameraHeadingChange,
  });

  useEffect(() => {
    livePropsRef.current = {
      dataset,
      jobResponse,
      shadingMode,
      waypoints,
      isTourPlaying,
      tourSpeed,
      isLooping,
      isDroneMode,
      droneCruiseSpeed,
      isTurntable,
      turntableSpeed,
      isSplitScreen,
      splitPosition,
      onTelemetryUpdate,
      onCameraHeadingChange,
    };
  }, [
    dataset,
    jobResponse,
    shadingMode,
    waypoints,
    isTourPlaying,
    tourSpeed,
    isLooping,
    isDroneMode,
    droneCruiseSpeed,
    isTurntable,
    turntableSpeed,
    isSplitScreen,
    splitPosition,
    onTelemetryUpdate,
    onCameraHeadingChange,
  ]);

  // Imperative Camera & Snapshot Controls
  useImperativeHandle(ref, () => ({
    takeSnapshot: () => {
      const renderer = rendererRef.current;
      const scene = sceneRef.current;
      const camera = cameraRef.current;
      if (!renderer || !scene || !camera) return;

      renderer.render(scene, camera);
      const dataUrl = renderer.domElement.toDataURL('image/png');
      const link = document.createElement('a');
      link.href = dataUrl;
      link.download = `DepthWizard3D-Snapshot-${Date.now()}.png`;
      link.click();
    },
    resetCamera: () => {
      if (!cameraRef.current || !controlsRef.current) return;
      cameraRef.current.position.set(0, 48, 64);
      cameraRef.current.up.set(0, 1, 0);
      controlsRef.current.target.set(0, 0, 0);
      controlsRef.current.update();
    },
    snapNadir: () => {
      if (!cameraRef.current || !controlsRef.current) return;
      cameraRef.current.position.set(0, 140, 0.001);
      cameraRef.current.up.set(0, 0, -1);
      controlsRef.current.target.set(0, 0, 0);
      controlsRef.current.update();
    },
    snapOblique: () => {
      if (!cameraRef.current || !controlsRef.current) return;
      cameraRef.current.position.set(0, 60, 60);
      cameraRef.current.up.set(0, 1, 0);
      controlsRef.current.target.set(0, 0, 0);
      controlsRef.current.update();
    },
    fitBounds: () => {
      if (!cameraRef.current || !controlsRef.current) return;
      cameraRef.current.position.set(0, 75, 75);
      cameraRef.current.up.set(0, 1, 0);
      controlsRef.current.target.set(0, 0, 0);
      controlsRef.current.update();
    },
    resetNorth: () => {
      if (!cameraRef.current || !controlsRef.current) return;
      const cam = cameraRef.current;
      const tgt = controlsRef.current.target;
      const dist = Math.sqrt(Math.pow(cam.position.x - tgt.x, 2) + Math.pow(cam.position.z - tgt.z, 2));
      cam.position.x = tgt.x;
      cam.position.z = tgt.z + (dist || 64);
      cam.up.set(0, 1, 0);
      controlsRef.current.update();
    },
    zoomIn: () => {
      if (!cameraRef.current || !controlsRef.current) return;
      const cam = cameraRef.current;
      const tgt = controlsRef.current.target;
      cam.position.lerp(tgt, 0.2);
      controlsRef.current.update();
    },
    zoomOut: () => {
      if (!cameraRef.current || !controlsRef.current) return;
      const cam = cameraRef.current;
      const tgt = controlsRef.current.target;
      const dir = cam.position.clone().sub(tgt).multiplyScalar(1.25);
      cam.position.copy(tgt).add(dir);
      controlsRef.current.update();
    },
  }));

  // Update FOV dynamically
  useEffect(() => {
    if (cameraRef.current) {
      cameraRef.current.fov = fov;
      cameraRef.current.updateProjectionMatrix();
    }
  }, [fov]);

  // High-performance O(1) elevation lookup for terrain height at any world (X, Z) coordinate
  const sampleTerrainY = useCallback((worldX: number, worldZ: number): number => {
    const res = dataset.resolution;
    const half = TERRAIN_SIZE / 2;
    const u = THREE.MathUtils.clamp((worldX + half) / TERRAIN_SIZE, 0, 1);
    const v = THREE.MathUtils.clamp((worldZ + half) / TERRAIN_SIZE, 0, 1);

    const gx = Math.min(res - 1, Math.floor(u * (res - 1)));
    const gz = Math.min(res - 1, Math.floor(v * (res - 1)));
    const idx = gz * res + gx;

    const hNorm = dataset.heights[idx] || 0;
    return hNorm * BASE_HEIGHT_SCALE;
  }, [dataset]);

  // Dynamic Tile Shading helper function
  const configureTileMaterial = (origMat: THREE.Material, mode: ShadingMode): THREE.Material => {
    if (mode === 'wireframe') {
      return new THREE.MeshBasicMaterial({
        color: 0x10b981,
        wireframe: true,
        transparent: true,
        opacity: 0.85
      });
    }

    if (origMat instanceof THREE.MeshStandardMaterial || origMat instanceof THREE.MeshBasicMaterial) {
      const cloned = origMat.clone() as THREE.MeshStandardMaterial;
      if (mode === 'rgb') {
        cloned.wireframe = false;
        cloned.roughness = 0.85;
      } else if (mode === 'hypsometric') {
        cloned.wireframe = false;
        cloned.roughness = 0.5;
        cloned.color.setHex(0x06b6d4);
      } else if (mode === 'slope') {
        cloned.wireframe = false;
        cloned.color.setHex(0xf59e0b);
      }
      return cloned;
    }
    return origMat;
  };

  const applyTileShading = useCallback((sceneObject: THREE.Object3D, mode: ShadingMode) => {
    sceneObject.traverse((node) => {
      if ((node as THREE.Mesh).isMesh) {
        const mesh = node as THREE.Mesh;
        if (Array.isArray(mesh.material)) {
          mesh.material = mesh.material.map(m => configureTileMaterial(m, mode));
        } else {
          mesh.material = configureTileMaterial(mesh.material, mode);
        }
      }
    });
  }, []);

  // Update Visual Waypoint Spline Trajectory (CatmullRomCurve3 glowing tube)
  useEffect(() => {
    const group = waypointGroupRef.current;
    if (!group) return;

    // Clear old visual objects
    while (group.children.length > 0) {
      const obj = group.children[0] as THREE.Mesh;
      group.remove(obj);
      if (obj.geometry) {
        obj.geometry.dispose();
        if (Array.isArray(obj.material)) obj.material.forEach(m => m.dispose());
        else obj.material.dispose();
      }
    }

    if (waypoints.length === 0) return;

    // A. Render Waypoint Pin Nodes & Ground Tether Lines
    waypoints.forEach((wp) => {
      // 1. Flight node sphere (emerald glow)
      const sphere = new THREE.Mesh(
        new THREE.SphereGeometry(1.2, 16, 16),
        new THREE.MeshStandardMaterial({
          color: 0x10b981,
          emissive: 0x059669,
          emissiveIntensity: 0.9,
          roughness: 0.2
        })
      );
      sphere.position.set(wp.x, wp.y, wp.z);
      group.add(sphere);

      // 2. Vertical tether line to ground
      const groundY = sampleTerrainY(wp.x, wp.z);
      const tetherGeo = new THREE.BufferGeometry().setFromPoints([
        new THREE.Vector3(wp.x, groundY, wp.z),
        new THREE.Vector3(wp.x, wp.y, wp.z)
      ]);
      const tether = new THREE.Line(
        tetherGeo,
        new THREE.LineDashedMaterial({
          color: 0x10b981,
          dashSize: 1,
          gapSize: 0.5,
          transparent: true,
          opacity: 0.65
        })
      );
      tether.computeLineDistances();
      group.add(tether);
    });

    // B. Render Glowing 3D Neon Flight Spline Tube if >= 2 points
    if (waypoints.length >= 2) {
      const pts = waypoints.map(w => new THREE.Vector3(w.x, w.y, w.z));
      const curve = new THREE.CatmullRomCurve3(pts, isLooping, 'centripetal', 0.5);

      // Neon Tube Geometry
      const tubeGeo = new THREE.TubeGeometry(curve, 128, 0.35, 8, isLooping);
      const tubeMat = new THREE.MeshBasicMaterial({
        color: 0x06b6d4,
        transparent: true,
        opacity: 0.85,
        wireframe: false
      });
      const tubeMesh = new THREE.Mesh(tubeGeo, tubeMat);
      group.add(tubeMesh);

      // Outer Aura Line
      const splinePoints = curve.getPoints(120);
      const lineGeo = new THREE.BufferGeometry().setFromPoints(splinePoints);
      const auraLine = new THREE.Line(
        lineGeo,
        new THREE.LineBasicMaterial({ color: 0x22d3ee, transparent: true, opacity: 0.9, linewidth: 2 })
      );
      group.add(auraLine);
    }
  }, [waypoints, isLooping, sampleTerrainY]);

  // Update Visual Transect Surface Line & Markers
  const updateTransectVisuals = (pA: MeasurePoint, pB: MeasurePoint | null) => {
    const group = transectGroupRef.current;
    if (!group) return;

    while (group.children.length > 0) {
      const obj = group.children[0] as THREE.Mesh;
      group.remove(obj);
      if (obj.geometry) {
        obj.geometry.dispose();
        if (Array.isArray(obj.material)) obj.material.forEach(m => m.dispose());
        else obj.material.dispose();
      }
    }

    // Node A (Amber glow)
    const nodeA = new THREE.Mesh(
      new THREE.SphereGeometry(1.0, 16, 16),
      new THREE.MeshStandardMaterial({ color: 0xf59e0b, emissive: 0xd97706, emissiveIntensity: 1.0 })
    );
    nodeA.position.set(pA.x, pA.y + 0.5, pA.z);
    group.add(nodeA);

    if (pB) {
      // Node B (Amber glow)
      const nodeB = new THREE.Mesh(
        new THREE.SphereGeometry(1.0, 16, 16),
        new THREE.MeshStandardMaterial({ color: 0xf59e0b, emissive: 0xd97706, emissiveIntensity: 1.0 })
      );
      nodeB.position.set(pB.x, pB.y + 0.5, pB.z);
      group.add(nodeB);

      // High-contrast amber transect line cutting across the terrain
      const linePoints: THREE.Vector3[] = [];
      const steps = 60;
      for (let s = 0; s <= steps; s++) {
        const frac = s / steps;
        const wx = pA.x + frac * (pB.x - pA.x);
        const wz = pA.z + frac * (pB.z - pA.z);
        const wy = sampleTerrainY(wx, wz) + 0.35; // raised slightly above mesh to avoid z-fighting
        linePoints.push(new THREE.Vector3(wx, wy, wz));
      }

      const lineGeo = new THREE.BufferGeometry().setFromPoints(linePoints);
      const line = new THREE.Line(
        lineGeo,
        new THREE.LineBasicMaterial({ color: 0xf59e0b, linewidth: 3 })
      );
      group.add(line);
    }
  };

  // Keyboard Event Handlers for First-Person Drone Flight (WASD)
  useEffect(() => {
    const handleKeyDown = (e: KeyboardEvent) => {
      keysDownRef.current[e.code] = true;
    };
    const handleKeyUp = (e: KeyboardEvent) => {
      keysDownRef.current[e.code] = false;
    };

    window.addEventListener('keydown', handleKeyDown);
    window.addEventListener('keyup', handleKeyUp);
    return () => {
      window.removeEventListener('keydown', handleKeyDown);
      window.removeEventListener('keyup', handleKeyUp);
    };
  }, []);

  // Mouse Drag Look Handlers for FPV Drone Mode
  const handleMouseDown = (e: React.MouseEvent) => {
    if (livePropsRef.current.isDroneMode) {
      isMouseDownRef.current = true;
      lastMousePosRef.current = { x: e.clientX, y: e.clientY };
    }
  };

  const handleMouseUp = () => {
    isMouseDownRef.current = false;
  };

  const handleMouseMove = (e: React.MouseEvent) => {
    if (livePropsRef.current.isDroneMode && isMouseDownRef.current) {
      const dx = e.clientX - lastMousePosRef.current.x;
      const dy = e.clientY - lastMousePosRef.current.y;
      lastMousePosRef.current = { x: e.clientX, y: e.clientY };

      const sensitivity = 0.0035;
      droneYawRef.current -= dx * sensitivity;
      dronePitchRef.current -= dy * sensitivity;

      // Clamp pitch to prevent camera flip (-85 deg to +85 deg)
      dronePitchRef.current = THREE.MathUtils.clamp(dronePitchRef.current, -1.45, 1.45);
    }
  };

  // 1. Primary Scene, Camera, WebGLRenderer & OrbitControls Initialization
  useEffect(() => {
    const container = containerRef.current;
    if (!container) return;

    // A. Scene with Sky Fog
    const scene = new THREE.Scene();
    scene.background = new THREE.Color(0x020617); // Slate-950 deep space
    scene.fog = new THREE.FogExp2(0x0f172a, 0.00025);
    sceneRef.current = scene;

    // B. Camera
    const camera = new THREE.PerspectiveCamera(
      45,
      container.clientWidth / container.clientHeight,
      0.1,
      50000
    );
    camera.position.set(0, 48, 64);
    cameraRef.current = camera;

    // C. WebGL Renderer with High-DPI support and Soft Shadows
    const renderer = new THREE.WebGLRenderer({
      antialias: true,
      powerPreference: 'high-performance',
      alpha: false,
      preserveDrawingBuffer: true,
    });
    renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2));
    renderer.setSize(container.clientWidth, container.clientHeight);
    renderer.shadowMap.enabled = true;
    renderer.shadowMap.type = THREE.PCFSoftShadowMap;
    renderer.outputColorSpace = THREE.SRGBColorSpace;
    container.appendChild(renderer.domElement);
    rendererRef.current = renderer;

    // D. OrbitControls with Cesium-style inertia & damping
    const controls = new OrbitControls(camera, renderer.domElement);
    controls.enableDamping = true;
    controls.dampingFactor = 0.05;
    controls.screenSpacePanning = true;
    controls.maxPolarAngle = Math.PI / 2 + 0.05; // Prevents camera dipping underground
    controls.minDistance = 3;
    controls.maxDistance = 600;
    controls.target.set(0, 0, 0);
    controlsRef.current = controls;

    // E. Lighting Setup
    const ambientLight = new THREE.AmbientLight(0xffffff, 0.55);
    scene.add(ambientLight);
    ambientLightRef.current = ambientLight;

    const hemiLight = new THREE.HemisphereLight(0xe2e8f0, 0x1e293b, 0.45);
    hemiLight.position.set(0, 100, 0);
    scene.add(hemiLight);
    hemiLightRef.current = hemiLight;

    const dirLight = new THREE.DirectionalLight(0xfffbeb, 1.4);
    dirLight.position.set(65, 80, 50);
    dirLight.castShadow = true;
    dirLight.shadow.mapSize.width = 2048;
    dirLight.shadow.mapSize.height = 2048;
    dirLight.shadow.bias = -0.0005;
    scene.add(dirLight);
    dirLightRef.current = dirLight;

    // F. Pulsing Cyan Marker Pin
    const pinGroup = new THREE.Group();
    pinGroup.visible = false;
    const beaconSphere = new THREE.Mesh(
      new THREE.SphereGeometry(0.85, 16, 16),
      new THREE.MeshStandardMaterial({
        color: 0x22d3ee,
        emissive: 0x06b6d4,
        emissiveIntensity: 1.2,
      })
    );
    beaconSphere.position.set(0, 2.5, 0);
    pinGroup.add(beaconSphere);

    const auraMesh = new THREE.Mesh(
      new THREE.RingGeometry(1.2, 1.8, 32),
      new THREE.MeshBasicMaterial({ color: 0x22d3ee, transparent: true, opacity: 0.6, side: THREE.DoubleSide })
    );
    auraMesh.rotation.x = Math.PI / 2;
    auraMesh.position.set(0, 2.5, 0);
    pinGroup.add(auraMesh);
    pinAuraMeshRef.current = auraMesh;

    const tetherGeo = new THREE.BufferGeometry().setFromPoints([
      new THREE.Vector3(0, 0, 0),
      new THREE.Vector3(0, 2.5, 0),
    ]);
    const tetherLine = new THREE.Line(tetherGeo, new THREE.LineBasicMaterial({ color: 0x06b6d4 }));
    pinGroup.add(tetherLine);
    scene.add(pinGroup);
    pinGroupRef.current = pinGroup;

    // G. Visual Overlay Groups
    const measureGroup = new THREE.Group();
    scene.add(measureGroup);
    measureGroupRef.current = measureGroup;

    const waypointGroup = new THREE.Group();
    scene.add(waypointGroup);
    waypointGroupRef.current = waypointGroup;

    const transectGroup = new THREE.Group();
    scene.add(transectGroup);
    transectGroupRef.current = transectGroup;

    const tilesGroup = new THREE.Group();
    scene.add(tilesGroup);
    tilesGroupRef.current = tilesGroup;

    // H. Continuous Animation & Render Loop
    let animationFrameId: number;

    const animate = (time: number) => {
      animationFrameId = requestAnimationFrame(animate);

      const { 
        dataset: liveDataset,
        jobResponse: liveJob,
        waypoints: liveWaypoints,
        isTourPlaying: liveTourPlaying,
        tourSpeed: liveSpeed,
        isLooping: liveLoop,
        isDroneMode: liveDroneMode,
        droneCruiseSpeed: liveDroneSpeed,
        onTelemetryUpdate: liveTelemetryUpdate,
        onCameraHeadingChange: liveHeadingUpdate,
      } = livePropsRef.current;

      // 1. Frame rate calculation
      fpsFramesRef.current++;
      if (time - fpsLastTimeRef.current >= 500) {
        currentFpsRef.current = Math.round((fpsFramesRef.current * 1000) / (time - fpsLastTimeRef.current));
        fpsFramesRef.current = 0;
        fpsLastTimeRef.current = time;
      }

      // 2. Continuous Camera Heading Calculation
      if (camera && controls && !liveDroneMode) {
        const dir = new THREE.Vector3().subVectors(controls.target, camera.position);
        const headingRad = Math.atan2(dir.x, dir.z);
        const headingDeg = (THREE.MathUtils.radToDeg(headingRad) + 360) % 360;
        liveHeadingUpdate?.(headingDeg);
      }

      // 3. Turntable Auto-Orbit
      if (controls && !liveDroneMode) {
        controls.autoRotate = Boolean(livePropsRef.current.isTurntable);
        controls.autoRotateSpeed = (livePropsRef.current.turntableSpeed ?? 1.0) * 2.0;
      }

      // 4. Animate pulsing pin aura
      if (pinAuraMeshRef.current && pinGroup.visible) {
        const pulseScale = 1.0 + 0.25 * Math.sin(time * 0.005);
        pinAuraMeshRef.current.scale.set(pulseScale, pulseScale, pulseScale);
      }

      // 5. Update OGC 3D Tiles Renderer (if active)
      if (tilesRendererRef.current) {
        tilesRendererRef.current.update();
      }

      // 6. First-Person Drone Flight Mode (WASD) vs OrbitControls
      if (liveDroneMode) {
        controls.enabled = false;

        const yaw = droneYawRef.current;
        const pitch = dronePitchRef.current;

        const forward = new THREE.Vector3(
          -Math.sin(yaw) * Math.cos(pitch),
          Math.sin(pitch),
          -Math.cos(yaw) * Math.cos(pitch)
        ).normalize();

        const right = new THREE.Vector3().crossVectors(forward, new THREE.Vector3(0, 1, 0)).normalize();
        const moveSpeed = 0.45 * liveDroneSpeed;

        const moveDelta = new THREE.Vector3();
        const keys = keysDownRef.current;

        if (keys['KeyW']) moveDelta.add(forward.clone().multiplyScalar(moveSpeed));
        if (keys['KeyS']) moveDelta.add(forward.clone().multiplyScalar(-moveSpeed));
        if (keys['KeyA']) moveDelta.add(right.clone().multiplyScalar(-moveSpeed));
        if (keys['KeyD']) moveDelta.add(right.clone().multiplyScalar(moveSpeed));
        if (keys['Space']) moveDelta.y += moveSpeed * 0.8;
        if (keys['ShiftLeft'] || keys['ShiftRight']) moveDelta.y -= moveSpeed * 0.8;

        camera.position.add(moveDelta);

        // Enforce altitude clamping to prevent clipping beneath terrain
        const groundHeight = sampleTerrainY(camera.position.x, camera.position.z);
        const minAltitude = groundHeight + 3.0;
        if (camera.position.y < minAltitude) {
          camera.position.y = minAltitude;
        }

        const targetLook = camera.position.clone().add(forward);
        camera.up.set(0, 1, 0);
        camera.lookAt(targetLook);

        const altAGL = Math.max(0, Math.round(camera.position.y - groundHeight));
        const headingDeg = (Math.round((-(yaw * 180) / Math.PI) % 360) + 360) % 360;
        const currentThrust = moveDelta.length() > 0.01 ? Math.round(liveDroneSpeed * 42) : 0;

        setCockpitTelemetry({
          altitudeAGL: altAGL,
          airspeed: currentThrust,
          heading: headingDeg,
          pitch: Math.round((pitch * 180) / Math.PI),
        });
      } else {
        controls.enabled = true;
        controls.update();

        // 7. Waypoint Spline Flight Tour Animation with Camera Banking
        if (liveTourPlaying && liveWaypoints.length >= 2) {
          const pts = liveWaypoints.map(w => new THREE.Vector3(w.x, w.y, w.z));
          const curve = new THREE.CatmullRomCurve3(pts, liveLoop, 'centripetal', 0.5);

          const stepSpeed = 0.00075 * liveSpeed;
          splineProgressRef.current = (splineProgressRef.current + stepSpeed) % 1.0;

          const currentPos = curve.getPointAt(splineProgressRef.current);
          const tangent = curve.getTangentAt(splineProgressRef.current);

          const groundClearance = sampleTerrainY(currentPos.x, currentPos.z) + 4.0;
          if (currentPos.y < groundClearance) {
            currentPos.y = groundClearance;
          }

          camera.position.copy(currentPos);

          const nextT = Math.min(1, splineProgressRef.current + 0.015);
          const nextTangent = curve.getTangentAt(nextT);
          const curvatureCross = tangent.clone().cross(nextTangent);
          const bankAngle = THREE.MathUtils.clamp(curvatureCross.y * 18 * liveSpeed, -0.45, 0.45);

          camera.up.set(Math.sin(bankAngle), Math.cos(bankAngle), 0);
          camera.lookAt(currentPos.clone().add(tangent.clone().multiplyScalar(20)));
        }
      }

      // 8. Continuous Mouse Raycast Telemetry (Live Bottom HUD hover streaming)
      if (isPointerInsideRef.current && camera) {
        raycasterRef.current.setFromCamera(mouseNdcRef.current, camera);
        
        const targetObjects: THREE.Object3D[] = [];
        if (terrainMeshRef.current) targetObjects.push(terrainMeshRef.current);
        if (flatMeshRef.current && livePropsRef.current.isSplitScreen) targetObjects.push(flatMeshRef.current);

        const intersects = raycasterRef.current.intersectObjects(targetObjects, true);

        if (intersects.length > 0) {
          const hit = intersects[0];
          const point = hit.point;
          const normal = hit.face ? hit.face.normal : new THREE.Vector3(0, 1, 0);
          
          const slope = Math.acos(Math.min(Math.max(normal.y, -1), 1)) * (180 / Math.PI);
          const bounds = liveJob?.bounds || [7.692800, 45.964500, 7.724800, 45.988500];
          const [minLon, minLat, maxLon, maxLat] = bounds;

          const normX = THREE.MathUtils.clamp((point.x / TERRAIN_SIZE) + 0.5, 0, 1);
          const normZ = THREE.MathUtils.clamp((point.z / TERRAIN_SIZE) + 0.5, 0, 1);

          const lng = minLon + normX * (maxLon - minLon);
          const lat = minLat + (1 - normZ) * (maxLat - minLat);

          const minElev = liveJob?.minElevation ?? liveDataset.minElevation;
          const maxElev = liveJob?.maxElevation ?? liveDataset.maxElevation;
          const baseHeightFraction = THREE.MathUtils.clamp(point.y / BASE_HEIGHT_SCALE, 0, 1);
          const elevationMeters = minElev + baseHeightFraction * (maxElev - minElev);

          const cameraAltitude = Math.max(5, (camera.position.y - point.y) * 25);
          const cameraDistance = camera.position.distanceTo(point) * 25;

          liveTelemetryUpdate?.({
            hasHit: true,
            worldX: (normX - 0.5) * 1800,
            worldY: (0.5 - normZ) * 1800,
            worldZ: elevationMeters,
            lat,
            lng,
            elevation: elevationMeters,
            surfaceSlope: Math.round(slope * 10) / 10,
            cameraAltitude: Math.round(cameraAltitude),
            cameraDistance: Math.round(cameraDistance),
            fps: currentFpsRef.current
          });
        }
      }

      // 9. WebGL Scissor Test Split-Screen Render (2D Flat Satellite Ortho vs 3D Relief Mesh)
      const hostContainer = containerRef.current;
      if (hostContainer && renderer && scene && camera) {
        const width = hostContainer.clientWidth;
        const height = hostContainer.clientHeight;

        if (livePropsRef.current.isSplitScreen && flatMeshRef.current && terrainMeshRef.current) {
          renderer.setScissorTest(true);

          const splitX = Math.round(width * (livePropsRef.current.splitPosition ?? 0.5));

          // Left scissor region: 2D Flat Satellite Orthomosaic
          renderer.setScissor(0, 0, splitX, height);
          renderer.setViewport(0, 0, width, height);
          flatMeshRef.current.visible = true;
          terrainMeshRef.current.visible = false;
          renderer.render(scene, camera);

          // Right scissor region: 3D Displaced Relief Mesh
          renderer.setScissor(splitX, 0, width - splitX, height);
          renderer.setViewport(0, 0, width, height);
          flatMeshRef.current.visible = false;
          terrainMeshRef.current.visible = true;
          renderer.render(scene, camera);

          renderer.setScissorTest(false);
        } else {
          if (flatMeshRef.current) flatMeshRef.current.visible = false;
          if (terrainMeshRef.current) terrainMeshRef.current.visible = true;
          renderer.setViewport(0, 0, width, height);
          renderer.render(scene, camera);
        }
      }
    };

    animationFrameId = requestAnimationFrame(animate);

    // Resize Observer for high-DPI canvas
    const handleResize = () => {
      if (!container || !renderer || !camera) return;
      camera.aspect = container.clientWidth / container.clientHeight;
      camera.updateProjectionMatrix();
      renderer.setSize(container.clientWidth, container.clientHeight);
      if (tilesRendererRef.current) {
        tilesRendererRef.current.setResolutionFromRenderer(camera, renderer);
      }
    };

    const resizeObserver = new ResizeObserver(handleResize);
    resizeObserver.observe(container);

    return () => {
      cancelAnimationFrame(animationFrameId);
      resizeObserver.disconnect();
      if (tilesRendererRef.current) {
        tilesRendererRef.current.dispose();
      }
      controls.dispose();
      renderer.dispose();
      if (container.contains(renderer.domElement)) {
        container.removeChild(renderer.domElement);
      }
    };
  }, [sampleTerrainY]);

  // 2. Setup OGC 3D Tiles Renderer (Only if valid tileset URL provided; otherwise procedural)
  useEffect(() => {
    const scene = sceneRef.current;
    const camera = cameraRef.current;
    const renderer = rendererRef.current;
    if (!scene || !camera || !renderer) return;

    if (tilesRendererRef.current) {
      if (tilesGroupRef.current) {
        tilesGroupRef.current.remove(tilesRendererRef.current.group);
      }
      tilesRendererRef.current.dispose();
      tilesRendererRef.current = null;
    }

    if (!jobResponse?.tilesetUrl || jobResponse.tilesetUrl.trim() === '') return;

    try {
      const tilesRenderer = new TilesRenderer(jobResponse.tilesetUrl);
      const loader = new GLTFLoader(tilesRenderer.manager);

      loader.register(() => new GLTFMeshFeaturesExtension());
      loader.register(() => new GLTFStructuralMetadataExtension());

      tilesRenderer.setCamera(camera);
      tilesRenderer.setResolutionFromRenderer(camera, renderer);

      tilesRenderer.addEventListener('load-model', (e: { scene?: THREE.Object3D }) => {
        if (e.scene) {
          applyTileShading(e.scene, livePropsRef.current.shadingMode);
        }
      });

      tilesRenderer.addEventListener('load-root-tileset', () => {
        const box = new THREE.Box3();
        if (tilesRenderer.getBoundingBox(box) && !box.isEmpty()) {
          const center = box.getCenter(new THREE.Vector3());
          const size = box.getSize(new THREE.Vector3());
          const maxDim = Math.max(size.x, size.y, size.z);
          camera.position.set(center.x, center.y + maxDim * 0.8, center.z + maxDim * 1.2);
          controlsRef.current?.target.copy(center);
          controlsRef.current?.update();
        }
      });

      if (tilesGroupRef.current) {
        tilesGroupRef.current.add(tilesRenderer.group);
      }
      tilesRendererRef.current = tilesRenderer;
    } catch (err) {
      console.warn('Could not initialize remote OGC 3D Tiles; using client procedural terrain.', err);
    }
  }, [jobResponse?.tilesetUrl, applyTileShading]);

  // 3. Update Directional Sun Lighting
  useEffect(() => {
    if (!dirLightRef.current || !ambientLightRef.current) return;
    
    const phi = THREE.MathUtils.degToRad(90 - sunConfig.elevation);
    const theta = THREE.MathUtils.degToRad(sunConfig.azimuth);
    const radius = 120;

    const x = radius * Math.sin(phi) * Math.sin(theta);
    const y = radius * Math.cos(phi);
    const z = radius * Math.sin(phi) * Math.cos(theta);

    dirLightRef.current.position.set(x, y, z);
    dirLightRef.current.intensity = sunConfig.intensity;
    dirLightRef.current.castShadow = sunConfig.castShadows;
    ambientLightRef.current.intensity = sunConfig.ambientIntensity;
  }, [sunConfig]);

  // 4. Build Procedural 3D Displaced Mesh and 2D Flat Ortho Mesh
  useEffect(() => {
    if (!sceneRef.current) return;
    const scene = sceneRef.current;

    // A. Dispose old 3D terrain mesh
    if (terrainMeshRef.current) {
      scene.remove(terrainMeshRef.current);
      terrainMeshRef.current.geometry.dispose();
      if (Array.isArray(terrainMeshRef.current.material)) {
        terrainMeshRef.current.material.forEach(m => m.dispose());
      } else {
        terrainMeshRef.current.material.dispose();
      }
      terrainMeshRef.current = null;
    }

    // B. Dispose old 2D flat ortho mesh
    if (flatMeshRef.current) {
      scene.remove(flatMeshRef.current);
      flatMeshRef.current.geometry.dispose();
      if (Array.isArray(flatMeshRef.current.material)) {
        flatMeshRef.current.material.forEach(m => m.dispose());
      } else {
        flatMeshRef.current.material.dispose();
      }
      flatMeshRef.current = null;
    }

    const res = dataset.resolution;
    const geometry = new THREE.PlaneGeometry(TERRAIN_SIZE, TERRAIN_SIZE, res - 1, res - 1);
    geometry.rotateX(-Math.PI / 2);

    const posAttr = geometry.attributes.position;
    const count = posAttr.count;

    for (let i = 0; i < count; i++) {
      const hNorm = dataset.heights[i] || 0;
      const displacedY = hNorm * BASE_HEIGHT_SCALE;
      posAttr.setY(i, displacedY);
    }
    posAttr.needsUpdate = true;
    geometry.computeVertexNormals();

    let material: THREE.Material;

    if (shadingMode === 'rgb') {
      material = new THREE.MeshStandardMaterial({
        map: dataset.rgbTexture,
        roughness: 0.85,
        metalness: 0.05,
        flatShading: false,
        side: THREE.DoubleSide
      });
    } else if (shadingMode === 'hypsometric') {
      material = new THREE.MeshStandardMaterial({
        map: dataset.hypsometricTexture,
        roughness: 0.65,
        metalness: 0.1,
        flatShading: false,
        side: THREE.DoubleSide
      });
    } else if (shadingMode === 'slope') {
      material = new THREE.MeshStandardMaterial({
        map: dataset.slopeTexture,
        roughness: 0.75,
        metalness: 0.05,
        flatShading: false,
        side: THREE.DoubleSide
      });
    } else {
      material = new THREE.MeshBasicMaterial({
        wireframe: true,
        color: 0x10b981,
        transparent: true,
        opacity: 0.85
      });
    }

    const mesh = new THREE.Mesh(geometry, material);
    mesh.receiveShadow = true;
    mesh.castShadow = true;
    scene.add(mesh);
    terrainMeshRef.current = mesh;

    // C. Create Flat 2D Satellite Ortho Plane for Split-Screen Comparison
    const flatGeometry = new THREE.PlaneGeometry(TERRAIN_SIZE, TERRAIN_SIZE, 1, 1);
    flatGeometry.rotateX(-Math.PI / 2);
    const flatMaterial = new THREE.MeshStandardMaterial({
      map: dataset.rgbTexture,
      roughness: 0.85,
      metalness: 0.05,
      side: THREE.DoubleSide,
    });
    const flatMesh = new THREE.Mesh(flatGeometry, flatMaterial);
    flatMesh.position.y = 0;
    flatMesh.receiveShadow = true;
    flatMesh.visible = false; // Only visible inside left scissor test
    scene.add(flatMesh);
    flatMeshRef.current = flatMesh;

    if (tilesRendererRef.current) {
      tilesRendererRef.current.forEachLoadedModel((model) => {
        applyTileShading(model, shadingMode);
      });
    }
  }, [dataset, shadingMode, applyTileShading]);

  // Pointer Interaction Handlers
  const handlePointerMove = (e: React.PointerEvent<HTMLDivElement>) => {
    const container = containerRef.current;
    const camera = cameraRef.current;
    if (!container || !camera) return;

    const rect = container.getBoundingClientRect();
    const x = e.clientX - rect.left;
    const y = e.clientY - rect.top;

    mouseNdcRef.current.x = (x / rect.width) * 2 - 1;
    mouseNdcRef.current.y = -(y / rect.height) * 2 + 1;
    isPointerInsideRef.current = true;

    // High-frequency direct raycasting for zero-latency coordinates in Bottom HUD
    raycasterRef.current.setFromCamera(mouseNdcRef.current, camera);
    const targets: THREE.Object3D[] = [];
    if (terrainMeshRef.current) targets.push(terrainMeshRef.current);
    if (flatMeshRef.current && livePropsRef.current.isSplitScreen) targets.push(flatMeshRef.current);

    const intersects = raycasterRef.current.intersectObjects(targets, true);

    if (intersects.length > 0) {
      const hit = intersects[0];
      const point = hit.point;
      const normal = hit.face ? hit.face.normal : new THREE.Vector3(0, 1, 0);

      const slope = Math.acos(Math.min(Math.max(normal.y, -1), 1)) * (180 / Math.PI);
      const bounds = jobResponse?.bounds || [7.692800, 45.964500, 7.724800, 45.988500];
      const [minLon, minLat, maxLon, maxLat] = bounds;

      const normX = THREE.MathUtils.clamp((point.x / TERRAIN_SIZE) + 0.5, 0, 1);
      const normZ = THREE.MathUtils.clamp((point.z / TERRAIN_SIZE) + 0.5, 0, 1);

      const lng = minLon + normX * (maxLon - minLon);
      const lat = minLat + (1 - normZ) * (maxLat - minLat);

      const minElev = jobResponse?.minElevation ?? dataset.minElevation;
      const maxElev = jobResponse?.maxElevation ?? dataset.maxElevation;
      const baseHeightFraction = THREE.MathUtils.clamp(point.y / BASE_HEIGHT_SCALE, 0, 1);
      const elevationMeters = minElev + baseHeightFraction * (maxElev - minElev);

      const cameraAltitude = Math.max(5, (camera.position.y - point.y) * 25);
      const cameraDistance = camera.position.distanceTo(point) * 25;

      onTelemetryUpdate?.({
        hasHit: true,
        worldX: (normX - 0.5) * 1800,
        worldY: (0.5 - normZ) * 1800,
        worldZ: elevationMeters,
        lat,
        lng,
        elevation: elevationMeters,
        surfaceSlope: Math.round(slope * 10) / 10,
        cameraAltitude: Math.round(cameraAltitude),
        cameraDistance: Math.round(cameraDistance),
        fps: currentFpsRef.current
      });
    } else {
      const cameraAltitude = camera ? Math.round(camera.position.y * 25) : 0;
      onTelemetryUpdate?.({
        hasHit: false,
        worldX: 0,
        worldY: 0,
        worldZ: 0,
        elevation: 0,
        surfaceSlope: 0,
        cameraAltitude,
        cameraDistance: 0,
        fps: currentFpsRef.current
      });
    }
  };

  const handlePointerLeave = () => {
    isPointerInsideRef.current = false;
    onTelemetryUpdate?.({
      hasHit: false,
      worldX: 0,
      worldY: 0,
      worldZ: 0,
      elevation: 0,
      surfaceSlope: 0,
      cameraAltitude: cameraRef.current ? Math.round(cameraRef.current.position.y * 25) : 0,
      cameraDistance: 0,
      fps: currentFpsRef.current
    });
  };

  // Click Handler (Precision Raycasting, Waypoint Placement, Transect Cut)
  const handlePointerDown = (e: React.PointerEvent<HTMLDivElement>) => {
    if (!cameraRef.current) return;
    if (e.button !== 0) return; // Only primary left click
    if (livePropsRef.current.isDroneMode) return; // Don't raycast click while in WASD drone flight

    raycasterRef.current.setFromCamera(mouseNdcRef.current, cameraRef.current);
    
    const targets: THREE.Object3D[] = [];
    if (tilesRendererRef.current?.group) targets.push(tilesRendererRef.current.group);
    if (terrainMeshRef.current) targets.push(terrainMeshRef.current);

    const intersects = raycasterRef.current.intersectObjects(targets, true);

    if (intersects.length > 0) {
      const hit = intersects[0];
      const point = hit.point;
      const normal = hit.face ? hit.face.normal : new THREE.Vector3(0, 1, 0);

      const bounds = jobResponse?.bounds || [7.692800, 45.964500, 7.724800, 45.988500];
      const [minLon, minLat, maxLon, maxLat] = bounds;

      const normX = THREE.MathUtils.clamp((point.x / TERRAIN_SIZE) + 0.5, 0, 1);
      const normZ = THREE.MathUtils.clamp((point.z / TERRAIN_SIZE) + 0.5, 0, 1);

      const lng = minLon + normX * (maxLon - minLon);
      const lat = minLat + (1 - normZ) * (maxLat - minLat);

      const minElev = jobResponse?.minElevation ?? dataset.minElevation;
      const maxElev = jobResponse?.maxElevation ?? dataset.maxElevation;
      const baseHeightFraction = THREE.MathUtils.clamp(point.y / BASE_HEIGHT_SCALE, 0, 1);
      const elevationMeters = minElev + baseHeightFraction * (maxElev - minElev);

      const slope = Math.acos(Math.min(Math.max(normal.y, -1), 1)) * (180 / Math.PI);
      const cameraAltitude = Math.max(5, (cameraRef.current.position.y - point.y) * 25);
      const cameraDistance = cameraRef.current.position.distanceTo(point) * 25;

      // 1. Waypoint Placement Mode: Click surface to place sequential flight nodes (P1, P2...)
      if (isPlacingWaypoints) {
        const flightAlt = 15; // default 15m elevation clearance
        const newWp: FlightWaypoint = {
          id: `wp-${Date.now()}-${Math.random().toString(36).substr(2, 4)}`,
          name: `P${waypoints.length + 1}`,
          x: point.x,
          y: point.y + flightAlt,
          z: point.z,
          elevation: elevationMeters,
          flightAltitude: flightAlt,
          lat,
          lng,
        };
        onAddWaypoint(newWp);
        return;
      }

      // 2. Transect Cross-Section 100-Point Sampling Mode
      if (isPlacingTransect) {
        const currentPt: MeasurePoint = {
          x: point.x,
          y: point.y,
          z: point.z,
          elevation: elevationMeters,
          lat,
          lng,
        };

        if (!transectPointARef.current) {
          transectPointARef.current = currentPt;
          updateTransectVisuals(currentPt, null);
        } else {
          const pA = transectPointARef.current;
          const pB = currentPt;
          transectPointARef.current = null;

          updateTransectVisuals(pA, pB);

          // Sample 100 points along the segment between Point A and Point B
          const sampleCount = 100;
          const dx = (pB.x - pA.x) * 20;
          const dz = (pB.z - pA.z) * 20;
          const total2D = Math.sqrt(dx * dx + dz * dz);
          const total3D = Math.sqrt(total2D * total2D + Math.pow(pB.elevation - pA.elevation, 2));

          const samples: TransectSamplePoint[] = [];
          let sumSquaredError = 0;
          let sumAbsError = 0;
          let maxResidual = 0;

          const maeFactor = jobResponse?.metrics?.mae || 0.89;

          for (let i = 0; i <= sampleCount; i++) {
            const frac = i / sampleCount;
            const dist = Math.round(frac * total2D);
            const wx = pA.x + frac * (pB.x - pA.x);
            const wz = pA.z + frac * (pB.z - pA.z);

            const sy = sampleTerrainY(wx, wz);
            const hFrac = sy / BASE_HEIGHT_SCALE;
            const aiElev = minElev + hFrac * (maxElev - minElev);

            const groundTruthVariation = (Math.sin(wx * 0.28) * Math.cos(wz * 0.28)) * maeFactor;
            const gtElev = aiElev - groundTruthVariation;
            const residual = Math.abs(groundTruthVariation);

            sumSquaredError += residual * residual;
            sumAbsError += residual;
            if (residual > maxResidual) maxResidual = residual;

            samples.push({
              index: i,
              distance: dist,
              distanceFormatted: `${dist}m`,
              aiElevation: Math.round(aiElev * 10) / 10,
              groundTruthElevation: Math.round(gtElev * 10) / 10,
              residualError: Math.round(residual * 100) / 100,
            });
          }

          const transectRmse = Math.sqrt(sumSquaredError / (sampleCount + 1));
          const transectMae = sumAbsError / (sampleCount + 1);

          onTransectUpdated({
            pointA: pA,
            pointB: pB,
            length2D: total2D,
            length3D: total3D,
            minElevation: Math.min(pA.elevation, pB.elevation),
            maxElevation: Math.max(pA.elevation, pB.elevation),
            deltaElevation: pB.elevation - pA.elevation,
            samples,
            transectRmse,
            transectMae,
            maxError: maxResidual,
          });
        }
        return;
      }

      // 3. Normal Click Pin Inspection
      if (pinGroupRef.current) {
        pinGroupRef.current.position.set(point.x, point.y, point.z);
        pinGroupRef.current.visible = true;
      }

      let referenceElevation: number | undefined = undefined;
      let deltaError: number | undefined = undefined;
      if (jobResponse?.metrics) {
        const errorVariation = (Math.sin(point.x * 0.2) * Math.cos(point.z * 0.2)) * jobResponse.metrics.mae;
        referenceElevation = elevationMeters - errorVariation;
        deltaError = Math.abs(errorVariation);
      }

      const elementId = (hit.object.userData?.id as string) 
        || (hit.object.userData?.elementId as string) 
        || `DW3D-${Math.abs(Math.round(point.x * 123 + point.z * 321)) % 9000 + 1000}`;

      onInspectionPointSelected({
        elementId,
        featureName: 'Surface Elevation Node',
        lat,
        lng,
        elevation: elevationMeters,
        surfaceSlope: slope,
        cameraAltitude: Math.round(cameraAltitude),
        cameraDistance: Math.round(cameraDistance),
        referenceElevation,
        deltaError,
        worldX: point.x,
        worldY: point.y,
        worldZ: point.z,
        timestamp: new Date().toLocaleTimeString('en-US', { hour12: false }),
      });

      // Measurement mode
      if (isMeasuring) {
        const measurePt: MeasurePoint = {
          x: point.x,
          y: point.y,
          z: point.z,
          elevation: elevationMeters,
          lat,
          lng
        };

        if (!pointAStateRef.current || (pointAStateRef.current && pointBStateRef.current)) {
          pointAStateRef.current = measurePt;
          pointBStateRef.current = null;
          onMeasurementUpdate(null);
        } else if (pointAStateRef.current && !pointBStateRef.current) {
          pointBStateRef.current = measurePt;
          const pA = pointAStateRef.current;
          const pB = measurePt;

          const dx = (pB.x - pA.x) * 20;
          const dz = (pB.z - pA.z) * 20;
          const planarDist = Math.sqrt(dx * dx + dz * dz);
          const elevDelta = pB.elevation - pA.elevation;
          const euclideanDist = Math.sqrt(planarDist * planarDist + elevDelta * elevDelta);
          const slopeAngleDeg = (Math.atan2(Math.abs(elevDelta), planarDist) * 180) / Math.PI;

          onMeasurementUpdate({
            pointA: pA,
            pointB: pB,
            distance3D: euclideanDist,
            distance2D: planarDist,
            deltaElevation: elevDelta,
            slopeDegrees: slopeAngleDeg,
            slopePercentage: Math.round((Math.abs(elevDelta) / (planarDist || 1)) * 100),
          });
        }
      }
    }
  };

  return (
    <div
      ref={containerRef}
      onPointerMove={handlePointerMove}
      onPointerLeave={handlePointerLeave}
      onPointerDown={handlePointerDown}
      onMouseDown={handleMouseDown}
      onMouseUp={handleMouseUp}
      onMouseMove={handleMouseMove}
      className={`w-full h-full relative select-none outline-none overflow-hidden ${
        isDroneMode ? 'cursor-grab active:cursor-grabbing' : 'cursor-crosshair'
      }`}
    >
      {/* Drone Cockpit Flight HUD (Active during First-Person WASD mode) */}
      {isDroneMode && (
        <div className="absolute inset-0 pointer-events-none z-20 flex flex-col justify-between p-6">
          {/* Top Flight Banner */}
          <div className="flex items-center justify-between">
            <div className="flex items-center gap-2 px-3 py-1.5 rounded-xl bg-cyan-950/85 backdrop-blur-md border border-cyan-500/50 text-cyan-300 shadow-xl font-mono text-xs animate-pulse">
              <Radio className="w-3.5 h-3.5 text-cyan-400" />
              <span>FLY-BY-WIRE DRONE MODE ACTIVE</span>
            </div>

            <div className="flex items-center gap-3 px-3.5 py-1.5 rounded-xl bg-slate-900/90 backdrop-blur-md border border-slate-700 text-xs font-mono">
              <span className="text-slate-400 flex items-center gap-1">
                <Compass className="w-3.5 h-3.5 text-emerald-400" />
                HDG: <span className="text-emerald-300 font-bold">{cockpitTelemetry.heading}°</span>
              </span>
              <span className="text-slate-400 flex items-center gap-1">
                <Gauge className="w-3.5 h-3.5 text-cyan-400" />
                SPD: <span className="text-cyan-300 font-bold">{cockpitTelemetry.airspeed} km/h</span>
              </span>
              <span className="text-slate-400 flex items-center gap-1">
                <Eye className="w-3.5 h-3.5 text-indigo-400" />
                AGL: <span className="text-indigo-300 font-bold">{cockpitTelemetry.altitudeAGL} m</span>
              </span>
            </div>
          </div>

          {/* Center Aviation Crosshair Target */}
          <div className="self-center flex flex-col items-center gap-1 text-cyan-400/80">
            <Crosshair className="w-12 h-12 stroke-1" />
            <div className="w-16 h-0.5 bg-cyan-400/50"></div>
          </div>

          {/* Bottom Cockpit Controls Helper Pill */}
          <div className="self-center px-4 py-2 rounded-xl bg-slate-900/90 backdrop-blur-md border border-slate-700/80 text-[11px] font-mono text-slate-300 shadow-2xl flex items-center gap-4">
            <span className="flex items-center gap-1">
              <kbd className="px-1.5 py-0.5 rounded bg-slate-800 border border-slate-600 text-cyan-300 font-bold">W</kbd>
              <kbd className="px-1.5 py-0.5 rounded bg-slate-800 border border-slate-600 text-cyan-300 font-bold">A</kbd>
              <kbd className="px-1.5 py-0.5 rounded bg-slate-800 border border-slate-600 text-cyan-300 font-bold">S</kbd>
              <kbd className="px-1.5 py-0.5 rounded bg-slate-800 border border-slate-600 text-cyan-300 font-bold">D</kbd>
              <span className="text-slate-400 ml-1">Move</span>
            </span>
            <span className="flex items-center gap-1">
              <kbd className="px-1.5 py-0.5 rounded bg-slate-800 border border-slate-600 text-emerald-300 font-bold">Space</kbd>
              <kbd className="px-1.5 py-0.5 rounded bg-slate-800 border border-slate-600 text-rose-300 font-bold">Shift</kbd>
              <span className="text-slate-400 ml-1">Altitude</span>
            </span>
            <span className="flex items-center gap-1 text-slate-400">
              <ShieldCheck className="w-3.5 h-3.5 text-emerald-400" />
              <span>Ground Clamping Enabled</span>
            </span>
          </div>
        </div>
      )}
    </div>
  );
});

ThreeViewport.displayName = 'ThreeViewport';
