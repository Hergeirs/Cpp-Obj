// VectorClass.h
// Headarafíla
// Hergeir
// 
//------------------------------------------------------------------------------
#ifndef VECTORCLASS
#define VECTORCLASS

#include "../Timer/Timer.h"
#include <random>
#include <algorithm>
#include <iostream>
using namespace std;

//------------------------------------------------------------------------------
// Array class for sorting algorithm purposes.
//------------------------------------------------------------------------------

class Array
{
private:

	unsigned int * dataSet;			//Pointer for beginning of dynamic integer array would make const if i could.
	unsigned int size;
	Timer timer;
	
public:

	Array (unsigned int arraySize, Timer & timer); 	// Constructor takes size.

	
	~Array (){cout << "Deallocating array!" << endl; delete dataSet;}	//Destructor.
		
	void newSize(unsigned int arraySize)
	{
		unsigned int * temp = dataSet;
		delete[] temp;
		dataSet = new unsigned int[arraySize];
		
		size=arraySize;
	}
			
	//------------------------------------------------------------------------------
	// Letting swap be defined here to ensure it's inline (speed).
	//------------------------------------------------------------------------------
	
	void inline swap(unsigned int &a,unsigned int &b)
	{
		unsigned int tmp = a;
		a = b;
		b = tmp;
	}
	
	void randomFill(); // Filling array with random integer numbers.
	
	//Sorting memberfuntions:
	
	long double bubbleSort();
	long double bubbleSort2();
	
	long double selectionSort();
	long double insertSort();	
	long double quickSort(); 				// Timing
	void quickSorT(int first, int last); 	//Sorting 

	long double quickSort2();				// Timing
	void quickSorT2(int first, int last);	// Sorting

	long double Sort();
};


#endif
