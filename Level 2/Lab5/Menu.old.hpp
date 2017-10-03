#ifndef MENU
#define MENU

#include "MenuItem.hpp"
#include <vector>
#include <memory>



class Menu
{
private:
	std::unique_ptr<std::vector <MenuItem>> menus;
	std::string menuTitle;


public:
	Menu();
	~Menu()=default;

	MenuItem & getMenuItem (int index);
	void setMenuTitle(std::string pMenuTitle);

	void addItem(std::string menuText,bool enabled);
	void printMenuItems() const;
	int getMenuChoice();

	void disable(size_t i);
	void enable(size_t i);
	void enableAll();
	void disableAll();
};


#endif
