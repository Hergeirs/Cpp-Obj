// UserInterface.h
// Headarafíla
// Hergeir
// 
//------------------------------------------------------------------------------
#ifndef USERINTERFACE
#define USERINTERFACE
#include "../PersonListClass/PersonListClass.h"

class UserInterface
{

	private:
	PersonList persons;

	void menu();
	void addPerson();
	void print();
	void sort();

	void saveMenu();
	void loadMenu();

	void save(bool remove);
	void load(bool remove);

	public:
	void run();
//UserInterface(); // Empty Constructor
};



#endif
