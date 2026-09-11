import * as THREE from 'three';

// Simplex-style pseudo noise for procedural elevation generation
function fract(n: number): number {
  return n - Math.floor(n);
}

function hash2D(x: number, y: number): number {
  const h = Math.sin(x * 127.1 + y * 311.7) * 43758.5453123;
  return fract(h);
}

function smoothNoise(x: number, y: number): number {
  const i = Math.floor(x);
  const j = Math.floor(y);
  const fx = fract(x);
  const fy = fract(y);

  // Cubic Hermite spline
  const ux = fx * fx * (3.0 - 2.0 * fx);
  const uy = fy * fy * (3.0 - 2.0 * fy);

  const a = hash2D(i, j);
  const b = hash2D(i + 1, j);
  const c = hash2D(i, j + 1);
  const d = hash2D(i + 1, j + 1);

  return a + (b - a) * ux + (c - a) * uy + (a - b - c + d) * ux * uy;
}

function fbm(x: number, y: number, octaves = 6): number {
  let val = 0;
  let freq = 1;
  let amp = 0.5;
  for (let o = 0; o < octaves; o++) {
    val += smoothNoise(x * freq, y * freq) * amp;
    freq *= 2.02;
    amp *= 0.48;
  }
  return val;
}

// Ridged multifractal for alpine peaks
function ridgeFbm(x: number, y: number, octaves = 6): number {
  let val = 0;
  let freq = 1;
  let amp = 0.6;
  let weight = 1.0;
  for (let o = 0; o < octaves; o++) {
    let signal = smoothNoise(x * freq, y * freq);
    signal = 1.0 - Math.abs(signal * 2.0 - 1.0);
    signal *= signal;
    signal *= weight;
    weight = signal * 1.5;
    if (weight > 1.0) weight = 1.0;
    if (weight < 0.0) weight = 0.0;
    val += signal * amp;
    freq *= 2.1;
    amp *= 0.5;
  }
  return val;
}

export interface TerrainDataPackage {
  resolution: number; // grid vertices per edge (e.g. 256)
  heights: Float32Array; // normalized 0..1
  rgbTexture: THREE.CanvasTexture;
  hypsometricTexture: THREE.CanvasTexture;
  slopeTexture: THREE.CanvasTexture;
  minElevation: number;
  maxElevation: number;
}

// Turbo / Jet Hypsometric color ramp interpolation
export function getTurboColor(t: number): [number, number, number] {
  // clamped 0..1
  t = Math.max(0, Math.min(1, t));
  // High quality 4th order polynomial approximation of Google Turbo Colormap
  const r = Math.max(0, Math.min(255, Math.round(
    255 * (0.1357 + t * (4.5974 - t * (42.3277 - t * (130.5887 - t * (150.5667 - t * 58.1375)))))
  )));
  const g = Math.max(0, Math.min(255, Math.round(
    255 * (0.0914 + t * (2.1856 + t * (4.8052 - t * (14.0195 - t * (4.2109 - t * 2.7747)))))
  )));
  const b = Math.max(0, Math.min(255, Math.round(
    255 * (0.1067 + t * (12.5594 - t * (60.1971 - t * (109.0745 - t * (88.5061 - t * 26.8183)))))
  )));
  return [r, g, b];
}

// Slope color ramp: Green (flat) -> Yellow (moderate) -> Red/Magenta (steep cliff)
export function getSlopeColor(slopeDegrees: number): [number, number, number] {
  const norm = Math.max(0, Math.min(1, slopeDegrees / 60)); // 0 to 60 deg
  if (norm < 0.25) {
    // Green to Light Green
    const f = norm / 0.25;
    return [Math.round(20 + f * 50), Math.round(180 + f * 40), Math.round(80 - f * 30)];
  } else if (norm < 0.55) {
    // Green to Yellow / Amber
    const f = (norm - 0.25) / 0.3;
    return [Math.round(70 + f * 170), Math.round(220 - f * 30), Math.round(50 - f * 30)];
  } else if (norm < 0.85) {
    // Amber to Red
    const f = (norm - 0.55) / 0.3;
    return [Math.round(240 + f * 15), Math.round(190 - f * 140), Math.round(20)];
  } else {
    // Deep crimson / purple cliff
    const f = (norm - 0.85) / 0.15;
    return [Math.round(255 - f * 50), Math.round(50 - f * 30), Math.round(50 + f * 100)];
  }
}

