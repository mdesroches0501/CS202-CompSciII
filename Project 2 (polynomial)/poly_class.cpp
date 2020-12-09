/* -----------------------------------------------------------------------------
FILE NAME:         poly_class.cpp
DESCRIPTION:       Driver file
USAGE:             ./poly_class
COMPILER:          GNU g++ compiler on Linux
NOTES:             

MODIFICATION HISTORY:
Author             Date               Version
---------------    ----------         --------------
Michael Des Roches 2018-03-20         1.0 // istream ostream lab transfer to 
					  // this proj
Michael Des Roches 2018-03-22	      2.0 // division operator
Michael Des roches 2018-03-24         3.0 // multiplication operator
Michael Des Roches 2018-03-24	      4.0 // addition and subtraction operators
Michael Des Roches 2018-03-27         5.0 // memory location return functions
Michael Des Roches 2018-04-05         6.0 // Destructor/ any degree
----------------------------------------------------------------------------- */

#include "Polynomial.h"

/* -----------------------------------------------------------------------------
FUNCTION:          main()
DESCRIPTION:       Program's main entry point
RETURNS:           0
NOTES:             
------------------------------------------------------------------------------- */
int main(int argc, char * argv[])
{
	int x;
	int f[1+1];
	
	Polynomial p1, p2, p3;

	cout << "\n\tInitializing polynomial #1...\n ";
	cin >> p1;

	cout << "\n\tInitializing polynomial #2...\n ";
	cin >> p2;

	cout << "\nPolynomial #1: ";
	cout << p1 << endl;

	cout << "\nPolynomial #2: ";
	cout << p2 << endl;

	cout << "\nAdding 2 Polynomials...\n";
	p3 = p1 + p2;
	cout << "Answer is: ";
	cout << p3 << endl;

	cout << "\nSubtracting 2 Polynomials...\n";
	p3 = p1 - p2;
	cout << "Answer is: ";
	cout << p3 << endl;

	cout << "\nMultiplying 2 Polynomials\n";
	p3 = p1 * p2;
	cout << "Answer is:";
	cout << p3 << endl;

	cout << "\nChecking for Equality...\n";
	if ((p1 == p2))
	{
		cout << "\nPolynomails are equivalent.\n";
		cout << p1 << " = " << p2 << endl; 
	}
	else
	{
		cout << "\nPolynomials are not Equivalent\n";
		cout << p1 << " does not equal " << p2 << endl;
	}

	cout << "\nEvaluate for Any Value\n";
	cout << "----------------------";
	p3 = p1 * p2;
	cout << "\nEnter an x value:";
	cin >> x;

	cout << endl;

	cout << "Answer for Poly #3 is: ";
	p3(x);
	cout << endl;
	
	cout << endl;
	cout << "Programmed by: " << PROGRAMMER_NAME << " -- ";
	cout << __DATE__ << "  " __TIME__ << endl;
	cout << endl;
	cout << endl;

	return 0;
}
