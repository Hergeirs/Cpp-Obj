// NameClass.h
// Headarafíla
// Hergeir
// 
//------------------------------------------------------------------------------
#ifndef NAMECLASS
#define NAMECLASS

#include <string>
#include <iostream>
#include <iomanip>

using namespace std; 



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
	
	Name(string pFirstName, string pLastName); // Constructor
	
	void print(int width=15); 				  // MemberFunction to print name of person.
	
											// Functions to set private variables from public.
	
	void setFirstName(string pFirstName);
	
	void setLastName(string pLastName);
	
										 // Functions to get private values from public
	
	const string getFirstName();

	const string getLastName();
};

#endif
