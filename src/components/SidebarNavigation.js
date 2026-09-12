'use client';

import React, { useState } from 'react';
import {
  Crosshair,
  Ruler,
  Layers,
  Compass,
  Activity,
  ChevronRight,
  ChevronLeft,
  Copy,
  Check,
  RefreshCw,
  Database,
  ArrowRight,
  TrendingUp,
  MapPin
} from 'lucide-react';

/**
 * SidebarNavigation - Left Vertical Icon Rail & Collapsible Ground-Truth Verification Drawer
 *
 * @param {Object} props
 * @param {Object} props.inspectionData - Real-time inspection telemetry from raycast
 * @param {Object} props.measurementData - 2-point caliper measurement metrics
 * @param {boolean} props.isMeasureMode - Whether 2-point caliper mode is active
 * @param {Function} props.onToggleMeasureMode - Callback to toggle measure mode
 * @param {Function} props.onClearMeasurement - Callback to clear caliper lines/points
 * @param {string} props.selectedDataset - Currently active benchmark DEM dataset
 * @param {Function} props.onSelectDataset - Callback to change benchmark dataset
 * @param {boolean} [props.isDrawerOpen=true] - Drawer open/closed state
 * @param {Function} [props.onToggleDrawer] - Callback to toggle drawer
 */
