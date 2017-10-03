#ifndef LISTMANIPULATORH
#define LISTMANIPULATORH


#include <algorithm>
#include <random>
#include <list>
#include <ctime>
#include <functional>
#include <memory>

template<typename T>
class ListManipulator
{
public:
	ListManipulator(std::list<T> *aList=new std::list<T>(20,0));
	//~ListManipulator();
	void randomFill(); // fill List with amount of random values
	T sumList() const;
	T avgList() const;
	bool findFirst1500_1900(T &num) const;
	void divideBy2();
	void swapPlaces();		// could just use std::reverse. but not following description
	void findMinMax(T &min, T &max) const;
	void sortList();
	void clearList();
	std::list<T> getList() const;
	void saveToFile() const;
	void readFromFile();
private:
	std::unique_ptr<std::list<T>> theList;	

	static T randomGenerator();	// would want the same for every instance (increased randomness)
};


#endif //LISTMANIPULATORH
