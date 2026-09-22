#!/usr/bin/env sh
set -eu

VERSION="${VERSION:-$(git describe --tags --exact-match)}"

rm -rf "release"
mkdir -p "release"

# Minisumo version
mkdir "release/minisumo-${VERSION}/"
cp -R \
    variants/minisumo-bot/ \
    3d/Old_Sumobot.v7.3mf \
    "release/minisumo-${VERSION}/"

# Bluetooth version
mkdir "release/bluetooth-${VERSION}/"
cp -R \
    variants/Bluetooth_control/ \
    3d/Old_Sumobot.v7.3mf \
    "release/bluetooth-${VERSION}/"

# Zip each folder, each created zip file is placed in the release/ folder
cd release
for variant in */; do
    name="${variant%/}"
    zip -r "${name}.zip" "${name}"
done
