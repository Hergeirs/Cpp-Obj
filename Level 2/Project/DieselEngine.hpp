#ifndef DIESELENGINEH
#define DIESELENGINEH


#include "Car.hpp"

#include <vector>

class DieselEngine: public Car
{
public:
    DieselEngine(const unsigned int _id,const unsigned int param0,const unsigned int param1)
    :Car(_id,DIESEL_ENGINE,{{"Max Speed",param0,"km/h"},{"Fuel Consumption",param1,"l/h"}}){}
    virtual ~DieselEngine(){}
};

#endif //DIESELENGINEH