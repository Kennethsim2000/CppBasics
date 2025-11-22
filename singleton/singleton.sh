#!/bin/bash

g++ -std=c++17 -Wall -fsanitize=address -fsanitize=undefined -fno-elide-constructors -g -o data.out data.cpp && ./data.out
