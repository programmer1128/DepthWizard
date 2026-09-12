'use client';

import React from 'react';
import CompassWidget from './CompassWidget.js';

/**
 * TopNavDock - Top Viewport Floating Navigation Dock
 *
 * Houses the Compass Widget on the far left, directly adjacent to the view snapping buttons.
 *
 * @param {Object} props
 * @param {number} props.heading - Camera heading in degrees (0-359)
 * @param {Function} props.onResetNorth - Handler to reset azimuth to True North
 * @param {Function} props.onSnapView - Handler to snap camera: (viewType) => void
 * @param {string} [props.className='']
 */
export default function TopNavDock({
  heading = 0,
  onResetNorth,
  onSnapView,
  className = ''
}) {
  return (
    <div
      className={`fixed top-16 left-20 z-30 flex items-center gap-1.5 p-1 rounded-2xl bg-[#0a1224]/85 backdrop-blur-md border border-slate-700/60 shadow-2xl select-none ${className}`}
      role="toolbar"
      aria-label="Viewport Navigation and View Snapping Controls"
    >
      {/* 1. Compass Widget (Far Left) */}
      <CompassWidget
        heading={heading}
        onResetNorth={onResetNorth}
      />

      {/* Subtle Vertical Divider */}
      <div className="h-7 w-px bg-slate-700/60 mx-0.5" />

      {/* 2. View Snapping Buttons Group */}
      <div className="flex items-center gap-1">
        {/* Top (Plan) View Snapping Button */}
        <button
          onClick={() => onSnapView && onSnapView('top')}
          className="h-11 px-2.5 rounded-xl bg-slate-900/60 hover:bg-slate-800 border border-slate-800 hover:border-cyan-500/40 text-slate-300 hover:text-cyan-300 transition-all flex flex-col items-center justify-center gap-0.5 min-w-[42px] group"
          title="Snap to Top / Plan View (90° Down)"
        >
          <span className="text-xs font-mono font-bold text-slate-400 group-hover:text-cyan-400">
            ⬇
          </span>
          <span className="text-[9px] font-mono tracking-tight font-semibold">
            TOP
          </span>
        </button>

        {/* 3D Perspective Snapping Button */}
        <button
          onClick={() => onSnapView && onSnapView('perspective')}
          className="h-11 px-2.5 rounded-xl bg-slate-900/60 hover:bg-slate-800 border border-slate-800 hover:border-cyan-500/40 text-slate-300 hover:text-cyan-300 transition-all flex flex-col items-center justify-center gap-0.5 min-w-[42px] group"
          title="Snap to 3D Isometric / Oblique Perspective"
        >
          <span className="text-xs font-mono font-bold text-slate-400 group-hover:text-cyan-400">
            ⬡
          </span>
          <span className="text-[9px] font-mono tracking-tight font-semibold">
            3D
          </span>
        </button>

        {/* Front Elevation (North-Facing) Snapping Button */}
        <button
          onClick={() => onSnapView && onSnapView('front')}
          className="h-11 px-2.5 rounded-xl bg-slate-900/60 hover:bg-slate-800 border border-slate-800 hover:border-cyan-500/40 text-slate-300 hover:text-cyan-300 transition-all flex flex-col items-center justify-center gap-0.5 min-w-[42px] group"
          title="Snap to Front Elevation View (Looking North)"
        >
          <span className="text-xs font-mono font-bold text-slate-400 group-hover:text-cyan-400">
            ⬆
          </span>
          <span className="text-[9px] font-mono tracking-tight font-semibold">
            FRONT
          </span>
        </button>

        {/* East Elevation Snapping Button */}
        <button
          onClick={() => onSnapView && onSnapView('right')}
          className="h-11 px-2.5 rounded-xl bg-slate-900/60 hover:bg-slate-800 border border-slate-800 hover:border-cyan-500/40 text-slate-300 hover:text-cyan-300 transition-all flex flex-col items-center justify-center gap-0.5 min-w-[42px] group"
          title="Snap to East Elevation View (Looking West)"
        >
          <span className="text-xs font-mono font-bold text-slate-400 group-hover:text-cyan-400">
            ➡
          </span>
          <span className="text-[9px] font-mono tracking-tight font-semibold">
            EAST
          </span>
        </button>

        {/* Reset Default View Snapping Button */}
        <button
          onClick={() => onSnapView && onSnapView('reset')}
          className="h-11 px-2 rounded-xl bg-slate-900/60 hover:bg-slate-800 border border-slate-800 hover:border-amber-500/40 text-slate-300 hover:text-amber-300 transition-all flex flex-col items-center justify-center gap-0.5 min-w-[36px] group"
          title="Reset Camera Framing"
        >
          <span className="text-xs font-mono font-bold text-slate-400 group-hover:text-amber-400">
            ↺
          </span>
          <span className="text-[9px] font-mono tracking-tight font-semibold">
            RESET
          </span>
        </button>
      </div>
    </div>
  );
}
