import React, { useState } from 'react';
import { 
  MapPin, 
  X, 
  Copy, 
  Check, 
  Download, 
  Mountain, 
  Compass, 
  Eye, 
  Crosshair,
  Layers,
  Sparkles
} from 'lucide-react';
import type { ElevationInspectionPoint } from '../../types/elevationApi';

interface RightTelemetryPanelProps {
  inspectionPoint: ElevationInspectionPoint | null;
  onClear: () => void;
}

export const RightTelemetryPanel: React.FC<RightTelemetryPanelProps> = ({
  inspectionPoint,
  onClear,
}) => {
  const [copied, setCopied] = useState(false);

  // If no point clicked yet, show a discreet hint badge
  if (!inspectionPoint) {
    return (
      <div className="absolute top-16 right-4 z-20 pointer-events-none select-none transition-all duration-300 opacity-80 hover:opacity-100">
        <div className="px-3 py-2 rounded-xl bg-slate-900/80 backdrop-blur-md border border-slate-800/80 shadow-xl flex items-center gap-2 text-xs text-slate-400">
          <Crosshair className="w-3.5 h-3.5 text-cyan-400 animate-pulse" />
          <span className="text-[11px]">Click 3D surface to inspect feature</span>
        </div>
      </div>
    );
  }

  // Copy structured telemetry text to clipboard
  const handleCopy = () => {
    const latStr = `${Math.abs(inspectionPoint.lat).toFixed(6)}° ${inspectionPoint.lat >= 0 ? 'N' : 'S'}`;
    const lngStr = `${Math.abs(inspectionPoint.lng).toFixed(6)}° ${inspectionPoint.lng >= 0 ? 'E' : 'W'}`;
    const text = `[DepthWizard 3D Inspection]
ID: ${inspectionPoint.elementId}
Feature: ${inspectionPoint.featureName}
Latitude: ${latStr}
Longitude: ${lngStr}
Elevation: ${inspectionPoint.elevation.toFixed(2)} m MSL
Slope Angle: ${inspectionPoint.surfaceSlope.toFixed(1)}°
${inspectionPoint.referenceElevation ? `Reference LiDAR: ${inspectionPoint.referenceElevation.toFixed(2)} m\nDelta Error: ${inspectionPoint.deltaError?.toFixed(2)} m` : ''}
Eye Altitude: ${inspectionPoint.cameraAltitude} m
Captured: ${inspectionPoint.timestamp}`;

    navigator.clipboard.writeText(text);
    setCopied(true);
    setTimeout(() => setCopied(false), 2000);
  };

  // Export JSON inspection report
  const handleExportJSON = () => {
    const exportData = {
      generator: 'DepthWizard 3D - Monocular Height Estimation Studio',
      version: '1.0.0-OGC-3DTILES',
      inspection: inspectionPoint,
    };
    const blob = new Blob([JSON.stringify(exportData, null, 2)], { type: 'application/json' });
    const url = URL.createObjectURL(blob);
    const link = document.createElement('a');
    link.href = url;
    link.download = `dw3d_feature_${inspectionPoint.elementId.replace(/[^a-zA-Z0-9_-]/g, '_')}.json`;
    document.body.appendChild(link);
    link.click();
    document.body.removeChild(link);
    URL.revokeObjectURL(url);
  };

  const latFormatted = `${Math.abs(inspectionPoint.lat).toFixed(6)}° ${inspectionPoint.lat >= 0 ? 'N' : 'S'}`;
  const lngFormatted = `${Math.abs(inspectionPoint.lng).toFixed(6)}° ${inspectionPoint.lng >= 0 ? 'E' : 'W'}`;

  return (
    <aside 
      className="absolute top-16 right-4 z-20 pointer-events-auto select-none w-80 sm:w-88 transition-all duration-300 transform translate-x-0"
      aria-label="Cesium Sandcastle Style Feature Inspector"
    >
      <div className="rounded-2xl bg-slate-900/95 backdrop-blur-2xl border border-slate-700/80 shadow-2xl overflow-hidden ring-1 ring-cyan-500/20">
        {/* Header - Cesium Sandcastle Style */}
        <div className="px-4 py-3 border-b border-slate-800 flex items-center justify-between bg-slate-950/70">
          <div className="flex items-center gap-2 overflow-hidden">
            <div className="p-1.5 rounded-lg bg-cyan-500/20 text-cyan-300 border border-cyan-500/30 shrink-0">
              <MapPin className="w-4 h-4" />
            </div>
            <div className="truncate">
              <div className="flex items-center gap-1.5">
                <h3 className="text-xs font-bold text-slate-100 truncate">
                  {inspectionPoint.featureName}
                </h3>
                <span className="text-[9px] px-1.5 py-0.2 rounded font-mono font-bold bg-cyan-950 text-cyan-300 border border-cyan-800/60">
                  {inspectionPoint.elementId}
                </span>
              </div>
              <p className="text-[10px] text-slate-400 font-mono flex items-center gap-1">
                <span>{inspectionPoint.timestamp}</span>
                <span>•</span>
                <span className="text-cyan-400">WGS84 Datum</span>
              </p>
            </div>
          </div>

          <div className="flex items-center gap-1 shrink-0 ml-2">
            {/* Export JSON button */}
            <button
              type="button"
              onClick={handleExportJSON}
              className="p-1.5 rounded-lg text-slate-300 hover:text-white bg-slate-800/80 hover:bg-slate-700 border border-slate-700 transition-colors"
              title="Export Inspector JSON"
            >
              <Download className="w-3.5 h-3.5 text-cyan-400" />
            </button>

            {/* Copy button */}
            <button
              type="button"
              onClick={handleCopy}
              className="p-1.5 rounded-lg text-slate-300 hover:text-white bg-slate-800/80 hover:bg-slate-700 border border-slate-700 transition-colors"
              title="Copy telemetry table"
            >
              {copied ? <Check className="w-3.5 h-3.5 text-emerald-400" /> : <Copy className="w-3.5 h-3.5" />}
            </button>

            {/* Close button */}
            <button
              type="button"
              onClick={onClear}
              className="p-1.5 rounded-lg text-slate-400 hover:text-rose-400 hover:bg-slate-800 transition-colors"
              title="Close panel"
            >
              <X className="w-3.5 h-3.5" />
            </button>
          </div>
        </div>

        {/* Structured Table matching Cesium Sandcastle Reference */}
        <div className="p-4 space-y-3 max-h-[calc(100vh-12rem)] overflow-y-auto">
          {/* Coordinates Rows */}
          <div className="rounded-xl bg-slate-950/80 border border-slate-800/90 divide-y divide-slate-800/80 text-xs">
            <div className="px-3 py-2 flex items-center justify-between">
              <span className="text-slate-400 font-medium">Latitude</span>
              <span className="font-mono font-bold text-cyan-300">{latFormatted}</span>
            </div>
            <div className="px-3 py-2 flex items-center justify-between">
              <span className="text-slate-400 font-medium">Longitude</span>
              <span className="font-mono font-bold text-cyan-300">{lngFormatted}</span>
            </div>
            <div className="px-3 py-2 flex items-center justify-between">
              <span className="text-slate-400 font-medium flex items-center gap-1.5">
                <Mountain className="w-3.5 h-3.5 text-emerald-400" />
                Absolute Elevation
              </span>
              <span className="font-mono font-bold text-emerald-400">
                {inspectionPoint.elevation.toLocaleString('en-US', { minimumFractionDigits: 2, maximumFractionDigits: 2 })} m MSL
              </span>
            </div>
            <div className="px-3 py-2 flex items-center justify-between">
              <span className="text-slate-400 font-medium flex items-center gap-1.5">
                <Compass className="w-3.5 h-3.5 text-amber-400" />
                Slope Angle
              </span>
              <span className="font-mono font-bold text-amber-300">
                {inspectionPoint.surfaceSlope.toFixed(1)}°
              </span>
            </div>
          </div>

          {/* Reference LiDAR Benchmark & Delta Error (when present) */}
          {inspectionPoint.referenceElevation !== undefined && inspectionPoint.deltaError !== undefined && (
            <div className="p-3 rounded-xl bg-gradient-to-br from-slate-950 to-slate-900 border border-slate-800">
              <div className="flex items-center justify-between text-[11px] font-semibold text-slate-300 mb-2">
                <span className="flex items-center gap-1.5 text-indigo-300">
                  <Sparkles className="w-3.5 h-3.5 text-indigo-400" />
                  LiDAR Ground Truth Comparison
                </span>
                <span className="text-[9px] px-1.5 py-0.2 rounded bg-indigo-950 text-indigo-300 border border-indigo-800/50 uppercase font-mono">
                  Benchmark
                </span>
              </div>
              <div className="grid grid-cols-2 gap-2 text-xs">
                <div className="p-2 rounded-lg bg-slate-900/90 border border-slate-800">
                  <span className="text-[10px] text-slate-400 block mb-0.5">Reference LiDAR</span>
                  <span className="font-mono font-bold text-slate-200">
                    {inspectionPoint.referenceElevation.toFixed(2)} m
                  </span>
                </div>
                <div className="p-2 rounded-lg bg-slate-900/90 border border-slate-800">
                  <span className="text-[10px] text-slate-400 block mb-0.5">Delta Error</span>
                  <span className="font-mono font-bold text-emerald-400 flex items-center gap-1">
                    <span>±{Math.abs(inspectionPoint.deltaError).toFixed(2)} m</span>
                  </span>
                </div>
              </div>
            </div>
          )}

          {/* Camera Perspective Telemetry */}
          <div className="grid grid-cols-2 gap-2 text-xs">
            <div className="p-2.5 rounded-xl bg-slate-950/80 border border-slate-800/80">
              <div className="flex items-center gap-1.5 text-[10px] font-semibold text-slate-400 mb-1">
                <Eye className="w-3 h-3 text-indigo-400" />
                <span>Eye Altitude</span>
              </div>
              <div className="font-mono font-bold text-slate-200">
                {inspectionPoint.cameraAltitude.toLocaleString()} m
              </div>
            </div>

            <div className="p-2.5 rounded-xl bg-slate-950/80 border border-slate-800/80">
              <div className="flex items-center gap-1.5 text-[10px] font-semibold text-slate-400 mb-1">
                <Crosshair className="w-3 h-3 text-cyan-400" />
                <span>Target Range</span>
              </div>
              <div className="font-mono font-bold text-slate-200">
                {inspectionPoint.cameraDistance.toLocaleString()} m
              </div>
            </div>
          </div>

          {/* Structural Metadata Table (if batch features present) */}
          {inspectionPoint.structuralMetadata && Object.keys(inspectionPoint.structuralMetadata).length > 0 && (
            <div className="rounded-xl bg-slate-950/80 border border-slate-800/80 p-2.5 space-y-1.5 text-xs">
              <div className="text-[10px] font-semibold text-slate-400 uppercase tracking-wider flex items-center gap-1 mb-1">
                <Layers className="w-3 h-3 text-cyan-400" />
                <span>OGC 3D Tile Structural Metadata</span>
              </div>
              <div className="space-y-1 font-mono text-[11px]">
                {Object.entries(inspectionPoint.structuralMetadata).map(([key, val]) => (
                  <div key={key} className="flex items-center justify-between text-slate-300">
                    <span className="text-slate-500">{key}:</span>
                    <span className="text-slate-200">{String(val)}</span>
                  </div>
                ))}
              </div>
            </div>
          )}
        </div>
      </div>
    </aside>
  );
};
