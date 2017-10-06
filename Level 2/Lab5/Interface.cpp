#include "Interface.hpp"
#include "TestApp.hpp"
#include <fstream>
#include <typeinfo>


template <typename T>
void runMain()
{
    //run temporary instantialization of TestApp with user defined type 
	TestApp<T>().run(); 
}


template <typename T>
void loadRun()
{
    TestApp<T>().loadFromFile().run();  // loading list into Testapp and running it
}

Interface::Interface()
{
    menu.setMenuTitle("Type choser");
	//menuItems 
	menu.addItem("integer",true);	        // 1
    menu.addItem("double",true);	        // 2
    menu.addItem("load from file",true);    // 3
	menu.addItem("exit",true);		        // 4
}

Interface::~Interface()
{
    //nothing
}
 
// loading from file
void Interface::loadFromFile()
{
    std::ifstream is("list.dat");
    char type;
    is >> type;
    if (type==*typeid(int).name()) // check for filtype
    {
        loadRun<int>();             //run apropriate run function.
    }
    else if(type==*typeid(double).name())
    {
        loadRun<double>();
    }
    else
    {
        printPrompt("ERROR TYPE IN FILE","ERROR");
    }

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
				runMain<int>();
				break;
			case 2:
				runMain<double>();	
				break;
            case 3:
                loadFromFile();
                break;
            case 4:
				again=false;
			default:
				break; //won't reach over menuSize anyway
		}
	}
}