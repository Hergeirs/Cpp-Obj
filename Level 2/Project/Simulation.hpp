#ifndef SIMULATIONH
#define SIMULATIONH

#include "TrainStation.hpp"
#include <list>

class Simulation
{
public:
	Simulation()
	:stations(new std::vector<std::unique_ptr<TrainStation>>()),trains(new std::vector<std::unique_ptr<Train>>()){}
	~Simulation(){}
	void run();
private:
	void round();
	void loadStations();
	void loadTrains();

	void printStations() const;
	
	const bool findStation(std::vector<std::unique_ptr<TrainStation>>::iterator & i,const std::string & name) const;
	std::unique_ptr<std::vector<std::unique_ptr<TrainStation>>> stations;
	std::unique_ptr<std::vector<std::unique_ptr<Train>>> trains;
};


#endif //SIMULATIONH
