// NameClass.h
// Headarafíla
// Hergeir
//
//------------------------------------------------------------------------------
#ifndef NAMECLASS
#define NAMECLASS
#include "../Functions/Functions.hpp"

//------------------------------------------------------------------
// Class to work with objects with name attributes
//------------------------------------------------------------------

class Name
{
private:

	string firstName;
	string lastName;

public:
	Name(); 									// default Constructor

	Name(string & pFirstName, string & pLastName); // Constructor

	void print(int width=15) const; 				  // MemberFunction to print name of person.

	// Functions to set private variables from public.

	void setFirstName(string & pFirstName);

	void setLastName(string & pLastName);

	// Functions to get private values from public

	const string & getFirstName() const;

	const string & getLastName() const;

	const bool operator==(Name &pName) const; // overloading operator "=="

	const bool operator<(Name &pName) const;



};
const istream &operator >> (istream &stream,Name &pName);
const ostream &operator << (ostream &stream, Name &pName);

#endif
