# include "Car.hpp"

const std::string Car::getTypeText() const
{
    std::string retur;
    switch(type)
    {
        case COACH:
            retur = "Coach";
            break;
        case SLEEPING:
            retur = "Sleeping";
            break;
        case OPEN_FREIGHT:
            retur = "Open Freight";
            break;
        case COVERED_FREIGHT:
            retur = "Covered Freight";
            break;
        case ELECTRICAL_ENGINE:
            retur = "Electrical Engine";
            break;
        case DIESEL_ENGINE:
            retur = "Diesel Engine";
            break;
    }
    return retur;
}

const unsigned int & Car::getId() const
{
    return id;
}

const std::list<CarInfo> & Car::getInfo() const
{
    return info;
}

const CarType &Car::getType() const 
{
    return type;
}
