// Khronos glTF Validator on one GLB; prints a JSON summary.
// Usage: node validate_glb.mjs <file.glb>
import { readFile } from 'node:fs/promises';
import validator from 'gltf-validator';

const path = process.argv[2];
if (!path) {
    console.error('usage: node validate_glb.mjs <file.glb>');
    process.exit(2);
}
const report = await validator.validateBytes(new Uint8Array(await readFile(path)), {
    maxIssues: 100,
    format: 'glb'
});
console.log(JSON.stringify({
    validator: report.validatorVersion,
    errors: report.issues.numErrors,
    warnings: report.issues.numWarnings,
    infos: report.issues.numInfos,
    hints: report.issues.numHints,
    messages: report.issues.messages.map((m) => ({
        code: m.code, severity: m.severity, pointer: m.pointer ?? null, message: m.message
    }))
}, null, 2));
