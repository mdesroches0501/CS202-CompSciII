* -----------------------------------------------------------------------------
FILE NAME:         cs202_template.cpp
DESCRIPTION:       Template for building stand-alone programs
USAGE:             ./cs202_template
COMPILER:          GNU g++ compiler on Linux
NOTES:             // This program stores the address of a cariable in a pointer.

MODIFICATION HISTORY:
Author             Date               Version
---------------    ----------         --------------
Michael Des Roches 2018-01-01         1.0
----------------------------------------------------------------------------- */

#include <iostream>

using namespace std;

const char PROGRAMMER_NAME[] = "Michael Des Roches";	// Global constant

/* -----------------------------------------------------------------------------
FUNCTION:          main()
DESCRIPTION:       Say something meaningful
RETURNS:           0
NOTES:             
------------------------------------------------------------------------------- */

int main()
{
	int x = 25;     	// int variable
	int *ptr = nullptr;	// Pointer variable, can point to an int

	ptr = &x; 		// Store the address of x in ptr

	cout << "The hex address of x is:  " << ptr  << endl;
	cout << "The dec address of x is:  " << (long long) ptr  << endl;
	cout << "The size of ptr is " << sizeof(ptr) << " bytes\n";

	cout << endl;

	cout << "The size of x is " << sizeof(x) << " bytes\n";
	cout << "The value in x is " << x << endl;

	cout << endl;
	cout << "Programmed by: " << PROGRAMMER_NAME << " -- ";
	cout << __DATE__ << "  " __TIME__ << endl;
	cout << endl;

	return 0;
