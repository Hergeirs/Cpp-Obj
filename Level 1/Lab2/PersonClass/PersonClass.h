// PersonClass.h
// Headarafíla
// Hergeir
// 
//------------------------------------------------------------------------------
#ifndef PERSONCLASS
#define PERSONCLASS

#include "../NameClass/NameClass.h"
#include "../AddressClass/AddressClass.h"

#include <vector> // Just for Persons class.


//------------------------------------------------------------------------------
// Person class containing Name and Address objects along with more info and 
// memberfunctions
//------------------------------------------------------------------------------

class Person
{
	private:
	Name name;					// object of Name class called name
	Address address;			// object of Address class called address
	string persNr;
	int skoNr;

	public:
	Person();					// Default constructor

	Person(string firstName,string lastName,string streetAddress,int zipCode,string city, string pPersNr,int pSkoNr);								// Explicit constructor (vast amount of parameters)

	void print(int width=15);	// Printing all info on Persons in vector. 

	void setPersNr(string pPersNr);								// Setting private variables through public memberfunctions.
	
	void setSkoNr (int pSkoNr);

	const string getPersNr();	// Getting private attributes into the public... never used... maybe should remove...

	const int getSkoNr();

};

//------------------------------------------------------------------------------
// Class to manage persons. Just for practice. But usefull. Especially printing.
//------------------------------------------------------------------------------

class Persons
{
	private:
	vector <Person> persons; 	// contains persons.

	public:
	Persons();					// Default construcor
	void print(int width=15); 	// Function to print info about Persons in vector.
	void push_back(Person person); // Just directing to push_back() memeber function from vector class.
};


#endif
