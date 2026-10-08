# Context for the VPS deployment session (DepthWizard)

You are deploying DepthWizard on this Linux VPS. The code is finished and
tested on the developer's machine; your job is deployment only: get the
backend service running, then MinIO, the frontend build and NGINX, and verify
end to end. Do not change application logic, pipeline flags or geometry code.

## Hard rules

- **Never print, echo, cat, log or paste credentials.** That covers
  `deploy/secrets.env`, `/etc/depthwizard/minio.env`, the MinIO keys, the
  OpenTopography key, and the fallback keys inside
  `drogon_service/gis_service/DataHandlers/MiniIOClient.cc`. Refer to files and
  variable names only. To check that a value is set, use
  `grep -c '^NAME=.\+' file`, never the value itself.
- Do not commit or push anything from the server. Treat the checkouts as read-only apart from build outputs.
- Do not change `deploy/depthwizard.env` unless asked. It holds the
  validated production flags. Overrides belong in `deploy/secrets.env` or in
  the systemd unit.
- Ask before deleting data in `/var/lib/depthwizard` or opening extra firewall ports.

## Layout (all in place already)

| Part | Location | Notes |
|---|---|---|
| Backend checkout | `/opt/depthwizard/backend` | branch `new_flow_microservice_aritra`; the service code is in `drogon_service/gis_service` |
| Frontend checkout | `/opt/depthwizard/frontend` | branch `front_final_aritra` (Vite app at repository root) |
| Backend binary | `/opt/depthwizard/backend/drogon_service/gis_service/build-release/gis_service` | built by `deploy/scripts/build_backend.sh` (Release, tests off) |
| Settings | `.../gis_service/deploy/depthwizard.env` (in git), `.../deploy/secrets.env` (not in git, chmod 600, owner depthwizard) | read by gis_service itself at start-up; real env vars override |
| systemd | `/etc/systemd/system/depthwizard-backend.service` (copied from `deploy/systemd/`) | runs as user `depthwizard`, WorkingDirectory = `build-release` |
| MinIO | `deploy/systemd/minio.service`, env `/etc/depthwizard/minio.env`, data `/var/lib/depthwizard/minio` | listens on 127.0.0.1:9000 |
| NGINX site | `deploy/nginx/depthwizard.conf` | serves `/var/www/depthwizard`, proxies `/api/` → 127.0.0.1:8081 |
| Full guide | `deploy/README.md` | read it first |

Architecture: browser → NGINX (:80/443). `/` serves the static frontend
build and `/api/` goes to `gis_service` on 127.0.0.1:8081. The backend stores
GLBs and rasters in MinIO on 127.0.0.1:9000 and returns them as same-origin
`/api/v1/download/...` URLs, so MinIO is never public. It calls outbound
HTTPS services: Modal (model inference and SAT2LoD2), the Earth Search STAC
API plus `sentinel-cogs.s3.us-west-2.amazonaws.com` (Sentinel-2 for the
bounding-box feature), OpenTopography and the Copernicus DEM on S3.

## Steps already completed by the user

1. Cloned both branches into `/opt/depthwizard/{backend,frontend}`.
2. Created `/etc/depthwizard/minio.env` and `deploy/secrets.env`
   (chmod 600, owner depthwizard). Contents not verified; check that they are
   filled in without printing them.
3. Ran `deploy/scripts/build_backend.sh` as user `depthwizard`, installed the
   unit, then ran `systemctl enable --now depthwizard-backend`.

## Current failure

```
depthwizard-backend.service: ExecStart=.../build-release/gis_service (code=exited, status=127)
Active: activating (auto-restart), CPU: 4ms
```

An exit status of 127 straight after exec almost always means the dynamic
loader cannot find a shared library ("error while loading shared libraries")
or cannot read it. The developer's build links source-installed libraries
from `/usr/local/lib64`: Drogon/Trantor, the AWS SDK for C++ (s3 plus the
aws-c-* and aws-crt-cpp libraries), Halide, and possibly Draco. Ubuntu's
loader searches `/usr/local/lib` but **not** `/usr/local/lib64` by default.

Diagnose (none of these print secrets):

```bash
B=/opt/depthwizard/backend/drogon_service/gis_service
ls -l $B/build-release/gis_service                 # binary exists and is executable?
sudo -u depthwizard $B/build-release/gis_service   # shows the exact loader error (Ctrl-C if it starts)
ldd $B/build-release/gis_service | grep "not found"
journalctl -u depthwizard-backend -n 50 --no-pager
```

Typical fixes:

```bash
# Libraries in /usr/local/lib64 (or another prefix) not registered:
echo /usr/local/lib64 | sudo tee /etc/ld.so.conf.d/usr-local-lib64.conf
echo /usr/local/lib   | sudo tee /etc/ld.so.conf.d/usr-local-lib.conf
sudo ldconfig
ldd $B/build-release/gis_service | grep "not found"     # must print nothing

# Libraries installed under a home directory or root-only path: reinstall
# them to /usr/local (cmake --install), or make them readable to depthwizard.

# Build outputs owned by root (if anything was built with sudo/root):
sudo chown -R depthwizard:depthwizard /opt/depthwizard
```

Then:

```bash
sudo systemctl restart depthwizard-backend
systemctl status depthwizard-backend --no-pager
curl -s http://127.0.0.1:8081/api/v1/ping   # expect {"message":"Drogon GIS Engine is online...","status":"success"}
```

On a successful start the log shows `[DepthWizard] settings file .../deploy/secrets.env (N entries)`,
`... deploy/depthwizard.env (18 entries)`, `running on 127.0.0.1:8081`, and a
`[MinioClient] ... Initialized (127.0.0.1:9000)` line. If the log says
`bucket terrain-assets unavailable`, MinIO is not running or its credentials
don't match (see below); the backend still starts.

