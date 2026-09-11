import React from 'react';
import { 
  FolderDown, 
  Palette, 
  Compass, 
  Activity,
  Ruler, 
  SunMedium, 
  Settings2,
  ChevronRight
} from 'lucide-react';
import type { ActiveDrawer } from '../../types/gis';

interface SlimToolbarProps {
  activeDrawer: ActiveDrawer;
  onSelectDrawer: (drawer: ActiveDrawer) => void;
  isMeasuring: boolean;
}

interface ToolItem {
  id: NonNullable<ActiveDrawer>;
  label: string;
  sublabel: string;
  icon: React.ElementType;
}

const TOOLS: ToolItem[] = [
  {
    id: 'ingest',
    label: 'Data Ingest',
    sublabel: 'Import GeoTIFF / Drone Imagery',
    icon: FolderDown,
  },
  {
    id: 'shading',
    label: 'Shading & Materials',
    sublabel: 'RGB, Turbo Heatmap, Slope, Wireframe',
    icon: Palette,
  },
  {
    id: 'tour',
    label: 'Drone Flight Tour',
    sublabel: 'Waypoints & WASD Aerial Cockpit',
    icon: Compass,
  },
  {
    id: 'accuracy',
    label: 'Accuracy & Transect',
    sublabel: 'RMSE, MAE & 100-Point LiDAR Profile',
    icon: Activity,
  },
  {
    id: 'measure',
    label: 'Raycast Measure',
    sublabel: '3D Distance, Slope & Elevation Delta',
    icon: Ruler,
  },
  {
    id: 'lighting',
    label: 'Sun & Lighting',
    sublabel: 'Solar Azimuth, Zenith & Shadows',
    icon: SunMedium,
  },
  {
    id: 'settings',
    label: 'Studio Settings',
    sublabel: 'Rendering Quality & Coordinate Systems',
    icon: Settings2,
  }
];

export const SlimToolbar: React.FC<SlimToolbarProps> = ({
  activeDrawer,
  onSelectDrawer,
  isMeasuring,
}) => {
  return (
    <aside className="w-14 h-[calc(100vh-3.5rem)] bg-slate-900/95 border-r border-slate-800/80 flex flex-col items-center py-3 z-20 select-none shadow-xl">
      <div className="flex-1 flex flex-col items-center gap-2.5 w-full">
        {TOOLS.map((tool) => {
          const Icon = tool.icon;
          const isActive = activeDrawer === tool.id;
          const isToolActiveExtra = tool.id === 'measure' && isMeasuring;

          return (
            <div key={tool.id} className="relative group flex items-center justify-center w-full">
              <button
                type="button"
                onClick={() => onSelectDrawer(isActive ? null : tool.id)}
                className={`w-10 h-10 rounded-lg flex items-center justify-center transition-all duration-150 relative ${
                  isActive
                    ? 'bg-cyan-500/20 text-cyan-300 border border-cyan-500/50 shadow-md shadow-cyan-500/20'
                    : isToolActiveExtra
                    ? 'bg-amber-500/20 text-amber-300 border border-amber-500/50 animate-pulse'
                    : 'text-slate-400 hover:text-slate-100 hover:bg-slate-800/80'
                }`}
                aria-label={tool.label}
              >
                <Icon className="w-5 h-5" />

                {/* Active Indicator bar */}
                {isActive && (
                  <span className="absolute left-0 top-1.5 bottom-1.5 w-1 bg-cyan-400 rounded-r shadow-glow"></span>
                )}
                
                {isToolActiveExtra && !isActive && (
                  <span className="absolute -top-0.5 -right-0.5 w-2 h-2 rounded-full bg-amber-400"></span>
                )}
              </button>

              {/* Tooltip on Hover */}
              <div className="absolute left-14 ml-2 px-3 py-1.5 rounded-md bg-slate-900 border border-slate-700 text-slate-100 text-xs shadow-xl pointer-events-none opacity-0 group-hover:opacity-100 transition-opacity duration-150 whitespace-nowrap z-50 flex items-center gap-1.5">
                <span className="font-semibold">{tool.label}</span>
                <span className="text-[10px] text-slate-400 font-mono">— {tool.sublabel}</span>
                <ChevronRight className="w-3 h-3 text-slate-500" />
              </div>
            </div>
          );
        })}
      </div>

      {/* Bottom GIS Coordinate Datum Badge */}
      <div className="w-10 h-10 rounded-lg border border-slate-800 bg-slate-950/60 flex items-center justify-center text-[10px] font-mono text-slate-500 hover:text-slate-300 cursor-help" title="GIS Reference Engine: WGS84 / EGM96">
        GIS
      </div>
    </aside>
  );
};
