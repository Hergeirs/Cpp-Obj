#include "HousingQ.hpp"

//------------------------------------------------------------------------------
// Function to Prompt user if he's sure.
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Function to to ask wether user's sure about deletion
//------------------------------------------------------------------------------

void printSure()
{
	cout << "***********Warning!************" << endl;
	cout << "Enter integer for action" << endl;
	cout << "Are you sure you want to delete." << endl;
	cout << "this person from queue?" << endl;
	cout << "1: Yes" << endl;
	cout << "0: Back to Menu" << endl;
	cout << "*******************************" << endl;
	cout << endl;
}

bool sure()
{
	while (1)
	{
		printSure();
		switch (getInt())
		{
		case 0:
			return false;
		case 1:
			return true;
		default:
			printPrompt("Not valid Choice");
		}
		cls();
	}
}

//------------------------------------------------------------------------------
// Function to load queue from file.
//------------------------------------------------------------------------------

void HousingQ::loadData()
{
	Item person;
	ifstream is(fileName);
	int amountLoaded;

	for (amountLoaded=0;is >> person && is.is_open();++amountLoaded)
	{
		queue.enque(person);
	}
	is.close();
	printPrompt("Loaded "+toString(amountLoaded)+" entries from the file "+fileName);
}

//------------------------------------------------------------------------------
// Function to save queue to file.
//------------------------------------------------------------------------------
void HousingQ::saveData()
{
	ofstream os(fileName);
	int amountSaved=0;
	for (QIterator i=queue.begin(); i!=queue.end() && os.is_open();++i,++amountSaved)
		os << *i;
	os.close();
	printPrompt("Saved "+toString(amountSaved)+" entries to file "+fileName);
}

//------------------------------------------------------------------------------
// Menu Functions
//------------------------------------------------------------------------------

void printMenu()
{
	cls();
	cout << "***********Welcome!***********" << endl;
	cout << "Enter integer for action" << endl;
	cout << "1: Add people to register." << endl;
	cout << "2: Print people in queue." << endl;
	cout << "3: Offer residence." << endl;
	cout << "4: Search for person." << endl;
	cout << "5: Delete person from file." << endl;
	cout << "6: Save queue to file." << endl;
	cout << "0: Quit" << endl;
	cout << "******************************" << endl;
	cout << endl;
}

void HousingQ::menu()
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
			break;
		case 3:
			offerResidence();
			break;
		case 4:
			search();
			break;
		case 5:
			deleteNode();
			break;
		case 6:
			saveData();
			break;
		default:
			cout << "not a valid choice!" << endl;
		}
	}
}

//------------------------------------------------------------------------------
// run function. Runs menu and assigns name to fileName
//------------------------------------------------------------------------------

void HousingQ::run()
{
	getLine(fileName,"Enter fileName: ");
	loadData();
	menu();
}

//------------------------------------------------------------------------------
// Function to add person to queue using user input (keyboard)
//------------------------------------------------------------------------------

void HousingQ::addPerson()
{
	string firstName,lastName,streetAddress,city,persNr;
	int zipCode, shoeSize;
	cls(); // Clear screen

	cout << "*******ADD PERSON*******" << endl;
	// Using custom getLine for controlling input not to be empty
	getLine(persNr,"Enter PersNr: ");
	getLine(firstName,"Enter firstname: ");
	getLine(lastName,"Enter lastname: ");
	getLine(streetAddress,"Enter streetAddress: ");
	// Using getInt to ensure input is number.
	getInt(zipCode,"Enter zipCode: ");
	getLine(city,"Enter CityName: ");
	getInt(shoeSize,"Enter shoeSize: ");
	Item person(nameFormat(firstName),nameFormat(lastName),nameFormat(streetAddress),zipCode,nameFormat(city),persNr,shoeSize); //nameFormat in city just because...
	queue.enque(person);

	printPrompt("Person Added:",false);
	person.print(); // Printing Person info
	systemPause();
}

//------------------------------------------------------------------------------
// Function to take the first element from queue/list printing and deleting it.
//------------------------------------------------------------------------------

void HousingQ::offerResidence()
{
	if(queue.isEmpty()){printPrompt("Queue is empty!");return;}

	Item person;
	queue.deque(person);

	printPrompt("This person has been offered residence",false);
	person.print();
	systemPause();
}

//------------------------------------------------------------------------------
// Printing elements in list.
//------------------------------------------------------------------------------

void HousingQ::print() const
{
	if(queue.isEmpty()){printPrompt("Queue is empty!");return;}

	int n=0;
	QIterator end = queue.end();
	for (QIterator i=queue.begin(); i!=end; ++i)
	{
		(*i).print(++n);
	}
	systemPause("There are "+toString(n)+" entries in queue.");
}

//------------------------------------------------------------------------------
// Searching for person in list using useInput. Calls QList search memberFunction.
//------------------------------------------------------------------------------

void HousingQ::search()
{
	if(queue.isEmpty()){printPrompt("Queue is empty!");return;}

	string persNr;
	getLine(persNr,"Enter PersNr to search on: ");

	Result result = queue.search(persNr);
	Item dummy;
	if (!(result.item==dummy)) // dummy is returned if element not found.
	{
		printPrompt("Person Found:",false);
		result.item.print(result.index);
		systemPause();
		return;
	}
	else
		printPrompt("Person not found in queue.");

	return;
}

//------------------------------------------------------------------------------
// Deletes node using persNr. Uses QList memberfunction search() with persNr.
// Gets Item/Person returned along with it's index in a struct of Result type.
//------------------------------------------------------------------------------

void HousingQ::deleteNode()
{
	if(queue.isEmpty()){printPrompt("Queue is empty!");return;}

	string persNr;
	getLine(persNr,"Enter PersNr to delete: ");
	Result result = queue.search(persNr); // Search for person using persNr
	Item dummy;
	if (!(result.item==dummy))
	{
		cls();
		result.item.print(result.index);
		if(sure())
		{
			if (queue.del(result.item))
				printPrompt ("Person deleted.");
			else
				printPrompt ("Person could not be deleted");
		}
		else
			printPrompt("Person not deleted.");
	}
	else{printPrompt("Person was not found for deletion.");}
}
