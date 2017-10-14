#ifndef ELECTRICALENGINEH
#define ELECTRICALENGINEH

#include "Car.hpp"

class ElectricalEngine: public Car
{
public:
    ElectricalEngine(const unsigned int _id,const unsigned int param0,const unsigned int param1)
    :Car(_id,ELECTRICAL_ENGINE,{{"Max Speed",param0,"km/h"},{"Power",param1,"kw"}}){}
    virtual ~ElectricalEngine(){}
};

#endif // !ELECTRICALENGINEH