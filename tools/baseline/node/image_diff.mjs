// Pixel difference between two screenshots; prints a JSON summary.
// Usage: node image_diff.mjs <a.png> <b.png> [--threshold 16]
import { readFile } from 'node:fs/promises';
import { PNG } from 'pngjs';

const [a, b] = process.argv.slice(2, 4);
const thresholdIndex = process.argv.indexOf('--threshold');
const threshold = thresholdIndex > 0 ? Number(process.argv[thresholdIndex + 1]) : 16;
if (!a || !b) {
    console.error('usage: node image_diff.mjs <a.png> <b.png> [--threshold 16]');
    process.exit(2);
}
const first = PNG.sync.read(await readFile(a));
const second = PNG.sync.read(await readFile(b));
if (first.width !== second.width || first.height !== second.height) {
    console.log(JSON.stringify({ comparable: false, a: [first.width, first.height], b: [second.width, second.height] }));
    process.exit(0);
}
let sum = 0, max = 0, differing = 0;
const pixels = first.width * first.height;
for (let i = 0; i < pixels; i += 1) {
    let pixelMax = 0;
    for (let c = 0; c < 3; c += 1) {
        const d = Math.abs(first.data[i * 4 + c] - second.data[i * 4 + c]);
        sum += d;
        pixelMax = Math.max(pixelMax, d);
    }
    max = Math.max(max, pixelMax);
    if (pixelMax > threshold) differing += 1;
}
console.log(JSON.stringify({
    comparable: true,
    width: first.width,
    height: first.height,
    mean_abs_diff: sum / (pixels * 3),
    max_abs_diff: max,
    differing_pixel_fraction: differing / pixels,
    threshold
}));
