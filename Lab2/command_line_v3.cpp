/* -----------------------------------------------------------------------------
FILE NAME:         command_line_v3.cpp
DESCRIPTION:       Test program for passing a command line
USAGE:             ./command_line_v3
COMPILER:          GNU g++ compiler on Linux
NOTES:             Program does not work correctly, v4 denotes fixes 

MODIFICATION HISTORY:
Author             Date               Version
---------------    ----------         --------------
Michael Des Roches 2018-02-13         3.0
----------------------------------------------------------------------------- */

const char PROGRAMMER_NAME[] = "Michael Des Roches";	// Global constant

#include <iostream>
#include <cstring>

using namespace std;

/* -----------------------------------------------------------------------------
FUNCTION:          main()
DESCRIPTION:       Program's main entry point
RETURNS:           0
NOTES:             int argc	// Number of parameters on the command-line
		   char *argv[] // An array of pointers to C-strings
------------------------------------------------------------------------------- */
int main(int argc, char *argv[])
{
	cout << endl;
	for (int i = 0; i < argc; ++i)
	{
		cout << "Argument " << i << " : " << argv[i] << endl;
	}
	cout << endl;

	char * argument = argv[1];
	const char SLASH = '/';

	char valid_options[] = "?ACDFILMNOPRSTW";
	char * p = valid_options;

	bool first_char = argument[0] == SLASH;	// Test 1st arg's character

	bool second_char = false;		// Test 1st arg's 2nd character

	for (; p != 0; ++p)
	{
		second_char = argument[1] == *p;
		if (second_char == true)
			break;
	}

	char bfr[100 + 1];			// look for a string

	bool string_found = argument[2] != 0;
	strcpy(bfr, argument+2);

	cout << "Database file: " << bfr << endl;

	cout << endl;
	cout << "Programmed by: " << PROGRAMMER_NAME << " -- ";
	cout << __DATE__ << "  " __TIME__ << endl;
	cout << endl;

	return 0;
}
