// PersonClass.h
// Headarafíla
// Hergeir
//
//------------------------------------------------------------------------------
#ifndef PERSONCLASS
#define PERSONCLASS

#include "../NameClass/NameClass.hpp"
#include "../AddressClass/AddressClass.hpp"


//------------------------------------------------------------------------------
// Person class containing Name and Address objects along with more info and
// memberfunctions
//------------------------------------------------------------------------------

class Person
{
private:
	Name name;						// object of Name class called name
	Address address;				// object of Address class called address
	string persNr;
	int skoNr;

public:
	Person();						// Default constructor

	Person(string firstName,string lastName,string streetAddress,int zipCode,string city, string pPersNr,int pSkoNr);

	// Explicit constructor (vast amount of parameters)

	void print(int n=0,int width=15) const;		// Printing all info on Persons in vector.

	void setPersNr(string pPersNr);	// Setting private variables through public memberfunctions.

	void setSkoNr (int pSkoNr);

	const string& getPersNr() const;	// Getting private attributes into the public... never used... maybe should remove...

	const int getSkoNr() const;

	Name& getName();

	Address& getAddress();

	const bool operator ==(Person &pPerson) const;

	const bool operator <(Person &pPerson) const;

	void operator = (Person &pPerson);

};

const ostream & operator << (ostream & stream, Person & pPerson);
const istream & operator >> (istream & stream, Person & pPerson);
#endif
