// VectorClass.h
// Headarafíla
// Hergeir
//
//------------------------------------------------------------------------------
#ifndef VECTORCLASS
#define VECTORCLASS
#include "Song.hpp"

#include <chrono> // used for waiting a few seconds before continuing.
#include <thread>

//------------------------------------------------------------------------------
// Queue class
//------------------------------------------------------------------------------


class Queue
{
private:

	Song * queue;				//Pointer for beginning of dynamic integer array would make const if i could.
	int first, last, queueSize;

	void moveDown();			// move all down.
	void expand(const unsigned int step=5);

public:

	Queue ();					//Constructor
	~Queue();					//Destructor.

	void push_back(Song song);
	Song pop();
	void play();

	bool isEmpty();

	const unsigned int size () const;
};


#endif
