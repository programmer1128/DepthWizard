#!/usr/bin/env bash
# Builds gis_service in Release mode into build-release/ (tests off).
# Usage: deploy/scripts/build_backend.sh   (from anywhere)
set -euo pipefail
SERVICE_DIR=$(cd "$(dirname "$0")/../.." && pwd)
BUILD_DIR="$SERVICE_DIR/build-release"
cmake -S "$SERVICE_DIR" -B "$BUILD_DIR" -DCMAKE_BUILD_TYPE=Release -DBUILD_TESTING=OFF
cmake --build "$BUILD_DIR" -j"$(nproc)" --target gis_service
echo "Built $BUILD_DIR/gis_service"
