/* -----------------------------------------------------------------------------
FILE NAME:         bankacct_v3.cpp
DESCRIPTION:       Template for building stand-alone programs
USAGE:             ./bankacct_v3
COMPILER:          GNU g++ compiler on Linux
NOTES:             

MODIFICATION HISTORY:
Author             Date               Version
---------------    ----------         --------------
Michael Des Roches 2018-02-15         1.0
Michael Des Roches 2018-02-20	      2.0 // changed structure
Michael Des roches 2018-01-24         3.0 // adds file operations
----------------------------------------------------------------------------- */

#include "bankacct_v3.h" // Includes header file

/* -----------------------------------------------------------------------------
FUNCTION:          main()
DESCRIPTION:       Program's main entry point
RETURNS:           0
NOTES:             
------------------------------------------------------------------------------- */
int main(int argc, char * argv[])
{ 
	AcctInfo * info = new AcctInfo;
	bool flag = true;

	cout << "argc = " << argc << endl;

	if (argc > 1)
	{
		read_file(argv[1], info);
		Display(cout, info);
		output_file(info);
	}	
	else
	{
	while(flag)
		{
		int select = MainMenu();
		Choice(info, select, flag);
	 	}
	}

	delete info;

	cout << endl;
	cout << "Programmed by: " << PROGRAMMER_NAME << " -- ";
	cout << __DATE__ << "  " __TIME__ << endl;
	cout << endl;


	return 0;
}
/* -----------------------------------------------------------------------------
FUNCTION:          MainMenu()
DESCRIPTION:       Displays directory
RETURNS:           int choice
NOTES:             displays options, returns option
------------------------------------------------------------------------------- */
int MainMenu()
{
	int choice;

	cout << "\n __________________________________";
	cout << "\n|               MENU               | ";
	cout << "\n|==================================|";
	cout << "\n| 1. Create New Account            |";
	cout << "\n| 2. Deposit                       |";        
	cout << "\n| 3. Withdrawl                     |";
	cout << "\n| 4. Display Info                  |";
	cout << "\n| 5. Transfer                      |";
	cout << "\n| 6. Close Account                 |";
	cout << "\n| 7. Write a report file           |";
	cout << "\n| 0. Quit                          |";
	cout << "\n|__________________________________|";
	cout << "\n Enter Selection : ";
	cin >> choice;

	return choice;
}

/* -----------------------------------------------------------------------------
FUNCTION:          NewAccount()
DESCRIPTION:       Creates a new account
RETURNS:           0
NOTES:             retrieves all info required to create a new account using
		   the structure 
------------------------------------------------------------------------------- */
void NewAccount(istream &in, AcctInfo *s, bool mode) 
{
	bool flag = false;
	char password[6+1]; 
	
	if (mode)cout << "First Name: ";
	in >> s->fname;
	if (mode)cout << "\nLast Name: ";
	in >> s->lname; 
	if (mode)cout << "\nMiddle Initial: ";
	in >> s->middle;
	if (mode)cout << "\nSocial Security Number: ";
	in >> s->social;
	if (mode)cout << "\nPhone Number: ";
	in >> s->phone;
		
	while(flag == false)
	{
		if (mode)cout << "\nEnter a password for the account: ";
		in >> s->acctp;
		if (mode)cout << "\nPleas re-enter password: ";	
		in >> password;					
							
	if(strcmp(s->acctp, password)== 0)
		flag = true;
	else
		if (mode)cout << "\nPassword did not match\n";
	}
}
/* -----------------------------------------------------------------------------
FUNCTION:          Choice
DESCRIPTION:       Takes return value
RETURNS:           N/A
NOTES:             Recieves "choic" value from main menu and sends to 
		   appropriate function
------------------------------------------------------------------------------- */
void Choice(AcctInfo *s, int choice, bool &flag)
{
		switch(choice)
		{
		case 0:
			flag = false;
			break;
		case 1:
			NewAccount(cin, s, true);
			break;
		case 2:
//			Deposit();
			break;
		case 3:
//			Withdrawl();
			break;
		case 4:
			Display(cout, s);
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
FUNCTION:          read_file()
DESCRIPTION:       Recieves input files
RETURNS:           N/A
NOTES:             Function is called if input file is executed 
------------------------------------------------------------------------------- */
void read_file(char * file, AcctInfo *info)
{
	ifstream infile(file);

	if (!infile) 	// tests for errors
		cout << "\nError opening file: " << file << "\n\n";

	else
	{
		cout << "Input File: " << file << endl;
//		for(i = 0, i < 4, i++)
//		{
		NewAccount(infile, info, 0);
//		}
		infile.close();
	}
}
/* -----------------------------------------------------------------------------
FUNCTION:          Display()
DESCRIPTION:       Displays customer information
RETURNS:           N/A
NOTES:             Also outputs data input into a file when called from 
	           output function
------------------------------------------------------------------------------- */
void Display(ostream &out, AcctInfo *s)
{
	out << endl;	// output statements
	out << "First name: " << s->fname << endl;
	out << "Last name: " << s->lname << endl;
	out << "Middle initial: " << s->middle << endl;
	out << "SSN: " << s->social << endl;
	out << "Phone: " << s->phone << endl;
}

/* -----------------------------------------------------------------------------
FUNCTION:          output_file()
DESCRIPTION:       creates an output file from data input
RETURNS:           N/A
NOTES:             recieves data input from Display() function
------------------------------------------------------------------------------- */
void output_file(AcctInfo *s)
{
	ofstream outfile;
	outfile.open("output.txt");

	cout << "Now writing data to the file.\n";
	
	Display(outfile, s);

	outfile.close();
	cout << "Finished.\n";
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
