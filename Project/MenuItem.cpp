#include "MenuItem.hpp"

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
