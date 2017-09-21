#include "Functions.hpp"
#include <iostream>	//std::cout, std::endl , std::cin
#include <iomanip> 	//std::setw, std::fill ... etc
#include <cstdio>	//
//------------------------------------------------------------------------------
// Handy function for controlling input as integer. Primarily i want to avoid
// eternal loops when std::cin buffer contains char and variable is int.
//------------------------------------------------------------------------------
void getInt(int & i, std::string prompt)
{
		// while input isn't compatible with int and std::cout works.
		while (std::cout << std::endl << prompt && !(std::cin >> i))
		{
			// clear everything until newline is encountered
			while(std::cin.get()!='\n')
			{
				std::cin.clear();
			}
			std::cout << std::endl << "Invalid Input... try again" << std::endl;
		}
		// clear everything until newline is encountered
		while(std::cin.get()!='\n')
			std::cin.clear();
}

double getDouble(std::string prompt)
{
		double i;
		// while input isn't compatible with int and std::cout works.
		while (std::cout << std::endl << prompt && !(std::cin >> i))
		{
			// clear everything until newline is encountered
			while(std::cin.get()!='\n')
			{
				std::cin.clear();
			}
			std::cout << std::endl << "Invalid Input... try again" << std::endl;
		}
		// clear everything until newline is encountered
		while(std::cin.get()!='\n')
			std::cin.clear();
		return i;
}

double getPositiveDouble(std::string prompt)
{
	double amount;
	do
	{
		amount=getDouble(prompt);
	} while (amount < 0);
	return amount;
}


unsigned int getUnsignedInt(std::string prompt)
{
	int integer;
	do
	{
		getInt(integer,prompt);
	} while (integer<0 && printPrompt("Invalid input... Only takes positive integers!"));
	return integer;
}

int getInt(std::string prompt) // overloaded for convenience (use in switch)
{
	int i;
	getInt(i,prompt);
	return i;
}


//------------------------------------------------------------------------------
// Function to change the case of std::string using ascii char values overloaded
//------------------------------------------------------------------------------

char toCase(char to_case, bool toLowercase=true)  // takes/returns char
{
	if (toLowercase)
	{
		if (to_case<='Z' && to_case>='A')
			to_case+=32;                            // 32 is difference between cases.
	}
	else if (to_case>='a' && to_case<='z')
		to_case-=32;

	return to_case;
}

std::string toCase (std::string to_Case,bool toLowercase)		// does not affect input std::string.
{	// Takes/returns std::string. uses overloaded functinon for individual chars
	for (uint n = 0; n < to_Case.size(); n += 1)
		to_Case[n] = toCase(to_Case[n],toLowercase);
	edgeTrim(to_Case);
	return to_Case;
}

void toCase (std::string & to_Case, bool tolowercase)
{
	for (uint i = 0; i < to_Case.size(); ++i)
	{
		to_Case[i]=toCase(to_Case[i]);
	}
}

//------------------------------------------------------------------------------
// Remove unnessesary spaces. trailing and beginning.
//------------------------------------------------------------------------------

void edgeTrim(std::string &s)
{
	if (!s.empty())
	{
		for (uint i = 0; s[i]==' '; ++i) // removing frontal spaces
		{
			s.erase(i);
		}
		for (uint i = s.size()-1; s[i]==' '; --i) //removing trailing spaces
		{
			s.erase(i);
		}
	}
}

//------------------------------------------------------------------------------
// an implementation of getline with check for empty input
//------------------------------------------------------------------------------

void getLine(std::string &s,std::string prompt)
{
	while (std::cout << std::endl << prompt && getline(std::cin,s)) // input output loop.
	{
		edgeTrim(s); //stripping spaces in ends of std::string.
		if (s.empty()) // making sure input won't be empty.
		{
			std::cout << std::endl << "Input can't be empty..." << std::endl;
			continue;
		}
		else
			break; // if s isn't empty.
	}
}

//------------------------------------------------------------------------------
// Function for printing warnings and prompts.
//------------------------------------------------------------------------------

const bool printPrompt(std::string prompt, std::string label, bool pause, bool clear,size_t width)
{ 
	if(width < std::max(prompt.size(),label.size()))
		width = std::max(prompt.size(),label.size());
	if(clear)
		cls();
	centerText("",'_','_',0,width);
	centerText(label,'_','|',1,width);
	centerText(prompt,' ','|',1,width);
	centerText("",'_','|',0,width);
	if (pause)
		systemPause();
	return true;
}

void centerText(std::string input, char fill, char edge, int padding,size_t width)
{
	std::cout << std::right << std::setfill(fill);
	width+=7;
	for (int tp=0 ;input.size()<width && tp < padding; ++tp)
	{
		input.push_back(' '); // std::right padding has priority

		if (input.size()+1 < width)
			input.insert(0,1,' ');
	}

	uint totalPadding = width-input.size();
	std::cout << edge;
	std::cout << std::setw((totalPadding/2)+input.size()) << input;
	std::cout << std::setw(float(totalPadding-float(totalPadding/2))) << edge << std::endl;
	std::cout << std::setfill(' ');
}

//------------------------------------------------------------------------------
// Emulate system("Pause") from windows. * have to press enter to continue though.
// cross-platform even !
//------------------------------------------------------------------------------

void systemPause(std::string prompt)
{
	std::cout << std::endl << prompt;
	std::cin.get();
}

//------------------------------------------------------------------------------
// Clear screen by spewing amount of std::endl.
//------------------------------------------------------------------------------

void cls(uint amountNewlines)
{
	for (uint i = 0; i < amountNewlines; ++i)
		std::cout << std::endl;
}



/*	Utility function to check wether file exists or not inspiration from stackoverflow.
	Because std::ifstream creates file when it leaves scope (unexpected behaviour)    	*/

const bool fileExist (const std::string& name) 
{
    if (FILE *file = fopen(name.c_str(), "r")) 
	{
        fclose(file);
        return true;
    } 
	else 
	{
        return false;
    }   
}