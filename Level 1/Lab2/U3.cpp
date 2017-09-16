#include "Functions.h"

//------------------------------------------------------------------------------
// Just printing menu options. Wanted to seperate output from the machinery.
//------------------------------------------------------------------------------

void printMenu()
{
	cout << "********Welcome!********" << endl;
	cout << "Enter integer for action" << endl;
	cout << "1: Add people to register." << endl; 
	cout << "2: Print list of people in register." << endl;
	cout << "0: Quit" << endl;
	cout << endl;
	return;
}


//------------------------------------------------------------------------------
// Menu function I/O
//------------------------------------------------------------------------------


void menu()
{
Persons persons;
cls();

	while (true) // entering 0 terminates program through switch.
	{
		printMenu(); // Display options.
		switch(getInt())
		{
		case 0:
		return; // terminate.
		
		case 1:
		addToReg(persons);
		break;
		case 2:
		persons.print();
		systemPause();
		break;

		default:
		cout << "not a valid choice!" << endl; 		
		}
	cls();
	}
}

//------------------------------------------------------------------------------
// Main function. Contains menu and function calls. No input/output as demands are.
//------------------------------------------------------------------------------

int main ()
{
menu();
}

