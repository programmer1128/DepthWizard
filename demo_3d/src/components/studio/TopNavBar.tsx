import React from 'react';
import { 
  Camera, 
  Play, 
  Pause, 
  ExternalLink, 
  Maximize, 
  Minimize, 
  Layers,
  Globe,
  Compass
} from 'lucide-react';
import type { DatasetMode, PipelineStage } from '../../types/gis';

interface TopNavBarProps {
  mode: DatasetMode;
  pipelineStage: PipelineStage;
  isTourPlaying: boolean;
  onToggleTour: () => void;
  onSnapshot: () => void;
  isFullscreen: boolean;
  onToggleFullscreen: () => void;
  onStandaloneOpen: () => void;
}

export const TopNavBar: React.FC<TopNavBarProps> = ({
  mode,
  pipelineStage,
  isTourPlaying,
  onToggleTour,
  onSnapshot,
  isFullscreen,
  onToggleFullscreen,
  onStandaloneOpen,
}) => {
  const isGeoreferenced = mode === 'georeferenced';

  // Determine operational state badge
  const getOperationalBadge = () => {
    switch (pipelineStage) {
      case 'idle':
        return (
          <div className="flex items-center gap-1.5 px-2.5 py-1 rounded-full bg-emerald-500/10 border border-emerald-500/30 text-emerald-400 text-xs font-medium">
            <span className="w-2 h-2 rounded-full bg-emerald-500"></span>
            <span>Ready</span>
          </div>
        );
      case 'streaming':
        return (
          <div className="flex items-center gap-1.5 px-2.5 py-1 rounded-full bg-emerald-500/10 border border-emerald-500/30 text-emerald-400 text-xs font-medium">
            <span className="relative flex h-2 w-2">
              <span className="animate-ping absolute inline-flex h-full w-full rounded-full bg-emerald-400 opacity-75"></span>
              <span className="relative inline-flex rounded-full h-2 w-2 bg-emerald-500"></span>
            </span>
            <span>Streaming Active</span>
          </div>
        );
      default:
        return (
          <div className="flex items-center gap-1.5 px-2.5 py-1 rounded-full bg-cyan-500/10 border border-cyan-500/30 text-cyan-400 text-xs font-medium">
            <span className="w-2 h-2 rounded-full bg-cyan-400 animate-pulse"></span>
            <span className="capitalize">Pipeline: {pipelineStage.replace('_', ' ')}</span>
          </div>
        );
    }
  };

  return (
    <header className="h-14 w-full bg-slate-900/95 backdrop-blur-md border-b border-slate-800/80 px-4 flex items-center justify-between z-30 select-none shadow-lg">
      {/* Left: Clean text branding & Operational State Badge */}
      <div className="flex items-center gap-3 min-w-[260px]">
        <div className="flex items-center gap-2.5 group cursor-pointer">
          <div className="w-8 h-8 rounded-lg bg-gradient-to-br from-cyan-500 via-indigo-600 to-emerald-500 p-0.5 shadow-md shadow-cyan-500/20 group-hover:scale-105 transition-transform duration-200">
            <div className="w-full h-full bg-slate-950 rounded-[6px] flex items-center justify-center">
              <Layers className="w-4 h-4 text-cyan-400" />
            </div>
          </div>
          <div className="flex items-baseline gap-1.5">
            <span className="font-bold text-base tracking-tight text-white">
              DepthWizard 3D
            </span>
            <span className="text-[10px] text-cyan-400 font-mono font-medium">
              STUDIO
            </span>
          </div>
        </div>

        <div className="h-4 w-[1px] bg-slate-800 mx-1 hidden sm:block" />

        <div className="hidden sm:flex">
          {getOperationalBadge()}
        </div>
      </div>

      {/* Center: Mode Indicator fixed to Georeferenced (Absolute Metric DSM) with fallback */}
      <div className="flex items-center gap-2 px-3 py-1.5 rounded-lg bg-slate-950/80 border border-slate-800 shadow-inner">
        {isGeoreferenced ? (
          <Globe className="w-3.5 h-3.5 text-cyan-400 shrink-0" />
        ) : (
          <Compass className="w-3.5 h-3.5 text-amber-400 shrink-0" />
        )}
        <span className="text-xs font-semibold text-slate-200 tracking-tight">
          {isGeoreferenced
            ? 'Georeferenced (Absolute Metric DSM)'
            : 'Non-Georeferenced (Relative rDSM Fallback)'}
        </span>
      </div>

      {/* Right: Action Buttons */}
      <div className="flex items-center gap-2">
        {/* Snapshot / HD Render */}
        <button
          type="button"
          onClick={onSnapshot}
          className="flex items-center gap-1.5 px-3 py-1.5 rounded-md bg-slate-800/90 hover:bg-slate-700 text-slate-200 hover:text-white border border-slate-700/80 text-xs font-medium transition-all duration-150 shadow-sm active:scale-95"
          title="Capture High-Resolution Viewport Render"
        >
          <Camera className="w-3.5 h-3.5 text-cyan-400" />
          <span className="hidden md:inline">Snapshot / HD Render</span>
        </button>

        {/* Cinematic Tour Toggle */}
        <button
          type="button"
          onClick={onToggleTour}
          className={`flex items-center gap-1.5 px-3 py-1.5 rounded-md border text-xs font-medium transition-all duration-150 active:scale-95 ${
            isTourPlaying
              ? 'bg-emerald-600 text-white border-emerald-500 shadow-md shadow-emerald-600/30'
              : 'bg-slate-800/90 hover:bg-slate-700 text-slate-200 hover:text-white border-slate-700/80'
          }`}
          title="Toggle Cinematic Flight Tour"
        >
          {isTourPlaying ? (
            <>
              <Pause className="w-3.5 h-3.5 text-white" />
              <span>Tour Playing</span>
            </>
          ) : (
            <>
              <Play className="w-3.5 h-3.5 text-emerald-400" />
              <span className="hidden sm:inline">Cinematic Tour</span>
            </>
          )}
        </button>

        {/* Standalone ↗ */}
        <button
          type="button"
          onClick={onStandaloneOpen}
          className="flex items-center gap-1.5 px-3 py-1.5 rounded-md bg-slate-800/90 hover:bg-slate-700 text-slate-200 hover:text-white border border-slate-700/80 text-xs font-medium shadow-sm transition-all duration-150 active:scale-95"
          title="Open Standalone Viewport"
        >
          <span>Standalone</span>
          <ExternalLink className="w-3.5 h-3.5 text-cyan-400" />
        </button>

        {/* Fullscreen Toggle */}
        <button
          type="button"
          onClick={onToggleFullscreen}
          className="p-2 rounded-md bg-slate-800/80 hover:bg-slate-700 text-slate-300 hover:text-white border border-slate-700/70 transition-colors"
          title={isFullscreen ? 'Exit Fullscreen' : 'Enter Fullscreen'}
        >
          {isFullscreen ? <Minimize className="w-4 h-4" /> : <Maximize className="w-4 h-4" />}
        </button>
      </div>
    </header>
  );
};
