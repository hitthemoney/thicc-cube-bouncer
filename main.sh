#!/bin/sh

clang++ -std=c++17 main.cpp -o bouncer -framework GLUT -framework OpenGL
./bouncer