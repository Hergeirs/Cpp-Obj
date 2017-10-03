#include "TestApp.hpp"

// sorry for the bloated main. only way i could think of to do this neatly.
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
	bool again=true;
	while(again)
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
				again=false;
			default:
				break; //won't reach over menuSize anyway
		}
		if (test!=nullptr && again == true)
			test->run();
		test.reset();
	}
	return 0;
}