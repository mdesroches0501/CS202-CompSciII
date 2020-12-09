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
DESCRIPTION:       Reads matrix from a file, creates a Matrix object, and displays it to the screen
RETURNS:           0
NOTES:             int argc     //num of para on command line
                   char *argv[] //an array of pointers to c strings
----------------------------------------------------------------------------- */

int main(int argc, char *argv[])
{
        int i, j, k;
        int m, n;
        char let_x;
        char file1[20];
        ifstream infile;

        if (argc<3)
        {
        cout << "Not enough Arguments ?\n\n";
        return 0;
        }

        if (strcmp(argv[1], "-inp") == 0)
        {
                strcpy(file1, argv[2]);
                strcat(file1, ".mtx");
                infile.open(file1);
                if (!infile)
                {
                        cout << "\nError opening file: " << file1 << "\n\n";
                        return 0;
                }
        }
        infile >> m >> let_x >> n;

        Matrix mat1(m, n);

        for (i = 0; i < m; i++)
        {
                for (j = 0; j < n; j++)
                {
                        infile >> k;
                        mat1.set(i, j, k);              //doesn't fill in all spots, just some
                }
        }

        mat1.display();
        infile.close();
        return 0;
}
