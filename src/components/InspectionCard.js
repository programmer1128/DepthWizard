'use client';

import React, { useState, useEffect } from 'react';
import {
  formatLatitude,
  formatLongitude,
  formatElevation,
  formatSlope
} from '../utils/geoUtils.js';
import { getActualHeight } from '../services/elevationApi.js';

/**
 * InspectionCard - Right-Aligned Surface Elevation & WGS84 Inspection Card
 *
 * @param {Object} props
 * @param {boolean} [props.isOpen=true] - Visibility toggle
 * @param {Function} [props.onClose] - Callback when card is closed
 * @param {Object} [props.inspectionData] - Telemetry data from Three.js raycast
 * @param {number} [props.inspectionData.latitude=45.980776] - WGS84 Latitude
 * @param {number} [props.inspectionData.longitude=7.696169] - WGS84 Longitude
 * @param {number} [props.inspectionData.elevation=1879.09] - Absolute Elevation MSL (m)
 * @param {number} [props.inspectionData.slopeAngle=8.6] - Slope inclination (degrees)
 * @param {number} [props.inspectionData.eyeAltitude=420.5] - Camera Eye Altitude (m)
 * @param {number} [props.inspectionData.targetRange=560.2] - Raycast Target Range (m)
 * @param {string} [props.badgeId="DW3D-2574"] - Mission or model badge ID
 */
