#!/bin/bash

OBJDIR=../../test_bin/gdb

mkdir -p $OBJDIR

make
cp -r gdb libcfg $OBJDIR
