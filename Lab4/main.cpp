#include "ArrayClass/ArrayClass.h"
#include "TestClass/TestClass.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;
const unsigned int WIDTH=75;

//------------------------------------------------------------------------------
// Sorting function.
//------------------------------------------------------------------------------

inline long double sorting(Array & array, Algorithm & usedAlgorithm)
{
long double time;
cout << "\b";
	switch(usedAlgorithm)
	{
		case NONE:
		case END:
			cout << "Error... Must fix" << endl;
			break;
		case bubbleSort:
			time=array.bubbleSort();
			break;
		case bubbleSort2:
			time=array.bubbleSort2();		
			break;
		case selectionSort:
			time=array.selectionSort();		
			break;
		case insertSort:
			time=array.insertSort();		
			break;
		case quickSort:
			time=array.quickSort();		
			break;
		case quickSort2:
			time=array.quickSort2();		
			break;
		case Sort:
			time=array.Sort();
			break;
		}

	return time;
}

//------------------------------------------------------------------------------
// function to center the given text string within a box.
//------------------------------------------------------------------------------

void centerText(string input, char fill='*', char edge=' ',int padding=1,int width=WIDTH)
{
	cout.fill(fill);
	
	if (input.size()+padding<width)
		{
			for(unsigned int a=0;a<padding;++a){input.push_back(' ');}	// right padding has priority
			if (input.size()+padding<width)
				input.insert(0,padding,' ');
		}
	
	unsigned int totalPadding = width-input.size();
	cout << edge << setw((totalPadding/2)+input.size()) << input << setw(totalPadding-(totalPadding/2)) << edge << endl;
}

void centerText(vector <string> & input,char fill='*', char edge=' ', int padding=1, int width=WIDTH)
{
	cout.fill(fill);
	for (auto v : input)
	{	
		if (v.size()+padding<width)
		{
			for(unsigned int a=0;a<padding;++a){v.push_back(' ');}	// right padding has priority
			if (input.size()+padding<width)
				v.insert(0,padding,' ');
		}
	}
}
//------------------------------------------------------------------------------
// calculate average value of long double vector.
//------------------------------------------------------------------------------

long double getAverage(vector<long double> v)
{
 	long double total=0;
 	
	for (auto a:v)
	{
		total+=a;
	}
	return total/v.size();
}

//------------------------------------------------------------------------------
// Function that iterates over all sorting algorithms and tests each one.
//------------------------------------------------------------------------------

void test(TestClass & results)
{
	// Just wanted to be able to test everything easely.
	const unsigned int stepAmount=5000;
	const unsigned int minAmount=stepAmount;
	const unsigned int maxAmount=40000;
	const unsigned int iterations=10;
	const Algorithm startAlgorithm=bubbleSort;
	const Algorithm endAlgorithm=END;
	

	Timer timer; 									// Only making one timer throughout program.
	Array array(0,timer);	 						// making array take time, so that only one timer needs to be constructed. 
	vector <long double> times;

	cout << unitbuf;

	for (int sort = startAlgorithm; sort < endAlgorithm; ++sort) // pseudo iterating over my enum
	{
		Algorithm usedAlgorithm = static_cast<Algorithm>(sort);
	
		centerText(getLabel(usedAlgorithm));
		centerText("   Elements in array                         Average sorting time[s]",' ','|');
		centerText("progress",' ','|');
		centerText("",' ','|');

		for (unsigned int amount = minAmount; amount <=maxAmount; amount += stepAmount)	//iterating over amounts of elements
		{
			cout << '|' << setw(WIDTH/4) << right << amount << setw(floor(float(WIDTH)/2-(float(WIDTH)/4))+2); 
			array.newSize(amount);	// Changing used size of array... array size increases dynamically alloates space.
			
			// Just some eyecandy
			cout << setw(10) << "0%";	
			
			for (unsigned int i = 0; i < iterations; ++i)		// Taking 10 measurements.
			{

				array.randomFill(); 							// Refilling random data into array			
				times.push_back(sorting(array,usedAlgorithm));	// filling time into vector.
				
				// Some more eyecandy
				cout << "\b\b\b" << setw(4) << (i+1)*10 << '%';
				
				if (i==iterations-1) 							// if last iteration of amount
				{
					results.addResult(getAverage(times),amount,usedAlgorithm);
					
					// Even more eyecandy and info
					cout << "\b\b\b\b" << " " << "DONE";
					cout << setfill(' ') << setw(ceil(float(WIDTH)/2-(float(WIDTH)/4))) << fixed << right << setprecision(6) << getAverage(times)/1000000 << setw(ceil(float(WIDTH)/4)-2) << '|' << endl;
					
					times.clear(); //clearing vector for another run
					if (amount==maxAmount)		// After algorithm is done.
					{
						centerText("",' ','|');
						centerText(getLabel(usedAlgorithm));
						cout << endl;
					}
				}
			}
		
		}
	}
}

//------------------------------------------------------------------------------
// Function to write to a file. 
//------------------------------------------------------------------------------

void writeToFile(TestClass & results, string fileName ="log")
{
	ofstream os(fileName);
	if (os.is_open())
	{
		centerText("*");
		centerText("Flushing to file \""+fileName+"\"",' ','|');
		os << results; // writing to file. 	
		centerText("Done!",' ','|');
		centerText("*");
	}
	else 
		centerText("The file \""+fileName+"\" could not be opened for writing.");
	os.close();
}

//------------------------------------------------------------------------------
// Just to keep things neat. 
//------------------------------------------------------------------------------

void printInfo()
{
centerText("Testing");
centerText("This program tests sorting algorithms by using them to sort a number",' ','|');
centerText("of elements 10 times and giving us the middle value of the time they use",' ','|');
centerText("*");
}

//------------------------------------------------------------------------------
// Main function. only call functions and print some info.
//------------------------------------------------------------------------------

int main()
{
	TestClass results;

	// Info for user.
	printInfo();

	test(results);
	writeToFile(results);

	cout << endl;
	centerText("Finished");
	return 0; 											
}
