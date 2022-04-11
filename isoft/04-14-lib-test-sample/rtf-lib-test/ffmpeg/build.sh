#!/bin/bash

OBJDIR=../../test_bin/ffmpeg

mkdir -p $OBJDIR
cp -r libcfg $OBJDIR
make
