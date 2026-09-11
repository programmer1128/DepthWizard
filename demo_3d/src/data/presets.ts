import type { TerrainMetadata } from '../types/gis';

export interface PresetDataset {
  metadata: TerrainMetadata;
  thumbnailUrl?: string;
  sourceType: 'geotiff' | 'drone_optical';
  recommendedExaggeration: number;
}

export const PRESET_DATASETS: PresetDataset[] = [
  {
    metadata: {
      id: 'alpine-ridge-dsm',
      title: 'Matterhorn Alpine Ridge DSM',
      mode: 'georeferenced',
      crs: 'EPSG:4326 (WGS84)',
      gsd: '0.20 m/pixel',
      verticalDatum: 'EGM96 Orthometric (MSL)',
      minElevation: 2240.5,
      maxElevation: 3892.0,
      areaCoverage: '2.4 km × 2.4 km',
      dateCaptured: '2025-08-14 10:42 UTC',
      sensor: 'Pléiades Neo Stereo-Panchromatic'
    },
    sourceType: 'geotiff',
    recommendedExaggeration: 1.2
  },
  {
    metadata: {
      id: 'quarry-mine-rdsm',
      title: 'Open-Pit Quarry Mine DSM',
      mode: 'georeferenced',
      crs: 'EPSG:3857 (Metric Web Mercator)',
      gsd: '0.05 m/pixel (UAV Decimeter)',
      verticalDatum: 'EGM96 Orthometric (MSL)',
      minElevation: 310.0,
      maxElevation: 458.5,
      areaCoverage: '1.2 km × 1.2 km',
      dateCaptured: '2025-09-02 14:15 UTC',
      sensor: 'DJI Zenmuse P1 (45MP Full-Frame Drone)'
    },
    sourceType: 'drone_optical',
    recommendedExaggeration: 1.6
  },
  {
    metadata: {
      id: 'coastal-fjord-dsm',
      title: 'Nordic Coastal Fjord & Cliffs',
      mode: 'georeferenced',
      crs: 'EPSG:25833 (ETRS89 / UTM 33N)',
      gsd: '0.50 m/pixel',
      verticalDatum: 'NN2000 European Vertical Datum',
      minElevation: 2.0,
      maxElevation: 914.0,
      areaCoverage: '3.6 km × 3.6 km',
      dateCaptured: '2025-07-29 09:18 UTC',
      sensor: 'Airborne LiDAR + Multi-spectral Aerial'
    },
    sourceType: 'geotiff',
    recommendedExaggeration: 1.4
  }
];
