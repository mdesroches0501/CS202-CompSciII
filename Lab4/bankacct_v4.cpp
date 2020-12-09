/* -----------------------------------------------------------------------------
FILE NAME:         bankacct_v4.cpp
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
Michael Des Roches 2018-01-24		  4.0 // added multiple accts
----------------------------------------------------------------------------- */

#include "bankacct_v4.h" // Includes header file

/* -----------------------------------------------------------------------------
FUNCTION:          main()
DESCRIPTION:       Program's main entry point
RETURNS:           0
NOTES:             
------------------------------------------------------------------------------- */
int main(int argc, char * argv[])
{ 	
	int num_accts = 0; 				// Set equal to get info function
	AcctInfo * info = new AcctInfo[100];
	bool flag = true;
	char fname[] = "TestDB.txt";

	
/*
	if (argc > 1)
	{
	cout << "argc = " << argc << endl;
*/
	read_file(fname, info, num_accts); // argc
	Display(cout, info, num_accts);
	output_file(info, num_accts);
/*
	}	
	else
	{
	while(flag)
		{
		int select = MainMenu();
		Choice(info, select, flag, num_accts);
	 	}
	}
*/
	delete[] info; 		// change

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
void NewAccount(istream &in, AcctInfo s[], bool mode, int &num_accts) 
{
	bool flag = false;
	
	while(! in.eof())		// while not eof add loop
	{
	if (mode)cout << "First Name: ";
	in >> s[num_accts].fname;
	if (mode)cout << "\nLast Name: ";
	in >> s[num_accts].lname; 
	if (mode)cout << "\nMiddle Initial: ";
	in >> s[num_accts].middle;				  //? doesn't like ptr
	if (mode)cout << "\nSocial Security Number: ";
	in >> s[num_accts].social;
	if (mode)cout << "\nPhone Number: ";
	in >> s[num_accts].phone;
	if (mode)cout << "\nAccount Balance: ";
	in >> s[num_accts].acctb;
	if (mode)cout << "\nAccount Number: ";
	in >> s[num_accts].acctn;		
	if (mode)cout << "\nEnter a password for the account: ";
	in >> s[num_accts].acctp;
	

	//cout << "Num accts = " << num_accts << "Fname = " << s[num_accts].fname << endl;
	++num_accts;
	}
}
/* -----------------------------------------------------------------------------
FUNCTION:          Choice
DESCRIPTION:       Takes return value
RETURNS:           N/A
NOTES:             Recieves "choic" value from main menu and sends to 
		   appropriate function
------------------------------------------------------------------------------- */
void Choice(AcctInfo *s, int choice, bool &flag, int &num_accts)
{
		switch(choice)
		{
		case 0:
			flag = false;
			break;
		case 1:
			NewAccount(cin, s, true, num_accts);
			break;
		case 2:
//			Deposit();
			break;
		case 3:
//			Withdrawl();
			break;
		case 4:
			Display(cout, s, num_accts);	//just show one for final syntax
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
void read_file(char * file, AcctInfo info[], int &num_accts)
{	
	ifstream infile(file);

	if (!infile) 	// tests for errors
		cout << "\nError opening file: " << file << "\n\n";

	else
	{
	cout << "Input File: " << file << endl;	// add while loop
	NewAccount(infile, info, 0, num_accts);
	num_accts--;
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
void Display(ostream &out, AcctInfo s[], int &num_accts)
{
	for(int i = 0; i < num_accts; ++i)
	{
		//cout << "\nThe size of num_accts is, " << num_accts << endl; //test

		cout << endl;										// output statements

		out << "Last name: "; 
		out << s[i].lname << endl;
		out << "First name: "; 
		out << s[i].fname << endl;
		out << "Middle initial: ";
		out << s[i].middle << endl;
		out << "SSN: "; 
		out << s[i].social << endl;
		out << "Phone: ";
		out << s[i].phone << endl;
		out << "Account balance: ";
		out << s[i].acctb << endl;
		out << "Account Number: ";
		out << s[i].acctn << endl;
		out << "Password: ";
		out << s[i].acctp << endl;
	}
}

/* -----------------------------------------------------------------------------
FUNCTION:          output_file()
DESCRIPTION:       creates an output file from data input
RETURNS:           N/A
NOTES:             recieves data input from Display() function
------------------------------------------------------------------------------- */
void output_file(AcctInfo *s, int &num_accts)
{
	//int size = 100;

	ofstream outfile;
	outfile.open("output.txt");

	cout << "Now writing data to the file.\n";
	
	//for (int i = 0; i < num_accts; ++i)
		Display(outfile, s, num_accts);	// 

	outfile.close();
	cout << "Finished.\n";
}
/* -----------------------------------------------------------------------------
FUNCTION:          void check_arg
DESCRIPTION:       Lists command-line inputs
RETURNS:           0
NOTES:             called if argument is 0 in main function
------------------------------------------------------------------------------- */
void check_arg(char arg[])
{
	char buf[100];
	const char SLASH = '/';
	char valid_options[] = "?ACDFILMNOPRSTW";
	char * p = valid_options;

	bool first_char = arg[0] == SLASH;	// Test 1st arg's character

	bool second_char = false;		// Test 1st arg's 2nd character

	for (; *p != 0; ++p)			// de-refrence pointer fix from version 3
	{
		second_char = arg[1] == *p;	// checks to see if a valid option
		if (second_char == true)
			break;
	}
	if (!first_char || !second_char)
	   cout << "Invalid argument" << endl;

	else
	{
		cout << "Option: " << *p ;

	if (arg[2] != 0)
	{
		strcpy(buf, arg+2);
		cout << "  Value: " << buf;
	}
	cout << endl;
	}

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
