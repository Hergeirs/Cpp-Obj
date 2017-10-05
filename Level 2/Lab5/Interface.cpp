#include "Interface.hpp"
#include "TestApp.hpp"

template <typename T>
void typeMain()
{
    //run temporary instantialization of TestApp with user defined type 
	TestApp<T>().run(); 
}

Interface::Interface()
{
    menu.setMenuTitle("Type choser");
	//menuItems 
	menu.addItem("integer",true);	// 1
	menu.addItem("double",true);	// 2
	menu.addItem("exit",true);		// 3
}

Interface::~Interface()
{
    //nothing
}

void Interface::run()
{
    //runing interface wrapper.
	bool again=true;
	while(again)
	{
		switch(menu.getMenuChoice())
		{
			case 1:
				typeMain<int>();
				break;
			case 2:
				typeMain<double>();	
				break;
			case 3:
				again=false;
			default:
				break; //won't reach over menuSize anyway
		}
	}
}