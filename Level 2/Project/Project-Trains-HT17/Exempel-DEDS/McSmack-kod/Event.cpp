/*
  File:         Event.cpp
  Objective:    Implementations

*/

#include "Event.h"
#include "RandomInt.h"
#include "BurgerBar.h"
#include "Simulation.h"

void ArriveEvent::processEvent()
{
    if (theBar->tryEnter(groupSize)) {
           Event *e = new OrderEvent(theSim,theBar,theSim->getTime()
                        + randBetween(MIN_ORDER_WAIT,MAX_ORDER_WAIT), groupSize);
           theSim->scheduleEvent(e);
    }
}

void OrderEvent::processEvent()
{
    theBar->order(nBurgers * BURGERS_PER_PERSON);
    int t = theSim->getTime() + randBetween(MIN_SERVICE_WAIT,MAX_SERVICE_WAIT);

    // Schedule service in a few minutes..
    Event *e = new ServiceEvent(theSim,theBar,t, nBurgers);
    theSim->scheduleEvent(e);
}

void ServiceEvent::processEvent()
{
    theBar->serve(nBurgers);
    // Schedule group to be seated in a minute
    int now = theSim->getTime();
    Event *e = new SeatedEvent(theSim,theBar,now + SEAT_SEARCH_TIME,nBurgers);
    theSim->scheduleEvent(e);
}


void SeatedEvent::processEvent()
{
    int now = theSim->getTime();

    // Try to find chairs
    if(!theBar->getChairs(nPeople)) {
       // Reschedule a SeatedEvent
       int t = now + SEAT_SEARCH_TIME;
       Event *e = new SeatedEvent(theSim,theBar,t, nPeople);
       theSim->scheduleEvent(e);
    }
    else { // Got the chairs
         // Schedule leave
        int t = now + randBetween(MIN_EATING_TIME,MAX_EATING_TIME);
        Event *e = new LeaveEvent(theSim,theBar,t, nPeople);
        theSim->scheduleEvent(e);
    }
}


void LeaveEvent::processEvent() {
    theBar->leave(groupSize);
}

void ClosingEvent::processEvent() {
    theBar->closeDown();
}






