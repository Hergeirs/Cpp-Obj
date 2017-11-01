/*
  File:         RandomInt.h
  Objective:    Provide Singleton class RandomInt used by function randBetween

*/

#ifndef RANDOMINT_H
#define RANDOMINT_H

class RandomInt {
public:
    static RandomInt* instance(); // Singleton
    int getRandInt(int);

private:
    RandomInt();
    static RandomInt *inst;
};

// Returns a random int �n interval [low, high] (inclusive)
int randBetween(int low, int high);

#endif
