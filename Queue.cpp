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

Queue::~Queue()
{
	delete[] queue;
	queue=NULL;
}

Song Queue::pop()
{
	if(last<0)
		return Song();
	Song returnA= *queue;
	++queue;
	--last;
	return returnA;
}


void Queue::expand(const unsigned int step)
{
	printPrompt("Expanding");
	queueSize+=5;
	Song * tmp = queue;
	queue = new Song[queueSize];
	for (unsigned int i=0;i<last+1;++i)
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

	int end = size();
	for (unsigned int i=0;i<end;++i)
	{
		centerText("currently playing: ", ' ',i+49);
		pop().print(i+1);
		this_thread::sleep_for(chrono::seconds(5)); // cross platform c++11
	}
}
