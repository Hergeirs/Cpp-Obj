#include "TestApp.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <iterator>
#include <algorithm>

/**********************************************************************************
		All functions in this class only exist to take user data and use pass them
		through to the lower silent classes and showing errors therefrom.
**********************************************************************************/

// default constructor.
template<typename T>
TestApp<T>::TestApp()
:theList(new ListManipulator<T>)
{
	std::cout << std::fixed;	// setting stream to print decimals (not scientific notation)
	
	menu.setMenuTitle("Main menu");
//menu Items
	menu.addItem("Fill list with random numbers.",true);
	menu.addItem("Summerize the values in the list.",false);
	menu.addItem("average of numbers",false);
	menu.addItem("find first number between 1500 and 1900",false);
	menu.addItem("Divide list by two.",false);
	menu.addItem("swap places",false);
	menu.addItem("find largest and smallest number",false);
	menu.addItem("sort.",false);
	menu.addItem("clear list.",false);
	menu.addItem("write to file",false);
	menu.addItem("read from file.",true);
	menu.addItem("Print numbers",false);
	menu.addItem("Quit",true);
}

template<typename T>
TestApp<T>::~TestApp()
{
	std::cout << "destroyed" << std::endl;
}


//Funcion to keep menues running until exit
template<typename T>
void TestApp<T>::run()
{
	while (doMenuChoice(menu.getMenuChoice())){} // will loop until doMenuChoice returns false	
}

// call relevant functions for menu choices.
template<typename T>
const bool TestApp<T>::doMenuChoice(const int choice)
{
	switch (choice)
	{
	case 1:
		menu.enableAll();
		fillList();
		break;
	case 2:
		getSum();
		break;
	case 3:
		getAvg();
		break;
	case 4:
		getNumberBetween1500and1900();
		break;
	case 5:
		divideBy2();
		break;
	case 6:
		swapPlaces();
		break;
	case 7:
		getMinMax();
		break;
	case 8:
		sortList();
		break;
	case 9:
		clearList();
		break;
	case 10:
		writeToFile();
		break;
	case 11:
		loadFromFile();
		break;
	case 12:
		printNumbers();
		break;
	case 13:    
		return false;
	default:
		break;
	}	
	return true;
}

template<typename T>
void TestApp<T>::fillList()
{
	theList->randomFill();
} 

template<typename T>
void TestApp<T>::getSum() const
{
	printPrompt(std::to_string(theList->sumList()));
}


template<typename T>
void TestApp<T>::getAvg() const
{
	printPrompt(std::to_string(theList->avgList()));
}

template<typename T>
void TestApp<T>::getNumberBetween1500and1900() const
{
	T num=0;
	if (theList->findFirst1500_1900(num))
	{
		std::cout << "first num between 1500 and 1900 is: " << num << std::endl;
	}
	else
	{
		std::cout << "no number between 1500 and 1900." << std::endl;
	}
	systemPause();
}

template<typename T>
void TestApp<T>::divideBy2()
{
	theList->divideBy2();
	printPrompt("The values int the list are now halved");
}

template<typename T>
void TestApp<T>::swapPlaces()
{
	theList->swapPlaces();
	printPrompt("The list is now reversed");
}


template<typename T>
void TestApp<T>::getMinMax() const
{
	T min,max;
	theList->findMinMax(min,max);
	printPrompt(std::to_string(min),"min",false,false);
	printPrompt(std::to_string(max),"max",true,false);
}
 
template<typename T>
void TestApp<T>::sortList()
{
	theList->sortList();
	printPrompt("List is now sorted!");
}

template<typename T>
void TestApp<T>::clearList()
{
	theList->clearList();
	printPrompt("List is now cleared!");
}

template<typename T>
void TestApp<T>::loadFromFile()
{
	theList->readFromFile();
}

template<typename T>
void TestApp<T>::writeToFile() const
{
	theList->saveToFile();
}


template<typename T>
void TestApp<T>::printNumbers() const
{
	for (auto & i: theList->getList())
		std::cout << std::setw(20) << std::right << i << std::endl;
	systemPause();
}


template class TestApp<double>;
template class TestApp<int>;

