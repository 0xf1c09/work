#!/bin/bash

OBJDIR=../../test_bin/iniparser

mkdir -p $OBJDIR
cp config.ini $OBJDIR
make
