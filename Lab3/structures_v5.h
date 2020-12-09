/* -----------------------------------------------------------------------------
FILE NAME:         structures_v5.h
DESCRIPTION:       Header file for structures
USAGE:             ./structures_v5.h
COMPILER:          GNU g++ compiler on Linux
NOTES:             

MODIFICATION HISTORY:
Author             Date               Version
---------------    ----------         --------------
Michael Des Roches 2018-01-01         5.0
----------------------------------------------------------------------------- */

#ifndef __STRUCTURES_H__
#define __STRUCTURES_H__

#include <iostream>
#include <cstring>		// Brings the c-String handling functions

using namespace std;

const char PROGRAMMER_NAME[] = "Michael Des Roches";	// Global constant

#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
#define MAX(x,y) ((x) > (y) ? (x) : (y))

struct StudentGrade
{
	unsigned int test[5];	// array of 5 tests
	char fname[20 + 1];	// First name field (or data member)
	char lname[20 + 1];	// Last name field (or data member0
	double average; 	// average of 5 scores
	char letter_grade; 	// Letter grade: A B C D F

};

// Function prototypes go here
void get_student_info(StudentGrade *);
void show_student_info(StudentGrade *);

#endif /* __STRUCTURES_H__ */
