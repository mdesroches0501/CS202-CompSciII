/* -----------------------------------------------------------------------------
FILE NAME:         structures_v7.cpp
DESCRIPTION:       Test program for structures
USAGE:             ./structures_v7
COMPILER:          GNU g++ compiler on Linux
NOTES:             Reads input from command line

MODIFICATION HISTORY:
Author             Date               Version
---------------    ----------         --------------
Michael Des Roches 2018-02-20         7.0
----------------------------------------------------------------------------- */


#include "structures_v7.h"

// "main()" function --- the program's entry point
// in argc		// Number of parameters on the command line
// char *argv[]		// An array of pointers to C-strings

/* -----------------------------------------------------------------------------
FUNCTION:          main()
DESCRIPTION:       Program's main entry poin
RETURNS:           0
NOTES:             int argc // Number of parameters on the command line
		   char *argv[] // an array of pointers to C-strings
------------------------------------------------------------------------------- */
int main(int argc, char * argv[])
{
	StudentGrade * student = new StudentGrade;

	cout << "argc = " << argc << endl;

	if (argc > 1)
		read_file(argv[1], student);
	else 
		get_student_info(cin, student, 1);	//Data Input


	student->average = get_average(ARRAY_SIZE(student->test), student->test);
	student->letter_grade = get_grade(student->average);
	show_student_info(student);	//Output statements

	delete student;

	cout << endl;
	cout << "Programmed by: " << PROGRAMMER_NAME << " -- ";
	cout << __DATE__ << "  " __TIME__ << endl;
	cout << endl;

	return 0;
}

/* -----------------------------------------------------------------------------
FUNCTION:          read_file()
DESCRIPTION:       opens and closes file
RETURNS:           N/A
NOTES:             use of a single function instead of using two functions
------------------------------------------------------------------------------- */
void read_file(char * file, StudentGrade *student)
{
	ifstream infile(file);

	if (!infile)	//Test for errors
		cout << "\nError opening file: " << file << "\n\n";

	else
	{
		cout << "Input File: " << file << endl;
		get_student_info(infile, student, 0);	//Data input
		infile.close();
	}
}

/* -----------------------------------------------------------------------------
FUNCTION:          get_info()
DESCRIPTION:       Data input 
RETURNS:           N/A
NOTES:             StudentGrade *s poinst to structure
------------------------------------------------------------------------------- */
void get_student_info(istream &in, StudentGrade *s, bool mode)
{
	if (mode) cout << "Enter first name: ";
	in >> (*s).fname;

	if (mode) cout << "Enter last name: ";
	in >> (*s).lname;
	
	cout << "\nNumber of tests: " << ARRAY_SIZE((*s).test) << endl;

	for (size_t i = 0; i < ARRAY_SIZE((*s).test); ++i)
	{
		if (mode) cout << "Enter test score: "; 
		in >> (*s).test[i];
	}
}

/* -----------------------------------------------------------------------------
FUNCTION:          show_student_info()
DESCRIPTION:       Shows data input 
RETURNS:           N/A
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
/* -----------------------------------------------------------------------------
FUNCTION:          get_average()
DESCRIPTION:       Gets average of data input of 5 test scores
RETURNS:           sum / num_tests // average
NOTES:             
------------------------------------------------------------------------------- */
double get_average(int num_tests, unsigned int test[])
{
	double sum = 0.0;

	for (size_t i = 0; i < num_tests; ++i)
		sum += test[i];

	return(sum / num_tests);
}

/* -----------------------------------------------------------------------------
FUNCTION:          get_grade()
DESCRIPTION:       recieves data input and returns a grade
RETURNS:           grade
NOTES:             assigns a letters grade depending on data input
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