/**
 * Procedurally generates elevation field and textures for specified preset
 */
export function generateTerrainDataset(
  type: 'alpine-ridge-dsm' | 'quarry-mine-rdsm' | 'coastal-fjord-dsm' | 'custom',
  customImage?: HTMLImageElement | null,
  customMode: 'georeferenced' | 'relative' = 'georeferenced'
): TerrainDataPackage {
  const res = 256;
  const heights = new Float32Array(res * res);
  
  let minElev = 0;
  let maxElev = 1000;

  if (type === 'alpine-ridge-dsm') {
    minElev = 2240.5;
    maxElev = 3892.0;
    for (let j = 0; j < res; j++) {
      const v = j / (res - 1);
      for (let i = 0; i < res; i++) {
        const u = i / (res - 1);
        const x = (u - 0.5) * 4.5;
        const y = (v - 0.5) * 4.5;
        
        // Massive central peak with jagged lateral ridges
        const distCenter = Math.sqrt(x * x + y * y);
        const peakEnvelope = Math.exp(-distCenter * 0.9);
        const ridges = ridgeFbm(x * 1.3 + 10.5, y * 1.3 + 12.8, 6);
        const detail = fbm(x * 3.5, y * 3.5, 4) * 0.25;
        
        let h = (ridges * 0.85 + detail) * peakEnvelope;
        // Valley floor taper
        h = Math.pow(Math.max(0, h), 1.25);
        heights[j * res + i] = Math.min(1, Math.max(0, h * 1.35));
      }
    }
  } else if (type === 'quarry-mine-rdsm') {
    minElev = 0;
    maxElev = 148.5;
    for (let j = 0; j < res; j++) {
      const v = j / (res - 1);
      for (let i = 0; i < res; i++) {
        const u = i / (res - 1);
        const x = (u - 0.5) * 3.8;
        const y = (v - 0.5) * 3.8;
        
        const dist = Math.sqrt(x * x + y * y);
        // Open pit excavation terracing
        let pitDepth = Math.max(0, 1.0 - dist * 0.75);
        const terraceSteps = Math.floor(pitDepth * 9) / 9;
        const rough = fbm(x * 6.0, y * 6.0, 4) * 0.08;
        
        let h = 0.9 - (terraceSteps * 0.75 + rough);
        // Haul road spiral carve
        const angle = Math.atan2(y, x);
        const spiral = (angle + Math.PI) / (Math.PI * 2);
        if (Math.abs(fract(dist * 2.2 - spiral * 0.5) - 0.5) < 0.08 && dist < 1.1) {
          h -= 0.04;
        }
        heights[j * res + i] = Math.min(1, Math.max(0, h));
      }
    }
  } else if (type === 'coastal-fjord-dsm') {
    minElev = 0;
    maxElev = 890;
    for (let j = 0; j < res; j++) {
      const v = j / (res - 1);
      for (let i = 0; i < res; i++) {
        const u = i / (res - 1);
        const x = (u - 0.5) * 4.0;
        const y = (v - 0.5) * 4.0;
        
        // Fjord channel cutting through coastal mountains
        const mountain = fbm(x * 1.5, y * 1.5, 6);
        const waterTrench = Math.abs(x - Math.sin(y * 1.8) * 0.4);
        let waterMask = Math.min(1, Math.max(0, (waterTrench - 0.35) * 3.0));
        let h = mountain * waterMask;
        if (waterTrench < 0.32) h = 0.01; // Water surface
        heights[j * res + i] = Math.min(1, Math.max(0, h));
      }
    }
  } else if (customImage) {
    // Custom user upload (derived from image luminance & depth gradients)
    minElev = customMode === 'georeferenced' ? 450 : 0;
    maxElev = customMode === 'georeferenced' ? 1860 : 120;
    
    // Sample image to canvas
    const sampleCanvas = document.createElement('canvas');
    sampleCanvas.width = res;
    sampleCanvas.height = res;
    const sCtx = sampleCanvas.getContext('2d')!;
    sCtx.drawImage(customImage, 0, 0, res, res);
    const imgData = sCtx.getImageData(0, 0, res, res).data;

    for (let j = 0; j < res; j++) {
      for (let i = 0; i < res; i++) {
        const idx = (j * res + i) * 4;
        const r = imgData[idx];
        const g = imgData[idx + 1];
        const b = imgData[idx + 2];
        // Relative height estimation derived from luminance + bilateral filter effect
        const lum = (0.299 * r + 0.587 * g + 0.114 * b) / 255;
        // Invert or shape based on typical aerial lighting
        const h = Math.pow(lum, 1.2);
        heights[j * res + i] = Math.min(1, Math.max(0, h));
      }
    }
  }

  // Create Canvases for RGB, Hypsometric, and Slope textures
  const rgbCanvas = document.createElement('canvas');
  rgbCanvas.width = res;
  rgbCanvas.height = res;
  const rgbCtx = rgbCanvas.getContext('2d')!;
  const rgbImgData = rgbCtx.createImageData(res, res);

  const hypoCanvas = document.createElement('canvas');
  hypoCanvas.width = res;
  hypoCanvas.height = res;
  const hypoCtx = hypoCanvas.getContext('2d')!;
  const hypoImgData = hypoCtx.createImageData(res, res);

  const slopeCanvas = document.createElement('canvas');
  slopeCanvas.width = res;
  slopeCanvas.height = res;
  const slopeCtx = slopeCanvas.getContext('2d')!;
  const slopeImgData = slopeCtx.createImageData(res, res);

  // Compute normals & slopes
  const cellSize = 1.0 / res;

  for (let j = 0; j < res; j++) {
    for (let i = 0; i < res; i++) {
      const idx = j * res + i;
      const pixelIdx = idx * 4;
      const h = heights[idx];

      // Slope calculation via Sobel / central difference
      const hL = heights[j * res + Math.max(0, i - 1)];
      const hR = heights[j * res + Math.min(res - 1, i + 1)];
      const hD = heights[Math.max(0, j - 1) * res + i];
      const hU = heights[Math.min(res - 1, j + 1) * res + i];

      const dx = (hR - hL) / (2 * cellSize);
      const dy = (hU - hD) / (2 * cellSize);
      const normalZ = 1.0;
      const normalLen = Math.sqrt(dx * dx + dy * dy + normalZ * normalZ);
      const slopeRad = Math.acos(normalZ / normalLen);
      const slopeDeg = (slopeRad * 180) / Math.PI;

      // 1. RGB Texture
      if (customImage) {
        // Draw directly from custom image
        const sampleCanvas = document.createElement('canvas');
        sampleCanvas.width = res;
        sampleCanvas.height = res;
        const sCtx = sampleCanvas.getContext('2d')!;
        sCtx.drawImage(customImage, 0, 0, res, res);
        const sData = sCtx.getImageData(0, 0, res, res).data;
        rgbImgData.data[pixelIdx] = sData[pixelIdx];
        rgbImgData.data[pixelIdx + 1] = sData[pixelIdx + 1];
        rgbImgData.data[pixelIdx + 2] = sData[pixelIdx + 2];
        rgbImgData.data[pixelIdx + 3] = 255;
      } else if (type === 'alpine-ridge-dsm') {
        // Alpine rock, scree, alpine meadow, snow
        let r = 70, g = 85, b = 60; // valley grass
        if (h > 0.35) {
          // Grey scree/limestone
          const rock = Math.round(90 + (h - 0.35) * 120);
          r = rock; g = rock - 5; b = rock - 10;
        }
        if (h > 0.68) {
          // Alpine perennial snow/firn
          const snow = Math.round(210 + (h - 0.68) * 130);
          r = snow; g = Math.min(255, snow + 10); b = Math.min(255, snow + 20);
        }
        // Hillshade shadow modulation
        const shade = Math.max(0.3, Math.min(1.2, 0.7 - dx * 0.003 - dy * 0.003));
        rgbImgData.data[pixelIdx] = Math.min(255, Math.round(r * shade));
        rgbImgData.data[pixelIdx + 1] = Math.min(255, Math.round(g * shade));
        rgbImgData.data[pixelIdx + 2] = Math.min(255, Math.round(b * shade));
        rgbImgData.data[pixelIdx + 3] = 255;
      } else if (type === 'quarry-mine-rdsm') {
        // Excavated clay, crushed granite gravel, machinery tracks
        const dirt = Math.round(160 + fbm(i * 0.1, j * 0.1, 3) * 60);
        const shade = Math.max(0.4, Math.min(1.2, 0.75 - dx * 0.003 - dy * 0.003));
        rgbImgData.data[pixelIdx] = Math.min(255, Math.round(dirt * 1.1 * shade));
        rgbImgData.data[pixelIdx + 1] = Math.min(255, Math.round(dirt * 0.95 * shade));
        rgbImgData.data[pixelIdx + 2] = Math.min(255, Math.round(dirt * 0.75 * shade));
        rgbImgData.data[pixelIdx + 3] = 255;
      } else {
        // Coastal Fjord: Deep blue water, forest green slopes, rocky grey cliffs
        if (h < 0.03) {
          // Water
          rgbImgData.data[pixelIdx] = 18;
          rgbImgData.data[pixelIdx + 1] = 68;
          rgbImgData.data[pixelIdx + 2] = 110;
        } else {
          const shade = Math.max(0.4, Math.min(1.2, 0.7 - dx * 0.003 - dy * 0.003));
          let r = 40, g = 90, b = 45;
          if (slopeDeg > 28) {
            r = 110; g = 110; b = 105;
          }
          rgbImgData.data[pixelIdx] = Math.min(255, Math.round(r * shade));
          rgbImgData.data[pixelIdx + 1] = Math.min(255, Math.round(g * shade));
          rgbImgData.data[pixelIdx + 2] = Math.min(255, Math.round(b * shade));
        }
        rgbImgData.data[pixelIdx + 3] = 255;
      }

      // 2. Hypsometric Turbo / Jet Texture with subtle contour lines
      const [tr, tg, tb] = getTurboColor(h);
      // Subtle contour lines every 10% height
      const contourMod = Math.abs((h * 10) % 1.0);
      const isContour = contourMod < 0.04 || contourMod > 0.96;
      hypoImgData.data[pixelIdx] = isContour ? Math.round(tr * 0.4) : tr;
      hypoImgData.data[pixelIdx + 1] = isContour ? Math.round(tg * 0.4) : tg;
      hypoImgData.data[pixelIdx + 2] = isContour ? Math.round(tb * 0.4) : tb;
      hypoImgData.data[pixelIdx + 3] = 255;

      // 3. Slope Texture
      const [sr, sg, sb] = getSlopeColor(slopeDeg);
      slopeImgData.data[pixelIdx] = sr;
      slopeImgData.data[pixelIdx + 1] = sg;
      slopeImgData.data[pixelIdx + 2] = sb;
      slopeImgData.data[pixelIdx + 3] = 255;
    }
  }

  rgbCtx.putImageData(rgbImgData, 0, 0);
  hypoCtx.putImageData(hypoImgData, 0, 0);
  slopeCtx.putImageData(slopeImgData, 0, 0);

  const rgbTexture = new THREE.CanvasTexture(rgbCanvas);
  rgbTexture.wrapS = THREE.ClampToEdgeWrapping;
  rgbTexture.wrapT = THREE.ClampToEdgeWrapping;
  rgbTexture.minFilter = THREE.LinearFilter;
  rgbTexture.magFilter = THREE.LinearFilter;

  const hypsometricTexture = new THREE.CanvasTexture(hypoCanvas);
  hypsometricTexture.wrapS = THREE.ClampToEdgeWrapping;
  hypsometricTexture.wrapT = THREE.ClampToEdgeWrapping;
  hypsometricTexture.minFilter = THREE.LinearFilter;

  const slopeTexture = new THREE.CanvasTexture(slopeCanvas);
  slopeTexture.wrapS = THREE.ClampToEdgeWrapping;
  slopeTexture.wrapT = THREE.ClampToEdgeWrapping;
  slopeTexture.minFilter = THREE.LinearFilter;

  return {
    resolution: res,
    heights,
    rgbTexture,
    hypsometricTexture,
    slopeTexture,
    minElevation: minElev,
    maxElevation: maxElev
  };
}
