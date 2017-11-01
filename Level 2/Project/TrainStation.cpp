#include "TrainStation.hpp"
#include <algorithm>
#include <iostream>

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////// Function to add car to train only used when loading from file //////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void TrainStation::addCar(const unsigned int &id, const CarType &type, const unsigned int &param0, const unsigned int &param1=0)
{
	switch(type)
	{
		case COACH:
			cars->push_back(std::make_unique<Coach>(Coach(id,param0,param1)));           
			break;
		case SLEEPING:
			cars->push_back(std::make_unique<SleepingCar>(SleepingCar(id,param0))); 
			break;
		case OPEN_FREIGHT:
			cars->push_back(std::make_unique<OpenFreightCar>(OpenFreightCar(id,param0,param1))); 
			break;
		case COVERED_FREIGHT:
			cars->push_back(std::make_unique<CoveredFreightCar>(CoveredFreightCar(id,param0)));              
			break;
		case ELECTRICAL_ENGINE:
			cars->push_back(std::make_unique<ElectricalEngine>(ElectricalEngine(id,param0,param1)));             
			break; 
		case DIESEL_ENGINE:
			cars->push_back(std::make_unique<DieselEngine>(DieselEngine(id,param0,param1)));             
			break;
	}
}

void TrainStation::addTrain(const unsigned int _id, const std::unique_ptr<TrainStation> &_fromStation, const std::unique_ptr<TrainStation> &_toStation, const Time _departTime,const Time _arriveTime,const std::vector<CarType> _types)
{
	trains->push_back(std::make_unique<Train>(Train(_id, _fromStation, _toStation, _departTime, _arriveTime,_types)));
}
 
void TrainStation::disassemble(std::vector<std::unique_ptr<Train>>::iterator &trainIt)
{
	std::unique_ptr<Car> car;
	while((*trainIt)->moveCar(car))
	{
		cars->push_back(std::move(car));
	}
}

void TrainStation::moveTrain(std::vector<std::unique_ptr<Train>>::iterator & trainIt,std::unique_ptr<Train> & train)
{ 
	train = std::move((*trainIt));	//moving ownership of train to passed in unique_ptr
	trains->erase(trainIt);			//erasing now empty unique_ptr
}

std::vector<std::unique_ptr<Train>>::iterator TrainStation::receiveTrain(std::unique_ptr<Train> & train)
{
	trains->push_back(std::move(train));
	return --trains->end();			//return iterator to last element
}

const std::unique_ptr<std::vector<std::unique_ptr<Train>>> &TrainStation::getTrains() const
{ 
	return trains;  
}

const std::string &TrainStation::getName() const
{
	return name;
}


void TrainStation::assemble(std::vector<std::unique_ptr<Train>>::iterator &train) const 
{
	for (auto &carType: (*train)->getRequiredCarTypes())
	{
		auto found = std::find_if(cars->begin(),cars->end(),[&carType](const std::unique_ptr<Car> &car){return carType==car->getType();});
		if(found != cars->end())
		{
			(*train)->addCar(*found);
			cars->erase(found);			//erasing the now null pointer from vector 
		}
	}
}

