#include "AddressClass.hpp"

Address::Address()
{
	streetAddress="";
	zipCode=0;
	city="";
}

Address::Address(string & pStreetAddress, int pZipCode, string & pCity)
{
	streetAddress=pStreetAddress;
	zipCode=pZipCode;
	city=pCity;
}

void Address::print(int width) const
{
	cout << endl << setw(width) << "streetAddress: " << setw(width)<< streetAddress << endl << setw(width) << "ZipCode: " << setw(width) << zipCode << endl << setw(width) << "City: " << setw(width) << city << endl;
}

void Address::setStreetAddress(string & pStreetAddress)
{
	streetAddress=pStreetAddress;
}

void Address::setZipCode(int pZipCode)
{
	zipCode=pZipCode;
}

void Address::setCity(string & pCity)
{
	city=pCity;
}

const string & Address::getStreetAddress() const
{
	return streetAddress;
}

const int Address::getZipCode() const
{
	return zipCode;
}

const string & Address::getCity() const
{
	return city;
}

//------------------------------------------------------------------------------
// Overloading operators.
//------------------------------------------------------------------------------

const bool Address::operator==(Address &pAddress) const
{
	if (pAddress.city==city)
		if (pAddress.streetAddress==streetAddress)
			return true;
return false;

}

const bool Address::operator<(Address &pAddress) const
{
if (pAddress.city==city)
{
	return streetAddress < pAddress.streetAddress;
}
else
	return city < pAddress.city;
}

const ostream & operator << (ostream & stream, Address & pAddress)
{
stream << pAddress.getStreetAddress() << DELIM << pAddress.getZipCode() << DELIM << pAddress.getCity() << DELIM;
return stream;
}

const istream & operator >> (istream & stream, Address & pAddress)
{
//Prep.
string streetAddress, city, zipCode;

// getting values.
getline(stream, streetAddress,DELIM);
getline(stream, zipCode,DELIM);
getline(stream, city,DELIM);

//setting values.
pAddress.setStreetAddress(streetAddress);
pAddress.setZipCode(toInt(zipCode));
pAddress.setCity(city);
return stream;
}
