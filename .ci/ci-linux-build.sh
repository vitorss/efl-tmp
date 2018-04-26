#!/bin/sh

set -e

PARALLEL_JOBS=10

CI_BUILD_TYPE=$1

DEFAULT_COPTS="--with-tests=regular"
WAYLAND_COPTS="--with-tests=regular --enable-wayland --enable-elput --enable-drm \
--enable-wayland-ivi-shell --enable-gl-drm --with-opengl=es --enable-egl"
MISC_COPTS="--enable-harfbuzz --enable-liblz4 --enable-image-loader-webp --enable-xinput22 --enable-multisense --enable-lua-old --enable-xpresent --enable-hyphen"

# --enable-libvlc --enable-vnc-server --enable-g-main-loop --enable-libuv --enable-fb --enable-eglfs --enable-sdl --enable-gl-drm --enable-egl --enable-pix    man --enable-tile-rotate --enable-ecore-buffer --enable-image-loader-generic --enable-image-loader-jp2k --enable-gesture --enable-v4l2 --enable-xine
# --with-profile=PROFILE --with-crypto=CRYPTO

MISC_DISABLED_COPTS="--disable-neon --disable-libeeze --disable-systemd --disable-magic-debug \
--disable-valgrind --disable-cxx-bindings --disable-gstreamer1 \
--disable-fontconfig --disable-fribidi --disable-poppler --disable-spectre --disable-libraw \
--disable-librsvg --disable-xcf --disable-libmount --disable-tslib --disable-audio \
--disable-pulseaudio --disable-avahi --disable-xinput2 --disable-xim --disable-scim \
--disable-ibus --disable-physics --disable-quick-launch --disable-elua"

if [ "$CI_BUILD_TYPE" = "" ]; then
  # Normal build test of all targets
  ./autogen.sh $DEFAULT_COPTS
  make -j $PARALLEL_JOBS
  make -j $PARALLEL_JOBS examples
  make -j $PARALLEL_JOBS benchmark
fi

if [ "$CI_BUILD_TYPE" = "wayland" ]; then
  ./autogen.sh $WAYLAND_COPTS
  make -j $PARALLEL_JOBS
  make -j $PARALLEL_JOBS examples
fi

if [ "$CI_BUILD_TYPE" = "misc" ]; then
  ./autogen.sh $MISC_COPTS
  make -j $PARALLEL_JOBS
  make -j $PARALLEL_JOBS examples
fi

if [ "$CI_BUILD_TYPE" = "misc-disabled" ]; then
  ./autogen.sh $MISC_DISABLED_COPTS
  make -j $PARALLEL_JOBS
  make -j $PARALLEL_JOBS examples
fi
