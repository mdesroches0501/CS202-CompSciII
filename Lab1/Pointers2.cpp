/* -----------------------------------------------------------------------------
FILE NAME:         Projects2 .cpp
DESCRIPTION:       Outputs hex and dex address of characters plus size 
USAGE:             ./Projects2
COMPILER:          GNU g++ compiler on Linux
NOTES:             // This program stores the address of a cariable in a pointer.

MODIFICATION HISTORY:
Author             Date               Version
---------------    ----------         --------------
Michael Des Roches 2018-02-06         2.0
----------------------------------------------------------------------------- */

#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

const char PROGRAMMER_NAME[] = "Michael Des Roches";	// Global constant

/* -----------------------------------------------------------------------------
FUNCTION:          main()
DESCRIPTION:       Outputs hex and dec address for int's and for the char
		   "My_Name," which in this case is my own name.
RETURNS:           0
NOTES:             only displays the information of my actual name and 
		   declared variables
------------------------------------------------------------------------------- */

int main()
{
	char My_Name[] = "Michael DesRoches";
	int x = 25;     	// int variable
	int *ptr = nullptr;	// Pointer variable, can point to an int

	ptr = &x; 		// Store the address of x in ptr

	cout << "The hex address of x is:  " << ptr  << endl;
	cout << "The dec address of x is:  " << (long long) ptr  << endl;
	cout << "The size of ptr is " << sizeof(ptr) << " bytes\n";

	cout << endl;

	cout << "The size of x is " << sizeof(x) << " bytes\n";
	cout << "The value in x is " << x << endl;

	cout << endl;
	
	cout << "My name is " << My_Name << endl;
	cout << "The size of my name is " << sizeof(&My_Name) << " bytes\n";
	cout << "The length of my name is " << strlen(My_Name) << " letters\n";
	
	for (int i=0; i < sizeof(My_Name); i++)	//counter is i and loops as many
						//times as the total num of char
						// in My_Name
	{
		cout << "Char " << i << " is " << My_Name[i]
		     << " at address " << (long long)&My_Name[i]
		     << " with a value of: " << (int)My_Name[i] << "\n";
	}	
		cout << endl;
	
	for (int i=0; i < sizeof(My_Name); i++) //sizeof instead of strlen to
						//show null character too
	{
		cout << "Char " << i << " is " << *(My_Name + i)
		     << " at address " << (long long)&*(My_Name + i)
		     << " with a value of: " << (int)*(My_Name + i)
		     << "\n";
	}
		cout << endl;
		    
	cout << endl;
	cout << "Programmed by: " << PROGRAMMER_NAME << " -- ";//outputs my name
	cout << __DATE__ << "  " __TIME__ << endl;	       //with date and
	cout << endl;					       //time mod'd	

	return 0;
}
