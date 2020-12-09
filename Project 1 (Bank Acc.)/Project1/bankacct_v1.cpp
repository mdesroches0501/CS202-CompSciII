/* -----------------------------------------------------------------------------
FILE NAME:         bankacct_v1.cpp
DESCRIPTION:       Template for building stand-alone programs
USAGE:             ./bankacct_v1
COMPILER:          GNU g++ compiler on Linux
NOTES:             

MODIFICATION HISTORY:
Author             Date               Version
---------------    ----------         --------------
Michael Des Roches 2018-01-01         1.0
----------------------------------------------------------------------------- */

const char PROGRAMMER_NAME[] = "Michael Des Roches";	// Global constant

#include <cstring>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib> 

using namespace std;

#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
#define MAX(x,y) ((x) > (y) : (y))

void MainMenu();
void NewAccount();
void SaveFile();
void LoadFile();
void Deposit();
void Withdrawl();
void Display();
//void Transfer();
void Close();
void ExistingAcct();

struct AcctInfo
{
	char fname[20+1];
	char lname[20+1];
	char middle;
	char social[20+1];
	char phone[20+1];
	char acctn[5+1];
	char acctp[6+1];
	double acctb[20+1];
};

struct Data
{
	// Random data like filenames will go here
};
	 
/* -----------------------------------------------------------------------------
FUNCTION:          main()
DESCRIPTION:       Say something meaningful
RETURNS:           0
NOTES:             
------------------------------------------------------------------------------- */
int main()
{
	LoadFile();
	MainMenu();
	SaveFile();
	
	cout << endl;
	cout << "Programmed by: " << PROGRAMMER_NAME << " -- ";
	cout << __DATE__ << "  " __TIME__ << endl;
	cout << endl;


	return 0;




}
/* -----------------------------------------------------------------------------
FUNCTION:          main()
DESCRIPTION:       Say something meaningful
RETURNS:           0
NOTES:             
------------------------------------------------------------------------------- */
void MainMenu()
{
	int choice;

	cout << "\n              MENU             ";
	cout << "\n==================================";
	cout << "\n 1. Create New Account ";
	cout << "\n 2. Deposit  ";
	cout << "\n 3. Withdrawl ";
	cout << "\n 4. Display Info";
	cout << "\n 5. Transfer";
	cout << "\n 6. Close Account";
	cout << "\n 7. Write a report file ";
	cout << "\n 8. ";
	cout << "\n==================================";
	cout << "\n      Enter Selection : ";
	cin >> choice;

		switch(choice)
		{
		case 0:
			//call hidden function
		case 1:
			NewAccount();
			break;
		case 2:
			Deposit();
			break;
		case 3:
			Withdrawl();
			break;
		case 4:
			Display();
			break;
		case 5:
//			Transfer();
			break;
		case 6:
			Close();
			break;
		case 7:
			//call function
			break;
		case 8:
			//call function
			break;
		default:
			cout << "Invalid choice, try again: ";
	}						//need a way to break out
}							// of menu, while loop


/* -----------------------------------------------------------------------------
FUNCTION:          NewAccount()
DESCRIPTION:       Creates a new account
RETURNS:           0
NOTES:             retrieves all info required to creat a new account using
		   the structure 
------------------------------------------------------------------------------- */
void NewAccount() 
{
	AcctInfo info;

	bool flag = false;
	char password[6+1]; 
	cout << "First Name: ";
	cin >> info.fname;
	cout << "\nLast Name: ";
	cin >> info.lname; 
	cout << "\nMiddle Initial: ";
	cin >> info.middle;
	cout << "\nSocial Security Number: ";
	cin >> info.social;
	cout << "\nPhone Number: ";
	cin >> info.phone;
		
		while(flag == false)
		{
			cout << "\nEnter a password for the account: ";
			cin >> info.acctp;
			cout << "\nPleas re-enter password: ";	
			cin >> password;
				if(strcmp(info.acctp, password)== 0)
					flag = true;
				else
					cout << "\nPassword did not match\n";
		}
	// call save file function through main
}
/* -----------------------------------------------------------------------------
FUNCTION:          main()
DESCRIPTION:       Say something meaningful
RETURNS:           0
NOTES:             
------------------------------------------------------------------------------- */
void Deposit()
{
//deposit function here
}
/* -----------------------------------------------------------------------------
FUNCTION:          main()
DESCRIPTION:       Say something meaningful
RETURNS:           0
NOTES:             
------------------------------------------------------------------------------- */
void Withdrawl()
{
// Withdrawl function here
}
/* -----------------------------------------------------------------------------
FUNCTION:          main()
DESCRIPTION:       Say something meaningful
RETURNS:           0
NOTES:             
------------------------------------------------------------------------------- */
void Display()
{
// Display info function here
}
/* -----------------------------------------------------------------------------
FUNCTION:          main()
DESCRIPTION:       Say something meaningful
RETURNS:           0
NOTES:             
------------------------------------------------------------------------------- */
void Close()
{
// Closing account function here
}
/* -----------------------------------------------------------------------------
FUNCTION:          main()
DESCRIPTION:       Say something meaningful
RETURNS:           0
NOTES:             
------------------------------------------------------------------------------- */
void ExistingAcct()
{
// a function that is called to verify existing account and the open it to write
// information, depending on where it was called from.
}
/* -----------------------------------------------------------------------------
FUNCTION:          main()
DESCRIPTION:       Say something meaningful
RETURNS:           0
NOTES:             
------------------------------------------------------------------------------- */
void LoadFile()
{
//
}
/* -----------------------------------------------------------------------------
FUNCTION:          main()
DESCRIPTION:       Say something meaningful
RETURNS:           0
NOTES:             
------------------------------------------------------------------------------- */
void SaveFile()
{
// A function that will be called to save bankers information to database
// will be called for just about every function
}
