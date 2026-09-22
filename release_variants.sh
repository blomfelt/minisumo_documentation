#!/usr/bin/env sh
set -eu

VERSION="${VERSION:-$(git describe --tags --exact-match)}"

rm -rf "release/${NAME}"
mkdir -p "release/${NAME}"

# Minisumo version
cp -R variants/minisumo-bot/ "release/minisumo-${VERSION}/"

# Zip each folder, each created zip file is placed in the release/ folder
cd release
for variant in */; do
    name="$dir%/"
    zip -r "${name}.zip" "${name}"
done
