/**
 * Format decimal degrees into standard GIS string (e.g. 45.9765° N, 7.7088° E)
 */
export function formatLatLng(lat: number, lng: number): string {
  const latDir = lat >= 0 ? 'N' : 'S';
  const lngDir = lng >= 0 ? 'E' : 'W';
  return `${Math.abs(lat).toFixed(4)}° ${latDir}, ${Math.abs(lng).toFixed(4)}° ${lngDir}`;
}

/**
 * Format local metric coordinates (X, Y in meters)
 */
export function formatLocalCoords(x: number, y: number): string {
  const xSign = x >= 0 ? '+' : '';
  const ySign = y >= 0 ? '+' : '';
  return `X: ${xSign}${x.toFixed(1)} m, Y: ${ySign}${y.toFixed(1)} m`;
}

/**
 * Format elevation with absolute datum or relative prefix
 */
export function formatElevation(meters: number, isGeoreferenced: boolean): string {
  if (isGeoreferenced) {
    return `${meters.toLocaleString('en-US', { minimumFractionDigits: 1, maximumFractionDigits: 1 })} m MSL`;
  }
  const sign = meters >= 0 ? '+' : '';
  return `${sign}${meters.toFixed(1)} m rel`;
}

/**
 * Format distance in meters or kilometers
 */
export function formatDistance(meters: number): string {
  if (meters >= 1000) {
    return `${(meters / 1000).toFixed(2)} km`;
  }
  return `${meters.toFixed(1)} m`;
}

/**
 * Format file byte sizes
 */
export function formatFileSize(bytes: number): string {
  if (bytes === 0) return '0 B';
  const k = 1024;
  const sizes = ['B', 'KB', 'MB', 'GB'];
  const i = Math.floor(Math.log(bytes) / Math.log(k));
  return `${parseFloat((bytes / Math.pow(k, i)).toFixed(1))} ${sizes[i]}`;
}
