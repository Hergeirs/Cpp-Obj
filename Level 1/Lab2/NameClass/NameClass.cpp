// NameClass.cpp
// keludfíla
// Hergeir
// 
//------------------------------------------------------------------------------

#include "NameClass.h"

//------------------------------------------------------------------
// Class to work with objects with name attributes
//------------------------------------------------------------------
   

	Name::Name() 									// Constructor
	{
		firstName="";
		lastName="";
	}
	
	Name::Name(string pFirstName, string pLastName) // Explicit constructor
	{
		firstName = pFirstName;
		lastName = pLastName;
	}
	
	void Name::print(int width)						// Printing Name info.
	{
	cout << endl << setw(width) << "Name: " << setw(width) << firstName + " " + lastName << endl;
	}
	
	void Name::setFirstName(string pFirstName)		// Setting private variable through public function.
	{
		firstName=pFirstName;						
	}	
	
	void Name::setLastName(string pLastName)
	{
		lastName=pLastName;
	}	
	
	const string  Name::getFirstName()				// Getting the private names out in public.
	{
		return firstName;
	}	
	
	const string Name::getLastName()
	{
		return lastName;
	}
