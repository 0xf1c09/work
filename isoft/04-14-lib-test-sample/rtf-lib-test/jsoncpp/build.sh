#!/bin/bash

OBJDIR=../../test_bin/jsoncpp

mkdir -p $OBJDIR
cp -r libcfg $OBJDIR
make
