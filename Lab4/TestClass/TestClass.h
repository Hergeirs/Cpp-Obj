// TestClass.h
// Headarafíla
// Hergeir
// 
//------------------------------------------------------------------------------
#ifndef TESTCLASS
#define TESTCLASS
#include "../Timer/Timer.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

enum Algorithm // Enum for sorting algorithm used. 
{
	NONE,
	bubbleSort,
	bubbleSort2,
	selectionSort,
	insertSort,
	quickSort,
	quickSort2,
	Sort,
	END,
};

struct Result	// struct to contain results.
{
	Algorithm algorithm;
	unsigned int elementAmount;
	long double averageTime;
	Result(Algorithm dalgorithm,unsigned int amount,long double daverageTime)
	{
		algorithm=dalgorithm;
		elementAmount=amount;
		averageTime=daverageTime;
	}
};

class TestClass	// Class to calculate, store and write out test-results
{

private:
	vector <Result> testResults; 

public:	

	TestClass(){testResults={};}		// default constructor.
	const inline vector <Result> & getResults() const;	// Used to write vector to file.
	void addResult(long double averageTime,const unsigned int amount,Algorithm & algorithm); // Used to make add a result to the vector. 
};

	const ostream & operator << (ostream & os,const TestClass & results); // Just to simplify things

	const string & getLabel(const Algorithm & algorithm);					// Don't have time to move.


#endif
