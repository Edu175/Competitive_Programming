#!/bin/bash

problem=dna
grader_name=grader

g++ -std=gnu++17 -O2 -Wall -Wextra -pipe -static -o "${problem}" "${grader_name}.cpp" "${problem}.cpp"
