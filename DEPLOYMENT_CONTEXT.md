# DepthWizard: deployment context

Read this before changing or deploying anything. It describes the system as
of 2026-09-30, how its parts connect, and what must change for a remote
server. Paths are from the original development machine (`/home/aritra/...`);
adjust them to wherever the code lives on the server.

## What the system is

DepthWizard is a Smart India Hackathon 2025 entry for ISRO problem 26175,
"single-view height estimation and 3D flythrough". A user uploads one
georeferenced RGB image (a GeoTIFF). The system estimates a DSM, DTM and nDSM
and builds a GLB 3D scene: terrain plus buildings. It then answers per-click
height queries and compares the DSM with a reference DEM.

Rules that constrain every change:
- **No OpenStreetMap or other human-mapped data.** Only the image, the models
  and backend maths. The SAT2LoD2 OSM step is disabled on purpose.
- **Report metrics honestly.** Earlier code capped accuracy at 92% and a
  validation script subtracted 0.03 from Pearson; both were removed. Never
  reintroduce caps or offsets. Judging is 50% DSM accuracy against LiDAR and
  50% visualization.
- The render multiplies building heights by 2.25 (`heightScaleMultiplier`) for
  visual relief. Exported rasters and height queries use unscaled metres.

## Architecture

```
Browser ── Vite/Three.js frontend (dev server :5173)
   │  POST /api/v1/processor (multipart "image"), /api/height/single, /api/height/compare
   ▼
drogon C++ backend "gis_service" (0.0.0.0:8081)
   ├─► Modal: nDSM depth model (HTTPS)      ─┐ both hard-coded, owned by the
   ├─► Modal: semantic segmentation (HTTPS) ─┘ "satadru-ghosh-cse28" workspace
   ├─► AWS Terrain Tiles (public S3, via GDAL /vsicurl/) — terrain base DEM
   ├─► Modal: SAT2LoD2 building reconstruction ("programmer1128" workspace)
   │      or a local uvicorn server on 127.0.0.1:8000 (same code)
   ├─► MinIO (127.0.0.1:9000, bucket "terrain-assets") — GLB + rasters
   └─► OpenTopography API (COP30) — only for /api/height/compare
Browser then loads the GLB directly from MinIO via a presigned URL.
```

One upload: ingest the GeoTIFF (it must use a projected CRS in metres) →
preprocess → tile and run the nDSM and semantic models on Modal → fetch the
terrain DEM → fuse the DSM → send nDSM, building mask and image to SAT2LoD2 →
import its rectangles as buildings, with heights from the nDSM → build and
upload the GLB → respond `{uuid, glb_url}`. After responding, a background
worker uploads the rasters and a building index to MinIO.

If SAT2LoD2 fails for any reason, the backend silently falls back to native
building reconstruction, which renders large blocky boxes. The backend log
line `building_source=sat2lod2|native` tells which ran; the line above a
`native` result gives the reason.

## Code locations and what must reach the server

| Component | Location | Git |
|---|---|---|
| Backend (C++) | `DepthWizard/drogon_service/gis_service/` | `github.com/programmer1128/DepthWizard`, branch `new_flow_microservice_aritra` |
| Frontend | `/home/aritra/Desktop/frontend_service/` (a separate checkout) | same repo, branch `front_final_aritra` |
| SAT2LoD2 service | `/home/aritra/LOD2BuildingModel/` | clone of the upstream `GDAOSU/LOD2BuildingModel`; **all DepthWizard changes are uncommitted local files** |

Much of the recent work was **uncommitted** on the development machine.
Commit and push, or copy, before deploying, and check `git status` on the
server. The SAT2LoD2 folder cannot be pushed to its upstream: copy it, or fork
it. Its DepthWizard files are `pipeline.py`, `server.py`,
`sat2lod2_worker.py`, `model_deploy.py`, plus edits to `code/building_polygon.py`,
`code/building_modelfit.py`, `code/SAT2LoD2.py` and `code/hrnet_seg.py`.
Leave out `Miniforge3-Linux-x86_64.sh` (124 MB) and `sat2lod2_framework.xml`.

