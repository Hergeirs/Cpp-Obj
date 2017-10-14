#include "Train.hpp"

const unsigned int & Train::getId() const
{
    return id;
}

const std::vector<CarType> & Train::getRequiredCarTypes() const
{
    return requiredCarTypes;  
}

const std::vector<std::list<CarInfo>> Train::getCarInfo() const
{ 
    std::vector<std::list<CarInfo>> carInfos;
    for (auto & car: *cars)
    {
        carInfos.push_back(car->getInfo());
    } 
    return carInfos;
}  

void Train::setState(const TrainState _state)
{
    state=_state;
}

void Train::addCar(std::unique_ptr<Car> &i) 
{
    if(cars->size()==requiredCarTypes.size())
        state=ASSEMBLED;
    else
        state=INCOMPLETE;
        
    cars->push_back(std::move(i));
}

const TrainState &Train::getState() const
{
    return state;
}
