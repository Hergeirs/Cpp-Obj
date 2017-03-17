#include "Menu.hpp"

//------------------------------------------------------------------------------
// Default constructor initializes menus as empty vector with MenuItem dataType
//------------------------------------------------------------------------------

Menu::Menu()
{
	menus = vector <MenuItem> ();
}

Menu::~Menu()
{
	// nothing to do here...
}

//------------------------------------------------------------------------------
// setMenuTitle used for setting name
//------------------------------------------------------------------------------

void Menu:: setMenuTitle(string pMenuTitle)
{
	menuTitle=pMenuTitle;
}

//------------------------------------------------------------------------------
// adds menuItem to menu list takes bool to set enabled state.
//------------------------------------------------------------------------------

void Menu:: addItem(string menuText,bool enabled)
{
	MenuItem menuItem(menuText,enabled);
	menus.push_back(menuItem);
}

//------------------------------------------------------------------------------
// Prints all enabled menuitems in menu.
//------------------------------------------------------------------------------

void Menu::printMenuItems()
{
	int a=0;
	size_t longest=0;
	for (auto t:menus)
		if (t.getState() && longest < t.getMenuText().size())
			longest = t.getMenuText().size();
	longest = max(longest,menuTitle.size());

	printPrompt(menuTitle,"Menu",false,false,longest);
	centerText("",'_','.',0,longest);
	centerText("choices",'_','|',1,longest);	
	centerText("",' ','|',0,longest);	
	for (auto i: menus)
		i.print(++a,longest);
	centerText("",'_','|',0,longest);	

}

//------------------------------------------------------------------------------
// Function to choice from user. Restricts choices to enabled menuitems
//------------------------------------------------------------------------------

int Menu::getMenuChoice()
{
	int i;
	cls();
	printMenuItems();
	// while loop ensures i only get enabled menus and valid menu-choices from user
	while(((i=getInt("your Choice: ")) && (i<1)) || (i>int(menus.size()) || menus[i-1].getState()==false))
	{
		printPrompt("Not valid choice!");
		cls();
		printMenuItems();
	}
	cls();
	return i;
}

//------------------------------------------------------------------------------
// enables menuchoice nr i
//------------------------------------------------------------------------------

void Menu::enable(size_t i)
{
	menus[--i].enable();
}

//------------------------------------------------------------------------------
// disables menuchoice nr i
//------------------------------------------------------------------------------

void Menu::disable(size_t i)
{
	menus[--i].disable();
}

//------------------------------------------------------------------------------
// enables all menuitems
//------------------------------------------------------------------------------

void Menu::enableAll()
{
	for (auto & i: menus)
		i.enable();
}