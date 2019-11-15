#!/bin/bash

gcc -L/home/joshua/Code/dxvk/build-native/src/d3d11 -L/home/joshua/Code/dxvk/build-native/src/dxgi -lSDL2 -ld3d11 -ldxgi -I/home/joshua/Code/dxvk/include/native -I/home/joshua/Code/dxvk/include/native/mingw main.cpp -o native_test