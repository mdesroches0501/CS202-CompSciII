#NAME:              Makefile
#DESCRIPTION:       Compiles and makes C++ file with executable desginated by the CPP file
#PURPOSE:           Build a program executable on Linux
#
#MODIFICATION HISTORY:
#
#Author             Date           Modification(s)
#----------------   -----------    ---------------
#Michael DesRoches  2018-04-11     Version 1
#-----------------------------------------------------------------------------

#       This generic makefile command builds any stand alone ".cpp" source file.
#       e.g make hello
.cpp : 
	g++ -o $* $*.cpp -std=c++11

#       This will build the two object files required for "matrix_test"
#       and link them into a single executable
#       Usage: make matrix_test

matrix_math: matrix_math.o
	g++ -o $@ $@.o -Wall -Wextra -std=c++11

#       This will build the two object files required for "matrix_test",
#       which are dependent on Matrix.h

%.o : %.cpp Matrix.h
	g++ -c $< -std=c++11

matrix_math.o: Matrix.cpp
