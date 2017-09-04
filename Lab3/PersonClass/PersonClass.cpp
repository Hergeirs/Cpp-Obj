// PersonClass.cpp
// Headarafíla
// Hergeir
//
//------------------------------------------------------------------------------
#include "PersonClass.h"

//------------------------------------------------------------------------------
// Person memberfunctino definitions
//------------------------------------------------------------------------------

Person::Person()
{
	persNr="";
	skoNr=0;
}

Person::Person(string firstName,string lastName,string streetAddress,int zipCode,string city, string pPersNr,int pSkoNr)
{
	//Setting values using memberfunction in address and person classes
	name.setFirstName(firstName);
	name.setLastName(lastName);
	address.setStreetAddress(streetAddress);
	address.setZipCode(zipCode);
	address.setCity(city);

	//Printing private values of Person class
	persNr=pPersNr;
	skoNr=pSkoNr;
}

void Person::print(int width) const
{
	cout << endl << "**********Person Info*********" << endl;
	name.print();
	cout << setw(width) << "PersNr: " << setw(width) << persNr;
	address.print();
	cout << setw(width) << "Shoesize: " << setw(width) << skoNr;
	cout << endl << "******************************" << endl;
}

void Person::setPersNr(string pPersNr)
{
	persNr=pPersNr;
}

void Person::setSkoNr(int pSkoNr)
{
	skoNr=pSkoNr;
}

const string& Person::getPersNr() const
{
	return persNr;
}
const int Person::getSkoNr() const
{
	return skoNr;
}

Name& Person::getName()
{
	return name;
}

Address& Person::getAddress()
{
	return address;
}

//------------------------------------------------------------------------------
// Overloaded operators of Person class
//------------------------------------------------------------------------------

const bool Person:: operator ==(Person &pPerson) const
{
if (name==pPerson.name)
	if (address==pPerson.address)
		if (skoNr==pPerson.skoNr)
			if (persNr==pPerson.persNr)	
				return true;
	
return false;
}

const bool Person::operator <(Person &pPerson) const
{
	if (name==pPerson.name)
	{
		return address < pPerson.address;
	}
	return name < pPerson.name;
}

const ostream & operator << (ostream & stream, Person & pPerson)
{
stream << pPerson.getName();
stream << pPerson.getAddress();
stream << pPerson.getPersNr() << DELIM << pPerson.getSkoNr() << endl;
return stream;
}

const istream & operator >> (istream & stream, Person & pPerson)
{
string persNr, skoNr;
stream >> pPerson.getName();
stream >> pPerson.getAddress();

getline(stream,persNr,DELIM);

getline(stream,skoNr);

pPerson.setPersNr(persNr);
pPerson.setSkoNr(toInt(skoNr));

return stream; 
}


