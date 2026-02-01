#!/usr/bin/env bash
# NativeProjectRunner/runtime/prepare_assets.sh
set -euo pipefail

# Base paths
PROJECT_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
ASSETS_SRC="$PROJECT_ROOT/project_spec/example_project/assets"
RES_DIR="$PROJECT_ROOT/Android/app/src/main/res"

# DPI scale factors
declare -A DPI_SCALE=(
    [mdpi]=1
    [hdpi]=1.5
    [xhdpi]=2
    [xxhdpi]=3
    [xxxhdpi]=4
)

echo "Preparing assets from $ASSETS_SRC..."

for dpi in "${!DPI_SCALE[@]}"; do
    OUT_DIR="$RES_DIR/drawable-$dpi"
    mkdir -p "$OUT_DIR"
    scale=${DPI_SCALE[$dpi]}

    for img in "$ASSETS_SRC"/*.{png,jpg,jpeg}; do
        [ -f "$img" ] || continue
        filename=$(basename "$img")
        echo "Processing $filename for $dpi..."
        convert "$img" -resize $(echo "$scale*100" | bc)% "$OUT_DIR/$filename"
    done
done

echo "All assets processed successfully."