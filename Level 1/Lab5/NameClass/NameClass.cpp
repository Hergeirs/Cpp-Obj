// NameClass.cpp
// keludfíla
// Hergeir
//
//------------------------------------------------------------------------------

#include "NameClass.hpp"



//------------------------------------------------------------------------------
// Class to work with objects with name attributes
//------------------------------------------------------------------------------


Name::Name()								// Constructor
{
	firstName="";
	lastName="";
}

Name::Name(string & pFirstName, string & pLastName) // Explicit constructor
{
	firstName = pFirstName;
	lastName = pLastName;
}

void Name::print(int width)	const					// Printing Name info.
{
	cout<<setw(width)<<"Name: "<<setw(width)<<firstName+ " " +lastName << endl;
}
// Setting private variable through public function.
void Name::setFirstName(string & pFirstName)
{
	firstName=pFirstName;
}

void Name::setLastName(string & pLastName)
{
	lastName=pLastName;
}
// Getting the private names out in public.
const string &  Name::getFirstName() const
{
	return firstName;
}

const string & Name::getLastName() const
{
	return lastName;
}

//------------------------------------------------------------------------------
// Overloading operators.
//------------------------------------------------------------------------------

const bool Name::operator==(Name &pName) const
{
	if (pName.lastName==lastName)
		if (pName.firstName==firstName)
			return true;

	return false;
}

const bool Name::operator<(Name &pName) const
{	// ensuring sorting by firstname if lastname equal.
	if (toCase(pName.lastName)==toCase(lastName))
	{
		return toCase(firstName) < toCase(pName.firstName);
	}
	else
		return toCase(lastName) < toCase(pName.lastName);
}

const istream &operator >> (istream &stream,Name &pName)
{
	//Prep
	string firstName,lastName;

	// Getting values.
	getline(stream,firstName,DELIM);
	getline(stream,lastName,DELIM);

	// Setting values.
	pName.setFirstName(firstName);
	pName.setLastName(lastName);
	return stream;
}

const ostream &operator << (ostream &stream, Name &pName)
{
	stream << pName.getFirstName() << DELIM << pName.getLastName() << DELIM;
	return stream;
}
