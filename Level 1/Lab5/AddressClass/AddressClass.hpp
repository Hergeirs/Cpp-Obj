// AddressClass.h
// Headarafíla
// Hergeir
//
//------------------------------------------------------------------------------
#ifndef ADDRESSCLASS
#define ADDRESSCLASS


#include "../Functions/Functions.hpp"

class Address
{
private:

	string streetAddress;
	int zipCode;
	string city;

public:

	Address();

	Address(string & pStreetAddress, int pZipCode, string & pCity);

	void print(int width=15) const;

	void setStreetAddress(string & pStreetAddress);

	void setZipCode(int pZipCode);

	void setCity(string & pCity);

	const string & getStreetAddress() const;

	const int getZipCode() const;

	const string & getCity() const;

	const bool operator==(Address &pAddress) const; // overloading operator "=="

	const bool operator<(Address &pAddress) const;
};

const ostream & operator << (ostream & stream, Address & pAddress);

const istream & operator >> (istream & stream, Address & pAddress);

#endif
