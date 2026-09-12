'use client';

import React, { useRef, useEffect, useState } from 'react';
import * as THREE from 'three';
import { OrbitControls } from 'three/examples/jsm/controls/OrbitControls.js';
import InspectionCard from '../components/InspectionCard.js';
import Sidebar from '../components/Sidebar.js';
import SidebarNavigation from '../components/SidebarNavigation.js';
import TopNavDock from '../components/TopNavDock.js';
import CompassWidget from '../components/CompassWidget.js';
import { useCameraHeading } from '../hooks/useCameraHeading.js';
import { createUnifiedRaycastHandler } from '../hooks/useTerrainRaycast.js';
import { getAvailableDatasets, uploadReferenceDem } from '../services/elevationApi.js';

export default function DepthWizardApp() {
  const containerRef = useRef(null);
  const [isCardOpen, setIsCardOpen] = useState(false);
  const [isDrawerOpen, setIsDrawerOpen] = useState(true);
  const [isMeasureMode, setIsMeasureMode] = useState(false);

  // Surface inspection telemetry state
  const [inspectionData, setInspectionData] = useState(null);

  const [measurementData, setMeasurementData] = useState(null);
  const [datasets, setDatasets] = useState([]);
  const [selectedDataset, setSelectedDataset] = useState('ISRO Bhuvan CartoDEM');
  const [uploadStatus, setUploadStatus] = useState('');

  const [cameraInstance, setCameraInstance] = useState(null);
  const [controlsInstance, setControlsInstance] = useState(null);

  const { heading, resetToNorth, snapView } = useCameraHeading(
    cameraInstance,
    controlsInstance
  );

  const raycastHandlerRef = useRef(null);
  const terrainMeshRef = useRef(null);
  const sceneRef = useRef(null);

  // Load available datasets
  useEffect(() => {
    getAvailableDatasets().then((data) => {
      if (Array.isArray(data)) {
        setDatasets(data);
      } else if (data && Array.isArray(data.datasets)) {
        setDatasets(data.datasets);
      }
    });
  }, []);

  // Initialize Three.js 3D WebGIS Canvas & Terrain
  useEffect(() => {
    const container = containerRef.current;
    if (!container) return;

    const scene = new THREE.Scene();
    sceneRef.current = scene;
    scene.background = new THREE.Color(0x080f21);
    scene.fog = new THREE.FogExp2(0x080f21, 0.0015);

    // Camera
    const camera = new THREE.PerspectiveCamera(
      50,
      container.clientWidth / container.clientHeight,
      0.1,
      5000
    );
    camera.position.set(130, 100, 150);

    // Renderer
    const renderer = new THREE.WebGLRenderer({
      antialias: true,
      powerPreference: 'high-performance'
    });
    renderer.setSize(container.clientWidth, container.clientHeight);
    renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2));
    renderer.toneMapping = THREE.ACESFilmicToneMapping;
    renderer.toneMappingExposure = 1.15;
    container.appendChild(renderer.domElement);

    // Orbit Controls
    const controls = new OrbitControls(camera, renderer.domElement);
    controls.enableDamping = true;
    controls.dampingFactor = 0.05;
    controls.maxDistance = 1500;
    controls.minDistance = 10;
    controls.target.set(0, 15, 0);

    setCameraInstance(camera);
    setControlsInstance(controls);

    // Lighting
    const ambientLight = new THREE.AmbientLight(0xffffff, 1.2);
    scene.add(ambientLight);

    const sunLight = new THREE.DirectionalLight(0xfff7ed, 2.4);
    sunLight.position.set(150, 260, 120);
    scene.add(sunLight);

    const fillLight = new THREE.DirectionalLight(0x38bdf8, 0.6);
    fillLight.position.set(-150, 80, -100);
    scene.add(fillLight);

    // Ground Reference Grid
    const grid = new THREE.GridHelper(300, 30, 0x00f0ff, 0x1e293b);
    grid.position.y = -0.5;
    scene.add(grid);

    // Procedural Mountainous 3D Terrain Mesh (DEM Simulation)
    const terrainWidth = 180;
    const terrainHeight = 180;
    const segments = 128;
    const geometry = new THREE.PlaneGeometry(terrainWidth, terrainHeight, segments, segments);
    geometry.rotateX(-Math.PI / 2);

    const pos = geometry.attributes.position;
    for (let i = 0; i < pos.count; i++) {
      const x = pos.getX(i);
      const z = pos.getZ(i);
      const d = Math.sqrt(x * x + z * z);
      const elevation =
        Math.sin(x * 0.05) * Math.cos(z * 0.05) * 12 +
        Math.sin(x * 0.1 + z * 0.08) * 6 +
        Math.cos(x * 0.02) * Math.sin(z * 0.02) * 22 +
        Math.max(0, 32 - d * 0.35);

      pos.setY(i, Math.max(0, elevation));
    }
    geometry.computeVertexNormals();

    const terrainMaterial = new THREE.MeshStandardMaterial({
      color: 0x334155,
      roughness: 0.85,
      metalness: 0.15,
      wireframe: false,
      flatShading: false
    });

    const terrainMesh = new THREE.Mesh(geometry, terrainMaterial);
    terrainMesh.name = 'TerrainMesh';
    scene.add(terrainMesh);
    terrainMeshRef.current = terrainMesh;

    // Create Unified Raycast & Caliper Handler
    const handler = createUnifiedRaycastHandler({
      camera,
      terrainMesh,
      scene,
      isMeasureMode,
      onPickInspection: (data) => {
        setInspectionData(data);
        setIsCardOpen(true);
      },
      onUpdateMeasurement: setMeasurementData,
      bounds: { minLat: 45.965, maxLat: 45.995, minLon: 7.685, maxLon: 7.725 }
    });
    raycastHandlerRef.current = handler;

    const onPointerDown = (e) => {
      handler.handlePointerDown(e);
    };
    renderer.domElement.addEventListener('pointerdown', onPointerDown);

    // Resize Handler
    const handleResize = () => {
      if (!container) return;
      camera.aspect = container.clientWidth / container.clientHeight;
      camera.updateProjectionMatrix();
      renderer.setSize(container.clientWidth, container.clientHeight);
    };
    window.addEventListener('resize', handleResize);

    // Animation Loop
    let animationFrameId;
    const animate = () => {
      animationFrameId = requestAnimationFrame(animate);
      controls.update();
      renderer.render(scene, camera);
    };
    animate();

    return () => {
      cancelAnimationFrame(animationFrameId);
      window.removeEventListener('resize', handleResize);
      renderer.domElement.removeEventListener('pointerdown', onPointerDown);
      handler.clearMeasurementVisuals();
      renderer.dispose();
      setCameraInstance(null);
      setControlsInstance(null);
      if (container.contains(renderer.domElement)) {
        container.removeChild(renderer.domElement);
      }
    };
  }, []);

  // Update measure mode in active raycast handler
  useEffect(() => {
    if (raycastHandlerRef.current) {
      raycastHandlerRef.current = createUnifiedRaycastHandler({
        camera: sceneRef.current?.children?.find(c => c.isCamera) || null,
        terrainMesh: terrainMeshRef.current,
        scene: sceneRef.current,
        isMeasureMode,
        onPickInspection: (data) => {
          setInspectionData(data);
          setIsCardOpen(true);
        },
        onUpdateMeasurement: setMeasurementData,
        bounds: { minLat: 45.965, maxLat: 45.995, minLon: 7.685, maxLon: 7.725 }
      });
    }
  }, [isMeasureMode]);

  // Handle DEM Upload
  const handleDemUpload = async (e) => {
    const file = e.target.files?.[0];
    if (!file) return;

    setUploadStatus(`Uploading ${file.name}...`);
    try {
      const res = await uploadReferenceDem(file);
      setUploadStatus(`✓ ${res.filename} loaded (${res.raster_format})`);
      setTimeout(() => setUploadStatus(''), 4000);
    } catch {
      setUploadStatus('Upload error');
    }
  };

  return (
    <main className="relative w-screen h-screen overflow-hidden bg-[#080f21] select-none">
      {/* 3D WebGL Canvas */}
      <div ref={containerRef} className="w-full h-full cursor-crosshair" />

      {/* Top Header Bar */}
      <header className="absolute top-0 left-0 right-0 h-14 bg-[#0b1329]/90 backdrop-blur-md border-b border-cyan-500/20 px-5 flex items-center justify-between z-20">
        <div className="flex items-center gap-3 ml-14">
          <div className="flex h-8 w-8 items-center justify-center rounded-lg bg-cyan-500/20 text-cyan-400 border border-cyan-500/40 text-lg">
            ◈
          </div>
          <div>
            <h1 className="text-sm font-bold tracking-wide text-white flex items-center gap-2">
              DepthWizard 3D
              <span className="text-[10px] uppercase font-mono px-1.5 py-0.5 rounded bg-cyan-950 text-cyan-300 border border-cyan-500/30">
                Ground-Truth Verification Rail
              </span>
            </h1>
            <p className="text-[10px] text-slate-400">
              Single-View Height Estimation & Sub-Meter LiDAR Benchmark Audit
            </p>
          </div>
        </div>

        {/* Top Actions */}
        <div className="flex items-center gap-3 text-xs">
          {/* Upload .tif */}
          <label className="cursor-pointer flex items-center gap-1 bg-cyan-950 hover:bg-cyan-900 text-cyan-300 px-2.5 py-1 rounded-lg border border-cyan-500/40 transition-colors">
            <span>↑</span>
            <span>Upload .TIF</span>
            <input
              type="file"
              accept=".tif,.tiff"
              onChange={handleDemUpload}
              className="hidden"
            />
          </label>

          {uploadStatus && (
            <span className="text-[11px] text-emerald-400 font-mono animate-pulse">
              {uploadStatus}
            </span>
          )}

          {!isCardOpen && (
            <button
              onClick={() => setIsCardOpen(true)}
              className="bg-cyan-500/20 hover:bg-cyan-500/30 text-cyan-300 px-2.5 py-1 rounded-lg border border-cyan-500/40 text-xs transition-colors"
            >
              Open Inspector Card
            </button>
          )}
        </div>
      </header>

      {/* ============================================================
          TOP VIEWPORT COMPASS & VIEW SNAPPING FLOATING NAVIGATION DOCK
          ============================================================ */}
      <TopNavDock
        heading={heading}
        onResetNorth={resetToNorth}
        onSnapView={snapView}
        className="left-20"
      />

      {/* ============================================================
          LEFT SIDEBAR: Raycast Measurement (3D Metric Vector & Slope Analysis)
          ============================================================ */}
      <Sidebar
        isMeasureMode={isMeasureMode}
        onToggleMeasureMode={setIsMeasureMode}
        measurementData={measurementData}
        onClearMeasurement={() => {
          if (raycastHandlerRef.current) {
            raycastHandlerRef.current.clearMeasurementVisuals();
          }
          setMeasurementData(null);
        }}
        inspectionData={inspectionData}
        selectedDataset={selectedDataset}
        onSelectDataset={setSelectedDataset}
        className="absolute top-14 left-0 bottom-0 shadow-2xl"
      />

      {/* ============================================================
          RIGHT-ALIGNED FLOATING INSPECTION CARD
          ============================================================ */}
      <InspectionCard
        isOpen={isCardOpen}
        onClose={() => setIsCardOpen(false)}
        inspectionData={inspectionData}
        badgeId="DW3D-2574"
      />

      {/* Bottom Hint HUD */}
      <div className="absolute bottom-4 left-20 z-20 flex items-center gap-3 text-[11px] font-mono text-slate-400 bg-slate-950/80 backdrop-blur-sm px-3.5 py-1.5 rounded-lg border border-slate-800 shadow-lg">
        <div className="flex items-center gap-1.5">
          <span className="h-2 w-2 rounded-full bg-cyan-400 animate-ping" />
          <span className="text-cyan-300 font-semibold">SYNCHRONIZED GIS RAIL</span>
        </div>
        <span>•</span>
        <span>Click terrain to sample WGS84 coordinates, fire API verification, & update both panels</span>
      </div>
    </main>
  );
}
