// Functions.h
// Headarafíla
// Hergeir
//
//------------------------------------------------------------------------------
#ifndef FUNCTIONS
#define FUNCTIONS

#include <sstream>
#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>

const char DELIM='|';

using namespace std;

void getLine(string &s,string prompt);					// Function to ensure input string not empty.

void getInt(int & i, string prompt="Enter integer: ");	// Function to get integer from user (Not allowing empty input).

int getInt(string prompt="Enter Integer: ");			// Function overloaded to allow use in switch.

int toInt(string s);

string toString (int to_b_string);

string toCase (string to_Case,bool toLowerCase=true);	// Takes/returns string. uses overloaded functino for individual chars

string & nameFormat(string & name);

void edgeTrim(string &s);								// Function to remove unnessesary whitespace.

void printPrompt(string prompt, string label="info!", bool pause=true, bool clear=true,size_t=0);

void centerText(string input, char fill='*', char edge=' ',int padding=1,size_t=75);

void centerMenuItem(string input, char fill='*', char edge=' ',int index=0,int padding=1,size_t=75);

void systemPause(string prompt="Press enter to continue..."); // Function to allow pause.

void cls(uint newlines=55); // Function to pseudo clear screent of terminal.

#endif
