#ifndef TESTAPPH
#define TESTAPPH

#include "DummyBaseClass.hpp"

#include "Menu.hpp"
#include "ListManipulator.hpp"
#include <memory>

template<typename T>
class TestApp : public DummyBaseClass
{
public:
	TestApp();
	//~TestApp();
	virtual void run() override;
private:
	std::unique_ptr<ListManipulator<T>> theList;
//menu-implementation
	Menu menu;
	const bool doMenuChoice(const int choice);

//menu-options  
	void fillList();
	void getSum() const; 
	void getAvg() const;
	void getNumberBetween1500and1900() const;
	void divideBy2();
	void swapPlaces();
	void getMinMax() const;
	void sortList();
	void clearList();
	void writeToFile() const;
	void loadFromFile();
	void printNumbers() const;
	//quit
};


#endif