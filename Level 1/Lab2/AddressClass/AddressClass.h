// AddressClass.h
// Headarafíla
// Hergeir
// 
//------------------------------------------------------------------------------
#ifndef ADDRESSCLASS
#define ADDRESSCLASS

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class Address
{
	private:
	
		string streetAddress;
		int zipCode;
		string city;
	
	public:
	
	Address();
	
	Address(string pStreetAddress, int pZipCode, string pCity);
	
	void print(int width=15);
	
	void setStreetAddress(string pStreetAddress);

	void setZipCode(int pZipCode);
	
	void setCity(string pCity);
	
	const string getStreetAddress();
	
	const int getZipCode();
	
	const string getCity();
	
};

#endif
