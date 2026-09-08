'use client';

import React from 'react';

interface InstructionsModalProps {
  isOpen: boolean;
  onClose: () => void;
}

export const InstructionsModal: React.FC<InstructionsModalProps> = ({ isOpen, onClose }) => {
  if (!isOpen) return null;

  return (
    <div className="fixed inset-0 z-50 flex items-center justify-center p-4 bg-slate-950/80 backdrop-blur-sm animate-in fade-in duration-200">
      <div className="relative w-full max-w-2xl max-h-[85vh] overflow-y-auto rounded-2xl bg-slate-900 border border-slate-800 p-6 shadow-2xl text-slate-200 space-y-6">
        <div className="flex items-center justify-between pb-3 border-b border-slate-800">
          <div className="flex items-center gap-2.5">
            <div className="w-8 h-8 rounded-lg bg-indigo-600/20 border border-indigo-500/40 flex items-center justify-center text-indigo-400">
              <svg className="w-4 h-4" viewBox="0 0 24 24" fill="none" stroke="currentColor">
                <path strokeLinecap="round" strokeLinejoin="round" strokeWidth="2" d="M12 6.253v13m0-13C10.832 5.477 9.246 5 7.5 5S4.168 5.477 3 6.253v13C4.168 18.477 5.754 18 7.5 18s3.332.477 4.5 1.253m0-13C13.168 5.477 14.754 5 16.5 5c1.747 0 3.332.477 4.5 1.253v13C19.832 18.477 18.247 18 16.5 18c-1.746 0-3.332.477-4.5 1.253" />
              </svg>
            </div>
            <h2 className="text-base font-bold text-white">
              Running Unity WebGL & Next.js Locally
            </h2>
          </div>
          <button
            onClick={onClose}
            className="p-1 rounded-lg text-slate-400 hover:text-white hover:bg-slate-800 transition-colors"
          >
            <svg className="w-5 h-5" viewBox="0 0 24 24" fill="none" stroke="currentColor">
              <path strokeLinecap="round" strokeLinejoin="round" strokeWidth="2" d="M6 18L18 6M6 6l12 12" />
            </svg>
          </button>
        </div>

        {/* Step 1 */}
        <div className="space-y-2">
          <h3 className="text-sm font-semibold text-white flex items-center gap-2">
            <span className="w-5 h-5 rounded-full bg-indigo-500/20 text-indigo-300 text-xs flex items-center justify-center font-mono">1</span>
            Building the Unity WebGL Project
          </h3>
          <p className="text-xs text-slate-400 leading-relaxed">
            The Unity project is located in <code className="text-cyan-300 font-mono bg-slate-950 px-1 py-0.5 rounded">unity-project/</code>. It contains the C# scripts, official <code className="text-cyan-300 font-mono bg-slate-950 px-1 py-0.5 rounded">com.unity.cloud.gltfast</code> package, and automated WebGL build script.
          </p>
          <div className="p-3 rounded-xl bg-slate-950 border border-slate-800 font-mono text-xs text-slate-300">
            <p className="text-slate-500"># Run the 1-click batch build script:</p>
            <p className="text-cyan-400 mt-1">cd d:\test\unity-project</p>
            <p className="text-emerald-400">build-webgl.bat</p>
          </div>
          <p className="text-[11px] text-slate-400">
            The build outputs automatically into <code className="text-slate-300 font-mono">nextjs-app/public/unity-build/</code>.
          </p>
        </div>

        {/* Step 2 */}
        <div className="space-y-2">
          <h3 className="text-sm font-semibold text-white flex items-center gap-2">
            <span className="w-5 h-5 rounded-full bg-indigo-500/20 text-indigo-300 text-xs flex items-center justify-center font-mono">2</span>
            Running the Next.js Frontend
          </h3>
          <p className="text-xs text-slate-400 leading-relaxed">
            In your terminal, navigate to <code className="text-cyan-300 font-mono bg-slate-950 px-1 py-0.5 rounded">nextjs-app/</code> and start the development server:
          </p>
          <div className="p-3 rounded-xl bg-slate-950 border border-slate-800 font-mono text-xs text-slate-300">
            <p className="text-cyan-400">cd d:\test\nextjs-app</p>
            <p className="text-emerald-400">npm run dev</p>
          </div>
          <p className="text-[11px] text-slate-400">
            Open <code className="text-cyan-300 font-mono">http://localhost:3000</code> in Chrome, Edge, or Firefox.
          </p>
        </div>

        {/* Step 3 */}
        <div className="space-y-2">
          <h3 className="text-sm font-semibold text-white flex items-center gap-2">
            <span className="w-5 h-5 rounded-full bg-indigo-500/20 text-indigo-300 text-xs flex items-center justify-center font-mono">3</span>
            JavaScript ↔ Unity Communication Architecture
          </h3>
          <div className="p-3 rounded-xl bg-slate-950 border border-slate-800 space-y-2 text-xs">
            <div className="flex items-start gap-2">
              <span className="px-1.5 py-0.5 rounded bg-blue-500/20 text-blue-300 font-mono text-[10px]">Next.js ➔ Unity</span>
              <span className="text-slate-300 font-mono">unityInstance.SendMessage(&quot;ModelManager&quot;, &quot;LoadGlbFromUrl&quot;, url)</span>
            </div>
            <div className="flex items-start gap-2">
              <span className="px-1.5 py-0.5 rounded bg-emerald-500/20 text-emerald-300 font-mono text-[10px]">Unity ➔ Next.js</span>
              <span className="text-slate-300">Assets/Plugins/WebGL/WebBridge.jslib dispatches DOM CustomEvents (UnityModelLoaded, UnityModelProgress, etc.)</span>
            </div>
          </div>
        </div>

        {/* Step 4 */}
        <div className="space-y-2">
          <h3 className="text-sm font-semibold text-white flex items-center gap-2">
            <span className="w-5 h-5 rounded-full bg-indigo-500/20 text-indigo-300 text-xs flex items-center justify-center font-mono">4</span>
            Testing Any .GLB Model
          </h3>
          <ul className="list-disc list-inside text-xs text-slate-400 space-y-1">
            <li>Select from preset models (Khronos Duck, PBR Cube, Damaged Helmet)</li>
            <li>Paste any remote HTTPS URL linking to a <code className="font-mono text-slate-300">.glb</code> file</li>
            <li>Drag & drop a <code className="font-mono text-slate-300">.glb</code> file from your computer directly onto the upload tab</li>
          </ul>
        </div>

        <div className="pt-3 border-t border-slate-800 flex justify-end">
          <button
            onClick={onClose}
            className="px-4 py-2 bg-indigo-600 hover:bg-indigo-500 text-white rounded-xl text-xs font-semibold transition-colors"
          >
            Got it, Let&apos;s Go
          </button>
        </div>
      </div>
    </div>
  );
};
