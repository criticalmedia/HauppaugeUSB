#!/bin/sh

MYPATH=$(dirname $0)
TSDIR=$MYPATH/records

test -d $TSDIR || mkdir $TSDIR

if [ "$1" = "debug" ]
then
    APP=$MYPATH/HDPVR2-testApp-cgdb
else
    APP=$MYPATH/HDPVR2-testApp
fi

$APP -s -f $TSDIR/$(date +%F)-composite.ts

