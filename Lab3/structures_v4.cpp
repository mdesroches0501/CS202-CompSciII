// structures_v3.cpp
/* -----------------------------------------------------------------------------
FILE NAME:         structures_v4.cpp
DESCRIPTION:       test program for structures
USAGE:             ./structures_v4
COMPILER:          GNU g++ compiler on Linux
NOTES:             Same as version 3 but header file is seperated

MODIFICATION HISTORY:
Author             Date               Version
---------------    ----------         --------------
Michael Des Roches 2018-01-01         4.0
----------------------------------------------------------------------------- */

#include "structures_v4.h" // Includes the newly made header file

const char PROGRAMMER_NAME[] = "Michael Des Roches";	// will include in header file

/* -----------------------------------------------------------------------------
FUNCTION:          main()
DESCRIPTION:       programs main entry point
RETURNS:           0
NOTES:             int argc // # of parameters on the command line
	 	   char *argv[] // an array of pointers to c-strings
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
DESCRIPTION:       Data input
RETURNS:           0
NOTES:             StudentGrade *s is the pointer to our structure
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
FUNCTION:	   show_student_info()
DESCRIPTION:       shows data input from other function
RETURNS:           0
NOTES:             StudentGrade *s is a pointer to our structure
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
