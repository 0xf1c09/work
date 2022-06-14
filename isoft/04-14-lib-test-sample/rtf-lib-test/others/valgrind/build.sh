#!/bin/bash

OBJDIR=../../test_bin/valgrind

mkdir -p $OBJDIR
cp -r libcfg $OBJDIR
make
