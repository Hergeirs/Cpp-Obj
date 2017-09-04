#include "UserInterfaceClass.h"
//------------------------------------------------------------------------------
// Required run function.
//------------------------------------------------------------------------------

void UserInterface::run()
{
menu();
}

//------------------------------------------------------------------------------
// Just printing functions. For menu. Didn't need these to be memberfunctions.
//------------------------------------------------------------------------------


void printSortMenu()
{
	cls();
	cout << "***********Sorting************" << endl;
	cout << "Enter integer for action" << endl;
	cout << "1: Sort entries by Name." << endl;
	cout << "2: Sort entries by PersNr." << endl;
	cout << "3: Sort by SkoNr." << endl;
	cout << "0: Back to Menu" << endl;
	cout << "******************************" << endl;
	cout << endl;
	return;
}

void printMenu()
{
	cls();
	cout << "***********Welcome!***********" << endl;
	cout << "Enter integer for action" << endl;
	cout << "1: Add people to register." << endl;
	cout << "2: Print list of people in register." << endl;
	cout << "3: Sort register." << endl;
	cout << "4: Save to file." << endl;
	cout << "5: Load from file." << endl;
	cout << "0: Quit" << endl; 
	cout << "******************************" << endl; 
	cout << endl;
}

void printSaveMenu()
{
	cls();
	cout << "**********Save menu!***********" << endl;
	cout << "Enter integer for action" << endl;
	cout << "1: Save people to file." << endl;
	cout << "2: Save people to file and delete" << endl;
	cout << "0: Back to Menu" << endl; 
	cout << "******************************" << endl; 
	cout << endl;
}
void printLoadMenu()
{
	cls();
	cout << "**********Load menu!***********" << endl;
	cout << "1: Add people from file" << endl;
	cout << "2: Load people from file (overwrite data)" << endl;
	cout << "0: Back to Menu" << endl; 
	cout << "******************************" << endl; 
	cout << endl;
}



//------------------------------------------------------------------------------
// Menu function. Takes user input and calls nessesary menus and functions further.
//------------------------------------------------------------------------------

void UserInterface::menu()
{

	cls();
	while (true) // entering 0 terminates program through switch.
	{
		printMenu(); // Display options.
		switch(getInt())
		{
		case 0:
			return; // terminate.
		case 1:
			addPerson();
			break;
		case 2:
			print();
			systemPause();
			break;
		case 3:
			sort();
			break;
		case 4:
			saveMenu();
			break;
		case 5:
			loadMenu();
			break;
		default:
			cout << "not a valid choice!" << endl;
		}
	}

}	

//------------------------------------------------------------------------------
// AddPerson function. Calls addPerson memberfunction from private PersonList object.
//------------------------------------------------------------------------------

void UserInterface::addPerson()
{
	string firstName,lastName,streetAddress,city,persNr;
	int zipCode, shoeSize;
		cls(); // Clear screen
		cout << "*******ADD PERSON*******" << endl;
	getLine(persNr,"Enter PersNr: ");				// Using custom getLine for controlling input not to be empty
	getLine(firstName,"Enter firstname: ");
	getLine(lastName,"Enter lastname: ");
	getLine(streetAddress,"Enter streetAddress: ");
	getInt(zipCode,"Enter zipCode: ");				// Using getInt to ensure input is number.
	getLine(city,"Enter CityName: ");
	getInt(shoeSize,"Enter shoeSize: ");
	Person person(nameFormat(firstName),nameFormat(lastName),nameFormat(streetAddress),zipCode,nameFormat(city),persNr,shoeSize); //nameFormat in city just because...
	
	persons.addPerson(person); // Calling memberfunction from PersonList class.
	
	// Giving feedback to user.
	printPrompt("Person Added:",false);
	person.print(); // Printing Person info
	systemPause();
}

//------------------------------------------------------------------------------
// calling print memberfunction in PersonList class.  
//------------------------------------------------------------------------------

void UserInterface::print()
{
	cls();		// ClearScreen and Print.
	persons.print();
}

//------------------------------------------------------------------------------
// Menu for saving to file. 
//------------------------------------------------------------------------------

void UserInterface::saveMenu()
{
	printSaveMenu();
	while (true)
	{
		switch(getInt())
		{
		case 1:
			save(false);
			return;
		case 2:
			printSure();
			switch (getInt())
			{
			case 1:
				save(true);
			case 0:
				return;
			default:
				cout << "not a valid choice!" << endl;	
			}
		case 0:
			return;
		default:
			cout << "not a valid choice!" << endl;
		}
	}
}


//------------------------------------------------------------------------------
// Menu for loading from file.
//------------------------------------------------------------------------------

void UserInterface::loadMenu()
{
	printLoadMenu();
	while (true)
	{
		switch(getInt())
		{
		case 1:
			load(false);
			return;
		case 2:
			printSure();
			switch (getInt())
			{
			case 1:
				load(true);
			case 0:
				return;
			default:
				cout << "not a valid choice!" << endl;	
			}
		case 0:
			return;
		default:
			cout << "not a valid choice!" << endl;
		}
	}
}

//------------------------------------------------------------------------------
// actual save function. Takes a bool to determine wether to delete data afterwards.
//------------------------------------------------------------------------------

void UserInterface::save(bool remove)
{
	string fileName;
	getLine(fileName,"FileName to save to: ");

	persons.setFileName(fileName);

	persons.writeToFile();	
	if (remove==true)
	{
		persons.clear();
	}
}

//------------------------------------------------------------------------------
// actual load function. Takes bool to determine wether to delete current data first.
//------------------------------------------------------------------------------


void UserInterface::load(bool remove)
{
	//Input and output.
	printPrompt("Current filename: "+persons.getFileName(),false);
	string fileName;
	getLine(fileName,"FileName to load from: ");

	persons.setFileName(fileName);
	
	if (remove==true)
	{
		persons.clear();
	}
	persons.readFromFile();
}

//------------------------------------------------------------------------------
// Sorting menu. Only calls sorting. memberfunctions of PersonList object.
//------------------------------------------------------------------------------

void UserInterface::sort()
{
	while (true) // entering 0 terminates program through switch.
	{
		printSortMenu(); // Display options.
		switch(getInt())
		{
		case 0:
			return; // back to menu.
		case 1:
			persons.sortName();
			printPrompt("Data now sorted by name.");
			break;
		case 2:
			persons.sortPersNr();
			printPrompt("Data now sorted by persNr");
			break;
		case 3:
			persons.sortSkoNr();
			printPrompt("Data now sorted by skoNr");
			break;
		default:
			cout << "not a valid choice!" << endl;
		}
	}
}

