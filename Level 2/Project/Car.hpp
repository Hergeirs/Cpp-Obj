#ifndef CARH
#define CARH

#include <string>
#include <vector>
#include <list>
#include <map>

struct CarInfo
{
public:
	CarInfo(const std::string _label, const unsigned int _capacity,const std::string _unit)
	:label(_label),capacity(_capacity),unit(_unit){}
	
	std::string label;
	unsigned int capacity;
	std::string unit;
};

enum CarType
{
	COACH,
	SLEEPING,
	OPEN_FREIGHT,
	COVERED_FREIGHT,
	ELECTRICAL_ENGINE,
	DIESEL_ENGINE
};

class Car
{
public:
	virtual ~Car(){};
	const std::string getTypeText() const;	
	const unsigned int & getId() const; 
	const CarType &getType() const;	
	const std::list<CarInfo> & getInfo() const;
	Car(const unsigned int _id, const CarType _type, const std::list<CarInfo> _info)
	:type(_type),id(_id),info(_info){}

protected:
private:
	const CarType type;
	const unsigned int id;
	const std::list<CarInfo> info;	
};


#endif //CARH
