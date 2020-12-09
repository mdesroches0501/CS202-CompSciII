/*------------------------------------------------------------------------------
 NAME:             Matrix.cpp
 DESCRIPTION:      Implementation for Matrix class
 USAGE:            #include "Matrix.cpp"
 COMPILER:         GNU g++ compiler on Linux
 NOTES:
 
 MODIFICATION HISTORY:
 Author             Date               Version
 ---------------    ----------         --------------
 Michael DesRoches  2018-04-11         1.0
 ----------------------------------------------------------------------------- */

//#include "Matrix.h"
#include "Matrix.cpp"

typedef unsigned char byte;

//function header here
template <class T>
Matrix<T>::Matrix(int n_rows, int n_cols)
{
        rows = n_rows;
        cols = n_cols;

        array = new T * [rows];

        for (int i = 0; i < rows; i++)
        {
                array[i] = new T [cols];       //each row now points to beginning of cols array
        }

        cout << "Matrix constructor:    ";
        cout << rows << " X " << cols << endl;
}

//function header here
template <class T>
T Matrix<T>::get(int i, int j)
{
        return array[i][j];
}

//function header here
template <class>
void Matrix<T>::set(int i, int j, T k)
{
        array[i][j] = k;
}


//function header here
template <class>
void Matrix<T>::display()
{
        cout << endl;
        for (int i = 0; i < rows; i++)
        {
                for (int j = 0; j < cols; j++)
                {
                        cout << setw(4) << get(i, j);
                }
                cout << endl;
        }
        cout << endl;
}

//function header here
template <class>
Matrix<T>::~Matrix()
{
        for(int i = 0; i < rows; i++)
        {
                delete [] array [i];
        }
        delete [] array;
}
