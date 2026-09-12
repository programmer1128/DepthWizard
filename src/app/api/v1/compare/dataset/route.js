// Next.js App Router API Route (ES6+)
// GET /api/v1/compare/dataset

export async function GET() {
  const datasets = [
    {
      id: 'isro-bhuvan',
      name: 'ISRO Bhuvan (CartoDEM)',
      agency: 'ISRO National Remote Sensing Centre',
      resolution: '10-meter',
      type: 'Stereo Optical InSAR',
      coverage: 'India & Subcontinent',
      datum: 'WGS84 / EGM96'
    },
    {
      id: 'opentopography',
      name: 'OpenTopography High-Res LiDAR',
      agency: 'NSF / OpenTopography Facility',
      resolution: '1-meter / Point Cloud',
      type: 'Airborne LiDAR',
      coverage: 'Global High-Priority',
      datum: 'WGS84 / NAVD88',
      isBenchmarkDefault: true
    },
    {
      id: 'copernicus',
      name: 'Copernicus GLO-30 DEM',
      agency: 'European Space Agency (ESA)',
      resolution: '30-meter',
      type: 'Radar TanDEM-X',
      coverage: 'Global',
      datum: 'WGS84'
    }
  ];

  return Response.json({
    count: datasets.length,
    default_benchmark: 'opentopography',
    datasets
  }, {
    status: 200,
    headers: {
      'Cache-Control': 'public, max-age=3600'
    }
  });
}
