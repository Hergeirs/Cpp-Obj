#include "PersonListClass.h"

//------------------------------------------------------------------------------
// PersonList memberfunctions definitions.
//------------------------------------------------------------------------------
PersonList::PersonList()
{
	list = vector <Person> ();
	Person person("Kasef","aeoe","AEFMoseaf",240,"SAVEf","a550",200); // Maybe valid Person somewhere.
	list.push_back(person);
	person.setPersNr("a551");
	list.push_back(person); // adding two identical twins !
	person.setPersNr("a552");
	list.push_back(person);
}

//------------------------------------------------------------------------------
// Printing all persons and corresponding info.
//------------------------------------------------------------------------------

void PersonList::print(int stopAmount) const
{
	for (int a=1;a<list.size()+1;++a)
	{
		if ((a)%5==0)
		{
			systemPause(toString(list.size()-a)+" Remaining entries. \nPress enter to continue...");
			cls();
		}
		list[a-1].print();
	}
}



//------------------------------------------------------------------------------
// Get/Set of private variables
//------------------------------------------------------------------------------
Person& PersonList::getPerson(int n)
{
	return list[n];
}

const string PersonList::getFileName() const
{
	return fileName;
}


void PersonList::addPerson(Person & person)
{
	list.push_back(person);
}
void PersonList::setFileName(string &pFileName)
{
	fileName=pFileName;
}

int PersonList::size() const
{
	return list.size();
}

void PersonList::clear()
{
	list.clear();
}

void PersonList::readFromFile()
{
	ifstream os(fileName);	// only input from stream therefore ifstream.
	if (os.is_open())
	{
		os >> *this;		// had already overloaded '<<' && '>>'for PersonListClass	
	}
	else
	{
		printPrompt("File couldn't be opened for reading...");
		return;
	}
	printPrompt("Data was loaded from file: "+fileName);
	os.close();
}

void PersonList::writeToFile()
{
	ofstream os(fileName);
	
	if (os.is_open())
	{
		os << *this;	
	}
	else
	{
		printPrompt("File couldn't be opened/created for writing...");
		return;
	}
	printPrompt("Data was saved to file: "+fileName);
	os.close();
}


//------------------------------------------------------------------------------
// overloading operators for PersonList class. 
//------------------------------------------------------------------------------
const ostream & operator << (ostream & stream,PersonList & persons)
{
	for	(size_t i=0;i<persons.size();++i)
		stream << persons.getPerson(i);
	return stream;
}

const istream & operator >> (istream & stream, PersonList & persons)
{
	Person person;
	while (stream >> person)
	{
		persons.addPerson(person);
	}
	return stream;
} 

//------------------------------------------------------------------------------
// sort memberfunctions and boolean functions to use in algorithm::sort.
//------------------------------------------------------------------------------
void PersonList::sortName()
{
	sort(list.begin(),list.end());
}

bool ComparePersNr(Person &a, Person &b)
{
	return a.getPersNr()<b.getPersNr();
}

void PersonList::sortPersNr()
{
	sort(list.begin(),list.end(),ComparePersNr);
}

bool CompareSkoNr (Person &a, Person &b)
{
	return a.getSkoNr()<b.getSkoNr();
}

void PersonList::sortSkoNr()
{
	sort(list.begin(),list.end(),CompareSkoNr);
}
