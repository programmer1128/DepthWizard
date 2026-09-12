'use client';

import React from 'react';

/**
 * CompassWidget - Top Viewport Compass Widget for DepthWizard 3D
 *
 * Real-time dynamic compass indicating camera heading azimuth relative to True North.
 * Clicking resets the viewport azimuth to True North (0°) while preserving pitch and zoom.
 *
 * @param {Object} props
 * @param {number} [props.heading=0] - Current camera azimuth heading in degrees (0 - 359)
 * @param {Function} [props.onResetNorth] - Callback to smoothly reset camera to 0° North
 * @param {string} [props.className=''] - Additional optional container CSS classes
 */
export default function CompassWidget({
  heading = 0,
  onResetNorth,
  className = ''
}) {
  const normalizedHeading = Math.round(((heading % 360) + 360) % 360);

  return (
    <div
      role="button"
      tabIndex={0}
      onClick={onResetNorth}
      onKeyDown={(e) => {
        if (e.key === 'Enter' || e.key === ' ') {
          e.preventDefault();
          if (onResetNorth) onResetNorth();
        }
      }}
      title="Click to reset viewport to True North (0°)"
      aria-label={`Compass: ${normalizedHeading} degrees. Click to reset to True North`}
      className={`h-11 w-11 rounded-xl bg-[#0a1224]/80 border border-slate-700/60 p-1 flex flex-col items-center justify-center cursor-pointer hover:border-cyan-500/50 hover:bg-slate-800/80 transition-all select-none shadow-md group ${className}`}
    >
      {/* SVG Dial & Needle */}
      <div className="relative flex items-center justify-center w-6 h-6">
        <svg
          viewBox="0 0 32 32"
          className="w-full h-full transition-transform duration-75 ease-out"
          style={{ transform: `rotate(${-normalizedHeading}deg)` }}
        >
          <defs>
            {/* Subtle drop shadow filter for 3D depth */}
            <filter id="needleShadow" x="-30%" y="-30%" width="160%" height="160%">
              <feDropShadow
                dx="0"
                dy="0.8"
                stdDeviation="0.6"
                floodColor="#000000"
                floodOpacity="0.75"
              />
            </filter>
          </defs>

          {/* Circular outer border */}
          <circle
            cx="16"
            cy="16"
            r="14"
            fill="none"
            stroke="#334155"
            strokeWidth="1.2"
            strokeOpacity="0.8"
          />

          {/* Subtle dotted / tick marks for Cardinal directions */}
          {/* North Tick (Red accent) */}
          <line
            x1="16"
            y1="2"
            x2="16"
            y2="5"
            stroke="#ef4444"
            strokeWidth="1.6"
            strokeLinecap="round"
          />
          {/* East Tick */}
          <line
            x1="27"
            y1="16"
            x2="30"
            y2="16"
            stroke="#64748b"
            strokeWidth="1.2"
            strokeLinecap="round"
          />
          {/* South Tick (Cyan accent) */}
          <line
            x1="16"
            y1="27"
            x2="16"
            y2="30"
            stroke="#06b6d4"
            strokeWidth="1.4"
            strokeLinecap="round"
          />
          {/* West Tick */}
          <line
            x1="2"
            y1="16"
            x2="5"
            y2="16"
            stroke="#64748b"
            strokeWidth="1.2"
            strokeLinecap="round"
          />

          {/* Sub-cardinal subtle dots (NE, SE, SW, NW) */}
          <circle cx="25.9" cy="6.1" r="0.6" fill="#475569" />
          <circle cx="25.9" cy="25.9" r="0.6" fill="#475569" />
          <circle cx="6.1" cy="25.9" r="0.6" fill="#475569" />
          <circle cx="6.1" cy="6.1" r="0.6" fill="#475569" />

          {/* Cardinal 'N' Letter Indicator */}
          <text
            x="16"
            y="8.2"
            textAnchor="middle"
            fontSize="4.2"
            fontWeight="bold"
            fill="#ef4444"
            fontFamily="monospace"
          >
            N
          </text>

          {/* Dual-Tone Pointer Needle */}
          <g filter="url(#needleShadow)">
            {/* North Pointer: Crisp Red (#ef4444) with two-tone bevel */}
            <polygon
              points="16,8.5 18.5,16 16,14.8"
              fill="#ef4444"
            />
            <polygon
              points="16,8.5 13.5,16 16,14.8"
              fill="#dc2626"
            />

            {/* South Pointer: Neon Cyan (#06b6d4) with two-tone bevel */}
            <polygon
              points="16,23.5 18.5,16 16,17.2"
              fill="#06b6d4"
            />
            <polygon
              points="16,23.5 13.5,16 16,17.2"
              fill="#0891b2"
            />

            {/* Center Pivot Cap: White center point */}
            <circle
              cx="16"
              cy="16"
              r="2.2"
              fill="#ffffff"
              stroke="#0b1329"
              strokeWidth="0.8"
            />
          </g>
        </svg>
      </div>

      {/* Angle Readout */}
      <span className="text-[9px] font-mono font-bold text-cyan-400 leading-none mt-0.5 group-hover:text-cyan-300">
        {normalizedHeading}°
      </span>
    </div>
  );
}
