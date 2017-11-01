#ifndef EVENTH
#define EVENTH 
#include "Time.hpp"
#include "TrainStation.hpp"
#include <queue>

class Simulation;

const Time DELAY_TIME = Time("00:10"); //constant delay interval is 10 minutes.

class Event
{
public:
	Event(Simulation &_simulation,std::vector<std::unique_ptr<Train>>::iterator &_trainIt)
	:simulation(_simulation),trainIt(_trainIt),train(*trainIt)
	{
		//
	}
	virtual ~Event()=default;
	const bool operator < (const Event &b) const;
	const bool operator > (const Event &b) const;
	const bool operator < (const std::unique_ptr<Event> &b) const;
	virtual const Time &getTime() const;
	
	virtual void process()=0;
protected:
	Simulation &simulation;
	std::vector<std::unique_ptr<Train>>::iterator trainIt;
	const std::unique_ptr<Train> &train;
	Time time;
};

class Assembly: public Event
{
public:
	Assembly(Simulation& _simulation,std::vector<std::unique_ptr<Train>>::iterator& _trainIt)
	:Event(_simulation,_trainIt)
	{
		time = train->getDepartTime()-Time("00:30");	//assembly happens 30 mins before departure
	}

	virtual ~Assembly(){};

	virtual void process() override;
};

class Ready: public Event
{
public:
	Ready(Simulation& _simulation,std::vector<std::unique_ptr<Train>>::iterator& _trainIt)
	:Event(_simulation,_trainIt)
	{
		time = train->getDepartTime()-Time("00:10");
	}

	virtual ~Ready()=default;

	virtual void process() override;
};


class Departure: public Event
{
public:
	Departure(Simulation& _simulation,std::vector<std::unique_ptr<Train>>::iterator& _trainIt)
	:Event(_simulation,_trainIt)
	{
		time = train->getDepartTime();
	}

	virtual ~Departure()=default;

	virtual void process() override;
};

class Arrival: public Event
{
public:
	Arrival(Simulation& _simulation,std::vector<std::unique_ptr<Train>>::iterator& _trainIt)
	:Event(_simulation,_trainIt)
	{
		time = train->getArriveTime();
		train->getDepartStation()->moveTrain(trainIt,runningTrain);
	}

	virtual ~Arrival()=default;

	virtual void process() override;

private:
	std::unique_ptr<Train> runningTrain;		//saving the running trainIts in events until arrival	
};

class Disassmbly: public Event
{
public:
	Disassmbly(Simulation& _simulation,std::vector<std::unique_ptr<Train>>::iterator& _trainIt)
	:Event(_simulation,_trainIt)
	{
		time=train->getArriveTime()+Time("00:20");
	}

	virtual void process() override;    
};

#endif //EVENTH