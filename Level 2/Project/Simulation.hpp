#ifndef SIMULATIONH
#define SIMULATIONH

#include "Event.hpp"
#include <queue>
#include <memory>
 
//forward declaring to save compilation time

class Simulation
{
public:
	Simulation(const Time startTime = Time(0));
	~Simulation(){}
	void scheduleEvent(std::unique_ptr<Event> &&newEvent);
	const Time & getTime() const;
	void advanceTime(const Time _time=Time("00:10"));
	void run();
	
private:
	Time time;
	std::priority_queue<std::unique_ptr<Event>,std::vector<std::unique_ptr<Event>>> events;
};


#endif //SIMULATIONH
