// PersonClass.cpp
// Headarafíla
// Hergeir
// 
//------------------------------------------------------------------------------
#include "PersonClass.h"

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
	void Person::print(int width)
	{
		name.print();
		cout << setw(width) << "PersNr: " << setw(width) << persNr;
		address.print();
		cout << setw(width) << "Shoesize: " << setw(width) << skoNr;

	}
	
	void Person::setPersNr(string pPersNr)
	{
	persNr=pPersNr;
	}
	void Person::setSkoNr(int pSkoNr)
	{
	skoNr=pSkoNr;
	}
	
	const string Person::getPersNr()
	{
		return persNr;
	}
	const int Person::getSkoNr()
	{
		return skoNr;
	}
	
	
	
	Persons::Persons()
	{
		persons = vector <Person> ();
		Person person("Kasef","aeoe","AEFMoseaf",240,"SAVEf","a550",200); // Maybe valid Person somewhere.
		persons.push_back(person); 
		person.setPersNr("a551");
		persons.push_back(person); // adding two identical twins !
		person.setPersNr("a552");
		persons.push_back(person);
	    
	}
	void Persons::print(int width)
	{
		for (auto n:persons)
		{
			n.print();
			cout << endl << setw(width) << "persNr: " << setw(width) << n.getPersNr();
			cout << endl<< setw(width) << "SkoNr : " << setw(width) << n.getSkoNr();
			cout << endl;
		}
	}
	void Persons::push_back(Person person)
	{
		persons.push_back(person);
	}

