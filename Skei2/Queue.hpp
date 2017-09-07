#ifndef QUEUE
#define QUEUE

#include <memory>
#include <iostream>

typedef int Type;
const int QSIZE = 10;

class Queue
{
	private:
		std::unique_ptr<int[]> smartPtr;
		int head;
		int tail;
		int nElem;
		int maxElem;
	public:
		Queue(int size = QSIZE);

		void enqueue(Type elem);

		void dequeue(Type &elem);
		
		int length() const;

		bool full() const;
		
		bool empty() const;

		int capacity() const;

		void print() const;

		void printStatus() const;
		void printStraight() const;

};

#endif