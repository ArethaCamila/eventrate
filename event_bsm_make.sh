#!/bin/bash
gcc -Wall -c bsm.c -std=c99
g++ -Wall -c EventRateBSM.cc
g++ -Wall EventRateBSM.o bsm.o -lglobes -lgsl -lgslcblas -O3 -o EventRateBSM
./EventRateBSM 
rm *.o