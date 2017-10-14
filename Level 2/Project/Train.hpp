#ifndef TRAINH
#define TRAINH

#include <memory>
#include "Car.hpp"
#include "Time.hpp"

#include "DieselEngine.hpp"
#include "ElectricalEngine.hpp"
#include "Coach.hpp"
#include "SleepingCar.hpp"
#include "OpenFreightCar.hpp"
#include "CoveredFreightCar.hpp" 

enum TrainState
{
    NOT_ASSEMBLED,
    INCOMPLETE,
    ASSEMBLED,
    READY,
    RUNNING,
    ARRIVED,
    FINISHED
};

class Train
{
public:
    Train(const unsigned int &_id, const std::string &_fromStation, const std::string &_toStation, const Time &_departTime,const Time &_arriveTime, const std::vector<CarType> &_requiredCars)
    :id(_id),state(NOT_ASSEMBLED),requiredCarTypes(_requiredCars),cars(new std::vector<std::unique_ptr<Car>>()),fromStation(_fromStation),toStation(_toStation),departTime(_departTime),arriveTime(_arriveTime)
    { }
    const unsigned int & getId() const;
    const std::vector<CarType> & getRequiredCarTypes() const;
    void addCar(std::unique_ptr<Car> &car);
    const TrainState & getState() const;
    const std::vector<std::list<CarInfo>> getCarInfo() const;
    void setState(const TrainState);
protected:
    const unsigned id;
    TrainState state;
    const std::vector<CarType> requiredCarTypes;
    std::unique_ptr<std::vector<std::unique_ptr<Car>>> cars;
    
    std::string fromStation;
    std::string toStation;
    Time departTime;
    Time arriveTime;
};

#endif // !TRAINH