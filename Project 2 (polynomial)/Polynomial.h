/* -----------------------------------------------------------------------------
FILE NAME:         Polynomial.h
DESCRIPTION:       Specification file
USAGE:             ./poly_class
COMPILER:          GNU g++ compiler on Linux
NOTES:             

MODIFICATION HISTORY:
Author             Date               Version
---------------    ----------         --------------
Michael Des Roches 2018-03-20         1.0 // istream ostream lab transfer to 
					  // this proj
Michael Des Roches 2018-03-22	      2.0 // changed structure
Michael Des roches 2018-03-24         3.0 // added constructor
Michael Des Roches 2018-03-24	      4.0 // addition and subtraction operators
Michael Des Roches 2018-03-27	      5.0 // memory location return functions
Michael Des Roches 2018-04-05	      6.0 // Destructor
----------------------------------------------------------------------------- */

#ifndef __POLYNOMIAL_H__
#define __POLYNOMIAL_H__

#include <iostream>

const char PROGRAMMER_NAME[] = "Michael Des Roches";

#define MAX(x,y) ((x) > (y) ? (x) : (y))
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

using namespace std;

/* -----------------------------------------------------------------------------
CLASS:             Polynomial
DESCRIPTION:       Used in conjunction with Polynomail.cpp and poly_class.cpp
NOTES:             
----------------------------------------------------------------------------- */
class Polynomial
{
private:
    int degree; 					// Degree of the polynomial
	int* coefficient; 		
public:
	Polynomial();					//constructor
	Polynomial(const Polynomial& o);//copy constructor
	Polynomial(int, int*); 			//overloaded constructor
//	~Polynomial();					//Destructor
	
	//   Overloaded operators 
	Polynomial operator = (const Polynomial & o); 
	Polynomial operator + (const Polynomial & o);
	Polynomial operator - (const Polynomial & o);
	Polynomial operator * (const Polynomial & o);
	bool operator==(const Polynomial& o);
	double operator()(int x);

	//    display and input operators
	friend ostream& operator<< (ostream& output, const Polynomial& o);
	friend istream& operator>> (istream & input, Polynomial& o);

	// functions
	int find_degree() const;
	int find_coefficient(int) const;
	void give_degree(int);
	void give_coefficient(int);
	void assign_coefficient(int, int);
	
};

#endif /*__POLYNOMIAL_H__*/
