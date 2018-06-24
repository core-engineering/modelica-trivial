#!/usr/bin/env bash

omc -s NewtonCooling.mo Modelica

make -f NewtonCooling.makefile

./NewtonCooling
