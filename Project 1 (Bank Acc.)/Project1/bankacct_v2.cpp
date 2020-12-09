/* -----------------------------------------------------------------------------
FILE NAME:         bankacct_v1.cpp
DESCRIPTION:       Template for building stand-alone programs
USAGE:             ./bankacct_v1
COMPILER:          GNU g++ compiler on Linux
NOTES:             

MODIFICATION HISTORY:
Author             Date               Version
---------------    ----------         --------------
Michael Des Roches 2018-02-15         1.0
Michael Des Roches 2018-02-20	      1.1 // changed structure to mimic Lab3
----------------------------------------------------------------------------- */

#include "bankacct_v2.h" // Includes header file

/* -----------------------------------------------------------------------------
FUNCTION:          main()
DESCRIPTION:       Say something meaningful
RETURNS:           0
NOTES:             
------------------------------------------------------------------------------- */
int main(int argc, char * argv[])
{ 
	AcctInfo *info;
	bool flag = true;

	cout << "The size of type 'info' is : "
	     << sizeof(info) << endl << endl;	// to remind me to change

	while(flag)
	{
		int select = MainMenu();
		Choice(info, select, flag);
	}

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
int MainMenu()
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
	cout << "\n 0. Quit ";
	cout << "\n==================================";
	cout << "\n      Enter Selection : ";
	cin >> choice;

	return choice;
}

/* -----------------------------------------------------------------------------
FUNCTION:          NewAccount()
DESCRIPTION:       Creates a new account
RETURNS:           0
NOTES:             retrieves all info required to creat a new account using
		   the structure 
------------------------------------------------------------------------------- */
void NewAccount(AcctInfo *s) 
{
	cout << "The size of pointer 's' is : " << sizeof(s)
	     << endl << endl;

	bool flag = false;
	char password[6+1]; 

	cout << "First Name: ";
	cin >> (*s).fname;
	cout << "\nLast Name: ";
	cin >> (*s).lname; 
	cout << "\nMiddle Initial: ";
	cin >> (*s).middle;
	cout << "\nSocial Security Number: ";
	cin >> (*s).social;
	cout << "\nPhone Number: ";
	cin >> (*s).phone;
		
	while(flag == false)
	{
		cout << "\nEnter a password for the account: ";
		cin >> (*s).acctp;
		cout << "\nPleas re-enter password: ";	
		cin >> password;
	
	if(strcmp((*s).acctp, password)== 0)
		flag = true;
	else
		cout << "\nPassword did not match\n";
	}
}
/* -----------------------------------------------------------------------------
FUNCTION:          main()
DESCRIPTION:       Say something meaningful
RETURNS:           0
NOTES:             
------------------------------------------------------------------------------- */
void Choice(AcctInfo *s, int choice, bool &flag)
{
		switch(choice)
		{
		case 0:
			flag = false;
			break;
		case 1:
			NewAccount(s);
			break;
		case 2:
//			Deposit();
			break;
		case 3:
//			Withdrawl();
			break;
		case 4:
			Display(s);
			break;
		case 5:
//			Transfer();
			break;
		case 6:
//			Close();
			break;
		case 7:
			//call function
			break;
		case 8:
			//call function
			break;
		default:
			cout << "Invalid choice, try again: ";
		}			//need a way to break out
}

/* -----------------------------------------------------------------------------
FUNCTION:          main()
DESCRIPTION:       Say something meaningful
RETURNS:           0
NOTES:             
------------------------------------------------------------------------------- */
/* -----------------------------------------------------------------------------
FUNCTION:          main()
DESCRIPTION:       Say something meaningful
RETURNS:           0
NOTES:             
------------------------------------------------------------------------------- */
void Display(AcctInfo *s)
{
	cout << endl;	// output statements
	cout << "First name: " << s->fname << endl;
	cout << "Last name: " << s->lname << endl;
	cout << "Middle initial: " << s->middle << endl;
	cout << "SSN: " << s->social << endl;
	cout << "Phone: " << s->phone << endl;
}

/* -----------------------------------------------------------------------------
FUNCTION:          main()
DESCRIPTION:       Say something meaningful
RETURNS:           0
NOTES:             
------------------------------------------------------------------------------- */

/* -----------------------------------------------------------------------------
FUNCTION:          main()
DESCRIPTION:       Say something meaningful
RETURNS:           0
NOTES:             
------------------------------------------------------------------------------- */

/* -----------------------------------------------------------------------------
FUNCTION:          main()
DESCRIPTION:       Say something meaningful
RETURNS:           0
NOTES:             
------------------------------------------------------------------------------- */

/* -----------------------------------------------------------------------------
FUNCTION:          main()
DESCRIPTION:       Say something meaningful
RETURNS:           0
NOTES:             
------------------------------------------------------------------------------- */
