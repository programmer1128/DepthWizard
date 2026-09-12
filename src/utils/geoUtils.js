/**
 * Geo-spatial Utilities for DepthWizard 3D
 * WGS84 Geographic Coordinate System & Elevation helpers
 */

// Default geospatial bounds (Cartosat / ISRO Alpine DEM test region)
export const DEFAULT_GEO_BOUNDS = {
  minLat: 45.950000,
  maxLat: 46.020000,
  minLon: 7.650000,
  maxLon: 7.750000,
  baseElevationMsl: 1800.0, // Base Mean Sea Level elevation reference in meters
  elevationScale: 1.0       // Mesh unit to meters conversion ratio
};

/**
 * Maps normalized UV coordinates (0 to 1) to WGS84 latitude and longitude.
 * Supports UV or normalized bounding box coordinates.
 */
export function uvToWgs84(u, v, bounds = DEFAULT_GEO_BOUNDS) {
  const clampU = Math.min(Math.max(u, 0), 1);
  const clampV = Math.min(Math.max(v, 0), 1);

  // In standard GIS raster mapping:
  // u (0 -> 1) maps West -> East (minLon -> maxLon)
  // v (0 -> 1) in Three.js UV typically maps South -> North (minLat -> maxLat)
  const lon = bounds.minLon + clampU * (bounds.maxLon - bounds.minLon);
  const lat = bounds.minLat + clampV * (bounds.maxLat - bounds.minLat);

  return { lat, lon };
}

/**
 * Format Latitude into GIS standard notation with hemisphere (N/S)
 * e.g., 45.980776° N
 */
export function formatLatitude(lat) {
  if (lat == null || isNaN(lat)) return '0.000000° N';
  const hemi = lat >= 0 ? 'N' : 'S';
  return `${Math.abs(lat).toFixed(6)}° ${hemi}`;
}

/**
 * Format Longitude into GIS standard notation with hemisphere (E/W)
 * e.g., 7.696169° E
 */
export function formatLongitude(lon) {
  if (lon == null || isNaN(lon)) return '0.000000° E';
  const hemi = lon >= 0 ? 'E' : 'W';
  return `${Math.abs(lon).toFixed(6)}° ${hemi}`;
}

/**
 * Format Elevation in meters above Mean Sea Level
 * e.g., 1,879.09 m MSL
 */
export function formatElevation(meters) {
  if (meters == null || isNaN(meters)) return '0.00 m MSL';
  return `${Number(meters).toLocaleString('en-US', {
    minimumFractionDigits: 2,
    maximumFractionDigits: 2
  })} m MSL`;
}

/**
 * Format Slope Angle into degrees
 * e.g., 8.6°
 */
export function formatSlope(deg) {
  if (deg == null || isNaN(deg)) return '0.0°';
  return `${Number(deg).toFixed(1)}°`;
}

/**
 * Calculate slope inclination in degrees from surface normal vector.
 * Formula: Math.acos(Math.min(Math.max(normal.y, -1), 1)) * (180 / Math.PI)
 */
export function computeSlopeAngle(normal) {
  if (!normal) return 0;
  const clampedY = Math.min(Math.max(normal.y, -1), 1);
  return Math.acos(clampedY) * (180 / Math.PI);
}