export default function InspectionCard({
  isOpen = true,
  onClose,
  inspectionData = {},
  badgeId = 'DW3D-2574'
}) {
  // Default coordinate telemetry fallback matching specification
  const lat = inspectionData.latitude ?? 45.980776;
  const lon = inspectionData.longitude ?? 7.696169;
  const elevation = inspectionData.elevation ?? 1879.09;
  const slope = inspectionData.slopeAngle ?? 8.6;
  const eyeAlt = inspectionData.eyeAltitude ?? 354.2;
  const targetRange = inspectionData.targetRange ?? 482.7;

  // Real-time timestamp
  const [timestamp, setTimestamp] = useState('');
  const [copyFeedback, setCopyFeedback] = useState(false);
  const [benchmarkLoading, setBenchmarkLoading] = useState(false);
  const [benchmarkData, setBenchmarkData] = useState({
    referenceLidar: 1878.28,
    deltaError: -0.81,
    dataset: 'OpenTopography LiDAR'
  });

  // Clock formatter for "HH:MM:SS • WGS84 Datum"
  useEffect(() => {
    const updateTime = () => {
      const now = new Date();
      const hours = String(now.getHours()).padStart(2, '0');
      const minutes = String(now.getMinutes()).padStart(2, '0');
      const seconds = String(now.getSeconds()).padStart(2, '0');
      setTimestamp(`${hours}:${minutes}:${seconds}`);
    };

    updateTime();
    const timer = setInterval(updateTime, 1000);
    return () => clearInterval(timer);
  }, []);

  // Fetch actual height from benchmark API whenever coordinates change
  useEffect(() => {
    let isSubscribed = true;

    async function fetchBenchmark() {
      setBenchmarkLoading(true);
      try {
        const result = await getActualHeight(lat, lon, elevation);
        if (isSubscribed && result) {
          setBenchmarkData({
            referenceLidar: result.actual_height ?? 1878.28,
            deltaError: result.delta_error ?? -0.81,
            dataset: result.dataset || 'OpenTopography LiDAR'
          });
        }
      } catch (err) {
        console.error('Failed to resolve elevation benchmark:', err);
      } finally {
        if (isSubscribed) setBenchmarkLoading(false);
      }
    }

    fetchBenchmark();

    return () => {
      isSubscribed = false;
    };
  }, [lat, lon, elevation]);

  if (!isOpen) return null;

  // Copy telemetry data to clipboard
  const handleCopy = async () => {
    const telemetryText = `[DepthWizard 3D - ${badgeId}]
Latitude: ${formatLatitude(lat)}
Longitude: ${formatLongitude(lon)}
Elevation: ${formatElevation(elevation)}
Slope: ${formatSlope(slope)}
LiDAR Reference: ${formatElevation(benchmarkData.referenceLidar)}
Delta Error: ${benchmarkData.deltaError >= 0 ? '+' : ''}${benchmarkData.deltaError.toFixed(2)} m
Eye Altitude: ${eyeAlt.toFixed(1)} m
Target Range: ${targetRange.toFixed(1)} m
Datum: WGS84`;

    try {
      if (navigator.clipboard) {
        await navigator.clipboard.writeText(telemetryText);
        setCopyFeedback(true);
        setTimeout(() => setCopyFeedback(false), 2000);
      }
    } catch (e) {
      console.error('Copy failed:', e);
    }
  };

  // Export inspection point data as GeoJSON / JSON file
  const handleExportJson = () => {
    const payload = {
      type: 'Feature',
      properties: {
        badgeId,
        timestamp: new Date().toISOString(),
        datum: 'WGS84',
        verticalDatum: 'EGM96 MSL',
        latitude: lat,
        longitude: lon,
        surfaceElevationMeters: elevation,
        slopeAngleDegrees: slope,
        referenceLidarMeters: benchmarkData.referenceLidar,
        deltaErrorMeters: benchmarkData.deltaError,
        eyeAltitudeMeters: eyeAlt,
        targetRangeMeters: targetRange
      },
      geometry: {
        type: 'Point',
        coordinates: [lon, lat, elevation]
      }
    };

    const blob = new Blob([JSON.stringify(payload, null, 2)], {
      type: 'application/json'
    });
    const url = URL.createObjectURL(blob);
    const link = document.createElement('a');
    link.href = url;
    link.download = `DW3D_Inspection_${badgeId}_${Date.now()}.json`;
    document.body.appendChild(link);
    link.click();
    document.body.removeChild(link);
    URL.revokeObjectURL(url);
  };

  // Delta color logic: emerald font for sub-meter tight tolerance, amber if larger
  const isDeltaStrict = Math.abs(benchmarkData.deltaError) <= 1.5;
  const deltaColorClass = isDeltaStrict ? 'text-emerald-400' : 'text-amber-400';
  const deltaSign = benchmarkData.deltaError >= 0 ? '+' : '';

  return (
    <aside
      role="region"
      aria-label="Surface Elevation and WGS84 Inspection Card"
      className="fixed top-16 right-5 z-30 w-84 w-[21rem] select-none rounded-xl border border-cyan-500/30 bg-[#0b1329]/90 p-4 shadow-2xl backdrop-blur-md text-white font-sans transition-all duration-300 animate-fadeIn"
      style={{
        boxShadow: '0 20px 45px -10px rgba(6, 182, 212, 0.15), 0 0 25px 0 rgba(11, 19, 41, 0.8)'
      }}
    >
      {/* ============================================================
          HEADER
          ============================================================ */}
      <header className="border-b border-cyan-500/20 pb-3">
        <div className="flex items-center justify-between gap-2">
          {/* Compass Icon & Title */}
          <div className="flex items-center gap-2 overflow-hidden">
            <div className="flex h-7 w-7 shrink-0 items-center justify-center rounded-lg bg-cyan-500/10 border border-cyan-500/30 text-cyan-400">
              {/* Modern SVG Compass */}
              <svg
                xmlns="http://www.w3.org/2000/svg"
                viewBox="0 0 24 24"
                fill="none"
                stroke="currentColor"
                strokeWidth="2"
                strokeLinecap="round"
                strokeLinejoin="round"
                className="h-4 w-4 transform rotate-45"
              >
                <circle cx="12" cy="12" r="10" strokeOpacity="0.5" />
                <polygon
                  points="16.24 7.76 14.12 14.12 7.76 16.24 9.88 9.88 16.24 7.76"
                  fill="#06b6d4"
                  fillOpacity="0.4"
                />
              </svg>
            </div>

            <div className="min-w-0">
              <div className="flex items-center gap-1.5">
                <h2
                  className="truncate text-sm font-semibold tracking-tight text-white/95"
                  title="Surface Elevation Inspection"
                >
                  Surface Elevatio...
                </h2>
                <span className="shrink-0 rounded bg-cyan-950/80 px-1.5 py-0.5 font-mono text-[10px] font-bold text-cyan-400 border border-cyan-500/40">
                  [{badgeId}]
                </span>
              </div>
            </div>
          </div>

          {/* Action Buttons: [Export JSON], [Copy], [X] */}
          <div className="flex items-center gap-1">
            <button
              type="button"
              onClick={handleExportJson}
              title="Export inspection point as GeoJSON"
              className="rounded px-1.5 py-0.8 text-[11px] font-medium bg-cyan-950/60 hover:bg-cyan-900/80 text-cyan-300 border border-cyan-500/30 hover:border-cyan-400 transition-colors"
            >
              Export JSON
            </button>

            <button
              type="button"
              onClick={handleCopy}
              title="Copy coordinate telemetry"
              className="rounded px-1.5 py-0.8 text-[11px] font-medium bg-slate-800/80 hover:bg-slate-700 text-slate-200 border border-slate-600/50 hover:border-slate-400 transition-colors relative"
            >
              {copyFeedback ? (
                <span className="text-emerald-400 font-bold">✓ Copied</span>
              ) : (
                'Copy'
              )}
            </button>

            {onClose && (
              <button
                type="button"
                onClick={onClose}
                aria-label="Close Inspection Card"
                className="flex h-6 w-6 items-center justify-center rounded text-xs text-slate-400 hover:bg-red-500/20 hover:text-red-400 transition-colors"
              >
                ✕
              </button>
            )}
          </div>
        </div>

        {/* Subtitle: HH:MM:SS • WGS84 Datum */}
        <div className="mt-1 flex items-center gap-1 text-[11px] font-mono text-cyan-300/70">
          <span>{timestamp || '00:00:00'}</span>
          <span>•</span>
          <span className="tracking-wide text-cyan-400/90 font-sans font-medium">
            WGS84 Datum
          </span>
        </div>
      </header>

      {/* ============================================================
          BODY ROWS: Lat, Lon, Absolute Elevation, Slope Angle
          ============================================================ */}
      <section className="my-3 space-y-2 text-xs">
        {/* Latitude */}
        <div className="flex items-center justify-between rounded-md bg-white/[0.03] px-2.5 py-1.5 border border-white/[0.05]">
          <span className="text-slate-400 font-medium">Latitude</span>
          <span className="font-mono font-semibold tracking-wide text-slate-100">
            {formatLatitude(lat)}
          </span>
        </div>

        {/* Longitude */}
        <div className="flex items-center justify-between rounded-md bg-white/[0.03] px-2.5 py-1.5 border border-white/[0.05]">
          <span className="text-slate-400 font-medium">Longitude</span>
          <span className="font-mono font-semibold tracking-wide text-slate-100">
            {formatLongitude(lon)}
          </span>
        </div>

        {/* Absolute Elevation */}
        <div className="flex items-center justify-between rounded-md bg-white/[0.03] px-2.5 py-1.5 border border-white/[0.05]">
          <div className="flex items-center gap-1.5">
            <span className="text-slate-400 font-medium">Absolute Elevation</span>
            <span className="text-[9px] rounded bg-cyan-950/70 text-cyan-400 px-1 py-0.2 border border-cyan-800/60 font-mono">
              EST
            </span>
          </div>
          <span className="font-mono font-bold tracking-tight text-cyan-300">
            {formatElevation(elevation)}
          </span>
        </div>

        {/* Slope Angle */}
        <div className="flex items-center justify-between rounded-md bg-white/[0.03] px-2.5 py-1.5 border border-white/[0.05]">
          <span className="text-slate-400 font-medium">Slope Angle</span>
          <span className="font-mono font-semibold text-slate-100">
            {formatSlope(slope)}
          </span>
        </div>
      </section>

      {/* ============================================================
          LIDAR GROUND TRUTH COMPARISON SUB-CARD
          ============================================================ */}
      <div className="mb-3 rounded-lg border border-indigo-500/30 bg-gradient-to-b from-indigo-950/40 to-[#070e24]/80 p-2.5">
        {/* Sub-Card Header */}
        <div className="flex items-center justify-between mb-2">
          <div className="flex items-center gap-1.5 text-[11px] font-semibold text-indigo-200">
            <span className="text-indigo-400">✦</span>
            <span>LiDAR Ground Truth Comparison</span>
          </div>
          <span className="rounded-full bg-indigo-900/60 px-2 py-0.5 font-mono text-[9px] font-bold tracking-wide text-indigo-300 border border-indigo-500/40">
            BENCHMARK
          </span>
        </div>

        {/* Comparison Metric Grid */}
        <div className="grid grid-cols-2 gap-2 text-xs">
          {/* Reference LiDAR */}
          <div className="rounded bg-black/30 p-2 border border-indigo-500/20">
            <div className="text-[10px] text-indigo-300/80 font-medium">
              Reference LiDAR
            </div>
            <div className="mt-0.5 font-mono text-sm font-bold text-white">
              {benchmarkLoading ? (
                <span className="animate-pulse text-indigo-300">Syncing...</span>
              ) : (
                `${Number(benchmarkData.referenceLidar).toLocaleString('en-US', {
                  minimumFractionDigits: 2,
                  maximumFractionDigits: 2
                })} m`
              )}
            </div>
          </div>

          {/* Delta Error */}
          <div className="rounded bg-black/30 p-2 border border-indigo-500/20">
            <div className="text-[10px] text-indigo-300/80 font-medium">
              Delta Error
            </div>
            <div className={`mt-0.5 font-mono text-sm font-bold ${deltaColorClass}`}>
              {benchmarkLoading ? (
                <span className="animate-pulse text-slate-400">...</span>
              ) : (
                `±${Math.abs(benchmarkData.deltaError).toFixed(2)} m`
              )}
            </div>
          </div>
        </div>
      </div>

      {/* ============================================================
          FOOTER: Eye Altitude & Target Range
          ============================================================ */}
      <footer className="flex items-center justify-between border-t border-cyan-500/20 pt-2 text-[11px] text-slate-400 font-mono">
        <div className="flex items-center gap-1">
          <span className="text-slate-400">Eye Altitude:</span>
          <span className="text-slate-200 font-semibold">
            {eyeAlt.toFixed(1)} m
          </span>
        </div>

        <div className="flex items-center gap-1">
          <span className="text-slate-400">Target Range:</span>
          <span className="text-slate-200 font-semibold">
            {targetRange.toFixed(1)} m
          </span>
        </div>
      </footer>
    </aside>
  );
}
