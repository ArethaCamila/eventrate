#!/bin/bash
#gcc -Wall -c liv.c -std=c99
g++ -Wall -c EventRateStd.cc
#g++ -Wall EventRateStd.o liv.o -lglobes -lgsl -lgslcblas -O3 -o EventRateStd
g++ -Wall EventRateStd.o -lglobes -lgsl -lgslcblas -O3 -o EventRateStd
./EventRateStd 
rm *.o