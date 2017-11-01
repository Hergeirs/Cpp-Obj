#ifndef TRAINSSIMULATIONH
#define TRAINSSIMULATIONH
#include "TrainStation.hpp"
#include "Simulation.hpp"

#include <memory>
#include <vector>

class TrainsSimulation
{
public:
	TrainsSimulation();
	~TrainsSimulation(){}
	
	void run();
	void load();
	const bool findStation(std::vector<std::unique_ptr<TrainStation>>::iterator & i,const std::string & name) const;
protected:
	void loadTrains();
	void loadStations();
	void printStations() const;
	std::unique_ptr<std::vector<std::unique_ptr<TrainStation>>> stations;
	std::unique_ptr<std::vector<std::unique_ptr<Train>>> trainsEnRoute;
	Simulation simulation;

	
};



#endif