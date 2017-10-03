#include "TestApp.hpp"
int main()
{
	std::unique_ptr<DummyBaseClass> test;

	//creating menu.    
	Menu menu;
	menu.setMenuTitle("Type choser");
	//menuItems
	menu.addItem("integer",true);
	menu.addItem("double",true);
	menu.addItem("exit",true);

	while(true)
	{
		switch(menu.getMenuChoice())
		{
			case 1:

				test.reset(new TestApp<int>);
				break;
			case 2:

				test.reset(new TestApp<double>);
				break;
			case 3:
				return 0;
			default:
				break; //won't reach over menuSize anyway
		}
		if (test!=nullptr)
			test->run();
	}
	return 0;
}