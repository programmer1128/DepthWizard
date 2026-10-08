# Deploying DepthWizard (backend + frontend)

Two checkouts of `github.com/programmer1128/DepthWizard`:

| Part | Branch | Server path | Runs as |
|---|---|---|---|
| Backend (`drogon_service/gis_service`) | `new_flow_microservice_aritra` | `/opt/depthwizard/backend` | systemd service `depthwizard-backend` on `127.0.0.1:8081` |
| Frontend (repository root) | `front_final_aritra` | `/opt/depthwizard/frontend` | static files in `/var/www/depthwizard`, served by NGINX |
| Object store | — | `/var/lib/depthwizard/minio` | systemd service `minio` on `127.0.0.1:9000` |

The browser only talks to NGINX. NGINX serves the frontend and forwards
`/api/` to the backend (same origin, no CORS). GLBs and raster exports are
returned as `/api/v1/download/...` paths, so MinIO never needs to be public.

```
browser ──► NGINX :80/:443 ──► /           → /var/www/depthwizard (frontend build)
                           └─► /api/...    → gis_service 127.0.0.1:8081 ──► MinIO 127.0.0.1:9000
                                                                       └─► Modal (models, SAT2LoD2),
                                                                           Earth Search / AWS (Sentinel-2),
                                                                           OpenTopography, Copernicus DEM
```

## Settings

`gis_service` reads its settings itself at start-up, so `./gis_service` needs
no `export`s:

1. variables already in the environment (an `export`, a systemd `Environment=`),
2. `$DEPTHWIZARD_ENV_FILE` if set,
3. `deploy/secrets.env` — credentials, **not in git** (template: `secrets.env.example`),
4. `deploy/depthwizard.env` — the validated production flags (urban, terrain,
   sparse and forest scenes), in git.

Earlier sources win, so one `export DEPTHWIZARD_X=...` overrides a file value.
`deploy/` is found next to the build directory (`build-release/../deploy`).

## One-time server setup (Ubuntu 22.04/24.04)

```bash
# 1. User and folders
sudo useradd --system --create-home --home-dir /opt/depthwizard depthwizard
sudo mkdir -p /var/lib/depthwizard/minio /etc/depthwizard /var/www/depthwizard
sudo chown -R depthwizard:depthwizard /opt/depthwizard /var/lib/depthwizard

# 2. Code (two checkouts of the same repository)
sudo -u depthwizard git clone -b new_flow_microservice_aritra git@github.com:programmer1128/DepthWizard.git /opt/depthwizard/backend
sudo -u depthwizard git clone -b front_final_aritra          git@github.com:programmer1128/DepthWizard.git /opt/depthwizard/frontend

# 3. Build tools and libraries
sudo apt install -y build-essential cmake git pkg-config nginx rsync \
    libgdal-dev gdal-bin libcurl4-openssl-dev libssl-dev zlib1g-dev uuid-dev \
    libjsoncpp-dev libeigen3-dev libopencv-dev libcgal-dev libomp-dev
# Node.js 20+ for the frontend build (e.g. from NodeSource), then:  node -v
# Not in apt at the versions used here; build from source and `sudo make install`:
#   Drogon (https://github.com/drogonframework/drogon), Draco (google/draco),
#   AWS SDK for C++ with -DBUILD_ONLY=s3, Halide (or its release tarball).
```

**GDAL must include GEOS.** SAT2LoD2 footprints are validated and repaired
with OGR geometry operations, which need GEOS. Without it, every SAT2LoD2
building is rejected ("SAT2LoD2 segment N: invalid footprint"), and only the
coarser native buildings remain. The backend logs an error at start-up when
GEOS is missing. If you build GDAL from source, install `libgeos-dev` first and
configure with `-DCMAKE_BUILD_TYPE=Release -DGDAL_USE_GEOS=ON`, so CMake fails
instead of silently leaving GEOS out. To check:
`ldd /usr/local/lib*/libgdal.so.* | grep geos` must list `libgeos_c`, and
`ogrinfo --version` must not say "debug build".

