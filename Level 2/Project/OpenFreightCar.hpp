#ifndef OPENFREIGHTCARH
#define OPENFREIGHTCARH

#include "Car.hpp"

class OpenFreightCar: public Car
{
public:
    OpenFreightCar(const unsigned int _id,const unsigned int param0,const unsigned int param1)
    :Car(_id,OPEN_FREIGHT,{{"Cargo Capacity",param0,"ton"},{"Floor area",param1,"m^2"}}){}
    virtual ~OpenFreightCar(){}   
};


#endif //OPENFREIGHTCARH