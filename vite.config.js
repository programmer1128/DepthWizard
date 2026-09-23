import { defineConfig } from 'vite'

export default defineConfig({
  // No plugins imported here to avoid "Module not found" errors.
  // Vite works fine without explicit plugins for basic proxying.
  
  server: {
    proxy: {
      '/api': {
        target: 'http://localhost:8080',
        changeOrigin: true,
        // CRITICAL FIX: Increase timeout to 2 minutes (120000 ms)
        // Default is often too short for your 36s Modal processing.
        timeout: 120000, 
        configure: (proxy, _options) => {
          proxy.on('error', (err, _req, _res) => {
            console.log('proxy error', err);
          });
          proxy.on('proxyReq', (proxyReq, req, _res) => {
            console.log('Sending Request to Backend:', req.method, req.url);
          });
          proxy.on('proxyRes', (proxyRes, req, _res) => {
            console.log('Received Response from Backend:', proxyRes.statusCode, req.url);
          });
        }
      }
    }
  }
})