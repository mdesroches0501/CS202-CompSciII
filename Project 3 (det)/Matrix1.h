/* -----------------------------------------------------------------------------
FILE NAME:         Matrix.h
DESCRIPTION:       header
USAGE:             ./matrix_math
COMPILER:          GNU g++ compiler on Linux
NOTES:             

MODIFICATION HISTORY:
Author             Date               Version
---------------    ----------         --------------
Michael Des Roches 2018-04-09         1.0 // implemented labs 
Michael Des Roches 2018-04-13	      2.0 // overloaded operators
Michael Des roches 2018-04-17         3.0 // constructors/desstructors
Michael Des Roches 2018-04-24	      4.0 // matrix operations
Michael Des Roches 2018-04-27         5.0 // template addition
Michael Des Roches 2018-04-30         6.0 // final touchups
----------------------------------------------------------------------------- */
#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <string.h>

using namespace std;

//Parent Class

template <class T>
class Matrix
{
protected: // Protected for use in inherited class

	int rows;
	int columns;
	T **array;

public:
	// default 
	Matrix();	
	//destructor 
	~Matrix();
	//copy 
	Matrix(const Matrix<T>&);
	//overloaded 
	Matrix(int rows, int cols);	
		
	//overloaded functions
	Matrix<T>& operator = (const Matrix<T>& o);
	template <class Z>
	friend istream& operator>> (istream &, Matrix<Z> &);
	template <class Z>
	friend ostream& operator<< (ostream &, const Matrix<Z> &);

	T get(int i, int j) const;
	void set(int i, int j, T k);
	void display();
};

//inheritance class

template <class T>
class Matrix_ops: public Matrix<T>
{
public:

//constructors

	Matrix_ops() : Matrix<T>() {};
	Matrix_ops(int rows, int cols) : Matrix<T>(rows, cols) {};
	Matrix_ops(const Matrix_ops<T>& a) : Matrix<T>(a) {};
	~Matrix_ops();

//Overloaded

	bool operator == (const Matrix_ops<T>& o);
    //Matrix_ops<T> trans();
	Matrix_ops<T> operator * (const Matrix_ops<T>& o);
	Matrix_ops<T> operator + (const Matrix_ops<T>& o);
	Matrix_ops<T> operator - (const Matrix_ops<T>& o);
};
#endif
