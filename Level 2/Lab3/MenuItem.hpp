#ifndef MENUITEM
#define MENUITEM
#include "Functions.hpp"

class MenuItem
{
	private:
	std::string menuText;
	bool enabled;

	public:
	MenuItem(std::string & pMenuText,bool pEnabled);
	//~MenuItem();
	const std::string & getMenuText() const;
	const bool getState() const;
	void print(int b,size_t width=42,size_t padding=0) const;

	void enable();
	void disable();

};

#endif
