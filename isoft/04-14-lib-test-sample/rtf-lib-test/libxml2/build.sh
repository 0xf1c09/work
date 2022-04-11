#!/bin/bash

OBJDIR=../../test_bin/libxml2

mkdir -p $OBJDIR
cp -r libcfg $OBJDIR
make
