#!/bin/sh

sudo g++ src/main.cpp src/invert.cpp -o bin/invert.out \
 -std=c++11 -lX11 -lpthread
