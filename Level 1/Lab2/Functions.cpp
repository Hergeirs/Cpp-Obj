#include "Functions.h"

//------------------------------------------------------------------------------
// Handy function for controlling input as integer. Primarily i want to avoid 
// eternal loops when cin buffer contains char and variable is int.
//------------------------------------------------------------------------------
void getInt(int &i, string prompt)
{
	while (cout << endl << prompt && !(cin >> i)) // while input isn't compatible with int and cout works.
	{
		while(cin.get()!='\n')					// clear everything until newline is encountered
		{
			cin.clear();
		}
		cout << endl << "Invalid Input... try again" << endl;
			}
		cin.get();									// Get that last newline.
	}
		int getInt() // overloaded for convenience
	{
		int i;
		getInt(i);
		return i;
	}
		//------------------------------------------------------------------------------
	// Remove unnessesary spaces. trailing and beginning.
	//------------------------------------------------------------------------------
		void edgeTrim(string &s)
	{
		if (!s.empty())
		{
			for (unsigned int i = 0; s[i]==' '; ++i) // removing frontal spaces
			{
				s.erase(i);
			}
			for (unsigned int i = s.size()-1; s[i]==' '; --i) //removing trailing spaces
			{
				s.erase(i);
			}
		}
	}
			//------------------------------------------------------------------------------
	// an implementation of getline with check for empty input
	//------------------------------------------------------------------------------
		void getLine(string &s,string prompt)
	{
		while (cout << endl << prompt && getline(cin,s)) // input output loop.
		{
			edgeTrim(s); //stripping spaces in ends of string.
						if (s=="") // making sure input won't be empty.
			{
				cout << endl << "Input can't be empty..." << endl;
				continue;
			}
			else
				break; // if s isn't empty.
			}
		}
		void systemPause(string prompt)
		{
		cout << endl << prompt;
		cin.get();
		}
		//------------------------------------------------------------------------------
		// Function to make a person using user input.
		//------------------------------------------------------------------------------
		void addToReg(Persons &persons)
		{
			string firstName,lastName,streetAddress,city,persNr;
			int zipCode, shoeSize;
			cls();
			cout << "*******ADD PERSON*******" << endl;
					getLine(persNr,"Enter PersNr: ");
					getLine(firstName,"Enter firstname: ");
						getLine(lastName,"Enter lastname: ");
						getLine(streetAddress,"Enter streetAddress: ");
						getInt(zipCode,"Enter zipCode: ");
						getLine(city,"Enter CityName: ");
						getInt(shoeSize,"Enter shoeSize: ");	
					Person person(firstName,lastName,streetAddress,zipCode,city,persNr,shoeSize);
			persons.push_back(person);
		}

//------------------------------------------------------------------------------
// Clear screen by spewing many endl.
//------------------------------------------------------------------------------

void cls(int newlines)
{
for (unsigned int i = 0; i < newlines; ++i)
	cout << endl;
}
