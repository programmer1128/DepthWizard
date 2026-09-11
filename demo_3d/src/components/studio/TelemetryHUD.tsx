import React from 'react';
import { 
  Mountain, 
  Eye, 
  Activity, 
  Globe, 
  Crosshair
} from 'lucide-react';
import type { TelemetryData } from '../../types/gis';
import { formatElevation, formatDistance } from '../../utils/formatters';

interface TelemetryHUDProps {
  telemetry: TelemetryData;
  isMeasuring: boolean;
}

export const TelemetryHUD: React.FC<TelemetryHUDProps> = ({
  telemetry,
  isMeasuring,
}) => {
  // Determine FPS color
  const getFpsColor = (fps: number) => {
    if (fps >= 50) return 'text-emerald-400';
    if (fps >= 30) return 'text-amber-400';
    return 'text-rose-400';
  };

  return (
    <footer className="absolute bottom-4 left-4 right-4 z-20 pointer-events-none flex items-center justify-between">
      {/* Main Glass Telemetry Capsule */}
      <div className="pointer-events-auto flex items-center gap-3 px-4 py-2 rounded-xl bg-slate-900/90 backdrop-blur-xl border border-slate-700/60 shadow-2xl text-xs select-none">
        {/* Geographic Coordinates Display */}
        <div className="flex items-center gap-2 pr-3 border-r border-slate-800">
          <div className="p-1 rounded bg-slate-800 text-cyan-400">
            <Globe className="w-3.5 h-3.5" />
          </div>
          <div>
            <div className="text-[10px] text-slate-400 font-medium">Coordinates</div>
            <div className="font-mono font-bold text-slate-200 tracking-tight">
              {telemetry.hasHit && telemetry.lat !== undefined && telemetry.lng !== undefined ? (
                `${telemetry.lat.toFixed(4)}° N, ${telemetry.lng.toFixed(4)}° E`
              ) : (
                <span className="text-slate-500 font-normal italic">Hover over 3D terrain</span>
              )}
            </div>
          </div>
        </div>

        {/* Sampled Elevation & Slope */}
        <div className="flex items-center gap-2 pr-3 border-r border-slate-800">
          <div className="p-1 rounded bg-slate-800 text-emerald-400">
            <Mountain className="w-3.5 h-3.5" />
          </div>
          <div>
            <div className="text-[10px] text-slate-400 font-medium">Sampled Elevation</div>
            <div className="font-mono font-bold text-emerald-300">
              {telemetry.hasHit ? (
                <>
                  {formatElevation(telemetry.elevation, true)}
                  <span className="text-[10px] text-slate-400 font-normal ml-1.5 font-mono">
                    ({telemetry.surfaceSlope}°)
                  </span>
                </>
              ) : (
                <span className="text-slate-500 font-normal">—</span>
              )}
            </div>
          </div>
        </div>

        {/* Camera Eye Altitude */}
        <div className="hidden sm:flex items-center gap-2 pr-3 border-r border-slate-800">
          <div className="p-1 rounded bg-slate-800 text-indigo-400">
            <Eye className="w-3.5 h-3.5" />
          </div>
          <div>
            <div className="text-[10px] text-slate-400 font-medium">Camera Eye Alt</div>
            <div className="font-mono font-semibold text-slate-200">
              {formatDistance(telemetry.cameraAltitude)}
            </div>
          </div>
        </div>

        {/* FPS Telemetry */}
        <div className="flex items-center gap-2">
          <div className="p-1 rounded bg-slate-800 text-slate-400">
            <Activity className="w-3.5 h-3.5" />
          </div>
          <div>
            <div className="text-[10px] text-slate-400 font-medium">Engine Frame Rate</div>
            <div className="font-mono font-bold flex items-center gap-1.5">
              <span className={getFpsColor(telemetry.fps)}>{telemetry.fps} FPS</span>
              <span className="text-[9px] px-1 py-0.2 rounded bg-slate-800 text-slate-400 font-normal border border-slate-700">
                256² Mesh
              </span>
            </div>
          </div>
        </div>
      </div>

      {/* Measurement Active Mode Pill (Right Side) */}
      {isMeasuring && (
        <div className="pointer-events-auto px-3 py-1.5 rounded-xl bg-amber-500/20 border border-amber-500/50 text-amber-300 backdrop-blur-md shadow-lg text-xs font-medium flex items-center gap-2 animate-pulse">
          <Crosshair className="w-3.5 h-3.5 text-amber-400" />
          <span>Measure Active: Click 2 Points</span>
        </div>
      )}
    </footer>
  );
};
