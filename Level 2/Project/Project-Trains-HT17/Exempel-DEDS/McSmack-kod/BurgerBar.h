/*
  File:         BurgerBar.h
  Objective:    Definition of class BurgerBar, the simulation target

*/

#ifndef BURGERBAR_H
#define BURGERBAR_H

#include "SimConst.h"

// Forward declaration
class Simulation;


class BurgerBar {

public:
   BurgerBar(Simulation *sim, int chairs);

   bool tryEnter (int nPeople);  // True if enough free chairs
   void order(int nBurgers);
   bool getChairs(int nPeople);  // True if enough free chairs
   void serve(int nBurgers);
   void leave(int nPeople);
   void closeDown();
   int getFreeChairs() const { return freeChairs; }
   float getProfit() { return profit; }

private:
   Simulation *theSim;
   int freeChairs;
   int nChairs; // Nr of chairs
   float profit;
};

#endif
