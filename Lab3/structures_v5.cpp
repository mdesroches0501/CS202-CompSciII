/* -----------------------------------------------------------------------------
FILE NAME:         structures_v5.cpp
DESCRIPTION:       Test Prototype for structures
USAGE:             ./structures_v5
COMPILER:          GNU g++ compiler on Linux
NOTES:             add a preprocessor macro to header file

MODIFICATION HISTORY:
Author             Date               Version
---------------    ----------         --------------
Michael Des Roches 2018-02-20         5.0
----------------------------------------------------------------------------- */

#include "structures_v5.h"
#include "structures_v5.h"
#include "structures_v5.h"
#include "structures_v5.h"
#include "structures_v5.h"


/* -----------------------------------------------------------------------------
FUNCTION:          main()
DESCRIPTION:       Program's main entry poin
RETURNS:           0
NOTES:             int argc // Number of parameters on command line
		   char argv* // an array of pointers to C-strings
------------------------------------------------------------------------------- */
int main(int argc, char * argv[])
{
	StudentGrade * student = new StudentGrade;

	cout << "The size of type 'student' is : "
	     << sizeof(student) << endl << endl;

	get_student_info(& (student[0]));	//Data input
	show_student_info(student);	//Output statements

	delete student;

	cout << endl;
	cout << "Programmed by: " << PROGRAMMER_NAME << " -- ";
	cout << __DATE__ << "  " __TIME__ << endl;
	cout << endl;

	return 0;
}
/* -----------------------------------------------------------------------------
FUNCTION:          get_student_info()
DESCRIPTION:       Data Input
RETURNS:           0
NOTES:             StudentGrade *s is a pointer to out structure
------------------------------------------------------------------------------- */
void get_student_info(StudentGrade *s)
{
	cout << "The size of pointer is 's' is: " << sizeof(s) << endl << endl;

	cout << "Enter first name: "; 	// Data type
	cin >> (*s).fname;

	cout << "Enter Last name: ";
	cin >> (*s).lname;
	
	cout << "\nNumber of tests: " << ARRAY_SIZE((*s).test) << endl;

	for (size_t i = 0; i < ARRAY_SIZE((*s).test); ++i)
	{
		cout << "Enter test score: "; 
		cin >> (*s).test[i];
	}
}
/* -----------------------------------------------------------------------------
FUNCTION:          show_student_info()
DESCRIPTION:       Shows data input
RETURNS:           0
NOTES:             Pointer to our structure
------------------------------------------------------------------------------- */
void show_student_info(StudentGrade *s)
{
	unsigned int max_score = 0;

	cout << endl;		// Output statements
	cout << "First name: " << s->fname << endl;
	cout << "Last name: " << s->lname << endl;

	for (size_t i = 0; i < ARRAY_SIZE(s->test); ++i)
	{
		cout << "Test score: " << s->test[i] << endl;
		max_score = MAX(max_score, s->test[i]);
	}	
	cout << "\n Max score: " << max_score << endl;
}
