#ifndef QUEUE
#define QUEUE
#include "../PersonClass/PersonClass.hpp"


typedef Person Item;

struct Result
{
	int index=-1;
	Item item;
};

class Node;
class QIterator
{
private:
	Node *node;
public:
	QIterator();				// Default constructor
	QIterator(Node *n);			// Initiation Constructor

	Item &operator*() const;

	QIterator &operator++();		// prefix ++i
	QIterator operator++(int); 	// postfix i++
	bool operator!=(const QIterator &qi) const;
};


//---------------------------------------------------------------------------
class QList
{
private:
	Node *first, *last;
public:
	QList():first(0),last(0) {};
	~QList();
	void enque(Item item);
	bool deque(Item &item);
	bool del(Item item);
	bool isEmpty()const;
	Result search (string persNr);

	QIterator begin()const {
		return QIterator(first);
	}
	QIterator end()const {
		return QIterator(0);
	}
};

#endif
