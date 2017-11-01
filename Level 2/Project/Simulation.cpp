#include "Simulation.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>

Simulation::Simulation(const Time startTime)
:time(startTime),events()
{
	//
} 

void Simulation::run ()
{
	Time simulationTime = Time("00:00");
	do
	{
		do
		{
			std::cout << "SIMULATION TIME: " << simulationTime << std::endl;
			auto top= events.top();
			events.pop();
			top.process();
		} while (events.top().getTime()<=simulationTime);
		std::cin.get();
		simulationTime += Time("00:10");
	} while (simulationTime>Time("00:00"));
}

void Simulation::scheduleEvent (Event * newEvent) 
{ 
    events.emplace(newEvent);
}

const Time& Simulation::getTime() const
{
	return time;
}

void Simulation::advanceTime(const Time _time)
{
	time = time+_time;
}