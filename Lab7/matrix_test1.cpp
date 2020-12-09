/*------------------------------------------------------------------------------
 NAME:             matrix_test.cpp
 DESCRIPTION:      Test program for Matrix class
 USAGE:            ./matrix_test.cpp
 COMPILER:         GNU g++ compiler on Linux
 NOTES:
 
 MODIFICATION HISTORY:
 Author             Date               Version
 ---------------    ----------         --------------
 Michael DesRoches  2018-04-11         1.0
 ----------------------------------------------------------------------------- */

#include "Matrix.h"             //Specification file

/* -----------------------------------------------------------------------------
FUNCTION:          main()
DESCRIPTION:       creates a Matrix object, sets some values and displays it
RETURNS:           0
NOTES:             test 
----------------------------------------------------------------------------- */

int main()
{
        int m, n;

        cout << "Input rows and cols: ";
        cin >> m >> n;

        Matrix mat1(m, n);

        for (int i = 0; i < m; i++)
        {
                mat1.set(i, i%n, i+1);          //doesn't fill in all spots, just some
        }

        mat1.display();
        return 0;
}
