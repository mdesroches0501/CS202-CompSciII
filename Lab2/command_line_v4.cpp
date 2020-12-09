/* -----------------------------------------------------------------------------
FILE NAME:         command_line_v4.cpp
DESCRIPTION:       Lists command line inputs from user
USAGE:             ./command_line_v4
COMPILER:          GNU g++ compiler on Linux
NOTES:             Makes sure inputs are valid options, states if it doesn't

MODIFICATION HISTORY:
Author             Date               Version
---------------    ----------         --------------
Michael Des Roches 2018-02-13         4.0
----------------------------------------------------------------------------- */

#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

const char PROGRAMMER_NAME[] = "Michael Des Roches";	// Global constant

void check_arg(char[]);



/* -----------------------------------------------------------------------------
FUNCTION:          main()
DESCRIPTION:       The program's main entry point
RETURNS:           0
NOTES:             int argc is the number of parameters on the command line
		   char *argv[] is an array of pointers to c-strings
------------------------------------------------------------------------------- */
int main(int argc, char *argv[])
{
	cout << endl;
	for (int i = 0; i < argc; ++i)       // seperates inputs divided by spaces and lists the argument
	{
		cout << "Argument " << i << " : " << left << setw(16) << argv[i];
		if (i)  check_arg(argv[i]);	// if argument is 0, calls check arg function
		else	cout << endl;
	}
	cout << endl;
	
	cout << endl;
	cout << "Programmed by: " << PROGRAMMER_NAME << " -- ";
	cout << __DATE__ << "  " __TIME__ << endl;
	cout << endl;

	return 0;
}

/* -----------------------------------------------------------------------------
FUNCTION:          void check_arg
DESCRIPTION:       Lists command-line inputs
RETURNS:           0
NOTES:             called if argument is 0 in main function
------------------------------------------------------------------------------- */
void check_arg(char arg[])
{
	char buf[100];
	const char SLASH = '/';
	char valid_options[] = "?ACDFILMNOPRSTW";
	char * p = valid_options;

	bool first_char = arg[0] == SLASH;	// Test 1st arg's character

	bool second_char = false;		// Test 1st arg's 2nd character

	for (; *p != 0; ++p)			// de-refrence pointer fix from version 3
	{
		second_char = arg[1] == *p;	// checks to see if a valid option
		if (second_char == true)
			break;
	}
	if (!first_char || !second_char)
	   cout << "Invalid argument" << endl;

	else
	{
		cout << "Option: " << *p ;

	if (arg[2] != 0)
	{
		strcpy(buf, arg+2);
		cout << "  Value: " << buf;
	}
	cout << endl;
	}

}
