#include "TestApp.hpp"
#include <iostream>

int main()
{
	try // just catching runtime error
	{
		TestApp app;
		app.run();
	}
	catch(std::runtime_error)
	{
		std::cout << "Application encountered an error and will exit gracefully" << std::endl;
		return 0;
	}
	return 0;
}