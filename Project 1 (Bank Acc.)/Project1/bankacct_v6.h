/* -----------------------------------------------------------------------------
FILE NAME:         bankacct_v3.h
DESCRIPTION:       Header file for bankacct
USAGE:             ./bankacct_v3
COMPILER:          GNU g++ compiler on Linux
NOTES:             

MODIFICATION HISTORY:
Author             Date               Version
---------------    ----------         --------------
Michael Des Roches 2018-02-15         1.0
Michael Des Roches 2018-02-20	      2.0
Michael Des Roches 2018-02-24	      3.0
----------------------------------------------------------------------------- */

#ifndef __BANKACCT_H__
#define __BANKACCT_H__

#include <iostream>
#include <cstring>	// Brings C-string handling
#include <fstream> 

using namespace std;

const char PROGRAMMER_NAME[] = "Michael Des Roches";	// Global constant

#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
#define MAX(x,y) ((x) > (y) : (y))

struct AcctInfo
{
	char fname[20+1];
	char lname[20+1];
	char middle;
	char social[20+1];
	char phone[20+1];
	char acctn[5+1];
	char acctp[6+1];
	char acctb[20+1];
};

// Function Prototypes go here
void help_menu();
void command_scan(AcctInfo &line, AcctInfo *s, char *cls, char &opt, int num_accts, int i, bool mode, int temp);
bool validate(AcctInfo *s, int &temp, bool mode, int num_accts, char *cls);
char* check_arg(char arg[], AcctInfo info[], AcctInfo &line, int &num_accts, char &opt);
void output_file(AcctInfo *s, int &);
void read_file(char * file, AcctInfo s[], int &);
void NewAccount(istream &in, AcctInfo *, bool, int &);
void Display(ostream &out, AcctInfo s[], int &, bool, int i);
void Choice(AcctInfo *s, int choice, bool &flag, int &num_accts, int temp, bool mode, char *, ostream &out);
int MainMenu(int num_accts);

#endif /* __BANKACCT_H__ */
