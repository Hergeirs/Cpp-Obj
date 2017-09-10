#include "TestApp.hpp"

//------------------------------------------------------------------------------
// Constructor for TestApp object
//------------------------------------------------------------------------------
//   Precondition: -
//   Postcondition: initializes TestApp object and It's Menu objects MenuItems
TestApp::TestApp(size_t pSize):size(pSize)
{
	menu.setMenuTitle("TestApp");
	menu.addItem("Create new queue",true);
	menu.addItem("Add to queue",false);
	menu.addItem("Take from queue",false);
	menu.addItem("Check if queue is empty",false);
	menu.addItem("Check if queue is full",false);
	menu.addItem("Show number of elements contained in queue",false);
	menu.addItem("Show maximum capacity of current queue",false);
	menu.addItem("Quit",true);
}

//------------------------------------------------------------------------------
// Function to create dynamic Queue object with user specified size.
//------------------------------------------------------------------------------
//   Precondition: -
//   Postcondition: initializes queue unique_ptr with Queue object of user specified size.
void TestApp::createQueue()
{
	int size;
	do
	{
		getInt(size,"enter queue size (must be more than 1): ");
	} while (size<1); 	//a size under 1 is illegal and doesn't make sense (defensive programming)

	std::unique_ptr <Queue> temp(new Queue(size));
	queue = std::move(temp);
}


//------------------------------------------------------------------------------
// Shows and excecutes menuItems
//------------------------------------------------------------------------------
//   Precondition: -
//   Postcondition: runs user interface
void TestApp::run()
{
	bool quit=false;
	while(quit==false)
	{
		quit=doMenuOption(menu.getMenuChoice());
	}
}

//------------------------------------------------------------------------------
// Function to ask user for integer to put in queue
//------------------------------------------------------------------------------
//   Precondition: Queue mustn't be full.
//   Postcondition: inserts integer in back of queue.
void TestApp::enqueue()
{
	if (!(queue->full()))
	{
		int a;
		getInt(a,"Give number for queue: ");	
		queue->enqueue(a);
	}
	else
	{
		printPrompt("queue full.");
	}
}

//------------------------------------------------------------------------------
// function to take "oldest" element in queue and print it on screen
//------------------------------------------------------------------------------
//   Precondition: queue mustn't be empty.
//   Postcondition: prints next element in queue and deletes it from queue.
void TestApp::dequeue()
{
	if(!queue->empty())
	{
		int a;
		queue->dequeue(a);
		printPrompt(to_string(a),"Number dequeued:");
	}
	else
	{
		printPrompt("queue empty.");
	}
}


//------------------------------------------------------------------------------
// Function Prints wether queue if currently empty.
//------------------------------------------------------------------------------
//   Precondition: -
//   Postcondition: Prints wether queue if currently empty.
void TestApp::empty() const
{
	string s = "";
	if (!queue->empty())
	{
		s="not ";
	}
	printPrompt("Queue is "+s+"empty","empty");
}

//------------------------------------------------------------------------------
// Function Prints wether queue if currently full.
//------------------------------------------------------------------------------
//   Precondition: -
//   Postcondition: Prints wether queue if currently full.
void TestApp::full() const
{
	string s = "";
	if (!queue->full())
	{
		s="not ";
	}
	printPrompt("Queue is "+s+"full","full");
}

//------------------------------------------------------------------------------
// Function Prints amount of elements currently in queue.
//------------------------------------------------------------------------------
//   Precondition: -
//   Postcondition: Prints amount of elements currently in queue..
void TestApp::nrElements() const
{
	printPrompt("Elements currently in queue: "+to_string(queue->length()));
}

//------------------------------------------------------------------------------
// Function Prints max capacity of current queue.
//------------------------------------------------------------------------------
//   Precondition: -
//   Postcondition: Prints max capacity of current queue.
void TestApp::capacity() const
{
	printPrompt("maximum capacity: "+to_string(queue->capacity()));
}


//------------------------------------------------------------------------------
// Function Prints max capacity of current queue.
//------------------------------------------------------------------------------
//   Precondition: menuobtion must exist
//   Postcondition: calls function from menu with integer.
bool TestApp::doMenuOption(const int option)
{
	switch(option)
	{
		case 1:
			createQueue();
			menu.enableAll();
			break;
		case 2:
			enqueue();
			break;
		case 3:
			dequeue();
			break;
		case 4:
			empty();
			break;
		case 5:
			full();
			break;
		case 6:
			nrElements();
			break;
		case 7:
			capacity();
			break;
		case 8:
			return true;
	}
	return false;
}