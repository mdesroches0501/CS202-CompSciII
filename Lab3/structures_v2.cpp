/* -----------------------------------------------------------------------------
FILE NAME:         structures_v2.cpp
DESCRIPTION:       Template for building stand-alone programs
USAGE:             ./structures_v2
COMPILER:          GNU g++ compiler on Linux
NOTES:             Test prototype for structures, create an input function

MODIFICATION HISTORY:
Author             Date               Version
---------------    ----------         --------------
Michael Des Roches 2018-02-20         2.0
----------------------------------------------------------------------------- */

#include <iostream>
#include <cstring>		// Brings the c-String handling functions

using namespace std;

const char PROGRAMMER_NAME[] = "Michael Des Roches";	// Global constant

struct StudentGrade
{
	unsigned int test[5];	// array of 5 tests
	char fname[20 + 1];	// First name field (or data member)
	char lname[20 + 1];	// Last name field (or data member0
	double average; 	// average of 5 scores
	char letter_grade; 	// Letter grade: A B C D F

};

void get_student_info(StudentGrade *);

/* -----------------------------------------------------------------------------
FUNCTION:          main()
DESCRIPTION:       Programs Main entry point
RETURNS:           0
NOTES:             int argc // number of parameters on commant line
		   char argv // an array of pointer to C-strings
------------------------------------------------------------------------------- */
int main(int argc, char * argv[])
{
	StudentGrade student;

	cout << "The size of type 'StudentGrade' is : "
	     << sizeof(StudentGrade) << endl << endl;

	get_student_info(& student);	//Data input

	cout << "First name: " << student.fname << endl;
	cout << "Last Name: " << student.lname << endl;

	for (int i = 0; i < 5; ++i)
	
		cout << "Test Score: " << student.test[i] << endl;


	cout << endl;
	cout << "Programmed by: " << PROGRAMMER_NAME << " -- ";
	cout << __DATE__ << "  " __TIME__ << endl;
	cout << endl;

	return 0;
}

/* -----------------------------------------------------------------------------
FUNCTION:          get_student_info()          
DESCRIPTION:       A seperate function for data input
RETURNS:           0
NOTES:             data input
------------------------------------------------------------------------------- */
void get_student_info(StudentGrade *s)
{
	cout << "The size of pointer is 's' is: " << sizeof(s) << endl << endl;

	cout << "Enter first name: "; 	// Data type
	cin >> (*s).fname;

	cout << "Enter Last name: ";
	cin >> (*s).lname;

	for (int i = 0; i < 5; ++i)
	{
		cout << "Enter test score: "; 
		cin >> (*s).test[i];
	}
}
