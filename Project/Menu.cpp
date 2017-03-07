#include "Menu.hpp"

Menu::Menu()
{
	menues = vector <MenuItem> ();
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
	return menues[index];
}

void Menu:: setMenuTitle(string pMenuTitle)
{
	menuTitle=pMenuTitle;
}

void Menu:: addItem(string menuText,bool enabled)
{
	MenuItem menuItem(menuText,enabled);
	menues.push_back(menuItem);
}

void Menu::printMenuItems()
{
int a=0;
printPrompt(menuTitle,"Menu",false,false);
	for (auto i: menues)
			i.print(++a);
}

int Menu::getMenuChoice()
{
		int i;
		cls();
		printMenuItems();
		while(((i=getInt("your Choice: ")) && (i<1)) || (i>int(menues.size()) || menues[i-1].getState()==false))
		{
			printPrompt("Not valid choice!");
			printMenuItems();
		}

	return i;
}

void Menu::toggle(int i)
{
	menues[--i].toggle();
}


void Menu::enableAll()
{
	for (uint i=0;i<menues.size();++i) // for some reason c++11 auto loop did not work here...
	{
		menues[i].enable();
	}
}
