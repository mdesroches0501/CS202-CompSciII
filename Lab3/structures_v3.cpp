// structures_v3.cpp
/* -----------------------------------------------------------------------------
FILE NAME:         structures_v3.cpp
DESCRIPTION:       Test prototype for structures
USAGE:             ./structures_v3
COMPILER:          GNU g++ compiler on Linux
NOTES:             Create an output function

MODIFICATION HISTORY:
Author             Date               Version
---------------    ----------         --------------
Michael Des Roches 2018-02-20         3.0
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
void show_student_info(StudentGrade *);

/* -----------------------------------------------------------------------------
FUNCTION:          main()
DESCRIPTION:       programs main entry point 
RETURNS:           0
NOTES:             int argc // Number of parameters on the comman line
		   char *argv[] // An array of pointers to c-strings
------------------------------------------------------------------------------- */
int main(int argc, char * argv[])
{
	StudentGrade student;

	cout << "The size of type 'student' is : "
	     << sizeof(student) << endl << endl;

	get_student_info(& student);	//Data input
	show_student_info(& student);	//Output statements

	cout << endl;
	cout << "Programmed by: " << PROGRAMMER_NAME << " -- ";
	cout << __DATE__ << "  " __TIME__ << endl;
	cout << endl;

	return 0;
}

/* -----------------------------------------------------------------------------
FUNCTION:          get_student_info()
DESCRIPTION:       Data input function
RETURNS:           0
NOTES:             
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

// "show student info()" function

/* -----------------------------------------------------------------------------
FUNCTION:          show_student_info
DESCRIPTION:       Shows student info from data input
RETURNS:           0
NOTES:             
------------------------------------------------------------------------------- */
void show_student_info(StudentGrade *s)
{
	cout << endl;		// Output statements
	cout << "First name: " << s->fname << endl;
	cout << "Last name: " << s->lname << endl;

	for (int i = 0; i < 5; ++i)
		cout << "Test score: " << s->test[i] << endl;
}
