#!/bin/bash

if [ -n "$1" ] ; then
	opts="CPU=$1"
fi

set -e
if [ `uname -s | tr '[:upper:]' '[:lower:]'` != 'darwin' ] ; then
	make -C ../3rd-party -f libusb.mk $opts
fi
make -C build-ADV7842 $opts clean all
make -C build $opts clean all
