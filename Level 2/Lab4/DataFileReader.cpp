#include "DataFileReader.hpp"
#include <stdexcept>
#include <exception>

template<typename T>
DataFileReader<T>::DataFileReader(std::string aDataFileName, std::string aErrorFileName)
:filesOpen(false),dataFileName(aDataFileName),errorFileName(aErrorFileName)
{
	//
}

/*
template<typename T>
DataFileReader<T>::~DataFileReader
{
	is.close();
	os.close();
}
*/

template<typename T>
void DataFileReader<T>::openFiles()
{
	is.open(dataFileName);
	if(!is.is_open())
	{
		throw std::runtime_error("Data file could not be opened");
	}
	os.open(errorFileName);
	if(!os.is_open())
	{
		throw std::runtime_error("Error file could not be opened");
	} 
	filesOpen=true;
}


//function to give one value of the input file returns wether value's valid or not
template<typename T>
bool DataFileReader<T>::readNextValue(T &aValue)
{
	if(!filesOpen) // if files are not open.
	{
		openFiles();
	}
	std::ios_base::iostate mask = std::ios::eofbit | std::ios::failbit | std::ios::badbit; //combining error flags 
	is.exceptions(mask);	
	try
	{
		is >> aValue;
		return true;
	}
	catch (const std::ios_base::failure &eo)	// if it failed to read
	{
		std::ios_base::iostate flags = is.rdstate(); // get flags
		if (flags & std::ios::eofbit) // if end of file is reached
		{
			is.clear();	//clear error flags
			return false;			
		}
		else
		{
			std::string error;
			is.clear();			//clearing flags
			std::getline(is,error);
			os << error << std::endl;	// saving error to error file.
			return readNextValue(aValue); // recursion to ensure value is loaded
		}
	}
}


template class DataFileReader<double>; //instantiating template with type double