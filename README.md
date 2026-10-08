# DepthWizard: Semantic-Aware Metric DSM & 3D Scene Reconstruction from 2D Imagery

[![Built for SIH 2026](https://img.shields.io/badge/SIH-2026-blue.svg)](https://www.sih.gov.in/)
[![C++20](https://img.shields.io/badge/Language-C%2B%2B20-00599C.svg?logo=cplusplus)](https://isocpp.org/)
[![Drogon](https://img.shields.io/badge/Framework-Drogon-red.svg)](https://drogon.org)
[![Three.js](https://img.shields.io/badge/Frontend-Three.js-black.svg?logo=three.js)](https://threejs.org/)
[![Modal](https://img.shields.io/badge/Inference-Modal%20GPU-green.svg)](https://modal.com/)

An end-to-end geospatial intelligence pipeline engineered for disaster management and rapid reconnaissance. **DepthWizard** translates single-view optical satellite and aerial imagery (from uncalibrated consumer formats to metric GeoTIFFs) into absolute, metric 3D Digital Surface Models (DSMs) and watertight building meshes delivered directly to an interactive WebGL interface in minutes.

---

## Live Links & Resources

* **Live Demo:** [depthwizard.aritra-projects.com](https://depthwizard.aritra-projects.com/)
* **GitHub Repository:** [github.com/programmer1128/DepthWizard](https://github.com/programmer1128/DepthWizard)
* **Technical Documentation:** [Google Drive Technical Report](https://drive.google.com/file/d/1fASZx6CBKb_z7G6r1q9pZRpXJZTnVuXI/view?usp=sharing)

---

## Problem & Value Proposition

During severe hydrometeorological and geological events (such as the floodplains of the Brahmaputra/Ganges or the landslide-prone slopes of the Western Ghats and Himalayas), emergency response is constrained by lack of current, high-resolution 3D data:
* **Conventional LiDAR / InSAR:** High metric accuracy, but mission tasking and post-processing take days or weeks at high recurring costs.
* **Open Global Elevation (Copernicus GLO-30, SRTM, CartoDEM):** Free and accessible, but published at ~30 m posting—too coarse to distinguish structural assets, road corridors, or flood embankments.
* **Standard Monocular Depth Models:** Predict relative, unitless depth with significant domain distortion over nadir/oblique overhead imagery.

**DepthWizard eliminates this trade-off** by coupling vision foundation models fine-tuned for remote sensing with open elevation models and computational geometry engines.

---

## Core Architecture

```text
                                 [ Optical Input ]
                      (GeoTIFF / JPG / PNG / Sentinel-2 Box)
                                         │
                                         ▼
                      ┌─────────────────────────────────────┐
                      │   Drogon C++ Ingestion & Tiling     │
                      │  (GDAL Reprojection & Validity Mask)│
                      └──────────────────┬──────────────────┘
                                         │
                   518x518 Overlapping   │  20% Stride
                   Tiles (Parallel RPC)  ▼
                      ┌─────────────────────────────────────┐
                      │      Modal Cloud GPU Inference      │
                      │  ├─ Depth Anything V2 + Scale Mod   │
                      │  ├─ GAMUS 6-Class Semantic Segment  │
                      │  └─ SAM 2.1 & KIBS Building Topology│
                      └──────────────────┬──────────────────┘
                                         │
                         Confidence-Weighted Hann Stitching
                                         │
                                         ▼
                      ┌─────────────────────────────────────┐
                      │   GDAL / OpenCV / CGAL Core Engine  │
                      │  ├─ Ground-Bias Residual Correction │
                      │  ├─ COP30 / CartoDEM Reference Fuse │
                      │  ├─ Planar Building Extrusion (LoD3)│
                      │  └─ Draco glTF / GLB Compression    │
                      └──────────────────┬──────────────────┘
                                         │
                               ┌─────────┴─────────┐
                               ▼                   ▼
                     [ MinIO S3 Object Store ]  [ Full Metric GeoTIFF ]
                     (Private Secure Storage)  (Background Delivery)
                               │
                               ▼ (Relative API Download)
                      ┌─────────────────────────────────────┐
                      │    NGINX Edge Proxy (Port 8081)     │
                      └──────────────────┬──────────────────┘
                                         │
                                         ▼
                      ┌─────────────────────────────────────┐
                      │        Interactive WebGL UI         │
                      │   (Three.js + NASA 3D Tiles Engine) │
                      │  ├─ Dynamic Water Flood Simulation  │
                      │  ├─ Route Elevation Profiles        │
                      │  └─ In-Browser RMSE / MAE Validation│
                      └─────────────────────────────────────┘
```

---

## Tech Stack

| Layer | Technologies & Libraries | Functionality |
| :--- | :--- | :--- |
| **Backend Core** | C++20, Drogon, CMake, GCC | Asynchronous, non-blocking coroutine-based REST orchestrator. |
| **Spatial & Geometry** | GDAL, CGAL, OpenCV, Halide | Raster ingest, UTM reprojection, watertight polygon arrangements, planar roof extraction, JIT heightmaps. |
| **ML Inference** | PyTorch, ONNX Runtime, Modal Cloud | Depth Anything V2, SAM 2.1, KIBS (Detectron2), GAMUS 6-class segmentation. |
| **Storage & Caching** | MinIO (AWS C++ SDK), S3 API | S3-compatible local bucket architecture for multi-textured `.glb` and GeoTIFFs. |
| **Frontend & 3D** | Three.js, Next.js / Vite, NASA 3DTilesRendererJS | Draco WebAssembly decoding, NASA-AMMOS 3D Tiles, shader-driven flood-fills. |
| **Infrastructure** | Ubuntu 24.04 LTS, NGINX, systemd | Edge reverse proxy, SSL termination, systemd auto-restart orchestration. |

---

## Key Features

1. **True Metric Height from a Single Image:** Fine-tuned Depth Anything V2 model with an integrated scale modulator trained on the GAMUS dataset, predicting normalized metric height above ground (m).
2. **Semantic Land-Cover Discrimination:** A 6-class semantic segmentation model (`ground`, `building`, `low_vegetation`, `water`, `road`, `other`) ensures vegetation crowns are never mistakenly extruded as architectural structures.
3. **Seam-Free Confidence Blending:** Large aerial rasters are partitioned into 518 x 518 tiles with 20% overlap, routed across parallel inference workers, and stitched using confidence-weighted 2D Hann windows.
4. **Autonomous Reference DEM Fusion:** Warps Copernicus GLO-30, SRTM, or ISRO CartoDEM data to match the image grid, computes median height bias over ground pixels, and fuses the result into an absolute bare-earth DSM.
5. **LoD3 Structural Extraction:** CGAL algorithms trace building boundaries, segment roof sections, and generate watertight polygonal meshes draped with the original optical texture.
6. **Built-in Quality Assurance:** Client-side spatial validation queries against OpenTopography / reference DEMs, delivering real-time Root Mean Square Error (RMSE), Mean Absolute Error (MAE), and Pearson correlation matrices.
7. **Disaster Simulation Suite:** Interactive water-level sliders for dynamic flood accumulation analysis, route corridor planning, and WASD free-fly terrain navigation.

---

## Measured Performance & Accuracy

Evaluated across verified bare-earth benchmarks (860,156 valid test pixels):

* **Mean Absolute Error (MAE):** 0.455 m
* **Root Mean Square Error (RMSE):** 1.374 m
* **Pearson Correlation (r):** 0.970
* **Tolerance Compliance:** 90.8% of test pixels within ±2.0 m of ground truth
* **End-to-End Processing Latency:** ~2.5 minutes for full 3D extraction and Draco packaging from upload

---


## Setup & Installation

### Prerequisites
* **Operating System:** Ubuntu 22.04 / 24.04 LTS
* **Compiler:** GCC / g++ 12+ (supporting C++20 standard)
* **Build System:** CMake 3.22+, Make/Ninja
* **Core Libraries:**
  ```bash
  sudo apt update && sudo apt install -y \
      libgdal-dev gdal-bin libcgal-dev libopencv-dev \
      libjsoncpp-dev uuid-dev zlib1g-dev libssl-dev
  ```

### 1. Build Halide & Draco
```bash
# Halide runtime (required for JIT heightmap processing)
git clone [https://github.com/halide/Halide.git](https://github.com/halide/Halide.git) && cd Halide
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -j$(nproc)
sudo cmake --install build

# Draco geometry compression
git clone [https://github.com/google/draco.git](https://github.com/google/draco.git) && cd draco
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -j$(nproc)
sudo cmake --install build
```

### 2. Configure Shared Linker
Ensure `/etc/ld.so.conf.d/depthwizard.conf` contains paths to non-standard shared libraries (e.g., `/usr/local/lib`), then execute:
```bash
sudo ldconfig
```

### 3. Build Drogon Backend
```bash
cd backend/drogon_service/gis_service
mkdir build-release && cd build-release
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . -j$(nproc)
```

### 4. Configure Secrets
Create `deploy/secrets.env` inside the working directory:
```env
S3_ENDPOINT="[http://127.0.0.1:9000](http://127.0.0.1:9000)"
S3_ACCESS_KEY="minioadmin"
S3_SECRET_KEY="minioadmin"
S3_BUCKET_NAME="depthwizard-models"
OPENTOPOGRAPHY_API_KEY="your_opentopo_token"
```

### 5. Frontend Build
```bash
cd ../../../../frontend
npm install
npm run build
```

---

## Deployment Configuration

### Systemd Backend Service
Deploy the application unit file to `/etc/systemd/system/depthwizard-backend.service`:

```ini
[Unit]
Description=DepthWizard Backend Service (Drogon Core)
After=network.target minio.service

[Service]
Type=simple
User=root
WorkingDirectory=/opt/depthwizard/backend/drogon_service/gis_service/build-release
Environment="LD_LIBRARY_PATH=/usr/local/lib"
ExecStart=/opt/depthwizard/backend/drogon_service/gis_service/build-release/gis_service
Restart=always
RestartSec=5
LimitNOFILE=65536

[Install]
WantedBy=multi-user.target
```

Reload and activate:
```bash
sudo systemctl daemon-reload
sudo systemctl enable --now depthwizard-backend
```

### NGINX Gateway Configuration
Configure `/etc/nginx/sites-available/depthwizard`:

```nginx
server {
    listen 80;
    server_name depthwizard.aritra-projects.com;

    root /opt/depthwizard/frontend/dist;
    index index.html;

    # Static UI and Draco WASM Assets
    location / {
        try_files $uri $uri/ /index.html;
    }

    # API Proxy to Drogon Core
    location /api/ {
        proxy_pass [http://127.0.0.1:8081](http://127.0.0.1:8081);
        proxy_http_version 1.1;
        proxy_set_header Upgrade $http_upgrade;
        proxy_set_header Connection 'upgrade';
        proxy_set_header Host $host;
        proxy_cache_bypass $http_upgrade;
        client_max_body_size 250M;
        proxy_read_timeout 600s;
    }
}
```

---

## API Reference

### 1. Ingest GeoTIFF
```http
POST /api/v1/processor
Content-Type: multipart/form-data
```
* **Payload:** `image=@terrain.tif`
* **Response:**
  ```json
  {
    "job_id": "8f8b1a20-a612-4fc4-bb97-b31a3962b161",
    "status": "PROCESSING",
    "glb_url": "/api/v1/download/scene_8f8b1a20.glb"
  }
  ```

### 2. Global Map Bounding Box Fetch
```http
POST /api/v1/global-map/geotiff
Content-Type: application/json
```
* **Payload:**
  ```json
  {
    "bbox": [77.1025, 28.7041, 77.1125, 28.7141],
    "source": "sentinel2-l2a"
  }
  ```

### 3. Point Elevation Query
```http
POST /api/height/single
Content-Type: application/json
```
* **Payload:** `{"x": 480210.5, "y": 1368420.2, "crs": "EPSG:32646"}`
* **Response:** `{"metric_elevation": 42.31, "class": "building"}`

---

---

## Acknowledgments & Data Sources
* **ISRO & NRSC:** Bhuvan Geoportal & CartoDEM elevation datasets.
* **European Space Agency (ESA):** Copernicus GLO-30 Digital Elevation Model.
* **NASA AMMOS:** 3D Tiles Renderer engine for WebGL.
* **OpenTopography:** Global High-Resolution Topography data and validation APIs.