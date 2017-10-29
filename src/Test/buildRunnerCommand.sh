#!/bin/bash

. GetGlobals.sh
export PATH=$CXXTEST/bin:$PATH

# @main:
cxxtestgen --error-printer  -o runner.cpp TestCommand.h 
# @:main

# @compile:
g++ -o runner -I$CXXTEST runner.cpp
# @:compile

./runner > buildRunner.log
# @run:
./runner -v
# @:run
\rm -f runner runner.cpp
