#!/usr/bin/env bash

reset

if [ ! -d build ]; then
    mkdir build
fi

cd build && cmake .. && make && ./bin/DoodleGameEngine && cd -
