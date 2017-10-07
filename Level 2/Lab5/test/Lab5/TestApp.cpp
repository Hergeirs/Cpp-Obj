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
	std::cout << std::setprecision(2);	//only want two decimals printed
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
	menu.addItem("Back",true);
}

template<typename T>
TestApp<T>::~TestApp()
{
	// nothing to do
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
	switch (choice)	//menu entries
	{
	case 1:
		fillList();	
		menu.enableAll();	
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
	printPrompt("List is now full of random elments");
} 

template<typename T>
void TestApp<T>::getSum() const
{
	printPrompt(std::to_string(theList->sumList()),"sum");
}


template<typename T>
void TestApp<T>::getAvg() const
{
	printPrompt(std::to_string(theList->avgList()),"avg");
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
	menu.enableAll();
	printPrompt("List is now cleared!");
}

template<typename T>
TestApp<T> &TestApp<T>::loadFromFile()
{
	try
	{
		theList->readFromFile();
		menu.enableAll(); //enable all menuoption once list is loaded
		printPrompt("elements from file loaded into list");
	}
	catch (std::runtime_error & error)
	{
		printPrompt("Elements in file are of wrong type","ERROR");
	}
	
	return *this;
}

template<typename T>
void TestApp<T>::writeToFile() const
{
	theList->saveToFile();
	printPrompt("list has been saved to file");
}

template<typename T>
void TestApp<T>::printNumbers() const
{
	size_t counter=0;
	std::cout << "numbers in list:" << std::endl;
	for (auto & i: theList->getList())
		std::cout << std::right << std::setw(3) << ++counter << std::right << std::setw(10) << i << std::endl;
	systemPause();
}	

template class TestApp<double>; //instantialating class template for compilation
template class TestApp<int>;	//instantializing class template for compilation