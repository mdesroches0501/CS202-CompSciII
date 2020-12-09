#ifndef __POLYNOMIAL_H__
#define __POLYNOMIAL_H__


#include <iostream>

#define MAX(x,y) ((x) > (y) ? (x) : (y)) // Macros
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

using namespace std;

class Polynomial
{
	private:
		int degree;		// Degree of polynomial
		int coef[9];		// Array of coefficients

	public:
		Polynomial();
		void get_poly();
		void display_poly();
		void Add_2_Polynomials(Polynomial, Polynomial);

		Polynomial operator + (const Polynomial &);  // Overload + operator
};

#endif /* __POLYNOMIAL_H__ */
