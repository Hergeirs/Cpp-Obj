// Functions.h
// Headarafíla
// Hergeir
// 
//------------------------------------------------------------------------------
#ifndef FUNCTIONS
#define FUNCTIONS

#include "PersonClass/PersonClass.h" // The created class


void getInt(int &i, string prompt="Enter integer: ");	// Function to get integer from user (Not allowing empty input). 

int getInt();											// Function overloaded to allow use in switch.

void edgeTrim(string &s);								// Function to remove unnessesary whitespace.
	
void getLine(string &s,string prompt);					// Function to ensure input string not empty.

void addToReg(PersonList &list);								// Function to add Person to vector from user input.

void systemPause(string prompt="Press enter to continue..."); // Function to allow pause. 

void cls(int newlines=50); // Function to pseudo clear screent of terminal.

#endif
