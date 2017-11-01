#include "Train.hpp"



//returns Id of train
const unsigned int &Train::getId() const
{
	return id;
}

//returns vector containing the cartypes nessecary to assemble train
const std::vector<CarType> &Train::getRequiredCarTypes() const
{
	return requiredCarTypes;  
}

//returs info about all cars in train
const std::vector<std::list<CarInfo>> Train::getCarInfo() const
{ 
	std::vector<std::list<CarInfo>> carInfos;
	for (auto &car: *cars)
	{
		carInfos.push_back(car->getInfo());
	} 
	return carInfos;
}  

//sets state of train
void Train::setState(const TrainState _state)
{
	state=_state;
}

//moves the ownership of input car from the station to the Train
void Train::addCar(std::unique_ptr<Car> &i) 
{   
	//cars->push_back(std::move(i));
	state = cars->size()!=requiredCarTypes.size() ? INCOMPLETE : ASSEMBLED;

}

const bool Train::moveCar(std::unique_ptr<Car> & car)
{
	if(cars->size()>0)
	{
		//car.reset(std::move(&*cars->back())); 
		cars->pop_back();
		return true;
	}
	return false;
}

//returns state.
const TrainState &Train::getState() const
{
	return state;
}

//returns actual departTime of train
const Time Train::getDepartTime() const
{
	return departTime+delay;
}

//returns actual ArriveTime of train
const Time Train::getArriveTime() const
{
	return arriveTime+delay;
}

const Time &Train::getDelay() const
{
	return delay;
}
void Train::addDelay(const Time _delay) 
{
	delay = delay+_delay;
}

const std::unique_ptr<TrainStation> &Train::getDepartStation() const
{
	return departStation;
} 

const std::unique_ptr<TrainStation> &Train::getArriveStation() const
{
	return arriveStation;
} 