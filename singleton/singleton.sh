#!/bin/bash

g++ -std=c++17 -Wall -fsanitize=address -fsanitize=undefined -g -o data.out data.cpp && ./data.out
