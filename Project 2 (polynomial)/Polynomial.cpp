/* -----------------------------------------------------------------------------
FILE NAME:         Polynomial.cpp
DESCRIPTION:       Implimentation file
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
Michael Des Roches 2018-04-05	      6.0 // any degree poly implimentation
----------------------------------------------------------------------------- */

#include"Polynomial.h"

/* -----------------------------------------------------------------------------
FUNCTION:          istream& operator>>();
DESCRIPTION:       Overrides the input operator to get input form user.
RETURNS:           input
NOTES:             
----------------------------------------------------------------------------- */
istream& operator>>(istream& input, Polynomial& o)
{
	int deg;//temp

	cout << "\nEnter the degree of the Polynomial :";
	input >> deg;

	o.give_degree(deg); 

	int* coeff = new int[deg + 1];

	cout << "\nEnter " << deg + 1 << " coefficients: ";
	for (int i = 0; i <= o.find_degree(); i++) 
	{
		input >> coeff[i];
	}

	o.give_coefficient(deg);

	for (int i = 0; i <= o.find_degree(); i++)
	{ 
		o.assign_coefficient(i, coeff[i]);
	}
	return input;
}

/* -----------------------------------------------------------------------------
FUNCTION:          ostream& operator<<();
DESCRIPTION:       Overrides the output operator to display info to the user
RETURNS:           output
NOTES:             
----------------------------------------------------------------------------- */
ostream& operator<<(ostream& output, const Polynomial& o)
{
		for (int x = o.find_degree(); x >= 1; x--)
		{
			cout << o.find_coefficient(x) << "x^" << x << " + ";
		}
		cout << o.find_coefficient(0);

		return output;
}

/* -----------------------------------------------------------------------------
FUNCTION:          Polynomial::Polynomial()
DESCRIPTION:       This is the CONSTRUCTOR function
RETURNS:           Sets to zero
NOTES:             
----------------------------------------------------------------------------- */
Polynomial::Polynomial()	//constructor
{
    coefficient = NULL;
    degree = 0;  		//initialize to zero	
}

/* -----------------------------------------------------------------------------
FUNCTION:          Polynomial::Polynomial()
DESCRIPTION:       This is the OVERLOADED class function
RETURNS:           Overloads our variables
NOTES:             
----------------------------------------------------------------------------- */
Polynomial::Polynomial(int deg, int* new_coef)
{
	degree = deg;
	coefficient = new int[deg + 1];

	for (int i = 0; i <= degree; i++)
		coefficient[i] = new_coef[i];
}
/* -----------------------------------------------------------------------------
FUNCTION:          Polynomial Polynomial::operator + ();
DESCRIPTION:       This overrides the ADDITION operator.
RETURNS:           Memory location
NOTES:             
----------------------------------------------------------------------------- */
Polynomial Polynomial::operator + (const Polynomial & o)
{
	int new_size = (o.find_degree() > degree) ? o.find_degree() : degree;
	int *new_coefficient = new int[new_size + 1];

	for (int i = 0; i <= new_size; i++)
	{
		new_coefficient[i] = 0;
	}

	for (int i = 0; i <= o.find_degree(); i++)
	{
		new_coefficient[i] = o.find_coefficient(i);
	}
	if (coefficient != NULL) {
		for (int i = 0; i <= degree; i++)
		{
			new_coefficient[i] += coefficient[i];
		}
	}
	coefficient = new_coefficient;
	degree = new_size;
	return *this;
}
/* -----------------------------------------------------------------------------
FUNCTION:          Polynomial::Polynomial()
DESCRIPTION:       copy constructor class function
RETURNS:           Copies of our variables
NOTES:             
----------------------------------------------------------------------------- */
Polynomial::Polynomial(const Polynomial& o)	//copy constructor
{
	int new_size = o.find_degree();
	int *new_coefficient = new int[new_size + 1];

	for (int i = 0; i <= new_size; i++) 
	{
		new_coefficient[i] = 0;
	}

	for (int i = 0; i <= o.find_degree(); i++)
	{
		new_coefficient[i] = o.find_coefficient(i);
	}
	
	coefficient = new_coefficient;
	degree = new_size;
}
/* -----------------------------------------------------------------------------
FUNCTION:          Polynomial Polynomial::operator = ();
DESCRIPTION:       This overrides the assignment operator.
RETURNS:           Memory location
NOTES:
----------------------------------------------------------------------------- */
Polynomial Polynomial::operator = (const Polynomial & o)
{
	int new_size = o.find_degree();
	int *new_coefficient = new int[new_size + 1];

	for (int i = 0; i <= new_size; i++)
	{
		new_coefficient[i] = 0;
	}

	for (int i = 0; i <= o.find_degree(); i++)
	{
		new_coefficient[i] = o.find_coefficient(i);
	}

	coefficient = new_coefficient;
	degree = new_size;
	return *this;
}

