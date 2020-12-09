#NAME:              Makefile
#DESCRIPTION:       Compiles and makes C++ file with executable desginated by the CPP file
#PURPOSE:           Build a program executable on Linux

#MODIFICATION HISTORY:

#Author             Date           Modification(s)
#----------------   -----------    ---------------
#Brianna Schmidt    2018-04-11     Version 1
#-----------------------------------------------------------------------------

#       This generic makefile command builds any stand alone ".cpp" source file.
#       e.g make hello
.cpp :
	g++ - Wall -o $* $*.cpp -std=c++11


#       This will build the two object files required for "matrix_test"
#       and link them into a single executable
#       Usage: make matrix_test

matrix_test: Matrix.o matrix_test.o
	g++ -Wall -o $@ $@.o Matrix.o -std=c++11

matrix_test1: Matrix.o matrix_test1.o
	g++ -Wall -o $@ $@.o Matrix.o -std=c++11
#       This will build the two object files required for "matrix_test",
#       which are dependent on Matrix.h

%.o : %.cpp Matrix.h
	g++ -Wall -c $< -std=c++11

matrix_test3: Matrix
