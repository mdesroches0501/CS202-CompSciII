# ------------------------------------------------------------------------------
#
# FILE NAME:    Makefile
#
# DESCRIPTION:  Makefile for a C++ program poly_class
#
# PURPOSE:      Build a program executable
#
# MODIFICATION HISTORY:
#
# Author            	Date          Modification(s)
# -----------       	----------    ---------------
# Michael DesRoches     2018-03-21    Version 1.0
# ------------------------------------------------------------------------------

## This is our original generic makefile command that will build
## any stand alone .cpp source file
.cpp : 
	g++ -o $* $*.cpp -std=c++11

##	This will build two objects files required for 'poly_class'
##	and link them to single ex
## 	usage : make poly_class

matrix_test: Matrix.o matrix_test.o
	g++ -o $@ $@.o Matrix.o  -std=c++11

## 	This will build the two objects for poly_class
##	usage: make poly_class

%.o : %.cpp Matrix.h
	g++ -c $< -std=c++11

