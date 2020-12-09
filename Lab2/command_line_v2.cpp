/* -----------------------------------------------------------------------------
FILE NAME:         command_line_v2.cpp
DESCRIPTION:       This program demonstrates how to display command-line 
		   arguments
USAGE:             ./command_line_v2
COMPILER:          GNU g++ compiler on Linux
NOTES:             Uses argc and argv in a while loop

MODIFICATION HISTORY:
Author             Date               Version
---------------    ----------         --------------
Michael Des Roches 2018-02-13         3.0
----------------------------------------------------------------------------- */

#include <iostream>

using namespace std;

const char PROGRAMMER_NAME[] = "Michael Des Roches";	// Global constant

/* -----------------------------------------------------------------------------
FUNCTION:          main(int argc, char *argv[])
DESCRIPTION:       Program's main entry point
RETURNS:           0
NOTES:             int argc	// Number of parameters on the comman-line
		   char *argv[] // An array of pointers to C-strings
------------------------------------------------------------------------------- */
int main(int argc, char *argv[])
{
	int i = 0;

	cout << endl;

	if (argc==1) cout << "Arguments ?/n/n";

	cout <<  "argc = " << argc << endl;
	
	while(argc--)
	{
		cout << "argc = " << argc << "    ";
		cout << "Argument # " << i++ << "   is:   ";
		cout << *argv++ << endl;
	}
	cout << endl;

	cout << endl;
	cout << "Programmed by: " << PROGRAMMER_NAME << " -- ";
	cout << __DATE__ << "  " __TIME__ << endl;
	cout << endl;

	return 0;
}
