import './globals.css';

export const metadata = {
  title: 'DepthWizard 3D — Geospatial Elevation & WGS84 Inspection',
  description: 'Single-view height estimation, monocular DEM inference, and WGS84 ground-truth verification.',
};

export default function RootLayout({ children }) {
  return (
    <html lang="en" className="dark">
      <body className="bg-[#0b1329] text-white antialiased overflow-hidden min-h-screen">
        {children}
      </body>
    </html>
  );
}
