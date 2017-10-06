#include "ListManipulator.hpp"
#include <fstream>
#include <iterator>
#include <iomanip>

template<typename T>
ListManipulator<T>::ListManipulator(std::list<T> *aList)
:theList(aList)
{
	//
}

//for use in the generate function
template<typename T>
T ListManipulator<T>::randomGenerator()
{
	//making distriburion static, so they don't have to be reinitialized on every call
	static std::uniform_real_distribution<> distribute(1000,2000); 
	//making engine static, so that the we don't get the same time value for seed and thereby same variable on every call.
	static std::default_random_engine random(static_cast<unsigned>(std::time(0)));
	return distribute(random);
}

template<typename T>
void ListManipulator<T>::randomFill()
{
	if(theList->size()!=20)
	{
		theList.reset(new std::list<T>(20,0));
	}
	//generating using member function above
	std::generate(theList->begin(),theList->end(),randomGenerator);
}

template<typename T>
T ListManipulator<T>::sumList() const
{
	return std::accumulate(theList->begin(),theList->end(),T(0));
}

template<typename T>
T ListManipulator<T>::avgList() const
{
	return sumList() / theList->size();	// avg
}

template<typename T>
bool ListManipulator<T>::findFirst1500_1900(T &item) const
{
	auto found = std::find_if(theList->begin(),theList->end(),[](T & t){return t>1500 && t<1900;});
	if (found!=theList->end())
	{
		item = *found;
		return true;
	}
	return false;
}

template<typename T>
void ListManipulator<T>::divideBy2()
{
	std::transform(theList->begin(),theList->end(),theList->begin(),std::bind(std::divides<T>(),std::placeholders::_1,2));
}

template<typename T>
void ListManipulator<T>::swapPlaces()
{
	auto b = theList->begin();
	auto e = theList->end();
	while(b!=e)	// while b and e not meet eachother.
	{
		std::iter_swap(b++,--e);
	}
}

template<typename T >
void ListManipulator<T>::findMinMax(T &min, T &max) const
{
	min = *std::min_element(theList->begin(),theList->end());
	max = *std::max_element(theList->begin(),theList->end());
}

template<typename T>
void ListManipulator<T>::sortList()
{
	theList->sort();
}

template<typename T>
void ListManipulator<T>::clearList()
{
	theList->clear();
}

template<typename T>
std::list<T> ListManipulator<T>::getList() const
{
	return *theList;
}

template<typename T>
void ListManipulator<T>::saveToFile() const
{
	std::ofstream os("list.dat");
	os << std::setprecision(50); // try to avoid to much truncation.
	if(os)
	{
		os << typeid(T).name() << std::endl;
		for (auto & i: *theList)
		{
			os << i << std::endl;
		}
	}
	os.close();
}

template<typename T>
void ListManipulator<T>::readFromFile()
{
	std::ifstream is("list.dat");
	if(is)
	{
		clearList();	// in case something already is in list.
		if (is.get()!= *typeid(T).name())
			throw std::runtime_error("wrong type");
		std::istream_iterator<T> eos;
		std::istream_iterator<T> iit(is);
		std::copy(iit,eos,std::back_inserter(*theList));
	}
	is.close();
}

template class ListManipulator<double>;
template class ListManipulator<int>;