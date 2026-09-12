// Next.js App Router API Route
// GET /api/v1/compare/dataset

export async function GET() {
  const datasets = [
    'ISRO Bhuvan',
    'OpenTopography',
    'GSI Ireland'
  ];

  return Response.json({
    count: datasets.length,
    default_benchmark: 'OpenTopography',
    datasets
  }, {
    status: 200,
    headers: {
      'Content-Type': 'application/json',
      'Cache-Control': 'public, max-age=3600'
    }
  });
}
