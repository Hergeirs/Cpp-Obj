#include "Queue.hpp"
#include "Functions.hpp"
#include<initializer_list>

//------------------------------------------------------------------------------
// Default constructor. Using quickassign for array so I won't need temp unique_ptr.
//------------------------------------------------------------------------------
//   Precondition: -
//   Postcondition: Queue object with user specified capacity will be created.
Queue::Queue(size_t size)
:queue(new int[size]),maxElem(size)
{
	head=0;	 // first element in array.
	tail=-1; // starting with -1 removes a special case in enqueue.
	nElem=0; // nElem keeps track of amount of integers in array.
}

//------------------------------------------------------------------------------
// Function to insert integer to back of queue.
//------------------------------------------------------------------------------
//   Precondition: queue must not be full.
//   Postcondition: integer will be added to back of queue.
void Queue::enqueue(const Type elem)
{		
	if (!full()) //if queue is not full
	{
		tail = (tail+1)%maxElem;
		queue[tail]=elem;	//inserting element in back of queue.
		++nElem;				//incrementing number of elements.
	}
}

//------------------------------------------------------------------------------
// Function to get integer from front of queue.
//------------------------------------------------------------------------------
//   Precondition: queue must not be empty.
//   Postcondition: integer will be taken from front of queue.
void Queue::dequeue(Type &elem)
{
	if(!empty())
	{
		elem=queue[head];
		if ((head+1)<maxElem)
		{
			++head;
		}
		else
		{
			head=0;
		}
		--nElem;
	}
}

//------------------------------------------------------------------------------
// Function to get amount of elements currently in queue.
//------------------------------------------------------------------------------
//   Precondition: -
//   Postcondition: returns amount of elements in queue.
const int Queue::length() const
{
	return nElem;
}

//------------------------------------------------------------------------------
// Function to check wether queue is full.
//------------------------------------------------------------------------------
//   Precondition: -
//   Postcondition: returns true if queue is full. Otherwise returns false.
const bool Queue::full() const
{
	return (nElem == maxElem);
}

//------------------------------------------------------------------------------
// Function to check wether queue is empty.
//------------------------------------------------------------------------------
//   Precondition: -
//   Postcondition: returns true if queue is empty. Otherwise returns false.
const bool Queue::empty() const
{
	return (nElem==0);
}

//------------------------------------------------------------------------------
// Function to get max capacity of current queue.
//------------------------------------------------------------------------------
//   Precondition: -
//   Postcondition: returns max capacity of current queue.
const int Queue::capacity() const
{
	return maxElem;
}