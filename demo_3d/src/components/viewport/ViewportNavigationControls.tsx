import React, { useState, useRef, useEffect } from 'react';
import { 
  Layers, 
  Maximize2, 
  RotateCw, 
  ZoomIn, 
  ZoomOut, 
  Sun, 
  Moon, 
  Sunrise, 
  Sunset, 
  Sliders, 
  Eye, 
  Columns
} from 'lucide-react';

export interface ViewportNavigationControlsProps {
  cameraHeading: number; // 0 to 360 degrees
  onResetNorth: () => void;
  onSnapNadir: () => void;
  onSnapOblique: () => void;
  onFitBounds: () => void;
  onZoomIn: () => void;
  onZoomOut: () => void;
  fov: number;
  onFovChange: (fov: number) => void;
  isTurntable: boolean;
  turntableSpeed: number;
  onToggleTurntable: () => void;
  timeOfDayHour: number; // 0 to 24
  onTimeOfDayChange: (hour: number) => void;
  isSplitScreen: boolean;
  onToggleSplitScreen: () => void;
  splitPosition: number; // 0 to 1
  onSplitPositionChange: (pos: number) => void;
  isStandalone?: boolean;
}

export const ViewportNavigationControls: React.FC<ViewportNavigationControlsProps> = ({
  cameraHeading,
  onResetNorth,
  onSnapNadir,
  onSnapOblique,
  onFitBounds,
  onZoomIn,
  onZoomOut,
  fov,
  onFovChange,
  isTurntable,
  onToggleTurntable,
  timeOfDayHour,
  onTimeOfDayChange,
  isSplitScreen,
  onToggleSplitScreen,
  splitPosition,
  onSplitPositionChange,
}) => {
  const [activePanel, setActivePanel] = useState<'none' | 'lighting' | 'camera'>('none');
  const [isDraggingSplit, setIsDraggingSplit] = useState(false);
  const dragContainerRef = useRef<HTMLDivElement>(null);

  // Format Time of Day to 24-hour string (e.g. 14:30)
  const formatTime = (hourVal: number) => {
    const totalMinutes = Math.round(hourVal * 60);
    const h = Math.floor(totalMinutes / 60) % 24;
    const m = totalMinutes % 60;
    return `${h.toString().padStart(2, '0')}:${m.toString().padStart(2, '0')}`;
  };

  const getTimeIcon = (h: number) => {
    if (h >= 5 && h < 8) return <Sunrise className="w-3.5 h-3.5 text-amber-400" />;
    if (h >= 8 && h < 17) return <Sun className="w-3.5 h-3.5 text-amber-300" />;
    if (h >= 17 && h < 20) return <Sunset className="w-3.5 h-3.5 text-orange-400" />;
    return <Moon className="w-3.5 h-3.5 text-indigo-300" />;
  };

  // Split-Screen Dragging Interaction
  useEffect(() => {
    const handlePointerMove = (e: PointerEvent) => {
      if (!isDraggingSplit) return;
      const targetWidth = window.innerWidth;
      const newPos = Math.max(0.05, Math.min(0.95, e.clientX / targetWidth));
      onSplitPositionChange(newPos);
    };

    const handlePointerUp = () => {
      setIsDraggingSplit(false);
    };

    if (isDraggingSplit) {
      window.addEventListener('pointermove', handlePointerMove);
      window.addEventListener('pointerup', handlePointerUp);
    }
    return () => {
      window.removeEventListener('pointermove', handlePointerMove);
      window.removeEventListener('pointerup', handlePointerUp);
    };
  }, [isDraggingSplit, onSplitPositionChange]);

  return (
    <>
      {/* 1. Floating Top-Left / Top-Center Navigation Gadget Bar */}
      <div className="absolute top-4 left-4 z-20 pointer-events-auto flex flex-col gap-2 select-none">
        {/* Main Floating Tool Strip */}
        <div className="flex items-center gap-1.5 p-1.5 rounded-2xl bg-slate-900/90 backdrop-blur-xl border border-slate-700/70 shadow-2xl">
          {/* Rotating SVG Compass */}
          <button
            type="button"
            onClick={onResetNorth}
            className="group relative flex items-center justify-center w-10 h-10 rounded-xl bg-slate-950 border border-slate-800 hover:border-cyan-500/50 hover:bg-slate-900 transition-all active:scale-95"
            title={`Current Heading: ${Math.round(cameraHeading)}°. Click to align to True North (0°)`}
          >
            {/* Compass Dial SVG */}
            <svg 
              className="w-7 h-7 transition-transform duration-100 ease-out" 
              style={{ transform: `rotate(${-cameraHeading}deg)` }}
              viewBox="0 0 100 100"
            >
              {/* Outer compass ring */}
              <circle cx="50" cy="50" r="46" fill="none" stroke="#334155" strokeWidth="3" />
              {/* Tick marks */}
              <line x1="50" y1="6" x2="50" y2="16" stroke="#06b6d4" strokeWidth="4" />
              <line x1="50" y1="84" x2="50" y2="94" stroke="#64748b" strokeWidth="3" />
              <line x1="6" y1="50" x2="16" y2="50" stroke="#64748b" strokeWidth="3" />
              <line x1="84" y1="50" x2="94" y2="50" stroke="#64748b" strokeWidth="3" />
              
              {/* North Arrow (Red & Cyan pointer needle) */}
              <polygon points="50,16 43,48 57,48" fill="#ef4444" />
              <polygon points="50,84 43,52 57,52" fill="#64748b" />
              <circle cx="50" cy="50" r="4.5" fill="#f8fafc" />
            </svg>
            <span className="absolute -bottom-1 text-[8px] font-mono font-bold text-cyan-400 bg-slate-950 px-1 rounded shadow">
              {Math.round(cameraHeading).toString().padStart(3, '0')}°
            </span>
          </button>

          <div className="h-6 w-[1px] bg-slate-800 mx-0.5" />

          {/* View Snapping: Nadir (2D Top-Down) */}
          <button
            type="button"
            onClick={onSnapNadir}
            className="flex items-center gap-1 px-2.5 py-1.5 rounded-lg bg-slate-950/80 hover:bg-slate-800 text-slate-300 hover:text-cyan-300 border border-slate-800 hover:border-slate-700 text-xs font-medium transition-all active:scale-95"
            title="Snap to 2D Top-Down Nadir View"
          >
            <Layers className="w-3.5 h-3.5 text-cyan-400" />
            <span className="hidden sm:inline text-[11px]">Nadir (2D)</span>
          </button>

          {/* View Snapping: Oblique (45° Perspective) */}
          <button
            type="button"
            onClick={onSnapOblique}
            className="flex items-center gap-1 px-2.5 py-1.5 rounded-lg bg-slate-950/80 hover:bg-slate-800 text-slate-300 hover:text-cyan-300 border border-slate-800 hover:border-slate-700 text-xs font-medium transition-all active:scale-95"
            title="Snap to 45° Oblique Perspective Relief View"
          >
            <Eye className="w-3.5 h-3.5 text-emerald-400" />
            <span className="hidden sm:inline text-[11px]">Oblique (45°)</span>
          </button>

          {/* View Snapping: Fit to Bounds */}
          <button
            type="button"
            onClick={onFitBounds}
            className="p-1.5 rounded-lg bg-slate-950/80 hover:bg-slate-800 text-slate-300 hover:text-cyan-300 border border-slate-800 hover:border-slate-700 transition-all active:scale-95"
            title="Fit Camera to Entire Terrain Bounds"
          >
            <Maximize2 className="w-3.5 h-3.5 text-indigo-400" />
          </button>

          <div className="h-6 w-[1px] bg-slate-800 mx-0.5" />

          {/* Incremental Zoom Buttons */}
          <div className="flex items-center bg-slate-950/80 rounded-lg border border-slate-800">
            <button
              type="button"
              onClick={onZoomIn}
              className="p-1.5 rounded-l-lg hover:bg-slate-800 text-slate-300 hover:text-white transition-colors"
              title="Zoom In"
            >
              <ZoomIn className="w-3.5 h-3.5 text-slate-300" />
            </button>
            <button
              type="button"
              onClick={onZoomOut}
              className="p-1.5 rounded-r-lg hover:bg-slate-800 text-slate-300 hover:text-white border-l border-slate-800 transition-colors"
              title="Zoom Out"
            >
              <ZoomOut className="w-3.5 h-3.5 text-slate-300" />
            </button>
          </div>

          {/* 360° Turntable Auto-Orbit Toggle */}
          <button
            type="button"
            onClick={onToggleTurntable}
            className={`flex items-center gap-1 px-2.5 py-1.5 rounded-lg border text-xs font-medium transition-all active:scale-95 ${
              isTurntable
                ? 'bg-cyan-500/20 text-cyan-300 border-cyan-500/50 shadow-md shadow-cyan-500/20'
                : 'bg-slate-950/80 text-slate-300 hover:bg-slate-800 border-slate-800'
            }`}
            title="Toggle 360° Continuous Turntable Auto-Orbit"
          >
            <RotateCw className={`w-3.5 h-3.5 ${isTurntable ? 'animate-spin text-cyan-400' : 'text-slate-400'}`} />
            <span className="hidden md:inline text-[11px]">360° Orbit</span>
          </button>

          <div className="h-6 w-[1px] bg-slate-800 mx-0.5" />

          {/* Time-of-Day Lighting Trigger */}
          <button
            type="button"
            onClick={() => setActivePanel(activePanel === 'lighting' ? 'none' : 'lighting')}
            className={`flex items-center gap-1.5 px-2.5 py-1.5 rounded-lg border text-xs font-medium transition-all ${
              activePanel === 'lighting'
                ? 'bg-amber-500/20 text-amber-300 border-amber-500/50'
                : 'bg-slate-950/80 text-slate-300 hover:bg-slate-800 border-slate-800'
            }`}
            title="Time-of-Day Solar Lighting &amp; Shadows"
          >
            {getTimeIcon(timeOfDayHour)}
            <span className="font-mono text-[11px] font-bold text-amber-300">
              {formatTime(timeOfDayHour)}
            </span>
          </button>

          {/* Camera Optics (FOV) Trigger */}
          <button
            type="button"
            onClick={() => setActivePanel(activePanel === 'camera' ? 'none' : 'camera')}
            className={`flex items-center gap-1 px-2 py-1.5 rounded-lg border text-xs transition-all ${
              activePanel === 'camera'
                ? 'bg-cyan-500/20 text-cyan-300 border-cyan-500/50'
                : 'bg-slate-950/80 text-slate-300 hover:bg-slate-800 border-slate-800'
            }`}
            title="Camera Field of View (FOV)"
          >
            <Sliders className="w-3.5 h-3.5 text-indigo-400" />
            <span className="font-mono text-[11px]">{fov}°</span>
          </button>

          <div className="h-6 w-[1px] bg-slate-800 mx-0.5" />

          {/* Split-Screen Scissor Mode Toggle */}
          <button
            type="button"
            onClick={onToggleSplitScreen}
            className={`flex items-center gap-1.5 px-2.5 py-1.5 rounded-lg border text-xs font-medium transition-all active:scale-95 ${
              isSplitScreen
                ? 'bg-indigo-600 text-white border-indigo-400 shadow-md shadow-indigo-600/30'
                : 'bg-slate-950/80 text-slate-300 hover:bg-slate-800 border-slate-800 hover:text-white'
            }`}
            title="Split-Screen Comparison (2D Flat Ortho vs 3D Relief Mesh)"
          >
            <Columns className="w-3.5 h-3.5 text-indigo-400" />
            <span className="hidden lg:inline text-[11px]">2D/3D Split</span>
          </button>
        </div>

        {/* Popover Panel: Time-of-Day Solar Orbit (0:00 to 24:00) */}
        {activePanel === 'lighting' && (
          <div className="w-72 p-3 rounded-xl bg-slate-900/95 backdrop-blur-xl border border-slate-700/80 shadow-2xl text-xs space-y-2 animate-in fade-in slide-in-from-top-2 duration-150">
            <div className="flex items-center justify-between text-slate-300 font-semibold">
              <span className="flex items-center gap-1.5">
                {getTimeIcon(timeOfDayHour)}
                <span>Time of Day (Solar Orbit)</span>
              </span>
              <span className="font-mono text-amber-300 font-bold bg-slate-950 px-2 py-0.5 rounded border border-slate-800">
                {formatTime(timeOfDayHour)}
              </span>
            </div>

            <input
              type="range"
              min="0"
              max="24"
              step="0.1"
              value={timeOfDayHour}
              onChange={(e) => onTimeOfDayChange(parseFloat(e.target.value))}
              className="w-full h-2 bg-slate-800 rounded-lg appearance-none cursor-pointer accent-amber-400"
            />

            <div className="flex justify-between text-[10px] font-mono text-slate-500">
              <span>00:00 (Night)</span>
              <span>06:00 (Dawn)</span>
              <span>12:00 (Noon)</span>
              <span>18:00 (Dusk)</span>
              <span>24:00</span>
            </div>

            <div className="grid grid-cols-4 gap-1 pt-1">
              <button
                type="button"
                onClick={() => onTimeOfDayChange(6.5)}
                className="p-1 rounded bg-slate-950 border border-slate-800 hover:border-amber-500/50 text-[10px] text-slate-300"
              >
                Sunrise
              </button>
              <button
                type="button"
                onClick={() => onTimeOfDayChange(12.0)}
                className="p-1 rounded bg-slate-950 border border-slate-800 hover:border-amber-500/50 text-[10px] text-slate-300"
              >
                Noon
              </button>
              <button
                type="button"
                onClick={() => onTimeOfDayChange(17.8)}
                className="p-1 rounded bg-slate-950 border border-slate-800 hover:border-amber-500/50 text-[10px] text-slate-300"
              >
                Golden
              </button>
              <button
                type="button"
                onClick={() => onTimeOfDayChange(22.0)}
                className="p-1 rounded bg-slate-950 border border-slate-800 hover:border-indigo-500/50 text-[10px] text-slate-300"
              >
                Night
              </button>
            </div>
          </div>
        )}

        {/* Popover Panel: Camera Field of View (FOV) */}
        {activePanel === 'camera' && (
          <div className="w-64 p-3 rounded-xl bg-slate-900/95 backdrop-blur-xl border border-slate-700/80 shadow-2xl text-xs space-y-2 animate-in fade-in slide-in-from-top-2 duration-150">
            <div className="flex items-center justify-between text-slate-300 font-semibold">
              <span className="flex items-center gap-1.5">
                <Eye className="w-3.5 h-3.5 text-cyan-400" />
                <span>Field of View (FOV)</span>
              </span>
              <span className="font-mono text-cyan-300 font-bold bg-slate-950 px-2 py-0.5 rounded border border-slate-800">
                {fov}°
              </span>
            </div>

            <input
              type="range"
              min="15"
              max="75"
              step="1"
              value={fov}
              onChange={(e) => onFovChange(parseInt(e.target.value, 10))}
              className="w-full h-2 bg-slate-800 rounded-lg appearance-none cursor-pointer accent-cyan-400"
            />

            <div className="flex justify-between text-[10px] font-mono text-slate-500">
              <span>15° (Telephoto)</span>
              <span>45° (Natural)</span>
              <span>75° (Wide)</span>
            </div>
          </div>
        )}
      </div>

      {/* 2. WebGL Scissor Split-Screen Comparison Interactive On-Canvas Slider */}
      {isSplitScreen && (
        <div 
          ref={dragContainerRef}
          className="absolute inset-0 pointer-events-none z-25 flex select-none"
        >
          {/* Vertical Divider Line with Grab Handle */}
          <div 
            className="absolute top-0 bottom-0 pointer-events-auto flex items-center justify-center cursor-ew-resize"
            style={{ left: `${splitPosition * 100}%`, transform: 'translateX(-50%)' }}
            onPointerDown={(e) => {
              e.preventDefault();
              setIsDraggingSplit(true);
            }}
          >
            {/* High-visibility glowing neon divider bar */}
            <div className="w-[3px] h-full bg-cyan-400/80 shadow-[0_0_12px_rgba(6,182,212,0.8)]" />

            {/* Center Floating Handle Badge */}
            <div className="absolute w-8 h-8 rounded-full bg-slate-950 border-2 border-cyan-400 flex items-center justify-center text-cyan-300 shadow-2xl active:scale-110 transition-transform">
              <Columns className="w-4 h-4" />
            </div>

            {/* Split Comparison Badges */}
            <div className="absolute -top-12 flex items-center gap-6 px-3 py-1 rounded-full bg-slate-950/90 border border-slate-700 text-[10px] font-mono shadow-2xl">
              <span className="text-amber-300 font-bold flex items-center gap-1">
                <span>&larr;</span> 2D FLAT ORTHO
              </span>
              <span className="text-cyan-400 font-bold flex items-center gap-1">
                3D RELIEF MESH <span>&rarr;</span>
              </span>
            </div>
          </div>
        </div>
      )}
    </>
  );
};
