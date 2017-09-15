#include "MenuItem.hpp"

#include <iostream>
#include <iomanip>

int amountNumbers(int i)
{
	if(i==0)
	{
		return 0;
	}
	return 1+amountNumbers(i/10);
}

//------------------------------------------------------------------------------
// Center menu choices with index at the sides(almost the same as centerText below)
//------------------------------------------------------------------------------

void centerMenuItem(std::string input, char fill, char edge, int index, int padding,size_t width)
{
	std::cout << std::right << std::setfill(fill);
	width+=7;
	for (int tp=0 ;input.size()<width && tp < padding; ++tp)
	{
		input.push_back(' '); // std::right padding has priority

		if (input.size()+1 < width)
			input.insert(0,1,' ');
	}

	int leftPad,rightPad;
	
	rightPad=amountNumbers(index);
	if (amountNumbers(index)%2!=0)
		leftPad=rightPad;
	else 
		leftPad=rightPad-1;

	uint totalPadding = width-input.size();
	std::cout << edge << index;
	std::cout << std::setw((totalPadding/2)+input.size()-rightPad)<< input;
	std::cout << std::setw(float(totalPadding-float(totalPadding/2))-leftPad) << index << edge << std::endl;
	std::cout << std::setfill(' ');
}


//------------------------------------------------------------------------------
// Default constructor
//------------------------------------------------------------------------------

MenuItem::MenuItem(std::string & pMenuText,bool pEnabled)
{
	menuText=pMenuText;
	enabled=pEnabled;
}

/*MenuItem::~MenuItem()
{
	//
}
*/
//------------------------------------------------------------------------------
// Returns Menuitem label as std::string
//------------------------------------------------------------------------------

const std::string & MenuItem::getMenuText() const
{
	return menuText;
}

//------------------------------------------------------------------------------
// Returns true if menuitem is anbled and false otherwise
//------------------------------------------------------------------------------

const bool MenuItem::getState() const
{
	return enabled;
}

//------------------------------------------------------------------------------
// print function to "this" menuitem
//------------------------------------------------------------------------------

void MenuItem::print(int a,size_t width, size_t padding) const
{
	if(enabled)
		centerMenuItem (menuText,'_','|',a,1,width);
}

//------------------------------------------------------------------------------
// Enables "this" menuitem
//------------------------------------------------------------------------------

void MenuItem::enable()
{
	enabled=true;
}

//------------------------------------------------------------------------------
// Disables "this" menuitem
//------------------------------------------------------------------------------

void MenuItem::disable()
{
	enabled=false;
}
