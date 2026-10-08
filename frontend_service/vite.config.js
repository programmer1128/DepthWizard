import { defineConfig, loadEnv } from 'vite';

// The browser always calls /api/... on the page's own origin. In development
// the Vite server forwards those calls to the backend, so `npm run dev` and
// `./gis_service` can run in separate terminals without CORS. In production
// NGINX does the same (deploy/nginx/depthwizard.conf in the backend repo).
// A full reconstruction can take several minutes, hence the long timeouts.
export default defineConfig(({ mode }) => {
    const env = loadEnv(mode, process.cwd(), '');
    const backend = env.DEPTHWIZARD_BACKEND_URL || 'http://127.0.0.1:8081';
    const proxy = {
        '/api': {
            target: backend,
            changeOrigin: true,
            timeout: 21 * 60 * 1000,
            proxyTimeout: 21 * 60 * 1000
        }
    };
    return {
        server: { proxy },
        preview: { proxy }
    };
});
