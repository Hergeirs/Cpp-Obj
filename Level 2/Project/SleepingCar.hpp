#ifndef SLEEPINGCARH
#define SLEEPINGCARH

#include "Car.hpp"

class SleepingCar: public Car
{
public:
	SleepingCar(const unsigned int _id,const unsigned int param0) 
	:Car(_id,COACH,{{"number of beds",param0,"pieces"}}){}
	virtual ~SleepingCar(){}
};

#endif //SLEEPINGCARH
