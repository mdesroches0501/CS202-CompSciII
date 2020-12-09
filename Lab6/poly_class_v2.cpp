// polyclass 
// Test


#include "Polynomial.h"
//#include "Polynomial.cpp"

int main(int argc, char * argv[])
{
	Polynomial poly[3];


	for (int n = 0; n<2; n++)
	{
		poly[n].get_poly();
		poly[n].display_poly();
	}
	
	poly[2].Add_2_Polynomials(poly[0], poly[1]);

	poly[2].display_poly();

	return 0;
}
