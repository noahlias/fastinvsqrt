#!/usr/bin/env bash
## compile the c
gcc -O3 fastinvsqrt.c -o fastinvsqrt -lm
hyperfine --shell=none --warmup 10 'python c_function.py' 'python python_function.py' './fastinvsqrt'
