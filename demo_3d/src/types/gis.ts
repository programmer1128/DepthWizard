export type DatasetMode = 'georeferenced' | 'relative';

export type ShadingMode = 'rgb' | 'hypsometric' | 'slope' | 'wireframe';

export type ActiveDrawer = 'ingest' | 'shading' | 'tour' | 'accuracy' | 'measure' | 'lighting' | 'settings' | null;

export type PipelineStage = 
  | 'idle'
  | 'upload'
  | 'depth_estimation'
  | 'metric_calibration'
  | 'tiling'
  | 'streaming';

export interface FileIngestValidation {
  file: File | null;
  name: string;
  size: number;
  extension: string;
  detectedMode: DatasetMode;
  isValid: boolean;
  errorMessage?: string;
}

export interface TerrainMetadata {
  id: string;
  title: string;
  mode: DatasetMode;
  crs: string; // e.g. 'EPSG:4326 (WGS84)'
  gsd: string; // Ground Sampling Distance, e.g. '0.25 m/pixel'
  verticalDatum: string; // e.g. 'EGM96 Orthometric (MSL)'
  minElevation: number; // meters
  maxElevation: number; // meters
  areaCoverage: string; // e.g. '2.4 km x 2.4 km'
  dateCaptured: string;
  sensor: string;
}

export interface TelemetryData {
  hasHit: boolean;
  worldX: number;
  worldY: number;
  worldZ: number;
  lat?: number;
  lng?: number;
  elevation: number; // in meters MSL
  surfaceSlope: number; // in degrees
  cameraAltitude: number; // meters above ground
  cameraDistance: number;
  fps: number;
}

export interface ClickedPointTelemetry {
  lat?: number;
  lng?: number;
  worldX?: number;
  worldY?: number;
  elevation: number;
  cameraAltitude: number;
  cameraDistance: number;
  surfaceSlope: number;
  timestamp: string;
}

export interface MeasurePoint {
  x: number;
  y: number;
  z: number;
  elevation: number;
  lat?: number;
  lng?: number;
}

export interface MeasurementResult {
  pointA: MeasurePoint;
  pointB: MeasurePoint | null;
  distance3D: number;
  distance2D: number;
  deltaElevation: number;
  slopeDegrees: number;
  slopePercentage: number;
}

export interface SunLightingConfig {
  azimuth: number; // 0 to 360 deg
  elevation: number; // 5 to 90 deg
  intensity: number; // 0.2 to 2.5
  ambientIntensity: number; // 0.1 to 1.0
  castShadows: boolean;
}

export interface TourConfig {
  isPlaying: boolean;
  speed: number; // 0.2x to 5x
  radius: number; // orbit radius
  altitude: number; // flight height
  focusCenter: [number, number, number];
}

export interface FlightWaypoint {
  id: string;
  name: string; // e.g. "P1", "P2"
  x: number;
  y: number;
  z: number;
  elevation: number;
  flightAltitude: number; // offset above ground (meters)
  lat?: number;
  lng?: number;
}

export interface TransectSamplePoint {
  index: number;
  distance: number; // in meters
  distanceFormatted: string;
  aiElevation: number; // in meters
  groundTruthElevation: number; // in meters
  residualError: number; // |ai - gt| in meters
}

export interface TransectMeasurement {
  pointA: MeasurePoint;
  pointB: MeasurePoint;
  length2D: number;
  length3D: number;
  minElevation: number;
  maxElevation: number;
  deltaElevation: number;
  samples: TransectSamplePoint[];
  transectRmse: number;
  transectMae: number;
  maxError: number;
}
