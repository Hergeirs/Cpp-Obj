#include "Simulation.hpp"
#include <iostream>
#include <queue>

int main()
{  
    try
    {
        Simulation().run(); 
    }
    catch (...)
    {
        return 0;
    }
}