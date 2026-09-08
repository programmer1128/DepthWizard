import type { Metadata } from 'next';
import './globals.css';

export const metadata: Metadata = {
  title: 'Unity WebGL × Next.js 3D .GLB Viewer Studio',
  description: 'Production Next.js application integrating a Unity WebGL rendering engine with glTFast for dynamic runtime .glb 3D model visualization and bidirectional JS-Unity bridge.',
  keywords: ['Unity', 'WebGL', 'Next.js', '3D', 'GLB', 'glTF', 'glTFast', '3D Model Viewer']
};

export default function RootLayout({
  children,
}: {
  children: React.ReactNode;
}) {
  return (
    <html lang="en" className="dark">
      <head>
        <link rel="preconnect" href="https://fonts.googleapis.com" />
        <link rel="preconnect" href="https://fonts.gstatic.com" crossOrigin="anonymous" />
        <link
          href="https://fonts.googleapis.com/css2?family=Inter:wght@300;400;500;600;700;800&family=JetBrains+Mono:wght@400;500;600&display=swap"
          rel="stylesheet"
        />
      </head>
      <body className="min-h-screen bg-slate-950 text-slate-100 antialiased font-sans">
        {children}
      </body>
    </html>
  );
}
