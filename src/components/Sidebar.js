'use client';

import React, { useState } from 'react';
import {
  Ruler,
  Crosshair,
  ChevronDown,
  ChevronUp,
  MapPin,
  TrendingUp,
  RotateCcw,
  Layers,
  Database,
  Compass,
  ArrowRight
} from 'lucide-react';

/**
 * Sidebar Component for DepthWizard 3D
 * Includes the dedicated "Raycast Measurement (3D Metric Vector & Slope Analysis)" module
 *
 * @param {Object} props
 * @param {boolean} props.isMeasureMode - Measurement tool active state
 * @param {Function} props.onToggleMeasureMode - Callback to toggle measurement mode
 * @param {Object} props.measurementData - { pointA, pointB, telemetry }
 * @param {Function} props.onClearMeasurement - Callback to clear caliper lines/points
 * @param {Object} props.inspectionData - Current inspection telemetry for ground truth
 * @param {string} props.selectedDataset - Active DEM dataset
 * @param {Function} props.onSelectDataset - Change active DEM dataset
 */
export default function Sidebar({
  isMeasureMode = false,
  onToggleMeasureMode = () => {},
  measurementData = null,
  onClearMeasurement = () => {},
  inspectionData = null,
  selectedDataset = 'ISRO Bhuvan CartoDEM',
  onSelectDataset = () => {},
  className = ''
}) {
  const [isSectionOpen, setIsSectionOpen] = useState(true);

  const pointA = measurementData?.pointA || null;
  const pointB = measurementData?.pointB || null;
  const telemetry = measurementData?.telemetry || null;

  // Delta elevation sign and color calculation
  const deltaH = telemetry?.deltaH ?? (pointA && pointB ? pointB.elevation - pointA.elevation : 0);
  const deltaSign = deltaH >= 0 ? '+' : '';
  const deltaColor = deltaH >= 0 ? 'text-emerald-400' : 'text-rose-400';

  // SVG Elevation Profile Curve points
  const renderProfileSvg = () => {
    if (!pointA || !pointB) return null;

    const elevA = pointA.elevation;
    const elevB = pointB.elevation;
    const minElev = Math.min(elevA, elevB);
    const maxElev = Math.max(elevA, elevB);
    const elevRange = Math.max(maxElev - minElev, 10.0);

    // Map elevations to SVG coordinates (0 to 280 X, 60 to 15 Y)
    const yA = 60 - ((elevA - minElev) / elevRange) * 45;
    const yB = 60 - ((elevB - minElev) / elevRange) * 45;

    // Control points for realistic terrain curvature between points
    const midY = (yA + yB) / 2 + (elevA > elevB ? 6 : -6);
    const pathD = `M 20 ${yA} Q 150 ${midY} 280 ${yB}`;
    const fillD = `M 20 ${yA} Q 150 ${midY} 280 ${yB} L 280 72 L 20 72 Z`;

    return (
      <div className="rounded-lg bg-black/40 border border-slate-700/50 p-2.5 mt-2 space-y-1">
        <div className="flex items-center justify-between text-[10px] text-slate-400 font-mono">
          <span className="text-cyan-400 font-semibold">Point A: {elevA.toFixed(1)}m</span>
          <span className="text-amber-400 font-semibold">Point B: {elevB.toFixed(1)}m</span>
        </div>

        <svg viewBox="0 0 300 75" className="w-full h-16 overflow-visible">
          <defs>
            <linearGradient id="profileGradient" x1="0%" y1="0%" x2="0%" y2="100%">
              <stop offset="0%" stopColor="#06b6d4" stopOpacity="0.4" />
              <stop offset="100%" stopColor="#0b1329" stopOpacity="0.0" />
            </linearGradient>
            <linearGradient id="lineGrad" x1="0%" y1="0%" x2="100%" y2="0%">
              <stop offset="0%" stopColor="#06b6d4" />
              <stop offset="100%" stopColor="#f59e0b" />
            </linearGradient>
          </defs>

          {/* Grid reference line */}
          <line x1="15" y1="72" x2="285" y2="72" stroke="rgba(255,255,255,0.1)" strokeWidth="1" />

          {/* Filled Area */}
          <path d={fillD} fill="url(#profileGradient)" />

          {/* Elevation Profile Curve */}
          <path d={pathD} fill="none" stroke="url(#lineGrad)" strokeWidth="2.5" strokeLinecap="round" />

          {/* Point A Node */}
          <circle cx="20" cy={yA} r="4" fill="#06b6d4" stroke="#ffffff" strokeWidth="1.5" />
          <text x="20" y={Math.max(yA - 8, 12)} fill="#06b6d4" fontSize="9" fontWeight="bold" textAnchor="middle">
            A
          </text>

          {/* Point B Node */}
          <circle cx="280" cy={yB} r="4" fill="#f59e0b" stroke="#ffffff" strokeWidth="1.5" />
          <text x="280" y={Math.max(yB - 8, 12)} fill="#f59e0b" fontSize="9" fontWeight="bold" textAnchor="middle">
            B
          </text>

          {/* Delta H Indicator badge in center */}
          <rect x="120" y="2" width="60" height="14" rx="3" fill="#0f172a" stroke="#475569" />
          <text x="150" y="12" fill="#38bdf8" fontSize="8" fontFamily="monospace" fontWeight="bold" textAnchor="middle">
            ΔH {deltaSign}{deltaH.toFixed(1)}m
          </text>
        </svg>

        <div className="flex items-center justify-between text-[9px] text-slate-400 font-mono px-1">
          <span>Min: {minElev.toFixed(1)}m</span>
          <span className="text-emerald-400 font-semibold">Elev Gain/Loss: {deltaSign}{deltaH.toFixed(1)}m</span>
          <span>Max: {maxElev.toFixed(1)}m</span>
        </div>
      </div>
    );
  };

  return (
    <aside
      className={`w-84 w-[21.5rem] bg-[#070d1d]/95 backdrop-blur-xl border-r border-cyan-500/20 flex flex-col justify-between overflow-y-auto z-20 text-white select-none ${className}`}
      aria-label="Sidebar Controls"
    >
      <div className="p-4 space-y-4">
        {/* Sidebar Mission Header */}
        <div className="flex items-center gap-3 border-b border-cyan-500/20 pb-3">
          <div className="flex h-9 w-9 items-center justify-center rounded-xl bg-cyan-500/15 border border-cyan-500/35 text-cyan-400 shadow-[0_0_12px_rgba(6,182,212,0.2)]">
            <Compass className="h-5 w-5" />
          </div>
          <div>
            <h1 className="text-xs font-bold tracking-wide text-white uppercase flex items-center gap-1.5">
              DepthWizard 3D
              <span className="text-[9px] px-1.5 py-0.2 rounded bg-cyan-950 text-cyan-300 border border-cyan-500/30">
                WebGIS
              </span>
            </h1>
            <p className="text-[10px] text-slate-400 font-mono">
              ISRO SAC Monocular Terrain Analysis
            </p>
          </div>
        </div>

        {/* ============================================================
            1. RAYCAST MEASUREMENT (3D METRIC VECTOR & SLOPE ANALYSIS)
            ============================================================ */}
        <section className="rounded-xl border border-amber-500/30 bg-gradient-to-b from-amber-950/25 via-[#0b1329]/90 to-[#070e24] shadow-xl overflow-hidden transition-all">
          {/* Header with toggle collapse */}
          <div
            onClick={() => setIsSectionOpen(!isSectionOpen)}
            className="flex items-center justify-between p-3 cursor-pointer bg-amber-500/10 hover:bg-amber-500/15 border-b border-amber-500/20 transition-colors"
          >
            <div className="flex items-center gap-2">
              <div className="flex h-6 w-6 items-center justify-center rounded bg-amber-500/20 text-amber-300 border border-amber-500/40">
                <Ruler className="h-3.5 w-3.5" />
              </div>
              <div>
                <h2 className="text-xs font-bold text-slate-100 flex items-center gap-1.5">
                  Raycast Measurement
                </h2>
                <span className="text-[9px] text-amber-300/80 font-mono block">
                  3D Metric Vector & Slope Analysis
                </span>
              </div>
            </div>

            <button type="button" className="text-slate-400 hover:text-white text-xs">
              {isSectionOpen ? <ChevronUp className="h-4 w-4" /> : <ChevronDown className="h-4 w-4" />}
            </button>
          </div>

          {/* Section Body */}
          {isSectionOpen && (
            <div className="p-3 space-y-3">
              {/* High-Visibility Amber Toggle Button */}
              <button
                type="button"
                onClick={() => onToggleMeasureMode(!isMeasureMode)}
                className={`w-full py-2 px-3 rounded-lg text-xs font-bold font-mono tracking-wide uppercase shadow-lg transition-all duration-200 flex items-center justify-center gap-2 ${
                  isMeasureMode
                    ? 'bg-amber-500 text-slate-950 font-bold hover:bg-amber-400 shadow-[0_0_18px_rgba(245,158,11,0.45)] ring-2 ring-amber-300 animate-pulse'
                    : 'bg-slate-800 text-amber-300 font-bold hover:bg-slate-700 border border-amber-500/40'
                }`}
              >
                <span>{isMeasureMode ? '⊙' : '○'}</span>
                <span>
                  {isMeasureMode
                    ? 'Measurement Tool Active (Click Terrain)'
                    : 'Enable Raycast Measurement'}
                </span>
              </button>

              {/* Instructions text */}
              <p className="text-[10px] text-slate-400 text-center leading-relaxed">
                Click Point A then Point B on the 3D block to measure.
              </p>

              {/* ============================================================
                  2. POINT A & POINT B SUB-CARDS
                  ============================================================ */}
              <div className="grid grid-cols-2 gap-2">
                {/* Point A Card */}
                <div className="rounded-lg border border-cyan-500/40 bg-cyan-950/30 p-2.5 space-y-1">
                  <div className="text-[10px] font-bold text-cyan-400 flex items-center gap-1">
                    <span>●</span>
                    <span>Point A (Start)</span>
                  </div>
                  <div className="font-mono text-xs font-bold text-slate-100 truncate">
                    Elev: {pointA ? `${pointA.elevation.toFixed(1)} m` : '-- m'}
                  </div>
                  <div className="text-[9px] font-mono text-slate-400 truncate" title={pointA ? `${pointA.lat.toFixed(4)}°N, ${pointA.lon.toFixed(4)}°E` : 'Click on 3D terrain'}>
                    {pointA
                      ? `${pointA.lat.toFixed(4)}°N, ${pointA.lon.toFixed(4)}°E`
                      : 'Click on 3D terrain'}
                  </div>
                </div>

                {/* Point B Card */}
                <div className="rounded-lg border border-amber-500/40 bg-amber-950/30 p-2.5 space-y-1">
                  <div className="text-[10px] font-bold text-amber-400 flex items-center gap-1">
                    <span>●</span>
                    <span>Point B (Target)</span>
                  </div>
                  <div className="font-mono text-xs font-bold text-slate-100 truncate">
                    Elev: {pointB ? `${pointB.elevation.toFixed(1)} m` : '-- m'}
                  </div>
                  <div className="text-[9px] font-mono text-slate-400 truncate" title={pointB ? `${pointB.lat.toFixed(4)}°N, ${pointB.lon.toFixed(4)}°E` : 'Click target on 3D terrain'}>
                    {pointB
                      ? `${pointB.lat.toFixed(4)}°N, ${pointB.lon.toFixed(4)}°E`
                      : 'Click target on 3D terrain'}
                  </div>
                </div>
              </div>

              {/* ============================================================
                  3. CALCULATED 3D VECTOR TELEMETRY GRID
                  ============================================================ */}
              {telemetry ? (
                <div className="space-y-2 pt-1">
                  <div className="text-[10px] uppercase font-bold text-slate-300 font-mono flex items-center gap-1">
                    <TrendingUp className="h-3 w-3 text-amber-400" />
                    <span>3D Vector Telemetry</span>
                  </div>

                  <div className="grid grid-cols-2 gap-2 text-xs font-mono">
                    {/* 3D Straight Distance */}
                    <div className="rounded-lg bg-black/40 border border-slate-700/60 p-2">
                      <span className="text-[9px] text-slate-400 font-sans block">
                        3D Straight Dist:
                      </span>
                      <span className="text-amber-300 font-bold text-sm">
                        {telemetry.straightDistance.toFixed(1)} m
                      </span>
                    </div>

                    {/* Horizontal Planar Distance */}
                    <div className="rounded-lg bg-black/40 border border-slate-700/60 p-2">
                      <span className="text-[9px] text-slate-400 font-sans block">
                        Horizontal Planar:
                      </span>
                      <span className="text-slate-200 font-bold text-sm">
                        {telemetry.horizontalDistance.toFixed(1)} m
                      </span>
                    </div>

                    {/* Elevation Delta (ΔH) */}
                    <div className="rounded-lg bg-black/40 border border-slate-700/60 p-2">
                      <span className="text-[9px] text-slate-400 font-sans block">
                        Elevation Delta (ΔH):
                      </span>
                      <span className={`font-bold text-sm ${deltaColor}`}>
                        {deltaSign}{telemetry.deltaH.toFixed(1)} m
                      </span>
                    </div>

                    {/* Slope Gradient */}
                    <div className="rounded-lg bg-black/40 border border-slate-700/60 p-2">
                      <span className="text-[9px] text-slate-400 font-sans block">
                        Slope Gradient:
                      </span>
                      <span className="text-amber-400 font-bold text-sm">
                        {telemetry.slopeDeg.toFixed(1)}° ({telemetry.slopePercent.toFixed(0)}%)
                      </span>
                    </div>
                  </div>

                  {/* ============================================================
                      4. INTERACTIVE SVG ELEVATION PROFILE CURVE
                      ============================================================ */}
                  {renderProfileSvg()}

                  {/* Clear Measurement Points Button */}
                  <button
                    type="button"
                    onClick={onClearMeasurement}
                    className="w-full py-1.5 px-3 rounded-lg text-xs font-semibold bg-slate-800 hover:bg-slate-700 text-slate-300 border border-slate-700 transition-colors flex items-center justify-center gap-1.5 mt-2"
                  >
                    <RotateCcw className="h-3.5 w-3.5 text-slate-400" />
                    <span>Clear Measurement Points</span>
                  </button>
                </div>
              ) : isMeasureMode ? (
                <div className="rounded-lg bg-amber-950/30 border border-amber-500/30 p-2.5 text-center text-xs text-amber-300/90 font-mono animate-pulse">
                  {pointA ? 'Click Point B on 3D terrain to complete vector' : 'Click Point A on 3D terrain to begin'}
                </div>
              ) : null}
            </div>
          )}
        </section>

        {/* Dataset Source Quick Selection */}
        <section className="rounded-xl border border-slate-700/50 bg-slate-900/40 p-3 space-y-2">
          <div className="flex items-center justify-between text-xs font-semibold text-slate-200">
            <span className="flex items-center gap-1.5">
              <Database className="h-3.5 w-3.5 text-cyan-400" />
              <span>Ground Truth Dataset</span>
            </span>
          </div>

          <select
            value={selectedDataset}
            onChange={(e) => onSelectDataset(e.target.value)}
            className="w-full bg-slate-950 border border-slate-700 rounded-lg px-2.5 py-1.5 text-xs text-cyan-300 font-medium focus:outline-none focus:border-cyan-400 cursor-pointer"
          >
            <option value="ISRO Bhuvan CartoDEM">ISRO Bhuvan CartoDEM (10m Stereo)</option>
            <option value="OpenTopography LiDAR">OpenTopography LiDAR (1m Benchmark)</option>
            <option value="Copernicus 30m">Copernicus 30m (GLO-30 InSAR)</option>
          </select>
        </section>
      </div>

      {/* Sidebar Footer */}
      <footer className="p-3 border-t border-cyan-500/20 bg-[#060a17] text-[10px] font-mono text-slate-400 flex items-center justify-between">
        <span>Datum: WGS84 MSL</span>
        <span className="text-cyan-400">DepthWizard 3D</span>
      </footer>
    </aside>
  );
}
