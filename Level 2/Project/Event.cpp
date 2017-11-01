#include "Event.hpp"
#include <iostream>
#include "Simulation.hpp"

const bool Event::operator < (const Event &b) const
{
	return time<b.time;
}

const bool Event::operator > (const Event &b) const
{
	return time>b.time;
}

const Time & Event::getTime() const
{
	return time;
}


void Assembly::process()
{ 
	std::cout << time << " ";
	train->getDepartStation()->assemble(trainIt);
	if(train->getState()!=ASSEMBLED)
	{
		train->addDelay();		
		std::cout << "Train " << train->getId() <<  " delayed at " << train->getDepartStation()->getName() << "!" << " new departTime: " << train->getDepartTime() << std::endl;		
		simulation.scheduleEvent(new Assembly(*this));
	}
	else 
	{
		std::cout << "Train " << train->getId() <<  " assembled at " << train->getDepartStation()->getName() << "!"<< " departTime: " << train->getDepartTime() << std::endl;		
		simulation.scheduleEvent(new Ready(simulation,trainIt));
	}
	delete this;
}

void Ready::process()
{
	train->setState(READY);
	simulation.scheduleEvent(new Departure(simulation,trainIt));
	std::cout << "Train " << train->getId() << " is born ready " <<  train->getArriveStation()->getName() << std::endl;
}

void Departure::process()
{
	std::cout << time << " ";
	train->setState(RUNNING);
	simulation.scheduleEvent(new Arrival(simulation,trainIt));
	std::cout << "Train " << train->getId() << " departed for " <<  train->getArriveStation()->getName() << std::endl;
}

void Arrival::process()
{
	std::cout << time << " ";
	train->setState(ARRIVED);
	trainIt=train->getArriveStation()->receiveTrain(runningTrain); //setting iterator to correct element
	simulation.scheduleEvent(new Disassmbly(simulation,trainIt));
	std::cout << "Train " << train->getId() << " arrived at " <<  train->getArriveStation()->getName() << std::endl;
}

void Disassmbly::process()
{
	std::cout << time << " ";
	train->getArriveStation()->disassemble(trainIt); 
	train->setState(FINISHED);
	std::cout << "Train " << train->getId() << " disassembled at " <<  train->getArriveStation()->getName() << std::endl;
}





