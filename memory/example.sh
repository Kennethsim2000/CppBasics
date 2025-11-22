#!/bin/bash

# Simple build script for Stack program

g++ -std=c++17 -Wall -fsanitize=address -fsanitize=undefined -fno-elide-constructors -g -o example.out example.cpp && ./example.out