export default function SidebarNavigation({
  inspectionData = {},
  measurementData = null,
  isMeasureMode = false,
  onToggleMeasureMode = () => {},
  onClearMeasurement = () => {},
  selectedDataset = 'ISRO Bhuvan CartoDEM',
  onSelectDataset = () => {},
  isDrawerOpen = true,
  onToggleDrawer = () => {}
}) {
  const [activeTab, setActiveTab] = useState('ground-truth'); // 'ground-truth' | 'layers' | 'overview'
  const [copiedUrl, setCopiedUrl] = useState(false);

  // Extract coordinates with defaults
  const lon = inspectionData.longitude ?? 7.696169;
  const lat = inspectionData.latitude ?? 45.980776;
  const height = inspectionData.absoluteElevation ?? inspectionData.elevation ?? 1879.09;
  const refLidar = inspectionData.referenceLidar ?? 1878.28;
  const deltaError = inspectionData.deltaError ?? 0.81;
  const isSampling = inspectionData.isSampling || false;

  const xStr = Number(lon).toFixed(6);
  const yStr = Number(lat).toFixed(6);
  const zStr = Number(height).toFixed(2);
  const liveEndpoint = `/api/v1/get-actual-height/x=${xStr},y=${yStr},z=${zStr}`;

  const handleCopyEndpoint = async () => {
    try {
      if (navigator.clipboard) {
        await navigator.clipboard.writeText(liveEndpoint);
        setCopiedUrl(true);
        setTimeout(() => setCopiedUrl(false), 2000);
      }
    } catch (e) {
      console.error('Failed to copy endpoint:', e);
    }
  };

  return (
    <div className="fixed top-14 left-0 bottom-0 z-30 flex select-none pointer-events-none font-sans">
      {/* ============================================================
          1. LEFT VERTICAL ICON RAIL
          ============================================================ */}
      <nav
        className="w-14 shrink-0 bg-[#070d1d]/95 backdrop-blur-md border-r border-cyan-500/20 flex flex-col items-center py-3.5 justify-between pointer-events-auto shadow-2xl"
        aria-label="Main Tool Rail"
      >
        <div className="flex flex-col items-center gap-2.5 w-full px-2">
          {/* Brand Pin */}
          <div className="flex h-9 w-9 items-center justify-center rounded-xl bg-gradient-to-tr from-cyan-600/30 to-blue-600/20 border border-cyan-500/40 text-cyan-400 mb-2 shadow-[0_0_15px_rgba(6,182,212,0.25)]">
            <Compass className="h-5 w-5" />
          </div>

          {/* Caliper / Crosshair Icon Button: Ground Truth Verification & Raycast Sampling */}
          <button
            type="button"
            onClick={() => {
              if (!isDrawerOpen) {
                onToggleDrawer(true);
              }
              setActiveTab('ground-truth');
            }}
            title="Ground Truth Verification & Raycast Sampling"
            aria-label="Ground Truth Verification & Raycast Sampling"
            className={`relative flex h-10 w-10 items-center justify-center rounded-xl transition-all duration-200 group ${
              isDrawerOpen && activeTab === 'ground-truth'
                ? 'bg-cyan-500/25 text-cyan-300 border border-cyan-400/60 shadow-[0_0_12px_rgba(6,182,212,0.3)]'
                : 'text-slate-400 hover:text-cyan-300 hover:bg-slate-800/60'
            }`}
          >
            <Crosshair className="h-5 w-5 transition-transform group-hover:scale-110" />
            {/* Active Pill Indicator */}
            {isDrawerOpen && activeTab === 'ground-truth' && (
              <span className="absolute left-0 top-2 bottom-2 w-1 bg-cyan-400 rounded-r-full" />
            )}
          </button>

          {/* Measure Caliper Quick Action */}
          <button
            type="button"
            onClick={() => {
              if (!isDrawerOpen) onToggleDrawer(true);
              setActiveTab('ground-truth');
              onToggleMeasureMode(!isMeasureMode);
            }}
            title={isMeasureMode ? 'Caliper Measure Active (Click 2 points)' : 'Enable Caliper Measure'}
            className={`flex h-10 w-10 items-center justify-center rounded-xl transition-all duration-200 ${
              isMeasureMode
                ? 'bg-amber-500/25 text-amber-300 border border-amber-400/60 shadow-[0_0_12px_rgba(245,158,11,0.3)] animate-pulse'
                : 'text-slate-400 hover:text-amber-300 hover:bg-slate-800/60'
            }`}
          >
            <Ruler className="h-5 w-5" />
          </button>

          {/* GIS Layers Tab */}
          <button
            type="button"
            onClick={() => {
              if (!isDrawerOpen) onToggleDrawer(true);
              setActiveTab('layers');
            }}
            title="Remote Sensing Layers"
            className={`flex h-10 w-10 items-center justify-center rounded-xl transition-all duration-200 ${
              isDrawerOpen && activeTab === 'layers'
                ? 'bg-cyan-500/25 text-cyan-300 border border-cyan-400/60'
                : 'text-slate-400 hover:text-cyan-300 hover:bg-slate-800/60'
            }`}
          >
            <Layers className="h-5 w-5" />
          </button>
        </div>

        {/* Bottom Drawer Collapse / Expand Toggle */}
        <button
          type="button"
          onClick={() => onToggleDrawer(!isDrawerOpen)}
          title={isDrawerOpen ? 'Collapse Sidebar Drawer' : 'Expand Sidebar Drawer'}
          className="flex h-9 w-9 items-center justify-center rounded-xl text-slate-400 hover:text-white hover:bg-slate-800/80 transition-colors border border-slate-700/40"
        >
          {isDrawerOpen ? <ChevronLeft className="h-4 w-4" /> : <ChevronRight className="h-4 w-4" />}
        </button>
      </nav>

      {/* ============================================================
          2. SIDEBAR SUB-DRAWER: Ground Truth & Metric Verification
          ============================================================ */}
      <aside
        className={`w-88 w-[22.5rem] bg-[#0b1329]/95 backdrop-blur-xl border-r border-cyan-500/20 flex flex-col justify-between overflow-y-auto pointer-events-auto transition-all duration-300 ease-in-out shadow-2xl text-white ${
          isDrawerOpen ? 'translate-x-0 opacity-100' : '-translate-x-full opacity-0 pointer-events-none'
        }`}
      >
        <div className="p-4 space-y-4">
          {/* Drawer Header */}
          <div className="flex items-center justify-between border-b border-cyan-500/20 pb-3">
            <div className="flex items-center gap-2">
              <div className="p-1.5 rounded-lg bg-cyan-500/10 border border-cyan-500/30 text-cyan-400">
                <Activity className="h-4 w-4" />
              </div>
              <div>
                <h2 className="text-xs font-bold uppercase tracking-wider text-slate-100 flex items-center gap-1.5">
                  Ground Truth & Metric Verification
                </h2>
                <p className="text-[10px] text-cyan-300/70 font-mono">
                  Raycast Sampling & Elevation Audit
                </p>
              </div>
            </div>

            <button
              type="button"
              onClick={() => onToggleDrawer(false)}
              className="text-slate-400 hover:text-slate-200 text-xs p-1 rounded hover:bg-slate-800/80"
              title="Close Drawer"
            >
              ✕
            </button>
          </div>

          {/* ============================================================
              SECTION 1: TARGET POINT TELEMETRY CARD
              ============================================================ */}
          <section className="rounded-xl border border-cyan-500/25 bg-slate-900/60 p-3 space-y-2.5">
            <div className="flex items-center justify-between">
              <div className="flex items-center gap-1.5 text-xs font-semibold text-slate-200">
                <MapPin className="h-3.5 w-3.5 text-cyan-400" />
                <span>Target Point Telemetry</span>
              </div>

              {/* Status Pill */}
              {isSampling ? (
                <span className="flex items-center gap-1 rounded-full bg-amber-500/15 border border-amber-500/40 px-2 py-0.5 text-[10px] font-mono font-semibold text-amber-300 animate-pulse">
                  <span className="h-1.5 w-1.5 rounded-full bg-amber-400" />
                  Sampling...
                </span>
              ) : (
                <span className="flex items-center gap-1 rounded-full bg-emerald-500/15 border border-emerald-500/40 px-2 py-0.5 text-[10px] font-mono font-semibold text-emerald-300">
                  <span className="h-1.5 w-1.5 rounded-full bg-emerald-400 animate-ping" />
                  Connected: LiDAR ISRO Bhuvan
                </span>
              )}
            </div>

            {/* Coordinates Grid */}
            <div className="grid grid-cols-3 gap-2 font-mono text-center">
              <div className="rounded-lg bg-black/40 border border-slate-700/40 p-2">
                <div className="text-[9px] uppercase tracking-wider text-slate-400 font-sans">
                  Longitude (X)
                </div>
                <div className="text-xs font-bold text-slate-100 mt-0.5 truncate" title={`${xStr}° E`}>
                  {xStr}°
                </div>
              </div>

              <div className="rounded-lg bg-black/40 border border-slate-700/40 p-2">
                <div className="text-[9px] uppercase tracking-wider text-slate-400 font-sans">
                  Latitude (Y)
                </div>
                <div className="text-xs font-bold text-slate-100 mt-0.5 truncate" title={`${yStr}° N`}>
                  {yStr}°
                </div>
              </div>

              <div className="rounded-lg bg-black/40 border border-cyan-500/30 p-2">
                <div className="text-[9px] uppercase tracking-wider text-cyan-400 font-sans">
                  AI Height (Z)
                </div>
                <div className="text-xs font-bold text-cyan-300 mt-0.5 truncate" title={`${zStr} m MSL`}>
                  {zStr} m
                </div>
              </div>
            </div>
          </section>

          {/* ============================================================
              SECTION 2: ACTIVE API ENDPOINT INSPECTOR
              ============================================================ */}
          <section className="rounded-xl border border-slate-700/60 bg-slate-900/50 p-3 space-y-2">
            <div className="flex items-center justify-between text-[11px]">
              <span className="font-semibold text-slate-300 flex items-center gap-1">
                <span>⚡</span> Active API Endpoint Inspector
              </span>
              <button
                type="button"
                onClick={handleCopyEndpoint}
                className="flex items-center gap-1 px-1.5 py-0.5 rounded text-[10px] font-mono bg-slate-800 hover:bg-slate-700 text-cyan-300 border border-slate-600 transition-colors"
              >
                {copiedUrl ? (
                  <>
                    <Check className="h-3 w-3 text-emerald-400" />
                    <span className="text-emerald-400">Copied</span>
                  </>
                ) : (
                  <>
                    <Copy className="h-3 w-3" />
                    <span>Copy URL</span>
                  </>
                )}
              </button>
            </div>

            {/* Code Readout Badge */}
            <div className="rounded-lg bg-[#040814] border border-cyan-500/30 p-2.5 font-mono text-[11px] text-cyan-300 break-all select-all flex items-start gap-2 shadow-inner">
              <span className="shrink-0 text-emerald-400 font-bold">GET</span>
              <span className="text-slate-200">{liveEndpoint}</span>
            </div>
          </section>

          {/* ============================================================
              SECTION 3: METRIC ACCURACY BENCHMARK CARD
              ============================================================ */}
          <section className="rounded-xl border border-indigo-500/30 bg-gradient-to-b from-indigo-950/40 to-[#070e24]/80 p-3 space-y-2.5">
            <div className="flex items-center justify-between">
              <div className="flex items-center gap-1.5 text-xs font-semibold text-indigo-200">
                <Database className="h-3.5 w-3.5 text-indigo-400" />
                <span>Metric Accuracy Benchmark</span>
              </div>
              <span className="rounded-full bg-indigo-900/60 px-2 py-0.5 font-mono text-[9px] font-bold text-indigo-300 border border-indigo-500/40">
                BENCHMARK
              </span>
            </div>

            {/* Metric Comparison Values */}
            <div className="grid grid-cols-2 gap-2 text-xs">
              <div className="rounded-lg bg-black/40 border border-indigo-500/20 p-2.5">
                <div className="text-[10px] text-indigo-300/80 font-medium">
                  Reference Elevation
                </div>
                <div className="mt-0.5 font-mono text-sm font-bold text-white">
                  {Number(refLidar).toLocaleString('en-US', {
                    minimumFractionDigits: 2,
                    maximumFractionDigits: 2
                  })}{' '}
                  m MSL
                </div>
              </div>

              <div className="rounded-lg bg-black/40 border border-indigo-500/20 p-2.5">
                <div className="text-[10px] text-indigo-300/80 font-medium">
                  Residual Delta Error
                </div>
                <div className="mt-0.5 font-mono text-sm font-bold text-emerald-400">
                  ±{Math.abs(deltaError).toFixed(2)} m
                </div>
              </div>
            </div>

            {/* Dataset Source Selector */}
            <div className="space-y-1 pt-1">
              <label className="text-[10px] text-slate-400 font-medium block">
                Ground-Truth Reference Catalog:
              </label>
              <select
                value={selectedDataset}
                onChange={(e) => onSelectDataset(e.target.value)}
                className="w-full bg-[#050b1a] border border-indigo-500/30 rounded-lg px-2.5 py-1.5 text-xs text-indigo-200 font-medium focus:outline-none focus:border-cyan-400 cursor-pointer"
              >
                <option value="ISRO Bhuvan CartoDEM">ISRO Bhuvan CartoDEM (10m Stereo)</option>
                <option value="OpenTopography LiDAR">OpenTopography LiDAR (1m Benchmark)</option>
                <option value="Copernicus 30m">Copernicus 30m (GLO-30 InSAR)</option>
              </select>
            </div>
          </section>

          {/* ============================================================
              SECTION 4: RAYCAST MEASURE MODE TOGGLE & CALIPER
              ============================================================ */}
          <section className="rounded-xl border border-amber-500/30 bg-slate-900/50 p-3 space-y-2.5">
            <div className="flex items-center justify-between">
              <div className="flex items-center gap-1.5 text-xs font-semibold text-amber-200">
                <Ruler className="h-3.5 w-3.5 text-amber-400" />
                <span>2-Point Caliper Measure Tool</span>
              </div>

              {/* Mode Toggle Button */}
              <button
                type="button"
                onClick={() => onToggleMeasureMode(!isMeasureMode)}
                className={`px-2.5 py-1 rounded-lg text-xs font-semibold font-mono border transition-all ${
                  isMeasureMode
                    ? 'bg-amber-500 text-black border-amber-400 shadow-[0_0_12px_rgba(245,158,11,0.4)]'
                    : 'bg-slate-800 text-slate-300 border-slate-700 hover:border-amber-400'
                }`}
              >
                {isMeasureMode ? 'ACTIVE' : 'OFF'}
              </button>
            </div>

            <p className="text-[10px] text-slate-400 leading-tight">
              Click 2 points on the 3D surface to measure Euclidean range, elevation delta (ΔH),
              and topographic slope gradient.
            </p>

            {/* Measurement Active Telemetry Display */}
            {measurementData && measurementData.telemetry ? (
              <div className="space-y-2 pt-1">
                <div className="grid grid-cols-2 gap-2 text-xs font-mono">
                  <div className="rounded bg-black/40 p-2 border border-slate-700/50">
                    <span className="text-[9px] text-slate-400 font-sans block">Straight Dist:</span>
                    <span className="text-amber-300 font-bold">
                      {measurementData.telemetry.straightDistance.toFixed(1)} m
                    </span>
                  </div>
                  <div className="rounded bg-black/40 p-2 border border-slate-700/50">
                    <span className="text-[9px] text-slate-400 font-sans block">Horizontal Run:</span>
                    <span className="text-slate-200 font-bold">
                      {measurementData.telemetry.horizontalDistance.toFixed(1)} m
                    </span>
                  </div>
                  <div className="rounded bg-black/40 p-2 border border-slate-700/50">
                    <span className="text-[9px] text-slate-400 font-sans block">Delta Height (ΔH):</span>
                    <span className="text-cyan-300 font-bold">
                      {measurementData.telemetry.deltaH.toFixed(2)} m
                    </span>
                  </div>
                  <div className="rounded bg-black/40 p-2 border border-slate-700/50">
                    <span className="text-[9px] text-slate-400 font-sans block">Slope Gradient:</span>
                    <span className="text-emerald-400 font-bold">
                      {measurementData.telemetry.slopeDeg.toFixed(1)}° ({measurementData.telemetry.slopePercent.toFixed(0)}%)
                    </span>
                  </div>
                </div>

                <button
                  type="button"
                  onClick={onClearMeasurement}
                  className="w-full text-center text-xs py-1 rounded bg-slate-800 hover:bg-slate-700 text-slate-300 border border-slate-700 transition-colors"
                >
                  Clear Caliper Points
                </button>
              </div>
            ) : isMeasureMode ? (
              <div className="rounded-lg bg-amber-950/30 border border-amber-500/30 p-2 text-center text-xs text-amber-300/90 font-mono animate-pulse">
                Click 1st point on terrain to begin caliper...
              </div>
            ) : null}
          </section>
        </div>

        {/* Drawer Footer */}
        <footer className="p-3 border-t border-cyan-500/20 bg-[#060a17] text-[10px] font-mono text-slate-400 flex items-center justify-between">
          <span>Datum: WGS84 / EGM96</span>
          <span className="text-cyan-400">ISRO SAC Spec</span>
        </footer>
      </aside>
    </div>
  );
}
