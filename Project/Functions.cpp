#include "Functions.hpp"

typedef unsigned int uint;

//------------------------------------------------------------------------------
// Handy function for controlling input as integer. Primarily i want to avoid
// eternal loops when cin buffer contains char and variable is int.
//------------------------------------------------------------------------------

void getInt(int & i, string prompt)
{
		// while input isn't compatible with int and cout works.
		while (cout << endl << prompt && !(cin >> i))
		{
			// clear everything until newline is encountered
			while(cin.get()!='\n')
			{
				cin.clear();
			}
			cout << endl << "Invalid Input... try again" << endl;
		}
		// clear everything until newline is encountered
		while(cin.get()!='\n')
		{
			cin.clear();
		}
}

int getInt(string prompt) // overloaded for convenience (use in switch)
{
	int i;
	getInt(i,prompt);
	return i;
}


//------------------------------------------------------------------------------
// Function to change the case of string using ascii char values overloaded
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

string toCase (string to_Case,bool toLowercase)		// does not affect input string.
{	// Takes/returns string. uses overloaded functinon for individual chars
	for (unsigned int n = 0; n < to_Case.size(); n += 1)
		to_Case[n] = toCase(to_Case[n],toLowercase);
	edgeTrim(to_Case);
	return to_Case;
}

void toCase (string & to_Case, bool tolowercase)
{
	for (unsigned int i = 0; i < to_Case.size(); ++i)
	{
		to_Case[i]=toCase(to_Case[i]);
	}
}

//------------------------------------------------------------------------------
// Function to format names.
//------------------------------------------------------------------------------
string & nameFormat(string & name)
{
	edgeTrim(name);
	toCase(name);											// making all lowercase
	name[0] = toCase(name[0],0);                          	// making first char capital
	for (unsigned int i = 2; i < name.size(); i += 1)   	// making every char after a space capital
		if (name[i-1]==' ')
			name [i] = toCase(name[i],0);
	return name;
}

//------------------------------------------------------------------------------
// Turns string into integer.... if not actually letters.
//------------------------------------------------------------------------------
int toInt(string s)
{
	int i;
	stringstream S(s);
	S>>i;

	return i;
}
//------------------------------------------------------------------------------
// Function to make integer into string.
//------------------------------------------------------------------------------

string toString (int to_b_string)
{
	string stringie;
	stringstream s;
	s << to_b_string;
	s >> stringie;
	return stringie;
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

//------------------------------------------------------------------------------
// Function for printing warnings and prompts.
//------------------------------------------------------------------------------

void printPrompt(string prompt, string label, bool pause, bool clear,int width)
{
if (width==0)
	width = prompt.size();

uint maxWidth = width+label.size()+3;
	if(clear)
		cls();
	centerText(label,'*',' ',1,maxWidth);
	centerText(prompt,' ','|',1,maxWidth);
	centerText("*",'*',' ',0,maxWidth);
	if (pause)
		systemPause();
}

void centerText(string input, char fill, char edge, int padding,int width)
{
	cout.fill(fill);

	if (signed(input.size())+padding<width)
		{
			for(int a=0;a<padding;++a){input.push_back(' ');}	// right padding has priority
			if (signed(input.size())+padding<width)
				input.insert(0,padding,' ');
		}

	unsigned int totalPadding = width-input.size();
	cout << edge << setw((totalPadding/2)+input.size()) << input << setw(totalPadding-(totalPadding/2)) << edge << endl << setfill(' ');
}

//------------------------------------------------------------------------------
// Emulate system("Pause") from windows. * have to press enter to continue though.
//------------------------------------------------------------------------------

void systemPause(string prompt)
{
	cout << endl << prompt;
	cin.get();
}

//------------------------------------------------------------------------------
// Clear screen by spewing many endl.
//------------------------------------------------------------------------------

void cls(uint newlines)
{
	for (unsigned int i = 0; i < newlines; ++i)
		cout << endl;
}
