#ifndef TRAINSTATIONH
#define TRAINSTATIONH

#include "Train.hpp"

class TrainStation
{
public:
	TrainStation(const std::string _name)
	:name(_name),cars(new std::vector<std::unique_ptr<Car>>()),trains(new std::vector<std::unique_ptr<Train>>())
	{
		//
	}
	
	virtual ~TrainStation()
	{
		//unique pointers take care of its
	}


	void addTrain(const unsigned int _id, const std::unique_ptr<TrainStation> &_fromStation, const std::unique_ptr<TrainStation> &_toStation, const Time _departTime,const Time _arriveTime,const std::vector<CarType> _types);
	void addCar(const unsigned int &id, const CarType &type,const unsigned int &param0, const unsigned int &param1);

	const std::string &getName() const;
	const bool getAvailableCars(std::unique_ptr<Train> &train, std::vector<std::unique_ptr<Car>> & _cars) const;
	const bool findCar(std::unique_ptr<Car> &find,const CarType &type) const;
	void buildAvailable();
	
	void assemble(std::vector<std::unique_ptr<Train>>::iterator &train) const;	
	//const bool assemble(std::unique_ptr<Train> &a) const;

	const std::unique_ptr<std::vector<std::unique_ptr<Train>>> &getTrains() const;
	void buildTrain(std::unique_ptr<Train> &train, std::vector<std::unique_ptr<Car>> &_cars);
	const bool getNotCompleteTrain(std::unique_ptr<Train> &i, std::unique_ptr<Train> &found) const;
	void disassemble(std::vector<std::unique_ptr<Train>>::iterator &trainIt);
	void moveTrain(std::vector<std::unique_ptr<Train>>::iterator & trainIt,std::unique_ptr<Train> & train);
	std::vector<std::unique_ptr<Train>>::iterator receiveTrain(std::unique_ptr<Train> & train);
private:
	const std::string name;
	std::unique_ptr<std::vector<std::unique_ptr<Car>>> cars;
	std::unique_ptr<std::vector<std::unique_ptr<Train>>> trains;
};


#endif //TRAINSTATIONH
