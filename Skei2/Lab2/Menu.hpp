#ifndef MENU
#define MENU

#include "MenuItem.hpp"
#include <vector>



class Menu
{
private:
	vector <MenuItem> menus;
	string menuTitle;


public:
	Menu();
	//~Menu();

	MenuItem & getMenuItem (int index);
	void setMenuTitle(string pMenuTitle);

	void addItem(string menuText,bool enabled);
	void printMenuItems() const;
	int getMenuChoice();

	void disable(size_t i);
	void enable(size_t i);
	void enableAll();
	void disableAll();
};


#endif
