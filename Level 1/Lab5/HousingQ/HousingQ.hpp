#ifndef HOUSINGQ
#define HOUSINGQ
#include "../Queue/queue.hpp"

class HousingQ
{
	private:
	QList queue;
	int queueSize;
	string fileName;
	void loadData();
	void saveData();
	void addPerson();
	void menu();
	void offerResidence();
	void print() const;
	void search();
	void deleteNode();

	public:
	HousingQ():queueSize(0) {};
	void run();
};

#endif
