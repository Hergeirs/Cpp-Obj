/*
  File:         Event.h
  Objective:    Definition of abstract class Event and derived concrete
                Event classes.
*/

#ifndef EVENT_H
#define EVENT_H

// Forward declarations
class Simulation;
class BurgerBar;

class Event {
public:
    // Constructor requires time of event
    Event (unsigned int t) : time(t) { }

    virtual ~Event() { }

    // Process event by invoking this method
    virtual void processEvent()=0;

    // Get time for this event
    unsigned int getTime() const {
        return time;
    }

protected:
    // Time for this event
    unsigned int time;
};



// Used to compare to Events with respect to time
class EventComparison {
public:
    bool operator() (Event * left, Event * right) {
        return left->getTime() > right->getTime();
    }
};

//--- Derived Event-classes ----------------------------------------------------

class ArriveEvent : public Event {
public:
    ArriveEvent (Simulation *sim, BurgerBar *bar, int time, int gs)
    : Event(time),theSim(sim),theBar(bar),groupSize(gs) { }

    virtual void processEvent();

protected:
    Simulation *theSim;
    BurgerBar *theBar;
    int groupSize;
};

class OrderEvent : public Event {
public:
    OrderEvent (Simulation *sim, BurgerBar *bar, int time, int nb)
    : Event(time),theSim(sim),theBar(bar),nBurgers(nb) { }

    virtual void processEvent();

protected:
    Simulation *theSim;
    BurgerBar *theBar;
    int nBurgers;
};



class ServiceEvent : public Event {
public:
    ServiceEvent(Simulation *sim, BurgerBar *bar, int time, int nb )
    :Event(time),theSim(sim),theBar(bar),nBurgers(nb) { }

    virtual void processEvent();

protected:
    Simulation *theSim;
    BurgerBar *theBar;
    int nBurgers;
};



class SeatedEvent : public Event {
public:
   SeatedEvent(Simulation *sim, BurgerBar *bar, int time, int np )
   :Event(time),theSim(sim),theBar(bar),nPeople(np) { }

   virtual void processEvent();

protected:
   Simulation *theSim;
   BurgerBar *theBar;
   int nPeople;
};


class LeaveEvent : public Event {
public:
    LeaveEvent (Simulation *sim, BurgerBar *bar, int time, int gs)
    :Event(time),theSim(sim),theBar(bar),groupSize(gs) { }

    virtual void processEvent();

protected:
    Simulation *theSim;
    BurgerBar *theBar;
    int groupSize;
};


class ClosingEvent : public Event {
public:
    ClosingEvent (Simulation *sim, BurgerBar *bar, int time)
    : Event(time),theSim(sim),theBar(bar) { }

    virtual void processEvent();

protected:
    Simulation *theSim;
    BurgerBar *theBar;

};



#endif

