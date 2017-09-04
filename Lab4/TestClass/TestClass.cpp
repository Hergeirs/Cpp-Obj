#include "TestClass.h"
const string & getLabel(const Algorithm & algorithm)
{
	static string s;
	switch(algorithm)
	{
	case bubbleSort:
		s = "BubbleSort";
	break;
	case bubbleSort2:
		s = "BubbleSort2";
	break;
	case selectionSort:
		s = "SelectionSort";
	break;
	case insertSort:
		s = "InsertionSort";
	break;
	case quickSort:
		s = "QuickSort";
	break;
	case quickSort2:
		s = "QuickSort2";
	break;
		case Sort:
		s = "default sort";
	break;
	default:
	s = "Exteeeerrminaate!!!";
	break;
	}
	return s;
}

void TestClass::addResult(long double averageTime, unsigned int amount, Algorithm & algorithm)
{
	Result result(algorithm,amount,averageTime);
	testResults.push_back(result);
}

const inline vector <Result> & TestClass::getResults() const
{
	return testResults;
}

const ostream & operator << (ostream & os,const TestClass & results)
{
	os << "Algorithm used" << char(9) << "Elements in array" << char(9) << "Average runningtime [s]" << endl;
	for (auto r: results.getResults())
	{
		os << getLabel(r.algorithm) << char(9) << r.elementAmount << char(9) << r.averageTime/1000000 << endl;
	}

}
