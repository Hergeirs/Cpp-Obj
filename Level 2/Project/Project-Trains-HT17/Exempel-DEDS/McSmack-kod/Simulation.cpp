/*
  File:         Simulation.cpp
  Objective:    Implementation of class Simulation

*/


#include "Simulation.h"
#include "Event.h"

// Execute events until event queue is empty
void Simulation::run(){
    while(!eventQueue.empty()) {
        Event * nextEvent = eventQueue.top();
        eventQueue.pop();
        currentTime = nextEvent->getTime();
        nextEvent->processEvent();
        delete nextEvent;
    }
}


void Simulation::scheduleEvent (Event * newEvent) {
    eventQueue.push (newEvent);
}
