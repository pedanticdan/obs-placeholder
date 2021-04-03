#!/bin/bash

set -e

OSTYPE=$(uname)

if [ "${OSTYPE}" != "Darwin" ]; then
    echo "[obs-placeholder - Error] macOS package script can be run on Darwin-type OS only."
    exit 1
fi

echo "[obs-placeholder] Preparing package build"
export QT_CELLAR_PREFIX="$(/usr/bin/find /usr/local/Cellar/qt -d 1 | sort -t '.' -k 1,1n -k 2,2n -k 3,3n | tail -n 1)"

#GIT_HASH=$(git rev-parse --short HEAD)
#GIT_BRANCH_OR_TAG=$(git name-rev --name-only HEAD | awk -F/ '{print $NF}')

#VERSION="$GIT_HASH-$GIT_BRANCH_OR_TAG"
VERSION=0.0.1

FILENAME_UNSIGNED="obs-placeholder-$VERSION-Unsigned.pkg"
FILENAME="obs-placeholder-$VERSION.pkg"

echo "[obs-placeholder] Modifying obs-placeholder.so"
install_name_tool \
	-change /usr/local/opt/qt/lib/QtWidgets.framework/Versions/5/QtWidgets \
		@executable_path/../Frameworks/QtWidgets.framework/Versions/5/QtWidgets \
	-change /usr/local/opt/qt/lib/QtGui.framework/Versions/5/QtGui \
		@executable_path/../Frameworks/QtGui.framework/Versions/5/QtGui \
	-change /usr/local/opt/qt/lib/QtCore.framework/Versions/5/QtCore \
		@executable_path/../Frameworks/QtCore.framework/Versions/5/QtCore \
	./build/obs-placeholder.so

# Check if replacement worked
echo "[obs-placeholder] Dependencies for obs-placeholder"
otool -L ./build/obs-placeholder.so

RELEASE_MODE="False"

if [[ "$RELEASE_MODE" == "True" ]]; then
	echo "[obs-placeholder] Signing plugin binary: obs-placeholder.so"
	codesign --sign "$CODE_SIGNING_IDENTITY" ./build/obs-placeholder.so
else
	echo "[obs-placeholder] Skipped plugin codesigning"
fi

echo "[obs-placeholder] Actual package build"
packagesbuild ./CI/macos/obs-placeholder.pkgproj

echo "[obs-placeholder] Renaming obs-placeholder.pkg to $FILENAME"
mv ./release/obs-placeholder.pkg ./release/$FILENAME_UNSIGNED

if [[ "$RELEASE_MODE" == "True" ]]; then
	echo "[obs-placeholder] Signing installer: $FILENAME"
	productsign \
		--sign "$INSTALLER_SIGNING_IDENTITY" \
		./release/$FILENAME_UNSIGNED \
		./release/$FILENAME
	rm ./release/$FILENAME_UNSIGNED

	echo "[obs-placeholder] Submitting installer $FILENAME for notarization"
	zip -r ./release/$FILENAME.zip ./release/$FILENAME
	UPLOAD_RESULT=$(xcrun altool \
		--notarize-app \
		--primary-bundle-id "fr.pedanticdan.obs-placeholder" \
		--username "$AC_USERNAME" \
		--password "$AC_PASSWORD" \
		--asc-provider "$AC_PROVIDER_SHORTNAME" \
		--file "./release/$FILENAME.zip")
	rm ./release/$FILENAME.zip

	REQUEST_UUID=$(echo $UPLOAD_RESULT | awk -F ' = ' '/RequestUUID/ {print $2}')
	echo "Request UUID: $REQUEST_UUID"

	echo "[obs-placeholder] Wait for notarization result"
	# Pieces of code borrowed from rednoah/notarized-app
	while sleep 30 && date; do
		CHECK_RESULT=$(xcrun altool \
			--notarization-info "$REQUEST_UUID" \
			--username "$AC_USERNAME" \
			--password "$AC_PASSWORD" \
			--asc-provider "$AC_PROVIDER_SHORTNAME")
		echo $CHECK_RESULT

		if ! grep -q "Status: in progress" <<< "$CHECK_RESULT"; then
			echo "[obs-placeholder] Staple ticket to installer: $FILENAME"
			xcrun stapler staple ./release/$FILENAME
			break
		fi
	done
else
	echo "[obs-placeholder] Skipped installer codesigning and notarization"
fi
