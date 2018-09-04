#!/bin/bash

set -e

APP=HDPVR2-testApp

OS=`uname -s | tr '[:upper:]' '[:lower:]'`

if [ $OS != 'darwin' ] ; then
	ARCH=`objdump -f build/$APP | grep 'architecture:' | sed -r 's@^[^:]*:\s*([-_A-Za-z0-9]+(:[-_A-Za-z0-9]+)?),.*$@\1@' | sed -r 's@^[^:]*:([^:]*)$@\1@'`
	OS=$OS-$ARCH
fi

rm -rf "$OS" "$OS.tgz"
mkdir -p "$OS"
cp -afL "build/$APP" readme build/*.cfg build/*.bin "$OS"
mkdir -p "$OS/inc"
cp -afL ../Common/Rx/*.h ../Common/FX2API/*.h ../Common/*.h ../Common/Wrappers/$OS/*.h ../Common/EncoderDev/*.h "$OS/inc"
mkdir -p "$OS/lib"
cp -afL build-ADV7842/libADV7842.a "$OS/lib"
mkdir -p "$OS/sample"
cp -afL main.cpp "$OS/sample"
cp -afL Makefile "$OS/sample"
strip "$OS/$APP"
tar -czf "../$OS.tgz" "$OS"

make -C build-ADV7842 clean
make -C build clean
