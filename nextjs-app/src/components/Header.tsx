'use client';

import React from 'react';

interface HeaderProps {
  isEngineReady: boolean;
  isModelLoading: boolean;
  currentModelName?: string;
  onOpenInstructions?: () => void;
}

export const Header: React.FC<HeaderProps> = ({
  isEngineReady,
  isModelLoading,
  currentModelName,
  onOpenInstructions
}) => {
  return (
    <header className="border-b border-slate-800/80 bg-slate-950/70 backdrop-blur-md sticky top-0 z-30 px-6 py-3.5 flex items-center justify-between">
      <div className="flex items-center gap-3.5">
        <div className="w-10 h-10 rounded-xl bg-gradient-to-tr from-cyan-500 to-indigo-600 flex items-center justify-center shadow-lg shadow-indigo-500/20 ring-1 ring-white/20">
          <svg className="w-5 h-5 text-white" viewBox="0 0 24 24" fill="none" stroke="currentColor" strokeWidth="2">
            <polygon points="12 2 2 7 12 12 22 7 12 2" />
            <polyline points="2 17 12 22 22 17" />
            <polyline points="2 12 12 17 22 12" />
          </svg>
        </div>
        <div>
          <div className="flex items-center gap-2">
            <h1 className="text-base font-bold tracking-tight text-white flex items-center gap-1.5">
              <span>Unity WebGL</span>
              <span className="text-indigo-400">×</span>
              <span className="text-cyan-400">Next.js</span>
            </h1>
            <span className="px-2 py-0.5 text-[10px] font-semibold uppercase tracking-wider rounded-full bg-indigo-500/10 text-indigo-300 border border-indigo-500/30">
              GLB Runtime
            </span>
          </div>
          <p className="text-xs text-slate-400">
            Bidirectional JavaScript ↔ Unity WebGL 3D model engine
          </p>
        </div>
      </div>

      <div className="flex items-center gap-4">
        {/* Engine Status Indicator */}
        <div className="flex items-center gap-2 px-3 py-1.5 rounded-lg bg-slate-900/90 border border-slate-800 text-xs">
          <span className="relative flex h-2.5 w-2.5">
            {isEngineReady ? (
              <>
                <span className={`animate-ping absolute inline-flex h-full w-full rounded-full opacity-75 ${isModelLoading ? 'bg-amber-400' : 'bg-emerald-400'}`} />
                <span className={`relative inline-flex rounded-full h-2.5 w-2.5 ${isModelLoading ? 'bg-amber-500' : 'bg-emerald-500'}`} />
              </>
            ) : (
              <span className="relative inline-flex rounded-full h-2.5 w-2.5 bg-slate-500 animate-pulse" />
            )}
          </span>
          <span className="text-slate-300 font-medium">
            {!isEngineReady
              ? 'Engine Initializing...'
              : isModelLoading
              ? 'Loading Model...'
              : currentModelName
              ? `Rendering: ${currentModelName}`
              : 'Engine Ready'}
          </span>
        </div>

        {/* Instructions button */}
        {onOpenInstructions && (
          <button
            onClick={onOpenInstructions}
            className="flex items-center gap-1.5 px-3 py-1.5 text-xs font-medium text-slate-300 hover:text-white bg-slate-800/80 hover:bg-slate-700/80 rounded-lg border border-slate-700/60 transition-colors"
          >
            <svg className="w-3.5 h-3.5 text-cyan-400" fill="none" viewBox="0 0 24 24" stroke="currentColor">
              <path strokeLinecap="round" strokeLinejoin="round" strokeWidth="2" d="M13 16h-1v-4h-1m1-4h.01M21 12a9 9 0 11-18 0 9 9 0 0118 0z" />
            </svg>
            <span>Run Guide</span>
          </button>
        )}
      </div>
    </header>
  );
};
