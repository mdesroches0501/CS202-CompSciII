/* -----------------------------------------------------------------------------
FILE NAME:         command_line_v1.cpp
DESCRIPTION:       Test program for reading command_line parameters
USAGE:             ./command_line_v1.cpp
COMPILER:          GNU g++ compiler on Linux
NOTES:             

MODIFICATION HISTORY:
Author             Date               Version
---------------    ----------         --------------
Michael Des Roches 2018-02-13         2.0
----------------------------------------------------------------------------- */

const char PROGRAMMER_NAME[] = "Michael Des Roches";	// Global constant
#include <iostream>
using namespace std;
void clear_screen();

/* -----------------------------------------------------------------------------
FUNCTION:          int main(int argc, char *argv[])
DESCRIPTION:       Program's main entry point
RETURNS:           0
NOTES:             int argc // number of parameters on the command-line
		   char *argv[]  // An array of pointers to C-strings
------------------------------------------------------------------------------- */

int main(int argc, char *argv[])
{
	clear_screen();

	for (int i = 0; i < argc; ++i)
	{		
	cout << "Command line parameter " << i
	<< " = " << argv[i] << endl;
	}

	cout << endl;

	cout << endl;
	cout << "Programmed by: " << PROGRAMMER_NAME << " -- ";
	cout << __DATE__ << "  " __TIME__ << endl;
	cout << endl;

	return 0;	// 0=success
}

/* -----------------------------------------------------------------------------
FUNCTION:          void clear_screen()
DESCRIPTION:       clears 50 lines 
RETURNS:           N/A
NOTES:             for loop that makes 50 clear lines
------------------------------------------------------------------------------- */

void clear_screen()
{
	for (int i = 0; i < 50; ++i)
		cout << endl;
}

