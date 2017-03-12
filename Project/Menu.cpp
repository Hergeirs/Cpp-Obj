#include "Menu.hpp"

Menu::Menu()
{
	menus = vector <MenuItem> ();
	//menuTitle=pMainTitle;
}

Menu::~Menu()
{
	//
}

const string & Menu::getMenuTitle() const
{
	return menuTitle;
}

MenuItem & Menu::getMenuItem(int index)
{
	return menus[index];
}

void Menu:: setMenuTitle(string pMenuTitle)
{
	menuTitle=pMenuTitle;
}

void Menu:: addItem(string menuText,bool enabled)
{
	MenuItem menuItem(menuText,enabled);
	menus.push_back(menuItem);
}

void Menu::printMenuItems()
{
int a=0;
printPrompt(menuTitle,"Menu",false,false,35);
	for (auto i: menus)
	{
		i.print(++a);
	}
}

int Menu::getMenuChoice()
{
		int i;
		cls();
		printMenuItems();
		// while loop ensures i only get enabled menus and valid menu-choices from user
		while(((i=getInt("your Choice: ")) && (i<1)) || (i>int(menus.size()) || menus[i-1].getState()==false))
		{
			printPrompt("Not valid choice!");
			printMenuItems();
		}
		cls();
	return i;
}

void Menu::enable(size_t i)
{
	menus[--i].enable();
}

void Menu::disable(size_t i)
{
	menus[--i].disable();
}

void Menu::enableAll()
{
	for (uint i=0;i<menus.size();++i) // for some reason c++11 auto loop did not work here...
	{
		menus[i].enable();
	}
}
