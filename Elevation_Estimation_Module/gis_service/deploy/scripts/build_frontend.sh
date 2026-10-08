#!/usr/bin/env bash
# Builds the frontend checkout and publishes it to the NGINX web root.
# Usage: FRONTEND_DIR=/opt/depthwizard/frontend WEB_ROOT=/var/www/depthwizard deploy/scripts/build_frontend.sh
set -euo pipefail
FRONTEND_DIR=${FRONTEND_DIR:-/opt/depthwizard/frontend}
WEB_ROOT=${WEB_ROOT:-/var/www/depthwizard}
cd "$FRONTEND_DIR"
npm ci
# Same-origin API (NGINX proxies /api): VITE_API_BASE stays unset.
npm run build
sudo mkdir -p "$WEB_ROOT"
sudo rsync -a --delete "$FRONTEND_DIR/dist/" "$WEB_ROOT/"
echo "Published $FRONTEND_DIR/dist to $WEB_ROOT"
