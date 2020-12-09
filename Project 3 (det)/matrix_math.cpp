/* -----------------------------------------------------------------------------
FILE NAME:         matrix_math.cpp
DESCRIPTION:       driver
USAGE:             ./matrix_math
COMPILER:          GNU g++ compiler on Linux
NOTES:             

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

#include "Matrix.cpp"
//#include "Matrix.h"

//prototype

void help(); 

typedef unsigned char byte;

/* -----------------------------------------------------------------------------
FUNCTION:          void help
DESCRIPTION:       Help Menu
RETURNS:           N/A
NOTES:             displays help
------------------------------------------------------------------------------- */
void help()
{ 
    cout << endl;

    cout << "\n __________________________________________________________ ";
    cout << "\n|                   Command Line Arguments                 |";
    cout << "\n|                                                          |";
    cout << "\n|-inp: Will Read in the file and displays it to the screen.|";
    cout << "\n|-out: Write to an output file                             |";
    cout << "\n|-add: adding 2 matrix i.e A+B                             |";
    cout << "\n|-sub: subtracting 2 matrix i.e A-B                        |";
    cout << "\n|-mul: Multiplying 2 matrix. i.e A*B                       |";
    cout << "\n| -eq: checks for matrix equality. i.e (A=B)               |";
    cout << "\n|__________________________________________________________|";
}

/* -----------------------------------------------------------------------------
FUNCTION:          int main()
DESCRIPTION:       Programs main entry point
RETURNS:           0
NOTES:             
------------------------------------------------------------------------------- */
int main(int argc, char *argv[])
{
	int i, j;
	int m, n;

	char let_x;
	char file_name1[20+1];
	char file_name2[20+1];

	ifstream filein;
	ofstream outfile;

	Matrix_ops<int> m3;

	if (argc<2)
	{
		cout << "\nNot enough Arguments\n";
		return 0;
	}

	if (argc == 2)
	{
		if (strcmp(argv[1], "-h") == 0)
		{        
            		help();	
		}
	}

	if (strcmp(argv[1], "-add") == 0)
	{
		strcpy(file_name1, argv[2]);
		strcat(file_name1, ".mtx");
		filein.open(file_name1);

		filein >> m >> let_x >> n;
		
		Matrix_ops<int> m1(m, n);
		
		filein >> m1;
		filein.close();
		
		// seperates the matirces 1 and 2
		strcpy(file_name2, argv[3]);
		strcat(file_name2, ".mtx");
		filein.open(file_name2);

		filein >> m >> let_x >> n;

		Matrix_ops<int> m2(m, n);
		filein >> m2;
		filein.close();
		
		m3 = m2 + m1;

		cout << "\n---Adding 2 Matrices---\n" 
		<< "\nMatrix #1:\n" << m1
		<< "\nMatrix #2:\n" << m2
		<< "= \n" << m3;
	
	}

	if (strcmp(argv[1], "-sub") == 0)
	{
		strcpy(file_name1, argv[2]);
		strcat(file_name1, ".mtx");
		filein.open(file_name1);

		filein >> m >> let_x >> n;

		Matrix_ops<int> m1(m, n);

		filein >> m1;
		filein.close();

		// seperates the matirces 1 and 2
		strcpy(file_name2, argv[3]);
		strcat(file_name2, ".mtx");
		filein.open(file_name2);

		filein >> m >> let_x >> n;

		Matrix_ops<int> m2(m, n);
		filein >> m2;
		filein.close();

//		m3 = new Matrix_ops<int>(m, n);

		m3 = m2 - m1;

		cout << "\n----Subtracting 2 Matrices----\n" 
		<< "\nMatrix #1:\n" << m1
		<< "\nMatrix #2:\n" << m2
		<< "= \n" << m3;

	}
	
	if (strcmp(argv[1], "-mul") == 0)
	{	 
		strcpy(file_name1, argv[2]);
		strcat(file_name1, ".mtx");
		filein.open(file_name1);

		filein >> m >> let_x >> n;

		Matrix_ops<int> m1(m, n);

		filein >> m1;
		filein.close();

		// seperates the matirces 1 and 2
		strcpy(file_name2, argv[3]);
		strcat(file_name2, ".mtx");
		filein.open(file_name2);

		filein >> m >> let_x >> n;

		Matrix_ops<int> m2(m, n);
		filein >> m2;
		filein.close();

		m3 = m1 * m2;


		cout << "\n---Multiplying 2 Matrices ;)---\n" 
		<< "\nMatrix #1:\n" << m1
		<< "\nMatrix #2:\n" << m2
		<< "= \n" << m3;

	}

	if (strcmp(argv[1], "-inp") == 0)
	{
		strcpy(file_name1, argv[2]);
		strcat(file_name1, ".mtx");
		filein.open(file_name1);
		if (!filein)
		{
			cout << "\nError opening file:) " << file_name1 << "\n\n";
			return 0;
		}
		filein >> m >> let_x >> n;

		Matrix_ops<int> m1(m, n);
		filein >> m1;
		filein.close();

		cout << endl;
		cout << "\nInput Matrix\n";
		cout << m1 << endl;
	}

	if (strcmp(argv[1], "-eq") == 0)
	{
		strcpy(file_name1, argv[2]);
		strcat(file_name1, ".mtx");
		filein.open(file_name1);

		filein >> m >> let_x >> n;

		Matrix_ops<int> m1(m, n);

		filein >> m1;
		filein.close();
		
		strcpy(file_name2, argv[3]);
		strcat(file_name2, ".mtx");
		filein.open(file_name2);

		filein >> m >> let_x >> n;

		Matrix_ops<int> m2(m, n);
		filein >> m2;
		filein.close();

	
		cout << "\nChecking for equality...\n";
		cout << "\nMatrix #1:\n" << m1;
		cout << "\nMatrix #2:\n" << m2;

	if (m1 == m2)
	{
		cout << "\nMatrices are equal\n\n";
	}
	else
	{
		cout <<"\nMatrices are not equal\n\n";
	}

	}

	if (argc > 5 && strcmp(argv[4], "-out") == 0)
	{
		strcpy(file_name1, argv[5]);
		strcat(file_name1, ".mtx");
		outfile.open(file_name1);
		if (!outfile)
		{
			cout << "\nError opening file: " << file_name1 << "\n\n";
			return 0;
		}
		outfile << m3;
		outfile.close();
	}
	
	cout << endl;
	cout << "Programmed by: " << PROGRAMMER_NAME << " -- ";
	cout << __DATE__ << "  " __TIME__ << endl;
	cout << endl;
	cout << endl;
	
	return 0;
}
