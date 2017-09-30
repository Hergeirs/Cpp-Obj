#include "TestApp.hpp"
#include <iostream>

TestApp::TestApp()
{

}

TestApp::~TestApp()
{

}

void TestApp::run()
{
	unsigned int amount=0,rangeAmount=0;
	double value=0,sum=0,avg=0;
	bool again=true;
	while (again)
	{
		try
		{
			again = filter.getNextValue(value);
		}
		catch(std::range_error)
		{
			++rangeAmount; // counting the errors
			continue;
		}
		sum+=value;
		++amount; 
	}
	avg=sum/amount; // implicit conversation from unsigned int to double

	std::cout << "numeric values        : " << amount << std::endl;
	std::cout << "Value outside interval: " << rangeAmount << std::endl;
	std::cout << "Total                 : " << sum << std::endl;
	std::cout << "Average               : " << avg << std::endl;
}