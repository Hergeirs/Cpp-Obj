#ifndef MENU
#define MENU

#include "MenuItem.hpp"



class Menu
{
private:
	vector <MenuItem> menus;
	string menuTitle;


public:
	Menu();
	~Menu();

	const string & getMenuTitle() const;
	MenuItem & getMenuItem (int index);
	void setMenuTitle(string pMenuTitle);

	void addItem(string menuText,bool enabled);
	void printMenuItems();
	int getMenuChoice();

	void disable(size_t i);
	void enable(size_t i);
	void enableAll();
};


#endif
