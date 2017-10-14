#ifndef COACHH
#define COACHH

#include "Car.hpp"

class Coach: public Car
{
public:
    Coach(const unsigned int _id,const unsigned int param0,const unsigned int param1)
    :Car(_id,COACH,{{"number of chairs",param0,"pieces"},{"internet access",param1,""}}){} 
    virtual ~Coach(){}
};


#endif //COACH
