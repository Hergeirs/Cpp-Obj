#include "Menu.hpp"

//------------------------------------------------------------------------------
// Default constructor initializes menus as empty std::vector with MenuItem dataType
//------------------------------------------------------------------------------
//   Precondition: -
//   Postcondition: empty Menu object is created
Menu::Menu()
:menus(std::vector <MenuItem> ())
{
	//
}

//   Precondition:  Menu object must exist.
//   Postcondition:  Menu object is deleted from memory.
/*Menu::~Menu()
{
	// nothing to do here...
}*/

//------------------------------------------------------------------------------
// setMenuTitle used for setting name
//------------------------------------------------------------------------------
//   Precondition: -
//   Postcondition:  menu title set.
void Menu:: setMenuTitle(std::string pMenuTitle)
{
	menuTitle=pMenuTitle;
}

//------------------------------------------------------------------------------
// adds menuItem to menu list takes bool to set enabled state.
//------------------------------------------------------------------------------
//   Precondition:  -
//   Postcondition:  menu option i is created.
void Menu:: addItem(std::string menuText,bool enabled)
{
	MenuItem menuItem(menuText,enabled);
	menus.push_back(menuItem);
}



//------------------------------------------------------------------------------
// Prints all enabled menuitems in menu.
//------------------------------------------------------------------------------
//   Precondition:  -.
//   Postcondition:  prints all menuItem titles in a fasionable manner.
void Menu::printMenuItems() const
{
	int a=0;
	size_t longest=0;
	for (auto t:menus)
		if (t.getState() && longest < t.getMenuText().size())
			longest = t.getMenuText().size();
	longest = std::max(longest,menuTitle.size());
	
	int padding = 0;
	printPrompt(menuTitle,"Menu",false,false,longest);
	centerText("",'_','.',padding,longest);
	centerText("choices",'_','|',1,longest);	
	centerText("",' ','|',padding,longest);	
	for (auto i: menus)
		i.print(++a,longest,padding);
	centerText("",'_','|',padding,longest);	

}

//------------------------------------------------------------------------------
// Function to choice from user. Restricts choices to enabled menuitems
//------------------------------------------------------------------------------
//   Precondition:  i is valid integer choice for enabled menuItem.
//   Postcondition:  menu option i is returned.
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
//   Precondition:  i <= menuItems.size() -- just enter menu option number.
//   Postcondition:  menu option i is enabled.
void Menu::enable(size_t i)
{
	menus[--i].enable();
}

//------------------------------------------------------------------------------
// disables menuchoice nr i
//------------------------------------------------------------------------------
//   Precondition:  i <= menuItems.size() -- just enter menu option number.
//   Postcondition:  menu option i is disabled.
void Menu::disable(size_t i)
{
	menus[--i].disable();
}

//------------------------------------------------------------------------------
// enables all menuitems
//------------------------------------------------------------------------------
//   Precondition:  i <= menuItems.size()
//   Postcondition:  All menuoptions are visible.
void Menu::enableAll()
{
	for (auto & i: menus)
		i.enable();
}


//------------------------------------------------------------------------------
// enables all menuitems
//------------------------------------------------------------------------------
//   Precondition:  i <= menuItems.size()
//   Postcondition:  All menuoptions are hidden.
void Menu::disableAll()
{
	for (auto & i: menus)
	i.disable();
	menus[menus.size()-1].enable(); //quitting must always be possible
}