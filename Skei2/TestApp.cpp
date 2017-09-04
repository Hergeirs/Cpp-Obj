#include "TestApp.hpp"

TestApp::TestApp()
{
    menu.setMenuTitle("TestApp");
    menu.addItem("Create Queue",true);
    menu.addItem("Add to queue",false);
    menu.addItem("Remove from queue",false);
    menu.addItem("Quit",true);
}

void TestApp::run()
{
    bool quit=false;
    while(quit==false)
    {
        doMenuOption(menu.getMenuChoice());
    }
}

void TestApp::createQueue()
{
    printPrompt("Hello!");
}


void TestApp::doMenuOption(int option)
{
    switch(option)
    {
        case 1:
            createQueue();
            break;
        case 2:
            //enqueue();
            break;
        case 3:
            //dequeue();
            break;
        case 4:
            exit(1);
    }
}