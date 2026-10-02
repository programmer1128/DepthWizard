// Fixed-camera screenshots of the real DepthWizard viewer.
// The viewer must be running (npm run dev in the frontend) and include the
// baseline hook (src/testing/baselineHook.js). Rendering uses SwiftShader so
// screenshots do not depend on the GPU.
//
// Usage: node screenshot.mjs --viewer http://localhost:5173 --glb <file|url>
//        --out <dir> [--cameras overview,oblique,top] [--chrome /usr/bin/google-chrome]
//        [--width 1280] [--height 720] [--timeout-ms 180000]
import { createServer } from 'node:http';
import { readFile, mkdir } from 'node:fs/promises';
import { existsSync } from 'node:fs';
import path from 'node:path';
import puppeteer from 'puppeteer-core';

function argument(name, fallback) {
    const index = process.argv.indexOf(`--${name}`);
    return index > 0 && process.argv[index + 1] ? process.argv[index + 1] : fallback;
}

const viewer = argument('viewer');
const glb = argument('glb');
const out = argument('out');
const cameras = argument('cameras', 'overview,oblique,top').split(',');
const chrome = argument('chrome', '/usr/bin/google-chrome');
const width = Number(argument('width', 1280));
const height = Number(argument('height', 720));
const timeout = Number(argument('timeout-ms', 180000));
if (!viewer || !glb || !out) {
    console.error('usage: node screenshot.mjs --viewer <url> --glb <file|url> --out <dir>');
    process.exit(2);
}

// Serve a local GLB with CORS so the viewer can fetch it.
let server = null;
let glbUrl = glb;
if (existsSync(glb)) {
    const bytes = await readFile(glb);
    server = createServer((request, response) => {
        response.writeHead(200, {
            'Content-Type': 'model/gltf-binary',
            'Access-Control-Allow-Origin': '*',
            'Content-Length': bytes.length
        });
        response.end(bytes);
    });
    await new Promise((resolve) => server.listen(0, '127.0.0.1', resolve));
    glbUrl = `http://127.0.0.1:${server.address().port}/${path.basename(glb)}`;
}

await mkdir(out, { recursive: true });
const browser = await puppeteer.launch({
    executablePath: chrome,
    headless: true,
    args: ['--use-angle=swiftshader', '--enable-unsafe-swiftshader', '--ignore-gpu-blocklist',
           '--force-device-scale-factor=1', '--force-color-profile=srgb', '--hide-scrollbars']
});
const results = [];
try {
    for (const name of cameras) {
        const page = await browser.newPage();
        await page.setViewport({ width, height, deviceScaleFactor: 1 });
        const url = `${viewer.replace(/\/+$/, '')}/?baselineGlb=${encodeURIComponent(glbUrl)}` +
                    `&baselineCamera=${encodeURIComponent(name)}`;
        await page.goto(url, { waitUntil: 'load', timeout });
        await page.waitForFunction(() => window.__DW_BASELINE?.ready === true, { timeout });
        const state = await page.evaluate(() => window.__DW_BASELINE);
        if (state.error) {
            results.push({ camera: name, error: state.error });
            await page.close();
            continue;
        }
        // The viewer's WebGL canvas is the largest canvas on the page.
        const canvas = await page.evaluateHandle(() =>
            [...document.querySelectorAll('canvas')]
                .sort((a, b) => b.width * b.height - a.width * a.height)[0]);
        const file = path.join(out, `${name}.png`);
        await canvas.asElement().screenshot({ path: file });
        results.push({ camera: name, file, extent_m: state.extentMetres, height_m: state.heightMetres });
        await page.close();
    }
} finally {
    await browser.close();
    server?.close();
}
console.log(JSON.stringify({ viewer, glb: glbUrl, width, height, renderer: 'swiftshader', screenshots: results }, null, 2));
