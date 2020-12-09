/* -----------------------------------------------------------------------------
FILE NAME:         structures_v1.cpp
DESCRIPTION:       Test program for structures
USAGE:             ./structures_v1
COMPILER:          GNU g++ compiler on Linux
NOTES:             

MODIFICATION HISTORY:
Author             Date               Version
---------------    ----------         --------------
Michael Des Roches 2018-01-01         1.0
----------------------------------------------------------------------------- */

const char PROGRAMMER_NAME[] = "Michael Des Roches";	// Global constant

/* -----------------------------------------------------------------------------
FUNCTION:          main()
DESCRIPTION:       Say something meaningful
RETURNS:           0
NOTES:             
------------------------------------------------------------------------------- */

// Version 1 ... basic version

#include <iostream>
#include <cstring>		// Brings the c-String handling functions

using namespace std;

struct StudentGrade
{
	unsigned int test[5];	// array of 5 tests
	char fname[20 + 1];	// First name field (or data member)
	char lname[20 + 1];	// Last name field (or data member0
	double average; 	// average of 5 scores
	char letter_grade; 	// Letter grade: A B C D F

};

// Function prototypes go here

/* -----------------------------------------------------------------------------
FUNCTION:          main()
DESCRIPTION:       Program's main entry point
RETURNS:           0
NOTES:             int argc  // Number of parameters on command line
		   char *argv[]  // An array of pointer to C-strings
------------------------------------------------------------------------------- */
int main(int argc, char * argv[])
{
	StudentGrade student;

	cout << "Enter first name: ";
	cin >> student.fname;

	cout << "Enter last Name: ";
	cin >> student.lname;

	for (int i = 0; i < 5; ++i)
	{
		cout << "Enter test score: ";
		cin >> student.test[i];
	}

	cout << endl;			// Output statements
	cout << "First name: " << student.fname << endl;
	cout << "Last name: " << student.lname << endl;

	for (int i = 0; i <5; ++i)
		cout << "Test score: " << student.test[i] << endl;
	
	cout << endl;
	cout << "Programmed by: " << PROGRAMMER_NAME << " -- ";
	cout << __DATE__ << "  " __TIME__ << endl;
	cout << endl;

	return 0;
}
