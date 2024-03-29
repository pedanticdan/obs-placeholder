#!/bin/sh

OSTYPE=$(uname)

if [ "${OSTYPE}" != "Darwin" ]; then
    echo "[obs-placeholder - Error] macOS build script can be run on Darwin-type OS only."
    exit 1
fi

HAS_CMAKE=$(type cmake 2>/dev/null)

if [ "${HAS_CMAKE}" = "" ]; then
    echo "[obs-placeholder - Error] CMake not installed - please run 'install-dependencies-macos.sh' first."
    exit 1
fi

#export QT_PREFIX="$(find /usr/local/Cellar/qt5 -d 1 | tail -n 1)"

echo "[obs-placeholder] Building 'obs-placeholder' for macOS."
mkdir -p build && cd build
cmake .. \
	-DQTDIR=/usr/local/opt/qt \
	-DLIBOBS_INCLUDE_DIR=../obs28/obs-studio/libobs \
	-DLIBOBS_LIB=../obs28/obs-studio/libobs \
	-DOBS_FRONTEND_LIB="$(pwd)/../obs28/obs-studio/build/UI/obs-frontend-api/libobs-frontend-api.dylib" \
	-DCMAKE_BUILD_TYPE=RelWithDebInfo \
	-DCMAKE_INSTALL_PREFIX=/usr \
&& make -j4
