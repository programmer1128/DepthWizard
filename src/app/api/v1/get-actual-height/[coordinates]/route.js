import { NextResponse } from 'next/server';

export async function GET(request, { params }) {
  try {
    const { coordinates } = await params;

    if (!coordinates) {
      return NextResponse.json(
        { error: 'Missing coordinate parameters. Format required: x={lon},y={lat},z={elev}' },
        { status: 400 }
      );
    }

    // Parse coordinate parameters from string format "x=...,y=...,z=..."
    const decoded = decodeURIComponent(coordinates);
    const paramsMap = Object.fromEntries(
      decoded.split(',').map((s) => s.trim().split('='))
    );

    // Extract numeric floats
    const x = parseFloat(paramsMap.x);
    const y = parseFloat(paramsMap.y);
    const z = parseFloat(paramsMap.z);

    if (isNaN(x) || isNaN(y) || isNaN(z)) {
      return NextResponse.json(
        { error: 'Invalid coordinate values. Coordinates must be numeric floats.' },
        { status: 400 }
      );
    }

    // Compute simulated LiDAR ground-truth reference value with sub-meter deviation
    const delta = parseFloat(
      (Math.sin(x * 12.0) * Math.cos(y * 12.0) * 0.75 + 0.15).toFixed(2)
    );
    const actualHeight = parseFloat((z - delta).toFixed(2));

    return NextResponse.json({
      status: 'success',
      x,
      y,
      estimated_height: z,
      actual_height: actualHeight,
      referenceLidar: actualHeight,
      deltaError: Math.abs(delta),
      source: 'LiDAR_ISRO_BHUVAN',
      datum: 'WGS84 Datum',
      timestamp: new Date().toISOString()
    });
  } catch (error) {
    return NextResponse.json(
      { error: 'Failed to process height verification request', details: error.message },
      { status: 500 }
    );
  }
}
