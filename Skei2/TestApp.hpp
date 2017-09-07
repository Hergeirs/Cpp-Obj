#ifndef TESTAPP
#define TESTAPP

#include "Menu.hpp"
#include "Queue.hpp"
#include <memory>

class TestApp {
private:
	//smart pointer object to hold the dynamically Queue object  
    unique_ptr <Queue> queue;
	
	const size_t size;
// Main menu
    Menu menu;

    void doMenuOption(int option); //contains switch to call menuoptions

// Menu-options
	void createQueue(); //creates dynamic queue object
	void enqueue();		//puts element in queueObject
	void dequeue();		//takes element from queueObject
	void empty() const;	//prints wether queue is empty
	void full() const;	//prints wether queue is full
	void nrElements() const;	//prints number of elements in queue
	void capacity() const;		//prints capacity of current array
	void printQueue() const;	//prints the queue.
public:
	TestApp(size_t size=10);
	void run();
};

#endif