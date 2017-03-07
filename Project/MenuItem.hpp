#ifndef MENUITEM
#define MENUITEM
#include "Functions.hpp"

class MenuItem
{
	private:
	string menuText;
	bool enabled;

	public:
	MenuItem(string & pMenuText,bool pEnabled);
	~MenuItem();
	const string & getMenuText() const;
	const bool getState() const;
	void setMenuText(string & pMenuText);
	void print(int b) const;

	void toggle();
	void enable();
	void disable();

};

#endif
