#!/bin/bash

problem="treasure"
grader_name="grader"

g++ -std=gnu++17 -O2 -Wall -pipe -static -o "${problem}" "${grader_name}.cpp" "${problem}.cpp"