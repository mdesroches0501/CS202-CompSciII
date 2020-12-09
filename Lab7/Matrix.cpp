/*------------------------------------------------------------------------------
 NAME:             Matrix.cpp
 DESCRIPTION:      Implementation for Matrix class
 USAGE:            #include "Matrix.cpp"
 COMPILER:         GNU g++ compiler on Linux
 NOTES:
 
 MODIFICATION HISTORY:
 Author             Date               Version
 ---------------    ----------         --------------
 Brianna Schmidt    2018-04-11         1.0
 ----------------------------------------------------------------------------- */

#include "Matrix.h"

//function header here
Matrix::Matrix(int n_rows, int n_cols)
{
        rows = n_rows;
        cols = n_cols;

        array = new int*[rows];

        for (int i = 0; i < rows; i++)
        {
                array[i] = new int[cols];       //each row now points to beginning of cols array
        }

        cout << "Matrix constructor:    ";
        cout << rows << " X " << cols << endl;
}

//function header here

int Matrix::get(int i, int j)
{
        return array[i][j];
}

//function header here

void Matrix::set(int i, int j, int k)
{
        array[i][j] = k;
}


//function header here

void Matrix::display()
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

Matrix::~Matrix()
{
        for(int i = 0; i < rows; i++)
        {
                delete [] array [i];
        }
        delete [] array;
}
