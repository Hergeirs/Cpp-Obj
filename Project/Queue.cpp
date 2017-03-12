#include "Queue.hpp"

//------------------------------------------------------------------------------
// Constructor...
//------------------------------------------------------------------------------
Queue::Queue():queueSize(5)
{
	first=0;
	last=-1;
	queue = new Song[queueSize];
}

//------------------------------------------------------------------------------
// Destructor. Since address of queue array changes i can't use 'delete[]'
//------------------------------------------------------------------------------

Queue::~Queue()
{
	cout << "deleting Queue!" << endl;
	delete[] queue;
	queue = nullptr;
}

//------------------------------------------------------------------------------
// I chose not to delete the first element, but overwrite it. All memory will be
// deAllocated in the destructor anyway and array doesn't shrink at any time.
//------------------------------------------------------------------------------

Song Queue::pop()
{
	if(last<0)
		return Song();
	Song returnA= *queue;
	++first;
	moveDown();	//overwriting first slot.
	return returnA;
}

//------------------------------------------------------------------------------
// Moves all entries down to start at index 0. Sets last index accordingly
//------------------------------------------------------------------------------

void Queue::moveDown()
{
	for(int i=0;i+first<=last;++i)
		queue[i]=queue[first+i];
	last=last-first;
	first=0;
}

//------------------------------------------------------------------------------
// when size reaches maximum it expands by 5
//------------------------------------------------------------------------------

void Queue::expand()
{
	queueSize+=5;
	Song * tmp = queue;
	queue = new Song[queueSize];
	for (int i=0;i<last+1;++i)
		queue[i]=tmp[i];
	delete[] tmp;
}

//------------------------------------------------------------------------------
// Chose to use syntax push_back. As the function adds song to the back.
//------------------------------------------------------------------------------

void Queue::push_back(Song song)
{
	if (last+1==queueSize)
		expand();

	queue[++last]=song;
}

//------------------------------------------------------------------------------
// get amount of elements in queue
//------------------------------------------------------------------------------

const unsigned int Queue::size() const
{
	return last+1;
}

//------------------------------------------------------------------------------
// Returns true if queue is empty
//------------------------------------------------------------------------------

bool Queue::isEmpty()
{
	return last==-1;
}

//------------------------------------------------------------------------------
// Pop's all entries of list one at the time and "plays them" to terminal output
//------------------------------------------------------------------------------

void Queue::play()
{
	if(last!=-1)
		Song().print(0);
	for(unsigned int i = 1;last!=-1;++i)
	{
		pop().print(i);	// returns first element and deletes it
		this_thread::sleep_for(chrono::seconds(2)); // cross platform c++11 for singe threaded software
	}
}
