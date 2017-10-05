#ifndef INTERFACEH
#define INTERFACEH
#include "Menu.hpp"


// function to run instance of TestApp with specified type
class Interface
{
    public:
        Interface();
        ~Interface();
        void run();
    private:
        Menu menu;
};

#endif