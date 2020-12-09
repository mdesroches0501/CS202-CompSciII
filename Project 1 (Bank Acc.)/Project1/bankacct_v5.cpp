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
Michael Des Roches 2018-03-04		  5.0 // command line implimitation
----------------------------------------------------------------------------- */

#include "bankacct_v5.h" // Includes header file

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
	AcctInfo line;
	char file[20+1]; //= new command_line;
	int temp = 99;
	char *cls;
	char opt;

 	if (argc > 1)
	{
		cout << "argc = " << argc << endl;
		for(int i = 1; i < argc; i++)
		{    
			cls = check_arg(argv[i], info, line, num_accts, opt);
			command_scan(line, info, cls, opt, num_accts, i, 0, temp);
		}
	}	
	else
	{
		cout << "\nPlease enter a file name:";
		cin >> file;
		read_file(file, info, num_accts);

	while(flag)
		{
		int select = MainMenu();
		Choice(info, select, flag, num_accts, temp, 1, cls, cout);//i needs to be declared
	 	}
	}
	delete[] info; 

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
	cout << "\n|               MENU               |";
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
RETURNS:           N/A
NOTES:             retrieves all info required to create a new account using
		   		   the structure 
------------------------------------------------------------------------------- */
void NewAccount(istream &in, AcctInfo s[], bool mode, int &num_accts) 
{		
	do 		// while not eof add loop
	{
	if (mode)cout << "\nFirst Name: ";
	in >> s[num_accts].fname;
	if (mode)cout << "Last Name: ";
	in >> s[num_accts].lname; 
	if (mode)cout << "Middle Initial: ";
	in >> s[num_accts].middle;				  //? doesn't like ptr
	if (mode)cout << "Social Security Number: ";
	in >> s[num_accts].social;
	if (mode)cout << "Phone Number: ";
	in >> s[num_accts].phone;
	if (mode)cout << "Account Balance: ";
	in >> s[num_accts].acctb;
	if (mode)cout << "Account Number: ";
	in >> s[num_accts].acctn;		
	if (mode)cout << "Enter a password for the account: ";
	in >> s[num_accts].acctp;
	
	++num_accts;
	}
	while(! in.eof() && !mode);
}
/* -----------------------------------------------------------------------------
FUNCTION:          Choice
DESCRIPTION:       Takes return value
RETURNS:           N/A
NOTES:             Recieves "choic" value from main menu and sends to 
		           appropriate function
------------------------------------------------------------------------------- */
void Choice(AcctInfo *s, int choice, bool &flag, int &num_accts, int temp, bool mode, char* cls, ostream &out)// *cls
{
		switch(choice)
		{
		case 0:
			flag = false;
			break;
		case 1:
			NewAccount(cin, s, true, num_accts);
			output_file(s, num_accts);
			break;
		case 2:
//			Deposit();
			break;
		case 3:
//			Withdrawl();
			break;
		case 4:
		//	validate(s, temp, true, num_accts, cls);
			for(int i = 0; i < num_accts; ++i);
			Display(cout, s, num_accts, true, temp);	//just show one for final syntax
			//output_file(s, num_accts);
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
void Display(ostream &out, AcctInfo s[], int &num_accts, bool mode, int i)
{
	//for(int i = 0; i < num_accts; ++i)
	//{
		if(mode)cout << "\nThe size of num_accts is, " << num_accts << endl; //test

		//cout << endl;					// output statements

		if(mode)cout << "First name: "; 
		out << s[i].fname << endl;
		if(mode)cout << "Last name: "; 
		out << s[i].lname << endl;
		if(mode)cout << "Middle initial: ";
		out << s[i].middle << endl;
		if(mode)cout << "SSN: "; 
		out << s[i].social << endl;
		if(mode)cout << "Phone: ";
		out << s[i].phone << endl;
		if(mode)cout << "Account balance: ";
		out << s[i].acctb << endl;
		if(mode)cout << "Account Number: ";
		out << s[i].acctn << endl;
		if(mode)cout << "Password: ";
		out << s[i].acctp << endl;
		out << endl;
//	}
}

/* -----------------------------------------------------------------------------
FUNCTION:          output_file()
DESCRIPTION:       creates an output file from data input
RETURNS:           N/A
NOTES:             recieves data input from Display() function
------------------------------------------------------------------------------- */
void output_file(AcctInfo *s, int &num_accts)
{	
	ofstream outfile;
	outfile.open("output.txt");

	cout << "Now writing data to the file.\n";
	
	for (int i =0; i < num_accts; i++)
	Display(outfile, s, num_accts, 0, i);	

	outfile.close();
	cout << "Information sent to output.txt\n";
}
/* -----------------------------------------------------------------------------
FUNCTION:          void check_arg
DESCRIPTION:       Lists command-line inputs
RETURNS:           char cls
NOTES:             called if argument is 0 in main function
------------------------------------------------------------------------------- */
char* check_arg(char arg[], AcctInfo info[], AcctInfo &line, int &num_accts, char &opt)
{
	char buf[100];
	const char SLASH = '/';
	char valid_options[] = "?ACDFILMNOPRSTW";
	char * p = valid_options;
	char * cls;
	
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
			cout << "Option: " << *p;
			opt = *p;
		}


	if (arg[2] != 0)
	{
		strcpy(buf, arg+2);
		cls = (arg+2);	
	}
	cout << endl;
return cls;
}
/* -----------------------------------------------------------------------------
FUNCTION:          validate()
DESCRIPTION:       used to confirm password and acct number
RETURNS:           match
NOTES:             strcmp not working correctley
------------------------------------------------------------------------------- */
bool validate(AcctInfo *s, int &temp, bool mode, int num_accts, char *cls)
{
	bool match = false;

	if(mode) 
	{
		cout << "\nPlease enter an account number:";
		cin >> s[temp].acctn;
		cout << "\nPassword:";
		cin >> s[temp].acctp;
	}
	else
	{
		strcpy(s[temp].acctn, cls);
		strcpy(s[temp].acctb, cls);
	}
		for (int i = 0; i < num_accts; i++)
		{
			if(!strcmp(s[temp].acctn, cls) && !strcmp(s[temp].acctp, cls))
			{
			match = true;
			temp = i;
			}
			else
			cout << "\nIncorrect account number or password";

		}
	return match;
}
/* -----------------------------------------------------------------------------
FUNCTION:          command_scan()
DESCRIPTION:       called from command line and uses break statements as 
				   neccesary
RETURNS:           0
NOTES:             Does not work validation options
				   /O /? works
------------------------------------------------------------------------------- */
void command_scan(AcctInfo &line, AcctInfo* s, char *cls, char &opt, int num_accts, int i, bool mode, int temp)
{
	if(opt != 'O' && opt != 'R')
	{
		switch (opt)
		{
		case '?':			// own function
		help_menu();
			break;
		case 'L':
		strcpy(line.lname, cls);
			break;
		case 'F':
		strcpy(line.fname, cls);
			break;
		case 'M':
		line.middle = *(cls);
			break;
		case 'S':
		strcpy(line.social, cls);// ssn
			break;
		case 'N':
		strcpy(line.phone, cls);
			break;
		case 'A':
		strcpy(line.acctn, cls);
			break;
		case 'P':
		strcpy(line.acctp, cls);
		}
		if(opt == 'C' && opt == 'D' && opt == 'W' && opt == 'T' && opt == 'I')
		{
			validate(s, temp, 0, num_accts, cls);
			//{
				switch(opt)
				{
					case 'C':
					// New password
					break;
					case 'D':
					// Deposit
					break;
					case 'W':
					//Withdrawl
					break;
					case 'T':
					// transfer
					break;
					case 'I':
					cout << "\nYou're in I!!\n";
					for(int i = 0; i < num_accts; ++i)
					Display(cout, s, num_accts, 0, i);
					break;
				}
			//}
		}
	}
	else //if(opt == 'O' && opt == 'R')
	{
		switch (opt)
		{
			case 'O':
			cout << cls << endl;
			read_file(cls, s, num_accts);
				for(int i = 0; i < num_accts; ++i)
					Display(cout, s, num_accts, 1, i);
					output_file(s, num_accts);
					break;
			case 'R':
			// report file
				break;

		}
	}
}

/* -----------------------------------------------------------------------------
FUNCTION:          help_menu()
DESCRIPTION:       Displays a help menu through the command line
RETURNS:           Nothing
NOTES:             A simple display that show the possible command lines
------------------------------------------------------------------------------- */
void help_menu()
{
	cout << "\n ______________________________________________________";
	cout << "\n|                         Help Menu                    |";
	cout << "\n|------------------------------------------------------|";
	cout << "\n| /L Last Name      | /N Phone Number  | /W Withdraw   |";
	cout << "\n|------------------------------------------------------|";
	cout << "\n| /F First Name     | /P Password      | /T Transfer   |";
	cout << "\n|------------------------------------------------------|";
	cout << "\n| /M Middle Initial | /C New Password  | /R Report File|";
	cout << "\n|------------------------------------------------------|";
	cout << "\n| /S Social Sec Num | /D Deposit       | /I Display    |";
	cout << "\n|------------------------------------------------------|";
	cout << "\n|______________________________________________________|";
	cout << "\n|  These are the possible commands, usage is SLASH(/)  |";
	cout << "\n|  and then the corresponding letter shown above       |";
	cout << "\n|______________________________________________________|";

}