## Remaining deployment steps (see deploy/README.md for exact commands)

1. **Build dependencies**, if the build itself fails. Ubuntu apt:
   `build-essential cmake pkg-config git libgdal-dev gdal-bin
   libcurl4-openssl-dev libssl-dev zlib1g-dev uuid-dev libjsoncpp-dev
   libeigen3-dev libopencv-dev libcgal-dev libgmp-dev libmpfr-dev libomp-dev`.
   From source with `cmake --install` into `/usr/local`: Drogon (bundles
   Trantor), Draco, the AWS SDK for C++ (`-DBUILD_ONLY=s3`), Halide (or its
   release tarball). GDAL **must be built with GEOS**
   (`-DGDAL_USE_GEOS=ON -DCMAKE_BUILD_TYPE=Release`, with `libgeos-dev` installed).
   Without it, every SAT2LoD2 building is rejected as "invalid footprint".
   The developer's machine has GDAL 3.12, OpenCV 4.13,
   Halide 22, CMake 4.3, GCC 16 and C++20; any reasonably recent versions
   should work, and GDAL must be 3.4 or newer. Run `sudo ldconfig` after each
   source install.
2. **MinIO.** Install `/usr/local/bin/minio`, copy `deploy/systemd/minio.service`,
   then `systemctl enable --now minio`. The `MINIO_ROOT_USER` and
   `MINIO_ROOT_PASSWORD` in `/etc/depthwizard/minio.env` must equal
   `DEPTHWIZARD_MINIO_ACCESS_KEY` and `DEPTHWIZARD_MINIO_SECRET_KEY` in
   `deploy/secrets.env`. If those two are empty, the backend falls back to the
   development keys compiled into `MiniIOClient.cc`. Prefer setting them;
   don't print either file. The backend creates the `terrain-assets` bucket
   itself on start-up; restart the backend after MinIO is up.
3. **Frontend.** Node.js 20.19+ or 22.12+ is required (Vite 8). Run
   `FRONTEND_DIR=/opt/depthwizard/frontend $B/deploy/scripts/build_frontend.sh`,
   which runs `npm ci`, `npm run build`, then rsyncs `dist/` to `/var/www/depthwizard`.
   Leave `VITE_API_BASE` unset: the app is same-origin.
4. **NGINX.** Copy `deploy/nginx/depthwizard.conf` to
   `/etc/nginx/sites-available/depthwizard`, symlink it into `sites-enabled`,
   remove `default`, set `server_name`, then `nginx -t` and reload. For TLS
   use certbot (`--nginx`). Keep `client_max_body_size 200m` and the
   1300 s proxy timeouts: one reconstruction can take several minutes.
5. **Firewall.** Expose only 80 and 443 (and SSH). Ports 8081 and 9000/9001
   must stay local; the backend already binds 127.0.0.1.

## Verification

```bash
curl -s http://127.0.0.1:8081/api/v1/ping
curl -s -o /dev/null -w "%{http_code}\n" http://127.0.0.1/                 # 200 (frontend via NGINX)
curl -s http://127.0.0.1/api/v1/ping                                       # via NGINX
# Bounding-box imagery (Sentinel-2; about 10-20 s):
curl -s -X POST http://127.0.0.1/api/v1/global-map/geotiff -H 'Content-Type: application/json' \
  -d '{"bbox":[77.20,28.60,77.23,28.63],"width":1024,"height":1024,"maxCloudCoverage":20}' -o /tmp/gm.tif -D - | grep -i "HTTP\|x-imagery"
# Full pipeline (several minutes; needs MinIO and outbound HTTPS to Modal):
curl -s -X POST -F image=@/tmp/gm.tif http://127.0.0.1/api/v1/processor     # -> {"uuid":..., "glb_url":"/api/v1/download/mesh_<uuid>.glb"}
curl -s -o /dev/null -w "%{http_code} %{size_download}\n" http://127.0.0.1/api/v1/download/mesh_<uuid>.glb
```

Then open the site in a browser. Try a GeoTIFF upload, and the Global Map
(Insert → "Select from Global Map", draw a box, generate).

## Useful facts

- Backend settings are read in this order, earliest wins: process env,
  `$DEPTHWIZARD_ENV_FILE`, `deploy/secrets.env`, then `deploy/depthwizard.env`.
- Debugging a scene: set `DEPTHWIZARD_DIAGNOSTICS=1` and
  `DEPTHWIZARD_VEGETATION_DIAGNOSTICS=1` (in `secrets.env` or a unit
  `Environment=` line) and restart. Output goes to
  `build-release/reconstruction_diagnostics/<uuid>/`. Use
  `DEPTHWIZARD_LOG_LEVEL=DEBUG` for more log.
- `config.json` (drogon settings, `idle_connection_timeout` 1200 s) is found
  as `build-release/../config.json`. drogon also serves static files from its
  working directory, which is why the backend must stay on 127.0.0.1 with
  only `/api/` proxied.
- Updates later: `sudo -u depthwizard $B/deploy/scripts/update.sh` pulls both
  checkouts, rebuilds, publishes, restarts and reloads. It needs sudo for the
  last steps.
- Endpoints used by the frontend: `POST /api/v1/processor`,
  `POST /api/v1/processor/normal-image`, `POST /api/v1/global-map/geotiff`,
  `GET /api/v1/download/{file}`, `GET /api/v1/processor/exports/{uuid}`,
  `POST /api/height/single`, `POST /api/height/compare`, `GET /api/v1/ping`.