```bash
# 4. MinIO (object store for GLBs and rasters)
sudo wget -O /usr/local/bin/minio https://dl.min.io/server/minio/release/linux-amd64/minio
sudo chmod +x /usr/local/bin/minio
B=/opt/depthwizard/backend/drogon_service/gis_service
sudo cp $B/deploy/systemd/minio.env.example /etc/depthwizard/minio.env
sudo nano /etc/depthwizard/minio.env          # choose MINIO_ROOT_USER / MINIO_ROOT_PASSWORD
sudo chmod 600 /etc/depthwizard/minio.env
sudo cp $B/deploy/systemd/minio.service /etc/systemd/system/
sudo systemctl daemon-reload && sudo systemctl enable --now minio

# 5. Backend secrets: same MinIO user/password, plus the OpenTopography key
sudo -u depthwizard cp $B/deploy/secrets.env.example $B/deploy/secrets.env
sudo -u depthwizard nano $B/deploy/secrets.env
sudo chmod 600 $B/deploy/secrets.env

# 6. Backend build and service (the bucket is created on first start)
sudo -u depthwizard $B/deploy/scripts/build_backend.sh
sudo cp $B/deploy/systemd/depthwizard-backend.service /etc/systemd/system/
sudo systemctl daemon-reload && sudo systemctl enable --now depthwizard-backend
curl http://127.0.0.1:8081/api/v1/ping

# 7. Frontend build and NGINX
FRONTEND_DIR=/opt/depthwizard/frontend $B/deploy/scripts/build_frontend.sh
sudo cp $B/deploy/nginx/depthwizard.conf /etc/nginx/sites-available/depthwizard
sudo ln -sf /etc/nginx/sites-available/depthwizard /etc/nginx/sites-enabled/depthwizard
sudo rm -f /etc/nginx/sites-enabled/default
sudo nano /etc/nginx/sites-available/depthwizard     # server_name your.domain
sudo nginx -t && sudo systemctl reload nginx
# HTTPS: sudo apt install certbot python3-certbot-nginx && sudo certbot --nginx
```

## Updating after a `git push`

```bash
sudo -u depthwizard /opt/depthwizard/backend/drogon_service/gis_service/deploy/scripts/update.sh
```

It pulls both checkouts, rebuilds the backend (Release) and the frontend,
publishes `dist/` to `/var/www/depthwizard`, restarts `depthwizard-backend`
and reloads NGINX. (The `depthwizard` user needs sudo for the publish,
restart and reload steps, or run the three steps by hand.)

## Local development (two terminals)

```bash
# Terminal 1: MinIO, then the backend (no exports needed)
minio server ~/minio_data &
cd drogon_service/gis_service/build-integration && ./gis_service

# Terminal 2: the frontend; Vite forwards /api to 127.0.0.1:8081
cd ~/Desktop/frontend_service && npm run dev        # http://localhost:5173
```

`DEPTHWIZARD_BACKEND_URL` (frontend `.env.local`) points the dev proxy
elsewhere. `VITE_API_BASE` makes the browser call a backend on another
origin directly; list that origin in the backend's `DEPTHWIZARD_CORS_ORIGINS`
and set `DEPTHWIZARD_LISTEN_ADDRESS=0.0.0.0`.

## API used by the frontend

| Method | Path | Purpose |
|---|---|---|
| POST | `/api/v1/processor` | GeoTIFF upload (`image` field) → `{uuid, glb_url}` |
| POST | `/api/v1/processor/normal-image` | JPG/PNG upload |
| POST | `/api/v1/global-map/geotiff` | `{bbox:[W,S,E,N], width, height, maxCloudCoverage}` → Sentinel-2 RGB GeoTIFF (UTM), then submitted to `/api/v1/processor` |
| GET | `/api/v1/download/{file}` | `mesh_<uuid>.glb`, raster exports (`*.tif`), `buildings_<uuid>.json` |
| GET | `/api/v1/processor/exports/{uuid}` | raster export status |
| POST | `/api/height/single`, `/api/height/compare` | height inspection / comparison |
| GET | `/api/v1/ping` | health check |

The global map uses Copernicus Sentinel-2 L2A (open licence) from the public
Element84 Earth Search catalogue and the AWS open-data bucket: no
credentials. Its imagery is 10 m per pixel, so it suits terrain and forest;
individual buildings need sub-metre uploads. Attribution is returned in the
`X-Imagery-Attribution` header ("Contains modified Copernicus Sentinel data").

## Operations

- Logs: `journalctl -u depthwizard-backend -f` (level: `DEPTHWIZARD_LOG_LEVEL`).
- Debug artefacts for a scene: set `DEPTHWIZARD_DIAGNOSTICS=1` and
  `DEPTHWIZARD_VEGETATION_DIAGNOSTICS=1` in `secrets.env` (or the unit),
  restart; files land in `build-release/reconstruction_diagnostics/<uuid>/`.
- "GLB file not found" / upload failures: MinIO down or wrong
  `DEPTHWIZARD_MINIO_*` values (`systemctl status minio`).
- Global map 502: the server cannot reach `earth-search.aws.element84.com` or
  `sentinel-cogs.s3.us-west-2.amazonaws.com` (outbound HTTPS).
- A reconstruction can take several minutes; NGINX (1300 s), the backend
  (`idle_connection_timeout` 1200 s) and the frontend (20 min) are sized for it.