`gis_service/build-integration/` is tracked in git, binaries included. Do
**not** run binaries built elsewhere; rebuild on the server.

## Backend: build, test, run

Dependencies (CMake `find_package`): Drogon (with jsoncpp, trantor), ZLIB,
GDAL, CURL, draco, AWS SDK C++ (`s3`), OpenMP, Halide, Eigen3, OpenCV (core,
imgproc, imgcodecs, photo), CGAL. Tests use GTest. C++20/23, GCC.

```sh
cd drogon_service/gis_service
cmake -S . -B build-integration -DCMAKE_BUILD_TYPE=Release
cmake --build build-integration -j"$(nproc)"
ctest --test-dir build-integration -j"$(nproc)"   # 202 tests, all must pass
cd build-integration && ./gis_service                # run FROM here
```

- `main.cc` loads `../config.json` **relative to the working directory**, so
  start the binary from `build-integration/`. It listens on `0.0.0.0:8081`;
  the `listeners` block in `config.json` is commented out.
- `config.json` sets `idle_connection_timeout: 1200`. Keep it. Drogon also
  drops a request *still being processed* once this runs out, and a full
  upload can take several minutes. At the old 60 s value, frontends saw
  "disconnects".
- The upload body limit is 200 MB (`setClientMaxBodySize` in `main.cc`, which
  overrides `config.json`).
- The `Loader` plugin initialises GDAL and the MinIO client. It sets
  `CPL_VSIL_CURL_ALLOWED_EXTENSIONS=tif` process-wide; code reading non-TIFF
  objects over `/vsicurl/` must override it thread-locally (see
  `HeightService/HeightRasterStore.cc`).

Environment variables (all optional):

| Variable | Default | Purpose |
|---|---|---|
| `DEPTHWIZARD_SAT2LOD2` | on | `0` disables SAT2LoD2 (native buildings only) |
| `DEPTHWIZARD_SAT2LOD2_URL` | the programmer1128 Modal URL | SAT2LoD2 base URL; `http://127.0.0.1:8000` selects the local server |
| `DEPTHWIZARD_SAT2LOD2_TRANSPORT` | inferred from URL | `modal` (multipart upload, inline JSON) or `local` (shared file paths) |
| `DEPTHWIZARD_SAT2LOD2_TIMEOUT_S` | 900 | total SAT2LoD2 budget, including following Modal redirects |
| `DEPTHWIZARD_DIAGNOSTICS` | on | `0` disables per-job debug rasters |
| `DEPTHWIZARD_DIAGNOSTICS_DIR` | `./reconstruction_diagnostics` | diagnostic output; **never cleaned up**, so set it or disable it on a server |
| `DEPTHWIZARD_PRESENTATION` | automatic | force `flat_urban` or `metric` |
| `OPENTOPOGRAPHY_API_KEY` | a key hard-coded in `HeightService/ReferenceDemService.cc` | COP30 downloads for `/api/height/compare` |

## MinIO

- The endpoint `127.0.0.1:9000` (HTTP), region `us-east-1`, and the access
  key and secret are **hard-coded** in `DataHandlers/MiniIOClient.cc`. Do not
  copy the credentials into chats or docs.