/* -----------------------------------------------------------------------------
FUNCTION:          Polynomial Polynomial::operator * ()
DESCRIPTION:       This overrides the multiplication  operator.
RETURNS:           Memory location
NOTES:
----------------------------------------------------------------------------- */
Polynomial Polynomial::operator * (const Polynomial & o)
{
	int new_size = o.find_degree() + degree;
	int *new_coefficient = new int[new_size + 1];

	for (int i = 0; i <= new_size; i++)
	{
		new_coefficient[i] = 0;
	}
	if (coefficient != NULL)
	{
		for (int i = 0; i <= degree; i++) 
		{
			for (int j = 0; j <= o.find_degree(); j++)
			{
				new_coefficient[i + j] += coefficient[i] * o.find_coefficient(j);
			}
		}
	}

	coefficient = new_coefficient;
	degree = new_size;
	return* this;
}
/* -----------------------------------------------------------------------------
FUNCTION:          Polynomial Polynomial::operator - ();
DESCRIPTION:       This overrides the SUBTRACTION operator.
RETURNS:           Memory location
NOTES:
----------------------------------------------------------------------------- */
Polynomial Polynomial::operator - (const Polynomial & o)
{ 

	int new_size = (o.find_degree() > degree) ? o.find_degree() : degree;
	int *new_coefficient = new int[new_size + 1];

	for (int i = 0; i <= new_size; i++)
	{
		new_coefficient[i] = 0;
	}

	for (int i = 0; i <= o.find_degree(); i++)
	{
		new_coefficient[i] = -o.find_coefficient(i);
	}
	if (coefficient != NULL) {
		for (int i = 0; i <= degree; i++)
		{
			new_coefficient[i] += coefficient[i];
		}
			
	}
	coefficient = new_coefficient;
	degree = new_size;
	return *this;
	
}

/* -----------------------------------------------------------------------------
FUNCTION:          Polynomial Polynomial::operator == ();
DESCRIPTION:       This overrides the DOUBLE EQUALITY operator.
RETURNS:           TRUE OR FALSE 
NOTES:
----------------------------------------------------------------------------- */
bool Polynomial::operator==(const Polynomial& o)
{
	if (degree != o.degree)
		return false;

	if (coefficient != NULL)
	{
		for (int i = 0; i <= degree; i++) 
		{
			if (coefficient[i] != o.find_coefficient(i))
				return false;
		}
	}
	return true;
}

/* -----------------------------------------------------------------------------
FUNCTION:          Polynomial Polynomial::operator () ();
DESCRIPTION:       This overrides the EVALUATION operator.
RETURNS:           INT
NOTES:
----------------------------------------------------------------------------- */
double Polynomial:: operator()(int x)
{
	int j = 0;

	if (coefficient != NULL) {
		for (int i = find_degree(); i >= 0; i--)
		{
			j = coefficient[i] + (x * j);

		}
	}
	
	cout << j ;

	return j;

}

/* -----------------------------------------------------------------------------
FUNCTION:          Polynomial::find_degree()
DESCRIPTION:       returns the value of degree 
RETURNS:           degree
NOTES:             
----------------------------------------------------------------------------- */
int Polynomial::find_degree() const
{
	return degree;
}
/* -----------------------------------------------------------------------------
FUNCTION:          Polynomial::find_coefficient()
DESCRIPTION:       looks for coefficents through array
RETURNS:           int
NOTES:             
----------------------------------------------------------------------------- */
int Polynomial::find_coefficient(int i) const
{
	if (coefficient != NULL) {
		return coefficient[i];
	}

	return 0;
}

/* -----------------------------------------------------------------------------
FUNCTION:          void Polynomial::give_degree()
DESCRIPTION:       gives degree a value
RETURNS:           Void function
NOTES:             
----------------------------------------------------------------------------- */
void Polynomial::give_degree(int i)
{
	degree = i;
}
/* -----------------------------------------------------------------------------
FUNCTION:          Polynomial::assign_coefficient()
DESCRIPTION:       assigns the array with the pointer 
RETURNS:           Void function
NOTES:             
----------------------------------------------------------------------------- */
void Polynomial::assign_coefficient(int n, int i)
{
	coefficient[n] = i;
}
/* -----------------------------------------------------------------------------
FUNCTION:          Polynomial::give_coefficient()
DESCRIPTION:       sets our variable equal to an array 
RETURNS:           Void function
NOTES:             
----------------------------------------------------------------------------- */
void Polynomial::give_coefficient(int i)
{
	coefficient = new int[i + 1];
}
Polynomial::~Polynomial()	//Destructor
{
	
	/*
	if (coefficient != NULL)	
	{
		delete[]coefficient;
	}
	*/
}