#!/bin/bash

OBJDIR=../../test_bin/gstreamer

mkdir -p $OBJDIR
cp -r libcfg $OBJDIR
make
