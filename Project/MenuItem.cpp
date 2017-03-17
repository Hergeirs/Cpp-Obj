#include "MenuItem.hpp"

//------------------------------------------------------------------------------
// Center menu choices with index at the sides(almost the same as centerText below)
//------------------------------------------------------------------------------

void centerMenuItem(string input, char fill, char edge, int index, int padding,size_t width)
{
	cout << right << setfill(fill);
	width+=7;
	for (int tp=0 ;input.size()<width && tp < padding; ++tp)
	{
		input.push_back(' '); // right padding has priority

		if (input.size()+1 < width)
			input.insert(0,1,' ');
	}

	uint totalPadding = width-input.size();
	cout << edge << index;
	cout << setw((totalPadding/2)+input.size()-1) << input;
	cout << setw(float(totalPadding-float(totalPadding/2))-1) << index << edge << endl;
	cout << setfill(' ');
}


//------------------------------------------------------------------------------
// Default constructor
//------------------------------------------------------------------------------

MenuItem::MenuItem(string & pMenuText,bool pEnabled)
{
	menuText=pMenuText;
	enabled=pEnabled;
}

MenuItem::~MenuItem()
{
	//
}

//------------------------------------------------------------------------------
// Returns Menuitem label as string
//------------------------------------------------------------------------------

const string & MenuItem::getMenuText() const
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
