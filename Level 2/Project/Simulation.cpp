#include "Simulation.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include "TrainStation.hpp"

void Simulation::run()
{
	loadStations();
	loadTrains();	
	
	round();
} 

void Simulation::round()
{
	for (auto &station: *stations)
	{
		station->round();
	}
}

const bool Simulation::findStation(std::vector<std::unique_ptr<TrainStation>>::iterator & i,const std::string & name) const
{
	i = std::find_if(stations->begin(),stations->end(),[&name](const std::unique_ptr<TrainStation> &t){return t->getName()==name;});
	return i!=stations->end();
}

bool getCar(std::istream &is, std::vector<unsigned int> &params)
{	
	params.clear();
	unsigned int param;
	std::string discard, keep;
	if(!getline(is,discard,'(') || !getline(is,keep,')'))
	{
		return false;
	}
	std::istringstream stream(keep);
	while(stream >> param)
	{
		params.push_back(param);
	}
	return true;
}


void Simulation::loadTrains()
{
	std::ifstream is("Trains.txt");
	if(is)
	{
		unsigned int id,type,maxSpeed;
		std::vector<CarType> carTypes;
		std::string from, to,params,line;
		Time departTime,arriveTime; 
		while(std::getline(is,line))
		{
			std::istringstream stream(line);
			stream >> id >> from >> to >> departTime >> arriveTime >> maxSpeed;
			carTypes.clear();
			while(stream >> type)
			{
				carTypes.push_back(static_cast<CarType>(type));
			}
			std::vector<std::unique_ptr<TrainStation>>::iterator i;
			if(findStation(i,from))
			{
				(*i)->addTrain(id,from,to,departTime,arriveTime,carTypes);
			}
		}
	}
}

void Simulation::printStations() const
{
	for (auto &station: *stations)
	{
		std::cout << "Station: " << station->getName() << std::endl;
		for (auto &train: station->getTrains())
		{
			std::cout << "Train: " << train->getId() << std::endl;
			std::cout << "Required Cars:" << std::endl;			
			unsigned int i=0;			
			for(auto &car: train->getRequiredCarTypes())
			std::cout << ++i << ": " << car << std::endl;
		}
	}
}

void Simulation::loadStations()
{
	std::ifstream is("TrainStations.txt");
	if(is)
	{
		std::string name;
		std::string car;
		std::string line;
		std::vector<unsigned int> params;
		std::unique_ptr<TrainStation> station;
		while (is >> name)
		{			
			station.reset(new TrainStation(name));
			
			std::string line;
			getline(is,line);
			std::istringstream stream(line);
			
			while(getCar(stream,params))
			{
				unsigned int id,_type,param0,param1=0;
				for(size_t i=0; i<params.size(); ++i)
				{
					switch(i)
					{
						case 0:
							id = params[i];
							break;	
						case 1:
							_type = params[i];
							break;
						case 2:
							param0 = params[i];
							break;
						case 3:
							param1 = params[i];
							break;
						default:
							throw std::runtime_error("To many params !");
					}
				}				
				station->addCar(id,static_cast<CarType>(_type),param0, param1);
			}
			stations->push_back(std::move(station));			
		}
	}

}