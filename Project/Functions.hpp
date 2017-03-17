// Functions.h
// Headarafíla
// Hergeir
//
//------------------------------------------------------------------------------
#ifndef FUNCTIONS
#define FUNCTIONS

//Includes used throughout all classes of project. Is included everywhere else as well
#include <string>
#include <iostream>
#include <iomanip>

const char DELIM='|';

using namespace std;

//Formatting functions.
string toCase (string to_Case,bool toLowerCase=true);	// Takes/returns string. uses overloaded functino for individual chars
void edgeTrim(string &s);								// Function to remove unnessesary whitespace.


// Functions to take user input.
void getLine(string &s,string prompt);					// Function to ensure input string not empty.
void getInt(int & i, string prompt="Enter integer: ");	// Function to get integer from user (Not allowing empty input).
int getInt(string prompt="Enter Integer: ");			// Function overloaded to allow use in switch.

// Formatted output-functions
void printPrompt(string prompt, string label="info!", bool pause=true, bool clear=true,size_t=0);
void centerText(string input, char fill='*', char edge=' ',int padding=1,size_t=75);
void centerMenuItem(string input, char fill='*', char edge=' ',int index=0,int padding=1,size_t=75);

// essentials
void systemPause(string prompt="Press enter to continue..."); // Function to allow pause.
void cls(uint newlines=55); // Function to pseudo clear screent of terminal.

#endif
