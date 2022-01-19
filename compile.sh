#!/bin/bash
clang++ -o $1 -std=c++11 -lsfml-system \
    -lsfml-graphics -lsfml-window -lsfml-audio "./$1.cpp" && ./$1