import React from 'react';
import { 
  Compass, 
  X, 
  Play, 
  Pause, 
  Gauge, 
  RotateCw, 
  Trash2, 
  Plus, 
  Repeat, 
  Sliders, 
  Radio
} from 'lucide-react';
import type { FlightWaypoint } from '../../types/gis';
import { formatDistance } from '../../utils/formatters';

interface DroneTourDrawerProps {
  isOpen: boolean;
  onClose: () => void;
  // Waypoint Spline Tour
  waypoints: FlightWaypoint[];
  isPlacingWaypoints: boolean;
  onTogglePlacingWaypoints: () => void;
  onRemoveWaypoint: (id: string) => void;
  onClearWaypoints: () => void;
  onLoadPresetWaypoints: (presetName: string) => void;
  isTourPlaying: boolean;
  onToggleTour: () => void;
  tourSpeed: number;
  onTourSpeedChange: (speed: number) => void;
  isLooping: boolean;
  onToggleLooping: () => void;
  // First-Person Drone Flight (WASD)
  isDroneMode: boolean;
  onToggleDroneMode: () => void;
  droneCruiseSpeed: number;
  onDroneCruiseSpeedChange: (speed: number) => void;
  onResetCamera: () => void;
}

export const DroneTourDrawer: React.FC<DroneTourDrawerProps> = ({
  isOpen,
  onClose,
  waypoints,
  isPlacingWaypoints,
  onTogglePlacingWaypoints,
  onRemoveWaypoint,
  onClearWaypoints,
  onLoadPresetWaypoints,
  isTourPlaying,
  onToggleTour,
  tourSpeed,
  onTourSpeedChange,
  isLooping,
  onToggleLooping,
  isDroneMode,
  onToggleDroneMode,
  droneCruiseSpeed,
  onDroneCruiseSpeedChange,
  onResetCamera,
}) => {
  if (!isOpen) return null;

  // Approximate total 3D trajectory path length
  const approximateLength = waypoints.reduce((acc, wp, idx) => {
    if (idx === 0) return 0;
    const prev = waypoints[idx - 1];
    const dx = (wp.x - prev.x) * 20;
    const dy = wp.elevation - prev.elevation;
    const dz = (wp.z - prev.z) * 20;
    return acc + Math.sqrt(dx * dx + dy * dy + dz * dz);
  }, 0);

  const estimatedFlightTime = approximateLength > 0 
    ? Math.round(approximateLength / (35 * tourSpeed)) 
    : 0;

  return (
    <aside 
      className="w-88 sm:w-104 h-[calc(100vh-3.5rem)] bg-slate-900/95 backdrop-blur-xl border-r border-slate-800 flex flex-col z-20 shadow-2xl overflow-y-auto select-none"
      aria-label="Drone Flight Navigation and Waypoint Tour Drawer"
    >
      {/* Header */}
      <div className="p-4 border-b border-slate-800 flex items-center justify-between sticky top-0 bg-slate-900/95 z-10 backdrop-blur-md">
        <div className="flex items-center gap-2">
          <div className="p-1.5 rounded-lg bg-emerald-500/20 text-emerald-400 border border-emerald-500/30">
            <Compass className="w-4 h-4" />
          </div>
          <div>
            <h2 className="text-sm font-bold text-slate-100">Aerial Navigation & Flight Tour</h2>
            <p className="text-[11px] text-slate-400 font-mono">Waypoint Splines & WASD Drone Flight</p>
          </div>
        </div>
        <button
          type="button"
          onClick={onClose}
          className="p-1.5 rounded-md text-slate-400 hover:text-slate-200 hover:bg-slate-800 transition-colors"
        >
          <X className="w-4 h-4" />
        </button>
      </div>

      <div className="p-4 space-y-5 flex-1">
        {/* Section 1: First-Person Drone Flight Mode (WASD) */}
        <div className="p-4 rounded-2xl bg-gradient-to-b from-slate-950 via-slate-900 to-slate-950 border border-slate-800 shadow-md">
          <div className="flex items-center justify-between mb-3">
            <span className="text-xs font-bold text-slate-200 flex items-center gap-1.5">
              <Radio className="w-3.5 h-3.5 text-cyan-400" />
              First-Person Drone Flight (WASD)
            </span>
            <span className={`text-[9px] px-2 py-0.5 rounded font-mono font-bold uppercase border ${
              isDroneMode 
                ? 'bg-cyan-950 text-cyan-300 border-cyan-500/50' 
                : 'bg-slate-900 text-slate-500 border-slate-700'
            }`}>
              {isDroneMode ? 'Engaged' : 'Standby'}
            </span>
          </div>

          <button
            type="button"
            onClick={onToggleDroneMode}
            className={`w-full py-2.5 px-4 rounded-xl font-medium text-xs flex items-center justify-center gap-2 transition-all shadow-md active:scale-95 ${
              isDroneMode
                ? 'bg-cyan-600 hover:bg-cyan-500 text-white shadow-cyan-600/30 ring-2 ring-cyan-400/40'
                : 'bg-slate-800 hover:bg-slate-700 text-slate-200 border border-slate-700'
            }`}
          >
            <Compass className="w-4 h-4" />
            <span>{isDroneMode ? 'Exit First-Person Flight Mode' : 'Take Manual Drone Flight Controls'}</span>
          </button>

          {/* Keybindings Cheat Sheet */}
          <div className="mt-3 p-2.5 rounded-xl bg-slate-950/80 border border-slate-800 text-[10px] font-mono space-y-1.5 text-slate-400">
            <div className="flex items-center justify-between">
              <span className="text-slate-300 font-bold">W / S</span>
              <span>Fly Forward / Backward</span>
            </div>
            <div className="flex items-center justify-between">
              <span className="text-slate-300 font-bold">A / D</span>
              <span>Strafe Left / Right</span>
            </div>
            <div className="flex items-center justify-between">
              <span className="text-slate-300 font-bold">Space / Shift</span>
              <span>Climb / Descend Altitude</span>
            </div>
            <div className="flex items-center justify-between">
              <span className="text-slate-300 font-bold">Mouse Drag</span>
              <span>Pitch & Yaw Orientation</span>
            </div>
          </div>

          {/* Drone Cruise Speed Slider */}
          <div className="mt-3">
            <div className="flex items-center justify-between text-xs mb-1.5">
              <span className="text-slate-400 font-medium">Cruise Thrust</span>
              <span className="font-mono text-cyan-300 font-bold">{droneCruiseSpeed.toFixed(1)}x</span>
            </div>
            <input
              type="range"
              min="0.5"
              max="3.0"
              step="0.1"
              value={droneCruiseSpeed}
              onChange={(e) => onDroneCruiseSpeedChange(parseFloat(e.target.value))}
              className="w-full h-1.5 bg-slate-800 rounded-lg appearance-none cursor-pointer accent-cyan-400"
            />
          </div>
        </div>

        {/* Section 2: Interactive Waypoint Tour Builder */}
        <div className="space-y-3 pt-2 border-t border-slate-800/80">
          <div className="flex items-center justify-between">
            <div>
              <h3 className="text-xs font-bold text-slate-200">Interactive Waypoint Spline Tour</h3>
              <p className="text-[10px] text-slate-400 font-mono">Catmull-Rom Smooth 3D Trajectory</p>
            </div>
            {waypoints.length > 0 && (
              <span className="text-[10px] font-mono px-2 py-0.5 rounded bg-emerald-950 text-emerald-300 border border-emerald-800/50">
                {waypoints.length} Nodes
              </span>
            )}
          </div>

          {/* Place Waypoint Mode Toggle */}
          <button
            type="button"
            onClick={onTogglePlacingWaypoints}
            className={`w-full py-2.5 px-4 rounded-xl font-medium text-xs flex items-center justify-center gap-2 transition-all shadow-md active:scale-95 ${
              isPlacingWaypoints
                ? 'bg-emerald-600 hover:bg-emerald-500 text-white shadow-emerald-600/30 animate-pulse'
                : 'bg-slate-800/90 hover:bg-slate-700 text-slate-200 border border-slate-700'
            }`}
          >
            <Plus className="w-4 h-4" />
            <span>{isPlacingWaypoints ? 'Click 3D Terrain to Add Waypoint (P...)' : 'Add Waypoint Pins by Clicking Terrain'}</span>
          </button>

          {/* Quick Preset Flight Trajectories */}
          <div className="space-y-1.5">
            <span className="text-[10px] font-semibold text-slate-400 uppercase tracking-wider block">
              Preset Inspection Paths
            </span>
            <div className="grid grid-cols-3 gap-1.5">
              <button
                type="button"
                onClick={() => onLoadPresetWaypoints('ridge')}
                className="py-1.5 px-2 rounded-lg bg-slate-950/60 hover:bg-slate-800 text-slate-300 text-[10px] font-mono border border-slate-800 transition-colors truncate"
              >
                Ridge Crest
              </button>
              <button
                type="button"
                onClick={() => onLoadPresetWaypoints('canyon')}
                className="py-1.5 px-2 rounded-lg bg-slate-950/60 hover:bg-slate-800 text-slate-300 text-[10px] font-mono border border-slate-800 transition-colors truncate"
              >
                Canyon Pass
              </button>
              <button
                type="button"
                onClick={() => onLoadPresetWaypoints('orbit')}
                className="py-1.5 px-2 rounded-lg bg-slate-950/60 hover:bg-slate-800 text-slate-300 text-[10px] font-mono border border-slate-800 transition-colors truncate"
              >
                Perimeter
              </button>
            </div>
          </div>

          {/* Waypoints List */}
          {waypoints.length > 0 && (
            <div className="p-3 rounded-2xl bg-slate-950/80 border border-slate-800 space-y-2">
              <div className="flex items-center justify-between text-xs mb-1">
                <span className="font-semibold text-slate-300">Flight Path Trajectory</span>
                <button
                  type="button"
                  onClick={onClearWaypoints}
                  className="text-[10px] font-mono text-rose-400 hover:text-rose-300 flex items-center gap-1 transition-colors"
                >
                  <Trash2 className="w-3 h-3" />
                  <span>Clear All</span>
                </button>
              </div>

              <div className="max-h-36 overflow-y-auto space-y-1.5 pr-1">
                {waypoints.map((wp, idx) => (
                  <div
                    key={wp.id}
                    className="p-2 rounded-lg bg-slate-900/90 border border-slate-800 flex items-center justify-between text-xs font-mono"
                  >
                    <div className="flex items-center gap-2">
                      <span className="w-5 h-5 rounded-full bg-emerald-500/20 text-emerald-400 border border-emerald-500/40 flex items-center justify-center font-bold text-[10px]">
                        {idx + 1}
                      </span>
                      <span className="text-slate-200 font-bold">{wp.name}</span>
                    </div>

                    <div className="text-slate-400 text-[10px]">
                      Elev: <span className="text-cyan-300">{Math.round(wp.elevation)}m</span>
                    </div>

                    <button
                      type="button"
                      onClick={() => onRemoveWaypoint(wp.id)}
                      className="p-1 rounded text-slate-500 hover:text-rose-400 transition-colors"
                      title="Delete waypoint"
                    >
                      <X className="w-3 h-3" />
                    </button>
                  </div>
                ))}
              </div>

              {/* Waypoint Trajectory Stats */}
              {approximateLength > 0 && (
                <div className="grid grid-cols-2 gap-2 pt-2 border-t border-slate-800 text-[11px] font-mono">
                  <div className="text-slate-400">
                    Path Length: <span className="text-slate-200 font-bold">{formatDistance(approximateLength)}</span>
                  </div>
                  <div className="text-slate-400 text-right">
                    Est. Time: <span className="text-cyan-300 font-bold">~{estimatedFlightTime}s</span>
                  </div>
                </div>
              )}
            </div>
          )}

          {/* Flight Control Console */}
          <div className="p-3.5 rounded-2xl bg-slate-950/90 border border-slate-800 space-y-3">
            <span className="text-xs font-semibold text-slate-200 flex items-center gap-1.5">
              <Sliders className="w-3.5 h-3.5 text-cyan-400" />
              Autonomous Flight Console
            </span>

            {/* Play/Pause Button */}
            <button
              type="button"
              onClick={onToggleTour}
              disabled={waypoints.length < 2}
              className={`w-full py-2.5 px-4 rounded-xl font-bold text-xs flex items-center justify-center gap-2 transition-all shadow-lg active:scale-95 ${
                waypoints.length < 2
                  ? 'bg-slate-800/50 text-slate-500 border border-slate-800 cursor-not-allowed'
                  : isTourPlaying
                  ? 'bg-amber-600 hover:bg-amber-500 text-white shadow-amber-600/30'
                  : 'bg-emerald-600 hover:bg-emerald-500 text-white shadow-emerald-600/30'
              }`}
            >
              {isTourPlaying ? (
                <>
                  <Pause className="w-4 h-4" />
                  <span>Pause Waypoint Tour</span>
                </>
              ) : (
                <>
                  <Play className="w-4 h-4" />
                  <span>{waypoints.length < 2 ? 'Place at least 2 Waypoints' : 'Launch Waypoint Flythrough'}</span>
                </>
              )}
            </button>

            {/* Speed Selector Buttons: 1x, 2x, 5x */}
            <div className="flex items-center justify-between text-xs">
              <span className="text-slate-400 font-medium flex items-center gap-1">
                <Gauge className="w-3.5 h-3.5 text-cyan-400" />
                Flight Speed
              </span>
              <div className="flex items-center gap-1">
                {[1, 2, 5].map((spd) => (
                  <button
                    key={spd}
                    type="button"
                    onClick={() => onTourSpeedChange(spd)}
                    className={`px-2.5 py-1 rounded-md text-[10px] font-mono font-bold transition-all border ${
                      Math.abs(tourSpeed - spd) < 0.2
                        ? 'bg-cyan-500 text-slate-950 border-cyan-400 shadow-md shadow-cyan-500/20'
                        : 'bg-slate-900 text-slate-400 border-slate-800 hover:text-white'
                    }`}
                  >
                    {spd}x
                  </button>
                ))}
              </div>
            </div>

            {/* Loop Toggle */}
            <div className="flex items-center justify-between text-xs pt-2 border-t border-slate-800">
              <span className="text-slate-400 font-medium flex items-center gap-1">
                <Repeat className="w-3.5 h-3.5 text-emerald-400" />
                Loop Trajectory
              </span>
              <button
                type="button"
                onClick={onToggleLooping}
                className={`px-2.5 py-1 rounded-md text-[10px] font-mono font-bold transition-all border ${
                  isLooping
                    ? 'bg-emerald-500/20 text-emerald-300 border-emerald-500/40'
                    : 'bg-slate-900 text-slate-500 border-slate-800 hover:text-slate-400'
                }`}
              >
                {isLooping ? 'Loop Active' : 'Single Pass'}
              </button>
            </div>
          </div>

          {/* Reset Camera View Button */}
          <button
            type="button"
            onClick={onResetCamera}
            className="w-full py-2 px-3 rounded-xl border border-slate-700 bg-slate-800/80 hover:bg-slate-700 text-slate-200 text-xs font-medium flex items-center justify-center gap-2 transition-colors"
          >
            <RotateCw className="w-3.5 h-3.5 text-slate-400" />
            <span>Reset Camera Orientation</span>
          </button>
        </div>
      </div>
    </aside>
  );
};
