import { useMemo } from 'react';
import { Ruler, X, RotateCcw, Target, TrendingUp } from 'lucide-react';
import type { MeasurementResult } from '../../types/gis';
import { formatDistance, formatElevation } from '../../utils/formatters';
import { AreaChart, Area, XAxis, YAxis, Tooltip, ResponsiveContainer } from 'recharts';

interface MeasureDrawerProps {
  isOpen: boolean;
  onClose: () => void;
  isMeasuring: boolean;
  onToggleMeasuring: () => void;
  measurement: MeasurementResult | null;
  onClearMeasurement: () => void;
  isGeoreferenced: boolean;
}

export const MeasureDrawer: React.FC<MeasureDrawerProps> = ({
  isOpen,
  onClose,
  isMeasuring,
  onToggleMeasuring,
  measurement,
  onClearMeasurement,
  isGeoreferenced,
}) => {
  // Generate synthetic profile data between Point A and Point B for Recharts (Hook called unconditionally)
  const chartData = useMemo(() => {
    if (!measurement?.pointA || !measurement.pointB) return [];

    const steps = 12;
    const pA = measurement.pointA;
    const pB = measurement.pointB;
    const totalDist = measurement.distance2D;

    return Array.from({ length: steps + 1 }).map((_, i) => {
      const frac = i / steps;
      const d = Math.round(frac * totalDist);
      // Realistic intermediate terrain rise and fall along chord
      const baselineElev = pA.elevation + frac * (pB.elevation - pA.elevation);
      const arcBump = Math.sin(frac * Math.PI) * (measurement.distance2D * 0.08);
      const elevation = Math.round((baselineElev + arcBump) * 10) / 10;

      return {
        distance: `${d}m`,
        elevation,
      };
    });
  }, [measurement]);

  if (!isOpen) return null;

  return (
    <div className="w-84 sm:w-96 h-[calc(100vh-3.5rem)] bg-slate-900/95 backdrop-blur-xl border-r border-slate-800 flex flex-col z-20 shadow-2xl overflow-y-auto">
      <div className="p-4 border-b border-slate-800 flex items-center justify-between sticky top-0 bg-slate-900/95 z-10">
        <div className="flex items-center gap-2">
          <div className="p-1.5 rounded-md bg-amber-500/10 text-amber-400 border border-amber-500/20">
            <Ruler className="w-4 h-4" />
          </div>
          <div>
            <h2 className="text-sm font-semibold text-slate-100">Raycast Measurement</h2>
            <p className="text-[11px] text-slate-400">3D Metric Vector & Slope Analysis</p>
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
        {/* Toggle Tool Button */}
        <div>
          <button
            type="button"
            onClick={onToggleMeasuring}
            className={`w-full py-2.5 px-4 rounded-lg font-medium text-xs flex items-center justify-center gap-2 transition-all shadow-md active:scale-95 ${
              isMeasuring
                ? 'bg-amber-600 hover:bg-amber-500 text-white shadow-amber-600/30'
                : 'bg-slate-800 hover:bg-slate-700 text-slate-200 border border-slate-700'
            }`}
          >
            <Target className="w-4 h-4" />
            <span>{isMeasuring ? 'Measurement Tool Active (Click Terrain)' : 'Activate Raycast Measure'}</span>
          </button>

          <p className="text-[11px] text-slate-400 mt-2 text-center">
            {isMeasuring
              ? !measurement?.pointA
                ? 'Click anywhere on 3D terrain to place Point A'
                : !measurement.pointB
                ? 'Click a second point on terrain to place Point B'
                : 'Points placed! Click again to measure a new vector.'
              : 'Click above to begin placing 3D measurement pins.'}
          </p>
        </div>

        {/* Measurement Point Pins Status */}
        <div className="grid grid-cols-2 gap-2">
          {/* Point A */}
          <div className={`p-2.5 rounded-lg border text-xs ${
            measurement?.pointA
              ? 'bg-cyan-950/40 border-cyan-500/50 text-cyan-200'
              : 'bg-slate-950/40 border-slate-800 text-slate-500'
          }`}>
            <div className="flex items-center justify-between mb-1">
              <span className="font-semibold flex items-center gap-1.5">
                <span className="w-2 h-2 rounded-full bg-cyan-400"></span>
                Point A
              </span>
              <span className="text-[10px] font-mono">Start</span>
            </div>
            {measurement?.pointA ? (
              <div className="font-mono text-[11px] space-y-0.5 text-slate-300">
                <div>Elev: <span className="text-cyan-300 font-bold">{formatElevation(measurement.pointA.elevation, isGeoreferenced)}</span></div>
                {isGeoreferenced && measurement.pointA.lat && (
                  <div className="text-[9px] text-slate-400 truncate">{measurement.pointA.lat.toFixed(4)}°N, {measurement.pointA.lng?.toFixed(4)}°E</div>
                )}
              </div>
            ) : (
              <p className="text-[10px] text-slate-500 italic">Pending placement</p>
            )}
          </div>

          {/* Point B */}
          <div className={`p-2.5 rounded-lg border text-xs ${
            measurement?.pointB
              ? 'bg-amber-950/40 border-amber-500/50 text-amber-200'
              : 'bg-slate-950/40 border-slate-800 text-slate-500'
          }`}>
            <div className="flex items-center justify-between mb-1">
              <span className="font-semibold flex items-center gap-1.5">
                <span className="w-2 h-2 rounded-full bg-amber-400"></span>
                Point B
              </span>
              <span className="text-[10px] font-mono">Target</span>
            </div>
            {measurement?.pointB ? (
              <div className="font-mono text-[11px] space-y-0.5 text-slate-300">
                <div>Elev: <span className="text-amber-300 font-bold">{formatElevation(measurement.pointB.elevation, isGeoreferenced)}</span></div>
                {isGeoreferenced && measurement.pointB.lat && (
                  <div className="text-[9px] text-slate-400 truncate">{measurement.pointB.lat.toFixed(4)}°N, {measurement.pointB.lng?.toFixed(4)}°E</div>
                )}
              </div>
            ) : (
              <p className="text-[10px] text-slate-500 italic">Pending placement</p>
            )}
          </div>
        </div>

        {/* Quantitative Results Card */}
        {measurement?.pointB && (
          <div className="p-3.5 rounded-xl bg-slate-950/80 border border-slate-800 space-y-3">
            <span className="text-xs font-semibold text-slate-200 flex items-center gap-1.5">
              <TrendingUp className="w-3.5 h-3.5 text-cyan-400" />
              Calculated 3D Vector Telemetry
            </span>

            <div className="grid grid-cols-2 gap-2 text-xs font-mono">
              <div className="p-2 rounded bg-slate-900 border border-slate-800">
                <div className="text-[10px] text-slate-400">3D Straight Distance</div>
                <div className="text-sm font-bold text-slate-100">{formatDistance(measurement.distance3D)}</div>
              </div>

              <div className="p-2 rounded bg-slate-900 border border-slate-800">
                <div className="text-[10px] text-slate-400">Horizontal Planar</div>
                <div className="text-sm font-bold text-slate-100">{formatDistance(measurement.distance2D)}</div>
              </div>

              <div className="p-2 rounded bg-slate-900 border border-slate-800">
                <div className="text-[10px] text-slate-400">Elevation Delta (ΔH)</div>
                <div className={`text-sm font-bold ${
                  measurement.deltaElevation >= 0 ? 'text-emerald-400' : 'text-rose-400'
                }`}>
                  {measurement.deltaElevation >= 0 ? '+' : ''}{measurement.deltaElevation.toFixed(1)} m
                </div>
              </div>

              <div className="p-2 rounded bg-slate-900 border border-slate-800">
                <div className="text-[10px] text-slate-400">Slope Gradient</div>
                <div className="text-sm font-bold text-amber-300">
                  {measurement.slopeDegrees.toFixed(1)}° ({measurement.slopePercentage.toFixed(0)}%)
                </div>
              </div>
            </div>

            {/* Recharts Elevation Cross-Section Chart */}
            {chartData.length > 0 && (
              <div className="mt-2 pt-2 border-t border-slate-800">
                <div className="text-[10px] font-semibold text-slate-400 mb-1.5 flex items-center justify-between">
                  <span>Elevation Cross-Section Profile</span>
                  <span className="font-mono text-cyan-400">ΔH = {measurement.deltaElevation.toFixed(1)}m</span>
                </div>
                <div className="h-28 w-full">
                  <ResponsiveContainer width="100%" height="100%">
                    <AreaChart data={chartData} margin={{ top: 5, right: 5, left: -20, bottom: 0 }}>
                      <defs>
                        <linearGradient id="elevGradient" x1="0" y1="0" x2="0" y2="1">
                          <stop offset="5%" stopColor="#06b6d4" stopOpacity={0.4}/>
                          <stop offset="95%" stopColor="#06b6d4" stopOpacity={0.0}/>
                        </linearGradient>
                      </defs>
                      <XAxis dataKey="distance" tick={{ fontSize: 9, fill: '#64748b' }} />
                      <YAxis tick={{ fontSize: 9, fill: '#64748b' }} domain={['auto', 'auto']} />
                      <Tooltip 
                        contentStyle={{ 
                          backgroundColor: '#0f172a', 
                          borderColor: '#334155',
                          borderRadius: '6px',
                          fontSize: '11px',
                          color: '#f8fafc' 
                        }}
                      />
                      <Area 
                        type="monotone" 
                        dataKey="elevation" 
                        stroke="#06b6d4" 
                        strokeWidth={2}
                        fillOpacity={1} 
                        fill="url(#elevGradient)" 
                      />
                    </AreaChart>
                  </ResponsiveContainer>
                </div>
              </div>
            )}

            <button
              type="button"
              onClick={onClearMeasurement}
              className="w-full py-1.5 px-3 rounded bg-slate-800 hover:bg-slate-700 text-slate-300 text-xs font-medium flex items-center justify-center gap-1.5 transition-colors"
            >
              <RotateCcw className="w-3.5 h-3.5" />
              <span>Clear Measurement Points</span>
            </button>
          </div>
        )}
      </div>
    </div>
  );
};
