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

class TrainStation;

class Train
{
public:
    Train(const unsigned int &_id, const std::unique_ptr<TrainStation> &_departStation, const std::unique_ptr<TrainStation> &_arriveStation, const Time &_departTime,const Time &_arriveTime, const std::vector<CarType> &_requiredCars)
    :id(_id),state(NOT_ASSEMBLED),requiredCarTypes(_requiredCars),cars(new std::vector<std::unique_ptr<Car>>()),departStation(_departStation),arriveStation(_arriveStation),departTime(_departTime),arriveTime(_arriveTime),delay(0)
    { }
    const unsigned int &getId() const;
    const std::vector<CarType> &getRequiredCarTypes() const;
    void addCar(std::unique_ptr<Car> &car);
    const bool moveCar(std::unique_ptr<Car> & car); //takes car and it's ownership to parameter unique_ptr
    const TrainState &getState() const;
    const std::vector<std::list<CarInfo>> getCarInfo() const;
    void setState(const TrainState);
    const Time getDepartTime() const;
    const Time getArriveTime() const;
    const Time &getDelay() const;
    void addDelay(const Time = Time("00:10"));
    const std::unique_ptr<TrainStation> &getDepartStation() const;
    const std::unique_ptr<TrainStation> &getArriveStation() const;
protected:
    const unsigned id;
    TrainState state;
    const std::vector<CarType> requiredCarTypes;
    std::unique_ptr<std::vector<std::unique_ptr<Car>>> cars;
    
    const std::unique_ptr<TrainStation> &departStation;    
    const std::unique_ptr<TrainStation> &arriveStation;
    const Time departTime;        //expected depart and arrivetimes.
    const Time arriveTime;
    Time delay;
};

#endif // !TRAINH