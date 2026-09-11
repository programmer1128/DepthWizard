import React from 'react';
import { SunMedium, X, Compass, Sunset, Sun, CloudSun } from 'lucide-react';
import type { SunLightingConfig } from '../../types/gis';

interface SunLightingDrawerProps {
  isOpen: boolean;
  onClose: () => void;
  config: SunLightingConfig;
  onChange: (config: SunLightingConfig) => void;
}

export const SunLightingDrawer: React.FC<SunLightingDrawerProps> = ({
  isOpen,
  onClose,
  config,
  onChange,
}) => {
  if (!isOpen) return null;

  const handlePreset = (azimuth: number, elevation: number, intensity: number, ambient: number) => {
    onChange({
      ...config,
      azimuth,
      elevation,
      intensity,
      ambientIntensity: ambient
    });
  };

  return (
    <div className="w-84 sm:w-96 h-[calc(100vh-3.5rem)] bg-slate-900/95 backdrop-blur-xl border-r border-slate-800 flex flex-col z-20 shadow-2xl overflow-y-auto">
      <div className="p-4 border-b border-slate-800 flex items-center justify-between sticky top-0 bg-slate-900/95 z-10">
        <div className="flex items-center gap-2">
          <div className="p-1.5 rounded-md bg-amber-500/10 text-amber-400 border border-amber-500/20">
            <SunMedium className="w-4 h-4" />
          </div>
          <div>
            <h2 className="text-sm font-semibold text-slate-100">Sun & Lighting Engine</h2>
            <p className="text-[11px] text-slate-400">Ephemeris Solar Vector & Shadows</p>
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
        {/* Quick Solar Presets */}
        <div>
          <label className="text-xs font-medium text-slate-300 mb-2 block">Solar Lighting Presets</label>
          <div className="grid grid-cols-2 gap-2">
            <button
              type="button"
              onClick={() => handlePreset(65, 18, 1.3, 0.45)}
              className="p-2.5 rounded-lg border border-slate-800 bg-slate-950/60 hover:bg-slate-800 text-left text-xs transition-colors"
            >
              <div className="flex items-center gap-1.5 font-semibold text-amber-300 mb-0.5">
                <Sunset className="w-3.5 h-3.5" />
                <span>Golden Hour</span>
              </div>
              <p className="text-[10px] text-slate-400">Az 65°, Alt 18°</p>
            </button>

            <button
              type="button"
              onClick={() => handlePreset(180, 72, 1.6, 0.6)}
              className="p-2.5 rounded-lg border border-slate-800 bg-slate-950/60 hover:bg-slate-800 text-left text-xs transition-colors"
            >
              <div className="flex items-center gap-1.5 font-semibold text-cyan-300 mb-0.5">
                <Sun className="w-3.5 h-3.5" />
                <span>Solar Noon</span>
              </div>
              <p className="text-[10px] text-slate-400">Az 180°, Alt 72°</p>
            </button>

            <button
              type="button"
              onClick={() => handlePreset(250, 26, 1.4, 0.5)}
              className="p-2.5 rounded-lg border border-slate-800 bg-slate-950/60 hover:bg-slate-800 text-left text-xs transition-colors"
            >
              <div className="flex items-center gap-1.5 font-semibold text-orange-400 mb-0.5">
                <Sunset className="w-3.5 h-3.5" />
                <span>Late Afternoon</span>
              </div>
              <p className="text-[10px] text-slate-400">Az 250°, Alt 26°</p>
            </button>

            <button
              type="button"
              onClick={() => handlePreset(140, 50, 0.6, 0.85)}
              className="p-2.5 rounded-lg border border-slate-800 bg-slate-950/60 hover:bg-slate-800 text-left text-xs transition-colors"
            >
              <div className="flex items-center gap-1.5 font-semibold text-slate-300 mb-0.5">
                <CloudSun className="w-3.5 h-3.5" />
                <span>Overcast Diffuse</span>
              </div>
              <p className="text-[10px] text-slate-400">Low shadow contrast</p>
            </button>
          </div>
        </div>

        {/* Sun Azimuth Slider */}
        <div className="p-3.5 rounded-xl bg-slate-950/60 border border-slate-800">
          <div className="flex items-center justify-between mb-2">
            <label className="text-xs font-medium text-slate-300 flex items-center gap-1.5">
              <Compass className="w-3.5 h-3.5 text-cyan-400" />
              Sun Azimuth (Angle)
            </label>
            <span className="text-xs font-mono font-bold text-cyan-300 px-2 py-0.5 rounded bg-slate-900 border border-slate-700">
              {config.azimuth}°
            </span>
          </div>

          <input
            type="range"
            min="0"
            max="360"
            step="1"
            value={config.azimuth}
            onChange={(e) => onChange({ ...config, azimuth: parseInt(e.target.value, 10) })}
            className="w-full h-1.5 bg-slate-800 rounded-lg appearance-none cursor-pointer accent-cyan-400"
          />

          <div className="flex justify-between text-[10px] font-mono text-slate-500 mt-1">
            <span>0° (N)</span>
            <span>90° (E)</span>
            <span>180° (S)</span>
            <span>270° (W)</span>
            <span>360°</span>
          </div>
        </div>

        {/* Sun Elevation / Zenith Slider */}
        <div className="p-3.5 rounded-xl bg-slate-950/60 border border-slate-800">
          <div className="flex items-center justify-between mb-2">
            <label className="text-xs font-medium text-slate-300 flex items-center gap-1.5">
              <SunMedium className="w-3.5 h-3.5 text-amber-400" />
              Solar Elevation (Altitude)
            </label>
            <span className="text-xs font-mono font-bold text-amber-300 px-2 py-0.5 rounded bg-slate-900 border border-slate-700">
              {config.elevation}°
            </span>
          </div>

          <input
            type="range"
            min="5"
            max="90"
            step="1"
            value={config.elevation}
            onChange={(e) => onChange({ ...config, elevation: parseInt(e.target.value, 10) })}
            className="w-full h-1.5 bg-slate-800 rounded-lg appearance-none cursor-pointer accent-amber-400"
          />

          <div className="flex justify-between text-[10px] font-mono text-slate-500 mt-1">
            <span>5° (Horizon)</span>
            <span>45° (Mid-sky)</span>
            <span>90° (Zenith)</span>
          </div>
        </div>

        {/* Sunlight Direct & Ambient Intensities */}
        <div className="p-3.5 rounded-xl bg-slate-950/60 border border-slate-800 space-y-3">
          <div>
            <div className="flex items-center justify-between mb-1.5">
              <span className="text-xs font-medium text-slate-300">Direct Beam Radiance</span>
              <span className="text-xs font-mono text-slate-300">{config.intensity.toFixed(1)}x</span>
            </div>
            <input
              type="range"
              min="0.2"
              max="2.5"
              step="0.1"
              value={config.intensity}
              onChange={(e) => onChange({ ...config, intensity: parseFloat(e.target.value) })}
              className="w-full h-1.5 bg-slate-800 rounded-lg appearance-none cursor-pointer accent-cyan-400"
            />
          </div>

          <div>
            <div className="flex items-center justify-between mb-1.5">
              <span className="text-xs font-medium text-slate-300">Atmospheric Ambient Bounce</span>
              <span className="text-xs font-mono text-slate-300">{config.ambientIntensity.toFixed(1)}x</span>
            </div>
            <input
              type="range"
              min="0.1"
              max="1.0"
              step="0.05"
              value={config.ambientIntensity}
              onChange={(e) => onChange({ ...config, ambientIntensity: parseFloat(e.target.value) })}
              className="w-full h-1.5 bg-slate-800 rounded-lg appearance-none cursor-pointer accent-cyan-400"
            />
          </div>

          <div className="flex items-center justify-between pt-2 border-t border-slate-800">
            <span className="text-xs font-medium text-slate-300">Shadow Map Projection</span>
            <input
              type="checkbox"
              checked={config.castShadows}
              onChange={(e) => onChange({ ...config, castShadows: e.target.checked })}
              className="rounded bg-slate-800 border-slate-700 text-cyan-500 focus:ring-0 cursor-pointer w-4 h-4"
            />
          </div>
        </div>
      </div>
    </div>
  );
};
