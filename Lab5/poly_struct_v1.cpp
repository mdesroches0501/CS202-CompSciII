// poly_struct_v1.cpp
// Test program for polynomials implemented as structures

// Version 1 ... Basic version Accessing polynomial array with pointers

#include <iostream>

#define MAX(x,y) ((x) > (y) ? (x) : (y)) // Macros

using namespace std;

struct Polynomial
{
	int degree;		// Degree of polynomial
	int coef[9];		// Array of coefficients
};

void get_poly(Polynomial *);
void display_poly(Polynomial *);
void Add_2_Polynomials(Polynomial *);


// "main() function --- the programs main entry point
// int argc // number of parameters on the command line
// char *argv[] 	/ an array of pointers to cstrings

int main(int argc, char * argv[])
{
	Polynomial poly[3];

	for (int n = 0; n < 2; n++)
	{
		get_poly(poly+n);
		display_poly(poly+n);
	}
	
	Add_2_Polynomials(poly);

	display_poly(poly+2);

	return 0;
}

void get_poly(Polynomial *p)
{
	cout << "\nEnter degree of polynomial: ";
	cin >> p->degree;

	cout << "\nEnter the " << p->degree+1 << " coefficient: ";

	for (int i = p->degree; i >= 0; i--)
		cin >> p->coef[i];
}

void display_poly(Polynomial *p)
{
	cout << "\n\t";		//Displays polynomial

	for (int i = p->degree; i >= 0; i--)
	{
		if (i < p->degree)
		{
		if (p->coef[i] >= 0)cout << " +";
		else cout << " ";
		}
	
	cout << p->coef[i];

	if (i>1) cout << "x^" << i ;
	if (i==1) cout << "x";
	}
	cout << endl;
	cout << endl;
}

void Add_2_Polynomials(Polynomial *p)
{
	cout << "\nAdding the two Polynomials: \n\n";

	(p+2)->degree = MAX(p->degree, (p+1)->degree);

	for (int i = (p+2)->degree; i >=0; i--)
		(p+2)->coef[i] = p->coef[i] + (p+1)->coef[i];
}


