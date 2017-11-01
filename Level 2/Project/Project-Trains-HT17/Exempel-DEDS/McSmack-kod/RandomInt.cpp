/*
  File:         RandomInt.cpp
  Objective:    Implementation of RandomInt and randBetween

*/
#include <ctime>
#include <cstdlib>
#include "RandomInt.h"


RandomInt * RandomInt::inst = 0;
RandomInt::RandomInt() {
    std::srand(std::time(0));
}

RandomInt* RandomInt::instance() {
    if(inst==0)
        inst = new RandomInt;
    return inst;
}

int RandomInt::getRandInt(int max) {
    int rval = std::rand();  // rand returns random integer
    return rval % (max+1);   // take remainder to put in range
}

int randBetween(int low, int high) {
    return low + RandomInt::instance()->getRandInt(high - low);

}
