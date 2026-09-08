'use client';

import React, { useState } from 'react';
import type { BridgeLogEntry } from '@/types/unity';

interface MessageConsoleProps {
  logs: BridgeLogEntry[];
  onClear: () => void;
}

export const MessageConsole: React.FC<MessageConsoleProps> = ({ logs, onClear }) => {
  const [filter, setFilter] = useState<'all' | 'to-unity' | 'from-unity'>('all');

  const filteredLogs = logs.filter((log) => {
    if (filter === 'all') return true;
    return log.direction === filter;
  });

  return (
    <div className="rounded-2xl bg-slate-900/80 border border-slate-800/80 p-4 shadow-xl backdrop-blur-sm flex flex-col h-[280px]">
      <div className="flex items-center justify-between mb-2.5 pb-2 border-b border-slate-800/60">
        <div className="flex items-center gap-2">
          <h3 className="text-xs font-semibold uppercase tracking-wider text-slate-400 flex items-center gap-1.5">
            <svg className="w-3.5 h-3.5 text-cyan-400" viewBox="0 0 24 24" fill="none" stroke="currentColor">
              <polyline points="4 17 10 11 4 5" />
              <line x1="12" y1="19" x2="20" y2="19" />
            </svg>
            <span>JS ↔ Unity Bridge Feed</span>
          </h3>
          <span className="text-[10px] px-1.5 py-0.5 rounded bg-slate-800 text-slate-400 font-mono">
            {logs.length}
          </span>
        </div>

        <div className="flex items-center gap-1.5">
          {/* Filter Pills */}
          <div className="flex rounded-lg bg-slate-950 p-0.5 border border-slate-800/80 text-[10px]">
            <button
              onClick={() => setFilter('all')}
              className={`px-2 py-0.5 rounded ${filter === 'all' ? 'bg-indigo-600 text-white font-medium' : 'text-slate-400 hover:text-white'}`}
            >
              All
            </button>
            <button
              onClick={() => setFilter('to-unity')}
              className={`px-2 py-0.5 rounded ${filter === 'to-unity' ? 'bg-indigo-600 text-white font-medium' : 'text-slate-400 hover:text-white'}`}
            >
              JS→Unity
            </button>
            <button
              onClick={() => setFilter('from-unity')}
              className={`px-2 py-0.5 rounded ${filter === 'from-unity' ? 'bg-indigo-600 text-white font-medium' : 'text-slate-400 hover:text-white'}`}
            >
              Unity→JS
            </button>
          </div>

          <button
            onClick={onClear}
            className="p-1 rounded text-slate-500 hover:text-slate-300 hover:bg-slate-800/60 transition-colors"
            title="Clear Log"
          >
            <svg className="w-3.5 h-3.5" viewBox="0 0 24 24" fill="none" stroke="currentColor">
              <path strokeLinecap="round" strokeLinejoin="round" strokeWidth="2" d="M19 7l-.867 12.142A2 2 0 0116.138 21H7.862a2 2 0 01-1.995-1.858L5 7m5 4v6m4-6v6m1-10V4a1 1 0 00-1-1h-4a1 1 0 00-1 1v3M4 7h16" />
            </svg>
          </button>
        </div>
      </div>

      {/* Log Feed */}
      <div className="flex-1 overflow-y-auto space-y-1 font-mono text-[11px] pr-1 select-text">
        {filteredLogs.length === 0 ? (
          <div className="h-full flex items-center justify-center text-slate-600 text-xs italic">
            Waiting for bridge events...
          </div>
        ) : (
          filteredLogs.map((log) => {
            const isToUnity = log.direction === 'to-unity';
            return (
              <div
                key={log.id}
                className="flex items-start gap-1.5 p-1.5 rounded-lg bg-slate-950/40 hover:bg-slate-950/80 border border-slate-800/40 transition-colors"
              >
                <span className="text-[10px] text-slate-500 shrink-0 pt-0.5">
                  {log.timestamp}
                </span>

                <span
                  className={`text-[9px] font-semibold uppercase px-1 py-0.2 rounded shrink-0 ${
                    isToUnity
                      ? 'bg-blue-500/20 text-blue-300 border border-blue-500/30'
                      : 'bg-emerald-500/20 text-emerald-300 border border-emerald-500/30'
                  }`}
                >
                  {isToUnity ? 'JS ➔ Unity' : 'Unity ➔ JS'}
                </span>

                <span className="text-slate-300 font-semibold truncate shrink-0 max-w-[140px]" title={log.channel}>
                  {log.channel}
                </span>

                <span className="text-slate-400 truncate flex-1" title={typeof log.payload === 'string' ? log.payload : JSON.stringify(log.payload)}>
                  {typeof log.payload === 'object' && log.payload !== null
                    ? JSON.stringify(log.payload)
                    : String(log.payload)}
                </span>
              </div>
            );
          })
        )}
      </div>
    </div>
  );
};