- Bucket `terrain-assets` must exist. Per job UUID it holds:
  - `mesh_<uuid>.glb`
  - `heights_<uuid>.tif` (absolute DSM), `dtm_`, `ndsm_`, `confidence_`
  - `buildings_<uuid>.tif` (building ID per pixel) and `buildings_<uuid>.json`
    (per-building heights, keyed by the GLB's `_FEATURE_ID_0`)
- The backend returns **presigned URLs** (for example `glb_url`), and the
  browser downloads from them directly. They are signed for host
  `127.0.0.1:9000`, and SigV4 signs the host, so the URL cannot simply be
  rewritten. See the first item under "Required changes".

## SAT2LoD2 service

Only the 2D geometry comes from SAT2LoD2: footprints and their decomposition
into rectangles, returned as `buildings.json` (schema
`depthwizard.sat2lod2.v1`). The backend (`BuildingReconstruction/Sat2Lod2Importer`)
turns each rectangle into its own building part and measures every height from
its own nDSM. Do not extrude the semantic segment outlines over the
rectangles, and do not fill uncovered footprint areas by default: both merged
buildings into slabs and paved courtyards.

Deploy on Modal from the SAT2LoD2 folder: `modal deploy model_deploy.py`
(app `sat2lod2-reconstruction`). Points that have each caused outages:
- **NumPy must be 1.23.5.** SAT2LoD2 builds ragged arrays and uses `np.int`,
  which fail from NumPy 1.24; the image pins it and `pipeline.py` refuses to
  start otherwise. Do not "fix" this by patching single lines; there are many
  such spots. Other pins: SciPy 1.15.2, opencv-python-headless 4.11.0.86,
  scikit-image 0.24.0.
- **CPU by default.** The backend always sends its own building label, so
  SAT2LoD2 never runs its HRNet detector or uses a GPU. Requesting GPUs only
  caused minutes of queueing. `SAT2LOD2_GPU=A10G modal deploy model_deploy.py`
  opts back in. Without a GPU the image uses CPU PyTorch wheels.
- **Modal's 150 s web limit.** After 150 s, including queue and cold start,
  Modal answers 303 with a result URL. `Sat2Lod2ModalTransport::send` follows
  these redirects, using a fresh HTTP client per poll.
- **Warm-up.** The backend sends `GET /api/v1/health` to SAT2LoD2 the moment
  an upload arrives, so the container starts while inference runs.
- Each job runs in a fresh `sat2lod2_worker.py` process in its own session,
  with a job timeout (`SAT2LOD2_JOB_TIMEOUT_S`, default 600) and a
  per-segment decomposition budget (`SAT2LOD2_SEGMENT_BUDGET_S`, default 90).
  Pool workers forked inside uvicorn inherit its SIGTERM handler and
  deadlock, and OpenCV threading must be off before forking; both are
  handled in `pipeline.py` and `server.py`.
- `scaledown_window=300` keeps a container warm for 5 minutes. For live demos,
  raising it or keeping one container always on removes cold starts; that is
  a cost decision.
- Local alternative: `uvicorn server:app --port 8000` from the SAT2LoD2
  folder, inside the `sat2lod2` conda env (Python 3.10, NumPy 1.23.5), with
  `DEPTHWIZARD_SAT2LOD2_URL=http://127.0.0.1:8000`.

The nDSM and semantic model endpoints are hard-coded in
`ImageTilingService/NdsmInference/NdsmInferenceConfig.cc` and
`ImageTilingService/SemanticInference/SemanticInferenceConfig.cc`. They run in
a different Modal workspace (`satadru-ghosh-cse28`) that this deployment does
not control.

## Frontend

Vanilla Three.js with Vite (`npm install`, `npm run dev` or `npm run build`,
Node 22). The API base comes from `src/services/backend.js`:
`VITE_API_BASE`, defaulting to `http://localhost:8081`. It is baked in at build
time, so set it when running `vite build` for the server. The upload request
allows 20 minutes and shows elapsed time.

Height clicks: the frontend raycasts meshes only (the white outlines are line
primitives) and reads the building ID from `_feature_id_0` on roof and wall
faces. It posts `{uuid, x, y, feature_id?}`, with `x, y` in metres east and
south of the terrain's north-west corner. The answer is either
`kind: "building"` (`building_height_meters`: that building only, unscaled,
plus roof and base elevations) or `kind: "terrain"` (`elevation_meters`,
absolute DSM).

## API summary

- `POST /api/v1/processor`: multipart field `image` (GeoTIFF) → `{uuid, glb_url}`.
- `GET /api/v1/processor/exports/<uuid>`: status of dsm, dtm, ndsm,
  confidence and buildings, with presigned URLs once ready. Height queries
  before export finishes return 409.
- `POST /api/height/single {uuid, x, y, feature_id?}`.
- `POST /api/height/compare {uuid, tag, x, y}`, with `tag` one of
  `opentopography` (COP30), `bhuvan`, or `upload` (multipart with a reference
  GeoTIFF). It returns scene-wide RMSE, MAE, Pearson, median, the percentage
  within ±2 m, anomaly counts (errors over 50 m are excluded from the headline
  metrics and reported in a `raw` block), point heights, and `diff_map_base64`
  (PNG). Results are cached per scene and tag. The logic matches the team's
  Python validation script exactly (checked on real data), minus the old
  Pearson offset.
- Errors are JSON `{status: "error", message}` with 400, 404, 409, 502 or 500.

Honest caveat for presentations: the terrain base is itself a 30 m global DEM,
so comparing against COP30 mostly measures agreement between two global DEMs.
Report accuracy against independent LiDAR where possible.

## Required changes for a remote server

These are not done yet. A setup that only works on `localhost` will fail for
any other browser.

1. **MinIO URLs reachable by browsers.** Make the MinIO endpoint (and
   credentials) configurable, via environment variables read in
   `DataHandlers/MiniIOClient.cc`, and set it to a hostname that both the
   backend and users' browsers can reach (for example
   `https://minio.example.com` behind a reverse proxy that preserves the
   `Host` header). Otherwise every `glb_url` points at `127.0.0.1:9000`.
