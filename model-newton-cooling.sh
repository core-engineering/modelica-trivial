#!/usr/bin/env bash

cd model-newton-cooling

omc -s NewtonCooling.mo

make -f NewtonCooling.makefile

./NewtonCooling -override startTime=0,stopTime=10 -s rungekutta

cd ..
