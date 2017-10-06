#ifndef INTERFACEH
#define INTERFACEH
#include "Menu.hpp"
#include "TestApp.hpp"
#include <memory>


// function to run instance of TestApp with specified type
class Interface
{
    public:
        Interface();
        ~Interface();
        void run();
    private:
        void loadFromFile();
        Menu menu;
};

#endif