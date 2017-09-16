// Defintionsfil
// Filnamn: queue.cpp
//-----------------------------------------------------------------------------
// Node class is placed in the cpp file to make it accessible ONLY for
// Classes QList and QIterator. In this way, data can be data members can be
// Public.

#include "queue.hpp"

//------------------------------------------------------------------------------
// Node Class definition
//------------------------------------------------------------------------------

class Node
{
public:
	Node *next;
	Item data;
	Node (Node *n, Item newData): next(n), data(newData) {}
};
// Fill with the function definitions of the member functions in QIterator
//and QList below!

//------------------------------------------------------------------------------
// QIterator Contstructors
//------------------------------------------------------------------------------

QIterator::QIterator()
{
	node=NULL;
}

QIterator::QIterator(Node *n)
{
	node=n;
}

//------------------------------------------------------------------------------
// Destructor.
//------------------------------------------------------------------------------

QList::~QList()
{
	while(first!=0)
	{
		Node *tmp = first;
		first = first->next;
		delete tmp;
	}
}

//------------------------------------------------------------------------------
// Overloading operators of QIterator class.
//------------------------------------------------------------------------------

Item & QIterator::operator*() const
{
	return node->data;
}

QIterator & QIterator::operator++()
{
	node=node->next;
	return *this;
}

QIterator QIterator::operator++(int)
{
	QIterator * tmp=this;
	node=node->next;
	return *tmp;
}

bool QIterator::operator!=(const QIterator &qi) const
{
	if (this->node==qi.node)
		return false;
	else
		return true;
}


//------------------------------------------------------------------------------
//**************************** QList	****************************************
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Adding person last in queue
//------------------------------------------------------------------------------

void QList::enque( Item item)
{
	cout << endl << "Checking if list is empty";
	if (isEmpty())
	{
		first = new Node(0,item);
		last = first;
	}
	else
	{
		last->next = new Node(0,item); 	// adding item to end.
		last = last->next;				//	moving last pointer to new last.
	}

}

//------------------------------------------------------------------------------
// Searching for person in list using string PersNR. Returning struct with
// queue number
//------------------------------------------------------------------------------

Result QList::search (string persNr)
{
	Result result;
	int n=1;
	for(QIterator i(first);i!=0;++i,++n)
	{
		if((*i).getPersNr()==persNr)
		{
			result.item=*i;
			result.index=n;
			return result;
		}
	}
	return result; // If not found respond with default constructed person.
}

//------------------------------------------------------------------------------
// I only use this function because tasked to make it. I would have deviced it
// together with a search function.
//------------------------------------------------------------------------------

bool QList::del(Item item)
{
		Node * p=NULL,*prev=NULL;
		if (first->data==item)	// If beginning of list.
		{
			p=first;
			first=first->next;	// move first pointer down.
			delete p;
			return true;
		}
		// anything in between firs and last element.
		for(p=first->next; p && !(p->data==item); p=p->next){prev=p;}
		prev->next=p->next;
		if (p==last)	// moving last pointer down if last element is removed
			last=prev;
		delete p;
return true;			//Never calling function with any item not in list....
}

//------------------------------------------------------------------------------
// Removing last item of queue and returning a bool along with the item into
// parameter.
//------------------------------------------------------------------------------

bool QList::deque(Item &item)
{
	if (isEmpty()){return false;}

	item = first->data;
	Node * tmp = first;
	first=first->next;
	delete tmp;
	return true;
}

//------------------------------------------------------------------------------
// Returns true if queue is empty.
//------------------------------------------------------------------------------

bool QList::isEmpty() const
{
	if (first==0){return true;}
	return false;
}
