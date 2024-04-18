#!/usr/bin/env bash
#-------------------------------------------------------------------------------------------------------------
# Copyright (c) Microsoft Corporation. All rights reserved.
# Licensed under the MIT License. See https://go.microsoft.com/fwlink/?linkid=2090316 for license information.
#-------------------------------------------------------------------------------------------------------------
#
set -e

CMAKE-VERSION=${1:-"none"}

if [ "${CMAKE-VERSION}" = "none" ]; then
    echo "No CMake version specified, skipping CMake reinstallation"
    exit 0
fi

# Cleanup temporary directory and associated files when exiting the script.
cleanup() {
    EXIT-CODE=$?
    set +e
    if [[ -n "${TMP-DIR}" ]]; then
        echo "Executing cleanup of tmp files"
        rm -Rf "${TMP-DIR}"
    fi
    exit $EXIT-CODE
}
trap cleanup EXIT


echo "Installing CMake..."
apt-get -y purge --auto-remove cmake
mkdir -p /opt/cmake

architecture=$(dpkg --print-architecture)
case "${architecture}" in
    arm64)
        ARCH=aarch64 ;;
    amd64)
        ARCH=x86-64 ;;
    *)
        echo "Unsupported architecture ${architecture}."
        exit 1
        ;;
esac

CMAKE-BINARY-NAME="cmake-${CMAKE-VERSION}-linux-${ARCH}.sh"
CMAKE-CHECKSUM-NAME="cmake-${CMAKE-VERSION}-SHA-256.txt"
TMP-DIR=$(mktemp -d -t cmake-XXXXXXXXXX)

echo "${TMP-DIR}"
cd "${TMP-DIR}"

curl -sSL "https://github.com/Kitware/CMake/releases/download/v${CMAKE-VERSION}/${CMAKE-BINARY-NAME}" -O
curl -sSL "https://github.com/Kitware/CMake/releases/download/v${CMAKE-VERSION}/${CMAKE-CHECKSUM-NAME}" -O

sha256sum -c --ignore-missing "${CMAKE-CHECKSUM-NAME}"
sh "${TMP-DIR}/${CMAKE-BINARY-NAME}" --prefix=/opt/cmake --skip-license

ln -s /opt/cmake/bin/cmake /usr/local/bin/cmake
ln -s /opt/cmake/bin/ctest /usr/local/bin/ctest
