export interface ElevationJobMetrics {
  rmse: number;
  mae: number;
  correlation: number;
  f1Score: number;
}

export interface ElevationJobResponse {
  uuid: string; // Session ID e.g., "a3f12d80-5b12-4c23-8c7a-e490218fa21e"
  tilesetUrl?: string; // Optional stream endpoint
  crs?: string; // e.g., "EPSG:4326"
  bounds?: [number, number, number, number]; // [minLon, minLat, maxLon, maxLat]
  minElevation: number;
  maxElevation: number;
  isGeoreferenced: boolean;
  metrics?: ElevationJobMetrics;
}

export interface ElevationInspectionPoint {
  elementId: string;
  featureName: string;
  lat: number;
  lng: number;
  elevation: number; // in meters MSL
  cameraAltitude: number; // meters
  cameraDistance: number; // meters
  surfaceSlope: number; // degrees
  referenceElevation?: number; // LiDAR reference in meters
  deltaError?: number; // |Predicted - Reference| in meters
  worldX: number;
  worldY: number;
  worldZ: number;
  timestamp: string;
  structuralMetadata?: Record<string, unknown>;
}
