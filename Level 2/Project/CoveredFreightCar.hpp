#ifndef COVEREDFREIGHTCARH
#define COVEREDFREIGHTCARH

#include "Car.hpp"

class CoveredFreightCar: public Car
{
public:
    CoveredFreightCar(const unsigned int _id,const unsigned int param0,const unsigned int param1=0)
    :Car(_id,COVERED_FREIGHT,{{"Cargo Capacity",param0,"m^3"}}){}
    virtual ~CoveredFreightCar(){}
private:
    
};


#endif //OPENFREIGHTCARH
