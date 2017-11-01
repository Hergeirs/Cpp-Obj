/*
  File:         McSmackSim.cpp
  Objective:    Main program for McSmack BurgerBar simulation

*/

#include <iostream>
#include "BurgerBar.h"
#include "Simulation.h"
#include "RandomInt.h"

using std::cout;
using std::endl;
using std::cin;

int main(int argc, char* argv[])
{
  vector<float> profits(40,0.0);

  for(int i=0;i<40;++i) {
    int chairs = i+1;

    cout << chairs << " chairs" << endl;
    Simulation *theSim = new Simulation;
    BurgerBar *theBar = new BurgerBar(theSim,chairs);

    // Load eventqueue with a number of initial arrival events
    int simTime = 0; // Simulation time starts at time 0
    int groupSz;

    while (simTime < SIM_TIME) {

       // Advance simulation time some random minutes...
       simTime += randBetween(MIN_ARRIVAL_DELAY,MAX_ARRIVAL_DELAY);

       // Decide size of group to arrive
       groupSz= randBetween(MIN_GRP_SIZE,MAX_GRP_SIZE);

       if(simTime>=SIM_TIME) // Schedule a new arrival
          theSim->scheduleEvent(new ClosingEvent(theSim,theBar,SIM_TIME));
       else
          // Schedule the close down
          theSim->scheduleEvent(new ArriveEvent(theSim,theBar,simTime,groupSz));
    }

    // Run simulation and get profits!
    theSim->run();

    profits[i] = theBar->getProfit();

    cout << "Chairs: " << (i+1) << " Profit: " <<  theBar->getProfit() << endl;


    delete theSim;
    delete theBar;
  }

  for(int i=0; i<40; ++i) {
    cout << i+1 << ": profit " << profits[i] << endl;
  }

  return 0;
}


