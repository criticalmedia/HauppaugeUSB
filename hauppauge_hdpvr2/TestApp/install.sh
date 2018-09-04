#!/bin/sh

set -e

APP=HDPVR2-testApp

mkdir -p "$1"
cp -afL "./build/$APP" ./build/*.cfg ./build/*.bin ./build/readme "$1" ./build-ADV7842/*.a
#strip "$1/$APP" # uncomment when reasonable
