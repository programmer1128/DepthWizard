'use client';

import React from 'react';
import type { ModelStats as ModelStatsType } from '@/types/unity';

interface ModelStatsProps {
  stats: ModelStatsType | null;
  isLoading: boolean;
  stage: string;
  progress: number;
}

export const ModelStats: React.FC<ModelStatsProps> = ({
  stats,
  isLoading,
  stage,
  progress
}) => {
  return (
    <div className="rounded-2xl bg-slate-900/80 border border-slate-800/80 p-4 shadow-xl backdrop-blur-sm">
      <div className="flex items-center justify-between mb-3">
        <h3 className="text-xs font-semibold uppercase tracking-wider text-slate-400 flex items-center gap-1.5">
          <svg className="w-4 h-4 text-indigo-400" viewBox="0 0 24 24" fill="none" stroke="currentColor">
            <path strokeLinecap="round" strokeLinejoin="round" strokeWidth="2" d="M9 19v-6a2 2 0 00-2-2H5a2 2 0 00-2 2v6a2 2 0 002 2h2a2 2 0 002-2zm0 0V9a2 2 0 012-2h2a2 2 0 012 2v10m-6 0a2 2 0 002 2h2a2 2 0 002-2m0 0V5a2 2 0 012-2h2a2 2 0 012 2v14a2 2 0 01-2 2h-2a2 2 0 01-2-2z" />
          </svg>
          <span>Model Telemetry</span>
        </h3>
        {isLoading && (
          <span className="text-[11px] text-amber-400 font-mono animate-pulse">
            {stage} ({Math.round(progress * 100)}%)
          </span>
        )}
      </div>

      {stats ? (
        <div className="space-y-3">
          <div className="flex items-center justify-between pb-2 border-b border-slate-800/60">
            <span className="text-xs text-slate-400">Model Name</span>
            <span className="text-xs font-mono font-medium text-white truncate max-w-[160px]" title={stats.name}>
              {stats.name}
            </span>
          </div>

          <div className="grid grid-cols-2 gap-2.5">
            <div className="p-2.5 rounded-xl bg-slate-950/60 border border-slate-800/50">
              <span className="text-[10px] uppercase font-semibold text-slate-400">Vertices</span>
              <p className="text-base font-bold font-mono text-cyan-400">
                {stats.vertexCount.toLocaleString()}
              </p>
            </div>

            <div className="p-2.5 rounded-xl bg-slate-950/60 border border-slate-800/50">
              <span className="text-[10px] uppercase font-semibold text-slate-400">Triangles</span>
              <p className="text-base font-bold font-mono text-indigo-400">
                {stats.triangleCount.toLocaleString()}
              </p>
            </div>

            <div className="p-2.5 rounded-xl bg-slate-950/60 border border-slate-800/50">
              <span className="text-[10px] uppercase font-semibold text-slate-400">Submeshes</span>
              <p className="text-base font-bold font-mono text-violet-400">
                {stats.meshCount}
              </p>
            </div>

            <div className="p-2.5 rounded-xl bg-slate-950/60 border border-slate-800/50">
              <span className="text-[10px] uppercase font-semibold text-slate-400">Load Time</span>
              <p className="text-base font-bold font-mono text-emerald-400">
                {Math.round(stats.loadTimeMs)} ms
              </p>
            </div>
          </div>

          {stats.boundsSizeX !== undefined && (
            <div className="pt-1 text-[11px] text-slate-400 flex justify-between font-mono">
              <span>Bounding Box:</span>
              <span className="text-slate-300">
                {stats.boundsSizeX.toFixed(2)} × {stats.boundsSizeY?.toFixed(2)} × {stats.boundsSizeZ?.toFixed(2)}m
              </span>
            </div>
          )}
        </div>
      ) : (
        <div className="py-6 text-center text-xs text-slate-500">
          {isLoading ? (
            <div className="flex flex-col items-center gap-2">
              <div className="w-5 h-5 border-2 border-indigo-500/30 border-t-indigo-500 rounded-full animate-spin" />
              <span>Receiving model geometry from Unity...</span>
            </div>
          ) : (
            'No model currently loaded'
          )}
        </div>
      )}
    </div>
  );
};
