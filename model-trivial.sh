#!/usr/bin/env bash

cd model-trivial

omc -s hello.mo

make -f Hello.makefile

./Hello -override startTime=0,stopTime=10 -s rungekutta

cd ..
