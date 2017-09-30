#include "DataFilter.hpp"
#include <stdexcept>
#include <exception>

//Constructor and destructor
template<typename T>
DataFilter<T>::DataFilter(DataFileReader<T> *aReader, T aMin, T aMax)
:min(aMin),max(aMax),sum(),amount(0),avg(0),filterAmount(0)
{
	reader.reset(aReader);
	rangeErrorFile.open("RangeErrors.dat");
}

//function to test wether value is ok.
template<typename T>
const bool DataFilter<T>::rangeOk(T &aValue)
{
	return max > aValue ? min < aValue : false; 				// return false if aValue is less than min or more than max
}

//Below function returns next value and throws approprate exceptions
template<typename T>
const bool DataFilter<T>::getNextValue(T &aValue)
{
	if (reader->readNextValue(aValue)) 							// if value is readable
	{
		if (!rangeOk(aValue))									// value is within range
		{
			rangeErrorFile << aValue << std::endl;				// writing wrong value to error log file				
			throw std::range_error("value not making sense");
		}
		else
		{
			return true;
		}
	}
	else
	{
		return false;
	}
}

		

template class DataFilter<double>;	// instantializing the DataFilter class template for datatype double 