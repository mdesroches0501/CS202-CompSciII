/* -----------------------------------------------------------------------------
FILE NAME:         Matrix.cpp
DESCRIPTION:       implementation
USAGE:             ./matrix_math
COMPILER:          GNU g++ compiler on Linux
NOTES:             Driver will call these functions

MODIFICATION HISTORY:
Author             Date               Version
---------------    ----------         --------------
Michael Des Roches 2018-04-09         1.0 // implementes lab7 
Michael Des Roches 2018-04-13	      2.0 // overloaded operators
Michael Des roches 2018-04-17         3.0 // constructors/desstructors
Michael Des Roches 2018-04-24	      4.0 // matrix operations
Michael Des Roches 2018-04-27         5.0 // template addition
Michael Des Roches 2018-04-30         6.0 // final touchups
----------------------------------------------------------------------------- */

#include "Matrix.h"

/* -----------------------------------------------------------------------------
FUNCTION:          Matrix<T>::set()
DESCRIPTION:       Sets the Matrix size
RETURNS:           N/A
NOTES:             
------------------------------------------------------------------------------- */
template <class T>
void Matrix<T>::set(int i, int j, T k)
{
	array[i][j] = k;
}

/* -----------------------------------------------------------------------------
FUNCTION:          Matrix<T>::get()
DESCRIPTION:       makes the matrix
RETURNS:           array
NOTES:             
------------------------------------------------------------------------------- */
template <class T>
T Matrix<T>::get(int i, int j) const
{
	return array[i][j];
}

/* -----------------------------------------------------------------------------
FUNCTION:          Matrix<T>::set()
DESCRIPTION:       Displays Matrix
RETURNS:           N/A
NOTES:             
------------------------------------------------------------------------------- */
template <class T>
void Matrix<T>::display()
{
	cout << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << setw(4) << get(i, j);
		}
		cout << endl;
	}
	cout << endl;
}

/* -----------------------------------------------------------------------------
FUNCTION:          ostream &operator << ()
DESCRIPTION:       Overloaded << operator
RETURNS:           out
NOTES:             sends ouput to a file
------------------------------------------------------------------------------- */
template <class T>
ostream &operator << (ostream &out, const Matrix<T> &matrix1)
{
	out << setw(6) << matrix1.rows << " X " << matrix1.columns << endl;
	for (int i = 0; i < matrix1.rows; i++)
	{
		for (int j = 0; j < matrix1.columns; j++)
		{
			out << setw(6) << matrix1.get(i, j);
		}
		out << endl;
	}
	return out;
}

/* -----------------------------------------------------------------------------
FUNCTION:          istream &operator >> ()
DESCRIPTION:       overloaded >> operator
RETURNS:           out
NOTES:             
------------------------------------------------------------------------------- */
template <class T>
istream &operator >> (istream &out, Matrix<T> &matrix1)
{
	for (int i = 0; i < matrix1.rows; i++)
	{
		for (int j = 0; j < matrix1.columns; j++)
		{
			out >> matrix1.array[i][j];
		}
	}
	return out;
}

/* -----------------------------------------------------------------------------
FUNCTION:          Matrix<T>::Matrix()
DESCRIPTION:       Constructor (default)
RETURNS:           N/A
NOTES:             Initializes variables to 0
------------------------------------------------------------------------------- */
template <class T> //Default
Matrix<T>::Matrix()
{
	columns = 0;
	rows = 0;
	array = NULL; // Null pointer???
}

/* -----------------------------------------------------------------------------
FUNCTION:          Matrix<T>::Matrix()
DESCRIPTION:       Copy Constructor
RETURNS:           N/A
NOTES:             
------------------------------------------------------------------------------- */
template <class T> 
Matrix<T>::Matrix(const Matrix<T>& c_struct)
{
	columns = c_struct.columns;
	rows = c_struct.rows;
	
	array = new T *[rows];

	for (int i = 0; i < rows; i++)
	{
		array[i] = new T[columns];
		for (int j = 0; j < columns; j++)
		{
			array[i][j] = c_struct.array[i][j];
		}
	}
}

/* -----------------------------------------------------------------------------
FUNCTION:          Matrix<T>& Matrix<T> ::operator=()
DESCRIPTION:       Overloaded assg operator
RETURNS:           this
NOTES:             
------------------------------------------------------------------------------- */ 
template <class T>
Matrix<T>& Matrix<T> ::operator=(const Matrix<T>& matrix1)
{
	rows = matrix1.rows;
	columns = matrix1.columns;

	array = new T *[rows];

	for (int i = 0; i < rows; i++)
	{
		array[i] = new T[columns];
		for (int j = 0; j < columns; j++)
		{
			array[i][j] = matrix1.array[i][j];
		}
	}
	return *this;
}

