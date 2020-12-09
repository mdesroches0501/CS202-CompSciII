#ifndef MATRIX_H__
#define MATRIX_H__
/*------------------------------------------------------------------------------
 NAME:             Matrix.h
 DESCRIPTION:      Specification file for Matrix class
 USAGE:            #include "Matrix.h"
 COMPILER:         GNU g++ compiler on Linux
 NOTES:
 
 MODIFICATION HISTORY:
 Author             Date               Version
 ---------------    ----------         --------------
 Michael DesRoches  2018-04-11         1.0
 ----------------------------------------------------------------------------- */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>

using namespace std;
template <class T>

class Matrix {
        private:
                int rows;
                int cols;
                T **array;

        public:
                Matrix(int rows, int cols);             //Overloaded Constructor
                ~Matrix();                              //Destructor
                T int get(int i, int j);                  //Accessor
                void set(int i, int j, T k);          //Mutator
                void display();                         //Accessor for output   
};

#endif