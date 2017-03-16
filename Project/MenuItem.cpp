#include "MenuItem.hpp"

MenuItem::MenuItem(string & pMenuText,bool pEnabled)
{
	menuText=pMenuText;
	enabled=pEnabled;
}

MenuItem::~MenuItem()
{
	//
}

const string & MenuItem::getMenuText() const
{
	return menuText;
}

const bool MenuItem::getState() const
{
	return enabled;
}

void MenuItem::setMenuText(string & pMenuText)
{
	menuText=pMenuText;
}

void MenuItem::toggle()
{
	if (enabled !=true)
		enabled=true;
	else
		enabled=false;
}

void MenuItem::print(int a,size_t width, size_t padding) const
{
	if(enabled)
	{
		centerMenuItem (menuText,'_','|',a,1,width);
	}
}

void MenuItem::enable()
{
	enabled=true;
}

void MenuItem::disable()
{
	enabled=false;
}
