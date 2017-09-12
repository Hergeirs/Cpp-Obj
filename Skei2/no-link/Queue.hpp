#ifndef QUEUE
#define QUEUE

#include <memory>
#include <iostream>

typedef int Type;
const size_t QSIZE = 10;

class Queue
{
	private:
		std::unique_ptr<int[]> queue;
		
		int head;
		int tail;
		int nElem;
		const int maxElem;
	public:
		Queue(size_t size = QSIZE);
		void enqueue(const Type elem);  //queues integer
		void dequeue(Type &elem);		//de-queues integer
		
		const int length() const;		//returns length of queue
		const bool full() const;		//returns wether queue is full
		const bool empty() const;		//returns wether queue is empty
		const int capacity() const;		//returns size of array

};

#endif