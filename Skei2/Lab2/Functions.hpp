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

//Formatting functions.
std::string toCase (std::string to_Case,bool toLowerCase=true);	// Takes/returns std::string. uses overloaded functino for individual chars
void edgeTrim(std::string &s);								// Function to remove unnessesary whitespace.


// Functions to take user input.
void getLine(std::string &s,std::string prompt);					// Function to ensure input std::string not empty.

int getInt(std::string prompt="Enter Integer: ");			// Function overloaded to allow use in switch.

void getInt(int & i, std::string prompt="Enter integer: ");	// Function to get integer from user (Not allowing empty input).

// Formatted output-functions
void printPrompt(std::string prompt, std::string label="info!", bool pause=true, bool clear=true,size_t=0);
void centerText(std::string input, char fill='*', char edge=' ',int padding=1,size_t=75);

// essentials
void systemPause(std::string prompt="Press enter to continue..."); // Function to allow pause.
void cls(unsigned int newlines=55); // Function to pseudo clear screent of terminal.

#endif