2. **CORS.** `main.cc` hard-codes `Access-Control-Allow-Origin:
   http://localhost:5173` in two places. Make it configurable and set it to
   the frontend's real origin.
3. **Frontend API base.** Build with `VITE_API_BASE=https://<backend-host>`.
4. **HTTPS consistency.** If the frontend is served over HTTPS, browsers block
   HTTP calls to the backend and MinIO (mixed content). All three need HTTPS,
   typically one reverse proxy such as nginx with TLS.
5. **Reverse proxy limits** in front of the backend:
   `proxy_read_timeout`/`proxy_send_timeout` ≥ 1200 s (uploads legitimately
   take minutes), `client_max_body_size` ≥ 200M, and no response buffering
   limits that truncate GLBs.
6. **Secrets.** Move the MinIO credentials and the OpenTopography key out of
   source into environment variables or a secrets file excluded from git.
7. **Process management.** Run MinIO and `gis_service` as services (for
   example systemd) with the working directory set to `build-integration/`,
   restart on failure, and set `DEPTHWIZARD_DIAGNOSTICS_DIR` or
   `DEPTHWIZARD_DIAGNOSTICS=0`.
8. **Bucket.** Create `terrain-assets` in the server's MinIO.

## Verification after deploying

1. `ctest` passes on the server build.
2. Upload a known scene. The backend log shows `building_source=sat2lod2`,
   and the response has a `glb_url` that opens from a browser on another
   machine.
3. The Modal logs for `sat2lod2-reconstruction` show a
   `GET /api/v1/health` right after the upload (the wake-up), then all six
   SAT2LoD2 steps and `POST /api/v1/reconstruct -> 200`. Read them with
   `modal app logs <app-id> --since <ISO time>`; find the app ID with
   `modal app list`.
4. `GET /api/v1/processor/exports/<uuid>` reaches `ready`, including
   `buildings`.
5. Clicking a building shows only that building's height; clicking terrain
   shows the absolute elevation. Compare returns metrics and a visible diff
   map.

More detail on reconstruction, diagnostics and the height API:
`drogon_service/gis_service/URBAN_RECONSTRUCTION.md`.
