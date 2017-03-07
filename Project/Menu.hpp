#ifndef MENU
#define MENU

#include "MenuItem.hpp"



class Menu
{
private:
	vector <MenuItem> menues;
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
	void toggle(int i);
	void enableAll();
};


#endif
