import React from 'react';
import { Settings2, X, RotateCw, MousePointer, Cpu } from 'lucide-react';
import type { TerrainMetadata } from '../../types/gis';

interface SettingsDrawerProps {
  isOpen: boolean;
  onClose: () => void;
  onResetCamera: () => void;
  metadata: TerrainMetadata;
}

export const SettingsDrawer: React.FC<SettingsDrawerProps> = ({
  isOpen,
  onClose,
  onResetCamera,
  metadata,
}) => {
  if (!isOpen) return null;

  return (
    <div className="w-84 sm:w-96 h-[calc(100vh-3.5rem)] bg-slate-900/95 backdrop-blur-xl border-r border-slate-800 flex flex-col z-20 shadow-2xl overflow-y-auto">
      <div className="p-4 border-b border-slate-800 flex items-center justify-between sticky top-0 bg-slate-900/95 z-10">
        <div className="flex items-center gap-2">
          <div className="p-1.5 rounded-md bg-purple-500/10 text-purple-400 border border-purple-500/20">
            <Settings2 className="w-4 h-4" />
          </div>
          <div>
            <h2 className="text-sm font-semibold text-slate-100">Studio Settings</h2>
            <p className="text-[11px] text-slate-400">Rendering & Navigation Controls</p>
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
        {/* Viewport Control Action */}
        <div className="space-y-2">
          <button
            type="button"
            onClick={onResetCamera}
            className="w-full py-2 px-3 rounded-lg border border-slate-700 bg-slate-800/80 hover:bg-slate-700 text-slate-200 text-xs font-medium flex items-center justify-center gap-2 transition-colors"
          >
            <RotateCw className="w-3.5 h-3.5 text-slate-400" />
            <span>Reset 3D Perspective Camera</span>
          </button>
        </div>

        {/* 3D Navigation Controls Cheatsheet */}
        <div className="p-3.5 rounded-xl bg-slate-950/70 border border-slate-800 space-y-2.5">
          <span className="text-xs font-semibold text-slate-200 flex items-center gap-1.5">
            <MousePointer className="w-3.5 h-3.5 text-cyan-400" />
            Navigation Shortcuts
          </span>

          <div className="space-y-2 text-xs">
            <div className="flex items-center justify-between">
              <span className="text-slate-400">Orbit / Rotate</span>
              <kbd className="px-2 py-0.5 rounded bg-slate-900 border border-slate-700 font-mono text-[10px] text-slate-300">Left Click + Drag</kbd>
            </div>

            <div className="flex items-center justify-between">
              <span className="text-slate-400">Pan Terrain</span>
              <kbd className="px-2 py-0.5 rounded bg-slate-900 border border-slate-700 font-mono text-[10px] text-slate-300">Right Click + Drag</kbd>
            </div>

            <div className="flex items-center justify-between">
              <span className="text-slate-400">Zoom Elevation</span>
              <kbd className="px-2 py-0.5 rounded bg-slate-900 border border-slate-700 font-mono text-[10px] text-slate-300">Scroll Wheel</kbd>
            </div>

            <div className="flex items-center justify-between">
              <span className="text-slate-400">Raycast Sample</span>
              <kbd className="px-2 py-0.5 rounded bg-slate-900 border border-slate-700 font-mono text-[10px] text-slate-300">Hover Cursor</kbd>
            </div>

            <div className="flex items-center justify-between">
              <span className="text-slate-400">Place Pins</span>
              <kbd className="px-2 py-0.5 rounded bg-slate-900 border border-slate-700 font-mono text-[10px] text-slate-300">Measure Tool Click</kbd>
            </div>
          </div>
        </div>

        {/* Active Dataset Specifications */}
        <div className="p-3.5 rounded-xl bg-slate-950/70 border border-slate-800 space-y-2.5">
          <span className="text-xs font-semibold text-slate-200 flex items-center gap-1.5">
            <Cpu className="w-3.5 h-3.5 text-indigo-400" />
            Dataset Telemetry Details
          </span>

          <div className="space-y-1.5 font-mono text-[11px] text-slate-300">
            <div className="flex justify-between">
              <span className="text-slate-400 font-sans">CRS Reference:</span>
              <span className="text-cyan-300">{metadata.crs}</span>
            </div>
            <div className="flex justify-between">
              <span className="text-slate-400 font-sans">Vertical Datum:</span>
              <span>{metadata.verticalDatum}</span>
            </div>
            <div className="flex justify-between">
              <span className="text-slate-400 font-sans">Ground Sampling:</span>
              <span>{metadata.gsd}</span>
            </div>
            <div className="flex justify-between">
              <span className="text-slate-400 font-sans">Sensor System:</span>
              <span className="text-slate-300 truncate max-w-[160px]">{metadata.sensor}</span>
            </div>
            <div className="flex justify-between">
              <span className="text-slate-400 font-sans">Timestamp:</span>
              <span className="text-slate-400">{metadata.dateCaptured}</span>
            </div>
          </div>
        </div>
      </div>
    </div>
  );
};
