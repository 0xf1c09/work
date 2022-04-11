#!/bin/bash

TEST_PATH=`pwd`
WORKDIR=$TEST_PATH

ALL_NUM=0
OK_NUM=0
FAIL_NUM=0

let "ALL_NUM =  `ls -l $WORKDIR | grep "^d" | wc -l`"

cd $WORKDIR
for test_item in `ls $WORKDIR`
do
    if [ -d $test_item ] ; then
        cd $test_item
    
        printf "\033[31m %-30s  %-20s %-30s\n\033[0m"  "===============building"  "$test_item"  	"=========="
        ./build.sh 

	   OP_MODE=$?
       cd $WORKDIR

    fi
done 



