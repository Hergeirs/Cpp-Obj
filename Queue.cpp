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
// Destructor. Since adress of queue array changes i can't use 'delete[]'
//------------------------------------------------------------------------------


Queue::~Queue()
{
	cout << "deleting Queue!" << endl;
	delete[] queue;
	queue=NULL;
}

// Song Queue::pop()
// {
// 	if(last<0)
// 		return Song();
// 	Song returnA= *queue;
// 	Song * temp=queue;
// 	++queue;
	//delete temp;
// 	temp=NULL;
// 	--last;
// 	return returnA;
// }

Song Queue::pop()
{
	if(last<0)
		return Song();
	Song returnA= *queue;
	++first;
	moveDown();	//overwriting first slot.
	return returnA;
}

void Queue::moveDown()
{
	for(int i=0;i+first<=last;++i)
		queue[i]=queue[first+i];
	last=last-first;
	first=0;
}


void Queue::expand(const unsigned int step)
{
	cout << "expanding"<< endl;
	queueSize+=5;
	Song * tmp = queue;
	queue = new Song[queueSize];
	for (int i=0;i<last+1;++i)
		queue[i]=tmp[i];
	delete[] tmp;
}

void Queue::push_back(Song song)
{
	if (last+1==queueSize)
		expand();

	queue[++last]=song;
}

const unsigned int Queue::size() const
{
	return last+1;
}

bool Queue::isEmpty()
{
	return last==-1;
}

void Queue::play()
{

	unsigned int i=0;

	while(last!=-1)
	{
		pop().print(++i);
		//this_thread::sleep_for(chrono::seconds(5)); // cross platform c++11
	}
}
