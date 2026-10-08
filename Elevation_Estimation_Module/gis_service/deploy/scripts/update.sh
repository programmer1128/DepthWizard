#!/usr/bin/env bash
# Pull both checkouts, rebuild, publish the frontend and restart the backend.
# Usage: BACKEND_REPO=/opt/depthwizard/backend FRONTEND_DIR=/opt/depthwizard/frontend deploy/scripts/update.sh
set -euo pipefail
BACKEND_REPO=${BACKEND_REPO:-/opt/depthwizard/backend}
FRONTEND_DIR=${FRONTEND_DIR:-/opt/depthwizard/frontend}
git -C "$BACKEND_REPO" pull --ff-only
git -C "$FRONTEND_DIR" pull --ff-only
"$BACKEND_REPO/drogon_service/gis_service/deploy/scripts/build_backend.sh"
FRONTEND_DIR="$FRONTEND_DIR" "$BACKEND_REPO/drogon_service/gis_service/deploy/scripts/build_frontend.sh"
sudo systemctl restart depthwizard-backend
sudo nginx -t && sudo systemctl reload nginx
systemctl --no-pager --lines=5 status depthwizard-backend || true
