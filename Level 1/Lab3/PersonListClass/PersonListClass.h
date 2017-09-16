// PersonListClass.h
// Headarafíla
// Hergeir
// 
//------------------------------------------------------------------------------
#ifndef PERSONLISTCLASS
#define PERSONLISTCLASS

#include "../PersonClass/PersonClass.h"

#include <vector> // Just for Persons class.
#include <algorithm> // For sorting.

//------------------------------------------------------------------------------
// Class to manage persons.
//------------------------------------------------------------------------------
class PersonList
{
private:

	vector <Person> list; 			// contains persons.
	string fileName;
	
public:
	
	PersonList();					// Default construcor
	
	void print(int width=15) const; // Function to print info about Persons in vector.
	
	void addPerson(Person &person);	// Just directing to push_back() memeber function from vector class.
	void setFileName(string &pFileName);
	
	const string getFileName() const;
	Person & getPerson(int n);
	
	int size() const;				// Used for knowledge of size in ofstream non memberfunction.
	void clear(); 					// Empty vector
	
	void readFromFile();
	void writeToFile();
	
	void sortName();
	void sortPersNr();
	void sortSkoNr();
};

const ostream & operator << (ostream & stream, PersonList & list);
const istream & operator >> (istream & stream, PersonList & list);

#endif