/* -----------------------------------------------------------------------------
FUNCTION:          Matrix<T>::Matrix()
DESCRIPTION:       Overloaded constructor
RETURNS:           N/A
NOTES:             
------------------------------------------------------------------------------- */
template <class T>
Matrix<T>::Matrix(int num_rows, int num_columns)
{
	rows = num_rows;
	columns = num_columns;
	
	array = new T *[rows];

	for (int i = 0; i < rows; i++)
	{
		array[i] = new T[columns];
	}
	
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			array[i][j] = 0; 
		}
	}
}

/* -----------------------------------------------------------------------------
FUNCTION:          Matrix_ops<T> Matrix_ops<T> ::operator
DESCRIPTION:       Overloaded - Operator
RETURNS:           Matrix3
NOTES:             Subtracts matrices with proper nxm 
------------------------------------------------------------------------------- */
template <class T>
Matrix_ops<T> Matrix_ops<T> ::operator-(const Matrix_ops<T>& matrix1)
{
	if (this->rows != matrix1.rows || this->columns != matrix1.columns)  
	{
		cout << endl << "You must have correct dimensions to add these... go study\n";
		cout << endl;

		Matrix_ops<T> matrix3;

		return matrix3;
	}

	Matrix_ops<T> matrix3(this->rows, this->columns); 

	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->columns; j++)
		{
			matrix3.array[i][j] = matrix1.array[i][j] - this->array[i][j];   
		}
	}
	return matrix3;
}

/* -----------------------------------------------------------------------------
FUNCTION:          Matrix_ops<T> ::operator+()
DESCRIPTION:       Overloaded + operator
RETURNS:           matrix3
NOTES:             checks for proper nxm before executing
------------------------------------------------------------------------------- */
template <class T>
Matrix_ops<T> Matrix_ops<T> ::operator+(const Matrix_ops<T>& matrix1)
{
	if (this->rows != matrix1.rows || this->columns != matrix1.columns)      
	{
		cout << endl << "You must have correct dimensions to add these... go study\n";
		cout << endl;

		Matrix_ops<T> matrix3;

		return matrix3;
	}

	Matrix_ops<T> matrix3(this->rows, this->columns); 

	for (int i = 0; i < this->rows; i++)  //performs addition 
	{
		for (int j = 0; j < this->columns; j++)
		{
			matrix3.array[i][j] = this->array[i][j] + matrix1.array[i][j];  
		}
	}
	return matrix3; //new value
}

/* -----------------------------------------------------------------------------
FUNCTION:          Matrix_ops<T>::operator
DESCRIPTION:       Overloaded equal operator
RETURNS:           bool
NOTES:             
------------------------------------------------------------------------------- */
template <class T>
bool Matrix_ops<T>::operator==(const Matrix_ops<T>& matrix1)
{
	if (this->rows != matrix1.rows || this->columns != matrix1.columns)
	{
		return false;
	}

	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->columns; j++)   // will check for similarity 
        {
			if (this->array[i][j] != matrix1.array[i][j])
			{
				return false;
			}
		}
	}
	return true;
}

/* -----------------------------------------------------------------------------
FUNCTION:          Matrix_ops<T> Matrix_ops<T>::operator*
DESCRIPTION:       Overloaded multiplication operator
RETURNS:           matrix3
NOTES:             multiplication function
------------------------------------------------------------------------------- */ 
template <class T>
Matrix_ops<T> Matrix_ops<T> ::operator*(const Matrix_ops<T>& matrix1)
{
	if (this->columns != matrix1.rows) 
	{
		cout << "Columns: " << columns << " Rows: " << matrix1.rows << endl;
		cout << endl << "Invalid Dimensions" << endl << endl;

		Matrix_ops<T> matrix3;

		return matrix3;
	}

	Matrix_ops<T> matrix3(this->rows, matrix1.columns); 
	
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < matrix1.rows; j++)
		{
			for (int k = 0; k < this->columns ; k++)
			{
				matrix3.array[i][j] += (this->array[i][k] * matrix1.array[k][j]); 
			}
		}
	}
	return matrix3;            
}

/* -----------------------------------------------------------------------------
FUNCTION:          Matrix<T>::~Matrix()
DESCRIPTION:       Destructor
RETURNS:           N/A
NOTES:             Destroys memory from program used
------------------------------------------------------------------------------- */
template <class T>
Matrix<T>::~Matrix() 
{
	for (int i = 0; i < rows; i++)
	{
		delete[] array[i];
	}
	delete[] array;
}
