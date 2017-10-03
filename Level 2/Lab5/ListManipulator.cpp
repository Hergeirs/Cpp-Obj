#include "ListManipulator.hpp"

template<typename T>
ListManipulator<T>::ListManipulator(std::list<T> *aList)
{
	theList.reset(aList);
}

template<typename T>
T ListManipulator<T>::randomGenerator()
{
	//making distriburion static, so they don't have to be reinitialized on every call
	std::uniform_real_distribution<> random(1000,2000); 
	//making engine static, so that the we don't get the same time value for seed and thereby same variable on every call.
	static std::default_random_engine generator(static_cast<unsigned>(std::time(0)));
	return random(generator);
}

template<typename T>
void ListManipulator<T>::randomFill()
{
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

	while(b!=e && b!=--e) // decrementing the end iterator
	{
		std::iter_swap(b,e);	//swapping end with begin
		++b;			// incrementing begin iterator
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


template class ListManipulator<double>;
template class ListManipulator<int>;