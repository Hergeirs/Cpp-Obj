#include "Queue.hpp"
#include "Functions.hpp"


//------------------------------------------------------------------------------
// Default constructor. Using quickassign for array so I won't need temp unique_ptr.
//------------------------------------------------------------------------------
//   Precondition: -
//   Postcondition: Queue object with user specified capacity will be created.
Queue::Queue(int size)
:smartPtr(new int[size])
{
	maxElem=size;
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
		if((tail+1)<maxElem) // if 'circulation' isn't needed
		{	
			++tail;
		}
		else	//'circulation' occurs
		{
			tail=0;
		}
		smartPtr[tail]=elem;	//inserting element in back of queue.
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
		elem=smartPtr[head];
		if ((head+1)<maxElem && std::cout << "hello!" << std::endl)
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

/*
int Queue::length() const
{
	int len;
	if(head > tail)
	{
		len = (maxElem-1)-(head-tail);
	}
	else
	{
		len = tail-head+1;
	}
	return len;
}
*/
/*
bool Queue::full() const
{
	bool full;
	if(std::cout << "hello" << std::endl && head > tail && std::cout << "hello" << std::endl)
	{
		full = (head-tail==1);
	}
	else
	{
		full = (tail-head+1==maxElem);
	}
	return full;
}
*/

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

//------------------------------------------------------------------------------
// Only used for stats "debugging"
//------------------------------------------------------------------------------
//   Precondition: -
//   Postcondition: prints good stats.
void Queue::printStatus() const
{
	printStraight();
	for(int i=0; i<head; ++i)
	{
		std::cout << "  ";
	}
	std::cout << "H" << std::endl;
	for(int i=0; i<tail; ++i)
	{
		std::cout << "  ";
	}
	std::cout << "T" << std:: endl;
	std::cout << "head: " << head << std::endl;
	std::cout << "tail: " << tail << std::endl;
	std::cout << "nElem: " << nElem << std::endl;
	std::cout << "maxElem: " << maxElem << std::endl;
}

//------------------------------------------------------------------------------
// Function print elements in array exactly as they lie in it.
//------------------------------------------------------------------------------
//   Precondition: -
//   Postcondition: prints elements in array order by index.
void Queue::printStraight() const
{
	for (int i=0; i<maxElem;++i)
	{
		if ((i<head && i>tail) || (i<head && head<tail) || (i>tail && tail>head))
		{
			std::cout << "  ";
		}
		else
		{
			std::cout << smartPtr[i] << " ";
		}
	}
	std::cout << std::endl;
}

//------------------------------------------------------------------------------
// Function to get max capacity of current queue.
//------------------------------------------------------------------------------
//   Precondition: -
//   Postcondition: prints on screen elements in queue in right order.
void Queue::print() const
{
	if(!empty())
	{
		if(tail<head)
		{
			for(int i = head; i < maxElem; ++i)
			{
				std::cout << smartPtr[i] << " ";
			}
			for(int i = 0; i <= tail; ++i)
			{
				std::cout << smartPtr[i] << " ";
			}
		}
		else
		{
			for(int i=head; i<=tail; ++i)
			{
				std::cout << smartPtr[i] << " ";
			}
		}
		std::cout << std::endl;		
	}
	std::cout << std::endl;
}
