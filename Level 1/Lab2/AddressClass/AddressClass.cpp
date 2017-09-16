#include "AddressClass.h"

Address::Address()
{
	streetAddress="";
	zipCode=0;
	city="";
}
Address::Address(string pStreetAddress, int pZipCode, string pCity)
{
	streetAddress=pStreetAddress;
	zipCode=pZipCode;
	city=pCity;
}
void Address::print(int width)
{
	cout << endl << setw(width) << "streetAddress: " << setw(width)<< streetAddress << endl << setw(width) << "ZipCode: " << setw(width) << zipCode << endl << setw(width) << "City: " << setw(width) << city << endl;
}
void Address::setStreetAddress(string pStreetAddress)
{
	streetAddress=pStreetAddress;
}
void Address::setZipCode(int pZipCode)
{
	zipCode=pZipCode;
}
void Address::setCity(string pCity)
{
	city=pCity;
}
const string Address::getStreetAddress()
{
	return streetAddress;
}
const int Address::getZipCode()
{
	return zipCode;
}
const string Address::getCity()
{
	return city;
}
