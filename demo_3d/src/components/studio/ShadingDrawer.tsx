import React from 'react';
import { Palette, X, Check } from 'lucide-react';
import type { ShadingMode } from '../../types/gis';

interface ShadingDrawerProps {
  isOpen: boolean;
  onClose: () => void;
  shadingMode: ShadingMode;
  onShadingModeChange: (mode: ShadingMode) => void;
}

export const ShadingDrawer: React.FC<ShadingDrawerProps> = ({
  isOpen,
  onClose,
  shadingMode,
  onShadingModeChange,
}) => {
  if (!isOpen) return null;

  const SHADING_OPTIONS: { id: ShadingMode; name: string; desc: string; preview: string }[] = [
    {
      id: 'rgb',
      name: 'Photorealistic Optical',
      desc: 'True RGB reflectance map projected onto high-resolution terrain.',
      preview: 'from-emerald-600 via-stone-600 to-amber-700'
    },
    {
      id: 'hypsometric',
      name: 'Elevation Heatmap (Turbo/Jet)',
      desc: 'Hypsometric color-coding across metric sea-level elevation bounds.',
      preview: 'from-blue-600 via-emerald-500 to-red-500'
    },
    {
      id: 'slope',
      name: 'Slope Gradient (0° – 60°)',
      desc: 'Hazard & terrain slope analysis derived from surface normals.',
      preview: 'from-emerald-500 via-yellow-400 to-rose-600'
    },
    {
      id: 'wireframe',
      name: 'GIS Vector Wireframe',
      desc: 'Triangulated irregular mesh network for topology analysis.',
      preview: 'from-slate-900 via-emerald-950 to-cyan-950 border border-emerald-500/50'
    }
  ];

  return (
    <div 
      className="w-84 sm:w-96 h-[calc(100vh-3.5rem)] bg-slate-900/95 backdrop-blur-xl border-r border-slate-800 flex flex-col z-20 shadow-2xl overflow-y-auto select-none"
      aria-label="Shading and Materials Panel"
    >
      <div className="p-4 border-b border-slate-800 flex items-center justify-between sticky top-0 bg-slate-900/95 z-10 backdrop-blur-md">
        <div className="flex items-center gap-2">
          <div className="p-1.5 rounded-md bg-cyan-500/10 text-cyan-400 border border-cyan-500/20">
            <Palette className="w-4 h-4" />
          </div>
          <div>
            <h2 className="text-sm font-semibold text-slate-100">Shading &amp; Materials</h2>
            <p className="text-[11px] text-slate-400">Radiance &amp; Surface Classifiers</p>
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

      <div className="p-4 space-y-4 flex-1">
        <div>
          <label className="text-xs font-medium text-slate-300 mb-3 block">Surface Shading Pipeline</label>
          <div className="space-y-2.5">
            {SHADING_OPTIONS.map((item) => (
              <button
                key={item.id}
                type="button"
                onClick={() => onShadingModeChange(item.id)}
                className={`w-full text-left p-3 rounded-xl border flex items-start gap-3 transition-all ${
                  shadingMode === item.id
                    ? 'bg-cyan-950/40 border-cyan-500/60 shadow-md shadow-cyan-500/10'
                    : 'bg-slate-950/40 border-slate-800 hover:border-slate-700 hover:bg-slate-950'
                }`}
              >
                <div className={`w-8 h-8 rounded-lg bg-gradient-to-br ${item.preview} shrink-0 shadow-inner mt-0.5`} />
                <div className="flex-1 min-w-0">
                  <div className="flex items-center justify-between mb-0.5">
                    <span className="text-xs font-semibold text-slate-100">{item.name}</span>
                    <span className="text-[10px] font-mono text-slate-500 uppercase">{item.id}</span>
                  </div>
                  <p className="text-[11px] text-slate-400 leading-relaxed">{item.desc}</p>
                </div>
                {shadingMode === item.id && (
                  <Check className="w-4 h-4 text-cyan-400 shrink-0 mt-0.5" />
                )}
              </button>
            ))}
          </div>
        </div>
      </div>
    </div>
  );
};
