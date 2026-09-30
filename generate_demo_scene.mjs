import { writeFileSync } from 'fs';
import { deflateSync } from 'zlib';
import * as THREE from 'three';
import { GLTFExporter } from 'three/addons/exporters/GLTFExporter.js';

const root = process.cwd();

if (!globalThis.FileReader) {
  globalThis.FileReader = class {
    constructor() {
      this.result = null;
      this.onloadend = null;
    }

    readAsArrayBuffer(blob) {
      blob.arrayBuffer().then((buffer) => {
        this.result = buffer;
        if (typeof this.onloadend === 'function') {
          this.onloadend();
        }
      }).catch((error) => {
        throw error;
      });
    }
  };
}

const scene = new THREE.Scene();
scene.background = new THREE.Color(0xdfeaf4);

const ground = new THREE.Mesh(
  new THREE.PlaneGeometry(220, 220, 128, 128),
  new THREE.MeshStandardMaterial({ color: 0x738894, roughness: 0.96, metalness: 0.05 })
);
ground.rotation.x = -Math.PI / 2;
scene.add(ground);

const palette = [0x869ab0, 0x71849a, 0x8fa2b4, 0x7185a2, 0x93a7b5];
const builds = [
  [-55, -42, 14, 12, 18, 0],
  [-32, -38, 18, 14, 22, 1],
  [-18, -40, 12, 10, 14, 2],
  [-4, -36, 16, 16, 26, 3],
  [18, -38, 12, 10, 19, 4],
  [36, -42, 18, 15, 28, 0],
  [-58, -6, 12, 12, 24, 1],
  [-35, -8, 18, 18, 30, 2],
  [-12, -12, 14, 14, 22, 3],
  [12, -12, 18, 16, 32, 4],
  [38, -10, 14, 14, 28, 0],
  [-52, 24, 14, 14, 20, 1],
  [-22, 24, 18, 16, 26, 2],
  [8, 22, 12, 14, 18, 3],
  [34, 24, 16, 18, 34, 4],
  [-60, 52, 16, 12, 18, 0],
  [-32, 56, 12, 10, 22, 1],
  [-8, 52, 14, 12, 20, 2],
  [22, 52, 18, 16, 30, 3],
  [48, 48, 12, 10, 18, 4],
];

const buildingMat = new THREE.MeshStandardMaterial({ roughness: 0.85, metalness: 0.18 });
for (const [x, z, width, depth, height, colorIndex] of builds) {
  const box = new THREE.Mesh(
    new THREE.BoxGeometry(width, height, depth),
    new THREE.MeshStandardMaterial({ color: palette[colorIndex % palette.length], roughness: 0.82, metalness: 0.15 })
  );
  box.position.set(x, height / 2, z);
  scene.add(box);
}

for (let i = 0; i < 5; i++) {
  const tower = new THREE.Mesh(
    new THREE.BoxGeometry(7, 42 + i * 8, 7),
    new THREE.MeshStandardMaterial({ color: 0xb8c3d7, roughness: 0.78, metalness: 0.2 })
  );
  tower.position.set(-18 + i * 12, (42 + i * 8) / 2, 40 - i * 10);
  scene.add(tower);
}

const exporter = new GLTFExporter();
exporter.parse(
  scene,
  (result) => {
    const buffer = result instanceof ArrayBuffer ? Buffer.from(result) : Buffer.from(JSON.stringify(result, null, 2));
    writeFileSync(`${root}/test_8_output.glb`, buffer);
    console.log('Wrote test_8_output.glb');
  },
  (error) => {
    console.error('GLTF export failed:', error);
    process.exit(1);
  },
  { binary: true }
);

function crc32(data) {
  let c = 0xffffffff;
  for (let i = 0; i < data.length; i++) {
    c ^= data[i];
    for (let k = 0; k < 8; k++) {
      c = (c & 1) ? (0xedb88320 ^ (c >>> 1)) : (c >>> 1);
    }
  }
  return (c ^ 0xffffffff) >>> 0;
}

function createPng(width, height, colorFn) {
  const pngSignature = Buffer.from([137, 80, 78, 71, 13, 10, 26, 10]);
  const rawData = [];

  for (let y = 0; y < height; y++) {
    rawData.push(0);
    for (let x = 0; x < width; x++) {
      const rgba = colorFn(x, y, width, height);
      rawData.push(rgba[0], rgba[1], rgba[2], rgba[3]);
    }
  }

  const compressed = deflateSync(Buffer.from(rawData));

  function pngChunk(type, data) {
    const length = Buffer.alloc(4);
    length.writeUInt32BE(data.length, 0);
    const chunkType = Buffer.from(type);
    const crc = Buffer.alloc(4);
    crc.writeUInt32BE(crc32(Buffer.concat([chunkType, data])), 0);
    return Buffer.concat([length, chunkType, data, crc]);
  }

  const widthBuf = Buffer.alloc(4); widthBuf.writeUInt32BE(width, 0);
  const heightBuf = Buffer.alloc(4); heightBuf.writeUInt32BE(height, 0);
  const ihdr = Buffer.concat([
    widthBuf,
    heightBuf,
    Buffer.from([8, 6, 0, 0, 0, 0]),
  ]);

  return Buffer.concat([
    pngSignature,
    pngChunk('IHDR', ihdr),
    pngChunk('IDAT', compressed),
    pngChunk('IEND', Buffer.alloc(0)),
  ]);
}

const pngImage = createPng(128, 128, (x, y, w, h) => {
  const dx = x / w;
  const dy = y / h;
  const r = Math.min(255, 120 + Math.round(dx * 90));
  const g = Math.min(255, 150 + Math.round(dy * 80));
  const b = Math.min(255, 190 + Math.round((dx + dy) * 30));
  return [r, g, b, 255];
});
writeFileSync(`${root}/demo_optical.png`, pngImage);
console.log('Wrote demo_optical.png');
