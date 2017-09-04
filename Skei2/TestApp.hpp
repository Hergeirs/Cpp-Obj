#ifndef TESTAPP
#define TESTAPP

#include "Menu.hpp"
#include <memory>

class TestApp {
private:
	//smart pointer object to hold the dynamically Queue object
	bool done;
// Main menu
    Menu menu;
    void doMenuOption(int option);
// Menu-alternativ
	void createQueue();
	void enqueue();
	void dequeue();
	void isEmpty() const;
	void isFull() const;
	void nrElements() const;
public:
	TestApp();
	void run();
};

#endif