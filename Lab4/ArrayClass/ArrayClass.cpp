#include "ArrayClass.h"

//------------------------------------------------------------------------------
// Constructor...
//------------------------------------------------------------------------------

Array::Array (unsigned int arraySize, Timer & timer):size(arraySize),timer(timer)
{
	dataSet = new unsigned int[arraySize]; // Rest is declared in quickassign
	size=arraySize;
}

//------------------------------------------------------------------------------
// Function to randomly assign values to array slots.
//------------------------------------------------------------------------------
void Array::randomFill()
{
	default_random_engine randomator((unsigned long) time(NULL));
	uniform_int_distribution<unsigned int>dist(0, size-1); 					//Required interval.
			for (size_t n = 0; n < size; ++n)
				dataSet[n]=dist(randomator);
}

//------------------------------------------------------------------------------
// Function to sort array using bubbleSort algorithm. Returns time operation took.
//------------------------------------------------------------------------------
long double Array::bubbleSort()
{
	int temp;
	timer.start();
	for(size_t i=0; i < size-1; ++i)
		for (size_t n = 0; n+1 < size; ++n)
			if (dataSet[n] > dataSet[n+1])
			{
				temp=dataSet[n];
				dataSet[n]=dataSet[n+1];
				dataSet[n+1]=temp;
			}	
	return timer.stop();
}
//------------------------------------------------------------------------------
// Function to sort array using alternative bubbleSort algorithm. Returns time operation took.
//------------------------------------------------------------------------------
long double Array::bubbleSort2()
{
	int temp;
	timer.start();
	bool sorted =false;
	for(unsigned int pass=0; pass < size-1 && !sorted ; pass++)
	{
		sorted = true;
		for(unsigned int i=0; i < size-1; ++i)
			if(dataSet[i] > dataSet[i+1])
			{
				sorted = false;
				temp=dataSet[i];
				dataSet[i]=dataSet[i+1];
				dataSet[i+1]=temp;
			}
		}
	return timer.stop();
}

//------------------------------------------------------------------------------
// Function to sort array using SelectionSort algorithm. Returns time operation took.
//------------------------------------------------------------------------------
long double Array::selectionSort()
{
	timer.start();
			unsigned int smallIdx = 0;
	for(unsigned int i=0; i < size - 1; ++i)
	{
		smallIdx = i;
		for(unsigned int j= i+1; j < size; ++j)
			if(dataSet[j] < dataSet[smallIdx])
				smallIdx = j;
		if(smallIdx != i)
			swap(dataSet[i], dataSet[smallIdx]);
	}
	return timer.stop();
}

//-----------------------------------------------------------------------------
// insertSort
//-----------------------------------------------------------------------------
long double Array::insertSort()
{
	timer.start();
	if(size > 1)
		{
			int save, j;
			for(int k = size - 1; k >= 0; k--)
			{
				j = k+1;
				save = dataSet[k];
				while(j < size && save > dataSet[j])
				{
					dataSet[j-1] = dataSet[j];
					j++; 
				}
				dataSet[j-1] = save;
			}
		}
	return timer.stop();
}

//------------------------------------------------------------------------------
// Times quickSort algorithm on private array within object.
//------------------------------------------------------------------------------
long double Array::quickSort()
{
	timer.start();
	quickSorT(0,size-1);
	return timer.stop();
}
//------------------------------------------------------------------------------
// Performs QuickSort on private array variable.
//------------------------------------------------------------------------------
void Array::quickSorT(int first, int last)
{
	if(first < last)
	{
		int low = first;
		int high = last;
		if(dataSet[first] > dataSet[last])
			swap(dataSet[first], dataSet[last]);
		do
		{
			do{ low++; }while(dataSet[low] < dataSet[first]);
			do{ high--;}while(dataSet[high] > dataSet[first]);
			if(low < high)
				swap(dataSet[low], dataSet[high]);
		}while(low <= high);
		swap(dataSet[first], dataSet[high]);
		quickSorT(first, high-1);
		quickSorT(high+1, last);
	}
}

//------------------------------------------------------------------------------
// Times alternative quickSort algorithm on private array within object.
//------------------------------------------------------------------------------
long double Array::quickSort2()
{
	timer.start();
	quickSorT2(0,size-1);
	return timer.stop();
}
//------------------------------------------------------------------------------
// Performs alternative QuickSort on private array variable.
//------------------------------------------------------------------------------
void Array::quickSorT2(int first, int last)
{
	int low = first;
	int high = last;
	int x = dataSet[(first+last)/2];
	do
	{
		while(dataSet[low] < x){low++;}
			while(dataSet[high] > x){high--;}
				if(low<=high)
		{
			swap(dataSet[low],dataSet[high]);
			low++;
			high--;
		}
			}while(low <= high); // Loopa genom vektorn medan low <= high
	if(first < high) quickSorT2(first,high);
	if(low < last) quickSorT2(low,last);
}

long double Array::Sort()
{
timer.start();
 sort(dataSet,&dataSet[size-1]);
return timer.stop();	
}
