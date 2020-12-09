/* -----------------------------------------------------------------------------
FILE NAME:         structures_v6.cpp
DESCRIPTION:       Test program for structures
USAGE:             ./structures_v6
COMPILER:          GNU g++ compiler on Linux
NOTES:             Calculates average grade

MODIFICATION HISTORY:
Author             Date               Version
---------------    ----------         --------------
Michael Des Roches 2018-02-20         6.0
----------------------------------------------------------------------------- */

#include "structures_v6.h"

/* -----------------------------------------------------------------------------
FUNCTION:          main()
DESCRIPTION:       Program's main entry point
RETURNS:           0
NOTES:             int argc // number of parameters on the command line
		   char *argv // an array of pointers to c-strings
------------------------------------------------------------------------------- */
int main(int argc, char * argv[])
{
	StudentGrade * student = new StudentGrade;

	cout << "The size of type 'student' is : "
	     << sizeof(student) << endl << endl;

	get_student_info(& (student[0]));	//Data input
	student->average = get_average(ARRAY_SIZE(student->test), student->test);
	student->letter_grade = get_grade(student->average);
	show_student_info(student);	//Output statements

	cout << endl;
	cout << "Programmed by: " << PROGRAMMER_NAME << " -- ";
	cout << __DATE__ << "  " __TIME__ << endl;
	cout << endl;

	delete student;

	return 0;
}

// "Get student info()" function

/* -----------------------------------------------------------------------------
FUNCTION:          get_student_info()
DESCRIPTION:       Data input function
RETURNS:           0
NOTES:             StudentGrade *s points to structure
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

// "show student info()" function

/* -----------------------------------------------------------------------------
FUNCTION:          show_student_info()
DESCRIPTION:       Shows data input from get student info function
RETURNS:           average 
NOTES:             StudentGrade *s points to structure
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
	cout << " Average: " << s->average << endl;
	cout << "   Grade: " << s->letter_grade << endl;
	cout << endl;
}
double get_average(int num_tests, unsigned int test[])
{
	double sum = 0.0;

	for (size_t i = 0; i < num_tests; ++i)
		sum += test[i];

	return(sum / num_tests);
}

/* -----------------------------------------------------------------------------
FUNCTION:          get_grade()
DESCRIPTION:       Recieves average grade
RETURNS:           grade
NOTES:             assigns a letter grade according to criterea
------------------------------------------------------------------------------- */
char get_grade(double avg)
{
	char grade = 'F';

	if (avg >= 60) grade = 'D';
	if (avg >= 70) grade = 'C';
	if (avg >= 80) grade = 'B';
	if (avg >= 90) grade = 'A';

	return (grade);
}
