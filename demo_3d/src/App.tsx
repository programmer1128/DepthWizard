import { useState, useRef, useMemo, useCallback, useEffect } from 'react';
import type { 
  ShadingMode, 
  ActiveDrawer, 
  SunLightingConfig, 
  MeasurementResult,
  TerrainMetadata,
  TelemetryData,
  FlightWaypoint,
  TransectMeasurement,
  TransectSamplePoint
} from './types/gis';
import type { ElevationInspectionPoint } from './types/elevationApi';
import { PRESET_DATASETS } from './data/presets';
import type { PresetDataset } from './data/presets';
import { generateTerrainDataset } from './utils/terrainGenerator';
import type { TerrainDataPackage } from './utils/terrainGenerator';
import { useElevationPipeline } from './hooks/useElevationPipeline';
import { TopNavBar } from './components/studio/TopNavBar';
import { SlimToolbar } from './components/studio/SlimToolbar';
import { IngestDrawer } from './components/studio/IngestDrawer';
import { ShadingDrawer } from './components/studio/ShadingDrawer';
import { DroneTourDrawer } from './components/studio/DroneTourDrawer';
import { AccuracyValidationDrawer } from './components/studio/AccuracyValidationDrawer';
import { MeasureDrawer } from './components/studio/MeasureDrawer';
import { SunLightingDrawer } from './components/studio/SunLightingDrawer';
import { SettingsDrawer } from './components/studio/SettingsDrawer';
import { RightTelemetryPanel } from './components/studio/RightTelemetryPanel';
import { TelemetryHUD } from './components/studio/TelemetryHUD';
import { ThreeViewport } from './components/viewport/ThreeViewport';
import type { ThreeViewportHandle } from './components/viewport/ThreeViewport';
import { ViewportNavigationControls } from './components/viewport/ViewportNavigationControls';
import { 
  Layers, 
  Globe, 
  Radio, 
  Play, 
  Pause, 
  Camera, 
  Maximize, 
  Minimize, 
  ArrowLeft 
} from 'lucide-react';

// Initial Preset Flight Path (Ridge Crest Survey)
const INITIAL_WAYPOINTS: FlightWaypoint[] = [
  { id: 'wp-1', name: 'P1 (West Ridge)', x: -28, y: 26, z: -20, elevation: 2150, flightAltitude: 15, lat: 45.9812, lng: 7.7012 },
  { id: 'wp-2', name: 'P2 (Summit Peak)', x: -2, y: 34, z: -6, elevation: 2842, flightAltitude: 16, lat: 45.9765, lng: 7.7088 },
  { id: 'wp-3', name: 'P3 (Cirque Descent)', x: 24, y: 24, z: 12, elevation: 1980, flightAltitude: 15, lat: 45.9715, lng: 7.7164 },
  { id: 'wp-4', name: 'P4 (Valley Approach)', x: -8, y: 22, z: 26, elevation: 1750, flightAltitude: 14, lat: 45.9680, lng: 7.7050 },
];

