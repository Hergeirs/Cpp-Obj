#include "TrainsSimulation.hpp"
#include <iostream>
#include <queue>



int main()
{

    std::unique_ptr<TrainsSimulation> sim = std::make_unique<TrainsSimulation>();
    std::cout << "continuing..." << std::endl;
    try
    {
        std::cout << "loading..." << std::endl; 
        sim->load();
        std::cout << "running..." << std::endl;
        sim->run();
    }
    catch (...)
    {
        std::cout << "An unhandled error occurred!" << std::endl;
        return 1;
    }
    return 0;
}