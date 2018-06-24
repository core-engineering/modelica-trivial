#!/usr/bin/env bash

omc -s hello.mo

make -f Hello.makefile

./Hello -s rungekutta