export function App() {
  // Standalone Route Detection (/standalone or ?mode=standalone)
  const [isStandalone, setIsStandalone] = useState<boolean>(() => {
    return window.location.pathname.includes('standalone') || 
           window.location.search.includes('mode=standalone') ||
           window.location.hash.includes('standalone');
  });

  // Sync browser back/forward buttons
  useEffect(() => {
    const handlePopState = () => {
      setIsStandalone(
        window.location.pathname.includes('standalone') || 
        window.location.search.includes('mode=standalone') ||
        window.location.hash.includes('standalone')
      );
    };
    window.addEventListener('popstate', handlePopState);
    return () => window.removeEventListener('popstate', handlePopState);
  }, []);

  // Active UI Drawer on Left Toolbar (Studio view)
  const [activeDrawer, setActiveDrawer] = useState<ActiveDrawer>('ingest');

  // Pure Client-Side Elevation Pipeline Simulation Hook
  const {
    pipelineStage,
    activeJobResponse,
    submitElevationJob,
    loadPresetJob,
  } = useElevationPipeline();

  // Active Dataset
  const [activePreset, setActivePreset] = useState<PresetDataset>(PRESET_DATASETS[0]);
  const [customImage, setCustomImage] = useState<HTMLImageElement | null>(null);

  // Shading Mode
  const [shadingMode, setShadingMode] = useState<ShadingMode>('rgb');

  // Sun & Solar Lighting Config
  const [sunConfig, setSunConfig] = useState<SunLightingConfig>({
    azimuth: 145,
    elevation: 38,
    intensity: 1.4,
    ambientIntensity: 0.55,
    castShadows: true,
  });
  const [timeOfDayHour, setTimeOfDayHour] = useState<number>(14.0);

  // Camera Optics & Navigation Controls State
  const [cameraHeading, setCameraHeading] = useState<number>(0);
  const [fov, setFov] = useState<number>(45);
  const [isTurntable, setIsTurntable] = useState<boolean>(false);
  const [isSplitScreen, setIsSplitScreen] = useState<boolean>(false);
  const [splitPosition, setSplitPosition] = useState<number>(0.5);

  // Waypoint Tour Flight State
  const [waypoints, setWaypoints] = useState<FlightWaypoint[]>(INITIAL_WAYPOINTS);
  const [isPlacingWaypoints, setIsPlacingWaypoints] = useState<boolean>(false);
  const [isTourPlaying, setIsTourPlaying] = useState<boolean>(false);
  const [tourSpeed, setTourSpeed] = useState<number>(1.0);
  const [isLooping, setIsLooping] = useState<boolean>(true);

  // First-Person Drone Flight (WASD) State
  const [isDroneMode, setIsDroneMode] = useState<boolean>(false);
  const [droneCruiseSpeed, setDroneCruiseSpeed] = useState<number>(1.0);

  // Transect Cross-Section 100-Point Sampling State
  const [isPlacingTransect, setIsPlacingTransect] = useState<boolean>(false);
  const [transect, setTransect] = useState<TransectMeasurement | null>(null);

  // Raycast Vector Measurement State
  const [isMeasuring, setIsMeasuring] = useState<boolean>(false);
  const [measurement, setMeasurement] = useState<MeasurementResult | null>(null);

  // Selected Feature Inspection Point (displayed in Right-Aligned Cesium Sandcastle Panel)
  const [inspectionPoint, setInspectionPoint] = useState<ElevationInspectionPoint | null>(null);

  // Real-time hover telemetry for Bottom HUD (Continuous streaming)
  const [telemetry, setTelemetry] = useState<TelemetryData>({
    hasHit: false,
    worldX: 0,
    worldY: 0,
    worldZ: 0,
    elevation: 0,
    surfaceSlope: 0,
    cameraAltitude: 1250,
    cameraDistance: 0,
    fps: 60,
  });

  // Fullscreen State
  const [isFullscreen, setIsFullscreen] = useState<boolean>(false);

  // Viewport Imperative Ref
  const viewportRef = useRef<ThreeViewportHandle>(null);

  // Generate 3D Terrain Data Package based on active preset or custom upload
  const terrainData: TerrainDataPackage = useMemo(() => {
    if (customImage) {
      return generateTerrainDataset('custom', customImage, 'georeferenced');
    }
    const presetId = activePreset.metadata.id as 'alpine-ridge-dsm' | 'quarry-mine-rdsm' | 'coastal-fjord-dsm';
    return generateTerrainDataset(presetId, null, 'georeferenced');
  }, [activePreset, customImage]);

  // Solar Time-of-Day Handler
  const handleTimeOfDayChange = (hour: number) => {
    setTimeOfDayHour(hour);
    // Calculate realistic sun azimuth and elevation from 24h clock
    const phi = ((hour - 6) * Math.PI) / 12;
    const elev = Math.sin(phi) * 68;
    const azim = ((hour / 24) * 360 + 90) % 360;

    const isDay = elev > 0;
    setSunConfig({
      azimuth: azim,
      elevation: Math.max(2, elev),
      intensity: isDay ? 0.8 + Math.sin(phi) * 0.8 : 0.25,
      ambientIntensity: isDay ? 0.55 : 0.25,
      castShadows: isDay,
    });
  };

  // Handle Preset Switching
  const handleSelectPreset = (presetId: string) => {
    const preset = PRESET_DATASETS.find(p => p.metadata.id === presetId);
    if (!preset) return;

    setCustomImage(null);
    setActivePreset(preset);
    setMeasurement(null);
    setInspectionPoint(null);
    setTransect(null);

    loadPresetJob(presetId);
  };

  // Handle File Upload from Ingest Drawer using pure in-memory pipeline simulation
  const handleRunPipeline = async (file: File) => {
    try {
      const resp = await submitElevationJob(file);

      const reader = new FileReader();
      reader.onload = (e) => {
        const img = new Image();
        img.onload = () => {
          setCustomImage(img);
          const customMetadata: TerrainMetadata = {
            id: resp.uuid,
            title: file.name,
            mode: 'georeferenced',
            crs: resp.crs || 'EPSG:4326 (WGS84)',
            gsd: '0.25 m/pixel',
            verticalDatum: 'EGM96 Orthometric (MSL)',
            minElevation: resp.minElevation,
            maxElevation: resp.maxElevation,
            areaCoverage: '2.0 km × 2.0 km',
            dateCaptured: new Date().toISOString().replace('T', ' ').substring(0, 19) + ' UTC',
            sensor: 'Single-View ViT Monocular Estimator',
          };

          setActivePreset({
            metadata: customMetadata,
            sourceType: 'geotiff',
            recommendedExaggeration: 1.0,
          });
        };
        img.src = e.target?.result as string;
      };
      reader.readAsDataURL(file);
    } catch (err) {
      console.error('Error running client-side elevation pipeline', err);
    }
  };

  // Waypoint Tour Actions
  const handleAddWaypoint = (wp: FlightWaypoint) => {
    setWaypoints(prev => [...prev, wp]);
  };

  const handleRemoveWaypoint = (id: string) => {
    setWaypoints(prev => prev.filter(w => w.id !== id));
  };

  const handleClearWaypoints = () => {
    setWaypoints([]);
    setIsTourPlaying(false);
  };

  const handleLoadPresetTour = (routeKey: string) => {
    if (routeKey === 'ridge-sweep') {
      setWaypoints(INITIAL_WAYPOINTS);
    } else if (routeKey === 'summit-overlook') {
      setWaypoints([
        { id: 'wp-p1', name: 'P1 (North)', x: 0, y: 32, z: -35, elevation: 2200, flightAltitude: 18 },
        { id: 'wp-p2', name: 'P2 (East)', x: 35, y: 30, z: 0, elevation: 2350, flightAltitude: 18 },
        { id: 'wp-p3', name: 'P3 (South)', x: 0, y: 28, z: 35, elevation: 2150, flightAltitude: 18 },
        { id: 'wp-p4', name: 'P4 (West)', x: -35, y: 26, z: 0, elevation: 2080, flightAltitude: 18 },
      ]);
    }
  };

  // Preset 100-Point Transect Loader for Immediate Demonstration
  const handleLoadPresetTransect = useCallback(() => {
    const pA = { x: -32, y: 12, z: -18, elevation: 1920.5, lat: 45.9815, lng: 7.7005 };
    const pB = { x: 30, y: 18, z: 22, elevation: 2740.0, lat: 45.9712, lng: 7.7180 };

    const sampleCount = 100;
    const total2D = 1850; // meters
    const total3D = 2025; // meters
    const samples: TransectSamplePoint[] = [];

    let sumSquaredError = 0;
    let sumAbsError = 0;
    let maxResidual = 0;
    const maeFactor = activeJobResponse?.metrics?.mae || 0.89;

    for (let i = 0; i <= sampleCount; i++) {
      const frac = i / sampleCount;
      const dist = Math.round(frac * total2D);

      const baseLine = pA.elevation + frac * (pB.elevation - pA.elevation);
      const ridgeBump = Math.sin(frac * Math.PI) * 420;
      const aiElev = Math.round((baseLine + ridgeBump) * 10) / 10;

      const delta = Math.sin(frac * Math.PI * 4) * maeFactor * 1.15;
      const gtElev = Math.round((aiElev - delta) * 10) / 10;
      const residual = Math.round(Math.abs(delta) * 100) / 100;

      sumSquaredError += residual * residual;
      sumAbsError += residual;
      if (residual > maxResidual) maxResidual = residual;

      samples.push({
        index: i,
        distance: dist,
        distanceFormatted: `${dist}m`,
        aiElevation: aiElev,
        groundTruthElevation: gtElev,
        residualError: residual,
      });
    }

    setTransect({
      pointA: pA,
      pointB: pB,
      length2D: total2D,
      length3D: total3D,
      minElevation: Math.min(...samples.map(s => s.aiElevation)),
      maxElevation: Math.max(...samples.map(s => s.aiElevation)),
      deltaElevation: pB.elevation - pA.elevation,
      samples,
      transectRmse: Math.sqrt(sumSquaredError / (sampleCount + 1)),
      transectMae: sumAbsError / (sampleCount + 1),
      maxError: maxResidual,
    });
  }, [activeJobResponse?.metrics?.mae]);

  // Action Buttons
  const handleSnapshot = () => {
    viewportRef.current?.takeSnapshot();
  };

  const handleToggleFullscreen = () => {
    if (!document.fullscreenElement) {
      document.documentElement.requestFullscreen().then(() => setIsFullscreen(true)).catch(() => {});
    } else {
      document.exitFullscreen().then(() => setIsFullscreen(false)).catch(() => {});
    }
  };

  const handleStandaloneOpen = () => {
    window.open('/standalone', '_blank', 'noopener,noreferrer');
  };

  const handleSwitchToStudio = () => {
    setIsStandalone(false);
    window.history.pushState({}, '', '/');
  };

  return (
    <div className="w-screen h-screen flex flex-col bg-slate-950 text-slate-100 overflow-hidden font-sans select-none">
      {/* 1. TOP BAR: Render Studio TopNavBar when in studio mode */}
      {!isStandalone && (
        <TopNavBar
          mode={activePreset.metadata.mode || 'georeferenced'}
          pipelineStage={pipelineStage}
          isTourPlaying={isTourPlaying}
          onToggleTour={() => setIsTourPlaying(!isTourPlaying)}
          onSnapshot={handleSnapshot}
          isFullscreen={isFullscreen}
          onToggleFullscreen={handleToggleFullscreen}
          onStandaloneOpen={handleStandaloneOpen}
        />
      )}

      {/* Main Work Area */}
      <div className="flex-1 flex relative overflow-hidden">
        {/* 2. LEFT SLIM TOOLBAR (Only in Studio view) */}
        {!isStandalone && (
          <SlimToolbar
            activeDrawer={activeDrawer}
            onSelectDrawer={setActiveDrawer}
            isMeasuring={isMeasuring || isPlacingTransect || isPlacingWaypoints}
          />
        )}

        {/* 3. COLLAPSIBLE DRAWERS (Only in Studio view) */}
        {!isStandalone && (
          <>
            <IngestDrawer
              isOpen={activeDrawer === 'ingest'}
              onClose={() => setActiveDrawer(null)}
              currentMetadata={activePreset.metadata}
              shadingMode={shadingMode}
              onShadingModeChange={setShadingMode}
              pipelineStage={pipelineStage}
              onRunPipeline={handleRunPipeline}
              onSelectPreset={handleSelectPreset}
              activeJobResponse={activeJobResponse}
            />

            <ShadingDrawer
              isOpen={activeDrawer === 'shading'}
              onClose={() => setActiveDrawer(null)}
              shadingMode={shadingMode}
              onShadingModeChange={setShadingMode}
            />

            <DroneTourDrawer
              isOpen={activeDrawer === 'tour'}
              onClose={() => setActiveDrawer(null)}
              waypoints={waypoints}
              isPlacingWaypoints={isPlacingWaypoints}
              onTogglePlacingWaypoints={() => setIsPlacingWaypoints(!isPlacingWaypoints)}
              onRemoveWaypoint={handleRemoveWaypoint}
              onClearWaypoints={handleClearWaypoints}
              onLoadPresetWaypoints={handleLoadPresetTour}
              isTourPlaying={isTourPlaying}
              onToggleTour={() => setIsTourPlaying(!isTourPlaying)}
              tourSpeed={tourSpeed}
              onTourSpeedChange={setTourSpeed}
              isLooping={isLooping}
              onToggleLooping={() => setIsLooping(!isLooping)}
              isDroneMode={isDroneMode}
              onToggleDroneMode={() => setIsDroneMode(!isDroneMode)}
              droneCruiseSpeed={droneCruiseSpeed}
              onDroneCruiseSpeedChange={setDroneCruiseSpeed}
              onResetCamera={() => viewportRef.current?.resetCamera()}
            />

            <AccuracyValidationDrawer
              isOpen={activeDrawer === 'accuracy'}
              onClose={() => setActiveDrawer(null)}
              metrics={activeJobResponse?.metrics}
              transect={transect}
              isPlacingTransect={isPlacingTransect}
              onTogglePlacingTransect={() => setIsPlacingTransect(!isPlacingTransect)}
              onClearTransect={() => setTransect(null)}
              onLoadPresetTransect={handleLoadPresetTransect}
            />

            <MeasureDrawer
              isOpen={activeDrawer === 'measure'}
              onClose={() => setActiveDrawer(null)}
              isMeasuring={isMeasuring}
              onToggleMeasuring={() => {
                setIsMeasuring(!isMeasuring);
                setMeasurement(null);
              }}
              measurement={measurement}
              onClearMeasurement={() => setMeasurement(null)}
              isGeoreferenced={activePreset.metadata.mode === 'georeferenced'}
            />

            <SunLightingDrawer
              isOpen={activeDrawer === 'lighting'}
              onClose={() => setActiveDrawer(null)}
              config={sunConfig}
              onChange={setSunConfig}
            />

            <SettingsDrawer
              isOpen={activeDrawer === 'settings'}
              onClose={() => setActiveDrawer(null)}
              onResetCamera={() => viewportRef.current?.resetCamera()}
              metadata={activePreset.metadata}
            />
          </>
        )}

        {/* 4. MAIN VIEWPORT CANVAS AREA */}
        <main className="flex-1 relative h-full bg-slate-950 overflow-hidden">
          {/* STANDALONE FLOATING TOP OVERLAY BADGE */}
          {isStandalone && (
            <div className="absolute top-4 right-4 z-30 pointer-events-auto flex items-center gap-2">
              <div className="flex items-center gap-2 px-3 py-1.5 rounded-xl bg-slate-900/90 backdrop-blur-xl border border-slate-700/80 shadow-2xl text-xs font-mono">
                <div className="flex items-center gap-2 pr-3 border-r border-slate-800">
                  <div className="w-5 h-5 rounded-md bg-gradient-to-br from-cyan-500 to-indigo-600 p-0.5">
                    <div className="w-full h-full bg-slate-950 rounded-[4px] flex items-center justify-center">
                      <Layers className="w-3 h-3 text-cyan-400" />
                    </div>
                  </div>
                  <span className="font-bold text-white tracking-tight">DepthWizard 3D</span>
                  <span className="text-[10px] px-1.5 py-0.2 rounded bg-cyan-950 text-cyan-300 border border-cyan-800/60 font-bold">
                    STANDALONE
                  </span>
                </div>

                <div className="hidden sm:flex items-center gap-1.5 text-slate-300 pr-3 border-r border-slate-800">
                  <Globe className="w-3.5 h-3.5 text-cyan-400" />
                  <span>Georeferenced (Absolute Metric DSM)</span>
                </div>

                {/* Drone Flight (WASD) Toggle */}
                <button
                  type="button"
                  onClick={() => setIsDroneMode(!isDroneMode)}
                  className={`flex items-center gap-1.5 px-2.5 py-1 rounded-lg border transition-all ${
                    isDroneMode 
                      ? 'bg-cyan-500 text-slate-950 border-cyan-400 font-bold shadow-md shadow-cyan-500/20'
                      : 'bg-slate-950 text-slate-300 hover:bg-slate-800 border-slate-800'
                  }`}
                  title="Toggle First-Person Drone Flight (WASD)"
                >
                  <Radio className="w-3.5 h-3.5" />
                  <span>{isDroneMode ? 'Fly Active' : 'Fly (WASD)'}</span>
                </button>

                {/* Tour Play/Pause */}
                <button
                  type="button"
                  onClick={() => setIsTourPlaying(!isTourPlaying)}
                  className={`p-1.5 rounded-lg border transition-all ${
                    isTourPlaying
                      ? 'bg-emerald-600 text-white border-emerald-500'
                      : 'bg-slate-950 text-slate-300 hover:bg-slate-800 border-slate-800'
                  }`}
                  title={isTourPlaying ? 'Pause Spline Tour' : 'Play Spline Tour'}
                >
                  {isTourPlaying ? <Pause className="w-3.5 h-3.5" /> : <Play className="w-3.5 h-3.5 text-emerald-400" />}
                </button>

                {/* Snapshot */}
                <button
                  type="button"
                  onClick={handleSnapshot}
                  className="p-1.5 rounded-lg bg-slate-950 hover:bg-slate-800 text-slate-300 hover:text-white border border-slate-800 transition-colors"
                  title="Snapshot / HD Render"
                >
                  <Camera className="w-3.5 h-3.5 text-cyan-400" />
                </button>

                {/* Fullscreen */}
                <button
                  type="button"
                  onClick={handleToggleFullscreen}
                  className="p-1.5 rounded-lg bg-slate-950 hover:bg-slate-800 text-slate-300 hover:text-white border border-slate-800 transition-colors"
                  title={isFullscreen ? 'Exit Fullscreen' : 'Enter Fullscreen'}
                >
                  {isFullscreen ? <Minimize className="w-3.5 h-3.5" /> : <Maximize className="w-3.5 h-3.5" />}
                </button>

                {/* Return to Studio */}
                <button
                  type="button"
                  onClick={handleSwitchToStudio}
                  className="flex items-center gap-1 px-2.5 py-1 rounded-lg bg-slate-800 hover:bg-slate-700 text-slate-200 hover:text-white border border-slate-700 transition-colors"
                  title="Return to Studio Workspace"
                >
                  <ArrowLeft className="w-3.5 h-3.5 text-cyan-400" />
                  <span>Studio</span>
                </button>
              </div>
            </div>
          )}

          {/* VIEWPORT NAVIGATION CONTROLS OVERLAY */}
          <ViewportNavigationControls
            cameraHeading={cameraHeading}
            onResetNorth={() => viewportRef.current?.resetNorth()}
            onSnapNadir={() => viewportRef.current?.snapNadir()}
            onSnapOblique={() => viewportRef.current?.snapOblique()}
            onFitBounds={() => viewportRef.current?.fitBounds()}
            onZoomIn={() => viewportRef.current?.zoomIn()}
            onZoomOut={() => viewportRef.current?.zoomOut()}
            fov={fov}
            onFovChange={setFov}
            isTurntable={isTurntable}
            turntableSpeed={1.0}
            onToggleTurntable={() => setIsTurntable(!isTurntable)}
            timeOfDayHour={timeOfDayHour}
            onTimeOfDayChange={handleTimeOfDayChange}
            isSplitScreen={isSplitScreen}
            onToggleSplitScreen={() => setIsSplitScreen(!isSplitScreen)}
            splitPosition={splitPosition}
            onSplitPositionChange={setSplitPosition}
            isStandalone={isStandalone}
          />

          {/* THREE.JS VIEWPORT 3D ENGINE */}
          <ThreeViewport
            ref={viewportRef}
            dataset={terrainData}
            jobResponse={activeJobResponse}
            shadingMode={shadingMode}
            sunConfig={sunConfig}
            fov={fov}
            isTurntable={isTurntable}
            turntableSpeed={1.0}
            isSplitScreen={isSplitScreen}
            splitPosition={splitPosition}
            onCameraHeadingChange={setCameraHeading}
            waypoints={waypoints}
            onAddWaypoint={handleAddWaypoint}
            isPlacingWaypoints={isPlacingWaypoints}
            isTourPlaying={isTourPlaying}
            tourSpeed={tourSpeed}
            isLooping={isLooping}
            isDroneMode={isDroneMode}
            droneCruiseSpeed={droneCruiseSpeed}
            isPlacingTransect={isPlacingTransect}
            onTransectUpdated={setTransect}
            isMeasuring={isMeasuring}
            onTelemetryUpdate={setTelemetry}
            onMeasurementUpdate={setMeasurement}
            onInspectionPointSelected={setInspectionPoint}
          />

          {/* 5. FLOATING BOTTOM TELEMETRY HUD (Continuous hover coordinates & elevation) */}
          <TelemetryHUD
            telemetry={telemetry}
            isMeasuring={isMeasuring}
          />

          {/* 6. RIGHT-ALIGNED CESIUM SANDCASTLE INSPECTOR WINDOW */}
          <RightTelemetryPanel
            inspectionPoint={inspectionPoint}
            onClear={() => setInspectionPoint(null)}
          />
        </main>
      </div>
    </div>
  );
}

export default App;
